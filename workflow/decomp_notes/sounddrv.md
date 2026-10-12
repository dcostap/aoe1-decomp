# Sounddrv.cpp source module

- PDB source: `C:\\msdev\\work\\age1_x1\\Sounddrv.cpp`.
- Source: `src/Sounddrv.cpp`.
- Header: `include/sounddrv.h`.
- Normal owners: 36.
- PDB order: `004BC590` through `004BD5C0`.
- Owner surface: `TSound_Driver` and `TDigital` constructors, methods, and destructors.
- Generated entries: none.

## Context evidence

The PDB assigns all 36 normal owners to `Sounddrv.cpp`, lines 33-1037.
The address sequence and source line bands increase in the source order.
The source keeps this order and uses the C++ Win32, WinMM, DirectSound, and
runtime declarations from the reviewed period context.

The class layouts preserve the observed `TSound_Driver` mixer records, path,
playlist, and `TDigital` wave fields. DirectSound calls use the real C++
interface surface. The module has no inline assembly, fake vtable, fallback
class declarations, context-selection macro, or wrapper owner.

## Recovery states

The prior source-bank states were 35 `matching` owners and one `scratch` owner.
The scratch owner is `004BCD30` (`TDigital::load`). These states describe prior
source recovery. They do not claim grouped byte equality after the source move.
The grouped source needs fresh checks after reunification.

## Transition

The merge moves all 36 function bodies into one C++ source module in PDB order.
It renames `include/sounddrv_context.h` to `include/sounddrv.h`, removes the
translation-unit wrapper, and removes the 36 module-owned source-bank
fragments. The translation-unit entry maps every owner to `src/Sounddrv.cpp`
and names the source module metadata.

## Validation

The migration uses `config/flags/default.rsp` and the registered `sounddrv`
translation-unit entry. The first post-move standalone check for
`004BC590` reports `MATCH` and `0.0000%` with the canonical module source.

The observed translation-unit audit compiled all 36 owners. It reports 35
registered owner matches with zero byte, relocation, and boundary differences.
The 35 prior exact owners have no grouped regression.

`004BCD30` remains scratch. Its natural source emits 384 differing bytes and
escapes the original boundary by one byte. The source keeps its prior cleanup,
resource, and DirectSound behavior. Its remaining issue is code generation and
boundary layout, not a missing owner.

## ABI compile repair

The PDB symbol `?RESFILE_load@@YAPAEKKAAH0@Z` proves a C++ `__cdecl` function
with two `int&` output parameters. `src/Sounddrv.cpp` now uses the canonical
declaration from `include/Res_file.h` and passes those outputs as references.
The former local declaration and pointer arguments were incompatible with the
owner ABI. The header also owns the PDB-proven C++ `sound_file_first` global.

The full Sounddrv source now compiles. `004BC590` remains `MATCH` with
`0.0000%`. The `004BCD30` checker still cannot select its overloaded `load`
owner from the unregistered grouped object; this is an extractor limitation,
not a compile failure.
