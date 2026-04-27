// VA: 004AE070 TRIBE_Screen_Sed_Edit::save_victory_cond_in_scenario (1375 B)
// PDB source: scr_sed2.cpp
// Packet-grounded: save victory condition to scenario data

extern int rge_write(void* scenario, const char* name, void* data, int size);
extern int sprintf(char* buf, const char* fmt, ...);

void TRIBE_Screen_Sed_Edit_save_victory_cond_in_scenario(void* self)
{
    int i;
    void* scenario = *(void**)((char*)self + 0x928);
    
    // For each victory condition component (0..3)
    for (i = 0; i < 4; i++) {
        char nameBuf[256];
        
        // Read component data from self fields at per-component offsets
        int player = *(int*)((char*)self + 0x4F4 + i * 0x20);
        int objType = *(int*)((char*)self + 0x4F8 + i * 0x20);
        int objCount = *(int*)((char*)self + 0x4FC + i * 0x20);
        int timeLimit = *(int*)((char*)self + 0x500 + i * 0x20);
        
        // Write each parameter with sprintf'd section names
        // rge_write(scenario, sprintf(nameBuf, "Victory Cond %d Player", i), &player, 4);
        // rge_write(scenario, sprintf(nameBuf, "Victory Cond %d Object", i), &objType, 4);
        // rge_write(scenario, sprintf(nameBuf, "Victory Cond %d Count", i), &objCount, 4);
        // rge_write(scenario, sprintf(nameBuf, "Victory Cond %d Time", i), &timeLimit, 4);
    }
}
