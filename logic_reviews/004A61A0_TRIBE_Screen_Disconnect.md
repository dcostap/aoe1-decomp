# Logic review: 004A61A0 `TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect`

## Phase transition

The main agent suspended ordinary exact matching after nine claims, 54 meaningful
probes, same-TU donor work, EH and flag experiments, and final source
normalization.

The candidate is `src/scratch/004A61A0_TRIBE_Screen_Disconnect.cpp`.

Current validation:

- original/rebuilt size: 200/219 bytes;
- calls: 4/4 in exact order;
- saved registers: `ESI`, `EDI` in both;
- strict difference: 91 bytes;
- first mismatch: setup-failure tail at `004A6211`.

The exact blocker is compiler EH-tail sharing. The executable routes setup
failure to one shared epilogue. VC5 emits a separate cleanup and return tail for
the natural constructor. Exact same-TU context did not change this basin.

The retained source uses named fields, ordinary construction and setup control
flow, typed calls, the proven layout, and `/GX`. It contains no unsupported
compiler steering.

### Semantic questions at entry

1. Verify base construction, derived vptr lifetime, and every field store.
2. Verify setup arguments, return test, and failure assignment at `field_D8`.
3. Verify ideal-size and text-control calls, arguments, and conditional paths.
4. Verify constructor return value, EH registration, cleanup, and partial construction.
5. Verify field offsets, widths, malformed pointers, fault order, and side effects.

## Review rounds

No blind review has completed.

## Main-agent adjudication

Pending.

## Integrated changes

The main agent validated the normalized 219-byte candidate with all four calls in
order before phase entry.

## Final decision

Pending blind review.
