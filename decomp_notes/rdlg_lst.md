# rdlg_lst.cpp module recovery

## Context gate

- PDB source: `C:\\msdev\\work\\age1_x1\\rdlg_lst.cpp`.
- Ten normal owners span lines 38 through 375.
- Nine are `RGE_Dialog_List` methods. `0047EAA0` is the cdecl compare helper.
- The address order is `0047E670`, `0047E6B0`, `0047E830`, `0047E8C0`,
  `0047E8F0`, `0047E910`, `0047EAA0`, `0047EAD0`, `0047EAF0`, and
  `0047EB60`.
- The constructor, list setup, allocations, compare import, and typed player
  fields provide anchors.
- `0047E690` is a generated scalar deleting destructor.

## Ownership

`rdlg_lst.h` owns only `rdlg_list_info` and `RGE_Dialog_List`.
It includes the canonical `dlg_list.h` chain.
The source uses the canonical screen, base-game, player, master-object, and
shared game-global owners.

The source has no wrapper, context declaration, fallback layout, or raw field
cursor.

The base-game header keeps its three adjacent `get_string` overloads in reverse
source order. This keeps the four-argument call at virtual offset `+0x1C`.

## Validation

`validate_candidate_tu.py` compiled eleven rows.
It matched all eight exact normal owners and the generated destructor.

`0047E6B0` is scratch. The natural typed setup differs by 228 bytes and crosses
the old boundary. It still initializes, copies, sorts, and starts the list.

`0047E910` remains accepted drift. It differs by five bytes with no relocation
mismatch or boundary escape. The difference is local register scheduling. No
call, memory access, or branch occurs in that span.
