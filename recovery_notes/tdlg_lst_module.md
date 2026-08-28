# tdlg_lst.cpp source recovery

PDB owns six `TRIBE_Dialog_List` methods. The source range is `0050B450`
through `0050B83A`.

`TRIBE_Dialog_List` uses canonical `RGE_Dialog_List`, `TListDialog`, and panel
headers. The source uses canonical BaseGame, Player, static-object, master-object,
and TRIBE Player headers.

The direct constructor calls `RGE_Dialog_List::RGE_Dialog_List` at `0047E670`.
`create_list` tail-jumps to the three local list builders or `0047E8F0`.
The builders call `00420330`, `004711D0` or `00471120`, and `005131C0` or
`00513000`.

`rdlg_list_info` has a 0x66-byte stride. The builder writes its text and ID
from `Item_Avail`.

The scalar deleting destructor at `0050B470` is compiler generated. It has no
source method.

Current status:

- `0050B450`, `0050B4A0`, `0050B4D0`, `0050B5E0`, and `0050B700` match.
- `0050B820` remains accepted drift. The direct module has a 15-byte control-flow
  mismatch and two bytes after its original boundary.

The constructor now matches after the canonical inherited headers replaced the
local context class. It calls `0047E670` and stores the derived vtable.
