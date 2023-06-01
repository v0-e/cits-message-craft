/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/denm`
 */

#ifndef	_Traces_H_
#define	_Traces_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct PathHistory;

/* Traces */
typedef struct Traces {
	A_SEQUENCE_OF(struct PathHistory) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Traces_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Traces;
extern asn_SET_OF_specifics_t asn_SPC_Traces_specs_1;
extern asn_TYPE_member_t asn_MBR_Traces_1[1];
extern asn_per_constraints_t asn_PER_type_Traces_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "PathHistory.h"

#endif	/* _Traces_H_ */
#include <asn_internal.h>
