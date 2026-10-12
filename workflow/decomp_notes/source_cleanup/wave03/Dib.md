# Source cleanup report: `Dib.cpp`

## Delivery

- Module: `src/Dib.cpp`.
- Base commit from `git rev-parse`: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final source commit from `git rev-parse`: `0789a3591bb8a64f5f162e70c8a696297f36b554`.
- Branch: `cleanup/staging-20260915-179`.
- Changed files: `src/Dib.cpp`; this report.
- Registry: `config/functions/src/Dib.cpp.json`; build flags `default`.
- Header owner: owner 20 owns `include/dib.h`. This worker did not edit it.

The cleanup covers all 28 procedures in the registry. It restores names from
procedure-scoped PDB records. It replaces four opaque Win32 values with pinned
SDK symbols. It does not change function symbols, types, storage, control flow,
declaration order, call targets, or resource lookup behavior.

The follow-up source commit applies 1TBS opening-brace placement throughout
`src/Dib.cpp`. It changes brace placement only. It does not add or remove
braces, move statements, or change executable tokens.

The PDB source is `C:\\msdev\\work\\age1_x1\\Dib.cpp`. Every PDB record uses
`.\\Release\\Dib.obj`. The original executable remains the behavior oracle:

`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`

Its SHA-256 is `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

## Evidence and coverage

Name evidence comes from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/Dib.cpp.json`.
- The 28 function packets under
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/`.
- Pinned VC5 headers under `C:/Program Files (x86)/DevStudio/VC/Include/`.

I inspected every assigned function packet. Each scoped PDB record has an empty
`function_statics` list and an empty `register_symbols` list. The table lists
every stack symbol. Offsets are entry-relative PDB offsets.

| VA | Function | PDB span; records | Scoped PDB stack records | Source result |
| --- | --- | --- | --- | --- |
| `00438820` | `DibBlt` | 72-145; 39 | Parameters: `DestInfo` +0x4 `BITMAPINFO256*`; `DestBits` +0x8 `unsigned char*`; `ClipRect` +0xc `tagRECT*`; `DestX` +0x10, `DestY` +0x14, `DestWid` +0x18, `DestHgt` +0x1c, `SrcX` +0x28, `SrcY` +0x2c, `SrcWid` +0x30, `SrcHgt` +0x34 `long`; `SrcInfo` +0x20 `BITMAPINFO256*`; `Clip` +0x38, `Mirror` +0x3c, `Flip` +0x40 `int`. Locals: `DestTotHgt` -0x4, `DestOrien` -0x8, `DestTotWid` +0x3c, `SrcOrien` +0x8, `SrcTotWid` +0x44, `SrcTotHgt` +0x10, `sySkip` +0x24 `long`; `dy` +0x40 `long`. | Renamed all parameters to recovered PDB names. Renamed dimension, orientation, destination-row, and fixed-point source-row locals to recovered PDB names. Other locals have no reliable PDB mapping and remain unchanged. |
| `00438AA0` | `TransDibBlt` | 155-273; 63 | Parameters: `DestInfo` +0x4 `BITMAPINFO256*`; `DestBits` +0x8 `unsigned char*`; `ClipRect` +0xc `tagRECT*`; `DestX` +0x10, `DestY` +0x14, `DestWid` +0x18, `DestHgt` +0x1c, `SrcX` +0x2c, `SrcY` +0x30, `SrcWid` +0x34, `SrcHgt` +0x38 `long`; `SrcInfo` +0x20 `BITMAPINFO256*`; `TransInfo` +0x28 `TRANSINFO*`; `Clip` +0x3c, `Mirror` +0x40, `Flip` +0x44, `TransColor` +0x48 `int`. Locals: `DestTotHgt` -0x4, `DestOrien` -0x8, `sySkip` -0xc, `SrcTotHgt` -0x10 `long`; `dy` +0x44, `dxSkip` +0x10, `DestTotWid` +0x40, `sy` +0x2c, `SrcOrien` +0x48, `SrcTotWid` +0x8 `long`; `b` +0xc `unsigned char`. | Renamed all parameters and the proved dimension, orientation, destination-row, source-row, destination-skip, and pixel locals. The PDB `sySkip` local has no direct current declaration mapping. Other locals remain unchanged. |
| `00438E80` | `ClipDibBlt` | 280-366; 39 | Parameters: `DestInfo` +0x4 `BITMAPINFO256*`; `ClipRect` +0x8 `tagRECT*`; `DestX` +0xc, `DestY` +0x10, `DestWid` +0x14, `DestHgt` +0x18, `SrcX` +0x1c, `SrcY` +0x20, `SrcWid` +0x24, `SrcHgt` +0x28 `long&`; `Mirror` +0x2c, `Flip` +0x30 `int`. Locals: `ey` -0x4, `ex` +0x8, `sySkip` +0xc `long`. | Renamed all parameters. Renamed the clipped right and bottom bounds to recovered `ex` and `ey`. The PDB `sySkip` local has no direct current declaration mapping. |
| `00439060` | `GetDibDim` | 372-383; 8 | Parameters: `Info` +0x4 `BITMAPINFO256*`; `TotWid` +0x8, `TotHgt` +0xc, `Orien` +0x10 `long&`. | Renamed all parameters to recovered PDB names. |
| `004390A0` | `TileDibBlt` | 394-628; 63 | Parameters: `DestInfo` +0x4 `BITMAPINFO256*`; `DestBits` +0x8 `unsigned char*`; `ClipRect` +0xc `tagRECT*`; `DestX` +0x10, `DestY` +0x14, `DestWid` +0x18, `DestHgt` +0x1c, `BlockWid` +0x20, `BlockHgt` +0x24, `SrcX` +0x34, `SrcY` +0x38, `SrcWid` +0x3c, `SrcHgt` +0x40 `long`; `SrcInfo` +0x28 `BITMAPINFO256*`; `SrcBits` +0x2c `unsigned char*`; `TransInfo` +0x30 `TRANSINFO*`; `Trans` +0x44, `Mirror` +0x48, `Flip` +0x4c `int`. Locals: `DestRtWid` +0x40, `yBlocks` +0x20, `sxSkip` +0x40, `xBlocks` +0x1c, `DestTopHgt` +0x44, `sySkip` +0x44, `DestY1` +0x18 and +0x34 `long`; `SrcBotHgt` -0x1c, `SrcTopHgt` -0x10, `DestBotHgt` -0x14, `SrcLtWid` -0xc, `SrcRtWid` -0x18 `long`. | No rename. All recorded parameter and local names already match the source. Reused PDB offsets remain unforced. |
| `004395A0` | `DibCheckTrans` | 634-714; 36 | Parameters: `DibInfo` +0x4 `BITMAPINFO256*`; `TransInfo` +0x8 `TRANSINFO*`; `DibBits` +0xc `unsigned char*`. Locals: `AnyTrans` -0x10 `int`; `orien` -0x4, `h` -0x14, `tw` -0xc, `w` -0x8, `y` +0x8 `long`. | No rename. All recorded parameter and local names already match the source. |
| `00439700` | `GetPaletteFromDib` | 721-732; 10 | Parameters: `FileName` +0x4 `char*`; `MakeIdentity` +0x8 `int`. | Renamed `path` and `make_identity` to recovered PDB names. |
| `00439750` | `ReadPalette` | 738-899; 62 | Parameters: `FileName` +0x4 `char*`; `ResourceId` +0x8 `long`; `MakeIdentity` +0xc `int`. Locals: `own_mem` -0xc `int`; `resDataSize` -0x4 `int`; `data` -0x10 `char*`; `hpal` -0x8 `void*`; `seps` +0x8 `char[3]`; `ok` +0xc `int`. | Renamed all parameters. Renamed `result` to recovered `hpal` and `data_size` to recovered `resDataSize`. The PDB `own_mem` type is `int`, while the current `own_mem` declaration is a pointer. It was not forced. The ownership flag remains the descriptive `owns_memory`. The PDB `ok` record has no direct declaration mapping. |
| `00439A10` | `DibOpenFile` | 930-1003; 25 | Parameter: `szFile` +0x4 `char*`. Locals: `of` -0x88 `_OFSTRUCT`; `fh` -0x90 `int`; `dwBits` -0x8c `unsigned long`. | Renamed `name` to recovered `szFile`. All recorded locals already match. |
| `00439B50` | `ReadDibBits` | 1011-1035; 14 | Parameter: `szFile` +0x4 `char*`. Local: `of` -0x88 `_OFSTRUCT`. | Renamed `param_1` to recovered `szFile`. The recorded local already matches. |
| `00439BE0` | `DibWriteClipped` | 1042-1059; 11 | Parameters: `pDIB` +0x4 `tagBITMAPINFOHEADER*`; `szFile` +0x8 `char*`; `x` +0xc, `y` +0x10, `w` +0x14, `h` +0x18 `long`. | Renamed all parameters to recovered PDB names. |
| `00439CC0` | `DibWriteFile` | 1066-1095; 17 | Parameters: `pdib` +0x4 `tagBITMAPINFOHEADER*`; `szFile` +0x8 `char*`. Locals: `hdr` -0x98 `tagBITMAPFILEHEADER`; `of` -0x88 `_OFSTRUCT`. | Renamed `name` to recovered `szFile`. The other records already match. |
| `00439D80` | `DibCreatePalette` | 1105-1155; 25 | Parameter: `pdib` +0x4 `tagBITMAPINFOHEADER*`. Local: `hpal` -0x4 `void*`. | Renamed `dib` to recovered `pdib`. The recorded local already matches. |
| `00439E50` | `DibReadBitmapInfo` | 1166-1280; 36 | Parameter: `fh` +0x4 `int`. Locals: `off` -0x48 `unsigned long`; `bi` -0x28 `tagBITMAPINFOHEADER`; `bf` -0x38 `tagBITMAPFILEHEADER`; `size` +0x8 `int`; `bc` -0x44 `tagBITMAPCOREHEADER`; `pdib` -0x50 `tagBITMAPINFOHEADER*`; `rgb` +0x8 `tagRGBQUAD`. | No rename. The inner `rgb` record already matches. The outer `pRgb` pointer has no PDB record. |
| `0043A070` | `DibFromBitmap` | 1290-1416; 51 | Parameters: `hbm` +0x4 `void*`; `biStyle` +0x8 `unsigned long`; `biBits` +0xc `unsigned int`; `hpal` +0x10 `void*`; `wUsage` +0x14 `unsigned int`. Locals: `bm` -0x18 `tagBITMAP`; `nColors` -0x1c `int`. | Renamed `usage` to recovered `wUsage`. All recorded locals already match. |
| `0043A330` | `DibSetUsage` | 1482-1538; 20 | Parameters: `pdib` +0x4 `tagBITMAPINFOHEADER*`; `hpal` +0x8 `void*`; `wUsage` +0xc `unsigned int`. Local: `ape` -0x400 `tagPALETTEENTRY[1024 bytes]`. | No rename. All recorded records already match. |
| `0043A420` | `DibDraw` | 1546-1589; 11 | Parameters: `hdc` +0x4 `void*`; `x` +0x8, `y` +0xc, `dx` +0x10, `dy` +0x14, `x0` +0x1c, `y0` +0x20, `dx0` +0x24, `dy0` +0x28 `int`; `pdib` +0x18 `tagBITMAPINFOHEADER*`; `rop` +0x2c `long`; `wUsage` +0x30 `unsigned int`. | Renamed all generated `a1`-`a12` parameters to recovered PDB names. |
| `0043A4B0` | `DibCopy` | 1592-1602; 8 | Parameter: `pdib` +0x4 `tagBITMAPINFOHEADER*`. | Renamed `dib` to recovered `pdib`. |
| `0043A500` | `DibCreate` | 1605-1659; 29 | Parameters: `bits` +0x4, `dx` +0x8, `dy` +0xc `int`. | No rename. All records already match. |
| `0043A660` | `DibMapToPalette` | 1782-1923; 65 | Parameters: `pdib` +0x4 `tagBITMAPINFOHEADER*`; `hpal` +0x8 `void*`; `TransLogic` +0xc, `ZeroIsTrans` +0x10 `int`. Locals: `SizeImage` -0x120 `unsigned long`; `pe` -0x110 `tagPALETTEENTRY`; `nDibColors` -0x118 `int`; `xlat` -0x100 `unsigned char[256]`; `HitEnd` -0x104 `int`; `nPalColors` -0x11c `int`; `ZeroIndex` -0x125 `unsigned char`; `lpBits` -0x124 `unsigned char*`; `ZeroBlue` -0x10c `int`; `TransIndex` -0x108 `unsigned char`; `lpRgb` -0x114 `tagRGBQUAD*`. | No rename. All recorded parameters and locals already match. |
| `0043AA60` | `xlatClut8` | 1691-1700; 4 | Parameters: `pb` +0x4 `unsigned char*`; `dwSize` +0x8 `unsigned long`; `xlat` +0xc `unsigned char*`. | No rename. All records already match. |
| `0043AA90` | `xlatClut4` | 1703-1712; 5 | Parameters: `pb` +0x4 `unsigned char*`; `dwSize` +0x8 `unsigned long`; `xlat` +0xc `unsigned char*`. | No rename. All records already match. |
| `0043AAD0` | `xlatRle8` | 1720-1763; 15 | Parameters: `pb` +0x4 `unsigned char*`; `dwSize` +0x8 `unsigned long`; `xlat` +0xc `unsigned char*`. Local: `b` +0x8 `unsigned char`. | Renamed `data` and `unused` to recovered `pb` and `dwSize`. Renamed `value` to recovered `b`. The other locals have no reliable PDB mapping. |
| `0043AB40` | `xlatRle4` | 1766-1766; 1 | Parameters: `pb` +0x4 `unsigned char*`; `dwSize` +0x8 `unsigned long`; `xlat` +0xc `unsigned char*`. | Added the recovered parameter names to the empty definition. The PDB body is one byte and has no locals. |
| `0043AB50` | `memmove` | 1770-1776; 6 | Parameters: `d` +0x4 `unsigned char*`; `s` +0x8 `unsigned char*`; `len` +0xc `long`. | No rename. All records already match. |
| `0043AB80` | `CreateIdentityPalette` | 1930-1992; 24 | Parameter: `hpal` +0x4 `void*`. Locals: `hdc` -0x808 `void*`; `from_pal` -0x400 `tagPALETTEENTRY[1024 bytes]`; `new_pal` -0x800 `tagPALETTEENTRY[1024 bytes]`; `hwnd` -0x804 `void*`. | Renamed `palette` to recovered `hpal`. The current union and overrun-preserving source structures cannot map directly to the PDB array names. |
| `0043ACB0` | `CopyPalette` | 1999-2026; 17 | Parameter: `hpal` +0x4 `void*`. Local: `nNumEntries` -0x4 `int`. | Renamed `param_1` to recovered `hpal`. The recorded local already matches. |
| `0043AD40` | `DibFree` | 2029-2031; 3 | Parameter: `pdib` +0x4 `tagBITMAPINFOHEADER*`. | Renamed `param_1` to recovered `pdib`. |

All names copied from the PDB are recovered original names. No new descriptive
names were added. Existing descriptive locals remain when the PDB has no safe
declaration mapping. No function has a register-name recovery requirement.

## Constants, resources, and comments

The source replaces these values with symbols. Each replacement has the same
value and effective VC5 type in the pinned headers:

- `MAKEINTRESOURCEA(2)` became `RT_BITMAP`. `WINUSER.H:137-151` defines
  `RT_BITMAP` through the same ANSI resource expression.
- `SetStretchBltMode(hdc, 4)` became `STRETCH_HALFTONE`.
  `WINGDI.H:109-117` defines `HALFTONE` as `4` and the stretch symbol as it.
- `GlobalAlloc(2, ...)` became `GlobalAlloc(GMEM_MOVEABLE, ...)`.
  `WINBASE.H:504` defines `GMEM_MOVEABLE` as `0x0002`.
- `LocalAlloc(0x40, ...)` became `LocalAlloc(LMEM_ZEROINIT, ...)`.
  `WINBASE.H:545` defines `LMEM_ZEROINIT` as `0x0040`.

`BI_BITFIELDS` remains in its original existing uses. Numeric compression checks
remain unchanged because the pinned macro is a suffixed `long`, while the source
literals are unsuffixed integers.

No RT_STRING resource ID was added or renamed. `ReadPalette` keeps its dynamic
custom-resource lookup. It first tries `FileName` when `shape_file_first` is set.
It then calls `RESFILE_load(0x62696e61, ResourceId, ...)`. The first argument is
a binary resource type, not a string ID. Its purpose and ID range remain
unresolved. No DLL text, language, or fallback mapping was changed.

The existing `SrcXTbl` storage comment remains unchanged. No new comments were
needed.

## Risks and requests

- Parameter and local renames do not change ABI types, storage, layout, or calls.
- Macro replacements use definitions read from the pinned VC5 SDK headers.
- The source still contains optimized stack-slot aliases that lack reliable
  declaration mappings. The report records them instead of forcing names.
- The current `ReadPalette` ownership declarations differ from the PDB type
  record. Further recovery needs source or stronger ABI evidence.
- The current `CreateIdentityPalette` union and source-array overrun model needs
  separate structural review. This cleanup does not reshape it.
- Header request to owner 20: align `include/dib.h` declaration parameter names
  with the PDB-backed definitions. Keep all types, signatures, and ABI details.
  Requested names are listed below; this worker did not edit the header.
  `DibBlt`: `DestInfo`, `DestBits`, `ClipRect`, `DestX`, `DestY`, `DestWid`,
  `DestHgt`, `SrcInfo`, `SrcBits`, `SrcX`, `SrcY`, `SrcWid`, `SrcHgt`,
  `Clip`, `Mirror`, `Flip`.
  `TransDibBlt`: the same first nine names, then `TransInfo`, `SrcX`, `SrcY`,
  `SrcWid`, `SrcHgt`, `Clip`, `Mirror`, `Flip`, `TransColor`.
  `ClipDibBlt`: `DestInfo`, `ClipRect`, `DestX`, `DestY`, `DestWid`, `DestHgt`,
  `SrcX`, `SrcY`, `SrcWid`, `SrcHgt`, `Mirror`, `Flip`.
  `GetDibDim`: `Info`, `TotWid`, `TotHgt`, `Orien`.
  `TileDibBlt`: `DestInfo`, `DestBits`, `ClipRect`, `DestX`, `DestY`, `DestWid`,
  `DestHgt`, `BlockWid`, `BlockHgt`, `SrcInfo`, `SrcBits`, `TransInfo`,
  `SrcX`, `SrcY`, `SrcWid`, `SrcHgt`, `Trans`, `Mirror`, `Flip`.
  `DibCheckTrans`: `DibInfo`, `TransInfo`, `DibBits`.
  `GetPaletteFromDib`: `FileName`, `MakeIdentity`. `ReadPalette`: `FileName`,
  `ResourceId`, `MakeIdentity`. `DibOpenFile` and `ReadDibBits`: `szFile`.
  `DibWriteClipped`: `pDIB`, `szFile`, `x`, `y`, `w`, `h`.
  `DibWriteFile`: `pdib`, `szFile`. `DibCreatePalette`: `pdib`.
  `DibReadBitmapInfo`: `fh`. `DibFromBitmap`: `hbm`, `biStyle`, `biBits`,
  `hpal`, `wUsage`. `DibSetUsage`: `pdib`, `hpal`, `wUsage`.
  `DibDraw`: `hdc`, `x`, `y`, `dx`, `dy`, `pdib`, `x0`, `y0`, `dx0`, `dy0`,
  `rop`, `wUsage`. `DibCopy`: `pdib`. `DibCreate`: `bits`, `dx`, `dy`.
  `DibMapToPalette`: `pdib`, `hpal`, `TransLogic`, `ZeroIsTrans`.
  `CreateIdentityPalette` and `CopyPalette`: `hpal`. `DibFree`: `pdib`.
  No resource-ID definition is requested.

Compilation, matching, audits, and tests were not run.
