# dlg_abt.cpp recovery

## PDB context

The PDB source module is `C:\\msdev\\work\\age1_x1\\dlg_abt.cpp`.
The four handwritten owners are in source and address order:

- `0043AD70`, `TribeAboutDialog::TribeAboutDialog`, lines 46-148
- `0043B300`, `TribeAboutDialog::~TribeAboutDialog`, lines 154-168
- `0043B400`, `TribeAboutDialog::action`, lines 174-200
- `0043B550`, `TribeAboutDialog::draw`, line 206

The scalar deleting destructor at `0043B2E0` is compiler generated. The
canonical `TribeAboutDialog` header owns the `0x490`-byte `TDialogPanel` base
and its thirteen pointer fields at `+0x490` through `+0x4C0`.

## Recovery

The module uses `include/dlg_abt.h` as its public owner declaration. It uses
the concrete panel, control, picture, registry, Base Game, and credits-screen
providers privately. The source keeps the original constructor, destructor,
action, and draw order.

The constructor keeps the shipped `RECT.right` placement expressions and the
inline picture-position expression. The action keeps independent close and
credits paths under the `command == 1` guard. The destructor deletes the
circle picture before the background panel.

## Validation

Fresh grouped validation is required after each source-tree change. Standalone
checks use the configured `dlg_abt` translation unit and the following commands:

```text
python tools/check_function.py --va 0043AD70 --rebuild
python tools/check_function.py --va 0043B300 --rebuild
python tools/check_function.py --va 0043B400 --rebuild
python tools/check_function.py --va 0043B550 --rebuild
```

The fresh candidate grouped check passed all four handwritten owners. Each row
reported `MATCH`, zero byte differences, zero relocation target mismatches, and
zero boundary escapes. The generated `0043B2E0` destructor also reported
`MATCH` with zero byte differences.
