/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PDU-Descriptions"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cpm/cpm_complete.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/cpm`
 */

#ifndef	_ClassConfidence_H_
#define	_ClassConfidence_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ClassConfidence {
	ClassConfidence_unknown	= 0,
	ClassConfidence_onePercent	= 1,
	ClassConfidence_oneHundredPercent	= 100,
	ClassConfidence_unavailable	= 101
} e_ClassConfidence;

/* ClassConfidence */
typedef long long	 ClassConfidence_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ClassConfidence_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ClassConfidence;
asn_struct_free_f ClassConfidence_free;
asn_struct_print_f ClassConfidence_print;
asn_constr_check_f ClassConfidence_constraint;
ber_type_decoder_f ClassConfidence_decode_ber;
der_type_encoder_f ClassConfidence_encode_der;
xer_type_decoder_f ClassConfidence_decode_xer;
xer_type_encoder_f ClassConfidence_encode_xer;
jer_type_encoder_f ClassConfidence_encode_jer;
oer_type_decoder_f ClassConfidence_decode_oer;
oer_type_encoder_f ClassConfidence_encode_oer;
per_type_decoder_f ClassConfidence_decode_uper;
per_type_encoder_f ClassConfidence_encode_uper;
per_type_decoder_f ClassConfidence_decode_aper;
per_type_encoder_f ClassConfidence_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ClassConfidence_H_ */
#include <asn_internal.h>
