# Recovery journal: 0043EF80 `setup`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/dlg_list.cpp`.
- PDB source: `C:\msdev\work\age1_x1\dlg_list.cpp`.
- Earlier recovery note: `recovery_notes/dlg_list_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:474952d896152904d369 -->
### `target-session` `build/target_sessions/0043EF80_setup.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Removed unsupported virtual qualifier from TListDialog main char* setup overload; candidate TU emits expected QAE symbol while all exact owners remain MATCH.
```
<!-- end-recovered:474952d896152904d369 -->

<!-- recovered:3693112f8ebfb18f459c -->
### `bfdf9a8b2fe5` `src/scratch/0043EF80_setup.cpp:1-18`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0043EF80 TListDialog::setup (main)
// dlg_list.cpp lines 66-96

// attempt 1: main setup with child panel creation
// 416/420 bytes (99% size) — 4 bytes short
// attempt 2: restored the dlg_list/panel virtual surface, the nested renderArea
// evaluation, and the original list/button parameter ownership.
// attempt 3: added the proven TPanel data gap; title/list/scroll field addresses and the
// first 0xEA bytes aligned, leaving a localized button-call schedule drift.
// attempt 4: typed cancel output-pointer and receiver locals were codegen duplicates or
// worsened the suffix; rolled back to direct member ownership.
// attempt 5: restored the virtual long setup overload declaration; codegen duplicate.
// attempt 6: direct create_button result tests were tried in both orders.  The retained
// natural shape tests OK directly and assigns the cancel result; it reaches 420/420 bytes,
// 10/10 ordered calls, 97.14% shape, 88 differing bytes.  Remaining drift starts at the
// three button-argument stack displacements after scroll_cur_line and the downstream cancel tail.
// attempt 7: conditional result assignment around the cancel create_button emitted duplicate
// code; restored the separate result assignment and retained the clean source.
```
<!-- end-recovered:3693112f8ebfb18f459c -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
