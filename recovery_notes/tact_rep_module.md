# tact_rep.cpp source reunification

## Translation-unit context

- PDB source: `C:\\msdev\\work\\age1_x1\\tact_rep.cpp`.
- The packet contains 12 normal owners in source and address order.
- The owner range is `004D1680` through `004D2020`.
- All owners belong to `TRIBE_Action_Repair`.
- The nearby `004D16F0` vector deleting destructor is compiler-generated.
- The canonical declaration surface is `include/tact_rep.h`.
- The module uses `config/flags/004CD210_TRIBE_Action_Build.rsp`.

## Status

The source owns all 12 normal owners in PDB order. Eleven owners remain
matching. `004D1BB0` (`TRIBE_Action_Repair::update`) remains scratch.

The natural update source keeps the original state routing, ordered calls,
size, frame, and 29-call surface. Its remaining two-byte drift is the state-4
action-list vtable load: the executable loads the vtable address through EDX,
while the rebuilt source uses EAX. No natural source change recovered that
register choice. Do not promote this owner without a fresh exact check.

The source has no inline assembly, byte filler, codegen-only body, or forced
register hint. The prior per-function comments and the update attempt log are
condensed into the source and this note.

## Ownership and cleanup

`src/tact_rep.cpp` is the sole compiler-facing source owner. The old direct
wrapper, all 11 matching fragments, and the update scratch fragment are
removed. The old context header is now the module-owned `include/tact_rep.h`.
The source has no `.cpp` includes, recovery context macros, fallback class
declarations, or duplicate owner declarations.
