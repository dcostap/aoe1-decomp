# Function notes: 004C6270 `drop_held_objects`

Module notes: `decomp_notes/stat_obj_module.md`.

## Recovered attempt history

<!-- recovered:5ea549ea9d76931f2c33 -->
### `target-session` `build/target_sessions/004C6270_drop_held_objects.json:1-53`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=331; shape=71.09375: Baseline clean typed reconstruction from existing attempt log: 0xB4 frame, four calls, four float arrays, retry loop and success-block held alias.
probe 2 control-flow; result=MISMATCH; diff=331; shape=71.09375: Hypothesis: explicit initial non-null guard plus do/while outer traversal will preserve original reload-and-next split at 004C62C0/62E0. [same emitted code as probe 1]
probe 4 liveness; result=MISMATCH; diff=331; shape=71.09375: Hypothesis: period-plausible register hint on the long-lived retry index may recover original ESI allocation and saved-register order. [same emitted code as probe 2]
probe 6 layout; result=MISMATCH; diff=331; shape=71.09375: Hypothesis: canonical same-TU RGE_Static_Object field declarations, instead of gap overlays, may recover original VC5 register and load scheduling while preserving all proven offsets. [same emitted code as probe 4]
probe 8 liveness; result=MISMATCH; diff=338; shape=69.53125: Hypothesis: declaring count before retry index may reproduce the original callee-saved register colors and entry prologue.
probe 10 control-flow; result=MISMATCH; diff=331; shape=71.09375: Hypothesis: explicit positive continuation after failure-copy stores will retain the original second retry-index test and conditional backedge. [same emitted code as probe 6]
probe 12 liveness; result=MISMATCH; diff=323; shape=69.53125: Hypothesis: a natural distinct retry-index local will preserve the original loop's post-copy test and two-variable decompiler shape without padding.
probe 14 behavior; result=MISMATCH; diff=331; shape=71.875: Hypothesis: source radius updates before coordinate copies will recover the original x87 evaluation stack and delayed store order at 004C63A7.
probe 17 control-flow; result=MISMATCH; diff=326; shape=70.54263565891473: Natural outer traversal captures next once before the retry while, matching the target's 004C62C4 setup and 004C62E0 retry split while preserving typed node ownership.
probe 18 control-flow; result=MISMATCH; diff=326; shape=70.54263565891473: Natural outer while captures next once, with a guarded retry do/while retained to test whether target-style 004C62C4 setup and 004C62E0 retry layout needs the source guard. [same emitted code as probe 17]
probe 19 liveness; result=MISMATCH; diff=427; shape=54.48275862068966: Natural running radius cursors now own the retry shifts, matching the target's EBP/EDI cursor evidence without raw cursor plumbing or untyped object access.
probe 21 layout; result=MISMATCH; diff=331; shape=71.09375: Canonical typed RGE_Object_List::list and RGE_Object_Node::node ownership names replace local aliases while retaining the proven +4 links and natural held-object release traversal. [same emitted code as probe 16]
probe 22 liveness; result=MISMATCH; diff=326; shape=60.15625: Move traversal next into the outer-loop block while retaining typed node and object ownership; this tests natural local lifetime and compiler home reuse without raw array aliases.
probe 24 control-flow; result=MISMATCH; diff=326; shape=70.54263565891473: Natural typed traversal captures each node's next link once before the retry while, matching the original's separate outer setup and retry blocks; canonical list/node ownership remains explicit. [same emitted code as probe 18]
probe 25 liveness; result=MISMATCH; diff=339; shape=58.59375: Typed running radius pointers are tested with a simple outer next capture and retry while, avoiding raw address arithmetic while probing the original EBP/EDI cursor allocation.
probe 28 control-flow; result=MISMATCH; diff=326; shape=71.31782945736434: Natural outer next capture and inner while combined with radius-before-coordinate success updates; test target's explicit retry CFG and x87 order.
probe 30 liveness; result=MISMATCH; diff=322; shape=60.15625: Separate natural next-node local from the contiguous DropLocals aggregate; test whether target's durable next home at entry -0xA4 comes from declaration scope.
probe 32 layout; result=MISMATCH; diff=322; shape=66.40625: Reorder the proven next pointer immediately before the four contiguous float arrays, matching original entry-relative next/array adjacency; retain natural aggregate ownership.
probe 35 control-flow; result=MISMATCH; diff=387; shape=54.01459854014598: Compile corrected pointer-bit alias spelling for the nested decompiler-shaped loop probe; this is the same hypothesis.
probe 37 layout; result=MISMATCH; diff=322; shape=66.40625: Move the natural next-node field immediately before the four contiguous float arrays, matching the target's proven next home followed by array bases; retain baseline loop and aliases. [same emitted code as probe 32]
probe 38 behavior; result=MISMATCH; diff=322; shape=64.0625: Test binary-backed output alias surfaces in the best next-before-arrays layout: find writes y and next, then teleport and history use those bits.
probe 39 context; result=MISMATCH; diff=322; shape=64.0625: Test period donor declaration context: canonical stat_obj master and static-object virtual/field surfaces at proven offsets, while retaining the best natural next-array layout and loop.
probe 40 abi; result=MISMATCH; diff=322; shape=64.0625: Correct canonical static-object slot ownership: exit_obj is the proven +0xD4 virtual target; remove the extra post-passable release declaration. [same emitted code as probe 38]
probe 41 liveness; result=MISMATCH; diff=351; shape=48.4375: Test binary-supported running radius cursors and a retry-index lifetime matching target EBP/EDI pointer decrements and decompiler variable topology; keep typed ownership.
probe 42 liveness; result=MISMATCH; diff=322; shape=64.0625: Test natural declaration order with the aggregate local before index, then count, against the target's decompiler local ordering and callee-saved color split. [same emitted code as probe 40]
probe 43 liveness; result=MISMATCH; diff=351; shape=53.73134328358209: Remove the extra retry-index local from the cursor model, leaving only the two proven running radius pointers and one shared index.
probe 44 control-flow; result=MISMATCH; diff=325; shape=62.5: Test a distinct retry-index local to preserve the target's redundant post-copy positive test and conditional backedge without opaque padding.
probe 45 control-flow; result=MISMATCH; diff=322; shape=64.0625: Test an explicit positive continuation after failure-copy stores to preserve the target's second test and conditional retry edge. [same emitted code as probe 42]
probe 46 layout; result=MISMATCH; diff=304; shape=67.96875: Test the simplest separate local recovery from Ghidra's proven order: current node, y, output-next, then four arrays, with node-next advanced before retry.
probe 47 liveness; result=MISMATCH; diff=285; shape=77.34375: Replace the node alias with a distinct natural next-node local, letting VC5 reuse the unused first float-array slot while preserving current-node ownership across retries.
probe 48 layout; result=MISMATCH; diff=277; shape=82.03125: Diagnostic test of the binary-proven next-node/drop_y[0] home overlap without a separate next-node local; use only to identify the source basin.
probe 49 liveness; result=MISMATCH; diff=314; shape=64.92537313432835: With the proven local overlap basin, add only natural radius cursors to target EBP/EDI pointer ownership and failure-copy topology.
probe 50 liveness; result=MISMATCH; diff=277; shape=82.03125: Test the proven decompiler x local as a declaration-only natural variable, checking whether VC5 restores the target 0xB4 frame without metric-only padding. [same emitted code as probe 48]
probe 51 layout; result=MISMATCH; diff=310; shape=76.5625: Reorder failure-copy assignments to the decompiler-supported drop_x, radius_y, drop_y, radius_x source order, testing target EBP/EDI cursor selection.
probe 52 liveness; result=MISMATCH; diff=277; shape=82.03125: Swap natural output-local declaration order so next occupies the target +0xC home and y the target +0x8 home, matching call pointer and teleport operand order. [same emitted code as probe 50]
probe 53 liveness; result=MISMATCH; diff=287; shape=71.31782945736434: With direct proven next-node overlap, test one natural running radius-y cursor to recover target EBP ownership without the two-cursor frame spill.
probe 54 control-flow; result=MISMATCH; diff=255; shape=65.625: Test the binary-supported nested outer cursor/retry do-loop topology from Ghidra, using the proven drop_y[0] next-node overlap and no extra node alias.
probe 59 control-flow; result=MISMATCH; diff=277; shape=82.03125: Tested an explicit positive continuation after failure-copy stores to preserve the target's redundant post-copy test and retry edge; retained pointer-home diagnostic basin only for comparison. [same emitted code as probe 56]
probe 60 behavior; result=MISMATCH; diff=285; shape=77.34375: Restored distinct typed x/y outputs and direct next local. This removes the rejected pointer-home overlay while preserving held-object traversal and coordinate argument order. [same emitted code as probe 57]
probe 61 control-flow; result=MISMATCH; diff=285; shape=77.34375: Tested a natural-looking redundant positive continuation after failure-copy stores with distinct x/y and next locals; check whether VC5 preserves the shipped post-copy test. [same emitted code as probe 60]
probe 62 control-flow; result=MISMATCH; diff=418; shape=54.54545454545455: Reshaped the retry as a positive outer guard around a do-while, matching the target's separate entry guard, post-failure guard, and bottom retry test without a compiler-only construct.
probe 63 control-flow; result=MISMATCH; diff=285; shape=77.34375: Tested a pretested while retry loop with direct typed outputs; this is the alternate natural loop basin for the target's separate entry and backedge tests. [same emitted code as probe 61]
probe 64 layout; result=MISMATCH; diff=365; shape=60.9375: Tested a real local aggregate for the four proven contiguous float arrays, preserving separate typed x/y and node locals. This checks whether aggregate ownership restores the target array window without overlays.
probe 65 layout; result=MISMATCH; diff=285; shape=77.34375: Reordered only natural local declarations so the four arrays precede next and x/y. This tests the proven contiguous array-window placement without changing behavior or ABI. [same emitted code as probe 63]
probe 66 liveness; result=MISMATCH; diff=285; shape=77.34375: Matched the decompiler's proven scalar declaration order temp, x, y, next before the four arrays. This tests VC5 lifetime and register colors while keeping typed locals. [same emitted code as probe 65]
probe 67 layout; result=MISMATCH; diff=285; shape=77.34375: Swapped only the two first array declarations. The target contiguous window reads drop_y then radius_x, while the current natural basin allocated radius_x then drop_y. [same emitted code as probe 66]
probe 68 layout; result=MISMATCH; diff=277; shape=82.03125: Tested a real typed union for the binary-proven drop_y[0]/next overlap, removing the separate next declaration. This avoids a pointer cast while modeling the observed shared home. [same emitted code as probe 59]
probe 69 liveness; result=MISMATCH; diff=277; shape=82.03125: Promoted the natural success index to function scope and reused it for the array update, testing whether its lifetime supplies the target frame and callee-saved color without changing behavior. [same emitted code as probe 68]
probe 70 layout; result=MISMATCH; diff=285; shape=77.34375: Restored separate typed next and four arrays, then ordered initial assignments as drop_x, drop_y, radius_x, radius_y from the decompiler's source-order evidence. [same emitted code as probe 67]
probe 71 liveness; result=MISMATCH; diff=307; shape=67.6923076923077: Tested natural running radius cursors with proven pointer decrement and current-radius rereads, aiming to recover target EBP/EDI ownership and the retry copy order.
probe 72 control-flow; result=MISMATCH; diff=418; shape=54.54545454545455: Tested explicit binary-supported retry and shared finish labels to preserve the target's separate post-copy positive test and common outer continuation. [same emitted code as probe 62]
probe 73 liveness; result=MISMATCH; diff=285; shape=77.34375: Tested a natural self pointer alias to see whether the target EBX this allocation is source-lifetime driven; loop and typed array semantics are otherwise restored. [same emitted code as probe 70]
probe 74 liveness; result=MISMATCH; diff=285; shape=77.34375: Tested a period-valid register-qualified self alias for the this receiver, checking whether VC5 preserves target EBX ownership instead of EBP. [same emitted code as probe 73]
```
<!-- end-recovered:5ea549ea9d76931f2c33 -->

<!-- recovered:44a0f0ea1c810aac76d7 -->
### `056a20c24f68` `src/scratch/004C6270_drop_held_objects.cpp:1-75`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C6270 RGE_Static_Object::drop_held_objects
// Source: stat_obj.cpp lines 3818-3875
// Attempt log:
// - the binary-backed local frame is 0xB4 with four contiguous float arrays,
//   an address-taken x/y pair, next/temp nodes, and a byte count; typed
//   DropLocals preserves those proven offsets and the complete four-call set;
// - self-alias removal was codegen-neutral; separate scalar/array locals
//   regressed the frame to 0xB8 and were rolled back;
// - changing the retry loop to while removed an emitted duplicate
//   find_drop_location call, and moving next-node reload into the retry loop
//   improved the diagnostic diff, but broad this/index/register and CFG drift
//   remains;
// - prior validated candidate: 350 rebuilt bytes versus 387 original,
//   64.06% instruction-shape similarity, four ordered calls. Left in scratch
//   after the bounded pass; next lead is recovering natural source lifetimes
//   that reproduce the proven overlapping stack homes without opaque padding.
// - current pass: direct node-object rereads at find_drop_location with a
//   success-block held alias improved the candidate to 336 differing bytes,
//   65.62% shape, 0xB4 frame, and four ordered calls; this remains natural
//   typed source but still selects EBP for this and EDI for the retry index.
// - removing register from the index and changing the outer traversal to a
//   pretested while were codegen duplicates; retain the success-block alias
//   candidate as the best source reconstruction for this pause.
// - moving next-node capture outside the retry loop followed the 004C62C4 /
//   004C62E0 split but worsened the rebuilt size and resync diff; rolled back.
// - moving list-head capture between world_x and world_y setup also worsened
//   the initial schedule; rolled back.
// - scoped running radius pointers produced a 0xB8 frame and broad drift;
//   rolled back because the original pointer-like EBP/EDI evidence is not a
//   natural fit for this aggregate source.
// - moving next after the four float arrays reproduced the original array
//   stack homes, raised shape similarity to 71.09%, and reduced the strict
//   diff to 331 bytes with the 0xB4 frame; keep this typed layout candidate.
// - reordering radius_x before world_y and the failure-copy radius stores
//   preserved that best 331-byte result; register and CFG drift remain.
// - current assigned pass: baseline rebuilt 365 bytes versus 387 original,
//   strict diff 331 bytes, 71.09% shape, 0xB4 frame, and four aligned calls;
//   the original saves EBX/ESI while this source saves EBP/EDI. Explicit
//   outer do/while structure, register index hints, canonical full fields,
//   and an explicit continuation were codegen duplicates. Declaring count
//   before i worsened the diff to 338 bytes. A distinct retry index reduced
//   the strict diff to 323 bytes but produced a 390-byte, 69.53% shape
//   variant with LEA instead of the original DEC, so it was rejected.
//   Reordering success radius stores kept the 331-byte strict diff but made
//   the diagnostic resynchronization worse; the baseline remains authoritative.
// - revisit: canonical typed list/node member names were codegen-neutral. A
//   natural outer traversal that captures next once before the retry loop
//   followed the original 004C62C4/004C62E0 split and reduced strict diff to
//   326 bytes, but made size and resynchronization worse; the pinned baseline
//   remains authoritative. Block-local next shifted the proven array homes.
//   Typed running radius pointers raised the frame to 0xB8 and were rejected.
// - revisit: an outer next capture with an inner while and radius-before-
//   coordinate success updates reduced the strict diff to 326 bytes and raised
//   shape to 71.32%, but shortened the body to 355 bytes and worsened resync;
//   rolled back. A separate next local reduced the diff to 322 bytes but fell
//   to 60.16% shape. Moving next before the arrays kept 322 bytes but only
//   66.41% shape. Both natural layout probes were rolled back.
// - fresh pass: canonical stat_obj master/object declarations and the proven
//   exit_obj +0xD4 slot were restored. Separate scalar locals for temp, y,
//   next, and the four arrays reached a 304-byte diff, 67.97% shape, and an
//   exact 0xB4 frame. Reusing the proven drop_y[0] stack home for the next
//   node restored EBX/ESI, 82.03% shape, 81.65% resync similarity, and a
//   277-byte diff; the frame is 0xB0 and the source uses a narrow pointer
//   overlay. Natural next-node locals reached 285 bytes, 77.34% shape, and
//   0xB4, but kept EBP for this. Running cursors, nested do loops, and retry
//   index variants were rejected for frame, call, or shape drift. Final
//   validation: 384 rebuilt bytes versus 387, four ordered calls, mismatch.
// - resumed exact-finish pass: the distinct typed x/y/next source is the
//   clean natural baseline at 386 bytes, 0xB4, and four ordered calls, with
//   a 285-byte mismatch. Real array aggregates, a typed drop_y/next union,
//   running radius cursors, goto retry labels, declaration reorders, and a
//   register-qualified self alias were tested and rejected. The union
//   reproduced the prior 384-byte, 277-byte diagnostic basin but still used
//   an unsupported local overlap. No exact result was found; keep the
//   separate typed source and do not claim the pointer-overlap candidate.
```
<!-- end-recovered:44a0f0ea1c810aac76d7 -->
