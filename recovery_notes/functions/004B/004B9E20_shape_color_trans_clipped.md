# Recovery journal: 004B9E20 `shape_color_trans_clipped`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Shape.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Shape.cpp`.
- Earlier recovery note: `recovery_notes/Shape_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:3bfa42b0d014b16c48cf -->
### `target-session` `build/target_sessions/004B9E20_shape_color_trans_clipped.json:1-28`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=800; shape=82.03592814371258: Current scratch reconstruction: typed clipped translated RLE decoder, 9-argument __thiscall ABI, inline translated loops, two forced memset calls, signed-pitch row update. Establish baseline before new probes.
probe 2 liveness; result=MISMATCH; diff=885; shape=54.790419161676645: Hypothesis 1: mirror exact sibling topology with a persistent save_buffer row base and a per-row dst cursor. Tests whether original puVar11/puVar12 ownership controls the first structural hunk.
probe 4 liveness; result=MISMATCH; diff=876; shape=80.53892215568862: Hypothesis 2: follow the decompiler's natural parameter-reuse topology for vertical skip and row count (mutate clip_y0 and clip_y1 instead of separate skip/rows locals). Tests parameter-home pressure without changing RLE behavior.
probe 6 control-flow; result=MISMATCH; diff=801; shape=83.72781065088758: Hypothesis 3: use the original-looking explicit masked parity comparison only in the top clipped-row skip loop. Tests whether its BL/CMP branch topology is source-active independently of the three draw phases.
probe 8 control-flow; result=MISMATCH; diff=804; shape=83.23353293413173: Hypothesis 4: explicit masked parity comparison only in the left-clipped band. Tests whether the original state dispatch's BL/CMP shape is local to that phase.
probe 10 control-flow; result=MISMATCH; diff=805; shape=83.83233532934132: Hypothesis 5: explicit masked parity comparison only in the in-bounds middle band. Tests whether the original central dispatch uses the larger BL/CMP form while leaving clipping and drain tests natural.
probe 12 control-flow; result=MISMATCH; diff=799; shape=83.23353293413173: Hypothesis 6: explicit masked parity comparison only in the final post-row drain loop. Tests whether the original drain block's command flag uses the same nonzero branch form as the top skip.
probe 13 control-flow; result=MISMATCH; diff=803; shape=85.92814371257485: Hypothesis 7: combine explicit parity forms in top skip and final drain, leaving left and middle bands direct. Tests whether the two phase-boundary loops share the oracle branch basin.
probe 14 liveness; result=MISMATCH; diff=803; shape=85.92814371257485: Hypothesis 8: reuse the dead shape_y1 incoming home as the first left-crossing literal's visible width, matching the oracle's store/reload of [esp+28]. Tests one binary-proven parameter-slot reuse without changing the phase topology.
probe 16 layout; result=MISMATCH; diff=800; shape=82.03592814371258: Hypothesis 9: represent the payload start through a typed Shape_Header* one-past-header before converting to byte*. Tests whether the original decompiler's typed payload cursor affects front-end address formation. [same emitted code as probe 1]
probe 18 context; result=MISMATCH; diff=800; shape=82.03592814371258: Hypothesis 10: restore the full period TDrawArea and TShape member surfaces used by exact same-TU Shape.cpp donors, while keeping target semantics unchanged. Tests whether hidden type context selects the target allocator basin. [same emitted code as probe 16]
probe 20 abi; result=MISMATCH; diff=800; shape=82.03592814371258: Hypothesis 11: narrow only the row count and horizontal cursor to int, matching the decompiler's iVar locals while preserving long formal ABI. Tests signed-width lowering and register pressure. [same emitted code as probe 18]
probe 22 liveness; result=MISMATCH; diff=885; shape=54.790419161676645: Hypothesis 12: make save_buffer and dst function-scope pointers, initialize dst once, and reset it from save_buffer at each row. Tests whether broader pointer liveness preserves the oracle's row-base spill without a nested declaration. [same emitted code as probe 2]
probe 24 liveness; result=MISMATCH; diff=837; shape=54.790419161676645: Hypothesis 14: delay save_buffer declaration until after vertical clipping and initialize it from the already-formed destination, then reset dst from it per row. Tests lifetime ordering as a source-level spill trigger.
probe 26 liveness; result=MISMATCH; diff=883; shape=54.49101796407186: Hypothesis 15: persistent row base with per-row destination declared before horizontal cursor. Tests whether the PDB-like local declaration order (puVar12 before iVar10) changes VC5 spill/color allocation.
probe 28 control-flow; result=MISMATCH; diff=800; shape=82.03592814371258: Hypothesis 16: express the two post-left state phases as while(state == 0) loops after decrement, mirroring the decompiler's bVar3/state loop form instead of if-wrapped do loops. Tests loop-rotation and shared-tail layout. [same emitted code as probe 20]
probe 30 liveness; result=MISMATCH; diff=800; shape=82.03592814371258: Hypothesis 17: add one function-scope width local for the first left-crossing literal count, matching the oracle's durable width home at entry-relative -8 and its count reload.
probe 32 context; result=MISMATCH; diff=800; shape=82.93413173652695: Hypothesis 18: add period memory.h context beside the existing string.h and explicit memset declaration. Tests whether Shape.cpp header state changes the VC5 inline and register basin.
probe 33 context; result=MISMATCH; diff=799; shape=84.13173652694611: Hypothesis 19: combine memory.h context with the final drain loop's explicit masked parity form. Tests an evidence-led interaction between TU header state and the only parity variant that improved strict bytes.
probe 34 control-flow; result=MISMATCH; diff=807; shape=86.82634730538922: Hypothesis 20: combine memory.h context, explicit top-skip parity, and explicit final-drain parity. Tests the strongest boundary-loop branch basin under the supported Shape.cpp header context.
probe 35 control-flow; result=MISMATCH; diff=807; shape=85.62874251497006: Hypothesis 21: under memory.h context, keep explicit parity only in the top skip loop and restore direct tests in the final drain. Tests the complementary boundary-loop combination.
probe 36 variant; result=MISMATCH; diff=840; shape=61.97604790419162: Hypothesis 22: port the same-TU shape_draw_clipped natural topology to color translation: shared byte count, save_buffer row base, clip_y0 as phase state, and parameter-reused vertical/row counts. Translated literal loops remain inline and only the two memset calls remain.
probe 39 liveness; result=MISMATCH; diff=881; shape=44.01197604790419: Hypothesis 23: mirror the binary-supported sibling's save_buffer row-base topology exactly: compute the row base before vertical clipping, offset it by clip_x0, then declare per-row dst from save_buffer. Tests the original [esp+10] row-base store at +005E rather than metric-only register steering.
probe 41 control-flow; result=MISMATCH; diff=799; shape=84.13173652694611: Hypothesis 24: use the exact sibling Shape.cpp outer positive guard form , matching Ghidra's source topology and donor assembly, instead of an early-return guard. Tests source-level block layout without changing packet behavior. [same emitted code as probe 38]
probe 43 liveness; result=MISMATCH; diff=799; shape=84.13173652694611: Hypothesis 25: promote the repeated translated-copy end pointer to one function-scope byte pointer. Ghidra lists one shared puVar6 local, and the oracle spills an end pointer at entry-relative -10 in the left crossing loop. Tests declaration lifetime and stack-home reuse without changing behavior. [same emitted code as probe 41]
probe 45 liveness; result=MISMATCH; diff=905; shape=47.604790419161674: Hypothesis 26: use one function-scope command byte across top skip, left, middle, and final drain. The oracle keeps packet-byte writes in one dead formal home at entry plus 0x4 while state stays at clip-y home plus 0x18; separate block command declarations currently coalesce command into state.
probe 47 liveness; result=MISMATCH; diff=881; shape=44.01197604790419: Hypothesis 27: copy the exact sibling declaration order: long xpos first, then row-local dst initialized from a function-scope save_buffer, then state. This differs from tested save-buffer variants that declared dst before xpos or state before dst. [same emitted code as probe 39]
probe 49 liveness; result=MISMATCH; diff=881; shape=44.01197604790419: Hypothesis 28: combine the binary row-base save_buffer with the Ghidra-listed shared translated-copy end pointer. This tests the complete pointer-local set against the oracle's three local homes, rather than the prior row-base-only basin. [same emitted code as probe 47]
```
<!-- end-recovered:3bfa42b0d014b16c48cf -->

