# Recovery journal: 00501D70 `checkForBuildInsertion`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taitacmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taitacmd.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:e4edb6ffbea9b3e0bdab -->
### `d050eea3c` `src/taitacmd.cpp:15236-15243`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// ---------------------------------------------------------------------------
// PDB source owner: 00501D70_checkForBuildInsertion.cpp
// ---------------------------------------------------------------------------
// VA: 00501D70 TribeTacticalAIModule::checkForBuildInsertion(int,int,int)
// PDB source: taitacmd.cpp:12391-12497
// FLAGS: config/flags/00501D70_checkForBuildInsertion.rsp (/GX)
// Attempt log:
// - The old source used raw module offsets and a synthetic vtable. It reached
```
<!-- end-recovered:e4edb6ffbea9b3e0bdab -->

<!-- recovered:1f2c8e80f2d2777924cc -->
### `d050eea3c` `src/taitacmd.cpp:15245-15250`

Mapping: `strong`. comment lies after mapped function checkForBuildInsertion at old line 15234.

```text
// - Fresh reconstruction uses the same-TU module ownership and named fields.
//   The original switch body order remains a codegen question.
// - Corrected the complete nested layout. buildAI ends at +0x6C4,
// [non-comment lines omitted during migration]
//   module-offset macros. Keep it in scratch for parent-agent promotion.
```
<!-- end-recovered:1f2c8e80f2d2777924cc -->

<!-- recovered:d00c1bb093fc6254932a -->
### `6a2aef2e2` `src/taitacmd.cpp:12946-12948`

Mapping: `strong`. comment lies after mapped function checkForBuildInsertion at old line 12944.

```text
//   the target size but had the wrong frame and broad block layout.
//   informationAI starts at +0xCEC, and closestDropsiteValue is at +0x540.
// - The typed source is period-plausible and has no inline assembly or raw
```
<!-- end-recovered:d00c1bb093fc6254932a -->

<!-- recovered:12649af3fcbb02cf7c09 -->
### `d8d4df442d57` `src/scratch/00501D70_checkForBuildInsertion.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00501D70 TribeTacticalAIModule::checkForBuildInsertion(int,int,int)
// FLAGS: config/flags/00501D70_checkForBuildInsertion.rsp (/GX)
// Attempt log:
// 1: natural decompiler source with ResourceItem ctor/dtor and typed member calls; /GX required for EH frame.
// 2: /GX /Oy compiled but .text 752B too small vs original 814B; no-/GX even smaller (704B).
// 3: no-/Oy probe also 752B; original needs EH but source/control-flow still too compact.
// 4: rewrote top-level dispatch as `if (id != 0x32) { 44/4f } else { 32 }`; recovered same-size 814B but frame became 0xE8 vs original 0x78 and broad drift.
// 5: original dispatch is `cmp 32 je later; cmp 44 je middle; cmp 4f inline`; source order can recover size but not EH stack layout.
// 6: removed forbidden raw `__thiscall` vtable cast; modeled BuildAI vtable slot +0x48 with padded virtual method.
// 7: used raw MD offset macros (+0x104 buildAI, +0x10D7C resourceAI, +0x1256C aiPlayer, +0x122C closestDropsite) after typed MasterData gap produced invalid negative layout.
// 8: ResourceItem size 0x70 and /GX produce EH prologue with handler 00560BB0; call set/cleanup broadly plausible.
// 9: no-/GX is definitely wrong (704B, too small), /GX is required; custom flag retained.
// 10: left in scratch: best same-size check is 79.7297% positional / 104.0541% edit; first mismatch offset 25 at EH frame allocation (`sub esp,78h` vs `sub esp,0E8h`) and broad block order drift, not accepted-drift-safe.
```
<!-- end-recovered:12649af3fcbb02cf7c09 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
