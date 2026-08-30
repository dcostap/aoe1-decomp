# Function notes: 0044C780 `RGE_Campaign_Info`

## Earlier notes from `decomp_notes/functions/0044/0044C780_RGE_Campaign_Info.md`

This section is historical. Use the status query for current state.

## 0044C780 RGE_Campaign_Info constructor

The null path calls `strcpy(name, "")`.

This preserves the shipped inline empty-string copy.

The campaign fields use the reviewed gameinfo layout.
