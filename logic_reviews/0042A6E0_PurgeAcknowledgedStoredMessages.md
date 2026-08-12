# Logic review: 0042A6E0 `TCommunications_Handler::PurgeAcknowledgedStoredMessages`

## Phase transition

The main agent suspended ordinary exact matching after five claims, 39 meaningful
probes, 47 checks, donor work, focused pointer/index variants, and final source
normalization.

The candidate is `src/scratch/0042A6E0_PurgeAcknowledgedStoredMessages.cpp`.
It uses the proven 0x38-byte `RESENDER` layout and named fields `TimeSent`,
`Serial`, `ResendMsg`, `Length`, and `DestMap`.

Current validation:

- original/rebuilt size: 283/255 bytes;
- frame: `0xC` / `0xC`;
- calls: 3/3 in exact order;
- branches: 10/10;
- strict difference: 266 bytes;
- instruction shape: 80.90%.

The exact blocker is VC5 induction and stack-home topology. Diagnostic flat-cursor
source reached a small diff but was compiler steering. The retained source uses
ordinary typed indexing.

### Semantic questions at entry

1. Verify slot bounds, player bounds, and all loop termination behavior.
2. Verify human-player filtering and `DestMap` tests.
3. Verify release conditions, logging arguments, delete order, and field clears.
4. Verify the final waiting-count scan, limits, and returned value.
5. Verify widths, layout, calling conventions, malformed pointers, and partial effects.

## Review rounds

No blind review has completed.

## Main-agent adjudication

Pending.

## Integrated changes

The main agent validated the normalized candidate before phase entry.

## Final decision

Pending blind review.
