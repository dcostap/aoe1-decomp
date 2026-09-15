# `taibldmd.cpp` cleanup report

## Delivery

- Module: `src/taibldmd.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source cleanup commit: `67db444c5c8c35c1e93b85efbd0ee366562547e7`
- Report commit: follow-up commit after this report
- Branch: `cleanup/staging-20260915-114`
- Changed files: `src/taibldmd.cpp` and this report

The source owner remains `src/taibldmd.cpp`. The header owner remains
`include/taibldmd.h`. This cleanup did not edit the header or any other source
file.

The cleanup covers all 27 source procedures in the registry. It keeps the
existing function order and public ABI names.

## Changes

The source now uses names from the procedure-scoped PDB. This includes names
that were already readable but did not match the PDB. The source also uses
1TBS braces and `} else {` placement throughout the module.

The cleanup restores these PDB names:

- Constructors: `pW`, `pID`, and `infile`.
- `setMainDecisionAI`: `m`.
- `loadBuildList`: `lName` and `player`.
- `initialize`: `bronzeAgeIndex`, `transportCount`, `toolAgeIndex`,
  `fishingBoatCount`, `resourceCount`, `warshipCount`, `triremeUpgrade`,
  `warshipUpgrade`, `transportUpgrade`, `ironAgeIndex`, `houseCount`,
  `requiredPop`, `divisionSize`, and `dockCount`.
- `nextBuildableItem`: `category`, `numStoragePits`, `numGranaries`,
  `numHouses`, `count`, `realCount`, and `itemCost`.
- `blockingResource`: `itemCost`.
- `mostNeededResource`: `itemCost`, `countNum`, and `count`.
- `addItem`: `newItem` and `gameStarted`.
- `addBuiltItem`: `newItem` and `buildID`.
- `removeBuiltItem`: `id`.
- `cancelBuildItem`: `reason`, `blockerID`, `blockerType`, `x`, `y`,
  `uniqueID`, `builderID`, `newLotStatus`, and `decrementWallBuild`.
- Training and research callbacks: `uType`, `rType`, `location`, `uniqueID`,
  `gameID`, and `reason`.
- `isAgeResearch`: `rID`.
- Insertion helpers: `typeID`, `buildCap`, `insertionPoint`, `buildCategory`,
  `rType`, and `percentage`.
- `numberBuiltOrInProgressItemsOfType`: `type` and `category`.
- `allBuilt`: `category1` and `category2`.
- `readyToResearch`: `id`, `ageResearch`, and `rState`.
- `unskipBuildList`: `builtSP` and `builtG`.
- `buildItem`: `typeID`, `category1`, and `category2`.

The PDB records no stack names for the destructor, `skipNextBuildListItem`, or
`nextBuildListItemCategory`. Their existing local names remain unchanged.

## Evidence

The primary name source is `inventory/pdb/scoped_symbols.json`. Its SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The PDB source path is `C:\\msdev\\work\\age1_x1\\taibldmd.cpp`, and the module
object is `.\\Release\\taibldmd.obj`.

The scoped records cover the constructors at `004D3A80` and `004D3AD0`, the
complete `initialize` procedure at `004D3D60`, and the remaining procedures
through `004D5DE0`. They record `this` in `ECX` for each procedure.

The main behavior packets were also reviewed:

- `inventory/functions/004D/004D3D60_initialize.txt`
- `inventory/functions/004D/004D4540_nextBuildableItem.txt`
- `inventory/functions/004D/004D4F80_mostNeededResource.txt`
- `inventory/functions/004D/004D5310_cancelBuildItem.txt`
- `inventory/functions/004D/004D5D40_unskipBuildList.txt`

These packets confirm the source boundaries, call order, constants, and local
uses. The original executable remains the behavior oracle.

`initialize` needs special care. The PDB reports reused stack homes. It records
these aliases: `triremeUpgrade` with `count`, `warshipUpgrade` with
`divisionSize`, `transportUpgrade` with `totalPercentage`, and `houseCount`
with `requiredPop`. The source keeps separate declarations and scopes where the
current source already separates their lifetimes.

The source keeps `trainedCount`, `itemCount`, `buildIndex`, `spacing`, and
`index` as descriptive names. The PDB and assembly do not prove separate
original declarations for every one of these names. No additional stack-slot
mapping was forced. The scalar `resource_building_count` is a new descriptive
name. It has no direct PDB name because the PDB `resourceCount` record belongs
to the later `ResourceItem` object.

The source keeps `val` in the two cancellation log functions. The PDB has no
local name there, and the pointer chain does not prove a better source name.
The source also keeps `first_category` and `second_category` in `allBuilt`.
These are new descriptive names for the former generated temporaries.

The `unskipBuildList` locals now use `storage_pit_count` and `granary_count`.
The PDB names only its unused parameters, `builtSP` and `builtG`. The local
names describe the two counted object types without changing their calls.

## Constants, resources, and comments

No numeric constant, type, cast, call target, or resource lookup changed. No
new constant or enum was added.

This module has no resource lookup. No resource ID mapping or resource header
request applies.

The source comment before the first constructor now states file ownership:
`This file owns the TribeBuildAIModule virtual surface.` It replaces a malformed
ownership note. The source owner and registry provide the supporting evidence.
No behavior claim was added to the source.

## Code generation and scope review

The source changes names, whitespace, line wrapping, and brace placement only.
They do not change types, declaration order, declaration scope, storage
duration, evaluation order, control flow, casts, calls, literals, function
boundaries, layout, relocations, or ABI symbols.

The reused `initialize` stack homes remain represented by separate source
variables where the current source has separate lifetimes. No helper, wrapper,
inline assembly, structural rewrite, or header edit was added.

## Validation

Evidence inspection, targeted searches, Git diff review, and `git diff --check`
were run. No compiler or build command was run.

Compilation, matching, audits, and tests were not run.
