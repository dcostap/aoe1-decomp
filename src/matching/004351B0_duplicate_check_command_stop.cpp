// 004351B0 RGE_Command::duplicate_check_command_stop
//
// Attempt log:
// - HollowSnowdrop pass: tried low-level pointer-delta scan and natural forms. Best prior while-loop remains exact size 89/89 but wrong prologue/loop-addressing. Low-level version improved initial param load but still pushes before last_order load and hoists pointer increments differently; rolled back to best natural behavior source.
// - LemonLily pass: tried packed RGE_Command_Stop (+2 unaligned int items), raw +1/+2 byte-offset forms, param-first and last-first locals, direct this->last_order uses, pointer-delta loops, nested ifs, for/while/do loops, volatile param read, and temporary flag probes (/O2 no /Oy, /Ot, /Og, /Ox, /O1, /Oa, /Ow). No exact.
// - 2026-05-10 StarryZephyr pass: rechecked baseline (89/89, first mismatch offset 4) and tried an explicit `last` local before reading param fields. That loads last_order before the parameter but reverses initial EAX/ECX roles, worsens first mismatch to offset 1, and keeps duplicate loop guard. Restored baseline.
// - 2026-05-10 SpruceGlow Boss-assigned pass: tried 20 variants: last-first, direct struct, do/for delta scans, index/raw scans, unsigned/char n, param-local, nested-if, memcmp-like, no-local direct last_order, countdown, fail/success labels, int*/long* item pointers, while-true break, no explicit n>0 guard, and result local. No exact.
// - Best kept source is the `long*` item-pointer form below: exact size, same control-flow/tails, edit diff 16, first mismatch offset 8. It preserves behavior and removes the prior duplicate loop guard, but VC5 still schedules `xor edx`/unit_num load before `push esi` and swaps the two loop loads (`mov esi,[eax]` / `mov ebx,[edi+eax]`) relative to original (`mov esi,[edi+eax]` / `mov ebx,[eax]`).
// ACCEPTED_DRIFT: reviewed by Boss. Same size, same control flow, same returns, same stack cleanup, and same memory effects for valid command buffers. Remaining drift is localized to scheduling/register choice: zero/unit_num load is moved before saved-register pushes, pointer setup is interleaved differently, and the loop compares the two dword loads in the opposite commutative order. No predicate/call/copy-size change.
// Exact translation-unit finish: the real earlier Command.cpp owner at
// 004348F0 selects the original register schedule. The shared command surface
// then matches all 89 bytes. Target-only compilation emits the reviewed load
// and register-order drift.

#ifndef COMMAND_CONTEXT_H
struct RGE_Command_Stop {
    char pad_00[1];
    unsigned char unit_num;
    int items[1];
};

class RGE_Command {
public:
    char gap_00[8];
    RGE_Command_Stop* last_order;

protected:
    unsigned char duplicate_check_command_stop(RGE_Command_Stop* param1);
};
#endif

unsigned char RGE_Command::duplicate_check_command_stop(RGE_Command_Stop* param1) {
    int n = *(unsigned char*)((char*)param1 + 1);
    long* p = (long*)((char*)param1 + 2);
    RGE_Command_Stop* last = (RGE_Command_Stop*)this->last_order;
    long* l = (long*)((char*)last + 2);

    if (n != *(unsigned char*)((char*)last + 1)) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (p[i] != l[i]) {
            return 0;
        }
    }

    return 1;
}
