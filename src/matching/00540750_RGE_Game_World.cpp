// public: __thiscall RGE_Game_World::RGE_Game_World(void)
// VA: 00540750
// PDB-qualified owner/name: public: __thiscall RGE_Game_World::RGE_Game_World(void)
// PDB source: World.cpp:138-221
// Original body boundary: 00540750-00540A0B; next symbol: 00540A40.
// 00540700 is the separate vw_main.cpp sibling and ends at 00540747.
// Attempt log:
// 1: natural constructor from packet with local layout and RGE_Object_List new calls; /GX required for original EH frame but local layout was shifted.
// 2: switched to byte-offset field accesses to preserve proven RGE_Game_World offsets.
// Exact-finish: the current source is the reduced exact reconstruction.  The
// typed full World.cpp class probe moved the vftable store to entry and changed
// 42 bytes, so it was restored.  The current narrow surface keeps the proven
// constructor ABI and direct RGE_Object_List calls.
// BINARY NOTE: The first two allocations publish objectsValue before the seven
// separate list allocations.  The repeated guarded constructor blocks preserve
// exception cleanup state and fault order.  The observed field widths and all
// byte offsets come from the target's this-relative stores.

#include <stdio.h>

void* __cdecl operator new(unsigned int);
extern "C" FILE* __cdecl fopen(const char*, const char*);

#define world_update_counter (*(int*)0x00886C10)
#define VIS_UNIT_objectsValue (*(void**)0x0087D7FC)
#define DVlogf (*(FILE**)0x00886C58)
#define I(off) (*(int*)((char*)this + (off)))
#define S(off) (*(short*)((char*)this + (off)))
#define B(off) (*(unsigned char*)((char*)this + (off)))
#define P(off) (*(void**)((char*)this + (off)))
#define L(off) (*(RGE_Object_List**)((char*)this + (off)))

class RGE_Object_List {
public:
    virtual void load(unsigned char, int, void*);
    int count;
    void* nodes;
    RGE_Object_List();
};

class RGE_Game_World {
public:
    virtual void v0();
    RGE_Game_World();
};

RGE_Game_World::RGE_Game_World()
{
    P(0x88) = 0;
    I(0x8c) = 0;
    I(0x90) = 10000;
    P(0x94) = 0;
    I(0x98) = 0;
    I(0x9c) = 1000;
    I(0xf4) = 2;
    I(0xf8) = 2;
    I(0xfc) = -1;
    I(0x100) = -1;
    *(int*)this = 0x00577910;
    world_update_counter = 0;
    P(0x88) = operator new(I(0x90) * 4);
    P(0x94) = operator new(I(0x9c) * 4);
    VIS_UNIT_objectsValue = P(0x88);
    P(0xa0) = 0;
    S(0x2c) = 0;
    P(0x30) = 0;
    S(0x34) = 0;
    P(0x38) = 0;
    S(0x3c) = 0;
    P(0x40) = 0;
    S(0x44) = 0;
    P(0x48) = 0;
    S(0x50) = 0;
    P(0x54) = 0;
    S(0x60) = 0;
    P(0x64) = 0;
    I(0x58) = 0;
    I(0x5c) = 0;
    P(0x4c) = 0;
    P(0x28) = 0;
    P(0x04) = 0;
    P(0x08) = 0;
    P(0x0c) = 0;
    P(0x84) = 0;
    I(0x10) = 0;
    I(0x14) = 0;
    I(0x18) = 0;
    B(0x1c) = 0;
    I(0x68) = 0;
    I(0x6c) = -1;
    I(0x78) = 14;
    S(0x7c) = 1;
    P(0x80) = 0;
    B(0x1d) = 2;
    B(0x1e) = 0;
    I(0x20) = 0;
    I(0x24) = 0;
    I(0xb0) = 0;
    for (int i = 0; i < 9; i++) {
        I(0xb4 + i * 4) = 0;
    }
    L(0xd8) = new RGE_Object_List;
    L(0xdc) = new RGE_Object_List;
    L(0xe0) = new RGE_Object_List;
    L(0xe4) = new RGE_Object_List;
    L(0xe8) = new RGE_Object_List;
    L(0xec) = new RGE_Object_List;
    L(0xf0) = new RGE_Object_List;
    B(0x74) = 0;
    if (DVlogf == 0) {
        DVlogf = fopen("c:\\aoeWVlog.txt", "w");
    }
}
