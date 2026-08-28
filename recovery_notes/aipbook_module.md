# aipbook.cpp source reunification

## Translation-unit context

- PDB source: `C:\\msdev\\work\\age1_x1\\aipbook.cpp`.
- Normal owners: 68.
- PDB order runs from `0040E930` through `00411660`.
- The compiler-generated vector deleting destructor at `004101D0` is not a normal owner.
- `include/aipbook.h` owns the reviewed module layouts.
- `include/ai_play_phase_command.h` owns AIPlayPhaseCommand.
- `include/ai_play_phase_trigger.h` owns AIPlayPhaseTrigger.

PDB field list `0x2629` puts the command fields in `protected` access. The
owner header supplies the PDB public accessors. The module uses those accessors
outside AIPlayPhaseCommand member functions. The grouped candidate keeps all
64 registered matching owners at `MATCH`, `0.0000%`.

The trigger record is 0x14. Its PDB fields are protected. PDB nested enum
`0x262B` defines its twelve trigger values. Natural alignment supplies its
internal gaps. Aipbook consumes its public accessors.

## Status

The module keeps 64 matching owners, two scratch owners, and two accepted-drift owners.
The source now owns every normal owner in one PDB-ordered file.

`0040F530` (`AIPlay::fillGroups`) stays scratch. Its natural source keeps the shipped
22-call surface and grouping effects. The current candidate is not byte exact.
Its prior matching notes remain in the pre-migration source history.

`00410220` (`AIPlayBook::loadPlays`) stays scratch. The source keeps the two-pass parser,
array construction, `/GX` lifetime requirement, and 72 ordered calls. The current
candidate is not byte exact. The remaining drift is compiler local-home and EH shape.

`0040F9B0` (`groupGivenCommandOnPhase`) stays accepted drift. Its calls, bounds,
predicates, memory effects, and return values match. The remaining difference is
register allocation before the command scan.

`00410050` (`AIPlayStatus::copy`) stays accepted drift. The copy order and memory
effects match. The remaining difference is a seven-byte setup register-order drift.

No status changed during source reunification. The old wrapper and all 68 fragment
owners are removed. The compiler-generated destructor remains outside this module.
