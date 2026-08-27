# tpnl_pop.cpp module merge

- PDB source: `tpnl_pop.cpp`.
- Source: `src/tpnl_pop.cpp`.
- Header: `include/tpnl_pop.h`.
- Flags: `config/flags/0051CDB0_TRIBE_Panel_Pop.rsp`.

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

`set_rect` had an exact standalone result but was not registered in the old
translation-unit entry.

`render_to_image_buffer` remains `scratch`. Its isolated result differed by 234
bytes and needs later grouped recovery.

No byte tuning was done during this merge. Run grouped checks after the final
source tree is ready.

The grouped compile produced seven matches. `set_rect` differed by 228 bytes.
`render_to_image_buffer` differed by 430 bytes and crossed one boundary. These
temporary regressions are accepted for this source-shape migration.
