# Function notes: 0043F340 `TribeMenuDialog`

Module notes: `decomp_notes/dlg_menu_module.md`.

## Recovered attempt history

<!-- recovered:ecefbce9c98f42eaf6c4 -->
### `d050eea3c` `src/dlg_menu.cpp:1-2`

Mapping: `strong`. next mapped function definition is TribeMenuDialog at old line 14.

```text
// PDB source module: C:\\msdev\\work\\age1_x1\\dlg_menu.cpp.
// The handwritten owners follow the original source-line and address order.
```
<!-- end-recovered:ecefbce9c98f42eaf6c4 -->

<!-- recovered:7a90bf0b344bd38c44ab -->
### `b6e159352e2d` `src/scratch/0043F340_TribeMenuDialog.cpp:1-18`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0043F340 TribeMenuDialog::TribeMenuDialog
// Attempt log:
// - Corrected create_button to the proven 11-argument parent/output ABI.
// - Mirrored exact dlg_menu.cpp sibling layout (TPanel RECT, TEasy size 0x490,
//   TDialog boundary, and virtual action surface).
// - Post-incrementing the output slot in each call recovered the oracle's
//   LEA-old-index/INC-before-call topology and raised shape similarity to 83.2%.
// - Indexed clear/memset/pointer-clear forms, a named zero, register hints, and
//   donor standard-header context emitted the same code; no source hack retained.
// Remaining mismatch is the VC5 EBX zero-carrier versus button-base allocation
// basin (original uses BL and push EBX for zeroes); calls/CFG/frame are aligned.
// - A single typed running y-state reached 43 positional bytes and 98.6% shape,
//   but used the wrong final scheduling basin; a separate base/post-row state
//   worsened the output to 775 bytes. Both probes were rolled back.
// - Probe 17: one natural y-state following the original EBP add-23 schedule
//   improved the diagnostic diff from 766 to 306 bytes and size gap to +4;
//   restored because the final three button block still diverged.
// Left in scratch after the bounded 10-hypothesis session.
```
<!-- end-recovered:7a90bf0b344bd38c44ab -->
