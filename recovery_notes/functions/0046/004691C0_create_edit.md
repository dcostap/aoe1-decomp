# Recovery journal: 004691C0 `create_edit`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Panel_ez.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Panel_ez.cpp`.
- Earlier recovery note: `recovery_notes/Panel_ez_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:5b7e846ba2624db9dba1 -->
### `target-session` `build/target_sessions/004691C0_create_edit.json:1-14`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=54; shape=93.28859060402685: Natural typed Panel_ez reconstruction: baseline behavior and calls; verify current 442-byte basin.
probe 2 control-flow; result=MISMATCH; diff=342; shape=93.83561643835617: Variant: initialized int result with common return and failure error guard; test whether VC5 emits original shared failure block before cleanup.
probe 4 control-flow; result=MISMATCH; diff=54; shape=93.28859060402685: Variant: uninitialized result assigned in nested success/failure arms with one final return; test original shared cleanup topology.
probe 6 variant; result=MISMATCH; diff=54; shape=93.28859060402685: Variant: explicit default-constructor parentheses in TEditPanel new-expression; test EH lowering context. [same emitted code as probe 1]
probe 8 context; result=MISMATCH; diff=54; shape=93.28859060402685: Variant: restore period <new.h> include context before typed declarations; test whether EH/new declaration selects the oracle shared tail.
probe 10 control-flow; result=MISMATCH; diff=355; shape=80.83832335329342: Variant: separate early error returns for allocation, constructor error, and setup failure; test whether VC5 tail-merges the repeated error/return block.
probe 12 control-flow; result=MISMATCH; diff=54; shape=93.28859060402685: Variant: duplicate failure assignment and return in inner setup-failure arm and outer allocation/error arm; test compiler tail merge. [same emitted code as probe 6]
probe 14 control-flow; result=MISMATCH; diff=54; shape=93.28859060402685: Variant: outer allocation/constructor guard uses an early error return; setup failure retains common trailing failure return.
probe 16 control-flow; result=MISMATCH; diff=54; shape=93.28859060402685: Variant: explicit success goto to a single done label with uninitialized result; test whether forced common return preserves oracle failure block.
probe 19 control-flow; result=MISMATCH; diff=54; shape=93.28859060402685: Explicit setup-failure goto to a shared fail label; test whether a named failure target restores the oracle success jump and common tail.
probe 21 control-flow; result=MISMATCH; diff=54; shape=93.28859060402685: Use p11 as the late result carrier across an explicit common return; test whether VC5 preserves the oracle shared tail without a new local. [same emitted code as probe 4]
probe 24 control-flow; result=MISMATCH; diff=54; shape=93.28859060402685: Fresh shared-tail probe: carry success and failure through one ordinary integer result and done label. [same emitted code as probe 16]
probe 26 liveness; result=MISMATCH; diff=54; shape=93.28859060402685: Fresh setup-result lifetime probe: name the typed setup return immediately before its success guard. [same emitted code as probe 14]
probe 30 context; result=MATCH; diff=0; shape=100.0: Use grouped pnl_ez.cpp owners and shared edit-panel surface
```
<!-- end-recovered:5b7e846ba2624db9dba1 -->

<!-- recovered:2d2e55d4bd367f2554d0 -->
### `b6e159352e2d` `src/scratch/004691C0_create_edit.cpp:1-30`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004691C0 TEasy_Panel::create_edit (442 B)
// PDB source: Panel_ez.cpp lines 1399-1439
// Attempt log:
// - Baseline decompiler-shaped stubs had the wrong TEditPanel size, error
//   offset, TEasy_Panel styling offset, setup arity, and font field.
// - Restored the period typed layouts and /GX context: TPanel owns +14/+18,
//   +20, and +D8; TEasy_Panel owns +F4/+F8 and +31C onward; TEditPanel is
//   0x16C bytes.  This moved the check from a 415-byte mismatch to 267.
// - Restored the real setup(TDrawArea*, TPanel*, ...) ABI, direct out-slot
//   construction, positive font guard, promoted bevel colors, and
//   brush/brush-color/background argument order.  The body through all calls
//   is now byte-aligned; remaining drift is VC5 success/failure epilogue
//   placement (54 positional bytes, +19 emitted bytes).
// - Common result/goto, volatile-result, initialized-result, destructor, and
//   register-result probes did not change the best ordinary codegen basin.
// - Mirrored same-TU create_auto_scrollbar's direct success/failure returns;
//   VC5 emitted the same 461-byte basin, so no control-flow lead remains.
// - A natural local TEditPanel owner before publishing the out slot left the
//   emitted code unchanged; restored the direct out-slot construction.
// - Inverted the allocation/error guard with one result return; VC5 normalized
//   it to the same 461-byte basin and retained the duplicated return tail.
// - Used explicit fail and done labels after separate allocation and error
//   guards; VC5 again emitted the same 461-byte basin, so the tail remains a
//   compiler/codegen blocker rather than an unresolved call or layout issue.
// Left in scratch: typed source is behaviorally aligned with all 9 calls and
//   proven field accesses; only the compiler's duplicated return tail remains.

// Canonical layouts recovered from the Panel_ez/pnl_edit surfaces.  The base
// panel owns the width/height/draw-area/error fields; TEasy_Panel owns the
// ideal dimensions and edit styling fields.
```
<!-- end-recovered:2d2e55d4bd367f2554d0 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
