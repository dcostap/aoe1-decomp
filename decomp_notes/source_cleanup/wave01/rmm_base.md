# Source cleanup report: `src/rmm_base.cpp`

## Commits and scope

- Module: `src/rmm_base.cpp`.
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`.
- Final source commit: `73a831ad2e4cac42d6bbc53ec2c76454150b7b4c`.
- Changed files: `src/rmm_base.cpp` and this report.
- Branch: `cleanup/staging-20260915-12`.
- Header read: `include/rmm_base.h`. It was not changed.

The source keeps all 24 registry functions in source order. It keeps their
signatures, types, scopes, storage, calls, and executable statements.
It also uses 1TBS braces for function definitions.

## Evidence coverage

I inspected every registry VA in `config/functions/src/rmm_base.cpp.json`.
I inspected each matching inventory packet under
`inventory/functions/0048/`.
I inspected all PDB stack and register records in
`inventory/pdb/scoped_symbols.json`.
The PDB source is `C:\msdev\work\age1_x1\rmm_base.cpp`.

All 24 procedures have the PDB register record `this` in `ecx`.
The stack-record coverage is:

| VA | PDB stack names |
| --- | --- |
| `00480790` | `in_map`, `parent_module`, `resources_needed` |
| `00480840` | none |
| `004808C0` | none |
| `004808D0` | none |
| `004809E0` | `module` |
| `00480A20` | `module` |
| `00480A80` | none |
| `00480B60` | none |
| `00480BC0` | none |
| `00480BE0` | none |
| `00480C10` | none |
| `00480C30` | `new_map` |
| `00480C80` | `search_map_pointer`, `search_map_rows_pointer`, `stack_array_pointer`, `stack_offsets_pointer` |
| `00480CC0` | `stack` |
| `00480CF0` | `stack` |
| `00480D10` | `stack`, `x`, `y`, `cost`, `tot_cost` |
| `00480DA0` | `stack`, `x`, `y`, `cost` |
| `00480DE0` | `stack`, `new_stack` |
| `00480E20` | `stack` |
| `00480E50` | none |
| `00480EA0` | `stack` |
| `00480EC0` | `stack`, `sub_stacks` |
| `00480FB0` | `x`, `y`, `end_x`, `end_y`, `terrain`, `path_stack` |
| `00481000` | `path_stack`, `x`, `y`, `end_x`, `end_y`, `terrain`, `left`, `map_h`, `map_w`, `calc_cost`, `tcost`, `up`, `cost`, `tile_type`, `hcost`, `right`, `down`, `ty` |

The PDB also records these `00481000` local homes:
`left` and `right` share `-0x21`; `up` is `-0x23`; `down` is `-0x22`;
`map_h` is `-0x8`; `map_w` is `-0x4`; `calc_cost` is `-0x20`;
`tcost` is `-0x18`; `cost` is `-0x10`; `tile_type` is `-0x1c`;
`hcost` is `-0x14`; and `ty` is `-0xc`.
The PDB reports the corresponding types. I did not alter any local type.

## Recovered original names

The following names came from procedure-scoped PDB records:

- `00480790`: `map` to `in_map`; `parent` to `parent_module`;
  `create_shared` to `resources_needed`.
- `00480A20`: `param_1` to `module`.
- `00480C30`: `param_1` to `new_map`.
- `00480C80`: `a`, `b`, `c`, and `d` to the four pointer names listed above.
- `00480D10`: `list` to `stack`; `param_2` through `param_5` to
  `x`, `y`, `cost`, and `tot_cost`.
- `00480DA0`: `head` to `stack`.
- `00480DE0`: `target` to `stack`; `node` to `new_stack`.
- `00480E20`: `node` to `stack`.
- `00480FB0`: `param_1` through `param_5` to `x`, `y`, `end_x`, `end_y`,
  and `terrain`.
- `00481000`: `target_x` to `end_x`; `target_y` to `end_y`;
  `terrain_cost` to `terrain`; `max_x` to `map_w`; `max_y` to `map_h`;
  `path_cost` to `ty`; `distance` to `cost`; `adjusted_distance` to
  `hcost`; and `new_cost` to `calc_cost`.

The `00481000` local mappings use the PDB names and the original assembly's
uses. The PDB names `left` and `right` share one stack home. The source keeps
`side` because one declaration covers both uses. This avoids forcing a reused
stack-slot mapping.

## Unresolved mappings

- `side` could map to either PDB `left` or PDB `right`.
- `next_x`, `next_y`, and `state` have no procedure-scoped PDB records.
- The PDB records `tcost` and `tile_type` across overlapping homes.
  The source keeps the existing `tile_type` declaration and its type.
- Locals such as `current`, `sorted`, `search`, `next`, `item`, `head`,
  `found`, `curr`, `pprev`, `i`, `j`, `count`, `node`, `x`, and `y` have
  no procedure-scoped records for their owning procedures. I did not force
  names without direct evidence.

No invented identifier was added. Names without PDB evidence remain the
existing descriptive names. The source uses no new resource name.

## Constants, resources, and comments

No constant or resource ID changed. No resource lookup occurs in this module.
The existing `DAT_00571e50`, `DAT_00571e54`, `DAT_00571e58`, `DAT_00571e5c`,
and `DAT_00571e60` references remain unchanged.
The existing debug path, line values, allocation sizes, and state values remain
unchanged.

I added no comment. I retained the existing comments that explain publication
order and the shipped allocation-failure behavior. No header or shared resource
mapping request is needed.

## Code-generation-sensitive points

The changes rename parameters and locals and move function braces to 1TBS.
They do not change types, storage, scopes, statement order, expressions, calls,
relocations, data, or public symbols.
The source keeps `ty` as `float`, despite the PDB record's reported type.
No type change was authorized by this naming pass.
The source keeps `side` because `left` and `right` reuse one PDB stack home.

Compilation, matching, audits, and tests were not run, as required for this
cleanup phase.
