# tpnl_pop.cpp module merge

- PDB source: `tpnl_pop.cpp`.
- Source: `src/tpnl_pop.cpp`.
- Header: `include/tpnl_pop.h`.
- Flags: `config/flags/gx.rsp`.

## Transition

This module has nine normal owners.

The source keeps the PDB order:

1. `TRIBE_Panel_Pop`
2. `~TRIBE_Panel_Pop`
3. `set_rect`
4. `startup`
5. `get_player_id`
6. `draw`
7. `get_true_render_rect`
8. `handle_idle`
9. `render_to_image_buffer`

The header owns the class and API declarations.

The merge removes the wrapper, source fragments, fallback declarations, and
context macro. It keeps the existing function bodies and their behavior.

The scalar deleting destructor at `0051CD90` is compiler-generated. It is not a
normal source owner.

## Check state

Seven owners had registered exact results before this merge.

The grouped `set_rect` result first differed by 228 bytes. The module
header modeled `TDrawArea` as 0x3C bytes, so `new TDrawArea` passed 0x3C to the
allocator. The original call passes 0x100. A module-local 0xC4-byte tail restores
the proven complete 0x100-byte draw-area layout. `set_rect` now matches all 389
bytes, its boundary, relocations, and direct targets. It remains unregistered
in the direct registry until promotion review.

`render_to_image_buffer` remains `scratch`. The merged source emits 681 bytes
for the original 668-byte body and differs by 430 positional bytes. Its frame
is 0x120 instead of 0x114, and 13 bytes escape the original boundary. All 23
calls align, and the protected owner symbol matches. The current natural source
has no supported module-local repair for the frame and API lowering basin.

## Canonical owner validation

The panel header owns only `TRIBE_Panel_Pop`. The source uses the canonical
panel, draw-area, base-game, player, world, and tribe-game owners.

The source uses typed population attribute indices and the derived game queue
owner. It uses the derived player and world types at their proven calls. The
panel fields use their original names and rely on natural alignment.

The canonical candidate module check was run with
`python tools/validate_candidate_tu.py --proposal build/candidate_tus/tpnl_pop_canonical/proposal.json --output-dir build/candidate_tus/tpnl_pop_canonical`.
All eight registered normal owners and the compiler-generated scalar deleting
destructor match. The observed `render_to_image_buffer` owner remains scratch:
it differs by 430 bytes and has a 0x120 frame versus the original 0x114 frame.

The source now uses natural `delete` for each draw-area allocation. The PDB
has no named global data symbol for either `tpnl_tim` debug string. Its data
labels are compiler string-literal records, so the pop owner uses local
literals instead of imported carriers. The PDB handle typedef and the
`CreateRectRgn`/`DeleteObject` API use confirm `image_clip_region` as `HRGN`.

The natural-delete and owner-local-literal candidate was also checked with
`python tools/validate_candidate_tu.py --proposal build/candidate_tus/tpnl_pop_canonical/proposal.json --output-dir build/candidate_tus/tpnl_pop_natural_owner_literals`.
It has the same eight exact normal owners, generated destructor match, and
430-byte scratch mismatch. No owner was demoted.
