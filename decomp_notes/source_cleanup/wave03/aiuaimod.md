# `aiuaimod.cpp` cleanup report

## Scope

- Source owner: `src/aiuaimod.cpp`
- Assigned header: `include/aiuaimod.h` (read only; unchanged)
- PDB range reviewed: `00412F00` through `0041A100`
- Scoped records reviewed: 117
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Base source blob: `ea4500e9068e5eaa82f129423a1a1c892e9962ce`
- Source blob after cleanup: `83ce798e8edcd37a997b71037262ce0a38a52fab`

The source changes restore procedure-scoped names. They do not change calls, literals, casts, types, statement order, or control flow.

## Evidence

Primary evidence:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
  - SHA-256: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`
- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/aiuaimod.cpp.json`
  - SHA-256: `400ed96daf6b2d29a1b40c9606b44b915eaef7fd441c5676b87af5dd4440a9e7`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/aiuaimod.cpp.decomp`
  - SHA-256: `b7070ab55f93bc0f5246b41fdef876ef01b893076d59c2794a55c42c7af8edb6`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/aiuaimod.cpp.asm`
  - SHA-256: `f92fc4a51ca2549233cbc7d9ee93dab89063e67babc5d18661472ccd73f47e48`
- Original executable: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  - SHA-256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- Original PDB: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/age1_x1.pdb`
  - SHA-256: `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`
- Preserved resource output: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/original.res`
  - SHA-256: `edd8f671b15254db0be049b421947cda59bbffdeb46a1d4c93176e42bfe9ee3a`

The registry marks the module's source functions and identifies accepted drift and reviewed logic records. The direct PDB inventory provides the names below. The original disassembly and decompilation confirm the affected owners and call boundaries.

## Recovered names

The following names come directly from the scoped PDB records:

- Constructor: `o`, `iQS`.
- Save/load: `outfile`, `infile`, `tempInt`, `numberOrders`.
- Accessors: `v` for the setter and element-index parameters.
- `attackingUnitID`: `v`.
- `update`: `uTime`, `haveGameAction`.
- `updateGroup`: `a` for the group-member index.
- Order and notify interfaces: `issuer`, `orderType`, `target`, `targetOwner`, `targetX`, `targetY`, `targetZ`, `range`, `immediate`, `inFront`, `priority`, `callerID`, `recipientID`, `mType`, `p1`, `p2`, and `p3`.
- Target helpers: `targetID`, `unconditional`, `tX`, `tY`, `tZ`, `minimumRange`, `desiredDistance`, `goCloser`, `checkOrderAndAction`, and `uID`.
- Target setters and relation helpers: `o`, `t`, `unitType`, `oID`, `vMap`, `type`, and `ps`.
- Queue and phase helpers: `orderNumber`, `unitToAttack`, `oEvent`, `nEvent`, `doSearch`, `inFront`, `id`, and `textIn`.
- Enemy scans: `threatSlot`, `largestThreat`, `smallestHP`, `largestThreatID`, and `attackThreat`.
- Notify processing: `currentTargetDC`, `killTimeTarget`, `killTimeAttacker`, `lastTargetXValue`, `lastTargetYValue`, `lastTargetZValue`, `tileY`, and `tileX`.

`004138B0` is the inline header implementation of `canConvert`. The assigned source file does not define it, and the header was not edited.

`queue_index` and `unit_count` are cleanup names. They replace generated forms whose original spelling is not unique in the reused load stack.

## Unresolved mappings

The PDB reuses stack slots and records overlapping names. I did not force those names into unrelated declarations.

- `load` has overlapping `numberNotifies`, `numberOrders`, `tempInt`, `tempOrder`, and `tempNotify` records. The source keeps the typed event union and separate status/count declarations. The `numberNotifies` record is not mapped to a unique current declaration.
- `bestUnitToAttack` has overlapping `largestThreat`, `largestThreatID`, `closestEnemyDistance`, `modifier`, `enemyDistance`, `distance`, `i`, and `enemyThreat` records. The current semantic declarations remain where a unique mapping is not provable.
- `closestUndiscoveredTile` has overlapping `i`, `j`, and `pathDistance` records. The current coordinate-loop and distance names remain because their stack ownership is not unique.
- `processMisc` records `targetObj`, but the source has several block-local target declarations. No cross-scope rename was forced.
- `save` includes compiler-visible unused locals without matching PDB names. Their declarations remain unchanged apart from the proved `tempInt` name.

The packet helper did not produce a module packet for the attempted `00412F00` inspection because its expected original executable input was unavailable. The checked-in PDB, original decompilation, assembly, and executable remain the evidence used here.

## Constants, resources, and comments

- No resource-string or language-DLL lookup occurs in this source. No resource-ID mapping request is needed.
- The module uses game resource objects, not language resource IDs. No numeric constant was replaced.
- Comments with stale `param_*` names were updated near `followObject` and `visibleStatus`. Existing boundary and ABI notes were retained.

## Changed files

- `src/aiuaimod.cpp`
- `decomp_notes/source_cleanup/wave03/aiuaimod.md`

No header, registry, inventory, or generated file was changed.

## Risks and requests

The main risk is the documented PDB stack-slot overlap. The cleanup keeps those uncertain declarations unchanged. A future generated-output comparison should confirm that the name-only edits introduce no new drift.

No shared declaration or resource request is open. No question blocks this report.

## Validation

Per the cleanup assignment, compilation, builds, matching, audits, tests, and game launch were not run. Review used direct PDB inspection, original evidence inspection, Git diff review, and `git diff --check` only.

## Correction delivery

- Initial cleanup delivery: `9902c3216ddbb33372653f2e39170cbb2b49a754`.
- Formatting correction delivery: recorded in the correction commit history after this report update.

The correction places opening braces on the definition line throughout this source. It covers `update`, `updateGroup`, `selectNewPlayPhase`, `order`, both `notify` overloads, `search`, `bestUnitToAttack`, action wrappers, movement helpers, `lookAround`, `askForHelp`, `processGroupNotify`, `processMisc`, both queue overloads, and `purgeNotifyQueue`. Existing standalone scope braces remain unchanged. No brace was added or removed.

The correction changed formatting only. Git diff review found no name, logic, comment, type, declaration, scope, or statement-order change. `git diff --check` passed. No compiler, build, matching, audit, test, or game command ran.
