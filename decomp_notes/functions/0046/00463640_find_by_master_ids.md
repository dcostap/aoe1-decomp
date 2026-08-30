# Function notes: 00463640 `find_by_master_ids`

## Earlier notes from `decomp_notes/functions/0046/00463640_find_by_master_ids.md`

This section is historical. Use the status query for current state.

## 00463640 RGE_Object_List::find_by_master_ids

The original schedule loads the master id before the object null check.

Keep this source order. It matched the original compiler schedule.
