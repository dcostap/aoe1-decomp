# Natural `rmm_elev.cpp` semantic review

## Scope

This review covers the five non-exact RMM elevation rows on main at
`fa2a6a47c`:

- `00484700` `generate`
- `004847C0` `check_start_elevation`
- `004848A0` `check_elevation`
- `00484B90` `link_stack_randomly`
- `00484D00` `base_elevation_generate`

The oracle is the original PDB, source map, and executable assembly. Fresh
checks were run for `00484700`, `004847C0`, and `00484D00`. Status data for the
other two rows came from the current live status and source evidence.

## Canonical evidence

`include/map.h` defines a 24-byte `RGE_Tile`. Its byte at `+0x05` has five
terrain bits and three `height` bits. The original elevation code reads this
byte, masks `0x1f`, shifts by five, and preserves the terrain bits on writes.

`include/rmm_base.h` defines `Map_Stack` with `x`, `y`, `cost`, `tot_cost`,
`next`, and `prev`. `src/rmm_base.cpp` proves that shared stack entries store
`x = column` and `y = row`. `pop_stack` returns these fields in that order and
then removes the node.

The elevation code therefore uses the first stack output as the column and the
second output as the row. Its `search_map_rows[row][column]` and
`map_row_offset[row][column]` accesses are correct.

## Row decisions

| VA | Current result | Preserved behavior | Unproven behavior | Recommendation |
| --- | --- | --- | --- | --- |
| `00484700` | 187 rebuilt bytes vs 191; 154 strict differences | Clears the stack. For a positive elevation count, writes the base height to every map tile and keeps terrain bits. Calls `generate_modifiers`, then processes each elevation line and calls `clean_elevation` with the same bounds. Returns `1`. | No behavior gap was found. The remaining gap is broad loop and local code generation drift. | **`verified_logic` candidate.** It is too broad for `accepted_drift` and is not `matching`. Keep the current row in scratch until the required ledger and fresh review process are complete. |
| `004847C0` | 224 rebuilt bytes; 149 strict differences | Clamps both inclusive bounds. Scans map rows and tiles in the same order. Tests `terrain == 0xff`, terrain bits, and `height < elevation` in the same order. Returns `0` on the first failure and `1` after the scan. It also keeps the original next-row load before the loop-end test. | Only private stack-home, register, and block-shape choices remain unproven. The function has no calls or writes. | **`accepted_drift`.** The source behavior is proved. The residual is local code generation drift. |
| `004848A0` | 408 rebuilt bytes; 286 strict differences | Keeps the radius-positive first scan, four clipped bounds, row and tile traversal, early failure predicate, fixed-radius second scan, height equality count, and low-byte return. It has no calls or writes. | Private local-home and loop-shape choices remain unproven. | **`accepted_drift`.** The two scans and their fault order are behavior-equivalent. |
| `00484B90` | 234 rebuilt bytes; 2 strict differences | Publishes the same doubly linked `stack_array` chain. Uses the same map-area/16 count, random sites `0xfa` and `0xfb`, width/height scaling, `stack_offsets[row][column]` selection, and `add_stack_node` calls. | No behavior gap was found. The two bytes are the opposite load order for a commutative height/width product. | **`accepted_drift`.** This is a small proved codegen difference. |
| `00484D00` | 1,274 rebuilt bytes vs 1,273; 1,093 strict differences; 23/23 calls aligned | Keeps the stack setup, first seed phase, `check_start_elevation` gate, `remove_area_from_lists`, height writes, four neighbor pushes, random mark threshold, `check_elevation` gate, weighted neighbor pushes, repeat condition, and stack cleanup. The first `pop_stack` output is the column and the second is the row. The four neighbor checks match left, right, up, and down traversal. | The frame and control-flow shape remain broad. Zero or invalid `clumps` floating conversion, private cost-output slot reuse, and all edge fault behavior need a formal semantic pass. The current body also uses the legacy context header and is not a final canonical owner. | **`scratch`.** The main map and stack behavior is supported, but the broad residual and open edge questions do not support `accepted_drift` or `verified_logic` yet. |

## Policy note

The reviewed bodies still include `rmm_elev_context.h` through fragment sources.
That header is not a canonical owner. A later status move must first use the
natural module owner with `rmm_elev.h`, `rmm_base.h`, and private `map.h`
access. This review makes no status or ownership change.

## Validation

- `00484700`: `MISMATCH`, 187/191 bytes, 154 strict differences.
- `004847C0`: `MISMATCH`, 224/224 bytes, 149 strict differences.
- `00484D00`: `MISMATCH`, 1,274/1,273 bytes, 1,093 strict differences, 23/23
  ordered calls.

No source or metadata was changed by this review.
