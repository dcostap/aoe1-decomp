// TRIBE_Screen_Name::~TRIBE_Screen_Name — real pass (EH-framed)
// VA: 004A66E0
#include "../../include/game_globals.h"

void __fastcall dtor_TRIBE_Screen_Name(void* _this, int _)
{
    // Set vtable, then set current panel back
    ((void(__fastcall*)(void*,int,char*,int))0x463E60)((void*)0x62E870, 0, (char*)"New Name Dialog", 0);
    // Delete 9 child panels at +0x478..0x498
    for (int i = 0; i < 9; i++)
        ((void(__fastcall*)(void*,int,void*))0x466820)(_this, 0, (char*)_this + 0x478 + i * 4);
    // Base dtor
    ((void(__fastcall*)(void*,int))0x47BAD0)(_this, 0);  // TScreenPanel::~TScreenPanel
}
