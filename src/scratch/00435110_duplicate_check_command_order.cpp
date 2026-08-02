// RGE_Command::duplicate_check_command_order
// VA: 00435110
// Command.cpp:1070-1092
// 153 bytes
//
// Attempt log:
// 1-3: Basic C++ version. 144B prologue (no push ecx/push ebp), inline failures.
// 4: goto fail for shared epilogue — same result (goto-skip-init errors resolved).
// 5: Declared all locals at top, goto fail — same 144B.
// 6: Added long* p1_units, p2_units locals — same 144B.
// 7: Inline ftol comparisons without short locals — same 144B.
// 8: Compound && condition — same 144B.
// 9: volatile int dummy — same 144B.
// 10: long* p1/p2 declared early — 153B but prologue still wrong (3 pushes, no ecx/ebp).
// 11: Explicit n1/n2 for count, p1/p2 for arrays — same 153B.
// 12: Manual delta pointer sub — no improvement.
// Boss retry 2026-05-19:
// 13: Shared `goto fail` with top-declared i and explicit p1/p2 unit pointers: major improvement
//     to exact-size 153B, 33/153 positional (21.57%), 32 edit bytes. It restored push ecx/push ebp,
//     shared fail epilogue, stack-stored unit pointers, and BP ftol temps.
// 14: Reversed float comparison source operands. y compare improved but x fld order worsened; net
//     unchanged metrics. Kept improved shared-fail source.
//
// Persistent differences from original:
// 1. Prologue/local setup still schedules count load before last_order load; original loads last_order first.
// 2. Some register choices differ (ECX/EDX swapped for unit pointer homes; ECX vs EDX target compare).
// 3. First x-coordinate ftol evaluation is reversed from original; y can be matched only by worsening x.
// 4. Success zero-count branch target/epilogue placement is still shifted by extra fallthrough bytes.
//
// Left in scratch. Not proposing accepted_drift (remaining drift spans prologue scheduling, compare order,
// and branch layout, not a tiny localized benign difference).
// Retry 2026-05-20: 20 more probes. Best improved to exact-size 153B, 17.6471% positional/edit by using
// nested positive success predicates instead of shared goto-fail for the top checks. Tried last_n/local
// forcing, split declarations, volatile last_order load, param-units-before-count, manual/delta loop,
// result local, target operand swap, explicit ftol temps, and alternative x/y compare spellings. None
// fixed the stable early scheduling mismatch: VC5 still emits `xor/load param count` before pushing EBP
// and before loading `last_order`, while original pushes EBP/ESI and loads last_order first. Remaining
// diffs also include x ftol operand order and ECX-vs-EDX target compare coloring. Not accepted_drift:
// broad prologue/FPU/compare scheduling, not localized benign drift.
// Retry 2026-05-21 Boss pass: 10 more probes. Tried split last_order-first declarations,
// volatile last_order load, delaying n until after pointer locals, explicit x ftol temps,
// reversed x comparison spelling, target-id operand swap, manual delta loop, explicit
// goto-fail/success-label form, result local, and delaying p1/p2 until loop. Best stayed
// the current exact-size 153B source at 17.6471% positional/edit, first mismatch +6.
// Remaining mismatch is stable VC5 scheduling/register coloring: count load before
// EBP/ESI/last_order, x ftol operand order, and target compare register choice. Leaving
// in scratch; no accepted_drift because the drift spans prologue/FPU/compare scheduling.
// Retry 2026-05-24 Boss pass: 19 more probes. Revalidated current exact-size best (17.6471% positional/edit, first mismatch +6). Tried last_order/p2 before n, target compare operand swap, explicit x/y ftol temps, early last unit count, delta-pointer loop, do-loop, pointer-walk while, flat && predicate, reversed FPU comparisons, volatile/register last_order, register param, uchar/int/long/volatile n widths, and const pointer locals. No variant improved on the current source; loop rewrites and uchar/volatile count regressed badly. Stable blocker remains the same early scheduling/coloring (VC5 loads param count before EBP/ESI/last_order), plus FPU operand order and target compare coloring. Not accepted_drift: broad prologue/FPU/compare scheduling, not localized benign drift.
// Retry 2026-05-26 Boss pass: 15 more probes. Revalidated current exact-size best (17.6471% positional/edit, first mismatch +6). Tried split last_order-first declarations (matched prologue through last_order but introduced early unit-pointer LEA/store and worsened to 23.5%), last_order+n+m+p declaration/assignment variants, char last-count local, direct member count, target-id operand swap, explicit ftol int locals, volatile float rereads, negative-goto form, and do/pointer-walk loop. None beat current best; several compile/regressed or worsened branch/FPU layout. GIVEUP: no accepted_drift because remaining drift is still broad prologue scheduling, FPU operand order, target compare coloring, not a localized benign difference.
// Retry 2026-08-02 Luna-435110 (10 meaningful probes): full RGE_Command data/polymorphic context was tested; the
// polymorphic declaration plus raw unsigned-char* last_order and reversed source operands for both coordinate
// comparisons improved the best to 24/153 positional bytes (15.6863%), exact size, all 4 calls/64 instructions,
// first mismatch +6. Ground-truth nested target/param+1 layout regressed; volatile last_order over-framed; reversed
// pointer declarations regressed; late target_id local was codegen-neutral. Remaining drift is broad prologue
// scheduling/register coloring (original saves EBP/ESI and loads last_order before count), pointer register roles,
// and final target compare register (original EDX versus rebuilt ECX). Left in scratch; no accepted_drift.
// Retry 2026-08-02 Luna435110 (10 meaningful probes): separate count locals, reversed count operands, raw/opaque
// last_order views, donor virtual/data type context, and two focused declaration/layout variant labs produced no
// improvement; the best remained the current 153-byte/24-byte-diff candidate. The final typed RGE_Obj_Info target
// and trailing-record layout regressed to 33 bytes. Restored the clean candidate; broad prologue/register coloring
// remains unresolved, so this stays in scratch rather than accepted_drift.

class RGE_Command_Order {
public:
    long unknown_00;    // +0x00
    long target_id;     // +0x04
    unsigned char unit_num; // +0x08
    char pad_09[3];     // +0x09 to +0x0B
    float pos_x;        // +0x0C
    float pos_y;        // +0x10
    long units[1];      // +0x14 (variable length)
};

class RGE_Command {
public:
    virtual void do_command_give_attribute(void*);
    virtual ~RGE_Command();
    virtual void do_command(void*);
    void* world; // +0x04
    unsigned char* last_order; // +0x08 (raw storage in the real class)
    long last_order_size; // +0x0C
    long last_order_time; // +0x10
    void* com_hand; // +0x14

    unsigned char duplicate_check_command_order(RGE_Command_Order* param_1);
};

unsigned char RGE_Command::duplicate_check_command_order(RGE_Command_Order* param_1)
{
    RGE_Command_Order* last_order = (RGE_Command_Order*)this->last_order;
    unsigned int n = (unsigned char)param_1->unit_num;
    long* p1 = param_1->units;
    long* p2 = last_order->units;
    int i;

    if (n == (unsigned char)last_order->unit_num) {
        if ((short)(int)last_order->pos_x == (short)(int)param_1->pos_x) {
            if ((short)(int)last_order->pos_y == (short)(int)param_1->pos_y) {
                long target_id = last_order->target_id;
                if (target_id == param_1->target_id) {
                    for (i = 0; i < (int)n; i++) {
                        if (p1[i] != p2[i])
                            goto fail;
                    }
                    return 1;
                }
            }
        }
    }
fail:
    return 0;
}
