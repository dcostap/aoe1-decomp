# Recovery journal: 0052EF30 `new_game`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tworld.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tworld.cpp`.
- Earlier recovery note: `recovery_notes/tworld_module.md`.

## Translation-unit context

- The PDB compiland is `tworld.cpp`. The function owns `0052EF30-005302D3`.
- The PDB line span is `525-1128`. The next normal function starts at `00530370`.
- The original has a `0x1308` stack allocation, EH state, and 171 calls.
- The original saves EBX, EBP, ESI, and EDI after the stack probe.
- The natural translation-unit group is `tworld_cpp`.

## Current mismatch

- Fresh natural-module baseline: 5,028/5,028 bytes, 4,351 strict differing
  bytes, 1,554-byte edit cost, 88.79% shape, and 44.33% exact blocks.
- The baseline had 168/171 calls. VC5 merged three conquest setter sites.
- Current source: 5,228/5,028 bytes, 4,301 strict differing bytes,
  1,440-byte edit cost, 86.31% shape, and 43.80% exact blocks.
- Current call counts are 171/171. Ordered call alignment is 99.42%.
- Current CFG counts are exact: 116 conditional branches and 47 jumps.
- The current boundary exceeds the original by 200 bytes. This is not a
  narrow drift candidate.
- The first instruction mismatch is at `+0x4C`. The original keeps the base
  result in BL. VC5 stores AL directly to `[esp+0x17]` in the rebuild.
- The only aggregate call-target gap is the stack-probe symbol. The original
  names `__alloca_probe`; the rebuild names `__chkstk`.

## Recovered attempt history


