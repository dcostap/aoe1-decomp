# `src/file_stf.cpp` source cleanup

## Delivery

- Module: `src/file_stf.cpp`
- Branch: `cleanup/staging-20260915-196`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `c7d9d73085173f70013142b79122ee1d6324e306`
- Changed files:
  - `src/file_stf.cpp`
  - `decomp_notes/source_cleanup/wave03/file_stf.md`
- Header changes: none

This worker owns only `src/file_stf.cpp` and this report. The header owner
remains `include/file_stf.h`. The source order and the 22 registry owners stay
unchanged.

## Changes

The source now uses the original procedure-scoped PDB names where the stack
home and type match. It also uses 1TBS braces for all function definitions.
It keeps all statements, expressions, types, casts, calls, literals, and
member accesses unchanged.

Recovered names:

- `compareFilenameStrings`: `e1`, `e2`.
- `driveAsLetter`: `d`.
- `driveAsInt`: `d`.
- `DriveInformation::validDrive`: `v`.
- `DriveInformation::numberOfFilesWithFilename`: `n`.
- `DriveInformation::numberOfFilesWithAttribute`: `a`.
- `DriveInformation::numberOfFilesWithFilenameOrAttribute`: `n`, `a`.
- `DriveInformation::changeDrive`: `d`.
- `DriveInformation::changeDirectory`: `d`.

The PDB records `fileInfo` in all three file-counting procedures. The source
already used that spelling. It also records `fullPath`, `cDrive`, `extension`,
and `filename` in `updateDirectory`; those names already matched the source.
The source did not change the `filename` local in `updateDirectory`.

## Original-name review coverage

The registry is `config/functions/src/file_stf.cpp.json`. Its 22 entries all
have status `matching` and map to the symbols below. The selected packet for
each entry is under `inventory/functions/0044/`.

