# Function notes: 004637C0 `find_by_type`

## Earlier notes from `decomp_notes/functions/0046/004637C0_find_by_type.md`

This section is historical. Use the status query for current state.

## 004637C0 RGE_Object_List::find_by_type

A normal `while (node != 0)` scan produced the recorded exact owner.

Use the direct node object return for the sentinel coordinate case.

Keep the best-distance comparison as `best_distance > distance`.
