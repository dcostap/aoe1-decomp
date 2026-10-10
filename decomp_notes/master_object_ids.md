# Master-object ID names

## Scope

The starting commit is `e5321ee98`.
This change adds `MASTER_OBJECT_*` macros to `include/m_s_obj.h` and uses them where source code compares,
switches on, or passes a master-object ID. A master-object ID is the index into `RGE_Player::master_objects`
and the value of `RGE_Master_Static_Object::id`.
No layouts, signatures, field types, parameters, locals, or registry entries changed.

## Name source

Each name is the internal name stored in the game data, not a cleanup guess.
The macro spelling uppercases the name and turns each run of other characters into `_`,
so `Town_Center1` becomes `MASTER_OBJECT_TOWN_CENTER1` and `Fish-tuna` becomes `MASTER_OBJECT_FISH_TUNA`.
The developers' spelling is kept, including `MISSLE` and `BALISTA`.

- File: `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/data2/empires.dat`,
  SHA256 `5ea86fadafc9f92dcc692d6210f377a1f6c0d82280b5b2a30a46b492b7c5253c`.
- The file is a raw deflate stream (`zlib` window bits `-15`) with the header `VER 3.7`.
- `build/cleanup-2026-10-10/dat_units.py` finds master-object records by the layout that
  `RGE_Master_Static_Object`'s file constructor reads in `src/m_s_obj.cpp`: the name length, ID, string IDs,
  and group come first, and the name follows the fixed fields, attribute bytes, and damage-sprite list.
  It writes `dat_units.json`.
- `build/cleanup-2026-10-10/dat_order_check.py` checks the scan. It finds 3,543 records in 17 runs.
  Each run has strictly ascending IDs: one list of 327 records and 16 lists of 201.
  These match one Gaia list and 16 civilization lists, so the scan found no stray records.
- 358 IDs have a record. Every ID has one name in every list, except 158, 159, and 163.
  The Gaia list calls those `Artifact_Ruins1_Gaia`, `Artifact1_Gaia`, and `Artifact_Ruins2_Gaia`.
  The other 16 lists drop the suffix, and the macros use that shorter name.
- IDs with no record have no macro. Examples in this range are 2, 3, 7, 8, 33, 42, 44, 57, 64, 67, 88, 91,
  92, 95 to 99, 107, 111, 128, 160, 196, 200 to 202, 220, 225, 232, 284 to 290, 325, 364, 371, and 396.

The header defines all 358 names so that later cleanup can use them without returning to the data.

## Cross-checks with the code

The code was not used to choose the names. These uses agree with them:

- `TribeBuildAIModule::insert` (`004D57A0`) maps each unit ID to the building that trains it.
  Archers go to `Range1`, catapults and `Soldier-Balista` to `Siege_Workshop`, `Man` to `Town_Center1`,
  `Priest` to `Temple1`, boats to `Dock_1`, and cavalry, chariots, elephants, and the scout to `Stable`.
  The buildings themselves map to -1.
- `TribeInformationAIModule::defendPriority` maps `Town_Center1`, `Dock_1`, `Artifact1`, and the two
  ruins to `SNTownDefendPriority`, `SNDockDefendPriority`, `SNArtifactDefendPriority`, and `SNRuinsDefendPriority`.
- `TRIBE_Player` places `Town_Center1` and `Man` objects when the game starts, and the build command plays
  the `Builder` sound.
- The tower checks in `t_c_obj.cpp`, `t_b_obj.cpp`, `tvw_main.cpp`, and `aiuaimod.cpp` name `Watch_Tower`,
  `Sentry_Tower`, `Guard_Tower`, `Guard_Tower2`, `Mirror_Tower`, and `Hero_Zenobia's_Tower`.
- `tmap.cpp` tests the range `Cliffs_1` to `Cliffs_10`.
- The repair code transforms a villager into `Repair_Man`. `RGE_Combat_Object::attack` transforms a civilian
  into `Man`.

## Substituted contexts

- comparisons with `master_obj->id`, `master->id`, `master_object->id`, and `object_master->id`,
  and the `switch` on `obj->master_obj->id` in `TribeInformationAIModule::checkDefend`;
- `ObjectMemory::type` comparisons through `importantObjectMemory[i].type`, `mem->type`, and `memory->type`,
  and `TacticalAIGroup::targetTypeValue`, which callers set from `mem->type`;
- the `typeID` argument of `MainDecisionAIModule::object(-1, typeID, ...)`;
- `master_objects[N]`, `make_new_object(N, ...)`, `find_obj(N, ...)`, `buildAI.insert(N, ...)`, and
  `checkForBuildInsertion(N, ...)`;
- comparisons with `obj_id`, `obj_cat`, `master_id`, and `buildingType`;
- the `objectType` argument of `UnitAIModule::closestObject`, which it compares with `master_obj->id`,
  and the matching `nEvent->p2` test in `taiuaimd.cpp`;
