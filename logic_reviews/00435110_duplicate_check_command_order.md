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

### Round 1 (in progress)

- Broad adversarial reviewer: normal-path arithmetic, comparisons, loop, calls,
  returns, and cleanup agree, but reported a definite fault/read-order difference
  at entry. The executable loads `this->last_order` before `param_1->unit_num`;
  the current rebuild performs the parameter read first. With valid `param_1`
  and invalid `this`, the candidate therefore reads `param_1+8` before faulting,
  while the executable faults on `this+8` first. Verdict: needs attention.
- Remaining concurrent reviewers are pending. No source change will be integrated
  until the cohort is complete; the leading natural remedy is to materialize the
  last-order count before the parameter count, then re-review emitted read order.

## Main-agent adjudication

The entry read-order finding is provisionally substantive because executable
fault order is part of the behavior oracle. Final adjudication awaits the full
cohort.

## Integrated changes

None at phase entry. The normalized candidate was validated unchanged.

## Final decision

Pending.
