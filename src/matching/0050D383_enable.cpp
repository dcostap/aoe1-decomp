// VA: 0050D383 TRIBE_Player_Tech::enable (125 B)
// __thiscall, set tech entries to enabled: either specific id or all

struct TRIBE_Player_Tech {
    void** tech_entries; // +0x00
    short count;         // +0x04
};

void TRIBE_Player_Tech_enable(TRIBE_Player_Tech* self, short techId)
{
    if (techId < 0) {
        // Enable all techs in table
        int i;
        for (i = 0; i < self->count; i++) {
            short* entry = (short*)((char*)self->tech_entries + i * 8);
            short entryType = entry[2]; // word at +4
            if (entryType != 3) {
                entry[2] = 0; // set to enabled
            }
        }
    } else {
        // Enable specific tech
        short* entry = (short*)((char*)self->tech_entries + techId * 8);
        short entryType = entry[2]; // word at +4
        if (entryType != 3) {
            entry[2] = 0; // set to enabled
        }
    }
}
