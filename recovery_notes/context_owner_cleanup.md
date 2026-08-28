# Retained context owner audit

This audit checks the seven context headers retained after the stale-artifact
cleanup. References below are source and configuration references, not text in
older recovery notes.

| Context | Actual consumer | Canonical owner | Result |
| --- | --- | --- | --- |
| `act_entr_context.h` | `src/scratch/00402740_update.cpp` | `act_entr.h`, `action.h`, `act_list.h`, `act_move.h`, `act_obj.h`, `player.h`, `task.h`, `world.h`, and `xy_point.h` | Consumer now uses the canonical closure. Removed. |
| `map_context.h` | `include/rmm_terr.h` | `map.h` | RMM terrain now includes the complete Map owner. Removed. |
| `map_tile_context.h` | None | `map.h` | Map owns the complete Tile record. Removed. |
| `m_co_obj_context.h` | None | `m_co_obj.h` and `com_obj.h` | Combat master and object owners are complete. Removed. |
| `rmm_base_context.h` | None | `rmm_base.h` | Random-map base owns the complete module and stack records. Removed. |
| `tvictory_context.h` | None | `tvictory.h` | Tribe victory owns the complete derived class. Removed. |
| `victory_context.h` | None | `victory.h` | Victory owns the complete base class and records. Removed. |

No unresolved provider-dependent context remains in this list. The audit found
no production or scratch include for the six context headers with no consumer.
The action-enter scratch owner was the only live context consumer, and its
canonical dependency closure is complete.
