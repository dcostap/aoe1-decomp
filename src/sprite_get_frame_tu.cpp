// Authentic sprite.cpp owner group in PDB source-line order.
//
// PDB module: C:\\msdev\\work\\age1_x1\\sprite.cpp
// Non-exact normal owners remain outside the exact-owner wrapper:
// 004C00E0 is accepted drift, 004C01A0 is scratch, 004C0B70 and 004C0D80 are
// accepted drift, and 004C1080 is verified logic. These classifications are
// not exact-owner claims.
//
// include/sprite_context.h supplies one canonical RGE_Sprite surface. Each
// included source owns one normal function; no body is duplicated here.
// The current grouped checker anchor 004C0960 remains exact. Standalone exact
// owners are exact under their own authoritative checks; the combined object
// has the two documented SIB pairs in 004C0720 and 004C0C90.

#include "../include/sprite_context.h"

#include "matching/004BFFE0_load_facets.cpp"
#include "matching/004BFFF0_play_sound.cpp"
#include "matching/004C04F0_draw.cpp"
#include "matching/004C0620_normal_draw.cpp"
#include "matching/004C0720_shadow_draw.cpp"
#include "matching/004C0840_get_size.cpp"
#include "matching/004C0960_get_frame.cpp"
#include "matching/004C0C50_get_lowest_draw_level.cpp"
#include "matching/004C0C90_hit_test.cpp"
#include "matching/004C0F90_make_active_sprite.cpp"
#include "matching/004C1030_check_for_shadows.cpp"
