# `src/rmm_shal.cpp` cleanup report

## Delivery

- Module: `src/rmm_shal.cpp`
- Branch: `cleanup/staging-20260915-18`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Prior source commit: `18ddffead707ce569cc7cf3dbb5542ef0a6c4d0`
- Final correction commit: `ee43991bfbbe042a2bdcdc778ce9ed3426c5b541`
- Changed files in the source commit:
  - `src/rmm_shal.cpp`
- The report is committed separately after the source commit.

## PDB coverage

I inspected all three registry VAs in `config/functions/src/rmm_shal.cpp.json`.
I inspected every scoped parameter, local, and register record in
`inventory/pdb/scoped_symbols.json`.

### `00487010` constructor

The PDB records these parameters:

- `in_map`: `RGE_Map*`
- `parent_module`: `RGE_Random_Map_Module*`
- `in_info`: `RGE_Shallows_Info*`
- `this`: `RGE_RMM_Shallows_Generator*` in `ecx`

All four names and types remain unchanged in the source.

### `00487050` `generate`

The PDB records:

- `index2`: `long` at stack offset `-0x8`
- `this`: `RGE_RMM_Shallows_Generator*` in `ecx`

`index2` and `this` remain unchanged. The PDB has no scoped records for the
other source locals. I did not claim those names as recovered originals.

### `00487200` `make_tribe_connections`

The PDB records these parameters and register:

- `point1`: `long`
- `point2`: `long`
- `this`: `RGE_RMM_Shallows_Generator*` in `ecx`

The source keeps all three names and types.

Two local names were recovered from direct procedure-scoped records and
assembly use. The source types and declaration structure did not change.

| PDB name | Previous source name | Evidence |
| --- | --- | --- |
| `tx1` | `path_x` | PDB stack record and path output use |
| `ty` | `path_y` | PDB stack record and path output use |

The `tx1` mapping is direct. At `00487245`, the second point's X value is
stored in the PDB `tx1` slot. At `00487268`, the function passes that slot to
`find_path` as the mutable X output. At `004872a6`, it reloads the same slot.

The `ty` mapping is also direct. At `00487252`, the second point's Y value is
stored in the PDB `ty` slot. At `0048725f`, the function passes that slot to
`find_path` as the mutable Y output. At `004872b2`, it reloads the same slot.

The following four PDB names remain unresolved reused-lifetime records. The
source keeps the descriptive names `done`, `min_x`, `max_x`, and `max_y`.

- `tx2` at stack offset `-0xc0` is not forced onto `done`.
- `end_y` is not forced onto `min_x`.
- `in_zone` is not forced onto `max_x`. The PDB type is `float`, while the
  source variable is `long`.
- `end_x` is not forced onto `max_y`. The PDB excerpt also shows reused
  lifetime evidence for this name.

The PDB `done` record is at stack offset `-0xc4`, separate from `tx2` at
`-0xc0`. The source keeps `done` as an unresolved descriptive name.

The PDB also records `x`, `y`, `stack`, and `terrain`. Those names were already
present and remain unchanged. The records `x1`/`ty2` share stack offset
`-0xd8`. The records `y1`/`ty` share stack offset `-0xc8`; the direct path
uses above identify `ty` before that later reuse. I did not merge or rename
`start_x`, `start_y`, `min_y`, `fill_x`, or `fill_y` across those reused slots.

The current source also retains `target_x`, `target_y`, `cost`, and
`terrain_type`. The PDB does not provide a reliable direct name mapping for
these declarations. The `generate` locals `i`, `j`, `count`, `index1`, and
`found` also remain descriptive names without scoped PDB records.

## Constants, resources, and comments

- No new constants were added.
- Existing terrain values and masks remain numeric and unchanged.
- No resource lookup or resource ID occurs in this module.
- No new source comment was added.
- The existing source comment was preserved.

## Recovered and retained names

Recovered or confirmed PDB names include `in_map`, `parent_module`, `in_info`,
`index2`, `point1`, `point2`, `x`, `y`, `stack`, `terrain`, `tx1`, and `ty`.

The cleanup did not invent a new identifier. Retained descriptive names remain
unclaimed as original names where the PDB has no direct record or where stack
slot reuse blocks a safe mapping.

## Code-generation-sensitive points

The source change only renames locals and moves function opening braces to 1TBS
style. It does not change calls, expressions, control flow, types, storage,
layout, declarations, ABI, or public symbols. No header was edited.

Brace changes can alter debug line records. No executable comparison was run.

## Header and resource requests

I read `include/rmm_shal.h` and made no header change. No header request is
needed. No resource-ID mapping is needed.

## Validation limits

Compilation, matching, audits, and tests were not run, as required for this
cleanup phase.
