# Wave 02 cleanup report: `m_s_obj.cpp`

## Delivery

- Source: `src/m_s_obj.cpp`
- Header owner: owner 08 owns `include/m_s_obj.h`.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final cleanup commit: `09b834b0424fafd7c2ff0a9075379b8d1c205592`
- Formatting correction base: `23b2f3cfaed4f0ea61b204661d4ebb06c034a4ed`
- Formatting correction commit: `760be242b1eb808ee7b2f95f815d1b37540dbf24`
- Changed files:
  - `src/m_s_obj.cpp`
  - `workflow/decomp_notes/source_cleanup/wave02/m_s_obj.md`

The source cleanup changes names only. It does not change types, statements, literals,
call order, casts, scopes, layouts, or function symbols.

## Formatting correction

I reviewed every touched `setup`, `copy_obj`, `modify`, `modify_delta`, and
`modify_percent` definition. I placed each short signature on one line.
I removed unnecessary signature continuation lines. I changed no source tokens
outside formatting.

## Evidence

I read the procedure records in:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

I matched the records by VA and module path `.\\Release\\m_s_obj.obj`.
Every procedure record lists `this` in `ecx`. I also reviewed the function packet and
assembly evidence for `004524E0`, `00452B00`, and `00453C40`.

The pinned toolchain record is `config/toolchain.json`. It identifies VC5 host tools
11.00.7022 and LINK 5.00.7022. No compiler command ran.

## PDB coverage

I inspected parameters, locals, and registers for every source-owned procedure.
The scalar deleting destructor at `00452150` is compiler generated. It has no source
body in this module. I inspected its `__flags` parameter and `this@ecx` record.

| VA | Procedure | PDB parameters | PDB locals reviewed | Result |
| --- | --- | --- | --- | --- |
| `00452120` | copy constructor | `other_object`, `do_setup` | none | Recovered parameters. |
| `00452170` | integer constructor | `infile`, `sprites`, `sounds`, `do_setup` | none | Recovered parameters. |
| `004521A0` | file constructor | `infile`, `sprites`, `sounds`, `in_id`, `do_setup` | none | Recovered parameters. |
| `004521E0` | `setup` copy | `other_object` | none | Recovered parameter. |
| `004524E0` | `setup` integer file | `infile`, `sprites`, `sounds` | `sprite_num`, `undead_sprite_num`, `death_sprite_num`, `name_size`, `selected_sound_num`, `temp_damage_sprite`, `created_sound_num`, `death_sound_num` | Recovered all eight named short locals. Other pointer and loop locals had no scoped PDB names. |
| `00452B00` | `setup` text file | `infile`, `sprites`, `sounds`, `in_id` | All 35 named locals reviewed. | Recovered parameter names. Existing named locals match. The PDB `temp_damage_sprite_num` record does not map to the current `int attribute_count` type. It remains unchanged. |
| `00452FA0` | destructor | none | none | `this@ecx` reviewed. |
| `00452FE0` | `make_new_obj` | `owner`, `x`, `y`, `z` | none | Recovered parameter. |
| `004530B0` | `make_new_master` | none | none | `this@ecx` reviewed. |
| `00453120` | `copy_obj` | `source` | `copy_id2`, `available2`, `object_type2`, `hide_in_scenario_editor2` | Recovered parameter and four locals. `name_ptr` and loop indices had no scoped PDB names. |
| `004534A0` | `modify` | `amount`, `flag` | none | Recovered parameters. |
| `00453540` | `modify_delta` | `amount`, `flag` | none | Recovered parameters. |
| `004535F0` | `modify_percent` | `amount`, `flag` | none | Recovered parameters. |
| `004536D0` | `save` | `outfile` | `temp_death_sprite`, `temp_sprite`, `name_size`, `temp_undead_sprite`, `selected_sound_num`, `created_sound_num`, `death_sound_num` | Recovered parameter and all seven named locals. Other helper pointers had no scoped PDB names. |
| `00453C40` | `check_placement` | `player`, `col`, `row`, `obstructionObject`, `check_vis`, `check_flat`, `check_overlay`, `construction_radius_flag`, `can_be_built_on_flag`, `check_objects` | All 25 named locals reviewed. | Recovered all parameters. Recovered the clear index, edge, terrain-request, and visibility names listed below. Reused-stack mappings remain unresolved. |
| `004543C0` | `make_available` | `on_off_flag` | none | Recovered parameter. |
| `004543D0` | `alignment` | `col`, `row`, `world`, `center_flag` | `dx1`, `dy1`, `dx2`, `dy2`, `map_w`, `map_h` | Recovered all named locals and parameters. |
| `00454690` | `alignment_box` | `world`, `col`, `row`, `x1`, `y1`, `x2`, `y2`, `x3`, `y3`, `x4`, `y4` | `tx`, `ty` | Recovered all named parameters and locals. |
| `004547F0` | `draw` | `render_area`, `x`, `y`, `player_color`, `facet`, `frame`, `draw_frame`, `frame_color` | `y4`, `y3`, `y2`, `y1`, `x4`, `x3`, `x2`, `x1`, `ry1`, `rx1` | Recovered all named parameters and locals. |
| `00454950` | `get_help_message` | none | none | `this@ecx` reviewed. |
| `00454960` | `get_help_page` | none | none | `this@ecx` reviewed. |
| `00454970` | `get_hotkey` | none | none | `this@ecx` reviewed. |
| `00454980` | `calc_base_damage_ability` | `attacker` | none | Recovered parameter. |

