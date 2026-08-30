# Function notes: 00484B50 `count_map_tiles`

Module notes: `decomp_notes/rmm_elev_natural_candidate.md`.

## Translation-unit context

- PDB module: `rmm_elev.cpp`, lines 211-221.
- Source order: constructor, `generate`, `check_start_elevation`,
  `check_elevation`, `generate_modifiers`, `fig_chance`, this function, then
  `link_stack_randomly`.
- Owner: `RGE_RMM_Elevation_Generator::count_map_tiles(uchar)`.
- Body: `00484B50-00484B85`, 54 bytes, `__thiscall`.
- Original code has no calls and no frame. It reads fields at `this+0x10`,
  `this+0x14`, and `this+0x18`.
- The loop scans `RGE_Tile` records with a 24-byte stride.

## Current mismatch

- No mismatch remains.
- Final code size is 54 bytes. The frame, calls, boundary, and relocations match.
- The rebuilt owner symbol is the expected `count_map_tiles` symbol.
- Final strict comparison: 0 differing bytes, 0.0000%.

## Recovered attempt history

<!-- recovered:323ad47f1f33fcadd3d5 -->
### `bb681882dea6` `src/matching/00484B50_count_map_tiles.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00484B50 count_map_tiles (54B)
// Keep byte-width comparisons
```
<!-- end-recovered:323ad47f1f33fcadd3d5 -->

### `wave20-rmm-elev` natural reconstruction

The source now uses a typed `RGE_Tile*` scan. It starts at
`map_row_offset[0]` and ends after `map_width * map_height` tiles. The
`terrain_type` bitfield supplies the original five-bit comparison.

- Fresh baseline: 93 rebuilt bytes, 100.0000% different, 32.50% shape match.
- Typed linear scan: 54 rebuilt bytes, `MATCH`, 0.0000% different.
- `map_row_offset[0]` replaced the equivalent first-element dereference with
  no code change.
- Count-first and named-total declaration order caused a 19-byte mismatch.
  The exact declaration order remains pinned.
- Raw `char*` access, explicit byte offsets, and explicit 24-byte stepping are
  not retained. They are less natural than the typed record model.

Focused validation used `target_session.py check` and
`check_function.py --no-build`. The final result has 24 aligned instructions,
100% exact-block coverage, matching saved registers, and no calls.

The grouped audit used the worker output directory. It compiled one group and
observed 10 normal functions. Two registered exact neighbors remained exact:
`004846C0` and `00484B30`. The target was an exact unregistered observation.

## Rejected approaches

- Row-and-column loops matched behavior but produced a 93-byte function.
- Count-first declaration order preserved behavior but changed instruction
  scheduling and produced a 19-byte mismatch.
- Raw pointer arithmetic can explain the bytes, but policy rejects raw offsets,
  aliases, and explicit record strides for this normal function.

## Open questions

- The coordinator must register or promote this exact natural source.
- No source or binary blocker remains for this function.

## Next useful approaches

- Keep the pinned typed scan unchanged.
- Run the standard promotion review. Do not alter status here.

## Worker updates

- `wave20-rmm-elev`: Recovered an exact natural typed scan. Pinned the clean
  source after focused and grouped validation. No status change was made.
