# `src/pathsys.cpp` cleanup report

## Delivery

- Module: `src/pathsys.cpp`
- PDB source: `C:\\msdev\\work\\age1_x1\\pathsys.cpp`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit: `d9cd60d02a02d893a4a16f65d3149f9e675428ad`
- Changed files:
  - `src/pathsys.cpp`
  - `decomp_notes/source_cleanup/wave04/pathsys.md`

The source commit changes only the assigned source. The report is the only other
assigned file. No header or registry file changed.

## PDB evidence

I inspected the procedure-scoped records in:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The extracted review copy is under:

`build/pathsys/pdb_scoped_records.txt`

Each normal procedure has a `this` register record in `ecx`. The constructor also
has a local `i`. The PDB records show reused stack homes. I did not force a name
onto a different type or declaration.

The PDB source map records these normal owners:

| VA | Procedure | PDB parameter and local coverage |
| --- | --- | --- |
| `0046B0F0` | `PathingSystem::PathingSystem` | Parameters `x`, `y`, `aiPSInit`, `map`, `world`; local `i`. Recovered all. |
| `0046B270` | `PathingSystem::~PathingSystem` | No stack locals. `this` only. Unchanged. |
| `0046B310` | `initialize` | Parameters `x`, `y`, `map`, `world`. Recovered `x` and `y`; others already matched. |
| `0046B360` | `printToFile` | Parameter `filename`. Already matched. |
| `0046B550` | `lookupMisc` | Parameters `x`, `y`. Recovered from `row`, `column`. |
| `0046B570` | `setMisc` | Parameters `x`, `y`, `v`. Recovered from `row`, `column`, `value`. |
| `0046B590` | `initMisc` | Parameter `v`. Recovered from `value`. |
| `0046B5C0` | `zeroObstructionMap` | No stack locals. `this` only. Unchanged. |
| `0046B5E0` | `obstruction` | Parameters `x`, `y`. Already matched. |
| `0046B620` | `incrementObstruction` | Parameters `x`, `y`. Already matched. |
| `0046B680` | `decrementObstruction` | Parameters `x`, `y`. Already matched. |
| `0046B6E0` | `findTilePath` | Recovered parameters `unit`, `actionRange`, `cTargetID`, `copyPathWhenDone`, `pathLength`, `checkPathingIterations`, `checkTerrainFirstTime`, `checkCollisions`, `stepSize`, `unobstructiblePlayerID`, and `unobstructibleGroupID`. Recovered local `MaxY`. Other listed locals already matched. |
| `0046D250` | `incrementInitialPaths` | No stack locals. `this` only. Unchanged. |
| `0046D260` | `incrementContinuePaths` | No stack locals. `this` only. Unchanged. |
| `0046D270` | `incrementCanPaths` | No stack locals. `this` only. Unchanged. |
| `0046D280` | `passable` | Parameters `obj`, `newX`, `newY`, `checkTerrain`. Existing names match. PDB locals `currentXOffset`, `maxY`, `maxX`, `minY`, `minX`, `inObMap`, and `yRadius` match the source. |
| `0046D740` | `checksum` | No stack locals. `this` only. Unchanged. |
| `0046D770` | `printState` | Recovered parameter `unit` from `obj`. |
| `0046D830` | `copyPath` | Recovered parameter `stepSize`, locals `temp`, `wp`, `tWX2`, `tWY2`, and `tWY1`. Existing `currentFacet`, `fooX`, `fooY`, and `objectCountOnTile` already match. |
| `0046DCB0` | `copyUnobstructibles` | Recovered parameter `d` from `out`. Local `i` already matched. |

The PDB also lists compiler-generated startup wrappers at `0046B060` and
`0046B0B0`, the scalar deleting destructor at `0046B250`, and parent-owned
fragments at `0046D202` and `0046DC8A`. No source body was added for them.

`findTilePath` has PDB locals `xDeltaRight4`, `bestPathPoint`, `xDeltaLeft4`,
`MGP_goalTolerance`, `temp`, `yRadius`, `yDeltaUp`, `numberIterationCap`,
`xDeltaLeft`, `yDeltaDown`, `xDeltaRight`, `yDeltaUp4`, `yDeltaDown4`,
`iterations`, `i`, `SkipBit`, `MaxY4`, `MaxY`, `oldTotal`,
`hitUnobstructibleObject`, `MaxX4`, `newCost`, `MinY4`, `tempPathValue`,
`newTotal`, `unobstructibleObjectHitpoints`, `MinX4`, `badCollision`, and
`objectCountOnTile`. The source already uses the listed names except for
`tempPathValue`, which has an `int` PDB type and reused homes. The source `path`
pointer cannot be mapped to it with reliable type and scope evidence. I left it
unchanged. The PDB does not provide reliable records for the remaining source
scan variables. I did not rename them by inference.

`copyPath` maps PDB locals `tWX2`, `tWY2`, and `tWY1` to the upper X bound and
the two Y bounds in the unobstructible-object scan. The lower X bound has no
PDB record, so the existing `minX` name remains. The PDB names its `BYTEPoint` type as
`PathingSystem::BYTEPoint`, while the current source has a source-local
`BYTEPoint`. This type-ownership issue predates this cleanup and remains open.

## Names and source changes

Recovered names preserve the PDB spelling, including `aiPSInit`, `cTargetID`,
`copyPathWhenDone`, `MGP_goalTolerance`, `SkipBit`, `MaxY`, `stepSize`, and `wp`.
No invented descriptive names were added. The constructor now declares the
PDB-local `i` instead of reusing the parameter name as a loop counter.

I moved function braces to 1TBS form in this source. I did not change literals,
strings, control flow, call order, casts, types, storage, or public symbols.

## Constants, resources, and comments

No resource ID or resource lookup occurs in this module. No DLL extraction was
needed. No new constant or macro was added. Existing literals and fallback paths
remain unchanged. Existing useful comments remain in place. No new comment was
needed.

## Possible effects and unresolved items

Parameter and local renames do not change ABI types, object layout, or decorated
symbols. The constructor local declaration and the `MaxY` declaration shape can
change VC5 local allocation or register scheduling. This remains unvalidated.
Brace movement can change debug line records, but the source has no `__LINE__`
use. No header layout or shared declaration changed.

The header owner is owner 24. Please review these parameter-name updates in
`include/pathsys.h`:

- Constructor: `x`, `y`, `aiPSInit`.
- `initialize`: `x`, `y`.
- `lookupMisc`: `x`, `y`.
- `setMisc`: `x`, `y`, `v`.
- `initMisc`: `v`.
- `findTilePath`: `unit`, `actionRange`, `cTargetID`, `copyPathWhenDone`,
  `pathLength`, `checkPathingIterations`, `checkTerrainFirstTime`,
  `checkCollisions`, `stepSize`, `unobstructiblePlayerID`, and
  `unobstructibleGroupID`.
- `passable`: `obj`, `newX`, `newY`, `checkTerrain`.
- `printState`: `unit`.
- `copyPath`: `stepSize`.
- `copyUnobstructibles`: `d`.

Root owns all other headers. No root shared declaration or resource mapping
request is open.

Compilation, matching, audits, and tests were not run. Builds, validation
commands, and games were also not run.
