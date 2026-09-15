# `rmm_tdbc.cpp` source-cleanup report

## Delivery

- Module: `C:/Projects/my_decomps/aoe1_attempt3/src/rmm_tdbc.cpp`
- Report: `C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/source_cleanup/wave04/rmm_tdbc.md`
- Branch: `cleanup/staging-20260915-233`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Source commit: `5df422526a5fb85e1fbc5213ee0c748fa8b78ad7`
- Report commit: `52c19609b735b7002f80859acced969624d22a79`
- Assigned header: `C:/Projects/my_decomps/aoe1_attempt3/include/rmm_tdbc.h` (read only)

The source owns the ten registered PDB procedures in source order. The header,
registry, globals, and all other modules were not edited.

## Evidence reviewed

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/004876C0_TRIBE_RMM_Database_Controller.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/004876F0_TRIBE_RMM_Database_Controller.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/00487710_init.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/00487930_de_init.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/00487940_add_land_module.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/00487DD0_add_terrain_module.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/00487FA0_add_object_module.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/00488700_add_elevation_module.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/004887A0_add_shallows_module.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/00488870_generate.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/aoe1_ghidra_assembly_listing.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/rmm_tdbc.cpp.decomp`
- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/rmm_tdbc.cpp.json`

I inspected the procedure-scoped parameters, locals, stack records, and
`this` register for every registered procedure. Every procedure records
`this` in `ecx`. No procedure has a function-static record.

## PDB coverage and name recovery

| VA | PDB lines | Records | Result |
| --- | ---: | ---: | --- |
| `004876C0` | 44-45 | 2 | Recovered constructor parameters. |
| `004876F0` | 52-53 | 2 | Recovered the file parameter. |
| `00487710` | 57-152 | 49 | Recovered parameters and cliff-info names. |
| `00487930` | 156-160 | 3 | No local or parameter rename. |
| `00487940` | 165-312 | 82 | Recovered the fixed-position parameter. |
| `00487DD0` | 321-385 | 38 | Existing local names already match. |
| `00487FA0` | 392-567 | 73 | Recovered the retry-counter name. |
| `00488700` | 572-588 | 9 | No local or parameter rename. |
| `004887A0` | 593-608 | 7 | Recovered the shallows-info name. |
| `00488870` | 614-629 | 9 | Recovered the return-value name. |

The first constructor now uses the PDB names `land_file`, `terrain_file`,
`object_file`, and `map_file`. The integer constructor uses `infile`.

`init` now uses `in_map`, `in_world`, `type`, `player_num`, and
`fixed_position`. Its local names are `cliff_info`, `base_cliff_size`, and
`base_cliff_length`. The PDB records for the two base-cliff locals share one
stack home. Their uses prove the mapping: size supplies the cliff count, and
length supplies the average and variance calculations. The source keeps both
existing declarations and does not change their storage or scope.

`add_land_module` now uses `fixed_positions`. `add_terrain_module` already uses
the PDB names `land_tile_num` and `tile_ratio`. Those records share an
optimized stack home across sequential lifetimes. The source keeps both
separate declarations.

`add_object_module` keeps the outer loop name `index`. The PDB `index1` record
maps to the inner retry counter initialized before the placement loop. The PDB
names `count` and `done` already match the source. The `extra_island_roll`
record has no safe one-to-one source declaration mapping after optimization and
byte-level home reuse, so no declaration was added or renamed for it.

`add_shallows_module` now uses `shallows_info`. `generate` now uses `ret_num`.
`add_elevation_module` has no procedure-scoped local record, so its existing
names remain unchanged. Generated loop names and other locals without a direct
PDB mapping also remain unchanged.

The adjacent records at `0048790A` and `00488675` were reviewed. They are not
registered source procedures. They are the switch-data boundary and the
parent-owned padding or alias boundary, so no source declaration was added.

PDB spellings were kept as recorded. The cleanup does not normalize mixed
styles such as `in_map`, `player_num`, `index1`, and `ret_num`.

## Source changes

- Restored supported PDB parameter and local names.
- Moved function-definition and applicable block braces to 1TBS style.
- Kept types, scopes, declarations, storage, casts, expressions, evaluation
  order, calls, constants, source order, and explicit `this->` unchanged.
- Added no assembly, wrapper, helper, or source owner.
- Changed no resource lookup, resource ID, global, header, or comment.

No behavior change is intended. Identifier and brace changes do not add or
remove executable statements.

## Header request

Owner 26 should update the declaration names in
`C:/Projects/my_decomps/aoe1_attempt3/include/rmm_tdbc.h` only. Add the
recovered names to the four-parameter constructor:
`land_file`, `terrain_file`, `object_file`, and `map_file`. Add `infile` to the
integer constructor. Add `in_map`, `in_world`, `type`, `player_num`, and
`fixed_position` to `init`. Add `fixed_positions` to `add_land_module`.

This request changes declaration names only. It does not change types, order,
ABI, or class layout. The source owner already uses these names.

## Validation and limits

The complete Git diff was reviewed. `git diff --check` passed.

No build, compiler check, matching check, audit, test, or game run was done.
This follows the wave-04 cleanup restriction. Final binary validation remains
pending the separate post-cleanup comparison stage.
