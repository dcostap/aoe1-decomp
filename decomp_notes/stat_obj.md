# stat_obj.cpp module merge

- PDB source: `C:\\msdev\\work\\age1_x1\\stat_obj.cpp`.
- Source: `src/stat_obj.cpp`.
- Header: `include/stat_obj.h`.
- Normal owners: 115.
- PDB order: `004C1100` through `004C7F40`.
- Owner class: `RGE_Static_Object`, with `RGE_Check_List` at `004C66C0` through `004C6700`.
- Nearby generated owner: `004C11C0` scalar deleting destructor. It has no source body.

## Context evidence

The packet lists one PDB source path for all 115 owners. The owner line bands increase
from 132 through 5080. The address sequence is strictly increasing. The source keeps
this packet order. The source uses one canonical `RGE_Static_Object` class surface.

The header models the inventory `RGE_Master_Static_Object` size of `0xB8`.
The executable proves `recyclable` at `+0xA4`, `damage_sprite_num` at `+0x93`,
and `damage_sprites` at `+0x94`. It also proves the static object size of `0x88`.

## Transition

The merge removes the wrapper TU, four small diagnostic wrappers, source-bank
fragments, context macros, and fallback class declarations. The source uses
canonical master, object, player, World, visibility, zone-map, and pathing
providers. It has no inline assembly or manual vptr setup.

The source uses direct map rows, object-list nodes, zone-map calls, and World
time delta. It does not keep local master, player, World, or visibility views.

## Validation

The source compiles with the pinned VC5 compiler and
`config/flags/default.rsp`. The full candidate is
`build/candidate_tus/stat_obj_cleanup_followup/report.txt`.

- 82 normal owners match with zero relocation mismatches and no boundary
  escapes.
- `004C11C0`, the scalar deleting destructor, matches.
- 4 accepted-drift owners remain accepted drift.
- 24 owners remain scratch. `004C7030` remains verified logic.
- The report has zero comparison errors.

The migration check found differences in these prior exact functions:
`004C1100`, `004C11E0`, `004C1D60`, `004C1DC0`, `004C3B30`, `004C3C70`,
`004C4D80`,
`004C4E00`, `004C4F10`, `004C5210`, `004C52F0`, `004C6400`, `004C6DA0`,
`004C7920`, and `004C7D00`.

The cleanup removes raw field views, stack aliases, value punning, fake
volatility, and manual array allocation. `004C4E00` and `004C6400` remain
natural source, but no longer match exactly. They are scratch.

`004C5F00` is scratch. Removing its unsupported volatile local increased its
drift from 24 to 127 bytes. The remaining source is natural.

`004C3B30` is scratch under the canonical BaseGame provider. The provider adds
the PDB-owned `debug_timeGetTime` declaration. The source does not call it,
but VC5 changes 224 bytes in `draw_frame`. No source-local context repair is
natural. The worker header without that declaration still matches.

The direct source promotes these prior scratch owners after grouped matches:
`004C1420`, `004C1590`, `004C16B0`, `004C41D0`, `004C4C40`, `004C50F0`,
`004C58E0`, `004C5D80`, `004C7430`, `004C74B0`, `004C7530`, and
`004C7CE0`.

## Heal overload ABI

VC5 emits overloaded virtual groups in reverse declaration order. The header
declares `heal(float)` before `heal(int, int)`. This produces the executable's
slots `+0x8C` and `+0x88`, respectively.

The repair removes the last byte from `004CECF0` and restores exact
`004165F0`. It also moves the repair-action heal call to its proven slot.

## Accepted-drift recheck

The fresh direct-module audit is `build/candidate_tus/audit_stat_obj_final`.
It demotes `004C22C0 capture_square_frame`: the natural body differs by 219
bytes and the checker reports a width and signedness mismatch across the main
draw block. The source keeps the executable's repeated screen-Y offset bug.

The same audit demotes `004C2110 draw_front_frame` because two direct targets
name the wrong helper, `004C2B50 draw_frame_3d_square_front` because its body
escapes the original boundary, and `004C58C0 more_room` because its body
escapes the original boundary. The other accepted rows remain observed. Their
current results have no relocation or boundary error, and their differences
are localized register, width, or instruction-order changes.
