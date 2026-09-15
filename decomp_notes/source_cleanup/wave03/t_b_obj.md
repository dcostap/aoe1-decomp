# Source cleanup report: `t_b_obj.cpp`

## Delivery

- Module: `src/t_b_obj.cpp`
- Base commit from `git rev-parse HEAD`: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source cleanup commits from `git rev-parse`: `23691bb50f331536eb6d0480d63fa4f2639e5448`, `ce54aeea79327942d6aa6005f0afa4e196f4f7b7`
- Final source commit from `git rev-parse HEAD`: `ce54aeea79327942d6aa6005f0afa4e196f4f7b7`
- Branch: `cleanup/staging-20260915-131`
- Changed files: `src/t_b_obj.cpp`; this report.
- The source commits contain only the assigned source module.
- The source keeps all 40 registered normal function bodies in PDB source order.
- The scalar deleting destructor at `004C8090` remains compiler-generated and has no source body.

No control flow, call target, expression, type, storage, layout, or data value changed.
The source only restores PDB names and applies 1TBS function-brace formatting.

## Evidence

The procedure-scoped PDB records were read from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The source registry was read from:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/t_b_obj.cpp.json`

The registry selects the original source path `C:\\msdev\\work\\age1_x1\\t_b_obj.cpp`.
The source packet asm and Ghidra excerpts were inspected for every assigned VA:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C7F50_TRIBE_Building_Object.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C8090_scalar_deleting_destructor.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C80B0_TRIBE_Building_Object.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C81D0_TRIBE_Building_Object.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C82A0_TRIBE_Building_Object.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C8370_recycle_out_of_game.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C83E0_setup.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C8490_setup.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C85D0_take_building_attribute_from_owner.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C8630_give_building_attribute_to_owner.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C8690_destroy_obj.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C86C0_heal.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C8740_set_object_state.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C8A60_rehook.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C8A80_update.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C8B80_explore_terrain.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C8BC0_save.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C8CB0_change_ownership.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C8E60_modify.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C8E90_transform.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C8ED0_check.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C90B0_connect.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9180_connect2.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9230_lay_down_impassable_terrain.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9360_lay_down_passable_terrain.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9480_cancel_object.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9490_cancel_build.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9560_build.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9620_work_status.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C96C0_get_construction_progress.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9710_copy_obj.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9760_rotate.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9770_damage.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9870_add_to_production_queue.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9B10_remove_from_production_queue.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9C80_advance_production_queue.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9D20_empty_production_queue.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9D90_enable_production_queue.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004C9DA0_update_production_queue.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CA030_production_queue_status.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CA0B0_stop.txt`

Every procedure-scoped PDB record has `this` in `ecx` with type
`TRIBE_Building_Object*`. The PDB records above were compared with the original
packet boundaries and call sites. The original executable remains the behavior
oracle.

The generated scalar destructor record at `004C8090` has parameter `__flags`
at stack offset `+0x4` and the same `this` register. It has no source body and
was not edited.

## Original-name recovery coverage

The table lists every registered source procedure. Names in the table are
recovered original PDB spellings. `none` means that the procedure has no PDB
stack symbol beyond its `this` register.

