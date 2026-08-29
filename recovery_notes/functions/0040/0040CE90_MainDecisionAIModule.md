# Recovery journal: 0040CE90 `MainDecisionAIModule`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/aimdmod.cpp`.
- PDB source: `C:\msdev\work\age1_x1\aimdmod.cpp`.
- Earlier recovery note: `recovery_notes/aimdmod_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:28ad774cfc124e27879f -->
### `3719bc4b64cd` `src/scratch/0040CE90_MainDecisionAIModule.cpp:1-26`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0040CE90 MainDecisionAIModule::MainDecisionAIModule(int, RGE_Player*, int)
// PDB: aimdmod.cpp lines 43-52
// Size: 390 bytes
// FLAGS: /GX
//
// Status: STUCK — instruction scheduling + register allocation diff
//
// First 56 bytes match (EH prologue + base ctor call). Then VC5 reorders
// field stores, rge_read argument setup, SEH code writes, and vtable store
// differently than the original. The same instructions exist in both, but in
// different order (scheduling) and with different register allocation (ebp vs
// edi as zero reg in various versions). No source surface controls VC5's
// instruction scheduler or register allocator.
//
// Best result: 56 bytes exact, first mismatch at offset 56. Edit diff 44%.
//
// Attempt log:
// - Fixed AIModule base size to 0xF0 (gap_04[0xEC]) for correct field offsets
// - Added <new.h>/<stdlib.h> includes to trigger EH prologue generation
// - Removed excess locals; simplified loop structure to match original style
// - Field offsets now correct (+0xF0 player, +0xF4 value, etc.)
// - Prologue register allocation matches (esi/edi save, edi as zero)
// - Remaining issue: instruction scheduling (field stores vs rge_read prep order)
//   and missing SEH code write (mov byte [esp+24h], 1)
//
// No accepted_drift: 74% positional diff, broad scheduling and register differences.
```
<!-- end-recovered:28ad774cfc124e27879f -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
