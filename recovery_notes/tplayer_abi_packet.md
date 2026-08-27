# tplayer.h ABI packet

This packet is header evidence only. Do not copy Map or World classes.

## Composition rule

`tplayer.h` must include the canonical player.h surface. It must not define
RGE_Map, RGE_Game_World, RGE_Base_Game, or fallback player classes.

player.h now owns the complete RGE_Player base. tplayer.h owns only the first
proved TRIBE_Player field and direct methods. tech.h owns TRIBE_Player_Tech.
It has no Map or World class.

## TRIBE_Player::tech_abling

| Item | Evidence |
| --- | --- |
| Owner | `00513DA0` |
| Source | `tplayer.cpp:1496-1501` |
| Signature | `void TRIBE_Player::tech_abling(long, unsigned char)` |
| Return cleanup | `ret 8` |
| Field | `TRIBE_Player_Tech* tech_tree` at `0x220` |
| Nonzero path | `TRIBE_Player_Tech::enable(short)` at `0050D383` |
| Zero path | `TRIBE_Player_Tech::disable(short)` at `0050D306` |

The long input is narrowed to short only at the enable or disable call.

The candidate includes tech.h and matches `00513DA0` exactly. It has 46 bytes,
zero positional difference, correct owner, boundaries, and direct targets.

## Required fanout

tscenaro now uses tplayer.h and has 79 exact matches. teffects now uses
tplayer.h. Its constructors stay exact. Its two effect loops need codegen
repair before exact promotion. Do not add narrow duplicate player classes.

Sources that call TRIBE_Player_Tech methods must include tech.h.

## Sources

- `inventory/functions/0051/00513DA0_tech_abling.txt`
- `inventory/types/dumps/TRIBE_Player_Tech.txt`
- `inventory/types/dumps/TRIBE_Tech.txt`
- `inventory/classes/all_class_interfaces.csv`, TRIBE_Player row
- `inventory/classes/all_class_interfaces_reference.h`, TRIBE_Player methods
