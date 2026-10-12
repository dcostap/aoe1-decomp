# Wave 02 cleanup: `src/aiconmod.cpp`

## Delivery

- Module: `src/aiconmod.cpp`.
- Header owner: owner 06 owns `include/aiconmod.h`. This worker did not edit it.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Final source commit: `1546ddb642e74f0f388fcd4f111d15a6f903dc33`.
- Changed source: `src/aiconmod.cpp`.
- Changed report: `workflow/decomp_notes/source_cleanup/wave02/aiconmod.md`.
- Branch: `cleanup/staging-20260915-54`.

The source commit contains only the assigned source. The report is a separate
assigned-file commit so the source commit hash remains exact and reproducible.

## Correction history

- Initial source commit: `9c10e5929358cab5ba4fe0757594b8222fe1e4db`.
- Initial report commit: `2a8f7ee35fd6e536e7c581a4c51114de1d7dd237`.
- Correction request: move both constructor braces onto their final
  initializer lines and correct the original executable hash.
- Correction source commit: `1b3e5335170c9f93bfa35211beb694adc87070cd`.
- Correction report commit: follows this source commit and contains the
  corrected report hash data.
- Root correction request: restore unsupported constructor local names and
  format both loops as `for (i = 0; i < ...; i++)`.
- Root correction source commit: `1546ddb642e74f0f388fcd4f111d15a6f903dc33`.
- Root correction report commit: follows this source commit.

## PDB coverage

The scoped PDB inventory reports all 19 normal source owners. Every owner has
`this` in `ecx`. The scalar deleting destructor at `0040AB90` is compiler
generated and has no source owner.

| VA | Function | PDB parameters and locals inspected |
| --- | --- | --- |
| `0040AA90` | `ConstructionAIModule::ConstructionAIModule` | Parameters `pW`, `playerID`; no locals; register `this=ecx`. |
| `0040ABB0` | `ConstructionAIModule::ConstructionAIModule` | Parameters `playerID`, `infile`; locals `i`, `tempInt`, `ySize`, `buildAttemptsValue`, `name`, `uniqueID`, `typeID`, `gameID`, `z`, `inProgressValue`, `y`, `x`, `xSize`, `zSize`, `skipValue`, `builtValue`; the latter 14 names repeat in the second loop where the PDB reports reused slots. Register `this=ecx`. |
| `0040B120` | `ConstructionAIModule::~ConstructionAIModule` | No parameters or locals; register `this=ecx`. |
| `0040B1A0` | `save` | Parameter `outfile`; locals `tempString`, `tempInt`, `tempBOOL`, `tempFloat`; repeated `tempBOOL` and `tempFloat` records are reused homes; register `this=ecx`. |
| `0040B690` | `loadConstructionPlan` | Parameters `pName`, `mXSize`, `mYSize`, `xRef`, `yRef`, `zRef`; locals `temp`, `ySize`, `commentTemp2`, `id`, `commentTemp1`, `name`, `z`, `y`, `x`, `xSize`, `zSize`; register `this=ecx`. |
| `0040B970` | `constructionPlanName` | No parameters or locals; register `this=ecx`. |
| `0040B980` | `setReferencePoint` | Parameters `mXSize`, `mYSize`, `x`, `y`, `z`; no locals; register `this=ecx`. |
| `0040BB70` | `xReferencePoint` | No parameters or locals; register `this=ecx`. |
| `0040BB80` | `yReferencePoint` | No parameters or locals; register `this=ecx`. |
| `0040BB90` | `placeStructure` | Parameter `bi`; no locals; register `this=ecx`. |
| `0040BBA0` | `lastPlacementReturnCode` | No parameters or locals; register `this=ecx`. |
| `0040BBB0` | `setBuilt` | Parameters `ci`, `v`; no PDB locals; register `this=ecx`. |
| `0040BC00` | `unplaceStructure(ConstructionItem*, int)` | Parameters `ci`, `decBA`; no PDB locals; register `this=ecx`. |
| `0040BC80` | `unplaceStructure(float, float, int)` | Parameters `x`, `y`, `decBA`; no PDB locals; register `this=ecx`. |
| `0040BD10` | `decrementBuildAttempts` | Parameters `x`, `y`, `n`; no PDB locals; register `this=ecx`. |
| `0040BD40` | `incrementBuildAttempts` | Parameters `x`, `y`, `n`; no PDB locals; register `this=ecx`. |
| `0040BD70` | `lot` | Parameters `x`, `y`; no PDB locals; register `this=ecx`. |
| `0040BE10` | `randomLot` | Parameters `x`, `y`; no PDB locals; register `this=ecx`. |
| `0040BE70` | `removeOldLots` | No parameters or locals; register `this=ecx`. |

