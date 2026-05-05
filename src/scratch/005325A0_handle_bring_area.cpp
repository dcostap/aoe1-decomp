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
//
// Remaining issues:
// 1. Null check: VC5 inlines `state=3; ret 4` (9 bytes: jne+inline+ret) instead
//    of `je` to a shared tail (2+7=9 bytes same, but offsets differ).
// 2. Block ordering: VC5 puts bounds code inline after the obj_state check and
//    state_done at a label (jae), while original puts state_done inline and
//    bounds at a label (jb). Semantically equivalent but shifts all offsets.

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

void RGE_Victory_Conditions::handle_bring_area(RGE_Victory_Entry* entry) {
    RGE_Static_Object* obj = entry->this_obj;

    if (obj == 0) {
        entry->state = 3;
        return;
    }

    if (obj->object_state < 3) {
        if (obj->world_x < entry->x0 || obj->world_x > entry->x1 ||
            obj->world_y < entry->y0 || obj->world_y > entry->y1) {
            entry->state = 0;
        } else {
            entry->state = 2;
        }
        return;
    }

    // object_state >= 3: bring area is done/completed
    if (entry->state == 0) {
        entry->state = 1;
    }
    entry->this_obj = 0;
}
