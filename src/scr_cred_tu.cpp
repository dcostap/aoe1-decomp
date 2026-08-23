// scr_cred.cpp owners in PDB source order.
// 00492FB0 retains its reviewed x87 drift. 00493160 remains standalone:
// grouped VC5 merges one TextOutA tail and loses an oracle call site.
// All other listed owners are exact anchors.
// The scalar deleting destructor at 00492950 has no source-line owner and is
// intentionally excluded.
#include "../include/scr_cred_context.h"
#include "matching/004926E0_TRIBE_Credits_Screen.cpp"
#include "matching/00492970_TRIBE_Credits_Screen.cpp"
#include "matching/00492A40_handle_mouse_down.cpp"
#include "matching/00492A50_handle_idle.cpp"
#include "matching/00492CC0_draw.cpp"
#include "matching/00492D50_key_down_action.cpp"
#include "matching/00492D70_action.cpp"
#include "matching/00492DB0_close_screen.cpp"
#include "matching/00492E70_TScrollTextPanel.cpp"
#include "matching/00492F70_TScrollTextPanel.cpp"
#include "matching/00492F80_set_text.cpp"
#include "accepted_drift/00492FB0_handle_idle.cpp"
#include "matching/00493070_draw.cpp"
#include "matching/00493420_RGE_fade_palette_start.cpp"
#include "matching/00493540_RGE_fade_palette_step.cpp"
