# `aiinfmod.cpp` cleanup report

## Scope and commits

- Module: `src/aiinfmod.cpp`
- Report: `workflow/decomp_notes/source_cleanup/wave02/aiinfmod.md`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Source-change head: `0a49e85731596125d56d4b8119d48286d866e635`
- The report commit is a child of the source-change head. The delivery response
  returns both full commit hashes.
- Changed files:
  - `src/aiinfmod.cpp`
  - `workflow/decomp_notes/source_cleanup/wave02/aiinfmod.md`
- No header was changed. `include/aiinfmod.h` remains owned by owner 07.

## Cleanup result

The constructor now uses the original PDB parameter names `pW` and `playerID`.
The initializer keeps the original argument order. Both definitions now use
1TBS braces. The destructor body remains empty.

No public function, class, member, global, type, storage layout, cast, call,
literal, or evaluation order changed. No source helper or assembly was added.

## PDB coverage and name evidence

The scoped PDB source is `C:\\msdev\\work\\age1_x1\\aiinfmod.cpp`. The scoped
record file is the shared `inventory/pdb/scoped_symbols.json` with SHA256
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.

- `0040CD90`, `InformationAIModule::InformationAIModule`
  - PDB object: `.\\Release\\aiinfmod.obj`
  - Size: 42 bytes; body: `0040CD90-0040CDB9`
  - PDB lines: 22-24; two line records
  - Stack parameters: `pW` at `+0x4`, type `void*`; `playerID` at `+0x8`,
    type `int`
  - Register: `this` in `ecx`, type `InformationAIModule*`
  - Function statics: none
  - Locals: none
  - Recovered names: `pW`, `playerID`
- `0040CDE0`, `InformationAIModule::~InformationAIModule`
  - PDB object: `.\\Release\\aiinfmod.obj`
  - Size: 11 bytes; body: `0040CDE0-0040CDEA`
  - PDB line: 29; one line record
  - Stack parameters: none
  - Register: `this` in `ecx`, type `InformationAIModule*`
  - Function statics: none
  - Locals: none
  - Recovered names: none
- `0040CDC0`, compiler-generated scalar deleting destructor
  - This is not a source owner and has no PDB source line.
  - PDB scoped record: `this` in `ecx` and `__flags` at `+0x4`, type
    `unsigned int`; no locals or statics.
  - Its body is `0040CDC0-0040CDDD`, size 30 bytes. It remains unchanged.

The PDB names are the only recovered parameter names in this module. No new
cleanup names were invented. The unowned header still spells these declaration
parameters `param1` and `param2`; the source definition uses the recovered
PDB spellings without changing the signature.

The constructor inventory record has SHA256
`5687e8930f31e9759eb13f88733bea4dd74a25195aed40f4b42e4b49aa0372c0`.
The destructor inventory record has SHA256
`b615c4e29924d07644753fb3e5dc70d5c89974e551f13b0f1c4efff31c2bae70`.
The records confirm the constructor call to `AIModule::AIModule` at `0040E2D0`.
They confirm the derived-vtable store. The destructor record confirms the
base-destructor tail jump to `0040E360`.

## Constants, comments, and resources

The constructor keeps the shipped module name `"InfAI"` and numeric module ID
`0x3ED`. Neither value changed. No new constant or enum was added.

No source comment was added. The two functions have no non-obvious local
contract that needs a source comment. The existing durable module note
`workflow/decomp_notes/aiinfmod.md` remains the source-order and compiler-generated-entry
evidence.

This module performs no resource lookup and defines no resource ID. Therefore,
there are no per-ID text, missing, empty, language, lookup-path, purpose, or
resource hash results. No shared resource request is needed.

## Generation-risk notes

The source edits only rename two parameters and move opening braces. The types,
scope, declaration order, initialization, argument order, calls, literal values,
and function boundaries remain unchanged. These edits can change debug line
metadata. No executable or data result is claimed until final validation.

The original executable evidence is the local
`orig/empiresx.exe`,
SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

## Validation

Compilation, matching, audits, and tests were not run.
