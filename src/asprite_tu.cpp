// Authentic PDB-order owner wrapper for asprite.cpp.
//
// The shared context models the real RGE_Active_Sprite hierarchy and the
// RGE_Sprite fields used by this module. Each included file owns one PDB
// function. The function files keep their narrow standalone declarations for
// focused checks, but use this common class surface in this complete TU.
//
// Candidate packet result with /O2 /Oy /GX: 28 exact normal owners, 7
// observed owners (3 byte-equal and 4 context mismatches), and 2 exact
// compiler-generated deleting destructors. No generated entry is blocked.
// The five observed mismatches remain outside exact registration.

#include "asprite_context.h"

#define ASPRITE_FULL_TU
#include "matching/0041AD20_RGE_Active_Sprite.cpp"
#include "matching/0041AD60_RGE_Active_Sprite.cpp"
#include "matching/0041ADD0_RGE_Active_Sprite.cpp"
#include "matching/0041ADE0_set_offset.cpp"
#include "matching/0041AE00_save.cpp"
#include "matching/0041AE50_update.cpp"
#include "matching/0041AE60_draw.cpp"
#include "matching/0041AEB0_normal_draw.cpp"
#include "matching/0041AEF0_shadow_draw.cpp"
#include "matching/0041AF30_what_frame.cpp"
#include "matching/0041AF40_set_frame.cpp"
#include "matching/0041AF50_is_animating.cpp"
#include "matching/0041AF60_frame_passed.cpp"
#include "matching/0041AF70_looped.cpp"
#include "matching/0041AF80_get_facetindex.cpp"
#include "matching/0041AFB0_get_frame.cpp"
#include "matching/0041AFE0_get_lowest_draw_level.cpp"
#include "matching/0041AFF0_setToFirstFrame.cpp"
#include "scratch/0041B000_check_for_shadows.cpp"
#include "matching/0041B010_RGE_Active_Animated_Sprite.cpp"
#include "matching/0041B140_RGE_Active_Animated_Sprite.cpp"
#include "scratch/0041B200_RGE_Active_Animated_Sprite.cpp"
#include "matching/0041B210_save.cpp"
#include "matching/0041B290_update.cpp"
#include "matching/0041B430_draw.cpp"
#include "matching/0041B4A0_normal_draw.cpp"
#include "matching/0041B4F0_shadow_draw.cpp"
#include "matching/0041B520_what_frame.cpp"
#include "matching/0041B530_is_animating.cpp"
#include "scratch/0041B550_set_frame.cpp"
#include "matching/0041B560_frame_passed.cpp"
#include "matching/0041B590_looped.cpp"
#include "matching/0041B5A0_get_facetindex.cpp"
#include "matching/0041B5D0_get_frame.cpp"
#include "matching/0041B600_setToFirstFrame.cpp"
#undef ASPRITE_FULL_TU
