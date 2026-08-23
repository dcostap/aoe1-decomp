// VA: 00492D50 TRIBE_Credits_Screen::key_down_action
// PDB donor: scr_cred.cpp lines 367-377

#include "../../include/scr_cred_context.h"

long TRIBE_Credits_Screen::key_down_action(long key, short, int, int, int)
{
    if (key == 0xD || key == 0x1B) {
        this->close_screen();
        return 1;
    }
    return 0;
}
