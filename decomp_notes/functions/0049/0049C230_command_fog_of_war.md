# Function notes: 0049C230 `command_fog_of_war`

## Translation-unit context

- PDB module: `scr_game.cpp`.
- Owning class: `TRIBE_Screen_Game`; source order is between `command_diplomacy`
  and `command_fps` in `src/scr_game.cpp`.
- Original body: `0049C230-0049C272`, 67 bytes, `__thiscall`.
- Exact anchors: `allowCheatCodes` at `0049C239`, `set_map_fog` at `0049C25F`,
  and virtual slot `+0x20` at `0049C26E`.

## Current mismatch

- No mismatch after the current source change.
- Original and rebuilt bodies are both 67 bytes with no frame and saved `ESI`.
- The three calls, boundaries, relocations, and direct targets match.
- Final strict difference: 0 bytes (`0.0000%`); shape similarity: `100.00%`.
- Focused validation checkpoint `final-natural` is current and reports
  `Result: MATCH`.

## Recovered attempt history

- Fresh baseline used `rge_base_game->fogOfWar()`. It emitted an extra direct
  `fogofwar` call, 61 bytes, and a 41-byte strict difference (`61.1940%`).
- Binary evidence showed `this + 0x5B4` is `world`, `world + 0x28` is `map`,
  and `map + 0x8DB9` is the `fog_flag` byte.
- Replaced the getter with `this->world->map->fog_flag == 0`.
- This natural field expression restored the original load, byte test, call
  order, and complete 67-byte body.

## Rejected approaches

- `rge_base_game->fogOfWar()` is rejected. It changes behavior-side call
  surface and cannot reproduce the original body.
- No artificial source forms were used.

## Open questions

- None for this function. The field chain and all observed calls are supported
  by the original assembly and reviewed class layouts.

## Next useful approaches

- Run the coordinator's promotion review. Keep the field-chain source and do
  not replace it with the semantically similar getter.

## Worker updates

- `wave21-scr-game`: exact natural reconstruction. Validation matched all 67
  bytes, three calls, boundaries, relocations, and direct targets. The grouped
  `scr_game` audit observed 65 registered-owner matches, including this
  function. The report is `build/audits/workers/wave21-scr-game/scr_game/report.txt`.
  Unrelated grouped mismatches remain outside this assignment.
