# `src/victory.cpp` source cleanup

## Delivery

- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit: `8bd1e5ae824fd6bf3e888ad6952fa659930c02a5`
- Changed files: `src/victory.cpp`, `decomp_notes/source_cleanup/wave04/victory.md`
- `include/victory.h` was not changed.
- This report covers all 58 procedures in the Victory PDB scope.

## Evidence

I used these local references:

- PDB scope: `build/victory-pdb-scope.json`
- Scoped-symbol tool: `tools/pdb_scoped_symbols.py`
- Original decompilation: `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/victory.cpp.decomp`
- Original assembly: `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/victory.cpp.asm`
- Declarations: `include/victory.h`
- Function registry: `config/functions/src/victory.cpp.json`

The PDB records `this` in `ecx` for every procedure. The table lists each procedure's PDB stack symbols. A dash means that the PDB has no stack symbol for that procedure. The PDB has no function-static symbols in this scope.

| VA | Procedure | PDB stack symbols: name, type, frame offset |
| --- | --- | --- |
| `00531750` | `RGE_Victory_Conditions::RGE_Victory_Conditions` | `in_player` RGE_Player* +0x4; `infile` int +0x8; `player_id_hash` long* +0xc; `version_control` unsigned char +0x10; `target_obj` long -0x18; `target_player` long -0x10; `index` long +0x14; `version` float -0xc; `this_obj` long +0xc; `temp2` RGE_Victory_Entry** -0x14; `temp_num` long -0x8 |
| `00531AF0` | `RGE_Victory_Conditions::RGE_Victory_Conditions` | `in_Player` RGE_Player* +0x4 |
| `00531B20` | `RGE_Victory_Conditions::~RGE_Victory_Conditions` | — |
| `00531B70` | `RGE_Victory_Conditions::save` | `outfile` int +0x4; `target_obj` long -0x8; `target_player` long +0x8; `version` float -0x4; `this_obj` long -0xc |
| `00531DB0` | `RGE_Victory_Conditions::check_for_victory` | `group_num` long -0x8; `curr_victory_group` long -0x4; `victory_void_num` long -0x10; `failed_group_num` long -0xc |
| `00531E90` | `RGE_Victory_Conditions::update` | — |
| `00531EF0` | `RGE_Victory_Conditions::update_for_object` | `obj` RGE_Static_Object* +0x4 |
| `00531F30` | `RGE_Victory_Conditions::handle_point_condition` | `node` RGE_Victory_Point_Entry* +0x4 |
| `00531F90` | `RGE_Victory_Conditions::handle_condition` | `node` RGE_Victory_Entry* +0x4 |
| `00532050` | `RGE_Victory_Conditions::handle_capture` | `node` RGE_Victory_Entry* +0x4 |
| `00532110` | `RGE_Victory_Conditions::handle_create` | `node` RGE_Victory_Entry* +0x4; `num` long -0x8 |
| `00532220` | `RGE_Victory_Conditions::handle_create_in_area` | `node` RGE_Victory_Entry* +0x4; `num` long -0xc |
| `005323B0` | `RGE_Victory_Conditions::handle_destroy` | `node` RGE_Victory_Entry* +0x4 |
| `005323D0` | `RGE_Victory_Conditions::handle_destroy_multiple` | `node` RGE_Victory_Entry* +0x4 |
| `005324A0` | `RGE_Victory_Conditions::handle_destroy_all` | `node` RGE_Victory_Entry* +0x4 |
| `00532570` | `RGE_Victory_Conditions::handle_destroy_player` | `node` RGE_Victory_Entry* +0x4 |
| `005325A0` | `RGE_Victory_Conditions::handle_bring_area` | `node` RGE_Victory_Entry* +0x4 |
| `00532610` | `RGE_Victory_Conditions::handle_bring_object` | `node` RGE_Victory_Entry* +0x4; `dx` float +0x8 |
| `005326F0` | `RGE_Victory_Conditions::handle_attribute` | `node` RGE_Victory_Entry* +0x4 |
| `005327A0` | `RGE_Victory_Conditions::handle_explore` | `node` RGE_Victory_Entry* +0x4 |
| `00532880` | `RGE_Victory_Conditions::handle_victory_points` | `node` RGE_Victory_Entry* +0x4; `player_count` long -0x4 |
| `00532930` | `RGE_Victory_Conditions::add` | `v_group` unsigned char +0x4; `alliance` unsigned char +0x8 |
| `00532970` | `RGE_Victory_Conditions::add_capture` | `v_group` unsigned char +0x4; `obj` RGE_Static_Object* +0x8; `alliance` unsigned char +0xc |
| `005329A0` | `RGE_Victory_Conditions::add_create` | `v_group` unsigned char +0x4; `obj_type` long +0x8; `number` long +0xc; `alliance` unsigned char +0x10 |
| `005329D0` | `RGE_Victory_Conditions::add_create` | `v_group` unsigned char +0x4; `obj_type` long +0x8; `number` long +0xc; `x0` float +0x10; `y0` float +0x14; `x1` float +0x18; `y1` float +0x1c; `alliance` unsigned char +0x20 |
| `00532A20` | `RGE_Victory_Conditions::add_destroy` | `v_group` unsigned char +0x4; `obj` RGE_Static_Object* +0x8 |
| `00532A50` | `RGE_Victory_Conditions::add_destroy` | `v_group` unsigned char +0x4; `obj_type` long +0x8; `num` long +0xc; `player` RGE_Player* +0x10 |
| `00532A90` | `RGE_Victory_Conditions::add_destroy` | `v_group` unsigned char +0x4; `obj_type` long +0x8; `player` RGE_Player* +0xc |
| `00532AC0` | `RGE_Victory_Conditions::add_destroy` | `v_group` unsigned char +0x4; `player` RGE_Player* +0x8 |
| `00532AF0` | `RGE_Victory_Conditions::add_bring` | `v_group` unsigned char +0x4; `obj` RGE_Static_Object* +0x8; `target` RGE_Static_Object* +0xc |
| `00532B30` | `RGE_Victory_Conditions::add_bring` | `v_group` unsigned char +0x4; `obj` RGE_Static_Object* +0x8; `x0` float +0xc; `y0` float +0x10; `x1` float +0x14; `y1` float +0x18 |
| `00532B70` | `RGE_Victory_Conditions::add_attributes` | `v_group` unsigned char +0x4; `attribute` long +0x8; `count` long +0xc; `alliance` unsigned char +0x10 |
| `00532BA0` | `RGE_Victory_Conditions::add_explore` | `v_group` unsigned char +0x4; `count` long +0x8; `alliance` unsigned char +0xc |
| `00532BE0` | `RGE_Victory_Conditions::add_victory_points` | `v_group` unsigned char +0x4; `count` long +0x8; `alliance` unsigned char +0xc |
| `00532C10` | `RGE_Victory_Conditions::sub` | `entry` RGE_Victory_Entry* +0x4 |
| `00532C50` | `RGE_Victory_Conditions::destroy_all` | — |
| `00532C70` | `RGE_Victory_Conditions::condition_info` | `condition` long +0x4; `description` char** +0x8; `type` unsigned char& +0xc |
| `00532CC0` | `RGE_Victory_Conditions::condition_description` | `node` RGE_Victory_Entry* +0x4; `temp` char[200] -0xc8; `description` char* -0xcc |
| `00532ED0` | `RGE_Victory_Conditions::condition_raw_info` | `condition` long +0x4 |
| `00532EF0` | `RGE_Victory_Conditions::condition_number` | `condition` long +0x4 |
| `00532F00` | `RGE_Victory_Conditions::victory_achieved` | — |
| `00532F10` | `RGE_Victory_Conditions::remove_condition` | `condition` long +0x4 |
| `00532F50` | `RGE_Victory_Conditions::add_point` | `id` unsigned char +0x4; `group` unsigned char +0x8 |
| `00532FA0` | `RGE_Victory_Conditions::sub_point` | `entry` RGE_Victory_Point_Entry* +0x4 |
| `00532FE0` | `RGE_Victory_Conditions::add_points_attribute_amount` | `group` unsigned char +0x4; `id` unsigned char +0x8; `attribute` long +0xc; `count` long +0x10; `points` long +0x14 |
| `00533020` | `RGE_Victory_Conditions::add_points_attribute_first` | `group` unsigned char +0x4; `id` unsigned char +0x8; `attribute` long +0xc; `count` long +0x10; `points` long +0x14 |
| `00533060` | `RGE_Victory_Conditions::add_points_highest_attribute` | `group` unsigned char +0x4; `id` unsigned char +0x8; `attribute` long +0xc; `count` long +0x10; `points` long +0x14 |
| `005330A0` | `RGE_Victory_Conditions::add_points_high_attribute_once` | `group` unsigned char +0x4; `id` unsigned char +0x8; `attribute` long +0xc; `count` long +0x10; `points` long +0x14 |
| `005330E0` | `RGE_Victory_Conditions::add_points_high_attribute_amount` | `group` unsigned char +0x4; `id` unsigned char +0x8; `attribute` long +0xc; `count` long +0x10; `points` long +0x14 |
| `00533120` | `RGE_Victory_Conditions::handle_points_attribute_amount` | `node` RGE_Victory_Point_Entry* +0x4; `amount` long +0x8 |
| `00533180` | `RGE_Victory_Conditions::handle_points_attribute_first` | `node` RGE_Victory_Point_Entry* +0x4; `points` long -0x4; `amount` long +0x8 |
| `00533240` | `RGE_Victory_Conditions::handle_points_highest_attribute` | `node` RGE_Victory_Point_Entry* +0x4; `points` long +0x8; `amount` long +0x8 |
| `00533330` | `RGE_Victory_Conditions::handle_points_high_attribute_once` | `node` RGE_Victory_Point_Entry* +0x4; `amount` long +0x8 |
| `00533410` | `RGE_Victory_Conditions::handle_points_high_attribute_amount` | `node` RGE_Victory_Point_Entry* +0x4; `amount` long +0x8 |
| `00533480` | `RGE_Victory_Conditions::get_victory_points` | — |
| `00533490` | `RGE_Victory_Conditions::get_victory_points_group` | `group` unsigned char +0x4 |
| `005334C0` | `RGE_Victory_Conditions::get_victory_points_id` | `id` unsigned char +0x4 |
| `005334E0` | `RGE_Victory_Conditions::get_attribute_id` | `id` unsigned char +0x4 |

