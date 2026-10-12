# `src/aipbook.cpp` source cleanup

## Delivery

- Module: `src/aipbook.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Previous source cleanup commit: `17f69a5f24484a751c3f65c0f0c07304b6f22414`
- Final source commit: `d2ca85e3a874c30129877eaa447c9946a089a218`
- VC5 loop repair commit: `c5ca8470790c070d29a0fe706aa07ce478b39add`
- The final delivery commit adds this hash correction to the report.
- Changed files:
  - `src/aipbook.cpp`
  - `workflow/decomp_notes/source_cleanup/wave03/aipbook.md`
- Header changes: none

## Correction history

- Follow-up correction applied 2026-09-15: formatted `src/aipbook.cpp` in 1TBS style.
- Joined braced parser branches to `} else {` and corrected the over-indented grouping call.
- Preserved braces, scopes, statements, names, calls, and expressions.
- Reviewed the Git diff and ran `git diff --check` only.

## Post-cleanup validation repair

The fresh main build report is:
`C:/Projects/my_decomps/aoe1_attempt3/build/executable/user/20260915T215425319815Z/20260915T215425568371Z/report.json`.
It records this exact error for `src/aipbook.cpp`:

```text
C:\Projects\my_decomps\aoe1_attempt3\src\aipbook.cpp(1142) : error C2374: 'j' : redefinition; multiple initialization
```

The preserved pre-cleanup source is commit `6d46835cdc6e31ba879a2e6e31415327a7c7e341`.
It uses distinct `iGroups` and `iPhases` counters for the two loops.
The scoped PDB and `00410220_loadPlays` packet show reused local homes for these loops.
VC5 gives for-loop declarations function scope in this case.

The repair restores `iGroups` and `iPhases` in `loadPlays`.
It changes no types, storage, scopes, braces, control flow, statement order, calls, or expressions.

This repair keeps the failed build outputs and history.
Root must repeat final build, matching, audit, test, and runtime checks.

## Scope and evidence

This review covers all 68 normal owners in the module registry, from `0040E930` through `00411660`.
The registry is `config/functions/src/aipbook.cpp.json`.

The main name evidence is the exact `aipbook.obj` subset in `build/evidence/aipbook-pdb-scoped.json`.
The review also used the selected packets in `inventory/functions/0040/` and `inventory/functions/0041/`.
The original source path in those records is `C:\msdev\work\age1_x1\aipbook.cpp`.

The legacy module note marks `AIPlay::fillGroups` and `AIPlayBook::loadPlays` as scratch owners.
It marks `AIPlayStatus::copy` as accepted drift.
No status or registry file changed in this cleanup.

## Name recovery

The following parameter names match the scoped PDB records:

- `AIPlayPhaseCommand` constructors: `g`, `t`, `v1`, `v2`, `v3`.
- `AIPlayPhaseCommand::convertToIntType` and `convertToNameType`: `t`.
- `AIPlayPhaseTrigger` constructors: `t`, `v1`, `v2`, `p`, `n`, `r`.
- `AIPlayPhaseTrigger::convertToIntType` and `convertToNameType`: `t`.
- `AIPlayPhase::command` and `trigger`: `v`.
- `AIPlayPhase::addCommand` and `addTrigger`: `c` and `t`.
- `AIPlayGroup::minimum`, `setMinimum`, `maximum`, and `setMaximum`: `n`, with `v` for the setter value.
- `AIPlay::setName`: `n`.
- `AIPlay` target accessors and mutators: `n` and `v` as recorded.
- `AIPlay::gatherTolerance`: `groupID` and `phaseID`.
- `AIPlay::group`, `phase`, and `fillGroups`: `n`; `n`; and `playStatus`, `groupMembers`, `numberGroupMembers`, `world`.
- `AIPlay::groupGivenCommandOnPhase`: `gID`, `cType`, `pID`.
- `AIPlay` conversion methods: `t`.
- `AIPlay::locationsOnMap`: `targetX`, `targetY`, `mapXSize`, `mapYSize`.
- `AIPlayStatus::originalHitPoints` and `setOriginalHitPoints`: `n`, with `v` for the setter value.
- `AIPlayStatus::numberInGroup`: `n`.
- `AIPlayStatus::numberOfTypeInGroup`: `n`, `type`.
- `AIPlayStatus::group`, `addGrouping`, and `removeGrouping`: `uID`; `uID`, `gID`, `type`; and `uID`.
- `AIPlayStatus::copyUnits`: `array`, `count`.
- `AIPlayStatus::load` and `save`: `infile`, `outfile`, and `tempInt`.
- `AIPlayStatus::copy`: `ps`.
- `AIPlayStatus::removeDeadUnits` and `resetHitPoints`: `gID`, `world`.
- `AIPlayBook::loadPlays`: `filename`.
- `AIPlayBook::play` and `playNumber`: `n` for the index overload, and `name` for name lookups.
- `AIPlayBook` conversion methods: `t`; `obj` for `convertUnitToIntType`.

`loadPlays` also uses the scoped names that have clear type and lifetime matches:
`temp`, `fileIn`, `temp2`, `temp3`, `temp4`, `temp5`, `temp6`, `temp7`, `temp8`,
`commentTemp1`, `commentTemp2`, `command`, `trigger`, `i`, `a`, `refGroup`,
`curGroup`, `refPhase`, and `curPhase`.
The command-copy loop uses the PDB name `a`.
Scoped PDB reuse cannot produce two VC5 loop declarations with the name `j`.
The repair restores baseline names `iGroups` and `iPhases` for the group and phase loops.
These are restored baseline names, not uniquely mapped PDB names.
The outer play index remains `currentPlay`.

The PDB has overlapping stack homes for several `loadPlays` locals.
It reports duplicate `trigger` records and reuses homes between integer counters and object pointers.
The source keeps separate declarations and scopes instead of forcing names across those overlaps.
The `fillGroups` packet has similar reused homes for `group`, `a`, `rVal`, `i`, and `j`.
Its existing descriptive locals remain where the packet does not prove a declaration mapping.

## Symbolic constants

The source now uses existing declarations from the unassigned headers:

- `AIPlayPhaseCommand::{InvalidCommand,MoveCommand,...}` for command states.
- `AIPlayPhaseTrigger::{InvalidTrigger,GatherTrigger,...}` for trigger states.
- `AIPlayPhase::{MaxCommands,MaxTriggers}` for phase array bounds.
- `AIPlayGroup::{MaxUnitTypes,InvalidGroup}` for group type bounds and the `0xFF` sentinel.

These declarations preserve the original values and effective integer conversions.
No new resource IDs or resource names were added.
No resource lookup call changed.

## Behavior and output limits

The cleanup changes identifier spelling and existing enum-symbol spelling only.
It does not change parameter types, member layout, storage duration, call order, literals, casts, or ABI symbols.
The parser keeps its two passes, array allocation, play-variant expansion, and trigger and command copy order.
The source keeps the known scratch and accepted-drift areas unchanged in structure.

Compilation, matching, audits, and tests were not run, as required for this cleanup stage.
Byte equality and generated-output preservation remain unvalidated until final wave validation.

## Open questions

- Reused optimized stack homes in `fillGroups` and `loadPlays` prevent a complete local declaration mapping.
- The PDB does not prove names for several descriptive locals that predate this cleanup.
- No shared-file change request is required. The used constants already exist in reviewed headers.
