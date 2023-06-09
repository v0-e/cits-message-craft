/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/denm`
 */

#ifndef	_TimestampIts_H_
#define	_TimestampIts_H_


#include <asn_application.h>

/* Including external dependencies */
#include <INTEGER.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum TimestampIts {
	TimestampIts_utcStartOf2004	= 0,
	TimestampIts_oneMillisecAfterUTCStartOf2004	= 1
} e_TimestampIts;

/* TimestampIts */
typedef INTEGER_t	 TimestampIts_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_TimestampIts_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_TimestampIts;
asn_struct_free_f TimestampIts_free;
asn_struct_print_f TimestampIts_print;
asn_constr_check_f TimestampIts_constraint;
ber_type_decoder_f TimestampIts_decode_ber;
der_type_encoder_f TimestampIts_encode_der;
xer_type_decoder_f TimestampIts_decode_xer;
xer_type_encoder_f TimestampIts_encode_xer;
jer_type_encoder_f TimestampIts_encode_jer;
oer_type_decoder_f TimestampIts_decode_oer;
oer_type_encoder_f TimestampIts_encode_oer;
per_type_decoder_f TimestampIts_decode_uper;
per_type_encoder_f TimestampIts_encode_uper;
per_type_decoder_f TimestampIts_decode_aper;
per_type_encoder_f TimestampIts_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _TimestampIts_H_ */
#include <asn_internal.h>
