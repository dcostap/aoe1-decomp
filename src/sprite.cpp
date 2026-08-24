// Authentic PDB-ordered owner wrapper for sprite.cpp.
//
// Module: C:\\msdev\\work\\age1_x1\\sprite.cpp.
// The shared RGE_Sprite surface is the reviewed sprite.cpp context. The
// source-local RGE_Sprite declarations in the blocked entries cannot share
// one C++ translation unit without a duplicate compiler-facing class owner.
// They remain listed in the proposal as blocked; this wrapper does not copy
// their bodies or use a synthetic adapter.
//
// The wrapper keeps all compatible normal owners in PDB source-line order.
// 004C01A0 remains scratch and is included as observed. The compatible
// shadow_draw and hit_test owners are included as grouped drift because their
// two documented SIB encodings change in this complete context. Accepted
// drift and verified-logic entries with private class surfaces remain outside
// this policy-safe wrapper. The /GX response file is the registered sprite.cpp
// anchor context for the EH-bearing get_frame owner.

#include "../include/sprite_context.h"

#include "matching/004BFFE0_load_facets.cpp"
#include "matching/004BFFF0_play_sound.cpp"
#include "scratch/004C01A0_do_draw.cpp"
#include "matching/004C04F0_draw.cpp"
#include "matching/004C0620_normal_draw.cpp"
#include "matching/004C0720_shadow_draw.cpp"
#include "matching/004C0840_get_size.cpp"
#include "matching/004C0960_get_frame.cpp"
#include "matching/004C0C50_get_lowest_draw_level.cpp"
#include "matching/004C0C90_hit_test.cpp"
#include "matching/004C0F90_make_active_sprite.cpp"
#include "matching/004C1030_check_for_shadows.cpp"
