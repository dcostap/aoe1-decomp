# `rmm_clif.cpp` cleanup report

## Delivery

- Module: `src/rmm_clif.cpp`
- PDB compiland: `C:\\msdev\\work\\age1_x1\\rmm_clif.cpp`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Final source commit: `d4622a4b8cd36b2bd76140d1d9e0222cff44db45`
- Final report commit: the commit that adds this report
- Changed files:
  - `src/rmm_clif.cpp`
  - `workflow/decomp_notes/source_cleanup/wave01/rmm_clif.md`
- Branch: `cleanup/staging-20260915-13`

The source commit restores names from procedure-scoped PDB records where the
mapping is safe. It also uses 1TBS braces. The body, types, scopes, calls, and
statement order stay the same. The report is a second assigned commit.

## Evidence reviewed

I reviewed these files and records:

- `config/functions/src/rmm_clif.cpp.json`
- `inventory/pdb/scoped_symbols.json`
- `inventory/functions/0048/00481980_RGE_RMM_Cliffs_Generator.txt`
- `inventory/functions/0048/004819C0_generate.txt`
- `inventory/functions/0048/00481A00_setup_cliff_maps.txt`
- `inventory/functions/0048/00481CD0_generate_cliff.txt`
- `inventory/functions/0048/00481FC0_check_for_valid_cliff_site.txt`
- `inventory/functions/0048/004820A0_invalidate_cliff_area.txt`
- `orig/ghidra_decomp/rmm_clif.cpp.decomp`
- `include/rmm_clif.h`
- `include/rmm_base.h`

