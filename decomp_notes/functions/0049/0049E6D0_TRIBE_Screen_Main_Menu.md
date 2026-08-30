# Function notes: 0049E6D0 `TRIBE_Screen_Main_Menu`

Module notes: `decomp_notes/scr_main.md`.

## Recovered attempt history

<!-- recovered:747dd6c7636feedf65b1 -->
### `target-session` `build/target_sessions/0049E6D0_TRIBE_Screen_Main_Menu.json:1-42`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1141; shape=88.99521531100478: Baseline current natural reconstruction: 1271 bytes vs original 1281, frame 0x230, 44/44 ordered calls, owner match; first codegen mismatch is zero/button-base register basin and direct-call alignment reports final call-site shift.
probe 2 liveness; result=MISMATCH; diff=1142; shape=85.57457212713936: H1 retry after source repair: remove named panel_height and reread pnl_hgt directly at each text-layout use; tests direct member reload schedule.
probe 3 liveness; result=MISMATCH; diff=1141; shape=88.99521531100478: H2: make button_base non-const; tests whether const pointer qualification changes VC5 register lifetime/coloring without changing ownership. [same emitted code as probe 1]
probe 4 liveness; result=MISMATCH; diff=1141; shape=88.99521531100478: H3: use one natural button_ptr for the clear loop and create loop, then direct this->button for the final tab copy; tests whether original pointer lifetime/color is one source local.
probe 5 liveness; result=MISMATCH; diff=1141; shape=88.99521531100478: H4: declare button_ptr before RECT/tab/temp locals; tests declaration-order effects on VC5 register coloring and 4-byte temp/EH stack placement. [same emitted code as probe 4]
probe 6 behavior; result=MISMATCH; diff=1141; shape=89.47368421052632: H5: use original assembly's RECT member offsets: circle x from rect.right, y from rect.top, second text y from rect.top, centering bound from rect.right; tests whether decompiler field labels hid the stack window.
probe 7 layout; result=MISMATCH; diff=1141; shape=91.14832535885168: H6: remove the unexplained temp_str +4 offset and use buffer base for get_string, test, concatenation, and create_text; raw assembly addresses the buffer at +0x40.
probe 8 liveness; result=MISMATCH; diff=1141; shape=91.14832535885168: H7 retry: use separately scoped i/j loop indices after VC5's function-scope for-variable rule; tests distinct local lifetimes.
probe 9 abi; result=MISMATCH; diff=1141; shape=91.14832535885168: H9: cast set_text state arguments explicitly to short zero; tests whether VC5's narrow parameter type selects original immediate-zero lowering.
probe 10 liveness; result=MISMATCH; diff=1141; shape=91.14832535885168: H10: initialize clear_button directly from this->button instead of aliasing button_base; tests alias graph effects on EBX/EAX zero and base-pointer colors. [same emitted code as probe 9]
probe 11 context; result=MISMATCH; diff=1141; shape=91.14832535885168: H11: replace local string literals with repository-known external string symbols from original pushes (Main Menu, scr1, empty, circlep2, space); tests relocation and literal-lowering identity.
probe 12 liveness; result=MISMATCH; diff=1141; shape=91.14832535885168: H12: mark button base and clear cursor as register locals; tests whether explicit period register hints recover original EBX base coloring. [same emitted code as probe 11]
probe 13 control-flow; result=MISMATCH; diff=1141; shape=91.14832535885168: H13: replace the descending pointer clear loop with an ascending indexed member loop; tests whether the original rep stosd came from a different natural loop form. [same emitted code as probe 12]
probe 14 abi; result=MISMATCH; diff=1141; shape=91.14832535885168: H14: cast create_button zero arguments explicitly to long; tests whether ABI width spelling changes immediate versus saved-zero register lowering.
probe 15 abi; result=MISMATCH; diff=1141; shape=91.14832535885168: H15 retry after pointer-type repair: use TPanel** local button and tab cursors with create_button cast; tests base-typed ownership codegen.
probe 16 layout; result=MISMATCH; diff=1141; shape=91.14832535885168: H16: replace the pointer clear loop with natural memset(this->button, 0, sizeof(this->button)), based on exact VC5 constructor donor memset lowering; test zero/base register basin.
probe 17 behavior; result=MISMATCH; diff=1140; shape=92.32613908872902: H17: model assembly's adjusted panel-height accumulator (pnl_hgt-0x3c, then +0x12/+0x24) and use pnl_wid for centering bound; tests direct arithmetic ownership and register reuse.
probe 18 liveness; result=MISMATCH; diff=1140; shape=92.32613908872902: H18: name circle_y = rect.top+1 before TPicturePanel::setup; tests whether a short-lived argument local restores original y-first evaluation and delays pnl_x load.
probe 19 liveness; result=MISMATCH; diff=1140; shape=92.32613908872902: H19: bind rect.right to circle_x before setup, while retaining circle_y; tests whether named coordinate intermediates reproduce original load/dependency scheduling.
probe 20 liveness; result=MISMATCH; diff=1140; shape=92.32613908872902: H20: make circle coordinates explicit mutable locals with ordered subtract/add/increment before setup; tests whether statement boundaries reproduce original argument scheduling. [same emitted code as probe 19]
probe 21 liveness; result=MISMATCH; diff=1140; shape=92.32613908872902: H21: remove the pre-zero button_base alias; derive clear cursor and final tab source directly from this->button, mirroring exact donor memset ownership. [same emitted code as probe 18]
probe 22 other; result=MISMATCH; diff=1140; shape=92.32613908872902: H22: parenthesize circle x subtraction before adding three; tests VC5 expression-tree scheduling without changing behavior. [same emitted code as probe 21]
probe 23 liveness; result=MISMATCH; diff=1140; shape=92.32613908872902: H23: hoist copy1/copy2 address-pointer declarations to function scope, reflecting original address-taken locals; test entry register allocation and stack homes. [same emitted code as probe 22]
probe 24 abi; result=MISMATCH; diff=1140; shape=92.32613908872902: H24: narrow adjusted panel_height local from long to int, matching decompiler's iVar9 width evidence; test declaration type effects. [same emitted code as probe 23]
probe 25 layout; result=MISMATCH; diff=1140; shape=92.32613908872902: H25: retain a named RECT* alias for all get_text_rect and field accesses; tests whether the original address-taken rectangle ownership changes VC5 load scheduling. [same emitted code as probe 20]
probe 26 liveness; result=MISMATCH; diff=1140; shape=92.32613908872902: H26: use a pre-body button_base alias as the memset target and reuse it for create/tab cursors; tests alias lifetime on the original EBX base basin.
probe 27 layout; result=MISMATCH; diff=1140; shape=92.32613908872902: H27: spell the button memset through &button[0] and a constant element count; tests compiler pointer-expression basin while preserving proven 0x1c-byte fill. [same emitted code as probe 26]
probe 30 abi; result=MISMATCH; diff=1140; shape=92.32613908872902: H1: qualify the TPicturePanel::setup call; tests whether explicit nonvirtual ownership recovers the original picture argument schedule without changing the direct target. [same emitted code as probe 29]
probe 31 abi; result=MISMATCH; diff=1140; shape=92.32613908872902: H2: qualify nonvirtual TScreenPanel, TEasy_Panel, and TPanel calls to match same-TU donor spelling; tests canonical direct-call ownership and argument scheduling. [same emitted code as probe 30]
probe 32 liveness; result=MISMATCH; diff=1166; shape=91.78743961352657: H3: initialize tab_list with this as Ghidra reconstructs tabList[0]=this before the base call; tests whether that apparent source initializer affects the prologue stack and register basin.
probe 33 behavior; result=MISMATCH; diff=1140; shape=92.32613908872902: H4: rewrite the circle x as rect.right - (pnl_x - 3), an equivalent period integer tree; tests whether VC5 preserves the original delayed sub/add schedule. [same emitted code as probe 31]
probe 34 behavior; result=MISMATCH; diff=1140; shape=92.32613908872902: H5: reverse the commutative circle y expression to 1 + rect.top; tests expression-tree operand order against the original delayed INC/push schedule. [same emitted code as probe 33]
probe 35 liveness; result=MISMATCH; diff=1140; shape=92.32613908872902: H6: initialize the final tab-copy index at declaration; tests whether an early real zero value recovers EAX zero coloring without fake volatility. [same emitted code as probe 34]
probe 36 abi; result=MISMATCH; diff=1140; shape=92.32613908872902: H7: model TEasy_Panel factory and sizing methods as virtual in the canonical class surface, then qualify the proven direct calls; tests whether vtable context changes the VC5 register basin.
probe 37 context; result=MISMATCH; diff=1140; shape=92.32613908872902: H8: restore the period Windows RECT declaration context used by the exact same-TU Main Error donor; tests whether SDK header state changes this constructor's VC5 basin.
probe 38 liveness; result=MISMATCH; diff=1140; shape=92.32613908872902: H9: use unqualified member expressions for the picture setup, matching the exact TPicturePanel donor source; tests whether implicit-this ownership changes argument load scheduling. [same emitted code as probe 35]
probe 39 liveness; result=MISMATCH; diff=1140; shape=92.32613908872902: H10: remove const from the long-lived button-base pointer; tests whether VC5 treats its alias as mutable and selects the original EBX base basin. [same emitted code as probe 38]
probe 40 control-flow; result=MISMATCH; diff=1140; shape=92.32613908872902: H11: spell the setup failure guard as natural boolean negation; tests whether VC5 branch polarity and EH-state scheduling match the original. [same emitted code as probe 39]
probe 41 liveness; result=MISMATCH; diff=1140; shape=92.32613908872902: H12: hoist button_width to function scope and assign it before the setup loop; tests whether a long-lived ESI width value restores EBX as the button base. [same emitted code as probe 40]
probe 42 control-flow; result=MISMATCH; diff=1116; shape=92.54807692307692: H13: replace memset with an ascending pointer clear loop; tests whether period VC5 recognizes the original REP fill while preserving EBX button-base ownership.
probe 43 control-flow; result=MISMATCH; diff=1140; shape=92.32613908872902: H14: correct the ascending pointer clear-loop variant by resetting clear_button before button creation; tests its REP lowering and full call surface against the original.
probe 44 abi; result=MISMATCH; diff=1140; shape=92.32613908872902: H15: add the proven unused TPanel virtual slots through handle_paint; tests whether the canonical inherited vtable surface changes constructor register allocation.
```
<!-- end-recovered:747dd6c7636feedf65b1 -->

<!-- recovered:3be20aa58dabed8f96b8 -->
### `ee72aee0191a` `src/scratch/0049E6D0_TRIBE_Screen_Main_Menu.cpp:1-47`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0049E6D0 TRIBE_Screen_Main_Menu ctor (1281B)
// Scr_main.cpp lines 85-193
// EH-framed constructor
// Attempt log:
// - Baseline reconstruction restores the period TPanel/TEasy/TScreenPanel
//   ownership, 0xF4/0x478 base boundaries, five-button setup loop, text
//   layout branches, picture panel, and final tab/child wiring.
// - Restored the four-argument virtual fixed-position calls from the original;
//   call count/order is now 44/44 and all three height/width/y-position call
//   families are present.
// - Matched the EH frame (0x230), setup guard, pointer-clearing loop, reused
//   panel-height local, member-owned picture lifetime, and pointer-copy tab
//   list.  The remaining drift is compiler register/address scheduling: the
//   rebuilt button-base/zeroing basin does not retain the original EBX/EAX
//   coloring and the constructor remains 10 bytes short.
// - Tested the full typed TPanel/TEasy virtual surface from the constructor
//   vtable and call evidence; emitted code was unchanged, so the probe was
//   rolled back.
// - Left in scratch after the bounded VC5 pass; no inline asm or codegen-only
//   volatile/offset scaffolding was retained.
// - Structural follow-up: reordered local declarations, reused one button
//   cursor, reused the loop index, and tested the pointer base type. These
//   forms emitted the same 1271-byte function.
// - A 0x204-byte temp buffer changed the frame to 0x234 and was rolled back.
//   The unresolved structural lead is VC5's zero-register choice: the rebuilt
//   code uses EBX for zero and ESI for the button base, while the original
//   uses EAX for zero and EBX for the button base. This saves ten bytes.
// - Sustained probe pass: 28 recorded checks. Direct buffer base, period string
//   symbols, RECT field offsets, and the adjusted panel-height accumulator
//   moved the clean result to 1272 bytes with 60.88% exact-block coverage.
//   The adjusted value is pnl_hgt - 0x3C; later y values add 0x12 and 0x24.
//   The centering bound reads pnl_wid - rect.right - 5, as the bytes prove.
// - Tested 20+ distinct declaration, alias, loop, type, string, memset, and
//   coordinate forms. Duplicate codegen ruled out pointer aliases, casts,
//   register hints, loop direction, and coordinate temporaries.
// - Follow-up claim probes H1-H15 tested explicit direct-call qualification,
//   tab-list initialization, equivalent x/y expression trees, early local
//   initialization, virtual/header context, pointer constness, setup guard
//   spelling, and function-scope button width. These forms did not change
//   emitted code. An ascending pointer clear loop reached 1116 differing
//   bytes and 1273 bytes, but it introduced three wrong direct getter targets;
//   resetting its cursor returned to the clean 1140-byte result. It was not
//   retained. The remaining evidence is the original EBX button-base/EAX zero
//   basin and the one picture-setup scheduling hunk.
// - Current clean source is pinned after the pass. Remaining mismatch is the
//   prologue zero/button-base register basin plus one picture-setup schedule.
// FLAGS: /GX (EH)
```
<!-- end-recovered:3be20aa58dabed8f96b8 -->
