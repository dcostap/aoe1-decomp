// 00535CC0 pick_weight (view.cpp:2396-2440)
// PDB source: view.cpp (RGE_View::pick_weight)
//
// virtual int __thiscall RGE_View::pick_weight(RGE_Static_Object*, int)
// Returns: weight value (1-5, 0 = unselectable)
// ret 8 cleanup (2 params, thiscall)
//
// === Attempt log ===
// Baseline isolated source was structurally broad (198 differing bytes, 198-byte
// rebuilt body).  Reconstructing a separate select_level local, initialized before
// the touched-object test, recovered the original 211-byte size and the complete
// first 46-byte load/test block (probe 3).
// Probes 4-6: bool/initialized-result/local-declaration-order variants either
// regressed or were codegen duplicates.  A polymorphic TPanel/RGE_View surface and
// int/long result-width variants were also duplicates (probes 8-9).
// Probe 7: a named zero result was a duplicate, but is retained because the binary
// pre-zeroes EAX before the level dispatch and returns that zero on two arms.
// Probe 10: reversing the final case-2 equality to an explicit negative guard
// improved the isolated result to 207 bytes, 150 differing bytes, 88.57% shape,
// and 77.94% exact-block coverage.  The remaining first hunk is register coloring:
// rebuilt bVar1 is ECX while original is EDX; rebuilt dispatch value is EAX while
// original is ECX; original also hoists XOR EAX,EAX and keeps a branching case-2
// tail.  No calls, frame, or ABI/layout uncertainty remains.
// Best source reconstruction retained below; no exact match in this assignment.

struct RGE_Master_Static_Object_Layout {
    char _gap_00[0x8D];
    unsigned char select_level;
};

struct RGE_Static_Object_Layout {
    void* vtable;
    long id;
    RGE_Master_Static_Object_Layout* master_obj;
};

class TPanel {
public:
    virtual void v00();
};

class RGE_View_Helper : public TPanel {
public:
    char _gap_04[0x33C - 4];
    int UC_ObjectTouched;
    int UC_TouchedObj;
    virtual int pick_weight(RGE_Static_Object_Layout* param_1, int param_2);
};

int RGE_View_Helper::pick_weight(RGE_Static_Object_Layout* param_1, int param_2) {
    int bVar1;
    unsigned char select_level = param_1->master_obj->select_level;

    // Check touched state.
    if (this->UC_ObjectTouched && this->UC_TouchedObj == param_1->id)
        bVar1 = 1;
    else
        bVar1 = 0;

    param_1 = (RGE_Static_Object_Layout*)(unsigned)select_level;

    int zero = 0;

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
            return zero;
        case 2:
            if (bVar1) return 5;
            if (param_2 == 1 || param_2 == 2) return 3;
            if (param_2 != 3) return zero;
            return 2;
        default:
            return 1;
    }
}
