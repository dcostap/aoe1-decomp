# Visible-unit ABI packet

## Tile list

`player.cpp` owns `RGE_Tile_List` and `RGE_Tile_List_Node`.

`RGE_Tile_List_Node` has size `0x08`:

- `int col` at `+0x00`;
- `int row` at `+0x04`.

`RGE_Tile_List` has size `0x14`:

- `int list_size` at `+0x00`;
- `int num_active` at `+0x04`;
- `int new_count` at `+0x08`;
- `int collapse_list` at `+0x0C`;
- `RGE_Tile_List_Node* list` at `+0x10`.

The exact owner at `00471E90` is:

```cpp
void RGE_Tile_List::get_list_info(RGE_Tile_List_Node*&, int&);
```

## Combat visible-unit pointers

`com_obj.cpp` owns `RGE_Combat_Object`.

The class derives from `RGE_Action_Object` and has size `0x1C4`.
Its visible-unit pointer array is:

```cpp
VISIBLE_UNIT_REC* VUR_Ptrs[9];
```

The array starts at `+0x194` and has size `0x24`.

`com_obj.h` can forward-declare `VISIBLE_UNIT_REC`. It must not copy the visible-unit record.

## Fanout

Apply these declarations to `player`, `com_obj`, and `vis_unit`.
Do not restore `m_s_obj_context.h` or local combat, player, map, or tile-list classes.
