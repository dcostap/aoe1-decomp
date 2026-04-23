# Toolchain helper-island audit report

Date: 2026-04-22

## Scope explored

- `inventory/functions/0055/005573B0_memmove.txt`
- `inventory/functions/0055/0055740B_FUN_0055740b.txt`
- `inventory/functions/0055/00557579_FUN_00557579.txt`
- `inventory/functions/0055/005575EF_FUN_005575ef.txt`
- `inventory/functions/0055/00557621_FUN_00557621.txt`
- `inventory/functions/0055/0055768E_FUN_0055768e.txt`
- `inventory/functions/0054/0054DAC0_memcpy.txt`
- `inventory/functions/0054/0054DB1B_FUN_0054db1b.txt`
- `inventory/functions/0054/0054DC89_FUN_0054dc89.txt`
- `inventory/functions/0054/0054DCFF_FUN_0054dcff.txt`
- `inventory/functions/0054/0054DD31_FUN_0054dd31.txt`
- `tools/generate_toolchain_supplied_manifest.py`
- `config/toolchain_supplied_functions.txt`

## Goal

Decide whether the suspicious unnamed islands around `memmove` and `memcpy` are real
manual decomp targets or toolchain/lib-supplied local helper machinery.

## High-confidence conclusions

### 1) These are toolchain/lib-supplied helper islands

Two mirrored neighborhoods are now high-confidence toolchain-supplied regions:

- `0055740B-005576CF` — `memmove` internal helper island
- `0054DB1B-0054DDDF` — `memcpy` internal helper island

Why this is high confidence:

- both islands sit immediately after named CRT functions `memmove` and `memcpy`,
- both are referenced directly from the parent CRT routine's switch/jump-table flow,
- both implement tail-copy / alignment / remainder handling in the same style,
- the second island is a near-structural mirror of the first at different addresses,
- all packets have no PDB source info,
- and the local names are generic unstable labels like `caseD_0`, `caseD_1`, `FUN_...`,
  exactly what we expect from internal helper fragments rather than project-authored functions.

Representative evidence:

- `0055740B_FUN_0055740b` is just a jump into `memmove`'s internal switch table.
- `00557579_FUN_00557579` and `005575EF_FUN_005575ef` are clearly remainder/alignment/tail-copy
  helpers for `memmove`.
- `0054DB1B_FUN_0054db1b`, `0054DC89_FUN_0054dc89`, and `0054DCFF_FUN_0054dcff` are the matching
  `memcpy` family helpers.
- `00557621_FUN_00557621` and `0054DD31_FUN_0054dd31` are not meaningful independent functions;
  they are table/landing glue inside the same helper islands.

## Important strictness correction

At first glance the second suspicious neighborhood looked like it might be related to
`strtok`, but the evidence says otherwise.

Strict conclusion:

- the mirrored unnamed helper island belongs to `memcpy`,
- **not** to `strtok`.

`strtok` starts later at `0054DE00` and should be classified on its own exact-name merits,
not by absorbing the preceding helper island sloppily.

## Why region-based toolchain classification was required

A plain function-name manifest is **not strict enough** for these islands, because they
contain duplicate generic names such as:

- `caseD_0`
- `caseD_1`

Those names are not unique across the whole binary, so excluding by name would be unsafe.

That is why this pass introduced:

- `config/toolchain_supplied_regions.txt`

This lets us exclude these CRT helper islands by exact VA range instead of by brittle
non-unique labels.

## Additional exact-name CRT additions

This pass also justified adding several obvious standard CRT/runtime names to the exact-name
safe set used by `tools/generate_toolchain_supplied_manifest.py`, including:

- `memcpy`
- `memmove`
- `memset`
- `ctime`
- `abort`
- `strtok`
- `__statusfp`
- `__clearfp`
- `__control87`
- `__controlfp`
- `__CxxSetUnhandledExceptionFilter`
- `__CxxRestoreUnhandledExceptionFilter`

These are high-confidence toolchain/lib-supplied names and do not belong in the normal
manual C/C++ queue.

## Policy outcome

For toolchain classification work:

1. Use exact-name manifests for obvious unique CRT/runtime names.
2. Use region manifests for local helper islands with duplicate generic labels.
3. Do **not** classify generic `caseD_*` names globally by name.
4. Prefer mirrored-implementation evidence and direct xref evidence before excluding.

## Bottom line

The `memmove` and `memcpy` helper islands are toolchain/lib-supplied internal machinery,
not project-authored decomp targets.

So the strict classification for this pass is:

- named CRT routines -> `toolchain_supplied` by exact name
- unnamed local helper islands -> `toolchain_supplied` by exact VA region
