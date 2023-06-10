#include "cam/CAM.h"
#include "denm/DENM.h"
#include <time.h>
#include <unistd.h>

uint64_t its_ts_get() {
    struct timespec systemtime;
    clock_gettime(CLOCK_REALTIME, &systemtime);
    uint64_t generationdeltatime;
    generationdeltatime = ((uint64_t)systemtime.tv_sec + 5) * 1000 + (uint64_t)systemtime.tv_nsec / 1E6;
    return generationdeltatime - 1072915200000;
}

int64_t rand_range(int64_t min, int64_t max) {
    return (rand() % (1 + max - min)) + min;
}

CAM_t* gen_cam() {
    CAM_t* cam = NULL;
    asn_random_fill(&asn_DEF_CAM, (void**)&cam, 256);
    cam->header.messageID = 2;
    cam->header.protocolVersion = 2;
    cam->header.stationID = rand_range(0, UINT32_MAX);
    cam->cam.generationDeltaTime = its_ts_get() % 65536;
    return cam;
}

DENM_t* gen_denm() {
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
        ASN_STRUCT_FREE(asn_DEF_PhoneNumber, denm->denm.alacarte->stationaryVehicle->carryingDangerousGoods->phoneNumber);
        denm->denm.alacarte->stationaryVehicle->carryingDangerousGoods->phoneNumber = NULL;
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

unsigned char* request(char* msg_type, char* encoding_type) {
    unsigned char* out = NULL;
    printf("encoding: %s | message: %s\n", encoding_type, msg_type);

    void* its_msg;
    asn_TYPE_descriptor_t* desc;
    enum asn_transfer_syntax ats;
    if (!strcmp(msg_type, "CAM") || !strcmp(msg_type, "cam")) {
        desc = &asn_DEF_CAM;
        its_msg = gen_cam();
    } else if (!strcmp(msg_type, "DENM") || !strcmp(msg_type, "denm")) {
        desc = &asn_DEF_DENM;
        its_msg = gen_denm();
    } else {
        return NULL;
    }

    int to_hex = 0;
    if (!strcmp(encoding_type, "oer")) {
        ats = ATS_CANONICAL_OER;
        to_hex = 1;
    } else if (!strcmp(encoding_type, "uper")) {
        ats = ATS_UNALIGNED_CANONICAL_PER;
        to_hex = 1;
    } else if (!strcmp(encoding_type, "ber")) {
        ats = ATS_BER;
        to_hex = 1;
    } else if (!strcmp(encoding_type, "der")) {
        ats = ATS_DER;
        to_hex = 1;
    } else if (!strcmp(encoding_type, "xml")) {
        ats = ATS_BASIC_XER;
    } else if (!strcmp(encoding_type, "json")) {
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
    int opt;
    char* msg_type = NULL;
    char* encoding_type = NULL;
    while ((opt = getopt(argc, argv, "e:m:")) != -1) {
        switch (opt) {
            case 'm':
                msg_type = optarg;
                break;
            case 'e':
                encoding_type = optarg;
                break;
        }
    }
    if (!msg_type || !encoding_type) {
        fprintf(stderr, "Usage: %s -m msg-type -e encoding-type\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }

    unsigned char* res = request(msg_type, encoding_type);
    printf("message:\n%s\n", res);
    free(res);

    return 0;
}
