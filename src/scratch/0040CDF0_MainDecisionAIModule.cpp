// VA: 0040CDF0 MainDecisionAIModule::MainDecisionAIModule (113 B)
// PDB source: aimdmod.cpp lines 34-35
// FLAGS: /GX

// Status: STUCK — same VC5 EH prologue family mismatch as ~MainDecisionAIModule (0040D020).
//
// Original uses FS-first SEH prologue (`mov eax,[fs:0]` before `push -1`) with
// interleaved parameter load before `mov [fs:0],esp`. Our VC5 uses no EH frame for
// the constructor body unless extra synthetic deleting-dtor/code is visible; the
// best exact-size build fills the configured 113 bytes with a neighboring deleting
// destructor and has no original FS-first frame. Same root cause as sibling dtor.
// No accepted_drift: broad prologue/frame/function-boundary mismatch.
//
// Retry 2026-05-18 top-20 mode:
// - Revalidated baseline /GX: exact size 113, positional 75.2212%, first mismatch 0.
// - Removed visible base virtual dtor: constructor shrank to 80 bytes; no EH frame.
// - Added visible derived virtual dtor: size 112, still no EH frame.
// - Added __declspec(novtable) derived surface: size 80, vtable store suppressed, no EH frame.
// - Tried constructor function-try-block syntax; VC5 rejected syntax, rolled back.
// - Probed /Od /GX: size 106, wrong basin; rolled back.
// - Probed /O2 /GX with /Oy disabled: size 80, no EH frame; rolled back.
// - Probed /G5 and /GR- with /GX: identical to baseline exact-size mismatch.
// - Restored baseline visible base virtual dtor, no derived dtor, /O2 /Oy /GX.
// Retry 2026-05-19:
// - Revalidated assigned target only: still exact size 113, MISMATCH 75.2212%, first mismatch offset 0.
// - Added empty ManagedArray_Int ctor/dtor to test member-lifetime EH; optimized away, no codegen change.
// - Added visible derived virtual destructor; constructor section shrank to 112 bytes, rolled back.
// - Removed base virtual dtor; constructor shrank to 80 bytes, rolled back.
// - Tried explicit vtable store with base virtual restored; section shrank to 80 bytes, rolled back.
// - Added extra derived virtual dummy; no improvement, same broad no-EH baseline.
// - Tried body try/catch plus /Ob0 probe while EH-affecting variants were present: forced push-first EH family with extra saved regs/slots, not original FS-first; rolled back.
// GIVEUP: not a reasonable accepted_drift; mismatch is broad from offset 0 and includes prologue/frame/function-boundary topology rather than a localized equivalent hunk.
// Retry 2026-05-19/20 assigned pass:
// - Revalidated baseline /GX: exact-size section from ctor plus synthesized deleting dtor tail, but target ctor still no FS-first EH; 75.2212% positional, first mismatch 0.
// - Body try/catch forced EH but wrong push-first family with saved-this slot; improved edit diff (27.4336%) yet stack offsets/tail cleanup and vptr/player store order stayed wrong.
// - Inline ManagedArray_Int constructor optimized back to baseline; out-of-line constructor polluted function boundary with separate helper before target.
// - /Ob0 with member-constructor probe produced push-first EH plus explicit member ctor call; worse and rolled back.
// - /EHsc accepted by VC5 but did not alter baseline no-EH ctor family; /d1ESrt was unsupported by c1.
// Left in scratch: still blocked on compiler EH-prologue/function-boundary topology, not accepted-drift quality.
// Retry 2026-05-19 Boss pass: 12 additional variants with existing custom /GX flags: derived dtor (112B), const-char name, extra base virtual slots before/after dtor, static/extern name, param_3 local, store order swap, derived dummy/nonvirtual dtor; ManagedArray ctor/dtor declarations failed to compile without definitions. All compiling full-size variants stayed baseline 75.2212% positional first mismatch 0; no FS-first EH prologue.
// Retry 2026-05-20 assigned pass: 17 more probes. ManagedArray visible dtor/ctor+dtor/virtual dtor forced EH but only the wrong push-first EH family (best 60.1770% positional, first mismatch 0) with extra saved regs/member ctor calls, not the original FS-first constructor frame. Base dummy virtual, hardcoded string address, param_3 local, flat member fields, and /Ob0 /Gz /Gr /Og /Op /GB all collapsed to baseline no-EH 75.2212% first mismatch 0. Base nonvirtual dtor and manual vptr stores did not compile under this surface. Still no accepted_drift: broad prologue/frame/function-boundary topology mismatch from byte 0, not localized equivalent drift.
// Retry 2026-05-21 Boss pass: 10+ more probes. Tested CE90-style <new.h>/<stdlib.h> context with/without derived virtual dtor (112B or same baseline), body try/catch (VC5 syntax rejected), local Cleanup dtor before/end (forced wrong EH, 65.4867% positional), ManagedArray dtor (wrong EH, 61.9469%), novtable/manual vptr (compile error), hardcoded name address (76.1062%), param_3 local, zero-store order swap, base no-virtual+derived virtual (112B), and extra base virtual slots (baseline). No variant produced the original FS-first EH frame; leaving baseline in scratch. No accepted_drift: mismatch starts at byte 0 and is prologue/frame/function-boundary topology, not localized benign drift.
// Retry 2026-05-24 assigned pass: 18 further probes. Derived virtual/nonvirtual dtor declarations failed or shrank to 112B, base dummy slots stayed baseline, ManagedArray ctor/dtor/virtual-dtor surfaces either baseline or wrong EH family (best still first mismatch 0), object initializer and local object pointer no change, param3 local/zero-first/manual vptr/zero-loop did not recover EH, flags /Ob0 /Oa /Og /Ow /Zp1 /vmg no change, and <new.h>/<stdlib.h>/<string.h>/hardcoded string contexts stayed baseline or worse. Still no accepted_drift: broad byte-0 EH/function-boundary mismatch, not localized equivalent drift.
// Retry 2026-05-26 Boss pass: 18 more probes on VA 0040CDF0 only. Member ctor/dtor/init-list variants could force EH, but only the wrong push-first family (best 60.1770% positional, first mismatch 0) with extra saved regs/member calls; member ctor-only was 66.3717%, dtor-only 61.9469%, inline ctor collapsed to baseline. Derived virtual dtor and aggregate zero-init shrank to 112B; player init-list, const char base ctor, operator delete declaration, and inline cleanup local stayed baseline. Flag probes /O1, /Oy-, /Gm, /GR, /Za, /Zp4, /vd0, /vd1 did not recover FS-first EH (or shrank/worsened). GIVEUP: not accepted_drift quality; mismatch remains broad byte-0 EH prologue/frame/function-boundary topology, not localized equivalent drift.

