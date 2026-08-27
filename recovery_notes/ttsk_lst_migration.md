# ttsk_lst.cpp source reunification

## Translation-unit context

- PDB source: `C:\\msdev\\work\\age1_x1\\ttsk_lst.cpp`.
- The module has two normal owners in source and address order.
- The owner range is `0052C3F0` through `0052C8F0`.
- `0052C8A1` is a switch-table and padding boundary. It is not a source
  owner.
- The direct module header is `include/ttsk_lst.h`.
- The source owner is `src/ttsk_lst.cpp`.
- No compiler or validator has run for this reunification.

The clean worker branch was fast-forwarded to
`source-reunification/terra-6` at `b91c0ff9f` before any build operation. This
provides canonical `include/ani_obj.h`. The source does not include
`ani_obj_context.h` or any other context header.

## Normal owners

1. `0052C3F0` `TRIBE_Task_List::get_target_task`, lines 41-294, 1201 bytes.
2. `0052C8D0` `TRIBE_Task_List::is_attack_task`, lines 299-304, 28 bytes.

The source defines both owners in this order. The former keeps the existing
natural reconstruction and the latter keeps its exact base fallback behavior.

## Canonical dependency closure

The source directly includes these reviewed owners:

- `include/ttsk_lst.h` for `TRIBE_Task_List`.
- `include/task_lst.h` for `RGE_Task_List`, its list/count members, and the
  direct base methods.
- `include/act_obj.h` for the complete `RGE_Action_Object` owner.
- `include/stat_obj.h` for the complete `RGE_Static_Object` owner.
- `include/m_s_obj.h` for the complete `RGE_Master_Static_Object` owner.
- `include/player.h` for the complete `RGE_Player` owner and `isAlly` slot.
- `include/game_globals.h` for `DAT_0057733c`.

The canonical include closure is `task_lst.h -> task.h` and
`act_obj.h -> move_obj.h -> ani_obj.h -> stat_obj.h`, with the other canonical
headers retained by their normal owner includes. No local class, raw offset
view, wrapper, source include, context macro, map/world layout, or CRT
fallback is used.

The target reads these proven owners and fields:

- `RGE_Task`: `attribute_type`, `action_type`, and `object_group`.
- `RGE_Task_List`: `list` at `+0x04`, `list_num` at `+0x08`, and the direct
  `get_target_task` and `is_attack_task` base methods.
- `RGE_Action_Object`: inherited `attribute_type_held`,
  `attribute_amount_held`, `master_obj`, and `owner`.
- `RGE_Static_Object`: `master_obj`, `owner`, `hp`, and `object_state`.
- `RGE_Master_Static_Object`: `id`, `object_group`, `master_type`, `hp`, and
  `unit_level`.
- `RGE_Player`: `id` and virtual `isAlly` at slot `+0x1C`.
- `DAT_0057733c`: the initial float threshold.

The first owner has seven ordered `RGE_Player::isAlly` calls at
`0052C580`, `0052C598`, `0052C60A`, `0052C6B2`, `0052C6CE`, `0052C78F`, and
`0052C7F1`. It has one direct `RGE_Task_List::get_target_task` call at
`0052C894`.

## Ownership and cleanup

`src/ttsk_lst.cpp` is now the sole compiler-facing owner for this PDB module.
The old `src/ttsk_lst_tu.cpp` wrapper, the two per-function source-bank files,
and `include/ttsk_lst_context.h` are removed. The translation-unit metadata and
source-module ownership records were not edited by this worker.

## Candidate proposal

The unregistered candidate proposal is
`build/candidate_tus/ttsk_lst.json`. It names `src/ttsk_lst.cpp`, uses
`config/flags/default.rsp`, and lists both normal owners in PDB order. It has
not been compiled or validated. The lead can apply the matching source-module
and translation-unit metadata changes after reviewing this source.
