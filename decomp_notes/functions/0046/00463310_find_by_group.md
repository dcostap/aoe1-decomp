# Function notes: 00463310 `find_by_group`

## Earlier notes from `decomp_notes/functions/0046/00463310_find_by_group.md`

This section is historical. Use the status query for current state.

## 00463310 RGE_Object_List::find_by_group overload

The zone seed uses strict `> -1.0f` checks for both coordinates.

The best-distance test is `best_distance > distance`.

Reload the list object for the return and distance block. This preserved the original register use.
