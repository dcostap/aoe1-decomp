// VA: 0050D306 TRIBE_Player_Tech::disable (125 B)
// __thiscall, set tech entries to disabled: either specific id or all

struct TRIBE_Player_Tech {
    void** tech_entries; // +0x00
    short count;         // +0x04
};

void TRIBE_Player_Tech_disable(TRIBE_Player_Tech* self, short techId)
{
    if (techId < 0) {
        // Disable all techs in table
        int i;
        for (i = 0; i < self->count; i++) {
            short* entry = (short*)((char*)self->tech_entries + i * 8);
            short entryType = entry[2]; // word at +4
            if (entryType != 3) {
                entry[2] = -1; // set to disabled
            }
        }
    } else {
        // Disable specific tech
        short* entry = (short*)((char*)self->tech_entries + techId * 8);
        short entryType = entry[2]; // word at +4
        if (entryType != 3) {
            entry[2] = -1; // set to disabled
        }
    }
}
