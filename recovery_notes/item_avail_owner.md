# Item_Avail owner record

## Decision

`Item_Avail` is complete and belongs in `include/tplayer.h`, the owner header
for `tplayer.cpp`. The record has no base and no named gap fields.

## CodeView and function evidence

The CodeView type export at `orig/all_types_ground_truth.h:1440-1457` defines
11 fields, size `0x28`, and three compiler alignment gaps. The generated
`inventory/types/dumps/Item_Avail.txt` and `inventory/types/all_types.csv`
preserve the same record.

The fields are:

- `name` (`char*`) at `+0x00`;
- `id` (`short`) at `+0x04`;
- `pict` (`short`) at `+0x06`;
- `inventory_item_1` (`short`) at `+0x08`;
- `inventory_cost_1` (`float`) at `+0x0C`;
- `inventory_item_2` (`short`) at `+0x10`;
- `inventory_cost_2` (`float`) at `+0x14`;
- `inventory_item_3` (`short`) at `+0x18`;
- `inventory_cost_3` (`float`) at `+0x1C`;
- `help_string_id` (`long`) at `+0x20`; and
- `help_page_id` (`long`) at `+0x24`.

The `tplayer.cpp` owners `00513000` (lines 930-975) and `005131C0` (lines
979-1059) allocate records with stride `0x28` and write every listed field.
Their PDB rows are in `inventory/pdb/function_source_map.csv`. The FPO
inventory records both decorated `Item_Avail**` signatures in
`build/004AB300_dumpbin_fpo.txt`.

The header uses natural VC5 alignment. It does not publish padding, a union,
or a foreign base. The focused probe asserts the complete size and offsets.

## Validation

Probe source: `build/header_probes/item_avail_size.cpp`.

Command:

`CL.EXE @config/flags/default.rsp /Iinclude /Fobuild/header_probes/item_avail_size.obj build/header_probes/item_avail_size.cpp`

Result: return code `0`. The probe passed `sizeof(Item_Avail) == 0x28` and all
11 field offsets. Object SHA-256:
`9bc8351b7a269c299c680ec9006d3756cf78941b08de1d92581257d7f2b6550d`.
