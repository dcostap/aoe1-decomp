# Recovery journal: 004D68A0 `compare`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taiconmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taiconmd.cpp`.
- Earlier recovery note: `recovery_notes/taiconmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:9dd503b5d80ce7b1a726 -->
### `d050eea3c` `src/taiconmd.cpp:258-258`

Mapping: `strong`. comment lies after mapped function compare at old line 252.

```text
    // BINARY NOTE: Read left first. A null left faults before a null right.
```
<!-- end-recovered:9dd503b5d80ce7b1a726 -->

<!-- recovered:c37d10476ee685a9d130 -->
### `target-session` `build/target_sessions/004D68A0_compare.json:1-2`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Baseline before access repair; target bytes are exact, but grouped symbol audit reports public QAEP instead of PDB protected IAEP.
probe 2 abi; result=MATCH; diff=0; shape=100.0: Protected compare declaration follows PDB decorated owner IAEP; bytes should remain unchanged while owner symbol is corrected. [same emitted code as probe 1]
```
<!-- end-recovered:c37d10476ee685a9d130 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
