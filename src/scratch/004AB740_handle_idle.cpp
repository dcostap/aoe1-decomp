// TRIBE_Screen_Sed::handle_idle — first pass
// VA: 004AB740
#include "../../include/game_globals.h"

extern int __fastcall debug_timeGetTime(char* file, int line);
extern void* __fastcall modalPanel(void* sys);
extern long __fastcall panelHandleIdle(void* _this);

long __fastcall handle_idle(void* _this, int _)
{
    if (*(int*)((char*)rge_base_game + 0x1B0) == 7) {
        int t = debug_timeGetTime("scr_sed.cpp", 0x8B1);
        int diff = *(int*)((char*)_this + 0x930) - t;
        if (diff >= *(int*)((char*)_this + 0x92C)) {
            void* mod = modalPanel((void*)0x62E870);
            if (!mod) {
                void* vw = *(void**)((char*)_this + 0x4C8);
                ((void (__stdcall*)(int))*(void**)(*(int*)vw + 0x20))(1);
                if (*(int*)((char*)_this + 0x938) - t >= *(int*)((char*)_this + 0x934)) {
                    void* mv = *(void**)((char*)_this + 0x4CC);
                    ((void (__stdcall*)(int))*(void**)(*(int*)mv + 0x20))(1);
                    *(int*)((char*)_this + 0x938) = t;
                }
            }
        }
    }
    return panelHandleIdle(_this);
}
