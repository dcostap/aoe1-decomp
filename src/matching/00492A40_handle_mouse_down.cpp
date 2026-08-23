// VA: 00492A40 TRIBE_Credits_Screen::handle_mouse_down
// PDB donor: scr_cred.cpp lines 210-213

#include "../../include/scr_cred_context.h"

long TRIBE_Credits_Screen::handle_mouse_down(uchar, long, long, int, int)
{
    this->close_screen();
    return 1;
}
