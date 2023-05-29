/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 */

#ifndef	_CenDsrcTollingZone_H_
#define	_CenDsrcTollingZone_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Latitude.h"
#include "Longitude.h"
#include "CenDsrcTollingZoneID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CenDsrcTollingZone */
typedef struct CenDsrcTollingZone {
	Latitude_t	 protectedZoneLatitude;
	Longitude_t	 protectedZoneLongitude;
	CenDsrcTollingZoneID_t	*cenDsrcTollingZoneID;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CenDsrcTollingZone_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CenDsrcTollingZone;

#ifdef __cplusplus
}
#endif

#endif	/* _CenDsrcTollingZone_H_ */
#include <asn_internal.h>
