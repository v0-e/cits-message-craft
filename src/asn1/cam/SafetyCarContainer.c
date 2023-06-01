/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cam_en_302_637_2_v1.4.1.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/cam`
 */

#include "SafetyCarContainer.h"

asn_TYPE_member_t asn_MBR_SafetyCarContainer_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct SafetyCarContainer, lightBarSirenInUse),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LightBarSirenInUse,
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
		"lightBarSirenInUse"
		},
	{ ATF_POINTER, 3, offsetof(struct SafetyCarContainer, incidentIndication),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CauseCode,
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
		"incidentIndication"
		},
	{ ATF_POINTER, 2, offsetof(struct SafetyCarContainer, trafficRule),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TrafficRule,
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
		"trafficRule"
		},
	{ ATF_POINTER, 1, offsetof(struct SafetyCarContainer, speedLimit),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SpeedLimit,
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
		"speedLimit"
		},
};
static const int asn_MAP_SafetyCarContainer_oms_1[] = { 1, 2, 3 };
static const ber_tlv_tag_t asn_DEF_SafetyCarContainer_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_SafetyCarContainer_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* lightBarSirenInUse */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* incidentIndication */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* trafficRule */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* speedLimit */
};
asn_SEQUENCE_specifics_t asn_SPC_SafetyCarContainer_specs_1 = {
	sizeof(struct SafetyCarContainer),
	offsetof(struct SafetyCarContainer, _asn_ctx),
	asn_MAP_SafetyCarContainer_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_SafetyCarContainer_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_SafetyCarContainer = {
	"SafetyCarContainer",
	"SafetyCarContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_SafetyCarContainer_tags_1,
	sizeof(asn_DEF_SafetyCarContainer_tags_1)
		/sizeof(asn_DEF_SafetyCarContainer_tags_1[0]), /* 1 */
	asn_DEF_SafetyCarContainer_tags_1,	/* Same as above */
	sizeof(asn_DEF_SafetyCarContainer_tags_1)
		/sizeof(asn_DEF_SafetyCarContainer_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_SafetyCarContainer_1,
	4,	/* Elements count */
	&asn_SPC_SafetyCarContainer_specs_1	/* Additional specs */
};

