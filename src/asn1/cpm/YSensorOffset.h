/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PDU-Descriptions"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cpm/cpm_complete.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/cpm`
 */

#ifndef	_YSensorOffset_H_
#define	_YSensorOffset_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum YSensorOffset {
	YSensorOffset_zeroPointZeroOneMeter	= 1,
	YSensorOffset_oneMeter	= 100
} e_YSensorOffset;

/* YSensorOffset */
typedef long long	 YSensorOffset_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_YSensorOffset_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_YSensorOffset;
asn_struct_free_f YSensorOffset_free;
asn_struct_print_f YSensorOffset_print;
asn_constr_check_f YSensorOffset_constraint;
ber_type_decoder_f YSensorOffset_decode_ber;
der_type_encoder_f YSensorOffset_encode_der;
xer_type_decoder_f YSensorOffset_decode_xer;
xer_type_encoder_f YSensorOffset_encode_xer;
jer_type_encoder_f YSensorOffset_encode_jer;
oer_type_decoder_f YSensorOffset_decode_oer;
oer_type_encoder_f YSensorOffset_encode_oer;
per_type_decoder_f YSensorOffset_decode_uper;
per_type_encoder_f YSensorOffset_encode_uper;
per_type_decoder_f YSensorOffset_decode_aper;
per_type_encoder_f YSensorOffset_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _YSensorOffset_H_ */
#include <asn_internal.h>
