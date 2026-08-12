# Logic review: 0052A510 `TRIBE_Game::disconnect_multiplayer_game`

## Phase transition

The main agent suspended ordinary exact matching after seven claims, 28
meaningful probes, 46 checks, a 36-case focused variant lab, exact donor work,
and repeated convergence on one register-color basin. The candidate remains
`src/scratch/0052A510_disconnect_multiplayer_game.cpp`.

Current validated checker state:

- original/rebuilt size: 279/279 bytes;
- frame: none / none;
- saved registers: `EBX`, `EBP`, `ESI`, `EDI` in both;
- calls: 14/14 in exact order with matching targets;
- instructions: 82/82;
- conditional branches: 11/11;
- returns: 2/2;
- instruction shape and exact-block coverage: 100%;
- strict difference: 16 register-encoding bytes;
- edit/resync cost: 16 bytes.

The executable keeps `this` in `EDI` and elapsed time in `ESI`. VC5 keeps
`this` in `ESI` and elapsed time in `EDI`. Matching work tested declaration
order, direct members, base and derived class surfaces, field widths, control
flow, timestamp expressions, translation-unit context, and focused variants.
No natural source changed this register assignment.

The retained source uses named communications, game-mode, and world fields,
typed calls, unsigned timestamp arithmetic, and natural wait loops. It contains
no fake volatility, manual vtable calls, raw offsets, or codegen-only aliases.

### Semantic questions at entry

1. Verify multiplayer and game-mode gates, including all no-op paths.
2. Verify every communications call, argument, order, and repetition.
3. Verify the waiting-message predicates and signed result handling.
4. Verify world null/status exits and the byte status width.
5. Verify unsigned timer subtraction, wraparound, 500-ms polling, and 15-second limit.
6. Verify shared `GameOver` and `UnlinkToLevel` tails for every exit.
7. Verify field offsets, malformed-pointer fault order, and partial effects.
8. Verify calling conventions, caller-saved register relevance, returns, and cleanup.

## Review rounds

Pending.

## Main-agent adjudication

Pending.

## Integrated changes

The main agent validated the unchanged normalized source at 279 bytes and 16
strict differing bytes before phase entry.

## Final decision

Pending.
