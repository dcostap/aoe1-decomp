# `taiinfmd.cpp` source cleanup

## Delivery

- Module: `src/taiinfmd.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source candidate commit: `e3c28ca2d20c2c3947403e20aecbe31496e4b074`
- Source SHA-256 at the source candidate commit:
  `c6b9e370aac6602d688c7052afa78dd94534d754dcdd96750cadd3869867af8c`
- Changed files:
  - `src/taiinfmd.cpp`
  - `decomp_notes/source_cleanup/wave03/taiinfmd.md`

The source owner is `src/taiinfmd.cpp`. The header `include/taiinfmd.h` was read but not changed.
No other tracked file changed.

## Scope and coverage

The registry contains 121 entries for this module. This includes two constructors and one destructor.
The source contains 118 ordinary function definitions plus those three special members.
All 121 registry entries were reviewed against their scoped PDB records and original packets.
The scoped PDB evidence also contains one compiler-generated scalar-deleting destructor wrapper.
That wrapper has no handwritten source body and was not edited.

The cleanup restores supported parameter and local names. It does not change public function names,
class names, member names, layouts, calling conventions, or header declarations.

## Evidence

The review used these files and records:

- `build/taiinfmd_evidence/scoped_symbols.json`
- `build/taiinfmd_evidence/packet_index.txt`
- `build/taiinfmd_evidence/packet_paths.txt`
- `build/taiinfmd_evidence/source_defs.txt`
- `inventory/pdb/scoped_symbols.json`
- The registry `config/functions/src/taiinfmd.cpp.json`
- Original packets under `inventory/functions/004D/` and `inventory/functions/004E/`
- `decomp_notes/taiinfmd.md`
- `include/taiinfmd.h`, read-only for this assignment

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
  `newStatus`, `overlapSize`, `x`, `y`, `pattern`, `townWalls`, and `numGates`.
- Learning and resource helpers: `name`, `numToLoad`, `numMemoriesToLoad`, `requiredZone`,
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

The cleanup changes names and presentation only. It keeps expressions, casts, literal values,
statement order, calls, explicit `this->` use, and source ownership.

Names do not affect the ABI, but local declaration changes can affect VC5 register allocation,
stack allocation, or instruction selection. The highest-risk edits are the removal of redundant
file-handle aliases in `save` and the destructor, the reuse of PDB-supported temporary names in
the load constructor, the use of PDB `x` and `y` parameters as wall-scan variables, and the
separate `timeKillRatio` declaration in `objectToAttackByGroup2`. These changes require the
final generated-output comparison.

No type, structure layout, public signature, function boundary, call target, tail jump, or
assembly region was changed by this cleanup.

## Shared requests and validation status

There are no shared-file requests. The header and resource-ID owners need no changes for this
module.

Compilation, matching, audits, tests, game execution, and validation were not run.
This report is a reviewed but unvalidated cleanup record.
