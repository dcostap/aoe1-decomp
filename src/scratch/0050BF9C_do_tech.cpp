// VA: 0050BF9C TRIBE_Tech::do_tech (81 B)
// __thiscall, check effect field at [tech_array + idx*0x3C + 0x20], if >= 0 call player tech vtable

extern void free(void* p);

struct TRIBE_Tech {
    void** tech_array;   // +0x00
    short count;         // +0x04
    void* rge_player;    // +0x08
};

unsigned char TRIBE_Tech_do_tech(TRIBE_Tech* self, short idx, void* player)
{
    // Check if tech entry's effect field (at +0x20 within 0x3C entry) is valid
    short* entry = (short*)((char*)self->tech_array + idx * 0x3C);
    short effect = entry[0x20 / 2];
    
    if (effect < 0)
        return 1;
    
    // Call world player tech application via vtable
    void* playerTech = *(void**)((char*)self->rge_player + 0x4C);
    void** vtable = *(void***)playerTech;
    typedef void (*ApplyFunc)(void*, short, void*);
    ((ApplyFunc)vtable[2])(playerTech, entry[0x20 / 2], player);
    return 1;
}
