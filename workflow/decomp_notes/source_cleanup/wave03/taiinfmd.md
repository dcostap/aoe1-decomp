# `taiinfmd.cpp` source cleanup

## Delivery

- Module: `src/taiinfmd.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source candidate before the declaration correction pass:
  `76180ec12a9cf731a9ddb5135f2caefdab780fd7`
- Source SHA-256 after the declaration correction pass:
  `51076e454e554097ac030189537d4540202cd5a3788a12df09118505f87695c5`
- Changed files:
  - `src/taiinfmd.cpp`
  - `workflow/decomp_notes/source_cleanup/wave03/taiinfmd.md`

The source owner is `src/taiinfmd.cpp`. The header `include/taiinfmd.h` was read but not changed.
No other tracked file changed.

## Declaration correction history

The correction pass compared the cleanup source with base commit
`76037279ee11dde077bb7d55aeb46b518b2bb27c` and the scoped PDB records.
It restored declaration shape where the cleanup had removed aliases or changed storage use.

- Restored the constructor's temporary declarations and reused parameter storage.
- Restored the destructor's separate unit-history file handle and assignment.
- Restored `update` output-slot declarations.
- Restored `save`'s separate output handle, temporary, and parameter reuse.
- Restored `objectMemory` pointer and index aliases.
- Restored `loadLearnInfo` count and item-value aliases.
- Restored the accumulator parameter in `higherPriorityObjectToDefend`.
- Removed the extra outer `timeKillRatio` declaration in `objectToAttackByGroup2`.
- Applied 1TBS brace placement and four-space indentation without changing scopes.

Only names supported by a direct PDB record remain recovered names. Other declarations retain
the source spelling from the base source. The pass did not change statements, scopes, calls,
casts, literals, storage types, or initialization order.

## Reviewer rejection and second correction

The integration review at `70d4611304b93c9e0d67aff0b1194b54a84d25fb` rejected six forms.
This pass corrected them on the source branch. The earlier history above now records the final
form, not the rejected form.

- `setupWalls` now has `centerX` and `centerY` parameters, with separate `x` and `y` locals.
- `setupWalls` retains baseline `wallShape` and `setupGates`; PDB parameter names `x` and `y`
  conflict with the required `x` and `y` loop locals.
- `save` now reuses `outfile` for the list counts and string length.
- The destructor now assigns `file` to `local_14` before its first file test.
- `update` now retains the explicit `RGE_Visible_Map*` cast.
- `unexploredPlayerLocation` now overwrites the low byte of `uID` and separately initializes `i`.
- `requiredZone` remains an unsafe reused-home PDB record, not a recovered source declaration.
- `dropsitesWithinRequiredDistance` now declares `a` before its separate initialization.

## Post-cleanup validation repair

The fresh main compilation report found an undeclared `gatherer` at the `lookupZone` call in
`gameIDOfResourceObject`. The finding is recorded in
`C:/Projects/my_decomps/aoe1_attempt3/build/executable/user/20260915T215425319815Z/20260915T215425568371Z/report.json`.

The integrated main at `fafc408fd43285ad1f9e778282cca9443b474b0f` and the precleanup source at
`6d46835cdc6e31ba879a2e6e31415327a7c7e341` showed the distinct gatherer-object binding. The
`lookupZone` use now binds to the existing `gathererObj` declaration. No scope, type, storage,
order, or declaration changed.

## Scope and coverage

The registry contains 121 entries for this module. This includes two constructors and one destructor.
The source contains 118 ordinary function definitions plus those three special members.
All 121 registry entries were reviewed against their scoped PDB records and original packets.
The scoped PDB evidence also contains one compiler-generated scalar-deleting destructor wrapper.
That wrapper has no handwritten source body and was not edited.

The cleanup restores supported parameter and local names. It does not change public function names,
class names, member names, layouts, calling conventions, or header declarations.

## Evidence

The review used these files and records. Paths are absolute for repeatable review:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-119/build/taiinfmd_evidence/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-119/build/taiinfmd_evidence/packet_index.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-119/build/taiinfmd_evidence/packet_paths.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-119/build/taiinfmd_evidence/source_defs.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-119/config/functions/src/taiinfmd.cpp.json`
- Original packets under `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/` and `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/`, including:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D8D20_closestUnexploredTile.txt`,
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004DFD60_findObjectMemoryLimits.txt`,
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E1260_loadLearnInfo.txt`,
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E2E90_updateResourceDropsites.txt`,
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E3210_amountForageBushesInXTiles.txt`, and
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E3390_damagePerSecond.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-119/decomp_notes/taiinfmd.md`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-119/include/taiinfmd.h`, read-only for this assignment

The original executable remains the behavior oracle. PDB names are evidence for spelling and type.
Packet disassembly and the existing source supplied the behavior context.

## Recovered names

These names come from the procedure-scoped PDB records:

- Constructors: `pW`, `pID`, `infile`, `tempIntNum`, `i`, and `tempInt`.
- Save and map scan: `outfile`, `timeLimit`, `vMap`, `gMap`, `list`, `listSize`, `i`,
  `visibleStatus`, `tileType`, `numberTreesOnTile`, and `qX`.
- Map and resource queries: `uID`, `cX`, `cY`, `uX`, `uY`, `rType`, `gathererID`,
  `roXPos`, `roYPos`, `dropsiteID`, `exclusions`, `numExclusions`, `oType`, `objects`,
  `owners`, `ownerNumber`, `cX`, `cY`, `centerType`, and `edgeType`.
- Attack and defense: `ownerID`, `targetID`, `attackState`, `startTime`, `commanderObj`,
  `oTDObject`, `soldiers`, `numberSoldiers`, `bestObject`, `bestAttackValue`,
  `timeKillRatio`, `killsByTarget`, `zoneFactor`, `targetRandomization`, `timeTK`,
  `attackAttemptFactor`, `damageIPS`, `inProgressFactor`, `timeTBK`, `miscFactor`,
  `targetDistance`, `inProgressCount`, `unobstructibleGroupID`, `unitID`, `oType`,
  `oGroup`, `bestDefendValue`, and `objPoint`.
- Lot, wall, and placement helpers: `one`, `two`, `countDiagonal`, `typeID`, `status`,
  `newStatus`, `overlapSize`, `x`, `y`, and `numGates`.
- Learning and resource helpers: `name`, `numToLoad`,
  `point`, `pathDistance`, `playerID`, `numTiles`, `victimID`, `objY`, `oT1`, `oT2`,
  `oT3`, `oT4`, `rDistance`, `rID`, `startPoint`, `rPoint`, `useTransport`,
  `landTerrainRequired`, `stageDistance`, `target`, `vMap`, `gMap`, `targetZone`,
  `targetPoint`, `maxLOSValue`, `maxAttackValue`, `randomization`, `temp`, `temp2`,
  `passableMax`, `passableMin`, `a`, `b`, `ownerID`, `x`, `y`, `r`, `t`, `resourceObj`,
  `countTownCenter`, `dropDistance`, `resourceZone`, `unitObj`, `rVal`, `useJustRange`,
  `bestTimer`, `bestHitpoints`, `bestState`, `hitpoints`, `bestMem`, `bestValue`,
  `vMap`, `numDS`, `maxDistance`, `dropsites`, `gMap`, `numberTreesOnTile`,
  `groupSize`, `playID`, `totalPlays`, `historyFileName`, `rVal1`, `rVal2`, and `obj`.

The source also uses concise descriptive names where the PDB had only register locations,
reused slots, or no stable source mapping. Those names are cleanup names, not recovered originals.
Examples include `building_size_int`, `object_x`, `object_y`, `resource_offset`,
`building_index`, `influence_radius`, and `distance_squared` in scopes without an exact PDB
mapping.

## Unresolved mappings

- Several `setupInfluenceMap` PDB records reuse stack slots. The records contain repeated
  `bMinLOS` and `bMaxLOS` entries and a `maxEdgeExclude` entry. The source keeps separate
  declarations for each lifetime and does not force a single name across those slots.
- The `a` and `b` labels in placement, resource, and staging procedures use reused storage.
  The source keeps descriptive names where a direct scope match is not proven.
- Register-only temporaries in object, resource, attack, and placement procedures remain
  descriptive. A readable substitute does not prove an original developer name.
- `requiredZone` in `unexploredPlayerLocation` is an unsafe reused-home PDB record. The source
  keeps the low-byte overwrite of `uID` instead of adding that declaration.
- No public header parameter declarations were changed. A header-owned spelling question
  remains with the header owner.

## Constants, resources, and comments

No numeric constant, resource ID, string lookup, resource lookup order, buffer size, or fallback
was changed. No new shared constant or resource declaration is requested.
The review checked the pinned VC5 include evidence. No SDK constant replacement was needed.

The file contains sparse comments for proven non-obvious behavior. These include the terrain
pointer chain in `initialize`, the tile and quadrant work in `update`, the separate zone-map
and cache homes in `placeDock`, branch behavior for the dock penalty, the unordered floating
comparison in `wonderToAttack`, and the fallback in `convertUnitToIntType`.
These comments were retained. The final edit added no new resource or API comment.

## Code-generation and type risks

The cleanup changes names and presentation. The correction pass restores declaration shape,
aliases, scopes, storage, and initialization points. It keeps expressions, casts, literal
values, statement order, calls, explicit `this->` use, and source ownership.

Names do not affect the ABI, but local declaration changes can affect VC5 register allocation,
stack allocation, or instruction selection. The correction pass reduces this risk by restoring
the original aliases and lifetimes. Remaining risk is limited to recovered local names and
source presentation. Generated-output comparison is still required.

No type, structure layout, public signature, function boundary, call target, tail jump, or
assembly region was changed by this cleanup.

## Shared requests and validation status

There are no shared-file requests. The header and resource-ID owners need no changes for this
module.

No local compilation, matching, audit, test, game execution, or validation command was run.
An external fresh-main compilation report supplied the finding above, and this repair records
the correction without claiming local validation.

## Post-cleanup matching investigation

The functions-r2 report recorded `loadLearnInfo` at `004E1260` as a matching regression:
61 positional bytes differed and 279 aligned. The row is in
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/final-validation/functions-r2/report.csv`.

