# Function notes: 004BA1C0 `shape_shadow_clipped`

Module notes: `decomp_notes/Shape_module.md`.

## Recovered attempt history

<!-- recovered:5d5c3e080bbfc8284457 -->
### `target-session` `build/target_sessions/004BA1C0_shape_shadow_clipped.json:1-29`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=805; shape=79.76878612716763: Retained clean source baseline: 906 bytes, frame 0x08, one AlignedWidth call, 805 strict differing bytes; p stays EBP and table reloads.
probe 2 liveness; result=MISMATCH; diff=805; shape=79.76878612716763: Reordered table alias before stream pointer to test callee-saved table lifetime and force p to a dead draw-area home. [same emitted code as probe 1]
probe 3 layout; result=MISMATCH; diff=805; shape=79.76878612716763: Typed the 256-byte shadow table payload to test the proven table-view SIB basin used by exact mirror-shadow donors. [same emitted code as probe 2]
probe 4 control-flow; result=MISMATCH; diff=857; shape=78.00586510263929: Moved visible-run command shifts into the odd-command arms, matching original delayed SHR and even-command TEST topology.
probe 6 liveness; result=MISMATCH; diff=805; shape=79.76878612716763: Delayed shadow-table alias assignment until after vertical skip, matching original table load at first visible-row setup and shortening its live range. [same emitted code as probe 3]
probe 7 layout; result=MISMATCH; diff=805; shape=79.76878612716763: Delayed typed 256-byte table view until visible rows, combining table payload ownership with the original late table load. [same emitted code as probe 6]
probe 9 liveness; result=MISMATCH; diff=805; shape=79.76878612716763: Removed the redundant table alias and used the incoming table parameter directly in all transform loops, testing parameter-register liveness. [same emitted code as probe 7]
probe 10 liveness; result=MISMATCH; diff=878; shape=79.76539589442815: Declared stream pointer before pitch to test whether VC5 follows original p-before-width source order and delays clip-bound materialization.
probe 12 liveness; result=MISMATCH; diff=805; shape=79.76878612716763: Reordered shared byte state, command, and count declarations to test VC5 byte-home and register-color assignment. [same emitted code as probe 9]
probe 13 abi; result=MISMATCH; diff=805; shape=79.76878612716763: Retyped TDrawArea::AlignedWidth to its donor-proven long return surface; the x86 ABI stays 32-bit but source type may alter VC5 expression lowering.
probe 14 liveness; result=MISMATCH; diff=856; shape=78.55072463768116: Assigned the dead draw-area formal from the stream pointer after setup to test whether VC5 overlays p onto the incoming parameter home.
probe 16 control-flow; result=MISMATCH; diff=885; shape=70.85714285714286: Moved command shifts into both odd and even visible arms, preserving the original two delayed SHR sites while keeping each arm initialized.
probe 18 liveness; result=MISMATCH; diff=805; shape=79.76878612716763: Moved the table alias declaration ahead of pitch and stream declarations to test full local declaration-order coloring. [same emitted code as probe 12]
probe 19 layout; result=MISMATCH; diff=805; shape=79.76878612716763: Used an explicit Byte_Table payload cast inside each shadow lookup to test the exact mirror donor's typed table-index basin without changing the byte-pointer ABI. [same emitted code as probe 18]
probe 20 context; result=MISMATCH; diff=805; shape=79.76878612716763: Added the proven trailing TShape member surface used by exact Shape.cpp donors to test class-context and alias-analysis effects. [same emitted code as probe 19]
probe 21 liveness; result=MISMATCH; diff=805; shape=79.76878612716763: Swapped row-local declaration order to put source x before working destination, testing the original row-entry register color sequence.
probe 22 liveness; result=MISMATCH; diff=805; shape=79.76878612716763: Applied period register storage to the read-only table pointer, testing whether it recovers original EBP table residency without changing ABI. [same emitted code as probe 21]
probe 23 liveness; result=MISMATCH; diff=805; shape=79.76878612716763: Applied register storage to the local shadow-table alias to test explicit table residency against the original EBP table role. [same emitted code as probe 22]
probe 25 abi; result=MISMATCH; diff=861; shape=80.05865102639297: Reused the incoming draw-area pointer itself as the typed byte-stream cursor after setup, testing the binary-proven parameter-home overlay directly.
probe 27 control-flow; result=MISMATCH; diff=805; shape=79.76878612716763: Recast the post-left-clipping visible loop as an explicit zero guard plus do-while, testing the Ghidra-positive-loop control form against the original top-tested topology. [same emitted code as probe 20]
probe 30 layout; result=MISMATCH; diff=805; shape=79.76878612716763: Typed the persistent shadow table alias as the proven 256-byte table aggregate, testing whether a real table owner keeps the table in EBP and spills the source cursor to the draw-area home. [same emitted code as probe 29]
probe 31 liveness; result=MISMATCH; diff=859; shape=77.41935483870968: Moved stream initialization after destination formation while keeping its natural typed owner, testing whether a later first use changes the source-cursor home toward the original draw-area parameter slot.
probe 32 liveness; result=MISMATCH; diff=805; shape=79.76878612716763: Split the persistent table alias declaration from its assignment, testing declaration-time liveness and allocator order without changing the typed byte-table ABI or decoder control flow. [same emitted code as probe 30]
probe 33 liveness; result=MISMATCH; diff=805; shape=79.76878612716763: Swapped stream and table alias declaration order in the natural setup, testing the original table-EBP versus source-home coloring while preserving all typed ownership and control flow. [same emitted code as probe 32]
probe 34 context; result=MISMATCH; diff=848; shape=80.17241379310344: Added the Shape.cpp donor-supported string header without changing source behavior, testing whether period CRT front-end context selects the target's table-versus-stream register basin.
probe 35 context; result=MISMATCH; diff=888; shape=71.26760563380282: Added the matching Shape.cpp memory header with string.h, testing the combined CRT front-end basin after string.h alone changed block placement but shortened the body.
probe 36 liveness; result=MISMATCH; diff=878; shape=79.76539589442815: Declared the stream pointer before pitch, testing whether VC5 emits the binary-observed header payload add before orientation and destination setup. [same emitted code as probe 10]
probe 37 layout; result=MISMATCH; diff=805; shape=79.76878612716763: Used a const typed Byte_Table alias for the read-only shadow table, testing whether qualified aggregate ownership preserves the target table register without changing the byte-pointer ABI. [same emitted code as probe 33]
probe 38 context; result=MISMATCH; diff=883; shape=70.53824362606233: Added the period Windows SDK header as a translation-unit context probe, testing the documented windows.h register basin without changing ownership or behavior.
```
<!-- end-recovered:5d5c3e080bbfc8284457 -->

<!-- recovered:4d5c1642285d8d9fd881 -->
### `0923cad7edb1` `src/scratch/004BA1C0_shape_shadow_clipped.cpp:1-39`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004BA1C0 TShape::shape_shadow_clipped
// Attempt log:
// 1: direct Ghidra-structured clipped shadow decoder with TDrawArea/TShape offsets; helper-call baseline compiled to 864 bytes, too short.
// 2: macro-inlined copy loops reached exact 906-byte size but 90.07% positional / 66.23% edit diff; first mismatch is frame size sub esp,10 vs original sub esp,8.
// 3: root issue appears source topology/local allocation: original reuses incoming stack homes for stream pointer/count byte and keeps only two explicit locals, while this clean source keeps extra locals and holds stream pointer in EBP.
// 4 (shared eager-count diagnostic): keep the original eager count spelling but reuse one command/count pair across all RLE phases, testing a smaller source-local set before any further control-flow tuning.
// 7 (retained best basin): shared eager command/count/state locals restore the oracle-sized 0x08 frame and improve shape to 78.61%; the remaining gap is the early cursor/home/register schedule.
// 5 (formal-row probe, rolled back): direct shape_y1 reuse improved shape similarity but shortened the body and worsened positional drift; the clean source retains its explicit current-row copy.
// 6 (destination-offset probe, rolled back): a separate row-offset temporary improved setup shape but shortened the body and worsened the authoritative positional diff.
// 10 (delayed named-header probe, rolled back): the named owner was a codegen duplicate of the retained source and did not change the EBX/EBP cursor basin.
// shardB3-BA1C0 probe 12 (natural row topology, rolled back): reusing shape_y1 for the vertical skip and save_buffer for the persistent row destination improved block shape but shortened the body by 11 bytes and worsened the strict diff to 836 bytes.
// shardB3-BA1C0 probe 14 (named owner, retained): naming a TShapeHeader owner before deriving p was codegen-identical and keeps the stream ownership period-plausible; no ABI or call change resulted.
// shardE-4BA1C0 probe 16 (ABI, rolled back): retyped the draw-area formal as a byte stream home and used a typed area alias; 861 diff, worse.
// shardE-4BA1C0 probe 18 (control-flow, retained): delayed the current-row assignment until after destination setup; 805 diff, 79.77% shape.
// shardE-4BA1C0 probe 19 (ABI, rolled back): reused the draw-area formal itself as the stream cursor; 856 diff and lost call relocation identity.
// shardE-4BA1C0 probe 21 (liveness, duplicate): declared the current-row local before pitch but assigned it after setup; same 805-byte output.
// shardE-4BA1C0 probe 22 (liveness, duplicate): hoisted a typed table alias into the visible-row phase; same 805-byte output.
// shardE-4BA1C0 probe 23 (layout, duplicate): removed the separate header owner and derived the stream directly from shape_header; same 805-byte output.
// shardE-4BA1C0 probe 24 (liveness, rolled back): restored early row initialization; 900 diff and +21 bytes.
// shardE-4BA1C0 probe 26 (liveness, rolled back): removed the unused x local; restored the 812-byte clean basin.
// shardE-4BA1C0 probe 28 (layout, retained): direct stream derivation plus delayed row declaration and table alias; 805 diff, 79.77% shape.
// final retained: shared eager command/count/state plus direct stream derivation, delayed row declaration, and explicit destination locals; 906 bytes, exact 0x08 frame, 1/1 call identity, 805 strict differing bytes. Remaining evidence-backed blocker is the original p/clip-parameter home and early register schedule.
// left in scratch: behavior model is close to Ghidra but not an exact/accepted-drift candidate; needs a parameter-home-reuse rewrite mirroring original stack slots.
// managed claim probes (sa-df68f809, 2026-08-17):
// - Table alias declaration order, delayed table assignment, direct table use,
//   typed Byte_Table views, and full TShape member context were duplicate 906B
//   basins; the p cursor remained EBP and table reloads remained in copy loops.
// - Moving command shifts into visible odd arms alone reached 879B/857 diff;
//   initializing both arms reached 936B with a 0xC frame. Both were rolled back.
// - p-before-pitch and state-first declaration orders were worse or duplicate.
//   Long-return AlignedWidth, register table forms, row-local order, and an
//   explicit zero-guarded do-loop were duplicate codegen basins.
// - A dead draw-area assignment from p reached 856 diff. Reusing draw_area as
//   the typed stream cursor reached 892B/861 diff. Both confirm the home lead
//   but are not clean retained source forms.
// - Final clean validation remains 906B, 0x08 frame, one alignedwidth call,
//   79.77% shape, and 805 strict differing bytes. Calls and ownership are set;
//   the open lead is a natural source form that gives p the draw-area home and
//   table EBP without raw aliases or compiler-steering constructs.
```
<!-- end-recovered:4d5c1642285d8d9fd881 -->
