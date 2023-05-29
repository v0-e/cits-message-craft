/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cam_en_302_637_2_v1.4.1.asn1"
 */

#ifndef	_SafetyCarContainer_H_
#define	_SafetyCarContainer_H_


#include <asn_application.h>

/* Including external dependencies */
#include "LightBarSirenInUse.h"
#include "TrafficRule.h"
#include "SpeedLimit.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CauseCode;

/* SafetyCarContainer */
typedef struct SafetyCarContainer {
	LightBarSirenInUse_t	 lightBarSirenInUse;
	struct CauseCode	*incidentIndication;	/* OPTIONAL */
	TrafficRule_t	*trafficRule;	/* OPTIONAL */
	SpeedLimit_t	*speedLimit;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SafetyCarContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SafetyCarContainer;
extern asn_SEQUENCE_specifics_t asn_SPC_SafetyCarContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_SafetyCarContainer_1[4];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CauseCode.h"

#endif	/* _SafetyCarContainer_H_ */
#include <asn_internal.h>
