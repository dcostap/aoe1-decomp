// TRIBE_Credits_Screen::~TRIBE_Credits_Screen — real pass (EH-framed)
// VA: 00492970
#include "../../include/game_globals.h"

void __fastcall dtor_TRIBE_Credits_Screen(void* _this, int _)
{
    // EH frame skipped
    for (int i = 0; i < 7; i++) {
        void* shape = *(void**)((char*)_this + 0x894 + i * 4);
        if (shape) {
            ((void(__fastcall*)(void*,int))0x4B8DD0)(shape, 0);
            operator delete(shape);
            *(void**)((char*)_this + 0x894 + i * 4) = 0;
        }
    }
    *(int*)((char*)_this + 0x204) = 0;
    void* tp = *(void**)((char*)_this + 0x478);
    if (tp) {
        (*(void(__stdcall**)(int))(*(int*)tp))(1); // vtable[0](1)
        *(void**)((char*)_this + 0x478) = 0;
    }
    void* ms = *(void**)((char*)rge_base_game + 0x64);
    if (ms && *(unsigned char*)((char*)ms + 0x104) == 1 && *(int*)((char*)ms + 0x248) == 0xF) {
        ((void(__fastcall*)(void*,int,int,int,int,int,int))0x462140)(ms, 0, 5, 0x0E, 1, 0, 0);
    }
    ((void(__fastcall*)(void*,int))0x47BAD0)(_this, 0); // TScreenPanel::~TScreenPanel
}
