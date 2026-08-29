# Recovery journal: 00470F80 `group_objects`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/player.cpp`.
- PDB source: `C:\msdev\work\age1_x1\player.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:1563b19e2244a1996417 -->
### `target-session` `build/target_sessions/00470F80_group_objects.json:1-15`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=6; shape=100.0: Fresh grouped-TU rebuild with full player surface; six SIB bytes differ from original.
probe 2 variant; result=MISMATCH; diff=6; shape=100.0: Natural pointer-arithmetic array spelling for all groups_used accesses; tests whether VC5 preserves this as base-plus-index in full grouped context. [same emitted code as probe 1]
probe 4 variant; result=MISMATCH; diff=6; shape=100.0: Explicit this->groups_used array member spelling; tests whether the full-class member path selects original base/index SIB order. [same emitted code as probe 2]
probe 6 context; result=MISMATCH; diff=6; shape=100.0: Context axis: retain full authentic RGE_Game_World surface but restore the prior RGE_Object_List first virtual declaration; tests whether its real class surface controls SIB operand order. [same emitted code as probe 4]
probe 7 context; result=MISMATCH; diff=6; shape=100.0: Context axis: keep full GameWorld and ObjectList surfaces but use the two-field RGE_Object_Node surface; tests whether node layout metadata selects original SIB order. [same emitted code as probe 6]
probe 8 layout; result=MISMATCH; diff=6; shape=100.0: Layout/type axis: model groups_used as the period C++ char[127] table rather than unsigned char; tests whether member element type controls SIB operand order without changing offsets. [same emitted code as probe 7]
probe 9 context; result=MATCH; diff=0; shape=100.0: Context isolation: retain only the world destructor plus required addObject/removeObject declarations, with full fields and current ObjectList/Node surfaces; identifies whether the expanded world surface drives SIB order.
probe 10 variant; result=MISMATCH; diff=6; shape=100.0: Natural address-of-member array spelling (*(&groups_used[0] + index)) under the full world surface; tests whether explicit array-element address recovers original SIB base/index order. [same emitted code as probe 8]
probe 12 context; result=MISMATCH; diff=6; shape=100.0: Context axis: retain full GameWorld virtual surface and add the PDB-supported nonvirtual updateObject declaration; tests whether the authentic missing method restores original SIB order.
probe 13 context; result=MISMATCH; diff=6; shape=100.0: Context axis: apply PDB-supported protected/public access bands to the full RGE_Game_World virtual surface; tests whether authentic access declarations restore original SIB ordering. [same emitted code as probe 10]
probe 14 context; result=MISMATCH; diff=6; shape=100.0: Authentic surface axis: add the PDB-listed nonvirtual RGE_Game_World method declarations absent from player_tu_context while retaining all proven virtual slots; tests whether complete class context restores SIB order. [same emitted code as probe 13]
probe 15 variant; result=MISMATCH; diff=6; shape=100.0: Natural integral index cast axis: use (long)i for groups_used reads and writes while preserving the proven short loop induction; tests VC5 type-tree choice for SIB base/index. [same emitted code as probe 14]
probe 17 layout; result=MISMATCH; diff=6; shape=100.0: Canonical typedef axis: express groups_used as an unsigned-char[127] typedef member; tests whether VC5 array-type spelling changes SIB base/index under the full world surface. [same emitted code as probe 15]
probe 19 layout; result=MISMATCH; diff=6; shape=100.0: Layout axis: remove only the trailing post-groups padding while preserving all touched offsets; tests whether complete RGE_Player size metadata controls SIB encoding. [same emitted code as probe 18]
probe 20 context; result=MISMATCH; diff=6; shape=100.0: Canonical context retry after moving the shared RGE_Player and RGE_Tile_List definitions before dependent player declarations. [same emitted code as probe 19]
```
<!-- end-recovered:1563b19e2244a1996417 -->

<!-- recovered:db60d14ed195e70967b3 -->
### `056a20c24f68` `src/scratch/00470F80_group_objects.cpp:1-40`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00470F80 RGE_Player::group_objects
// PDB source: player.cpp, lines 1933-2009
//
// Baseline reconstruction: reserve or recover a group number, clear that
// group from existing objects when requested, then mark this player's
// selected objects with the resulting group.
//
// Attempt log:
// - Added the proven polymorphic player/object/list surfaces and a byte
//   selected_group local; BL then reproduces the original table-byte tests,
//   parameter-home reuse, and common selected-object stores.
// - Bounded for scans (rather than peeled do/while forms) recover the first
//   search and second recovery search CFG; the natural typed source remains
//   in scratch because exactness stalled at 37 positional bytes (+9 bytes).
// - Remaining binary-local drift is the second memset setup order and the
//   common selection-tail counter compare/register order; no opaque steering
//   or fake volatility was retained.
// - An ordinary byte-clear loop compiles to the exact REP-stos block and
//   removes the memset setup-order drift; swapped count/index declarations
//   recover ESI-then-EDI zeroing. The remaining 24 bytes are the compiler's
//   nested count recheck/polarity and a 9-byte late tail beyond the boundary.
// - Outer-guard/goto, pointer/header, and typed dword-clear variants were
//   tested and restored; they either changed the whole CFG or worsened output.
// - A count-controlled `while (count < sel_count)` with an index increment and
//   post-bound break improved shape to 96.15%, but VC5 still emitted a second
//   count check before the back-edge; the original has one guard at the tail.
// - Inverting the post-bound test to `continue` below 0x19 was codegen-identical
//   and less direct, so the direct while/break form remains the best source.
// - The exact player.cpp ungroup_objects tail donor uses an index-bound while
//   with the selected-count guard first; using that natural short index/count
//   form removed the prior 24-byte tail drift and matched size and CFG.
// - Spelling the guard as `count >= sel_count` produced the original compare
//   operand order and closed the final 2-byte mismatch in the narrow owner
//   context.  The complete player TU retains a six-byte SIB-order drift after
//   the canonical RGE_Game_World virtual surface is restored for addObject.
//   Direct member, pointer, and commuted array expressions keep the same
//   register map.  Do not retain a non-source steering construct for this.
// - The grouped player build now uses the canonical RGE_Player declaration
//   from include/rge_player_context.h.  Its addObject/removeObject neighbors
//   emit the original 0xF8/0xFC world slots and exact 71/88-byte bodies.
```
<!-- end-recovered:db60d14ed195e70967b3 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
