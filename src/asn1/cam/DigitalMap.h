/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 */

#ifndef	_DigitalMap_H_
#define	_DigitalMap_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ReferencePosition;

/* DigitalMap */
typedef struct DigitalMap {
	A_SEQUENCE_OF(struct ReferencePosition) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DigitalMap_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DigitalMap;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ReferencePosition.h"

#endif	/* _DigitalMap_H_ */
#include <asn_internal.h>
