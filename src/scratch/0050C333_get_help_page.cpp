// VA: 0050C333 TRIBE_Player_Tech::get_help_page (57 B)
// __thiscall, return help page entry at id*8+6, or -1 if out of range

struct TRIBE_Player_Tech {
    void* tech_entries;  // +0x00
    short count;         // +0x04
    void* unknown;       // +0x08 (from get_string_id pattern)
};

short TRIBE_Player_Tech_get_help_page(TRIBE_Player_Tech* self, short id)
{
    if (id < 0 || id > self->count)
        return -1;
    
    // Each tech entry is 8 bytes. help page is at entry+6 (word)
    short* entry = (short*)((char*)self->tech_entries + id * 8);
    return entry[3]; // entry[3] = offset 6
}
