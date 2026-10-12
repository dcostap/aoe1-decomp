# Source-cleanup wave 04: `src/Res_file.cpp`

## Handoff

- Module: `src/Res_file.cpp`
- Branch: `cleanup/staging-20260915-245`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit: `c2076994499a18cee6bed677491feef1c3a11e67`
- Changed files:
  - `src/Res_file.cpp`
  - `workflow/decomp_notes/source_cleanup/wave04/Res_file.md`
- Assigned header: `include/Res_file.h` (read only; group owner)

The source and report keep LF line endings. I reviewed the complete source diff.

## Evidence

The name evidence is the procedure-scoped PDB index at:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The PDB source is `C:\msdev\work\age1_x1\Res_file.cpp`. The function inventories and original instruction listings are under:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`

The original executable remains the behavior oracle. No compiler or runtime command was used.

## PDB name recovery coverage

All nine normal procedures in this source have a scoped PDB record. Every record has zero register symbols and zero function-static records. The stack-symbol counts below include parameters and locals.

| VA | Function | PDB stack records | Recovery result |
| --- | --- | ---: | --- |
| `0047EE90` | `RESFILE_open_new_resource_file` | 9 | Recovered three parameters. Kept five PDB locals and `path`. |
| `0047F180` | `RESFILE_close_new_resource_file` | 1 | Recovered `res_file`. |
| `0047F230` | `RESFILE_locate_resource` | 8 | Recovered six parameters, `x`, and `p`. |
| `0047F320` | `RESFILE_load` | 9 | All PDB names already matched the source. |
| `0047F480` | `RESFILE_Extract_to_File` | 7 | Recovered three parameters and two locals. Kept `file` and `temp_path`. |
| `0047F580` | `RESFILE_Set_Missing_Flag` | 1 | Recovered `FlagVal`. |
| `0047F590` | `RESFILE_Decommit_Mapped_Memory` | 2 | Recovered `ResData` and `resSize`. |
| `0047F5C0` | `RESFILE_build_res_file` | 17 | Recovered `iq`. Kept all other matching PDB names. |
| `0047FC50` | `BUILDRES_get_files_resource_type` | 3 | Recovered `filename` and `extension`. Kept `extLen`. |

### Renamed identifiers

All names in this table are recovered original spellings from the scoped PDB. No new descriptive parameter or local names were added.

| Function | Before | After | Evidence and mapping |
| --- | --- | --- | --- |
| `0047EE90` parameter | `name` | `resFileName` | PDB stack record: `char*` at `+0x8`; the value builds the resource path and fills `ResFileHdr::res_name`. |
| `0047EE90` parameter | `cmpName` | `password` | PDB stack record: `char*` at `+0xc`; the value compares with `header->password`. |
| `0047EE90` parameter | `isMapped` | `open_mode` | PDB stack record: `int` at `+0x14`; the value selects mapped or file-backed opening. |
| `0047F180` parameter | `name` | `res_file` | PDB stack record: `char*` at `+0x4`; the value selects the list entry to close. |
| `0047F230` parameters | `type_id`, `res_id` | `rType`, `rId` | PDB stack records at `+0x4` and `+0x8`, both `unsigned long`. |
| `0047F230` output references | `out_fd`, `out_field1`, `out_data`, `out_field2` | `file`, `offset`, `mapped_file`, `size` | PDB stack records at `+0xc` through `+0x18`; types and output order match the source calls. |
| `0047F230` local | `i` | `x` | PDB stack record: `int` at `+0xc`; it is the type-directory loop counter. |
| `0047F230` local | `cur` | `p` | PDB stack record: `ResFileHdr*` at `-0x4`; it walks the resource-file list. |
| `0047F480` parameters | `type`, `id`, `name` | `rType`, `rId`, `file_name` | PDB records at `+0x4`, `+0x8`, and `+0xc`. |
| `0047F480` locals | `load_type`, `data_size` | `rLoadType`, `rDataSize` | PDB records at `-0x10c` and `-0x108`, both `int`. |
| `0047F580` parameter | `flag` | `FlagVal` | PDB stack record: `int` at `+0x4`. The mixed spelling is original. |
| `0047F590` parameters | `address`, `size` | `ResData`, `resSize` | PDB records at `+0x4` and `+0x8`; types are `unsigned char*` and `int`. |
| `0047F5C0` local | `idNode` | `iq` | PDB stack record: `BuildRes_id_node*` at `-0x4a0`; the source uses this declaration for ID-node traversal and cleanup. |
| `0047FC50` parameter | `name` | `filename` | PDB stack record: `char*` at `+0x4`; the value is scanned for an extension. |
| `0047FC50` local | `extBuf` | `extension` | PDB stack record: `char[8]` at `-0x8`; the buffer holds the normalized extension. |

`0047F320` already uses the PDB names `rType`, `rId`, `rLoadType`, `rDataSize`, `infile`, `offset`, `mapped_file`, `datalength`, and `error_string`. Its names were checked and left unchanged.

The build procedure also has exact PDB names already present in the source: `build_list_file`, `source_path`, `target_path`, `typeDirNode`, `resHandle`, `ID_List`, `theHeader`, `idDirNode`, `rPassword`, `rId`, `temp_filename`, `resource_filename`, `data_filename`, `buildFile`, `numResTypes`, and `build_filename`.

## Unresolved declaration mappings

The PDB omits several current source locals. I left these declarations unchanged because the PDB does not prove a reliable source mapping:

- `0047EE90`: `mapping`, `newFile`, and the list-tail `cur`.
- `0047F180`: `cur` and `prev`.
- `0047F230`: `hdr`, `dir`, `sub`, and the inner counter `j`.
- `0047F320`: the allocated-data pointer `data`.
- `0047F480`: the loaded-data pointer `data`.
- `0047F5C0`: `typeNode`, `lastType`, `lastId`, `filePos`, `dataPos`, `fileSize`, `type`, `typeCursor`, `dataHandle`, `nextId`, and `nextType`.
- `0047FC50`: `len`, `dotPos`, the inner counter `i`, character `c`, and table cursors `base` and `next`.

The PDB has optimized stack homes. `iq` and `ID_List` are separate PDB records. The `iq` rename follows the matching `BuildRes_id_node*` declaration and its ID-node uses. The source does not split variables, force stack homes, or change declaration order.

The original `0047EE90` extent includes parent-owned blocks at `0047F00C` and `0047F076`. This cleanup did not change those boundaries or the existing `__asm int 3` instruction.

## Proven symbolic constants

The source now uses existing pinned VC5 SDK and CRT symbols. The numeric values came from these local headers:

- `C:/Program Files (x86)/DevStudio/VC/Include/WINNT.H`
- `C:/Program Files (x86)/DevStudio/VC/Include/WINBASE.H`
- `C:/Program Files (x86)/DevStudio/VC/Include/WINUSER.H`
- `C:/Program Files (x86)/DevStudio/VC/Include/WINDEF.H`
- `C:/Program Files (x86)/DevStudio/VC/Include/FCNTL.H`
- `C:/Program Files (x86)/DevStudio/VC/Include/SYS/STAT.H`

| Existing value | New spelling | Uses |
| ---: | --- | --- |
| `0x80000000` | `GENERIC_READ` | `CreateFileA` access. |
| `1` | `FILE_SHARE_READ` | `CreateFileA` sharing mode. |
| `4` | `OPEN_ALWAYS` | `CreateFileA` creation mode. |
| `0x80` | `FILE_ATTRIBUTE_NORMAL` | `CreateFileA` attributes. |
| `2` | `PAGE_READONLY` | `CreateFileMappingA` protection. |
| `4` | `FILE_MAP_READ` | `MapViewOfFile` access. `WINBASE.H` maps this to `SECTION_MAP_READ` `0x0004`. |
| `0x30` | `MB_ICONEXCLAMATION` | All resource error message boxes. |
| `0x8000` | `_O_BINARY` | Binary input opens. |
| `0x8301` | `_O_BINARY | _O_WRONLY | _O_CREAT | _O_TRUNC` | Resource output open. |
| `0x180` | `_S_IREAD | _S_IWRITE` | Resource output permissions. |
| `0x104` | `MAX_PATH` | `GetTempPathA` buffer length. |
| `0x4000` | `MEM_DECOMMIT` | `VirtualFree` decommit type. |

The source added only `<fcntl.h>` and `<sys/stat.h>` for the CRT symbols. It did not define shared macros. The filename-length guard at `0x104`, header sizes, offsets, and other literals remain unchanged because this pass did not prove a stronger source meaning for those uses.

The macro values prove the numeric values. Compiler type conversion and generated output remain unverified. In particular, SDK constants use their pinned header spellings, while `_open` flags and permissions remain integer expressions for the varargs call.

## Resource IDs

`Res_file.cpp` has no Win32 string-resource lookup and no fixed `RT_STRING` ID. It only passes data IDs through the resource-file directory API. Therefore no DLL extraction or resource-ID mapping applies, and no `include/resource_ids.h` request is needed.

I ran `python tools/inspect_pe_strings.py --help` before resource work. No extraction was needed. No resource DLL hash, language, or text result exists for this module because it has no relevant string-resource lookup.

## Comments and presentation

No source comment was added or removed. Existing error text and the `INT3` path are unchanged. Function definitions now use 1TBS braces. Short signatures use one line where practical. No statement, call order, cast, literal payload, source owner, storage, layout, calling convention, public symbol, or ABI surface changed by intent.

## Shared-file requests

No header change is requested.

- `include/Res_file.h` remains group-owner owned and unchanged. Its parameter names need not match definition parameter names.
- `include/game_globals.h` and `src/game_globals.cpp` were not edited.
- `include/resource_ids.h` needs no definition for this module.
- The new CRT includes are private to `src/Res_file.cpp`.

## Possible effects and unresolved questions

- Identifier changes should affect debug names only. No compiler output check was allowed.
- SDK and CRT macro substitutions preserve the documented values, but type conversion and code emission remain open until the final validation stage.
- Formatting can change debug line records. No line-dependent macro appears in this source.
- Optimized PDB homes do not prove a one-to-one source declaration layout. Omitted locals remain unchanged.
- The existing `__asm int 3` is outside this cleanup's allowed assembly changes. It was not introduced or removed.
- Resource-file error paths still preserve their original allocation, close, and failure behavior. This report does not claim semantic approval.

## Validation status

Compilation, matching checks, audits, validation commands, and tests were **not run** by user instruction. The game was not launched. I do not claim byte equality, semantic approval, or validated compiler output.
