// VA: 0052DD10 pick_weight (tvw_main.cpp:667-723)
//
// The object/master offsets and the two touched-object fields are taken from
// the executable accesses.  The level switch and special master IDs retain the
// period source shape suggested by the PDB/decompiler, rather than using raw
// cursor arithmetic.
//
// Attempt log:
// baseline pending: clean reconstruction of the master ID/selection level,
// touched-object predicate, and three-way level dispatch.
// probe 1 baseline: 272 bytes, 184 differing; initial loads and special-ID
// override matched through the touched predicate, with the natural switch
// dispatch structurally close.
// probes 2-3: named-zero and nested negative-guard forms reduced the size gap
// but did not recover the original shared-tail topology; probe 3 duplicated 2.
// probe 4 bool touched: 265 bytes and 168 differing, but narrowed the predicate
// to byte-register code and moved the first mismatch earlier; rolled back.
// probe 5 declaration-order change duplicated the nested form.
// probe 6 variant lab (48 natural type/order/guard/zero forms): only two codegen
// groups, no size/frame-eligible result; original uses EDX predicate, ECX level,
// and pre-dispatch EAX zero while all variants stayed in the ECX/EAX basin.
// probes 7-10: explicit object local, full inherited view context, corrected
// layout gap, and entry zero liveness were duplicates or farther; restored the
// clean natural source. Remaining lead is original tvw_main.cpp TU context or
// VC5 register/return-tail allocation, not an ownership or behavior gap.
// Main-agent audit restored canonical master/view polymorphic ownership at
// unchanged offsets; the validated codegen gap is unchanged.
// probe 11: made cases 2/3 assign a natural result local and fall through to
// one shared return, matching the original line-723 zero tail and exact bytes.

#ifndef TVW_MAIN_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;
    char gap_12[0x7B];
    unsigned char select_level;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x3C];
    unsigned char object_state;
};

class RGE_View {
public:
    virtual ~RGE_View();
    char gap_04[0x338];
    int UC_ObjectTouched;
    int UC_TouchedObj;
};

class TRIBE_Main_View : public RGE_View {
public:
    int pick_weight(RGE_Static_Object* param_1, int param_2);
};
#endif

int TRIBE_Main_View::pick_weight(RGE_Static_Object* param_1, int param_2) {
    unsigned char select_level = param_1->master_obj->select_level;

    if (param_1->master_obj->id == 0x4F ||
        param_1->master_obj->id == 0xC7 ||
        param_1->master_obj->id == 0x45 ||
        param_1->master_obj->id == 0x116) {
        select_level = 3;
    }

    int touched;
    if (this->UC_ObjectTouched != 0 && this->UC_TouchedObj == param_1->id)
        touched = 1;
    else
        touched = 0;

    int result = 0;
    switch (select_level) {
        case 4:
            if (touched)
                return 5;
            if (param_2 == 1 || param_2 == 2)
                return 4;
            if (param_2 == 3)
                return 3;
            return 2;

        case 3:
            if (touched)
                return 5;
            if (param_2 == 1 || param_2 == 2)
                result = 3;
            else if (param_2 == 3 && param_1->object_state < 2)
                result = 2;
            break;

        case 2:
            if (touched)
                return 5;
            if (param_2 == 1 || param_2 == 2)
                result = 3;
            else if (param_2 == 3)
                result = 2;
            break;

        default:
            return 1;
    }

    return result;
}
