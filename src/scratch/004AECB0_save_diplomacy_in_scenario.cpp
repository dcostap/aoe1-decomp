// TRIBE_Screen_Sed::save_diplomacy_in_scenario — real pass
// VA: 004AECB0
#include "../../include/game_globals.h"

extern int __fastcall _getBtnState(void* btn);

void __fastcall save_diplomacy_in_scenario(void* _this, int _, int plr)
{
    if (plr < 0) return;
    for (int i = 0; i < 8; i++) {
        void** group = (void**)((char*)_this + 0x8AC + i * 12);  // 3 buttons per group
        int st0 = _getBtnState(group[-1]);
        if (st0 == 1) {
            void* scenario = *(void**)(*(int*)((char*)_this + 0x928) + 0x5C);
            ((void(__fastcall*)(void*,int,int,int,int))0x52B2D0)(scenario, 0, plr, i, 0);
        } else {
            int st1 = _getBtnState(group[0]);
            if (st1 == 1) {
                void* scenario = *(void**)(*(int*)((char*)_this + 0x928) + 0x5C);
                ((void(__fastcall*)(void*,int,int,int,int))0x52B2D0)(scenario, 0, plr, i, 1);
            } else {
                int st2 = _getBtnState(group[1]);
                if (st2 == 1) {
                    void* scenario = *(void**)(*(int*)((char*)_this + 0x928) + 0x5C);
                    ((void(__fastcall*)(void*,int,int,int,int))0x52B2D0)(scenario, 0, plr, i, 3);
                }
            }
        }
    }
    int allied = _getBtnState(*(void**)((char*)_this + plr * 4 + 0x908));
    void* scenario = *(void**)(*(int*)((char*)_this + 0x928) + 0x5C);
    ((void(__fastcall*)(void*,int,int,int))0x52B6A0)(scenario, 0, plr, allied);
}
