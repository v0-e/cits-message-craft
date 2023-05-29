/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cd_dictionary_ts_102_894_2_v1.3.1.asn1"
 */

#include "VerticalAcceleration.h"

static asn_TYPE_member_t asn_MBR_VerticalAcceleration_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct VerticalAcceleration, verticalAccelerationValue),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VerticalAccelerationValue,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"verticalAccelerationValue"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct VerticalAcceleration, verticalAccelerationConfidence),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_AccelerationConfidence,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"verticalAccelerationConfidence"
		},
};
static const ber_tlv_tag_t asn_DEF_VerticalAcceleration_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_VerticalAcceleration_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* verticalAccelerationValue */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* verticalAccelerationConfidence */
};
static asn_SEQUENCE_specifics_t asn_SPC_VerticalAcceleration_specs_1 = {
	sizeof(struct VerticalAcceleration),
	offsetof(struct VerticalAcceleration, _asn_ctx),
	asn_MAP_VerticalAcceleration_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_VerticalAcceleration = {
	"VerticalAcceleration",
	"VerticalAcceleration",
	&asn_OP_SEQUENCE,
	asn_DEF_VerticalAcceleration_tags_1,
	sizeof(asn_DEF_VerticalAcceleration_tags_1)
		/sizeof(asn_DEF_VerticalAcceleration_tags_1[0]), /* 1 */
	asn_DEF_VerticalAcceleration_tags_1,	/* Same as above */
	sizeof(asn_DEF_VerticalAcceleration_tags_1)
		/sizeof(asn_DEF_VerticalAcceleration_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_VerticalAcceleration_1,
	2,	/* Elements count */
	&asn_SPC_VerticalAcceleration_specs_1	/* Additional specs */
};

