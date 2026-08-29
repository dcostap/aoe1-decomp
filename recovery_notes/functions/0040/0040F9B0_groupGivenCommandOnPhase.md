# Recovery journal: 0040F9B0 `groupGivenCommandOnPhase`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/aipbook.cpp`.
- PDB source: `C:\msdev\work\age1_x1\aipbook.cpp`.
- Earlier recovery note: `recovery_notes/aipbook_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:6d956f8f5b1cf46a4ea9 -->
### `d050eea3c` `src/aipbook.cpp:431-431`

Mapping: `ambiguous`. next mapped function definition is groupGivenCommandOnPhase at old line 601.

```text
// The current source is nonexact. See recovery_notes/aipbook_module.md.
```
<!-- end-recovered:6d956f8f5b1cf46a4ea9 -->

<!-- recovered:212765474a1366622f92 -->
### `d050eea3c` `src/aipbook.cpp:603-604`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// 0040F9B0 AIPlay::groupGivenCommandOnPhase
// Scratch status: the current natural result escapes its original boundary.
```
<!-- end-recovered:212765474a1366622f92 -->

<!-- recovered:8cbfb4117d38a4208f07 -->
### `e5b22f4df482` `src/scratch/0040F9B0_groupGivenCommandOnPhase.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0040F9B0 AIPlay::groupGivenCommandOnPhase (132 bytes)
// Attempt log:
// - Previous source suggested accepted drift, but live check was broad (48% positional) due scheduling/stack-slot mismatch and local command body.
// - 2026-05-10 StarryZephyr pass: tried removing local AIPlayPhase::command body and forcing parameter stack-slot write/reload for
//   the observed byte compare. VC5 still kept the type byte in EDX and produced a 128-byte too-short text window, so restored
//   the comparable 132-byte baseline. No accepted_drift: branch distances, loop body, and tail/padding drift remain broad.
```
<!-- end-recovered:8cbfb4117d38a4208f07 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
