# Source cleanup: `src/Dsutil.c`

## Handoff

- Module: `src/Dsutil.c`.
- Header owner: `include/dsutil.h` (Owner 20). I read it but did not edit it.
- Branch: `cleanup/staging-20260915-177`.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final source commit: `3ca1b0b561f6e2ae03a0598a16136369b370f220`.
- Changed files:
  - `src/Dsutil.c`
  - `decomp_notes/source_cleanup/wave03/Dsutil.md`

The source commit changes only the assigned source. The report commit changes
only this assigned report.

## Scope and evidence

I read `AGENTS.md`, `docs/source_cleanup.md`, `docs/source_comments.md`,
`docs/resource_ids.md`, `docs/source_cleanup_owners.md`, `docs/testing.md`,
and `decomp_notes/source_cleanup/wave03_assignments.md`.

I inspected the assigned registry at
`C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/Dsutil.c.json`.
The registry selects 33 procedures in `Dsutil.obj`. I inspected every selected
packet under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/` and every
procedure-scoped PDB record in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.

The PDB source path is `C:\msdev\work\age1_x1\Dsutil.c`. The PDB used for
cross-checking is
`C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`, SHA-256
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
The packet set is:

`004477D0_ShowErrMsg.txt`, `004477E0_DSLoadSoundBuffer.txt`,
`00447890_DSReloadSoundBuffer.txt`, `004478F0_DSGetWaveResource.txt`,
`00447950_SndObjCreate.txt`, `00447A20_SndObjDestroy.txt`,
`00447A60_SndObjGetFreeBuffer.txt`, `00447B20_SndObjPlay.txt`,
`00447B70_SndObjStop.txt`, `00447BC0_DSFillSoundBuffer.txt`,
`00447C60_DSParseWaveResource.txt`, `00447D50_WaveOpenFile.txt`,
`00447EF0_WaveStartDataRead.txt`, `00447F40_WaveReadFile.txt`,
`00448040_WaveCloseReadFile.txt`, `00448080_WaveCreateFile.txt`,
`004481A0_WaveStartDataWrite.txt`, `004481E0_WaveWriteFile.txt`,
`00448250_WaveCloseWriteFile.txt`, `00448340_WaveCopyUselessChunks.txt`,
`00448400_riffCopyChunk.txt`, `004484D0_WaveLoadFile.txt`,
`004485C0_WaveSaveFile.txt`, `00448660_ds_stream_init.txt`,
`004486B0_ds_stream_exit.txt`, `004486F0_ds_stream_file.txt`,
`00448A40_ds_stream_volume.txt`, `00448A60_ds_stream_pause.txt`,
`00448A70_ds_stream_resume.txt`, `00448A80_ds_stream_stop.txt`,
`00448B30_ds_stream_messages.txt`, and `00448BA0_ds_stream_time_func.txt`.

The original executable is
`C:/Projects/my_decomps/aoe1_attempt3/orig/_original_empiresx_from_beta_that_was_decompiled.exe`,
SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved pre-cleanup object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/Dsutil.obj`,
SHA-256 `039761a0c260801246def4cae2a4706272507590fa653aa5c66a70f5f9a86fef`.
The executable remains the behavior oracle. I did not execute it.

## Cleanup result

The source restores procedure-scoped PDB names where the current declaration
has a reliable mapping. It also applies 1TBS opening-brace placement to the
module's function definitions. It keeps types, declaration scope, storage,
statements, expression order, casts, calls, literals, function boundaries,
layouts, and public symbols unchanged.

No new helper, declaration, local variable, constant, resource macro, or
source comment was added.

## Function-by-function PDB coverage

All 33 records are in module object path `.\Release\Dsutil.obj`. The PDB has no
register-symbol record for any assigned procedure. The only function static is
`bInTimer`, an `int` at `0062E658`, for `00448BA0 ds_stream_time_func`.

