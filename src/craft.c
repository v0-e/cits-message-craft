#include "cam/CAM.h"
#include "denm/DENM.h"
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>

#define MSG_MAX_LEN 32768

enum MODE {
    MODE_UNSPECIFIED,
    MODE_GENERATOR,
    MODE_CONVERTER
};

struct msg_fields {
    int32_t station_id;
    bool station_id_set;

    double latitude;
    bool latitude_set;
    double longitude;
    bool longitude_set;
};

struct generator_args {
    char* encoding;
    char* type;
    struct msg_fields fields;
};

struct converter_args {
    char* encoding_in;
    char* encoding_out;
    char* msg;
};

uint64_t its_ts_get() {
    struct timespec systemtime;
    clock_gettime(CLOCK_REALTIME, &systemtime);
    uint64_t generationdeltatime;
    generationdeltatime = ((uint64_t)systemtime.tv_sec + 5) * 1000 + 
        (uint64_t)systemtime.tv_nsec / 1E6;
    return generationdeltatime - 1072915200000;
}

int64_t rand_range(int64_t min, int64_t max) {
    return (rand() % (1 + max - min)) + min;
}

CAM_t* gen_cam(struct msg_fields* fields) {
    CAM_t* cam = NULL;
    asn_random_fill(&asn_DEF_CAM, (void**)&cam, 256);
    cam->header.messageID = messageID_cam;
    cam->header.protocolVersion = 2;
    cam->header.stationID = rand_range(0, UINT32_MAX);
    cam->cam.generationDeltaTime = its_ts_get() % 65536;

    if (fields) {
        if (fields->station_id_set) {
            cam->header.stationID = fields->station_id;
        }

        if (fields->latitude_set) {
            cam->cam.camParameters.basicContainer.referencePosition.latitude = (int32_t)(fields->latitude*10e6);
        }
        if (fields->longitude_set) {
            cam->cam.camParameters.basicContainer.referencePosition.longitude = (int32_t)(fields->longitude*10e6);
        }
    }
    return cam;
}

DENM_t* gen_denm(struct msg_fields* fields) {
    DENM_t* denm = NULL;
    asn_random_fill(&asn_DEF_DENM, (void**)&denm, 256);
    denm->header.messageID = messageID_denm;
    denm->header.protocolVersion = 2;
    denm->header.stationID = rand_range(0, UINT32_MAX);
    uint64_t now = its_ts_get();
    asn_ulong2INTEGER(&denm->denm.management.detectionTime, now);
    asn_ulong2INTEGER(&denm->denm.management.referenceTime, now);

    // TODO fix positionOfOccupants encoding
    // TODO fix phoneNumber encoding
    if (denm->denm.alacarte && 
            denm->denm.alacarte->stationaryVehicle && 
            denm->denm.alacarte->stationaryVehicle->carryingDangerousGoods &&
            denm->denm.alacarte->stationaryVehicle->carryingDangerousGoods->phoneNumber) {
        ASN_STRUCT_FREE(
                asn_DEF_PhoneNumber, 
                denm->denm.alacarte->stationaryVehicle->carryingDangerousGoods->phoneNumber
                );
        denm->denm.alacarte->stationaryVehicle->carryingDangerousGoods->phoneNumber = NULL;
    }

    if (fields) {
        if (fields->station_id_set) {
            denm->header.stationID = fields->station_id;
            denm->denm.management.actionID.originatingStationID = fields->station_id;
        }

        if (fields->latitude_set) {
            denm->denm.management.eventPosition.latitude = (int32_t)(fields->latitude*10e6);
        }
        if (fields->longitude_set) {
            denm->denm.management.eventPosition.longitude = (int32_t)(fields->longitude*10e6);
        }
    }

    return denm;
}

int encode(void* msg, asn_TYPE_descriptor_t* desc, enum asn_transfer_syntax ats, uint8_t* buf, int buf_len) {
    asn_enc_rval_t enc = asn_encode_to_buffer(NULL, ats, desc, msg, buf, buf_len);
    if (enc.encoded == -1) {
        fprintf(stderr, "encode failed: %s\n", enc.failed_type->name);
        return 0;
    }
    return enc.encoded;
}

