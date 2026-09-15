# `src/aistrmod.cpp` cleanup report

## Commits and scope

- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Head commit for the source cleanup: `cd928daecef5427fb13131868ba93fd26e45cfe0`
- Changed source: `src/aistrmod.cpp`
- This report is the only other assigned file. `include/aistrmod.h` was not edited.

The source change recovers the constructor parameter names and applies 1TBS
brace placement. It keeps the constructor call, argument order, literal values,
virtual destructor body, and source order unchanged.

## PDB coverage and name recovery

The scoped PDB is `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Its recorded SHA256 is `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The PDB source path is `C:\msdev\work\age1_x1\aistrmod.cpp`.

| VA | source function | PDB coverage | PDB parameters and locals | PDB registers | result |
| --- | --- | --- | --- | --- | --- |
| `00412AF0` | `StrategyAIModule::StrategyAIModule` | 42 bytes, `00412AF0-00412B19`, lines 22-24 | `pW` at `+0x4`, `void*`; `playerID` at `+0x8`, `int`; no locals | `this` in `ecx`, `StrategyAIModule*` | Recovered `pW` and `playerID` from PDB. |
| `00412B40` | `StrategyAIModule::~StrategyAIModule` | 11 bytes, `00412B40-00412B4A`, line 29 | no stack parameters or locals | `this` in `ecx`, `StrategyAIModule*` | No source names to recover. |

The PDB also records compiler-generated scalar deleting destructor
`00412B20` (`30` bytes). It has `this` in `ecx` and `__flags` at `+0x4` as an
`unsigned int`. It has no handwritten source owner and remains unchanged.

The old source used generated names `param1` and `param2` in the constructor
definition. The definition now uses the recovered original spellings `pW` and
`playerID`. No invented names were added. No locals or reused stack slots need
mapping.

The function inventory confirms the constructor's original range, two line
records, and `__thiscall` convention. It also confirms the destructor's range,
one line record, and `__thiscall` convention. The original listing names the
constructor call target at `0040E2D0` as `AIModule::AIModule`. It names the
destructor tail target at `0040E360` as `AIModule::~AIModule`.

## Constants, comments, and resources

No new constant or resource ID was added. The constructor retains the original
`"Strategy AI"` string and `0x3F0` ID. The original listing shows the same
string and pushes `3F0h` before the base constructor call.

No resource lookup occurs in this module. Resource extraction was not needed.

The existing destructor comment was retained. Original assembly at `00412B40`
first writes the derived vtable and then jumps to `AIModule::~AIModule`, which
supports that comment. No new source comment was added.

## Generation and ownership risks

- The parameter rename changes only source names. Types, offsets, scope, and
  argument evaluation order remain unchanged.
- Brace placement is a presentation-only cleanup. No statement moved and no
  control-flow scope changed.
- The compiler-generated scalar deleting destructor at `00412B20` remains
  compiler-owned. The source does not add a wrapper or vtable definition.
- No build or compiler check was available in this phase. Generated-code
  equality and symbol identity remain unvalidated until final validation.

## Shared request

Request the `include/aistrmod.h` owner rename the declaration parameters:

```cpp
StrategyAIModule(void* pW, int playerID);
```

Evidence: the scoped PDB record for `00412AF0` gives `pW` as `void*` at `+0x4`
and `playerID` as `int` at `+0x8`. Original assembly shows constructor callers
at `TribeStrategyAIModule` addresses `004E912C` and `004E928A`. The declaration
name change does not change the ABI or mangled symbol. No other shared request
is open.

Compilation, matching, audits, and tests were not run.
