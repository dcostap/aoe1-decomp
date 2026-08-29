# Recovery journal: 004B3110 `~TRIBE_Screen_Sed_Menu`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_sedm.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_sedm.cpp`.
- Earlier recovery note: `recovery_notes/scr_sedm_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:8169bc9189c0277909a9 -->
### `c0ec6793eb44` `src/matching/004B3110_TRIBE_Screen_Sed_Menu.cpp:1-15`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu destructor
// VA: 004B3110
// PDB: scr_sedm.cpp:91-97
// FLAGS: /GX (EH-framed)
//
// Attempt log:
// - explicit out-of-class dtor (virtual funcs, no in-class dtor decl): C2084
// - inline dtor + virtual funcs: no .text
// - dtor declared in class + out-of-class body, explicit ~TScreenPanel call: double call
// - current: implicit base destructor call (remove explicit ~TScreenPanel)
// [non-comment lines omitted during migration]
// TPanel: 4-byte implicit vtable ptr + 0x54 bytes data = 0x58 total
```
<!-- end-recovered:8169bc9189c0277909a9 -->

<!-- recovered:f37476eeb1d904865576 -->
### `c0ec6793eb44` `src/matching/004B3110_TRIBE_Screen_Sed_Menu.cpp:57-58`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// NOTE: ~TScreenPanel() is NOT explicitly called body - VC5 generates the
// implicit base destructor call at the end automatically.
```
<!-- end-recovered:f37476eeb1d904865576 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
