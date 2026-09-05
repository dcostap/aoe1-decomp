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

The approved closure baseline
(`98fe3aa9cabf146f9cf01933eed95f5067ca2fcef9572af26b67ef242465bf7e`, run
`48068d7fd0f355098155933180f7c4befe117a2dc20a65477bc8b621bf5d22a4`)
reports ten configured normal owners: nine `MATCH` results and one
accepted-drift observation. It reports no compile errors, relocation target
mismatches, or boundary escapes.

`0047E6B0` is matching. The natural typed setup reports `MATCH` with zero
different bytes, the expected owner, no relocation target mismatches, and no
boundary escapes.

`0047E910` remains accepted drift. It differs by five bytes with no relocation
mismatch or boundary escape. The difference is local register scheduling. No
call, memory access, or branch occurs in that span.
