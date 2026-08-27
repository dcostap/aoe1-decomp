# RGE_Base_Game owner packet

`include/basegame.h` now owns `RGE_Base_Game`.

## Proved layout facts

| Field | Type | Offset | Evidence |
| --- | --- | --- | --- |
| `prog_info` | `RGE_Prog_Info*` | `0x0C` | `0041E920` loads `[this+0x0C]` |
| `draw_system` | `TDrawSystem*` | `0x48` | `0041E920` stores `[this+0x48]` |
| `prog_mode` | `int` | `0x1B0` | `00421BF0` compares `[this+0x1B0]` |

The class has size `0xA24`. The PDB dump gives high confidence.

## Scope

`basegame.h` declares all 98 named fields and the PDB virtual order. It defines
no padding or pointer-owner class. The seven typed gaps use natural alignment.

The pinned VC5 probe confirms `prog_info` at `0x0C`, `draw_system` at `0x48`,
`prog_mode` at `0x1B0`, and class size `0xA24`.

## Owner evidence

- `inventory/types/dumps/RGE_Base_Game.txt`
- `inventory/functions/0041/0041E920_setup_graphics_system.txt`
- `inventory/functions/0042/00421BF0_calc_timings.txt`

A stale World note says `prog_info` is at `0x10`. BaseGame assembly proves
`0x0C`. The checkpoint uses `0x0C`.
