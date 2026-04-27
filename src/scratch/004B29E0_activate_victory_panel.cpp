// TRIBE_Screen_Sed::activate_victory_panel — real pass
// VA: 004B29E0
#include "../../include/game_globals.h"

extern int __fastcall _getSPVictoryType(void* _this, int _, int i);

void __fastcall activate_victory_panel(void* _this, int _, int flag)
{
    for (int i = 0; i < 12; i++) {
        void* btn = *(void**)((char*)_this + 0x704 + i * 4);
        (*(void(__stdcall**)(int))(*(int*)btn))(flag);  // vtable[0x14](flag)
        int vt = _getSPVictoryType(*(void**)(*(int*)((char*)_this + 0x928) + 0x5C), 0, i);
        int val = (-(vt != 0) & 2) + (*(int*)((char*)_this + 0x498) == i ? 1 : 0);
        if (flag)
            (*(void(__stdcall**)(int))(*(int*)btn + 0xE0))(val);  // vtable[0xE0](val)
    }
    // Three more panel show/hide calls
    (*(void(__stdcall**)(int))(*(int*)(*(void**)((char*)_this + 0x734))))(flag);
    (*(void(__stdcall**)(int))(*(int*)(*(void**)((char*)_this + 0x75C))))(flag);
    void* plrList = *(void**)((char*)_this + 0x73C);
    (*(void(__stdcall**)(int))(*(int*)plrList))(flag);
    if (flag) {
        ((void(__fastcall*)(void*,int,int))0x475250)(plrList, 0, (int)*(short*)((char*)_this + 0x4B8) - 1);
    } else {
        long line = ((long(__fastcall*)(void*,int))0x475380)(plrList, 0);
        *(short*)((char*)_this + 0x4B8) = (short)(line + 1);
    }
}
