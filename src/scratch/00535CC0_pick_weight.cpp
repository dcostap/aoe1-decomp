// 00535CC0 pick_weight (view.cpp:2396-2440)
// PDB source: view.cpp (RGE_View::pick_weight)
//
// virtual int __thiscall RGE_View::pick_weight(RGE_Static_Object*, int)
// Returns: weight value (1-5, 0 = unselectable)
// ret 8 cleanup (2 params, thiscall)
//
// === Attempt log ===
// attempts 1-18: all produce 208-211 byte function, same codegen family.
// Persistent register allocation differences:
//   - bVar1 in ecx vs original's edx
//   - switch var in eax vs original's ecx
//   - no pre-zero xor eax,eax at switch dispatch
//   - case 2: branch-free (setne/dec/and) vs original's branching
// Tried: if-else/ternary/nested bVar1 forms, param_1 overwrite vs local var,
//   __fastcall standalone function, order changes, id capture.
// All produce same register family; root cause appears to be VC5 single-function
// TU context (view.cpp with ~100 virtual functions in RGE_View) vs isolated
// compilation. Full TU compilation might resolve but is not single-function
// reproducible.
//
// Best variant retained below.

struct RGE_Master_Static_Object_Layout {
    char _gap_00[0x8D];
    unsigned char select_level;
};

struct RGE_Static_Object_Layout {
    void* vtable;
    long id;
    RGE_Master_Static_Object_Layout* master_obj;
};

struct RGE_View_Helper {
    char _gap_00[0x33C];
    int UC_ObjectTouched;
    int UC_TouchedObj;
    int pick_weight(RGE_Static_Object_Layout* param_1, int param_2);
};

int RGE_View_Helper::pick_weight(RGE_Static_Object_Layout* param_1, int param_2) {
    // Check touched state
    int bVar1;
    if (this->UC_ObjectTouched && this->UC_TouchedObj == param_1->id)
        bVar1 = 1;
    else
        bVar1 = 0;

    // Overwrite param_1 with select_level (original reuses stack slot)
    param_1 = (RGE_Static_Object_Layout*)(unsigned)(unsigned char)param_1->master_obj->select_level;

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
