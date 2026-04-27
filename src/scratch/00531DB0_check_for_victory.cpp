// RGE_Victory_Conditions::check_for_victory — first pass
// VA: 00531DB0
#include "../../include/game_globals.h"

void __fastcall check_for_victory(void* _this)
{
    // Complex victory condition checking
    // Iterates victory_list, tracks groups and states
    *(char*)((char*)_this + 0x10) = 0;
}
