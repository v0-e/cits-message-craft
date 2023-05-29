/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 */

#ifndef	_StationaryVehicleSubCauseCode_H_
#define	_StationaryVehicleSubCauseCode_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum StationaryVehicleSubCauseCode {
	StationaryVehicleSubCauseCode_unavailable	= 0,
	StationaryVehicleSubCauseCode_humanProblem	= 1,
	StationaryVehicleSubCauseCode_vehicleBreakdown	= 2,
	StationaryVehicleSubCauseCode_postCrash	= 3,
	StationaryVehicleSubCauseCode_publicTransportStop	= 4,
	StationaryVehicleSubCauseCode_carryingDangerousGoods	= 5
} e_StationaryVehicleSubCauseCode;

/* StationaryVehicleSubCauseCode */
typedef long long	 StationaryVehicleSubCauseCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_StationaryVehicleSubCauseCode;
asn_struct_free_f StationaryVehicleSubCauseCode_free;
asn_struct_print_f StationaryVehicleSubCauseCode_print;
asn_constr_check_f StationaryVehicleSubCauseCode_constraint;
ber_type_decoder_f StationaryVehicleSubCauseCode_decode_ber;
der_type_encoder_f StationaryVehicleSubCauseCode_encode_der;
xer_type_decoder_f StationaryVehicleSubCauseCode_decode_xer;
xer_type_encoder_f StationaryVehicleSubCauseCode_encode_xer;
jer_type_encoder_f StationaryVehicleSubCauseCode_encode_jer;
oer_type_decoder_f StationaryVehicleSubCauseCode_decode_oer;
oer_type_encoder_f StationaryVehicleSubCauseCode_encode_oer;
per_type_decoder_f StationaryVehicleSubCauseCode_decode_uper;
per_type_encoder_f StationaryVehicleSubCauseCode_encode_uper;
per_type_decoder_f StationaryVehicleSubCauseCode_decode_aper;
per_type_encoder_f StationaryVehicleSubCauseCode_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _StationaryVehicleSubCauseCode_H_ */
#include <asn_internal.h>
