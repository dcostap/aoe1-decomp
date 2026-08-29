# Recovery journal: 00525D20 `start_game`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tribegam.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tribegam.cpp`.
- Earlier recovery note: `recovery_notes/tribegam_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:8a7311a301205a2effb9 -->
### `912332e8f578` `src/matching/00525D20_start_game.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00525D20 TRIBE_Game::start_game (299 B)
// PDB source: tribegam.cpp, lines 2586-2638
// Attempt log:
// baseline: natural start-game flow with period string-copy, status-message,
// world/scenario, and member-call surfaces reconstructed from the packet and
// same-TU donors; size/frame/call set matched, with only three LEA bytes off.
// declaration-order and register/local-result probes were codegen duplicates.
// 260-byte and 252-byte buffers changed the frame (104h/0fch); union overlay
// changed the copy topology; all were rolled back.
// exact: using the named 256-byte info_file directly (rather than the inferred
// decompiler +4 prefix) reproduces the original stack address and all 299 bytes.
// Main-agent audit restored the donor-backed scenario/world/base-game virtual
// slot declarations; the natural start-game source remains exact.
```
<!-- end-recovered:8a7311a301205a2effb9 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
