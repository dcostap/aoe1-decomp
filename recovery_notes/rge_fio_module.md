# rge_fio.cpp source module

- PDB source: `C:\\msdev\\work\\age1_x1\\rge_fio.cpp`.
- Source: `src/rge_fio.cpp`.
- Header: `include/rge_fio.h`.
- Flags: `config/flags/default.rsp`.

## Context evidence

The PDB assigns ten normal owners to `rge_fio.cpp`, lines 49-360. Their
addresses and source bands increase in this order:
`0047FD30`, `0047FD90`, `0047FE20`, `0047FEB0`, `0047FF30`, `00480000`,
`00480040`, `00480080`, `00480290`, and `004802C0`.

The original assembly proves the CRT call surface used by this module:
source spellings `open`, `lseek`, `tell`, `read`, `write`, `close`, `calloc`,
and `free`, plus the compression helpers. Ghidra displays the CRT entry points
`__open` and `__tell` for the `open` and `tell` source calls. The original
symbol at `0086B284` is the C++ global `rge_write_error`; the owner source uses
that name.

## Consolidation

The ten prior matching fragments now have one compiler-facing owner in
`src/rge_fio.cpp`. The old wrapper and fragment owners are removed. The public
C++ function surface and `rge_write_error` declaration live in
`include/rge_fio.h`. No shared cross-shard header changed.

The source keeps the prior function order, control flow, global storage names,
and compression call order. It does not add a wrapper, duplicate context, or
synthetic owner.

## Validation

This structural consolidation was not compiled, as required by the assigned
lane. The grouped translation-unit check remains pending:

```text
python tools/validate_translation_units.py
```

The main agent should run the grouped check before accepting exact ownership.
