# Recovery journal: 00518F00 `logStatus`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tplayer.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tplayer.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:57945ad7afa6e6f54f21 -->
### `98727635e181` `src/matching/00518F00_logStatus.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA 00518F00 TRIBE_Player::logStatus
// tplayer.cpp:4744-4805
// Attempt log:
// 1: Direct source from packet/decompiler, preserving sequential fprintf/call pattern.
// 2: Recovered the canonical TRIBE_Player owner and shared tplayer ABI. The
//    virtual owner, frame, calls, and all 994 bytes now match the target.
```
<!-- end-recovered:57945ad7afa6e6f54f21 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
