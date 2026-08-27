# Object-list ABI packet

## Header ownership

`obj_list.cpp` owns `RGE_Object_Node` and `RGE_Object_List`.
The PDB gives sizes `0x10` and `0x0C`.

`RGE_Object_Node::node` is a `RGE_Static_Object*` at `+0x00`.
`RGE_Object_List::list` is an `RGE_Object_Node*` at `+0x04`.

The header does not own view, master, static, player, world, or derived object classes.

## Source hold

Do not compile or integrate `obj_list.cpp` yet.
The old draw path uses a fake view support class.
Do not move that class into source.

The source needs canonical `stat_obj.h` for static fields and virtual calls.
It needs canonical `m_s_obj.h` for `fog_flag`.
It needs the full player owner header for `color_table`, `world`, and `id`.
It needs `world.h` for `curr_player` and `players`.

The source must call canonical static-object virtual methods after these headers land.
