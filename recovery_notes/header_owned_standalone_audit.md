# Header-owned standalone audit

Status: complete.

This audit removes duplicate source-bank probes for header-owned and generated
functions. The original inventory and PDB records remain the evidence source.

## Final counts

| Group | Count |
| --- | ---: |
| Valid unresolved header-owned standalone rows | 101 |
| Normal canonical-owner rows without duplicate probes | 6 |
| Newly classified compiler-generated rows | 29 |
| Existing intentional unclaimed exceptions | 60 |
| Normal corpus rows | 5,428 |
| Compiler-generated corpus rows | 256 |

The six normal rows remain in the normal corpus. Their standalone probes are
removed because their canonical bodies already exist:

- `00424DD0` and `00424E30`: `include/com_addr.h` (`IPAD` constructor and
  destructor).
- `00426450`, `004264A0`, `004265E0`, and `00426600`:
  `src/com_hand.cpp` with declarations in `include/com_hand.h` (`RESENDER`
  and `HOLDER` constructors and destructors).

The deleted files for these rows were duplicate probes, not source owners.
The inventory records their PDB header or source-module ownership.

`004147A0` remains a normal unresolved standalone row. Its PDB record proves
protected `ManagedArray<int>::resize(int)` ownership, but reconstructed external
callers still depend on the current public header access. The standalone source
keeps this access debt visible until the owner boundary is resolved.

## Newly classified generated rows

The manifest adds these rows:

- `00408D20`, `004EA750`, and `004F1390`:
  `compiler_generated_template_instantiation` for `ManagedArray<int>` methods
  emitted from `include/utmarray.h`.
- `00404A00`, `00404C80`, `00406DB0`, `0041A200`, `00441A60`, `004754B0`,
  `004CCB10`, `004CCBF0`, `004CD200`, `004CDA80`, `004CE5E0`, `004CE980`,
  `004CF120`, `004D1710`, `004D2700`, `004D3970`, `004E68F0`, `00509760`,
  `0050D4A0`, `00520E20`, `0052AB80`, `0052CA20`, and `0053D3A0`:
  `compiler_generated_destructor` bodies.
- `00463BA0`, `00463BC0`, and `00463BD0`:
  `compiler_generated_static_initializer` entries for the `E4`, `E3`, and
  `E2` startup and cleanup sequence.

The 26 PDB-less rows have no PDB source file or line record. Their inventory
records and Ghidra listings show either a direct jump to the base destructor
or the static initializer sequence. This is generated evidence, not a new
normal source owner.

## Deleted-file verification

All 29 generated source-bank files named by the manifest rows were deleted.
The three remaining `ManagedArray<int>` probes are covered by the exact header
method records in `docs/utmarray_reconstruction.md`.
The 23 scalar-destructor probes have matching destructor symbols and direct
base-destructor evidence in `inventory/functions/` and the original Ghidra
listings. The three `00463BA0`-`00463BD0` probes have the `E4`/`E3`/`E2`
sequence in `orig/ghidra_decomp/bucket_0463.{asm,decomp}`.

The six normal duplicate probes have named canonical owners above. No deleted
file lacks either a canonical body or generated evidence.
