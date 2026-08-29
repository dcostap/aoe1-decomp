# Recovery journal: 0046DE30 `TPicture`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Picture.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Picture.cpp`.
- Earlier recovery note: `recovery_notes/Picture_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:f570c2f675ddf65845bd -->
### `a5fb96a1e6de` `src/scratch/0046DE30_TPicture.cpp:1-9`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0046DE30 TPicture::TPicture(int file_handle, int param_2)
// Picture.cpp lines 25-76

// attempt 3: proper file-read / bitmap-allocation constructor
// ret 8, takes 2 params (file handle + transinfo flag)
// 366/366 exact size, 14 diff bytes
// Remaining: push order for calloc (1 vs dib_size first) + extra mov ecx,esi before malloc
// Both are VC5 optimizer scheduling artifacts
// Left in scratch.
```
<!-- end-recovered:f570c2f675ddf65845bd -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
