# Function notes: 0049C650 `command_score`

## Recovered attempt history

<!-- recovered:79bbaa687542e97c2e57 -->
### `d050eea3c` `src/scr_game.cpp:4005-4005`

Mapping: `strong`. next mapped function definition is command_score at old line 4007.

```text
    // BINARY NOTE: This command uses the set_game_mode virtual slot.
```
<!-- end-recovered:79bbaa687542e97c2e57 -->

<!-- recovered:df920b6518aca6cb1fd3 -->
### `8b8759603dfe` `src/scratch/0049C650_command_score.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TRIBE_Screen_Game::command_score
// VA: 0049C650
// scr_game.cpp
// Attempts: built natural typed surface: world +0x5B4 show_score byte, eight score_panel pointers at +0x58C, text_line_panel +0x50C, main_view +0x4B8, virtual slots +0x14/+0x18/+0x20.
// Good prologue/loop through reset_score_display matches. Stuck after show_score test: VC5 tail-merges the two set_rect/redraw arms into one common tail with a conditional 0xB8-vs-4 push (144B), while original keeps two fully duplicated call+redraw+epilogue arms (189B).
// Tried explicit if/else returns, switch, two independent ifs, branch-local locals, duplicate helper class/cast, volatile show_score read, and /Ob0,/O1,/Od,/Og- probes. No exact source basin found; no accepted_drift proposed because branch layout/call duplication differs broadly.
```
<!-- end-recovered:df920b6518aca6cb1fd3 -->
