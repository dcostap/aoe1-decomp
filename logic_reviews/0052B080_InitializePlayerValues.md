# Logic review: 0052B080 `T_Scenario::InitializePlayerValues`

## Phase transition

The main agent suspended ordinary exact matching on 2026-08-02 after many
independent assignments and more than one hundred documented source, type,
layout, liveness, control-flow, context, flag, and scheduling hypotheses. The
latest bounded pass established typed `Player_Start_Info` and `_padding_`
layouts, corrected declaration/order pressure, and reduced the strict difference
from the previous 78-byte best to 23 bytes. Remaining differences are confined
to loop-induction scheduling and VC5's choice to hoist the repeated constant 200.
Natural pointer, index, increment, declaration, volatile, direct-store, memset,
loop-form, constant-spelling, and optimization-flag families have repeatedly
collapsed into the same compiler basins. No credible exact-match lead remains
without genuinely new compiler-IR or translation-unit evidence.

Current validated checker state:

- source remains `src/scratch/0052B080_InitializePlayerValues.cpp`;
- original/rebuilt size: 123/123 bytes;
- frame: none/none;
- saved registers: `ebx, ebp, esi, edi` / `ebx, ebp, esi, edi`;
- calls: 0/0;
- CFG signals: 1/1 conditional branch, 0/0 jumps, 1/1 returns;
- instructions: 40/41;
- instruction shape: 85.37%; exact-block coverage: 45.00%;
- strict difference: 23 bytes in 3 spans, first mismatch `0052B0A0`;
- edit/resync cost: 23 raw, 9.35% bounded, 108 equal bytes.

The first differing hunk merely schedules the three independent induction
updates as rebuilt `add eax,4; add ecx,10h; inc edx` instead of original
`inc edx; add ecx,10h; add eax,4`. The other principal hunk loads 200 into a
register for its two stores instead of issuing two immediate stores. Exactness
is still absent, and behavior must be established formally rather than inferred
from the small diff.

### Cumulative matching evidence

- Exact function size, prologue/epilogue, saved registers, loop topology,
  iteration count, stack home, all object offsets, all store widths, and the
  post-loop write are represented.
- `Player_Start_Info` is modeled as four contiguous 32-bit fields, with `Food` at
  scenario offset `+0x1998`; `_padding_` begins at `+0x18CC`.
- Natural `memset(block, 0, 16)` preserves the original four explicit zero-write
  effects and recovered the original zero-block register family.
- Moving `saved` before the player-info pointer recovered the original prologue
  and stack-home schedule; typed member addresses then recovered all memory
  offsets and the tail exactly.
- Exhausted families include direct versus typed byte-offset pointers, indexed
  and advancing loops, prefix/postfix updates, update order, declaration order,
  separate and reused locals, volatile pointers/stores/zeros/constants, explicit
  zero stores, `memset`, counter widths, goto/for/while/do forms, constant
  spellings/locals, and broad VC5 optimization/context flags.
- Many source variants are emitted-code duplicates. The retained source is the
  closest natural defined candidate and improves substantially over every prior
  validated state.

### Semantic questions at entry

Blind reviewers must establish these directly from the executable:

1. The exact initial pointers, 16-iteration bound, update timing, and whether the
   reordered independent induction instructions can affect any address or value.
2. Every zero/constant store, including duplicate or overwritten writes, exact
   32-bit width, ordering, and whether volatile/MMIO/callback observability is
   possible for the scenario memory.
3. Exact destination offsets for each per-player field and the final post-loop
   `1` store, including first/last iteration boundaries.
4. Whether `memset(block, 0, 16)` has precisely the same runtime writes and fault
   behavior as the original four stores under the pinned build/runtime model.
5. Aliasing, overlapping-memory, malformed-object, integer-overflow, and invalid
   pointer cases permitted by the binary, including whether the typed source
   introduces assumptions absent from emitted code.
6. Whether hoisting 200 into a register changes any observable behavior or only
   instruction selection.
7. Any difference in memory-write order that could matter through overlap,
   asynchronous observation, faults, or exceptional behavior.

## Review rounds

No formal blind review round has been integrated yet.

## Main-agent adjudication

Pending independent review.

## Integrated changes

None during logic review yet.

## Final decision

Pending. The function remains in `src/scratch` and must not move to
`src/verified_logic` while any substantive finding is unresolved.
