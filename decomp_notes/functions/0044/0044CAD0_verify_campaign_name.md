# Function notes: 0044CAD0 `verify_campaign_name`

## Earlier notes from `decomp_notes/functions/0044/0044CAD0_verify_campaign_name.md`

This section is historical. Use the status query for current state.

## 0044CAD0 verify_campaign_name

The function compares campaign names with the period `strcmp` implementation.

The natural `if` return form preserves the shipped unsigned-byte result without explicit byte casts.
