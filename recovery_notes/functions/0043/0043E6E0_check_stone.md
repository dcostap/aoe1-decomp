# Recovery journal: 0043E6E0 `check_stone`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/dlg_dip.cpp`.
- PDB source: `C:\msdev\work\age1_x1\dlg_dip.cpp`.
- Earlier recovery note: `recovery_notes/dlg_dip_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:7129c4956fc5adf260ca -->
### `ce50f56890ba` `src/matching/0043E6E0_check_stone.cpp:1-9`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// protected: TribeDiplomacyDialog::check_stone
// VA: 0043E6E0; dlg_dip.cpp:846-874; body: 0043E6E0-0043E767
// PDB/Ghidra symbol: ?check_stone@TribeDiplomacyDialog@@IAEHXZ
// BINARY NOTE: Do not replace protected access with public access. The public
// QAEH symbol is byte-identical but is not the PDB-qualified owner.
// BINARY NOTE: Keep the prog-mode guard, resource check, ordered calls,
// receiver reloads, loop cleanup, and final result publication.
// EXACT FINISH: A public reversion kept the bytes but emitted QAEH. The
// protected source emits IAEHXZ and remains an exact match.
```
<!-- end-recovered:7129c4956fc5adf260ca -->

<!-- recovered:8cee0b29cde653af886a -->
### `ce50f56890ba` `src/matching/0043E6E0_check_stone.cpp:33-34`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// Narrow standalone surface models the inherited TPanel slot at +0x14 as
// set_active. The other declarations preserve the observed slot order.
```
<!-- end-recovered:8cee0b29cde653af886a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
