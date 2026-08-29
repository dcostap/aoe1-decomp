# Recovery journal: 004D8C80 `blotExploredMap`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taiinfmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taiinfmd.cpp`.
- Earlier recovery note: `recovery_notes/taiinfmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:d70edb153734b6ca2e57 -->
### `6a2aef2e2` `src/taiinfmd.cpp:638-639`

Mapping: `ambiguous`. next mapped function definition is blotExploredMap at old line 741.

```text
// The binary identifies this +0x158 subobject as the path/InfluenceMap save
// surface; keep the local ABI narrow until the shared class layout is proven.
```
<!-- end-recovered:d70edb153734b6ca2e57 -->

<!-- recovered:f898db0c85e5f9d46b17 -->
### `00492347d989` `src/scratch/004D8C80_blotExploredMap.cpp:1-15`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TribeInformationAIModule::blotExploredMap
// VA: 004D8C80
// taiinfmd.cpp:870-890
// 152 bytes, not matched (parked)
// Takes rect coords, clamps via mapBound, then loops to set
// influence map values to 2 where not already 1.
//
// Attempt log (5+ variants):
// v0: XYPoint locals + influence pathMap → sub esp 0x14, reg alloc diff
// v1: flat layout, simpler structs → 40B diff, sub esp 0x10 matches
// v2: reordered assignments → still ~40B diff
// v3: temps for params + y-then-x store order → still registers diverge
//
// Remaining diff: register allocation (ECX/EDX/EAX for param loads)
// and store ordering. TU-context boundary issue.
```
<!-- end-recovered:f898db0c85e5f9d46b17 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
