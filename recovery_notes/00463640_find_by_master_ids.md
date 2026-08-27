# 00463640 RGE_Object_List::find_by_master_ids

The original schedule loads the master id before the object null check.

Keep this source order. It matched the original compiler schedule.
