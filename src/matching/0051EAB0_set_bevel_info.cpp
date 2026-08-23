// 0051EAB0 Time_Line_Panel::set_bevel_info (tpnl_tml.cpp:234-242)
// BINARY NOTE: this owner uses the shared tpnl_tml.cpp timeline surface.
// PDB-qualified owner: ?set_bevel_info@Time_Line_Panel@@QAEXHHHHHHH@Z.
// The body ends at 0051EAF8 after ret 1Ch; padding starts at 0051EAF9.
// Fresh exact validation used the authentic multi-owner src/tpnl_tml_tu.cpp,
// with Time_Line_Panel::setup at 0051E9E0 immediately before this owner.
// Exact-finish: implicit int-to-byte member conversion is sufficient; removing
// explicit casts preserved all 73 bytes.

#include "../../include/tpnl_tml_context.h"

void Time_Line_Panel::set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    bevel_type = param_1;
    bevel_color1 = param_2;
    bevel_color2 = param_3;
    bevel_color3 = param_4;
    bevel_color4 = param_5;
    bevel_color5 = param_6;
    bevel_color6 = param_7;
}
