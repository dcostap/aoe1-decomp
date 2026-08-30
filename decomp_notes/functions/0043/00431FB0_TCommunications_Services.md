# Function notes: 00431FB0 `TCommunications_Services`

## Earlier notes from `decomp_notes/functions/0043/00431FB0_TCommunications_Services.md`

This section is historical. Use the status query for current state.

## 00431FB0 `TCommunications_Services::TCommunications_Services`

- PDB source: `com_serv.cpp`, lines 20 to 37.
- Original size: 113 bytes.
- Historical status: exact registered owner before module migration.

`Service` has 100 entries of 0x60 bytes. `ServiceCount` is at offset 0x2580.

The constructor clears each name with `strcpy(name, "")`. It clears the GUID
pointer and the three integer fields. It then calls `DirectPlayEnumerateA` with
`DPEnumCallback` and `this`.

### Module migration

`src/com_serv.cpp` keeps this source form. It replaces the fragment bank and
wrapper-only class definition. Exact repair resumes from the natural module.
