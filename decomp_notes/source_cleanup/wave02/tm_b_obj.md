# `tm_b_obj.cpp` cleanup report

## Scope and commits

- Source: `src/tm_b_obj.cpp`
- Report: `decomp_notes/source_cleanup/wave02/tm_b_obj.md`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `bfeeaa062d35c6d0388e8c6d279a221779694253`
- Source commit head was copied from `git rev-parse HEAD` after the source commit.
- The source commit changed only `src/tm_b_obj.cpp`.
- The report is a second commit because its final hash cannot appear inside itself.

The source change recovers names from the procedure-scoped PDB data. It does not
change types, statements, calls, literals, scopes, or storage declarations.

## PDB inspection coverage

I inspected the `scoped_symbols.json` entry for every one of the 17 normal
source owners in `config/functions/src/tm_b_obj.cpp.json`. Each entry had a
`this` register symbol in `ecx`. No entry had a function-static symbol or an
additional register symbol.

| VA | Function | PDB parameters | PDB locals | Result |
| --- | --- | --- | --- | --- |
| `0050E040` | copy constructor | `other_object`, `do_setup` | none | Recovered both parameter names. |
| `0050E0C0` | integer constructor | `infile`, `sprites`, `sounds`, `do_setup` | none | Recovered `infile`; retained the other names. |
| `0050E130` | file constructor | `infile`, `sprites`, `sounds`, `in_id`, `do_setup` | none | Recovered `infile` and `in_id`; retained the other names. |
| `0050E1B0` | object `setup` | `other_object` | none | Recovered the parameter name. |
| `0050E250` | binary-file `setup` | `infile`, `sprites`, `sounds` | `sound_num` at `+0xc`; `sprite_num` at `+0x10` | Recovered the parameter and both PDB local names. The `sound_num` slot overlaps the `sounds` parameter slot. |
| `0050E360` | text-file `setup` | `infile`, `sprites`, `sounds`, `in_id` | none | Recovered `infile` and `in_id`. Local declarations have no scoped PDB names. |
| `0050E430` | destructor | none | none | No names to recover. |
| `0050E440` | `copy_obj` | `source` | none | Retained the recovered parameter name. |
| `0050E4D0` | `modify` | `amount`, `flag` | none | Recovered both parameter names. |
| `0050E500` | `modify_delta` | `amount`, `flag` | none | Recovered both parameter names. |
| `0050E530` | `modify_percent` | `amount`, `flag` | none | Recovered both parameter names. |
| `0050E550` | `save` | `outfile` | `sound_num` at `-0x4` | Recovered `outfile` and `sound_num`. |
| `0050E630` | five-argument `make_new_obj` | `owner`, `x`, `y`, `z`, `uID` | none | Recovered `owner` and `uID`; retained the other names. |
| `0050E6B0` | four-argument `make_new_obj` | `owner`, `x`, `y`, `z` | none | Recovered `owner`; retained the other names. |
| `0050E730` | `make_new_master` | none | none | No names to recover. |
| `0050E7A0` | `draw` | `render_area`, `x`, `y`, `player_color`, `facet`, `frame`, `draw_frame`, `frame_color` | `y4`, `y3`, `y2`, `y1`, `x4`, `x3`, `x2`, `x1`, `ry1`, `rx1` | Recovered all readable parameter and local names. |
| `0050E950` | `alignment` | `col`, `row`, `world`, `center_flag` | none | Recovered `col`, `row`, and `center_flag`; retained `world`. |

The generated deleting destructor at `0050E0A0` is not a source owner. It was
not counted as a source function.

## Recovered name mappings

The following names come from the PDB, not from inference:

