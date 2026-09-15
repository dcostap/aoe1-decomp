# Source cleanup report: `point.cpp`

## Delivery

- Module: `src/point.cpp`
- Slot and branch: 207, `cleanup/staging-20260915-207`
- Base commit from `git rev-parse`: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit from `git rev-parse`: `5d8b041d307096bbaf217f847c5e7ffa9e810f20`
- Changed source file in the source commit: `src/point.cpp`
- This report is committed separately.
- Read-only paired header: `include/point.h`

The cleanup restores supported PDB parameter and local names. It also applies
1TBS braces in the rotation function. It preserves expressions, types, scopes,
storage, calls, literals, and ABI symbols.

## Evidence

The scoped PDB evidence is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The source map is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`.
The PDB source path is `C:\msdev\work\age1_x1\point.cpp`.

I inspected the complete procedure packets at these paths:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047E480_XYZ.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047E490_XYZ.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047E4B0_operator.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047E4E0_operator.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047E510_operator.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047E530_operator.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047E580_operator.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047E5D0_rotateXYByFacet.txt`

I also inspected the complete relevant listing at
`C:/Projects/my_decomps/aoe1_attempt3/orig/aoe1_ghidra_assembly_listing.txt`.
The original executable remains the behavior oracle.

The original executable hashes are:

- `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/_original_empiresx_from_beta_that_was_decompiled.exe`
- `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

The preserved pre-cleanup evidence includes:

- `5c5e891e38ae3826d186c380fc104b385f43771cb68e454a2c83dbf680e3906a`:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/point.obj`
- `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`

## PDB name-recovery coverage

All eight assigned procedures have PDB source records. Their source spans,
registers, stack symbols, and cleanup results are listed below.

| VA | Function | PDB source span | PDB registers | PDB parameters and locals | Cleanup |
| --- | --- | --- | --- | --- | --- |
| `0047E480` | `XYZ::XYZ()` | `22-23` | `this` in `ecx` | No stack symbols | No rename |
| `0047E490` | `XYZ::XYZ(int,int,int)` | `32-33` | `this` in `ecx` | `a`, `b`, `c`: `int` at `+0x4`, `+0x8`, `+0xc` | Renamed `x`, `y`, `z` to `a`, `b`, `c` |
| `0047E4B0` | `operator==` | `38-44` | No register symbols | `one`, `two`: `const XYZ&` at `+0x4`, `+0x8` | Renamed `a`, `b` to `one`, `two` |
| `0047E4E0` | `operator!=` | `49-55` | No register symbols | `one`, `two`: `const XYZ&` at `+0x4`, `+0x8` | Renamed `a`, `b` to `one`, `two` |
| `0047E510` | `XYZ::operator=` | `60-65` | `this` in `ecx` | `p`: `const XYZ&` at `+0x4` | Renamed `other` to `p` |
| `0047E530` | `XYZ::operator+` | `70-73` | `this` in `ecx`, type `const XYZ*` | `__$ReturnUdt` at `+0x4`; `p`: `const XYZ&` at `+0x8`; `newP`: `XYZ` at `-0xc` | Renamed `other` to `p`; renamed `tmp` to `newP` |
| `0047E580` | `XYZ::operator-` | `78-81` | `this` in `ecx`, type `const XYZ*` | `__$ReturnUdt` at `+0x4`; `p`: `const XYZ&` at `+0x8`; `newP`: `XYZ` at `-0xc` | Renamed `param_1` to `p`; `newP` already matched |
| `0047E5D0` | `XYZ::rotateXYByFacet` | `86-109` | `this` in `ecx` | `refPoint`: `const XYZ&`; `rPoint`: `XYZ&`; `facet`: `unsigned char`; `yDiff`, `xDiff`: `int`; `rotAmount`: `float` | Renamed `dx` to `xDiff`, `dy` to `yDiff`, and `angle` to `rotAmount` |

The default constructor has no parameters, locals, or statics beyond `this`.
The parameterized constructor has only the three PDB integer parameters.
Both comparison operators have only their two PDB reference parameters.
The assignment operator has only `this` and `p`.

The PDB records for both arithmetic operators include the hidden
`__$ReturnUdt` stack entry. C++ source does not declare that ABI parameter.
Both records also name the local `newP`. The source now uses that recovered name.

The rotation PDB records place `facet`, `xDiff`, `yDiff`, and `rotAmount` in the
same `+0xc` stack home. The original instructions reuse that home for the byte,
two integer differences, and the float angle. The expression uses and types
map `xDiff` to `this->xValue - refPoint.xValue`, `yDiff` to the y difference,
and `rotAmount` to the masked facet product. No storage or declaration change
was made.

The PDB has no records for `s`, `c`, `y1`, or `x1` in the rotation procedure.
Those existing names remain descriptive names, not recovered original names.
No name was invented for an absent PDB symbol. All recorded PDB names have a
source mapping or an explicit ABI explanation.

## Constants, resources, and comments

No constant changed. The rotation literal remains
`0.7853981852531433f`. The original data dump at
`C:/Projects/my_decomps/aoe1_attempt3/inventory/globals/dumps/00571CE8_DAT_00571ce8.txt`
identifies `DAT_00571CE8` as a read-only `float` with initializer
`0.785398185f`, raw bytes `0xDB, 0x0F, 0x49, 0x3F`, and one reference at
`0047E617`.

This module has no resource lookup and no resource ID. The original resource
files and runtime DLLs are not relevant to this source. For provenance, the
hash-only checks saw these runtime files:

- `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`:
  `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
- `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`:
  `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`

No string ID extraction was needed. No resource mapping request is open.

No source comment was added or removed. The named rotation products are
supported by the exact-product-order evidence in
`C:/Projects/my_decomps/aoe1_attempt3/logic_reviews/0047E5D0.md`.

## Code generation and unresolved items

The source commit changes parameter and local identifiers. It moves two
opening braces to 1TBS form in the rotation function. It does not change types,
storage, declaration scope, member order, evaluation order, control flow, calls,
relocations, literals, function boundaries, or ABI symbols.

Identifier changes can change debug names and line records. The formatting can
also change debug line association. No source expression or machine-code
operation was intentionally changed. This wave did not compile or match the
translation unit, so those effects remain unvalidated.

The hidden `__$ReturnUdt` entries remain implicit. The rotation names `s`, `c`,
`y1`, and `x1` remain unresolved against the scoped PDB. No uncertain mapping
was forced. No other unresolved parameter or local mapping remains.

## Header and shared requests

`include/point.h` was read and not edited. Owner 23 controls that paired header.
The header declarations can use these recovered names without changing types or
signatures:

```cpp
XYZ(int a, int b, int c);
int __cdecl operator==(const XYZ& one, const XYZ& two);
int __cdecl operator!=(const XYZ& one, const XYZ& two);
XYZ& operator=(const XYZ& p);
XYZ operator+(const XYZ& p) const;
XYZ operator-(const XYZ& p) const;
```

This request only aligns declaration names with the source definitions. No
root-owned header request exists. No request targets `include/resource_ids.h`
or `include/game_globals.h`.

## Validation status

Evidence extraction, hash checks, and complete Git diff review ran.
Compilation, matching, audits, and tests were not run.
No build, compiler, matching, audit, validation, test, game, or runtime command
was run for this assignment.
