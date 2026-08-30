# Function notes: 00471EC0 `TButtonPanel`

Module notes: `decomp_notes/pnl_btn.md`.

## Recovered attempt history

<!-- recovered:cbf331940c1e3436ff14 -->
### `8558dca82389` `src/scratch/00471EC0_TButtonPanel.cpp:1-20`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00471EC0 TButtonPanel constructor
// PDB source: Pnl_btn.cpp
// Attempt log:
// - 1st attempt: novtable + manual vtable + body field assignments + array loop
// [non-comment lines omitted during migration]
// Minimal TPanel layout (0xF4 bytes)
```
<!-- end-recovered:cbf331940c1e3436ff14 -->

<!-- recovered:75fd3e4e508ed6849834 -->
### `8558dca82389` `src/scratch/00471EC0_TButtonPanel.cpp:182-185`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // Manual vtable write (after all scalar fields, like original)
    *(void**)this = (void*)0x570FC8;

    // Override TPanel's panel_type
```
<!-- end-recovered:75fd3e4e508ed6849834 -->