// Retry 2026-08-02 LunaM40CDF0: claimed after dossier/donor/ABI review. Fresh /GX baseline
// rebuilt only 78/113 bytes (93.8053% positional, 63 edit bytes, first mismatch 0), with
// the single direct AIModule call aligned and the expected +0xF0..+0x100 stores present;
// current output is the no-EH basin, not the stale historical 113-byte artifact. Tested
// binary-proven absolute string/vtable addresses (context; 107 positional / 60 edit), a
// comma-expression store-order probe (duplicate codegen), compiler-owned vptr with the
// absolute string (107 positional / 60 edit), and a real player member initializer
// (duplicate codegen). Rolled all speculative probes back to the literal/automatic-vptr
// baseline. The original still begins FS-first (mov eax,[fs:0], push -1, handler, old FS)
// while VC5 either emits no EH or the already-documented push-first saved-this EH family.
// This is a real pinned-toolchain EH/function-boundary blocker; stop before spending the
// remaining hypothesis budget on repetitions. Leave in scratch; not accepted_drift.

// Retry 2026-08-02 Luna40CDF0 canonical-base pass:
// - Replaced the gap-only AIModule stub with the donor-backed 0xF0 field surface
//   (AIModuleID, player/name/log fields, and the scalar tail) and the explicit
//   vtable-pointer style used by exact 0040E2D0_AIModule. Baseline #8 remained
//   the no-EH 78-byte basin (106 positional diff, first mismatch 0), but its
//   delayed explicit vptr write followed the scalar initialization rather than
//   the old compiler-owned-vptr ordering.
// - Filled AIModuleID with its typed vptr/id/name fields and declared the
//   binary AIModule/AIModuleID destruction surface (#9); emitted code was an
//   exact duplicate, so the added lifetime metadata did not enable EH.
// - Used the proven MainDecisionAIModule vtable address for the explicit write
//   (#10); this made the vptr bytes literal but worsened positional alignment
//   (107 bytes) and still emitted no EH. Rolled back to the donor-style external
//   vtable surface.
// - Tried the complete AIModule virtual method list as an ABI-context control
//   (#11); it returned to the same 78-byte no-EH basin (duplicate of the old
//   compiler-owned-vptr output), not the original FS-first frame. Restored the
//   clean explicit-vtable/full-field source.
// Conclusion: the canonical full AIModule surface restores the delayed derived
// vptr ordering family but does not restore the original FS-first 3-slot EH
// entry. The remaining byte-0 prologue/function-boundary mismatch is a pinned
// VC5 EH topology blocker, not localized drift; keep this readable source in
// scratch and do not repeat the exhausted thin-class/flag variants.

