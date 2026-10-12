# `src/zone_map.cpp` cleanup report

## Scope and commits

- Module: `src/zone_map.cpp`
- Header owner: owner 16 owns `include/zone_map.h`; this worker did not edit it.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source commit: `1f420783ede0356da604142e88434c825340f838`
- Final report commit: see the full Git hash in the delivery record.
- Changed files:
  - `src/zone_map.cpp`
  - `workflow/decomp_notes/source_cleanup/wave03/zone_map.md`

The source keeps all 22 handwritten owners in PDB source order. This cleanup
recovers procedure-scoped PDB names and applies 1TBS throughout the module. It
does not change types, calls, literals, declaration scopes, evaluation order,
storage, or layouts.

Evidence identity used during review:

- Original executable:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`, SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Preserved baseline report:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`.
  Its baseline `src/zone_map.cpp` SHA256 is
  `752ad126e664b6b023a54e9fa8ee905b1d4cf0b0a7ea38c683c715febf379604`.
- No resource lookup occurs in this module. Therefore, no runtime DLL was
  queried for an ID and no resource hash is part of this module's evidence.

## Original-name inspection coverage

The registry packet is `config/functions/src/zone_map.cpp.json`. It selects 22
normal functions from `00546720` through `005474D0`. I inspected every selected
original packet under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0054/` and every
matching procedure record in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The records identify `.\\Release\\zone_map.obj` and the `this` register as
`ecx` for every member function. The extracted review copy is the ignored file
`build/zone_map_cleanup/scoped_symbols_zone_map.json`.

| VA | Function | Recovered original names | PDB evidence |
| --- | --- | --- | --- |
| `00546720` | `zone_pop` | `zone_queue`, `zone_end`, `x`, `y` | stack records at `+0x4`, `+0x8`, `+0xc`, `+0x10` |
| `00546770` | `zone_push` | `zone_queue`, `zone_end`, `x`, `y` | stack records at `+0x4`, `+0x8`, `+0xc`, `+0x10` |
| `005467B0` | `RGE_Zone_Map::RGE_Zone_Map` | `infile`, `new_map` | stack records at `+0x4`, `+0x8` |
| `005468C0` | `RGE_Zone_Map::RGE_Zone_Map` | `new_map`, `new_terrain_rules`, `new_terrain_rules_num` | stack records at `+0x4`, `+0x8`, `+0xc` |
| `005469C0` | `RGE_Zone_Map::~RGE_Zone_Map` | none | `this` in `ecx`; no stack names |
| `00546A00` | `RGE_Zone_Map::save` | `outfile` | stack record at `+0x4` |
| `00546A90` | `RGE_Zone_Map::do_zone_map` | existing `map_width`, `map_height`, `y`, `group` retained | locals at `-0x8`, `-0x4`, `-0x10`, `-0xc` |
| `00546BB0` | `RGE_Zone_Map::do_zone_map_area` | `x`, `y`, `group`, `zone`; `zone_end`, `zone_queue` retained | parameters at `+0x4` to `+0x10`; locals at `-0x10`, `-0xc` |
| `00546E50` | `RGE_Zone_Map::check_info` | `new_terrain_rules`, `new_terrain_rules_num` | stack records at `+0x4`, `+0x8` |
| `00546EB0` | `RGE_Zone_Map::get_zone_info` | existing `x`, `y` retained | stack records at `+0x4`, `+0x8` |
| `00546ED0` | first `withinRange` overload | `start`, `goal`, `range` | stack records at `+0x4`, `+0xc`, `+0x14` |
| `00546F00` | second `withinRange` overload | `startZone`, `goal`, `range`; `max` retained | parameters at `+0x4`, `+0x8`, `+0x10`; local at `-0x8` |
| `00547000` | `RGE_Zone_Map::numberTilesInZone` | `zone`, `mapWidth` (from `width`), `count` retained | stack records for `zone`, `count`; local record for `mapWidth` |
| `00547080` | `findClosestPointInTerrainType` | `p`, `rVal`, `type1`, `type2`, `range`; `min`, `max` retained | parameters at `+0x4` to `+0x18`; locals at `-0x8`, `-0x10` |
| `00547180` | `RGE_Zone_Map_List::RGE_Zone_Map_List` | `infile`, `in_map` | stack records at `+0x4`, `+0x8` |
| `00547240` | `RGE_Zone_Map_List::RGE_Zone_Map_List` | `in_map` | stack record at `+0x4` |
| `00547260` | `RGE_Zone_Map_List::~RGE_Zone_Map_List` | none | `this` in `ecx`; no stack names |
| `00547270` | `RGE_Zone_Map_List::save` | `outfile` | stack record at `+0x4` |
| `005472B0` | `create_zone_map` | `new_terrain_rules`, `new_terrain_rules_num`; `new_zone_maps` retained | stack records at `+0x4`, `+0x8`, `+0xc` |
| `005473B0` | terrain-rule `get_zone_map` overload | `new_terrain_rules`, `new_terrain_rules_num`, `zoneMapIndex` | stack records at `+0x4`, `+0x8`, `+0xc` |
| `005474B0` | indexed `get_zone_map` overload | `id` | stack record at `+0x4` |
| `005474D0` | `delete_zone_maps` | none | `this` in `ecx`; no stack names |

The changed names are recovered originals. They are not new descriptive names.
The source retained existing descriptive names when the scoped PDB did not prove
a mapping.

`do_zone_map` has only four scoped local records. Its current `visible`,
`group_counter`, `row`, `col`, `x`, `terrainByte`, and `passability` declarations
have no direct PDB name record. I did not force a reused register or stack-slot
mapping. The PDB `group` record is `unsigned char`, while the current declaration
is `int`; the source keeps the current type and reports that type mapping as
unresolved. The source also retains current locals in `numberTilesInZone` and
`findClosestPointInTerrainType` where no separate PDB record proves a rename.

## Constants, resources, and comments

No resource lookup occurs in this module. No resource ID mapping or request is
needed. No new constant was added. The original packets support the retained
numeric values, including the queue allocation size `0xC`, byte sentinel `0xFF`,
row stride `0x18`, terrain mask `0x1F`, serialized block size `0x3FC`, and the
passability threshold at `DAT_00577a20`. No value was replaced by an unproved
symbol.

I read the pinned VC5 `FCNTL.H` and `WINUSER.H` files. This source does not use
an SDK or CRT constant that needs replacement.

No comment was added or removed. The existing load-constructor note remains
unchanged. It records the observed serialized read order and pointer lifetime.

## Presentation correction

The correction round places every function and control-statement opening brace
on its statement line. It joins readable signatures and calls, including the
three-parameter constructor, `check_info`, `create_zone_map`, and the
three-parameter terrain-rule `get_zone_map`. It does not add or remove braces,
change scopes, or reorder statements.

## Header requests

The owner of `include/zone_map.h` should align declaration parameter names with
the recovered definitions. This is a declaration-only request. It does not
change an ABI symbol, type, layout, or calling convention.

- `RGE_Zone_Map(int infile, RGE_Map* new_map)`
- `RGE_Zone_Map(RGE_Map* new_map, float* new_terrain_rules, long new_terrain_rules_num)`
- `save(int outfile)`
- private `do_zone_map_area(long x, long y, uchar group, uchar zone)`
- `check_info(float* new_terrain_rules, long new_terrain_rules_num)`
- `withinRange(XYPoint start, XYPoint goal, float range)`
- `withinRange(uchar startZone, XYPoint goal, float range)`
- `findClosestPointInTerrainType(XYPoint p, XYPoint& rVal, int type1, int type2, int range)`
- `RGE_Zone_Map_List(int infile, RGE_Map* in_map)`
- `RGE_Zone_Map_List(RGE_Map* in_map)`
- `RGE_Zone_Map_List::save(int outfile)`
- `create_zone_map(float* new_terrain_rules, long new_terrain_rules_num)`
- `get_zone_map(float* new_terrain_rules, long new_terrain_rules_num, int& zoneMapIndex)`
- indexed `get_zone_map(long id)`

No shared resource declaration request is pending.

## Code-generation and unresolved items

Source edits rename existing declarations and uses, and change whitespace only
for the presentation correction. They do not change a public function name, ABI
symbol, type, cast, literal, scope, statement order, call target, or storage
duration. No structural rewrite or behavior repair was made. The existing
module statuses remain unchanged: `005467B0` and `00546A90` are accepted drift,
and the second constructor at `005468C0` remains scratch per the module note.

Unresolved items are the omitted or optimized local-name mappings listed above,
the `do_zone_map` `group` type mismatch, and the pending header-only parameter
name request. No resource or constant question remains.

## Validation status

Compilation, matching, audits, and tests were not run. No compiler, build,
matching, audit, test, or game command was run for this assignment.