unsigned char* gen(struct generator_args* args) {
    unsigned char* out = NULL;
    printf("encoding: %s | message: %s\n", args->encoding, args->type);

    void* its_msg;
    asn_TYPE_descriptor_t* desc;
    enum asn_transfer_syntax ats;
    if (!strcmp(args->type, "CAM") || !strcmp(args->type, "cam")) {
        desc = &asn_DEF_CAM;
        its_msg = gen_cam(&args->fields);
    } else if (!strcmp(args->type, "DENM") || !strcmp(args->type, "denm")) {
        desc = &asn_DEF_DENM;
        its_msg = gen_denm(&args->fields);
    } else {
        return NULL;
    }

    int to_hex = 0;
    if (!strcmp(args->encoding, "oer") || !strcmp(args->encoding, "OER")) {
        ats = ATS_CANONICAL_OER;
        to_hex = 1;
    } else if (!strcmp(args->encoding, "uper") || !strcmp(args->encoding, "UPER")) {
        ats = ATS_UNALIGNED_CANONICAL_PER;
        to_hex = 1;
    } else if (!strcmp(args->encoding, "ber") || !strcmp(args->encoding, "BER")) {
        ats = ATS_BER;
        to_hex = 1;
    } else if (!strcmp(args->encoding, "der") || !strcmp(args->encoding, "DER")) {
        ats = ATS_DER;
        to_hex = 1;
    } else if (!strcmp(args->encoding, "xml") || !strcmp(args->encoding, "XML")) {
        ats = ATS_BASIC_XER;
    } else if (!strcmp(args->encoding, "json") || !strcmp(args->encoding, "JSON")) {
        ats = ATS_JER;
    } else {
        return NULL;
    }

    const int buf_len = MSG_MAX_LEN;
    unsigned char* buf = malloc(buf_len);
    buf[0] = 0;
    int enc = encode(its_msg, desc, ats, buf, buf_len);

    if (enc) {
        if (to_hex) {
            out = malloc(enc * 2 + 2 + 1);
            sprintf((char*)out, "0x");
            for (int i = 0; i < enc; ++i) {
                sprintf((char*)out + 2 + i*2, "%02x", buf[i]);
            }
            free(buf);  
        } else {
            out = buf;
        }
    } 

    ASN_STRUCT_FREE(*desc, its_msg);
    return out;
}

int hex2bin(char* hex, uint8_t* bin) {
    if (!memcmp("0x", hex, 2)) {
        hex += 2;
    }

    unsigned int bin_len = strlen(hex) / 2;
    char substr[3];
    substr[2] = '\0';
    for (int i = 0; i < bin_len; ++i) {
        memcpy(substr, hex + i * 2, 2);
        bin[i] = (uint8_t)strtoul(substr, NULL, 16);
    }

    return bin_len;
}

int bin2hex(uint8_t* bin, size_t bin_len, char* hex) {
    sprintf((char*)hex, "0x");
    for (int i = 0; i < bin_len; ++i) {
        sprintf((char*)hex + 2 + i*2, "%02x", bin[i]);
    }
    return strlen(hex);
}

