// TRIBE_Screen_Sed::load_diplomacy_from_scenario — real pass
// VA: 004AED50
#include "../../include/game_globals.h"

extern void __fastcall _setRadioBtn(void* btn, int _);

void __fastcall load_diplomacy_from_scenario(void* _this, int _, int plr)
{
    if (plr < 0) return;
    for (int i = 0; i < 8; i++) {
        void** group = (void**)((char*)_this + 0x8AC + i * 12);
        void* scenario = *(void**)(*(int*)((char*)_this + 0x928) + 0x5C);
        int att = ((int(__fastcall*)(void*,int,int,int))0x52B310)(scenario, 0, plr, i);
        if (att == 0)
            _setRadioBtn(group[-1], 0);
        if (att == 1)
            _setRadioBtn(group[0], 0);
        if (att == 3)
            _setRadioBtn(group[1], 0);
        // Clear button state via vtable[0xE0](0)
        void* btn = *(void**)((char*)_this + 0x908 + i * 4);
        (*(void(__stdcall**)(int))(*(int*)btn))(0);
    }
    void* targetBtn = *(void**)((char*)_this + plr * 4 + 0x908);
    void* scenario = *(void**)(*(int*)((char*)_this + 0x928) + 0x5C);
    int av = ((int(__fastcall*)(void*,int,int))0x52BA30)(scenario, 0, plr);
    (*(void(__stdcall**)(int))(*(int*)targetBtn))(av);
}
