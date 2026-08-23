// Safe scr_cred.cpp prefix in PDB source order.
// PDB lines 46-470 are included. The prefix stops before 00492FB0,
// whose accepted-drift arithmetic basin is not exact.
// Later standalone exact owners 00493070, 00493420, and 00493540 remain
// outside this prefix. 00493160 remains unresolved in src/scratch.
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
