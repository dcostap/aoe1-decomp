# `src/rmm_shal.cpp` cleanup report

## Delivery

- Module: `src/rmm_shal.cpp`
- Branch: `cleanup/staging-20260915-18`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Final source commit: `18ddffead707ce569cc7cf3dbb5542ef0a6c4d0`
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

The following local names were recovered from the procedure-scoped records and
assembly use. The source types and declaration structure did not change.

| PDB name | Previous source name | Evidence |
| --- | --- | --- |
| `tx1` | `path_x` | PDB stack record and path output use |
| `ty` | `path_y` | PDB stack record and path output use |
| `tx2` | `done` | PDB stack record and loop stop flag use |
| `end_y` | `min_x` | PDB stack record and lower bound use |
| `in_zone` | `max_x` | PDB stack record and upper bound use |
| `end_x` | `max_y` | PDB stack record and upper bound use |

The PDB reports `in_zone` as `float`. The source keeps its existing `long`
type because this cleanup does not change effective types or storage.

The PDB also records `x`, `y`, `stack`, and `terrain`. Those names were already
present and remain unchanged. The records `x1`/`ty2` share stack offset
`-0xd8`. The records `y1`/`ty` share stack offset `-0xc8`. The `end_x` record
covers reused lifetime evidence in the original assembly. The current source
uses separate declarations for some of these lifetimes. I did not merge or
rename `start_x`, `start_y`, `min_y`, `fill_x`, or `fill_y` across those reused
slots.

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
`index2`, `point1`, `point2`, `x`, `y`, `stack`, `terrain`, `tx1`, `ty`, `tx2`,
`end_y`, `in_zone`, and `end_x`.

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
