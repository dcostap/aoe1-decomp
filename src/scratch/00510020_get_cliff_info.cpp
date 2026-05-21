// VA: 00510020 TRIBE_Map::get_cliff_info
// tmap.cpp:489-515
//
// Attempt log:
// v0: struct TRIBE_Cliff_Info + int* entryPtr loop -> 144 bytes (2 reg saves)
// v1: added four zero vars (z0..z3) -> 160 bytes (3 reg saves + stack temp)
// v2: nested if format -> 144 bytes
// v3: Ghidra-style while loop -> 144 bytes
// v4: shared 'done' label with z0..z3 overwrite -> 160 bytes
// v5-v9: varied struct/array access, type casts, variable ordering -> 144-160 bytes
// tried natural C++ struct return by value; still 144-byte compact family.
// tried full RGE_Map base surface from matched find_cliff donor; no change to compact family.
// tried direct found-path copy instead of z-overwrite/goto; produced 128-byte compact family.
// tried /Ob0 (no change) and /Og- (wrong broad family); removed flags.
//
// Remaining gap: register allocation. Original uses ebx/ebp/esi/edi (4 callee-saved)
// as zero constants + working registers. VC5 in all probes uses 2-3 saves + stack temps
// or a too-compact no-match family. The core issue is VC5's register allocator choosing
// not to use ebx/ebp as callee-saved zero registers in this isolated TU context.
// Behavior, loop structure, and memory effects are understood; left in scratch.

#include <string.h>

struct TRIBE_Cliff_Info {
    int info[4];
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;  // +0x10
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;  // +0x08
    char gap_0C[0x29];                     // +0x0C..+0x34
    unsigned char facet;                   // +0x35
};

class TRIBE_Map {
public:
    char gap_00[0x8DF8];

    TRIBE_Cliff_Info* get_cliff_info(TRIBE_Cliff_Info* ret, RGE_Static_Object* obj);
};

TRIBE_Cliff_Info* TRIBE_Map::get_cliff_info(TRIBE_Cliff_Info* ret, RGE_Static_Object* obj) {
    int z0 = 0;
    int z1 = 0;
    int z2 = 0;
    int z3 = 0;

    if (obj == 0) {
        ret->info[0] = z0;
        ret->info[1] = z1;
        ret->info[2] = z2;
        ret->info[3] = z3;
        return ret;
    }

    int facet = (int)obj->facet;
    int masterObjId = (int)obj->master_obj->id;
    int* entryPtr = (int*)((char*)this + 0x8DFC);
    int i;

    for (i = 0; i < 256; i++) {
        if (entryPtr[-1] == masterObjId && entryPtr[0] == facet) {
            z0 = entryPtr[3]; z1 = entryPtr[4]; z2 = entryPtr[5]; z3 = entryPtr[6];
            goto done;
        }
        if (entryPtr[1] == masterObjId && entryPtr[2] == facet) {
            z0 = entryPtr[3]; z1 = entryPtr[4]; z2 = entryPtr[5]; z3 = entryPtr[6];
            goto done;
        }
        entryPtr += 10;
    }

done:
    ret->info[0] = z0;
    ret->info[1] = z1;
    ret->info[2] = z2;
    ret->info[3] = z3;
    return ret;
}
