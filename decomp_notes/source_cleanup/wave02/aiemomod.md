# `src/aiemomod.cpp` cleanup report

## Delivery

- Module: `src/aiemomod.cpp`.
- Branch: `cleanup/staging-20260915-57`.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Final commit: `bb75b5afe8c1ca7c75633292217a2d004e3ff699`.
- Changed files:
  - `src/aiemomod.cpp`
  - `decomp_notes/source_cleanup/wave02/aiemomod.md`
- `include/aiemomod.h` was read but not edited. Owner 07 owns that header.

The registry `config/functions/src/aiemomod.cpp.json` assigns 13 normal functions.
All 13 have `matching` status at the base commit. This cleanup changes names and
one function brace position. It does not claim a new match.

## Evidence reviewed

I read the complete repository contract, source-cleanup guides, source-comment
guide, resource-ID guide, owner guide, testing guide, and wave 02 assignment.

I inspected the source, header, registry, original Ghidra source and assembly
units, all 13 function packets under
`inventory/functions/0040/`, and every assigned procedure record in
`inventory/pdb/scoped_symbols.json`. The PDB source path is
`C:\\msdev\\work\\age1_x1\\aiemomod.cpp`.

The original executable reference is
`orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`,
SHA-256:
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved pre-cleanup object is
`build/source-cleanup-20260915/preparation/baseline-build/aiemomod.obj`,
SHA-256:
`967d0caec4c3131be06623a56831e9e808522cd82ad3ee21652467563e9eff87`.
The preserved pre-cleanup executable is
`build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`,
SHA-256:
`492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.

The current runtime resource hashes are recorded for provenance:

- `runtime/language.dll` — SHA-256
  `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- `runtime/languagex.dll` — SHA-256
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.

This module has no resource lookup. No resource extraction was needed.

## Complete PDB coverage

Each assigned procedure has one scoped PDB record and one body range. Every
record has `this` in ECX. The PDB has no function-local static records and no
additional register records for these procedures.

| VA | Function | PDB line span / records | Stack records | Register record |
| --- | --- | --- | --- | --- |
| `0040C7C0` | constructor `(void*, int)` | `23-33` / 9 | `pW` (`void*`, `+0x4`), `playerID` (`int`, `+0x8`) | `this` (`EmotionalAIModule*`) |
| `0040C920` | constructor `(int, int)` | `40-50` / 9 | `playerID` (`int`, `+0x4`), `infile` (`int`, `+0x8`) | `this` (`EmotionalAIModule*`) |
| `0040CA90` | destructor | `55-55` / 1 | none | `this` (`EmotionalAIModule*`) |
| `0040CAA0` | `setMainDecisionAI` | `61-63` / 2 | `m` (`MainDecisionAIModule*`, `+0x4`) | `this` (`EmotionalAIModule*`) |
| `0040CAB0` | `save` | `68-72` / 4 | `outfile` (`int`, `+0x4`) | `this` (`EmotionalAIModule*`) |
| `0040CAE0` | `stateName` | `77-81` / 5 | `s` (`int`, `+0x4`) | `this` (`EmotionalAIModule*`) |
| `0040CB10` | `state` | `86-90` / 5 | `s` (`int`, `+0x4`) | `this` (`const EmotionalAIModule*`) |
| `0040CB30` | `setState` | `95-98` / 3 | `s` (`int`, `+0x4`), `value` (`int`, `+0x8`) | `this` (`EmotionalAIModule*`) |
| `0040CB50` | `incrementState` | `103-106` / 3 | `s` (`int`, `+0x4`), `delta` (`int`, `+0x8`) | `this` (`EmotionalAIModule*`) |
| `0040CB80` | `decrementState` | `111-114` / 3 | `s` (`int`, `+0x4`), `delta` (`int`, `+0x8`) | `this` (`EmotionalAIModule*`) |
| `0040CBB0` | `overallState` | `119-129` / 7 | none | `this` (`const EmotionalAIModule*`) |
| `0040CBE0` | `setOverallState` | `134-187` / 38 | `s` (`int`, `+0x4`) | `this` (`EmotionalAIModule*`) |
| `0040CD80` | `defaultState` | `192-194` / 2 | none | `this` (`const EmotionalAIModule*`) |

