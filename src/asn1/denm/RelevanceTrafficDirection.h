/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/denm`
 */

#ifndef	_RelevanceTrafficDirection_H_
#define	_RelevanceTrafficDirection_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RelevanceTrafficDirection {
	RelevanceTrafficDirection_allTrafficDirections	= 0,
	RelevanceTrafficDirection_upstreamTraffic	= 1,
	RelevanceTrafficDirection_downstreamTraffic	= 2,
	RelevanceTrafficDirection_oppositeTraffic	= 3
} e_RelevanceTrafficDirection;

/* RelevanceTrafficDirection */
typedef long long	 RelevanceTrafficDirection_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_RelevanceTrafficDirection_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_RelevanceTrafficDirection;
extern const asn_INTEGER_specifics_t asn_SPC_RelevanceTrafficDirection_specs_1;
asn_struct_free_f RelevanceTrafficDirection_free;
asn_struct_print_f RelevanceTrafficDirection_print;
asn_constr_check_f RelevanceTrafficDirection_constraint;
ber_type_decoder_f RelevanceTrafficDirection_decode_ber;
der_type_encoder_f RelevanceTrafficDirection_encode_der;
xer_type_decoder_f RelevanceTrafficDirection_decode_xer;
xer_type_encoder_f RelevanceTrafficDirection_encode_xer;
jer_type_encoder_f RelevanceTrafficDirection_encode_jer;
oer_type_decoder_f RelevanceTrafficDirection_decode_oer;
oer_type_encoder_f RelevanceTrafficDirection_encode_oer;
per_type_decoder_f RelevanceTrafficDirection_decode_uper;
per_type_encoder_f RelevanceTrafficDirection_encode_uper;
per_type_decoder_f RelevanceTrafficDirection_decode_aper;
per_type_encoder_f RelevanceTrafficDirection_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RelevanceTrafficDirection_H_ */
#include <asn_internal.h>
