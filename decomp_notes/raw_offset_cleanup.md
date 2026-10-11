# Raw offset cleanup

Notes on replacing `(char*)ptr + offset` reads with typed member access.

## `TRIBE_Game::load_game` (00526170) debug dump

The checksum dump read `RGE_Player` fields through a `p_bytes` cursor. A
compile-time `offsetof` check against `include/player.h` (VC5) confirmed each
offset:

| Offset | Member |
| --- | --- |
| 0x28 | `objects` |
| 0x2C | `sleeping_objects` |
| 0x30 | `doppleganger_objects` |
| 0x34 | `victory_conditions` |
| 0x44 | `name` |
| 0x4A | `id` |
| 0x4C | `attribute_num` |
| 0x50 | `attributes` |
| 0x105 | `master_player_id` (printed as `civ=`) |

`load_game` is not an exact match. With typed access its grouped diff went from
3111 to 3125 bytes, and resync similarity from 51.8% to 51.5%. That is
noise-level for a function that is about half matched. No other function or
object payload changed.
