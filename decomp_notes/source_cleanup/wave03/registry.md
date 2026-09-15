# Source-cleanup wave 03: `src/registry.cpp`

## Delivery and Git history

- Module: `src/registry.cpp`
- Branch: `cleanup/staging-20260915-198`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `a86a070d7aae53f33ef7eec82c3999e2bd36b48d`
- Changed files:
  - `src/registry.cpp`
  - `decomp_notes/source_cleanup/wave03/registry.md`
- Paired header: `include/registry.h` (read only)

The source registry is
`config/functions/src/registry.cpp.json`. It assigns eight matching functions
in PDB source order. The source keeps one natural owner and no generated
function body or assembly region.

## Evidence reviewed

I read the source-cleanup contract and all assigned cleanup guides. I read
`include/registry.h` and the prior module note at
`decomp_notes/registry.md`.

I inspected the registry-selected original packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/`:

- `0047EB80_TRegistry.txt`
- `0047EC00_TRegistry.txt`
- `0047EC40_RegSet.txt`
- `0047ECA0_RegSetInt.txt`
- `0047ED00_RegSetAscii.txt`
- `0047ED60_RegGetAscii.txt`
- `0047EDD0_RegGet.txt`
- `0047EE20_RegGetInt.txt`

I inspected the procedure-scoped records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB source path is `C:\msdev\work\age1_x1\registry.cpp`. Every procedure
has a `this` register in `ecx` with type `TRegistry*`. No procedure has a
function-static record. The packets provide the original body ranges, line
spans, call targets, and assembly from the original executable oracle at
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.

## Systematic original-name recovery

The table covers every function in the source registry. Names in the PDB
columns are procedure-scoped records. The stack offset is included where the
PDB records a local or parameter.

| VA | Function and PDB span | PDB parameters | PDB locals | Source result |
| --- | --- | --- | --- | --- |
| `0047EB80` | `TRegistry::TRegistry`, lines 12-59 | `Key` (+4) | none | Recovered `Key`. |
| `0047EC00` | `TRegistry::~TRegistry`, lines 63-83 | none | none | Reviewed; no rename. |
| `0047EC40` | `TRegistry::RegSet`, lines 87-105 | `UseUserKey` (+4), `lptszName` (+8), `lpData` (+0xc), `dwSize` (+0x10) | none | Recovered all four parameters. Existing `err` has no PDB record and remains unchanged. |
| `0047ECA0` | `TRegistry::RegSetInt`, lines 108-125 | `UseUserKey` (+4), `lptszName` (+8), `Value` (+0xc) | none | Recovered all three parameters. Existing `ret` has no PDB record and remains unchanged. |
| `0047ED00` | `TRegistry::RegSetAscii`, lines 131-149 | `UseUserKey` (+4), `lptszName` (+8), `lpData` (+0xc), `dwSize` (+0x10) | none | Recovered all four parameters. Existing `err` has no PDB record and remains unchanged. |
| `0047ED60` | `TRegistry::RegGetAscii`, lines 153-187 | `UseUserKey` (+4), `lptszName` (+8) | `dwSize` (-8), `dwType` (-4) | Recovered both parameters and both locals. |
| `0047EDD0` | `TRegistry::RegGet`, lines 192-203 | `UseUserKey` (+4), `lptszName` (+8), `lpData` (+0xc), `lpdwDataSize` (+0x10) | `dwType` (+0x14) | Recovered all four parameters and the local type variable. |
| `0047EE20` | `TRegistry::RegGetInt`, lines 206-231 | `UseUserKey` (+4), `lptszName` (+8) | `Size` (-8), `dwType` (-4), `Data` (+0xc) | Recovered both parameters and all three PDB locals. |

The PDB register record for every row is `this` in `ecx`. The PDB provides no
named locals for `err` or `ret`; those existing source names are not claimed as
original names. The `Data` local in `RegGetInt` is distinct from the
header-owned `TRegistry::Data` member. Its mapping follows the PDB name, type,
call role, and stack record. No reused slot was merged or given a forced new
meaning.

## Source changes and name provenance

Recovered original PDB spellings restored in `src/registry.cpp`:

- Constructor parameter: `Key`.
- Shared registry parameters: `UseUserKey` and `lptszName`.
- Data parameters: `lpData`, `dwSize`, and `lpdwDataSize`.
- Integer parameter: `Value`.
- Registry type locals: `dwType`.
- Integer getter locals: `Size` and `Data`.

The cleanup also applies 1TBS braces and adjusts whitespace. No new parameter,
local, public symbol, class member, helper, or wrapper was invented. Existing
`err` and `ret` names remain because the PDB does not establish replacements.

## Constants, resources, and comments

I read the pinned VC5 SDK definitions before replacing registry type literals:

- `C:/Program Files (x86)/DevStudio/VC/include/WINNT.H:4801` defines
  `REG_SZ` as `(1)`.
- `C:/Program Files (x86)/DevStudio/VC/include/WINNT.H:4805` defines
  `REG_DWORD` as `(4)`.
- `C:/Program Files (x86)/DevStudio/VC/include/WINREG.H:548-560` declares the
  `RegQueryValueExA` type and data arguments.
- `C:/Program Files (x86)/DevStudio/VC/include/WINREG.H:680-692` declares the
  `RegSetValueExA` type and data arguments.

The source now uses `REG_DWORD` for the existing value `4` in `RegSet`,
`RegSetInt`, and `RegGetInt`. It uses `REG_SZ` for the existing value `1` in
`RegSetAscii`. `RegGetAscii` already used `REG_SZ`. The fixed four-byte data
lengths remain literal `4`; no size or width change was made. Existing
`HKEY_*` and key-access symbols remain unchanged.

This module has no resource lookup or resource ID. No resource DLL was
inspected. No source comment was added; the recovered names and SDK symbols
explain the code without a repetitive comment.

## Code-generation effects and unresolved questions

The source changes rename parameters and locals, replace SDK macros that expand
to the same integer values, and apply 1TBS formatting. They preserve types,
declaration order, storage, casts, expression order, field layout, control
flow, API calls, direct targets, public symbols, and ABI signatures. The source
has no `__LINE__` use. Formatting can change debug line records. Generated
instructions, data, relocations, and call targets remain unvalidated.

The paired header still uses its baseline parameter spellings. Request the
owner of `include/registry.h` to align its declaration names with the proved
PDB names: `Key`; `UseUserKey`, `lptszName`, `lpData`, and `dwSize` for the
setters; `UseUserKey` and `lptszName` for the getters; and
`lpdwDataSize` for `RegGet`. This request changes no type, layout, symbol, or
ABI. No resource-header request is needed.

No source declaration mapping blocks this delivery. The only unresolved
source-local names are existing `err` and `ret`, which have no scoped PDB
records and remain unchanged. The PDB has no function-static mapping or
resource-purpose question for this module.

## Validation status

I reviewed the complete source diff and ran `git diff --check`.

**Compilation, matching, audits, and tests were not run.** I did not run a
compiler, build, matching check, audit, test, or game.
