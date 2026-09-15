# `src/Cdaudio.cpp` cleanup report

## Delivery

- Module: `src/Cdaudio.cpp`
- Base commit from `git rev-parse`: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit from `git rev-parse`: `229d74d94d249231d25b7c35da7090ffff83861c`
- Branch: `cleanup/staging-20260915-173`
- Changed files:
  - `src/Cdaudio.cpp`
  - `decomp_notes/source_cleanup/wave03/Cdaudio.md`
- Header read but not changed: `include/cdaudio.h`

The source keeps the registry order for all 16 normal owners. The PDB source
module is `C:\\msdev\\work\\age1_x1\\Cdaudio.cpp`.

## Evidence

The source registry was read from:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/Cdaudio.cpp.json`

The procedure-scoped PDB records were read from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The registry-selected original function packets were read from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/004237C0_CCDAudio.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/004237D0_CCDAudio.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423800_Open.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423880_Close.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/004238C0_Stop.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/004238E0_Play.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423930_Pause.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423950_ResumePlay.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423980_Eject.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/004239B0_GetNumberOfTracks.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/004239F0_IsMediaPresent.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423A40_IsPlaying.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423AC0_GetLength.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423B10_GetTrackLength.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423B70_GetPosition.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423BD0_DisplayErrorMsg.txt`

The decompiler and assembly unit records were also read from:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/cdaudio.cpp.decomp`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/cdaudio.cpp.asm`

