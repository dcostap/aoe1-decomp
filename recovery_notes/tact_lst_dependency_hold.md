# tact_lst factory dependency hold

## Review basis

Packet `62307b2c2` reunifies `tact_lst.cpp` as one source module. This review
uses current main `03097cfd8` as the source tree. It does not use the old
`*_context.h` files as owner declarations.

The packet needs complete declarations for every class created by its two
factory owners. The shared owners are already published:

- `include/action.h` owns `RGE_Action`.
- `include/act_list.h` owns `RGE_Action_List` and `RGE_Action_Node`.
- `include/task.h` owns `RGE_Task`.

The compiler-facing list header is prepared in `include/tact_lst.h`. It uses
only those shared owners. The source module remains held because its factory
targets are not all safely consumable from canonical owner headers.

## Factory owner matrix

| Factory target | Required owner header | Current main state |
| --- | --- | --- |
| `RGE_Action_Enter` | `include/act_entr.h` | Published and compatible |
| `RGE_Action_Transport` | `include/act_tran.h` | Published and compatible |
| `TRIBE_Action_Build` | `include/tact_bld.h` | Missing; only `tact_bld_context.h` exists |
| `TRIBE_Action_Make_Obj` | `include/tact_mob.h` | Missing; only `tact_mob_context.h` exists |
| `TRIBE_Action_Make_Tech` | `include/tact_tek.h` | Present, but not compatible |
| `TRIBE_Action_Convert` | `include/tact_cnv.h` | Present, but not compatible |
| `TRIBE_Action_Heal` | `include/tact_hea.h` | Missing; only `tact_hea_context.h` exists |
| `TRIBE_Action_Artifact` | `include/tact_art.h` | Published and compatible |
| `TRIBE_Action_Wonder` | `include/tact_wnd.h` | Published and compatible |
| `TRIBE_Action_Discovery_Artifact` | `include/tact_dar.h` | Missing; only `tact_dar_context.h` exists |
| `TRIBE_Action_Hunt` | `include/tact_hnt.h` | Published and compatible |
| `TRIBE_Action_Repair` | `include/tact_rep.h` | Published and compatible |
| `TRIBE_Action_Trade` | `include/tact_trd.h` | Published and compatible |

The compatible headers listed above compile with `action.h`, `act_list.h`, and
`task.h` under the pinned VC5 compiler. The prepared list header also passes
that include and size check.

## Unsafe published headers

`include/tact_cnv.h` cannot yet be consumed with the shared owners. It
redeclares `RGE_Action_List`, `RGE_Task`, `RGE_Action`, and
`RGE_Action_Move_To`.

`include/tact_tek.h` cannot yet be consumed with the shared owners. It
redeclares `RGE_Action_Object`, `RGE_Player`, `RGE_Action`, and
`RGE_Base_Game`.

A VC5 include probe reports these exact redefinition errors. Each header needs
canonical-base cleanup before `tact_lst.cpp` can include it. Do not hide the
errors with include-order tricks or guard macros.

## Hold

Publish canonical owner headers for Build, Make Object, Heal, and Discovery
Artifact. Repair the Convert and Make Tech owner headers so they compose with
the shared action, list, and task owners. Then consume all factory headers in
the packet source without local target declarations.

Keep the packet factory calls unchanged. Do not import the old context headers.
Do not add local target classes, fake slots, raw vptr writes, or layout shims.
No source status or translation-unit registration changed in this hold.
