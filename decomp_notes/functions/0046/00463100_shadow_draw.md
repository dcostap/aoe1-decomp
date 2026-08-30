# Function notes: 00463100 `shadow_draw`

## Earlier notes from `decomp_notes/functions/0046/00463100_shadow_draw.md`

This section is historical. Use the status query for current state.

## 00463100 RGE_Object_List::shadow_draw

`shadow_draw` is virtual slot four after the object vptr.

The master object has a virtual destructor. This supplies its vptr.

When fog is active, the function checks `master_obj->fog_flag` before the virtual call.
