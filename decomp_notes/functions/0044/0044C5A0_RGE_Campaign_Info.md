# Function notes: 0044C5A0 `RGE_Campaign_Info`

## Earlier notes from `decomp_notes/functions/0044/0044C5A0_RGE_Campaign_Info.md`

This section is historical. Use the status query for current state.

## 0044C5A0 RGE_Campaign_Info constructor

The constructor reads the saved name and scenario fields.

It finds the campaign with `strcmp` on the campaign name.

It calls `scenario_number` again at each observed site.

The resize copy uses the typed scenario record buffer.
