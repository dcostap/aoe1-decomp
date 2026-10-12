# `src/obj_list.cpp` cleanup report

## Delivery

- Module: `src/obj_list.cpp`
- Slot and branch: 78, `cleanup/staging-20260915-78`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `5a7fdc9ed62feccf56e1b80dcc1b1aab8dcd87da`
- Changed files in the source commit: `src/obj_list.cpp`
- This report is committed separately.
- Header owner: owner 09 owns `include/obj_list.h`; this worker did not edit it.

The source registry packet is `config/functions/src/obj_list.cpp.json`. It selects
21 matching procedures in original source order. The cleanup changes identifiers
only. It preserves types, scopes, calls, casts, literals, evaluation order, and
layouts.

## PDB coverage and name recovery

The scoped PDB evidence is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Every assigned procedure has a scoped PDB record: 21 of 21. Every record has
`this` in `ecx`. The PDB source path is
`C:\msdev\work\age1_x1\obj_list.cpp`.

The selected function packets are under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0046/`. Their source
spans and scoped names are:

| VA | Function | PDB source span | PDB parameters | PDB locals |
| --- | --- | --- | --- | --- |
| `00462E80` | `RGE_Object_List::RGE_Object_List` | `42-45` | none besides `this` | none |
| `00462EA0` | `RGE_Object_List::~RGE_Object_List` | `50-70` | none besides `this` | none |
| `00462EF0` | `removeAllObjects` | `74-86` | none besides `this` | none |
| `00462F30` | `add_node` | `91-113` | `obj` | none |
| `00462F70` | `remove_node` | `119-176` | `obj`, `node` | none |
| `00462FD0` | `invert` | `181-199` | none besides `this` | none |
| `00463000` | `draw` | `205-314` | `render_area`, `x`, `y`, `fogged_tile` | none |
| `00463100` | `shadow_draw` | `320-335` | `render_area`, `x`, `y`, `flag`, `fog_flag` | none |
| `00463180` | `normal_draw` | `342-368` | `render_area`, `x`, `y`, `fog_flag` | none |
| `00463210` | `update` | `374-402` | none besides `this` | none |
| `00463260` | `sort` | `407-457` | none besides `this` | `sorted` |
| `004632E0` | `find_by_group(long)` | `462-469` | `id` | none |
| `00463310` | `find_by_group(long, ...)` | `474-512` | `id`, `x`, `y`, `certain_state`, `object_state`, `zone_obj` | `found_obj`, `diff_x`, `dist` |
| `00463490` | `find_by_id` | `517-524` | `id` | none |
| `004634C0` | `find_by_master_id` | `531-569` | `id`, `x`, `y`, `certain_state`, `object_state`, `zone_obj` | `found_obj`, `diff_x`, `dist` |
| `00463640` | `find_by_master_ids` | `575-615` | `id1`, `id2`, `x`, `y`, `certain_state`, `object_state`, `zone_obj` | `found_obj`, `diff_x`, `dist` |
| `004637C0` | `find_by_type` | `621-649` | `type`, `x`, `y`, `certain_state`, `object_state` | `diff_x`, `dist` |
| `00463890` | `save` | `655-663` | `outfile` | `finished` |
| `004638D0` | `load_list` | `668-683` | `infile`, `world` | `object_type` |
| `00463910` | `rehook_list` | `688-693` | none besides `this` | none |
| `00463930` | `load` | `700-729` | `object_type`, `infile`, `world` | none |

The table names are recovered PDB names. The source previously used these
substitutes in the affected declarations:

- `object` became `obj` in `add_node` and `remove_node`.
- `draw_area` and `fog` became `render_area` and `fogged_tile` in `draw`.
- `draw_area`, `parameter`, and `fog` became `render_area`, `flag`, and
  `fog_flag` in `shadow_draw`.
- `draw_area` and `fog` became `render_area` and `fog_flag` in `normal_draw`.
- `group` became `id` in both `find_by_group` procedures.
- `check_player`, `player_id`, and `zone_object` became `certain_state`,
  `object_state`, and `zone_obj` in the long `find_by_group` procedure.
- `target_id` became `id` in `find_by_id`.
- `master_id`, `use_state`, `state`, and `zone_object` became `id`,
  `certain_state`, `object_state`, and `zone_obj` in `find_by_master_id`.
- `first_id`, `second_id`, `check_player`, `player_id`, and `zone_object`
  became `id1`, `id2`, `certain_state`, `object_state`, and `zone_obj` in
  `find_by_master_ids`.
- `check_state` and `state` became `certain_state` and `object_state` in
  `find_by_type`.
- `file` became `outfile` in `save`.
- `file` and `type` became `infile` and `object_type` in `load_list`.
- `type` and `mode` became `object_type` and `infile` in `load`.

The PDB local names `found_obj`, `diff_x`, and `dist` were also restored in
all three distance-search procedures. `sorted` and `finished` already matched
the PDB and remain unchanged. The PDB records place `dist` in a reused input
slot for the distance searches. Its sentinel initialization, comparison, and
update use prove that it is the distance accumulator. No uncertain slot mapping
was forced.

Other locals have no scoped PDB name. They remain descriptive and are not
claimed as recovered originals. These include list traversal names such as
`node`, `next`, `object`, `current`, `zone`, `dy`, and `distance`; draw names
such as `owner`, `should_draw`, and `color_table`; sorting names such as
`insertion`, `scan`, `current_object`, `current_y`, `current_sort`,
`scanned_object`, and `scanned_sort`; update names such as `count` and
`update_result`; and `best_object` in `find_by_type`. No new local name was
invented.

## Constants, resources, and comments

No constants changed. Existing object-type values `10`, `20`, `25`, `30`, `40`,
`50`, `60`, and the `0x19` object-type check remain unchanged. No existing
symbol was replaced without role and value evidence.

No resource lookup occurs in this module. No resource ID request is needed.
No comments were added. The source has no comment that needs correction.

No shared declaration request was sent. Parameter names in the definitions do
not change the declarations or ABI in `include/obj_list.h`.

## Code-generation and unresolved items

The source commit changes parameter and local identifiers only. It makes no
ABI, type, layout, call-target, cast, literal, control-flow, or storage change.
It does not move braces or statements. Optimized machine code should remain
unchanged, but this wave did not compile or match the source.

The PDB does not name many compiler locals. The report lists those names as
unrecovered. Their current descriptive names remain because this task does not
support a stronger mapping. The destructor's unusual node-free sequence also
remains unchanged.

Evidence hashes:

- Baseline object: `f0ea8fd4c547ffc71bad96c6d4ff1656d09139a56d49218f7d91a221b30215e1`
  (`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/obj_list.obj`)
- Preserved baseline executable: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`
  (`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`)
- Original executable: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
  (`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`)

## Validation status

Evidence extraction, hash checks, and Git diff review ran. Compilation,
builds, matching, audits, tests, and game commands were not run. No compiler,
build, matching, audit, test, or game command was run for this assignment.
