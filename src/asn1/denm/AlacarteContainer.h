/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DENM-PDU-Descriptions"
 * 	found in "/home/v0/it2s/it2s-asn/asn/denm_en_302_637_3_v1.3.1.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/denm`
 */

#ifndef	_AlacarteContainer_H_
#define	_AlacarteContainer_H_


#include <asn_application.h>

/* Including external dependencies */
#include "LanePosition.h"
#include "Temperature.h"
#include "PositioningSolutionType.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ImpactReductionContainer;
struct RoadWorksContainerExtended;
struct StationaryVehicleContainer;

/* AlacarteContainer */
typedef struct AlacarteContainer {
	LanePosition_t	*lanePosition;	/* OPTIONAL */
	struct ImpactReductionContainer	*impactReduction;	/* OPTIONAL */
	Temperature_t	*externalTemperature;	/* OPTIONAL */
	struct RoadWorksContainerExtended	*roadWorks;	/* OPTIONAL */
	PositioningSolutionType_t	*positioningSolution;	/* OPTIONAL */
	struct StationaryVehicleContainer	*stationaryVehicle;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AlacarteContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AlacarteContainer;
extern asn_SEQUENCE_specifics_t asn_SPC_AlacarteContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_AlacarteContainer_1[6];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ImpactReductionContainer.h"
#include "RoadWorksContainerExtended.h"
#include "StationaryVehicleContainer.h"

#endif	/* _AlacarteContainer_H_ */
#include <asn_internal.h>
