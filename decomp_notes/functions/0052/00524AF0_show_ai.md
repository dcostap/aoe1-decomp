# Function notes: 00524AF0 `show_ai`

Module notes: `decomp_notes/tribegam_module.md`.

## Recovered attempt history

<!-- recovered:d2e9e6877945c129985b -->
### `target-session` `build/target_sessions/00524AF0_show_ai.json:1-11`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=610; shape=93.65853658536585: Baseline natural typed player-slot and panel reconstruction before further review.
probe 2 abi; result=MISMATCH; diff=610; shape=93.65853658536585: Replaced local PlayerSlot/TribeGame names with evidence-backed RGE_Game_World/TRIBE_Game world and game_screen ownership. [same emitted code as probe 1]
probe 3 layout; result=MISMATCH; diff=601; shape=92.6829268292683: Tested a typed contiguous row cursor rooted at s[2], matching the observed EBP row stride.
probe 4 layout; result=MISMATCH; diff=606; shape=93.17073170731707: Moved the typed row cursor into the computer branch after formatting, matching the observed post-format cursor setup.
probe 5 liveness; result=MISMATCH; diff=606; shape=93.17073170731707: Tested an explicit typed TRIBE_Game alias across the display flow with the row cursor. [same emitted code as probe 4]
probe 6 layout; result=MISMATCH; diff=593; shape=91.9047619047619: Tested a typed char-buffer cursor at s[1] with 256-byte row stepping.
probe 7 liveness; result=MISMATCH; diff=30; shape=97.54901960784314: Tested a typed row cursor plus branch-local output pointer, so destination address exists before null fallback.
probe 8 context; result=MISMATCH; diff=30; shape=97.54901960784314: Tested direct period string literals instead of local static aliases for format and empty AI text relocations.
probe 9 control-flow; result=MISMATCH; diff=2; shape=99.01960784313725: Matched the observed source-value fallback shape with a default empty source plus non-null replacement, and reordered loop initialization.
probe 10 control-flow; result=MATCH; diff=0; shape=100.0: Changed the bounded loop to i <= 6 to match the original cmp-6/jle encoding.
probe 11 liveness; result=MATCH; diff=0; shape=100.0: Removed the explicit game=this alias after exact recovery to test the simpler direct this member form. [same emitted code as probe 10]
```
<!-- end-recovered:d2e9e6877945c129985b -->

<!-- recovered:f313c29aac343525bda8 -->
### `89e7bfe16c04` `src/scratch/00524AF0_show_ai.cpp:1-33`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00524AF0 TribeGame::show_ai
// Source: tribegam.cpp lines 2100-2137
// Attempt log:
// 1: natural reconstruction from packet: gather six player AI strings and pass them to UI display; after adding missing computerPlayer declaration compiled too small (608 vs 636).
// 2: tried /Oi for inline strcpy/sprintf-style sequence; no size change, flag removed.
// 3: unrolled computer-player name copy loop; size now matches 636 but broad prologue/register and block layout mismatch.
// 4: tried /O1 /Oy flag probe; object shrank to 545 and failed configured size, flag removed.
// 5: reviewed stack layout: original has six 0x100 buffers plus 4-byte home (0x604); current source matches total after unroll.
// 6: reviewed computer-player branch: original uses a loop with EBX=2..6 and EBP walking output buffers; unrolled source matches size but loses loop topology.
// 7: loop form source originally was closer semantically but too small; unroll fixes size at cost of topology.
// 8: reviewed non-computer branch: original performs one provider name copy, sprintf for player id, then four EMPTY_AI copies; modeled.
// 9: final display call argument order modeled for both computer/non-computer paths, but rebuilt has different push/order schedule.
// 10: left in scratch: remaining drift is broad and not accepted_drift-safe; exact source likely needs original loop/string-copy shape with inline rep movs/scas and correct this register EBX.
// 11: replaced the five unrolled computer-name calls with one natural indexed loop; call set/CFG then aligned and the frame reached 0x604.
// 12: changed the provider declaration to RGE_Player so computerPlayer uses the proven direct method symbol; emitted bytes were unchanged.
// 13: removed cached player/provider locals and used direct member expressions; this recovered the original reload topology and 77.94% exact-block coverage.
// 14: an explicit game=this alias was a codegen duplicate and was rolled back.
// 15: restored the virtual/base layout (player slot at +0x3F4, panel at +0xC24); the layout is canonical but did not change this register basin.
// 16: function-scope loop-index and inherited-base variants were codegen duplicates.
// 17: a pointer-cursor spelling moved four bytes closer but was less plausible than the direct indexed array loop, so it was rolled back.
// 18: paused after the bounded pass: current natural source has 9/9 ordered calls, 0x604 frame, 640 emitted bytes versus 636, and broad register/prologue drift.
// 19: renamed the panel declaration to TRIBE_Screen_Game; relocation identity is now period-canonical with no emitted-byte change.
// 20: tested the packet's cmp-6/jle loop spelling as i <= 6; only resync cost improved, so restored i < 7.
// 21: this claim tested a natural contiguous destination cursor at s[1]; it reached 636 bytes and diff 595, but kept this in EBP and was rolled back.
// 22: register-qualified cursor rooted at s[2] did not change VC5 allocation; rolled back.
// 23: typed array cursor with destination[-1] was emitted identically to the prior cursor basin.
// 24: explicit game=this alias with the typed cursor was a codegen duplicate.
// 25: register-qualified typed cursor was a duplicate; VC5 still kept this in EBP.
// 26: grouping i and the typed cursor in the for initializer returned the clean 640-byte basin.
// 27: pairing the typed cursor with i <= 6 changed only resync cost, not structural bytes.
// 28: mutable char* name ABI matched the binary pointer surface but emitted no new code.
// 29: Restored the real string literals. The former absolute addresses were
//     diagnostic data plumbing, not valid source ownership.
```
<!-- end-recovered:f313c29aac343525bda8 -->