<!-- recovered:0a9a4379efc0206fef83 -->
### `0923cad7edb1` `src/scratch/004B9E20_shape_color_trans_clipped.cpp:1-47`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004B9E20 TShape::shape_color_trans_clipped
// Attempt log:
// try 1: reconstructed non-mirrored clipped color-translation RLE draw from packet and sibling shape_draw_clipped/shape_mirror_color_trans_clipped scratch.
// try 2: modeled TDrawArea fields Bits +8, Height +0x1c, Orien +0x24 and AlignedWidth() pitch call.
// try 3: modeled TShape shape_header at +0x0c and RLE source as header +0x18.
// try 4: implemented positive/negative orientation destination formulas from original asm.
// try 5: implemented top-clipped row skip loop with odd literal packets, zero extended skip, even fill/end packets.
// try 6: implemented left-side clipped band with state values and partial translated literal/fill handling.
// try 7: implemented middle in-bounds band with translated literal copies and translated fill packets through memset.
// try 8: implemented right-side drain loop after visible span.
// try 9: validation reaches exact configured size 917B, but broad mismatch (93.2388% positional / 150.0545% edit); first mismatch is frame size 0x28 vs original 0x0c.
// try 10: compared with sibling clipped/color/mirror scratch attempts; same family problem: behavior surface plausible, but VC5 original uses very tight 3-local frame and specific EBX/EBP/ESI/EDI allocation while natural C state machine creates too much local pressure.
// try 11: kept helper copy_trans_fwd rather than macro/inlined version because sibling 004BAF20 showed inline translated-copy worsens frame pressure; still broad and not drift-safe.
// try 12: restored the binary-proven inline translated-copy loops and out-of-line
// memset surface; the original has only AlignedWidth plus two memset calls.
// try 13: restored the omitted shape-index parameter from the caller/PDB ABI and
// mapped the seven long arguments to shape origin plus four clip bounds.
// sa-c8968b7c-r1 probe 1 baseline: the prior helper-call source rebuilt 1126B
// with five calls; retained only as history, not as the living reconstruction.
// probe 2: inlined the translated literal loops and forced the two binary-proven
// memset calls; call set became exact and the candidate fell to 932B.
// probe 3: restored the caller-proven nine-stack-argument ABI (shape index plus
// seven longs); semantics and stack cleanup became exact, with a 949B candidate.
// probe 4/restore: reusing clip-y homes for skip/row counts worsened the basin.
// probe 5: one mutable byte command plus direct table indexing reduced the frame
// to 0x10 and the candidate to 882B, but was retained only as evidence.
// probe 6: replacing the orientation-dependent row tail with `dst += pitch`
// recovered the signed-pitch behavior, exact 0x0c frame, 334 instructions,
// 41 conditional signals, and the best 82.04% shape / 800-byte strict diff.
// probe 7/restore: a separate save_buffer/row-destination split worsened the
// prologue and frame; a function-scope command and a post-setup save_buffer alias
// were likewise rolled back. Current best remains the simple signed-pitch form.
// shardB4-B9E20 layout probe: direct typed save_buffer row-base plus per-row
// destination cursor duplicated prior evidence and worsened to 883 bytes with
// a 0x10 frame; restored the clean signed-pitch source.
// GIVEUP blockers: exact clipped RLE source topology, parameter-slot reuse for min/max/x/y counters, state-byte placement at [esp+34], and register allocation for EDI=src/ESI=dst/EBP=xpos/EDX=min_x. No inline asm used; no accepted_drift proposal.
// luna-4B9E20-r2 control-flow probe: spelling all four parity tests as
// `(command & 1) == 1` matched the original masked compare branches and
// improved block coverage (49.40% to 60.48%) and size (866B to 900B), but
// worsened strict diff (800B to 813B); restored the pinned natural source.
// sa-fca62799-r1: 22 evidence-led hypotheses tested. Save-buffer lifetime and
// order, parameter-home reuse, each parity phase, full donor type surfaces,
// narrow counters, header context, loop rotation, and a sibling shared-count
// topology did not reach exactness. Memory.h plus explicit final-drain parity
// is the retained 799-byte strict basin. Calls, frame, ABI, and RLE behavior
// align; the first structural gap remains the saved row-base allocation at
// +005E. No inline asm or compiler-steering form was retained.
```
<!-- end-recovered:0a9a4379efc0206fef83 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
