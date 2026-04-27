// TRIBE_Mission_Screen::~TRIBE_Mission_Screen — real pass (EH-framed)
// VA: 004B87D0
#include "../../include/game_globals.h"

void __fastcall dtor_TRIBE_Mission_Screen(void* _this, int _)
{
    // Sound cleanup if not a game scenario
    if (!*(unsigned char*)((char*)_this + 0x494)) {
        void* bg = rge_base_game;
        void* progInfo = *(void**)((char*)bg + 0x0C);
        int useSound = *(int*)((char*)progInfo + 0x8A8);
        if (useSound) {
            void* soundSys = *(void**)((char*)bg + 0x60);
            if (soundSys)
                ((int(__fastcall*)(void*,int))0x4BC970)(soundSys, 0);  // stop_stream
        }
    }
    // Delete child panels — 4 named + 3 in array
    void** panels[] = {
        (void**)((char*)_this + 0x478),  // title
        (void**)((char*)_this + 0x47C),  // list
        (void**)((char*)_this + 0x480),  // scroll_bar
        (void**)((char*)_this + 0x484),  // ok_button
    };
    int idx;
    for (idx = 0; idx < 4; idx++) {
        void* p = *panels[idx];
        if (p) {
            void* vtbl = *(void**)p;
            ((void(__stdcall*)(int))(*(int*)vtbl))(1);  // vtable[0](1) = deleting dtor
        }
    }
    // 3 text buttons at +0x488..0x490
    for (idx = 0; idx < 3; idx++) {
        void* p = *(void**)((char*)_this + 0x488 + idx * 4);
        if (p) {
            void* vtbl = *(void**)p;
            ((void(__stdcall*)(int))(*(int*)vtbl))(1);  // vtable[0](1)
        }
    }
    // Call base dtor
    ((void(__fastcall*)(void*,int))0x47BAD0)(_this, 0);  // TScreenPanel::~TScreenPanel
}
