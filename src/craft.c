#include "cam/CAM.h"
#include "denm/DENM.h"
#include <time.h>
#include <unistd.h>
#include <argp.h>
#include <stdbool.h>

const char *argp_program_version = "cits-mc 0.1";
const char *argp_program_bug_address = "xyz.vieira@gmail.com";
static char doc[] = "C-ITS random message generator";
static struct argp_option options[] = { 
    { "type",         'm', "TYPE",       0,                   "Message type"},
    { "encoding",     'e', "ENCODING",   0,                   "Message encoding"},
    { "station-id",   1,   "ID",         OPTION_ARG_OPTIONAL, "Station ID"},
    { 0 } 
};

struct fields {
    int32_t station_id;
    bool station_id_set;
};

struct arguments {
    char* encoding;
    char* type;
    struct fields fields;
};

static error_t parse_opt(int key, char* arg, struct argp_state* state) {
    struct arguments *arguments = state->input;
    switch (key) {
        case 'm': 
            arguments->type = arg; 
            break;
        case 'e': 
            arguments->encoding = arg; 
            break;
        case 1: 
            arguments->fields.station_id = atoi(arg); 
            arguments->fields.station_id_set = true; 
            break;
        case ARGP_KEY_ARG: 
            return 0;
        default: 
            return ARGP_ERR_UNKNOWN;
    }   
    return 0;
}

static struct argp argp = { options, parse_opt, NULL, doc, 0, 0, 0 };

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

CAM_t* gen_cam(struct fields* fields) {
    CAM_t* cam = NULL;
    asn_random_fill(&asn_DEF_CAM, (void**)&cam, 256);
    cam->header.messageID = 2;
    cam->header.protocolVersion = 2;
    cam->header.stationID = rand_range(0, UINT32_MAX);
    cam->cam.generationDeltaTime = its_ts_get() % 65536;

    if (fields) {
        if (fields->station_id_set) {
            cam->header.stationID = fields->station_id;
        }
    }
    return cam;
}

DENM_t* gen_denm(struct fields* fields) {
    DENM_t* denm = NULL;
    asn_random_fill(&asn_DEF_DENM, (void**)&denm, 256);
    denm->header.messageID = 1;
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

unsigned char* request(struct arguments* arguments) {
    unsigned char* out = NULL;
    printf("encoding: %s | message: %s\n", arguments->encoding, arguments->type);

    void* its_msg;
    asn_TYPE_descriptor_t* desc;
    enum asn_transfer_syntax ats;
    if (!strcmp(arguments->type, "CAM") || !strcmp(arguments->type, "cam")) {
        desc = &asn_DEF_CAM;
        its_msg = gen_cam(&arguments->fields);
    } else if (!strcmp(arguments->type, "DENM") || !strcmp(arguments->type, "denm")) {
        desc = &asn_DEF_DENM;
        its_msg = gen_denm(&arguments->fields);
    } else {
        return NULL;
    }

    int to_hex = 0;
    if (!strcmp(arguments->encoding, "oer")) {
        ats = ATS_CANONICAL_OER;
        to_hex = 1;
    } else if (!strcmp(arguments->encoding, "uper")) {
        ats = ATS_UNALIGNED_CANONICAL_PER;
        to_hex = 1;
    } else if (!strcmp(arguments->encoding, "ber")) {
        ats = ATS_BER;
        to_hex = 1;
    } else if (!strcmp(arguments->encoding, "der")) {
        ats = ATS_DER;
        to_hex = 1;
    } else if (!strcmp(arguments->encoding, "xml")) {
        ats = ATS_BASIC_XER;
    } else if (!strcmp(arguments->encoding, "json")) {
        ats = ATS_JER;
    } else {
        return NULL;
    }

    const int buf_len = 32000;
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


int main(int argc, char* argv[]) {
    srand(time(NULL));

    struct arguments arguments = {0};

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    unsigned char* res = request(&arguments);
    printf("message:\n%s\n", res);
    free(res);

    return 0;
}
