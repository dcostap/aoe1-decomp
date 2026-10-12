# tpnl_txl.cpp module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\tpnl_txl.cpp`.
- Source: `src/tpnl_txl.cpp`.
- Header: `include/tpnl_txl.h`.
- Flags: `config/flags/gx.rsp`.

## Context gate

- PDB source module: proved by the translation-unit packet as `tpnl_txl.cpp`.
- Source lines and order: proved by the packet. The three normal owners span
  lines 23-34, 40-47, and 53-79 in increasing address and source order.
- Owning class: proved by PDB symbols as `TRIBE_Panel_Text_Line` for all three
  owners.
- Address sequence: proved as `00520D70`, `00520E30`, and `00520ED0`.
- Exact anchors: proved by the constructor, `set_info`, and `draw` symbols,
  their direct calls, the `TPanel` virtual slots, and the field offsets in the
  original assembly.
- Nearby generated code: `00520E00` is the compiler-generated scalar deleting
  destructor. It has no standalone source owner.

## Migration

The three exact owner bodies now live in one source module in PDB order. The
natural header reuses the canonical `TPanel` and owns the
`TRIBE_Panel_Text_Line` declaration. The old wrapper, focused owner fragments,
context macro, and fallback class surfaces are removed.

The source preserves the exact owner bodies and the `/GX` module flags. Candidate
validation must check all three normal owners and the generated deleting
destructor.
