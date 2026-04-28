// VA: 0050D1D9 TRIBE_Tech::get_button_location (32 B)
// __thiscall, returns byte at [tech_array + id*0x3C + 0x26]

struct TRIBE_Tech {
    void** tech_array;   // +0x00
    short count;         // +0x04
    void** entries;      // +0x08
};

unsigned char TRIBE_Tech_get_button_location(TRIBE_Tech* self, short id)
{
    void* entryTable = *(void**)self->entries;
    unsigned char* entry = (unsigned char*)((char*)entryTable + id * 0x3C);
    return entry[0x26];
}
