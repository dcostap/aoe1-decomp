// TRIBE_Mission_Screen::draw — real pass
// VA: 004B88E0
#include "../../include/game_globals.h"

void __fastcall draw_TRIBE_Mission_Screen(void* _this, int _)
{
    ((void(__fastcall*)(void*,int))0x47BB40)(_this, 0);  // TScreenPanel::draw
    if (!*(void**)((char*)_this + 0x498)) return;  // vc_back_bmp
    
    void* vtable = *(void**)_this;
    ((void(__stdcall*)(int))(*(int*)vtable + 0x28))(0);  // vtable[0x28](0) — get DC
    
    if (*(int*)((char*)_this + 0x38) == 2) {
        int color = *(unsigned char*)((char*)_this + 0x454);
        ((void(__fastcall*)(void*,int,void*,int))0x444680)(*(void**)((char*)_this + 0x20), 0, (char*)_this + 0x24, color);  // Clear
    }
    
    void* drawArea = *(void**)((char*)_this + 0x20);
    unsigned char* lock = ((unsigned char*(__fastcall*)(void*,int,char*,int))0x444270)(drawArea, 0, (char*)"scr_vc::draw", 1);
    if (!lock) {
        ((void(__stdcall*)())(*(int*)vtable + 0x2C))();
        return;
    }
    
    int f14 = *(int*)((char*)_this + 0x14);
    int f10 = *(int*)((char*)_this + 0x10);
    int f0C = *(int*)((char*)_this + 0x0C);
    int x, y;
    if (f14 <= 0x280) {  // 640 or less
        y = f10 + 0xA6;
        x = f0C + 7;
    } else if (f14 <= 0x320) {  // 800 or less
        y = f10 + 0x118;
        x = f0C + 0x53;
    } else {  // 1024+
        y = f10 + 0x16B;
        x = f0C + 0xC5;
    }
    ((void(__fastcall*)(void*,int,void*,int,int,int,int))0x46E2D0)(
        *(void**)((char*)_this + 0x498), 0, drawArea, x, y, 0, 0);
    
    ((void(__fastcall*)(void*,int,char*))0x444300)(drawArea, 0, (char*)"scr_vc::draw");
    ((void(__stdcall*)())(*(int*)vtable + 0x2C))();
}
