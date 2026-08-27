# tact_bld.cpp source reunification

## Context

The PDB identifies `C:\\msdev\\work\\age1_x1\\tact_bld.cpp` as the owner of
nine normal `TRIBE_Action_Build` methods from lines 45 through 483. Their
address order is the source order in `src/tact_bld.cpp`:

| VA | PDB lines | bytes | owner |
| --- | ---: | ---: | --- |
| `004CD1B0` | 45-47 | 40 | `TRIBE_Action_Build::TRIBE_Action_Build(int, RGE_Action_Object*)` |
| `004CD210` | 55-69 | 142 | `TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)` |
| `004CD2A0` | 77-87 | 61 | `TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object*, RGE_Task*, float, float, float)` |
| `004CD2E0` | 93-103 | 45 | `TRIBE_Action_Build::first_in_stack` |
| `004CD310` | 109-198 | 661 | `TRIBE_Action_Build::set_state` |
| `004CD5E0` | 204-424 | 724 | `TRIBE_Action_Build::update` |
| `004CD910` | 430-433 | 13 | `TRIBE_Action_Build::stop` |
| `004CD920` | 440-447 | 51 | `TRIBE_Action_Build::move_to` |
| `004CD960` | 454-483 | 121 | `TRIBE_Action_Build::work` |

The owning class is `TRIBE_Action_Build`, derived from the canonical
`RGE_Action` owner. `include/tact_bld.h` is an owner-only carrier for this
class. It consumes the canonical action, action-list, action-move, object,
master, combat, and building headers. It does not redeclare those classes.

The exact anchors are `004CD1B0`, `004CD2A0`, `004CD2E0`, `004CD310`,
`004CD910`, and `004CD920`. The nearby `004CD1E0` vector deleting
destructor is compiler generated and has no handwritten owner. The no-PDB
`004CD200` destructor body and padding or boundary entries at `004CD1FE` and
`004CD5A5` are not source owners.

## Statuses

The source retains the reviewed prior statuses:

- `matching`: `004CD1B0`, `004CD2A0`, `004CD2E0`, `004CD310`,
  `004CD910`, `004CD920`.
- `accepted_drift`: `004CD210`, `004CD5E0`, `004CD960`.

The canonical owner composition changes four bytes in the `004CD210` owner-id
comparison. The difference is register allocation only. The function keeps
its 142-byte boundary, two calls, predicates, stores, cleanup, and return.
The prior source expression is retained because it is the simpler natural
form, although reversing the comparison reduces the register difference.

The notification calls use explicit integer and long casts. The canonical
`RGE_Static_Object` owner also declares a nonvirtual six-argument overload.
The casts select the shipped six-argument virtual notification slot.

`update` differs only in the second sub-action vtable-load register. Its
reviewed source retains the original 724-byte boundary, call order, control
flow, stores, cleanup, and returns.

`work` differs only in owner-id and fallback coordinate load order. Its
reviewed source retains the original 121-byte boundary, calls, branches,
stores, cleanup, and returns. Neither accepted-drift owner is marked exact.

## Migration effects

The old `src/tact_bld_tu.cpp` wrapper and nine source-bank fragments are no
longer compiler-facing owners. The direct translation-unit entry now points
to `src/tact_bld.cpp` and registers the six exact owners. The module metadata
records all nine handwritten statuses, including both accepted-drift owners.
The generated compiler destructor remains an emitted class artifact and is not
a handwritten source owner.

The original constructors and `set_state` contain C++ EH registration and
unwind-state stores. The existing `004CD210_TRIBE_Action_Build.rsp` flags remain
the module flags. `set_state` also retains the prior `/GX` evidence in its
source notes.

## Owner closure

`RGE_Action_Move_To` is owned by `include/act_move.h`.
`TRIBE_Building_Object` is owned by `include/t_b_obj.h`.
`TRIBE_Combat_Object` is owned by `include/t_c_obj.h` through that building
owner. No packet-local class carrier remains.

## Scoped validation

The scoped checks ran after source composition. `004CD1B0`, `004CD2A0`,
`004CD2E0`, `004CD310`, `004CD910`, and `004CD920` each reported `MATCH` and
`0.0000%`. `004CD210` reported the documented four-byte
`CONSISTENT_REGISTER_RECOLOR`; it is not registered as an exact owner.
No grouped validation ran.
