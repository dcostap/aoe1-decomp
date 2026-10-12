# `Picture.cpp` cleanup report

## Commits and files

- Module: `src/Picture.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source/final module commit: `0c57ce1807f4ecb5c87b3ad248728b4434493ec2`
- Branch: `cleanup/staging-20260915-180`
- Changed files:
  - `src/Picture.cpp`
  - `workflow/decomp_notes/source_cleanup/wave03/Picture.md`

The source commit contains only the assigned source file. This report is the
assigned durable evidence file. The header remains unchanged because the Owner
20 integration slot owns `include/Picture.h`.

## Evidence provenance

I used the original executable evidence and the pre-cleanup source.

- Scoped PDB records: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- Function registry: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/Picture.cpp.json`
- Function packets: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0046/`
- Original assembly: `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/picture.cpp.asm`
- Original decompilation: `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/picture.cpp.decomp`
- Prior module note: `workflow/decomp_notes/picture.md`
- Read-only module header: `include/Picture.h`

The PDB records identify `C:\msdev\work\age1_x1\Picture.cpp` as the source
module. They assign all eleven procedures to `Picture.obj` and record `this`
in `ecx` for each procedure. The function packets confirm the source order and
boundaries.

## Original-name recovery

I inspected all eleven registered procedures. The following names have direct
PDB support and are restored in `src/Picture.cpp`.

| VA | Procedure | Recovered parameters |
| --- | --- | --- |
| `0046DDE0` | `TPicture::TPicture(char*,long,int,void*,int)` | `FileName`, `res_id`, `UseTrans`, `MapToPal`, `ZeroIsTrans` |
| `0046DE30` | `TPicture::TPicture(int,int)` | `infile`, `UseTrans` |
| `0046DFA0` | default constructor | none |
| `0046DFC0` | destructor | none |
| `0046E020` | `Save` | `outfile` |
| `0046E0B0` | `Load` | `FileName`, `res_id`, `UseTrans`, `MapToPal`, `ZeroIsTrans` |
| `0046E270` | `Init` | `FromInfo`, `FromBits`, `FromTrans` |
| `0046E2C0` | `AlignedWidth` | none |
| `0046E2D0` | `Draw` | `DrawArea`, `DestX`, `DestY`, `Mirror`, `Flip` |
| `0046E370` | `Tile` | `DrawArea`, `DestX`, `DestY`, `DestWid`, `DestHgt`, `BlockWid`, `BlockHgt`, `SrcX`, `SrcY`, `SrcWid`, `SrcHgt` |
| `0046E3E0` | `GetPixel` | existing `x`, `y`; restored `Mirror`, `Flip` |

The PDB also records `temp_file_name` and `temp_file` in `Load`. The source
already used both names, so no body local required a rename. The helper
prototype declarations now use the recorded names `handle`, `data`,
`source_name`, and `source_line` where those PDB records apply.

The source keeps existing descriptive locals with no direct scoped PDB record:
`dib`, `bitmap`, `bits`, `info`, `height`, `trans_info`,
`transparency_bits`, `orientation`, and `row`. I did not map a reused or
optimized stack slot to one of these declarations.

The source keeps the recorded spelling and case. It does not normalize names
such as `FileName`, `UseTrans`, `MapToPal`, `DrawArea`, or `DestWid`.

## Constants, resources, and comments

No resource lookup occurs in this module. No resource ID name or shared
constant was added. The `res_id` parameter name is a PDB recovery, not a claim
about a string resource.

I preserved all existing literal values and types. This includes the binary
resource type value `0x62696e61`, the DIB size `0x428`, the transparency size
`0x18`, compression value `3`, and all zero and orientation values.

No source comment was added or removed. The fixed debug path and line value
remain unchanged.

## Shared-file requests

The header owner should align `include/Picture.h` parameter names with the
recovered source names. This request changes names only:

- The file constructor: `file_name`, `resource_id`, `palette_id`, `palette`,
  `palette_flags` to `FileName`, `res_id`, `UseTrans`, `MapToPal`,
  `ZeroIsTrans`.
- The stream constructor: `file_handle`, `param_2` to `infile`, `UseTrans`.
- `Save`: `fd` to `outfile`.
- `Load`: the same five names as the file constructor.
- `Init`: `info`, `bits`, `trans` to `FromInfo`, `FromBits`, `FromTrans`.
- `Draw`: `draw_area`, `x`, `y`, `dst_x`, `dst_y` to `DrawArea`, `DestX`,
  `DestY`, `Mirror`, `Flip`.
- `Tile`: `draw_area` and `param_2` through `param_11` to the eleven names
  listed in the recovery table.
- `GetPixel`: `param_3`, `param_4` to `Mirror`, `Flip`.

No other shared-file request is needed.

## Diff and code-generation review

The full diff against the base contains identifier substitutions and line
wrapping in the affected declarations and calls. It does not change types,
casts, declaration scope, storage duration, field layout, statement order,
expressions, literal values, calls, decorated symbols, or function boundaries.
The helper prototype name changes are also declaration-name-only changes.

`git diff --check` passed. Only the assigned source file changed in the source
commit. The accepted-drift status for `0046E270` and the scratch status of the
other prior candidates remain unchanged. No registry or build recipe changed.

The source remains unvalidated. Compilation, matching, audits, and tests were
not run. No build or game command was run.