PDB coverage evidence comes from
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Its recorded PDB hash is
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
The scoped inventory file hash is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.

## Recovered names

The cleanup restores PDB spellings in the source definitions. It does not
change public symbols, types, scopes, layouts, calls, literals, or evaluation
order.

- `0040AA90`: `param_1` became `pW`; `param_2` became `playerID`.
- `0040ABB0`: `p1` became `playerID`; `fd` became `infile`; loop counter `n`
  became PDB `i`.
- `0040B1A0`: `fd` became `outfile`.
- `0040B690`: parameters became `pName`, `mXSize`, `mYSize`, `xRef`, `yRef`,
  and `zRef`.
- `0040B980`: parameters became `mXSize`, `mYSize`, `x`, `y`, and `z`.
- `0040BB90`: `item` became `bi`.
- `0040BBB0`: `item` and `built` became `ci` and `v`.
- `0040BC00` and `0040BC80`: `decrement` became `decBA`; the item
  parameter became PDB `ci` in the pointer overload.
- `0040BD10` and `0040BD40`: `count` became PDB `n`.
- `0040BE10`: `px` and `py` became PDB `x` and `y`.

The inner serialized integer/float local formerly named `i` would conflict
with the recovered loop counter. It is now `i_value`. This is an invented
snake_case cleanup name. Its type, declaration scope, raw-bit access, and
position remain unchanged.

The source already used PDB spellings for the other directly mapped locals,
including `x`, `y`, `z`, `xSize`, `ySize`, `zSize`, `uniqueID`, `typeID`,
`gameID`, `tempString`, `tempInt`, `tempBOOL`, and `tempFloat`.

## Unresolved mappings

The PDB has no safe one-to-one source mapping for some reused stack homes.
The source keeps these mappings unchanged:

- In `0040ABB0`, PDB `tempInt` and the raw serialized length local are not a
  safe one-to-one match in the current typed `IntFloat x` source. The source
  keeps `IntFloat x` and its `.i` accesses. The PDB type records also report
  overlapping integer and floating names in this constructor.
- In `0040ABB0`, the PDB repeats `buildAttemptsValue`, `inProgressValue`,
  `skipValue`, and `builtValue` across reused homes. The records do not prove
  those names for both current loop declarations. Both loops therefore retain
  baseline names `buildAttempts`, `inProgress`, `skip`, and `built`. Their
  `IntFloat` types, declaration scopes and order, `rge_read` calls, uses, and
  raw-bit member accesses remain unchanged.
- In `0040B690`, PDB records for `id`, `name`, `xSize`, and `y` overlap the
  current saved-plan pointer, parser integer, parser floats, comment bytes,
  and buffer declarations. The current `saved_plan`, `xSize`, `item_arg_5`,
  `item_arg_6`, `itemName[60]`, and unused `y` declarations remain unchanged.
  The PDB records report `id` as `int`, `name` as `char[64]`, and `xSize` as
  `float`; changing current types or buffer sizes would be a structural edit.
- The PDB emits no locals for the list pointers in several functions. Existing
  descriptive names such as `item`, `current`, `end`, `target`, `prev`, and
  `next` remain unchanged.

The packet for `0040ABB0` shows the serialized field order and the loop counter
in `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0040/0040ABB0_ConstructionAIModule.txt`.
The packet for `0040B690` shows the parser stack reuse in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0040/0040B690_loadConstructionPlan.txt`.
The other owner packets are under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0040/`.

## Constants, comments, and resources

No numeric constants changed. No resource ID changed. No new comment was
added. Existing comments about raw serialized locals, the unused base placement
routine, and accepted drift remain in the source.

No shared declaration request is needed. No header changed.

For provenance, the inspected binary paths and hashes are:

- Original behavior oracle:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`, SHA256
  `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Preserved pre-cleanup object:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/aiconmod.obj`, SHA256
  `1e37678ec9a0f6a92c4c7aabaffa6950a89617a16e8ac34691ee9e8b7710bdb2`.
- Preserved pre-cleanup executable:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`, SHA256
  `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
- Runtime base resources, not used for a resource edit:
  `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`, SHA256
  `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`;
  `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`, SHA256
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
- Original expansion resource reference:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA256
  `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

No resource request exists. Therefore there is no ID, text, missing/empty
status, language, lookup path, or purpose to report.

## Risk and validation

The source edits change identifiers and function-brace presentation only.
They do not change ABI symbols, types, storage, layout, control flow, calls,
literals, or explicit casts. Renamed parameters and locals have no ABI effect.
The inner `i_value` rename keeps its original declaration and type.

I reviewed the complete Git diff with `git diff --check` and `git diff`.
Compilation, matching, audits, builds, and tests were not run, as required for
this cleanup wave. No byte equality or semantic approval is claimed.
