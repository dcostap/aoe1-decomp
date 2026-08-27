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
`RGE_Action` owner. `include/tact_bld.h` is an owner-only declaration for this
class. It includes only `action.h`; that header supplies the base and the
forward declarations for pointer parameters. Full dependency owners are
included only by `src/tact_bld.cpp`.

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

The pre-cleanup source changed four bytes in the `004CD210` owner-id
comparison. After full owner includes moved to `src/tact_bld.cpp`, the
candidate check reports this constructor as `MATCH` with 142 bytes. The
source module still records its prior `accepted_drift` status. No status move
is made from an observed candidate result.

The notification calls use explicit integer and long casts. The canonical
`RGE_Static_Object` owner also declares a nonvirtual six-argument overload.
The casts select the shipped six-argument virtual notification slot.

`update` keeps its 724-byte boundary, owner symbol, 24 calls, 22 conditional
branches, and 13 returns. It has four strict byte differences. The direct
checker identifies a virtual-slot replacement at offset `+01A5`: original
`vslot+0x1F0`, rebuilt `vslot+0x1F8`. Its dispatcher load also uses a different
table-offset form. The accepted-drift status remains supported by this strict
call-surface mismatch.

`work` keeps its 121-byte boundary, owner symbol, four calls, five conditions,
and two returns. It has nine strict byte differences. The differences cover
the owner-id register map and fallback coordinate stack-home load order. The
accepted-drift status remains supported by this strict register-map mismatch.

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

The scoped candidate check ran after the public-header cleanup. The six exact
owners `004CD1B0`, `004CD2A0`, `004CD2E0`, `004CD310`, `004CD910`, and
`004CD920` each reported `MATCH`, `0.0000%`, owner-symbol match, zero
relocation-target mismatches, and zero boundary escapes. The observed owners
also had owner-symbol match, zero relocation-target mismatches, and zero
boundary escapes: `004CD210` reported `MATCH` with 142 bytes, `004CD5E0`
reported `MISMATCH` with four bytes (`0.5525%`), and `004CD960` reported
`MISMATCH` with nine bytes (`7.4380%`). No status move was made from the
observed candidate result.
