// TRIBE_Screen_Name::get_player_names — real pass
// VA: 004A6800
#include "../../include/game_globals.h"

void __fastcall get_player_names(void* _this, int _)
{
    void* nameList = *(void**)((char*)_this + 0x480);
    ((void(__fastcall*)(void*,int))0x47E370)(nameList, 0);
    
    void* bg = (void*)rge_base_game;
    void* gameInfo = *(void**)((char*)bg + 4);
    char** players = 0;
    long currIdx = 0;
    int numPlayers = ((int(__fastcall*)(void*,int,char***,long*))0x44D850)(gameInfo, 0, &players, &currIdx);
    if (!numPlayers) return;
    
    *(int*)((char*)nameList + 0x15C) = 1;
    
    int i;
    for (i = 0; i < numPlayers; i++)
        ((int(__fastcall*)(void*,int,int,void*))0x47DCD0)(nameList, 0, i, (void*)players[i]);
    
    long line = ((long(__fastcall*)(void*,int,long))0x47E200)(nameList, 0, currIdx);
    ((void(__fastcall*)(void*,int,long))0x47DC80)(nameList, 0, line);
    
    for (i = 0; i < numPlayers; i++)
        ((void(__fastcall*)(void*,int))0x54B7D0)((void*)players[i], 0);
    ((void(__fastcall*)(void*,int))0x54B7D0)((void*)players, 0);
}
