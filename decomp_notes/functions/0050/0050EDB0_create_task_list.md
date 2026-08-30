# Function notes: 0050EDB0 `create_task_list`

## Earlier notes from `decomp_notes/functions/0050/0050EDB0_create_task_list.md`

This section is historical. Use the status query for current state.

## 0050EDB0 create_task_list

PDB owner: `tm_co_ob.cpp:157-159`.

The function allocates a 12-byte `TRIBE_Task_List` and calls the existing `RGE_Task_List` constructor owned by `task_lst.cpp:27-30` at `00508E00`. This module does not define that constructor.

`RGE_Task_List` uses four virtual slots: `create_task`, `get_target_task`, `is_attack_task`, and protected `check_task`. `TRIBE_Task_List` keeps four slots. It overrides `get_target_task` and `is_attack_task`.
