# `src/sceninfo.cpp` cleanup report

## Delivery

- Module: `src/sceninfo.cpp`
- Worker slot: 231
- Branch: `cleanup/staging-20260915-231`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit: `fed8be14c04f867bfd65a07f23c6ea077adf7599`
- Report commit: `20d5f1b6c4abb91c362d589366620aec17009a85`
- Changed files:
  - `src/sceninfo.cpp`
  - `workflow/decomp_notes/source_cleanup/wave04/sceninfo.md`

The source registry is `config/functions/src/sceninfo.cpp.json`.
It selects six normal procedures.
The PDB source path is `C:\\msdev\\work\\age1_x1\\sceninfo.cpp`.
The paired header owner is owner 26.
This worker did not edit `include/sceninfo.h`.

The source change restores two parameter spellings.
It moves three function braces to 1TBS form.
It keeps types, scopes, storage, declarations, calls, expressions, literals, and control flow unchanged.
It changes no public symbol or ABI signature.

## PDB coverage

I inspected every assigned procedure packet and its scoped PDB record.
The scoped records are in:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The selected packets are under:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/`

All six procedures have a `this` register record in `ecx`.
The table lists each procedure's original packet size, source span, parameters, and locals.
Names in the table are PDB names.

| VA | Procedure | Bytes | PDB source span | Parameters | Locals |
| --- | --- | ---: | --- | --- | --- |
| `0048CEA0` | `RGE_Scenario_File_Info::RGE_Scenario_File_Info` | 292 | 26-61 | `in_filename` | none |
| `0048CFD0` | `RGE_Scenario_File_Info::~RGE_Scenario_File_Info` | 110 | 67-80 | none | none |
| `0048D040` | `RGE_Scenario_File_Info::save` | 152 | 86-105 | none | none |
| `0048D0E0` | `RGE_Scenario_File_Info::reload_scenarios` | 995 | 111-230 | none | `new_scenarios`, `looped`, `file_info`, `handle`, `version`, `count`, `found_in_list`, `file_name` |
| `0048D4D0` | `RGE_Scenario_File_Info::get_scenario_name` | 46 | 236-240 | `id` | none |
| `0048D500` | `RGE_Scenario_File_Info::get_scenario_info` | 46 | 246-250 | `id` | none |

The constructor parameter record is `char* in_filename` at stack offset `+0x4`.
The two getter parameter records are `long id` at stack offset `+0x4`.
The other procedures have no explicit stack parameter record.

The reload locals have these PDB types and homes:

- `new_scenarios`: `RGE_Scenario_File_Entry*`, `-0x220`.
- `looped`: `unsigned char`, `-0x22E`.
- `file_info`: `_finddata_t`, `-0x118`.
- `handle`: `long`, `-0x228`.
- `version`: `long`, `-0x21C`.
- `count`: `long`, `-0x224`.
- `found_in_list`: `unsigned char`, `-0x22D`.
- `file_name`: `char[256]`, `-0x218`.

The source keeps `file_info`, `looped`, `count`, `found_in_list`, and
`file_name` unchanged.
Their spellings already match the PDB records.

The optimized reload packet does not map every PDB home to the current source declaration.
Its listing labels the calloc result as `version` at `0048D246`.
The same slot supplies `this->scenarios` at `0048D4A4`.
The source declaration for that pointer is `new_scenarios`.
The packet labels the final `scenario_num` value as `new_scenarios` at `0048D4A8`.
The source declaration for that count is `total`.
The PDB record for `version` is also `long`, while the current `total` declaration is `int`.
I did not force these records onto different declarations or change their types.

The current `file_name` declaration is `char[260]`.
The PDB record is `char[256]`.
The source uses `file_name + 4` and retains the existing declaration.
This type and stack-layout question remains unresolved.

The constructor local `i`, destructor locals `i` and `hdr`, save locals `fd` and
`cnt`, and reload locals `current`, `index`, and block-local `fd` have no
procedure-scoped PDB name record.
I left them unchanged.
I added no declaration to represent an omitted or reused PDB home.

## Recovered names

The following substitutions use direct procedure-scoped PDB records:

- Constructor: `path` to `in_filename`.
- `get_scenario_name`: `index` to `id`.
- `get_scenario_info`: `index` to `id`.

These are recovered original spellings.
No new descriptive cleanup name was added.
The reload `total` name remains because the PDB `version` record does not map
safely to that declaration.
The current `new_scenarios` name remains because the packet shows an optimized
stack-label conflict around the same storage.

## Constants, resources, comments, and formatting

This module has no resource ID or resource lookup.
No resource extraction was needed.
No shared resource mapping request is open.

No numeric literal changed.
I reviewed the pinned VC5 headers before deciding this.
`C:/Program Files (x86)/DevStudio/VC/Include/FCNTL.H` defines `_O_BINARY`
as `0x8000`, `_O_WRONLY` as `0x0001`, `_O_CREAT` as `0x0100`, and `_O_TRUNC`
as `0x0200`.
These values explain the existing `rge_open` flags `0x8000` and `0x8301`.
`sys/STAT.H` defines `_S_IREAD` as octal `0400` and `_S_IWRITE` as octal
`0200`; together they explain the existing `0x180` mode value.
The existing literals remain unchanged.
The `4`, `0x104`, and `0x10C` values retain their existing field and entry-size roles.

No source comment was added.
The existing code did not need a sparse behavior comment.
Function braces for the constructor, `save`, and `reload_scenarios` now use 1TBS.
Short signatures and calls remain on one line where practical.

## Header request

Owner 26 should update these paired-header declaration names:

- `RGE_Scenario_File_Info(char* in_filename)`.
- `char* get_scenario_name(long id)`.
- `RGE_Scenario_Header* get_scenario_info(long id)`.

This request changes parameter names only.
It does not request a type, layout, storage, or ABI change.
Root owns all other headers.

## Code-generation and unresolved risks

The source changes preserve the six original function boundaries and decorated symbols.
They preserve call targets, virtual slots, casts, field offsets, declaration order,
and evaluation order.
The two parameter renames do not change types or object layout.
The brace changes can alter debug line records.
The source has no `__LINE__` use in this module.
The unresolved PDB home and type questions can affect a future source recovery pass.
No compiler comparison was made during this wave.

## Evidence hashes

- Original executable:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`
  SHA-256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- Original PDB:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`
  SHA-256: `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`
- Scoped PDB inventory:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
  SHA-256: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`
- Preserved baseline executable:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
  SHA-256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`
- Preserved baseline object:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/sceninfo.obj`
  SHA-256: `ad7d2f0a4a74c2659c1f79bacfcae992bbd7ddae2cd7450d0b0b299ee5165efa`

Evidence inspection, hash extraction, complete diff review, and Git commit review were performed.
Compilation, builds, matching, audits, validation, and tests were not run.
No runtime or game command was run.
