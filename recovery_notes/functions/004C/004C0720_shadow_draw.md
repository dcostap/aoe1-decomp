# Recovery journal: 004C0720 `shadow_draw`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/sprite.cpp`.
- PDB source: `C:\msdev\work\age1_x1\sprite.cpp`.
- Earlier recovery note: `recovery_notes/sprite_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:186380ed2f128a7f2c07 -->
### `target-session` `build/target_sessions/004C0720_shadow_draw.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MATCH; diff=0; shape=100.0: Fresh standalone baseline: prior matching source remains exact; grouped context drift is two SIB bytes.
```
<!-- end-recovered:186380ed2f128a7f2c07 -->

<!-- recovered:e6e11e00a014a9ebae52 -->
### `5d0cbeb754fa` `src/scratch/004C0720_shadow_draw.cpp:1-26`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C0720 RGE_Sprite::shadow_draw
// PDB source: sprite.cpp, lines 656-684
// Baseline: canonical RGE_Sprite/RGE_Picture_List ownership with the natural
// draw-list scan and the observed facet-selection/fallback behavior.
// Attempts:
// - baseline reconstruction from the matching normal_draw sibling: 279 bytes,
//   with the wrong entry cursor and only 64.42% instruction-shape similarity.
// - parameter-left facet guard, <=0 list guard, function-scope count home, and
//   a typed 16-byte byte cursor: 272 bytes and 95.10% shape similarity.
// - raw decompiler-style top-level pointer locals and a named list base made
//   the function 259 bytes; both were rolled back.
// - a small source-shape lab over typed entry/cursor and update spellings found
//   no size-valid or exact variant (8 variants, 272/282-byte groups).
// - loading the child sprite before forming the entry address reproduces the
//   observed child-load-before-LEA topology and reaches 274 bytes / 32 differing
//   bytes. This raw view remains diagnostic only; it proves the 16-byte stride
//   and ordering, while the living source uses a typed pointer walk.
// Corrected the draw-list arm to call sprite->do_draw: original ECX is the
// child sprite, not the parent. The same binary-proven cursor source then
// reaches 19 differing bytes with exact size/calls and 91.18% block coverage;
// typed-entry probes were worse, but the living source is normalized to a
// typed RGE_Picture_List pointer walk rather than retain a raw cursor solely
// for metrics (current documented diff: 269 bytes). The 19-byte result is
// diagnostic history; corrected ownership remains the semantic baseline.
// Main-agent audit confirmed child-sprite draw ownership and the normalized
// typed entry traversal; no raw cursor survives.
```
<!-- end-recovered:e6e11e00a014a9ebae52 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
