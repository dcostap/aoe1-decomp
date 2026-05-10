// VA: 00485240 RGE_RMM_Land_Generator::generate
// rmm_land.cpp lines 33-51
//
// Attempt log:
// - SpruceGlow tried 24 variants: natural memset/set_terrain/clean_terrain with corrected member layout, width/height
//   argument order swaps, raw offset accesses, manual byte and dword fill loops, local value/count temporaries,
//   signed/unsigned char terrain fields, alternate memset prototypes/includes, staged count/value expressions,
//   volatile value temps, and raw signed/unsigned byte value loads.
// - Behavior and call surface are understood. Best current source is the raw-offset/memset family: it gets the same
//   calls, field offsets, fill operation, and return, but VC5 schedules the memset setup differently: rebuilt emits
//   `xor eax,eax` / value load order and moves the set_terrain trailing pushes relative to the REP fill differently.
// - Best observed: positional diff 96/133, edit diff 31, first mismatch offset 12. Not an accepted_drift suggestion:
//   broad scheduling/layout drift through the fill and set_terrain setup remains.

extern "C" void* memset(void* dst, int value, unsigned int size);

class RGE_Map {
public:
    void set_terrain(void* player, void* world, int a, int b, short x, short y,
                     unsigned char terrain, unsigned char flag1, unsigned char flag2);
    void clean_terrain(long x, long y, long w, long h, unsigned char terrain);
};

class RGE_Random_Map_Module {
public:
    void clear_stack();
};

class RGE_RMM_Land_Generator : public RGE_Random_Map_Module {
public:
    unsigned char generate();
    unsigned char base_land_generate();
};

unsigned char RGE_RMM_Land_Generator::generate() {
    this->clear_stack();

    memset(*(void**)((char*)this + 0x20),
           *(unsigned char*)((char*)this + 0x144C),
           *(int*)((char*)this + 0x14) * *(int*)((char*)this + 0x18));

    (*(RGE_Map**)((char*)this + 0x0C))->set_terrain(
        0, 0, 0, 0,
        (short)(*(int*)((char*)this + 0x14) - 1),
        (short)(*(int*)((char*)this + 0x18) - 1),
        *(unsigned char*)((char*)this + 0x1450),
        1,
        0);

    this->base_land_generate();

    (*(RGE_Map**)((char*)this + 0x0C))->clean_terrain(
        0,
        0,
        *(int*)((char*)this + 0x14),
        *(int*)((char*)this + 0x18),
        *(unsigned char*)((char*)this + 0x1450));

    return 1;
}
