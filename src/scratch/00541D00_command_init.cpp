// World.cpp:852-854, 89 bytes
// RGE_Game_World::command_init(int, TCommunications_Handler*)
// FLAGS: config/flags/00541D00_command_init.rsp uses /GX for original SEH/new/ctor cleanup basin.
//
// Attempt log:
// - Prior pass: natural new with /GX emits expected SEH prologue, allocator size 0x18,
//   ctor arg pushes (`param2`, `this`), and ctor call, but direct source sinks the
//   member store/SEH restore into the non-null path (23.6% positional / 16.9% edit).
// - Prior 2026-05-09 pass: tried direct assignment, zero-init local, explicit if/goto/
//   two-stage common-store forms, assignment-in-if/comma/do-while, param2 local, this
//   alias, volatile local, no-virtual command surface, void*/int member, ctor signature
//   casts, and /O1+/GX. Same blocker as 0052E530/00541C90.
// - 2026-05-10 pass on this VA only: retried 20+ focused variants: no-virtual and
//   virtual RGE_Command surfaces, typed vs void param2, direct/local new, common-store
//   if-null/if-not/goto forms, assignment-in-condition, parameter-slot reuse, zero-init,
//   volatile local, bool temp, switch-on-pointer, empty-if, ternary, and flag probes
//   (/O1, /Og, /Ob0, /Ox, /Gf, /Gy, /Oa, /Ot, /Oy- with /GX). No exact.
// - Best source below reaches the original common-tail family: ctor-success `jmp`, null
//   `xor eax,eax`, and common member-store intent, but VC5 inserts redundant
//   `test eax,eax; jne +0` at the join. This shifts/truncates the EH epilogue inside
//   the 89-byte window (`83c4` incomplete at tail), so it is not an accepted_drift
//   suggestion under Boss's 00449E20/00541C90 window ruling.
// Left in scratch: behavior and EH/call surface are correct; blocker is VC5 source shaping
// around null-path/common-store join. No inline asm/hacks.

void* __cdecl operator new(unsigned int size);

class RGE_Game_World;
class TCommunications_Handler;

class RGE_Command {
public:
    char gap_00[0x18];
    RGE_Command(RGE_Game_World* world, TCommunications_Handler* handler);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Command* command;  // +0x58

    void command_init(int param1, TCommunications_Handler* param2);
};

void RGE_Game_World::command_init(int param1, TCommunications_Handler* param2) {
    RGE_Command* p = new RGE_Command(this, param2);
    if (p == 0) {
        p = 0;
    }
    this->command = p;
}
