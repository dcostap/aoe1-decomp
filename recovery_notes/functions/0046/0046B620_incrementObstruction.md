# Recovery journal: 0046B620 `incrementObstruction`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/pathsys.cpp`.
- PDB source: `C:\msdev\work\age1_x1\pathsys.cpp`.
- Earlier recovery note: `recovery_notes/pathsys_module.md`.

## Translation-unit context

- PDB module: `C:\msdev\work\age1_x1\pathsys.cpp`.
- Natural owner: `PathingSystem::incrementObstruction(int, int)` in
  `src/pathsys.cpp`, after `obstruction` and before `decrementObstruction`.
- PDB lines: 641-652. Body range: `0046B620-0046B675` (86 bytes).
- Calling convention: `__thiscall`; the owner symbol and `ret 8` boundary match.
- The natural source uses the reviewed two-dimensional
  `obstructionValue[1020][255]` layout. The original address calculation is
  equivalent to row stride `sizeof(obstructionValue[0])`.

## Current mismatch

- Fresh baseline and final natural validation both rebuild 84 bytes versus 86
  original bytes. The final focused result is `MISMATCH`, 76 differing bytes
  (88.3721%), shape similarity 74.19%, and first mismatch at `0046B621`.
- The original saves `ebx`, `esi`, and `edi`. The natural rebuild saves only
  `ebx` and `esi`, so the body has 29 instructions versus 31 original.
- Both bodies have no calls, one conditional branch, and one return. The owner
  symbol matches. The shorter rebuild also reaches its end two bytes early.
- The original loads `y` before `x`, saves `edi`, and computes the row address
  as `x * 255 + (y >> 2)`. The natural two-dimensional source computes the
  equivalent address but VC5 loads `x` first and keeps the row product in
  `esi`.

## Recovered attempt history


<!-- recovered:71ad61b18e05d8054ebd -->
### `5868718576a8` `src/scratch/0046B620_incrementObstruction.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: pointer field + pointer math; total mismatch at offset 1 (prologue, all different)
// attempt 2: byte array + extern globals; first 52 bytes match, mismatch at +52 (VC5 saves cl to [esp+14h])
// attempt 3: mask computed early; param order swapped back (edx/eax reversed at offset 1)
// attempt 4: named ob var; same as attempt 2, cl saved to stack
// Original: keeps shift in cl through both shr and shl without spill; VC5 spills cl after shr
// Left in scratch: VC5 register liveness analysis differs, benign codegen drift, behavior correct
```
<!-- end-recovered:71ad61b18e05d8054ebd -->

### `wave21-pathsys` natural-source probes

- The fresh canonical two-dimensional baseline produced 84 bytes, 76 differing
  bytes, and 29 instructions.
- A y-first pointer expression, a byte-pointer cast, `sizeof` row arithmetic,
  precomputed row and column locals, and a separate byte alias all produced the
  same 84-byte code. These forms were not retained.
- The historical standalone flat-array source is useful evidence only. It
  hides the reviewed two-dimensional member shape and uses raw row-stride
  arithmetic. It cannot become the natural module source under current policy.
- The final source is the simple canonical expression:
  `&obstructionValue[x][y >> 2]`. No source improvement survived.

## Rejected approaches

- Flat obstruction aliases, raw row-stride indexing, and casts were rejected.
  They violate the natural-layout policy, and the cast probes did not change
  VC5 output in this translation unit.
- Extra row and column locals were rejected. They changed neither register
  allocation nor instruction order.

## Open questions

- What period declaration or compiler context made VC5 load `y` first, save
  `edi`, and keep the shift in `cl` through both shifts?
- A future exact attempt needs period source or an exact natural donor that
  proves this context without a flat alias, raw offset, overlay, or compiler
  steering.

## Next useful approaches

- Review this as a localized structural drift proposal only if the coordinator
  accepts the proven equivalent access and control flow.
- Otherwise search period source and same-TU exact donors for the missing
  two-dimensional declaration or compiler context.

## Worker updates

- `wave21-pathsys`: Rebuilt the natural source after a fresh baseline. Tested
  five materially distinct address forms. None improved code generation. The
  canonical two-dimensional source remains in `src/pathsys.cpp`; final
  validation remains a localized structural mismatch. The focused grouped
  audit (`build/audits/workers/wave21-pathsys/pathsys/report.txt`) kept all 15
  registered exact neighbors matched and reported this target at diff 76.
