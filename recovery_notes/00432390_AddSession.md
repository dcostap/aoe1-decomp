# 00432390 `TCommunications_Sessions::AddSession`

- PDB source: `com_sess.cpp`, lines 126 to 157.
- Flags: `config/flags/default.rsp`.
- Original size: 342 bytes.

`SEs` is 0x238 bytes.
It has 255-byte name and password arrays.
It has two 16-byte `GUID` fields.

The original writes all four user values to `User1`.
This source keeps that behavior.
It does not write `User2`, `User3`, or `User4`.