unsigned char* conv(struct converter_args* args) {
    unsigned char* out = NULL;
    printf("converting %s to %s\n", args->encoding_in, args->encoding_out);

    const int bin_len = 2048;
    uint8_t bin[bin_len];
    void* its_msg = NULL;
    asn_TYPE_descriptor_t* desc;
    enum asn_transfer_syntax ats;
    int msg_type; 
    int msg_len;
    uint8_t* msg;

    /* Find out message type */
    if (!strcmp(args->encoding_in, "oer") || !strcmp(args->encoding_in, "OER")) {
        ats = ATS_CANONICAL_OER;
        msg_len = hex2bin(args->msg, bin);
        msg_type = bin[1]; /* 2nd byte */
        msg = bin;

    } else if (!strcmp(args->encoding_in, "uper") || !strcmp(args->encoding_in, "UPER")) {
        ats = ATS_UNALIGNED_CANONICAL_PER;
        msg_len = hex2bin(args->msg, bin);
        msg_type = bin[1]; /* 2nd byte */
        msg = bin;

    } else if (!strcmp(args->encoding_in, "ber") || !strcmp(args->encoding_in, "BER")) {
        ats = ATS_BER;
        msg_len = hex2bin(args->msg, bin);
        for (int i = 0; i < msg_len; ++i) {
            if (*(uint16_t*)&bin[i] == 0x0181) {
                msg_type =  bin[i+2];
                break;
            }
        }
        msg = bin;

    } else if (!strcmp(args->encoding_in, "der") || !strcmp(args->encoding_in, "DER")) {
        ats = ATS_DER;
        msg_len = hex2bin(args->msg, bin);
        for (int i = 0; i < msg_len; ++i) {
            if (*(uint16_t*)&bin[i] == 0x0181) {
                msg_type =  bin[i+2];
                break;
            }
        }
        msg = bin;

    } else if (!strcmp(args->encoding_in, "xml") || !strcmp(args->encoding_in, "XML")) {
        ats = ATS_BASIC_XER;
        
        char mts[32];
        int mts_len = 0;

        char* p = strstr(args->msg, "<");
        if (p) {
           if (*(p + 1) != '?') { /* without XML header */
               mts_len = strstr(p, ">") - (p + 1);
               memcpy(mts, p + 1, mts_len);
               mts[mts_len] = 0;
           } else { /* with XML header */
               p = strstr(args->msg + 1, "<");
               if (p) {
                   mts_len = strstr(p, ">") - (p + 1);
                   memcpy(mts, p + 1, mts_len);
                   mts[mts_len] = 0;
               } else {
                   return NULL;
               }
           }
        } else {
            return NULL;
        }

        if (mts_len) {
            if (!strcmp(mts, "CAM")) {
                msg_type = messageID_cam;
            } else if (!strcmp(mts, "DENM")) {
                msg_type = messageID_denm;
            } else {
                return NULL;
            }
        }
        msg = (uint8_t*)args->msg;
        msg_len = strlen(args->msg);
        
    } else if (!strcmp(args->encoding_in, "json") || !strcmp(args->encoding_in, "JSON")) {
        ats = ATS_JER;
        return NULL; // TODO support JER decoding
    } else {
        return NULL;
    }

    switch (msg_type) {
        case messageID_cam:
            desc = &asn_DEF_CAM;
            break;

        case messageID_denm:
            desc = &asn_DEF_DENM;
            break;

        default:
            return NULL;
    }

    asn_dec_rval_t dec = asn_decode(NULL, ats, desc, (void**) &its_msg, msg, msg_len);
    if (dec.code) {
        fprintf(stderr, "%s decode failed\n", desc->name);
        ASN_STRUCT_FREE(*desc, its_msg);
        return NULL;
    }

    int to_hex = 0;
    if (!strcmp(args->encoding_out, "oer") || !strcmp(args->encoding_out, "OER")) {
        ats = ATS_CANONICAL_OER;
        to_hex = 1;
    } else if (!strcmp(args->encoding_out, "uper") || !strcmp(args->encoding_out, "UPER")) {
        ats = ATS_UNALIGNED_CANONICAL_PER;
        to_hex = 1;
    } else if (!strcmp(args->encoding_out, "ber") || !strcmp(args->encoding_out, "BER")) {
        ats = ATS_BER;
        to_hex = 1;
    } else if (!strcmp(args->encoding_out, "der") || !strcmp(args->encoding_out, "DER")) {
        ats = ATS_DER;
        to_hex = 1;
    } else if (!strcmp(args->encoding_out, "xml") || !strcmp(args->encoding_out, "XML")) {
        ats = ATS_BASIC_XER;
    } else if (!strcmp(args->encoding_out, "json") || !strcmp(args->encoding_out, "JSON")) {
        ats = ATS_JER;
    } else {
        return NULL;
    }

    uint8_t* buf = malloc(MSG_MAX_LEN);

    int enc = encode(its_msg, desc, ats, buf, MSG_MAX_LEN);
    if (enc) {
        if (to_hex) {
            out = malloc(enc * 2 + 2 + 1);
            sprintf((char*)out, "0x");
            for (int i = 0; i < enc; ++i) {
                sprintf((char*)out + 2 + i*2, "%02x", buf[i]);
            }
            free(buf);  
        } else {
            out = buf;
        }
    } 

    ASN_STRUCT_FREE(*desc, its_msg);
    return out;
}

