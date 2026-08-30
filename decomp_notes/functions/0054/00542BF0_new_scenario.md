# Function notes: 00542BF0 `new_scenario`

Module notes: `decomp_notes/world_module.md`.

## Recovered attempt history

<!-- recovered:027f214240110d7495ad -->
### `target-session` `build/target_sessions/00542BF0_new_scenario.json:1-96`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=221; shape=93.4065934065934: Clean typed source baseline before new evidence-led probes.
probe 3 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: Test a typed local reference alias for random_seed to explain the original store and ECX push. [same emitted code as probe 2]
probe 4 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: Move the result declaration to function scope before setup, matching a plausible original declaration order. [same emitted code as probe 3]
probe 5 context; result=MISMATCH; diff=221; shape=93.4065934065934: Test period World.cpp stdio header context alongside stdlib for codegen basin changes. [same emitted code as probe 4]
probe 6 context; result=MISMATCH; diff=221; shape=93.4065934065934: Test period World.cpp string header context alongside stdlib. [same emitted code as probe 5]
probe 7 context; result=MISMATCH; diff=221; shape=93.4065934065934: Test period Windows SDK header context for the World.cpp translation-unit basin. [same emitted code as probe 6]
probe 8 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: Test a natural chained assignment that preserves the selected seed through member storage. [same emitted code as probe 7]
probe 9 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: Test a block-local selected seed to separate its lifetime from the incoming parameter. [same emitted code as probe 8]
probe 10 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: Recheck a natural assignment expression as the debug_srand seed, with no extra helper or alias. [same emitted code as probe 9]
probe 11 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: Move the final scan index to function scope to test original declaration order without changing behavior. [same emitted code as probe 10]
probe 12 liveness; result=MISMATCH; diff=222; shape=92.22222222222223: Test a branch-local typed player-list pointer to explain the original ECX row-base load.
probe 13 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: Test a loop-local typed player pointer, matching the binary's repeated player load before the direct call. [same emitted code as probe 11]
probe 14 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_104427: 8 variants, 8 invariant-eligible, 0 exact
probe 15 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: Test an explicit signed reread of the stored member as the debug_srand argument. [same emitted code as probe 13]
probe 16 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_104517: 512 variants, 512 invariant-eligible, 0 exact
probe 19 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_173019: 10 variants, 10 invariant-eligible, 0 exact
probe 20 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_173226: 8 variants, 6 invariant-eligible, 0 exact
probe 21 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_173249: 8 variants, 7 invariant-eligible, 0 exact
probe 22 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_173540: 48 variants, 48 invariant-eligible, 0 exact
probe 23 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_173645: 7 variants, 7 invariant-eligible, 0 exact
probe 24 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_173700: 7 variants, 7 invariant-eligible, 0 exact
probe 25 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_173801: 42 variants, 35 invariant-eligible, 0 exact
probe 26 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_173924: 5 variants, 5 invariant-eligible, 0 exact
probe 27 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_174000: 30 variants, 20 invariant-eligible, 0 exact
probe 28 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_174020: 30 variants, 20 invariant-eligible, 0 exact
probe 30 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_174651: 2 variants, 2 invariant-eligible, 0 exact
probe 31 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_174723: 3 variants, 3 invariant-eligible, 0 exact
probe 32 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_174740: 2 variants, 2 invariant-eligible, 0 exact
probe 33 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_174750: 2 variants, 2 invariant-eligible, 0 exact
probe 34 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_174801: 2 variants, 2 invariant-eligible, 0 exact
probe 35 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_174812: 2 variants, 2 invariant-eligible, 0 exact
probe 36 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_174822: 3 variants, 3 invariant-eligible, 0 exact
probe 37 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_174843: 2 variants, 2 invariant-eligible, 0 exact
probe 38 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_174854: 2 variants, 2 invariant-eligible, 0 exact
probe 39 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_174911: 2 variants, 2 invariant-eligible, 0 exact
probe 40 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_174928: 2 variants, 2 invariant-eligible, 0 exact
probe 41 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_175022: 2 variants, 2 invariant-eligible, 0 exact
probe 42 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_175031: 2 variants, 1 invariant-eligible, 0 exact
probe 43 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_175040: 2 variants, 2 invariant-eligible, 0 exact
probe 44 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260817_175049: 2 variants, 2 invariant-eligible, 0 exact
probe 46 context; result=MISMATCH; diff=221; shape=93.4065934065934: Historical World.cpp context family: repository-supported game_globals/game_types headers, period stdio/string/memory/windows/new headers and combinations, exact new_game/new_random_game neighboring declarations/macros/globals all produced duplicate 275-byte groups; no allocation or seed-store scheduling change. Supported /GX, /O1, /Og, /Ox probes likewise produced no exact lead; /O1 was a wrong 263-byte basin. [same emitted code as probe 45]
probe 48 abi; result=MISMATCH; diff=221; shape=93.4065934065934: Focused PDB-name source test: renamed seed to random_seed_in and result to retval, matching the only target parameter/local names in original CodeView. Pinned VC5 object .text and .debug were byte-identical to baseline (288-byte section, 275-byte effective function); names do not explain seed scheduling.
probe 50 abi; result=MISMATCH; diff=221; shape=93.4065934065934: Canonicalized the target-local World, Map, Player, Command, Player_Info, and Map_Gen_Info surfaces from inventory type/class evidence. Preserved struct-tag target owner and pointer-shaped virtual slot declarations where target call sites prove those slots. Rebuild retains 275-byte size, FPO, four saved registers, 12-call set, and seed value flow; first mismatch remains the known seed store/push schedule. [same emitted code as probe 49]
probe 52 abi; result=MISMATCH; diff=221; shape=93.4065934065934: Seed argument member reread after store: test explicit this->random_seed in the debug_srand expression under the canonical typed World and map-generator layout. [same emitted code as probe 51]
probe 53 abi; result=MISMATCH; diff=221; shape=93.4065934065934: Nested assignment hypothesis: preserve the input seed value while assigning the World random_seed member, then pass the assigned parameter value to debug_srand. [same emitted code as probe 52]
probe 54 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: Top-level selected seed local: test whether the PDB seed ownership is an ordinary local with a member store and debug_srand argument. [same emitted code as probe 53]
probe 55 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: Split selected seed declaration from assignment to test PDB declaration-site scheduling without changing seed behavior. [same emitted code as probe 54]
probe 56 abi; result=MISMATCH; diff=221; shape=93.4065934065934: Signed cast at the debug_srand seed argument: test whether the period debug RNG declaration uses signed int at this call while preserving the four-byte ABI. [same emitted code as probe 55]
probe 57 abi; result=MISMATCH; diff=221; shape=93.4065934065934: Assignment-expression seed argument: test whether VC5 preserves the store result as the third debug_srand argument. [same emitted code as probe 56]
probe 58 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: Parameter reuse after the member store: test whether the original keeps the selected seed in the input home before debug_srand. [same emitted code as probe 57]
probe 59 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: PDB-local scope: declare retval at function entry rather than at the branch, then restore natural parameter seed ownership and call expression. [same emitted code as probe 58]
probe 60 abi; result=MISMATCH; diff=221; shape=93.4065934065934: PDB parameter-name recovery: use random_seed_in exactly as CodeView names the int input, with retval at function scope. [same emitted code as probe 59]
probe 61 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: Loop-local declaration order: move the visible set_map_visible index to function scope, while retaining PDB-derived retval and random_seed_in names. [same emitted code as probe 60]
probe 62 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: Selected-seed ownership: keep the PDB input parameter unchanged and select into one ordinary int before the RNG fallback. [same emitted code as probe 61]
probe 63 abi; result=MISMATCH; diff=221; shape=93.4065934065934: Nested parameter/member assignment in the third RNG argument: test whether the original ECX seed copy represents a source assignment result. [same emitted code as probe 62]
probe 64 abi; result=MISMATCH; diff=221; shape=93.4065934065934: Period debug_srand prototype audit: use signed int for the third parameter, matching the old World.cpp call family while preserving the 32-bit call.
probe 65 abi; result=MISMATCH; diff=221; shape=93.4065934065934: Combine the period signed debug_srand prototype with a member-owned seed reread after assignment. [same emitted code as probe 64]
probe 66 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: Use the exact PDB local spelling retval throughout the output-result path, with random_seed_in as the parameter and the signed period RNG declaration. [same emitted code as probe 65]
probe 67 control-flow; result=MISMATCH; diff=221; shape=93.4065934065934: Comma sequencing at the seed store/call boundary: test a source-enforced store-before-debug_srand order without changing calls or behavior. [same emitted code as probe 66]
probe 69 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: PDB-compatible declaration ordering: place the loop index before retval at function entry, then use the natural seed parameter and period RNG call. [same emitted code as probe 63]
probe 70 context; result=MISMATCH; diff=221; shape=93.4065934065934: PDB class-surface context: add the exact nonvirtual World.cpp methods shown in RGE_Game_World's CodeView class field list. [same emitted code as probe 69]
probe 71 context; result=MISMATCH; diff=221; shape=93.4065934065934: Source-line context: place the member seed store and period debug_srand call on one original-style statement line. [same emitted code as probe 70]
probe 75 layout; result=MISMATCH; diff=221; shape=93.4065934065934: H1: cache this->map in a branch-local pointer before new_map; test whether receiver evaluation before cdecl cleanup matches the original early block. [same emitted code as probe 74]
probe 77 layout; result=MISMATCH; diff=221; shape=93.4065934065934: H2: bind the map receiver as a reference rather than a pointer; test whether reference ownership changes new_map receiver and argument scheduling. [same emitted code as probe 75]
probe 79 abi; result=MISMATCH; diff=221; shape=93.4065934065934: H3: model the proven random_seed dword as signed int, matching debug_srand's signed period surface; test extension and seed liveness. [same emitted code as probe 77]
probe 81 abi; result=MISMATCH; diff=221; shape=93.4065934065934: H4: model GetRandomSeed as signed int, matching the target's integer seed flow; test whether return width or signedness changes the post-call seed store/push.
probe 83 abi; result=MISMATCH; diff=221; shape=93.4065934065934: H5: widen the seed parameter to unsigned int while preserving its 32-bit ABI; test whether seed signedness changes the first post-random call schedule. [same emitted code as probe 79]
probe 85 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: H6: mark only the random_seed field volatile; test whether an observable store forces the original store-before-push ordering. [same emitted code as probe 83]
probe 87 abi; result=MISMATCH; diff=221; shape=93.4065934065934: H7: add explicit unsigned-store and signed-call casts around random_seed; test whether conversion nodes force a member reload or ECX copy. [same emitted code as probe 85]
probe 89 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: H8: materialize map width and height as short locals in declaration order before new_map; test whether distinct homes recover original EDX/EAX argument colors and receiver preload. [same emitted code as probe 87]
probe 91 liveness; result=MISMATCH; diff=210; shape=89.1304347826087: H9: keep one map pointer live across both new_map and clear_map; test whether persistent receiver liveness recovers both receiver preloads and register colors.
probe 93 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: H10: cache only the clear_map receiver after new_map; test whether a short-lived receiver local recovers the original byte-load and receiver order without changing entry liveness. [same emitted code as probe 89]
probe 95 control-flow; result=MISMATCH; diff=221; shape=93.4065934065934: H11: express the final visible-player scan as an explicit guarded do/while; test whether the original loop rotation is source-form sensitive. [same emitted code as probe 93]
probe 97 abi; result=MISMATCH; diff=221; shape=93.4065934065934: H12: remove the explicit int cast from the final player_num bound; test whether native short promotion controls the original loop compare register. [same emitted code as probe 95]
probe 98 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: H13: preserve the decompiler-supported short count local across the member store and calloc; test whether its independent home recovers the original store-before-push and EAX sequence. [same emitted code as probe 97]
probe 100 layout; result=MISMATCH; diff=221; shape=93.4065934065934: H14: model random_seed as period-style long instead of unsigned int; test whether signed long field ownership changes seed scheduling without changing the dword layout. [same emitted code as probe 98]
probe 102 context; result=MISMATCH; diff=221; shape=93.4065934065934: H15: restore the period Windows header context with windows.h; test whether SDK declarations change the VC5 scheduling basin. [same emitted code as probe 100]
probe 104 context; result=MISMATCH; diff=221; shape=93.4065934065934: H16: add string.h to the standard-header context alongside stdio and stdlib; test whether period CRT declarations alter the codegen basin. [same emitted code as probe 102]
probe 106 context; result=MISMATCH; diff=221; shape=93.4065934065934: H17: add an unused polymorphic file-scope context declaration with members; test the documented old-MSVC ambient-declaration codegen axis. [same emitted code as probe 104]
probe 108 context; result=MISMATCH; diff=221; shape=93.4065934065934: H18: use the proven absolute world_update_counter singleton form from the exact World.cpp donor; test relocation and early-byte parity.
probe 110 abi; result=MISMATCH; diff=221; shape=93.4065934065934: H19: make the new_map long promotions explicit at both arguments; test whether cast nodes alter VC5 receiver and dimension scheduling. [same emitted code as probe 106]
probe 112 abi; result=MISMATCH; diff=221; shape=93.4065934065934: H20: combine signed int surfaces for debug_srand, GetRandomSeed, and random_seed; test whether the complete period ABI combination changes the seed live range.
probe 116 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260822_125013: 6 variants, 5 invariant-eligible, 0 exact
probe 117 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: H21: apply period register storage to the mutable seed parameter; test the documented VC5 register-color axis for the first post-random call. [same emitted code as probe 116]
probe 119 context; result=MISMATCH; diff=221; shape=93.4065934065934: H22: disable inline depth only around new_scenario; test the documented VC5 inline-budget and function-context axis. [same emitted code as probe 117]
probe 121 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: H23: apply register storage to the info reference despite its later address-taking; test whether its pointer color changes the map argument schedule. [same emitted code as probe 119]
probe 123 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: H24: use a volatile reference alias for the random_seed store; test whether a forced observable store recovers the original ECX copy and store-before-push sequence. [same emitted code as probe 121]
probe 125 control-flow; result=MISMATCH; diff=221; shape=93.4065934065934: H25: fold the random_seed assignment into the debug_srand argument as a natural assignment expression; measure whether it recovers the original store-before-push topology. [same emitted code as probe 123]
probe 127 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: H26: use a block-scoped seed copy that spans the member store and debug_srand; test whether natural short-lived liveness emits the missing ECX copy. [same emitted code as probe 125]
probe 129 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: H27: chain member assignment into a named seed result before debug_srand; test whether a natural assignment-result local recovers the missing move and improves block shape. [same emitted code as probe 127]
probe 131 liveness; result=MISMATCH; diff=221; shape=93.4065934065934: H28: bind the final scan element to a natural player pointer local before set_map_visible; test whether receiver and bound registers recover the original loop block. [same emitted code as probe 129]
probe 132 variant; result=MISMATCH; diff=221; shape=93.4065934065934: variant lab build\variant_lab\00542BF0_new_scenario\20260822_125348: 10 variants, 6 invariant-eligible, 0 exact
probe 134 control-flow; result=MISMATCH; diff=226; shape=91.30434782608695: H29: combine result and positive player-count guards before the final scan; measure whether one short-circuit source guard improves CFG and exact block coverage.
probe 136 liveness; result=MISMATCH; diff=220; shape=91.20879120879121: H30: cache player_num in a branch-local short for the final scan; test whether a natural bounded count local recovers the original EDX loop bound.
probe 137 variant; result=MISMATCH; diff=220; shape=91.20879120879121: variant lab build\variant_lab\00542BF0_new_scenario\20260822_125501: 256 variants, 256 invariant-eligible, 0 exact
probe 139 variant; result=MISMATCH; diff=220; shape=91.20879120879121: variant lab build\variant_lab\00542BF0_new_scenario\20260822_125555: 2 variants, 2 invariant-eligible, 0 exact
```
<!-- end-recovered:027f214240110d7495ad -->

<!-- recovered:3d8b708e0b75e8d24d7a -->
### `de698545d3d6` `src/scratch/00542BF0_new_scenario.cpp:1-15`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00542BF0 RGE_Game_World::new_scenario (World.cpp:1478-1537)
// Shared World.cpp context reconstruction. This owner remains non-exact:
// 275 bytes, 221 differing bytes, with the first mismatch at +0x2D.
// The remaining schedule changes the proven map fault order, so this is not
// accepted drift.
// Context gate: PDB World.cpp lines 1478-1537 owns 00542BF0-00542D02.
// Exact anchors are the World vslot calls, GetRandomSeed, debug_srand, the
// map calls, calloc, and the final RGE_Player::set_map_visible loop.
// Recovery log: phase2 context, explicit this qualifiers, result and index
// scope changes, seed and map locals, terrain casts, and explicit long map
// arguments did not change the 221-byte result. The natural source is kept.
// Final validation: MISMATCH, rebuilt 273 bytes, first mismatch +0x2D.
// 2026-08-26 TU captain probe: passing random_seed, instead of seed, to
// debug_srand produced identical output. The probe was restored. The source
// spelling and the value-store/push order remain unresolved.
```
<!-- end-recovered:3d8b708e0b75e8d24d7a -->
