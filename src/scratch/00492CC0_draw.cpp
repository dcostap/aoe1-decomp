// TRIBE_Credits_Screen::draw — real pass
// VA: 00492CC0
#include "../../include/game_globals.h"

void __fastcall draw_credits(void* _this, int _)
{
    if (*(int*)((char*)_this + 0x48C) == 4) {
        void* screen = *(void**)((char*)_this + 0x20);
        void* vtable = *(void**)screen;
        if (*(unsigned char*)((char*)vtable + 0x479) == 2 || *(unsigned char*)((char*)vtable + 0x478) == 1) {
            ((void(__fastcall*)(void*,int,void*))0x444680)(0, 0, (char*)_this + 0x24);
            return;
        }
    }
    if (*(void**)((char*)_this + 0x8B0)) {
        for (int i = 0; i < 7; i++) {
            void* shape = *(void**)((char*)_this + 0x894 + i * 4);
            *(void**)((char*)_this + 0x204) = shape;
            ((void(__fastcall*)(void*,int))0x47BB40)(_this, 0);
        }
        *(void**)((char*)_this + 0x8B0) = 0;
        void* shape = *(void**)((char*)_this + 0x894);
        *(void**)((char*)_this + 0x204) = shape;
    }
    ((void(__fastcall*)(void*,int))0x47BB40)(_this, 0);
}