<!-- recovered:4ae6ccce332e205a33c1 -->
### `target-session` `build/target_sessions/0052EF30_new_game.json:1-38`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=4650; shape=88.26229508196721: Baseline current broad reconstruction before new probes; establishes behavior, call surface, frame, and mismatch.
probe 2 control-flow; result=MISMATCH; diff=4782; shape=84.36911487758945: Hypothesis 1: an if/else chain will preserve distinct Set_Multi_Conquest call sites instead of the switch's common tail.
probe 4 liveness; result=MISMATCH; diff=4650; shape=88.26229508196721: Hypothesis 2: scoped scenario receiver aliases in each victory case will keep call ownership branch-local and block the compiler's common setter tail.
probe 6 layout; result=MISMATCH; diff=4642; shape=87.8688524590164: Hypothesis 3: the loop index may be a narrow short because player_num is a proven short; this tests whether width preserves the original induction and homes.
probe 8 control-flow; result=MISMATCH; diff=4650; shape=88.26229508196721: Hypothesis 4: a natural while loop for the initial reset scan may preserve the oracle's pre-tested branch and induction placement better than for syntax. [same emitted code as probe 1]
probe 10 behavior; result=MISMATCH; diff=4641; shape=88.14669286182057: Hypothesis 5: the post-save victory getter is one binary call whose result drives both time and score tests; cache it to remove the extra rebuilt call.
probe 11 control-flow; result=MISMATCH; diff=4601; shape=88.39344262295081: Hypothesis 6: encode the one-call post-victory 8/9 dispatch as a switch, matching the oracle's sub/dec two-case lowering.
probe 12 context; result=MISMATCH; diff=4641; shape=88.14669286182057: Hypothesis 7: period memory.h plus string.h may select the original VC5 string intrinsic basin and restore the observed copy mask and schedule.
probe 13 flags; result=MISMATCH; diff=4641; shape=88.14669286182057: Hypothesis 8: reduce VC5 inlining to /Ob1; this tests whether the oracle's helper boundaries explain the merged setter and string-call drift. [same emitted code as probe 10]
probe 14 flags; result=MISMATCH; diff=4303; shape=71.47540983606558: Hypothesis 9: disable inlining with /Ob0 to test whether the original's repeated helper blocks came from a smaller inline budget.
probe 16 control-flow; result=MISMATCH; diff=4642; shape=88.21218074656188: Hypothesis 10: group victory cases 0 and 9 because the oracle jump table maps both entries to one case block; test whether this restores dispatch and setter layout.
probe 17 liveness; result=MISMATCH; diff=4641; shape=88.14669286182057: Hypothesis 11: the cached post-victory enum is a function-scope local in the decompiler; move its declaration to the top to test stack lifetime and register coloring.
probe 18 control-flow; result=MISMATCH; diff=4641; shape=88.14669286182057: Hypothesis 12: an inline repeated-operation helper may preserve each case's distinct setter site while still inlining to the proven direct target.
probe 19 liveness; result=MISMATCH; diff=4641; shape=88.14669286182057: Hypothesis 13: explicitly register-qualify the byte result to recover the oracle's BL carry across the initial reset loop; current cached getter context may change the prior result. [same emitted code as probe 17]
probe 20 context; result=MISMATCH; diff=4641; shape=88.14669286182057: Hypothesis 14: stdlib.h was period-plausible in tworld.cpp; test whether its VC5 front-end context recovers the early result register and helper schedule.
probe 21 behavior; result=MISMATCH; diff=4403; shape=89.04918032786885: Hypothesis 15: the oracle's difficulty block uses buffered get_string(0x25e0,str2,0x100), then sprintf(str3,str2,str1), unlike generic one-argument append_line; restore this proven call surface.
probe 22 control-flow; result=MISMATCH; diff=4843; shape=84.63949843260188: Hypothesis 16: separate mutually exclusive if statements may stop VC5 from tail-merging the four positive conquest setters into one common switch tail.
probe 23 control-flow; result=MISMATCH; diff=4890; shape=85.34912718204488: Hypothesis 17: keep four independent conquest ifs to preserve setter sites, but use a compact switch for amount-based cases 2-6 to reduce the separate-if size penalty.
probe 24 flags; result=MISMATCH; diff=4748; shape=63.14754098360656: Hypothesis 18: test VC5 /O1 to see if a lower optimization basin preserves separate switch calls or the oracle's prologue scheduling.
probe 26 liveness; result=MISMATCH; diff=4403; shape=89.04918032786885: Hypothesis 19: place postVictoryType first among locals, matching the decompiler's early enum temporary, to test declaration-order register coloring. [same emitted code as probe 25]
probe 28 liveness; result=MISMATCH; diff=4403; shape=89.04918032786885: Hypothesis 20: register-qualify ret_num to keep the base new_game byte result in a callee-saved byte register, matching the oracle's mov bl,al and later test bl. [same emitted code as probe 27]
probe 29 layout; result=MISMATCH; diff=4419; shape=83.8688524590164: Hypothesis 21: recover the decompiler-proven overlap of the base-result byte with str1[3], instead of a separate ret_num local; this should move str1 to [esp+14], produce mov bl,al/store BL, and preserve the original byte home.
probe 30 control-flow; result=MISMATCH; diff=4359; shape=88.26229508196721: Hypothesis 22: mirror the binary decompiler's bounded player scans with a saved player_count, moving player cursor, positive guard, and bottom decrement instead of indexed for loops.
probe 31 liveness; result=MISMATCH; diff=4369; shape=88.78688524590164: Hypothesis 23: keep each player-array cursor declaration inside its positive-count guard, matching the decompiler's delayed players load and original fault order.
probe 32 control-flow; result=MISMATCH; diff=4537; shape=85.19447929736512: Hypothesis 24: inline the binary-proven random-game fallback scans, zeroing artifact_count/ruin_count before each bounded walk and incrementing the members directly.
probe 33 liveness; result=MISMATCH; diff=4369; shape=88.78688524590164: Hypothesis 25: restore the PDB/decompiler local order (generator, victoryAmount, ret_num, buffers, loop values) and place the late postVictoryType temporary after those declarations. [same emitted code as probe 31]
probe 34 abi; result=MISMATCH; diff=4369; shape=88.78688524590164: Hypothesis 26: use the original PDB-decorated RGE_Player_Info reference ABI for both world new_game declarations, rather than the pointer candidate.
probe 35 behavior; result=MISMATCH; diff=4369; shape=88.78688524590164: Hypothesis 27: correct the post-save victory enum values from 8/9 to the executable's proven VictoryTime=7 and VictoryScore=8 (sub eax,7; dec eax).
probe 36 liveness; result=MISMATCH; diff=4369; shape=88.78688524590164: Hypothesis 28: model the decompiler's separate base-result byte and ret_num home: keep base_result live for the late branch, then store ret_num and return it.
probe 37 abi; result=MISMATCH; diff=4369; shape=88.78688524590164: Hypothesis 29: test signed char for the returned local, since the target's byte home and BL live value might use the source char surface rather than uchar. [same emitted code as probe 36]
probe 38 liveness; result=MISMATCH; diff=4369; shape=88.78688524590164: Hypothesis 30: register-qualify the separate base_result byte, testing whether the compiler can retain the decompiler-proven late result in BL rather than folding it into ret_num. [same emitted code as probe 37]
probe 39 control-flow; result=MISMATCH; diff=4526; shape=85.29595015576324: Hypothesis 31: reproduce the original switch handler order and grouped labels: 0/9, 1, 7, 8, 3, 4, 5, 2, 6, as proved by switchdata XREFs and PDB line bands.
probe 40 control-flow; result=MISMATCH; diff=4379; shape=88.85245901639344: Hypothesis 32: isolate grouped 0/9 labels from the original handler-order change while restoring ascending source case order.
probe 41 control-flow; result=MISMATCH; diff=4373; shape=88.85245901639344: Hypothesis 33: test original PDB textual handler order without grouping labels, to separate source order from case-label sharing.
probe 42 liveness; result=MISMATCH; diff=4369; shape=88.78688524590164: Hypothesis 34: match the PDB local order exactly at the victory block: victoryAmount before generator, then ret_num and the string buffers. [same emitted code as probe 38]
probe 43 control-flow; result=MISMATCH; diff=4404; shape=88.98360655737704: Hypothesis 35: replace the cached post-save if/else with the binary-proven one-call two-case switch; original sub/dec lowering and PDB cases are 7 and 8.
probe 44 liveness; result=MISMATCH; diff=4369; shape=88.78688524590164: Hypothesis 36: introduce one natural zero accumulator in the successful initialization arm, matching the original EBX zero used for reset fields, setter arguments, Save, generator construction, and missing-object spacing.
probe 45 liveness; result=MISMATCH; diff=4369; shape=88.78688524590164: Hypothesis 37: preserve a real short object_id local through each count_objects scan, testing the original artifact loop's mov edi,9F/cmp word,[...],di shape.
```
<!-- end-recovered:4ae6ccce332e205a33c1 -->

<!-- recovered:6d7e71dbdfebe0721957 -->
### `57de5af98e5d` `src/scratch/0052EF30_new_game.cpp:1-65`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// Initial heuristic C++ lift from Ghidra for TRIBE_World::new_game (0052EF30).
// This is intentionally broad and local-stub-heavy: first goal is to get the full
// behavioral surface compiling, then iterate call/layout/codegen toward parity.
// FLAGS: config/flags/0052EF30_new_game.rsp (/GX)
// Natural new/delete for RGE_RMM_Object_Generator plus /GX recovers the original
// EH prologue shape and 0x1308 frame; broad code-shape drift remains.
// Inlining description helpers and direct player/resource access brought the body
// above 5028 bytes so check_function now reports a real diff instead of size-stop.
// Remaining early mismatch: VC5 stores base new_game result from AL to [esp+17]
// and frees EBX for a hoisted strlen mask; original keeps AL in BL, stores BL,
// and later tests BL. Tried register/result-holder forms; they were unchanged.
// Attempt log:
// - Replaced the description-path goto with one negated guard; VC5 emitted the
//   same bytes, so the natural guard remains the source form.
// - Collapsed duplicate base-new-game result locals; VC5 emitted the same bytes.
// - Cached the post-save victory getter after Save_victory_conditions_into_players;
//   this removes one rebuilt call and matches the oracle's single post-save call.
// - Modeled the generator's binary-proven 0x1920 object size with derived padding;
//   this fixed the allocation ABI and improved the structural call surface.
// - Restored explicit branches for the Yes/No description selectors; this fixed
//   the condition count and one exact description block.
// - Retained the binary-proven standalone difficulty getter despite local drift;
//   a register-qualified return local emitted duplicate code.
// - Buffered difficulty formatting matched the virtual call surface but exceeded
//   the original boundary by 164 bytes, so it was rolled back.
// - Restored the victory switch's binary case table: cases 0/9 map to type 0,
//   1 to type 1, 7 to type 2, and 8 to type 3; cases 2-6 set amount fields.
//   This moved the switch hunk one byte closer but VC5 still tail-merged the
//   five source conquest calls into two emitted calls.
// - Tested the period VictoryType enum return surface from the Ghidra source;
//   VC5 emitted identical bytes and the enum surface was rolled back.
// - Tested 20 source, type, control-flow, context, and flag hypotheses. /Ob1 and
//   header changes were duplicates. /Ob0 and /O1 were worse.
// - The oracle uses a buffered difficulty format-string fetch, not generic
//   append_line. This restores one virtual call slot and 247 positional bytes.
// - VC5 still merges four conquest setter tails. Separate if arms restore all
//   four calls but add 168 bytes, so the switch remains the clean source.
// - The stack helper still emits __chkstk instead of the oracle's __alloca_probe.
// Follow-up pass:
// - The PDB/Ghidra player scans use a saved count, a moving player cursor, a
//   positive guard, and a bottom decrement.  The two reusable scans now use
//   that natural form.  This reduced the positional diff from 4403 to 4369.
// - The original PDB ABI uses RGE_Player_Info&.  The reference surface is
//   retained.  It is codegen-neutral in this function.
// - The post-save enum values are VictoryTime=7 and VictoryScore=8.  The
//   source now uses those proven values.
// - Grouped and reordered victory switch cases recovered the missing setter
//   calls only with a 184-byte boundary overrun.  The natural ascending switch
//   remains the clean source.
// - Separate result, register, zero-local, and object-id forms were neutral or
//   worse.  They are not retained.
// - Remaining blockers are the base-result BL schedule, three merged conquest
//   setter calls, and the compiler's __chkstk symbol choice.
// BINARY NOTE: score_displayed and controllingComputerPlayer publish before
//   the base new_game call. Keep that order and the direct RGE_Player_Info& ABI.
// BINARY NOTE: player objects, victory state, resources, and civilization use
//   the reviewed RGE_Player offsets. TRIBE_Player casts only select derived calls.
// BINARY NOTE: the post-save victory query is one call, generator publication
//   follows the scenario updates, and player effects follow generator cleanup.
// Shared-context audit: world/player ownership is canonical. The 5028-byte
//   candidate retains 168/171 calls and 4369 strict drift; the missing calls are
//   repeated equal-value conquest setter tails, not missing source branches.
// Context audit: the phase2 context places T_Scenario helpers on its
//   RGE_Scenario base. The original decorated targets belong to T_Scenario;
//   this shared declaration defect needs main-agent review.
```
<!-- end-recovered:6d7e71dbdfebe0721957 -->

