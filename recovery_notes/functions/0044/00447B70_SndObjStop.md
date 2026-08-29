# Recovery journal: 00447B70 `_SndObjStop`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Dsutil.c`.
- PDB source: `C:\msdev\work\age1_x1\Dsutil.c`.
- Earlier recovery note: `recovery_notes/dsutil_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:24a9169c70940feda825 -->
### `bf81de068f12` `src/scratch/00447B70_SndObjStop.cpp:5-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// tried raw SNDOBJ pointer, then raw void* and register locals; mismatch stayed in prolog/basin
// tried direct vtable-slot calls for +0x48 and +0x34; call shape was close, but VC5 kept choosing EBP
```
<!-- end-recovered:24a9169c70940feda825 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
