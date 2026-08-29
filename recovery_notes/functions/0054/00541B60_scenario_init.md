# Recovery journal: 00541B60 `scenario_init`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/world.cpp`.
- PDB source: `C:\msdev\work\age1_x1\World.cpp`.
- Earlier recovery note: `recovery_notes/world_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:9428ae8fa0e93d93dbc0 -->
### `e5b22f4df482` `src/scratch/00541B60_scenario_init.cpp:1-49`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00541B60 RGE_Game_World::scenario_init(int, RGE_Game_World*)
// PDB source: World.cpp lines 820-822 (96 bytes, 29 asm lines)
// FLAGS: config/flags/00541B60_scenario_init.rsp uses /GX for original EH frame.
//
// __thiscall: this in ecx, 2 stack params. ret 8 cleanup.
// SEH-framed, allocates RGE_Scenario (0x1990 bytes), constructs if non-null,
// stores at this->scenario (+0x5C).
//
// Attempt log:
// - Baseline (direct new + store) matches exact EH prologue/allocation/ctor family but stores on success path
//   and branches null to padded epilogue. 96/96, edit diff 15.
// - Try 1: explicit null normalization (`if (p == 0) p = 0;`) forces original short null branch/xor/common-store
//   family, but VC5 inserts redundant `test eax,eax; jne +0` at join before EH saved-ecx reload. Best basin,
//   96/96, positional 16.6667%, edit diff 11.
// - Try 2: non-virtual RGE_Scenario with same sizeof: no change from try 1.
// - Try 3: volatile local: spills/reloads through stack before store, worse.
// - Try 4: manual operator new + explicit constructor call loses EH new-expression lowering, only 64-byte text.
// - Try 5/6: direct assignment and ternary common-store collapse to baseline success-path store/null-to-tail family.
// - Try 7: /Ob0 with explicit null normalization: no effect, restored /GX-only flag.
// - Try 8: /O1 /GX probe wrong size/family (75-byte text), restored /GX-only flag.
// - Try 9: separate declaration then assignment with explicit null normalization: same redundant join test as try 1.
// - SpruceGlow tries 10/16/17: direct store, ternary common-store, and two-local result all fell back to the
//   baseline success-path store/null-to-tail family (edit diff 15, first mismatch 53).
// - SpruceGlow tries 11/13/14/18/23: separate declaration, goto join, negated empty-else, self-assign arm,
//   and explicit `this->scenario` all stayed in the best common-store basin but kept the redundant
//   `test eax,eax; jne +0` at the join (edit diff 11, first mismatch 75).
// - SpruceGlow try 12: if/else member stores kept first mismatch 75 but worsened edit diff to 17.
// - SpruceGlow try 15: assignment-in-condition worsened edit diff to 26.
// - SpruceGlow tries 19/20: reusing param1 or param2 as the null-arm zero source did not change the redundant join test.
// - SpruceGlow tries 21/22: while/do break spellings did not change the redundant join test.
// - SpruceGlow try 24: removing the virtual destructor / making RGE_Scenario a plain 0x1990-byte class did not change best-basin codegen.
// - SpruceGlow try 25: helper-returned zero worsened codegen (edit diff 20).
// - 2026-05-10 resumed pass on this VA only: retried 15 variants: direct store,
//   local-no-if, if-null/if-not/voidcast/intcast/zero-init/volatile/bool/while common
//   tail, goto, assignment-in-condition, member-alias, param locals, if-member-arms,
//   and plain non-virtual scenario surface. No exact. Direct/goto forms fall to the
//   success-store/null-tail basin; common-tail forms keep the redundant `test eax,eax;
//   jne +0`; member-arm forms add a real post-join branch. Same EH epilogue/window
//   truncation blocker remains.
// - 2026-05-10 current Boss-assigned pass: revalidated baseline and tried slot pointer/reference aliases,
//   ternary/self-ternary, if/else-empty, goto null/non-null labels, switch-on-pointer, and one-shot loop forms.
//   Alias/goto/switch forms stayed in the best common-tail basin but kept the redundant join test; ternary
//   collapsed to success-store/null-tail; loop forms added real loop/control-flow drift. Kept unqualified
//   `scenario = p` best source because `this->scenario = p` falls back to the worse success-store family.
// - 2026-05-10 StarryZephyr pass: rechecked current source (16.6667% positional, 11.4583% edit) and direct member new
//   (success-store/null-tail, first mismatch 53, edit 15). Restored current best source; same EH join-test blocker.
// Left in scratch: behavior, EH frame, allocation size, ctor args/call, and stack cleanup are correct; blocker is
// VC5 source shaping around the null-path/common-store join, same as sibling init helpers. Not proposing accepted_drift:
// best object inserts a no-op join test and shifts/truncates the compared tail/epilogue. No inline asm/hacks.
```
<!-- end-recovered:9428ae8fa0e93d93dbc0 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
