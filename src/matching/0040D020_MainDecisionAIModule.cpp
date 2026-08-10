// 0040D020 MainDecisionAIModule::~MainDecisionAIModule (aimdmod.cpp:57-58, 112B)
// FLAGS: /GX
//
// Attempt log (2026-05-19):
// 18+ probes attempted. Best result: non-virtual stubs + delete expression + /GX.
// Edit diff 18.75%, positional diff 64.29%. Field offsets correct.
// 2026-05-19 additional probes: real virtual destructor surface worsened edit diff to 37.5%; manual vtable store scheduled after cmp and worsened to 41.1%; volatile vtable store no help; /O2 without /Oy no change; /O1 too small; /Od much worse; novtable virtual surface no improvement; delete[] same as delete; free too small; explicit operator delete no improvement.
// 2026-05-20 Boss retry: revalidated baseline (same 18.75% edit / 64.29% positional, first mismatch 0). Tried /GR, /vd0, /vd1, /Gd flag additions: no byte change. Tried manual vtable store first: worsened to 41.07% edit / 69.64% positional. Tried explicit local pointer for objects_value: no byte change. Tried explicit operator delete call: no byte change. Tried virtual derived dtor: worsened to 65.18% edit / 69.64% positional. Tried virtual base+derived dtors: worsened to 45.54% edit / 67.86% positional. Tried removing <stdlib.h>: no byte change.
// 2026-05-21 Boss retry: revalidated baseline again. Tried virtual base+derived natural dtor (49.11% edit), virtual+manual vtable (53.57%), novtable derived+manual vtable (53.57%), nonvirtual+manual vtable+explicit operator delete (41.07%). Tried flags /Ob0, /Zp1, /Zp4, /GR-, /Gf, /Gy, /vd2, /ML, /MT, /MD, /Fr: no byte change from baseline. /Zd and /Zi hit checker COFF parsing errors, not a usable axis. No candidate moved first mismatch past offset 0; the prologue-family gap remains the blocker.
//
// Remaining mismatch (18.75% edit / 64.29% positional):
// The EH prologue format is structurally different:
//   Original: FS-first 3-slot (mov eax,[fs:0]; push -1; push handler; push eax)
//   Rebuilt:  push-first 4-slot (push -1; push handler; mov eax,[fs:0]; push eax; push ecx)
// VC5's /GX always emits push-first (4-slot with saved-this). The 1998 build's
// compiler emitted FS-first (3-slot, no saved-this). This is a compiler-version
// internal EH model difference.
//
// Body (null check, delete, zero stores, base dtor call) is behaviorally correct.
// Stack frame offsets differ by 4 due to saved-this slot.
// Tail cleanup: add esp 0Ch vs add esp 10h.
// Missing vtable store (suppressed by non-virtual stub pattern).
//
// accepted_drift not applicable: stack cleanup and frame layout are structurally
// different per AGENTS.md rules.
// GIVEUP: exact match blocked by compiler EH model difference.
// 2026-05-24 Boss retry: re-read packet and revalidated baseline (18.75% edit / 64.29% positional, first mismatch 0). Tried 10 more source-shape probes: virtual derived dtor (65.18% edit), virtual derived + explicit operator delete (65.18%), novtable virtual + manual vptr (61.61%), nonvirtual + manual vptr (41.07%), local pointer + manual vptr (41.07%), virtual base+derived (37.50%), positive if/local delete path (same as baseline), reversed zero-store order (22.32%), memset tail (compile rejected until string.h; not pursued because it would only affect the already-matching zero-store tail), explicit base-dtor call in body (30.36%). No probe moved first mismatch past offset 0 or removed VC5's push-first EH prologue/saved-this slot. Baseline remains best; accepted_drift still not proposed because EH frame/stack cleanup and missing vptr store are structural, not localized benign drift.
// 2026-05-26 Boss retry: re-read packet and revalidated baseline (18.75% edit / 64.29% positional, first mismatch 0). Tried 16 additional axes: manual vptr first (41.07%), explicit pointer local (same), reversed zero-store order (22.32%), else/goto delete guards (same), zero local (compile/no improvement), virtual derived (49.11%), virtual base+derived (37.50%), novtable virtual+manual vptr (61.61%), struct member surface (same), delete[] (same), no-/GX virtual variants (95.54% / wrong no-EH basin), __try/__finally no-/GX (58.93%), __try with /GX or /EH rejected by C2712, and hidden /d1ESrt flag rejected. No probe moved first mismatch past offset 0 or produced the original FS-first 3-slot EH prologue. GIVEUP remains: baseline is best; no accepted_drift proposal because EH frame shape/stack cleanup and vptr-store differences are structural.
// 2026-08-02 LunaM40D020: claimed and rechecked the live baseline after dossier,
// donor, and ABI review. Current checker: 112B, 2/2 calls aligned, 75.0000%
// positional diff (84 bytes), first mismatch offset 0. Dossier confirms the
// only unresolved structural facts are the FS-first 3-slot original EH entry,
// absent saved-this slot, and original vptr store; the current /GX compiler
// emits push-first 4-slot EH with saved-this. Prior source/flag probes already
// cover the natural/virtual/manual-vptr, delete form, TU, and flag axes; leave
// the best baseline in scratch rather than repeat them.
// 2026-08-03 Luna40D020TU: normalized the compiler-facing source toward the
// binary-backed polymorphic AIModule/MainDecisionAIModule layout: named base
// fields, virtual destructors, the real player member, a named ManagedArray
// member, natural delete, and implicit base destruction. Manual vptr/base-dtor
// plumbing remains intentionally absent.
// Probe baseline: the normalized natural source is 117B, 99 positional bytes
// different (84.6154%), with both calls aligned and the first mismatch at 0.
// Expanding the complete binary-backed virtual method surface and replacing the
// local pointer/array aliases with RGE_Player* / ManagedArray<int> were codegen
// duplicates.
// Full-TU lead: a temporary faithful aimdmod.cpp context defining AIModuleID,
// AIModule, both related MainDecision constructors, and both destructors under
// /O2 /Oy /GX emitted the same push-first EH family. It did not produce the
// original FS-first 3-slot entry. The natural candidate does reproduce the
// observed null test, operator delete, post-delete nulling, three scalar zero
// stores, derived-vptr write, and compiler-generated base-dtor call. The only
// remaining lead is the pinned VC5 EH topology/function-boundary difference;
// retain this readable source in scratch for logic-readiness assessment.

