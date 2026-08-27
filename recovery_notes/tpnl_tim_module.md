# `tpnl_tim.cpp` source migration

## Ownership

- PDB source: `C:\\msdev\\work\\age1_x1\\tpnl_tim.cpp`
- Source order: constructor, destructor, `set_rect`, `startup`,
  `set_clock_type`, `get_clock_type`, `get_player_id`, `draw`,
  `get_true_render_rect`, `handle_idle`, and `render_to_image_buffer`.
- The scalar deleting destructor at `0051D890` is compiler generated.
- All eleven normal owners now have one compiler-facing source owner in
  `src/tpnl_tim.cpp`.

## Recovery state

The ten functions from `0051D790` through `0051E150` retain their reviewed
matching status. `0051E2B0 render_to_image_buffer` remains scratch because its
natural typed body is not byte exact. The migration does not add padding,
assembly, wrappers, or synthetic declarations to hide that result.

The source uses one module header for the reviewed panel, world, player, draw
area, and imported API declarations. It keeps the original timer, color,
formatting, image-cache, and redraw behavior.

The consolidated source passes the checker for the ten matching owners. This
includes the three exact bodies that were not registered in the old wrapper.
The checker reports the existing `0051E2B0` mismatch only for the scratch body.

## Open exactness issue

The last clean `render_to_image_buffer` body emits a `0x11c` frame and differs
by 439 positional bytes. The original body has a `0x114` frame. The current
source is the simplest typed reconstruction retained after prior ABI, layout,
local, and declaration-order probes. This source-shape migration does not
attempt byte tuning.
