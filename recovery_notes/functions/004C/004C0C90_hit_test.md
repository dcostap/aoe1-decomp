# Recovery journal: 004C0C90 `hit_test`

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


<!-- recovered:06f1a814ab5ed0b2d553 -->
### `target-session` `build/target_sessions/004C0C90_hit_test.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MATCH; diff=0; shape=100.0: Fresh standalone baseline: prior matching source remains exact; grouped context drift is two SIB bytes.
```
<!-- end-recovered:06f1a814ab5ed0b2d553 -->

<!-- recovered:75696a643b4750a190a6 -->
### `1d6744467d66` `src/scratch/004C0C90_hit_test.cpp:1-25`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C0C90 RGE_Sprite::hit_test(short, short, long, long)
// sprite.cpp
//
// Attempt log:
// - Established the RGE_Sprite box/draw-list/facet ownership and the
//   binary-observed 16-byte picture-list stride.
// - A nested box-presence guard plus an explicit while scan reproduces the
//   original size, frame, ordered calls, and branch topology.
// - The remaining mismatch is VC5 register/liveness coloring in the scan;
//   raw cross-member cursor experiments improved bytes only marginally and
//   were restored to this typed entry form.
// This pass tested a named draw-list base, a materialized parent facet
// denominator, and a typed pointer-increment scan. The normalized typed walk
// is the living source (137-byte diff); the raw-cursor 124-byte result remains
// diagnostic history only. Remaining drift starts at child-entry coloring.
// Follow-up bounded pass: a top-level byte index restored the original early
// EBX zero and improved the emitted diff to 124 bytes, but all base/member
// cursor spellings remained in the same VC5 basin. Function-scope pointer and
// counter declarations, delayed entry materialization, and a byte-buffer
// cursor were nonproductive or duplicate-codegen probes. A six-variant local
// shape lab found no exact candidate; its best raw indexing form was rejected
// as noncanonical. Restored the typed source below; residual drift is the
// original child-entry register/liveness schedule.
// Main-agent audit confirmed typed 0x10-byte picture-entry traversal and child
// sprite ownership; no byte cursor survives.
```
<!-- end-recovered:75696a643b4750a190a6 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
