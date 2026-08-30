# flics.cpp module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\flics.cpp`.
- Source: `src/flics.cpp`.
- Header: `include/flics.h`.
- Flags: `config/flags/default.rsp`.

## Source order

The module owns these normal functions in PDB order:

`00449B30`, `00449BE0`, `00449C40`, `00449C50`, `00449DF0`, `00449E00`,
`00449E10`, `00449E20`, `00449E80`, `00449E90`, `0044A090`, `0044A100`,
`0044A2A0`, `0044A390`, and `0044A3E0`.

`0044A05D` is a reviewed padding-only boundary. It has no compiler-facing owner.

## Migration

The module now has one source file and one FLIC header. The source keeps the
PDB order and the reviewed class, record, and draw-area layouts. It no longer
uses a wrapper, a source-bank include, a fallback class declaration, or a
recovery context macro.

The old per-function files held the durable recovery history. This note keeps
the important results from that work. Exact byte results from isolated source
banks are not claims about the merged source.

## Reviewed source facts

- `FlicHead` is 0x84 bytes. `FrameHead` is 0x10 bytes. `RGE_Flic_Player` is
  0xBC bytes.
- The first constructor copies the complete FLIC header before it reads width.
  A successful open does not initialize `flic_handle`; this shipped behavior
  is retained.
- `start` handles AF11 and AF12 files. AF11 uses the 1000/70 speed conversion
  and starts at the 0x84-byte header. AF12 adds the file base to `oframe1`.
- `draw` stores x1, drawarea, y1, x2, and y2 in that order. It dispatches the
  six frame chunk types to the private helpers and frees file-backed frames.
- Palette type 4 keeps a typed two-byte packet header. Type 0x0B advances the
  palette cursor before its three stores. This preserves packed-stream order
  and store/fault order.
- `delta_flc` keeps the ushort stream cursor, signed packet size, and separate
  scan and packet loops. Its current source is behavior-correct but nonexact.
- `delta_fli` keeps separate outer and line counters. The source uses the
  packed signed byte counts from the original stream.
- `byte_run` advances past one row header before its opcode loop. Its negative
  arm uses a signed-byte run count.

## Prior matching state

The grouped packet recorded 13 matching-bank owners and two scratch owners.
The two scratch owners were `00449C50 palette` and `0044A100 delta_flc`.
The migration checkpoint had 13 other exact functions.

Before migration, the registered exact set had 12 owners. `byte_run` was an
exact isolated owner but was not registered in the old translation-unit entry.
The merged source is not byte-tuned during this migration. The temporary source
shape may change old exact results.

`palette` reached a 407-byte behavior-correct source. The merged-source check
reported 187 differing bytes after the final asymmetric palette alias. The
unresolved code-generation issue was the packed chunk and packet register
allocation.

`delta_flc` reached a 397-byte natural source in the final clean pass. Its best
reported natural result had 367 differing bytes. The unresolved issue was the
original EBP stream cursor, EDI packet value, and early prologue allocation.

Earlier matching work also recorded these exact source lessons:

- The first constructor needs a typed 0x84-byte aggregate assignment for the
  original header copy.
- The second constructor needs the full header and the draw-area fields before
  the `flic_width` member.
- `draw` needs the early y1 store and the typed frame header.
- `delta_fli` needs the pre-increment packet count read to retain two separate
  header increments.
- `byte_run` needs a signed-byte run local and the row-header increment inside
  the outer loop.

No new exact claim is made by this source-shape migration.
