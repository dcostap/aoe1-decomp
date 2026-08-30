# Function notes: 0053C920 `unexplore_terrain`

Module notes: `decomp_notes/visible.md`.

## Recovered attempt history

<!-- recovered:0824fe3ac136c8a07076 -->
### `target-session` `build/target_sessions/0053C920_unexplore_terrain.json:1-40`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=385; shape=65.71428571428571: Clean canonical source baseline before new probes; compare current frame and positional metrics.
probe 2 liveness; result=MISMATCH; diff=385; shape=65.71428571428571: Direct this-member ownership probe; tests whether self alias controls the original EBP/local basin. [same emitted code as probe 1]
probe 3 abi; result=MISMATCH; diff=385; shape=65.71428571428571: Use same-TU C++ linkage spelling for log_map_call, matching exact visible.cpp donors.
probe 4 liveness; result=MISMATCH; diff=380; shape=66.42857142857143: Diagnostic volatile player-id local probe; tests whether an observed stack home can recover frame and hash load order.
probe 5 liveness; result=MISMATCH; diff=385; shape=65.71428571428571: Function-scope cursor declarations probe; tests declaration scope and original three-local frame topology. [same emitted code as probe 3]
probe 6 liveness; result=MISMATCH; diff=385; shape=65.71428571428571: Lift LOS cursor to function scope; tests whether its lifetime selects original square-parameter home for offset traversal. [same emitted code as probe 5]
probe 7 abi; result=MISMATCH; diff=385; shape=65.71428571428571: Reference self alias probe; tests whether canonical this-reference lowering recovers the original saved-this local. [same emitted code as probe 6]
probe 8 context; result=MISMATCH; diff=385; shape=65.71428571428571: Sized unified-map table declaration probe; tests reviewed visible.cpp array context. [same emitted code as probe 7]
probe 9 liveness; result=MISMATCH; diff=385; shape=65.71428571428571: Reorder player-id and tile declarations to match original plNum/tile stack order. [same emitted code as probe 8]
probe 10 context; result=MISMATCH; diff=385; shape=65.71428571428571: Add period string.h include context probe; tests same-TU standard-header basin without behavior changes. [same emitted code as probe 2]
probe 11 layout; result=MISMATCH; diff=385; shape=65.71428571428571: Diagnostic square-home reference alias probe; binary proves LOS pointer reuse in square parameter home, but source plausibility remains open. [same emitted code as probe 10]
probe 12 flags; result=MISMATCH; diff=320; shape=74.65753424657534: Diagnostic local /Oy- pragma with natural typed source; prior log identified this as a flag-only frame basin.
probe 13 flags; result=MISMATCH; diff=320; shape=74.65753424657534: Diagnostic /Oy- plus original plNum-before-tile declaration order; tests whether natural local order recovers 0xC frame and register colors. [same emitted code as probe 12]
probe 14 flags; result=MISMATCH; diff=320; shape=74.65753424657534: Diagnostic /Oy- direct-this probe; tests whether the original EBX self register comes from direct member ownership. [same emitted code as probe 13]
probe 15 control-flow; result=MISMATCH; diff=320; shape=74.65753424657534: Diagnostic positive suppression early-return form under /Oy-; tests source guard polarity against original exit edge. [same emitted code as probe 14]
probe 16 liveness; result=MISMATCH; diff=320; shape=74.65753424657534: Named x-coordinate local probe under /Oy-; tests whether coordinate liveness selects original EDI argument color. [same emitted code as probe 15]
probe 17 liveness; result=MISMATCH; diff=320; shape=74.65753424657534: Restore canonical self-first declaration order with x local under /Oy-; tests local ordering and register colors. [same emitted code as probe 16]
probe 20 baseline; result=MISMATCH; diff=385; shape=65.71428571428571: Fresh claim baseline: clean natural typed terrain traversal before new probes. [same emitted code as probe 19]
probe 21 abi; result=MISMATCH; diff=385; shape=65.71428571428571: Restore proven C++ log_map_call linkage from visible.cpp exact donors; tests direct symbol identity without changing behavior. [same emitted code as probe 9]
probe 22 liveness; result=MISMATCH; diff=385; shape=65.71428571428571: Natural source order follows visible.cpp bands: load input checksum before player id before hash. [same emitted code as probe 21]
probe 23 context; result=MISMATCH; diff=385; shape=65.71428571428571: Use reviewed 256-row unified_map_offsets declaration from exact visible.cpp donors; confirms typed table extent without codegen scaffolding. [same emitted code as probe 22]
probe 24 abi; result=MISMATCH; diff=385; shape=65.71428571428571: Direct this-member ownership probe; tests whether canonical C++ member expressions recover original EBX self lifetime without an alias. [same emitted code as probe 23]
probe 25 control-flow; result=MISMATCH; diff=380; shape=63.12056737588652: Use natural negative-bound rejection with continue, matching original JL/JGE edges and shared LOS-row advance.
probe 27 context; result=MISMATCH; diff=385; shape=65.71428571428571: Restore canonical visible.cpp world/player surfaces from exact explore_terrain_sq donor; tests whether unused period fields select the original EBP frame and register basin. [same emitted code as probe 26]
probe 28 flags; result=MISMATCH; diff=320; shape=74.65753424657534: Diagnostic only: disable frame-pointer omission for the clean typed source; measures whether the oracle frame is a flag basin before source hypotheses.
probe 29 liveness; result=MISMATCH; diff=385; shape=65.71428571428571: Move plNum into the successful suppression guard; tests evidence-band scope against the original local spill without steering. [same emitted code as probe 27]
probe 30 liveness; result=MISMATCH; diff=385; shape=65.71428571428571: Split tile declaration from its zero assignment; tests original delayed local store order with a natural source form. [same emitted code as probe 29]
probe 31 context; result=MISMATCH; diff=385; shape=65.71428571428571: Use the complete canonical RGE_Player/RGE_Game_World surfaces from the paired exact TU donor, including tile lists and curr_player; tests real period context rather than a narrow local stub. [same emitted code as probe 30]
probe 32 abi; result=MISMATCH; diff=385; shape=65.71428571428571: Keep a typed self alias only for the proven map/tile branch; tests whether compiler spill ownership follows the original saved-this lifetime without raw tricks. [same emitted code as probe 31]
probe 33 layout; result=MISMATCH; diff=385; shape=65.71428571428571: Replace the player gap with the binary-grounded canonical RGE_Player member surface through id; tests whether real named fields recover the original frame basin. [same emitted code as probe 32]
probe 35 flags; result=MISMATCH; diff=320; shape=74.65753424657534: Function-local /Oy- on the canonical C++ source tests whether the oracle EBP frame is a source pragma basin rather than register pressure. [same emitted code as probe 28]
probe 36 liveness; result=MISMATCH; diff=320; shape=74.65753424657534: Under the binary-supported /Oy- frame basin, load and name player id before checksum to match the oracle's early [player+4A] load and [ebp-8] local evidence. [same emitted code as probe 35]
probe 37 liveness; result=MISMATCH; diff=320; shape=74.65753424657534: Under /Oy-, declare and initialize plNum at the first successful-guard use; tests declaration-site materialization for the oracle's [ebp-8] player-id home. [same emitted code as probe 36]
probe 38 liveness; result=MISMATCH; diff=320; shape=74.65753424657534: Under /Oy-, use the decompiler-supported separate unsigned checksum accumulator rather than mutating p6; tests whether accumulator liveness creates the oracle p6-home and plNum spill topology. [same emitted code as probe 37]
probe 39 liveness; result=MISMATCH; diff=315; shape=76.92307692307692: Diagnostic only: volatile plNum tests whether the proven [ebp-8] spill alone can recover the oracle frame; not a retention candidate without a matching memory-effect fact.
probe 40 liveness; result=MISMATCH; diff=315; shape=76.92307692307692: Diagnostic only: keep function-scope plNum while copying a volatile player-id spill; tests whether longer local scope prevents parameter-home reuse and exposes the oracle three-local frame. [same emitted code as probe 39]
probe 42 control-flow; result=MISMATCH; diff=342; shape=72.14285714285714: Under /Oy-, reuse the clipped x2 local as the inner countdown instead of a separate count; tests the oracle's direct EDX countdown and removes the current count-home store.
probe 44 liveness; result=MISMATCH; diff=320; shape=74.65753424657534: Under /Oy-, use an unsigned inner count to test whether the observed unsigned countdown selects the oracle's register and home topology. [same emitted code as probe 38]
probe 46 liveness; result=MISMATCH; diff=320; shape=74.65753424657534: Use the decompiler-supported local declaration order plNum before tile under /Oy-; tests whether VC5 stack-slot and entry-register colors follow the original local order. [same emitted code as probe 44]
probe 50 context; result=MISMATCH; diff=385; shape=65.71428571428571: Temporary full visible.cpp group with PDB-ordered exact anchors. Default preserves anchors and emits 384/401 with 385 diff; /Oy- gives 400/401 with 320 diff but invalidates all anchors. [same emitted code as probe 49]
```
<!-- end-recovered:0824fe3ac136c8a07076 -->

<!-- recovered:b04b040ace9765d62fcd -->
### `6d2b027754e4` `src/scratch/0053C920_unexplore_terrain.cpp:1-54`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0053C920 RGE_Visible_Map::unexplore_terrain
// Source: visible.cpp lines 665-767
// Attempt log:
// baseline candidate: canonical visible-map/world/player/map ownership and natural
// LOS-table traversal paired with unexplore_terrain_sq.
// /Oy- moved the candidate into the correct EBP basin and to 384 bytes; absolute
// binary-proven LOS table bases improved relocation/edit alignment, while canonical
// polymorphic map/player surfaces were codegen-neutral.
// Player-id ordering, checksum naming, and LOS skip/control-flow variants were
// nonproductive.  The remaining gap is the original three-local frame and its
// parameter-home reuse; no call or field ownership mismatch is indicated.
// Typed LOSTBL records, sized unified-map rows, and full canonical RGE_Tile/
// RGE_Map surfaces emitted identically to the clean source. A typed player owner
// local and a center-y copy likewise produced no codegen movement. The original
// EBP frame and reuse of the square/p6 homes remain an ABI/codegen-context blocker;
// diagnostic forms were restored rather than retained as scaffolding.
// Follow-up session: swapping checksum/player-id assignment order, retaining a
// self alias, splitting a checksum temporary, and lifting cursor locals were
// codegen-duplicates under default /O2 /Oy. Narrow volatile player-id/tile
// diagnostics moved emitted code but did not recover the EBP frame and were
// rolled back. A temporary /Oy- response file improved the frame basin to 394
// bytes/320 strict diff, but still had an 8-byte frame and remained a flag-only
// diagnostic; it was removed. The clean typed source is restored below.
// Additional pass: direct-this and reference-self spellings, C++ versus C
// linkage for log_map_call, a sized unified-map declaration, string.h context,
// function-scope cursor declarations, named radius/x locals, and guard polarity
// were either codegen duplicates or flag-only diagnostics. An ambient declaration
// sweep of 256 samples was also one codegen basin. The /Oy- basin remained
// 394 bytes with an 8-byte frame, versus the oracle's 401 bytes and 0xC frame.
// Restore the default canonical source and seek original TU/flag evidence for
// the saved-this, player-id, and parameter-home topology.
// Final source keeps the symbol-backed LOSTBL* declarations and full typed map/tile
// records even though VC5 emitted the same bytes; the prior validation metrics remain
// authoritative for this canonical-source correction.
// Fresh pass: restore the decorated C++ log_map_call symbol and the reviewed
// 256-row unified-map declaration. Direct this expressions and checksum load order
// remain codegen duplicates. A natural negative-bound continue reached 388 bytes
// and a 380-byte diff, but worsened CFG shape, so it was rolled back. The clean
// typed traversal remains 376 bytes with a 385-byte strict diff. The saved-this,
// plNum, and parameter-home basin still needs original TU evidence.
// Revisit: the paired explore_terrain_sq type surface, the complete player field
// surface, guarded plNum scope, split tile initialization, and a branch-local
// self alias all remained in the 376-byte default basin. The original /Oy- probe
// remained 394 bytes with an 8-byte frame and a 320-byte diff. These are diagnostic
// basins only. No policy-valid exact source was found in this pass.
// Current claim: function-local /Oy- remained the best shape diagnostic at 394
// bytes, a 0x08 frame, and a 320-byte diff. Reordered plNum/tile declarations,
// player-id initialization, and a separate checksum accumulator were duplicates.
// A volatile player-id spill reached 398 bytes and a 315-byte diff, but it did
// not create the oracle 0x0C frame, so it is not retained. Reusing clipped x2 as
// the inner countdown worsened the structure to 384 bytes and 342 bytes. The
// unsigned-count form duplicated the /Oy- basin. The pinned default typed source
// is restored; final validation is 376 bytes, 385-byte strict diff, and no
// policy-valid exact source.
```
<!-- end-recovered:b04b040ace9765d62fcd -->

<!-- recovered:98ad55b827700b0334fa -->
### `6d2b027754e4` `src/scratch/0053C920_unexplore_terrain.cpp:132-133`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// Main-agent audit replaced raw absolute LOS/unified-map globals and retained
// canonical visible-map ownership with natural row traversal.
```
<!-- end-recovered:98ad55b827700b0334fa -->
