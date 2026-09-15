# `aibldmod.cpp` cleanup report

## Delivery

- Module: `src/aibldmod.cpp`
- Branch: `cleanup/staging-20260915-53`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final module code commit: `9f6b6017a31a4474860ff7c0af427fe088f3cfe3`
- Durable report follows the module code commit in a separate commit.
- Changed files:
  - `src/aibldmod.cpp`
  - `decomp_notes/source_cleanup/wave02/aibldmod.md`
- Header not changed: `include/aibldmod.h` remains owner 06's file.

## Cleanup result

The source now uses the readable names recorded by the procedure-scoped PDB.
It uses 1TBS function braces. It keeps statement order, types, casts, calls,
literals, scopes, and storage. It adds no constants, resource macros, or
source comments. It adds no helper, layout, assembly, or wrapper.

Recovered PDB names changed in the source:

- `004086B0 BuildAIModule::BuildAIModule`: `param_1` to `pW`; `param_2` to
  `playerID`.
- `00408840 BuildAIModule::BuildAIModule`: `p1` to `playerID`; `fd` to
  `infile`. The length local is `tempInt`. The optional item capacity local
  is `buildCap`. The PDB names `terrainAdjOne`, `terrainAdjTwo`, and
  `numberSkipCycles` replace descriptive substitutes.
- `00408DF0 BuildAIModule::save`: `file` to `outfile`; `iStack_110` to
  `tempBOOL`; `local_109` to `tempBYTE`.
- `00409430 BuildAIModule::loadBuildList`: `filename` to `lName`; `fp` to
  the PDB's `fileIn` stream name. The parsed fifth field local is the PDB's
  `buildCap` name, not the stream name.
- `004098C0` through `00409E20` type filters: PDB names `type` and `category`
  replace generated or substituted parameter names.
- `00409EE0 BuildAIModule::anyBuildListItem`: `param_1`, `param_2`, and
  `param_3` to `id`, `checkBuilt`, and `buildStatus`.
- `00409F50 BuildAIModule::specificBuildListItem`: `uniqueID` to the PDB's
  `id`.

The source had no new cleanup names. Existing local names without a PDB
mapping remain unchanged. This includes loop, sentinel, item, and `saveID`
locals. No reused stack-slot mapping was forced.

## PDB coverage

Source: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB source path is `C:\msdev\work\age1_x1\aibldmod.cpp`. Every assigned
procedure has a scoped record. Every record has `this` in `ecx` with the
`BuildAIModule*` or `const BuildAIModule*` type shown below. No other register
name was present in these records.

| VA | Procedure | PDB parameters | PDB locals |
| --- | --- | --- | --- |
| `004086B0` | `BuildAIModule::BuildAIModule` | `pW: void*`, `playerID: int` | none |
| `00408840` | `BuildAIModule::BuildAIModule` | `playerID: int`, `infile: int` | `tempInt`, `buildCap`, `builtValue`, `inProgressValue`, `buildAttemptsValue`, `terrainAdjOne`, `skipValue`, `zSize`, `gameID`, `xSize`, `x`, `uniqueID`, `y`, `buildCategory`, `z`, `terrainAdjTwo`, `numberBuilds`, `ySize`, `numberSkipCycles`, `typeID`, `permanentSkip`, `terrainSet`, `placeOnElevation`, `buildFrom`, `name[257]` |
| `00408D50` | `BuildAIModule::~BuildAIModule` | none | none |
| `00408DF0` | `BuildAIModule::save` | `outfile: int` | `tempString[257]`, `tempBOOL: int`, `tempBYTE: unsigned char`, `tempFloat: float`, `tempInt: int` |
| `004092F0` | `BuildAIModule::displayBuildList` | none | none |
| `00409430` | `BuildAIModule::loadBuildList` | `lName: char*`, `player: RGE_Player*` | `fileIn: _iobuf*`, `temp[256]`, `ySize: float`, `commentTemp2: char`, `commentTemp1: char`, `name[64]`, `typeID: int`, `buildCategoryAsChar: char`, `quantity: int`, `xSize: float`, `buildFrom: int`, `buildCap: int` |
| `004098A0` | `BuildAIModule::buildListLength` | none | none |
| `004098B0` | `BuildAIModule::buildListName` | none | none |
| `004098C0` | `BuildAIModule::haveBuildList` | none | none |
| `00409950` | `BuildAIModule::insertItem` | `player`, `typeID`, `quantity`, `buildCategory`, `buildFrom`, `buildCap`, `insertAfterItemNumber` | `ySize`, `name[64]`, `xSize` |
| `00409B70` | `BuildAIModule::numberItemsBuilt` | none | none |
| `00409BB0` | `BuildAIModule::numberItemsInProgress` | none | none |
| `00409BF0` | `BuildAIModule::numberItemsBuiltOrInProgress` | none | none |
| `00409C30` | `BuildAIModule::numberItemsIntoBuildList` | none | none |
| `00409C40` | `BuildAIModule::lastBuildItemRequested` | none | none |
| `00409C50` | `BuildAIModule::currentBuildItemRequested` | none | none |
| `00409C60` | `BuildAIModule::nextBuildItemRequested` | none | none |
| `00409C70` | `BuildAIModule::numberItemsOfType` | `type`, `category` | `count: int` |
| `00409CD0` | `BuildAIModule::numberBuiltItemsOfType` | `type`, `category` | `count: int` |
| `00409D40` | `BuildAIModule::numberUnbuiltItemsOfType` | `type`, `category` | `count: int` |
| `00409DB0` | `BuildAIModule::numberBuiltOrInProgressItemsOfType` | `type`, `category` | `count: int` |
| `00409E20` | `BuildAIModule::numberInProgressItemsOfType` | `type`, `category` | `count: int` |
| `00409E90` | `BuildAIModule::removeOldList` | none | none |
| `00409EE0` | `BuildAIModule::anyBuildListItem` | `id`, `checkBuilt`, `buildStatus` | none |
| `00409F50` | `BuildAIModule::specificBuildListItem` | `id` | none |

The compiler-generated scalar deleting destructor at `00408820` is outside the
assigned source owner and was not changed.

## Evidence

- Function registry: `config/functions/src/aibldmod.cpp.json`.
- Original decompiler reference:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/aibldmod.cpp.decomp`.
- Original executable reference:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
  SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Preserved baseline object:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/aibldmod.obj`.
  SHA256: `a16689323fd7915b062eea1a0fe9d8d86f43cc765ff02f878829f5be22a3e9bd`.
- The source uses `0x3E9` as the `AIModule` numeric module ID. It does not
  call a string lookup. I left the literal unchanged.

### Resource review

No resource macro request was made. The `0x3E9` value is stored as an AI
module ID, not passed to a resource lookup in this module. The extraction
results are recorded here because the same number exists in string resources:

- `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`, SHA256
  `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
  RT_STRING ID `1001` (`0x03E9`), language `0x0409`, block `63`, slot `9`,
  text `Age of Empires`.
- `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`, SHA256
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
  ID `0x03E9` is missing.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`,
  SHA256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
  ID `0x03E9` is missing.

The string text does not prove a resource lookup path for this constructor.

## Risk and validation

The changes rename parameters and locals and move function opening braces.
They do not change source types, layout, ABI symbols, call targets, literal
values, expression order, or control flow. Identifier and brace changes can
still change debug records or compiler choices. The preserved baseline remains
available for the final comparison.

Compilation, matching, audits, builds, and tests were not run. No compiler,
build, matching, audit, test, or game command was run for this cleanup.
