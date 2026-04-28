// VA: 0050D1B8 TRIBE_Tech::get_string_id2 (33 B)
// __thiscall, returns short at [tech_array + id*0x3C + 0x2C]

struct TRIBE_Tech {
    void** tech_array;   // +0x00
    short count;         // +0x04
    void** entries;      // +0x08
};

short TRIBE_Tech_get_string_id2(TRIBE_Tech* self, short id)
{
    // Get entry from secondary table, then index into tech_array
    void* entryTable = *(void**)self->entries;
    short* entry = (short*)((char*)entryTable + id * 0x3C);
    return entry[0x2C / 2]; // word at +0x2C
}
