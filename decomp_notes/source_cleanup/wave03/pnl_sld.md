# `pnl_sld.cpp` source-cleanup report

## Delivery and Git history

Module: `src/pnl_sld.cpp`

Base commit:

`76037279ee11dde077bb7d55aeb46b518b2bb27c`

Final source commit:

`512181c282bf2f14a1b70c26d64f30b9ad81ea75`

The report is delivered in a separate commit after the source commit.

Changed files:

- `src/pnl_sld.cpp`
- `decomp_notes/source_cleanup/wave03/pnl_sld.md`

`include/pnl_sld.h` was not edited.

## Scope

The source owns ten handwritten functions in PDB order:

- `0047BCE0` `TVerticalSliderPanel::TVerticalSliderPanel`
- `0047BD30` `TVerticalSliderPanel::~TVerticalSliderPanel`
- `0047BD40` `TVerticalSliderPanel::setup`
- `0047BDC0` `TVerticalSliderPanel::set_rect`
- `0047BDE0` `TVerticalSliderPanel::draw`
- `0047BDF0` `THorizontalSliderPanel::THorizontalSliderPanel`
- `0047BE30` `THorizontalSliderPanel::~THorizontalSliderPanel`
- `0047BE40` `THorizontalSliderPanel::setup`
- `0047BEC0` `THorizontalSliderPanel::set_rect`
- `0047BF30` `THorizontalSliderPanel::draw`

The scalar deleting destructors at `0047BD10` and `0047BE10` are compiler-generated.
They are outside the handwritten source set.

The PDB source is `C:\msdev\work\age1_x1\pnl_sld.cpp`.

## Systematic PDB coverage

The procedure-scoped records are in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The per-function evidence is in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/`.
The PDB records `this` in ECX for every handwritten function.

| VA and function | PDB parameters | PDB locals | Register record |
| --- | --- | --- | --- |
| `0047BCE0` constructor | none | none | `this`, `TVerticalSliderPanel*` |
| `0047BD30` destructor | none | none | `this`, `TVerticalSliderPanel*` |
| `0047BD40` `setup` | `renderAreaIn`, `parentPanelIn`, `xIn`, `yIn`, `widthIn`, `heightIn`, `backPictureIn`, `thumbPictureIn`, `thumbHeightIn`, `scaleIn`, `one_step_in`, `page_step_in`, `drawBoxIn`, `spineWidthIn` | none | `this`, `TVerticalSliderPanel*` |
| `0047BDC0` `set_rect` | `x_in`, `y_in`, `wid_in`, `hgt_in` | none | `this`, `TVerticalSliderPanel*` |
| `0047BDE0` `draw` | none | none | `this`, `TVerticalSliderPanel*` |
| `0047BDF0` constructor | none | none | `this`, `THorizontalSliderPanel*` |
| `0047BE30` destructor | none | none | `this`, `THorizontalSliderPanel*` |
| `0047BE40` `setup` | `renderAreaIn`, `parentPanelIn`, `xIn`, `yIn`, `widthIn`, `heightIn`, `backPictureIn`, `thumbPictureIn`, `thumbWidthIn`, `scaleIn`, `one_step_in`, `page_step_in`, `drawBoxIn`, `spineWidthIn` | none | `this`, `THorizontalSliderPanel*` |
| `0047BEC0` `set_rect` | `x_in`, `y_in`, `wid_in`, `hgt_in` | none | `this`, `THorizontalSliderPanel*` |
| `0047BF30` `draw` | none | none | `this`, `THorizontalSliderPanel*` |

The PDB has no procedure-scoped local records for this module.
It does not prove original names for the existing `left` and `right` locals in
`THorizontalSliderPanel::set_rect`. Those concise names remain unchanged.

## Names

Recovered original parameter names from the procedure-scoped PDB records:

- Both `setup` definitions: `renderAreaIn`, `parentPanelIn`, `xIn`, `yIn`,
  `widthIn`, `heightIn`, `backPictureIn`, `thumbPictureIn`, `scaleIn`,
  `one_step_in`, `page_step_in`, `drawBoxIn`, and `spineWidthIn`.
- `TVerticalSliderPanel::setup`: `thumbHeightIn`.
- `THorizontalSliderPanel::setup`: `thumbWidthIn`.
- Both `set_rect` definitions: `x_in`, `y_in`, `wid_in`, and `hgt_in`.

The `this` register name is already implicit in each member definition.
The member names `drawBox`, `spineWidth`, `one_step`, `page_step`, `pnl_x`,
`pnl_wid`, `pnl_hgt`, and the rectangle fields were already present and were
not changed.

`left` and `right` are existing descriptive cleanup names, not claimed PDB
recoveries. No uncertain stack-slot mapping forced a rename.

## Source changes

The source replaces all generated `param_*` names in the ten handwritten
functions with the PDB names above. It also applies 1TBS brace placement and
keeps short `set_rect` signatures on one line.

The source keeps the existing `Vertical` and `Horizontal` scroll direction
enum values. It keeps all null arguments, casts, member writes, call order,
control flow, and explicit literal values unchanged.

No helper, wrapper, context fragment, layout change, assembly, or behavior
repair was added. No comments, constants, or resource IDs were added.

## Output risk

The source changes alter parameter identifier spelling and formatting only.
They do not alter parameter types, declarations, scopes, storage, expressions,
call targets, class layout, or ABI symbols. The header remains unchanged.

Formatting can change debug line records. The file has no `__LINE__` use.
No generated-output claim is made without the deferred validation stage.

## Shared requests and unresolved questions

The owner of `include/pnl_sld.h` may add the same PDB parameter names to the
two `setup` declarations and both `set_rect` declarations. This worker did not
edit that shared header.

No resource-header request is needed.

The PDB does not provide original names for the existing `left` and `right`
locals. Their baseline names remain in place without original-name claims.

## Validation

I reviewed the complete source diff and ran `git diff --check`.

**Compilation, matching, audits, and tests were not run.**

No game or resource runtime test was run.
