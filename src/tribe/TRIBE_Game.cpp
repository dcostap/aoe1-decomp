#include "TRIBE_Game.h"
#include <stdio.h>

// Address: 004549e0
TRIBE_Game::TRIBE_Game(RGE_Prog_Info* info, int setup) 
    : RGE_Base_Game(info, setup) 
{
    printf("[DECOMP] TRIBE_Game constructor called at 0x004549e0\n");
    
    // Member initialization as found in the constructor decompilation
    this->started_menu_music = 0;
    this->show_object_id = 0;
    this->inHandleIdle = 0;
    this->handleIdleLock = nullptr;
    
    // We will fill more of this as we decompile further
}