static struct option generator_long_options[] =
{
    {"help",     no_argument,       0, 'h'},
    {"type",     required_argument, 0, 'm'},
    {"encoding", required_argument, 0, 'e'},
    {"station-id", required_argument, 0, 1},
    {"latitude", required_argument, 0, 2},
    {"longitude", required_argument, 0, 3},
    {0, 0, 0, 0}
};

static struct option converter_long_options[] =
{
    {"help",        no_argument,       0, 'h'},
    {"message",     required_argument, 0, 'm'},
    {"in-encoding", required_argument, 0, 'i'},
    {"out-encoding", required_argument, 0, 'o'},
    {0, 0, 0, 0}
};

void print_help() {
    printf("Usage: cits-mc gen|conv [...]\n\
    gen: random message generator\n\
    conv: message encoding converter");
}


int main(int argc, char* argv[]) {
    srand(time(NULL));

    if (argc < 2) {
        print_help();
        return 0;
    }

    int mode = MODE_UNSPECIFIED;
    if (!strcmp(argv[1], "gen")) {
        mode = MODE_GENERATOR;
    } else if (!strcmp(argv[1], "conv")) {
        mode = MODE_CONVERTER;
    } else {
        print_help();
        return 0;
    }

    unsigned char* res; 

    struct generator_args g_args = {0};
    struct converter_args c_args = {0};
    int c;
    int option_index = 1;
    switch (mode) {
        case MODE_GENERATOR:
            while ((c = getopt_long(argc, argv, "ht:e:",
                            generator_long_options, &option_index)) != -1) {
                switch (c) {
                    case 0:
                        if (generator_long_options[option_index].flag != 0)
                            break;
                        printf ("\n");
                        break;

                    case 'h':
                        printf("Usage: %s %s -t message-type -e encoding\n",
                                argv[0], argv[1]);
                        return 0;

                    case 't':
                        g_args.type = optarg;
                        break;

                    case 'e':
                        g_args.encoding = optarg;
                        break;

                    case 1:
                        g_args.fields.station_id = atoi(optarg);
                        g_args.fields.station_id_set = true;
                        break;

                    case 2:
                        g_args.fields.latitude = strtod(optarg, NULL);
                        g_args.fields.latitude_set = true;
                        break;

                    case 3:
                        g_args.fields.longitude = strtod(optarg, NULL);
                        g_args.fields.longitude_set = true;
                        break;

                    case '?':
                        break;

                    default:
                        abort();
                }
            }
            if (!g_args.encoding || !g_args.type) {
                printf("Usage: %s gen -t message-type -e encoding\n",
                        argv[0]);
                return 0;
            }
            res = gen(&g_args);
            break;

        case MODE_CONVERTER:
            while ((c = getopt_long(argc, argv, "hm:i:o:",
                            converter_long_options, &option_index)) != -1) {
                switch (c) {
                    case 0:
                        if (converter_long_options[option_index].flag != 0)
                            break;
                        printf ("\n");
                        break;

                    case 'h':
                        printf("Usage: %s conv -m message -i input-encoding -o output-encoding\n",
                                argv[0]);
                        return 0;

                    case 'm':
                        c_args.msg = optarg;
                        break;

                    case 'i':
                        c_args.encoding_in = optarg;
                        break;

                    case 'o':
                        c_args.encoding_out = optarg;
                        break;

                    case '?':
                        break;

                    default:
                        abort();
                }
            }

            if (!c_args.encoding_in || !c_args.encoding_out || !c_args.encoding_out) {
                printf("Usage: %s %s -m message -i input-encoding -o output-encoding\n",
                        argv[0], argv[1]);
                return 0;
            }
            res = conv(&c_args);
            break;

        default:
            exit(1);

    }

    printf("message:\n%s\n", res);
    free(res);

    return 0;
}
