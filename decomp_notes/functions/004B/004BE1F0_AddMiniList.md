# Function notes: 004BE1F0 `AddMiniList`

Module notes: `decomp_notes/spanlist_module.md`.

## Translation-unit context

- PDB module: `spanlist.cpp`; owner: `TSpan_List_Manager`.
- The target starts at `004BE1F0` and ends at `004BE236`; `AddLine_Align`
  precedes it at `004BE090`.
- `VSpanMiniList` is a three-byte record: `Y_delta`, `X_start`, `X_end`.
- `Y_delta == 0xFF` ends the walk. Each record advances by three bytes.
- Typed `++list` preserves the proven three-byte record step.
- Each valid record calls `AddSpan(X_start + x_off, X_end + x_off,
  Y_delta + y_off)`.

## Current mismatch

- Focused result: `MATCH`, `0.0000%`, 71/71 bytes, 33/33 instructions.
- The frame and saved registers match: no frame; `ebx`, `ebp`, `esi`, `edi`.
- The one direct `AddSpan` call aligns. The owner symbol and boundary match.
- One relocation is safely masked and targets `AddSpan`.
- There is no current structural difference.
- Worker audit: `build/audits/workers/wave20-spanlist/spanlist/report.txt`.
- The grouped audit included 29 normal functions. It retained 22 registered
  owner matches and found this target exact as an unregistered grouped match.
- The audit reported a three-byte regression for registered `DeleteShape`
  (`004BE4B0`). This worker changed only `AddMiniList`; do not alter that row
  here. Other queued rows are pre-existing `AddSpan`, `AddLine_Align`,
  `AddShape`, `DecodeLine`, and `take_snapshot` issues.

## Recovered attempt history

<!-- recovered:40d5c64bd0f7280019bc -->
### `target-session` `build/target_sessions/004BE1F0_AddMiniList.json:1-7`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 behavior; result=MATCH; diff=0; shape=100.0: Mirror exact SubtractMiniList source shape with canonical Y_delta/X_start/X_end ownership, copied offsets, and natural AddSpan call order.
probe 3 liveness; result=MATCH; diff=0; shape=100.0: Walkback: remove copied x/y offset locals and use incoming parameters directly. [same emitted code as probe 2]
probe 4 liveness; result=MISMATCH; diff=51; shape=85.29411764705883: Walkback: remove the carried y_delta local and reread the canonical byte field.
probe 6 abi; result=MATCH; diff=0; shape=100.0: Walkback: remove explicit this qualifier from the AddSpan member call. [same emitted code as probe 3]
probe 7 behavior; result=MATCH; diff=0; shape=100.0: Walkback: remove explicit int casts from unsigned-byte span endpoints. [same emitted code as probe 6]
probe 8 liveness; result=MATCH; diff=0; shape=100.0: Reduced exact source: remove copied offset locals after proving direct parameter use is codegen-identical. [same emitted code as probe 7]
probe 9 liveness; result=MATCH; diff=0; shape=100.0: Walkback from reduced exact source: split y_delta declaration from its field initialization. [same emitted code as probe 8]
```
<!-- end-recovered:40d5c64bd0f7280019bc -->

<!-- recovered:d3f6488bc8471e3d806a -->
### `037950f4de84` `src/scratch/004BE1F0_AddMiniList.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// first pass: walk 3-byte span records, stop on 0xFF in the first byte, and feed each span into AddSpan
// tried direct AddSpan calls, swapped offset parameter names, and an unsigned-int first-byte compare; the remaining mismatch stayed in the early prolog / branch-displacement basin
```
<!-- end-recovered:d3f6488bc8471e3d806a -->

## Rejected approaches

- Reversed source parameter names (`yoff, xoff`) preserved the apparent call
  semantics but recolored the two offset registers and differed by two bytes.
- A temporary `line` local emitted the same exact bytes but added no source value.
- Explicit `int` casts on the byte fields emitted the same exact bytes and were
  removed from the final natural form.
- Numeric pointer arithmetic for the three-byte record step was rejected by
  policy. Typed `++list` emits the same exact bytes.

## Open questions

- No target-specific questions remain after the focused exact check.

## Next useful approaches

- The coordinator can review promotion. No further source experiment is
  needed unless the registered audit changes. The `DeleteShape` regression
  needs separate coordinator review.

## Worker updates

- 2026-08-29 (`wave20-spanlist`): corrected the natural parameter order and
  removed incidental locals and casts. Focused checks progressed from a
  two-byte register recolor to `MATCH`, `0.0000%`. The final focused check and
  grouped audit are exact. The exact source is pinned for the coordinator.
- 2026-08-29 (`wave20-spanlist`): replaced numeric record stride arithmetic
  with typed `++list`. Focused and target-session checks remain exact. The
  grouped audit keeps this target exact and reports an unrelated `DeleteShape`
  three-byte regression.
