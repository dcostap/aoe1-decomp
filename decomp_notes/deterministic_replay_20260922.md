# Deterministic replay parity for a human session

## Result

On 2026-09-22 a replay reproduced a human recording byte for byte.
The recording covers random-map gameplay, one unit move, and the Save Game Screen.
It holds 9,649 inputs, 1,472 world updates, and 35.5 seconds of game time.

Recording capture: `build/runtime/original-20260921T235216857979Z-d38862a0ec6f`.
Replay capture: `build/runtime/original-20260921T235508224490Z-3277f9467f13`.
Recording file: `build/runtime/human-20260921T235216850473Z-1fd09997e1ce/recording.json`.

Both runs wrote `savegame/test.gmx` with SHA-256:

`933b5992aee8f38c92c9de3f446b18cf7fc4e3e51a7399cb2cb57d7748d4614b`

The RNG traces also match. Both hold 981,899 records with SHA-256:

`903858feefdba230318c7b55361d4301f5d2ab7a4e06d5e543edcf1e54f880c9`

World state matches: world time 21,140, object count 2,858, camera at 68 and 107.
Input order and update count match. The allocation fill reports the same
34,764 blocks and 5,506,088 bytes in both runs.

The replay consumed 1,196,834 of 1,197,393 message-pump records.
It consumed 3,592,258 of 3,593,453 clock calls.
The tail sits after the terminal Paint boundary. All inputs and updates
reached the game before the stop. This tail is expected.

## Contract

`game.cmd record-original --deterministic-trace` records four streams.
It records RNG calls in `rng.bin`, with call sites and values.
It records the game-thread message pump in `messages.bin`, format
`aoe-message-pump-v7-le`. It records global clock values and per-update
clock, world-time, and input boundaries in `recording.json`.

Replay feeds the recorded `srand` seeds, clock values, and message-pump
results back in recorded order. USER32 still translates and dispatches
each message. The harness posts no synthetic game input outside the stream.

`tools/harness/human_alloc_fill.js` zero-fills the game `operator new`
on both sides. The decomp sources keep the original uninitialized reads.

## Original bug found

`ManagedArray::operator[]` in `include/utmarray.h` reads without a
`numberValue` check. A read past the count returns uninitialized memory.
The callsite `TribeTacticalAIModule::setupSoldierGroups` reads
`soldiers[0]` while the list is empty at game start. The stale value
works as a game-object id. It selects one terrain class, so the lazy
zone-map cache grows differently between runs. The save then differs.

Probe evidence: `build/runtime/original-20260921T232513704940Z-f30225add2a3`
shows `numberValue: 0`, a null buffer, and ids such as 59840432 at
`fullyExploredZone`. That id is heap garbage. The same call site created
different terrain tables across runs.

Both locations carry `//! @bug` markers. The harness normalizes the
behavior only in deterministic runs.

## Limits

Recordings made before the fill keep their heap garbage. Their saves can
match on world state and RNG but not on garbage-seeded AI bookkeeping.
One such case matched every zone map but kept a 256 byte tail difference.

This result covers runs under the recorded-stream and fill contract.
It does not prove determinism of a stock process without the harness.

The next step is rebuilt-executable replay of this same recording.
