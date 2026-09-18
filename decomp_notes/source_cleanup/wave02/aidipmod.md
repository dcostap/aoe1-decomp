# `src/aidipmod.cpp` cleanup report

## Delivery

- Module: `src/aidipmod.cpp`.
- Report: `decomp_notes/source_cleanup/wave02/aidipmod.md`.
- Branch: `cleanup/staging-20260915-56`.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Final source commit: `222c80715f2dfee67a8ee2215a68b1d69472a5a5`.
- Changed files in the source commit: `src/aidipmod.cpp`.
- The report is a second, report-only commit on top of the source commit.
- No header, registry, inventory, or game-global file changed.

The source commit keeps the module's 21 normal owners in source order. The compiler-generated scalar deleting destructor remains outside the source file.

## Evidence used

- Procedure-scoped PDB data: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
- Function packets: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0040/`.
- Decompiled reference: `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/aidipmod.cpp.decomp`.
- Original executable reference: `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
- Original executable SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Preserved baseline object: `build/source-cleanup-20260915/preparation/baseline-build/aidipmod.obj`.
- Preserved baseline object SHA256: `5fe4510e52ec0a8a2dc65742ff3522cbb7a1b8b37875d7e1e80f25e72833075e`.

The decompiler supplied control-flow and field-use context. The scoped PDB supplied name evidence.
The original executable remains the behavior oracle. No executable was run.

## PDB coverage

Every source owner has one procedure-scoped PDB entry. Each entry has one `this` register symbol. No entry has a function static. No entry has a named local register symbol beyond `this`.

| VA | Owner | PDB lines | Records | PDB parameters | PDB stack locals | Register symbols |
| --- | --- | ---: | ---: | --- | --- | --- |
| `0040BEC0` | `DiplomacyAIModule::DiplomacyAIModule` | 26-33 | 6 | `pW:void*`, `playerID:int` | none | `this:DiplomacyAIModule*` |
| `0040BF40` | `DiplomacyAIModule::DiplomacyAIModule` | 40-47 | 6 | `playerID:int`, `infile:int` | none | `this:DiplomacyAIModule*` |
| `0040BFF0` | `DiplomacyAIModule::~DiplomacyAIModule` | 52-52 | 1 | none | none | `this:DiplomacyAIModule*` |
| `0040C000` | `DiplomacyAIModule::setMainDecisionAI` | 58-60 | 2 | `m:MainDecisionAIModule*` | none | `this:DiplomacyAIModule*` |
| `0040C010` | `DiplomacyAIModule::update` | 65-93 | 8 | `timeLimit:int` | none | `this:DiplomacyAIModule*` |
| `0040C0A0` | `DiplomacyAIModule::save` | 98-105 | 6 | `outfile:int` | none | `this:DiplomacyAIModule*` |
| `0040C100` | `DiplomacyAIModule::stance` | 110-138 | 19 | `playerID:int`, `likeType:int` | none | `this:const DiplomacyAIModule*` |
| `0040C190` | `DiplomacyAIModule::changeStance` | 144-189 | 30 | `playerID:int`, `likeType:int`, `delta:int` | none | `this:DiplomacyAIModule*` |
| `0040C2B0` | `DiplomacyAIModule::setStance` | 195-240 | 30 | `playerID:int`, `likeType:int`, `value:int` | none | `this:DiplomacyAIModule*` |
| `0040C3B0` | `DiplomacyAIModule::isDisliked` | 245-252 | 6 | `playerID:int` | none | `this:const DiplomacyAIModule*` |
| `0040C3F0` | `DiplomacyAIModule::isAmbivalent` | 257-261 | 4 | `playerID:int` | none | `this:const DiplomacyAIModule*` |
| `0040C420` | `DiplomacyAIModule::isLiked` | 266-272 | 6 | `playerID:int` | none | `this:const DiplomacyAIModule*` |
| `0040C460` | `DiplomacyAIModule::isChangeable` | 277-282 | 6 | `playerID:int` | none | `this:const DiplomacyAIModule*` |
| `0040C4A0` | `DiplomacyAIModule::setChangeable` | 287-290 | 3 | `playerID:int`, `v:unsigned char` | none | `this:DiplomacyAIModule*` |
| `0040C4D0` | `DiplomacyAIModule::mostHated` | 296-333 | 19 | `tributeOn:int`, `tributePlayer:int`, `attackWinningPlayer:int`, `attackWinningPlayerFactor:int` | `highestValue:int` at `-0x8`; `highest:int` at `-0x4` | `this:const DiplomacyAIModule*` |
| `0040C5B0` | `DiplomacyAIModule::mostLiked` | 338-362 | 11 | `tributeOn:int`, `tributePlayer:int` | `highest:int` at `-0x8` | `this:const DiplomacyAIModule*` |
| `0040C660` | `DiplomacyAIModule::isEnemy` | 367-378 | 5 | `playerID:int` | none | `this:const DiplomacyAIModule*` |
| `0040C6A0` | `DiplomacyAIModule::isNeutral` | 383-394 | 5 | `playerID:int` | none | `this:const DiplomacyAIModule*` |
| `0040C6E0` | `DiplomacyAIModule::isAlly` | 399-413 | 8 | `playerID:int` | none | `this:const DiplomacyAIModule*` |
| `0040C730` | `DiplomacyAIModule::isAlliedWithMe` | 418-427 | 7 | `playerID:int` | none | `this:const DiplomacyAIModule*` |
| `0040C780` | `DiplomacyAIModule::setRelation` | 432-442 | 4 | `playerID:int`, `newRelation:int` | none | `this:DiplomacyAIModule*` |

