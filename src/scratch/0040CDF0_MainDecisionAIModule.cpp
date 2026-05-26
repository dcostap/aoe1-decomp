// VA: 0040CDF0 MainDecisionAIModule::MainDecisionAIModule (113 B)
// PDB source: aimdmod.cpp lines 34-35
// FLAGS: /GX
//
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

struct ManagedArray_Int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Player {};

class AIModule {
public:
    char gap_04[0xEC];
    AIModule(char* name, int id, int player_number, void* owner);
    virtual ~AIModule();
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    ManagedArray_Int objects;

    MainDecisionAIModule(void* param_1, int param_2, RGE_Player* param_3);
};

MainDecisionAIModule::MainDecisionAIModule(void* param_1, int param_2, RGE_Player* param_3)
    : AIModule("Main Decision AI", 1000, param_2, param_1)
{
    this->player = param_3;
    this->objects.value = 0;
    this->objects.numberValue = 0;
    this->objects.desiredNumberValue = 0;
    this->objects.maximumSizeValue = 0;
}
