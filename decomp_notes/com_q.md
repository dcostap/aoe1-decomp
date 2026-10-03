# com_q.cpp source module

`src/com_q.cpp` owns the 18 normal PDB functions. `include/com_q.h` owns the
queue records and queue interface.

The module uses the canonical debug-log type. Queue globals stay source-private.
The source has no wrapper, context macro, copied log class, or raw byte cursor.
`QueuedForTurn` uses one typed interior-field pointer. Its record-sized increment
emits the exact loop proven by the executable.

## Status

The registry lists 17 matching owners and one scratch owner in `src/com_q.cpp`.
The scratch owner is `00431D30 GetSpecificItem`. A fresh closure also checks two header-owned functions.
All 19 matching closure owners pass. The scratch target has 138 differences within its 156-byte boundary.
No accepted-drift approval applies to this target.

The direct typed forms changed code generation for several former leaf exact
owners. Do not restore raw pointer arithmetic to promote them.

The earlier shared-worktree trial recovered `00431A40` with typed record iteration.
Its exact result remains part of the current matching closure.

## Header-owner closure

`include/com_q.h` already contains the canonical `MsgQueue` constructor and
destructor bodies. The direct object confirms `00431F60` and `00431F80` as
`MATCH`, `0.0000%`, with correct symbols, boundaries, relocations, and the
destructor delete target. No `.cpp` body or translation-unit owner is added.
