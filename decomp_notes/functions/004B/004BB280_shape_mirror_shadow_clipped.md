# Function notes: 004BB280 `shape_mirror_shadow_clipped`

Module notes: `decomp_notes/Shape_module.md`.

## Recovered attempt history

<!-- recovered:41ec00b9896d623144f3 -->
### `target-session` `build/target_sessions/004BB280_shape_mirror_shadow_clipped.json:1-48`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=858; shape=47.41641337386018: Current clean typed clipped mirror-shadow decoder; establish 908-byte/858-diff structural baseline.
probe 2 liveness; result=MISMATCH; diff=858; shape=47.41641337386018: Hypothesis 2: split pitch declaration from assignment may preserve call-result EAX and original setup schedule; test exact structural effect. [same emitted code as probe 1]
probe 3 layout; result=MISMATCH; diff=858; shape=47.41641337386018: Hypothesis 3: use the binary's named width local rather than pitch; test whether source-owned width changes allocator basin. [same emitted code as probe 2]
probe 4 control-flow; result=MISMATCH; diff=932; shape=41.228070175438596: Hypothesis 4: mirror the decompiler's unsigned shadow-loop guard  and explicit low-byte mask before the do-loop.
probe 5 control-flow; result=MISMATCH; diff=858; shape=47.41641337386018: Hypothesis 5: use the natural truth-test spelling  after the pre-load decrement, seeking VC5's direct DEC/JNE loop. [same emitted code as probe 3]
probe 6 liveness; result=MISMATCH; diff=858; shape=47.41641337386018: Hypothesis 6: introduce one typed shadow-table alias, as exact unclipped sibling does, to test table-versus-stream register ownership. [same emitted code as probe 5]
probe 7 layout; result=MISMATCH; diff=802; shape=55.015197568389056: Hypothesis 7: widen the shared command-count local to unsigned int, matching original dword count consumers and testing its stack-home width.
probe 8 liveness; result=MISMATCH; diff=858; shape=47.41641337386018: Hypothesis 8: share one command byte across top-skip, visible, middle, and drain phases, matching Ghidra's one bVar8 and sibling local topology. [same emitted code as probe 6]
probe 9 layout; result=MISMATCH; diff=858; shape=47.41641337386018: Hypothesis 9: name the proven Shape_Header owner before deriving the payload, matching exact mirror-shadow siblings and testing header-pointer liveness. [same emitted code as probe 8]
probe 10 liveness; result=MISMATCH; diff=858; shape=47.41641337386018: Hypothesis 10: scope the shadow-table alias after the vertical rejection, matching its first binary load after that guard and testing stream/table register swap. [same emitted code as probe 9]
probe 11 liveness; result=MISMATCH; diff=866; shape=46.504559270516715: Hypothesis 11: materialize AlignedWidth as a typed local before multiplying by orientation, matching the call's return value and testing setup EAX retention.
probe 12 liveness; result=MISMATCH; diff=858; shape=47.41641337386018: Hypothesis 12: keep a distinct typed rows local instead of reusing shape_y1, matching the natural source model behind the original row-count home. [same emitted code as probe 10]
probe 13 control-flow; result=MISMATCH; diff=847; shape=58.358662613981764: Hypothesis 13: delay literal source-span advancement until after the clipped shadow copy, matching original source-pointer stores and line-band order.
probe 14 liveness; result=MISMATCH; diff=876; shape=63.50148367952522: Hypothesis 14: preserve the original literal run length in a distinct typed local while delaying source advancement, avoiding the prior behavior-changing overwrite.
probe 15 layout; result=MISMATCH; diff=801; shape=52.27963525835866: Hypothesis 15: widen the shared count to signed long, following the decompiler's long packet-count temporary and testing signed source arithmetic.
probe 16 liveness; result=MISMATCH; diff=858; shape=47.41641337386018: Hypothesis 16: reverse shared state/count declaration order to test the binary's AL state and byte-count home coloring. [same emitted code as probe 12]
probe 17 liveness; result=MISMATCH; diff=845; shape=52.58358662613982: Hypothesis 17: use an int state temporary, testing whether VC5 keeps the observed AL state in EAX instead of spilling the byte flag.
probe 18 liveness; result=MISMATCH; diff=858; shape=47.41641337386018: Hypothesis 18: type state as signed char, matching the decompiler's char cVar2 and testing AL decrement/comparison lowering. [same emitted code as probe 16]
probe 19 liveness; result=MISMATCH; diff=858; shape=47.41641337386018: Hypothesis 19: promote xpos to a function-scope long local, matching the decompiler's persistent iVar9 and testing register lifetime across RLE phases. [same emitted code as probe 18]
probe 20 liveness; result=MISMATCH; diff=858; shape=47.41641337386018: Hypothesis 20: declare rows at function scope but assign after vertical rejection, testing lifetime-driven home allocation against the original shape_y1 row home. [same emitted code as probe 19]
probe 21 liveness; result=MISMATCH; diff=858; shape=48.02431610942249: Hypothesis 21: split the vertical-skip count and visible-row count into nonoverlapping typed scopes, allowing natural home coalescing after clip_y0 dies.
probe 22 liveness; result=MISMATCH; diff=845; shape=55.92705167173252: Hypothesis 22: share one unsigned transform-count local across all shadow loops, matching Ghidra's single uVar10 rather than macro-local counters.
probe 23 layout; result=MISMATCH; diff=845; shape=55.92705167173252: Hypothesis 23: model the proven 256-byte shadow table as a typed payload view, preserving the byte ABI while testing table-index SIB and register allocation. [same emitted code as probe 22]
probe 24 control-flow; result=MISMATCH; diff=824; shape=56.23100303951368: Hypothesis 24: move the transform-count decrement into the do-while condition, seeking VC5's direct DEC/JNE lowering without a separate test.
probe 25 abi; result=MISMATCH; diff=824; shape=56.23100303951368: Hypothesis 25: qualify the read-only shadow table as const, preserving the byte-pointer ABI while testing const-driven register and alias analysis. [same emitted code as probe 24]
probe 26 control-flow; result=MISMATCH; diff=824; shape=56.23100303951368: Hypothesis 26: use the direct truth-test form , testing VC5 loop-flag lowering against the target DEC/JNE pattern. [same emitted code as probe 25]
probe 27 liveness; result=MISMATCH; diff=824; shape=56.23100303951368: Hypothesis 27: combine the exact same-TU donor's early Byte_Table alias and named Shape_Header owner with the shared DEC-loop count. [same emitted code as probe 26]
probe 28 liveness; result=MISMATCH; diff=824; shape=56.23100303951368: Hypothesis 28: initialize the persistent xpos local before vertical clipping, testing whether its earlier lifetime selects the target ESI cursor basin. [same emitted code as probe 27]
probe 29 layout; result=MISMATCH; diff=824; shape=56.23100303951368: Hypothesis 29: reverse the commutative width multiplication order, testing whether VC5 retains the call result in EAX as in the original setup. [same emitted code as probe 28]
probe 31 abi; result=MISMATCH; diff=824; shape=56.23100303951368: Hypothesis 1: remove the Byte_Table wrapper and use the original byte-table parameter directly in each shadow lookup, testing whether direct table ownership changes the target EBP/EDI basin without changing behavior or calls. [same emitted code as probe 30]
probe 32 liveness; result=MISMATCH; diff=834; shape=55.92705167173252: Hypothesis 2: delay stream initialization until after destination formation and route it through the consumed draw_area parameter, testing natural dead-parameter reuse for the target's [esp+1c] source home.
probe 33 liveness; result=MISMATCH; diff=834; shape=55.92705167173252: Hypothesis 3: use the consumed draw_area parameter itself as the byte-stream cursor through explicit typed byte reads and advances, testing the PDB-proven parameter-home overlay behind the target's [esp+1c] source stores. [same emitted code as probe 32]
probe 34 liveness; result=MISMATCH; diff=791; shape=56.53495440729483: Hypothesis 4: reuse the dead clip_y0 parameter as the packet count, matching the PDB-free target count home at [esp+2c] and reducing one independent byte local.
probe 36 liveness; result=MISMATCH; diff=793; shape=56.838905775075986: Hypothesis 5: reuse clip_y0 as the packet count in the clean stream-pointer source, isolating the parameter-home effect from the prior draw_area cursor experiment.
probe 37 liveness; result=MISMATCH; diff=791; shape=56.53495440729483: Hypothesis 6: combine the proven clip_y0 count-home reuse with delayed stream initialization through draw_area, testing whether both natural parameter reuses recover target state, count, and source/table allocation together. [same emitted code as probe 34]
probe 38 control-flow; result=MISMATCH; diff=815; shape=56.53495440729483: Hypothesis 7: keep shadow transforms inside each even-run clip branch instead of one unconditional call, restoring the binary's separate partial/full transform loops and correct visible-run behavior.
probe 39 control-flow; result=MISMATCH; diff=786; shape=74.16413373860182: Hypothesis 8: delay literal-stream advancement until after each clipped shadow copy, matching the target's post-loop source-home updates and preserving source fault/evaluation order.
probe 40 abi; result=MISMATCH; diff=786; shape=74.16413373860182: Hypothesis 9: use the byte-table parameter directly in the reordered, parameter-count, post-advance source shape, testing whether wrapper removal preserves the target EBP table register while retaining the improved size and topology. [same emitted code as probe 39]
probe 41 liveness; result=MISMATCH; diff=783; shape=75.37993920972644: Hypothesis 10: reuse shape_y1 as the visible-row countdown after vertical clipping, matching the target's proven [esp+24] row home instead of a separate rows local.
probe 42 layout; result=MISMATCH; diff=794; shape=74.77203647416414: Hypothesis 11: compute pitch with a natural return local followed by compound multiplication, testing whether VC5 retains the AlignedWidth result in EAX like the target's imul eax,edi.
probe 43 liveness; result=MISMATCH; diff=785; shape=75.6838905775076: Hypothesis 12: initialize the stream before destination formation while retaining the count-home, row-home, and post-transform advance changes, testing whether target header EBP setup and later topology coexist.
probe 44 liveness; result=MISMATCH; diff=785; shape=75.6838905775076: Hypothesis 13: create the table lookup alias at visible-row scope, where the target first loads table after row setup and retains one table register across its transform loops. [same emitted code as probe 43]
probe 45 liveness; result=MISMATCH; diff=785; shape=75.6838905775076: Hypothesis 14: declare the per-row x cursor before state and command, testing whether natural declaration order selects the target ESI x and EAX state colors without aliases or register directives. [same emitted code as probe 44]
probe 46 liveness; result=MISMATCH; diff=803; shape=73.86018237082067: Hypothesis 15: widen the state temporary to int, testing whether VC5 naturally assigns its persistent 0-3 state to the target AL/EAX role instead of BL/EBX.
probe 47 liveness; result=MISMATCH; diff=783; shape=75.37993920972644: Hypothesis 16: preserve the original draw-area in a natural area alias, then consume draw_area as the post-setup stream owner, testing the PDB-proven parameter-home overlay with typed setup. [same emitted code as probe 41]
probe 48 liveness; result=MISMATCH; diff=783; shape=75.37993920972644: Hypothesis 17: consume the stream entirely through the aliased draw_area parameter, with area preserving draw fields, testing whether parameter-home writes select target EDI source and EBP table allocation.
probe 49 liveness; result=MISMATCH; diff=785; shape=75.6838905775076: Hypothesis 18: move stream declaration after the destination locals while preserving its early initializer, testing declaration-order liveness against the target source/table register and home basin. [same emitted code as probe 45]
probe 50 liveness; result=MISMATCH; diff=785; shape=75.6838905775076: Hypothesis 19: scope each shadow-loop counter inside its transform block instead of one function-wide counter, matching the PDB-free uVar10 behavior and testing loop-local liveness. [same emitted code as probe 49]
```
<!-- end-recovered:41ec00b9896d623144f3 -->

<!-- recovered:75673e8f504400541403 -->
### `0923cad7edb1` `src/scratch/004BB280_shape_mirror_shadow_clipped.cpp:1-53`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004BB280 TShape::shape_mirror_shadow_clipped
// Shape.cpp
// Attempt log:
// Previous workers reconstructed the RLE state machine with the wrong formal
// argument order and compiler-steering cursor forms. This pass starts again
// from the exact mirror and shadow siblings.
//
// fresh shape pass:
// - restored the period clipped-renderer ABI: shape origin, then four clip
//   bounds, with the shadow table last;
// - used the same signed-pitch destination and vertical skip structure as the
//   exact mirror siblings;
// - kept one shared byte count and ordinary inline shadow loops for each RLE
//   band. No raw offsets, fake volatility, or inline assembly remain.
// Probe notes:
// - Correcting the ABI and row ownership changed the 1073-byte first build
//   into a 998-byte candidate with the proven single AlignedWidth call.
// - Moving command/state to shared locals recovered the original 0x8 frame.
// - Advancing literal source spans before shadow branches reduced the body to
//   941 bytes and aligned the repeated shadow loops.
// - Reusing shape_y1 as the row counter was source-plausible but codegen
//   neutral. The typed SHADOW_BACK idiom then reached 928 bytes and 867
//   strict differing bytes, the retained codegen best.
// - A single byte overlay and split pitch assignment were rolled back. They
//   worsened shape or setup allocation. No behavior or call uncertainty
//   remains; the unresolved gap is the VC5 prologue/register and home basin.
// - Restored the donor-shaped positive guard and post-decrement shadow loop.
//   This reduced the build to 908 bytes and 858 strict differing bytes. The
//   current source remains a typed clipped shadow decoder; the open gap is
//   still structural block placement and local-home allocation.
// - Reading orientation first, splitting the width assignment, delaying the
//   shadow-table alias, and using signed state were codegen duplicates.
// - A byte shadow-loop counter reached 878 bytes/823 differing bytes, but it
//   added repeated counter homes and was rolled back as a codegen-only basin.
// - Moving literal source advances after the clipped branch enlarged the
//   frame to 0xC and 884 differing bytes; delaying source setup reached 853
//   differing bytes but lost shape and was also rolled back.
//
// Revisit probes (sa-74f73810-r1):
// - Re-read the PDB symbols and exact Shape.cpp siblings. The target has one
//   width home, one save-buffer home, one command home, and one buffer home.
//   Its remaining stream, state, row, and transform values are compiler
//   coalescences, not proven source aggregates.
// - Twenty-nine distinct natural probes covered call-result lifetime,
//   declaration scope, count width, source-advance order, typed table view,
//   and loop lowering. No probe matched the target.
// - A shared unsigned transform count with a decrementing do-loop follows
//   the exact 004BAAF0 loop donor. It reduced the candidate to 888 bytes and
//   824 strict differing bytes, with 31.31% exact-block coverage.
// - The remaining mismatch is the original parameter-home and register basin:
//   target roles are EBP=table, EDI=source, ESI=x, EAX=state, EDX=count;
//   the clean typed source keeps EBP=source and EDI=table. Parameter-home
//   overlays and compiler steering are not retained.
```
<!-- end-recovered:75673e8f504400541403 -->
