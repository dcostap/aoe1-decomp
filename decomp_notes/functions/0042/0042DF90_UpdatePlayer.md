# Function notes: 0042DF90 `UpdatePlayer`

Module notes: `decomp_notes/com_hand_module.md`.

## Recovered attempt history

<!-- recovered:d10670b863da97cccbce -->
### `target-session` `build/target_sessions/0042DF90_UpdatePlayer.json:1-30`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=854; shape=64.44444444444444: Baseline current canonical typed reconstruction before new work; establishes emitted call map, frame, switch topology, and exactness metrics.
probe 2 layout; result=MISMATCH; diff=856; shape=67.51592356687898: Hypothesis 1: use the packet's proven PlayerID/size dword as the DirectPlay size output, instead of a separate size local. Original passes the local packet window at +4 and later reuses it for the missing-player report.
probe 3 liveness; result=MISMATCH; diff=856; shape=67.51592356687898: Hypothesis 2: declare the address-taken packet before the heap pointer. Original stack evidence places the packet and lpData in a different fixed window; declaration order may recover the VC5 local allocation. [same emitted code as probe 2]
probe 4 control-flow; result=MISMATCH; diff=835; shape=66.11295681063123: Hypothesis 3: restore the source decision tree with explicit fatal and unknown labels. The original branches share one early fatal block, while unknown failure, success, and invalid-player blocks follow distinct emitted arms.
probe 5 control-flow; result=MISMATCH; diff=835; shape=66.11295681063123: Hypothesis 4: move the zero-dcoID log to a late label and branch forward to it. Original tests zero with JE to a cold no-name block after release paths; the prior early-return source inverted that layout.
probe 6 control-flow; result=MISMATCH; diff=774; shape=70.80536912751678: Hypothesis 5: express the nonzero-dcoID path as the positive guarded body, with the zero-dcoID log as the fall-through arm. This tests whether VC5 selects the original fall-through main path and late zero-name block.
probe 7 abi; result=MISMATCH; diff=774; shape=70.80536912751678: Hypothesis 6: pass the DirectPlay size pointer as the packet base, not its PlayerID field. Original zeroes and rereads the packet's first dword, then later overwrites its command byte while sending the same packet.
probe 8 liveness; result=MISMATCH; diff=907; shape=48.36601307189542: Hypothesis 7: preserve the player index in a register local while intentionally reusing the incoming player home as DirectPlay's size output. Original EBP carries the index while the entry player home is zeroed, read for calloc, and passed again.
probe 9 liveness; result=MISMATCH; diff=907; shape=48.36601307189542: Hypothesis 8: use a register-qualified saved index while reusing the parameter home for the DirectPlay size output. This tests whether VC5 keeps the original EBP index color instead of allocating the prior local frame. [same emitted code as probe 8]
probe 10 layout; result=MISMATCH; diff=713; shape=66.44067796610169: Hypothesis 9: restore a distinct DirectPlay size local while retaining the corrected positive nonzero-dcoID branch and fatal/unknown decision tree. This separates local-home effects from branch-topology effects.
probe 11 abi; result=MISMATCH; diff=936; shape=60.96774193548387: Hypothesis 11: intentionally reuse the player parameter itself as the DirectPlay size output and continue to use that source name. This tests the old compiler's register/home treatment against the proven EBP index and parameter-home write.
probe 12 control-flow; result=MISMATCH; diff=713; shape=66.44067796610169: Hypothesis 12: place the unknown-result block before the fatal block in source order. Original fallthrough after all HRESULT comparisons reaches unknown first, then success and invalid blocks, with fatal physically later. [same emitted code as probe 10]
probe 13 control-flow; result=MISMATCH; diff=716; shape=42.758620689655174: Hypothesis 13: spell the low HRESULT arm as two direct equality guards to the shared fatal label, then an unknown fallthrough. This should select the original JE-fatal, JE-fatal, JMP-unknown sequence.
probe 14 control-flow; result=MISMATCH; diff=815; shape=59.036144578313255: Hypothesis 14: duplicate the small fatal-result source arm in both low and high HRESULT branches. VC5 may tail-merge the proven shared fatal body while placing unknown, success, and invalid blocks in original order.
probe 15 control-flow; result=MISMATCH; diff=829; shape=63.728813559322035: Hypothesis 15: model computer and closed as one shared log tail with a branch-local format pointer. Original pushes each format immediate, then shares one global-log load, call, and cleanup block.
probe 16 control-flow; result=MISMATCH; diff=713; shape=66.44067796610169: Hypothesis 16: express the HRESULT handling as one nested if/else-if chain. The original decompiler and PDB bands show a signed low arm followed by high-code, invalid-player, success, and unknown arms.
probe 17 control-flow; result=MISMATCH; diff=771; shape=61.51419558359621: Hypothesis 17: inline the low-arm unknown-result body, leaving the high-arm fallback label. This tests whether a source fallthrough block recovers the original unknown, success, invalid, then fatal layout through VC5 tail merging.
probe 18 liveness; result=MISMATCH; diff=713; shape=66.44067796610169: Hypothesis 18: name the returned DirectPlay record in the success arm. The original copy loop loads the source field and zeroes the scan count in a specific order; a typed local may recover that schedule. [same emitted code as probe 16]
probe 19 liveness; result=MISMATCH; diff=713; shape=66.44067796610169: Hypothesis 19: declare the DirectPlay size local before lpData and the packet. The original stack map assigns size, heap pointer, and packet to distinct homes; declaration order may select the VC5 layout. [same emitted code as probe 18]
probe 20 abi; result=MISMATCH; diff=713; shape=66.44067796610169: Hypothesis 20: type the DirectPlay player ID as unsigned, matching the API's unsigned player identifier and the proven dcoID table width. This tests signedness effects without changing ownership or control flow. [same emitted code as probe 19]
probe 21 liveness; result=MISMATCH; diff=936; shape=60.96774193548387: Hypothesis 21: create the parameter-home size pointer only inside the nonzero-dcoID block. This tests whether late address-taking preserves the original prologue index register while still emitting the home write.
probe 23 abi; result=MISMATCH; diff=892; shape=47.17607973421927: Hypothesis 1: preserve the original player index in a natural local, then reuse the incoming player home as DirectPlay's size output. This tests the proven size-home reuse with current typed control flow.
probe 25 liveness; result=MISMATCH; diff=907; shape=48.36601307189542: Hypothesis 2: qualify the preserved player index as register while reusing the parameter home for DirectPlay size. This tests whether VC5 keeps the proven EBP index without a separate stack home.
probe 28 liveness; result=MISMATCH; diff=944; shape=49.354838709677416: Hypothesis 3: place the register-preserved player index after packet and data declarations, while reusing player as the size output. This tests declaration-order control of the frame and EBP color.
probe 30 liveness; result=MISMATCH; diff=713; shape=66.44067796610169: Hypothesis 4: declare the natural DirectPlay size local only inside the positive dcoID block. This tests whether late address-taking lets VC5 reuse the incoming player home while preserving the parameter index.
probe 32 control-flow; result=MISMATCH; diff=829; shape=63.728813559322035: Hypothesis 5: share the computer and closed log call through a register local format. Original assembly pushes each format before a common L load and call, so this tests a natural shared tail without a stack format home.
probe 34 control-flow; result=MISMATCH; diff=710; shape=57.333333333333336: Hypothesis 6: make unknown, success, invalid, and fatal outcomes explicit ordered labels, with direct free calls in each body. The original physical blocks and four free sites follow this order.
probe 36 control-flow; result=MISMATCH; diff=717; shape=53.666666666666664: Hypothesis 7: keep success as the fall-through result of a nested nonzero guard, while routing invalid and fatal outcomes to labeled bodies. This tests whether the original zero-test success block is laid before the invalid block.
probe 39 abi; result=MISMATCH; diff=946; shape=44.69453376205788: Hypothesis 8: copy player to a register local after the initial dcoID load, use player for the switch, then reuse player as size. This mirrors the decompiler's uVar7-before-param-home overwrite order.
probe 41 liveness; result=MISMATCH; diff=944; shape=43.13099041533546: Hypothesis 9: preserve player_index as a normal local after loading dcoID, then overwrite player for the size output. This tests the decompiler order without register qualification.
```
<!-- end-recovered:d10670b863da97cccbce -->

<!-- recovered:f675e1ae99b709c1d7e9 -->
### `912332e8f578` `src/scratch/0042DF90_UpdatePlayer.cpp:1-64`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0042DF90 TCommunications_Handler::UpdatePlayer
// Com_hand.cpp lines 6001-6188
// Attempt log:
// try 1-10 (prior worker): broad decompiler-shaped reconstruction reached exact
// size but used placeholder log/error/chat/update call surfaces; switch topology,
// DirectPlay name record, and packet locals remained broadly unresolved.
// baseline (sa-ab44abb9-r1): canonicalized the player-option arrays and the
// period DirectPlay/name-record ownership; current mismatch is structural.
// probe 2: replaced placeholder log/error/chat/update calls with the exact
// TDebuggingLog, RGE_Comm_Error, FastSend, and NotifyWindow member surfaces;
// ordered call targets aligned, but the extra preserved-index/local basin made
// the frame and switch prologue worse.
// probes 3-8: tested delayed/register-qualified player-index lifetimes, a flat
// offset overlay, static Log syntax, and parameter-home reuse.  The separate
// natural size local gave the best early structural basin; parameter reuse with
// an index alias regressed the frame and was rolled back.
// probe 9: rewrote the HRESULT handling as the binary-backed signed nested
// decision tree (fatal low/high arms, invalid-player arm, success, unknown).
// This improved shape to 54.55% and edit similarity to 53.62%; direct free is
// still compiler-tail-merged (1 rebuilt site versus 4 original sites).
// probe 10: restored canonical nested COMMPLAYEROPTIONS ownership after the
// flat overlay diagnostic; emitted code was unchanged.
// probe 11: reordered the switch cases toward the original handler order;
// call-site alignment improved to 86.36%, but size grew by 36 bytes and the
// positional diff worsened, so restored the clean case order.
// probe 14 baseline: current canonical source measured diff 895, frame 0x10
// versus 0xC, and one rebuilt free versus four original free sites.
// probe 15: one natural release tail reached exact size and diff 874; it still
// merged all free calls and left the switch handler layout unresolved.
// probe 16: direct free/update returns raised size to 1000 and worsened diff;
// rolled back.
// probe 17: PDB-backed switch order 0,3,2,4,5,6,1 improved diff to 854 and
// shape to 64.44%, but expanded to five free calls and 1044 bytes.
// probes 18-19: split and then fall-through release labels; emitted code stayed
// at diff 850, with five free calls, so retained the simpler single-tail form.
// probe 20: reused the incoming player home for DirectPlay size with a saved
// index local; frame grew to 0x14 and diff regressed to 937, so rolled back.
// left in scratch: canonical typed behavior/call surface is reconstructed, but
// the VC5 frame/parameter-home reuse, switch handler placement, and four
// distinct free call sites remain structurally unresolved.
//
// current claim (sa-0a2444f7-r1): probes 1-21 tested local ownership, packet
// size-home use, guard polarity, HRESULT topology, case tails, copy locals,
// declaration order, and dcoID signedness.  The best clean source is the
// current typed form: size is a distinct local, the nonzero dcoID body is the
// positive arm, and fatal/unknown results use shared labels.
// BINARY NOTE: the original first GetPlayerName size pointer is the incoming
// player home ([entry ESP+4]); EBP still carries the player index.  Direct
// parameter-home reuse variants grew or changed the frame and were discarded.
// BINARY NOTE: the original no-dcoID test jumps forward to a cold log block;
// the positive guarded body recovers that branch polarity and keeps the tail
// close, but the VC5 local frame and HRESULT block order remain unresolved.
// Best final check: 968-byte rebuilt span, frame 0x10 versus 0xC, 713 strict
// differing bytes, 66.44% shape, 95.45% ordered-call alignment.
// Next leads: recover the parameter-home/index color without an extra local;
// then recover delayed cdecl cleanup and unknown/success/invalid/fatal block
// order.  Do not keep the parameter-alias experiments without a clean frame.
//
// current claim (sa-739dc223-r1): tested nine additional source hypotheses.
// Parameter-home reuse with explicit index locals made 0x14 frames and large
// structural regressions.  A block-scoped size local stayed in the same basin.
// A register format tail for COMPUTER/CLOSED also regressed the shape.  Four
// explicit result frees improved the raw diff to 710, but changed the CFG and
// was not retained.  The clean source below remains the best natural model.
```
<!-- end-recovered:f675e1ae99b709c1d7e9 -->
