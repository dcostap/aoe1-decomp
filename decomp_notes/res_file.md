# Res_file.cpp module recovery and ABI packet

## Migration state

- PDB source: `C:\\msdev\\work\\age1_x1\\Res_file.cpp`.
- Natural source: `src/Res_file.cpp`.
- Natural header: `include/Res_file.h`.
- Candidate proposal: `build/candidate_tus/Res_file.json`.
- The old wrapper and context header are replaced by the natural source and
  header. The source has no source-bank includes or private fallback layouts.
- The lead owns grouped exact validation. Focused checks below record the
  current compile and representative owner results.

The orchestrator assigned all seven resource record types to `Res_file.cpp`.
Their canonical declarations are in `include/Res_file.h`. The declarations use
only the PDB field names and sizes recorded below. No virtual methods or other
methods occur in these PDB records.

## PDB ownership and source order

The PDB function map proves one source path for all nine normal owners. The
packet is `build/tu_plans/Res_file_cpp/packet.json` and its text form is
`build/tu_plans/Res_file_cpp/packet.txt`. The source map is also recorded in
`inventory/pdb/function_source_map.csv`.

| VA | PDB owner | PDB lines | bytes | prior status |
| --- | --- | ---: | ---: | --- |
| `0047EE90` | `RESFILE_open_new_resource_file` | 70-233 | 541 | scratch |
| `0047F180` | `RESFILE_close_new_resource_file` | 240-286 | 170 | matching |
| `0047F230` | `RESFILE_locate_resource` | 293-411 | 232 | matching |
| `0047F320` | `RESFILE_load` | 420-484 | 346 | verified_logic |
| `0047F480` | `RESFILE_Extract_to_File` | 496-536 | 247 | matching |
| `0047F580` | `RESFILE_Set_Missing_Flag` | 544-546 | 10 | matching |
| `0047F590` | `RESFILE_Decommit_Mapped_Memory` | 555-563 | 33 | matching |
| `0047F5C0` | `RESFILE_build_res_file` | 574-935 | 1669 | scratch |
| `0047FC50` | `BUILDRES_get_files_resource_type` | 943-990 | 217 | matching |

The PDB order is strictly increasing in the table above. The original source
also contributes parent-owned blocks at `0047F00C` and `0047F076` inside the
`0047EE90` source span. These are not extra normal owners in the packet.

## Canonical type ownership and evidence

### `ResFileHdr`

- Owner: `Res_file.cpp`, by orchestrator decision and use by the three PDB
  owners `0047EE90`, `0047F180`, and `0047F230`.
- PDB record: `inventory/types/dumps/ResFileHdr.txt`.
- Size: `0x114` (276 bytes).
- Fields:
  - `mapped_file` at `+0x00`, `unsigned char*`.
  - `handle` at `+0x04`, `int`.
  - `header` at `+0x08`, `resfile_header*`.
  - `next` at `+0x0C`, `ResFileHdr*`.
  - `res_name` at `+0x10`, `char[260]`.
- Binary evidence: `RESFILE_open_new_resource_file` allocates `0x114` bytes
  at `0047EF6F` and stores these fields. The list walk reads `+0x0C` at
  `0047F076-0047F09B`, `0047F180-0047F1D1`, and `0047F230-0047F2CE`.
  `RESFILE_close_new_resource_file` reads the name at `+0x10`, the handle at
  `+0x04`, the mapped pointer at `+0x00`, and the header at `+0x08`.
- Methods: none in the PDB record.

### `resfile_header`

- Owner: `Res_file.cpp`, by orchestrator decision and use by `0047EE90`,
  `0047F230`, and `0047F5C0`.
- PDB record: `inventory/types/dumps/resfile_header.txt`.
- Size: `0x40` (64 bytes).
- Fields:
  - `banner_msg` at `+0x00`, `char[40]`.
  - `version` at `+0x28`, `char[4]`.
  - `password` at `+0x2C`, `char[12]`.
  - `num_res_types` at `+0x38`, `int`.
  - `directory_size` at `+0x3C`, `int`.
- Binary evidence: the file-backed open path reads `0x40` bytes into this
  record at `0047EFF7-0047F009` and reads `directory_size` at `+0x3C`.
  The password check reads `+0x2C` at `0047F0A1`, and the version check reads
  `+0x28` at `0047F0F0`. `RESFILE_locate_resource` reads the type count at
  `+0x38` at `0047F27E`. The builder writes `0x40` bytes from this record.
- Methods: none in the PDB record.

### `resfile_type_dir_node`

- Owner: `Res_file.cpp`, by orchestrator decision and use by
  `RESFILE_locate_resource` and `RESFILE_build_res_file`.
- PDB record: `inventory/types/dumps/resfile_type_dir_node.txt`.
- Size: `0x0C` (12 bytes).
- Fields:
  - `type` at `+0x00`, `unsigned long`.
  - `dirOffset` at `+0x04`, `long`.
  - `numID` at `+0x08`, `long`.
