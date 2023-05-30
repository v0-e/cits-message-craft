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
    cam->cam.generationDeltaTime =  rand_range(0, 65535);
    cam->cam.camParameters.basicContainer.stationType = rand_range(0, 15);
    cam->cam.camParameters.basicContainer.referencePosition.positionConfidenceEllipse.semiMajorConfidence = rand_range(0, 4095);
    cam->cam.camParameters.basicContainer.referencePosition.positionConfidenceEllipse.semiMinorConfidence = rand_range(0, 4095);
    cam->cam.camParameters.basicContainer.referencePosition.positionConfidenceEllipse.semiMajorOrientation = rand_range(0, 3601);

    switch (cam->cam.camParameters.highFrequencyContainer.present) {
        case HighFrequencyContainer_PR_basicVehicleContainerHighFrequency:
            ;
            BasicVehicleContainerHighFrequency_t* bvc = &cam->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency;
            bvc->vehicleLength.vehicleLengthValue = rand_range(1, 1023);
            bvc->vehicleLength.vehicleLengthConfidenceIndication = rand_range(0, 4);
            bvc->vehicleWidth = rand_range(1, 62);
            bvc->heading.headingValue = rand_range(0, 3601);
            bvc->heading.headingConfidence = rand_range(1, 127);
            bvc->speed.speedValue = rand_range(0,16383);
            bvc->speed.speedConfidence = rand_range(1, 127);
            bvc->longitudinalAcceleration.longitudinalAccelerationValue = rand_range(-160, 161);
            bvc->longitudinalAcceleration.longitudinalAccelerationConfidence = rand_range(0, 102);
            if (bvc->lateralAcceleration) {
                bvc->lateralAcceleration->lateralAccelerationValue = rand_range(-160, 161);
                bvc->lateralAcceleration->lateralAccelerationConfidence = rand_range(0, 102);
            }
            if (bvc->verticalAcceleration) {
                bvc->verticalAcceleration->verticalAccelerationValue = rand_range(-160, 161);
                bvc->verticalAcceleration->verticalAccelerationConfidence = rand_range(0, 102);
            }
            bvc->yawRate.yawRateValue = rand_range(-32766, 32767);
            bvc->yawRate.yawRateConfidence = rand_range(0, 8);
            bvc->curvature.curvatureValue = rand_range(-1023, 1023);
            bvc->curvature.curvatureConfidence = rand_range(0, 7);
            if (bvc->steeringWheelAngle) {
                bvc->steeringWheelAngle->steeringWheelAngleValue = rand_range(-511, 512);
                bvc->steeringWheelAngle->steeringWheelAngleConfidence = rand_range(1, 127);
            }
            if (bvc->lanePosition) {
                *bvc->lanePosition = rand_range(-1, 14);
            }
            if (bvc->performanceClass) {
                *bvc->performanceClass = rand_range(0, 7);
            }
            if (bvc->cenDsrcTollingZone) {
                if (bvc->cenDsrcTollingZone->cenDsrcTollingZoneID) {
                    *bvc->cenDsrcTollingZone->cenDsrcTollingZoneID = rand_range(0, 134217727);
                }
            }
            break;

        case HighFrequencyContainer_PR_rsuContainerHighFrequency:
            ;
            RSUContainerHighFrequency_t* rc = &cam->cam.camParameters.highFrequencyContainer.choice.rsuContainerHighFrequency;
            if (rc->protectedCommunicationZonesRSU) {
                for (int i = 0; i < rc->protectedCommunicationZonesRSU->list.count; ++i) {
                    if (rc->protectedCommunicationZonesRSU->list.array[i]->expiryTime) {
                        uint64_t ret = rand_range(0, 100000) + its_ts_get();
                        asn_ulong2INTEGER(rc->protectedCommunicationZonesRSU->list.array[i]->expiryTime, ret);
                    }
                    if (rc->protectedCommunicationZonesRSU->list.array[i]->protectedZoneRadius) {
                        *rc->protectedCommunicationZonesRSU->list.array[i]->protectedZoneRadius = rand_range(1, 255);
                    }
                    if (rc->protectedCommunicationZonesRSU->list.array[i]->protectedZoneID) {
                        *rc->protectedCommunicationZonesRSU->list.array[i]->protectedZoneID = rand_range(0, 134217727);
                    }
                }
            }
            break;

        default:
            break;
    }

    if (cam->cam.camParameters.lowFrequencyContainer) {
        switch (cam->cam.camParameters.lowFrequencyContainer->present) {
            case LowFrequencyContainer_PR_basicVehicleContainerLowFrequency:
                ;
                PathHistory_t* ph = &cam->cam.camParameters.lowFrequencyContainer->choice.basicVehicleContainerLowFrequency.pathHistory;
                for (int i = 0; i < ph->list.count; ++i) {
                    ph->list.array[i]->pathPosition.deltaAltitude = rand_range(-12700, 12800);
                    if (ph->list.array[i]->pathDeltaTime) {
                        *ph->list.array[i]->pathDeltaTime = rand_range(1, 65535);
                    }
                }
                break;
            default:
                break;
        }
    }

    if (cam->cam.camParameters.specialVehicleContainer) {
        SpecialVehicleContainer_t* svc = cam->cam.camParameters.specialVehicleContainer;
        switch (svc->present) {
            case SpecialVehicleContainer_PR_publicTransportContainer:
                if (svc->choice.publicTransportContainer.ptActivation) {
                    svc->choice.publicTransportContainer.ptActivation->ptActivationType = rand_range(0, 255);
                }
                break;
            case SpecialVehicleContainer_PR_specialTransportContainer:
                break;
            case SpecialVehicleContainer_PR_dangerousGoodsContainer:
                break;
            case SpecialVehicleContainer_PR_roadWorksContainerBasic:
                if (svc->choice.roadWorksContainerBasic.roadworksSubCauseCode) {
                    *svc->choice.roadWorksContainerBasic.roadworksSubCauseCode = rand_range(0, 6);
                }
                break;
            case SpecialVehicleContainer_PR_rescueContainer:
                break;
            case SpecialVehicleContainer_PR_emergencyContainer:
                if (svc->choice.emergencyContainer.incidentIndication) {
                    svc->choice.emergencyContainer.incidentIndication->causeCode = rand_range(0, 255);
                    svc->choice.emergencyContainer.incidentIndication->subCauseCode = rand_range(0, 255);
                }
                break;
            case SpecialVehicleContainer_PR_safetyCarContainer:
                if (svc->choice.safetyCarContainer.incidentIndication) {
                    svc->choice.safetyCarContainer.incidentIndication->causeCode = rand_range(0, 255);
                    svc->choice.safetyCarContainer.incidentIndication->subCauseCode = rand_range(0, 255);
                }
                if (svc->choice.safetyCarContainer.speedLimit) {
                    *svc->choice.safetyCarContainer.speedLimit = rand_range(1, 255);
                }
                break;

            default:
                break;
        }
    }

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
    denm->denm.management.actionID.sequenceNumber = rand_range(0, UINT16_MAX);
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
