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
// GIVEUP: not a reasonable accepted_drift; mismatch is broad from offset 0 and includes prologue/frame/function-boundary topology rather than a localized equivalent hunk.

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
