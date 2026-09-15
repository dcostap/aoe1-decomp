# `src/asp_list.cpp` cleanup report

## Scope and hashes

- Module: `src/asp_list.cpp`
- Header owner: owner 23 owns `include/asp_list.h`; this worker did not edit it.
- Base commit from `git rev-parse`: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Base source SHA-256 from Git: `31cc0408cfd251fb4a6a5c34e7c8259b7ccdcb8b5b04ab8cbcd61e5fd92298f4`
- Final source SHA-256: `6727133fdb7a42cda691bb77846ad2b4c698dcce2f420f366457d39ff6f7daa1`
- Final commit: see the delivery record for the full Git hash.
- Changed files:
  - `src/asp_list.cpp`
  - `decomp_notes/source_cleanup/wave04/asp_list.md`

The source keeps one natural owner and the original source order. It contains 23 normal `RGE_Active_Sprite_List` owners. The compiler-generated vector-deleting destructor at `0041A660` remains outside the source owner.

Evidence identity used during review:

- Original executable: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`, SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Registry packet: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/asp_list.cpp.json`. It selects `config/flags/gx.rsp` through the `gx` build profile.
- Preserved baseline report: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`, SHA-256 `fddd62868626e21ec7282183fa1cf84ad5b0b14fc719c8830a266d6ed0f155b3`.
- Scoped PDB records: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
- CVDump extraction: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-200/build/evidence/asp_list-cvdump-s.txt`.
- Original assembly and decompiler listing: `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/asp_list.cpp.asm` and `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/asp_list.cpp.decomp`.
- Procedure packets: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0041/`, using the packet named by each row below.

## Original-name recovery coverage

The scoped PDB records were inspected for every normal owner and for the adjacent generated function. Every normal owner has `this` in `ecx`. The PDB names below are recovered original names.

| VA | Function and binary range | PDB source span | PDB parameters and locals used by the cleanup |
| --- | --- | --- | --- |
| `0041A640` | `RGE_Active_Sprite_List::RGE_Active_Sprite_List`, `0041A640-0041A658` | 23-27 | `owner_in` |
| `0041A680` | `RGE_Active_Sprite_List::~RGE_Active_Sprite_List`, `0041A680-0041A68A` | 31-32 | none beyond `this` |
| `0041A690` | `load`, `0041A690-0041A6EA` | 37-60 | `infile`, `sprites`, `type` |
| `0041A6F0` | `load_node`, `0041A6F0-0041A810` | 64-90 | `infile`, `type`, `sprites` |
| `0041A820` | `save`, `0041A820-0041A857` | 94-102 | `outfile`, `ender` |
| `0041A860` | `delete_list`, `0041A860-0041A8AB` | 106-124 | none beyond `this` |
| `0041A8B0` | `copy_sprite_list`, `0041A8B0-0041A8EE` | 128-143 | none beyond `this` |
| `0041A8F0` | `use_sprite_list`, `0041A8F0-0041A902` | 147-150 | `temp_list` |
| `0041A910` | `add_sprite`, `0041A910-0041A9AD` | 154-200 | `sprite`, `order`, `x`, `y` |
| `0041A9B0` | `remove_sprite`, `0041A9B0-0041AA1E` | 204-237 | `sprite` |
| `0041AA20` | `update`, `0041AA20-0041AA47` | 241-246 | `time`, `speed` |
| `0041AA50` | `draw`, `0041AA50-0041AA96` | 250-255 | `facet`, `x`, `y`, `sx`, `sy`, `player_color`, `draw_area` |
| `0041AAA0` | `normal_draw`, `0041AAA0-0041AADA` | 259-264 | `facet`, `x`, `y`, `player_color`, `draw_area` |
| `0041AAE0` | `shadow_draw`, `0041AAE0-0041AB1F` | 268-273 | `facet`, `x`, `y`, `player_color`, `draw_area`, `flag` |
| `0041AB20` | `frame`, `0041AB20-0041AB50` | 277-285 | `sprite` |
| `0041AB60` | `is_animating`, `0041AB60-0041AB8E` | 289-297 | `sprite` |
| `0041AB90` | `set_frame`, `0041AB90-0041ABBB` | 301-307 | `sprite`, `new_frame` |
| `0041ABC0` | `frame_passed`, `0041ABC0-0041ABF3` | 311-319 | `sprite`, `pass_frame` |
| `0041AC00` | `looped`, `0041AC00-0041AC2E` | 323-331 | `sprite` |
| `0041AC30` | `get_facetindex`, `0041AC30-0041AC65` | 335-343 | `sprite`, `facet` |
| `0041AC70` | `get_frame`, `0041AC70-0041ACB7` | 347-355 | `min_x`, `min_y`, `max_x`, `max_y`, `sprite`, `facet` |
| `0041ACC0` | `get_lowest_draw_level`, `0041ACC0-0041ACE3` | 359-374 | none beyond `this` |
| `0041ACF0` | `check_for_shadows`, `0041ACF0-0041AD16` | 378-390 | none beyond `this` |
| `0041A660` | compiler-generated vector-deleting destructor, `0041A660-0041A67D` | none | no source PDB span; not edited |

The `load` PDB record names `type` at stack offset `+0xC`. The source uses that name for the one-byte `load_node` result. The original binary reads the type byte through the local stack copy of `sprites`, while `sprites_copy` keeps the original array pointer for the active-sprite constructors. This source form is unchanged apart from recovered names and a nearby explanation.

The PDB has no scoped local records for the list cursors or temporary values in these owners. The cleanup replaces generated forms with descriptive names where needed:

- `pRVar2` and `pRVar5` become `node` and `reversed_list` in `load`.
- `ppRVar3` becomes `sprites_copy` in `load`.
- The promoted switch value in `load_node` becomes `type_value`.
- `p` and `ppPrev` become `node` and `previous_link` in `remove_sprite`.
- `next` becomes `next_node` in `delete_list`.
- `p1` and `p2` become `time_value` and `speed_value` in `update`.

These are new descriptive cleanup names. They are not claims about original local names. Other descriptive locals already present in the source remain unchanged and are not claimed as PDB names.

## Binary behavior review

The original assembly packet for each row above was compared with the source control flow, field access, calls, and return paths.

- `0041A640` writes the list vtable, clears `list`, and stores `owner_in`.
- `0041A680` writes the list vtable and tail-jumps to `delete_list`. The existing comment records this unusual destructor form.
- `0041A690` reads one type byte, calls the virtual `load_node` slot at `+0x2C`, and reverses the newly loaded head-inserted list.
- `0041A6F0` switches on the byte value. Type zero returns zero. Types one and two allocate a node and the matching active-sprite object, link the node at the head, and return one. Other values link a node with a null active-sprite pointer and return one. The existing comment records the shipped exception-cleanup state.
- `0041A820` saves each node through virtual slot `+0x08`, then writes the zero `ender` byte.
- `0041A860` checks shadows, removes owner shadows when required, deletes each active sprite, frees each node, and clears `list`.
- `0041A8B0` clears `list` while it calls `add_sprite` for each old node. It restores the old list and returns the new list.
- `0041A8F0` calls `delete_list`, then assigns `temp_list` to `list`.
- `0041A910` rejects a null `sprite`, removes owner shadows when the sprite has shadows, shares an existing node by increasing its count, and inserts new nodes after entries whose `order` is less than or equal to the new order. The existing reviewed insertion logic remains unchanged.
- `0041A9B0` finds the first matching `sprite`. It decrements a nonzero count. Otherwise it unlinks, removes shadows, deletes the active sprite, and frees the node.
- `0041AA20` forwards `time` and `speed` to every active sprite through virtual slot `+0x0C`.
- `0041AA50`, `0041AAA0`, and `0041AAE0` forward the recovered drawing parameters through virtual slots `+0x10`, `+0x14`, and `+0x18`.
- `0041AB20` returns the matching active sprite frame through virtual slot `+0x1C`, or zero when no node matches.
- `0041AB60` returns the matching active sprite animation state through virtual slot `+0x20`, or zero when no node matches.
- `0041AB90` sends `new_frame` to every matching active sprite through virtual slot `+0x24`.
- `0041ABC0` sends `pass_frame` to the first matching active sprite through virtual slot `+0x28`, or returns zero when no node matches.
- `0041AC00` returns the first matching active sprite loop state through virtual slot `+0x2C`, or zero when no node matches.
- `0041AC30` forwards `facet` to the first matching active sprite through virtual slot `+0x30`, or returns zero when no node matches.
- `0041AC70` forwards the four output references, `facet`, and the matching `sprite` through virtual slot `+0x34`, or returns zero when no node matches.
- `0041ACC0` starts with `0x14`, compares each active sprite draw level, and returns the lowest value.
- `0041ACF0` calls each active sprite shadow check and returns one at the first positive result. An empty list and a list with no shadows return zero.

The new comments explain only the type-byte read, the serialization sentinel, the shadow-removal order, the temporary copy list, and the reference count. Each comment is supported by the listed assembly range and the paired load/save or list-management behavior.

No numeric constant or resource ID was replaced. This module has no resource lookup.

## Code-generation risks and unresolved mappings

The source changes rename parameters and locals and add short comments. They do not change an ABI symbol, type, cast, declaration scope, storage duration, field offset, literal value, evaluation order, control flow, call target, or object layout. The `load` stack-through-`sprites` expression and the `load_node` promoted switch value remain in place. Comments can change debug line records, but this module has no line-dependent macro.

The existing `0041A910 add_sprite` status is `new_verified_logic`. Its prior review records accepted behavior and known VC5 register drift. This cleanup does not claim a new match or accepted drift. It preserves the existing list insertion source.

The remaining local-name mappings are unresolved because the scoped PDB records do not name them. No reused stack slot was forced into a new declaration.

## Shared-file requests

Request to owner 23 for a non-blocking declaration-name cleanup in `include/asp_list.h`:

- Constructor: `owner_in`.
- `load`: `infile`, `sprites`.
- `load_node`: `infile`, `type`, `sprites`.
- `save`: `outfile`.
- `use_sprite_list`: `temp_list`.
- `add_sprite`: `sprite`, `order`, `x`, `y`.
- `remove_sprite`: `sprite`.
- `update`: `time`, `speed`.
- `draw`: `facet`, `x`, `y`, `sx`, `sy`, `player_color`, `draw_area`.
- `normal_draw`: `facet`, `x`, `y`, `player_color`, `draw_area`.
- `shadow_draw`: `facet`, `x`, `y`, `player_color`, `draw_area`, `flag`.
- `frame`, `is_animating`, `looped`: `sprite`.
- `set_frame`: `sprite`, `new_frame`.
- `frame_passed`: `sprite`, `pass_frame`.
- `get_facetindex`: `sprite`, `facet`.
- `get_frame`: `min_x`, `min_y`, `max_x`, `max_y`, `sprite`, `facet`.

The evidence is the procedure-scoped PDB data at the VAs in the table. The header request changes declaration names only. This worker did not edit the shared header.

## Validation status

Compilation, matching, audits, validation, and tests were not run. No compiler, build, matching, audit, validation, test, or game command was run for this assignment. The complete source diff was reviewed, and `git diff --check` passed.

## Correction history

After full diff review, the three-parameter `load_node` definition and the four-parameter `add_sprite` definition moved onto one line. The duplicate reference-count comment in `remove_sprite` was removed. The earlier `add_sprite` comment already explains shared-node retention.
