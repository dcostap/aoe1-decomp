# Toolchain CRT conversion/io helper audit report

Date: 2026-04-22

## Scope explored

- `inventory/functions/0055/00557E70_atodbl.txt`
- `inventory/functions/0055/00557EA8_FUN_00557ea8.txt`
- `inventory/functions/0055/00557EF0_atoflt.txt`
- `inventory/functions/0055/00557DF0_ld12told.txt`
- `inventory/functions/0055/00557950_ZeroTail.txt`
- `inventory/functions/0055/005579C0_IncMan.txt`
- `inventory/functions/0055/005586C0_FUN_005586c0.txt`
- `inventory/functions/0055/0055878E_FUN_0055878e.txt`
- `inventory/functions/0055/0055885E_FUN_0055885e.txt`
- `inventory/functions/0055/005588F0_strgtold12.txt`
- `tools/generate_toolchain_supplied_manifest.py`

## Goal

Audit the next high-confidence CRT/runtime neighborhood and decide which entries can be
strictly removed from the normal manual C/C++ corpus.

## High-confidence conclusions

### 1) A large set of named CRT/runtime helpers in this neighborhood is safe for exact-name exclusion

This pass promotes the following kinds of names into the generator's conservative
exact-name safe set:

- long-double / string-conversion helpers
  - `__ZeroTail`
  - `__IncMan`
  - `__RoundMan`
  - `__CopyMan`
  - `__FillZeroMan`
  - `__IsZeroMan`
  - `__ShrMan`
  - `__ld12cvt`
  - `__ld12tod`
  - `__ld12tof`
  - `__ld12told`
  - `__atodbl`
  - `__atoflt`
  - `__fptostr`
  - `__fltout`
  - `___dtold`
  - `__fptrap`
- obvious standard CRT helpers
  - `getenv`
  - `ungetc`
  - `wctomb`
  - `mbtowc`
  - `__mbbtype`
  - `__setmode`
- obvious compiler helpers
  - `__aulldiv`
  - `__aullrem`
  - `__allshl`

These names are standard CRT/compiler-runtime surfaces, have no PDB source, and do not
look like game-authored functions.

### 2) `FUN_00557ea8` is a hidden CRT wrapper: `__atoldbl`

High-confidence evidence:

- the listing excerpt labels `FUN_00557ea8` as `__atoldbl`,
- the body calls `___strgtold12` and then `__ld12told`,
- it is structurally the long-double sibling of nearby named wrappers `__atodbl` and `__atoflt`.

Strict conclusion:

- this is toolchain-supplied,
- but because the inventory name is still `FUN_00557ea8`, it is safest to classify it by
  exact VA region, not by a guessed manifest name.

### 3) `FUN_0055878e` is a hidden CRT helper: `__fcloseall`

High-confidence evidence:

- the listing excerpt labels `FUN_0055878e` as `__fcloseall`,
- the body iterates over `__nstream` / `___piob`,
- and it calls `fclose` and `free` in a standard CRT cleanup pattern.

Strict conclusion:

- this is toolchain-supplied,
- and again the safest classification is by exact VA region because the inventory name is still `FUN_...`.

## Applied region classifications

This pass adds two exact toolchain helper regions:

- `00557EA8-00557EE7` — hidden CRT wrapper `__atoldbl`
- `0055878E-005587F7` — hidden CRT helper `__fcloseall`

## Important strict non-action

I did **not** classify every nearby unnamed helper automatically.

Examples intentionally left alone for now:

- `FUN_005586c0`
- `FUN_0055885e`

Reason:

- they likely are CRT-adjacent helper/data artifacts,
- but this pass did not produce the same level of direct hidden-name evidence as for
  `FUN_00557ea8` and `FUN_0055878e`.

That is deliberate strictness, not hesitation.

## Bottom line

This neighborhood contains a mixture of:

- clearly named CRT/compiler-runtime functions that are safe for exact-name exclusion,
- and a couple of unnamed but high-confidence hidden CRT wrappers that are safest to
  exclude by exact VA region.

That is the strict classification applied here.
