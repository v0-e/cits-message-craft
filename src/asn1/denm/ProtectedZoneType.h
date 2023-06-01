/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/denm`
 */

#ifndef	_ProtectedZoneType_H_
#define	_ProtectedZoneType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ProtectedZoneType {
	ProtectedZoneType_permanentCenDsrcTolling	= 0,
	/*
	 * Enumeration is extensible
	 */
	ProtectedZoneType_temporaryCenDsrcTolling	= 1
} e_ProtectedZoneType;

/* ProtectedZoneType */
typedef long long	 ProtectedZoneType_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ProtectedZoneType_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ProtectedZoneType;
extern const asn_INTEGER_specifics_t asn_SPC_ProtectedZoneType_specs_1;
asn_struct_free_f ProtectedZoneType_free;
asn_struct_print_f ProtectedZoneType_print;
asn_constr_check_f ProtectedZoneType_constraint;
ber_type_decoder_f ProtectedZoneType_decode_ber;
der_type_encoder_f ProtectedZoneType_encode_der;
xer_type_decoder_f ProtectedZoneType_decode_xer;
xer_type_encoder_f ProtectedZoneType_encode_xer;
jer_type_encoder_f ProtectedZoneType_encode_jer;
oer_type_decoder_f ProtectedZoneType_decode_oer;
oer_type_encoder_f ProtectedZoneType_encode_oer;
per_type_decoder_f ProtectedZoneType_decode_uper;
per_type_encoder_f ProtectedZoneType_encode_uper;
per_type_decoder_f ProtectedZoneType_decode_aper;
per_type_encoder_f ProtectedZoneType_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ProtectedZoneType_H_ */
#include <asn_internal.h>
