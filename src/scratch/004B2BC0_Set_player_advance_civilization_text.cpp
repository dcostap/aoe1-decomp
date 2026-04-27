// TRIBE_Screen_Sed::Set_player_advance_civilization_text — real pass
// VA: 004B2BC0
#include "../../include/game_globals.h"

int __fastcall Set_player_advance_civilization_text(void* _this, int _)
{
    void* drop = *(void**)((char*)_this + 0x5BC);
    ((void(__fastcall*)(void*,int))0x475460)(drop, 0);        // empty_list
    ((int(__fastcall*)(void*,int,int,int))0x4752D0)(drop, 0, 0x1069, 0); // Stone Age
    ((int(__fastcall*)(void*,int,int,int))0x4752D0)(drop, 0, 0x106A, 1); // Tool Age
    ((int(__fastcall*)(void*,int,int,int))0x4752D0)(drop, 0, 0x106B, 2); // Bronze Age
    ((int(__fastcall*)(void*,int,int,int))0x4752D0)(drop, 0, 0x106C, 3); // Iron Age
    ((int(__fastcall*)(void*,int,int,int))0x4752D0)(drop, 0, 0x106D, 4); // Post-Iron Age
    ((void(__fastcall*)(void*,int,int))0x475150)(drop, 0, 0); // setCurrentLineNumber
    (*(void(__stdcall**)(int))(*(int*)drop))(0);               // vtable[0x14](0)
    return 1;
}
