# `rmm_terr.cpp` source-cleanup report

## Delivery

- Module: `src/rmm_terr.cpp`
- Report: `decomp_notes/source_cleanup/wave01/rmm_terr.md`
- Branch: `cleanup/staging-20260915-19`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Previous source commit: `cccb50ecbb00fdf39c3cfad336f0094b3c3dec31`
- Final source commit: `0d8b67a7c8b68126eac5a92eedc30afc784cfe1a`
- Changed files in the source commit: `src/rmm_terr.cpp`
- The follow-up report commit contains this report only.

The header `include/rmm_terrain_generator.h` was read and was not edited.

## Correction round

The correction source commit is `0d8b67a7c8b68126eac5a92eedc30afc784cfe1a`.
It moves every function-definition opening brace to 1TBS style. It preserves
all braces and scopes. It keeps the inner `base_terrain_generate` scope and
indents its body.

A whitespace-stripped token comparison against the previous source commit
returned equal. No non-whitespace source token changed in this round.

## Evidence reviewed

- PDB source: `C:\\msdev\\work\\age1_x1\\rmm_terr.cpp`
- Procedure records: `inventory/pdb/scoped_symbols.json`
- Function packets: `inventory/functions/0048/004888E0_RGE_RMM_Terrain_Generator.txt`
- Class and type packets for `RGE_RMM_Terrain_Generator`
- Existing module note: `decomp_notes/rmm_terr.md`
- Assigned header and its included terrain declarations

I inspected every assigned VA and every stack, local, and register record.
All eleven records contain the `this` register. No assigned procedure has a
function-static record.

## PDB name recovery

The following names match the procedure-scoped PDB records.

- `004888E0` constructor: `map` to `in_map`, `parent` to `parent_module`, and
  `info` to `in_info`.
- `00488920` `generate`: PDB names `index` and `terrain_table` were already
  present. `zid` became the cleanup name `zone_id`; `p` became
  `terrain_line` from its typed use.
- `004889D0` `water`: `value` to recovered `terrain`.
- `004889F0` `check_borders`: PDB records named `x`, `max_y`, and `max_x`
  were reviewed. The current descriptive loop names remain unchanged because
  optimized stack records do not prove which loop owns `x`. The current `t`
  name also remains unchanged.
- `00488B90` `check_terrain`: parameters became recovered `target`, `x`,
  `y`, `spacing`, and `base_terrain`. The result counter `count` became
  recovered `index1`. The local terrain value became recovered
  `i_base_terrain`.
- `00488D50` `generate_modifiers`: recovered `modifier` was already present.
- `00488E40` `fig_chance`: `p0`, `p1`, `p2`, and `p3` became recovered
  `count`, `x`, `y`, and `clumpiness_factor`.
- `00488E60` `count_map_tiles`: `tileType` became recovered `terrain`.
- `00488EA0` `link_stack_randomly`: parameters `param_1` and `param_2`
  became recovered `loc_stack` and `base_terrain_type`. The PDB local
  `max_y` was already present.
- `00488F90` `remove_area_from_lists`: parameters `p1`, `p2`, and `p3`
  became recovered `x`, `y`, and `spacing`. The PDB loop records remain
  unresolved because they reuse argument slots.
- `00489030` `base_terrain_generate`: parameter `line` became recovered
  `info_line`. The adjacent coordinate output `chance` became recovered
  `y`.
  `fair_count` became recovered `terrain_fairness_zones_visited_count`.
  `local_a44` became recovered `base_area`. `loc_stack_x` became recovered
  `max_y`. The PDB records already supported `index1`, `clump_size`,
  `in_zone`, `x`, `loc_stack`, `done`, `stack`,
  `terrain_fairness_zones_visited`, `max_x`, and
  `terrain_fairness_zones`.

The new `score` name replaces the decompiler-style `fStack_a4c`. It is a
cleanup name, not a recovered developer name. The PDB has no matching source
name for this compiler temporary.

## Unresolved mappings

- `00488B90` has PDB records named `y1`, `x1`, and `count` in reused stack
  slots. The current typed scan uses clipped-bound and row-pointer locals.
  I did not force those records onto different types or scopes.
- `00488F90` has PDB `y1`, `x1`, and `y_index` records in reused argument
  slots. The current typed loop keeps its existing descriptive bounds and
  does not force those mappings.
- `00489030` has a PDB `chance` record sharing a slot with the fairness-count
  record. The current `cost` output has a different declaration role, so it
  remains unresolved. The source keeps its existing type and storage.
- Several generated loop, pointer, and temporary names have no PDB record.
  They remain unchanged unless a direct mapping was clear.
- The PDB reports `in_zone` as `float` in `00489030`; the source keeps its
  existing `long` type. No type or storage change was made.

## Constants, resources, and comments

No constant replacement was made. Existing terrain values, masks, sentinels,
random values, and debug line constants remain unchanged.

No resource lookup or resource ID change was made. No resource mapping request
is needed.

No new explanatory comment was added. Two existing comments were updated to
match the recovered coordinate and fairness names. The comments preserve the
known `pop_stack` output layout and the reused fairness-count storage.

## Code-generation-sensitive points

The source cleanup edits are identifier substitutions or descriptive local
names. The correction round changes whitespace only. Types, scopes, declaration
order, storage, casts, calls, control flow, constants, structures, and source
ownership remain unchanged. No header, ABI name, or public signature was
edited. No inline assembly or wrapper was added.

Compilation, matching, audits, and tests were not run, as required for this
cleanup phase. I ran only Git diff review and `git diff --check`.

## Requests

No header or shared resource-ID request is pending.