// Retry 2026-08-10 orch-aimdmod-logic-02 TU-exclusive follow-up:
// - Baseline revalidated at 117/112 bytes, 99 strict diff bytes, 78.12% shape,
//   with both calls aligned. The current compiler remains in the push-first
//   four-slot EH family with a saved-this home; the oracle is FS-first three-slot.
// - C++ throw() specifications on AIModuleID/AIModule/MainDecision destructors
//   changed the body to 112 bytes and 93 diff bytes but still emitted push-first
//   EH and removed the original state-store topology; rolled back.
// - A destructor function-try-block was rejected by VC5 (C2059 at `try`).
// - A reference alias for objects.value was an emitted-code duplicate.
// - An inline empty AIModule destructor exposed an extra AIModuleID destructor
//   call and wrong relocation/call sequence; rolled back.
// - A period-style throw() declaration for global operator delete removed the
//   EH frame entirely (65-byte emission); rolled back. The oracle therefore
//   needs the potentially-throwing delete state, but VC5 still homes this.
// - Added the donor-backed inactive AIModuleID(char*, int) constructor ABI
//   declaration; emitted code duplicated the clean source and is retained as
//   canonical same-TU type context. No natural new mechanism selected the
//   FS-first frame or its erroneous cleanup address; leave in scratch.
// 2026-08-10 orch-aimdmod-logic-luna-04:
// - New constructor-backed ownership hypothesis: make ManagedArray<T> a
//   nontrivial class with its inline scalar-delete/null/zero destructor, and
//   leave MainDecisionAIModule::~MainDecisionAIModule empty so the compiler
//   emits the natural member-dtor then base-dtor sequence. This is supported
//   by exact 0040CE90's nontrivial ManagedArray member/EH surface and matches
//   the target exactly (112B, 30 instructions, both calls and all bytes).

#include <stdlib.h>

class AIModuleMessage;
class RGE_Player;
class RGE_Static_Object;
struct _iobuf;

class AIModuleID {
public:
    virtual ~AIModuleID();
    AIModuleID(char* name, int id);

    int id;
    char name[0x40];
};

class AIModule {
public:
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

    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[0x40];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    _iobuf* historyLogFile;
    char historyLogFilename[0x40];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ~ManagedArray() {
        if (this->value != 0) {
            delete this->value;
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }
};

class MainDecisionAIModule : public AIModule {
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
};

MainDecisionAIModule::~MainDecisionAIModule() {}
