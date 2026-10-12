# `aitacmod.cpp` cleanup report

## Scope and commits

- Module: `src/aitacmod.cpp`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Source-change head: `f52f474766e6c3bbdc744d0853d0e8d122c1ce3e`
- Changed files in the source-change commit: `src/aitacmod.cpp`
- Report file: `workflow/decomp_notes/source_cleanup/wave02/aitacmod.md`
- All files in the final diff: `src/aitacmod.cpp` and
  `workflow/decomp_notes/source_cleanup/wave02/aitacmod.md`
- The report is committed in a follow-up commit. The worker response returns both
  commit hashes.

The source owner remains `src/aitacmod.cpp`. The header owner remains
`include/aitacmod.h`, which this worker did not edit.

## Changes

The constructor definition now uses the recovered PDB names `pW` and `playerID`.
The argument types and order remain `void*`, `int`, then `playerID`, `pW` in the
base constructor call. The function definitions now use 1TBS brace placement.
The leading empty line was removed. No statements, casts, types, scopes, calls,
literals, or public declarations changed.

No new names were invented. No public function, class, member, global, or ABI
symbol was renamed.

## PDB coverage and name evidence

The scoped PDB is `inventory/pdb/scoped_symbols.json`, with SHA256
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
Its source path is `C:\\msdev\\work\\age1_x1\\aitacmod.cpp`. It contains all
three procedures from `.\\Release\\aitacmod.obj`:

| VA | Procedure and registry status | PDB coverage | Parameters, locals, and registers |
| --- | --- | --- | --- |
| `00412B50` | `TacticalAIModule::TacticalAIModule`; registry `matching` | 42 bytes; source lines 24-26; line records at 24 and 26 | `pW` at `+0x4`, `void*`; `playerID` at `+0x8`, `int`; `this` in `ECX`; no statics or additional locals |
| `00412B80` | `TacticalAIModule::scalar deleting destructor`; compiler generated and not a normal registry owner | 30 bytes; no source-line record in the scoped entry | `__flags` at `+0x4`, `unsigned int`; `this` in `ECX`; no statics or additional locals |
| `00412BA0` | `TacticalAIModule::~TacticalAIModule`; registry `matching` | 11 bytes; source line 31; one line record | `this` in `ECX`; no stack symbols, statics, or additional locals |

The inventory packets confirm the normal function boundaries and source records:

- `inventory/functions/0041/00412B50_TacticalAIModule.txt`, SHA256
  `add19ceeda9c26cdf508fb8d630ae607928efd0d0ca444270453b9fe7b1daa20d`.
  Its Ghidra excerpt labels the stack values `param_1` and `param_2`; the PDB
  names `pW` and `playerID` take precedence.
- `inventory/functions/0041/00412BA0_TacticalAIModule.txt`, SHA256
  `c7f03a2f12e039578ade85525d22a2833e04b5f03575a3d300525386b6bf096d`.
  It confirms the destructor source line and `00412BA0-00412BAA` body range.

There are no uncertain reused-stack-slot mappings. The generated deleting
destructor's `__flags` is compiler data, not a handwritten declaration, so it
has no source-name mapping to recover.

## Constants and comments evidence

The constructor keeps the original string literal `"TacAI"`, numeric ID `0x3F1`,
and call order. The original PE is
`orig/empiresx.exe`,
SHA256
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The inventory assembly at `00412B50` shows `push 3F1h`, the `TacAI` string
address, both argument loads, and `call 0040E2D0`. The destructor assembly shows
the derived vptr store at `00412BA0` and the tail jump to
`AIModule::~AIModule` at `0040E360`. The existing two-line destructor comment
records this non-obvious ownership behavior and remains supported by that
assembly evidence. No new comment was added.

This module has no resource lookup or resource ID. Therefore there are zero
per-ID resource records, no resource extraction, and no shared resource-header
request. Runtime language hashes, language IDs, lookup paths, and payload results
are not applicable.

## Generation-risk notes

Parameter spelling changes do not affect the function type or emitted instructions.
The 1TBS changes only brace placement and do not change executable structure.
The leading blank-line removal and source formatting can change debug line records;
line-record changes are expected cleanup metadata drift. No object layout, ABI,
calling convention, type, storage, literal, relocation, call target, or symbol
identity change is intended. The preserved baseline object is
`build/source-cleanup-20260915/preparation/baseline-build/aitacmod.obj`, SHA256
`1016d21e778b76ec64d3c00c28a64dfb78882908e7856a296845ac757282f2d6`.

## Validation status

Evidence extraction ran with `tools/extract_original_function.py` for
`00412B50` (42 bytes) and `00412BA0` (11 bytes). It produced temporary evidence
under `build/asm/`. No compiler or validation command was used.

Compilation, matching, audits, and tests were not run.
