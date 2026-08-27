# Sound.cpp source module

`src/Sound.cpp` owns all 14 PDB functions in source order. `include/sound.h`
owns only RGE_Sound and RGE_Sound_Info. Runtime helpers and globals stay in
the source file.

RGE_Sound has size `0x10`. RGE_Sound_Info has size `0x24`. The public
`play(int)` declaration is `004BC310` with symbol
`?play@RGE_Sound@@QAEXH@Z`.

The grouped candidate has 11 exact owners. All report `MATCH` and `0.0000%`.
It has no comparison errors.

`004BBF30` remains verified logic with a 191-byte mismatch.
`004BC270` remains accepted drift with a 93-byte mismatch.
`004BC310` remains verified logic with a 21-byte mismatch.

The owner-only play declaration unblocks callers that need the Sound ABI.