| VA | Registry status | PDB names and source result |
| --- | --- | --- |
| `004477D0` | `matching` | PDB parameters are `msg` and `errcode`. The current empty definition has no parameter declarations, so it remains unchanged. |
| `004477E0` | `matching` | Renamed parameters `ds` -> `pDS` and `name` -> `lpName`. PDB locals `pDSB`, `dsBD`, and `pbWaveData` already match the source. |
| `00447890` | `matching` | Renamed `buffer` -> `pDSB`, `param2` -> `lpName`, `param3` -> `cbWaveSize`, and `local_4` -> `pbWaveData`. The current `int` and `void*` declarations remain unchanged. |
| `004478F0` | `matching` | Renamed output parameters `out1` -> `ppWaveHeader`, `out2` -> `ppbWaveData`, and `out3` -> `pcbWaveSize`. PDB parameters `hModule` and `lpName` already match. |
| `00447950` | `matching` | Renamed `count` -> `iConcurrent`. PDB parameters `pDS` and `lpName`, and locals `pbData`, `pWaveHeader`, and `cbData`, already match. |
| `00447A20` | `matching` | Renamed `obj` -> `pSO`. No other reliable local mapping was available. |
| `00447A60` | `matching` | Renamed `obj` -> `pSO` and `status` -> `dwStatus`. The PDB does not provide reliable names for `buf` or `hr`. |
| `00447B20` | `matching` | Renamed `sndobj` -> `pSO` and `flags` -> `dwPlayFlags`. `result`, `buffer`, and `hr` remain inferred locals without scoped PDB records. |
| `00447B70` | `matching` | Renamed `obj` -> `pSO`. The loop local `i` has no scoped PDB record. |
| `00447BC0` | `matching` | Renamed `dsb` -> `pDSB`, `data` -> `pbWaveData`, `size` -> `cbWaveSize`, `ptr1` -> `pMem1`, `size1` -> `dwSize1`, `ptr2` -> `pMem2`, and `size2` -> `dwSize2`. PDB names `pMem2` and `dwSize2` use the recorded stack slots without changing declarations. |
| `00447C60` | `matching` | PDB parameters `pvRes`, `ppWaveHeader`, `ppbData`, and `pdwDataSize` already match. Its cursor locals have no reliable scoped names and remain unchanged. |
| `00447D50` | `matching` | PDB parameters `pszFileName`, `phmmioIn`, `ppwfxInfo`, and `pckInRIFF`, plus locals `cbExtraAlloc`, `pcmWaveFormat`, and `ckIn`, already match. Other locals remain unchanged. |
| `00447EF0` | `matching` | Renamed `handle_ptr` -> `phmmioIn`, `buffer` -> `pckIn`, and `wave_info` -> `pckInRIFF`. |
| `00447F40` | `matching` | Renamed `hmmio` -> `hmmioIn`. PDB parameters `cbRead`, `pbDest`, `pckIn`, and `cbActualRead`, and local `mmioinfoIn`, already match. Other local names remain without forced mappings. |
| `00448040` | `matching` | Renamed `hmmio` -> `phmmio` and `pwav` -> `ppwfxSrc`. |
| `00448080` | `matching` | PDB parameters `pszFileName`, `phmmioOut`, `pwfxDest`, `pckOut`, and `pckOutRIFF`, and locals `ckOut1` and `dwFactChunk`, already match. |
| `004481A0` | `matching` | Renamed `hmmioPtr` -> `phmmioOut`, `ckOut` -> `pckOut`, and `mmioinfoOut` -> `pmmioinfoOut`. |
| `004481E0` | `matching` | Renamed `hmmio` -> `hmmioOut`, `cBytes` -> `cbWrite`, and `lpSrc` -> `pbSrc`; renamed `lpmmio` -> `pmmioinfoOut`. PDB parameters `pckOut` and `pdwWritten` already match. |
| `00448250` | `matching` | PDB parameters `phmmioOut`, `pckOut`, `pckOutRIFF`, `pmmioinfoOut`, and `cSamples` already match. |
| `00448340` | `matching` | Renamed the four existing parameters `hmmio` -> `phmmioIn`, `ck` -> `pckIn`, `parent` -> `pckInRiff`, and `src` -> `phmmioOut`. The PDB also records omitted parameters `pckOut` and `pckOutRiff`; the current four-parameter declaration remains unchanged. |
| `00448400` | `matching` | PDB parameters `hmmioSrc`, `hmmioDst`, and `pckIn`, and local `ck`, already match. The `data` local has no scoped PDB record. |
| `004484D0` | `matching` | Renamed `pcbWaveSize` -> `cbSize`, `pcbHeaderSize` -> `pcSamples`, `ppWaveHeader` -> `ppwfxInfo`, and `ppbWaveData` -> `ppbData`. PDB locals `hmmioIn`, `ckInRiff`, `ckIn`, and `cbActualRead` already match. |
| `004485C0` | `matching` | Renamed parameters `param_1` -> `pszFileName`, `param_2` -> `cbSize`, `param_3` -> `cSamples`, `param_4` -> `pwfxDest`, and `param_5` -> `pbData`. The PDB locals `hmmioOut`, `cbActualWrite`, `ckOut`, `ckOutRIFF`, and `mmioinfoOut` are represented by the existing aggregate `l` and its fields. |
| `00448660` | `accepted_drift` | PDB parameters `hWnd`, `lpd`, and `lpb` already match. |
| `004486B0` | `matching` | No parameters or locals are recorded. No source name change was needed. |
| `004486F0` | `matching` | Renamed `filename` -> `szName`, `param_2` -> `bLoop`, and `param_3` -> `Volume`. PDB locals `lpWrite1`, `dwLen2`, `lpWrite2`, `dsbd`, `uChkErr`, and `dwLen1` already match. |
| `00448A40` | `matching` | Renamed `volume` -> `val`. |
| `00448A60` | `matching` | No parameters or locals are recorded. No source name change was needed. |
| `00448A70` | `matching` | No parameters or locals are recorded. No source name change was needed. |
| `00448A80` | `matching` | No parameters or locals are recorded. No source name change was needed. |
| `00448B30` | `matching` | Renamed existing parameters `a1` -> `hWnd` and `a2` -> `wMsg`. The PDB also records omitted parameters `wParam` and `lParam`; the current two-parameter declaration remains unchanged. Current progress locals have no reliable scoped names. |
| `00448BA0` | `new_verified_logic` | PDB parameters `uTimerID`, `uMsg`, `dwUser`, `dw1`, and `dw2`, the static `bInTimer`, and locals `lpWrite1`, `dwLen2`, `dwPlay`, `lpWrite2`, `dwWrite`, `uChkErr`, and `dwLen1` already match. `playDistance`, `lpWriteCursor`, and `stream` have no scoped PDB records and remain unchanged. |

