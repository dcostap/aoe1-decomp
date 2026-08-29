# Recovery journal: 0043D6E0 `~TribeDiplomacyDialog`

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


<!-- recovered:dc3549073730b95d5d70 -->
### `6e2375c51785` `src/scratch/0043D6E0_TribeDiplomacyDialog.cpp:1-5`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0043D6E0 TribeDiplomacyDialog::~TribeDiplomacyDialog
// Source: dlg_dip.cpp lines 374-428
// 445 bytes, 163 asm, EH-framed destructor with /GX
// FLAGS: config/flags/0043D6E0_TribeDiplomacyDialog.rsp = /nologo /c /O2 /Oy /GX
// Attempt 2: all 8 arrays in loop 1, more complete layout
```
<!-- end-recovered:dc3549073730b95d5d70 -->

<!-- recovered:447cec292dada907bf00 -->
### `6e2375c51785` `src/scratch/0043D6E0_TribeDiplomacyDialog.cpp:79-80`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // Loop 1: 8 groups of 8 pointers each, accessed via offset pattern
    // VC5 generates an ESI walking pointer for this pattern
```
<!-- end-recovered:447cec292dada907bf00 -->

<!-- recovered:ff035b9366dd9ecb9aad -->
### `6e2375c51785` `src/scratch/0043D6E0_TribeDiplomacyDialog.cpp:115-116`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // Scroll panels
    // Note: original checks +0x620, +0x624, +0x628, +0x62C individually
```
<!-- end-recovered:ff035b9366dd9ecb9aad -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
