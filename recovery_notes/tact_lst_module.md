# tact_lst.cpp source module

## Context

The PDB source is `C:\\msdev\\work\\age1_x1\\tact_lst.cpp`.
The owner is `src/tact_lst.cpp`. The source order is:

| VA | PDB lines | Owner |
| --- | --- | --- |
| `004D0150` | 37-38 | `TRIBE_Action_List::TRIBE_Action_List` |
| `004D0170` | 43-88 | `TRIBE_Action_List::create_action` |
| `004D05D0` | 93-156 | `TRIBE_Action_List::create_task_action` |
| `004D0C50` | 160-183 | `TRIBE_Action_List::get_action_name` |

The module uses one compiler-facing source owner. It has no local factory
classes, copied foreign bases, fake slots, raw vptr writes, or layout shims.

## Canonical ownership

`include/tact_lst.h` owns `TRIBE_Action_List`.
`include/action.h`, `include/act_list.h`, and `include/task.h` own the shared
base, list, node, and task declarations.

The factory targets come from their owner headers:
`act_entr.h`, `act_tran.h`, `tact_bld.h`, `tact_mob.h`, `tact_tek.h`,
`tact_cnv.h`, `tact_hea.h`, `tact_art.h`, `tact_wnd.h`, `tact_dar.h`,
`tact_hnt.h`, `tact_rep.h`, and `tact_trd.h`.

## Grouped candidate validation

The pinned VC5 grouped candidate check used
`build/candidate_tus/tact_lst_candidate_final/report.json`.
All four registered Tact List owners match:

| VA | Result | Original | Rebuilt | Owner | Relocations | Boundary |
| --- | --- | ---: | ---: | --- | ---: | ---: |
| `004D0150` | `MATCH` | 25 | 25 | match | 0 | 0 |
| `004D0170` | `MATCH` | 935 | 935 | match | 0 | 0 |
| `004D05D0` | `MATCH` | 1496 | 1496 | match | 0 | 0 |
| `004D0C50` | `MATCH` | 216 | 216 | match | 0 | 0 |

The candidate summary is 4/4 exact. No generated row belongs to this module.

## Publication hold

The Tact List source is ready. The final packet report remains held until the
coordinator registers Tact Mob owner `004D15F0` and validates its 7/7 owners
plus generated `004D0E90`. This lane does not edit Tact Mob configuration.
