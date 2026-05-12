// 0052E530 TRIBE_World::command_init
// EH-framed allocate and construct TRIBE_Command, store at +0x58.
// FLAGS: config/flags/0052E530_command_init.rsp uses /GX for original EH frame.
//
// === ACCEPTED_DRIFT CANDIDATE ===
// Remaining diff: 4 bytes of dead no-op `test eax,eax; jne +0` before common store.
// Behavior: Identical. The test+jnz is a VC5 phi-merge artifact that never branches.
// Shift: Epilogue moves 4 bytes into post-function padding; all regs/memory exact.
// Review: Low risk, no behavior change. Same VC5 artifact as just-approved 0052E650.
// Move to accepted_drift/ if Boss approves.
//
// Attempt log — 20+ focused variants and confirmed by variant lab (5 variants, G0000):
// All approaches that force a common store produce identical codegen:
// `test eax,eax; jne +0` persists as a VC5 phi-merge artifact.
//
// Direct `this->commands = new TRIBE_Command(this, handler)` gives sunk-store (21 pos diff).
// If-else separate stores avoid the artifact but have 2 stores (14 pos diff, worse edit).
// Variant lab confirmed G0000 (if_assign) is the best basin (16 pos / 11 edit).
//
// Best source below. If accepted, promote to src/accepted_drift/.

void* __cdecl operator new(unsigned int size);

class TCommunications_Handler;
class TRIBE_Command;

class RGE_Game_World {
public:
    char pad_00[0x58];
    TRIBE_Command* commands;
};

class TRIBE_World : public RGE_Game_World {
public:
    void command_init(int unused, TCommunications_Handler* handler);
};

class TRIBE_Command {
public:
    char gap_00[0x18];
    TRIBE_Command(TRIBE_World* world, TCommunications_Handler* handler);
};

void TRIBE_World::command_init(int unused, TCommunications_Handler* handler) {
    TRIBE_Command* cmd;
    cmd = new TRIBE_Command(this, handler);
    if (cmd == 0) {
        cmd = 0;
    }
    this->commands = cmd;
}
