/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 */

#ifndef	_PosCentMass_H_
#define	_PosCentMass_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PosCentMass {
	PosCentMass_tenCentimeters	= 1,
	PosCentMass_unavailable	= 63
} e_PosCentMass;

/* PosCentMass */
typedef long long	 PosCentMass_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PosCentMass;
asn_struct_free_f PosCentMass_free;
asn_struct_print_f PosCentMass_print;
asn_constr_check_f PosCentMass_constraint;
ber_type_decoder_f PosCentMass_decode_ber;
der_type_encoder_f PosCentMass_encode_der;
xer_type_decoder_f PosCentMass_decode_xer;
xer_type_encoder_f PosCentMass_encode_xer;
jer_type_encoder_f PosCentMass_encode_jer;
oer_type_decoder_f PosCentMass_decode_oer;
oer_type_encoder_f PosCentMass_encode_oer;
per_type_decoder_f PosCentMass_decode_uper;
per_type_encoder_f PosCentMass_encode_uper;
per_type_decoder_f PosCentMass_decode_aper;
per_type_encoder_f PosCentMass_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _PosCentMass_H_ */
#include <asn_internal.h>