## Name recovery and cleanup

### Recovered PDB names

The source now uses the PDB names for the mapped parameters and locals. This includes `in_player`, `infile`, `player_id_hash`, `version_control`, `in_Player`, `obj`, `node`, `v_group`, `alliance`, `obj_type`, `number`, `num`, `player`, `target`, `attribute`, `count`, `condition`, `description`, `type`, `id`, `group`, `points`, and `amount`.

The constructor also uses the PDB names `target_obj`, `target_player`, `version`, `temp2`, and `temp_num`. The existing `index` name already matched the PDB. The save locals `target_obj`, `version`, and `this_obj` already matched the PDB.

### New descriptive names

- `object_node` separates the object-list iterator from the PDB-backed `node` parameter.
- `calculated_points` replaces the generated `iVar2` temporary. It names the value before and after the points multiplication.

These names are cleanup names. They are not claims about original source spelling.

### Important mappings and limits

- `handle_create` and `handle_create_in_area` keep their outer `count` locals. The PDB `num` symbol maps to the nested world player-count local, which already used `num`.
- `check_for_victory` keeps `has_success`. Ghidra marks `victory_void_num` as an unmapped variable. The PDB name does not prove a source declaration for `has_success`.
- `handle_points_highest_attribute` keeps separate `points` and `amount` declarations. The PDB records both names at the same stack home. This is reused storage evidence, not proof that the declarations can combine.
- Several PDB symbols share homes with other values. The source keeps its declaration scopes, types, and storage arrangement. It does not add declarations to force a PDB name.
- The source keeps the existing `int` declarations for the point-handler `amount` and `player_count` locals. The PDB displays these symbols as `long`. This cleanup changes names only.
- The constructor reads the object ID into the existing `infile` parameter. The PDB also reports a `this_obj` local at an overlapping home. This source mapping remains unresolved because the PDB home is reused.
- The save procedure reports a `target_player` local, but the existing source reuses the `outfile` parameter for that serialized ID. The source does not add a second declaration.

No constants, resource IDs, comments, public symbols, layouts, casts, calls, control flow, or declarations in `include/victory.h` changed.

Compilation, matching, audits, and tests were not run, as required.
