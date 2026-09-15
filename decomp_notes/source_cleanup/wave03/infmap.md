# Source cleanup: `src/infmap.cpp`

## Handoff

- Module: `src/infmap.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source cleanup commit: `7da15a7b1921b5aa4610919ff2b55a6f3cc72a9d`
- Final report commit: this report commit; the full hash is in Git output and the final handoff.
- Branch: `cleanup/staging-20260915-139`
- Changed paths:
  - `src/infmap.cpp`
  - `decomp_notes/source_cleanup/wave03/infmap.md`

The source commit changes only the assigned source. The report commit changes
only this assigned report.

## Scope and evidence

I read the repository contract and the complete source-cleanup, source-comment,
resource-ID, ownership, resource, and testing guides. I read `include/infmap.h`
but did not edit it.

I inspected all 21 normal `InfluenceMap` registry entries and the compiler-
generated scalar deleting destructor entry. I read every selected packet under
`inventory/functions/0044/`, the procedure-scoped PDB records, the module notes,
and the source registry.

The PDB source is:

`C:\\msdev\\work\\age1_x1\\infmap.cpp`

The scoped PDB evidence file is:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The original executable is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The original executable remains the behavior oracle cited by packet evidence.
It was not executed.

## Cleanup result

The source changes restore PDB-backed parameter and local names. They also apply
1TBS function-brace placement. They keep source order, declaration scopes,
types, storage duration, statements, expressions, calls, casts, literals,
control flow, and public symbols.

The source keeps these proven behavior constraints:

- `0044E680` compares both Y bounds with `xSizeValue`.
- `0044E800` compares both Y bounds with `xSizeValue`.
- `0044E9E0` keeps the case-zero fall-through into the case-seven suffix.

The existing comments for the two Y-bound bugs remain. No source comment was
added.

## PDB recovery coverage

Every row below was checked against its packet and scoped PDB record. `this` is
in ECX for every normal and generated member-function record.

| VA | Registry status | PDB names and source result |
| --- | --- | --- |
| `0044DF80` | `matching` | Restored constructor parameters `x`, `y`, and `initialValue` from `xSize`, `ySize`, and `fillValue`. |
| `0044E030` | compiler-generated | Scalar deleting destructor. PDB records `this` and `__flags`. It has no handwritten source owner and was not edited. |
| `0044E050` | `matching` | Restored `infile` from `fd`. |
| `0044E080` | `matching` | PDB has only `this`. No source name change was needed. |
| `0044E0B0` | `matching` | Restored `initialValue` from `value`. |
| `0044E0F0` | `matching` | Restored `outfile` from `fd`. Restored the outer row cursor `j` from the PDB `j` record. The inner cursor uses `i`; no separate scoped PDB record maps it. |
| `0044E1A0` | `matching` | Restored `infile` from `fd` and `tempBYTE` from `b`. The PDB `j` record and packet storage map to the outer row cursor `j`; the inner cursor uses `i` without a separate scoped record. |
| `0044E250` | `accepted_drift` | `filename` already matched the PDB. Restored the row cursor `j` from the inferred `r` name. The column cursor `i`, file pointer `f`, `next`, and `val` have no safe scoped records and remain unchanged. |
| `0044E4C0` | `matching` | Parameters `x` and `y` already matched the PDB. |
| `0044E4E0` | `matching` | Parameters `x` and `y` already matched the PDB. |
| `0044E510` | `matching` | Parameters `x` and `y` already matched. Restored `v` from `value`. |
| `0044E560` | `matching` | Restored parameters `minX`, `minY`, `maxX`, `maxY`, and `v`. Restored the outer row cursor `j` from `y`; the PDB `j` record shares the `minY` stack slot. The inner cursor has no separate scoped record. |
| `0044E600` | `matching` | Parameters `x` and `y` already matched. Restored `v` from `value`. |
| `0044E680` | `matching` | Restored parameters `minX`, `minY`, `maxX`, `maxY`, and `v` from the prior coordinate and `amount` names. Existing `y`, `x`, and `value` locals have no scoped PDB records and remain unchanged. |
| `0044E790` | `matching` | Parameters `x` and `y` already matched. Restored `v` from `amount`. |
| `0044E800` | `matching` | Restored parameters `minX`, `minY`, `maxX`, `maxY`, and `v` from the prior coordinate and `amount` names. Existing `y`, `x`, and `value` locals have no scoped PDB records and remain unchanged. |
| `0044E900` | `matching` | Restored parameters `min`, `max`, and `valueLevel` from `from`, `to`, and `threshold`. The PDB `i` record aliases a receiver spill in the packet. It was not forced onto a source loop variable. |
| `0044E9E0` | `accepted_drift` | Restored `min`, `max`, `valueLevel`, `countOrthogonalEdgesAsConnections`, `countDiagonalEdgesAsConnections`, and `countDiagonalConnections`. Restored loop names `i` and `j` from the PDB records and packet stack roles. Existing `self`, `rows`, `xOffset`, `neighborX`, `neighborY`, and `direction` have no scoped PDB records and remain unchanged. |
| `0044EC00` | `matching` | Parameters `min`, `max`, `valueLevel`, and `newValueLevel`, plus locals `rVal` and `i`, already matched the PDB. The PDB local `i` shares a parameter stack slot; the existing declaration was retained. |
| `0044ED20` | `accepted_drift` | Parameters `min`, `max`, `valueLevel`, `newValueLevel`, `countOrthogonalEdgesAsConnections`, `countDiagonalEdgesAsConnections`, and `countDiagonalConnections`, plus locals `rVal`, `i`, and `j`, already matched the PDB. Reused stack slots were not used to change declarations. |
| `0044F030` | `matching` | Restored `uL` from `value`. |
| `0044F040` | `new_verified_logic` | PDB has only `this`. Existing locals remain unchanged. |

The PDB name `__flags` belongs to the generated destructor. It is not a
handwritten declaration. No public function, class, member, global, type,
virtual slot, calling convention, layout, or ABI symbol changed.

## Recovered names and cleanup names

The recovered original names are the names listed in the PDB coverage table.
They include the mixed-style names `initialValue`, `tempBYTE`, `minX`, `valueLevel`,
`countOrthogonalEdgesAsConnections`, `rVal`, `i`, `j`, and `uL`.

No new word-based descriptive parameter or local name was invented. The inner
`i` cursors in `save` and `load` are inferred loop names after the PDB-backed
outer row cursors were restored to `j`. Existing inferred names remain where
the scoped record did not map safely. In particular, the source does not force
PDB names onto reused receiver or parameter stack slots.

## Constants, resources, and comments

No numeric constant or enum was added. The existing module-local print format
strings remain unchanged. They are ordinary format data, not resource IDs.

This module has no resource lookup. It calls `rge_read`, `rge_write`, `fopen`,
and `fprintf`, but it does not pass a language-table ID. No resource extraction
or resource-ID request is needed.

The existing comments for the `xSizeValue` Y-bound behavior remain at
`0044E680` and `0044E800`. No comment was added, removed, or rewritten.

## Header and shared-file requests

`include/infmap.h` was read but not edited. This assignment requires no header
change. Header parameter names can remain different because they do not affect
the function type, symbol, calling convention, or ABI. A future header owner
can synchronize declaration names if that is desired, but no request is needed
for this source cleanup.

No other shared file was changed or requested.

## Code-generation and behavior risk

The edits rename existing identifiers and move existing function opening braces
onto the definition line. The source keeps every declaration scope, type,
initializer, statement, expression, cast, call target, literal, branch, and
return. The loop-name changes keep the same declarations and storage roles.

These edits should not change machine instructions, data, relocations, or call
targets. That claim is not validated. Parameter and local names can change PDB
records. Brace placement can change compiler line records. The prior registry
accepted-drift status for `0044E250`, `0044E9E0`, and `0044ED20` remains
unchanged. Module notes also record scratch histories for `0044E600`,
`0044E9E0`, and `0044ED20`. These issues remain unresolved by this cleanup.

## Validation status

I reviewed the complete source diff against the base commit and checked that
only the two assigned paths changed. No compiler or build command was run.
Compilation, matching, audits, tests, and game execution were **NOT run**.
Generated code, program data, relocations, call targets, and runtime behavior
remain unvalidated.