The preserved baseline object
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/taiinfmd.obj`
and the fresh object
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/final-validation/functions-r2/objects/taiinfmd.obj`
both place `loadLearnInfo` in section 211 with 1216 bytes at raw offset `0x11160`. The
baseline section hash is `d14a2a90be0692828775c0b4f4464a8613ad4d104056872d7c165da28908a053`.
The fresh section hash is `74b7aceb23a6718dc4c1a33f759f79367c5e75f331fc192445d57e627a76e2b1`.

The baseline and fresh source comparison used integrated main
`07e1b741fbd7c60b18c7de222af7ad6f5d28decc` and precleanup commit
`6d46835cdc6e31ba879a2e6e31415327a7c7e341`. The cleanup added the separate
`numMemoriesToLoad` declaration and used it for the first count. The precleanup source reused
`numToLoad`. This is the only extra local in the function. The baseline object starts with
`sub esp, 0x34`; the fresh object starts with `sub esp, 0x38`. The original executable bytes at
`004E1260` in `C:/Projects/my_decomps/aoe1_attempt3/build/array-integration-worktree/orig/empiresx.exe`
also start with `sub esp, 0x34`. The changed instructions are stack-home offsets,
which proves that the extra local caused this drift. Parameter and loop-counter renames did not
cause the observed frame change.

The source now removes only `numMemoriesToLoad` and reuses `numToLoad` for the first count and
loop bound. `numMemoriesToLoad` is a reused-home PDB record. It does not prove a distinct source
declaration. `numToLoad` is the retained declaration and storage. The source preserves the prior
`name` parameter, `resource_index` loop, casts, calls, order, and all earlier corrections. The
repair is cleanup-introduced, not preexisting in the preserved baseline object.
