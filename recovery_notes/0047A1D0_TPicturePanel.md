# 0047A1D0 TPicturePanel::TPicturePanel

## Source recovery note

The constructor calls the canonical out-of-line `TPanel` constructor at
`004648B0`. The canonical header restores this direct call.

The canonical-header grouped check differs by 52 bytes. It changes only the
derived vptr-store position. The code stays inside the original boundary.
This owner is scratch. Do not use a local panel declaration or a manual vptr
store to tune it.

The body keeps the shipped field values: `keep_loaded` is one, the picture
pointers are null, `handle_mouse_input` is zero, `panel_type` is two, and
`res_id` is minus one.