<!-- recovered:bd14ae45108e28f647f1 -->
### `57de5af98e5d` `src/scratch/0052EF30_new_game.cpp:426-426`

Mapping: `exact`. historical standalone source path names this target VA.

```text
            // BINARY NOTE: the executable makes one post-save victoryType call.
```
<!-- end-recovered:bd14ae45108e28f647f1 -->

## Rejected approaches

- A named `TRIBE_Game::VictoryType` post-victory local emits the same code as
  a direct switch expression.
- A base-class receiver for the nested path-finding `get_string` call emits
  the same code as the derived-class receiver.
- The earlier result-width, register, local-order, zero-local, helper, flag,
  and switch experiments remain rejected. The recovered history lists them.
- Do not retain independent `if` statements, fake aliases, dummy liveness,
  fake volatility, or flag changes to preserve conquest call sites.

## Open questions

- Why does this VC5 context hoist the repeated string-copy mask into EBX?
  The original reserves BL for the base result through the description block.
- Which natural declaration or period header context selects the original
  `__alloca_probe` symbol instead of `__chkstk`?
- Why does the current compiler expand the proved victory-handler order by
  192 bytes? The original keeps all four conquest setter blocks in 144 bytes.

## Next useful approaches

- Find an exact VC5 donor that keeps a byte result in BL across several
  intrinsic `strcpy` blocks. No current assembly-bank donor covers this shape.
