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
// - 2026-05-10 resumed pass on this VA only: retried 15 variants: direct member store,
//   local-no-if, if-not/if-null storing into member in arms, goto-store, assignment in
//   condition, void*/int casts, comma expression, volatile read, member pointer alias,
//   handler local/param assignment, bool temp, and while-break null form. No exact.
//   Direct/local/goto forms collapse to sunk-store/null-tail basin; all common-tail
//   null-normalization forms keep the redundant join `test eax,eax; jne +0`; store-in-arm
//   forms add a real post-join branch. Same EH epilogue/window truncation blocker.
// 2026-05-10 SpruceGlow Boss-assigned pass: revalidated current best and tried 16 more source
// variants: direct/local new assignment, handler local, this local, if-not-empty, goto common/null,
// member reference/pointer alias, if store in both arms, volatile command pointer, bool temp,
// unused-param touch, and explicit casts/order on ctor args. No exact. The direct/local family remains
// sunk-store/null-tail (21 positional/15 edit). Common-tail variants all keep the redundant join
// `test eax,eax; jne +0` and truncate/shift the EH epilogue in-window. Store-in-arm forms have fewer
// positional bytes (14) but worse edit diff and real branch/store layout drift, so not kept.
// Left in scratch: current source is the closest common-tail source but remains stuck
// because VC5 inserts a redundant join test that shifts the EH epilogue. No inline asm
// or accepted_drift suggestion for this state (same blocker as denied 0052E650 drift).

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
