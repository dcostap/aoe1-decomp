// VA: 0052E530 TRIBE_World::command_init
// FLAGS: config/flags/0052E530_command_init.rsp uses /GX for original SEH/new/ctor cleanup basin.
//
// Prior scratch note: /GX natural new emits expected SEH prolog, allocator size 0x18,
// ctor args, and store target, but VC5 sinks the member store/SEH restore into the
// non-null path. Original has common tail with `jmp`, `xor eax,eax`, then one
// store/FS restore. Explicit placement-new temp reproduced same sunk-store basin.
//
// 2026-05-10 focused pass on this VA only:
// - Baseline scratch used manual operator new + placement new and now compiles to only
//   64 bytes under /GX (missing the original new-expression EH lowering), so restored
//   natural `new TRIBE_Command(this, handler)` as the valid EH-family baseline.
// - Try 1: direct natural new gives exact EH prologue, size push 0x18, ctor arg pushes,
//   and ctor call, but emits success-path `mov [esi+58h],eax`/epilogue and sends the
//   null path to a separate tail after the compared window (edit diff 15).
// - Try 2: `if (cmd == 0) cmd = 0;` produces the original short null branch, success
//   `jmp`, null `xor eax,eax`, and common member-store shape, but inserts redundant
//   `test eax,eax; jne +0` at the join. This shifts/truncates the EH epilogue inside
//   the 89-byte function window, so it is not an accepted-drift candidate.
// - Try 3: equivalent `if (cmd != 0){} else cmd=0`, goto-common/goto-null, and
//   `*(int*)&cmd = 0` forms all collapsed to the same redundant-join-test basin.
// - Try 4: result-local and ternary forms collapsed back to the sunk-store direct-new
//   basin with null tail after the window.
// - Try 5: volatile local/read variants kept the join but spilled EAX through the
//   stack and stored via EDX; worse and also truncates the epilogue.
// - Try 6: regular member-init helper instead of constructor removed the special
//   new-expression EH lowering and compiled to only 48 bytes; wrong family.
// Left in scratch: current source is the closest common-tail source but remains stuck
// because VC5 inserts a redundant join test that shifts the EH epilogue. No inline asm
// or accepted_drift suggestion for this state.

void* __cdecl operator new(unsigned int size);

class TCommunications_Handler;
class TRIBE_Command;

class TRIBE_World {
public:
    char gap_00[0x58];
    TRIBE_Command* commands;

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
