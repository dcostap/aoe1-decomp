# 0047A1D0 TPicturePanel::TPicturePanel

## Source recovery note

The constructor calls the out-of-line `TPanel` constructor at `004648B0`.
The module header has only an implicit default constructor for `TPanel`.
Keep this owner under grouped validation until that ABI is reviewed.

The body keeps the shipped field values: `keep_loaded` is one, the picture
pointers are null, `handle_mouse_input` is zero, `panel_type` is two, and
`res_id` is minus one.
