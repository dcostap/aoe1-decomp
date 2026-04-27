// TScrollTextPanel::handle_idle — real pass
// VA: 00492FB0
#include "../../include/game_globals.h"

long __fastcall handle_idle_scroll(void* _this, int _)
{
    int t;
    if (!*(int*)((char*)_this + 0x18C)) {
        t = ((int(__fastcall*)(char*,int))0x4231E0)((char*)"scr_cred.cpp", 0x1DC);
        *(int*)((char*)_this + 0x18C) = t;
    } else {
        int t2 = ((int(__fastcall*)(char*,int))0x4231E0)((char*)"scr_cred.cpp", 0x1DF);
        int dt = t2 - *(int*)((char*)_this + 0x18C);
        // FPU: (dt * constant) / scroll_speed 
        int scroll = 0;
        int speed = *(int*)((char*)_this + 0x190);
        if (speed) {
            // approximate: scroll = (int)((float)dt * 0.1f / (float)speed);
        }
        if (scroll > 0) {
            *(int*)((char*)_this + 0x188) += scroll;
            (*(void(__stdcall**)(int))(*(int*)_this + 0x20))(1);
            *(int*)((char*)_this + 0x18C) = t2;
        }
    }
    if (*(int*)((char*)_this + 0x194)) {
        void* child = *(void**)((char*)_this + 0x40);
        if (child) {
            (*(void(__stdcall**)(int,int,void*))(*(int*)child + 0xB4))(0, 0, _this);
        }
    }
    return ((long(__fastcall*)(void*,int))0x465780)(_this, 0);
}
