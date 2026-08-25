// VA: 0052E4C0 TRIBE_World::map_init(int, TSound_Driver*)
// PDB source: tworld.cpp lines 249-252 (97 bytes, 30 asm lines)
// FLAGS: /GX
//
// __thiscall: this in ecx, 2 stack params. ret 8 cleanup.
// SEH-framed, allocates TRIBE_Map (0xB5F8 bytes), constructs if non-null,
// stores at this->map (+0x28).
//
// === ACCEPTED_DRIFT ===
// 2026-05-12: Switched from direct-new (21.65% pos, sunk-store) to common-store
// self-assign form (16.49% pos/11.34% edit) matching the accepted_drift pattern
// in 00541C90/00541BC0/00541B60. Same VC5 /GX new-expression + EH lowering
// artifact: first N bytes exact (prologue, new, null test, ctor, jmp, xor), then
// dead zero-displacement `test eax,eax; jne +0` at the common-store join. Accepted
// as behavior-neutral; it only shifts/truncates epilogue into padding.
//
// Attempt log (prior passes):
// - GraniteCub: 19 focused variants — local/direct, explicit if/goto/common-store,
//   two-stage result, field_30/param/this locals, assignment-in-if/comma/volatile,
//   no-virtual map surface, void*/int map member, ctor flag/arg changes, /O1+/GX.
//   Direct new keeps exact EH/new/ctor but sinks store into success path.
//   Common-store forms reach closer basin but insert redundant post-merge test.
// - LemonLily: 12 more — plain/direct/volatile, explicit null/self-assign, goto,
//   if/else, ternary, slot pointer, field_30 local, dummy param_2, flag local.
//   Flag probes: /Oa, /Ow, /Ot, /Ox, /O1 with /GX. No exact.
//   2026-05-10: 15 more — local/null common-store, unqualified store, goto, empty
//   else, slot-after-new, field/param/flag locals, if-store-arms, ternary,
//   plain/void/int map member, placement-new, flags /Ob0 /Og /Oa /Ot /G5 /Ox /O1
//   /Oy-. No exact.
// 2026-05-12: Verified same artifact as accepted_drift siblings. Common-store
// form is the best basin (16.49%/11.34%). Recommended accepted_drift per Boss ruling.
//
// Field layout:
//   map     @ +0x28 (TRIBE_Map*)
//   field_30 @ +0x30 (void*, passed to TRIBE_Map ctor as 2nd arg)

#ifndef TWORLD_PHASE2_CONTEXT
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
#endif

#ifdef TWORLD_PHASE2_CONTEXT
void TRIBE_World::map_init(int param_1, TSound_Driver* param_2) {
#else
void TRIBE_World::map_init(int param_1, void* param_2) {
#endif
    TRIBE_Map* p = new TRIBE_Map(param_1, this->field_30, 1);
    if (p == 0) {
        p = 0;
    }
#ifdef TWORLD_PHASE2_CONTEXT
    this->map = (RGE_Map*)p;
#else
    this->map = p;
#endif
}
