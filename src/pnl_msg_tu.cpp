// Authentic owner wrapper for C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp.
//
// The source module has twelve normal owners. The list below follows PDB
// source-line order, not linked-address order. The scalar deleting destructor
// at 00479030 is compiler-generated and stays in the generated category.
//
// Flags: config/flags/00479050_TMessagePanel.rsp (/nologo /c /O2 /Oy /GX).
// Three existing owners have /GX overlays; the other owners use default.rsp.
// A single original module flag set is not proved. The candidate report keeps
// this as a flag-risk observation and records the default-flags control run.
//
// Policy: no synthetic function, handwritten assembly, raw cursor owner, or
// metric-only register steering is added by this wrapper.

#include "../include/pnl_msg_context.h"

#include "accepted_drift/00478F40_TMessagePanel.cpp"
#include "matching/00479050_TMessagePanel.cpp"
#include "matching/004790E0_set_rect.cpp"
#include "matching/00479270_set_justification.cpp"
#include "matching/004792A0_show_message.cpp"
#include "matching/004793C0_show_message2.cpp"
#include "matching/00479540_remove_message.cpp"
#include "scratch/00479590_draw.cpp"
#include "matching/00479A10_get_true_render_rect.cpp"
#include "matching/00479A80_handle_idle.cpp"
#include "scratch/00479AE0_render_to_image_buffer.cpp"
#include "matching/0047A190_set_font.cpp"
