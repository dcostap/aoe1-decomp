# `src/getdxver.cpp` cleanup report

## Delivery

- Module: `src/getdxver.cpp`.
- Branch: `cleanup/staging-20260915-239`.
- Report: `workflow/decomp_notes/source_cleanup/wave04/getdxver.md`.
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Final source-cleanup commit: `4c93f670b298833bf3c804f46fa2c551b77cf747`.
- Base source blob SHA-1: `562d4736832c2c9b322c4d1268cdb9ee99076fb6`.
- Final source blob SHA-1: `b25076a6bc37fb03ed6ff1b0aa5a3c09e4ac8fe9`.
- Base source SHA256: `596d3977bffbd32892873925aa32ac3119c197ee2682b1bbe0fc6b382652cc45`.
- Final source SHA256: `1c9098d729a0c48a7f1fb3d14daf4a63bc8b417ac236edb62b2e8519cfa76047`.
- Changed files:
  - `src/getdxver.cpp`.
  - `workflow/decomp_notes/source_cleanup/wave04/getdxver.md`.

The correction commit contains only the assigned source file. The report
update is a separate assigned-file commit. Earlier commits were not amended
or removed.

## Scope and evidence

I inspected both normal procedures in source order:

- `0044DAC0 GetDXVersion`, 1053 bytes, `__cdecl`.
- `0044DEE0 IsDPlay501a`, 160 bytes, `__cdecl`.

The procedure records are in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The original PDB is
`C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`, SHA256
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
Both procedures use `C:\msdev\work\age1_x1\getdxver.cpp` as their PDB
source. The PDB line spans are 54-338 and 342-389.

Original instruction and decompiler evidence is in:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044DAC0_GetDXVersion.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044DEE0_IsDPlay501a.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/getdxver.cpp.asm`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/getdxver.cpp.decomp`.