- `0050E040`: `source` to `other_object`.
- `0050E0C0`: `id` to `infile`.
- `0050E130`: `file` to `infile`; `id` to `in_id`.
- `0050E1B0`: `source` to `other_object`.
- `0050E250`: `file` to `infile`; `sprite_id` to `sound_num`; `sound_id` to `sprite_num`.
- `0050E360`: `file` to `infile`; `id` to `in_id`.
- `0050E4D0`, `0050E500`, and `0050E530`: `value` to `amount`; `attribute` to `flag`.
- `0050E550`: `file` to `outfile`; `sound_id` to `sound_num`.
- `0050E630`: `player` to `owner`; `unique_id` to `uID`.
- `0050E6B0`: `player` to `owner`.
- `0050E7A0`: `area` to `render_area`; `color_table` to `player_color`; the unnamed `long` to `frame`; `add_gdi_node` to `draw_frame`; `draw_flag` to `frame_color`; `radius_x` to `rx1`; `radius_y` to `ry1`.
- `0050E950`: `x` to `col`; `y` to `row`; the unnamed flag to `center_flag`.

The PDB also confirms the existing `source` parameter in `copy_obj`, the
existing `x`, `y`, and `world` names in `draw` and `alignment`, and the
existing `do_setup`, `sprites`, `sounds`, `facet`, and coordinate names.

## Inferred and unresolved mappings

These names remain inferred because the scoped PDB has no matching local symbol:

- `0050E250`: `selected_sprite` and `selected_sound`.
- `0050E360`: `sprite_id`, `connect_flag`, `build_and_go_away`, `sound_id`, `selected_sprite`, and `selected_sound`.
- `0050E440`: `building_source`, the downcast local for the proven building-master source.
- `0050E550`: `sprite_id`.
- `0050E7A0`: `sprite` and `map`.

I left these declarations in place. I did not force a mapping through a reused
stack slot. In `0050E250`, the PDB records `sound_num` at the `sounds` argument
slot and `sprite_num` at `+0x10`; the source now uses those exact names without
changing the declaration order or the lookup order.

No resource ID or numeric constant needed a new name. No unresolved resource
purpose remains in this module.

## Constants and comments

The source commit adds no constants and replaces no literals. Existing values
remain unchanged. The inventory assembly supports `0x50` as the master-type
field write, `0x11` as the building-facet attribute test, and `1` as the
forwarded alignment flag. The `-1` sentinels and fixed read/write lengths also
remain unchanged.

The source commit adds no comments and changes no existing comments. The
existing `copy_obj` comment states that the virtual path receives a
building-master source. The PDB parameter type and the field accesses at the
building-master offsets support that note.

## Risk review

- All edits are identifier renames.
- No parameter type, return type, class layout, declaration scope, storage
  duration, cast, evaluation order, call target, literal, or ABI symbol changed.
- The recovered `uID` and `in_id` spellings preserve PDB capitalization.
- Naming the unused `frame` parameter does not add a use.
- The `0050E250` stack-slot overlap remains unresolved in layout terms. The
  source keeps the existing two local declarations and their order.
- The source still uses the existing natural owner and real inheritance.

## Header and resource requests

`include/tm_b_obj.h` belongs to owner 08. Please mirror the recovered parameter
names in its declarations. The requested names are:

- Constructors: `other_object`, `infile`, `sprites`, `sounds`, `in_id`, and
  `do_setup` in their existing signatures.
- Protected `setup`: `other_object`, `infile`, `sprites`, `sounds`, and `in_id`.
- `copy_obj`: `source`.
- `modify`, `modify_delta`, and `modify_percent`: `amount`, `flag`.
- `save`: `outfile`.
- Both `make_new_obj` overloads: `owner`, `x`, `y`, and `z`; add `uID` to the
  five-argument overload.
- `draw`: `render_area`, `x`, `y`, `player_color`, `facet`, `frame`,
  `draw_frame`, and `frame_color`.
- `alignment`: `col`, `row`, `world`, and `center_flag`.

This request changes declaration names only. It does not request a type,
layout, or interface change.

There are no resource lookups in this module. No resource-ID request is
needed.

## Validation

I ran evidence inspection and `git diff --check` only. I did not run a
compiler, build, matching, audit, or test. I did not run the game.
