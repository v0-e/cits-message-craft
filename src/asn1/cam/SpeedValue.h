/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 */

#ifndef	_SpeedValue_H_
#define	_SpeedValue_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SpeedValue {
	SpeedValue_standstill	= 0,
	SpeedValue_oneCentimeterPerSec	= 1,
	SpeedValue_unavailable	= 16383
} e_SpeedValue;

/* SpeedValue */
typedef long long	 SpeedValue_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_SpeedValue_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_SpeedValue;
asn_struct_free_f SpeedValue_free;
asn_struct_print_f SpeedValue_print;
asn_constr_check_f SpeedValue_constraint;
ber_type_decoder_f SpeedValue_decode_ber;
der_type_encoder_f SpeedValue_encode_der;
xer_type_decoder_f SpeedValue_decode_xer;
xer_type_encoder_f SpeedValue_encode_xer;
jer_type_encoder_f SpeedValue_encode_jer;
oer_type_decoder_f SpeedValue_decode_oer;
oer_type_encoder_f SpeedValue_encode_oer;
per_type_decoder_f SpeedValue_decode_uper;
per_type_encoder_f SpeedValue_encode_uper;
per_type_decoder_f SpeedValue_decode_aper;
per_type_encoder_f SpeedValue_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _SpeedValue_H_ */
#include <asn_internal.h>
