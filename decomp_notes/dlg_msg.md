# Dlg_msg.cpp source recovery

The PDB module owns seven `TMessageDialog` methods. The source range is
`0043FC70` through `00440130`.

`TMessageDialog` uses canonical dialog, panel, button, text, BaseGame, and
global headers. It has no copied panel layout or manual vtable store.

The deleting destructor at `0043FCB0` is compiler generated. It has no
handwritten source body.

The main setup remains nonexact and stays scratch. Its authoritative grouped
comparison has a 311-byte mismatch. The constructor and the other five
handwritten PDB owners retain matching status. The deleting destructor is
compiler generated and also matches in the grouped audit.

The direct grouped check matches six normal owners and the generated deleting
destructor. Main setup is a broad unresolved body with correct ownership,
boundary, relocations, and 14 aligned calls. Neither source body was changed.
