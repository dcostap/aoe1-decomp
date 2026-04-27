// VA: 00521120 TRIBE_Game::TRIBE_Game (599 B)
// PDB source: tribegam.cpp
// Packet-grounded: EH-framed, call RGE_Base_Game init, zero fields, set vtable

extern void RGE_Base_Game_RGE_Base_Game(void* self, void* appState);

void* panel_system_find;  // 0x62E87C

void* TRIBE_Game_ctor(void* self, void* appState)
{
    // EH frame via FS:[0]
    
    // Call RGE_Base_Game constructor
    RGE_Base_Game_RGE_Base_Game(self, appState);
    
    // Zero-initialize many fields from +0xBEC to +0xC24
    int* p = (int*)((char*)self + 0xBEC);
    int i;
    for (i = 0; i < 26; i++)
        p[i] = 0;
    *(int*)((char*)self + 0x1250) = 0;
    
    // Set vtable to 0x5771A8
    *(int**)self = (int*)0x5771A8;
    
    // Set base class fields via RGE_Base_Game
    // ...
    
    // Zero out additional byte fields
    *(unsigned char*)((char*)self + 0xAE8) = 0;
    *(unsigned char*)((char*)self + 0xC58) = 0;
    *(unsigned char*)((char*)self + 0xD5C) = 0;
    *(unsigned char*)((char*)self + 0xE64) = 0;
    *(unsigned char*)((char*)self + 0xF68) = 0;
    *(int*)((char*)self + 0xE60) = 0;
    *(unsigned char*)((char*)self + 0x106C) = 0;
    
    // Zero globals
    *(int*)0x86BCD4 = 0;
    *(int*)0x62C560 = 0;
    *(int*)0x62C564 = 0;
    
    // Set mode to 0
    *(int*)((char*)self + 0x1B0) = 0;
    *(int*)((char*)self + 0x1B4) = 0;
    
    // Find panel system
    *(void**)((char*)self + 0x1A8) = panel_system_find;
    
    // More field init
    // ...
    
    return self;
}
