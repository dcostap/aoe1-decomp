# view.cpp canonical-header composition

## Scope

`view.h` cannot remove its local type bodies until owner headers expose all used
members. The failed candidate compile used the canonical Drawarea, Shape, and
Panel headers. It found the bounded gaps below.

## Terra 5: Drawarea and base game

- `TDrawArea` needs `OverlayMemCopy`, `PtrSpanCopy`, `Unlock(const char*)`,
  and the `CurrentMask` alias. View uses them in `00535210`, `00536B40`, and
  `00538710`. The PDB owners are in `view.cpp`.
- `TDrawSystem` needs the byte alias at `+0x478`. `00535210` reads it before
  the overlay copy path.
- The clip and span surface needs `DClipInfo_List` construction, `SetDrawRegion`,
  `Scroll`, `ReclaimAllNodes`, `SetCaptureLevel`, `AddGDINode`, and the node
  arrays. View uses this surface in `005346F0`, `00534A00`, `00536B40`, and
  `00538280`.
- `TSpan_List_Manager` needs `AddMiniList`, `SubtractMiniList`,
  `Merge_n_Align`, and `AddShape_Align`. View uses these methods in `00536B40`.
- `RGE_Base_Game` needs `prog_mode`, `game_mode`, `sub_game_mode`,
  `master_obj_id`, `brush_size`, `rollover`, `get_player`, and `get_mouse_pos`.
  View uses them in `00536B40` and `00538F00`.

## Terra 2: Shape and Panel

- `Shape_Info` must be one canonical definition. `00533940` and `00538B80`
  use its `shape_info` member and the proven 0x20-byte `TShape` surface.
- `TPanel` needs the reviewed aliases for `game_enable`, `drawSystem`,
  `screen_w`, `screen_h`, `left`, `top`, `right`, `bottom`, and the render
  rectangle. View uses them in `00533940`, `00534340`, `00535FE0`, and
  `00536B40`.

## Reopening condition

Remove the local `TDrawArea`, `TShape`, and `TPanel` bodies only after these
owner headers provide the listed members. Then run one grouped View candidate
and up to three cached focused checks. Keep the two documented Shape regressions
nonexact.

## 2026-08-28 owner repairs

The former View wrapper could not become a direct natural compiland.
It supplied copied `TPanel`, `TDrawArea`, and `TShape` bodies.
The held migration commit `744ab00cd` is not a solution.
It uses alias unions and context suppression.

`drawarea.h` now exposes these Drawarea.cpp methods:

- `TDrawArea::PtrSpanCopy` at `00445250`;
- `TDrawArea::OverlayMemCopy` at `00445580`.

View calls them from `00536B40` and `00534AE0`.
The PDB symbols prove these declarations:

```cpp
void PtrSpanCopy(TDrawArea*, long, long, tagRECT*, unsigned char**);
void OverlayMemCopy(tagRECT&, tagRECT&, int, int, int, int);
```

`TDrawArea::SpanList` and `CurSpanList` are the canonical `+0xCC` and
`+0xD0` fields. View source must use them. Do not add `SavedMask` or
`CurrentMask` aliases.

`Shape.h` no longer declares a partial `DClipInfo_List` class. View owns the
PDB `DClipInfo_List` and
`DClipInfo_Node` definitions. The node is `0x40` bytes. `Node_Type` is at
`+0x2C`. The list is `0x70` bytes. `AddGDINode` returns a node pointer and
takes thirteen `int` values.

`src/Shape.cpp` includes `view.h` for the complete list type. The public Shape
header keeps only a forward declaration. Do not use a partial compatibility
class.

Now convert View source to `panel.h`, `drawarea.h`,
and `Shape.h`. Use the real field names. In particular, use
`render_rect`, `first_child_node`, `have_focus`, `pnl_wid`, `pnl_hgt`, and
`cur_render_area`. Route any remaining Player, World, Visible, Map, or object
surface gap to that type owner. Do not restore a View context, carrier, alias
union, or manual vptr.
## Direct View checkpoint

`src/view.cpp` owns the 79 View and DClip definitions. It compiles against the
canonical `TPanel`, `TDrawArea`, `TShape`, `DClipInfo_List`, and `RGE_View`
declarations.

The direct candidate validates 48 exact owners with `MATCH` and zero
relocation or boundary failures. The other rows keep their source-bank status.

The candidate records decorated symbols for the five overloaded rows. This
lets it classify each row without a false comparison error.

## Direct source construction

`src/view.cpp` has 79 View and DClip definitions in PDB order. It includes
canonical headers only. It has no fragment include, TU context, or copied type.
The registered exact rows point to this direct source.

## Current direct compile

The direct source consumes the canonical Mouse, Sprite, Message Panel, and
Base Game providers. It compiles on main after `569981402` changed
`get_mouse_pos` to use a reference.

CodeView type `0x24BA` and `004202E0` prove this declaration:

```cpp
void RGE_Base_Game::get_mouse_pos(tagPOINT&);
```

The target symbol is `?get_mouse_pos@RGE_Base_Game@@QAEXAAUtagPOINT@@@Z`.

The former `rollover_info` source name was not an owner gap. View now calls
`RGE_Player::get_mouse_pointer_action_vars(int, int&, int&)`. It is virtual
at `+0x9C`, has PDB type `0x1E5A`, and resolves to `00471530`.
