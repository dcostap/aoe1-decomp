# Dsutil.c source module

- PDB source: `C:\\msdev\\work\\age1_x1\\Dsutil.c`.
- Source: `src/Dsutil.c`.
- Header: `include/dsutil.h`.
- Normal owners: 32.
- PDB order: `004477D0` through `00448BA0`.
- Owner surface: ordinary C functions for DirectSound, WinMM, RIFF, and stream helpers.
- Generated entries: none.

## Context evidence

The PDB assigns all 32 normal owners to `Dsutil.c`. Their source line bands and
address sequence increase from `ShowErrMsg` through `ds_stream_time_func`.
The source keeps this order. The module uses C mode and the reviewed
`/Oi- /TC` flags from `config/flags/00448BA0_ds_stream_time_func.rsp`.

The source keeps the proven DirectSound C-interface and WinMM call surfaces.
It uses the period SDK `MMCKINFO`, `MMIOINFO`, `PCMWAVEFORMAT`, and
`WAVEFORMATEX` declarations. The shared Dsutil header owns the stream globals.
No inline assembly, fake vtable, absolute API pointer, or wrapper owner remains.

## Recovery states

The module now keeps 26 `matching` owners and 6 `scratch` owners. The former
accepted-drift rows `00447B70`, `004481E0`, and `00448660` are scratch because
their fresh checks show structural instruction drift. The two current-main SDK
regressions, `00448250` and `00448340`, are also scratch.
These states describe source recovery. They do not claim grouped byte equality
after the source move.

The prior grouped exact owners need fresh checks against
`src/Dsutil.c`.

## Transition

The merge moves all 32 function bodies into one C source module in PDB order.
It renames `include/dsutil_context.h` to `include/dsutil.h`, removes the prefix
wrapper, and removes the 32 module-owned source-bank fragments. The translation
unit entry now points to `src/Dsutil.c` and maps each existing exact owner to
that source file. No generated owner was present.

## Validation

`build/dsutil_candidate_tu.c` includes `src/Dsutil.c` once. The pinned VC5
candidate check uses `config/flags/00448BA0_ds_stream_time_func.rsp`.

The pre-SDK candidate compiled all 32 owners. It matched 27 owners with zero
byte, relocation, and boundary differences. The 23 prior `matching` owners
were exact in that source context. The four accepted-drift owners remained
nonexact. The five scratch owners included the prior exact observations for
`00447890`, `00447A20`, `00447EF0`, and `004481A0`; `00448BA0` remained
nonexact.

The candidate report is `build/candidate_tus/dsutil_compile_std/report.txt`.

Standalone checks also report `MATCH` and `0.0000%` for `004477E0`
(`DSLoadSoundBuffer`), `00447D50` (`WaveOpenFile`), and `00448B30`
(`ds_stream_messages`). Their owners, boundaries, calls, and relocations
match the original executable.

## Review repair

The `ds_stream_time_func` source now tests `_wiWave` before each silence
`memset`. The original tests this pointer before each format-width access.
This preserves the original no-wave fault behavior. The function remains
scratch until its boundary and byte differences are recovered.

After this repair, `00448BA0` rebuilds at 1422 bytes. The original is 1332
bytes. It has 1321 strict differences (92.8973%) and a 90-byte boundary
escape. The ordered calls still differ by one `memset` call.

## Current-main SDK naturalization

The natural source now uses the period SDK declarations and the shared Dsutil
globals. The fresh grouped audit is
`build/audits/dsutil_current_main/report.txt`.

The pre-status-change audit reported 21 registered matches, four
accepted-drift observations, four unregistered grouped matches, two
registered regressions, and one boundary problem. `00448250`
(`_WaveCloseWriteFile`) differed by 160 bytes. `00448340`
(`_WaveCopyUselessChunks`) differed by two bytes. Both kept their owner
symbols, zero relocation-target mismatches, and zero boundary escapes, but
neither passed the exact gate. Their exact registrations were removed, and
both are now scratch. The natural bodies remain unchanged.

The final status review also demoted `00447B70` (`_SndObjStop`), `004481E0`
(`_WaveWriteFile`), and `00448660` (`ds_stream_init`). Their fresh checks report
high-severity structural instruction differences. Dsutil has no remaining
accepted-drift row in this source module.

The shared-worktree trial recovered `00448A60 ds_stream_pause` as an integer
function that stores and returns `1`. This preserves the return value used by
the tail-jump caller. Focused and complete-module checks report `MATCH` and
`0.0000%`. All 26 registered owners match.

## Canonical provider repair

The source no longer declares target-address API pointer views. Calls use the
period Win32 and WinMM declarations. The former `DAT_00888464` through
`DAT_008884B4` overlays now use named Dsutil globals in `include/dsutil.h`.
Their definitions are owned by `src/game_globals.cpp`.

The direct checks remain exact for `00447D50`, `00447950`, `00448040`,
`00448400`, `004484D0`, `004486F0`, and `00448B30`. Direct API declarations
change the instruction layout of `00448250` and `00448340`, while preserving
their observed API call sequence and behavior. The module needs a fresh grouped
audit after integration because the local worktree lacks the FPO reference file.
