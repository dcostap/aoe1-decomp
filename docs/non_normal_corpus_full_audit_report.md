# Non-normal corpus and no-PDB-source full audit

Date: 2026-04-27

## Scope

This pass reviewed:

1. every function currently classified as `toolchain_supplied`, `asm_special`, or `asm_region`, and
2. every still-`normal` function that does not have a PDB-backed `.cpp`/`.c` source file attached.

The intent was to catch false-positive non-normal classifications and to identify any remaining no-source functions that should be moved out of the ordinary C/C++ matching queue.

## Commands run

- `python tools\generate_toolchain_supplied_manifest.py`
- `python tools\generate_status_dashboard.py`

Machine-readable audit outputs written during this pass:

- `build\non_normal_corpus_audit.tsv`
- `build\normal_no_pdb_cpp_source_audit.tsv`
- `build\normal_no_pdb_source_remaining.tsv`
- `build\orphan_unclaimed_no_pdb_remaining.tsv`

## Non-normal corpus result

Current corpus counts after this audit:

| Bucket | Count | PDB-source-backed entries |
|---|---:|---:|
| `toolchain_supplied` | 1519 | 0 |
| `asm_special` | 8 | 0 |
| `asm_region` | 575 | 0 |
| **Total non-normal** | **2102** | **0** |

The review queue reports are now empty:

- `build\toolchain_hidden_label_unhandled_candidates.tsv`: 0 data rows
- `build\toolchain_probable_helper_island_candidates.tsv`: 0 data rows

## Fix made during this pass: local `Dib.cpp` `memmove`

The audit found one real false positive in the toolchain supplied name manifest:

- `0043AB50 memmove`
  - PDB source: `Dib.cpp:1770-1776`
  - evidence: line records and listing show a small local backward-copy helper called by `DibMapToPalette`
  - conclusion: this is not the CRT `memmove`; keep it in the normal corpus

Applied fix:

- removed global exact-name classification for `memmove` from `tools\generate_toolchain_supplied_manifest.py`,
- regenerated `config\toolchain_supplied_functions.txt`, and
- widened the CRT memmove region from `0055740B-005576CF` to `005573B0-005576CF` so the real CRT `005573B0 memmove` remains classified by VA region rather than by unsafe exact name.

Current `memmove` state:

| VA | Source | Bucket | Reason |
|---|---|---|---|
| `0043AB50` | `Dib.cpp` | `normal` | PDB-backed local helper |
| `005573B0` | none | `toolchain_supplied` | CRT memmove region |

## Toolchain manifest regeneration notes

The regenerated exact-name manifest also keeps two previously reviewed safe additions:

- DPLAYX ordinal-import thunks exposed by Ghidra labels:
  - `_DirectPlayCreate@12`
  - `_DirectPlayLobbyCreateA@20`
  - `_DirectPlayEnumerateA@8`
- VC runtime helper:
  - `` `vector_constructor_iterator' ``

These have no PDB source and are still high-confidence toolchain/import material.

## Non-normal source-file cleanup

A follow-up cleanup removed the 38 old compiler-facing source files for functions now classified as non-normal:

| Bucket | Removed matching source files | Remaining compiler-facing source files |
|---|---:|---:|
| `toolchain_supplied` | 31 | 0 |
| `asm_region` | 7 | 0 |
| `asm_special` | 0 | 0 |

After regenerating the dashboard, no `toolchain_supplied`, `asm_special`, or `asm_region` entry has a `src\matching\...`, `src\scratch\...`, `src\accepted_drift\...`, or `src\verified_logic\...` owner.

## Still-normal functions with no PDB-backed `.cpp`/`.c` source

There are 477 normal functions whose PDB source is not a `.cpp`/`.c` file. Breakdown:

| Category | Count | Decision |
|---|---:|---|
| PDB header inline/header-declared normal functions | 141 | keep normal |
| compiler-generated class deleting destructors | 191 | keep normal/manual helper targets |
| compiler-generated class destructors | 100 | keep normal/manual helper targets |
| `TRIBE_Tech` / `TRIBE_Player_Tech` gameplay cluster with missing PDB lines | 28 | keep normal |
| named padding/thunk/local labels | 13 | keep normal; already exact or harmless padding-style local labels |
| local compiler cleanup labels | 3 | keep normal; localized game-code funclet labels |
| padding/local generic label | 1 | keep normal; exact NOP padding label |

Source status for these 477:

| Source status | Count |
|---|---:|
| `matching` | 441 |
| `scratch` | 5 |
| `unclaimed` | 31 |

## Still-normal functions with no PDB source at all

There are 336 normal functions with no PDB source file at all. Breakdown:

| Category | Count | Decision |
|---|---:|---|
| compiler-generated class deleting destructors | 191 | keep normal/manual helper targets |
| compiler-generated class destructors | 100 | keep normal/manual helper targets |
| `TRIBE_Tech` / `TRIBE_Player_Tech` gameplay cluster | 28 | keep normal gameplay code |
| named padding/thunk/local labels | 13 | keep normal; already exact or harmless local labels |
| local compiler cleanup labels | 3 | keep normal |
| padding/local generic label | 1 | keep normal |

Source status for these 336:

| Source status | Count |
|---|---:|
| `matching` | 303 |
| `scratch` | 2 |
| `unclaimed` | 31 |

The remaining unclaimed no-PDB normal functions are listed in:

- `build\orphan_unclaimed_no_pdb_remaining.tsv`

They are intentionally left in the normal queue:

- 27 `TRIBE_Tech` / `TRIBE_Player_Tech` gameplay-cluster entries, including two class destructors,
- 4 class-specific vector deleting destructors.

## Dashboard note

After deleting the redundant non-normal source files and regenerating the dashboard, there are no source-owner conflicts in `project_full_status.csv`.

## Bottom line

The full pass found and fixed one unsafe non-normal exact-name classifier (`memmove`) and removed 38 redundant compiler-facing source files for entries now classified as non-normal. All current non-normal entries have no PDB-backed source file and no source owner under `src\...`; the remaining no-`.cpp`/`.c` normal functions are explainable as header inlines, class compiler helpers, localized padding/funclet labels, or real `TRIBE_Tech` gameplay code that should stay in the ordinary matching corpus.
