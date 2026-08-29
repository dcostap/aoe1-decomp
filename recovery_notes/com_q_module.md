# com_q.cpp source module

`src/com_q.cpp` owns the 18 normal PDB functions. `include/com_q.h` owns the
queue records and queue interface.

The module uses the canonical debug-log type. Queue globals stay source-private.
The source has no wrapper, context macro, copied log class, or raw byte cursor.
`QueuedForTurn` uses one typed interior-field pointer. Its record-sized increment
emits the exact loop proven by the executable.

## Status

The direct module reports `MATCH` and `0.0000%` for these registered owners:

- `00431720`, `00431760`, `00431810`, `00431A40`, `00431A70`, `00431BD0`, `00431BE0`.
- `00431D10`, `00431D20`, `00431DD0`, `00431E40`, `00431F50`.

`004319E0`, `00431A80`, `00431B10`, `00431BF0`, and `00431F10`
are scratch. `00431D30` remains accepted drift. Its fresh check has equal size,
frame, saved registers, calls, CFG, and owner symbol. The first 75 bytes match;
the residual starts with one local `pop edi` scheduling move and has a 4.49%
edit cost. It has no relocation or boundary mismatch, so the difference remains
localized.

The direct typed forms changed code generation for several former leaf exact
owners. Do not restore raw pointer arithmetic to promote them.

The shared-worktree trial recovered `00431A40` with a typed pointer to
`ExecTurn`, a record-sized increment, and a count of `HighQueueDepth + 1`.
Focused and complete-module checks report `MATCH` and `0.0000%`. The module now
has 14 matching owners, three scratch owners, and one accepted-drift owner.

## Header-owner closure

`include/com_q.h` already contains the canonical `MsgQueue` constructor and
destructor bodies. The direct object confirms `00431F60` and `00431F80` as
`MATCH`, `0.0000%`, with correct symbols, boundaries, relocations, and the
destructor delete target. No `.cpp` body or translation-unit owner is added.