The table records every PDB parameter, local, static, and register result
needed for this source. I did not force names onto unlisted optimized locals or
onto reused stack slots.

## Recovered names and unresolved mappings

Every renamed identifier in the source is a recovered original spelling from
the procedure-scoped PDB. This includes mixed-style names such as `pDSB`,
`pSO`, `iConcurrent`, `pMem1`, `dwSize1`, `phmmioIn`, `pmmioinfoOut`, `szName`,
and `Volume`. No new descriptive name was invented.

The source keeps the existing inferred names when no scoped PDB record proves a
mapping. This includes `result`, `hr`, `obj`, `buf`, `i`, `pdw`, `dwRiff`,
`dwLength`, `dwType`, `pdwEnd`, `nError`, `cT`, `cbDataIn`, `cbDataToCopy`,
`err`, `stream`, `playDistance`, and `lpWriteCursor`. It also keeps the
aggregate `l` and its `pad` field in `WaveSaveFile`; the PDB does not record
those source-level aggregate names.

Three current declarations omit PDB-recorded parameters: `ShowErrMsg` omits
`msg` and `errcode`; `WaveCopyUselessChunks` omits `pckOut` and `pckOutRiff`;
and `ds_stream_messages` omits `wParam` and `lParam`. I did not add them in a
name-and-presentation pass. `DSReloadSoundBuffer` also retains its current
`int lpName`, `void* cbWaveSize`, and `int pbWaveData` declarations despite
PDB type records that differ. This preserves the current source types, casts,
stack-slot reuse, and generated-code risk profile.

## Constants, resources, comments, and headers

I read the relevant pinned VC5 definitions in:

- `C:/Program Files (x86)/DevStudio/VC/Include/DSOUND.H` for
  `DSBUFFERDESC`, `DSBPLAY_LOOPING`, status flags, and buffer capability flags.
- `C:/Program Files (x86)/DevStudio/VC/Include/MMSYSTEM.H` for
  `WAVE_FORMAT_PCM`, timer flags, and MMIO flags such as `MMIO_DIRTY` and
  `MMIO_WRITE`.
- `C:/Program Files (x86)/DevStudio/VC/Include/WINUSER.H` for USER APIs.

The source already uses `WAVE_FORMAT_PCM`, `MMIO_DIRTY`, and `MMIO_WRITE`.
No new constant mapping was proved. DirectSound masks, RIFF chunk values,
stream messages, timer values, and error values remain numeric. No constant was
added, removed, or replaced.

`DSGetWaveResource` reads binary wave resources through `FindResourceA`,
`LoadResource`, and `LockResource`. It has no `RT_STRING` lookup and passes no
string-table ID. This source therefore needs no resource extraction and no
request to `include/resource_ids.h`. No runtime DLL or resource hash applies.

No source comment was added, removed, or rewritten. No header or shared-file
request is needed. Header declaration parameter names can remain separate from
these source names because this cleanup did not change a function type or ABI.

## Code-generation and identity risk

The source changes rename identifiers and move existing function opening braces
to 1TBS placement. They do not change a type, declaration scope, storage
duration, initializer, statement, expression, cast, call target, literal,
function boundary, public symbol, layout, or calling convention. The registry
status and function identity remain unchanged.

Identifier names can change debug records. Brace placement can change source
line records. The PDB-backed omitted parameters and the `DSReloadSoundBuffer`
stack-slot/type mismatch remain unresolved. Generated code, program data,
relocations, call targets, and runtime behavior are not validated by this
commit.

## Validation

I reviewed the complete Git diff against base and checked the assigned paths.
I ran `git diff --check`. I did not run a compiler, build, matching check,
audit, test, or game.

Compilation, matching, audits, and tests were not run.
