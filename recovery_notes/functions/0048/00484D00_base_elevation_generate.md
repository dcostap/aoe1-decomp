# Recovery journal: 00484D00 `base_elevation_generate`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/rmm_elev.cpp`.
- PDB source: `C:\msdev\work\age1_x1\rmm_elev.cpp`.
- Earlier recovery note: `recovery_notes/rmm_elev_natural_candidate.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:4215468dbd70a5aac882 -->
### `target-session` `build/target_sessions/00484D00_base_elevation_generate.json:1-48`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1109; shape=83.37236533957845: Baseline current natural typed reconstruction before fresh probes; assess boundary, calls, frame, and first mismatch.
probe 2 layout; result=MISMATCH; diff=1226; shape=88.3177570093458: Hypothesis 1: initialize local_stack.x and max_y before stack setup, then use those saved bounds in phase-B neighbor guards; original stores both bounds before init and phase uses their homes.
probe 4 liveness; result=MISMATCH; diff=1179; shape=83.01886792452831: Hypothesis 2: leave x, y, and the later fig_chance result uninitialized because pop_stack and fig_chance first define them; remove compiler-visible zero stores absent from the oracle.
probe 6 control-flow; result=MISMATCH; diff=1099; shape=83.37236533957845: Hypothesis 3: move only local_stack.x initialization ahead of the clump init loop, matching the oracle's early width-bound store without adding a second bound local.
probe 7 layout; result=MISMATCH; diff=1226; shape=88.3177570093458: Hypothesis 4: keep the early local_stack.x store, add an uninitialized max_y assigned immediately after it, and use both saved bounds only in phase-B neighbor checks.
probe 9 layout; result=MISMATCH; diff=1218; shape=88.08411214953271: Hypothesis 5: assign max_y only after the seed initialization loop while retaining an early local_stack.x; test whether VC5 hoists the bound and keeps the original frame without changing clump-load order.
probe 11 context; result=MISMATCH; diff=1109; shape=83.37236533957845: Hypothesis 6: pass the original debug_rand source path as string literals, not an unresolved external array; the oracle pushes the nonzero rdata address at all five sites.
probe 13 liveness; result=MISMATCH; diff=1099; shape=82.97872340425532: Hypothesis 7: remove the persistent base_elevation local and reread the by-value line field at each proven tile comparison; oracle loads base elevation late into EBP while EBX carries the phase stack cursor.
probe 15 liveness; result=MISMATCH; diff=1109; shape=83.37236533957845: Hypothesis 8: scope base_elevation inside the phase-B accepted-candidate branch, after check_elevation, so the value loads late into the compare register and does not extend across seed setup. [same emitted code as probe 1]
probe 17 context; result=MISMATCH; diff=1109; shape=83.37236533957845: Hypothesis 9: add the period CRT declaration context via stdlib.h before math.h; old VC5 front-end state can change intrinsic and local allocation in this same-TU function. [same emitted code as probe 15]
probe 19 control-flow; result=MISMATCH; diff=1186; shape=83.76470588235294: Hypothesis 10: mirror the oracle's countdown pointer loop for init_stack, with a cached clump count and post-call pointer increment, instead of an upward indexed for loop.
probe 21 liveness; result=MISMATCH; diff=1109; shape=83.37236533957845: Hypothesis 11: cache line.clumps in a dedicated init-count local before zero initialization, while preserving direct line.clumps uses in later phases; test whether VC5 keeps the oracle's early EBX count. [same emitted code as probe 17]
probe 23 abi; result=MISMATCH; diff=1109; shape=83.37236533957845: Hypothesis 12: correct Map_Stack.cost to float to match the helper ABI and neighboring period donor, while preserving the proven 0x18-byte record layout. [same emitted code as probe 21]
probe 25 liveness; result=MISMATCH; diff=1109; shape=83.37236533957845: Hypothesis 14: remove only the local_chance zero initializer; the oracle materializes that float only after fig_chance, unlike the current prologue zero store. [same emitted code as probe 23]
probe 27 liveness; result=MISMATCH; diff=1192; shape=83.09859154929578: Hypothesis 15: leave only x uninitialized because pop_stack writes it before every read; retain y and chance initializers to isolate its home/lifetime effect.
probe 29 liveness; result=MISMATCH; diff=1191; shape=80.51643192488262: Hypothesis 16: leave only y uninitialized because pop_stack writes it before every read; retain x and chance initializers to isolate the alternate output-home effect.
probe 31 layout; result=MISMATCH; diff=940; shape=84.07494145199063: Hypothesis 17: use the direct row-plus-stride-plus-five expression for the seed tile RMW, matching the exact generate donor and the oracle's single LEA with displacement 5.
probe 32 layout; result=MISMATCH; diff=964; shape=83.14087759815243: Hypothesis 18: spell the phase-B tile RMW as a direct row-plus-stride-plus-five expression, testing whether VC5 recovers the oracle's reused tile address and byte-register schedule.
probe 34 layout; result=MISMATCH; diff=1203; shape=88.78504672897196: Hypothesis 19: combine the proven direct seed tile RMW with an early saved max_y bound and local_stack.x phase bounds, testing whether the exact first island survives the original frame basin.
probe 36 liveness; result=MISMATCH; diff=920; shape=83.68794326241135: Hypothesis 20: retain the direct seed tile RMW but remove the persistent base-elevation local, combining two independent oracle-supported source forms to test phase register pressure.
probe 37 control-flow; result=MISMATCH; diff=920; shape=83.68794326241135: Hypothesis 21: reverse the equivalent fairness predicate to , matching the oracle's cmp mark,random followed by jg and removing the compiler-created short branch block.
probe 38 control-flow; result=MISMATCH; diff=838; shape=84.39716312056737: Hypothesis 22: put expansion in the positive  arm and mark reset in its explicit else arm, so VC5 can lay out the fall-through like the oracle's jg-to-reset branch.
probe 39 layout; result=MISMATCH; diff=838; shape=84.39716312056737: Hypothesis 23: name the search-map row before adding y to form mark, matching the oracle's separate row load, scaled x LEA, and row-plus-y LEA. [same emitted code as probe 38]
probe 40 layout; result=MISMATCH; diff=932; shape=88.67924528301887: Hypothesis 24: allocate max_y as a real local but assign it immediately before the expansion do-loop, testing whether its slot raises the frame without disturbing the exact seed and fairness CFG.
probe 42 liveness; result=MISMATCH; diff=1109; shape=83.37236533957845: Hypothesis 25: keep one cached clumps local live across seed, phase, and cleanup loops, testing whether VC5 preserves the oracle's count register instead of reloading the by-value field. [same emitted code as probe 25]
probe 44 abi; result=MISMATCH; diff=923; shape=84.23529411764706: Hypothesis 26: preserve check_elevation full integer result in a long and test it greater than zero, matching the oracle test-eax/jle sequence instead of spilling an unsigned byte.
probe 45 abi; result=MISMATCH; diff=806; shape=84.63356973995272: Hypothesis 27: retain a full raw check_elevation result for the test while materializing a separate uchar ok only for fig_chance, testing natural ABI-width preservation with the desired frame.
probe 46 liveness; result=MISMATCH; diff=806; shape=84.63356973995272: Hypothesis 28: split the uchar ok declaration from its raw-result assignment at function scope, testing whether a real persistent byte home restores the oracle frame while retaining full-result testing. [same emitted code as probe 45]
probe 47 liveness; result=MISMATCH; diff=806; shape=84.63356973995272: Hypothesis 29: promote stack_ptr to function scope and assign it at phase entry, matching the decompiler evidence that one pointer local spans the seed and expansion phases. [same emitted code as probe 46]
probe 48 layout; result=MISMATCH; diff=796; shape=85.1063829787234: Hypothesis 30: initialize local_stack.x before the seed loop while retaining the direct tile RMW, reversed fairness layout, and full raw check result; this should force saved-register setup before the clump load.
probe 49 layout; result=MISMATCH; diff=940; shape=85.1063829787234: Hypothesis 31: add the late max_y bound to the improved early-local-stack source, testing frame recovery after saved-register setup already matches.
probe 51 abi; result=MISMATCH; diff=913; shape=84.70588235294117: Hypothesis 32: use one long ok result directly for both the positive test and fig_chance, avoiding the delayed uchar cast and matching the oracle's full-EAX path.
probe 52 liveness; result=MISMATCH; diff=931; shape=85.91549295774648: Hypothesis 33: retain the improved early-stack and fairness source, but cache base_elevation as a long local for all phase tile comparisons to test the oracle EBP comparison register.
probe 53 liveness; result=MISMATCH; diff=809; shape=82.03309692671395: Hypothesis 34: reuse the post-sqrt clump_size local for all four weighted random scores, matching the oracle's repeated integer score home and decompiler evidence.
probe 55 layout; result=MISMATCH; diff=1104; shape=88.4160756501182: Hypothesis 1: restore the binary-proven local stack head initialization (next and prev), cached map bounds, and stack-before-head declaration order; test whether the original 0x988 local window is the natural source shape.
probe 56 liveness; result=MISMATCH; diff=1173; shape=88.17966903073287: Hypothesis 2: use one function-scope seed/deinit index and leave pop_stack output coordinates uninitialized; the original has one reused clump counter in EBX and no entry stores for the two output homes.
probe 57 liveness; result=MISMATCH; diff=1173; shape=88.17966903073287: Hypothesis 3: materialize a short-lived init_count from line.clumps before the local declarations, while retaining the binary-proven stack head and bounds; this tests the early parameter load seen before max-width setup. [same emitted code as probe 56]
probe 60 control-flow; result=MISMATCH; diff=1139; shape=85.34278959810875: Hypothesis 4: model the init-stack phase as a pointer walk with a short-lived count, matching the oracle pointer increment and count-down loop and testing whether this selects EBX for line.clumps before the bound locals.
probe 62 liveness; result=MISMATCH; diff=796; shape=85.1063829787234: Hypothesis 5: keep the expansion stack cursor block-local rather than function-scope; the original cursor is only used in the phase and must share EBX with the seed count while EBP carries the mark pointer on the reset path. [same emitted code as probe 54]
probe 64 liveness; result=MISMATCH; diff=1125; shape=84.74178403755869: Hypothesis 6: reuse the one stack_ptr local for both init-stack and expansion walks; this tests whether the oracle EDI init cursor and EBX phase cursor are one source pointer with disjoint lifetimes.
probe 66 abi; result=MISMATCH; diff=1205; shape=84.03755868544602: Hypothesis 7: correct the local Map_Stack head fields without changing bounds or loop shape; pop_stack requires head.next and the oracle writes both head links, while stack[0].x has no binary store.
probe 69 layout; result=MISMATCH; diff=796; shape=85.1063829787234: Hypothesis 8: change only declaration order so the 24-byte local head precedes the 99-entry stack array in the frame; this tests the original stack base and local-head boundary without changing source behavior. [same emitted code as probe 68]
probe 71 liveness; result=MISMATCH; diff=796; shape=85.1063829787234: Hypothesis 9: mark the proven phase stack cursor as a register local to test whether the oracle EBX cursor is source-level register intent rather than a normal local allocation. [same emitted code as probe 69]
probe 73 layout; result=MISMATCH; diff=796; shape=85.1063829787234: Hypothesis 10: declare the phase countdown before assigning the stack cursor, testing the oracle source order where the countdown home precedes the EBX cursor setup at the phase entry.
probe 75 liveness; result=MISMATCH; diff=796; shape=85.1063829787234: Hypothesis 11: promote the search-map mark pointer to function scope so its long reset edge stays live; the original EBP carries mark across the random branch before being reused for base elevation. [same emitted code as probe 71]
probe 77 layout; result=MISMATCH; diff=796; shape=85.1063829787234: Hypothesis 12: name the fetched search-map row before forming mark, matching the oracle row-pointer-plus-coordinate topology around debug_rand and the later reset store. [same emitted code as probe 75]
probe 79 abi; result=MISMATCH; diff=931; shape=85.91549295774648: Hypothesis 13: compare promoted tile elevations directly with the long line.base_elevation field, removing unsupported byte narrowing; the oracle loads a full base-elevation dword into EBP before its comparisons. [same emitted code as probe 52]
probe 81 abi; result=MISMATCH; diff=828; shape=84.39716312056737: Hypothesis 14: use the reviewed unsigned-char check_elevation result directly for the positive guard and fig_chance, removing the redundant raw long result while preserving the observed byte ABI.
```
<!-- end-recovered:4215468dbd70a5aac882 -->

