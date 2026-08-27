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

The direct module check has seven exact owners. They report `MATCH` and
`0.0000%`: `00479270`, `004792A0`, `004793C0`, `00479540`, `00479A10`,
`00479A80`, and `0047A190`.

The other five owners are scratch. Their current module results are:

| VA | Name | Original | Rebuilt | Positional diff |
| --- | --- | ---: | ---: | ---: |
| `00478F40` | `TMessagePanel` | 235 | 191 | 184 |
| `00479050` | `~TMessagePanel` | 139 | 83 | 130 |
| `004790E0` | `set_rect` | 389 | 333 | 369 |
| `00479590` | `draw` | 1147 | 1146 | 633 |
| `00479AE0` | `render_to_image_buffer` | 1662 | 1671 | 1305 |

The current check reports nine non-padding bytes after the original boundary
for `00479AE0`.

The constructor no longer writes a vtable through a raw address. The executable
does contain a late derived-vtable store at `00479000`. The natural constructor
emits its compiler vtable store earlier and remains nonexact under the default
module flags. No unsupported ABI machinery is retained.

The source module metadata records all 12 normal owners. The generated deleting
destructor remains outside that metadata.
