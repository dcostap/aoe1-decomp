// VA: 005325A0 RGE_Victory_Conditions::handle_bring_area(RGE_Victory_Entry*)
// PDB source: victory.cpp lines 663-686
// Default flags
//
// __thiscall: this in ecx (unused), entry param on stack at [esp+4].
// Function overwrites ecx with entry pointer, never uses this.
// ret 4 for one stack parameter.
//
// attempt log:
// The FPU bounds-check section matches byte-for-byte (4x fld/fcomp/fnstsw/test
// sequences with correct test ah,1/test ah,41h for < and > comparisons).
// State_done code also matches (mov al,[ecx+2Eh]; test al,al; jne + mov/c7/c2).
// - Initial scratch had null check inline and block ordering reversed: VC5 emitted `jne` skip-over-null and put
//   bounds inline while original uses `je` to null tail and puts state_done inline before bounds label.
// - SpruceGlow try 1 MATCH: write the main body as `if (obj) { ... } else { state=3; return; }`, with the
//   state_done arm (`object_state >= 3`) before bounds. This forces the original `je` null tail and `jb` to
//   bounds block while preserving the FPU compare sequence.
// Result: MATCH locally with `python tools/check_function.py --va 005325A0`.
// - Prefix pass: a controlled float view of the proven +0x18 y2 storage preserved standalone MATCH
//   and isolated the grouped duplicate-y1 declaration blocker. The view bypasses canonical ownership,
//   so the natural y1 source was restored.

#ifndef VICTORY_CONTEXT_H
class RGE_Static_Object {
public:
    char gap_00[0x38];
    float world_x;              // +0x38
    float world_y;              // +0x3C
    char gap_40[0x08];
    unsigned char object_state; // +0x48
};

class RGE_Victory_Entry {
public:
    char pad_0C[0x0C];
    float x0;                    // +0x0C
    float y0;                    // +0x10
    float x1;                    // +0x14
    float y1;                    // +0x18
    char pad_1C[0x08];
    RGE_Static_Object* this_obj; // +0x24
    char pad_28[0x06];
    unsigned char state;         // +0x2E
};

class RGE_Victory_Conditions {
public:
    char pad_00[0x04];

    void handle_bring_area(RGE_Victory_Entry* entry);
};
#endif

void RGE_Victory_Conditions::handle_bring_area(RGE_Victory_Entry* entry) {
    RGE_Static_Object* obj = entry->this_obj;

    if (obj) {
        if (obj->object_state >= 3) {
            if (entry->state == 0) {
                entry->state = 1;
            }
            entry->this_obj = 0;
            return;
        }

        if (obj->world_x < entry->x0 || obj->world_x > entry->x1 ||
            obj->world_y < entry->y0 || obj->world_y > entry->y1) {
            entry->state = 0;
        } else {
            entry->state = 2;
        }
        return;
    } else {
        entry->state = 3;
        return;
    }
}
