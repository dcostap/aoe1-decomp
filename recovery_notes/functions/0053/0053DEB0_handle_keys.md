# Recovery journal: 0053DEB0 `handle_keys`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/vw_main.cpp`.
- PDB source: `C:\msdev\work\age1_x1\vw_main.cpp`.
- Earlier recovery note: `recovery_notes/vw_main_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:aa236c733b225a2943cd -->
### `target-session` `build/target_sessions/0053DEB0_handle_keys.json:1-62`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=438; shape=87.31343283582089: Baseline current clean natural source before new probes; establish metrics and mismatch maps.
probe 2 liveness; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 2: inline the quotient around the truncating cast so VC5 can keep ST0 live across __ftol, matching original fld/fld qword/fidiv topology.
probe 4 context; result=MISMATCH; diff=436; shape=84.01486988847584: Hypothesis 3: use the proven shared DAT_00577900/04/08 extern constants, as the exact sibling do_auto_scroll does and the original target references three absolute constants.
probe 6 liveness; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 4: remove the named key_state alias and use the original decompiler's direct keyboard-array accesses; this tests whether the alias causes excess local pressure and the wrong x87/home topology.
probe 8 liveness; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 5: remove the explicit elapsed local and compute the unsigned delta directly, matching the original decompiler's absent elapsed variable and testing compiler scratch placement. [same emitted code as probe 6]
probe 10 abi; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 6: use int for the __ftol truncation result, matching the decompiler's iVar7 type instead of long, and test its local-home and x87 effects. [same emitted code as probe 1]
probe 13 liveness; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 7: compare quotient minus whole directly instead of mutating scroll_dist2 before the threshold, matching the original decompiler's extraout_ST0 - iVar7 expression and preserving x87 quotient lifetime.
probe 15 abi; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 8: use unsigned changed, matching Ghidra's uVar10 return/predicate type, to test whether signedness affects branch and local topology. [same emitted code as probe 10]
probe 17 abi; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 9: use the long return surface proven by exact RGE_Main_View::handle_idle's caller declaration, testing whether the source ABI candidate affects codegen. [same emitted code as probe 15]
probe 19 layout; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 10: reverse the declaration order of the two short directions, testing whether VC5 assigns the original horz/vert homes by declaration order rather than first-use order. [same emitted code as probe 17]
probe 21 variant; result=MISMATCH; diff=438; shape=87.31343283582089: variant lab build\variant_lab\0053DEB0_handle_keys\20260817_141052: 6 variants, 0 invariant-eligible, 0 exact
probe 22 abi; result=MISMATCH; diff=457; shape=82.20640569395017: Hypothesis 11: test a double scroll accumulator against the original x87 temporary evidence; this probes whether VC5's float local store is the controlling basin.
probe 24 liveness; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 12: move scroll_dist to function scope, matching the decompiler's function-level fVar1 and testing whether its lifetime changes the direction/x87 homes. [same emitted code as probe 19]
probe 26 layout; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 13: declare the keyboard array after scalar locals, matching Ghidra's local listing where pbKeyState is last, to test stack-home assignment. [same emitted code as probe 24]
probe 28 liveness; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 14: make the __ftol integer result function-scoped, matching Ghidra's function-level iVar7 temporary, to test declaration lifetime and stack-home placement. [same emitted code as probe 26]
probe 30 layout; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 15: declare changed before the direction and float locals, following Ghidra's iVar7-before-direction listing, to test stack-home and register pressure effects. [same emitted code as probe 28]
probe 32 abi; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 16: replace suffixed local class names with canonical RGE symbols, matching exact same-TU donors and restoring direct-call ABI identity for get_paused and handle_keys.
probe 33 layout; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 17: use the reviewed sibling TDrawArea/RenderArea ownership at this+20 instead of a target-only host struct, matching original foreground-window access and canonical layout. [same emitted code as probe 32]
probe 34 layout; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 18: model player.selected_obj with the canonical RGE_Static_Object pointer type instead of a temporary RGE_Player pointer cast, testing ownership and virtual-surface effects. [same emitted code as probe 33]
probe 35 layout; result=MISMATCH; diff=438; shape=87.31343283582089: Hypothesis 19: remove redundant selected-object casts after correcting the field type, testing whether direct typed ownership changes VC5 liveness or register coloring.
probe 36 context; result=MISMATCH; diff=127; shape=88.05970149253731: Hypothesis 20: use only the original threshold constants DAT_00577904/08 while retaining literal 1.0/0.0, isolating the prior all-constant probe's quantization gain from its frame loss.
probe 37 layout; result=MISMATCH; diff=400; shape=86.76470588235294: Hypothesis 21: widen direction locals to int to test whether their dword stores and later word compares unlock the original +10/+14 stack homes; retained only if evidence supports it.
probe 39 context; result=MISMATCH; diff=127; shape=88.05970149253731: Hypothesis 22: add the proven DAT_00577900 initial-distance symbol to the threshold-constant best source, testing whether the remaining literal mismatch and frame topology converge.
probe 40 layout; result=MISMATCH; diff=127; shape=88.05970149253731: Hypothesis 23: place scroll_dist2 before the two short directions, testing the compiler's stack allocation order for the required +10/+14 direction homes and +18 x87 scratch. [same emitted code as probe 39]
probe 41 liveness; result=MISMATCH; diff=127; shape=88.05970149253731: Hypothesis 24: apply a period-plausible register hint to the x87 accumulator, testing whether it removes the current scroll_dist2 stack home and exposes the original direction homes. [same emitted code as probe 40]
probe 42 layout; result=MISMATCH; diff=124; shape=89.17910447761194: Hypothesis 25: test a 260-byte keyboard array with the threshold-constant best source; prior lab evidence showed this can reserve the original 0x118 frame, but Ghidra's 256-byte type makes it diagnostic only.
probe 43 liveness; result=MISMATCH; diff=124; shape=89.17910447761194: Hypothesis 26: with threshold symbols and the frame-restoring array, compare quotient minus whole directly to avoid storing scroll_dist2 before __ftol, targeting the original qword/+18 x87 topology. [same emitted code as probe 42]
probe 44 liveness; result=MISMATCH; diff=437; shape=88.43283582089552: Hypothesis 27: remove the named whole local and express truncation inline in both threshold arms, testing whether VC5 keeps quotient/whole on x87 and shifts direction homes.
probe 46 liveness; result=MISMATCH; diff=124; shape=89.17910447761194: Hypothesis 28: remove the named key_state pointer while retaining the frame-restoring array and constants, testing direct array ownership against the original decompiler form. [same emitted code as probe 45]
probe 50 liveness; result=MISMATCH; diff=346; shape=95.16728624535315: Hypothesis 1: compute elapsed = now - last_key_scroll_time immediately after debug_timeGetTime, before key_scrolling gate; original computes EAX delta before testing key_scrolling, so this tests source evaluation order and local-home topology.
probe 51 liveness; result=MISMATCH; diff=346; shape=95.16728624535315: Hypothesis 2: make elapsed a block-local declaration initialized immediately after the timer call, testing whether function-scope lifetime created the extra four-byte home that shifted the proven 256-byte keyboard buffer. [same emitted code as probe 50]
probe 52 layout; result=MISMATCH; diff=346; shape=95.16728624535315: Hypothesis 3: declare the 256-byte keyboard buffer after scalar and pointer locals while retaining precomputed elapsed; test whether VC5 places the buffer at original esp+28 without synthetic padding. [same emitted code as probe 51]
probe 53 liveness; result=MISMATCH; diff=127; shape=88.05970149253731: Hypothesis 4: remove the named elapsed local and use the direct unsigned delta expression in the quotient; this tests whether the original hoisted delta uses no separate home, allowing qword temp and 256-byte keyboard storage to overlap. [same emitted code as probe 49]
probe 54 layout; result=MISMATCH; diff=337; shape=98.51301115241635: Hypothesis 5: use the proven 256-byte keyboard buffer directly (GetKeyboardState(keys), indices 0x25-0x28) while retaining precomputed elapsed; this tests whether original esp+28 and byte offsets come from direct buffer ownership rather than a +4 alias.
probe 55 context; result=MISMATCH; diff=322; shape=99.62825278810409: Hypothesis 6: preserve the binary-observed DAT_00577908 symbol in the low-fraction quantization arm instead of folding it to 0.0f; the original has a distinct DAT_00577908 load and shared faddp tail.
probe 56 liveness; result=MISMATCH; diff=329; shape=98.51301115241635: Hypothesis 7: form each quantized result as (float)whole + threshold rather than threshold followed by compound add; test x87 operand order because original has faddp without the rebuilt fxch.
probe 57 liveness; result=MISMATCH; diff=329; shape=98.51301115241635: Hypothesis 8: assign the whole-unit value first, then compound-add the selected threshold; test the opposite x87 stack producer order for the original faddp without fxch. [same emitted code as probe 56]
probe 58 control-flow; result=MISMATCH; diff=331; shape=98.5239852398524: Hypothesis 9: select DAT_00577908 or DAT_00577904 in the two arms, then add whole once in a common tail; original has one shared faddp block after both threshold loads.
probe 59 liveness; result=MISMATCH; diff=331; shape=98.5239852398524: Hypothesis 10: carry the selected threshold through a named float local, then add whole; test whether an addressable threshold value recovers the original two-load faddp topology. [same emitted code as probe 58]
probe 60 liveness; result=MISMATCH; diff=331; shape=98.5239852398524: Hypothesis 11: keep the fractional result in a separate float local before selecting the threshold and adding whole; decompiler shows a distinct fraction expression and a common fVar11 = fVar11 + whole tail. [same emitted code as probe 59]
probe 61 liveness; result=MISMATCH; diff=331; shape=98.5239852398524: Hypothesis 12: model decompiler's separate output fVar11 and extraout_ST0 explicitly with fraction, quantized, and final scroll_dist2 locals; test whether distinct lifetimes recover the original faddp tail. [same emitted code as probe 60]
probe 62 control-flow; result=MISMATCH; diff=371; shape=97.7859778597786: Hypothesis 13: use the decompiler's explicit predicate DAT_00577904 <= fractional value, with DAT04 in the true arm and DAT08 in the false arm; test branch polarity and x87 block ordering.
probe 63 context; result=MISMATCH; diff=366; shape=97.02602230483271: Hypothesis 14: mirror the decompiler's direct 0.5f/0.0f threshold source and common whole addition, testing whether literal period constants select the original faddp basin.
probe 64 control-flow; result=MISMATCH; diff=371; shape=97.41697416974169: Hypothesis 15: keep threshold symbols but write the low-fraction predicate as DAT_00577904 > scroll_dist2; test equivalent compare spelling for x87 branch and faddp scheduling.
probe 65 liveness; result=MISMATCH; diff=331; shape=98.5239852398524: Hypothesis 16: separate quotient/fraction temporaries from the final scroll_dist2 output, matching the decompiler's fVar11 and extraout_ST0 roles; test whether this produces original faddp without fxch. [same emitted code as probe 61]
probe 66 context; result=MISMATCH; diff=331; shape=98.5239852398524: Hypothesis 17: use the repository's reviewed non-const extern float declarations for DAT_00577900/04/08, testing whether const qualification drives the residual x87 stack exchange.
probe 69 layout; result=MISMATCH; diff=127; shape=88.05970149253731: Hypothesis 1: preserve a real 256-byte keyboard buffer but pass a key_state alias at keys+4; test whether the natural alias lifetime recovers the 0x118 frame and target short homes without changing key reads. [same emitted code as probe 68]
probe 71 liveness; result=MISMATCH; diff=127; shape=88.05970149253731: Hypothesis 2: remove the named elapsed local and cast the direct unsigned now-minus-last-key-scroll expression; test the target EAX subtraction order, x87 duplicate, and natural stack frame. [same emitted code as probe 69]
probe 73 control-flow; result=MISMATCH; diff=436; shape=84.01486988847584: Hypothesis 3: load the observed DAT_00577908 zero threshold in the low-fraction arm, select DAT_00577904/DAT_00577908, then add whole in one common statement; test the target threshold call/load order and faddp basin.
probe 75 liveness; result=MISMATCH; diff=127; shape=88.05970149253731: Hypothesis 4: move the quantization whole-number local to function scope; test whether VC5 declaration lifetime produces the target 0x118 frame, short homes, and unspilled x87 quotient. [same emitted code as probe 71]
probe 77 layout; result=MISMATCH; diff=127; shape=88.05970149253731: Hypothesis 5: mirror the Ghidra local order with scroll_dist2 before vert_scroll before horz_scroll; test declaration-order-driven homes against original horz +0x10, vert +0x14, and frame 0x118. [same emitted code as probe 75]
probe 79 liveness; result=MISMATCH; diff=127; shape=88.05970149253731: Hypothesis 6: give scroll_dist2 a natural zero initializer at declaration; test VC5's local home and FPU lifetime against the target without synthetic storage. [same emitted code as probe 77]
probe 81 control-flow; result=MISMATCH; diff=436; shape=84.01486988847584: Hypothesis 7: mirror the exact same-TU do_auto_scroll branch-local quantization: load DAT_00577908 or DAT_00577904 and add whole inside each arm; test original threshold block and faddp shape. [same emitted code as probe 73]
probe 83 control-flow; result=MISMATCH; diff=436; shape=84.01486988847584: Hypothesis 8: use a natural ternary to select DAT_00577908 or DAT_00577904, then add whole; test whether VC5 emits the target shared faddp tail and branch polarity. [same emitted code as probe 81]
probe 85 liveness; result=MISMATCH; diff=127; shape=88.05970149253731: Hypothesis 9: make the whole-number subtraction explicitly float, matching the exact do_auto_scroll donor and target fsub ST1 topology; test whether this removes the quotient home and recovers the frame. [same emitted code as probe 79]
probe 87 liveness; result=MISMATCH; diff=436; shape=84.01486988847584: Hypothesis 10: combine explicit float whole subtraction with the donor-supported DAT_00577908/DAT_00577904 branch-local quantization; test whether this reproduces the original fild/fxch/fsub/faddp chain. [same emitted code as probe 83]
probe 89 context; result=MISMATCH; diff=436; shape=84.01486988847584: Hypothesis 11: transplant the same-TU do_auto_scroll declaration order and explicit branch-local quantization into handle_keys; test whether registered vw_main context selects the original x87 basin and frame. [same emitted code as probe 87]
probe 91 layout; result=MISMATCH; diff=136; shape=84.32835820895522: Hypothesis 12: adopt the natural direct 256-byte key buffer and local order proven by the same-TU scroll donor: shorts/float/scalars first, keys last, GetKeyboardState(keys), indices 0x25-0x28, and block-local elapsed.
probe 93 layout; result=MISMATCH; diff=124; shape=89.17910447761194: Hypothesis 13 (diagnostic only): enlarge the keyboard array to 260 bytes while keeping the proven +4 pointer and key reads; measure whether the registered context reaches frame 0x118 and target local homes. [same emitted code as probe 46]
probe 94 layout; result=MISMATCH; diff=124; shape=89.17910447761194: Hypothesis 14 (diagnostic only): retain the 260-byte frame probe but move the key array after scalar locals, matching the same-TU donor's natural declaration order; test whether VC5 moves shorts from +0x14/+0x18 to target +0x10/+0x14. [same emitted code as probe 93]
probe 96 liveness; result=MISMATCH; diff=127; shape=88.05970149253731: Hypothesis 15: scope scroll_dist2 inside the non-selected player fallback, where it is the only owner of the scroll-distance path; test whether reduced lifetime removes the target quotient spill and shifts homes naturally. [same emitted code as probe 85]
probe 98 variant; result=MISMATCH; diff=436; shape=84.01486988847584: Hypothesis 16 (diagnostic only): combine the 260-byte frame probe with explicit float whole subtraction and the observed DAT_00577908 branch; test whether removing the quotient home also corrects short homes.
```
<!-- end-recovered:aa236c733b225a2943cd -->

