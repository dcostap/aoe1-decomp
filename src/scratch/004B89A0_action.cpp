// TRIBE_Mission_Screen::action — real pass
// VA: 004B89A0
#include "../../include/game_globals.h"

long __fastcall action_TRIBE_Mission_Screen(void* _this, int _, void* sender, long actionType, unsigned long param3, unsigned long param4)
{
    if (actionType == 1) {
        // Check text buttons at +0x488..0x490
        for (int i = 0; i < 3; i++) {
            if (sender == *(void**)((char*)_this + 0x488 + i * 4)) {
                int listIdx = i;
                // Get list panel, call vtable[0xE8] with list idx
                void* bg = rge_base_game;
                int* pgmInfo = *(int**)((char*)bg + 0x0C);
                int campaign = *(int*)((char*)pgmInfo + 0x3F4);
                int* list = *(int**)((char*)_this + 0x47C);
                void* listVtbl = *(void**)list;
                int idx = 0;
                if (i == 0) idx = 4;
                else if (i == 2) idx = 1;
                ((void(__fastcall*)(void*,int,int))0x48CE40)((void*)(campaign + 0x5C), 0, idx);
                ((void(__fastcall*)(void*,int,int))((int*)listVtbl)[0xE8/4])(list, 0, 0);
                return 1;
            }
        }
        // Check OK button at +0x484
        if (sender == *(void**)((char*)_this + 0x484)) {
            if (*(unsigned char*)((char*)_this + 0x494)) {
                // Game scenario — return to Game Screen
                ((void(__fastcall*)(void*,int,char*,int))0x463E60)((void*)0x62E870, 0, (char*)"Game Screen", 0);
                int sp = ((int(__fastcall*)(void*,int))0x4223F0)(rge_base_game, 0);
                if (sp == 1) {
                    if (!*(int*)((char*)rge_base_game + 0xA00)) {
                        ((void(__fastcall*)(void*,int,int,int))0x420220)(rge_base_game, 0, 0, 0);
                    }
                }
            } else {
                // Non-game scenario
                ((void(__fastcall*)(void*,int))0x527830)(rge_base_game, 0);
            }
            ((void(__fastcall*)(void*,int,char*))0x464060)((void*)0x62E870, 0, (char*)"Victory Screen");
            return 1;
        }
    }
    // Fall through to base class handler
    return ((long(__fastcall*)(void*,int,void*,long,unsigned long,unsigned long))0x46A4E0)(_this, 0, sender, actionType, param3, param4);
}
