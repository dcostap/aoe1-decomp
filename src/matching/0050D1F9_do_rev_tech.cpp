// VA: 0050D1F9 TRIBE_Player_Tech::do_rev_tech (136 B)
// __thiscall, reverse a tech: loop through 4 slots, find matching entries, call sub

struct TRIBE_Player_Tech {
    void* tech_entries;  // +0x00
    short count;         // +0x04
};

extern short do_rev_tech_slot(void* self, short slotEntry);
extern void disable_tech(void* self, short techId);

void TRIBE_Player_Tech_do_rev_tech(void* self, short techId)
{
    int i;
    for (i = 0; i < 4; i++) {
        // Look up entry at tech_entries[techId * 0x3C + i * 2 + 4] -> short
        short* entryBase = (short*)((char*)(*(int*)self) + techId * 0x3C);
        short slotEntry = entryBase[i * 2 + 2]; // offset = techId*0x3C + i*2 + 4
        
        if (slotEntry < 0)
            continue;
        
        // Validate slot entry
        short* slotEntryData = (short*)((char*)(*(int*)self) + slotEntry * 8);
        short entryType = slotEntryData[2]; // offset 4 within 8-byte entry
        if (entryType >= 3)
            continue;
        if (entryType < 0)
            continue;
        
        // Reverse this slot
        do_rev_tech_slot(self, slotEntry);
    }
    
    // Clean up the tech
    disable_tech(self, techId);
}
