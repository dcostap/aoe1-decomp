# teffects.cpp source-module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\teffects.cpp`.
- Held source wrapper: `src/teffects_tu.cpp`.
- Held owners remain in PDB order: `0050D460`, `0050D4B0`, `0050D4D0`, and `0050D550`.
- The original addresses and direct targets are recorded in the four matching owner files.

## Canonical dependency review

- `include/effects.h` is now the canonical non-context owner for
  `RGE_Effect_Command`, `RGE_Effect`, and `RGE_Effects`.
- `include/tplayer.h` is the canonical `TRIBE_Player` owner. It declares
  `tech_abling(long, unsigned char)` and includes `include/player.h`.
- This module does not copy an effects record, player, world, or base-game
  layout.
- `include/effects_context.h` and `include/teffects_context.h` remain context
  headers. This module must not include either header.

## Derived ABI checkpoint

The PDB class inventory proves `TRIBE_Effects` derives from `RGE_Effects` and
has no fields of its own:

- `inventory/classes/dumps/TRIBE_Effects.txt` reports `LayoutBase` and
  `DonorBase` as `RGE_Effects`, with `FieldCount: 0` and size `0x0C`.
- `inventory/types/dumps/TRIBE_Effects.txt` reports `Base: RGE_Effects`, size
  `0x0C`, and an empty class body.
- `inventory/classes/dumps/RGE_Effects.txt` reports the three virtual slots at
  `0x00`, `0x04`, and `0x08`.
- `inventory/types/dumps/RGE_Effects.txt` reports the base size as `0x0C`.

The PDB source map assigns the derived owners to `teffects.cpp` in this order:
`0050D460` (lines 22-23), `0050D4B0` (29-30), `0050D4D0` (36-77), and
`0050D550` (83-114). The first constructor calls `RGE_Effects` at `0050D468`;
the second calls it at `0050D4B8`. Each then writes the `TRIBE_Effects`
vftable at object offset `0x00`. No constructor writes any offset after the
base call except that vtable pointer.

The legal owner header is therefore a thin derived declaration that includes
`include/effects.h`, declares no data fields, and checks
`sizeof(TRIBE_Effects) == 0x0C`. It must not include an effects context header
or copy the base effect records.

## Minimal VC5 probe

Probe source: `build/header_probes/teffects_size.cpp`.

Command:

`CL.EXE @config/flags/default.rsp /Iinclude /Fobuild/header_probes/teffects_size.obj build/header_probes/teffects_size.cpp`

The probe checked both `sizeof(RGE_Effects) == 0x0C` and
`sizeof(TRIBE_Effects) == 0x0C`. VC5 returned code `0`.
The object SHA-256 is
`f76aadf8d05d57419ded7b0457973ad74701d15fd840b0106722f384e74a066e`.
