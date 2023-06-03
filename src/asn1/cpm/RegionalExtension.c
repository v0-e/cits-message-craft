/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PDU-Descriptions"
 * 	found in "/home/v0/it2s/it2s-asn/asn/cpm/cpm_complete.asn1"
 * 	`asn1c -S /home/v0/it2s/it2s-asn/skeletons -D cits-message-craft/src/asn1/cpm`
 */

#include "RegionalExtension.h"

static int
memb_regionId_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long long *)sptr;
	
	if((value >= 0L && value <= 255L)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_regExtValue_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(1 /* No applicable constraints whatsoever */) {
		/* Nothing is here. See below */
	}
	
	return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
}

#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_memb_regionId_constr_2 CC_NOTUSED = {
	{ 1, 1 }	/* (0..255) */,
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_regionId_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  0,  255 }	/* (0..255) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_memb_regExtValue_constr_3 CC_NOTUSED = {
	{ 0, 0 },
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_regExtValue_constr_3 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static asn_CHOICE_specifics_t asn_SPC_regExtValue_specs_3 = {
	sizeof(struct regExtValue),
	offsetof(struct regExtValue, _asn_ctx),
	offsetof(struct regExtValue, present),
	sizeof(((struct regExtValue *)0)->present),
	0,	/* No top level tags */
	0,	/* No tags in the map */
	0, 0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_regExtValue_3 = {
	"regExtValue",
	"regExtValue",
	&asn_OP_OPEN_TYPE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		OPEN_TYPE_constraint
	},
	0, 0,	/* No members */
	&asn_SPC_regExtValue_specs_3	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_Reg_NodeOffsetPointXY_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct Reg_NodeOffsetPointXY, regionId),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RegionId,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			&asn_OER_memb_regionId_constr_2,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_regionId_constr_2,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_regionId_constraint_1
		},
		0, 0, /* No default value */
		"regionId"
		},
	{ ATF_OPEN_TYPE | ATF_NOFLAGS, 0, offsetof(struct Reg_NodeOffsetPointXY, regExtValue),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_regExtValue_3,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			&asn_OER_memb_regExtValue_constr_3,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_regExtValue_constr_3,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_regExtValue_constraint_1
		},
		0, 0, /* No default value */
		"regExtValue"
		},
};
static const ber_tlv_tag_t asn_DEF_Reg_NodeOffsetPointXY_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Reg_NodeOffsetPointXY_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* regionId */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* regExtValue */
};
asn_SEQUENCE_specifics_t asn_SPC_Reg_NodeOffsetPointXY_specs_1 = {
	sizeof(struct Reg_NodeOffsetPointXY),
	offsetof(struct Reg_NodeOffsetPointXY, _asn_ctx),
	asn_MAP_Reg_NodeOffsetPointXY_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_Reg_NodeOffsetPointXY = {
	"Reg-NodeOffsetPointXY",
	"Reg-NodeOffsetPointXY",
	&asn_OP_SEQUENCE,
	asn_DEF_Reg_NodeOffsetPointXY_tags_1,
	sizeof(asn_DEF_Reg_NodeOffsetPointXY_tags_1)
		/sizeof(asn_DEF_Reg_NodeOffsetPointXY_tags_1[0]), /* 1 */
	asn_DEF_Reg_NodeOffsetPointXY_tags_1,	/* Same as above */
	sizeof(asn_DEF_Reg_NodeOffsetPointXY_tags_1)
		/sizeof(asn_DEF_Reg_NodeOffsetPointXY_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_Reg_NodeOffsetPointXY_1,
	2,	/* Elements count */
	&asn_SPC_Reg_NodeOffsetPointXY_specs_1	/* Additional specs */
};

