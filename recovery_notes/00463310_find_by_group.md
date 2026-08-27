# 00463310 RGE_Object_List::find_by_group overload

The zone seed uses strict `> -1.0f` checks for both coordinates.

The best-distance test is `best_distance > distance`.

Reload the list object for the return and distance block. This preserved the original register use.
