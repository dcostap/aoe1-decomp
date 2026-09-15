# `taitacmd.cpp` source cleanup

## Scope

- Edited `src/taitacmd.cpp` only.
- Added this report.
- Did not edit `include/taitacmd.h`.

## Evidence

- Used `build/taitacmd-evidence/pdb_scoped_summary.txt`.
- Used the scoped PDB records for `TacticalAIGroup` and `TribeTacticalAIModule`.
- Used the assigned original function packets and original assembly notes.
- Used the source ownership and cleanup guides.

## Changes

- Recovered PDB names for serialization handles, module parameters, task parameters, and group parameters.
- Recovered names for coordinates, ranges, IDs, priorities, targets, and task flags.
- Recovered names for tactical task locals, including `oHP`, `distance`, `gatherRange`, `commanderObj`, and `targetObj`.
- Recovered names in notification, task dispatch, group, gatherer, and water-task helpers.
- Kept types, calls, casts, control flow, evaluation order, and storage patterns unchanged.

## Review and validation

- Reviewed the full source diff.
- No build ran.
- No matching check ran.
- No audit ran.
- No test ran, as the assignment required.
