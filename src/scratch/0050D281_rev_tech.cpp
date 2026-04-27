// VA: 0050D281 TRIBE_Player_Tech::rev_tech (133 B)
// __thiscall, check tech enable state, if enabled loop through slots and reverse

extern short is_enabled(void* self, short techId);
extern void do_rev_tech(void* self, short techId);

void TRIBE_Player_Tech_rev_tech(void* self, short techId)
{
    // Check if tech is enabled
    short enabled = is_enabled(self, techId);
    if (!enabled)
        return;
    
    int i;
    for (i = 0; i < 4; i++) {
        // Look up slot from tech table
        short* entry = (short*)((char*)(*(int*)self) + techId * 8);
        short slotEntry = entry[i * 2 + 2]; // offset = techId*8 + i*2 + 4
        
        if (slotEntry < 0)
            continue;
        
        // Validate slot entry type
        short* slotData = (short*)((char*)(*(int*)self) + slotEntry * 8);
        if (slotData[2] >= 3) // entry type at offset 4
            continue;
        
        // Reverse the tech in this slot
        do_rev_tech(self, techId);
        break;
    }
}
