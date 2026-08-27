# tplayer.h ABI packet

This packet is header evidence only. Do not copy Map or World classes.

## Composition rule

`tplayer.h` must include the canonical player.h surface. It must not define
RGE_Map, RGE_Game_World, RGE_Base_Game, or fallback player classes.

Current owner ambiguity: player.h does not yet define the RGE_Player base.
Do not publish a derived TRIBE_Player class until that base is canonical.

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

## Required fanout

After player.h supplies the canonical base, add the method to tplayer.h.
Then rebuild tscenaro and teffects. Do not add narrow duplicate player classes.

## Sources

- `inventory/functions/0051/00513DA0_tech_abling.txt`
- `inventory/classes/all_class_interfaces.csv`, TRIBE_Player row
- `inventory/classes/all_class_interfaces_reference.h`, TRIBE_Player methods
