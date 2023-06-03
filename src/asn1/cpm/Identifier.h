/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PDU-Descriptions"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cpm/cpm_complete.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/cpm`
 */

#ifndef	_Identifier_H_
#define	_Identifier_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Identifier */
typedef long long	 Identifier_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_Identifier_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_Identifier;
asn_struct_free_f Identifier_free;
asn_struct_print_f Identifier_print;
asn_constr_check_f Identifier_constraint;
ber_type_decoder_f Identifier_decode_ber;
der_type_encoder_f Identifier_encode_der;
xer_type_decoder_f Identifier_decode_xer;
xer_type_encoder_f Identifier_encode_xer;
jer_type_encoder_f Identifier_encode_jer;
oer_type_decoder_f Identifier_decode_oer;
oer_type_encoder_f Identifier_encode_oer;
per_type_decoder_f Identifier_decode_uper;
per_type_encoder_f Identifier_encode_uper;
per_type_decoder_f Identifier_decode_aper;
per_type_encoder_f Identifier_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _Identifier_H_ */
#include <asn_internal.h>
