# Function notes: 004324F0 `Refresh`

## Earlier notes from `decomp_notes/functions/0043/004324F0_Refresh.md`

This section is historical. Use the status query for current state.

## 004324F0 `TCommunications_Sessions::Refresh`

- PDB source: `com_sess.cpp`, lines 161 to 186.
- Flags: `config/flags/com_sess.rsp`.
- Original size: 103 bytes.

The function clears its session list.
It clears one 0x50-byte `DPSESSIONDESC2` value.
It copies the application GUID into the descriptor.
It calls DirectPlay `EnumSessions` with `EnumSessionCallback`.

The old fragment used a raw vtable call and fixed addresses.
The merged source uses the DirectPlay interface declaration.