The compiler-generated scalar deleting destructor at `0040BF20` has no PDB line span or records. Its scoped symbols are `__flags:unsigned int` at `+0x4` and `this:DiplomacyAIModule*` in `ecx`. It was not edited.

## Recovered original names

The source now uses every readable PDB parameter name listed above. This includes names that looked readable before cleanup.

- Constructors: `param` became `pW`; `value` became `playerID`; the load constructor uses `playerID` and `infile`.
- `setMainDecisionAI`: `value` became `m`.
- `update`: the unnamed parameter became `timeLimit`.
- `save`: `param_1` became `outfile`.
- `stance`: `player_id` and `type` became `playerID` and `likeType`.
- `changeStance`: `player`, `type`, and `value` became `playerID`, `likeType`, and `delta`.
- `setStance`: `player` and `type` became `playerID` and `likeType`. `value` already matched the PDB.
- `isDisliked`, `isAmbivalent`, `isLiked`, and `isChangeable`: `player` became `playerID`.
- `setChangeable`: `index` became `playerID`; `value` became the PDB spelling `v`.
- `mostHated`: `param1` through `param4` became `tributeOn`, `tributePlayer`, `attackWinningPlayer`, and `attackWinningPlayerFactor`.
- `mostLiked`: `param1` and `param2` became `tributeOn` and `tributePlayer`.
- `isEnemy`, `isNeutral`, and `isAlly`: generated or generic parameter names became `playerID`.
- `isAlliedWithMe`: `player_num` became the PDB spelling `playerID`.
- `setRelation`: `player_id` and `stance` became `playerID` and `newRelation`.

The PDB stack slots identify `highestValue` at `-0x8` and `highest` at `-0x4` in `mostHated`. The assembly uses the `-0x4` slot for the selected player and the `-0x8` slot for the score. The source now preserves those PDB names without changing declaration order or types.

The PDB identifies `highest` in `mostLiked`. The selected-player local has no PDB name. The source retains its descriptive `result` name.

## Inferred cleanup names

The following names have no scoped PDB record. They are cleanup names, not recovered original names.

- The load constructor uses `changeable_table` and `like_table` for its two table pointers.
- `update` and both selection routines use `player_index` for their loop index.
- `save` uses `changeable_table` and `like_table` for its table pointers.
- `mostHated` uses `victory_points` and `stance_value` for the value calculation.
- `isEnemy` and `isNeutral` use `player` for the cached player pointer.
- Existing inferred names such as `player`, `world`, `me`, `other`, `result`, `count`, `dislike_diff`, and `like_diff` remain descriptive and use snake_case where applicable.
- The first constructor's array loop keeps the existing short `i` name. The PDB has no local record for it.

The source has no remaining `param_*`, `param1`-style, `pRVar*`, or `pVar*` names.

## Constants, comments, and resources

No numeric constant changed. No new constant was added. No source comment was added.
The source keeps the explicit casts, literal values, calls, declaration order, statement order, and control flow.

### Shared resource request

Request the root resource-ID owner to review one shared mapping for the base-game lookup use only. This source does not replace the literal because it passes the value as an `AIModuleID`, not directly to a string lookup.

- Proposed cleanup name for the base-game lookup: `STRING_ID_HELP_WINDOW_TITLE`.
- Numeric ID: `0x03EB` (decimal `1003`).
- Resource type: `RT_STRING`.
- Current base runtime: `runtime/language.dll`.
- Base runtime SHA256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- Language: `0x0409` (`1033`).
- Text: `Age of Empires Help`.
- Current expansion runtime: `runtime/languagex.dll`.
- Expansion runtime SHA256: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
- Expansion result: ID `0x03EB` is missing. It is not an empty slot result.
- Pinned original expansion file: `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`.
- Pinned original expansion SHA256: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
- Pinned original expansion result: ID `0x03EB` is missing. It is not an empty slot result.
- Lookup path: `RGE_Base_Game::get_string(long,char*,int)` calls `LoadStringA(StringTable, ...)`. `TRIBE_Game::get_string(long,char*,int)` tries `StringTableX` first, then falls back to the base lookup.
- Call-site purpose: `RGE_Base_Game::~RGE_Base_Game` passes `0x03EB` to `FindWindowA` as the `MS_WINHELP` window-name argument. `DiplomacyAIModule` passes the same value to `AIModule` as its module ID.

The text and purpose are established for the base-game string lookup. This request applies to that lookup use only. The identical `DiplomacyAIModule` module ID must remain numeric. Equal values do not prove equal semantic roles. The proposed mapping remains a shared request only.

## Generation and ownership risk

The source change only renames identifiers and moves opening braces to 1TBS form. It does not change a type, layout, ABI signature, symbol spelling, call target, cast, literal, evaluation order, or statement order.

The formerly unnamed `update` parameter now has its PDB name. This can change debug metadata only.
The PDB-backed `mostHated` names follow scoped stack slots. No local declaration moved or changed type.
Formatting can change PDB line records. Final validation must check executable content and relocations.

The header `include/aidipmod.h` remains unchanged. Its unnamed declarations still match the definitions by type and order.

A pre-existing status conflict remains. `config/functions/src/aidipmod.cpp.json` lists 21 `matching` owners. The older `decomp_notes/aidipmod.md` says 20 matching owners and marks `stance` as scratch. This cleanup did not change either record. No matching check was run.

## Validation

Allowed evidence commands ran before delivery. `inspect_pe_strings.py --help` ran before resource extraction. `git diff --check` ran after the source edit. The complete source diff was reviewed.

Compilation, matching, audits, and tests were not run.
Builds, compiler checks, games, and runtime validation were not run.
