# `src/airchmod.cpp` cleanup

## Delivery

- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Head commit for the source cleanup: `9a0dbca8480bf09e23927a6b9e548b65a9c1fa0c`
- Changed files:
  - `src/airchmod.cpp`
  - `decomp_notes/source_cleanup/wave02/airchmod.md` (this report)
- The assigned header `include/airchmod.h` was read but not changed.

The source cleanup restores procedure-scoped PDB names and applies 1TBS brace
formatting. It does not change statements, types, storage, calls, literals, or
source order.

## Evidence

The name source is the procedure-scoped PDB inventory:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- SHA-256: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff033b`
- PDB source path: `C:\msdev\work\age1_x1\airchmod.cpp`
- PDB object module: `.\\Release\\airchmod.obj`

The assigned function packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0041/` supplied the
procedure boundaries, line spans, sizes, and original instruction evidence.
The original behavior-oracle PE is
`orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

## PDB coverage and name recovery

All 13 functions in `config/functions/src/airchmod.cpp.json` have procedure
records. Every record has the expected `this` register. Stack parameters and
locals below are the complete scoped-symbol entries for each function.

| VA | PDB coverage | Scoped parameters and locals | Change |
| --- | --- | --- | --- |
| `00411670` | 169 bytes; lines 26-30; 3 line records | `pW` (`void*`), `playerID` (`int`); `this` in `ecx` | Recovered `pW` from `ptr`; recovered `playerID` from `arg`. |
| `00411740` | 512 bytes; lines 38-75; 17 line records | `playerID` (`int`), `infile` (`int`); `i`, `tempInt`, `name` (`char[257]`), `typeID`, `newRCost` (`ResourceItem`), `rc` (`int[4]`); `this` in `ecx` | Recovered `playerID` from `file`; recovered `infile` from `arg2`. |
| `00411940` | 105 bytes; lines 80-83; 4 line records | No stack symbols; `this` in `ecx` | No scoped name change. |
| `004119B0` | 13 bytes; lines 88-90; 2 line records | `m` (`MainDecisionAIModule*`); `this` in `ecx` | Recovered `m` from `value`. |
| `004119C0` | 378 bytes; lines 95-129; 17 line records | `outfile` (`int`), `tempString` (`char[257]`), `tempInt`; `this` in `ecx` | Recovered `outfile` from `file`. |
| `00411B40` | 27 bytes; lines 134-139; 5 line records | `id` (`int`); `this` in `ecx` | `id` already matched the PDB. |
| `00411B60` | 8 bytes; lines 144-147; 2 line records | `bi` (`BuildItem*`); `this` in `ecx` | Recovered `bi` from `item`. |
| `00411B70` | 3 bytes; line 152; 1 line record | `bi` (`BuildItem*`); `this` in `ecx` | Recovered `bi` from `item`. |
| `00411B80` | 637 bytes; lines 159-206; 27 line records | `lName` (`char*`), `temp` (`char[256]`), `id` (`int`), `name` (`char[64]`), `newRCost` (`ResourceItem`), `rc` (`int[4]`); `this` in `ecx` | Recovered `lName` from `filename`; recovered `newRCost` from `newRCost2`. |
| `00411E00` | 7 bytes; lines 211-213; 2 line records | No stack symbols; `this` in `ecx` as `const ResearchAIModule*` | No scoped name change. |
| `00411E10` | 7 bytes; lines 218-220; 2 line records | No stack symbols; `this` in `ecx` | No scoped name change. |
| `00411E20` | 66 bytes; lines 225-236; 8 line records | No stack symbols; `this` in `ecx` | No scoped name change. |
| `00411E70` | 69 bytes; lines 241-251; 9 line records | `id` (`int`); `this` in `ecx` | Recovered `id` from `tech_id`. |

The PDB confirms these original spellings, including mixed case: `pW`,
`playerID`, `infile`, `m`, `outfile`, `bi`, `lName`, `tempInt`, `tempString`,
`typeID`, `newRCost`, `rc`, and `id`.

## Invented and unresolved names

The source had no `param_*`, `local_*`, or decompiler-style `iVar*` names.
The following source locals are not present in the scoped PDB records. Their
storage mappings are therefore uncertain, and the declarations remain in place:

- `00411670`: `head`.
- `00411740`: `head`, `j`, `p`, `item`, and the cleanup name `old_tail`.
- `004119C0`: `item`, `end`, `cost`, and `i`.
- `00411B40`: `tech`.
- `00411B80`: `fp`, `item`, `tail`, `alloc`, and the cleanup name `old_tail`.
- `00411E20`: `node` and `next`.
- `00411E70`: `item` and `end`.

`oldTail` was changed to the invented snake-case name `old_tail`. The other
names above were retained because the PDB does not prove a different mapping.
They are not claimed as original developer names.

Two type discrepancies remain unresolved and were not changed:

- The PDB records `00411740`'s `name` as `char[257]`, while the existing source
declaration is `char name[0x104]`.
- The PDB records `00411B80`'s `id` as `int`, while the existing source uses
`char* id` for the copied technology-tree name.

The name evidence does not authorize changing either type or declaration size.

## Constants, resources, and comments

No constants were added or renamed. Existing values and forms remain unchanged,
including `0x3ee`, serialized width `4`, loop bound `4`, buffer size `0x100`,
`"NONE"`, `.tmp`, and all format strings. No existing symbol proves a shared
replacement for these values in this module.

This module has no resource-ID lookup. It has no language, menu, dialog, or
string-table resource request. Per-ID text, missing, empty, language, lookup,
and purpose evidence is therefore not applicable. No shared declaration request
was made. No source comment was added; the existing code and the durable report
cover the non-obvious null branch and the `rc[5]` serialization model.

The `id == 0` branch in `loadTechnologyTree` remains unchanged. The recovered
notes identify that branch as unreachable after `id` receives the member-array
address. The source also retains the original `strcpy(0, "NULL")` statement.
The five-element `rc` array in that function remains unchanged because the
original `sscanf` call writes `rc[0]` through `rc[4]`.

## Generation-risk notes

- Changes are local identifier renames and opening-brace placement only.
- No function, class, member, ABI symbol, signature type, layout, declaration
scope, evaluation order, call target, literal, or source-order change was made.
- The PDB line records can differ after formatting. No compiler or byte check was
run to measure that effect.
- The type and stack-size discrepancies listed above remain possible sources of
future generation drift.

Compilation, matching, audits, and tests were not run.
