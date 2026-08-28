# Dlg_msg.cpp source recovery

The PDB module owns seven `TMessageDialog` methods. The source range is
`0043FC70` through `00440130`.

`TMessageDialog` uses canonical dialog, panel, button, text, BaseGame, and
global headers. It has no copied panel layout or manual vtable store.

The deleting destructor at `0043FCB0` is compiler generated. It has no
handwritten source body.

The constructor and main setup retain their prior accepted-drift status. The
other five PDB owners retain matching status pending direct module validation.

The direct grouped check matches the five matching owners and the generated
deleting destructor. The constructor differs by 44 bytes. Main setup differs
by 526 bytes. Neither accepted-drift owner escapes its original boundary.
