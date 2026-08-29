# Recovery journal: 00496800 `handle_game_update`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_game.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_game.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:a38b4da0f9da34fc1921 -->
### `target-session` `build/target_sessions/00496800_handle_game_update.json:1-35`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1880; shape=86.41765704584041: Baseline current canonical packet reconstruction: 2192 bytes, 583 instructions, 100 calls, frame 0x18, 1880 strict diff; no exact source pinned yet.
probe 2 liveness; result=MISMATCH; diff=1880; shape=86.41765704584041: Hypothesis 1: update_flag is not initialized at function entry; original xor EBX only stores update_counter and first update_flag write occurs in loop. Remove the unsupported initializer. [same emitted code as probe 1]
probe 3 liveness; result=MISMATCH; diff=1880; shape=86.41765704584041: Hypothesis 2: source local declaration order controls the two persistent homes; declare update_counter before calc_game_time to test original stack ownership and saved-register color. [same emitted code as probe 2]
probe 4 liveness; result=MISMATCH; diff=2042; shape=89.13412563667232: Hypothesis 3: decompiler shows two independent last-single-time values; retain both named results and form their sum only at the ratio use, instead of naming an eager sum.
probe 5 liveness; result=MISMATCH; diff=2042; shape=89.13412563667232: Hypothesis 4: with separate single-time locals, an explicit entry zero for update_flag may let VC5 materialize the original EBX zero and share it with update_counter. [same emitted code as probe 4]
probe 6 liveness; result=MISMATCH; diff=1880; shape=86.41765704584041: Hypothesis 5: original add EBP,EAX directly after the second getter indicates a compound accumulator; initialize sum from getter 2, then compound-add getter 3.
probe 7 liveness; result=MISMATCH; diff=1880; shape=86.41765704584041: Hypothesis 6: compiler home assignment follows declaration order; declare persistent update_counter before byte update_flag to recover its original stack slot and EBX zero. [same emitted code as probe 6]
probe 8 liveness; result=MISMATCH; diff=1880; shape=86.41765704584041: Hypothesis 7: chained zero initialization may preserve one zero register and a store into update_counter, matching xor EBX followed by the initial home store. [same emitted code as probe 7]
probe 9 behavior; result=MISMATCH; diff=1880; shape=86.41765704584041: Hypothesis 8: original post-loop tests use test/jbe and test/ja, proving unsigned-positive semantics. Replace all update_counter != 0 guards with update_counter > 0.
probe 10 behavior; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 9: test/jbe and test/ja prove update_counter is unsigned, despite decompiler int naming. Use unsigned long for the accumulated world-time delta.
probe 11 liveness; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 10: a named zero value may model the compiler's early zero register without using volatility; initialize update_counter from a distinct zero local.
probe 12 liveness; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 11: keep the second getter result in a nested scope so VC5 can kill that temporary after the add while preserving the first sum in EBP and leaving EDI for the per-update ratio.
probe 13 abi; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 12: the FPU denominator casts the accumulated getter times to int; use an int sum local to test whether VC5 then keeps EBP as the dword accumulator. [same emitted code as probe 12]
probe 14 liveness; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 13: original sum remains in a callee-saved register across calls; mark the natural accumulator register-qualified to test that source-level allocation hint. [same emitted code as probe 13]
probe 15 context; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 15: same-TU exact donors include stdio.h; restore that period header context to test whether VC5 register allocation and stack-home basin changes.
probe 16 liveness; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 16: the sum may be a function-scope local whose lifetime begins before the multiplayer arm; move the accumulator declaration to function scope and keep compound getter updates.
probe 17 liveness; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 17: initialization at declaration may select the original early store scheduling and zero register, unlike a later assignment statement. [same emitted code as probe 16]
probe 18 liveness; result=MISMATCH; diff=2043; shape=89.64346349745331: Hypothesis 19: decompiler's separate uVar4/uVar6 values may be function-scope temporaries; retain both getter results at function scope and sum only at the ratio.
probe 19 liveness; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 20: keep only the first getter result long-lived, add the second getter through a block-local temporary, and retain the summed result for the later ratio. [same emitted code as probe 15]
probe 21 liveness; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 21: expanded accumulator and loop-index assignments may preserve the original add/store scheduling better than compound assignment and post-increment.
probe 22 liveness; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 22: decompiler cVar3 exists only per update iteration; narrow update_flag to the loop body and remove its dead entry initializer. [same emitted code as probe 21]
probe 23 control-flow; result=MISMATCH; diff=1889; shape=86.77966101694915: Hypothesis 23: auto-exit is a terminal close path; use a direct close-and-return rather than a goto cold label to test original tail placement.
probe 25 control-flow; result=MISMATCH; diff=1889; shape=86.77966101694915: Hypothesis 25: the single-player timeout game-over arm may be a direct terminal cleanup, not a shared source label; duplicate cleanup in that arm and return.
probe 28 abi; result=MISMATCH; diff=1880; shape=86.24787775891342: Hypothesis 1: restore the Ghidra-indicated unsigned long calc_game_time and int update_counter types; test whether original stack-home order and loop compare arise from source widths.
probe 30 control-flow; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 2: inline the game-over and auto-close bodies at their source arms, then branch to the shared exit; this follows the PDB/Ghidra line order instead of cold labels after L_exit.
probe 32 liveness; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 3: model the binary's single EBP=-1 sentinel as a named function local initialized immediately before the update loop, and reuse it for all proven -1 arguments.
probe 34 control-flow; result=MISMATCH; diff=1882; shape=89.81324278438031: Hypothesis 4: replace the guarded do/while update loop with an equivalent top-tested while; test whether VC5 emits the original jl backedge and fall-through loop exit.
probe 35 liveness; result=MISMATCH; diff=1882; shape=89.81324278438031: Hypothesis 5: on the while-loop frontier, carry the first timing getter in a compound accumulator and add the second getter into it; test whether the original EBP sum and FPU spill topology return.
probe 37 liveness; result=MISMATCH; diff=1882; shape=89.81324278438031: Hypothesis 6: combine the while-loop CFG with reversed declaration order for update_counter and calc_game_time, testing whether the original -0x20/-0x24 stack-home assignment appears without changing behavior. [same emitted code as probe 34]
probe 38 control-flow; result=MISMATCH; diff=1882; shape=89.81324278438031: Hypothesis 7: keep the original positive pre-guard and use a nested top-tested while; test whether this preserves the original entry test/reload while retaining the jl backedge.
probe 40 abi; result=MISMATCH; diff=1882; shape=88.96434634974533: Hypothesis 8: combine the structurally stronger while loop with Ghidra-indicated unsigned calc_game_time and signed int update_counter types; test whether type widths recover original homes and size.
probe 42 control-flow; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 9: express the update loop as an infinite loop with an explicit positive continue test and break; this may preserve the original guarded entry while selecting jl-body/fall-through-exit lowering. [same emitted code as probe 32]
probe 44 control-flow; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 10: use a local positive goto backedge after the guarded update-loop entry; this is a source-level way to request the original jl-body/fall-through-exit topology. [same emitted code as probe 22]
probe 46 behavior; result=MISMATCH; diff=1880; shape=86.92699490662139: Hypothesis 11: use the natural truth test for game_ended instead of an explicit == 0 comparison; test whether VC5 emits the original load/test branch. [same emitted code as probe 27]
probe 48 control-flow; result=MISMATCH; diff=1882; shape=89.81324278438031: Hypothesis 12: combine the stronger top-tested while CFG with inline game-over and auto-close bodies; test interaction between tail source order and exact call sequence.
```
<!-- end-recovered:a38b4da0f9da34fc1921 -->

<!-- recovered:db048292f0d39450ead4 -->
### `4da364361016` `src/scratch/00496800_handle_game_update.cpp:1-51`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00496800 TRIBE_Screen_Game::handle_game_update (2206B)
// PDB source: scr_game.cpp lines 1589-1996
// EH frame (/GX): function contains `new TDigital(...)` expressions.
//
// Attempt log:
// baseline: canonical packet reconstruction. TRIBE_Screen_Game is a
// TScreenPanel-derived screen; world is TRIBE_World at +0x5B4 with inherited
// player_num/players/curr_player fields; main_view/map_view are at +0x4B8/+0x4BC.
// The named TPanel, RGE_View, RGE_Game_World, RGE_Base_Game, TRIBE_Game, and
// TTextPanel surfaces model the proven period layouts and virtual slots.
// The body preserves the x87 ratio calculation, 0x18 frame, 100 calls, /GX
// TDigital construction, update loop, timeout scan, game-over, and close paths.
//
// probes (2026-08):
// - rebuilt the provisional declarations as named ABI/layout surfaces and
//   replaced all provisional dispatch placeholders; the emitted code stayed in the
//   same VC5 basin while the source became auditable.
// - typed score_panel access through TPanel::active; no codegen change.
// - tested direct returns and inverted timeout-arm order; both were neutral or
//   worse, so the natural goto cold-tail form is retained.
// - named the single-time sum and initialized calc_game_time before the ratio;
//   this recovered the best 2192-byte / 1880-diff basin while retaining the
//   original x87 ratio behavior.
// - natural outer update-interval/mode guards and explicit initializations did
//   not change the useful codegen. The current source is the clean canonical
//   reconstruction, not a compiler-only variant.
// - tested the behavior-backed rare call region: inlining the game-over and
//   auto-exit bodies changed size or shape but kept the same -6/+6 call-site
//   gap, so it was restored. Direct exit logging and a negative multiplayer
//   guard were also codegen-neutral or worse; the observed shared-exit gotos
//   remain the best source form.
// - the original post-loop tests use unsigned test/jbe/ja forms; an unsigned
//   update counter with positive guards improved shape slightly but not bytes.
// - narrowing update_flag to the update loop, expanded versus compound loop
//   updates, separate getter temporaries, local declaration order, register
//   hints, stdio context, and named-zero forms all stayed in the same basin.
//   Direct close and game-over returns reached exact size but added a return
//   and worsened the strict diff, so the shared exits were restored.
// - resumed matching tested the Ghidra-indicated calc/update type reversal,
//   named -1 sentinel, inline cold exits, and zero-test spellings. These were
//   neutral or worse. A top-tested while loop is a useful structural lead: it
//   gives 100% ordered-call alignment, 10/10 jump parity, and 89.81% shape,
//   but loses the original accumulator carry and is 17 bytes short; it was
//   restored because strict diff is 1882 versus 1880 for the clean do-loop.
//
// unresolved structural lead: original materializes an early EBX zero and
// later uses EBP=-1 before the loop, while this basin keeps EBP=0 and the
// single-time sum in a stack home. That register cascade changes the initial
// store, loop-exit polarity, and placement of the rare game-over/close tails.
// The original places those tails after the common epilogue; VC5 places them
// before the current-panel block for the remaining natural source forms.
```
<!-- end-recovered:db048292f0d39450ead4 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