The original executable is
`C:/Projects/my_decomps/aoe1_attempt3/orig/_original_empiresx_from_beta_that_was_decompiled.exe`,
SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved baseline object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/getdxver.obj`,
SHA256 `5bee54d245e42a45a7739d43104be7b8d2d9f4e0d3b7342667ffacc31eb24160`.

I read `include/getdxver.h` and the caller in `src/basegame.cpp`. The caller
passes `&directx_version` and `&directx_platform` to `GetDXVersion`. The public
header was not changed.

## PDB coverage and name recovery

### `GetDXVersion`

The PDB has no register symbols for this procedure. Its stack records are:

| PDB offset | PDB name | PDB type | Source result |
| --- | --- | --- | --- |
| `+0x4` | `pdwDXVersion` | `unsigned long*` | Renamed `param_1`. |
| `+0x8` | `pdwDXPlatform` | `unsigned long*` | Renamed `param_2`. |
| `-0x114` | `pDDraw` | `IDirectDraw*` | Existing name kept. |
| `-0x108` | `pDDraw2` | `IDirectDraw2*` | Existing name kept. |
| `-0x10c` | `pSurf` | `IDirectDrawSurface*` | Existing name kept. |
| `-0x110` | `DirectInputCreateA` | unresolved PDB type | Renamed both block-local `DirectInputCreate` declarations. |
| `-0x94` | `osVer` | `_OSVERSIONINFOA` | Existing name kept. |
| `-0x104` | `pSurf3` | `IDirectDrawSurface3*` | Existing name kept. The source keeps `IUnknown*`. |
| `-0x100` | `desc` | `_DDSURFACEDESC` | Existing name kept. |
| `-0x110` | `dp3` | `IDirectPlay3*` | Existing name kept. The source keeps `IUnknown*`. |

The PDB has one `DirectInputCreateA` record for a reused home. The source
keeps two separate declarations and scopes. The exact PDB spelling and the
same `GetProcAddress` target support both renames. The shared home does not
prove one source lifetime.

The PDB does not record `hr`, `DDHinst`, `DIHinst`, `DirectDrawCreate`, or
`coInitResult`. I left those declarations unchanged. The PDB types for
`pSurf3` and `dp3` name legacy interfaces that the pinned headers do not
provide. I did not change the current `IUnknown*` declarations or add a
private type declaration.

### `IsDPlay501a`

The PDB has no parameters and no register symbols. Its stack records are:

| PDB offset | PDB name | PDB type | Source result |
| --- | --- | --- | --- |
| `-0xc` | `verInfo` | `tagVS_FIXEDFILEINFO*` | Existing name kept. |
| `-0x8` | `zero` | `unsigned long` | Renamed `lpDummy`. |
| `-0x4` | `verSize` | `unsigned int` | Existing name kept. |

The PDB does not record `verInfoLen`, `pv`, `result`, `a`, or `b`. I left
those declarations unchanged. No reused home received a forced mapping.

Recovered original names are `pdwDXVersion`, `pdwDXPlatform`,
`DirectInputCreateA`, and `zero`. Existing PDB names remain unchanged,
including `pDDraw`, `pDDraw2`, `pSurf`, `osVer`, `pSurf3`, `desc`, `dp3`,
`verInfo`, and `verSize`. No new descriptive names were added. No public
function, class, member, global, ABI name, or decorated symbol changed.

## Constants and SDK evidence

I read the pinned VC5 SDK declarations before replacing API literals:

- `C:/Program Files (x86)/DevStudio/VC/Include/winbase.h:7297-7304` defines
  `_OSVERSIONINFOA`. Its five `DWORD` fields and 128-byte `CHAR` array prove
  that `0x94` fits the structure. They do not prove the original source form.
  The source retains the explicit `osVer.dwOSVersionInfoSize = 0x94`.
- `C:/Program Files (x86)/DevStudio/VC/Include/winbase.h:7328-7329` defines
  `VER_PLATFORM_WIN32_WINDOWS` as `1` and `VER_PLATFORM_WIN32_NT` as `2`.
  The source now uses those names for the platform test and output.
- `C:/Program Files (x86)/DevStudio/VC/Include/wtypes.h:631-641` defines
  `CLSCTX_INPROC_SERVER` as enum value `0x1`. The source now uses it in the
  `CoCreateInstance` call. The prototype is in `objbase.h:664-666`.
- `C:/Program Files (x86)/DevStudio/VC/Include/ddraw.h:755` defines
  `DDSD_CAPS` as `0x00000001l`.
- `C:/Program Files (x86)/DevStudio/VC/Include/ddraw.h:933` defines
  `DDSCAPS_PRIMARYSURFACE` as `0x00000200l`.
- `C:/Program Files (x86)/DevStudio/VC/Include/ddraw.h:1941` defines
  `DDSCL_NORMAL` as `0x00000008l`.
- `C:/Program Files (x86)/DevStudio/VC/Include/winver.h:206-286` declares
  the version-information APIs used by `IsDPlay501a`.

The SDK names preserve the original numeric values at these assignments and
calls. The explicit `0x94` remains unchanged.
No new shared constant or resource mapping is needed.

## Resources and DLL lookup

This module has no game string lookup, `LoadString` call, resource ID, or
resource namespace. No resource override or fallback path applies. I did not
run string-resource extraction because the module does not perform a string
resource lookup.

The module does perform code-DLL and version-file lookups. These are separate
from game string resources:

| Lookup | Evidence and path result |
| --- | --- |
| `LoadLibraryA("DINPUT.DLL")` | Windows DLL search path. `DINPUT.DLL` is absent from the pinned original tree and `runtime/`. No local SHA256 is available. No language, ID, or payload applies. |
| `LoadLibraryA("DDRAW.DLL")` | Windows DLL search path. The staged harness copy at `C:/Projects/my_decomps/aoe1_attempt3/build/runtime/original-20260915T131345059786Z/ddraw.dll` has SHA256 `85e0f7d530dfda134793a57cb3e76b0287dcc96892ee57162dd68f47283b03a9`. It is a runtime compatibility DLL, not a pinned original game resource. No language, ID, or payload applies. |
| `GetFileVersionInfoSizeA("dplayx.dll", ...)` and `GetFileVersionInfoA("dplayx.dll", ...)` | Windows DLL search path. `dplayx.dll` is absent from the pinned original tree and `runtime/`. No local SHA256 is available. The lookup reads a version resource through `VERSION.DLL`; it does not read a game string table. |

The original installation directory contains `languagex.dll` but this module
never references it. Its pinned original SHA256 is
`a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
The local `runtime/language.dll` and `runtime/languagex.dll` are also unused
here; their SHA256 values are `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
and `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
No ID, language, payload, or fallback mapping is applicable to these unused
files.

## Comments and formatting

I kept the existing comment that explains the private legacy GUID imports.
It agrees with the pinned `ddraw.h` and `dplay.h` declarations. I added no
new source comment. The edit keeps 1TBS braces, declaration order, statement
order, casts, scopes, storage, calls, and known failure paths.

## Possible code-generation and symbol effects

The identifier changes affect debug names only. They do not change types,
storage, scopes, evaluation order, calls, boundaries, or decorated symbols.
The SDK macros and enum value replace literals with the same 32-bit values.
The explicit `0x94` remains unchanged. No layout, vtable, calling convention,
public interface, or resource data changed.
The source was not compiled, so generated-code stability remains unverified.

## Shared requests and unresolved questions

- Header request: the owner of `include/getdxver.h` should use
  `void GetDXVersion(unsigned long* pdwDXVersion, unsigned long* pdwDXPlatform);`.
  The PDB records these names at parameter homes `+0x4` and `+0x8`. This
  changes declaration names only. The worker did not edit the header.
- Resource mapping request: none.
- The PDB records legacy `IDirectDrawSurface3*` and `IDirectPlay3*` homes,
  while the current source uses `IUnknown*` because the pinned headers do not
  define those interfaces. This declaration mapping remains unresolved.
- Optimized locals without PDB records remain unchanged.

I reviewed the complete source diff and ran `git diff --check`.
Compilation, matching, audits, and tests were not run. I also did not run a
build, validation command, or game.
