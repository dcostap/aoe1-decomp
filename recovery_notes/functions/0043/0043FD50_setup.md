# Recovery journal: 0043FD50 `setup`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/dlg_msg.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Dlg_msg.cpp`.
- Earlier recovery note: `recovery_notes/dlg_msg_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:60c99fe6b55edda3d005 -->
### `target-session` `build/target_sessions/0043FD50_setup.json:1-29`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=534; shape=70.83333333333333: Current clean scratch source: typed TMessageDialog ownership, natural base setup, text, button loop, and message-specific labels.
probe 2 control-flow; result=MISMATCH; diff=575; shape=72.39583333333333: Nested p1->renderArea() in the typed base setup call, matching the original argument-evaluation stack flow.
probe 4 behavior; result=MISMATCH; diff=533; shape=73.01587301587301: Use typed empty-string button labels, matching the original create_button call's two literal-string relocations.
probe 5 control-flow; result=MISMATCH; diff=533; shape=74.07407407407408: Order the button-count switch cases as the PDB bands and original jump-table blocks: 0, 4, then 1-3.
probe 6 control-flow; result=MISMATCH; diff=526; shape=78.83597883597884: Order message-text switch cases as original PDB bands: 0, 1, 2, 4, then 3.
probe 7 control-flow; result=MISMATCH; diff=525; shape=80.85106382978724: Use direct typed button1 set_text calls in cases 1-3, allowing VC5 to tail-merge the original immediate-push call tail.
probe 8 liveness; result=MISMATCH; diff=525; shape=80.85106382978724: Declare the draw-area temporary before field initialization, matching the decompiler local order while retaining local staging. [same emitted code as probe 7]
probe 10 control-flow; result=MISMATCH; diff=536; shape=74.60317460317461: Use the binary-proven positive spacing guard: original emits test eax and jg before division.
probe 12 liveness; result=MISMATCH; diff=525; shape=80.85106382978724: Name the button-width value after the count switch so VC5 can preserve the original callee-saved width through spacing and button creation.
probe 14 control-flow; result=MISMATCH; diff=525; shape=80.85106382978724: Use a separately declared loop index and while form to test the original PDB line-124 loop setup. [same emitted code as probe 8]
probe 17 liveness; result=MISMATCH; diff=526; shape=80.85106382978724: Use separate natural zero assignments for the three typed button fields to test original forward store order.
probe 22 control-flow; result=MISMATCH; diff=574; shape=82.44680851063829: Inline the renderArea call in the base setup argument list; original pushes flags/info id before button zero stores and records renderArea at 0043FD81.
probe 23 abi; result=MISMATCH; diff=525; shape=80.85106382978724: Restore the canonical TDialogPanel setup overload preceding the char/info overload; donor header and class dump prove both slots at 0x128 and 0x12C.
probe 24 abi; result=MISMATCH; diff=526; shape=80.31914893617021: Use the canonical three TPanel virtuals after action before set_tab_order; the prior VPAD4 surface placed the overloads one slot late.
probe 25 layout; result=MISMATCH; diff=525; shape=80.85106382978724: Model the proven three-button array as button[3] instead of three named fields; the canonical TMessageDialog donor header and decompiler use an inline array. [same emitted code as probe 23]
probe 26 layout; result=MISMATCH; diff=525; shape=80.85106382978724: Move the parent pointer into the proven TPanel base gap instead of duplicating it as a direct TMessageDialog field; offsets and size remain unchanged, but ownership becomes canonical. [same emitted code as probe 25]
probe 27 liveness; result=MISMATCH; diff=525; shape=80.85106382978724: Declare the draw-area local at function scope before the button clears, matching the decompiler local order and testing whether declaration timing controls the delayed EDI save. [same emitted code as probe 26]
probe 28 liveness; result=MISMATCH; diff=526; shape=80.85106382978724: Use three separate natural array stores in declaration order, matching the decompiler's button[0], button[1], button[2] statements and original first store order.
probe 29 variant; result=MISMATCH; diff=526; shape=80.85106382978724: Reverse the chained button clear expression to test whether VC5's right-to-left store lowering recovers the original button[0], button[1], button[2] store order. [same emitted code as probe 28]
probe 30 control-flow; result=MISMATCH; diff=527; shape=78.72340425531915: Move the draw-area evaluation before the button clears to test the original call argument scheduling and whether VC5 can reload the parent after renderArea.
probe 31 liveness; result=MISMATCH; diff=525; shape=80.85106382978724: Introduce an explicit parent alias only for renderArea, testing whether separate alias lifetime permits the original reload of p1 at the base setup call.
probe 32 liveness; result=MISMATCH; diff=525; shape=80.85106382978724: Apply VC5 register storage to the read-only parent parameter; test the documented register-color axis against the original delayed callee-save placement. [same emitted code as probe 27]
probe 33 behavior; result=MISMATCH; diff=525; shape=80.85106382978724: Use the reviewed s_592A40 global empty string instead of local literals; original create_button pushes 592A40 at both string arguments.
probe 34 control-flow; result=MISMATCH; diff=536; shape=74.60317460317461: Use the binary-proven positive spacing guard () instead of the equivalent  form; preserve division and malformed-width behavior.
probe 35 liveness; result=MISMATCH; diff=525; shape=80.85106382978724: Name the button height before spacing and reuse it for y and create_button; original loads p9 into EBP before the spacing multiply and carries it through the loop.
probe 36 liveness; result=MISMATCH; diff=525; shape=80.85106382978724: Make the parent parameter top-level const to test whether VC5 treats it as a reloadable read-only input instead of preserving it in EDI across renderArea. [same emitted code as probe 33]
probe 37 liveness; result=MISMATCH; diff=525; shape=80.85106382978724: Hoist all natural locals to function scope in decompiler order, matching VC5-era declaration style and testing stack-home/register allocation.
probe 38 control-flow; result=MISMATCH; diff=646; shape=55.41125541125541: Use the PDB-supported explicit positive-count do/while loop with a separate index; test original loop-entry and update order around create_button.
probe 39 control-flow; result=MISMATCH; diff=525; shape=80.85106382978724: Use a top-tested while loop with explicit index initialization and update; compare its shared call-site layout with the original private loop. [same emitted code as probe 37]
```
<!-- end-recovered:60c99fe6b55edda3d005 -->

