# com_q.cpp source module

`src/com_q.cpp` owns the 18 normal PDB functions. `include/com_q.h` owns the
queue records and queue interface.

The module uses the canonical debug-log type. Queue globals stay source-private.
The source has no wrapper, context macro, copied log class, raw record cursor,
or interior-field pointer.

## Status

The direct module reports `MATCH` and `0.0000%` for these registered owners:

- `00431720`, `00431760`, `00431810`, `00431A70`, `00431BD0`, `00431BE0`.
- `00431D10`, `00431D20`, `00431DD0`, `00431E40`, `00431F50`.

`004319E0`, `00431A40`, `00431A80`, `00431B10`, `00431BF0`, and `00431F10`
are scratch. `00431D30` remains accepted drift. Its fresh check has equal size,
frame, saved registers, calls, CFG, and owner symbol. The first 75 bytes match;
the residual starts with one local `pop edi` scheduling move and has a 4.49%
edit cost. It has no relocation or boundary mismatch, so the difference remains
localized.

The direct typed forms changed code generation for several former leaf exact
owners. Do not restore raw pointer arithmetic to promote them.
