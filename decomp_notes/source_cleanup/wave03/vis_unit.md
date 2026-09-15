# `src/vis_unit.cpp` cleanup report

## Scope and commits

- Module: `src/vis_unit.cpp`
- PDB source: `C:\\msdev\\work\\age1_x1\\vis_unit.cpp`
- Header read only: `include/vis_unit.h`
- Header owner: owner 16 owns `include/vis_unit.h`.
- Branch: `cleanup/staging-20260915-141`
- Base commit from `git rev-parse HEAD`: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source cleanup commit: `e7b39612604e8420970680e0877ac79107535cbc`
- Final source commit: `e7b39612604e8420970680e0877ac79107535cbc`
- Changed files:
  - `src/vis_unit.cpp`
  - `decomp_notes/source_cleanup/wave03/vis_unit.md`

The source commit changes only the assigned source. The report is committed in
one later report-only commit. The delivery response records that report commit.

The source keeps all 13 registry owners in PDB address and source order. The
cleanup restores procedure-scoped PDB names and applies 1TBS function braces.
It does not change types, casts, scopes, storage, calls, literals, evaluation
order, control flow, layouts, or ABI symbols.

## Evidence identity

I inspected the assigned source, the registry, the read-only header, the
existing module note, and the complete procedure-scoped PDB records at:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/vis_unit.cpp.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/vis_unit.md`

I inspected the registry-selected original packets at these paths:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/0053B5A0_Visible_Unit_Manager.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/0053B670_Visible_Unit_Manager.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/0053B730_Build_Distance_Table.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/0053B7E0_Update_Unit_Info.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/0053B9A0_GetVisibleUnits.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/0053BB30_Visible_Resource_Manager.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/0053BBE0_Visible_Resource_Manager.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/0053BD10_Visible_Resource_Manager.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/0053BD70_save.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/0053BE00_Process_New_Tiles.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/0053BED0_AddResource.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/0053BFD0_Remove_Resource.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/0053C050_Get_Closest_Resource.txt`

The original executable and preserved baseline executable identify the evidence
set as follows:

