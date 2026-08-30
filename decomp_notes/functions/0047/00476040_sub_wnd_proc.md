# Function notes: 00476040 `sub_wnd_proc`

Module notes: `decomp_notes/pnl_edit_module.md`.

## Recovered attempt history

<!-- recovered:85b0366cdadfd17e5879 -->
### `target-session` `build/target_sessions/00476040_sub_wnd_proc.json:1-38`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=867; shape=82.3699421965318: Baseline current natural source: exact frame and 25 calls, but parameter preload, low-message dispatch topology, and final coordinate arithmetic differ.
probe 2 control-flow; result=MISMATCH; diff=885; shape=83.62573099415205: Hypothesis 1: express low and high message ranges as <= WM_ERASEBKGND and <= WM_MOUSEMOVE, matching original cmp/ja/je dispatch rather than < bounds.
probe 4 control-flow; result=MISMATCH; diff=886; shape=76.96793002915452: Hypothesis 2: use proven late high-message label with msg > WM_ERASEBKGND and msg <= WM_MOUSEMOVE guards, to reproduce original cmp/ja and high dispatch target.
probe 7 liveness; result=MISMATCH; diff=867; shape=82.3699421965318: Hypothesis 3: retain explicit message and lParam copies, as Ghidra shows uVar2/lVar3 locals and original preloads msg/lParam before later home reuse.
probe 9 control-flow; result=MISMATCH; diff=867; shape=82.3699421965318: Hypothesis 4: model the low-message pair as a switch with WM_PAINT before WM_ERASEBKGND, because original emits invalidate inline and erase calls in a later target.
probe 11 liveness; result=MISMATCH; diff=867; shape=82.3699421965318: Hypothesis 5: declare the Ghidra-indicated message/lParam copies before all selection locals, testing declaration order as a VC5 register and home-color input. [same emitted code as probe 7]
probe 13 control-flow; result=MISMATCH; diff=922; shape=38.63636363636363: Hypothesis 6: split WM_MOUSEMOVE from the remaining switch, testing whether its dedicated arm recovers original cmp-200 range and mouse block placement.
probe 16 behavior; result=MISMATCH; diff=867; shape=82.3699421965318: Hypothesis 7: use two mutable coordinate locals and compose the adjusted lParam, reflecting original low/high extraction, in-place adds, and final masking.
probe 18 behavior; result=MISMATCH; diff=870; shape=82.26744186046511: Hypothesis 8: carry one mutable adjusted lParam through high/low extraction and recomposition, matching original EBX lifetime and in-place coordinate updates.
probe 20 context; result=MISMATCH; diff=867; shape=82.3699421965318: Hypothesis 9: restore the period string-header context used by neighboring pnl_edit.cpp methods, testing whether VC5 TU state changes the register and branch basin. [same emitted code as probe 1]
probe 22 abi; result=MISMATCH; diff=867; shape=82.3699421965318: Hypothesis 10: use the canonical Windows HWND parameter type for the callback member, testing whether typed Win32 ABI lowering changes the saved parameter colors. [same emitted code as probe 20]
probe 23 abi; result=MISMATCH; diff=867; shape=82.3699421965318: Hypothesis 11: remove the redundant old-procedure local and pass the proven +0x110 WNDPROC field directly to CallWindowProcA, testing call-argument lifetime.
probe 25 liveness; result=MISMATCH; diff=867; shape=82.3699421965318: Hypothesis 12: preserve the Ghidra-indicated uVar9 wParam copy and use it through default forwarding, testing the original EDI preload and stack-home reuse.
probe 27 liveness; result=MISMATCH; diff=904; shape=62.07865168539326: Hypothesis 13: use the incoming msg home itself as the second EM_GETSEL start output, while preserving original message in a local, matching Ghidra's &param_2 and later message tests.
probe 29 liveness; result=MISMATCH; diff=923; shape=75.43352601156069: Hypothesis 14: reuse the incoming lParam formal as the selection-tracking flag while retaining an original_lParam copy, matching Ghidra's param_4=0/1 and original lParam home store.
probe 31 behavior; result=MISMATCH; diff=867; shape=82.3699421965318: Hypothesis 15: reverse source coordinate-field calculation order, testing whether VC5 then emits original pnl_x-before-pnl_y loads and EBX/EDI arithmetic. [same emitted code as probe 22]
probe 33 behavior; result=MISMATCH; diff=865; shape=82.84883720930233: Hypothesis 16: make extracted coordinates unsigned short values, matching original early low-word masking and naturally narrow message coordinates.
probe 35 liveness; result=MISMATCH; diff=867; shape=82.3699421965318: Hypothesis 17: keep a named saved lParam live across forwarding calls and mutate it for coordinate dispatch, testing whether VC5 assigns the original EBX long-lived home. [same emitted code as probe 25]
probe 37 control-flow; result=MISMATCH; diff=885; shape=84.34782608695652: Hypothesis 18: reverse low-message if order so WM_PAINT is the inline arm and WM_ERASEBKGND is the later body, matching original low-call order.
probe 39 liveness; result=MISMATCH; diff=867; shape=82.3699421965318: Hypothesis 19: hoist the result declaration to function scope, matching Ghidra's top-level lVar7 and testing result-register/color lifetime.
probe 42 liveness; result=MISMATCH; diff=867; shape=82.3699421965318: Hypothesis 1: declare and use message, wParam, and lParam copies before selection locals, matching the decompiler's entry assignments and testing whether lParam takes the original EBX lifetime.
probe 43 control-flow; result=MISMATCH; diff=867; shape=82.3699421965318: Hypothesis 2: use a low-message switch with WM_ERASEBKGND before WM_PAINT, matching the original cmp-14/je brush, cmp-0f/default layout rather than the if/else branch polarity.
probe 44 control-flow; result=MISMATCH; diff=885; shape=84.92753623188406: Hypothesis 3: invert the low-message erase predicate so WM_PAINT stays on the fall-through path and WM_ERASEBKGND jumps to its late brush block, matching the original cmp-14/je and cmp-0f/jne topology.
probe 45 control-flow; result=MISMATCH; diff=864; shape=84.72622478386167: Hypothesis 4: combine the low bound as msg <= WM_ERASEBKGND and keep the inverted inner erase predicate, testing the original single cmp-14 reused for range and equality.
probe 46 liveness; result=MISMATCH; diff=864; shape=84.72622478386167: Hypothesis 5: make the copied lParam an unsigned mutable value and shift that value in place during coordinate dispatch, matching the original EBX shr-10h lifetime and final mutation.
probe 47 liveness; result=MISMATCH; diff=771; shape=87.68328445747801: Hypothesis 6: mutate the real long lParam formal with an unsigned right shift at the coordinate tail, rather than a removable copy, to preserve the original entry-loaded EBX and shr topology.
probe 48 liveness; result=MISMATCH; diff=771; shape=87.68328445747801: Hypothesis 7: remove optimized message and wParam copies while retaining the in-place lParam formal mutation, testing whether the compiler assigns EBX to lParam and EBP to message as in the original.
probe 49 liveness; result=MISMATCH; diff=864; shape=84.72622478386167: Hypothesis 8: use one first-declared unsigned lParam copy throughout forwarding and mutate that copy in the coordinate tail, testing declaration order plus lParam lifetime for original EBX coloring.
probe 50 liveness; result=MISMATCH; diff=771; shape=87.68328445747801: Hypothesis 9: mark the non-address-taken mutable lParam formal register-qualified, testing whether explicit period C++ register storage recovers the original EBX lParam color without changing ABI. [same emitted code as probe 48]
probe 51 liveness; result=MISMATCH; diff=771; shape=87.68328445747801: Hypothesis 10: register-qualify both message and mutable lParam formals, testing whether the original EBP-message/EBX-lParam pair is an explicit register allocation basin. [same emitted code as probe 50]
probe 52 liveness; result=MISMATCH; diff=773; shape=86.00583090379008: Hypothesis 11: preserve original lParam in a top local and reuse the incoming lParam home as the selection-tracking flag, matching Ghidra's lVar3 copy plus param_4=0/1 stores.
probe 53 abi; result=MISMATCH; diff=773; shape=85.42274052478135: Hypothesis 12: use the decompiler's signed long lParam copy type while retaining lParam-home selection tracking and unsigned shift semantics, testing whether width/signedness recovers original allocation.
probe 54 liveness; result=MISMATCH; diff=812; shape=75.85227272727273: Hypothesis 13: recover the proven stack-window reuse: function-scope RECT, new_end/old_end locals, msg home as the second EM_GETSEL start output, and lParam home as the tracking flag.
probe 55 liveness; result=MISMATCH; diff=812; shape=75.85227272727273: Hypothesis 14: declare the dossier's unmapped old_start stack local, testing whether its proven frame slot restores the original 0x1C frame and entry-relative parameter homes without adding behavior.
probe 57 behavior; result=MISMATCH; diff=758; shape=89.11764705882354: Hypothesis 15: move currentPanel before coordinate masking and mutate lParam after the call's receiver lookup, matching the original pre-call add/shr and post-call mask/shl/or schedule.
probe 58 control-flow; result=MISMATCH; diff=745; shape=88.33819241982508: Hypothesis 16: express the upper message bound as msg <= WM_MOUSEMOVE, eliminating the compiler's extra cmp-201 from the nested <0x201 guard and matching the original cmp-200/ja/je sequence.
probe 59 control-flow; result=MISMATCH; diff=745; shape=88.33819241982508: Hypothesis 17: spell the four proven guards as early gotos to the shared default tail, testing whether explicit one-field checks recover the original EAX load/test chain and preserve the late dispatch.
probe 60 control-flow; result=MISMATCH; diff=927; shape=33.903133903133906: Hypothesis 18: handle WM_MOUSEMOVE as the explicit high-range equality before the remaining sparse switch, matching the original cmp-200/je mouse path and testing EAX jump-index lowering.
```
<!-- end-recovered:85b0366cdadfd17e5879 -->

<!-- recovered:707e870c8884e0a27a37 -->
### `c48653bd3c0e` `src/scratch/00476040_sub_wnd_proc.cpp:1-52`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA 00476040 TEditPanel::sub_wnd_proc
// PDB source: pnl_edit.cpp:604-753
//
// Attempt log:
// - the packet-shaped first pass used synthetic router/filter helpers and was
//   125 bytes short with no aligned Win32 call targets;
// - replacing those with windows.h imports and the typed panel chain restored
//   the 25-call topology (the best intermediate was 80% ordered-call parity);
// - the current source follows the period-shaped local scopes and forwarding
//   surface recovered from the original PDB/decompiler line bands.  In
//   particular, the erase RECT is scoped to its paint branch and the four
//   selection DWORDs are separate post-default locals.
// - replacing the reused message output slot with sel_start_after improved
//   the structural diff (926 bytes, 54.26% shape) without changing calls.
// - making WM_MOUSEMOVE an ordinary switch arm produced the best structural
//   checkpoint: 96% ordered-call alignment, 923-byte diff, and -2-byte size
//   gap; the remaining frame is 0x20 versus the original 0x1C.
// - next structural lead: place the WM_PAINT arm before WM_ERASEBKGND so the
//   first low-message call follows the original InvalidateRect/FillRect order.
// - swapping the saved parameter declaration order did not change emitted
//   code; the original still points to direct parameter homes and a 1C frame.
// - the direct-parameter plus separate selection flag form restored the 1C
//   frame and 84% shape; test one canonical lParam copy with that local order.
// - restoring the original erase-before-paint source order improved the
//   positional diff to 867 bytes with exact frame and call-count parity.
// - mutating the long lParam formal with the proven unsigned high-word shift
//   recovered the original 994-byte boundary and reduced the diff to 771.
//   The executable keeps lParam in EBX through the forwarding calls and tail.
// - using msg <= WM_ERASEBKGND with the inverted erase predicate, msg <=
//   WM_MOUSEMOVE, and a post-currentPanel coordinate mask improved the clean
//   reconstruction to 745 bytes with 88.34% shape and 63.75% exact blocks.
// - BINARY NOTE: the original jump-table index is EAX at +0xD4; the current
//   natural sparse-switch source uses ECX there. The original also has a
//   separate late table block and is two bytes longer.
// - failed: a separate lParam copy, parameter-home selection reuse, and an
//   explicit WM_MOUSEMOVE arm did not improve the retained source. The last
//   one broke call and block order, so it was restored.
// - unresolved: jump-index register, selection-local placement, and remaining
//   forwarding/final-tail scheduling.
// - TU-captain probe: inverting the WM_KEYDOWN parent guard kept the non-null
//   forwarding arm inline, restored exact size, and improved standalone diff
//   745 -> 667 with 25/25 ordered calls. Candidate-TU diff improved 794 ->
//   746 while all 22 existing exact owners stayed MATCH.
// - TU-captain probes of message-home reuse, explicit dispatch expression,
//   coordinate locals, and callback-result width were worse or duplicate.
//   Restore each failed form; retain the inverted parent guard only.
// - Final observed standalone result: 994 bytes, 342 instructions, 667 strict
//   differing bytes, 25/25 ordered calls, 0x1C frame. Candidate-TU result:
//   746 differing bytes; shared context changes the emitted basin.
// - BLOCKER: pnl_edit_context.h declares setup as a virtual int method with
//   int format parameters. The target needs a nonvirtual long method with its
//   nested FormatType symbol. This source cannot repair that shared ABI.
```
<!-- end-recovered:707e870c8884e0a27a37 -->
