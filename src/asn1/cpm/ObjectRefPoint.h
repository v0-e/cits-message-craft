/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PDU-Descriptions"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cpm/cpm_complete.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/cpm`
 */

#ifndef	_ObjectRefPoint_H_
#define	_ObjectRefPoint_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ObjectRefPoint {
	ObjectRefPoint_mid	= 0,
	ObjectRefPoint_bottomLeft	= 1,
	ObjectRefPoint_midLeft	= 2,
	ObjectRefPoint_topLeft	= 3,
	ObjectRefPoint_bottomMid	= 4,
	ObjectRefPoint_topMid	= 5,
	ObjectRefPoint_bottomRight	= 6,
	ObjectRefPoint_midRight	= 7,
	ObjectRefPoint_topRight	= 8
} e_ObjectRefPoint;

/* ObjectRefPoint */
typedef long long	 ObjectRefPoint_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ObjectRefPoint_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ObjectRefPoint;
asn_struct_free_f ObjectRefPoint_free;
asn_struct_print_f ObjectRefPoint_print;
asn_constr_check_f ObjectRefPoint_constraint;
ber_type_decoder_f ObjectRefPoint_decode_ber;
der_type_encoder_f ObjectRefPoint_encode_der;
xer_type_decoder_f ObjectRefPoint_decode_xer;
xer_type_encoder_f ObjectRefPoint_encode_xer;
jer_type_encoder_f ObjectRefPoint_encode_jer;
oer_type_decoder_f ObjectRefPoint_decode_oer;
oer_type_encoder_f ObjectRefPoint_encode_oer;
per_type_decoder_f ObjectRefPoint_decode_uper;
per_type_encoder_f ObjectRefPoint_encode_uper;
per_type_decoder_f ObjectRefPoint_decode_aper;
per_type_encoder_f ObjectRefPoint_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ObjectRefPoint_H_ */
#include <asn_internal.h>
