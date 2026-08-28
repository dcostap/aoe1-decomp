# dlg_abt provider surface

`include/dlg_abt.h` owns the `TribeAboutDialog` declaration.

The PDB identifies `dlg_abt.cpp` as the source module. It owns four normal
members in this address order: `0043AD70`, `0043B300`, `0043B400`, and
`0043B550`. The scalar deleting destructor at `0043B2E0` is compiler
generated.

The PDB class size is `0x4C4`. The canonical `TDialogPanel` base is `0x490`.
The thirteen pointer fields add the proved `0x34`-byte derived tail.

The header stores foreign types only as pointers. It does not copy panel,
screen, control, picture, registry, credit-screen, or Base Game layouts.

`src/dlg_abt_tu.cpp` remains the compiler-facing exact wrapper. Direct source
composition waits for a canonical credits-screen provider and the Base Game
pause method. Do not add local declarations or casts to bypass these owners.
