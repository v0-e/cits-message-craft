/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PDU-Descriptions"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cpm/cpm_complete.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/cpm`
 */

#ifndef	_Heading_H_
#define	_Heading_H_


#include <asn_application.h>

/* Including external dependencies */
#include "HeadingValue.h"
#include "HeadingConfidence.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Heading */
typedef struct Heading {
	HeadingValue_t	 headingValue;
	HeadingConfidence_t	 headingConfidence;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Heading_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Heading;
extern asn_SEQUENCE_specifics_t asn_SPC_Heading_specs_1;
extern asn_TYPE_member_t asn_MBR_Heading_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _Heading_H_ */
#include <asn_internal.h>
