// 00535CC0 pick_weight (view.cpp:2396-2440)
// PDB source: view.cpp (RGE_View::pick_weight)
//
// virtual int __thiscall RGE_View::pick_weight(RGE_Static_Object*, int)
// Returns: weight value (1-5, 0 means unselectable)
// ret 8 cleanup (2 params, thiscall)
//
// Attempt log:
// attempt 1-6: various shapes. Issues: eax for switch (vs ecx), ecx for bVar1 (vs edx),
//   branch-free (p2==3)?2:0 instead of if-else branching, missing pre-zero xor eax,eax.
// attempt 7: explicit if-else branching for case 2.
// attempt 8: overwrite param_1 stack slot like original, capture id first.

// Forward declarations for types used
struct RGE_Master_Static_Object_Layout;
struct RGE_Static_Object_Layout;

// Minimal layout stubs (local, exact offsets only)
struct RGE_Master_Static_Object_Layout {
    char _gap_00[0x8D];             // +0x00-0x8C
    unsigned char select_level;     // +0x8D
};

struct RGE_Static_Object_Layout {
    void* vtable;                   // +0x00
    long id;                        // +0x04
    RGE_Master_Static_Object_Layout* master_obj; // +0x08
};

// RGE_View member struct for thiscall dispatch
struct RGE_View_Helper {
    char _gap_00[0x33C];            // +0x00-0x33B
    int UC_ObjectTouched;           // +0x33C
    int UC_TouchedObj;              // +0x340

    int pick_weight(RGE_Static_Object_Layout* param_1, int param_2);
};

int RGE_View_Helper::pick_weight(RGE_Static_Object_Layout* param_1, int param_2) {
    // Capture original id before param_1 is overwritten with select_level
    long obj_id = param_1->id;

    // Overwrite param_1 with select_level (like original source)
    param_1 = (RGE_Static_Object_Layout*)(unsigned)(unsigned char)param_1->master_obj->select_level;

    // Check touched state using captured id
    int bVar1;
    if (this->UC_ObjectTouched != 0 && this->UC_TouchedObj == obj_id) {
        bVar1 = 1;
    } else {
        bVar1 = 0;
    }

    // Switch on select_level (values 2,3,4 handled, default=1)
    switch ((int)(unsigned)param_1) {
        case 4:
            if (bVar1) return 5;
            if (param_2 == 1 || param_2 == 2) return 4;
            if (param_2 == 3) return 3;
            return 2;
            
        case 3:
            if (bVar1) return 5;
            if (param_2 == 1 || param_2 == 2) return 3;
            return 0;
            
        case 2:
            if (bVar1) return 5;
            if (param_2 == 1 || param_2 == 2) return 3;
            if (param_2 == 3) return 2;
            return 0;
            
        default:
            return 1;
    }
}
