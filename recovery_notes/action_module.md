# action.cpp dependency recovery

## PDB ownership

PDB source: `C:\\msdev\\work\\age1_x1\\action.cpp`.
The compiland has 29 normal owners from `00407460` through `00407D70`.
`RGE_Action` owns every normal entry.
The source owner is now `src/action.cpp`.

## Normal owners

The direct source provides these owners:

- `00407460 RGE_Action` — `src/action.cpp`
- `004074C0 RGE_Action` — `src/action.cpp`
- `004074F0 ~RGE_Action` — `src/action.cpp`
- `00407530 setup` — `src/action.cpp`
- `00407680 setup` — `src/action.cpp`
- `004076D0 create_action_list` — `src/action.cpp`
- `00407740 rehook` — `src/action.cpp`
- `00407790 save` — `src/action.cpp`
- `004078D0 type` — `src/action.cpp`
- `004078E0 first_in_stack` — `src/action.cpp`
- `004078F0 stop` — `src/action.cpp`
- `00407900 move_to` — `src/action.cpp`
- `00407910 work` — `src/action.cpp`
- `00407920 attack_response` — `src/action.cpp`
- `00407930 relation_response` — `src/action.cpp`
- `00407940 set_state` — `src/action.cpp`
- `00407950 inside_obj_update` — `src/action.cpp`
- `00407990 idle_update` — `src/action.cpp`
- `004079D0 update` — `src/action.cpp`
- `00407A20 set_target_obj` — `src/action.cpp`
- `00407A90 set_target_obj2` — `src/action.cpp`
- `00407B00 copy_obj` — `src/action.cpp`
- `00407C00 copy_obj_sprites` — `src/action.cpp`
- `00407C10 get_state_name` — `src/action.cpp`
- `00407D30 targetX` — `src/action.cpp`
- `00407D40 targetY` — `src/action.cpp`
- `00407D50 targetZ` — `src/action.cpp`
- `00407D60 subAction` — `src/action.cpp`
- `00407D70 setSubAction` — `src/action.cpp`

The first 28 entries retain `matching` status.
`00407C10 get_state_name` retains `accepted_drift` status.

## Compiler-generated owner

`004074A0` is the vector deleting destructor.
It has no ordinary source owner.
The candidate expects the VC5 weak symbol `??_ERGE_Action@@UAEPAXI@Z`.
Its scalar fallback is `??_GRGE_Action@@UAEPAXI@Z`.

## Canonical dependencies

`src/action.cpp` includes the canonical surfaces for:

- `RGE_Action`: `include/action.h`;
- `RGE_Action_List`: `include/act_list.h`;
- `RGE_Action_Object`: `include/act_obj.h`;
- `RGE_Master_Action_Object`: `include/m_ac_obj.h`;
- `RGE_Task` and `RGE_Task_List`: `include/task.h` and `include/task_lst.h`;
- file I/O: `include/rge_fio.h`;
- `RGE_Sprite`: `include/sprite.h`;
- `RGE_Static_Object`: `include/stat_obj.h`;
- `RGE_Player`: `include/player.h`;
- `RGE_Game_World`: `include/world.h`.

Complete owner includes remain local to source files that dereference fields or
call methods. No action context header remains in this compiland.
`act_obj.h` is included where source accesses `RGE_Action_Object` fields or
methods. `m_ac_obj.h` remains the sole master-action owner surface.
No derived task-list view or substitute type remains.

## Structural migration and proposal

The former wrapper was `src/action_tu.cpp`. The direct source now contains all
29 PDB owners in address and source order. The 28 exact normal owners and the
accepted-drift `00407C10` body no longer use source includes. The generated
vector deleting destructor at `004074A0` remains source-free.

The candidate proposal is `build/action_candidate_proposal.json`. It uses
`config/flags/004076D0_create_action_list.rsp` and assigns every normal owner
to `src/action.cpp`. After direct ownership registration, the grouped candidate
reports all 28 normal owners as `MATCH` with `0.0000%` difference, zero
relocation mismatches, and zero boundary escapes.

The compiler-generated owner `004074A0` matches its 30-byte range. The
accepted-drift owner `00407C10` remains a 4-byte mismatch in a 216-byte range.
It has zero relocation mismatches and zero boundary escapes.