The original executable path supplied for this module is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`

The registry lists six normal owners. They are at `00481980`, `004819C0`,
`00481A00`, `00481CD0`, `00481FC0`, and `004820A0`. The block at `00482081`
is padding between the last two owners. It is not a source owner.

## Full PDB recovery coverage

All six registry VAs have one procedure record in `scoped_symbols.json`.
Each record has `this` in ECX with type `RGE_RMM_Cliffs_Generator*`.
No procedure has a function-static record.

| VA | owner | PDB lines | body | stack records |
| --- | --- | --- | --- | ---: |
| `00481980` | constructor | 33-37 | 59 bytes | 3 parameters |
| `004819C0` | `generate` | 41-56 | 53 bytes | none |
| `00481A00` | `setup_cliff_maps` | 60-173 | 706 bytes | 8 locals |
| `00481CD0` | `generate_cliff` | 177-294 | 751 bytes | 9 locals |
| `00481FC0` | `check_for_valid_cliff_site` | 298-344 | 193-byte body | 4 parameters |
| `004820A0` | `invalidate_cliff_area` | 348-375 | 243 bytes | 7 records |

The PDB records contain 3, 6, 47, 37, 20, and 18 line records in source
order. This gives 131 reviewed line records.

### Constructor `00481980`

- `in_map`, `+0x4`, `RGE_Map*`
- `parent_module`, `+0x8`, `RGE_Random_Map_Module*`
- `cliff_info`, `+0xc`, `RGE_Cliffs_Info`
- `this`, ECX, `RGE_RMM_Cliffs_Generator*`

The source now uses all three PDB parameter names.

### `generate` `004819C0`

- No stack parameters or locals are present in the PDB record.
- `this`, ECX, `RGE_RMM_Cliffs_Generator*`

The source keeps the existing local `i`. The PDB does not prove another name.

### `setup_cliff_maps` `00481A00`

- `cliff_height2`, `-0x8`, `long`
- `cliff_width`, `-0x24`, `long`
- `cliff_width2`, `-0x4`, `long`
- `cliff_y`, `-0x28`, `long`
- `cliff_height`, `-0x18`, `long`
- `cliff_x`, `-0x2c`, `long`
- `water_area`, `-0x2d`, `unsigned char`
- `terrain_height`, `-0x14`, `unsigned char`
- `this`, ECX, `RGE_RMM_Cliffs_Generator*`

The source now uses the PDB names for the map bounds and the outer and inner
cliff coordinates. It keeps `area` for the tile-elevation accumulator. The
PDB name `terrain_height` is not applied because its record says
`unsigned char`, while the source declaration is `long`.

### `generate_cliff` `00481CD0`

- `index`, `-0x24`, `long`
- `this_cliff_size`, `-0x20`, `long`
- `cliff`, `-0x18`, `Map_Stack`
- `valid_height`, `-0x28`, `long`
- `y`, `-0x2c`, `long`
- `cost`, `-0x1c`, `float`
- `x`, `-0x30`, `long`
- `first_cliff`, `-0x31`, `unsigned char`
- `cliff_end_found`, `-0x32`, `unsigned char`
- `this`, ECX, `RGE_RMM_Cliffs_Generator*`

The source changed `start_x` to the PDB name `x`. The other PDB names were
already present. The source keeps the existing `long` declaration for `cost`.
The PDB record says `float`; this cleanup did not change the type.

### `check_for_valid_cliff_site` `00481FC0`

- `direction`, `+0x4`, `long`
- `x`, `+0x8`, `long&`
- `y`, `+0xc`, `long&`
- `valid_height`, `+0x10`, `long`
- `this`, ECX, `RGE_RMM_Cliffs_Generator*`

The old definition used `y`, `valid_height`, and `index` for these three
positions. The definition now uses the PDB names `x`, `y`, and
`valid_height`. The pointer aliases remain in place. They have no separate
PDB records.

The scoped-symbol size is 212 bytes, while the registry and function packet
show the 193-byte body ending at `00482080`. The 19-byte difference is a PDB
size versus body-range metadata difference. No source change tries to resolve
that metadata difference.

### `invalidate_cliff_area` `004820A0`

- `x`, `+0x4`, `long`
- `y`, `+0x8`, `long`
- `radius`, `+0xc`, `long`
- `cliff_height2`, `-0x4`, `long`
- `x2`, `+0x8`, `long`
- `x1`, `+0x10`, `long`
- `cliff_width2`, `-0x8`, `long`
- `this`, ECX, `RGE_RMM_Cliffs_Generator*`

The source changed `spacing` to `radius` and `min_x` to `x1`. It keeps
`max_x` because the PDB `x2` record shares the incoming `y` stack slot at
`+0x8`. The existing bound names already match the PDB where safe.

## Renames and supporting evidence

The following names changed in the source.

| VA | old source name | new name | evidence and limits |
| --- | --- | --- | --- |
| `00481980` | `map` | `in_map` | PDB parameter at `+0x4`, type `RGE_Map*` |
| `00481980` | `module` | `parent_module` | PDB parameter at `+0x8`, type `RGE_Random_Map_Module*` |
| `00481980` | `cliffs_info` | `cliff_info` | PDB by-value parameter at `+0xc`, type `RGE_Cliffs_Info` |
| `00481A00` | `terrain_height` | `cliff_height` | PDB long map-bound local at `-0x18`; use is `map_height / 3` |
| `00481A00` | `cliff_width_m1` | `cliff_width2` | PDB long bound local at `-0x4`; use is `cliff_width - 1` |
| `00481A00` | `terrain_height_m1` | `cliff_height2` | PDB long bound local at `-0x8`; use is `cliff_height - 1` |
| `00481A00` | `row` | `cliff_y` | PDB long coordinate local at `-0x28`; use is the outer cliff row |
| `00481A00` | `column` | `cliff_x` | PDB long coordinate local at `-0x2c`; use is the inner cliff column |
| `00481CD0` | `start_x` | `x` | PDB long local at `-0x30`; target uses this value as the brush start x coordinate |
| `00481FC0` | second `y` parameter | `x` | PDB `long&` parameter at `+0x8`; source pointer alias follows the PDB role |
| `00481FC0` | third `valid_height` parameter | `y` | PDB `long&` parameter at `+0xc`; source pointer alias follows the PDB role |
| `00481FC0` | `index` parameter | `valid_height` | PDB long value parameter at `+0x10`; it is the cell-height tag compared in the search map |
| `004820A0` | `spacing` | `radius` | PDB long parameter at `+0xc`; all three call sites pass a spacing radius |
| `004820A0` | `min_x` | `x1` | PDB long local at `+0x10`; it is the lower x endpoint |

The source does not force a mapping for reused stack slots. In particular,
`x2` shares the PDB stack offset of the incoming `y` parameter. The source
keeps `max_x` instead of forcing the `x2` name. The PDB `terrain_height`
record also remains unresolved because its type differs from the source
`area` declaration.

## Names retained without PDB recovery

These names remain because the PDB has no matching record, or because the
record does not prove a better mapping:

- `generate`: `i`.
- `setup_cliff_maps`: `terrain_width`, `row_offset`, `column_offset`,
  `area`, `valid`, `tile_row`, `tile_rows`, `tile_columns`, `tile`, `value`,
  `terrain`, `elevation`, `cell`, `hot_spot_index`, and `hot_spot`.
- `setup_cliff_maps` final pruning loop: `y`, `x`, and its `cell` pointer.
  The PDB coordinate records are scoped to earlier loop storage. The source
  does not force a second mapping to those records.
- `generate_cliff`: `variance`, `start_y`, `direction`, `stack_cost`,
  `map_row`, `column`, and `turn`.
- `check_for_valid_cliff_site`: `height_pointer` and `width_pointer`.
- `invalidate_cliff_area`: `min_y`, `max_y`, `max_x`, `row`, and `column`.

These are descriptive cleanup names already present in the source. They are
not claimed as recovered original names.

## Constants, resources, and comments

No constant or resource ID was added or renamed.

- The module has no resource lookup call.
- The module has no language or resource ID expression.
- `include/resource_ids.h` needs no mapping from this module.
- Existing numeric terrain values, strides, and brush values remain unchanged.
- No runtime DLL extraction was needed because this module does not look up a
  resource string.

One sparse comment was added in `invalidate_cliff_area`:

```cpp
// The shipped code compares the upper x endpoint with the height bound.
```

The function packet at `004820A0` proves this comparison. The comment records
that constraint without changing it. The source also retains the existing
comment that the hot-spot cursor starts at the `y` field. The packet at
`00481A00` proves that cursor anchor.

## Code-generation and behavior-sensitive points

- No type, cast, scope, storage duration, layout, call, relocation, or
  control-flow change was made.
- Identifier changes preserve the old declarations and expressions.
- The `check_for_valid_cliff_site` parameter names now match their PDB
  positions. Its argument types and ABI stay unchanged.
- The `invalidate_cliff_area` x2-versus-height comparison stays unchanged.
- The 1TBS changes move opening braces only.
- The added comment does not add a preprocessor token.
- No inline assembly was added.
- The registry and header were not edited.

The PDB type differences for setup `terrain_height` and generate-cliff `cost`
remain open. The PDB `x2` record also shares a slot with the incoming `y`
parameter. Changing any of these declarations would be outside this naming
pass and could change emitted code. No such change was made.

## Header requests

The owner of `include/rmm_clif.h` should update declaration parameter names in
a later header commit:

```cpp
RGE_RMM_Cliffs_Generator(RGE_Map* in_map,
    RGE_Random_Map_Module* parent_module, RGE_Cliffs_Info cliff_info);

uchar check_for_valid_cliff_site(long direction, long& x, long& y,
    long valid_height);
```

Evidence is the PDB parameter table above. These are parameter-name changes
only. They do not change the public type or ABI. I did not edit the header.

No resource or shared-constant request is pending.

## Validation

I reviewed the complete source diff and ran `git diff --check`.

Compilation, matching, audits, and tests were not run, as required for this
cleanup wave.
