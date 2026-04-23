# Toolchain FPU control helper audit report

Date: 2026-04-22

## Scope explored

- `inventory/functions/0055/00557710_statusfp.txt`
- `inventory/functions/0055/00557730_clearfp.txt`
- `inventory/functions/0055/00557750_control87.txt`
- `inventory/functions/0055/00557790_controlfp.txt`
- `inventory/functions/0055/005577A8_FUN_005577a8.txt`
- `inventory/functions/0055/005577E0_FUN_005577e0.txt`
- `inventory/functions/0055/00557880_FUN_00557880.txt`
- `inventory/functions/0055/00557910_FUN_00557910.txt`

## Goal

Decide whether the unnamed neighborhood immediately after the CRT FPU-control functions
belongs in the normal manual C/C++ corpus or should be classified as toolchain-supplied
helper machinery.

## High-confidence conclusion

The region

- `005577A8-00557946`

is a **toolchain-supplied helper island**, not project-authored code.

It is now tracked via `config/toolchain_supplied_regions.txt`.

## Why this is high confidence

### 1) It sits directly on top of known CRT FPU-control functions

Named CRT functions immediately adjacent to the island:

- `__statusfp` at `00557710`
- `__clearfp` at `00557730`
- `__control87` at `00557750`
- `__controlfp` at `00557790`

All have no PDB source file and standard CRT-style names/behavior.

### 2) Every unnamed body is used only as internal helper machinery for that CRT cluster

Representative evidence:

- `005577A8_FUN_005577a8`
  - listing excerpt labels it `__fpreset`
  - performs `FNINIT`, calls `__setdefaultprecision`, and updates exception state
- `005577E0_FUN_005577e0`
  - referenced by `__control87`
  - converts CRT control flags into x87 control-word bits
- `00557880_FUN_00557880`
  - also referenced by `__control87`
  - converts x87 control-word bits back into CRT control flags
- `00557910_FUN_00557910`
  - referenced by both `__statusfp` and `__clearfp`
  - converts status-word bits into CRT-style status flags

These are all textbook runtime helper relationships, not free-standing game functions.

### 3) The bodies are tight conversion/helpers, not normal app code

The unnamed functions are all tiny and self-contained:

- bitfield/flag translation logic,
- direct FPU state interaction,
- or runtime reset/setup logic.

There is no evidence of project-specific globals, game data structures, or game-side call
patterns.

### 4) Region-based exclusion is the cleanest strict classification

Using a small exact VA range is safer than trying to overfit hidden helper names into the
name manifest, because:

- the inventory names are still `FUN_...`,
- some helper names only appear in listing excerpts,
- and the region is compact, coherent, and directly bounded by the known CRT cluster.

## Classification summary

| Inventory entry | Evidence-based conclusion |
|---|---|
| `005577A8_FUN_005577a8` | hidden `__fpreset`; CRT reset helper |
| `005577E0_FUN_005577e0` | `__control87` internal flag-conversion helper |
| `00557880_FUN_00557880` | `__control87` internal reverse-conversion helper |
| `00557910_FUN_00557910` | `__statusfp` / `__clearfp` status conversion helper |

## Policy outcome

This neighborhood should be classified as:

- `toolchain_supplied` by **region**

not as:

- normal manual C/C++ decomp work,
- and not as handwritten asm.

## Bottom line

This is a CRT FPU-control helper island. It is tightly anchored to `__statusfp`,
`__clearfp`, `__control87`, and `__controlfp`, and it contains no credible evidence of
project-authored logic.
