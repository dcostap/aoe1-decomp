# 0053D500 `RGE_Diamond_Map_View::mouse_left_up_action`

- PDB source: `vw_dimap.cpp`, lines 95 to 148.
- Original size: 284 bytes.

## Recovery record

A prior recovery used padded virtual declarations and ordinary switch and branch
source. The final body removed the padding. It uses the module-local view
surface instead.

The merged module has 97 differing bytes. The source remains `matching` because
this was its reviewed bank state. The merge does not claim a new exact result.