The PDB records no local names for any assigned function. Existing source locals
therefore remain inferred names, except for the one presentation rename listed
below. No reused stack-slot mapping was forced.

The nearby scalar deleting destructor at `0040C900` is compiler-generated and
is not a registry-owned source function. Its PDB records `this` in ECX and
`__flags` (`unsigned int`, `+0x4`). It was inspected and not edited.

## Original-name recovery

The following source definition changes restore exact procedure-scoped PDB
spellings. The header declaration names remain unchanged because this worker
cannot edit `include/aiemomod.h`:

- `0040C7C0`: `param1` became `pW`; `param2` became `playerID`.
- `0040C920`: `param1` became `playerID`; `param2` became `infile`.
- `0040CAA0`: `v` became `m`.
- `0040CAB0`: `file` became `outfile`.
- `0040CAE0`: `index` became `s`.
- `0040CB10`: `index` became `s`.
- `0040CB30`: `index` became `s`; `val` became `value`.
- `0040CB50`: `index` became `s`; `value` became `delta`.
- `0040CB80`: `index` became `s`; `value` became `delta`.
- `0040CBE0`: `state` became `s`.

The first and second constructor uses preserve the PDB parameter positions and
types. The `value` local in `save` is not the PDB parameter `value` from
`setState`; the PDB has no local record for that save pointer.

The `overallState` local `maxValue` became `max_value`. The PDB has no record
for that local, so this is a new descriptive cleanup name, not a recovered
original. The existing inferred locals `ptr`, `count`, `value`, `result`, `i`,
and `values` remain unchanged. Their declarations, scopes, types, and storage
are unchanged.

No generated `param_*`, `local_*`, or register-carrier name remains in this
source. No public function, class, member, global, type, or ABI symbol was
renamed.

## Constants, comments, and resources

No numeric constant was added, removed, or changed. Existing values remain
literal because this module has no reviewed shared constant with an equal role.
This includes the module size `0x3EC`, six-state bounds, state defaults,
state-value tables, and the `-1` invalid-state return.

The six state-name strings are copied into object storage. They are not resource
lookups. This module has no resource ID expression, language fallback, or
expansion override. No per-ID resource request is needed, and no resource name
was added.

No source comment was added. The control flow and state-value tables are already
clear, and the comment guide does not support a comment quota.

## Code generation, type, and layout review

The source changes rename parameters and one inferred local. They also move the
`setOverallState` opening brace onto its definition line for 1TBS style. They do
not change types, declaration order, declaration scope, storage duration,
member access, casts, evaluation order, control flow, calls, literals, string
data, function boundaries, relocations, direct targets, virtual slots, or
public symbols.

The PDB names for the const methods remain represented by the unchanged `const`
qualifiers. The six `stateValue` fields and six 30-byte `stateNameValue` fields
remain untouched in the owner-controlled header. No inline assembly, helper,
wrapper, layout change, or structural rewrite was added.

Identifier changes can alter debug names. The brace change can alter PDB line
records. No compiler output or program-data comparison was run, so generated
output equality remains unvalidated.

## Header and shared requests

Owner 07 may add these PDB-backed parameter names to `include/aiemomod.h`
without changing types, order, virtual slots, or ABI:

```cpp
EmotionalAIModule(void* pW, int playerID);
EmotionalAIModule(int playerID, int infile);
void setMainDecisionAI(MainDecisionAIModule* m);
virtual int save(int outfile);
char* stateName(int s);
int state(int s) const;
void setState(int s, int value);
void incrementState(int s, int delta);
void decrementState(int s, int delta);
void setOverallState(int s);
```

No resource-ID declaration, shared constant, or other header request is needed.
There are no unresolved parameter mappings. Original local spellings remain
unknown where the PDB has no local record; the report does not force those
mappings.

## Validation

Only evidence inspection, hash collection, source review, complete Git diff
review, and `git diff --check` were run.

Compilation, matching, audits, and tests were not run. Builds and games were
not run. Byte equality, relocation identity, and runtime behavior remain
unvalidated.
