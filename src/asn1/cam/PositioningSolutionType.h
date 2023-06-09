/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/cam`
 */

#ifndef	_PositioningSolutionType_H_
#define	_PositioningSolutionType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PositioningSolutionType {
	PositioningSolutionType_noPositioningSolution	= 0,
	PositioningSolutionType_sGNSS	= 1,
	PositioningSolutionType_dGNSS	= 2,
	PositioningSolutionType_sGNSSplusDR	= 3,
	PositioningSolutionType_dGNSSplusDR	= 4,
	PositioningSolutionType_dR	= 5
	/*
	 * Enumeration is extensible
	 */
} e_PositioningSolutionType;

/* PositioningSolutionType */
typedef long long	 PositioningSolutionType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PositioningSolutionType;
asn_struct_free_f PositioningSolutionType_free;
asn_struct_print_f PositioningSolutionType_print;
asn_constr_check_f PositioningSolutionType_constraint;
ber_type_decoder_f PositioningSolutionType_decode_ber;
der_type_encoder_f PositioningSolutionType_encode_der;
xer_type_decoder_f PositioningSolutionType_decode_xer;
xer_type_encoder_f PositioningSolutionType_encode_xer;
jer_type_encoder_f PositioningSolutionType_encode_jer;
oer_type_decoder_f PositioningSolutionType_decode_oer;
oer_type_encoder_f PositioningSolutionType_encode_oer;
per_type_decoder_f PositioningSolutionType_decode_uper;
per_type_encoder_f PositioningSolutionType_encode_uper;
per_type_decoder_f PositioningSolutionType_decode_aper;
per_type_encoder_f PositioningSolutionType_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _PositioningSolutionType_H_ */
#include <asn_internal.h>
