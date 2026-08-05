# Logic review: 00480610 `RGE_TimeSinceLastCall::GetHiLoInfo`

## Phase transition

The main agent suspended ordinary exact matching after numerous independent passes, more than thirty meaningful source/type/control-flow/liveness hypotheses, a focused 48-case variant lab, and repeated convergence on stable VC5 parameter-home/register-allocation basins. An independent phase-readiness audit found no unresolved behavior, ABI, layout, call, or memory-effect fact, but required removal of codegen-only control-flow residue before ledger entry.

The candidate remains `src/scratch/00480610_GetHiLoInfo.cpp`. Before entry, the main agent removed a redundant positive-count guard already implied by the `1..100` range and normalized an empty positive branch to `if (idx <= 0) idx = 100`. The previously pinned 11-byte diagnostic used fake volatile/home-read scaffolding and is not the review candidate.

Current validated normalized checker state:

- original/rebuilt meaningful size: 132/126 bytes (128 extracted);
- frame: none/none;
- saved registers: `ebx, ebp, esi, edi` / `ebx, ebp, esi, edi`;
- calls: 1/1, ordered and target-aligned (`sprintf`);
- original/rebuilt instructions: 54/54;
- CFG: 7/6 conditional branches, 1/1 jump, 1/1 return;
- instruction-shape similarity: 87.04%; exact-block coverage: 33.33%;
- strict difference: 108 bytes in 3 spans, first mismatch `00480626`;
- edit/resync cost: 42 raw, 16.15% bounded, 104 equal bytes.

### Cumulative matching evidence

- Repeated passes tested exact class layout, signed/unsigned local surfaces, declaration and initialization order, direct parameter countdown, parameter-home aliases, register qualifiers, natural loop forms, compare algebra, invalid-path assignment forms, focused flags, and a 48-case home/tail lab.
- The closest 11-byte emitted candidate required fake volatile stack-home rereads and empty/redundant branch scaffolding. Those forms were rejected during source normalization despite their better metrics.
- Exact same-TU donors prove `RGE_TimeSinceLastCall` layout and the `__thiscall char*(int)` surface.
- The normalized candidate uses ordinary bounded control flow, unsigned accumulation/division, named fields, and one `sprintf` call; no opaque scheduling trick remains.

### Semantic questions at entry

Blind reviewers must establish directly from the executable:

1. Exact valid range, offset decrement/wrap rule, array element range, and loop iteration count.
2. Signedness/width of sum, minimum, maximum, quotient, and `sprintf` arguments, including overflow and division behavior.
3. Exact invalid-count fallback values and whether any array/member read occurs on invalid inputs.
4. Evaluation and memory-read order, especially for invalid object pointers and unusual `Offset` values.
5. Format string, argument order, destination buffer, return pointer, calling convention, and cleanup.
6. Whether normalization removed only redundant source conditions or changed any binary-observed edge behavior.

## Review rounds

No formal blind cohort has yet been adjudicated.

## Main-agent adjudication

Pending a complete concurrent blind cohort.

## Integrated changes

- Removed codegen-only redundant/empty branch scaffolding.
- Revalidated and repinned the normalized natural source; the expected metric regression from the 11-byte diagnostic to 108 strict bytes is explicitly nonsemantic pending blind verification.

## Final decision

Pending.
