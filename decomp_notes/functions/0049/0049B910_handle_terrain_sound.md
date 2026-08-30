# Function notes: 0049B910 `handle_terrain_sound`

## Recovered attempt history

<!-- recovered:fdee6c3a33dc69935238 -->
### `58e45d7ca2b6` `src/scratch/0049B910_handle_terrain_sound.cpp:1-42`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0049B910 handle_terrain_sound (468B)
// scr_game.cpp:4621-4711
//
// Natural reconstruction of the terrain-sound throttle, terrain priority
// scan, and DirectSound stream restart.  The map and terrain-set declarations
// retain the proven 0x198 terrain stride and field ownership.
//
// Attempt log:
// - baseline natural typed terrain-set scan: 233 differing bytes, rebuilt
//   size 462 versus the 468-byte oracle; all 12 calls were ordered correctly.
// - moved the world load ahead of the last-time store and corrected the
//   terrain-playing 1000ms path to the oracle's direct epilogue return;
//   size became exact and CFG coverage improved.
// - A field-centered cursor diagnostic reached 202 differing bytes, but its
//   negative-offset field accesses were not retained. Restoring direct typed
//   terrain_types[index] ownership unexpectedly improved the canonical source
//   to exact size/CFG/calls and only eight register-encoding bytes of drift.
// - byte priority, register hints, direct loop-bound, and for-loop spelling
//   probes were regressive or emitted duplicates. The remaining gap is the
//   best-index/count register coloring in the typed scan.
// - swapped priority/index declarations and routed the interval throttle to
//   the shared no-log return; diff improved from 8 to 7 bytes.
// - moved the named map/count loads before the result locals; output was
//   unchanged. Remaining drift is seven register-encoding bytes in the scan.
// - declaring best_index before terrain_count was a natural ownership-order
//   probe; output was unchanged, so the clean declaration order remains.
// - named the typed terrain sound before get_file_name() as a natural dispatch
//   probe; output was unchanged, so the seven scan register bytes remain.
// - declaration/init and natural for/while variants all collapsed to the same
//   seven-byte group; register/const hints and a selected-terrain pointer also
//   had no emitted effect.
// - signed no-selection guard variants changed the branch or layout, but did
//   not recover the oracle; restored the clean == -1 guard after the budget.
// - nested, direct-member, and early-continue eligibility forms all emitted
//   the same seven-byte group; the typed pointer/combined guard remains clean.
// - widening the selected index changed the map-load topology and regressed to
//   66 bytes; a scoped loop index and reversed assignments also did not swap
//   the count/index colors, so the clean short locals remain authoritative.
// - unsigned best-drawn changed the signed branch to jbe and regressed to eight
//   bytes; split sentinel initialization regressed to eleven bytes.
// - declaring the result locals before the map load changed scheduling but
//   still emitted the same seven-byte group; the remaining gap is EBX/EBP color.
```
<!-- end-recovered:fdee6c3a33dc69935238 -->
