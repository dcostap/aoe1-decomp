# Logic review: 0047F320 `RESFILE_load`

## Phase transition

The main agent suspended ordinary exact matching after four claims and 25 meaningful probes.

The candidate is `src/scratch/0047F320_RESFILE_load.cpp`.

Current validation:

- original and rebuilt size: 346 bytes;
- all eight calls align in exact order;
- frame and control flow align;
- strict difference: one byte at `0047F3CA`;
- original and rebuilt code differ only in commutative LEA base/index encoding.

Pointer, integer, union, cast, operand-order, and compound forms reproduced the same result.
The retained source uses the natural mapped pointer plus byte offset expression.

### Semantic questions at entry

1. Verify output initialization and resource-location output ownership.
2. Verify missing-resource diagnostics and return paths.
3. Verify mapped-data address addition, including 32-bit wrap and malformed offsets.
4. Verify allocation, seek, read, error paths, and intentional allocation retention after read failure.
5. Verify call arguments, return values, fault order, and all memory effects.

## Review rounds

No review has started.