- Original PE:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  - SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- Baseline PE:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
  - SHA256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`
- Base source SHA256:
  `6c697a40c031ce7b65f84617606e9ed3e269f2b7ca0d524aa2062e4ae88766aa`
- Final source SHA256:
  `c58a9457cdbd9fa7315bf08994596c659335c105b03047254332dbde57e23120`

I read the pinned VC5 host configuration and the local VC5 `stdlib.h` and
`string.h` headers. No SDK or CRT symbol applied to an unchanged literal.

## Original-name recovery coverage

The scoped PDB records cover all 13 registry-selected normal owners. Each
procedure has a `this` register record in `ecx` with the owning manager type.
No function-static record is present. The table lists every scoped stack
parameter and named local. A blank entry means that the PDB has no named
record for that category.

| VA | Procedure | PDB stack parameters | PDB locals | Register |
| --- | --- | --- | --- | --- |
| `0053B5A0` | `Visible_Unit_Manager::Visible_Unit_Manager` | `Num_Players`, `Num_Categories` | none | `this:ecx` |
| `0053B670` | `Visible_Unit_Manager::~Visible_Unit_Manager` | none | `i` | `this:ecx` |
| `0053B730` | `Visible_Unit_Manager::Build_Distance_Table` | none | none | `this:ecx` |
| `0053B7E0` | `Visible_Unit_Manager::Update_Unit_Info` | `Object_Id`, `player_id`, `Xpos`, `Ypos`, `Category`, `PriorUnifiedMap`, `NewUnifiedMap`, `ObjectPtrs` | `i`, `r`, `ChangedMask` | `this:ecx` |
| `0053B9A0` | `Visible_Unit_Manager::GetVisibleUnits` | `Xpos`, `Ypos`, `LOS`, `player`, `DesiredTypes`, `DesiredCount`, `PlayerListMap` | `found`, `y2`, `PDP`, `y1`, `distTbl`, `x2`, `x1`, `count` | `this:ecx` |
| `0053BB30` | `Visible_Resource_Manager::Visible_Resource_Manager` | `list_owner`, `num_lists` | none | `this:ecx` |
| `0053BBE0` | `Visible_Resource_Manager::Visible_Resource_Manager` | `infile`, `list_owner` | none | `this:ecx` |
| `0053BD10` | `Visible_Resource_Manager::~Visible_Resource_Manager` | none | none | `this:ecx` |
| `0053BD70` | `Visible_Resource_Manager::save` | `outfile` | none | `this:ecx` |
| `0053BE00` | `Visible_Resource_Manager::Process_New_Tiles` | `tile_list` | `TileOffsets`, `thelist`, `size` | `this:ecx` |
| `0053BED0` | `Visible_Resource_Manager::AddResource` | `Obj_Id`, `ObjGroup` | `o`, `n`, `Xpos`, `p` | `this:ecx` |
| `0053BFD0` | `Visible_Resource_Manager::Remove_Resource` | `Obj_Id`, `ObjGroup` | none | `this:ecx` |
| `0053C050` | `Visible_Resource_Manager::Get_Closest_Resource` | `Xpos`, `Ypos`, `Zone`, `ResType`, `excList`, `elSize` | `yd`, `xd`, `bestdist`, `Reject`, `c` | `this:ecx` |

The PDB packet line bands are `49-88`, `91-125`, `129-168`, `172-258`,
`265-434`, `445-474`, `477-518`, `521-533`, `537-554`, `559-611`, `616-665`,
`669-703`, and `708-792`, in the same order as the table. The packet sizes
are 196, 183, 173, 445, 387, 165, 298, 89, 135, 195, 244, 122, and 351
bytes, respectively.

The following source names changed. Each mapping is a procedure-scoped PDB
recovery. The record matches the procedure owner and declaration offset.

| VA | Renamed source names |
| --- | --- |
| `0053B5A0` | `player_count` -> `Num_Players`; `category_count` -> `Num_Categories` |
| `0053B7E0` | `object_id` -> `Object_Id`; `player` -> `player_id`; `x` -> `Xpos`; `y` -> `Ypos`; `category` -> `Category`; `old_mask` -> `PriorUnifiedMap`; `new_mask` -> `NewUnifiedMap`; `refs` -> `ObjectPtrs`; local `mask` -> `ChangedMask` |
| `0053B9A0` | `x` -> `Xpos`; `y` -> `Ypos`; `distance` -> `LOS`; `categories` -> `DesiredTypes`; `category_count` -> `DesiredCount`; `player_map` -> `PlayerListMap`; local `player_data` -> `PDP`; `distance_table` -> `distTbl`; `min_x` -> `x1`; `max_x` -> `x2`; `min_y` -> `y1`; `max_y` -> `y2` |
| `0053BB30` | `owner` -> `list_owner`; `count` -> `num_lists` |
| `0053BBE0` | `handle` -> `infile`; `owner` -> `list_owner` |
| `0053BD70` | `handle` -> `outfile` |
| `0053BE00` | parameter `list` -> `tile_list`; local `tile_list` -> `thelist`; local `rows` -> `TileOffsets` |
| `0053BED0` | `object_id` -> `Obj_Id`; `type` -> `ObjGroup`; local `object` -> `o`; local `record` -> `p`; local `x` -> `Xpos` |
| `0053BFD0` | `object_id` -> `Obj_Id`; `type` -> `ObjGroup` |
| `0053C050` | locals `dx` -> `xd`; `dy` -> `yd` |

Names already matching the PDB remain unchanged. These include the destructor
`i` local, `found` and `count` where present, the second resource constructor's
`infile`, the closest-resource parameters, and all unlisted descriptive locals.
The PDB has no parameter or local records for `0053B730` or `0053BD10`.

## Unresolved and invented names

The PDB records `r` as `VISIBLE_UNIT_REC*` at `-0x8` in
`0053B7E0`, but the original assembly writes and increments a player index in
that slot. The source keeps `int r` because its use is an integer player index.
No type, storage, or reused-slot mapping was forced.

The `0053BED0` PDB records `Xpos` and `p` at the same `+0xc` stack offset.
The source keeps the separate `int Xpos` and `VISIBLE_RESOURCE_REC* p`
declarations required by their uses. This preserves the natural declaration
scope and does not infer a shared carrier.

The PDB does not name other source locals such as `row`, `j`, `table`,
`offsets`, `entry`, `first`, `last`, `index`, `count`, `current_table`,
`list`, `list_size`, `new_list`, `record`, `last_record`, `bucket`,
`record_x`, `record_y`, `dx`, `dy`, `unit_distance`, `result`, `saved`,
`i`, `saved_handle`, `current_tile`, `tile`, `node`, `object`, `master`,
`id`, `y`, `list`, `distance`, and `record`, where applicable. These names
remain concise descriptive source names. They are not claimed as original
names. No reused register or stack-slot mapping was forced.

All recovered names preserve the PDB's original mixed style, including
capitalized names and terse names. No public function, class, member, global,
type, storage layout, or ABI symbol was renamed.

## Constants, resources, comments, and formatting

- No numeric constant, enum use, literal notation, or resource ID changed.
- No resource lookup occurs in this module. No resource DLL extraction,
  language record, missing slot, fallback path, override path, or resource
  mapping request is needed.
- No source comment was added, removed, or changed. The module has no comment
  that needs a new evidence note.
- Function definition braces now use 1TBS. Short constructor, save, process,
  and closest-resource signatures remain on one line. No statement moved.

## Code-generation, type, layout, and symbol review

The edits change identifier spellings and function brace placement only. They
do not intentionally change a type, cast, declaration scope, storage duration,
statement order, control flow, call target, literal, class layout, function
boundary, or decorated ABI symbol.

Name changes can change debug identifier metadata. Brace placement can change
source line records. This wave deferred generated-output checks, so it does not
claim unchanged compiler output, byte equality, or matching status.

## Shared requests and unresolved questions

Header owner request for `include/vis_unit.h`: update declaration parameter names
to match the recovered PDB spellings. Keep all types, signatures, layouts,
calling conventions, and ABI symbols unchanged.

```cpp
Visible_Unit_Manager(int Num_Players, int Num_Categories);
void Update_Unit_Info(int Object_Id, int player_id, int Xpos, int Ypos,
                      int Category, unsigned long PriorUnifiedMap,
                      unsigned long NewUnifiedMap,
                      VISIBLE_UNIT_REC** ObjectPtrs);
int GetVisibleUnits(int Xpos, int Ypos, int LOS, int player,
                    int* DesiredTypes, int DesiredCount,
                    int* PlayerListMap);
Visible_Resource_Manager(RGE_Player* list_owner, int num_lists);
Visible_Resource_Manager(int infile, RGE_Player* list_owner);
void save(int outfile);
void Process_New_Tiles(RGE_Tile_List* tile_list);
void AddResource(int Obj_Id, int ObjGroup);
int Remove_Resource(int Obj_Id, int ObjGroup);
```

The request does not block this source commit. No root-owned header or shared
resource mapping request is pending. The unresolved `r` type and the
`Xpos`/`p` stack-slot overlap remain open questions for later source recovery.

## Review and validation status

I reviewed the complete source diff and this complete report diff. `git diff
--check` passed before the source commit. No compiler or repository validation
tool was run.

Compilation, matching, audits, and tests were not run. I did not run a
compiler, build, matching check, audit, test, or game command.
