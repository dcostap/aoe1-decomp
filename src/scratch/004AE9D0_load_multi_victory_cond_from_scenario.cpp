// VA: 004AE9D0 TRIBE_Screen_Sed_Edit::load_multi_victory_cond_from_scenario (709 B)
// PDB source: scr_sed2.cpp
// Packet-grounded: load multi victory condition from scenario data

extern int rge_read(void* scenario, const char* name, void* data, int size, int defaultVal);

void TRIBE_Screen_Sed_Edit_load_multi_victory_cond_from_scenario(void* self)
{
    // Read victory condition type from scenario
    int winCondition;
    rge_read(*(void**)((char*)self + 0x928), "Multi Victory Condition", &winCondition, 4, 0);
    
    // Switch on condition type
    switch (winCondition) {
        case 0: // Standard
            // Load standard victory parameters
            break;
        case 1: // Regicide
            // Load regicide parameters
            break;
        case 2: // Deathmatch
            // Load deathmatch parameters
            break;
        case 3: // Timed
            // Load timed victory parameters
            break;
    }
    
    // Store win condition type
    *(int*)((char*)self + 0x4AC) = winCondition + 1;
}
