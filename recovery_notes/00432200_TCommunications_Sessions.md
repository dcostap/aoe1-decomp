# 00432200 `TCommunications_Sessions::TCommunications_Sessions`

- PDB source: `com_sess.cpp`, lines 19 to 35.
- Flags: `config/flags/com_sess.rsp`.
- Original size: 134 bytes.

The constructor copies two 16-byte `GUID` values from the communications handler.

The PDB field offsets prove `ServiceGUID` at `+0x12DC`.
They prove `ApplicationGUID` at `+0x12EC`.

The module source uses whole-structure assignment for both copies.
This gives the required source model.
