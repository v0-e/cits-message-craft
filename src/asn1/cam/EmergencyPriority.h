/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/cam`
 */

#ifndef	_EmergencyPriority_H_
#define	_EmergencyPriority_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum EmergencyPriority {
	EmergencyPriority_requestForRightOfWay	= 0,
	EmergencyPriority_requestForFreeCrossingAtATrafficLight	= 1
} e_EmergencyPriority;

/* EmergencyPriority */
typedef BIT_STRING_t	 EmergencyPriority_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_EmergencyPriority_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_EmergencyPriority;
asn_struct_free_f EmergencyPriority_free;
asn_struct_print_f EmergencyPriority_print;
asn_constr_check_f EmergencyPriority_constraint;
ber_type_decoder_f EmergencyPriority_decode_ber;
der_type_encoder_f EmergencyPriority_encode_der;
xer_type_decoder_f EmergencyPriority_decode_xer;
xer_type_encoder_f EmergencyPriority_encode_xer;
jer_type_encoder_f EmergencyPriority_encode_jer;
oer_type_decoder_f EmergencyPriority_decode_oer;
oer_type_encoder_f EmergencyPriority_encode_oer;
per_type_decoder_f EmergencyPriority_decode_uper;
per_type_encoder_f EmergencyPriority_encode_uper;
per_type_decoder_f EmergencyPriority_decode_aper;
per_type_encoder_f EmergencyPriority_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _EmergencyPriority_H_ */
#include <asn_internal.h>
