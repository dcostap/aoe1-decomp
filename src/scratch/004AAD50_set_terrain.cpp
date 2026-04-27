// TRIBE_Screen_Sed::set_terrain — first pass
// VA: 004AAD50
#include "../../include/game_globals.h"

void __fastcall set_terrain(void* _this, int _, short param_1)
{
    int v;
    switch (param_1) {
    case 1: v = 6; break;
    case 2: v = 10; break;
    case 3: v = 1; break;
    case 4: v = 0xD; break;
    case 5: v = 0x14; break;
    case 6: v = 4; break;
    case 7: v = 0x13; break;
    case 8: v = 0x16; break;
    default: v = 0; break;
    }
    *(short*)((int)rge_base_game + 0x3FE) = (short)v;
    void* list = *(void**)((char*)_this + 0x5A0);
    // TListPanel::scroll_cur_line(list, 1, param_1, 1)
}