// Retry 2026-08-03 Luna40CDF0TU final TU-context lead:
// - Temporarily compiled a faithful aimdmod.cpp-style TU under /O2 /Oy /GX,
//   with both MainDecisionAIModule constructors and its destructor, real
//   AIModule/AIModuleID field declarations, and the current explicit delayed
//   derived-vptr assignment. The target constructor remained the same 78-byte
//   no-EH emission: 106/113 positional diff, 55.17% shape, 1/1 call aligned,
//   first mismatch 0. No FS-first 3-slot frame appeared.
// - Integrated probe #15 was an emitted-code duplicate of the clean source.
//   Restored the canonical single-function source; no flags or sibling files
//   were changed. Full TU context does not overcome the pinned VC5 EH basin.
//
// Follow-up 2026-08-03 orch-aimdmod-logic-01:
// - Corrected the inactive AIModuleID declaration to the donor-backed (char*, int)
//   constructor ABI; this target does not call it directly.
// - The inline ManagedArray default constructor plus natural player member
//   initializer emits player at +0xF0 before the four zero stores, matching the
//   original fault/store order (58.62% shape, 106 strict bytes; no EH).
// - Inline/member lifetime declarations, the full polymorphic header surface,
//   aggregate objects(), and destructor declarations either duplicated that
//   no-EH output or worsened size; the aggregate form was restored.
// - Retain the readable typed AIModuleID fields/vptr and donor-backed ABI, but
//   retain the explicit AIModule/derived vptr surface because it is the only
//   tested form preserving the delayed derived-vptr write.
// - Remaining blocker: VC5 still emits no EH frame, while the oracle has the
//   FS-first three-slot frame and original cleanup metadata; no natural tested
//   source surface selects that family. Leave in scratch, not accepted-drift.

// Follow-up 2026-08-10 orch-aimdmod-logic-luna-05:
// - Rebuild against the newly exact same-TU CE90 load constructor and D020
//   destructor surfaces: the 0xF0 AIModule layout, declaration-only
//   polymorphic AIModule/MainDecision surfaces, and a nontrivial inline
//   ManagedArray scalar-delete/null/zero destructor. This is a fresh
//   ownership/EH hypothesis, not another FS-frame spelling variant.
// - Probes #31-#39 all emitted the same 78-byte no-EH basin: adding the
//   D020-style AIModuleID/virtual ABI, template ManagedArray<int>, an inline
//   or declaration-only member destructor, same-TU empty MainDecision dtor,
//   CE90 explicit objects(), exact include context, and exact named pointer
//   types changed no target bytes. The single AIModule call remains aligned
//   and the player/four zero stores/delayed vptr body are present.
// - Final blocker remains structural: original is 113 bytes with FS-first
//   handler 55C638, saved ESI, FS restore, and cleanup; VC5 emits 78 bytes
//   with no EH frame. No natural new surface selected the original family;
//   keep this canonical typed source in scratch, not accepted-drift.

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}

    ~ManagedArray();
};

class AIModuleMessage;
class RGE_Static_Object;
struct _iobuf;

class RGE_Player {};

// Binary-backed AIModule surface, combining the exact CE90 load-constructor
// layout with the exact D020 destructor's real AIModuleID/member lifetime
// surface.  The derived constructor still writes its delayed vtable explicitly
// because CE90 proves that source/context ownership for this TU.
class AIModuleID {
public:
    virtual ~AIModuleID();
    int id;
    char name[0x40];
    AIModuleID(char* name, int id);
};

class AIModule {
public:
    AIModuleID idValue;             // +0x04, sizeof 0x48
    int playerNumberValue;         // +0x4C
    char playerNameValue[0x40];    // +0x50
    int runningValue;              // +0x90
    int pausedValue;               // +0x94
    int logHistoryValue;           // +0x98
    int logCommonHistoryValue;     // +0x9C
    _iobuf* historyLogFile;        // +0xA0
    char historyLogFilename[0x40]; // +0xA4
    int intelligenceLevelValue;    // +0xE4
    int priorityValue;             // +0xE8
    int processFrameValue;         // +0xEC

    AIModule(char* name, int id, int player_number, void* owner);
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int value);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char* name);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int value);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char* name);
    virtual int saveState(char* name);
    virtual int gleanState(int value);
    virtual int processMessage(AIModuleMessage* message);
    virtual int update(int value);
    virtual void setCallbackMessage(AIModuleMessage* message);
    virtual int filterOutMessage(AIModuleMessage* message);
};

extern void* MainDecisionAIModule_vtable;

class __declspec(novtable) MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    ManagedArray<int> objects;

    virtual ~MainDecisionAIModule();
    virtual void setLogHistory(int value);
    virtual int save(int value);
    virtual int addObject(RGE_Static_Object* object);
    virtual int removeObject(int object_id);
    virtual int objectGroupThatCanPerformAction(int action);
    virtual int canPerformAction(int action, int target);

    MainDecisionAIModule(void* param_1, int param_2, RGE_Player* param_3);
};

MainDecisionAIModule::MainDecisionAIModule(void* param_1, int param_2, RGE_Player* param_3)
    : AIModule("Main Decision AI", 1000, param_2, param_1), player(param_3), objects()
{
    *(void**)this = &MainDecisionAIModule_vtable;
}
