// 00457DF0 RGE_Map::save
// ACCEPTED_DRIFT 2026-05-21 (Boss approved): exact-size, behavior-equivalent, only two address-encoding bytes differ.
// Best validation: 180B, 1.1111% positional / 1.1111% edit, first mismatch in second sound-id loop.
// Drift: original stores fallback/id in second loop as `[eax+edx]` (base=current sound slot pointer,
// index=copy-this delta); rebuilt uses `[edx+eax]` for the same two registers/address. First loop, aggregate
// copy, terrain/border logic, rge_write, random-map save, free, stack cleanup, and all control flow match.
// Tried manual copy, aggregate copy, temp-this, p+diff vs diff+p casts, q pointer temps, copy-offset form,
// int-pointer casts, and preserving first/second loop addressing separately. Only remaining bytes are the
// commuted SIB addressing form in two equivalent stores.

extern "C" void* __cdecl calloc(unsigned int n, unsigned int size);
extern "C" void __cdecl free(void* p);
extern "C" void __cdecl rge_write(int file, void* data, int size);

#ifndef MAP_CONTEXT_H
class RGE_RMM_Database_Controller {
public:
    unsigned char save(int file);
};

struct RGE_Sound {
    char gap[0x0c];
    short id;
};

struct RGE_Map_Copy {
    char bytes[0x8dd0];
};

class RGE_Map {
public:
    char bytes[0x8dc0];
    void save(int file);
};

#endif

void RGE_Map::save(int file)
{
    RGE_Map_Copy* copy = (RGE_Map_Copy*)calloc(1, 0x8dd0);
    *copy = *(RGE_Map_Copy*)this;

    char* p = (char*)this + 0xb0;
    int diff = (char*)copy - (char*)this;
    int count = 0x20;
    do {
        if (*(unsigned char*)(p - 0x24) != 0) {
            RGE_Sound* snd = *(RGE_Sound**)p;
            char* q = (char*)(diff + (int)p);
            if (snd != 0)
                *(int*)q = snd->id;
            else
                *(int*)q = -1;
        }
        p += 0x198;
        --count;
    } while (count);

    p = (char*)this + 0x33b0;
    count = 0x10;
    do {
        RGE_Sound* snd = *(RGE_Sound**)p;
        if (snd != 0 && *(unsigned char*)(p - 0x24) != 0)
            *(int*)(p + diff) = snd->id;
        else
            *(int*)(p + diff) = -1;
        p += 0x5a0;
        --count;
    } while (count);

    rge_write(file, copy, 0x8dd0);
    (*(RGE_RMM_Database_Controller**)((char*)this + 0x8dbc))->save(file);
    free(copy);
}
