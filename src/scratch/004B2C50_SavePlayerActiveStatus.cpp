// VA: 004B2C50 TRIBE_Screen_Sed_Open::SavePlayerActiveStatus (383 B)
// PDB source: scr_sed2.cpp
// Packet-grounded: save player active status to scenario, loop over players

extern int StringList_GetCount(void* list);
extern int StringList_Clear(void* list);
extern int StringList_SetString(void* list, int idx, int strId);
extern int RGE_Scenario_Set_player_Active(void* scenario, int player, int active);

void TRIBE_Screen_Sed_Open_SavePlayerActiveStatus(void* self)
{
    // Get number of active strings from list
    int activeCount = StringList_GetCount(*(void**)((char*)self + 0x5B8)) + 1;
    
    // Get scenario pointer
    void* scenario = *(void**)((char*)self + 0x928);
    int numPlayers = *(short*)((char*)scenario + 0x3C) - 1;
    
    // Loop over players and set active status based on activeCount
    int i;
    for (i = 0; i < numPlayers; i++) {
        int isActive = (i < activeCount) ? 1 : 0;
        RGE_Scenario_Set_player_Active(*(void**)((char*)scenario + 0x5C), i, isActive);
    }
    
    // Clear several string lists
    StringList_Clear(*(void**)((char*)self + 0x73C));
    StringList_Clear(*(void**)((char*)self + 0x740));
    StringList_Clear(*(void**)((char*)self + 0x7CC));
    StringList_Clear(*(void**)((char*)self + 0x894));
    StringList_Clear(*(void**)((char*)self + 0x5B4));
    StringList_Clear(*(void**)((char*)self + 0x618));
    
    // Add default strings back
    StringList_SetString(*(void**)((char*)self + 0x618), 0, 0x2776);
    
    if (activeCount > 0) {
        // Add strings for each active player
        for (i = 0; i < activeCount; i++) {
            // Set player-specific name strings
            // ...
        }
    }
}