<!-- recovered:3ed36f2b9c028eb02454 -->
### `24d6ba1ee254` `src/scratch/00484D00_base_elevation_generate.cpp:1-65`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00484D00 RGE_RMM_Elevation_Generator::base_elevation_generate
// Source: rmm_elev.cpp lines 290-403
//
// Natural reconstruction of the elevation clump seeding/expansion routine.
// The executable proves the map-row, search-map, stack, helper ABI, and four
// weighted neighbor-random branches below; keep those ownership facts explicit.
// Initial scratch was a raw direct reconstruction with 21 calls and a 992-byte
// body. This source restores the period typed surfaces and all five debug_rand
// sites before any codegen tuning.
// Matching claim: replacing the first seed do-loop with a natural while loop
// removed a duplicated pop_stack site and aligned all 23 direct calls. Reusing
// the pop cost out-home removed one redundant local and reached the original
// 0x988 frame; restoring the explicit cost local is retained as the more
// period-plausible final source because it preserves the real pop ABI. Named
// clumps/base-elevation locals, stack declaration order, and nested neighbor
// guards were codegen duplicates. Final gap: +14 bytes / 0x984 frame, with
// calls and target order aligned; no raw/asm scaffolding retained.
// Current claim probes: 34+ evidence-led probes retained a smaller natural
// basin at 796 differing bytes, 1273 rebuilt bytes, and 0x980 frame. The
// direct seed tile RMW matches its original LEA/address shape. The fairness
// expansion arm is written as positive expansion with mark reset in else;
// this matches the original cmp/jg layout better than the equivalent inverse.
// Full integer check results improve the test shape, but do not recover the
// original local frame. Saved max-y bounds, cached clump counts, countdown
// init, and score-local reuse were worse or duplicate. The retained source is
// the clearest natural nonexact basin; no asm or metric-only padding remains.
// Fresh shard probes (sa-3119f01e-r1): the original local head writes next and
// prev, leaves pop output homes uninitialized, and uses a 0x988 frame with the
// stack array at the proven boundary. Corrected head fields, declaration order,
// pointer walks, phase cursor order, mark-row aliases, and direct long
// comparisons were worse, duplicate, or moved to the known 0x984/0x988 basin.
// The clean 796-byte basin remains the best natural source. The reviewed
// Map_Stack ABI also confirms that cost is float, even though this function
// only passes stack addresses to the helpers.
// [non-comment lines omitted during migration]
// Main-agent audit confirmed canonical elevation/map-stack ownership and kept
// the natural typed clump-expansion source.
// Continuation (sa-ab4dd300-r1): rmm_land's verified pop_stack ABI exposed a
// real row/column transpose in the four neighbor bounds: y is the column and
// x is the row. Direct map_width/map_height guards replaced unproven carried
// max-bound locals, improving the frame basin and exact-block coverage. The
// phase-B source now has a separate stack_ptr plus countdown, matching the
// original stack[0] cursor and dec/jnz pass. Main-agent audit restored the
// pop cost output to its natural float owner rather than retaining a diagnostic
// long-slot type pun. Validation before that audit:
// 1109 differing bytes, 1287-byte code versus 1273, frame 0x984 versus 0x988,
// all 23 direct call sites aligned. Remaining gap starts in the prologue/local
// window and is structural; no asm or opaque register scaffolding retained.
// Current claim: rechecked the full packet, dossier, ABI donors, and the
// executable-supported helper surfaces. The prior 10-probe campaign already
// exhausted natural phase-loop/local-window leads; retain this readable source
// rather than repeat the 14-byte boundary/frame basin blindly.
// Context pass: PROVED PDB module rmm_elev.cpp, lines 290-403, and owner class
// RGE_RMM_Elevation_Generator. PROVED address order and all 23 direct-call
// anchors. LIKELY source declarations follow the nearby terrain generator.
// UNKNOWN original local-home allocation remains the grouped blocker.
// BINARY NOTE: pop_stack receives y output before x output in this owner.
// Keep that order to preserve the executable's adjacent coordinate homes.
```
<!-- end-recovered:3ed36f2b9c028eb02454 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
