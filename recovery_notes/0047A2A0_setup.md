# 0047A2A0 TPicturePanel::setup

## Exact source evidence before migration

The matching source uses `strcpy` for the optional picture name. A manual copy
loop produced the wrong library-call shape. The local `short sw, sh` values
allow VC5 to reuse the parameter homes after `shape_bounds`.

The `shape_bounds` declaration uses an unsigned-char thiscall result and short
reference arguments. The qualified `TPanel::setup` call and canonical panel
inheritance are required by the recovered module context.
