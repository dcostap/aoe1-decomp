# `stat_obj.cpp` source cleanup

## Delivery

- Module: `src/stat_obj.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `5719dfd55ac6ebcc5ff87fc69e703e980220ffac`
- Changed files:
  - `src/stat_obj.cpp`
  - `decomp_notes/source_cleanup/wave03/stat_obj.md`

The final source commit contains only the source cleanup. The report is the second
assigned file and has no source ownership effect.

## Evidence

I reviewed all 115 configured source procedures for this module. I also reviewed
all 117 PDB procedures in `stat_obj.obj`. The two extra PDB records are the scalar
deleting destructor at `004C11C0` and `getSpeed` at `004C1CE0`.

Primary evidence:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `build/evidence/stat_obj_pdb_records.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/stat_obj.cpp.decomp`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/stat_obj.cpp.asm`
- `config/functions/src/stat_obj.cpp.json`

The PDB source path is `C:\msdev\work\age1_x1\stat_obj.cpp`.

## Recovered original names

I restored names from the procedure-scoped PDB records. The spellings below keep
PDB case and underscore style.

- Constructors and setup: `master` and `player` to `tobj` and `obj_owner`;
  loader constructor `id` and `world` to `infile` and `gworld`; loader setup
  `file` and `world` to `infile` and `gworld`.
- Rendering: draw-area parameters to `render_area`, color parameter to
  `draw_color`, and shadow parameters to `render_area`, `x`, `y`, and `flag`.
  The empty cube capture method now uses `render_area`, `x`, and `y`.
- Damage sprites: `current_damage_loc` to `curr_damage_loc`, and random point
  locals to `rand_x` and `rand_y`.
- Object lookup and save: `object_id` to `obj_id`, `index` to `sprite_id`,
  save parameter `file` to `outfile`, and save locals to `short_val`, `long_val`,
  and `tempInt`.
- Teleport: tile and offset locals to the PDB names `rz`, `tx`, `ty`, `rx`,
  `ry`, and `zd`.
- Sprite, ownership, and attribute methods: restored `nsprite`, `order`,
  `new_owner`, `amount`, `flag`, `hp_num`, `source`, `whos`, `explore_type`,
  `Override_LOS`, `weapon_num`, `damage`, `attack_modifier`,
  `attacking_player`, `attackingObject`, `attr_type`, `attr_amount`, `delta`,
  `check_max`, and `healing`.
- Relation, work, and range methods: restored `player_id`, `relation`, `work_obj`,
  `action_type`, `attack_flag`, `caller`, `obj`, `dX`, and `dY`.
- Hit and box tests: restored `draw_x`, `draw_y`, `mouse_x`, `mouse_y`,
  `check_radius`, `scr_x`, `scr_y`, `i`, `start_x`, `start_y`, `end_x`, and
  `end_y`.
- Drop and collision methods: restored `dropZone`, `temp`, `m_obj`, `obj`,
  `index`, `count`, `delta`, `check_list`, `rx`, `ry`, `rx2`, `ry2`,
  `smallestFacetDifference`, `anglePerFacet`, `obMapCode`, `yIndex`,
  `tempRX`, and `tempRY`.
- Zone and group methods: restored `p`, `zone`, `range`, `point`, `rVal`,
  `type1`, `type2`, `units`, `commander`, `unit`, `uID`, `unitObj`, and
  `flag_in`.
- State and map masks: restored `new_object_state`, `member`, and `ExploredVal`.

The loader kept the original declaration scopes. The old generated names now map
to the PDB names `temp_int`, `temp_dword`, and `tempInt` where the PDB records
support that mapping.

## New descriptive names

Some locals had no direct PDB name. I used concise names without claiming that
they are original names. These include `negative_rx1`, `negative_ry`,
`negative_rz2`, `negative_ry1`, `negative_ry2`, `game_mode`, `outline_type`,
`is_selected`, `damage_amount`, `max_hp`, `new_hp`, and `zone_map`.

I left other readable locals unchanged when the PDB did not establish a better
mapping. This includes locals such as `master`, `map`, `view`, `object`, and
`value`.

## Comments, constants, and resources

I added no constants, resource IDs, or source comments. I removed one duplicate
setup comment and one stale loader comment. No comment change adds behavior claims.

## Unresolved mappings

- The loader PDB record has reused stack homes for `tempInt`, `temp_int`,
  `temp_dword`, `i`, and `temp_float`. I kept the baseline declaration scopes
  and types where the source mapping was not direct.
- The PDB types `unsigned char byte_val` and `long long_val` do not match the
  baseline loader and save declarations. I kept the baseline types to avoid a
  type or code-generation change.
- Several procedures have no PDB local records. Their existing descriptive
  locals remain unchanged.
- The destructor and `getSpeed` records have no rename target in this source.

No shared-file request is open. I changed no header, registry, build recipe,
status file, inventory file, or global declaration.

## Code-generation and behavior review

The cleanup changes identifier names and removes stale comments only. It keeps
statement order, control flow, calls, casts, declaration scopes, storage
duration, types, literals, and public ABI symbols unchanged. No new constant or
resource lookup was added. The source diff received a full review, and
`git diff --check` passed.

Compilation, compiler checks, matching checks, audits, tests, and games were not
run, as required for this cleanup stage.