- Binary evidence: `RESFILE_locate_resource` starts the first type record at
  header `+0x40`, reads the three words at `+0x40`, `+0x44`, and `+0x48`, and
  advances by `0x0C` at `0047F285-0047F2BD`. The builder writes one `0x0C`
  record per resource type.
- Methods: none in the PDB record.

### `resfile_id_dir_node`

- Owner: `Res_file.cpp`, by orchestrator decision and use by
  `RESFILE_locate_resource` and `RESFILE_build_res_file`.
- PDB record: `inventory/types/dumps/resfile_id_dir_node.txt`.
- Size: `0x0C` (12 bytes).
- Fields:
  - `id` at `+0x00`, `unsigned long`.
  - `itemOffset` at `+0x04`, `long`.
  - `itemSize` at `+0x08`, `long`.
- Binary evidence: the locate loop compares the ID at the record base and
  reads the offset and size at the next two words at `0047F2A0-0047F303`.
  The builder writes all three words with a `0x0C` record size.
- Methods: none in the PDB record.

### `res_file_type_info`

- Owner: `Res_file.cpp`, by orchestrator decision and use by
  `BUILDRES_get_files_resource_type`.
- PDB record: `inventory/types/dumps/res_file_type_info.txt`.
- Size: `0x08` (8 bytes).
- Fields:
  - `extension` at `+0x00`, `char[4]`.
  - `rType` at `+0x04`, `unsigned long`.
- Binary evidence: the table base is `0x00585520`; its first type word is at
  `0x00585524`, recorded as `DAT_00585524 = 0x766F6320`. The original loop
  reads the sentinel/type word at `0047FCD9`, compares the four-byte extension
  at `0047FCEF-0047FCF1`, reads the result at `+0x04` at `0047FD14`, and
  advances each entry by eight bytes at `0047FD00`.
- Methods: none in the PDB record.

### `BuildRes_type_node`

- Owner: `Res_file.cpp`, by orchestrator decision and use only by
  `RESFILE_build_res_file`.
- PDB record: `inventory/types/dumps/BuildRes_type_node.txt`.
- Size: `0x14` (20 bytes).
- Fields:
  - `type` at `+0x00`, `unsigned long`.
  - `idOffset` at `+0x04`, `int`.
  - `nIds` at `+0x08`, `int`.
  - `idList` at `+0x0C`, `BuildRes_id_node*`.
  - `next` at `+0x10`, `BuildRes_type_node*`.
- Binary evidence: `RESFILE_build_res_file` allocates this node with the PDB
  record size `0x14`, compares and stores `type`, maintains `idOffset` and
  `nIds`, and walks `idList` and `next` through the build and cleanup loops.
- Methods: none in the PDB record.

### `BuildRes_id_node`

- Owner: `Res_file.cpp`, by orchestrator decision and use only by
  `RESFILE_build_res_file`.
- PDB record: `inventory/types/dumps/BuildRes_id_node.txt`.
- Size: `0x118` (280 bytes).
- Fields:
  - `id` at `+0x00`, `unsigned long`.
  - `dataOffset` at `+0x04`, `int`.
  - `resData` at `+0x08`, `unsigned char*`.
  - `resSize` at `+0x0C`, `int`.
  - `next` at `+0x10`, `BuildRes_id_node*`.
  - `fName` at `+0x14`, `char[260]`.
- Binary evidence: `RESFILE_build_res_file` allocates this node with the PDB
  record size `0x118`, stores the ID, data offset, data pointer, size, next
  pointer, and file name, then frees the data and nodes in the final cleanup.
- Methods: none in the PDB record.

## Proposed canonical declarations and unresolved shared ABI

The completed module header provides the seven record declarations above and
these function surfaces:

```cpp
void __cdecl RESFILE_open_new_resource_file(char*, char*, char*, int);
void __cdecl RESFILE_close_new_resource_file(char*);
int __cdecl RESFILE_locate_resource(
    unsigned long, unsigned long, int&, int&, unsigned char*&, int&);
unsigned char* __cdecl RESFILE_load(
    unsigned long, unsigned long, int&, int&);
int __cdecl RESFILE_Extract_to_File(
    unsigned long, unsigned long, char*, FILE*&);
void __cdecl RESFILE_Set_Missing_Flag(int);
int __cdecl RESFILE_Decommit_Mapped_Memory(unsigned char*, int);
int __cdecl RESFILE_build_res_file(char*, char*, char*);
unsigned long __cdecl BUILDRES_get_files_resource_type(char*);
```

The following declarations remain orchestrator-owned ABI requests. This module
does not edit shared global definitions or shared headers.

