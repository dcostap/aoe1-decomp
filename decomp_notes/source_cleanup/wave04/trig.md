# `src/trig.cpp` cleanup report

## Scope and hashes

- Module: `src/trig.cpp`.
- Header owner: owner 28 owns `include/trig.h`. This worker did not edit it.
- Branch: `cleanup/staging-20260915-252`.
- Base commit from `git rev-parse`: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Base source blob from Git: `526ce6f6f9fce20a65910a13f98133357bff6c9c`.
- Final source blob from Git: `0c7557dc8dff29ee877fbba9de0f5ff6dc2690a5`.
- Final commit: see the delivery record for the full Git hash.
- Changed files:
  - `src/trig.cpp`
  - `decomp_notes/source_cleanup/wave04/trig.md`

The module has 11 normal source owners. Their source order follows the PDB
source line bands from 11 through 56. The registry remains
`config/functions/src/trig.cpp.json` with the default build profile.

Evidence identity used during review:

- Original executable:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Original PDB:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/age1_x1.pdb`
  SHA-256 `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
- Scoped PDB inventory:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
  SHA-256 `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
- Class layout dump:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/TRIGONOMETRY.txt`
  SHA-256 `0c19d5d246314496784757838aca276a62eeac4db26d25050c3a85294b300cb2`.
- Original assembly listing:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/trig.cpp.asm`
  SHA-256 `24dc762357149e170d0d2e22bfd4d3ea88bff5c4e271828afe2eb7ac4a4e0e11`.
- Original decompiler listing:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/trig.cpp.decomp`
  SHA-256 `a403720c17941d097f2d0c6f388405f0307f6b4074a973e86eab6253235a7a08`.
- Preserved baseline report:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`
  SHA-256 `fddd62868626e21ec7282183fa1cf84ad5b0b14fc719c8830a266d6ed0f155b3`.

## Original-name recovery coverage

The procedure-scoped PDB records were inspected for every normal owner. The
records show `this` in `ecx` for every function. They show no function static
symbols. The table lists every stack symbol and register symbol relevant to
this cleanup.

| VA | Function and binary range | PDB source span | PDB stack symbols | PDB register symbols |
| --- | --- | --- | --- | --- |
| `0052A730` | `TRIGONOMETRY::TRIGONOMETRY`, `0052A730-0052A82F` | 11-35 | `i` at `-0x4`, `int` | `this` in `ecx`, `TRIGONOMETRY*` |
| `0052A830` | `TRIGONOMETRY::RestrictAngle`, `0052A830-0052A848` | 37-40 | `angle` at `+0x4`, `int` | `this` in `ecx`, `TRIGONOMETRY*` |
| `0052A850` | `TRIGONOMETRY::RestrictAngle360`, `0052A850-0052A866` | 43-46 | `angle` at `+0x4`, `int` | `this` in `ecx`, `TRIGONOMETRY*` |
| `0052A870` | `TRIGONOMETRY::sine`, `0052A870-0052A883` | 48 | `angle` at `+0x4`, `int` | `this` in `ecx`, `TRIGONOMETRY*` |
| `0052A890` | `TRIGONOMETRY::cosine`, `0052A890-0052A8A7` | 49 | `angle` at `+0x4`, `int` | `this` in `ecx`, `TRIGONOMETRY*` |
| `0052A8B0` | `TRIGONOMETRY::tangent`, `0052A8B0-0052A8C7` | 50 | `angle` at `+0x4`, `int` | `this` in `ecx`, `TRIGONOMETRY*` |
| `0052A8D0` | `TRIGONOMETRY::atangent`, `0052A8D0-0052A8E7` | 51 | `angle` at `+0x4`, `int` | `this` in `ecx`, `TRIGONOMETRY*` |
| `0052A8F0` | `TRIGONOMETRY::sin360`, `0052A8F0-0052A907` | 53 | `angle` at `+0x4`, `int` | `this` in `ecx`, `TRIGONOMETRY*` |
| `0052A910` | `TRIGONOMETRY::cos360`, `0052A910-0052A927` | 54 | `angle` at `+0x4`, `int` | `this` in `ecx`, `TRIGONOMETRY*` |
| `0052A930` | `TRIGONOMETRY::tan360`, `0052A930-0052A947` | 55 | `angle` at `+0x4`, `int` | `this` in `ecx`, `TRIGONOMETRY*` |
| `0052A950` | `TRIGONOMETRY::atan360`, `0052A950-0052A967` | 56 | `angle` at `+0x4`, `int` | `this` in `ecx`, `TRIGONOMETRY*` |

The procedure packets are under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/`.
They are named `0052A730_TRIGONOMETRY.txt` through
`0052A950_atan360.txt`. Each packet confirms the source path
`C:\msdev\work\age1_x1\trig.cpp`, its line span, body range, calling
convention, and original instructions.

