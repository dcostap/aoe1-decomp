# Logic review: 00435110 `RGE_Command::duplicate_check_command_order`

## Phase transition

The main agent suspended ordinary exact matching after repeated independent assignments, more than one hundred documented source/type/control-flow/liveness hypotheses, and four focused variant labs covering approximately sixty variants. Independent phase-readiness audit found repeated convergence on the same exact-size 24-byte register/scheduling basin and no credible unexplored exact-match lead.

Current validated checker state:

- candidate: `src/scratch/00435110_duplicate_check_command_order.cpp`;
- original/rebuilt size: 153/153 bytes;
- frame: none/none;
- saved registers: `ebx, ebp, esi, edi` / `ebx, ebp, esi, edi`;
- calls: 4/4, ordered and target-aligned (`__ftol` four times);
- CFG: 7/7 conditional branches, 0/0 jumps, 2/2 returns;
- instructions: 64/64;
- instruction-shape similarity: 93.75%; exact-block coverage: 71.88%;
- strict difference: 24 bytes in 9 spans, first mismatch `00435116`;
- edit/resync cost: 24 raw, 7.84% bounded, 137 equal bytes.

The remaining drift is concentrated in prologue load/save scheduling and register coloring. The executable saves EBP/ESI and loads `last_order` before loading the parameter's byte count; the candidate hoists the count load and consequently swaps several pointer/target registers. From `0043513A` onward, the float conversions, array comparison loop, stack slots, success/failure tails, and `ret 4` are substantially aligned.

### Cumulative matching evidence

- Eight or more sequential matching passes tested declaration/initialization order, count widths, natural loop and branch forms, shared-failure control flow, typed and raw class surfaces, compare operand order, explicit float-conversion temporaries, `register`/volatile diagnostics, and target-load spellings.
- Four deliberate variant labs collapsed approximately sixty variants into a few duplicate emitted-code groups; none matched.
- The retained source is normalized ordinary C++ with typed fields and a binary-supported shared failure tail. It contains no fake volatility, inline assembly, manual vtable calls, or decompiler cursor arithmetic.
- Exact size, frame, call identities/order, CFG counts, instruction count, return cleanup, reads, and return values are stable.
- Same-family accepted-drift functions exhibit the same early load/save scheduling class, but this function is entering semantic review independently rather than inheriting their decision.

### Semantic questions at entry

Blind reviewers must establish directly from the executable:

1. Exact `RGE_Command_Order` field widths and offsets, especially byte `unit_num`, float coordinates, target ID, and the variable-length unit array.
2. Signedness and bounds of the unit loop, including zero count and all byte-range values.
3. Exact float-to-integer conversion and subsequent `short` truncation semantics for both coordinates, including NaN, infinities, overflow, and x87 conversion behavior.
4. Exact comparison order, short-circuit paths, memory-read/fault order, and shared failure/success returns.
5. Calling convention, four `__ftol` calls, stack cleanup, and return-byte behavior.
6. Whether the residual prologue/register scheduling changes any observable fault-time context or memory-read order on invalid pointers.

## Review rounds

### Round 1 (complete; four reviewers)

- Broad adversarial reviewer: normal-path arithmetic, comparisons, loop, calls,
  returns, and cleanup agree, but reported a definite fault/read-order difference
  at entry. The executable loads `this->last_order` before `param_1->unit_num`;
  the current rebuild performs the parameter read first. With valid `param_1`
  and invalid `this`, the candidate therefore reads `param_1+8` before faulting,
  while the executable faults on `this+8` first. Verdict: needs attention.
- ABI/numeric reviewer found no blocking result, width, loop, `__ftol`, ABI, or
  cleanup difference and independently confirmed the intentional low-16-bit
  coordinate comparison behavior, including NaN/infinity/overflow cases.
- Control/memory reviewer confirmed all ordinary predicates and memory effects,
  but found that both coordinate equalities are spelled in the reverse operand
  order. The executable reads/converts `param_1->pos_x/pos_y` first; the candidate
  reads/converts `last_order->pos_x/pos_y` first. Results are commutatively equal,
  but fault and signaling-NaN exception order differ. Recommended remedy: put
  `param_1` on the left for both coordinate comparisons.
- Full machine-effect reviewer independently confirmed both defects. It also
  identified changed upper-EAX residue on a Y mismatch and a stack-alias case in
  which the candidate's earlier callee-save push could overwrite a count byte
  before reading it. Verdict: needs attention.

## Main-agent adjudication

Both ordering findings are substantive because the executable is the oracle for
fault, exception, and stack-alias behavior. The ABI/numeric review's `correct`
verdict applies to ordinary values and confirms the predicates, widths, and
low-16-bit conversion quirk, but does not rebut the concrete machine-order
counterexamples reported by the other three reviewers.

The main agent integrated the natural source-order corrections and confirmed the
new emitted prologue against the oracle. It now loads `this->last_order`, reads
the incoming count, reads the last-order count, and delays `push edi` in the same
order as the executable. Both coordinate pairs now convert `param_1` first.
The first strict mismatch moved from +6 to +0x18; the remaining first hunk is the
placement of non-faulting unit-pointer LEAs relative to the already-equivalent
count branch.

## Integrated changes

- Reversed both coordinate equalities to evaluate `param_1` first, preserving
  coordinate fault/FPU-exception order and mismatch register residue.
- Moved count rejection before unit-pointer declarations. This changed VC5's
  prologue to the executable's dereference/push order and preserves malformed
  pointer and stack-alias behavior.
- Revalidated the corrected candidate: 153/153 bytes, 64/64 instructions, 4/4
  ordered calls, 29 strict differing bytes, first mismatch +0x18.
- A fresh post-fix blind cohort is required before promotion.

## Final decision

Pending completion of the post-fix cohort.

### Round 2 (post-fix; in progress)

- Numeric/ABI reviewer found no blocking difference. It independently verified
  the corrected full dereference order (`this->last_order`, both count bytes,
  param-first X/Y conversions, target IDs, then p1/p2 units), malformed-pointer
  fault order, low-16-bit `__ftol` quirks for NaN/infinity/overflow, loop bounds,
  AL-only return contract, stack aliases, and `ret 4` cleanup.
- Two concurrent post-fix machine/adversarial reviewers remain pending.
- Adversarial reviewer found the early-return rewrite introduced a new P1
  machine-order defect: p1/p2 homes became conditional, occurred after the first
  coordinate load, and occupied opposite stack slots. Stack-overlapping records
  and trapping coordinate loads therefore differed. It also reported caller-
  saved register residue differences. Verdict: needs attention.

The main agent restored a nested count guard and reversed pointer declarations.
The emitted object now writes p2 to `[esp+10h]` and p1 to `[esp+18h]`
unconditionally before the count branch and all coordinate loads, while retaining
param-first coordinate conversion and `this->last_order` as the first object
dereference. A narrower pre-existing ordering gap remains: rebuilt `push edi`
still precedes the last-order count read, unlike the executable. Promotion is
blocked pending the final machine reviewer and any further natural source remedy.

- The remaining round-2 machine reviewer completed against the superseded
  29-byte early-return candidate. It independently reproduced the same swapped,
  delayed pointer-home defect and volatile-residue differences, while verifying
  all ordinary record/FPU/loop/ABI behavior. Its source-faithful verdict does not
  clear the concrete stack-alias defect and is stale for the corrected 28-byte
  candidate. A fresh round-3 reviewer is evaluating the current emitted object.
