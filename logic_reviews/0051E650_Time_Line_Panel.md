# Logic review: 0051E650 `Time_Line_Panel::Time_Line_Panel`

## Phase transition

The main agent suspended ordinary exact matching after three claims, 22 meaningful
probes, 32 checks, donor work, initializer variants, and canonical base-layout
reconstruction.

The candidate is `src/scratch/0051E650_Time_Line_Panel.cpp`. It now models the
canonical 0xF4-byte `TPanel` and `TEasy_Panel` ownership through 0x478.

Current validation:

- original/rebuilt size: 276/276 bytes;
- instructions: 47/47;
- frame: none / none;
- calls: 1/1;
- strict difference: 125 bytes.

The exact blocker is constructor store scheduling. The same fields receive the
same final values, but VC5 emits a different order for early text-style, color,
and derived-vptr stores. Canonical layout did not alter that basin.

### Semantic questions at entry

1. Verify the base constructor call and derived-vptr lifetime.
2. Verify every field offset, width, value, and final object state.
3. Verify store order where alias, fault, or partial construction can expose it.
4. Verify signed constants, byte fields, null pointers, and floating values.
5. Verify EH, calling convention, cleanup, and constructor-failure behavior.

## Review rounds

No blind review has completed.

## Main-agent adjudication

Pending.

## Integrated changes

The main agent validated the canonical-layout candidate before phase entry.

## Final decision

Pending blind review.