| VA | Function | PDB parameters and locals |
| --- | --- | --- |
| `004C7F50` | constructor | `tobj`, `obj_owner`, `x`, `y`, `z`, `uID`, `do_setup` |
| `004C80B0` | constructor | `tobj`, `obj_owner`, `x`, `y`, `z`, `do_setup` |
| `004C81D0` | constructor | `infile`, `gworld`, `do_setup` |
| `004C82A0` | destructor | none |
| `004C8370` | `recycle_out_of_game` | none |
| `004C83E0` | `setup` | `tobj`, `obj_owner`, `x`, `y`, `z` |
| `004C8490` | `setup` | `infile`, `gworld` |
| `004C85D0` | `take_building_attribute_from_owner` | none |
| `004C8630` | `give_building_attribute_to_owner` | none |
| `004C8690` | `destroy_obj` | none |
| `004C86C0` | `heal` | parameter `healing` |
| `004C8740` | `set_object_state` | parameter `new_object_state` |
| `004C8A60` | `rehook` | none |
| `004C8A80` | `update` | none |
| `004C8B80` | `explore_terrain` | `whos`, `explore_type`, `Override_LOS` |
| `004C8BC0` | `save` | parameter `outfile` |
| `004C8CB0` | `change_ownership` | parameter `new_owner` |
| `004C8E60` | `modify` | `amount`, `flag` |
| `004C8E90` | `transform` | parameter `obj` |
| `004C8ED0` | `check` | `checks`, `counter`, `x`, `h`, `w` |
| `004C90B0` | `connect` | local `checks[4]` |
| `004C9180` | `connect2` | local `checks[4]` |
| `004C9230` | `lay_down_impassable_terrain` | `map`, `tx2`, `tx1` |
| `004C9360` | `lay_down_passable_terrain` | `map`, `tx2`, `tx1` |
| `004C9480` | `cancel_object` | none |
| `004C9490` | `cancel_build` | local `percent` |
| `004C9560` | `build` | parameter `build_amount` |
| `004C9620` | `work_status` | `work_type`, `work_target`, `progress`, `name`, `name_size` |
| `004C96C0` | `get_construction_progress` | none |
| `004C9710` | `copy_obj` | parameter `source` |
| `004C9760` | `rotate` | parameter `amount` |
| `004C9770` | `damage` | `weapon_num`, `damage`, `attack_modifier`, `attacking_player`, `attacking_object`, local `temp_hp` |
| `004C9870` | `add_to_production_queue` | `master_id`, `unit_count`, local `queue_changed`, local `temp_attr` |
| `004C9B10` | `remove_from_production_queue` | `master_id`, `unit_count` |
| `004C9C80` | `advance_production_queue` | none |
| `004C9D20` | `empty_production_queue` | none |
| `004C9D90` | `enable_production_queue` | parameter `enabled` |
| `004C9DA0` | `update_production_queue` | locals `work_target`, `work_type`, `progress` |
| `004CA030` | `production_queue_status` | `master_id`, `progress` |
| `004CA0B0` | `stop` | none |

The exact source changes are:

- Constructors restore `master`/`player` to PDB `tobj`/`obj_owner`, and restore
  `unique_id` to `uID`.
- The load constructor restores `mode`/`world` to `infile`/`gworld`.
- Both `setup` overloads restore their PDB parameter names.
- `heal`, `set_object_state`, `explore_terrain`, `save`, `change_ownership`,
  `modify`, and `transform` restore their PDB names.
- `check` restores `checks`, `counter`, `w`, and `h`. Its existing `y` local
  has no PDB record and remains unchanged.
- The terrain methods restore `tx1` and `tx2`. Their `y1` and `y2` locals have
  no distinct PDB records and remain unchanged.
- `build`, `work_status`, `rotate`, and `production_queue_status` restore their
  PDB parameter names.
- `damage` restores all five parameter names and `temp_hp`.
- The production queue methods restore `unit_count`, `queue_changed`,
  `work_target`, `progress`, and the other recorded names.

The `004C9870` PDB records `temp_attr` at stack offset `+0x8`, the same home as
`unit_count`, and records `queue_changed` at `-0x1`. The source keeps two
separate `temp_attr` declarations. The inner declaration shadows the earlier
one after its last use. The source does not merge declarations or change
storage. The packet uses each value as the mutable cost-check result.

The `004C8ED0` PDB records `counter` at `-0x10`, `x` at `-0xc`, `w` at
`-0x8`, and `h` at `-0x4`. The packet uses these short and long homes for the
coordinate, map-bound, and result roles restored in the source. The world-y
local has no separate PDB record, so it remains `y`.

The `004C9230` and `004C9360` records name `map` at `-0x4`, `tx1` at `-0x8`,
and `tx2` at `-0xc`. Their optimized homes are reused by later terrain-bound
values. The source restores `tx1` and `tx2` only where the mapping is direct;
`y1` and `y2` remain descriptive names.

## Retained and unresolved names

The PDB has no reliable source mapping for many optimized locals. I did not
force names from decompiler temporaries or reused stack labels. Existing
cleanup names remain for these declarations:

- Static helper parameters and helper bodies at the top of the module.
- Constructor locals `master_object`, `row`, and `col`.
- Destructor and queue-counter locals `id`, `game`, `value`, `old`, and
  `result`.
- Setup and queue loop indices named `i`.
- State, update, transform, and status locals such as `dopple_removed`,
  `random_value`, `old_random`, `sound`, `max_value`, `master`, `result`,
  `combat_master`, and `action`.
