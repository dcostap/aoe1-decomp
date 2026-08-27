# tact_lst factory dependency hold

## Resolution

Packet `62307b2c2` reunifies `tact_lst.cpp` as one source module. The source
closure is now in `src/tact_lst.cpp`, with declarations in
`include/tact_lst.h`. The former hold ended when the canonical Make Object
owner became available in the reduced Tact Mob chain.

The source uses only canonical action, list, task, and factory owner headers.
It does not use old `*_context.h` declarations. It adds no local factory class,
foreign base, fake slot, raw vptr write, or layout shim.

## Factory owner matrix

| Factory target | Required owner header | State |
| --- | --- | --- |
| `RGE_Action_Enter` | `include/act_entr.h` | Consumed |
| `RGE_Action_Transport` | `include/act_tran.h` | Consumed |
| `TRIBE_Action_Build` | `include/tact_bld.h` | Consumed |
| `TRIBE_Action_Make_Obj` | `include/tact_mob.h` | Consumed from dependency chain |
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

## Dependency order

Land the reduced Tact Mob chain first:
`ddd9d1310`, `c44e35261`, `32e9da440`, `1456ce959`, `90f75472b`,
`de26117c1`, `c773638c7`, and `b1ec6a5b3`.

Then land follow-up `7c6732a93`. It registers Tact Mob owner `004D15F0` and
reports 7/7 exact owners plus generated `004D0E90` as `MATCH`.

Land the Tact List commits after those dependencies, or land all commits
atomically. This packet is not a standalone main claim.
