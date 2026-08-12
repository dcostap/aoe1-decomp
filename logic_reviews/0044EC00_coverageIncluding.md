# Logic review: 0044EC00 `InfluenceMap::coverageIncluding`

## Phase transition

The main agent suspended ordinary exact matching after six independent claims,
26 meaningful probes, 45 recorded checks, focused variant labs, exact donor
searches, and one final same-TU donor-order test. The candidate remains
`src/scratch/0044EC00_coverageIncluding.cpp`.

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

Pending.

## Main-agent adjudication

Pending.

## Integrated changes

The final donor-order experiment was restored before phase entry. The main agent
validated the unchanged normalized source at 275 bytes and four strict differing
bytes.

## Final decision

Pending.
