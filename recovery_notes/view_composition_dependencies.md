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
