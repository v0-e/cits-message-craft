/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/denm`
 */

#ifndef	_DeltaLongitude_H_
#define	_DeltaLongitude_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DeltaLongitude {
	DeltaLongitude_oneMicrodegreeEast	= 10,
	DeltaLongitude_oneMicrodegreeWest	= -10,
	DeltaLongitude_unavailable	= 131072
} e_DeltaLongitude;

/* DeltaLongitude */
typedef long long	 DeltaLongitude_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_DeltaLongitude_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_DeltaLongitude;
asn_struct_free_f DeltaLongitude_free;
asn_struct_print_f DeltaLongitude_print;
asn_constr_check_f DeltaLongitude_constraint;
ber_type_decoder_f DeltaLongitude_decode_ber;
der_type_encoder_f DeltaLongitude_encode_der;
xer_type_decoder_f DeltaLongitude_decode_xer;
xer_type_encoder_f DeltaLongitude_encode_xer;
jer_type_encoder_f DeltaLongitude_encode_jer;
oer_type_decoder_f DeltaLongitude_decode_oer;
oer_type_encoder_f DeltaLongitude_encode_oer;
per_type_decoder_f DeltaLongitude_decode_uper;
per_type_encoder_f DeltaLongitude_encode_uper;
per_type_decoder_f DeltaLongitude_decode_aper;
per_type_encoder_f DeltaLongitude_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _DeltaLongitude_H_ */
#include <asn_internal.h>
