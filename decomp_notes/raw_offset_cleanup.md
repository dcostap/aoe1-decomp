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

## AI module pointer chains

`offsetof` checks confirmed these members:

- `TribeMainDecisionAIModule::player` at 0xF0, `RGE_Player::world` at 0x3C,
  `RGE_Game_World::map` at 0x28 and `world_time` at 4, and `RGE_Map::map_width`/`map_height` at 8/0xC.
- `TribeInformationAIModule::unitHistory` at 0xFF64 and `unitHistoryFilename` at 0xFF90.
- `RGE_Static_Object::owner` at 0xC.

Results:

- `taiinfmd.cpp` `loadUnitHistory` read: now `this->unitHistory`, byte-identical.
- `taiinfmd.cpp` `initialize` (map size and filename) and the owner read in
  the object-memory update: typed access keeps the edited function exact but
  changes the later `objectToTradeWith` (004DEA80) and makes
  `storeAttackMemory` (004E0FD0) lose its exact match by swapping two argument
  loads. Tried a typed local named `map` or `terrain`, no local, a `world` local,
  and swapping the `x1 + x2` order in `storeAttackMemory`. None restored it. The
  raw chains stay with comments naming the members.
- `taibldmd.cpp` `cancelTrainUnit`/`cancelResearch` (`world_time`): the file
  does not include `world.h`. Adding it, at either include position, makes
  `mostNeededResource` (004D4F80) lose its exact match. Kept raw with comments.

## Small member offsets

`offsetof` checks confirmed each member. All four objects are byte-identical.

- `TribeStrategyAIModule::loadRules`: `this + 0x268` is `vcRules`.
- `TDrawSystem::HandleQueryNewPalette`: `this + 0x78` is `palette`.
- `RGE_Scenario::~RGE_Scenario`: the `slot` cursor at 0x1308 walked
  `CityPlan` with ±16-entry strides into `BuildList`, `AiRules`, and the three
  `*File` buffers. It is now a `for` loop over the six named arrays.
- `TribeGameSettingsScreen::~TribeGameSettingsScreen`: the cursor at 0x534
  walked `optionText` and `optionButton` (0x524). It is now a `for` loop.

## `TribeInformationAIModule::updateResourceDropsites`

The loop walked `resources[rType]` with a byte counter `a` (+0x14 per step) and
read `ResourceMemory` fields at +0, +8, +0xD, +0xE and +0x10. It now indexes
`resources[rType][i]` and uses `id`, `gatherValue`, `gone`, `dropDistance` and
`dropsiteID`. Byte-identical.
