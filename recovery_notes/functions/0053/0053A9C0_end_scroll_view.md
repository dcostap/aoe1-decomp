# Recovery journal: 0053A9C0 `end_scroll_view`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/view.cpp`.
- PDB source: `C:\msdev\work\age1_x1\view.cpp`.
- Earlier recovery note: `recovery_notes/view_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:1ed344365305dc888d7a -->
### `912332e8f578` `src/scratch/0053A9C0_end_scroll_view.cpp:1-36`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0053A9C0 RGE_View::end_scroll_view (view.cpp:6161-6220)
// Using proper virtual method declarations for correct thiscall vtable dispatch.
// vtable: set_redraw at slot 8 (0x20), end_scroll_view at slot 60 (0xF0), do_paint at slot 61 (0xF4)
// [non-comment lines omitted during migration]
// TPanel virtual methods (first 9, set_redraw at vtable slot 8 = offset 0x20)
// [non-comment lines omitted during migration]
// RGE_View local vtable layout:
// TPanel_Base: 9 virtuals (slots 0-8)
// RGE_View_Local: 51 dummies (slots 9-59), end_scroll_view (slot 60), do_paint (slot 61)
// offset: set_redraw=0x20, end_scroll_view=0xF0, do_paint=0xF4
```
<!-- end-recovered:1ed344365305dc888d7a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
