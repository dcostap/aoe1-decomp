# Recovery journal: 004354F0 `command_stop`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Command.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Command.cpp`.
- Earlier recovery note: `recovery_notes/Command_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:3872ef38408d55817ec4 -->
### `912332e8f578` `src/matching/004354F0_command_stop.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// RGE_Command::command_stop — MATCH (171B)
// VA: 004354F0
// Key fixes: use the real member-call/logging surface instead of helper wrappers; compute
// `dst = buf + 2` before the null check to match the original `lea eax,[esi+2]` before `je`;
// copy via a char-byte delta from source array to destination so VC5 emits the exact
// `[ecx+eax]` addressing form in the packed id copy loop.
```
<!-- end-recovered:3872ef38408d55817ec4 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
