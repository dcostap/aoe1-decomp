# `com_serv.cpp` source-cleanup report

## Commits and scope

- Module: `src/com_serv.cpp`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `d5b80fde34c8c9df93ab2d71497a4831d607b560`
- Changed files: `src/com_serv.cpp`; this report.
- Header request only: `include/com_serv.h` remains unchanged.
- Registry: `config/functions/src/com_serv.cpp.json`, build flags `default`.
- Assigned registry functions: `00431FB0`, `00432030`, `00432040`, `00432050`, `00432060`, `00432080`, `004320C0`, `004320F0`, `00432120`, `00432150`, and `00432180`.

The branch is `cleanup/staging-20260915-105`. The worktree was clean at the base commit. Evidence uses the absolute shared paths below:

- Registry: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/com_serv.cpp.json`
- Scoped PDB records: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
  (SHA-256 `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`)
- Function packets: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00431FB0_TCommunications_Services.txt` through `00432180_DPEnumCallback.txt`
- Original executable: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  (SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`)

## Original-name recovery

All 11 assigned procedures were inspected. The PDB gives `this` in `ecx` for each member function. The source changes restore every source-level parameter name that has a direct scoped PDB record.

- `00431FB0` constructor: PDB records only `this`. No source parameter or local name was available.
- `00432030` destructor: PDB records only `this`. No source parameter or local name was available.
- `00432040`, `GetServiceCount`: PDB records only `this`.
- `00432050`, `IncServiceCount`: PDB records only `this`.
- `00432060`, `GetServiceName`: restored `index` to `id` from the PDB stack record at `+0x4`.
- `00432080`, `SetServiceName`: restored `serviceIndex` to `id` and `name` to `Text` from PDB stack records at `+0x4` and `+0x8`.
- `004320C0`, `GetServiceGUID`: restored `index` to `id` from the PDB stack record at `+0x8`. The hidden return-storage record `__$ReturnUdt` at `+0x4` is compiler ABI storage and has no source declaration.
- `004320F0`, `EnumServiceGUID`: restored `index` to `id` and `guid` to `gid` from PDB stack records at `+0x4` and `+0x8`.
- `00432120`, `GetServiceActive`: restored `index` to `id` from the PDB stack record at `+0x4`.
- `00432150`, `SetServiceActive`: restored `index` to `id` and `active` to `state` from PDB stack records at `+0x4` and `+0x8`.
- `00432180`, `DPEnumCallback`: restored `guid` to `pid`, `name` to `szName`, `flags` to `major_ver`, `reserved` to `minor_ver`, and `context` to `lpx` from PDB stack records at `+0x4`, `+0x8`, `+0xc`, `+0x10`, and `+0x14`. The PDB `IDirectPlay*` record named `lpIDC` maps to the local DirectPlay output pointer used by `DirectPlayCreate` and `Release`, so `directPlay` was restored to `lpIDC`.

The PDB records use mixed spelling and case. The source preserves that spelling, including `Text`, `szName`, `major_ver`, `minor_ver`, `lpx`, and `lpIDC`. The callback's unused parameters remain declared. No type, declaration order, scope, storage duration, expression order, call, literal, or control-flow change was made.

## Locals and unresolved mappings

The PDB has no standalone local record for the constructor loop variable `i` or for the callback locals `services`, `count`, and `result`. These existing concise names remain unchanged. The scoped `lpIDC` record supplies the local name for the DirectPlay output pointer. No uncertain source declaration was forced from a reused compiler stack slot.

The function packets show the original call targets and boundaries for all assigned functions. No generated function outside the registry entries was edited.

## Constants, resources, and comments

No constant was added or renamed. Existing values, including service-count bounds, active-state values, and the DirectPlay success value `0`, remain unchanged.

No resource lookup or resource ID occurs in this module. No resource request is open. The runtime resource files were not copied or changed.

No source comment was added. The code has no non-obvious lifetime, unit, or compatibility rule that needs a new comment.

## Header request

Owner 12 may update only parameter-name spelling in `include/com_serv.h`. Keep all types, calling conventions, signatures, layouts, and values unchanged:

```cpp
char* GetServiceName(int id);
int SetServiceName(int id, char* Text);
_GUID GetServiceGUID(int id);
void EnumServiceGUID(int id, _GUID* gid);
int GetServiceActive(int id);
void SetServiceActive(int id, int state);
BOOL __stdcall DPEnumCallback(LPGUID pid, LPSTR szName, DWORD major_ver,
                               DWORD minor_ver, LPVOID lpx);
```

The request is supported by the scoped PDB records listed above. No shared constant, resource-ID, or other header request is open.

## Risk and validation

The source commit changes identifier spellings only. It does not change types, layout, ABI, symbol identity, relocations, call targets, or runtime data by source inspection. The header request also changes names only.

Compilation, matching, audits, and tests were not run, as required for this cleanup wave.
