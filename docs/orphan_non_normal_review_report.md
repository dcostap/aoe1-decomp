# Orphan no-PDB non-normal review report

Date: 2026-04-27

## Goal

Review currently unclaimed functions with no PDB-backed source file and move high-confidence non-normal material out of the ordinary C/C++ matching queue.

This pass focused on functions whose source file is absent from PDB line records, especially generic `FUN_...` islands and one-instruction/thunk-like helpers.

## Changes made

Updated non-normal manifests:

- `config/toolchain_supplied_regions.txt`
- `config/asm_special_regions.txt`
- `config/toolchain_supplied_functions.txt` via `tools/generate_toolchain_supplied_manifest.py`

Updated generator logic:

- `tools/generate_toolchain_supplied_manifest.py` now recognizes the three DPLAYX ordinal-import thunks whose import names are visible in Ghidra but not in the PE name table.
- The VC runtime `` `vector_constructor_iterator' `` helper is now in the safe exact-name runtime set.

## Newly classified toolchain/lib-supplied regions

### `005479A0-0054B17F`

External compression/decompression library block.

Evidence:

- no PDB source records for the whole block,
- public-looking compression entrypoints such as `deflate_data`, `deflate_init`, `deflate_deinit`, `_Inf32Decode`, and `_Inf32BufSize`,
- many generic local helpers coupled only to that compression state machine,
- table/state-machine dispatch and local exit codelets,
- xrefs from RGE file I/O rather than from normal gameplay source clusters.

### `0054B1D0-0056204F`

VC5 runtime / CRT / C++ standard-library and compiler-generated EH block.

Evidence:

- begins at `_JumpToContinuation` and continues through C++ EH runtime helpers,
- contains named CRT/string/stdio/math/io helpers, standard iostream/type_info methods, and many no-source `FUN_...` helper islands,
- later `0055C0A5-0056204F` style entries are compiler-generated EH handler thunks and cleanup funclets (`mov eax, FuncInfo; jmp ___CxxFrameHandler`, destructor cleanup funclets, etc.),
- no PDB source records in the block.

### Small compiler-generated thunk/funclet regions

Added small exact regions for isolated no-source compiler-generated helpers outside the large CRT block:

- `00460FC0-00460FC7` vcall thunk in the pathing neighborhood,
- `0046B050-0046B0E9` selected no-source EH cleanup funclets around `pathsys.cpp` helpers,
- `004D6AC0-004D6BA9` selected no-source EH cleanup funclets around `taiinfmd.cpp` helpers,
- `0052A970-0052A974` no-source thunk to a sibling `trig.cpp` helper label.

These were kept as narrow ranges because neighboring `$E...` labels in the same clusters already have PDB source or checked source files.

## Newly classified asm region

### `0044A4B9-0044AB84`

FLIC decoder optimized copy/dispatch codelet table.

Evidence:

- no PDB source records,
- starts with padding and a pointer/table-looking area that linear disassembly misreads as instructions,
- followed by repeated fixed-width copy codelets and `_x_StandardMemCopy`,
- immediately follows the PDB-backed `flics.cpp` decoder routines, but does not look like ordinary compiler-generated C/C++ output,
- better treated as handwritten/table-driven asm support than as one-function-one-`.cpp` work.

## Result

After the follow-up full audit in `docs/non_normal_corpus_full_audit_report.md` and the `memmove` false-positive fix, the regenerated dashboard reports:

- `toolchain_supplied` corpus count: `1519`
- `asm_region` corpus count: `575`
- unclaimed normal functions with no PDB source: `31`

The remaining 31 no-PDB normal unclaimed functions are intentionally left in the normal queue for now:

- 27 `TRIBE_Tech` / `TRIBE_Player_Tech` gameplay functions around `0050B840-0050D383`, which look like real game logic despite missing source-file records,
- 4 class-specific `` `vector_deleting_destructor' `` helpers around `00424AC0`, `004260F0`, `00426170`, and `00431790`, which are ordinary compiler-generated class helper targets rather than reusable toolchain/library code.

A machine-readable list of those remaining review targets is written to:

- `build/orphan_unclaimed_no_pdb_remaining.tsv`

## Notes

The broad CRT/runtime region intentionally overlaps older narrower toolchain helper-island regions. The older regions remain useful because `classify_corpus_bucket()` reports the first matching region reason, preserving more specific reasons for previously reviewed helper islands.
