/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/cam`
 */

#ifndef	_RestrictedTypes_H_
#define	_RestrictedTypes_H_


#include <asn_application.h>

/* Including external dependencies */
#include "StationType.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RestrictedTypes */
typedef struct RestrictedTypes {
	A_SEQUENCE_OF(StationType_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RestrictedTypes_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RestrictedTypes;

#ifdef __cplusplus
}
#endif

#endif	/* _RestrictedTypes_H_ */
#include <asn_internal.h>
