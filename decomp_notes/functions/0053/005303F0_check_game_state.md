# Function notes: 005303F0 `check_game_state`

Module notes: `decomp_notes/tworld_module.md`.

## Recovered attempt history

<!-- recovered:9126b3dba5a85ff77dd4 -->
### `target-session` `build/target_sessions/005303F0_check_game_state.json:1-35`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1494; shape=83.59683794466403: Baseline current natural source after prior audit; establish exact metrics, call map, block shape, and stack homes.
probe 2 liveness; result=MISMATCH; diff=1494; shape=83.59683794466403: Hypothesis 1: scope loop index i inside the countdown and collection blocks; original initializes EBP after countdown guards, so top-scope i may be hoisted before victory checks. [same emitted code as probe 1]
probe 4 liveness; result=MISMATCH; diff=1494; shape=83.59683794466403: Hypothesis 2: use a distinct index j for the nine-entry initialization and leave i only for the later player loop; this may stop VC5 hoisting i=1 before the victory guard. [same emitted code as probe 2]
probe 6 control-flow; result=MISMATCH; diff=1494; shape=83.59683794466403: Hypothesis 3: explicitly initialize a branch-local i=1 before a separate j-based array fill, then use a continuation for-loop; this models the original post-guard EBP initialization without reusing the fill index. [same emitted code as probe 4]
probe 8 control-flow; result=MISMATCH; diff=1494; shape=83.59683794466403: Hypothesis 4: combine countdown subtraction and threshold test in one compound-assignment guard; original compares ST0 before fstp, unlike the prior separate assignment and if. [same emitted code as probe 6]
probe 10 layout; result=MISMATCH; diff=1544; shape=87.35177865612648: Hypothesis 5: remove cached player_count and read the proven +0x3C player_num directly; original collection setup has no observed stack store for a count local.
probe 12 layout; result=MISMATCH; diff=1560; shape=82.15686274509804: Hypothesis 6: type the cached player count as short, matching the proven short player_num field and original sign-extended bound loads, to avoid an unnecessary full-width home.
probe 14 liveness; result=MISMATCH; diff=1457; shape=84.55445544554455: Hypothesis 7: remove the short-lived count local and use direct post-increment team_size[local_198] expressions; original assembly carries one count through the flattened team-player cursor.
probe 15 layout; result=MISMATCH; diff=1300; shape=87.03339882121807: Hypothesis 8: keep player_count only for the two initialization loops, but reload this->player_num for team outer and inner bounds; original reloads +0x3C at each outer backedge and has no count-home evidence there.
probe 16 liveness; result=MISMATCH; diff=1300; shape=87.03339882121807: Hypothesis 9: move the i declaration after the array locals; original Ghidra lists i as an unmapped late variable, and declaration order can control the early EBP initialization and saved-this color. [same emitted code as probe 15]
probe 17 control-flow; result=MISMATCH; diff=1496; shape=87.20472440944881: Hypothesis 10: add an explicit player_num > 1 guard around the first player loop; the original compare-to-one occurs after the nine-entry fill and may represent this source guard rather than a bare for condition.
probe 18 control-flow; result=MISMATCH; diff=1300; shape=87.03339882121807: Hypothesis 11: use an assignment expression rather than compound assignment in the countdown guard; the original fcom-before-fstp order may require this exact VC5 expression form. [same emitted code as probe 16]
probe 19 behavior; result=MISMATCH; diff=1300; shape=87.03339882121807: Hypothesis 12: spell the initial countdown threshold as >= rather than !(<); Ghidra's decompilation suggests the period source used the positive relation, while the emitted x87 predicate should stay equivalent. [same emitted code as probe 18]
probe 20 liveness; result=MISMATCH; diff=1300; shape=87.03339882121807: Hypothesis 13: declare the countdown player-loop index in the for header, shadowing the later winner-loop index; this tests whether VC5 keeps its initialization inside the guarded branch. [same emitted code as probe 19]
probe 21 layout; result=MISMATCH; diff=1300; shape=87.03339882121807: Hypothesis 14: swap local array declaration order to see whether VC5 assigns the implicit team-player and team-size cursors to the original homes [esp+0x10] and [esp+0x18]. [same emitted code as probe 20]
probe 22 layout; result=MISMATCH; diff=1526; shape=87.20472440944881: Hypothesis 15: model the binary-proven row and size cursors explicitly for the artifact pass using int* team_size and TRIBE_Player** team_player[0]; this tests the original pointer-cursor lowering.
probe 23 liveness; result=MISMATCH; diff=1300; shape=87.03339882121807: Hypothesis 16: use one function-scope p receiver assigned in each artifact/ruin arm; Ghidra shows one pTVar1 reused across arms, and original keeps the first-team receiver live through loop setup. [same emitted code as probe 21]
probe 24 liveness; result=MISMATCH; diff=1300; shape=87.03339882121807: Hypothesis 17: load held directly from team_player[i][0] before assigning the shared p receiver; this tests whether declaration/evaluation order recovers the original ECX pointer and EAX float load. [same emitted code as probe 23]
probe 25 layout; result=MISMATCH; diff=1522; shape=87.20472440944881: Hypothesis 19: repeat the proven artifact row/size cursors with player_cursor declared first, testing whether alias declaration order selects the original [esp+0x10]/[esp+0x18] home assignment.
probe 26 layout; result=MISMATCH; diff=1526; shape=86.81102362204724: Hypothesis 20: retain typed team_player indexing but make the team-size cursor explicit and advance it by one row; original reuses a moving size-pointer home while current implicit lowering assigns the opposite home.
probe 27 liveness; result=MISMATCH; diff=1300; shape=87.03339882121807: Hypothesis 21: lift winner and best to function-scope locals, matching Ghidra's function-wide receiver/result variables; this tests whether their lifetimes control the early EBP and saved-this allocation. [same emitted code as probe 24]
probe 29 layout; result=MISMATCH; diff=1396; shape=82.37623762376238: Hypothesis 22: use the CodeView/Ghidra-declared float held_time type instead of int; test whether the original shared stack home came from the period declaration.
probe 31 behavior; result=MISMATCH; diff=1559; shape=87.35408560311284: Hypothesis 23: use the period-style bulk memset initialization for team_size and player_team; original setup has byte-count LEA/SHR and two REP STOS blocks that loop syntax does not reproduce.
probe 32 context; result=MISMATCH; diff=1559; shape=87.35408560311284: Hypothesis 24: force the supported VC5 intrinsic memset lowering for the proven bulk initializers; test whether it removes the REP STOS byte-tail that the external declaration added. [same emitted code as probe 31]
probe 34 control-flow; result=MISMATCH; diff=1300; shape=87.03339882121807: Hypothesis 25: lower the victory-player pass as the PDB-supported  form, instead of a for initializer that VC5 hoists to the entry. [same emitted code as probe 28]
probe 36 behavior; result=MISMATCH; diff=1300; shape=87.03339882121807: Hypothesis 26: use the natural compound countdown update followed by a separate threshold guard; the original FPU block compares before FSTP, unlike the current assignment-in-condition lowering. [same emitted code as probe 34]
probe 37 liveness; result=MISMATCH; diff=1300; shape=87.03339882121807: Hypothesis 27: make each artifact/ruin outer team index block-local, matching the original team-pass lifetime and testing whether VC5 can reuse the team_size[0] home for the group countdown. [same emitted code as probe 36]
probe 39 layout; result=MISMATCH; diff=1517; shape=89.10891089108911: Hypothesis 28: model the original team passes as typed +1 row/size cursors with a do/countdown loop; the binary proves row stride 9, size stride 1, and a stored team-left counter.
probe 40 layout; result=MISMATCH; diff=1516; shape=89.5049504950495: Hypothesis 29: keep the typed countdown cursors but anchor them at team_size and team_player[0]; raw original setup uses LEA [esp+28]/[esp+70], while +1 was a decompiler label bias.
probe 41 liveness; result=MISMATCH; diff=1519; shape=89.70297029702971: Hypothesis 30: declare the proven player-row cursor before the size cursor so VC5 assigns the original artifact setup homes: player cursor [esp+10], size cursor [esp+18].
probe 43 behavior; result=MISMATCH; diff=1300; shape=87.22986247544205: Hypothesis 31: spell winner selection as , matching the original CMP value,best / JLE block rather than the equivalent best < value form.
probe 44 abi; result=MISMATCH; diff=1437; shape=88.8671875: Hypothesis 32: restore the canonical RGE_Player::attributes pointer at +0x50 and use proven attribute indices 7/55 for artifact and 14/54 for ruin totals/reset effects; original assembly dereferences those pointers instead of the TRIBE held-time fields.
probe 45 layout; result=MISMATCH; diff=1522; shape=91.55206286836935: Hypothesis 33: combine the proven RGE_Player attribute-pointer accesses with the original typed row/size cursor countdown; test whether pointer ownership restores both attribute loops and outer team CFG.
probe 46 liveness; result=MISMATCH; diff=1434; shape=91.9921875: Hypothesis 34: lift the shared player and held temporaries to function scope, matching the decompiler's reused pTVar1/fVar2 lifetimes across artifact and ruin passes.
probe 47 liveness; result=MISMATCH; diff=1437; shape=88.8671875: Hypothesis 35: lift only the reused player receiver p while keeping held branch-local; test the original pTVar1 lifetime without adding the early held home. [same emitted code as probe 44]
```
<!-- end-recovered:9126b3dba5a85ff77dd4 -->

<!-- recovered:1ac16e18bccc09d1c84d -->
### `57de5af98e5d` `src/scratch/005303F0_check_game_state.cpp:1-46`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 005303F0 TRIBE_World::check_game_state
// PDB source: tworld.cpp lines 1151-1371
// Attempt log:
// 1: initial natural reconstruction from Ghidra body, typed local arrays and direct call surfaces.
// 2: corrected world/player offsets, float constants, and direct victory/message call surfaces; call set aligned but body remained structurally broad.
// 3: tried source loop/local-shape reductions and external float constants; no exact basin, frame/size still drift.
// 4: replaced the raw volatile game-state guard with the named game_state field; emitted code was unchanged, so the natural form remains.
// 5: threshold-left and negated-less countdown guards changed FPU order but did not match; kept the period guard form.
// 6: removing the positive array-init guard changed the call prefix and worsened the body; restored it.
// 7-8: local base-game aliases prevented message-call tail merging and aligned all virtual calls, but added code.
// 9: removed the grouping p local and used direct player expressions; frame reached 0x1A4 and team arrays reached original homes.
// 10: removed the outer team-building guard; one loop entry test now matches the original and size dropped to +22 bytes.
// 11: cached player_count across team setup; size reached +11 bytes, but register/block shape worsened.
// 12: kept a local base-game alias for the ruin-start message; all 16 calls now align, with 1668 rebuilt bytes vs 1653 original.
// 13: tested the proven 00577580 global for held == -1 comparisons; kept it because the original has two absolute references.
// 14: tested scoped base-game aliases at each message site and direct player_num bounds; call and block shape improved, but the source was compiler-steering and was rolled back.
// 15: restored the clean cached-player reconstruction; remaining drift is team-array scheduling and the saved this home.
// 16: direct team_size increments reduced the strict difference to 1457 bytes.
// 17: keeping player_count only for the two fill loops and reloading player_num
//     for the team loops reduced the strict difference to 1300 bytes.
// 18-21: declaration, comparison, pointer-scope, and cursor variants did not
//        change emitted code or improve the 1300-byte result.
// Main-agent audit replaced raw-address macros with named extern globals.
// Best clean result: 1653 rebuilt bytes, 0 size delta, exact frame, all 16
// calls aligned, 1300 strict differing bytes, 87.03% shape similarity.
// BINARY NOTE: The original reloads player_num at the team-loop backedge.
// Keep those bounds as direct this->player_num expressions.
// 22: the CodeView-declared float held_time type added an unwanted __ftol call;
//     the int count form is the supported codegen basin.
// 23-24: bulk memset and intrinsic variants added byte-tail code and were
//        discarded; the existing integer fill lowering is closer in size.
// 25-27: do-loop and block-scope victory-index variants were codegen-neutral.
// 28-30, 33: typed row/size cursors improved CFG shape but moved pointer homes
//            and increased strict drift; the direct indexed form remains.
// 31: member-left winner comparison restores the original CMP/JLE block.
// 32, 34-35: the canonical RGE_Player attributes pointer improves exact
//             attribute blocks; lifted p/held variants do not improve codegen.
// BINARY NOTE: Artifact totals and reset-zero effects use attributes[7] and
// attributes[55]. Ruin uses attributes[14] and attributes[54]. Held timers
// still use the direct derived fields at +840 and +844.
// Current semantic checkpoint: 1662 bytes, exact frame, all 16 calls aligned,
// 1437 strict differing bytes, and 63.37% exact-block coverage.
// Unresolved: the victory guard hoists i=1 and team-array cursor homes differ.
// Follow-up probes: scoped held_time, nested countdown guards, and a split
//   countdown assignment were codegen-neutral. The pinned natural source is
//   restored; a new declaration or context fact is still needed.
```
<!-- end-recovered:1ac16e18bccc09d1c84d -->
