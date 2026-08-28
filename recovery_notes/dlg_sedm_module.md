# dlg_sedm.cpp module recovery

## Source context

The PDB source is `C:\\msdev\\work\\age1_x1\\dlg_sedm.cpp`.
The normal owners stay in source-line and address order:

- `00440140` constructor, lines 41-58;
- `00440360` destructor, lines 64-75;
- `00440400` action, lines 81-274.

All three owners belong to `TRIBE_Dialog_Sed_Menu`. The scalar deleting
destructor at `00440340` is compiler generated.

The constructor uses the derived fields at `+0x490`, `+0x494`, and
`+0x498..+0x4B0`. The action uses the same button array and the scenario
editor pointer. These fields are declared in `include/dlg_sedm.h`.

## Migration

`src/dlg_sedm.cpp` now owns all three normal bodies in PDB order. It consumes
`pnl_dlg.h`, `pnl_btn.h`, `scr_sed.h`, `scr_sedo.h`, and `tribegam.h`.
The source has no wrapper, context macro, fragment include, copied panel
layout, local vtable, raw address, or manual allocator call.

The old matching fragments and `dlg_sedm_context.h` were temporary provider
records. They are removed from the compiler-facing source path. The dialog
header owns only `TRIBE_Dialog_Sed_Menu`.

## Validation

Candidate: `build/dlg_sedm_natural_candidate.json`.
Report: `build/candidate_tus/dlg_sedm_natural_after/report.json`.

The candidate compiles all three normal bodies and the generated
`00440340` destructor. The constructor (`00440140`, 505 bytes) and action
(`00440400`, 919 bytes) report `MATCH` with zero positional differences.
The generated destructor also reports `MATCH`.

The action keeps `MATCH` after removing the decompiler result tail. It uses
direct returns for each handled action. The open-screen allocation is a
standalone construction statement. The destructor uses indexed `buttons[i]`
access instead of a button-pointer cursor.

The natural destructor uses typed `delete` calls. It preserves child ownership
without an address cast, but it does not match the original direct
`TPanel::delete_panel` calls. It emits two indirect destructor calls, has a
169-byte body against the 147-byte original, and escapes its owner boundary
twice. It remains `scratch` until a canonical typed panel deletion surface
can express the shipped cleanup without an address cast.

No status promotion is implied by the candidate report. The source module
status records the two exact normal owners and the unresolved destructor.
