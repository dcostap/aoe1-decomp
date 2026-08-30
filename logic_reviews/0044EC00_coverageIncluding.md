# Logic review: 0044EC00 `InfluenceMap::coverageIncluding`

Current source: `src/infmap.cpp`. This ledger contains historical review evidence.

## Phase transition

The main agent suspended ordinary exact matching after six independent claims,
26 meaningful probes, 45 recorded checks, focused variant labs, exact donor
searches, and one final same-TU donor-order test. The candidate remains
`src/infmap.cpp`.

Current validated checker state:

- original/rebuilt size: 275/275 bytes;
- frame: `0x10` / `0x10`;
- saved registers: `EBX`, `EBP`, `ESI`, `EDI` in both;
- calls: none;
- instructions: 94/94;
- conditional branches: 14/14;
- returns: 2/2;
- instruction shape: 98.94%;
- exact-block coverage: 91.49%;
- strict difference: 4 bytes in one span at `+0x96`;
- edit/resync cost: 2 bytes.

The sole emitted-code difference is instruction order. The executable emits
`shl edi,2; inc eax`; VC5 emits `inc eax; shl edi,2`. Both instructions update
independent values before their uses. Matching work tested declaration order,
row-count forms, y-reference caching, typed and explicit row cursors, loop forms,
standard-header context, and focused variants. A final exact same-TU donor-order
probe broadened the output to 143 differing bytes and was restored.

The retained source uses the binary-backed `InfluenceMap` layout, typed
`XYPoint` references, natural bounds checks, an inclusive x/y scan, byte map
accesses, and the proven threshold expression. It contains no fake volatility,
manual vtable calls, raw absolute addresses, or codegen-only control flow.

### Semantic questions at entry

1. Verify every bounds predicate and its signedness.
2. Verify inclusive loop bounds, empty or reversed ranges, and termination.
3. Verify row indexing, reference-point subtraction, and byte access width.
4. Verify unsigned-byte promotion for `minimum`, `amount`, and map values.
5. Verify the two-part threshold predicate, including addition overflow behavior.
6. Verify when and how `coverageCountValue` changes the returned value.
7. Verify null, invalid, aliased, and malformed input fault and read order.
8. Verify calling convention, reference parameters, return value, and memory effects.

## Review rounds

### Round 1 — concurrent blind cohort, 2026-08-12

- `sa-8c41609c` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-85be266b` — `deepseek/deepseek-v4-flash`, high

#### Luna report

The reviewer found no definite difference.

Verified behavior:

- `coverageCountValue` is read before validation at `0044EC03`.
- The eight validation reads and signed predicates match at
  `0044EC0B–0044EC70`. Every invalid coordinate returns zero.
- Reversed X returns the original count. Reversed Y skips map reads but still
  processes each X, matching `0044EC76–0044ECF7`.
- Both loop bounds are inclusive.
- Row and byte indexes use y/y-reference and x/x-reference as modeled.
- Each qualifying map byte is read twice, at `0044ECA1` and `0044ECB5`, with
  matching short-circuit order.
- `minimum`, `amount`, and map values use unsigned-byte promotion. Their sum is
  at most 510.
- The count increments only when value is below minimum and adding amount
  reaches minimum.
- Return values, cleanup, and `__thiscall` ABI match.

Plausible concerns:

1. Signed overflow in translated x/y indexes, while the executable wraps.
2. Signed overflow of `rVal++`, while the executable `inc` wraps.
3. Invalid row pointers and out-of-range indexes are undefined in C++ but raw
   machine accesses in the executable.
4. Concurrent or externally changing memory is outside ordinary non-volatile
   C++ behavior.

Conclusion: ordinary paths match. Machine-specific malformed-state overflow and
invalid-pointer behavior required main-agent adjudication.

#### DeepSeek report

The reviewer traced all 94 instructions.

Verified ABI and predicates:

- `__thiscall`, four stack arguments, `ret 10h`, and saved-register restoration match.
- All eight bounds checks occur in exact source order with signed branches.
- Reversed ranges and inclusive loop conditions match.
- Inner setup uses the proven fields `+4`, `+8`, `+0C`, `+10`, `+18`, and `+1C`.
- The row count is `to.y-from.y+1`, with a positive guarded do-loop.
- Address arithmetic and the two byte reads match exactly.
- The first compare is unsigned. The second signed compare is equivalent because
  every operand is nonnegative and the sum is at most 510.
- Count increment, row advance, loop countdown, returns, and cleanup match.

Access and fault order match: object fields, row pointer, first byte, optional
second row-pointer and byte read. The source preserves the executable's raw
translated indexes and repeated expression. The sole scheduling gap at `+0x96`
contains no memory operation or fault.

Findings: no definite difference and no open semantic concern. Original
identifier spelling and runtime occurrence of malformed indexes are
unestablished but do not change fidelity.

## Main-agent adjudication

- **Bounds, loops, indexes, widths, threshold, return, and ABI:** confirmed by
  both independent traces.
- **Signed-overflow concerns:** cleared under the pinned VC5 execution model.
  The current rebuilt object emits the same 32-bit `sub`, `inc`, scale, and
  address operations. The four differing bytes only exchange independent
  `shl edi,2` and `inc eax` scheduling.
- **Invalid-pointer and translated-index concerns:** cleared as source-difference
  findings. The current object emits the same memory access instructions and
  order. The source intentionally retains the executable's unchecked indexes.
- **Concurrent mutation:** cleared as outside the non-volatile single-threaded
  surface modeled by both the original and candidate. There is no call inside
  the scan that can modify fields through ordinary execution.

Round 1 found no substantive open behavior issue. No source change is justified.

### Round 2 — fresh concurrent blind cohort, 2026-08-12

- `sa-718da62f` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-2ca56fee` — `deepseek/deepseek-v4-flash`, high

Both reviewers traced the complete function and found no definite behavior
difference. Luna confirmed every bound, loop, byte predicate, repeated read,
return, and ABI path. DeepSeek verified all 94 instructions and the raw
executable bytes. It confirmed the same translated-address operations, repeated
reads, and fault order in the pinned VC5 object.

The main agent cleared the abstract overflow concerns against the pinned VC5
emission. No differing instruction affects arithmetic values, memory, branches,
or faults. Round 2 has no open substantive finding.

## Integrated changes

The final donor-order experiment was restored before phase entry. The main agent
validated the unchanged normalized source at 275 bytes and four strict differing
bytes before and after both rounds.

## Final decision

Promote to `verified_logic` status. Two fresh blind cohorts converged with no open
behavior uncertainty. The four byte drift is one independent instruction-order
swap with no memory or control-flow effect.