- Compare the original period `tribegam.h` victory enum and `tworld.cpp`
  include order if repository evidence becomes available.
- Isolate the main victory switch in its authentic full translation-unit
  context. Keep the proved handler order and reject synthetic control flow.
- Resolve the stack-probe symbol through toolchain evidence. Do not add a
  source wrapper or a direct helper declaration.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

### `bonus-sol-tworld` deep recovery

Facts from the executable and PDB line bands:

- The main victory switch emits handlers in this order: `0/9`, `1`, `7`, `8`,
  `3`, `4`, `5`, `2`, and `6`. The handler lines are 773 through 808.
- The post-save victory query is one call. The executable lowers values 7 and
  8 as `sub eax,7; je; dec eax; jne`.
- The scenario switch places the time handler at PDB line 845 before the score
  handler at line 850.
- The random-game fallback sets `artifact_count` to zero before its first
  player walk. It then sets `ruin_count` to zero before its second walk.
- The fallback reuses one saved player count. Each walk uses a moving player
  pointer and a bottom decrement.

The source now follows those facts. The direct fallback walks recovered near
exact blocks. The artifact walk starts at original `+0xCBD` and rebuilt
`+0xCBC`. The ruin walk starts at original `+0xD07` and rebuilt `+0xD02`.

The proved switch orders recover all 171 call sites. They expose a 192-byte
VC5 expansion in the main switch. The direct fallback walks add eight bytes,
but reduce strict drift from 4,548 to 4,301 bytes. They also restore the
original fault order for partial player walks.

The final source improves strict drift by 50 bytes from the fresh baseline.
It restores three missing conquest calls and exact CFG instruction counts.
It remains unresolved because the body is 200 bytes too large.

`target_session.py check` timed out on the shared session lock. The worker did
not retry the lock. Direct focused checks and the grouped audit provide the
validation evidence for this pass.

The grouped `tworld_cpp` audit found all 20 registered exact neighbors at
`MATCH`. It reports this target as `MISMATCH` with 4,301 differing bytes.
The report is under `build/audits/workers/bonus-sol-tworld/tworld_cpp/`.
