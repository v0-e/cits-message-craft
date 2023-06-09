/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/cam`
 */

#ifndef	_HazardousLocation_ObstacleOnTheRoadSubCauseCode_H_
#define	_HazardousLocation_ObstacleOnTheRoadSubCauseCode_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum HazardousLocation_ObstacleOnTheRoadSubCauseCode {
	HazardousLocation_ObstacleOnTheRoadSubCauseCode_unavailable	= 0,
	HazardousLocation_ObstacleOnTheRoadSubCauseCode_shedLoad	= 1,
	HazardousLocation_ObstacleOnTheRoadSubCauseCode_partsOfVehicles	= 2,
	HazardousLocation_ObstacleOnTheRoadSubCauseCode_partsOfTyres	= 3,
	HazardousLocation_ObstacleOnTheRoadSubCauseCode_bigObjects	= 4,
	HazardousLocation_ObstacleOnTheRoadSubCauseCode_fallenTrees	= 5,
	HazardousLocation_ObstacleOnTheRoadSubCauseCode_hubCaps	= 6,
	HazardousLocation_ObstacleOnTheRoadSubCauseCode_waitingVehicles	= 7
} e_HazardousLocation_ObstacleOnTheRoadSubCauseCode;

/* HazardousLocation-ObstacleOnTheRoadSubCauseCode */
typedef long long	 HazardousLocation_ObstacleOnTheRoadSubCauseCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HazardousLocation_ObstacleOnTheRoadSubCauseCode;
asn_struct_free_f HazardousLocation_ObstacleOnTheRoadSubCauseCode_free;
asn_struct_print_f HazardousLocation_ObstacleOnTheRoadSubCauseCode_print;
asn_constr_check_f HazardousLocation_ObstacleOnTheRoadSubCauseCode_constraint;
ber_type_decoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCode_decode_ber;
der_type_encoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCode_encode_der;
xer_type_decoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCode_decode_xer;
xer_type_encoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCode_encode_xer;
jer_type_encoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCode_encode_jer;
oer_type_decoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCode_decode_oer;
oer_type_encoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCode_encode_oer;
per_type_decoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCode_decode_uper;
per_type_encoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCode_encode_uper;
per_type_decoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCode_decode_aper;
per_type_encoder_f HazardousLocation_ObstacleOnTheRoadSubCauseCode_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _HazardousLocation_ObstacleOnTheRoadSubCauseCode_H_ */
#include <asn_internal.h>
