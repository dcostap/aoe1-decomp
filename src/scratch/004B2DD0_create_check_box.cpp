// TRIBE_Screen_Sed::create_check_box — real pass
// VA: 004B2DD0
#include "../../include/game_globals.h"

int __fastcall create_check_box(void* _this, int _, void* parent, void* btnOut)
{
    int ok = ((int(__fastcall*)(void*,int,void*,void*,int,int,int,int,int,int))0x468760)
        (_this, 0, parent, btnOut, 0, 0, 0, 0, 1, 0);
    if (!ok) return 0;
    void* btn = *(void**)btnOut;
    ((void(__fastcall*)(void*,int,int,int))0x466430)(btn, 0, 1, 0); // set_z_order
    (*(void(__stdcall**)(int))(*(int*)btn))(0);  // vtable[0x14](0)
    if (*(int*)((char*)_this + 0x31C)) {
        int c0 = *(unsigned char*)((char*)_this + 0x320);
        int c1 = *(unsigned char*)((char*)_this + 0x321);
        int c2 = *(unsigned char*)((char*)_this + 0x322);
        int c3 = *(unsigned char*)((char*)_this + 0x323);
        int c4 = *(unsigned char*)((char*)_this + 0x324);
        int c5 = *(unsigned char*)((char*)_this + 0x325);
        ((void(__fastcall*)(void*,int,int,int,int,int,int,int,int))0x472760)
            (btn, 0, 3, c0, c1, c2, c3, c4, c5);
    }
    return 1;
}