The scoped PDB index is `inventory/pdb/scoped_symbols.json`. It has SHA-256
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`. The PDB
source path is `C:\msdev\work\age1_x1\file_stf.cpp`. The module object path is
`.\Release\file_stf.obj` for every record. Function statics are empty for all
22 records.

| VA | Procedure and packet | PDB line span | Stack symbols | Registers |
| --- | --- | --- | --- | --- |
| `00449710` | `compareFilenameStrings` / `00449710_compareFilenameStrings.txt` | 20-22 | `e1` `void*` +0x4; `e2` `void*` +0x8 | none |
| `00449750` | `driveAsLetter` / `00449750_driveAsLetter.txt` | 28-30 | `d` `int` +0x4 | none |
| `00449760` | `driveAsInt` / `00449760_driveAsInt.txt` | 35-37 | `d` `char` +0x4 | none |
| `00449770` | `DriveInformation::DriveInformation` / `00449770_DriveInformation.txt` | 43-53 | none | `this` in `ecx`, `DriveInformation*` |
| `004497C0` | `DriveInformation::initialDrive` / `004497C0_initialDrive.txt` | 58-60 | none | `this` in `ecx`, `const DriveInformation*` |
| `004497D0` | `DriveInformation::initialDriveAsLetter` / `004497D0_initialDriveAsLetter.txt` | 65-67 | none | `this` in `ecx`, `const DriveInformation*` |
| `004497E0` | `DriveInformation::initialDirectory` / `004497E0_initialDirectory.txt` | 72-74 | none | `this` in `ecx`, `DriveInformation*` |
| `004497F0` | `DriveInformation::currentDrive` / `004497F0_currentDrive.txt` | 79-81 | none | `this` in `ecx`, `const DriveInformation*` |
| `00449800` | `DriveInformation::currentDriveAsLetter` / `00449800_currentDriveAsLetter.txt` | 86-88 | none | `this` in `ecx`, `const DriveInformation*` |
| `00449810` | `DriveInformation::currentDirectory` / `00449810_currentDirectory.txt` | 93-95 | none | `this` in `ecx`, `DriveInformation*` |
| `00449820` | `DriveInformation::numberDrives` / `00449820_numberDrives.txt` | 100-102 | none | `this` in `ecx`, `const DriveInformation*` |
| `00449830` | `DriveInformation::validDrive` / `00449830_validDrive.txt` | 107-109 | `v` `int` +0x4 | `this` in `ecx`, `const DriveInformation*` |
| `00449840` | `DriveInformation::checkDrives` / `00449840_checkDrives.txt` | 114-129 | none | `this` in `ecx`, `DriveInformation*` |
| `004498A0` | `DriveInformation::numberOfFilesWithFilename` / `004498A0_numberOfFilesWithFilename.txt` | 134-145 | `n` `char*` +0x4; `fileInfo` `_finddata_t` -0x118 | `this` in `ecx`, `DriveInformation*` |
| `00449910` | `DriveInformation::numberOfFilesWithAttribute` / `00449910_numberOfFilesWithAttribute.txt` | 150-162 | `a` `int` +0x4; `fileInfo` `_finddata_t` -0x118 | `this` in `ecx`, `DriveInformation*` |
| `00449990` | `DriveInformation::numberOfFilesWithFilenameOrAttribute` / `00449990_numberOfFilesWithFilenameOrAttribute.txt` | 167-180 | `n` `char*` +0x4; `a` `int` +0x8; `fileInfo` `_finddata_t` -0x118 | `this` in `ecx`, `DriveInformation*` |
| `00449A20` | `DriveInformation::resetCurrentDriveAndDirectory` / `00449A20_resetCurrentDriveAndDirectory.txt` | 185-189 | none | `this` in `ecx`, `DriveInformation*` |
| `00449A40` | `DriveInformation::resetCurrentDrive` / `00449A40_resetCurrentDrive.txt` | 194-196 | none | `this` in `ecx`, `DriveInformation*` |
| `00449A50` | `DriveInformation::resetCurrentDirectory` / `00449A50_resetCurrentDirectory.txt` | 201-203 | none | `this` in `ecx`, `DriveInformation*` |
| `00449A60` | `DriveInformation::changeDrive` / `00449A60_changeDrive.txt` | 208-214 | `d` `int` +0x4 | `this` in `ecx`, `DriveInformation*` |
| `00449A90` | `DriveInformation::changeDirectory` / `00449A90_changeDirectory.txt` | 219-225 | `d` `char*` +0x4 | `this` in `ecx`, `DriveInformation*` |
| `00449AC0` | `DriveInformation::updateDirectory` / `00449AC0_updateDirectory.txt` | 230-239 | `fullPath` `char[260]` -0x104; `cDrive` `char[3]` -0x308; `extension` `char[256]` -0x304; `filename` `char[256]` -0x204 | `this` in `ecx`, `DriveInformation*` |

The source keeps these existing names because the scoped PDB does not prove a
mapping for them: `drive` in the constructor and `checkDrives`, and `handle`
and `count` in the three file-counting procedures. These are descriptive
names already present before this cleanup. They are not recovered originals.
No reused stack slot forced a declaration merge or a rename.

The PDB and packet records also confirm the free-function calling conventions:
`__cdecl` for the first three functions and `__thiscall` for the 19 member
functions. The source keeps the existing `const` qualifier on the two
`compareFilenameStrings` parameters. The PDB stack type is `void*`, while the
registry symbol and source declaration preserve `const void*`.

## Constants, resources, and comments

No resource lookup or resource ID occurs in this module. No resource mapping or
shared resource-header request applies.

No numeric constant was replaced. The packets and source retain the drive
conversion offsets `0x40` and `64`, the drive scan bound `0x1A`, array index
`0`, find failure sentinel `-1`, and `_getcwd` size `0x104`. The pinned VC5
headers were reviewed at:

- `C:/Program Files (x86)/DevStudio/VC/Include/IO.H`
- `C:/Program Files (x86)/DevStudio/VC/Include/DIRECT.H`

Those headers confirm `_finddata_t`, `_findfirst`, `_findnext`, `_chdrive`,
`_getdrive`, `_chdir`, and `_getcwd` declarations. No new symbol or constant
was needed.

No comment was added. The source has no non-obvious lifetime or compatibility
fact that needs a new comment. Existing file behavior remains unchanged,
including the file-counting paths and drive restoration order.

## Code-generation and scope review

The source changes only identifier spelling and brace placement. They do not
change declaration types, scopes, storage duration, evaluation order, control
flow, function boundaries, ABI names, member layout, call targets, relocations,
or literal values. Identifier spelling can change debug names. Brace placement
can change debug line records. No `__LINE__` use occurs in this source.

The original packets confirm the function boundaries and direct call targets.
The selected registry packet for each function remains unchanged. No helper,
wrapper, assembly, macro-context fragment, header edit, or behavior repair was
added.

## Evidence-tool incident

After running its required `--help`, this worker attempted:

`python tools/generate_function_registry_inventory.py --format json --output build/file_stf_evidence/registry_inventory.json`

The tool failed before writing output because this lean worktree has no
`inventory/all_functions.csv`. Its startup called the internal translation-unit
validation routine. No report or audit result was produced, and no tracked file
changed. The failed attempt is recorded here; no further registry tool was run.

## Validation limits

Evidence inspection, targeted searches, pinned-header review, Git diff review,
and `git diff --check` were run. The failed evidence-tool startup is described
above.

Compilation, matching, audits, and tests were not run. No build, game, or
runtime command was run. Byte equality and generated-output preservation remain
unvalidated until the final wave validation stage.

## Open questions and shared requests

- The PDB does not record the original spellings of `drive`, `handle`, or
  `count`. The source keeps its existing descriptive names.
- The PDB `void*` display for `e1` and `e2` does not override the source and
  registry `const void*` declaration. The source keeps that type.
- No shared declaration request is required.
