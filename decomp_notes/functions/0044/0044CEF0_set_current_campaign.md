# Function notes: 0044CEF0 `set_current_campaign`

## Earlier notes from `decomp_notes/functions/0044/0044CEF0_set_current_campaign.md`

This section is historical. Use the status query for current state.

## 0044CEF0 set_current_campaign

The function uses the reviewed campaign and person layouts.

It creates a new campaign record after it grows the pointer array.

The source needs the module destructor declaration for the correct exception cleanup context.

The recorded matching flags were `/O2 /Oy /GX`.