<!-- recovered:c882d0cbf37baef9f5d0 -->
### `ed3a3f85db1c` `src/scratch/0053DEB0_handle_keys.cpp:1-73`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA 0053DEB0 RGE_Main_View::handle_keys
// vw_main.cpp:258-423
// Attempt log:
// 1: Natural source from packet/decompiler, local type surfaces and Win32 imports.
// 2: First natural /O2 build compiled but was 928 bytes vs original 964; broad behavior represented but too short for configured size.
// 3: Fixed foreground-window surface: original compares GetForegroundWindow() to `[this+20]+4`, so modeled host pointer at +0x20 with HWND at +0x04 instead of HWND directly at +0x20.
// 4: After host fix natural build was still short (944 bytes), indicating remaining source/codegen missing bulk rather than just offsets.
// 5: Added a volatile diagnostic pad block only to recover exact 964-byte size for comparison; it causes first mismatch at offset 2 and is intentionally documented as sizing/probe scaffolding, not a match path.
// 6: Probed /Ob0: no size/codegen improvement over default. Probed /Og- and /Od: both gave exact size but very broad 91.7012% positional diff from offset 0; flags removed.
// 7: Implemented pause/prog_mode/foreground/active early failure path and key_scrolling reset on failure.
// 8: Implemented selected-object movement mode for game_mode 0x12 using arrow key state bytes, object +0x38/+0x3c coordinates, prog_info +0x8d8 movement scalar, and virtual +0x34 move call.
// 9: Implemented map scrolling fallback: horz/vert short locals, debug_timeGetTime, key_scrolling/last_key_scroll_time, divisor quantization to 0/0.5/whole, max-distance clamp, set_view_loc calls, and repaint of main/map views.
// 10: Remaining blocker is broad stack/local/FPU topology mismatch. Original uses FPO `sub esp,118h` with keys at esp+28, horz/vert at esp+10/+14 and qword fild temp at +18; current C either compiles too short or needs artificial pad that shifts prologue and early layout.
// 11: No accepted_drift proposal: diff is broad and current exact-size build contains diagnostic volatile padding, while natural builds are size-short.
// 12: Clean-source reset removed the diagnostic pad; keep the typed key and scroll model as the baseline before import or guard probes.
// 13: Binary-backed import correction: Win32 foreground and keyboard-state calls use the period DLL-import surface, matching the two original indirect call sites.
// 14: Import correction aligned all 13 ordered calls and removed the target-count gap; remaining drift is frame/local topology and early block layout, not key-call identity.
// 15: A positive active-view block with the sibling scroll routine's short-circuit guard moved the first structural mismatch to the keyboard local and reduced the positional diff to 447 bytes.
// 16: The natural 256-byte direct keyboard buffer keeps source ownership clear but leaves the VC5 frame four bytes short; over-allocation and pointer-offset variants were diagnostic only and rolled back.
// 17: Explicit elapsed-time locals were optimized to the same x87 form; the remaining structural lead is VC5 local-home allocation, not call or behavior topology.
// 18: The proven unsigned key-scroll interval changes the frame to 0x114, emits the original qword/fidiv stack topology, and improves the diff to 446.
// 19: A named key-state pointer at keys+4 aligns all four keyboard tests and the API home; with a diagnostic 260-byte buffer it reaches diff 437 and 71.64% exact-block coverage.
// 20: The 260-byte buffer is allocation scaffolding, not canonical source; the normalized 256-byte alias source remains diff 438 with frame 0x114.
// 21: The remaining structural lead is a four-byte local-home shift: current shorts are at esp+14/+18 while the original uses esp+10/+14; all calls and key accesses align.
// 22: The original decompiler lists DAT_00577900/04/08.  Threshold externs
//     DAT_00577904/08 reduced the natural source to 964 bytes and diff 127,
//     with all 13 ordered calls and exact size.  Adding DAT_00577900 was neutral.
// 23: Canonical RGE class and TDrawArea ownership, typed selected-object fields,
//     direct key-array indexing, declaration-order changes, and ABI width changes
//     were codegen-neutral or worse.  Keep the canonical typed ownership.
// 24: A diagnostic 260-byte key array restored frame 0x118 and improved diff 124
//     with 71.64% exact-block coverage, but contradicts the proven 256-byte array.
//     It was rolled back.  The remaining blocker is the natural local-home shift.
// 25: Inline truncation, double/register accumulator, widened directions, direct
//     quotient forms, and local scope variants did not beat the threshold source.
// GIVEUP: left in scratch for future source-shape/stack-local topology work.
// BLOCKER: The executable frame is 0x118, while the natural 256-byte keyboard
// state array produces 0x114. A 260-byte array reaches the target frame but
// contradicts the proved GetKeyboardState buffer ownership. Do not pad it.
// 26: Fresh probes moved the unsigned elapsed delta before the key_scrolling
//     test and modeled GetKeyboardState(keys) with indices 0x25-0x28. This
//     reached frame 0x118 and exact keyboard-buffer offsets. It reached 99.63%
//     exact-block coverage, but added one x87 exchange and shifted the tail.
// 27: Using DAT_00577908 in the low-fraction arm restored the original two
//     threshold loads and shared faddp shape. Natural operand, common-tail,
//     literal, local, comparison, and extern-qualification variants did not
//     remove the one x87 exchange.
// 28: The improved probe was restored. The clean source remains authoritative.
// GIVEUP: The remaining blocker is the natural VC5 x87 basin for the shared
//         threshold addition. No accepted_drift proposal is supported.
// 29: Fresh target checks confirmed all 13 ordered calls, the
//     handle_keys owner symbol, and the 964-byte boundary. The clean 256-byte
//     key source remains 127 bytes different with a 0x114 frame. Its natural
//     homes are shorts at esp+14/+18 and the qword scratch at esp+1C.
// 30: A diagnostic 260-byte key array reached the 0x118 frame, 964-byte size,
//     and 124-byte difference. It still kept shorts at esp+14/+18. It is not
//     retained because the API writes a 256-byte key state and the executable
//     reads the four arrow keys from the proven esp+28 buffer.
// 31: Direct GetKeyboardState(keys) with key indices 0x25-0x28, donor local
//     order, block-local elapsed, explicit float subtraction, threshold-symbol
//     branches, and local-scope variants were tested. They were duplicates or
//     widened the structural difference. Registered anchor checks stayed exact.
// BLOCKER: The executable keeps the 256-byte key buffer at esp+28, shorts at
//          esp+10/+14, and the qword/x87 scratch at esp+18. Natural VC5 source
//          in the registered context keeps the key buffer and calls correct,
//          but allocates the short homes and quotient spill four bytes later.
//          A 260-byte array fixes only the frame and is not valid source.
// 32: Restored the overloaded set_rect slot in the narrow fallback surface.
//     This fixes the standalone set_redraw target from vslot +1C to +20 and
//     reduces the standalone diff to 127 bytes with all 13 calls aligned.
// 33: A grouped-only owner surface fixed the +20/+78 reads but changed the
//     following exact owner. It was rejected. The natural source keeps the
//     set_rect ABI repair and have_focus alias; grouped context remains open.
```
<!-- end-recovered:c882d0cbf37baef9f5d0 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
