/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/cam`
 */

#ifndef	_LateralAcceleration_H_
#define	_LateralAcceleration_H_


#include <asn_application.h>

/* Including external dependencies */
#include "LateralAccelerationValue.h"
#include "AccelerationConfidence.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* LateralAcceleration */
typedef struct LateralAcceleration {
	LateralAccelerationValue_t	 lateralAccelerationValue;
	AccelerationConfidence_t	 lateralAccelerationConfidence;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} LateralAcceleration_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_LateralAcceleration;
extern asn_SEQUENCE_specifics_t asn_SPC_LateralAcceleration_specs_1;
extern asn_TYPE_member_t asn_MBR_LateralAcceleration_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _LateralAcceleration_H_ */
#include <asn_internal.h>
