# Function notes: 004634C0 `find_by_master_id`

## Earlier notes from `decomp_notes/functions/0046/004634C0_find_by_master_id.md`

This section is historical. Use the status query for current state.

## 004634C0 RGE_Object_List::find_by_master_id

Recovery tests changed stack use and empty-list returns. They did not improve the result.

The stored source uses the normal list scan. It keeps a common return and the original distance expression order.