- The `check` local `y`, plus its existing `map` local. `map` is also a direct
  PDB name in the terrain methods; the check packet has no ambiguity for the
  map pointer.
- Terrain loop locals `y`, `x`, and `tile`, plus `y1` and `y2`.
- Queue locals `queue_count`, `remove_count`, `index`, `copy_index`,
  `new_queue`, `i`, `attributes`, `action_state`, and the counter update
  aliases.

These are retained descriptive names, not recovered original names, unless
listed in the recovery table. No new descriptive name was invented in this
commit. No uncertain stack-slot mapping was used to merge declarations.

## Constants, resources, and comments

No numeric constant changed. No new enum, macro, or typed constant was added.
The existing state, terrain, notification, object, and sentinel values remain
numeric. Existing casts and literal widths remain unchanged.

This module has no resource lookup. It does not call `get_string`,
`get_string2`, or a string-table API. The numeric arguments to
`rge_base_game->notification` are notification codes, not proven resource IDs.
No DLL resource ID was investigated. Therefore no DLL hash, language payload,
resource lookup path, or `include/resource_ids.h` request applies.

No source comment was added. The existing source expresses the supported
behavior without a new explanatory comment.

## Code generation, type, layout, and symbol review

The changes rename identifiers and move function opening braces to 1TBS form.
They preserve types, declaration scopes, initialization points, storage,
expression order, control flow, calls, function boundaries, and ABI symbols.
The two `temp_attr` declarations remain separate. The unused `rotate` parameter
now has its PDB name `amount`; its type and empty body remain unchanged.

The source definitions use the same parameter types as
`include/t_b_obj.h`. No header was edited. No wrapper, helper, assembly, layout,
macro context, or shared declaration was added.

Brace changes and debug-name changes can affect debug line records. No
executable comparison was run.

## Header request

I read `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-131/include/t_b_obj.h` and did not edit it.
Owner 15 owns this matching header. Please consider adding the recovered
parameter names below without changing declarations, types, layout, or ABI:

```cpp
TRIBE_Building_Object(TRIBE_Master_Building_Object* tobj, RGE_Player* obj_owner,
                      float x, float y, float z, int uID, int do_setup);
TRIBE_Building_Object(TRIBE_Master_Building_Object* tobj, RGE_Player* obj_owner,
                      float x, float y, float z, int do_setup);
TRIBE_Building_Object(int infile, RGE_Game_World* gworld, int do_setup);
virtual uchar heal(float healing);
virtual void set_object_state(uchar new_object_state);
virtual int explore_terrain(RGE_Player* whos, uchar explore_type, int Override_LOS);
virtual void save(int outfile);
virtual void change_ownership(RGE_Player* new_owner);
virtual void modify(float amount, uchar flag);
void transform(TRIBE_Master_Building_Object* obj);
long check(TRIBE_Building_Object** checks);
virtual void damage(int weapon_num, RGE_Armor_Weapon_Info* damage,
                    float attack_modifier, RGE_Player* attacking_player,
                    RGE_Static_Object* attacking_object);
void add_to_production_queue(short master_id, short unit_count);
void remove_from_production_queue(short master_id, short unit_count);
void cancel_build();
int work_status(short& work_type, short& work_target, short& progress,
                char* name, short name_size);
void advance_production_queue();
void enable_production_queue(int enabled);
int production_queue_status(short& master_id, short& progress);
virtual void rotate(long amount);
unsigned char build(float build_amount);
virtual void copy_obj(RGE_Master_Static_Object* source);

protected:
virtual int setup(TRIBE_Master_Building_Object* tobj, RGE_Player* obj_owner,
                  float x, float y, float z);
virtual int setup(int infile, RGE_Game_World* gworld);
```

The `004C8ED0` packet supports `checks`, `counter`, `x`, `w`, and `h`.
The `004C9230` and `004C9360` packets support `map`, `tx1`, and `tx2`.
The `004C9870` packet supports `unit_count`, `queue_changed`, and `temp_attr`
at its reused parameter stack home. No root-owned header request or shared
resource declaration request exists.

## Validation limits

Compilation, matching, audits, and tests were not run.
No build, compiler check, game, runtime harness, or validation audit was run.
Only evidence inspection, source review, full Git diff review, and
`git diff --check` were run.
