# Function notes: 0043D8A0 `action`

Module notes: `decomp_notes/dlg_dip_module.md`.

## Recovered attempt history

<!-- recovered:6994b6c0e277dded3dad -->
### `target-session` `build/target_sessions/0043D8A0_action.json:1-55`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=2916; shape=81.7762399077278: Baseline current living source: canonical typed surface and natural nested dispatch; frame 0x108, 124 calls, 2916 strict diff, 81.78% shape, 3105 rebuilt bytes. Original assembly and Ghidra excerpt show source-order/default-action and variable-home differences.
probe 2 control-flow; result=MISMATCH; diff=2904; shape=81.31487889273356: Hypothesis 1: model original early base-action guard as panel==0 || event!=1 before ok/cancel dispatch; also use cost*scale <= player attribute-total from the decompiler's emitted x87 operand order. Test branch layout and FPU topology.
probe 3 control-flow; result=MISMATCH; diff=2916; shape=81.7762399077278: Hypothesis 2: retain the early guard plus ok/cancel else dispatch, but restore the baseline >= comparator because the <= spelling materialized a scaled-cost temporary and worsened x87 lowering. Isolate branch topology from arithmetic operand order. [same emitted code as probe 1]
probe 4 control-flow; result=MISMATCH; diff=2916; shape=81.7762399077278: Hypothesis 3: split the outer null-panel and event guards into two statements. Original entry uses test panel, while the combined boolean candidate used a zero-register cmp; test whether separate guards recover test/branch topology. [same emitted code as probe 3]
probe 5 liveness; result=MISMATCH; diff=2916; shape=81.66089965397924: Hypothesis 4: declare the ok-loop pointer locals before its player-id local, matching the decompiler's pointer setup then iVar8=1. Test whether VC5 colors tribute as EBP and player id as EDI, as original assembly proves.
probe 6 control-flow; result=MISMATCH; diff=2939; shape=77.85467128027682: Hypothesis 5: use the decompiler's exact branch shape: if(ok) ... else if(panel != cancel) { help, clear, tribute scan, goto base_action; } then shared cancel close tail. This may place the default TPanel::action block at the original +059c.
probe 8 liveness; result=MISMATCH; diff=2916; shape=81.7762399077278: Hypothesis 7: use a period-plausible register local for the ok-loop player id to free EBP for the long-lived wood tribute cursor. Test whether VC5 recovers original EDI id, EBP tribute pointer, and simple ally LEA. [same emitted code as probe 4]
probe 9 liveness; result=MISMATCH; diff=2916; shape=81.66089965397924: Hypothesis 8: make the ok-loop cursor and counter function-scope locals, in pointer/pointer/int declaration order. This tests whether VC5 lifetime coloring, rather than syntax, explains original EBP wood cursor and EDI player counter. [same emitted code as probe 5]
probe 11 liveness; result=MISMATCH; diff=2916; shape=81.89158016147636: Hypothesis 9: move the clear-handler food-button cursor declaration before the four total zero stores, matching original LEA +0554 before stores +0610..+061c. Test clear-block ordering and zero-register liveness.
probe 12 liveness; result=MISMATCH; diff=2898; shape=66.66666666666667: Hypothesis 10: reproduce the decompiler's proven stack aliases in clear: format wood into &tc and stone into &cost, then pass those addresses. Original emits alternating temp-string LEAs, unlike the all-temp_str baseline.
probe 13 liveness; result=MISMATCH; diff=2895; shape=81.66089965397924: Hypothesis 11: isolate only the proven wood-buffer alias (&tc) while restoring temp_str for stone. Determine whether tc alias alone recovers the original alternating LEA without the cost address-taking frame penalty.
probe 14 liveness; result=MISMATCH; diff=2916; shape=81.89158016147636: Hypothesis 12: order top locals as PDB records show: temp_str, cost, tc, instead of the prior cost/tc/temp_str reconstruction. Keep only the clear cursor reorder; test whether this shifts the buffer home to original LEA offsets. [same emitted code as probe 11]
probe 15 liveness; result=MISMATCH; diff=2895; shape=81.66089965397924: Hypothesis 13: combine the PDB-local declaration order with the proven wood alias &tc. Test whether declaration order changes the alias address and preserves the H11 frame while moving more formatting LEAs toward original. [same emitted code as probe 13]
probe 16 liveness; result=MISMATCH; diff=2895; shape=81.66089965397924: Hypothesis 14: reverse generic-loop scalar declaration order to index=0 then player_id=1. Original setup proves EBX=index and EDI=player_id, while the current source emits the opposite colors and swapped count tests. [same emitted code as probe 15]
probe 17 liveness; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 15: match the decompiler's distinct counters: use player_id-1 for every tribute-amount read/write, but keep the separate index for button-array access. This tests the original EDI player-id versus EBX button-index topology.
probe 18 liveness; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 16: preserve the original PDB parameter role name and lifetime through a typed fromPanel alias used by every dispatch and the base fallback. Test whether this keeps panel in EBP while retaining EBX index and EDI player-id colors. [same emitted code as probe 17]
probe 19 liveness; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 17: mark only the panel parameter register, testing a period-supported compiler hint to retain the original panel-in-EBP role after the H15 counter separation. No address is taken. [same emitted code as probe 18]
probe 20 liveness; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 19: reverse ok-loop pointer declaration order to ally cursor then tribute cursor. The original setup colors ally in ESI, tribute in EBP, and player id in EDI; test whether declaration order selects that source-supported topology. [same emitted code as probe 19]
probe 21 liveness; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 21: use a register declaration on the generic button index, testing whether VC5 can retain the original panel in EBP while assigning the proven index to EBX. This is a bounded compiler-color probe, not a final source form. [same emitted code as probe 20]
probe 22 liveness; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 22: split generic counter declarations from their initializers, following the decompiler's independent scalar setup and testing VC5 home/register scheduling without changing behavior. [same emitted code as probe 21]
probe 26 control-flow; result=MISMATCH; diff=2868; shape=83.96770472895041: Second-pass hypothesis 1: make the four generic button handlers one explicit else-if chain. This tests whether VC5 recognizes one dispatch ladder and moves the shared base-action fallthrough, while preserving typed fields and two counter roles. [same emitted code as probe 25]
probe 28 control-flow; result=MISMATCH; diff=2882; shape=85.81314878892734: Second-pass hypothesis 2: express the generic player dispatch as a top-tested for loop with the three observed updates in its increment list. This tests natural for-loop block rotation against the original bottom backedge.
probe 29 control-flow; result=MISMATCH; diff=2870; shape=85.69780853517878: Second-pass hypothesis 3: remove the redundant positive-count guard and let the for-loop own the sole count test. H2 exposed a duplicate test before the early base block; this tests the same rotated handler layout without that extra condition.
probe 31 control-flow; result=MISMATCH; diff=2882; shape=85.81314878892734: Second-pass hypothesis 4: use a top-tested while loop for the generic dispatch, retaining the outer positive-count guard. This separates while rotation from the H2 for increment-list form and tests the natural condition polarity. [same emitted code as probe 28]
probe 33 control-flow; result=MISMATCH; diff=2868; shape=83.96770472895041: Second-pass hypothesis 5: model the proven shared default and four late resource handlers as source labels. Dispatch jumps to one handler block; no-match and invalid paths join one base_action block. This is behavior-backed block ownership, not a layout-only expression. [same emitted code as probe 26]
probe 35 control-flow; result=MISMATCH; diff=2868; shape=83.96770472895041: Second-pass hypothesis 6: retain the outer positive-count guard but use an infinite loop with an explicit bottom break. This tests whether natural break ownership moves the shared base block early without the duplicate top test from H2. [same emitted code as probe 33]
probe 37 liveness; result=MISMATCH; diff=2868; shape=83.96770472895041: Second-pass hypothesis 7: move the generic button cursor declaration to function scope while keeping its assignment inside the positive-count guard. This tests whether handler-block placement depends on cursor scope, without changing address ownership. [same emitted code as probe 35]
probe 39 control-flow; result=MISMATCH; diff=2868; shape=83.96770472895041: Second-pass hypothesis 8: write the positive player-count guard in decompiler-supported zero-left form (0 < player_count). This tests comparison operand ownership at the handler entry without changing the proven guard. [same emitted code as probe 37]
probe 41 liveness; result=MISMATCH; diff=2868; shape=83.96770472895041: Second-pass hypothesis 9: carry player_count through a named player_limit local for the generic guard and backedge. This tests whether the original saved count is a distinct source value that controls block layout and register lifetime. [same emitted code as probe 39]
probe 43 control-flow; result=MISMATCH; diff=2868; shape=83.85236447520184: Second-pass hypothesis 10: move the generic index increment into the do-while condition while retaining separate cursor and player updates. This tests whether VC5's natural post-condition lowering can preserve the original inc-index/add-cursor/inc-player order.
probe 45 control-flow; result=MISMATCH; diff=2811; shape=86.04382929642445: Second-pass hypothesis 11: use a top-tested for loop with an empty increment clause, keeping all three induction updates in the body. This isolates VC5's loop-rotation choice from H2's increment-list scheduling.
probe 46 control-flow; result=MISMATCH; diff=2811; shape=85.92848904267589: Second-pass hypothesis 12: retain H11's for-loop rotation and use an equality terminator. The original count is positive and the observed backedge reaches equality; this tests whether VC5 removes H11's duplicate compare and malformed cold self-loop.
probe 48 liveness; result=MISMATCH; diff=2812; shape=85.92848904267589: Second-pass hypothesis 13: use H11's top-tested empty-increment loop, but move index initialization into the for header. The original emits zero setup immediately before generic count setup; this tests initialization placement and handler layout together.
probe 49 control-flow; result=MISMATCH; diff=2868; shape=84.19838523644752: Second-pass hypothesis 14: retain the positive-count guard but move the for-loop terminator to an explicit top break. This tests whether a natural break target reproduces the early base block while avoiding the compiler's H11 cold self-loop.
probe 50 control-flow; result=MISMATCH; diff=2882; shape=85.81314878892734: Second-pass hypothesis 15: validate the actual empty-increment for form with its proper closing brace. H11's apparent gain came from an accidental standalone empty while statement; this probe tests the valid period-plausible form without that artifact. [same emitted code as probe 31]
probe 53 other; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 1: reverse the commutative cost/scale multiplication spelling in all four tribute guards. Test whether VC5 schedules the original attr-then-cost x87 topology without a staged temporary. [same emitted code as probe 52]
probe 54 other; result=MISMATCH; diff=2858; shape=80.50749711649365: Hypothesis 2: use the original-looking left cost*scale <= available spelling in the current clean structural source. Test whether this changes the x87 order toward original without changing the surrounding handler CFG.
probe 55 liveness; result=MISMATCH; diff=2870; shape=84.77508650519032: Hypothesis 3: bind each tribute guard's get_player result in a short-lived local before the left cost*scale comparison. This forces the side-effectful receiver call before x87 operand setup and tests a natural source lifetime for the original attr-then-cost sequence.
probe 56 control-flow; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 4: reconstruct the PDB-supported late handler ownership with four explicit dispatch labels and a shared base_action target. This reproduces the original comparison-before-handler source order before testing direct-return placement. [same emitted code as probe 53]
probe 57 control-flow; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 5: keep the PDB-supported explicit handler labels, but use a direct base-action return at the no-match fallthrough instead of a goto target. This tests whether VC5 places the shared base call at the original +059c block. [same emitted code as probe 56]
probe 59 control-flow; result=MISMATCH; diff=2869; shape=83.96770472895041: Hypothesis 6: place the no-match base return inside the positive player-count scope and retain the outer fallback return. This tests whether source block ownership moves the shared base call before cold tribute handlers without changing behavior.
probe 61 abi; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 7: qualify the direct base call as this->TPanel::action. Test whether the explicit receiver expression changes only the shared fallback block placement while preserving the known direct target and ABI. [same emitted code as probe 57]
probe 63 control-flow; result=MISMATCH; diff=2968; shape=83.62168396770473: Hypothesis 1 compile repair: keep the PDB-shaped explicit guard and handler chain, with goto-safe function-scope loop homes.
probe 65 control-flow; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 2: use a goto-safe authentic invalid-input guard and one handler scope so the shared base action can own the original early boundary.
probe 67 other; result=MISMATCH; diff=2858; shape=80.50749711649365: Hypothesis 3: restore the PDB/decompiler-supported left cost-times-scale comparison operand order in all four resource handlers.
probe 69 liveness; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 4: use a period-valid register-qualified panel parameter to recover the executable's EBP panel color and prologue push order. [same emitted code as probe 65]
probe 71 liveness; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 5: restore original-looking local declaration order with tc before the 256-byte buffer and cost. [same emitted code as probe 69]
probe 73 liveness; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 6: place the cost scalar before the stack-window buffer to recover the original clear-handler buffer home and declaration order. [same emitted code as probe 71]
probe 75 control-flow; result=MISMATCH; diff=2868; shape=83.96770472895041: Hypothesis 7: match the PDB-supported mutually exclusive ok/cancel/help/clear handler chain with else-if source structure. [same emitted code as probe 73]
probe 77 control-flow; result=MISMATCH; diff=2945; shape=78.66205305651673: Hypothesis 8: mirror the authentic PDB CFG: ok, else-if non-cancel handlers plus cancel cleanup after the resource loop.
probe 79 other; result=MISMATCH; diff=2868; shape=86.04382929642445: Hypothesis 9 confirmed as a source improvement: remove decompiler-only temp_str+4 aliases; assembly shows every action formatter and corresponding set_text uses one shared buffer base.
probe 80 liveness; result=MISMATCH; diff=2929; shape=85.81314878892734: Hypothesis 10: replace the decompiler stack alias &tc in the wood formatter with the shared temp_str owner proved by adjacent formatter addresses.
probe 81 other; result=MISMATCH; diff=2858; shape=80.50749711649365: Hypothesis 11: combine the improved shared formatter buffer owner with the original left cost-times-scale comparison order.
probe 82 liveness; result=MISMATCH; diff=2868; shape=86.04382929642445: Hypothesis 12: split each branch-local amount declaration from its assignment to test the original x87 temporary lifetime. [same emitted code as probe 79]
probe 83 layout; result=MISMATCH; diff=2868; shape=86.04382929642445: Hypothesis 13: use an explicit address-of-zero-element cursor for the resource scan to preserve the original moving wood-button base. [same emitted code as probe 82]
```
<!-- end-recovered:6994b6c0e277dded3dad -->

<!-- recovered:5d1494de88c9f50d84eb -->
### `447517ad606f` `src/scratch/0043D8A0_action.cpp:1-65`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0043D8A0 TribeDiplomacyDialog::action
// PDB: dlg_dip.cpp lines 434-738
// Baseline reconstruction: named dialog arrays, direct resource/button ownership,
// and the executable's observed command/update branches.
//
// Attempt log:
// - baseline: natural named-field reconstruction; frame was 0x10c and the
//   event parameter was unnecessarily kept in a callee-save register.
// - reversed the capacity comparison to the observed attribute-total form;
//   control-flow similarity moved from 39.68% to 64.82%.
// - changed the top guard to positive nested dispatch; frame became 0x108 and
//   control-flow similarity moved to 79.93%.
// - modeled the contribution arrays as one wood-based cursor with the proven
//   gold/food/stone negative offsets; ordered calls became 124/124 and the
//   structural diff stayed at the 81% shape basin.
// - hoisted the player-id initializer to match the original pre-loop setup;
//   this recovered additional exact blocks but not the missing 87 bytes.
// - declaration-order and explicit shared-fallback-label probes were emitted
//   duplicates; they were removed from the living source after review.
// - canonical surface pass: replaced the rejected TTextPanel vfXX scaffold
//   with TPanel inheritance, named TPanel slots 0..55, the four named text
//   slots, and the proven TDialogPanel/TEasy_Panel additions and layouts.
// - VC5 overload-order probe: declaring set_text(char*), set_text(long), then
//   set_text(char**, short) is required for the binary slots E8/E4/E0; the
//   declarations are intentionally in that source order, not CSV slot order.
// - negative early-guard, if/else-chain, explicit fallback-label, and early
//   return variants did not restore the original block placement; the natural
//   nested dispatch was restored.
// - using player_id - 1 for tribute arrays while retaining the zero-based
//   button index preserves the original two-counter topology and improved the
//   current canonical diff from 2932 to 2916 bytes. Applying the same distinct
//   counter form to all four resource arrays improved it to 2868 bytes,
//   83.97% shape, and 23.53% exact-block coverage.
// - declaring the clear-handler cursor before its total stores follows the
//   original LEA/store order and keeps the best source basin.
// - declaration order, pointer aliases, register hints, split guards, and
//   comparator spellings were tested. They were duplicates or worse.
// - binary stack addresses show that every action formatter and its matching
//   set_text call use one shared temp_str base. The decompiler's +4 aliases
//   were removed; this recovers the original formatter block shape.
// Second-pass handler-layout probes:
// - else-if, while, explicit-break, count-limit, cursor-scope, comparator,
//   and update-condition forms were duplicates or worse.
// - valid top-tested for forms moved the base call before the handlers and
//   aligned all 124 calls, but added a duplicate count test, shortened the
//   body by 98 bytes, and worsened the strict diff to 2882 bytes.
// - behavior-backed handler labels with one base_action target were a VC5
//   codegen duplicate. A malformed empty trailing while looked better at
//   2811 bytes but is rejected as a source artifact.
// - moving index initialization into the for header and using a top break
//   did not improve the valid for frontier. The natural do/while is restored.
// Final paused state: frame 0x108, 124/124 calls with 99.19% ordered alignment,
// 83.97% shape similarity, 23.53% exact-block coverage, rebuilt size 3115 vs.
// original 3201, strict diff 2868. The original uses EBX for the button index
// and EDI for the player id; the clean candidate preserves that distinction in
// resource addresses but still colors the panel and index differently. The
// shared TPanel::action call remains late instead of the original +059c block.
// No manual vfXX/VPAD surface, raw vptr, volatility, inline asm, or custom
// flags remain.
// - claim sa-2646b822-r1: corrected the standalone declaration to protected.
//   The checker now emits the PDB-qualified MAEJ symbol.  The authentic shared
//   header still declares this member public, so grouped validation reports no
//   MAEJ owner until that separate context issue is repaired.
// - claim sa-2646b822-r1: a register-panel hint and a reversed gold assignment
//   order did not improve the reduced source.  Both experiments were restored.
```
<!-- end-recovered:5d1494de88c9f50d84eb -->

<!-- recovered:e9faa5deba2854fee3ff -->
### `447517ad606f` `src/scratch/0043D8A0_action.cpp:98-100`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// The panel surface is kept in the original declaration order.  In
// particular, action is slot 45 (0xB4); the text-panel additions below then
// start at slot 56 without a synthetic vfXX/padding surface.
```
<!-- end-recovered:e9faa5deba2854fee3ff -->
