# Function notes: 005346F0 `CreateBlitQueue`

Module notes: `decomp_notes/view_module.md`.

## Recovered attempt history

<!-- recovered:cead0cd6d0d11c9a3e6c -->
### `target-session` `build/target_sessions/005346F0_CreateBlitQueue.json:1-35`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=671; shape=61.440677966101696: Baseline current clean source before new probes; establish exactness, frame, calls, and mismatch.
probe 2 control-flow; result=MISMATCH; diff=718; shape=57.02127659574468: Hypothesis 1: restore decompiler-shaped local declaration and control-flow order, with explicit outside marker and distinct count, to recover original local pressure and branch layout.
probe 3 liveness; result=MISMATCH; diff=697; shape=59.57446808510638: Hypothesis 2: change the outside flag to a dword and retain a parameter-4 yd alias for the entry guard, targeting the original dword marker store and EBP parameter color.
probe 4 layout; result=MISMATCH; diff=664; shape=61.702127659574465: Hypothesis 3: use one natural aggregate assignment for the working RECT instead of four field assignments, testing whether VC5 preserves the original four-load initialization and local-frame ownership.
probe 6 liveness; result=MISMATCH; diff=674; shape=63.983050847457626: Hypothesis 4: preserve a function-scope RECT with aggregate assignment only in the overlap arm, leaving outside-path RECT slots dead as the original stack reads suggest.
probe 8 liveness; result=MISMATCH; diff=742; shape=52.765957446808514: Hypothesis 5: preload four source RECT bounds into distinct named locals before the overlap guard, extending their lifetimes to explain the oracle's four saved boundary slots.
probe 10 layout; result=MISMATCH; diff=671; shape=61.440677966101696: Hypothesis 6: initialize the function-scope working RECT from the source RECT at declaration, testing whether VC5 reserves the oracle's full 16-byte stack window. [same emitted code as probe 1]
probe 12 behavior; result=MISMATCH; diff=715; shape=59.07172995780591: Hypothesis 7: express absolute deltas with conditional operators rather than mutable locals, testing the oracle's test/move/neg scheduling and signed divisor homes.
probe 14 liveness; result=MISMATCH; diff=671; shape=61.440677966101696: Hypothesis 8: reverse declaration and zero-initialization order of the horizontal delta and vertical delta locals, testing the oracle's adjacent zero-store schedule.
probe 15 behavior; result=MISMATCH; diff=671; shape=62.28813559322034: Hypothesis 9: reverse the first two overlap predicates to source-left greater-than form, matching the oracle's cmp source-bound,destination-bound / jg encoding and testing source operand order.
probe 17 liveness; result=MISMATCH; diff=671; shape=61.440677966101696: Hypothesis 10: use the local yd alias for every vertical-delta use, extending its live range and testing whether the oracle's EBP parameter color and stack stores follow. [same emitted code as probe 10]
probe 19 layout; result=MISMATCH; diff=671; shape=61.440677966101696: Hypothesis 11: keep a typed pointer alias to the local RECT for all working-field accesses, testing whether a proven 16-byte local object forces the oracle's larger stack frame. [same emitted code as probe 17]
probe 21 layout; result=MISMATCH; diff=674; shape=64.83050847457628: Hypothesis 12: replace the working RECT aggregate with three scalar coordinate locals plus the existing bottom local, testing whether the oracle stack window is scalar-lifetime driven.
probe 23 layout; result=MISMATCH; diff=719; shape=47.3469387755102: Hypothesis 13: express queue writes through a typed Blit_Queue_Entry cursor and post-increment, testing whether VC5 recovers the proven 0x20 stride without raw byte offsets.
probe 25 abi; result=MISMATCH; diff=671; shape=61.440677966101696: Hypothesis 14: name the old queue pointer before the free call, testing whether explicit ownership and post-call parameter reloads recover the oracle call-setup schedule. [same emitted code as probe 19]
probe 27 behavior; result=MISMATCH; diff=728; shape=60.0: Hypothesis 15: expand the outside one-entry aggregate copies into eight explicit field stores, testing source assignment order and the oracle's queue-copy register schedule.
probe 29 abi; result=MISMATCH; diff=671; shape=61.440677966101696: Hypothesis 16: hold calloc's return in a typed new_queue local, then assign capacity before the queue field, matching the original decompiler's allocation ownership order. [same emitted code as probe 25]
probe 31 behavior; result=MISMATCH; diff=668; shape=62.71186440677966: Hypothesis 17: write the queue-capacity guard as vBlits greater-than allocated, matching the oracle's vBlits-left cmp/jle operand order.
probe 33 control-flow; result=MISMATCH; diff=710; shape=62.0253164556962: Hypothesis 18: remove dead working-RECT assignments from the outside-overlap arm, so all four failure edges join at the original common marker block.
probe 35 liveness; result=MISMATCH; diff=671; shape=61.440677966101696: Hypothesis 19: declare and initialize the yd alias before all other locals, testing whether source declaration order selects the oracle's early EBP parameter load. [same emitted code as probe 29]
probe 38 layout; result=MISMATCH; diff=671; shape=61.440677966101696: Hypothesis 1 (compiled): recover the PDB local-home roles by using One_Blit as the outside marker, nBlits as the final count, and vBlits as the vertical temporary. [same emitted code as probe 37]
probe 39 layout; result=MISMATCH; diff=670; shape=61.702127659574465: Hypothesis 2: match the PDB's yd/nBlits aliased local home by mutating one yd local for absolute y and using an unnamed register temporary for absolute x.
probe 40 liveness; result=MISMATCH; diff=664; shape=68.93617021276596: Hypothesis 3: reuse the final nBlits local as the absolute-y denominator before its later 9999/count assignment, testing the PDB yd/nBlits shared home as a real source lifetime.
probe 41 liveness; result=MISMATCH; diff=664; shape=68.93617021276596: Hypothesis 4: use the PDB-proven blt_deltaX and blt_deltaY homes for horizontal and vertical motion, removing the decompiler-only local_24 role. [same emitted code as probe 40]
probe 42 control-flow; result=MISMATCH; diff=720; shape=61.86440677966102: Hypothesis 5: remove the outside-arm writes to the working RECT because the original common outside block loads dead RECT/local slots and later copies source rectangles directly.
probe 43 layout; result=MISMATCH; diff=664; shape=68.93617021276596: Hypothesis 6: move the PDB-proven outside marker declaration before the delta locals, testing whether its live range recovers the original marker/delta stack-slot order. [same emitted code as probe 41]
probe 44 liveness; result=MISMATCH; diff=664; shape=68.93617021276596: Hypothesis 7: restore the PDB-named yd local before the outer guard, while keeping nBlits as the reused absolute-y/count home. [same emitted code as probe 43]
probe 45 behavior; result=MISMATCH; diff=664; shape=69.7872340425532: Hypothesis 8: express the first two overlap failures with source-bound greater-than comparisons, matching the original cmp/jg operand order.
probe 46 layout; result=MISMATCH; diff=664; shape=69.7872340425532: Hypothesis 9: model the four proven early boundary spill values as one local bounds RECT, then use its fields in the two delta-adjustment arms. [same emitted code as probe 45]
probe 47 context; result=MISMATCH; diff=710; shape=68.51063829787235: Hypothesis 10: restore the period SDK tagRECT/windows context instead of a private RECT clone, testing the original view.cpp header basin.
probe 48 liveness; result=MISMATCH; diff=664; shape=69.7872340425532: Hypothesis 11: swap the two independent marker/vertical-delta source roles to test whether the original lower marker home is allocator-driven rather than declaration-driven. [same emitted code as probe 46]
probe 49 liveness; result=MISMATCH; diff=664; shape=69.7872340425532: Hypothesis 12: initialize the PDB-named One_Blit marker at declaration rather than as a later assignment, testing its early stack-home lifetime. [same emitted code as probe 48]
probe 50 behavior; result=MISMATCH; diff=665; shape=70.63829787234043: Hypothesis 13: write the capacity guard as nBlits greater-than allocated, matching the original cmp nBlits,allocated / jle lowering.
probe 51 behavior; result=MISMATCH; diff=672; shape=68.4873949579832: Hypothesis 14: reverse the allocation-branch source stores so capacity precedes the queue pointer, matching the original post-calloc store order.
probe 52 abi; result=MISMATCH; diff=665; shape=70.63829787234043: Hypothesis 15: retain calloc's return in a typed new_queue local, then assign capacity before the queue field to model the original post-call ownership order. [same emitted code as probe 50]
```
<!-- end-recovered:cead0cd6d0d11c9a3e6c -->

<!-- recovered:6fbe6fdad392818c8a05 -->
### `056a20c24f68` `src/scratch/005346F0_CreateBlitQueue.cpp:1-61`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 005346F0 RGE_View::CreateBlitQueue
// Attempt log:
// v1 natural RECT/queue implementation with duplicated one-blit tail: compiled 780B but 94.49% positional, stack 0x14 not original 0x34.
// v2 single allocation/fill tail, top locals mirror packet names: undersized 736B under /O2, so tail sharing got closer structurally but not size.
// v3 /GX with v2: no change, still 736B; rolled back flag because no EH evidence.
// v4 /Od with v2: 780B same size but EBP-frame /Od family, 95.00% positional; rolled back flag.
// v5 kept v2 because it is cleaner and documents likely intended source, but it is not accepted-drift-safe.
// probe 6 structural/layout: restored the period TPanel render_rect at +8c/+90
// and the RGE_View queue-offset fields at +2ec/+2f0; the prior flat class put
// the panel rectangle at the wrong offsets and compiled the final assignments
// away.  The binary proves the final source is render_rect.left/top -> offsets.
// probe 7: a local yd initialized from param_4 was codegen-duplicate; retained
// only as the binary-supported vertical-delta naming clue.
// probe 8: a fixed-stride long* source-entry cursor moved to 0x2c frame / 783B
// and improved shape; direct byte-offset destination stores retained the
// original repeated queue-base reload schedule.
// probe 9: count=vBlits before off=0 reached 781B / 0x2c frame and improved
// resync; the loop counter stayed in the incoming dst-reference home.
// probe 10: hoisting count into an outer non-outside guard was one byte worse
// and lost an exact block; rolled back to probe 9.
// probe 12: removing the local yd copy and using the typed param_4 directly
// left the first hunk and all metrics unchanged; restored the clean source.
// probe 14: swapped loop counter initialization; output grew to 783B and was rolled back.
// probe 15: inlined boundary loads into the overlap predicate; VC5 emitted duplicate code.
// probe 16: used the binary's outside-marker slot directly; duplicate code.
// probe 18: boundary declaration order was duplicate; probe 19 sentinel order was worse and rolled back.
// probe 22: initialized the outside one-blit RECT from the already loaded boundary values;
// best current result is 780B, 0x24 frame, 671-byte positional diff, 61.44% shape.
// probe 23: a distinct outside marker was codegen-duplicate; retained for readable ownership.
// paused: calls, CFG counts, queue fields, clipping behavior, and output size align; frame and
// local/register topology remain structurally different. Next lead is expanded original locals.
// Reassessment pass sa-460299c2: 20 additional source hypotheses were compiled and checked.
// Decompiler-shaped locals and an explicit dword outside marker moved the frame to 0x2c but
// worsened size and shape. Aggregate RECT initialization, dead outside-arm assignments,
// scalar coordinate locals, typed queue cursors, explicit queue stores, queue ownership
// aliases, and declaration-order changes were duplicate or worse. Reversing the first two
// overlap predicates to source-left greater-than form improved shape only (62.29%). Writing
// vBlits greater-than allocated improved the best clean basin to 668 differing bytes and
// 62.71% shape, but the frame stayed 0x24. The pinned natural source remains the clean
// reconstruction. Calls are 2/2 aligned, size is 780, CFG counts are 23/23 conditions,
// 5/5 jumps, and 1/1 return; unresolved evidence is the original 0x34 local frame and
// register/stack topology. No policy-valid exact source was found.

// Follow-up sa-476ae437-r1: the original PDB locals show One_Blit as the
// outside marker, nBlits as the final count, and yd/nBlits sharing a home.
// Renaming roles alone was duplicate. Reusing nBlits for the absolute-y
// denominator before its count assignment reduced the mismatch to 664 bytes
// and raised shape to 68.94%; this is retained as the smallest supported
// lifetime model. Matching blt_deltaX/Y names and a PDB yd alias were
// duplicates. Reversing the first two overlap comparisons to source-bound
// greater-than form raised shape to 69.79% without changing the 664-byte
// mismatch. A local bounds RECT and SDK windows/tagRECT context were
// duplicates or worse. The capacity guard written as nBlits greater than
// allocated raised shape to 70.64%, exact-block coverage to 12.77%, and gave
// a 665-byte mismatch; this source form is retained because its cmp/jle
// direction matches the executable. Reversing allocation stores and adding a
// typed calloc result local were worse or codegen-duplicate. Final current
// result: 780 bytes, 0x24 frame versus original 0x34, 2/2 ordered calls,
// 23/23 conditions, 5/5 jumps, 1/1 return, 665 differing bytes. The blocker
// remains the original four boundary spill slots and prologue register/home
// topology. No accepted-drift residue is supported.
```
<!-- end-recovered:6fbe6fdad392818c8a05 -->
