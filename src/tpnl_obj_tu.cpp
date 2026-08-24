// Authentic PDB-ordered owner wrapper for tpnl_obj.cpp.
//
// Module: C:\\msdev\\work\\age1_x1\\tpnl_obj.cpp
// Normal owners follow the source-line and address sequence in
// build/tu_plans/tpnl_obj_cpp/packet.json.  0051B050 is the compiler-generated
// scalar deleting destructor and is not a source owner.
//
// The constructor and destructor have reviewed /GX standalone evidence.  The
// remaining owners use the normal /O2 /Oy response.  The candidate module
// response uses the constructor's /GX flags so the authentic EH owners remain
// in the same compiler input; observed default-context differences are reported
// by the candidate validator rather than hidden with per-owner wrappers.

#include "../include/tpnl_obj_context.h"

#include "matching/0051ADF0_TRIBE_Panel_Object.cpp"
#include "matching/0051B070_TRIBE_Panel_Object.cpp"
#include "matching/0051B110_set_player.cpp"
#include "matching/0051B140_set_object.cpp"
#include "matching/0051B160_set_mode.cpp"
#include "matching/0051B180_get_mode.cpp"
#include "scratch/0051B190_draw.cpp"
#include "scratch/0051BF90_draw_score.cpp"
#include "matching/0051C220_draw_item.cpp"
#include "scratch/0051C3F0_handle_idle.cpp"
#include "matching/0051CA10_save_object_info.cpp"
#include "matching/0051CC80_mouse_left_down_action.cpp"
#include "matching/0051CC90_mouse_left_up_action.cpp"