1. `DAT_0086b254` at image VA `0x0086B254`.
   `inventory/globals/dumps/0086B254_DAT_0086b254.txt` records a four-byte
   writable global. Binary references at `0047F076`, `0047F184`, `0047F1F8`,
   and `0047F240` prove that it is the head of the `ResFileHdr` list. Proposed
   declaration: `extern ResFileHdr* DAT_0086b254;`. The current generated
   `include/game_globals.h` declaration is `extern unsigned int`, which cannot
   represent the observed list owner. This request is blocking until the lead
   resolves the shared declaration and definition.

2. `DAT_0086b258` at image VA `0x0086B258`.
   `inventory/globals/dumps/0086B258_DAT_0086b258.txt` records references at
   `0047F36B` and `0047F584`. The original instructions load and store a dword;
   `RESFILE_Set_Missing_Flag(int)` writes it and `RESFILE_load` tests it.
   Proposed declaration: `extern int DAT_0086b258;`. The inventory currently
   omits its size and type. The lead should add the reviewed global declaration
   and definition without renaming it to `RESFILE_Missing_Flag`.

3. `res_extension_table` at image VA `0x00585520`.
   `BUILDRES_get_files_resource_type` uses the table base at `0047FCDE`, the
   sentinel/type word at `DAT_00585524`, and eight-byte entries. Proposed
   declaration: `extern res_file_type_info res_extension_table[];`. The table
   definition and ownership are not present in the current global inventory.
   The lead should preserve the shipped table and must not replace it with a
   guessed local table.

These requests are shared ABI work. They are not private fallback declarations.
Do not use `include/tcommand.h` as a source for any of them.

## Consumers and validation fanout

Direct source references were checked with `rg` across `src` and `include`.
The lead should validate the new Res_file grouped candidate and then fan out
ABI checks as follows:

| Consumer | Uses | Required check |
| --- | --- | --- |
| `src/Dib.cpp` | `RESFILE_load` | Confirm C++ cdecl reference-output ABI and owner target. |
| `src/Shape.cpp` | `RESFILE_load`, `RESFILE_Decommit_Mapped_Memory` | Confirm load linkage and both output references; confirm decommit target. |
| Sounddrv owner `004BCD30` (`src/scratch/004BCD30_load.cpp`) | `RESFILE_load` | Repair its currently incompatible C-linkage/pointer-output declaration only in its own TU, then check the call target and output order. |
| `src/matching/0046E0B0_Load.cpp` | `RESFILE_Extract_to_File` | Confirm `FILE*&` output ABI and direct target. |
| `src/matching/0041D0A0_setup_cmd_options.cpp` | `RESFILE_Set_Missing_Flag` | Confirm the shared `DAT_0086b258` store. |
| `src/tribegam.cpp` | open, close, build | Confirm C++ cdecl declarations and argument constness against PDB symbols. |
| `src/Res_file.cpp` | all nine owners and all seven records | The lead owns grouped candidate validation. |

The requested minimum fanout is `Dib`, `Shape`, and Sounddrv `004BCD30`. The
other rows identify all direct repository consumers found in this checkout and
prevent a declaration repair from hiding a cross-TU ABI regression.

## Status and regressions

- `0047F180`, `0047F230`, `0047F480`, `0047F580`, `0047F590`, and `0047FC50`
  retain their prior `matching` status as source status only. The merged TU has
  not been validated here.
- `0047F320` retains `verified_logic`. Its known remaining difference is the
  mapped-data LEA SIB base/index byte documented in its prior recovery history.
- `0047EE90` retains `scratch`. Its body contains parent-owned fragments at
  `0047F00C` and `0047F076`; the original file-backed short-read path reaches
  an `INT3` before the error dialog. Inline assembly is forbidden.
- `0047F5C0` retains `scratch`. Its clean source checkpoint has the proven
  `0x4A4` frame, 35 ordered calls, and a remaining source-shape difference in
  header-copy scheduling and scalar homes. The current module source keeps the
  natural PDB-named records and cleanup order.
- No exact claim is made by this migration. The lead must record grouped result,
  owner, boundary, relocation, and direct-target outcomes after validation.

## Rejected repair pass

`0047EE90` was tested with a function-scoped frame-pointer option. The frame
matched, but 357 bytes still differed. The option has no source evidence and
was not retained.

`0047F320` retains one mapped-data LEA SIB byte. Natural pointer variants did
not remove it. `0047F5C0` retains its 680-byte difference after natural local
and declaration-order variants. The clean source remains authoritative.

## ABI compile repair

The Win32 headers already provide the PDB-compatible imported C-linkage
`__stdcall` declarations and record types. The source no longer redeclares
those APIs with local `HANDLE`, `DWORD`, or `void*` substitutes.

Resource consumers now include the canonical header. This removes the former
`RESFILE_load` and `RESFILE_close_new_resource_file` declarations. The latter
had incorrectly added `const` to its `char*` parameter and changed its C++
decorated target.

The full Res_file source now compiles. `0047F180`, `0047F230`, and
`0047F480` remain `MATCH` with `0.0000%`. `0047F320` remains a one-byte
`CONSISTENT_REGISTER_RECOLOR` mismatch documented above.
