# Function notes: 00483A20 `add_land_module`

Module notes: `decomp_notes/rmm_dbct_module.md`.

## Recovered attempt history

<!-- recovered:802630419ed1e0a24c31 -->
### `target-session` `build/target_sessions/00483A20_add_land_module.json:1-34`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1561; shape=78.69127516778524: Clean cursor-form baseline: frame/calls exact, 1874 bytes versus 1853, first mismatch entry home, phase-B CFG drift.
probe 2 liveness; result=MISMATCH; diff=1561; shape=78.69127516778524: Added first-declared unused self alias to test whether VC5 allocates saved-this home at target [esp+10]. [same emitted code as probe 1]
probe 4 abi; result=MISMATCH; diff=1561; shape=78.69127516778524: Used a named current_team alias for the map-data owner and map_type to test whether an explicit self receiver recovers the target saved-this home. [same emitted code as probe 2]
probe 6 control-flow; result=MISMATCH; diff=1561; shape=78.69127516778524: Replaced phase-A for loops with guarded do/while forms to test target's explicit zero setup, first-iteration jump, and backedge blocks. [same emitted code as probe 4]
probe 8 control-flow; result=MISMATCH; diff=1555; shape=79.15966386554622: Changed relation grouping to target-like preincrement cursors and do/while, with direct land_num reloads for outer and relation bounds.
probe 9 abi; result=MISMATCH; diff=1555; shape=79.15966386554622: Removed the branch-local seed alias and nested the proven player relation receiver, testing push-before-receiver evaluation order from target assembly. [same emitted code as probe 8]
probe 10 liveness; result=MISMATCH; diff=1587; shape=75.83892617449665: Delayed land_wanted initialization until after relation grouping and used direct land_num in distance and relation phases, matching target's EBX live count and late stack write.
probe 12 liveness; result=MISMATCH; diff=1555; shape=79.15966386554622: Declared self alias before scalar locals and used it for both calc_land_start receivers to test explicit saved-this home ordering. [same emitted code as probe 9]
probe 13 abi; result=MISMATCH; diff=1555; shape=79.15966386554622: Replaced the optimized pointer self alias with a reference receiver for map-data ownership, testing whether reference liveness moves the implicit this home. [same emitted code as probe 12]
probe 14 layout; result=MISMATCH; diff=1783; shape=61.774744027303754: Introduced a typed land-entry cursor for phase A, preserving record ownership while testing target's persistent source cursor and loop preheader.
probe 16 liveness; result=MISMATCH; diff=1555; shape=79.15966386554622: Used a first-declared self pointer at phase-B entry for land count and y cursor, testing whether explicit current-team liveness recovers target home allocation. [same emitted code as probe 13]
probe 17 liveness; result=MISMATCH; diff=1555; shape=79.15966386554622: Narrowed the relation-loop counter from long to int to test target's register counter and compare-width behavior. [same emitted code as probe 16]
probe 18 liveness; result=MISMATCH; diff=1555; shape=78.99159663865547: Changed bubble-sort changed flag to bool, following Ghidra's boolean evidence and testing byte liveness and test lowering.
probe 19 liveness; result=MISMATCH; diff=1833; shape=75.37437603993344: Moved the phase-A record counter declaration to the scalar declaration block to test declaration order and register-home coloring.
probe 21 liveness; result=MISMATCH; diff=1538; shape=78.28282828282828: Rebased relation grouping on zero-based player and team-size cursors with preincrement, testing target's pointer phase and slot coloring.
probe 22 control-flow; result=MISMATCH; diff=1554; shape=80.0: Reversed the equivalent bubble-sort comparison spelling to test target operand order and branch polarity.
probe 23 liveness; result=MISMATCH; diff=1587; shape=76.67785234899328: Combined delayed land_wanted materialization with the target comparison operand order to test the interaction that should keep n in EBX and index1 in EBP.
probe 25 liveness; result=MISMATCH; diff=1554; shape=80.0: Narrowed the transient other-team index to int, matching Ghidra's iVar8 and testing index register pressure in the reassignment loop. [same emitted code as probe 22]
probe 26 liveness; result=MISMATCH; diff=1554; shape=80.0: Narrowed reassignment-loop land indices to int, matching Ghidra's iVar4/iVar9 and testing address-index register pressure. [same emitted code as probe 25]
probe 27 abi; result=MISMATCH; diff=1554; shape=80.0: Nested the relation receiver after all cursor and comparison changes to retest call argument evaluation order in the best basin. [same emitted code as probe 26]
probe 28 liveness; result=MISMATCH; diff=1554; shape=80.0: Swapped index and index1 declaration order to test the target's EBP index1 and EBX land-count register coloring. [same emitted code as probe 27]
probe 29 liveness; result=MISMATCH; diff=1554; shape=80.0: Used an explicit self alias across the phase-B distance, relation, and final coordinate accesses to test full current-team liveness and saved-this home allocation. [same emitted code as probe 28]
probe 32 layout; result=MISMATCH; diff=1554; shape=80.0: Typed local_180 as long* to follow Ghidra's inferred reused team_size cursor, with explicit initial placement cast; tests whether pointer provenance recovers target stack home or cursor lowering. [same emitted code as probe 31]
probe 34 layout; result=MISMATCH; diff=1577; shape=75.45909849749583: Matched Ghidra's declared long ty[8] and player_teams[8], preserving the proven one-based writes that overlap adjacent stack arrays; tests whether target's +0x9c distance base and phase-B topology recover.
probe 36 layout; result=MISMATCH; diff=1576; shape=75.79298831385643: Reduced the array overlap axis to ty[8] only while retaining player_teams[9], testing whether the target's frame and distance base are controlled by ty's one-based extent.
probe 38 liveness; result=MISMATCH; diff=1577; shape=75.45909849749583: Combined exact Ghidra array extents ty[8]/player_teams[8] with a live current_team receiver alias used through phase B, testing whether the target current_team home and array-overlap basin are coupled. [same emitted code as probe 34]
probe 40 abi; result=MISMATCH; diff=1554; shape=80.0: Matched Ghidra's inferred int widths for local_178 and local_174, testing whether narrow scalar types recover the target +0x28/+0x2c home order without changing behavior. [same emitted code as probe 32]
probe 42 control-flow; result=MISMATCH; diff=1528; shape=74.70489038785834: Replaced phase-B distance and row-index for-loops with binary-proven preincrement cursor loops, explicit remaining countdown, and a guarded do-loop; tests the target's line-656/660 topology and instruction order.
probe 43 liveness; result=MISMATCH; diff=1528; shape=74.70489038785834: Hoisted the binary-proven distance and packed-line cursors plus countdown to function scope, testing original declaration order and whether stack/register coloring restores the target edge and local homes. [same emitted code as probe 42]
probe 44 control-flow; result=MISMATCH; diff=1537; shape=74.53625632377741: Changed the bubble-sort changed flag to bool in the pointer-cursor distance basin, following Ghidra's bVar5 evidence and testing byte-width/liveness interaction.
probe 45 liveness; result=MISMATCH; diff=1528; shape=74.70489038785834: Added a live current_team receiver alias to the pointer-cursor distance basin and used it across phase B, testing whether the target's saved-this home and relation-call register colors require explicit owner liveness. [same emitted code as probe 43]
probe 46 liveness; result=MISMATCH; diff=1528; shape=74.70489038785834: Moved the live current_team alias before all scalar and array declarations, testing declaration order as the cause of the target prologue's [esp+10] saved-this home. [same emitted code as probe 45]
probe 47 liveness; result=MISMATCH; diff=1533; shape=73.48993288590604: Separated relation group identity from final group count with a real group_index local, matching the decompiler's distinct iVar16/index roles; tests whether this preserves the target's relation-loop register topology.
probe 49 control-flow; result=MISMATCH; diff=1615; shape=74.74747474747475: Rewrote only the distance inner scan as a natural typed packed-line cursor with a countdown, retaining the clean row-fill and relation source; isolates the line-656/660 source form.
```
<!-- end-recovered:802630419ed1e0a24c31 -->
