// VA: 0052E4C0 TRIBE_World::map_init(int, TSound_Driver*)
// PDB source: tworld.cpp lines 249-252 (97 bytes, 30 asm lines)
// FLAGS: /GX
//
// __thiscall: this in ecx, 2 stack params. ret 8 cleanup.
// SEH-framed, allocates TRIBE_Map (0xB5F8 bytes), constructs if non-null,
// stores at this->map (+0x28).
//
// Left in scratch: 87/97 edit-match bytes (21.9% positional diff).
// Same null-path shared-epilogue issue as 005414A0, 00541BC0, 0052E920, 00541B60.
// Original has jmp + shared epilogue for null path; VC5 generates separate paths.
// 2026-05-09 GraniteCub: tried 19 focused variants: local/direct assignment,
// explicit if/goto/common-store forms, two-stage result, field_30/param/this locals,
// assignment-in-if/comma/volatile local, no-virtual map surface, void*/int map member,
// ctor flag/arg signature changes, and brief /O1+/GX probe. Same blocker as nearby
// EH new helpers: direct new keeps exact EH/new/ctor family but sinks store into
// success path; artificial `if (p == 0) p = 0;` reaches closer common-store basin
// (16 positional/11 edit) but inserts a redundant post-merge test before store.
// Left cleaner direct-new source. No inline asm/hacks.
//
// Field layout:
//   map     @ +0x28 (TRIBE_Map*)
//   field_30 @ +0x30 (void*, passed to TRIBE_Map ctor as 2nd arg)
//
// TRIBE_Map::TRIBE_Map(new_obj, param_1, this->field_30, 1)

class TRIBE_Map {
public:
    char gap_00[0xB5F8 - 4];
    virtual ~TRIBE_Map();
    TRIBE_Map(int param_1, void* sound, int flag);
};

class TRIBE_World {
public:
    char gap_00[0x28];
    TRIBE_Map* map;            // +0x28
    char gap_2C[0x30 - 0x2C];
    void* field_30;            // +0x30 (passed to TRIBE_Map ctor)

    void map_init(int param_1, void* param_2);
};

void TRIBE_World::map_init(int param_1, void* param_2) {
    this->map = new TRIBE_Map(param_1, this->field_30, 1);
}
