# Recovery journal: 004CD5E0 `update`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tact_bld.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tact_bld.cpp`.
- Earlier recovery note: `recovery_notes/tact_bld_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:e930e0ab6f36d3f7dcef -->
### `d050eea3c` `src/tact_bld.cpp:71-72`

Mapping: `ambiguous`. next mapped function definition is update at old line 158.

```text
// PDB lines 109-198; VA 004CD310.
// BINARY NOTE: /GX is required for the original EH registration and unwind
```
<!-- end-recovered:e930e0ab6f36d3f7dcef -->

<!-- recovered:24d3443b7e46b70bd196 -->
### `d050eea3c` `src/tact_bld.cpp:160-162`

Mapping: `strong`. comment lies after mapped function update at old line 158.

```text
// PDB lines 204-424; VA 004CD5E0.
// BINARY NOTE: The direct checker reports four strict bytes. The rebuilt
// source selects vslot+0x1F8 where the original selects vslot+0x1F0.
```
<!-- end-recovered:24d3443b7e46b70bd196 -->

<!-- recovered:54e7a73aa38ab15f381d -->
### `6a2aef2e2` `src/tact_bld.cpp:152-152`

Mapping: `strong`. comment lies after mapped function update at old line 150.

```text
// The direct checker reports four strict bytes. The rebuilt
```
<!-- end-recovered:54e7a73aa38ab15f381d -->

<!-- recovered:28011455fa1ea6869df7 -->
### `9da6cde6708b` `src/scratch/004CD5E0_update.cpp:1-40`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004CD5E0 TRIBE_Action_Build::update
// Attempt log:
// try 1-10: prior decompiler-shaped source reached the original 724-byte size,
// but used fabricated action classes, wrong task states, and misnamed virtual
// calls; its broad switch drift was not a useful source reconstruction.
// baseline: canonical TRIBE_Action_Build/RGE_Action ownership with natural
// target checks and state dispatch; exact size, but the old local surfaces still
// produced broad call and layout drift.
// probe 2: restored the period action/static/moving/building hierarchy and the
// observed direct/virtual helper ownership; this is the clean structural lead.
// probe 3: corrected the player command ABI to five integer, four float, and
// three integer arguments; this removed three __ftol calls and restored 724B.
// probe 4: binary fcomp/test evidence requires the active target gate at
// timer == 0.0f, not timer != 0.0f; the branch and early body now align.
// probe 5: push order proves target id precedes target-owner id in command().
// probe 6: PDB/source handler order is 0x0B, 4, 6, 7, 1, 0x0D; restoring it
// reduced the mismatch to a localized nested-switch region.
// probe 7: status-3 arms do not clear the target; adding those calls was a
// broad negative result and was rolled back.
// probe 8: quick_build's positive arm is the inline 1000.0f path; reversing
// the source guard reproduced the original cold work-rate branch.
// probes 9-10: explicit shared-label and nested-case-order variants were
// codegen duplicates; retained the natural direct switch spelling.
// probe 15: moving the state-0x0B target-reset arm before its status-3 arm
// was a codegen duplicate; restored the clean natural switch order.
// retry 18: making the state-0x0B status-3 arm fall through was a duplicate.
// retry 19: an incorrect shared-tail label layout grew the function to 824B;
// it was rolled back.
// retry 21: explicit state-3 and reset/state-0x0B tails reduced drift to 24B.
// retry 24: placing state-4 reset cases before state-6 cases aligned all 24
// calls and reduced drift to 3B; this is the current source candidate.
// retries 25-31: named list/status locals, moved work scope, and register
// locals were codegen duplicates; all were rolled back.
// current best: 724B, 3 differing bytes at the second sub-action vtable
// load (EDX versus original EAX); call targets, order, CFG, and size align.
// r3 probe 1: braces around the state-4 nested switch were a codegen duplicate.
// r3 probe 2: an explicit state-4 default break was a codegen duplicate.
// r3 probe 3: unsigned-int promotion of the state-4 update result was a
// codegen duplicate. Exact donors confirm the same natural switch family;
// retain the shared-tail candidate and pause at the isolated register drift.
```
<!-- end-recovered:28011455fa1ea6869df7 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
