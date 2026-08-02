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
// Retry 2026-05-24 assigned pass: 13 more probes. Volatile zero locals produced exact size but
// broad wrong frame/register family (98.8372% positional). register zeros, direct-zero fail path,
// direct-copy found path, struct-entry typed row, while <=255, unsigned i, and flags /Ob0 /Oa
// /G5 /O1 /Og all stayed in too-short 144/153/160 byte families. memcpy done path was exact size
// but broad wrong stack-copy family. No accepted_drift: best behavioral source is 12 bytes short,
// while exact-size variants are broad topology mismatches.
// Retry 2026-05-26 Boss pass: 16 probes on VA 00510020 only. Revalidated kept source: 160B for
// 172B target. Tried direct found-path copy, register/volatile zeros (volatile exact-size but
// 97.0930% positional byte-0 mismatch), while/nested-if loop, typed CliffEntry row, <=255 and
// unsigned loop counters, struct temp, memcpy copy, recomputed found-index source, true struct
// return-by-value signature, dummy locals, and flags /Ob0 /G5 /Oa /Og /Oy- /O1 /Od /Zp1. Close
// behavioral families remain 144/160B; exact-size variants are broad wrong frame/register/copy
// topology. GIVEUP: not accepted_drift quality; mismatch is structural register allocation and
// hidden-return/copy layout, not localized equivalent drift.
// Retry 2026-08-02 Luna-510020 (10/10): baseline rebuilt 159B/154 diff. Reconstructed the
// true struct-return ABI, Ghidra-style bounded scan, and initialized aggregate; the direct
// aggregate form reached exact size 172B (155 diff, 58.4% shape). A four-form zero-init lab
// was one variant family (all 172B/155 diff). Restoring the RGE_Map base was codegen-neutral.
// Deriving the copied row from the loop index and the typed 40-byte cliff table exposed the
// original LEA index topology (shape 63.9%, 178B/164 diff); direct aggregate return improved
// it to 72.2% shape, 176B/164 diff, edit diff 97. Register-qualified zeros were codegen-neutral.
// Best current source keeps the true return ABI, index-derived typed row, and direct aggregate
// return. Remaining mismatch is the original four-save/zero-register basin (EBP/EBX/EDX/ESI)
// and delayed EDI pop; no accepted-drift promotion.

#include <string.h>

struct TRIBE_Cliff_Info {
    int info[4];
};

struct TRIBE_Master_Cliff_Info {
    int id;
    int facet;
    int id2;
    int facet2;
    TRIBE_Cliff_Info info;
    float offset_x;
    float offset_y;
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

class RGE_Map {
public:
    char gap_00[0x08];
    long map_width;
    long map_height;
    char gap_10[0x8D7C];
    void* map_row_offset;
};

class TRIBE_Map : public RGE_Map {
public:
    char gap_8D90[0x68];
    TRIBE_Master_Cliff_Info cliff_master_table[256];

    TRIBE_Cliff_Info get_cliff_info(RGE_Static_Object* obj);
};

TRIBE_Cliff_Info TRIBE_Map::get_cliff_info(RGE_Static_Object* obj) {
    register int z0 = 0;
    register int z1 = 0;
    register int z2 = 0;
    register int z3 = 0;
    TRIBE_Cliff_Info ret = {z0, z1, z2, z3};

    if (obj == 0) {
        return ret;
    }

    int facet = (int)obj->facet;
    int masterObjId = (int)obj->master_obj->id;
    int* entryPtr = (int*)((char*)this + 0x8DFC);
    int i = 0;

    while ((entryPtr[-1] != masterObjId || entryPtr[0] != facet) &&
           (entryPtr[1] != masterObjId || entryPtr[2] != facet)) {
        ++i;
        entryPtr += 10;
        if (i > 255) {
            ret.info[0] = z0;
            ret.info[1] = z1;
            ret.info[2] = z2;
            ret.info[3] = z3;
            return ret;
        }
    }

    return this->cliff_master_table[i].info;
}
