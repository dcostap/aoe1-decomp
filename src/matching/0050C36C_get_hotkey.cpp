// VA: 0050C36C TRIBE_Player_Tech::get_hotkey (57 B)
// __thiscall, return hotkey at id*8+0, or -1 if out of range

struct TRIBE_Player_Tech {
    void* tech_entries;  // +0x00
    short count;         // +0x04
};

short TRIBE_Player_Tech_get_hotkey(TRIBE_Player_Tech* self, short id)
{
    if (id < 0 || id > self->count)
        return -1;
    
    // Each tech entry is 8 bytes. hotkey is at entry+0 (word)
    short* entry = (short*)((char*)self->tech_entries + id * 8);
    return entry[0];
}