- the case labels of `defendPriority`'s first `switch`, `checkForBuildInsertion`, and
  `TribeBuildAIModule::insert`, and that function's `buildCategory` values.
  The PDB names this local `buildCategory`, but `insertItem` receives it as `buildFrom`.
- `oType` in `TRIBE_Combat_Object::keepGatheringWhenObjectIsOut`.

## Values left numeric

- `obj_id >= 0` bounds checks in `player.cpp` and `stat_obj.cpp`.
- `trail->master_obj->id > 30` in `move_obj.cpp`. It is a range test, and 30 is a terrain path piece.
- `master->id == 0x63` in `t_c_obj.cpp`. ID 99 has no record in the pinned data.
- Object-group values, such as `importantWhenDead`, the `oType` tests in `taiinfmd.cpp`, and the second
  `switch (group)` in `checkDefend`. These already use `OBJECT_GROUP_*` where a name exists.
- `BuildItem::typeID()` tests on research items (categories 1 and 4) in
  `TribeBuildAIModule`, because those values are technology IDs.
- `mostDamaged(3, ...)` and `mostDamaged(0x1b, ...)` pass object groups (building and wall), not IDs.
- `placementCode` return values stay numeric. They are placement codes, not IDs.

## Validation

Artifacts are under `build/cleanup-2026-10-10/master-objects`.

- A full audit compiled 224 of 225 groups. `rmm_tdbc` failed before it was reverted, because the macros were
  not declared there. The 224 groups passed all 5,005 of their exact claims, and their non-debug object
  payloads equal the `c41e6039a` baseline (`compare_objects.py`).
- `rmm_tdbc` (reverted) and `taiuaimd` (edited once more during the full audit) were audited again.
  Both compiled, all their exact claims passed (8 in `rmm_tdbc`), and both payloads equal the baseline
  (`master-objects-2`, `mo-rmm-reverted`). The total is 5,013 exact claims, the same as the baseline.
- clang-format 21.1.8 was applied to the edited source files.

No linked executable build, image audit, automated tests, or runtime suites ran.

## Follow-up (second pass)

The starting commit is `e8aeb1358`.

### `rmm_tdbc.cpp`

`add_object_module` (`00487FA0`) now uses `MASTER_OBJECT_MAN` and `MASTER_OBJECT_TOWN_CENTER1`, and the file
includes `m_s_obj.h` after `map.h`. Adding the include also changes `add_terrain_module` (`00487DD0`).
Neither function is an exact claim. The rebuilt function now multiplies by `[esi+18h]` before `[esi+14h]`.
The original executable at `00487DEC` uses that same order (`imul ecx,[esi+18h]`, then `imul ecx,[esi+14h]`).
The rebuilt function therefore moved closer to the original, from 380 to 378 differing bytes, and
`add_object_module` stays at 99. The disassembly of the object differs only in that pair of instructions and in
compiler label numbers. Its data sections are unchanged. The include placement was not further optimized.

### More contexts

`build/cleanup-2026-10-10/name_master_objects2.py` applies these:

- the case labels of `TribeInformationAIModule::placementCode`: towers, walls, `Granary`, `Storage_Pit1`,
  houses and other 6-code buildings, `Dock_1`, `Farm`, and `Town_Center1`;
- `storeLot(MASTER_OBJECT_WALL_SMALL, ...)`, which marks wall lots around gates;
- `BuildItem::typeID()` tests where the item is a building (category 0) or a unit (category 2), and the
  `typeID` argument of the `number*ItemsOfType(type, 0)` counters;
- `typeID()` tests on construction items in `taiconmd.cpp` and `TribeTacticalAIModule`;
- the second `nEvent->p2 == MASTER_OBJECT_FARM` test in the same notify handler in `taiuaimd.cpp`.

The two `item->typeID()` tests next to `storage_pit_count` and `granary_count` do not check the category.
The names follow the counters they belong to.

The literal-argument search covered `gameIDsOfObjectType`, `numberGameIDsOwnedBy`, the lot functions,
`higherPriorityObjectToDefend`, the defend and importance helpers, the train and cost functions,
`command_*` building functions, and `add_to_production_queue`. Only `storeLot` received a literal ID.
Their bodies have no other literal master-ID tests.

In the first loop of `TribeBuildAIModule`'s list scan (around `taibldmd.cpp:50`), the counter names do not
fit what they count. For example, `bronzeAgeIndex` counts houses and `fishingBoatCount` counts transports.
They were not renamed here.

### Second-pass validation

Artifacts are under `build/cleanup-2026-10-10/master-objects-3`.
The six affected groups compiled, and all 386 exact claims passed.
Five object payloads equal the baseline. `rmm_tdbc` differs only as described above.
