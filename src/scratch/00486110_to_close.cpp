// VA: 00486110 RGE_RMM_Object_Generator::to_close(RGE_Object_Info_Line&, long, long)
// PDB source: rmm_obj.cpp lines 185-202 (97 bytes, 47 asm lines)
// Default flags
//
// __thiscall: this in ecx, 3 stack params. ret 0Ch cleanup.
// Returns 1 if (x,y) is within land_inner_radius of any land point, 0 otherwise.
//
// Previous scratch notes:
// - Natural do-while source was reported as very close but compiled to a 96-byte .text
//   section (checker cannot compare the 97-byte function). The known blocker was loop
//   bottom layout: VC5 tends to emit `jge exit; jmp loop` instead of original `jl loop`,
//   or reaches the desired `jl` only by spilling count and adding a `push ecx` prologue.
// - 2026-05-09 GraniteCub tried 20 variants: while/for/goto/continue loop forms,
//   bottom conditions `i < count`, `count > i`, `i - count < 0`, `!(i >= count)`,
//   `count - i > 0`, volatile i/count checks, pointer vs reference info_line, and local
//   declaration/order changes for count/radius/x/y. No exact.
//
// 2026-05-10 focused pass on this VA only:
// - Revalidated the checked-in natural do-while source: current VC5 emits a 96-byte
//   function with extra `push ecx`/byte result local family, so check_function stops
//   with configured size 97 > .text 96.
// - Try 1: declaration-order probes (`i` before `count`, split locals, positive outer
//   `if (count > 0)`) can recover the original prologue/register family and a 97-byte
//   comparable function, but introduce a duplicated `test edi,edi; jle` before the loop
//   and shift the loop/tail (best comparable edit diff 17, 88 equal bytes).
// - Try 2: `for`, `while`, `while(1)+continue`, `goto found`, and explicit label-order
//   variants either kept the duplicate guard family, crossed-initialization compile errors,
//   or regressed to the stack-spilled result-local basin.
// - Try 3: ordering y/radius/p_y locals to match original `mov ebp,[esp+1Ch]; lea edx;
//   mov ebx,[eax+24h]` did not change scheduling; VC5 still emits `lea edx` before the
//   duplicated guard and delays the `ebp` load to the loop entry.
// - Try 4: flag probes /Ob0, /Og, /Ot no effect on the 96-byte natural source; /Os and
//   /O1 were 79-byte wrong-family functions. No custom flag kept.
// - 2026-05-10 resumed pass on this VA only: tried 10 more variants: natural do/while,
//   for without separate outer guard, for with outer guard, preloaded y, explicit goto,
//   one-return result local, reversed comparisons, ternary abs expressions, byte-pointer
//   land pointer, and radius-before-pointer ordering. No exact. Natural/goto/preload
//   forms still compile to 96-byte text and checker cannot compare; comparable for-loop
//   forms either start with wrong param load/order or keep duplicated count guard and
//   shifted tail. Current checked-in comparable 97-byte family remains best.
// Left in scratch: current source is the best comparable 97-byte family, not exact and not
// an accepted_drift candidate because the duplicate loop guard and shifted tails are broader
// than a localized harmless scheduling/register drift. No inline asm/hacks used.

struct RGE_Object_Info_Line {
    char gap_00[0x24];
    long land_inner_radius;
};

struct RGE_RMM_Object_Generator {
    char gap_000[0x12C8];
    char lands_area[0x18F8 - 0x12C8];
    long land_num;  // +0x18F8

    unsigned char to_close(RGE_Object_Info_Line* info_line, long x, long y);
};

unsigned char RGE_RMM_Object_Generator::to_close(RGE_Object_Info_Line* info_line, long x, long y) {
    long i = 0;
    long count = this->land_num;

    if (count > 0) {
        long radius = info_line->land_inner_radius;
        long* p_y = (long*)((char*)this + 0x12CC);

        for (; i < count; i++, p_y += 4) {
            long dx = x - *(p_y - 1);
            if (dx < 0) dx = -dx;

            long dy = y - *p_y;
            if (dy < 0) dy = -dy;

            if (dx < radius && dy < radius) {
                return 1;
            }
        }
    }

    return 0;
}
