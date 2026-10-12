# `rmm_land.cpp` cleanup report

## Delivery

- Module: `src/rmm_land.cpp`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Final source commit: `a7cbddbc8bee3f5c65c57317f821fb0834a37072`
- Base source blob: `613f5d61f40269f785b190c2214766e0fa92d5ce`
- Final source blob: `3b79a15d4300e907e5cfa9d8e2db85c507835ac6`
- Changed files:
  - `src/rmm_land.cpp`
  - `workflow/decomp_notes/source_cleanup/wave01/rmm_land.md`
- Header read but not changed: `include/rmm_land.h`

The source commit contains only the assigned source file. The report is the
second assigned change and is committed in the follow-up report commit.

## PDB coverage

The source owner is `C:\\msdev\\work\\age1_x1\\rmm_land.cpp`. I inspected all
five VAs in `config/functions/src/rmm_land.cpp.json` and their inventory
packets:

| VA | Symbol | PDB lines | Size | Registry status |
| --- | --- | ---: | ---: | --- |
| `00485200` | `RGE_RMM_Land_Generator::RGE_RMM_Land_Generator` | 25-29 | 59 | `matching` |
| `00485240` | `generate` | 33-51 | 133 | `matching` |
| `004852D0` | `check_terrain_and_zone` | 57-140 | 417 | `new_verified_logic` |
| `00485480` | `chance` | 146-208 | 159 | `accepted_drift` |
| `00485520` | `base_land_generate` | 213-353 | 1833 | `new_verified_logic` |

I inspected every procedure-scoped stack and register record in
`inventory/pdb/scoped_symbols.json`:

- `00485200`: stack parameters `in_map` (`+0x4`, `RGE_Map*`),
  `parent_module` (`+0x8`, `RGE_Random_Map_Module*`), and `in_info`
  (`+0xc`, `RGE_Land_Info*`); register `this` (`ecx`).
- `00485240`: no stack records; register `this` (`ecx`).
- `004852D0`: stack records `target` (`+0x4`, `uchar`), `land_num` (`+0x8`,
  `uchar`), `x` (`+0xc`, `long`), `y` (`+0x10`, `long`), `cy1` (`+0x14`,
  `long`), `y1` (`-0xc`, `long`), `cy0` (`+0x10`, `long`), `cx1` (`-0x10`,
  `long`), `x1` (`-0x4`, `long`), `cx0` (`-0x14`, `long`), `x0` (`-0x8`,
  `long`), `count` (`-0x1c`, `long`), `octogon_y0` (`-0x18`, `long`),
  `octogon_y1` (`-0x18`, `long`), and `zone` (`+0xc`, `uchar`); register
  `this` (`ecx`).
- `00485480`: stack parameters `x` (`+0x4`, `long`), `y` (`+0x8`, `long`),
  and `land_type` (`+0xc`, `long`); register `this` (`ecx`).
- `00485520`: stack records `tile` (`-0xaf8`, `RGE_Tile*`), `index2`
  (`-0xaec`, `long`), `index1` (`-0xb00`, `long`), `in_zone` (`-0xad8`,
  `float`), `land_size` (`-0xad4`, `long[99]`), `y` (`-0xb10`, `long`),
  `x` (`-0xb0c`, `long`), `x1` (`-0xae8`, `long`), `done` (`-0xaf1`,
  `uchar`), `stack` (`-0x948`, `Map_Stack[2376 bytes]`), `max_y` (`-0xae0`,
  `long`), `max_x` (`-0xadc`, `long`), `index3` (`-0xafc`, `long`), `zone`
  (`-0xaf0`, `uchar`), and `terrain` (`-0xae4`, `uchar`); register `this`
  (`ecx`).

All five `this` register records have type `RGE_RMM_Land_Generator*`.

The scoped-symbols evidence file has SHA-256
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The five inspected inventory packets have these SHA-256 values:

- `inventory/functions/0048/00485200_RGE_RMM_Land_Generator.txt`:
  `104e5821c14ed6361a1668038bd953543a1509895b10e23cbf877a9b7963d0c8`
