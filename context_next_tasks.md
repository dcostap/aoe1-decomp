**Handoff Context For Next Agent**

**Project state**
- Repo is intentionally dirty with many in-progress files. Do not reset/revert unrelated edits.
- Current priority track was `T_Scenario` / victory parity and `TRIBE_World::new_game` parity.
- Latest builds are green (`build.bat` succeeds, output `dist\empiresx.exe`).

**What was completed**
- `TRIBE_World::new_game` got major parity restoration in `src/game/src/TRIBE_World.cpp:515`:
  - Added full default pop-limit victory points rule setup (`add_points_*` block) and `add_population_entry`.
  - Removed non-source-of-truth `SetVictoryScore/SetVictoryTime` calls from random/non-default victory setup branch.
- `T_Scenario::Save_victory_conditions_into_players` now has full non-stub body in `src/game/src/TRIBE_World_types.cpp:1467`, aligned to `tscenaro.cpp.decomp` structure.
- Added missing `RGE_Game_World` object accessors (needed by scenario objective resolution):
  - Declarations: `src/game/include/RGE_Game_World.h:82`
  - Implementations: `src/game/src/RGE_Game_World.cpp:1034`
  - Methods: `numberObjects`, `numberNegativeObjects`, `object`, `object_ptr`
- `T_Scenario::get_object_pointer` now calls `world->object(id-1)` as in source-of-truth:
  - `src/game/src/TRIBE_World_types.cpp:1340`
- `T_Scenario::rehook` changed from stub to true no-op:
  - `src/game/src/TRIBE_World_types.cpp:1347`

**Important unresolved parity gaps**
- `TRIBE_World::new_random_game` is still a stub fallback:
  - `src/game/src/TRIBE_World.cpp:386`
  - It currently delegates to `RGE_Game_World::new_random_game`.
  - Prior investigation found no recoverable dedicated body under that symbol in current `tworld` export.
- `T_Scenario::save` is still stubbed:
  - `src/game/src/TRIBE_World_types.cpp:1351`
  - This is the next highest-value parity block for scenario/victory persistence.
- Base `RGE_Scenario` stubs still exist in `TRIBE_World_types.cpp` (non-critical for immediate new random game path, but still stubs).
- `TRIBE_Effects` tech-enable/disable handling is partial (`TODO(accuracy)` around `tech_abling`).
- `RGE_Player::update` still has a TODO warning about full victory update loop stability:
  - `src/game/src/RGE_Player.cpp:450`

**Known source-of-truth references**
- `TRIBE_World::new_game`: `src/game/decomp/tworld.cpp.decomp` around lines ~1485-1959 and `tworld.cpp.asm` around ~3200-3850.
- `T_Scenario::Save_victory_conditions_into_players`: `src/game/decomp/tscenaro.cpp.decomp` around ~1605 and asm around ~2731.
- `RGE_Game_World::object/object_ptr`: `src/game/decomp/world.cpp.decomp` around ~4994 and asm around ~10810.

**Immediate next tasks (priority order)**
1. Implement full `T_Scenario::save` parity 1:1 from `tscenaro.cpp.decomp/asm`.
2. Audit `T_Scenario::Save_victory_conditions_into_players` instruction-level edge cases against asm:
   - Especially VictoryType 1/2/3 branches and object-vs-player destroy behavior.
3. Run runtime verification focused on scenario/victory conditions:
   - Load/new game paths that exercise SP victory entries and MP victory mode.
4. Continue parity block after that: command encode/decode stubs in `TRIBE_World_types.cpp` (`RGE_Command`/`TRIBE_Command`) because these are silent gameplay desync risks.
5. Revisit `TRIBE_World::new_random_game` only if new source-of-truth appears; otherwise keep explicit TODO and route through base path.

**Acceptance checks for next agent**
- Build passes with `build.bat`.
- No new crashes on launch.
- Scenario victory/objective conditions actually trigger and evaluate correctly in game.
- No objects referenced by scenario objectives resolve to null unexpectedly when IDs are valid.
- Any remaining stubs must have explicit `// TODO: STUB` (per AGENTS rules).

**Quick resume commands**
- `git status --short`
- `rg -n "T_Scenario::save|Save_victory_conditions_into_players|new_random_game|TODO: STUB" src/game/src src/game/include`
- `build.bat`