# Pnl_msg.cpp module merge

- PDB source: `C:\msdev\work\age1_x1\Pnl_msg.cpp`.
- Source: `src/Pnl_msg.cpp`.
- Header: `include/pnl_msg.h`.
- Flags: `config/flags/default.rsp`.

## Transition

This module has 12 normal owners in PDB source order. The owner range is
00478F40 through 0047A1C9. The scalar deleting destructor at 00479030 is a
compiler-generated owner and is not a source function.

The source keeps the original class and field ownership. The module header now
owns the declarations for `TPanel`, `TMessagePanel`, `TDrawArea`, and `TShape`.
The merged source removes the wrapper, bank fragments, fallback declarations,
context guards, and `.cpp` includes.

The source keeps the prior natural bodies. It does not add byte-tuning forms.
The complete module build can differ from the old isolated owner results because
all owners now share one compiler context.

## Check state

The old wrapper had seven registered exact owners. The constructor had 16
positional differences, `draw` had 633, and `render_to_image_buffer` had 1319.
The merged source keeps those reviewed statuses: constructor is accepted drift,
`draw` and `render_to_image_buffer` are scratch, and the other nine normal
owners are matching.

The source module metadata records each normal owner. The generated deleting
destructor remains outside that metadata.
