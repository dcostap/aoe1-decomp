# Dlg_msg.cpp source recovery

The PDB module owns seven `TMessageDialog` methods. The source range is
`0043FC70` through `00440130`.

`TMessageDialog` uses canonical dialog, panel, button, text, BaseGame, and
global headers. It has no copied panel layout or manual vtable store.

The deleting destructor at `0043FCB0` is compiler generated. It has no
handwritten source body.

The constructor and main setup remain nonexact. The constructor is scratch
because its current check has a structural instruction difference. The main
setup is scratch because its 526-byte drift is broad and its current grouped
comparison has no valid exact proof. The other five PDB owners retain matching
status pending direct module validation.

The direct grouped check matches the five matching owners and the generated
deleting destructor. The constructor differs by 44 bytes. Main setup differs
by 526 bytes. The constructor has a high-severity structural difference. Main
setup remains a broad unresolved body. Neither source body was changed.