### Renamed parameters and locals

- Each of the ten definitions from `0052A830` through `0052A950` now uses
  `angle` instead of `param_1`. The scoped PDB record gives the original
  spelling `angle` at stack offset `+0x4` for every one of these procedures.
- The constructor already used the PDB name `i`. No constructor local was
  renamed.
- The source header still uses `param_1` because the header is read-only for
  this worker. A declaration-name request is listed below.
- The source locals `value`, `index`, and `rad` have no matching scoped PDB
  symbol. They remain unchanged. The PDB has no local record that proves an
  original name for them. No reused stack slot was mapped into a new
  declaration.
- `this` is a recovered original register name. The PDB lists it in `ecx` for
  all 11 procedures.

The source change also moves each function opening brace onto its definition
line. It does not move a statement or change a scope.

## Binary and source evidence

The constructor packet `0052A730_TRIGONOMETRY.txt` shows two loops. The first
uses bound `0x1000` and writes the four arrays at offsets `0x0`, `0x4000`,
`0x8000`, and `0xC000`. The second uses bound `0x168` and writes the four
arrays at offsets `0x10000`, `0x105A0`, `0x10B40`, and `0x110E0`. The class dump
confirms these array lengths and offsets.

The constructor assembly proves the special zero entries. It writes zero
for tangent at `0x400` and `0xC00`, and for arctangent at `0` and `0x800`.
The degree table uses `0x5A` and `0x10E` for tangent, and `0` and `0xB4` for
arctangent. These values remain unchanged.

The `RestrictAngle` packet proves the signed modulus and absolute-value path.
The `RestrictAngle360` packet proves the signed remainder by `0x168` and the
negative-value correction. The eight accessor packets prove their calls to
the matching restriction method and their reads from the matching table.
Those expressions and call targets remain unchanged.

## Constants, comments, and resources

No numeric constant was added, removed, or replaced. The existing bounds and
special entries are supported by the original assembly and the class layout
dump. The existing radian literals remain unchanged.

No new source comment was added. The existing phase comments describe the two
proven table loops. They remain sparse and accurate.

`python tools/inspect_pe_strings.py --help` was run before resource review.
This module has no resource lookup and no resource ID. No DLL is relevant to
this source. No resource mapping request is needed.

## Code-generation, type, layout, and symbol effects

The edits change parameter identifiers and brace placement only. They do not
change a type, cast, declaration scope, storage duration, literal, evaluation
order, control flow, field access, call target, calling convention, class
layout, or ABI symbol. The source keeps explicit `this->` uses.

Parameter names do not form the mangled symbols. The header request below also
changes declaration names only. Brace placement can change debug line records,
but this source has no line-dependent macro. No compiler comparison was run.

## Header and shared-file requests

Request owner 28 to update declaration parameter names in
`include/trig.h`, without changing any type or signature:

- `RestrictAngle(int angle)`.
- `RestrictAngle360(int angle)`.
- `sine(int angle)`.
- `cosine(int angle)`.
- `tangent(int angle)`.
- `atangent(int angle)`.
- `sin360(int angle)`.
- `cos360(int angle)`.
- `tan360(int angle)`.
- `atan360(int angle)`.

The request is supported by the scoped PDB records listed above. This worker
did not edit the header. There is no shared constant or resource declaration
request.

## Unresolved questions

- The scoped PDB does not name the source locals `value`, `index`, or `rad`.
  Their current descriptive names remain unclaimed as original names.
- The header declaration names remain `param_1` until owner 28 reviews the
  request.
- The final compiler effect of the cleanup remains untested.

## Validation status

The complete source diff was reviewed. `git diff --check` passed.
Compilation, matching, audits, validation, and tests were not run. No compiler,
build, matching, audit, validation, test, or game command was run for this
assignment. This report does not claim byte equality, semantic approval, or
validation.
