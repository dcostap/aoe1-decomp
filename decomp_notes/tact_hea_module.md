# tact_hea.cpp source closure

## PDB context

The PDB source is `C:\\msdev\\work\\age1_x1\\tact_hea.cpp`.
The seven normal owners keep this source and address order:

| VA | PDB lines | bytes | owner | status |
| --- | --- | ---: | --- | --- |
| `004CE930` | 41-43 | 40 | `TRIBE_Action_Heal::TRIBE_Action_Heal` | matching |
| `004CE990` | 51-59 | 120 | `TRIBE_Action_Heal::TRIBE_Action_Heal` | matching |
| `004CEA10` | 67-74 | 61 | `TRIBE_Action_Heal::TRIBE_Action_Heal` | matching |
| `004CEA50` | 80-92 | 58 | `TRIBE_Action_Heal::first_in_stack` | matching |
| `004CEA90` | 98-169 | 566 | `TRIBE_Action_Heal::set_state` | scratch |
| `004CECF0` | 175-365 | 739 | `TRIBE_Action_Heal::update` | scratch |
| `004CF030` | 371-390 | 96 | `TRIBE_Action_Heal::work` | matching |

The scalar deleting destructor at `004CE960` is compiler generated. It has no
source-line owner. The constructor sequence, `first_in_stack`, and `work` are
exact anchors for the `TRIBE_Action_Heal` owner.

## Source ownership and dependencies

`src/tact_hea.cpp` is the only compiler-facing owner. It contains all seven
normal definitions in PDB order. The former wrapper and source-bank fragments
are removed. `include/tact_hea.h` keeps the owner declaration, includes
`action.h`, and uses pointer forward declarations only.

The source includes the canonical dependency set from the owner packet:
`act_move.h`, `act_list.h`, `act_obj.h`, `stat_obj.h`, `m_s_obj.h`,
`m_ac_obj.h`, `move_obj.h`, `t_c_obj.h`, and `t_b_obj.h`. It also includes the
complete `task.h`, `player.h`, `world.h`, and `sound.h` surfaces needed by body
member access. No `tact_hea_context.h` fallback or copied foreign layout is
used.

The direct source uses canonical names for the same proven fields. The action
coordinates use `target_x`, `target_y`, and `target_z`. Task work data uses
`work_val1` and `work_range`. The action master is cast to its canonical
`RGE_Master_Action_Object` owner for `work_rate`.

## Candidate validation

The direct source compiled with the pinned VC5 compiler and
`config/flags/004CE990_TRIBE_Action_Heal.rsp`. The candidate proposal is
`build/candidate_tus/tact_hea_direct/proposal.json`.

| VA | kind | result | rebuilt | diff | relocations | boundary escapes |
| --- | --- | --- | ---: | ---: | ---: | ---: |
| `004CE930` | exact | MATCH | 40 | 0 | 0 | 0 |
| `004CE990` | exact | MATCH | 120 | 0 | 0 | 0 |
| `004CEA10` | exact | MATCH | 61 | 0 | 0 | 0 |
| `004CEA50` | exact | MATCH | 58 | 0 | 0 | 0 |
| `004CF030` | exact | MATCH | 96 | 0 | 0 | 0 |
| `004CEA90` | observed | MISMATCH | 566 | 456 | 0 | 0 |
| `004CECF0` | observed | MISMATCH | 739 | 568 | 0 | 0 |
| `004CE960` | generated | MATCH | 30 | 0 | 0 | 0 |

The candidate has five exact normal owners, two observed scratch owners, and
one exact compiler-generated destructor. All owner symbols and boundaries
match. The two scratch owners retain their natural source bodies and exact
original sizes, but canonical direct dependencies change their codegen.

No codegen probe was run. Future matching work should start with the canonical
`set_state` and `update` source context. Do not restore the removed fallback
header or copied foreign class layout.

## Rebase validation

The direct source chain was rebased onto current main at `ef17afb7f`.
The earlier closure commit was already upstream, so rebase dropped that
duplicate patch. Source-module statuses remain unchanged: five matching
owners and two scratch owners.

A fresh complete candidate ran after the rebase. It covered every registered
exact owner, both observed scratch owners, and the generated destructor. The
command was:

`python tools/validate_candidate_tu.py --proposal build/candidate_tus/tact_hea_direct/proposal.json --output-dir build/candidate_tus/tact_hea_direct/rebased`

The report is `build/candidate_tus/tact_hea_direct/rebased/report.json`.

| VA | kind | status | result | original | rebuilt | diff | owner | relocations | boundary |
| --- | --- | --- | --- | ---: | ---: | ---: | --- | ---: | ---: |
| `004CE930` | exact | matching | MATCH | 40 | 40 | 0 (0.0000%) | match | 0 | 0 |
| `004CE990` | exact | matching | MATCH | 120 | 120 | 0 (0.0000%) | match | 0 | 0 |
| `004CEA10` | exact | matching | MATCH | 61 | 61 | 0 (0.0000%) | match | 0 | 0 |
| `004CEA50` | exact | matching | MATCH | 58 | 58 | 0 (0.0000%) | match | 0 | 0 |
| `004CF030` | exact | matching | MATCH | 96 | 96 | 0 (0.0000%) | match | 0 | 0 |
| `004CEA90` | observed | scratch | MISMATCH | 566 | 566 | 456 (80.5654%) | match | 0 | 0 |
| `004CECF0` | observed | scratch | MISMATCH | 739 | 739 | 568 (76.8606%) | match | 0 | 0 |
| `004CE960` | generated | compiler_generated | MATCH | 30 | 30 | 0 (0.0000%) | unverified | 0 | 0 |

The complete candidate result is unchanged from the prior evidence. It has
five exact normal owners, one exact generated destructor, and two observed
scratch owners. No scratch owner was promoted.
