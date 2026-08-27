# `rmm_elev.cpp` owner surface

## Result

The owner surface is complete enough for a natural header. The new header is
`include/rmm_elev.h`. The legacy `include/rmm_elev_context.h` stays unchanged.

The new header owns only the elevation records used by the elevation generator
and the generator class. It includes `rmm_base.h` for the proven base class and
stack record. It does not copy the base class. It has no padding fields, unions,
source globals, or context aliases.

## PDB and CodeView evidence

The pinned original PDB is `orig/age1_x1.pdb`. Its CodeView type export is
`orig/all_types_ground_truth.h`.

The complete CodeView records are:

| Record | CodeView export | Size | Layout |
| --- | ---: | ---: | --- |
| `RGE_Elevation_Info_Line` | lines 2867-2876 | `0x18` | six `long` fields at `0x00` through `0x14` |
| `RGE_Elevation_Hot_Spots` | lines 2849-2856 | `0x10` | four `long` fields at `0x00` through `0x0C` |
| `RGE_Elevation_Info` | lines 2858-2865 | `0xF80` | `elevation[99]`, count, `hot_spots[99]`, count |

The generated packets record the same facts in
`inventory/types/dumps/RGE_Elevation_Info_Line.txt`,
`inventory/types/dumps/RGE_Elevation_Hot_Spots.txt`, and
`inventory/types/dumps/RGE_Elevation_Info.txt`. The complete record offsets
are:

- `elevation[99]`: `99 * 0x18 = 0x948` bytes at `+0x00`.
- `elevation_num`: `long` at `+0x948`.
- `hot_spots[99]`: `99 * 0x10 = 0x630` bytes at `+0x94C`.
- `hot_spot_num`: `long` at `+0xF7C`.
- Total: `0xF80` bytes.

The CodeView generator record is at lines 3783-3787 of the same export. It
proves `RGE_RMM_Elevation_Generator` derives from `RGE_Random_Map_Module`,
contains `RGE_Elevation_Info info` at `+0x30`, and has size `0xFB0`.
The class packet at `inventory/types/dumps/RGE_RMM_Elevation_Generator.txt`
and the class interface packet at
`inventory/classes/dumps/RGE_RMM_Elevation_Generator.txt` agree.

The donor header
`C:/Projects/my_decomps/aoe1/src/game/include/RGE_RMM_Elevation_Generator.h`
proves the natural method surface and order. The PDB class interface packet
also records `generate` at virtual slot zero and all nine protected helpers.

The PDB source map proves the owner module and address sequence:

`004846C0`, `00484700`, `004847C0`, `004848A0`, `00484A40`, `00484B30`,
`00484B50`, `00484B90`, `00484C80`, `00484D00` all map to
`C:\\msdev\\work\\age1_x1\\rmm_elev.cpp`.

The source spans are `21-25`, `29-59`, `64-95`, `100-153`, `159-193`,
`198-205`, `211-221`, `225-260`, `264-285`, and `290-403`.
The direct PDB rows are in `inventory/pdb/function_source_map.csv`.
The address-to-line anchors are in `inventory/pdb/function_line_changes.csv`.

The separate `RGE_Elevation_Data` and `RGE_Elevation_Data_Entry` records are
database-file records. They are not fields of the elevation generator. They
remain private to the database-controller owner and are not copied into this
header.

## VC5 checks

The layout probe was
`build/tmp/rmm_elev_layout_probe.cpp`. It compiled with the pinned VC5
compiler, `config/flags/default.rsp`, and `include/rmm_elev.h`.
All four compile-time checks passed:

- `sizeof(RGE_Elevation_Info_Line) == 0x18`;
- `sizeof(RGE_Elevation_Hot_Spots) == 0x10`;
- `sizeof(RGE_Elevation_Info) == 0xF80`;
- `sizeof(RGE_RMM_Elevation_Generator) == 0xFB0`.

One focused constructor candidate used only `rmm_elev.h` and `<string.h>`.
The candidate used the existing natural body and did not edit a tracked owner.
It compiled with VC5 and compared as follows:

| VA | Result | Original | Rebuilt | Difference | Relocations | Boundary |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| `004846C0` | `MATCH` | 59 | 59 | `0` (`0.0000%`) | 2 compatible, 0 mismatched | 0 escapes |

The rebuilt owner symbol was
`??0RGE_RMM_Elevation_Generator@@QAE@PAVRGE_Map@@PAVRGE_Random_Map_Module@@PAURGE_Elevation_Info@@@Z`.
The PDB-qualified owner was
`RGE_RMM_Elevation_Generator::RGE_RMM_Elevation_Generator`.

This is a focused candidate result. It is not a registered translation-unit
claim.

## Natural source and consumer path

The smallest natural source destination is `src/rmm_elev.cpp`. It should
include `../include/rmm_elev.h` once. It should include `../include/map.h`
privately for `RGE_Map` methods and the complete `RGE_Tile` record. The source
also needs its period C-library headers and private `debug_rand` declaration
where the method bodies use them. The ten owner bodies should follow the PDB
order above. The current fragment wrapper and fragment includes still use the
legacy context; this task does not migrate them.

The original database-controller generator at VA `00483430` is the direct
consumer. Its PDB span is `rmm_dbct.cpp` lines 378-389. The original bytes at
`004834E8` allocate `0xFB0` bytes, and `00483517` calls `004846C0`. The current
database-controller source shows the same constructor call at
`src/rmm_dbct.cpp:680`.

This direct call proves the binary consumer edge. It does not prove a grouped
consumer composition. No grouped fanout was run in this task. Therefore this
note makes no grouped-composition claim. DBCT, TDBC, and the legacy context
remain unchanged.
