# Game notification types

`RGE_Base_Game::notification(type, val1, val2, val3, val4)` sends game events.
`TRIBE_Game::notification` handles them. `include/basegame.h` names the types as `GAME_NOTIFY_*`
macros. Each name is a cleanup label taken from the message or sound the handler produces and from
the code that sends the type.

| Type | Macro | Sender | Handler |
| --- | --- | --- | --- |
| 1 | `NOT_CLOSE_ENOUGH_TO_LAND` | `TRIBE_Player::notify` 0x207 (transport) | "Not close enough to land to unload." |
| 2 | `NOT_ENOUGH_UNLOAD_SPACE` | `notify` 0x206 (transport) | "Not enough room to unload all." |
| 3 | `CANNOT_TRADE_WITH_ENEMY` | `notify` 0x20C with the trade action | "You cannot trade with an enemy." |
| 4 | `PLAYER_DISCONNECTED` | no literal sender | disconnect message |
| 5 | `PLAYER_RESIGNED` | `RGE_Player::do_resign` | resign or disconnect message |
| 6 | `PLAYER_DEFEATED` | `RGE_Player::set_game_status` | defeat message |
| 7 | `TRIBUTE_PAID` | tribute commands | "%s paid %d <resource> in tribute to you." |
| 8 | `DIPLOMACY_CHANGED` | the relation command | ally, neutral, or enemy message |
| 0x64 | `RESEARCH_COMPLETED` | `TRIBE_Action_Make_Tech::update` | sound, buttons, location |
| 0x65 | `RESEARCH_STOPPED` | `TRIBE_Action_Make_Tech::stop` and its destructor | not handled |
| 0x66 | `UNIT_TRAINED` | `TRIBE_Action_Make_Obj::update` | buttons, location |
| 0x67 | `TRAINING_STOPPED` | `TRIBE_Action_Make_Obj::stop` | not handled |
| 0x68 | `NO_ROOM_FOR_UNIT` | `TRIBE_Action_Make_Obj` placement failure | error message |
| 0x69 | `BUILDING_COMPLETED` | `TRIBE_Building_Object` | buttons, location |
| 0x6B | `CANNOT_REPAIR` | `TRIBE_Action_Repair` | "Can't repair ... out of resources." |
| 0x6C to 0x6E | `WONDER_STARTED`, `WONDER_COMPLETED`, `WONDER_DESTROYED` | `TRIBE_Action_Wonder` | wonder messages |
| 0x72 to 0x75 | `ARTIFACTS_CAPTURED`, `ARTIFACTS_LOST`, `RUINS_CAPTURED`, `RUINS_LOST` | `TRIBE_World` victory checks | capture messages |
| 0x76 to 0x7A | `CONVERSION_*` failures | `TRIBE_Action_Convert` | conversion error strings |
| 0x7B | `CONVERSION_SUCCEEDED` | `TRIBE_Action_Convert` | sound |
| 0x7C | `PRODUCTION_QUEUE_CHANGED` | `TRIBE_Building_Object` queue | buttons |
| 0x7D | `ATTRIBUTE_NEEDED` | `TRIBE_Building_Object` queue; `val2` is the missing attribute | attribute message |
| 0x7E | `OBJECT_DEPLETED` | `RGE_Action_Make`, when the object runs out and dies | sound, location |

## Transport messages are not swapped

An earlier version of this note reported an original bug: a transport with units still aboard
(0x206) showed "You cannot trade with an enemy", and a failed trade (0x20C) showed "Not enough room
to unload all." That conclusion was wrong. It came from the rebuilt `TRIBE_Game::notification`
(`00524D70`), whose type 2 and type 3 cases sat in the opposite source order. The code bytes still
matched, but the switch table sent each type to the other block.

The original table at `00525C20` sends type 2 to the block that shows attribute message 0x67 ("Not
enough room to unload all.") and type 3 to the block that shows 0x69 ("You cannot trade with an
enemy."). The dispatch in `TRIBE_Player::notify` (`005159D0`) sends 0x206 as type 2 and 0x20C as
type 3, so each sender shows the matching message. The macros for types 2 and 3 were renamed to
match, and the `@bug` comment was removed. The linked image diff now compares switch tables; see
[linked data findings](linked_data_findings.md).

## Related cleanup

- `STRING_ID_MESSAGE_TRIBUTE_RECEIVED` (0x0BC1) is now `STRING_ID_MESSAGE_TRIBUTE_GOLD`. Its text
  is "%s paid %d gold in tribute to you."; 0x0BC7 to 0x0BC9 are the wood, food, and stone
  messages. `RGE_ATTRIBUTE_MESSAGE_TRIBUTE_RECEIVED` was renamed the same way.
- The tribute and diplomacy sub-switches use `RGE_RESOURCE_*` and `RGE_RELATION_*`.
- `TRIBE_Building_Object` indexed player attributes by byte offset (`attributes[0x2C / 4]`). It
  now uses the attribute names. The `work_type` values use `TRIBE_ACTION_TYPE_MAKE_OBJECT` and
  `MAKE_TECH`.
- More raw action types now use the existing `RGE_ACTION_TYPE_*` and `TRIBE_ACTION_TYPE_*` macros.
  Action type 7 has no macro and stays numeric.

The names are macros, not an enum. A first version declared them as an enum in `basegame.h`. That
changed `.text` in 16 objects, including files that never use the names, and broke 4 exact
claims. `workflow/vc5_lessons.md` already records this effect.

Validation: a full translation-unit audit kept all 5,013 exact claims. 224 of 225 object payloads
equal the baseline. The one difference is `rmm_tdbc.obj`, from the earlier include change.