For `00453C40`, the recovered local names are `x1`, `x2`, `y1`, `y2`,
`edge_x1`, `edge_x2`, `edge_y1`, `edge_y2`, `x_index`, `y_index`, `req_terr1`,
`req_terr2`, `part_vis`, `map`, and `terrain_table`. The PDB also lists
`rz2`, `ry2`, `rx2`, `tx1`, `tx2`, `ty1`, `ty2`, `rx`, `ry`, and `req_x1`.
Their stack offsets overlap active parameters and other locals. I left the current
storage mappings unchanged.

## Name mapping

All changed names come from the PDB. They are not new inferred names.

- Constructors: `object` to `other_object`; `value` to `infile`; `file` to `infile`;
  `value` to `in_id`; `doSetup` to `do_setup`.
- Copy setup: `src` to `other_object`.
- Integer setup: `handle` to `infile`; the eight short locals now use the PDB names.
- Text setup: `file` to `infile`; `value` to `in_id`.
- Object creation: `player` to `owner`.
- Object copy: `src` to `source`; saved values now use `copy_id2`, `available2`,
  `object_type2`, and `hide_in_scenario_editor2`.
- Modifiers: `value` to `amount`; `op` to `flag`.
- Save: `fd` to `outfile`.
- Placement: the full PDB parameter list is restored, including unused
  `check_overlay` and mixed-case `obstructionObject`.
- Alignment: `x`, `y`, and `align` to `col`, `row`, and `center_flag`; local names
  now use `dx1`, `dy1`, `dx2`, `dy2`, `map_w`, and `map_h`.
- Alignment box: `x`, `y`, `x_offset`, and `y_offset` to `col`, `row`, `tx`, and `ty`.
- Draw: the PDB names replace the six placeholder parameters.
- Damage calculation: `param` to `attacker`.

I did not rename a local when its PDB stack record had a conflicting type or a reused
slot. This includes `00452B00` `temp_damage_sprite_num` and the unresolved placement
locals above. Existing inferred names remain in those cases.

## Constants, comments, and resources

No constant changed. No constant was added. No resource ID is used in this source.
No resource request is needed. No source comment was added or removed. Existing
comments about the beta save stream and outline draw order remain unchanged.

## Risks and requests

The edits change identifiers only. They should not change ABI, layout, call targets,
constant values, or storage. A build is still required to prove generated code.
The source definition now uses recovered parameter names. The header keeps unnamed
parameters because owner 08 owns `include/m_s_obj.h`.

Header request to owner 08:

- Consider adding the recovered parameter names to `include/m_s_obj.h`.
- Keep every existing type, order, calling convention, and unnamed ABI unchanged.
- Use the PDB spellings from this report for constructors, `setup`, `copy_obj`,
  modifiers, `save`, `check_placement`, `make_available`, `alignment`,
  `alignment_box`, `draw`, and `calc_base_damage_ability`.
- This request is for declaration readability only. It does not block this source.

No resource-ID or shared declaration request is pending.

## Validation

I reviewed the complete base-to-head diff. I ran `git diff --check`.
Compilation, matching, audits, and tests were not run, as required for this wave.
The cleanup and correction hashes above were copied from Git after each commit.
