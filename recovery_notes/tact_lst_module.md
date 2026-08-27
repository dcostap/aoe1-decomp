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
All four Tact List owners match:

| VA | Result | Original | Rebuilt | Owner | Relocations | Boundary |
| --- | --- | ---: | ---: | --- | ---: | ---: |
| `004D0150` | `MATCH` | 25 | 25 | match | 0 | 0 |
| `004D0170` | `MATCH` | 935 | 935 | match | 0 | 0 |
| `004D05D0` | `MATCH` | 1496 | 1496 | match | 0 | 0 |
| `004D0C50` | `MATCH` | 216 | 216 | match | 0 | 0 |

The candidate summary is 4/4 exact. No generated row belongs to this module.

## Dependent integration

The Tact List source chain depends on the reduced Tact Mob chain:
`ddd9d1310`, `c44e35261`, `32e9da440`, `1456ce959`, `90f75472b`,
`de26117c1`, `c773638c7`, and `b1ec6a5b3`.

It also depends on follow-up `7c6732a93`, which registers `004D15F0`.
That follow-up reports 7/7 exact Tact Mob owners and generated `004D0E90`
with `MATCH` results. Land these dependencies first or land them atomically.
This is a dependent packet, not a standalone main claim.
