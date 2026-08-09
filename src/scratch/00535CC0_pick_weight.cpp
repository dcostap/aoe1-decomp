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
// Fresh pass probe 1 rolled back: the natural nested level/predicate spelling
// restored the 211-byte size and improved positional diff to 139 bytes, but it
// changed the dispatch CFG to cmp/jne (72.46% shape, 57.35% blocks), farther
// from the original sub/dec/je dispatch than the switch basin.
// Fresh pass probe 2: the full proven TPanel/RGE_View and static-object surfaces
// were a codegen duplicate of the minimal shells; retained because ownership is
// more canonical, with no metric change.
// Fresh pass probe 3: next test mirrors the decompiler's proven source lifetime:
// save the object pointer, write the level through param_1 before the touched
// predicate, then use the saved pointer for the id comparison.
// Probe 3 rolled back: the explicit saved pointer forced an EBX save and a
// 211-byte/194-diff basin, so the compiler's existing parameter-home reuse is
// the better source reconstruction.
// Fresh pass probe 4: add the period RGE_View virtual surface (TPanel slots
// 0-47, view slots 48-55, pick_through_fog 56, pick_weight 57) without adding
// any function bodies, testing TU/vtable context rather than body control flow.
// Fresh pass probe 5: retain the saved object only for the proven id read, but
// express the observed byte write to the incoming parameter home directly.
// Probe 5 was a codegen duplicate of the clean 207-byte basin; the explicit
// byte-home form did not alter VC5's register family.
// Fresh pass probe 6: test a narrow register-qualified result local because the
// executable carries the predicate as a full-width EDX value across dispatch.
// Probe 6 was also a codegen duplicate; register qualification did not move the
// predicate from ECX or the level key from EAX.
// Fresh pass probe 7: move the proven zero result initialization to function
// entry, testing declaration/lifetime placement for the original pre-dispatch
// XOR EAX,EAX without retaining the duplicate raw alias experiment.
// Probe 7 was a codegen duplicate. The 108-variant fresh lab over level-home,
// zero-lifetime, and late predicate spellings produced eight nonexact groups;
// no exact or invariant-eligible variant was found. Final source below keeps
// the full proven layout/vtable context and natural nested predicates; remaining
// drift is the isolated VC5 register/dispatch basin (ECX/EAX vs EDX/ECX) plus
// the pre-dispatch zero/branch-tail topology.
// Main-agent normalization replaced the raw static-object vptr field with its
// canonical virtual destructor surface; emitted code is unchanged.
// Session normalization uses the canonical RGE_View, RGE_Static_Object, and
// RGE_Master_Static_Object names and a real unsigned-char level local; no
// parameter-home pointer alias remains.  The best natural source is retained
// below; remaining drift is the VC5 register/dispatch basin described above.
// Main-agent audit restored polymorphic master/panel ownership; the natural
// select-level switch remains authoritative.

// Fresh pass probe 2 uses the proven concrete RGE_View/TPanel and
// RGE_Static_Object data surfaces rather than the prior minimal helper shells.
struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    char _gap_04[0x89];
    unsigned char select_level;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    char _gap_0C[0x7C];
};

class TPanel {
public:
    virtual ~TPanel(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    char _gap_04[0xF0];
};

class RGE_View : public TPanel {
public:
    char _gap_F4[0x33C - 0xF4];
    int UC_ObjectTouched;
    int UC_TouchedObj;
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void pick_through_fog();
    virtual int pick_weight(RGE_Static_Object* param_1, int param_2);
};

int RGE_View::pick_weight(RGE_Static_Object* param_1, int param_2) {
    int zero;
    int bVar1;
    unsigned char select_level = param_1->master_obj->select_level;

    // Check touched state.
    if (this->UC_ObjectTouched && this->UC_TouchedObj == param_1->id)
        bVar1 = 1;
    else
        bVar1 = 0;

    zero = 0;

    // Switch on select_level (values 2,3,4 handled, default=1)
    switch ((int)(unsigned)select_level) {
        case 4:
            if (bVar1) return 5;
            if (param_2 == 1 || param_2 == 2) return 4;
            if (param_2 == 3) return 3;
            return 2;
        case 3:
            if (bVar1) return 5;
            if (param_2 != 1) {
                if (param_2 != 2) return zero;
            }
            return 3;
        case 2:
            if (bVar1) return 5;
            if (param_2 != 1) {
                if (param_2 != 2) {
                    if (param_2 != 3) return zero;
                    return 2;
                }
            }
            return 3;
        default:
            return 1;
    }
}
