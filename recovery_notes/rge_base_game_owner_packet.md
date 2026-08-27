# RGE_Base_Game owner packet

This is a header-only checkpoint. It does not define `RGE_Base_Game`.

## Proved layout facts

| Field | Type | Offset | Evidence |
| --- | --- | --- | --- |
| `prog_info` | `RGE_Prog_Info*` | `0x0C` | `0041E920` loads `[this+0x0C]` |
| `draw_system` | `TDrawSystem*` | `0x48` | `0041E920` stores `[this+0x48]` |
| `prog_mode` | `int` | `0x1B0` | `00421BF0` compares `[this+0x1B0]` |

The class has size `0xA24`. The PDB dump gives high confidence.

## Scope

`include/rge_base_game_evidence.h` gives types and offsets only. It has no
class layout, virtual table, padding, Panel, Map, or World declaration.

Do not use it for member access. Compose the real class only after its
remaining fields and virtual slots have one canonical owner.

## Owner evidence

- `inventory/classes/dumps/RGE_Base_Game.txt`
- `inventory/functions/0041/0041E920_setup_graphics_system.txt`
- `inventory/functions/0042/00421BF0_calc_timings.txt`

A stale World note says `prog_info` is at `0x10`. BaseGame assembly proves
`0x0C`. The checkpoint uses `0x0C`.