The original executable is the behavior oracle:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  - SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The preserved pre-cleanup executable is:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
  - SHA256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`

## Original-name recovery coverage

All 16 source functions were inspected in the scoped PDB records. Each
record has `this` in `ecx`. No record has a function-static symbol.

| VA | Function | PDB stack records | Source result |
| --- | --- | --- | --- |
| `004237C0` | `CCDAudio::CCDAudio` | none | No source parameter or local to rename. |
| `004237D0` | `CCDAudio::~CCDAudio` | `playing` (`int`, `-0x4`) | Preserved `playing`. |
| `00423800` | `CCDAudio::Open` | `Wnd` (`void*`, `+0x4`), `mciOpenParms` (`tagMCI_OPEN_PARMSA`, `-0x14`), `mciSetInfo` (`tagMCI_SET_PARMS`, `-0x20`) | Recovered `wnd` to `Wnd`. The two local names already matched. |
| `00423880` | `CCDAudio::Close` | none | No PDB source parameter or local name. |
| `004238C0` | `CCDAudio::Stop` | none | No PDB source parameter or local name. |
| `004238E0` | `CCDAudio::Play` | `nTrack` (`unsigned char`, `+0x4`) | Recovered `track` to `nTrack`. |
| `00423930` | `CCDAudio::Pause` | none | No PDB source parameter or local name. |
| `00423950` | `CCDAudio::ResumePlay` | none | No PDB source parameter or local name. |
| `00423980` | `CCDAudio::Eject` | none | No PDB source parameter or local name. |
| `004239B0` | `CCDAudio::GetNumberOfTracks` | `nNumTracks` (`unsigned char&`, `+0x4`), `mciStatusInfo` (`tagMCI_STATUS_PARMS`, `-0x10`) | Recovered `track_count` to `nNumTracks`. The local name already matched. |
| `004239F0` | `CCDAudio::IsMediaPresent` | `bPresent` (`int&`, `+0x4`), `mciStatusParms` (`tagMCI_STATUS_PARMS`, `-0x10`) | Recovered `present` to `bPresent`. The local name already matched. |
| `00423A40` | `CCDAudio::IsPlaying` | `bPlaying` (`int&`, `+0x4`), `mciStatusParms` (`tagMCI_STATUS_PARMS`, `-0x10`) | Recovered `playing` to `bPlaying`. The local name already matched. |
| `00423AC0` | `CCDAudio::GetLength` | `nMinutes` (`unsigned char&`, `+0x4`), `nSeconds` (`unsigned char&`, `+0x8`), `mciStatusParms` (`tagMCI_STATUS_PARMS`, `-0x10`) | Recovered `minutes` and `seconds` to `nMinutes` and `nSeconds`. The local name already matched. |
| `00423B10` | `CCDAudio::GetTrackLength` | `nTrack` (`unsigned char`, `+0x4`), `nMinutes` (`unsigned char&`, `+0x8`), `nSeconds` (`unsigned char&`, `+0xc`), `mciStatusParms` (`tagMCI_STATUS_PARMS`, `-0x10`) | Recovered `track`, `minutes`, and `seconds` to `nTrack`, `nMinutes`, and `nSeconds`. The local name already matched. |
| `00423B70` | `CCDAudio::GetPosition` | `nTrack` (`unsigned char&`, `+0x4`), `nMinutes` (`unsigned char&`, `+0x8`), `nSeconds` (`unsigned char&`, `+0xc`), `mciStatusParms` (`tagMCI_STATUS_PARMS`, `-0x10`) | Recovered `minutes`, `seconds`, and `frames` to the PDB spellings `nTrack`, `nMinutes`, and `nSeconds`. |
| `00423BD0` | `CCDAudio::DisplayErrorMsg` | `dwError` (`unsigned long`, `+0x4`), `szErrorMsg` (`char[256]`, `-0x100`) | Recovered `error` to `dwError`. The local name already matched. |

The registry marks all 16 entries as `matching`. The PDB records also show
`this` as `CCDAudio*` in `ecx` for every entry.

The PDB gives `GetPosition` the original names `nTrack`, `nMinutes`, and
`nSeconds`, even though the body extracts three packed position bytes. The
source now preserves those recovered spellings. The positional mapping is
reliable from the three `unsigned char&` records. The semantic mismatch is
not resolved by this cleanup.

The PDB has no records for the source locals `result`, `error` in `Close`,
`devID`, `track_local`, `item`, or `time`. The source leaves these descriptive
names unchanged. The Ghidra `local_4` label in `GetTrackLength` was not used to
force a stack-slot mapping. No generated local name was copied from a reused
slot.

## Constants, resources, and comments

No numeric constant changed. The MCI command, flag, status-item, and packed
value literals remain unchanged. The existing
`MCI_DEVTYPE_CD_AUDIO` expression remains unchanged.

The pinned VC5 SDK definitions used for review were read from:

- `C:/Program Files (x86)/DevStudio/VC/Include/MMSYSTEM.H`
- `C:/Program Files (x86)/DevStudio/VC/Include/WINUSER.H`

Those definitions establish the MCI command names, status items, parameter
block layouts, `MCI_DEVTYPE_CD_AUDIO`, and `MAKEINTRESOURCEA`. No replacement
was needed. This avoids changing literal types or expression evaluation.

This source has no resource lookup and no resource ID. No runtime DLL or
resource file was inspected. No resource-ID request exists.

No source comment was added. No existing source comment was changed.

## Header request and unresolved mappings

The owner of `include/cdaudio.h` may align declaration parameter names with the
PDB records without changing types or ABI symbols:

```cpp
unsigned long Open(void* Wnd);
unsigned long Play(unsigned char nTrack);
unsigned long GetNumberOfTracks(unsigned char& nNumTracks);
unsigned long IsMediaPresent(int& bPresent);
unsigned long IsPlaying(int& bPlaying);
unsigned long GetLength(unsigned char& nMinutes, unsigned char& nSeconds);
unsigned long GetTrackLength(unsigned char nTrack, unsigned char& nMinutes,
                             unsigned char& nSeconds);
unsigned long GetPosition(unsigned char& nTrack, unsigned char& nMinutes,
                          unsigned char& nSeconds);
private:
    unsigned long DisplayErrorMsg(unsigned long dwError);
```

This is a spelling-only request. It does not block the source change. No
root-owned header request exists. No type, storage, layout, scope, or call
target mapping remains unresolved beyond the `GetPosition` semantic naming
mismatch noted above.

## Code-generation risks and validation

The source edits rename recovered parameters only. They do not change types,
casts, declarations, scopes, storage, evaluation order, calls, literals,
function boundaries, layouts, relocations, or ABI symbols. The changes can
alter debug names and line records. No comments or formatting changes were
made.

The complete assigned diff was reviewed. `git diff --check` passed before the
source commit.

Compilation, matching, audits, and tests were not run. No build, compiler
check, game, or runtime harness was run.
