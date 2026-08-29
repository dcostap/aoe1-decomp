# Recovery journal: 004C9230 `lay_down_impassable_terrain`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/t_b_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\t_b_obj.cpp`.
- Earlier recovery note: `recovery_notes/t_b_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:558059a79d73f7c6892d -->
### `30c9a04a1db9` `src/scratch/004C9230_lay_down_impassable_terrain.cpp:1-17`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004C9230 TRIBE_Building_Object::lay_down_impassable_terrain (t_b_obj.cpp:704-744, 292B)
// Lays down impassable terrain under a building by modifying tile terrain types (values 0, 1, 6).
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt notes:
// - Logic, FPU operations, field offsets, loops, and tile access all match correctly
// - Remaining ~5.1% edit diff (15 bytes) is from the cascaded val check:
//   * Original: `sub edx, 0; je handler; dec; je handler; sub edx, 5; jne skip`
//   * Rebuilt: `je handler; dec; je handler; add edx, -5; test edx, edx; jne skip`
//   * VC5 optimized away the identity (`sub edx, 0`) and flipped `sub edx, 5` to `add edx, -5`
//   * VC5 also inserts `test edx, edx` before `jne` (same quirk as lay_down_passable_terrain)
//   * The 1-byte cascade size shift propagates through the case handlers and epilogue
//   * Total size stays 292 (trailing nop makes up the difference)
// - FPU eval order: x_start→x_end→y_start→y_end (matched by declaration order)
// - Terrain type map: 0→(b&0xF0)|0x10, 1→(b&0xEF)|0x0F, 6→(b&0xEE)|0x0E
// - Three-level indirection: building→obj→map (same as lay_down_passable_terrain)
// - Tile access: `*(tile_data + row*4) + col*24` at byte offset 5
```
<!-- end-recovered:558059a79d73f7c6892d -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
