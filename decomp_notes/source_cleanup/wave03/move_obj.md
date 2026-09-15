# `src/move_obj.cpp` source cleanup

## Delivery

- Module: `src/move_obj.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source cleanup commit: `819293c71043fd471befad2dbfc7d3f86395d19e`
- Source correction commit: `d9571240fb921b11820edc5d4b93203da2ba2f7d`
- Final report commit: `be26cbf860b59dc718fecb84402284206ddb67d1`
- Correction report commit: `ff6f42778162569c3559f6cf89588bfabc1c2125`
- Branch: `cleanup/staging-20260915-129`
- Changed files:
  - `src/move_obj.cpp`
  - `decomp_notes/source_cleanup/wave03/move_obj.md`

This cleanup changes only the assigned source module and this report. It does not
edit `include/move_obj.h` or any other shared file.

## Original-name recovery

The main evidence is the procedure-scoped PDB record in
`build/move_obj_pdb_all.json`. The records match the functions by symbol and VA.
The original packets under `inventory/functions/0045/` and
`inventory/functions/0046/` confirm the related call and local-use context.
The declarations and types were checked against `include/move_obj.h`.

Recovered PDB parameter and local names include:

- Constructors and setup/save paths: `tobj`, `obj_owner`, `do_setup`, `infile`,
  `gworld`, `numberOfWaypoints`, `temp`, `currentWaypoint`, and `outfile`.
- Object and angle paths: `nsprite`, `obj`, `to_object`, `world_time`,
  `angle_delta`, `d`, `x`, `y`, `z`, `new_angle`, `gX`, `gY`, `gZ`, `r`,
  `tid`, and `w`.
- Path queries: `p`, `aRange`, `targetID`, `targetID2`, `pathDistance`,
  `aiCheck`, `unobstructiblePlayerID`, `unobstructibleGroupID`, `initialZone`,
  `zoneMap`, `obstructions`, `eTerrain1`, `eTerrain2`, and `eTerrain`.
- Line and waypoint helpers: `s`, `d`, `range`, `rPoint`, `tType1`, `tType2`,
  `checkPassability`, `xTile`, `yTile`, `priorY`, `sX`, `sY`, `dX`, `dY`,
  `v`, `stopObject`, `goalPoint`, `min`, `max`, and `source2`.
- Geometry helpers: `x`, `numFacets`, `bestFacet`, `bestDifference`, `amount`,
  `angle2`, and the `tempZ` local in `doTrivialMove`.

The PDB gives `radiusDistance` for the radius-derived distance in `doMove`.
The source now uses that name instead of the prior descriptive substitute
`distanceToWaypoint`.

`doMove` has two unresolved PDB names. `goalDX` and `fudgeFactor` share stack
slots with other source variables in the PDB records. The current recovered
source reuses `dX` and `newDY` across those scopes. This cleanup does not add
new declarations or force an ambiguous mapping.

`tile_x` and `tile_y` are new cleanup names. The PDB records the related float
locals as `xTile` and `yTile`, but it does not record names for these integer
casts. Their names describe the existing integer tile values.

No public function, class, member, type, or ABI symbol was renamed. Parameter
names changed only in definitions owned by this source module.

## Comments and evidence

No constants or resource IDs were added. No shared declaration request is
needed.

Two sparse `//! @bug` comments record behavior proven by original packets:

- `teleport` at VA `0045D3D0` adds `trail_remainder` again when the trail count
  is nonpositive.
- `findFirstTerrainAlongExceptionPath` at VA `00460210` stores the x-derived
  result through both output pointers. The packet shows both stores at
  `0046038D` and `0046039E`.

The comments do not change either behavior.

The correction restores four accurate evidence notes from the base source:

- The direct `new_angle` assignment preserves its bit-copy store and direct
  symbol.
- The `findPath` constant guard and unreachable cleanup arm remain in the
  executable.
- The natural `findTilePath` casts preserve the `__ftol` x87 `ST0` input.
- The floor results are cast before subtracting the float tile bias.

The original packets and PDB evidence support these constraints.

## Code-generation and ownership notes

The cleanup changes local and parameter identifiers, comments, whitespace,
blank lines, indentation, and brace placement. It does not change types,
initialization points, storage duration, statement order, expressions, calls,
lengths, constants, or control-flow structure. It does not change source
ownership or public declarations.

Debug line records can change because comments and formatting changed. This
was not checked during this assignment.

## Validation limits

`git diff --check` ran after the source review. No build or compiler check ran.
No matching check, audit, test, or game ran. Byte equality and semantic approval
remain unvalidated until the final wave validation stage.
