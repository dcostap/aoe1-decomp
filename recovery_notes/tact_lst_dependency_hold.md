# tact_lst factory dependency hold

## Review basis

Packet `62307b2c2` reunifies `tact_lst.cpp` as one source module. This review
uses the rebased current main `a3c4a35b6` as the source tree. It does not use
the old `*_context.h` files as owner declarations.

The packet needs complete declarations for every class created by its two
factory owners. The shared owners are already published:

- `include/action.h` owns `RGE_Action`.
- `include/act_list.h` owns `RGE_Action_List` and `RGE_Action_Node`.
- `include/task.h` owns `RGE_Task`.

The compiler-facing list header is prepared in `include/tact_lst.h`. It uses
only those shared owners. The narrow include probe is
`tests/tact_lst_owner_probe.cpp`; its object belongs under `build/`.

The source module remains held. Its four factory owners are not all present as
canonical headers.

## Factory owner matrix

| Factory target | Required owner header | Current main state |
| --- | --- | --- |
| `RGE_Action_Enter` | `include/act_entr.h` | Published and compatible |
| `RGE_Action_Transport` | `include/act_tran.h` | Published and compatible |
| `TRIBE_Action_Build` | `include/tact_bld.h` | Published and compatible on current main |
| `TRIBE_Action_Make_Obj` | `include/tact_mob.h` | Missing; only `tact_mob_context.h` exists |
| `TRIBE_Action_Make_Tech` | `include/tact_tek.h` | Published owner declaration |
| `TRIBE_Action_Convert` | `include/tact_cnv.h` | Published owner declaration |
| `TRIBE_Action_Heal` | `include/tact_hea.h` | Missing; only `tact_hea_context.h` exists |
| `TRIBE_Action_Artifact` | `include/tact_art.h` | Published and compatible |
| `TRIBE_Action_Wonder` | `include/tact_wnd.h` | Published and compatible |
| `TRIBE_Action_Discovery_Artifact` | `include/tact_dar.h` | Published and compatible on current main |
| `TRIBE_Action_Hunt` | `include/tact_hnt.h` | Published and compatible |
| `TRIBE_Action_Repair` | `include/tact_rep.h` | Published and compatible |
| `TRIBE_Action_Trade` | `include/tact_trd.h` | Published and compatible |

The compatible headers listed above compile with `action.h`, `act_list.h`, and
`task.h` under the pinned VC5 compiler. The prepared list header and the new
Build and Discovery Artifact owners pass that include and size check.

## Remaining exact dependencies

Publish canonical owner headers for Make Object and Heal. Do not import
`tact_mob_context.h` or `tact_hea_context.h` into the packet source. Do not
copy either missing action class into `tact_lst`.

Start source closure only after `include/tact_mob.h` and `include/tact_hea.h`
are present and all four factory owners compose cleanly with the packet's
shared action, list, and task owners.

Keep the packet factory calls unchanged. Do not add local target classes, fake
slots, raw vptr writes, or layout shims. No source status or translation-unit
registration changed in this hold.
