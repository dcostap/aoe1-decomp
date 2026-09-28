# Sound.cpp source module

`src/Sound.cpp` owns all 14 PDB functions in source order. `include/sound.h`
owns only RGE_Sound and RGE_Sound_Info. Runtime helpers and globals stay in
the source file.

RGE_Sound has size `0x10`. RGE_Sound_Info has size `0x24`. The public
`play(int)` declaration is `004BC310` with symbol
`?play@RGE_Sound@@QAEXH@Z`.

The final sound audit reports 13 exact functions and one exact candidate.
`004BC270` remains registered as accepted drift. Its exact candidate awaits review.
The audit reports no compile errors or exact-function regressions.
See `decomp_notes/functions/004B/004BC270.md` for behavior and byte evidence.
The audit report is `build/drift-073-Sound/final-audit-20260928T2229/report.txt`.

The owner-only play declaration unblocks callers that need the Sound ABI.