<!-- recovered:c0bea13c69cc6c4a8623 -->
### `de564b871749` `src/scratch/0043FD50_setup.cpp:1-33`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0043FD50 TMessageDialog::setup (main)
// Dlg_msg.cpp lines 71-165

// attempt 1 baseline: simple panel stubs, but wrong virtual slots and setup order
// attempt 2: restored the period panel virtual surface; create_text is vt[64]
// and create_button(char*, char*) is vt[59]. Base setup uses p4/p5. Button
// and text ownership remains named.
// attempt 3: nested renderArea evaluation kept the base setup call ordered.
// attempt 4: reserved the two unused text overload slots to select vt[64].
// attempt 5: shared the button text and hotkey switch tail.
// attempt 6: a counted for loop hoisted the create_button function pointer.
// attempt 7: an info_id local had no emitted-code effect; it was removed.
// attempt 8: the spacing guard variant was rolled back; the original source
// shape uses the prior < 1 form in this compiler basin.
// attempt 9: corrected create_button arguments to x, y, button width, height.
// attempt 10: separate adjacent button fields emitted the same code.
// attempt 11: passed p5 as the dialog height to base setup per the original
// stack load; this grew the body to 676 bytes and worsened the first hunk.
// attempt 12: removed the redundant positive button-count wrapper; the packet
// shows one loop-entry test before the create_button vtable load. Diff improved
// 586->563 bytes, but shape and exact-block coverage worsened; kept natural code.
// claim orch-43FD50-a: result-local and array variants worsened structural shape;
// chained button initialization retained the original first-hunk basin.
// Local draw-area staging with p5 base height is the best period-plausible source
// reconstruction here; it reaches exact size and ordered calls.
// attempt 13: restored the two empty string arguments proven by the button-call
// relocations. This reduced the diff by one byte and improved block shape.
// attempt 14: ordered the count switch as cases 0, 4, and 1-3 from PDB blocks.
// attempt 15: ordered the text switch as cases 0, 1, 2, 4, and 3 from PDB
// blocks. Direct case-local button1 calls recover the original immediate pushes.
// Declaration, loop-form, spacing, and separate-zero probes were unchanged or
// worse. Best current result: exact size and ordered call parity; diff 525,
// shape 80.85%, with the first mismatch at +0005 in register scheduling.
```
<!-- end-recovered:c0bea13c69cc6c4a8623 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
