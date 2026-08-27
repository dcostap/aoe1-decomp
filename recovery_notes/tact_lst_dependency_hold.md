# tact_lst factory dependency hold

## Resolution

`tact_lst.cpp` is one canonical source module. The source closure is in
`src/tact_lst.cpp`, with declarations in `include/tact_lst.h`. The former hold
ended when the canonical Make Object owner reached main. Tact Mob is canonical
through `e97ffd370`. Its candidate
reports seven of seven registered exact owners and generated `004D0E90` as
`MATCH`. Tact List is canonical through `0801f9d0e`. Its four grouped owners
match.

The source uses only canonical action, list, task, and factory owner headers.
It does not use old `*_context.h` declarations. It adds no local factory class,
foreign base, fake slot, raw vptr write, or layout shim.

## Factory owner matrix

| Factory target | Required owner header | State |
| --- | --- | --- |
| `RGE_Action_Enter` | `include/act_entr.h` | Consumed |
| `RGE_Action_Transport` | `include/act_tran.h` | Consumed |
| `TRIBE_Action_Build` | `include/tact_bld.h` | Consumed |
| `TRIBE_Action_Make_Obj` | `include/tact_mob.h` | Consumed |
| `TRIBE_Action_Make_Tech` | `include/tact_tek.h` | Consumed |
| `TRIBE_Action_Convert` | `include/tact_cnv.h` | Consumed |
| `TRIBE_Action_Heal` | `include/tact_hea.h` | Consumed |
| `TRIBE_Action_Artifact` | `include/tact_art.h` | Consumed |
| `TRIBE_Action_Wonder` | `include/tact_wnd.h` | Consumed |
| `TRIBE_Action_Discovery_Artifact` | `include/tact_dar.h` | Consumed |
| `TRIBE_Action_Hunt` | `include/tact_hnt.h` | Consumed |
| `TRIBE_Action_Repair` | `include/tact_rep.h` | Consumed |
| `TRIBE_Action_Trade` | `include/tact_trd.h` | Consumed |

The four Tact List owners pass the grouped candidate check. The owner,
relocation, and boundary results are recorded in
`recovery_notes/tact_lst_module.md`.

## Resolved main state

Tact Mob is canonical through `e97ffd370`. The module has seven registered
exact owners and generated `004D0E90` as `MATCH`.

Tact List is canonical through `0801f9d0e`. Its four grouped owners are
`MATCH`.