- `inventory/functions/0048/00485240_generate.txt`:
  `fbae77b8d9ade6eb1f82b6c982a02c38d76c00ec6576c266599fae887f174d66`
- `inventory/functions/0048/004852D0_check_terrain_and_zone.txt`:
  `a5b02c0ac81c2a5224e4830eb5328974fee399a68824e29384d8b514ecd6e202`
- `inventory/functions/0048/00485480_chance.txt`:
  `dfdc9feeeb45e8614f2f69c2d972b934d98f5e4814120c756b1c46fcaaefeeeb`
- `inventory/functions/0048/00485520_base_land_generate.txt`:
  `2e215e5f050fca5df8d2ad03f15e389617fe1d3fb8d0cfa8615f09b24afddd52`

## Name recovery

Recovered original PDB names in the source definition:

- Constructor parameters: `map` to `in_map`, `module` to `parent_module`, and
  `info` to `in_info`.
- `check_terrain_and_zone` parameters: `unused` to `target` and `land_id` to
  `land_num`. The `x` and `y` names already matched the PDB.
- `chance` parameter: `land_id` to `land_type`. The `x` and `y` names already
  matched the PDB.
- `base_land_generate` loop index: `index` to `index3`.
- `base_land_generate` phase-B size value: `current_size` to `index2`.

The source already used the PDB names `land_size`, `stack`, `x`, `y`, `x1`,
`done`, `max_x`, `max_y`, `zone`, `terrain`, and `tile` in matching lexical
roles. I did not change their declarations or types. I added no new
invented names. Existing descriptive names such as `line`, `stack_ptr`,
`size_ptr`, `placement_chance`, and `stack_cost` remain because the PDB does
not provide a safe one-to-one replacement for them.

The following records were not forced into the current source because the
original executable reuses their homes or scopes:

- `004852D0` places `cy0` in the incoming `y` home and `zone` in the incoming
  `x` home. It also places `octogon_y0` and `octogon_y1` in one `-0x18` home.
  The source keeps its existing `cy0`, `cy1`, and code-generation-sensitive
  `volatile long octogon` form.
- `00485520` reuses `index1` across pointer cursors, `in_zone` across a
  separate local lifetime, and `tile` across coordinate and tile-address
  lifetimes. `x1` also has a reused stack role. The current natural pointer
  and loop declarations do not prove those as one source declaration.
  No duplicate aliases or raw cursor declarations were added.

## Constants, resources, and comments

No new constant or resource ID was added. This module has no resource lookup.
Existing literals and the `DAT_00571ed0` symbol remain unchanged. No runtime
language DLL extraction was needed.

I added one sparse comment at `004852D0` source line 69. The comment records
the proven separation between the converted radius and the fixed `+/-2` scan
bounds. The evidence is the original `004852D0` inventory and assembly: the
area conversion calls `0054B700 __ftol`, then the target stores the two
clamped octogon values in one reused home before the scan. I removed the old
`boundary under the canonical header` comment because it did not explain
source behavior.

## Code-generation and header requests

The edits do not change function signatures, types, storage, class layout,
call order, relocations, direct targets, or executable statements. Parameter
and local spelling can change debug records. The 1TBS brace changes and the
new comment can change line records. The existing volatile octogon carrier and
its overlapping PDB homes remain untouched because they are code-generation
sensitive.

Request for owner 02: update `include/rmm_land.h` parameter names only, with
no type or layout change:

- Constructor declaration: `map` to `in_map`, `parent` to `parent_module`,
  `info` to `in_info`.
- `check_terrain_and_zone`: `unused` to `target`, `land_id` to `land_num`.
- `chance`: `land_id` to `land_type`.

The request is supported by the scoped PDB records listed above. The source
owner did not edit the header.

## Validation limits

I ran only evidence inspection, Git diff review, `git diff --check`, and Git
hash commands. I did not run compilation, matching, audits, or tests. I did
not run a build, game, or runtime validation. No byte equality or semantic
approval is claimed from this cleanup review.
