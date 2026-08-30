# Function notes: 0049CCB0 `command_select_building`

## Recovered attempt history

<!-- recovered:30f1c2b4d9e0108458ec -->
### `7f9d273d677d` `src/matching/0049CCB0_command_select_building.cpp:1-16`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0049CCB0 command_select_building (307B)
// scr_game.cpp:5478-5512
// Natural reconstruction from the executable and same-TU command_view_tribe:
// choose the command object id, preserve the currently selected matching object
// as the find_obj continuation, then select the result and update both views.
// The repeated get_player() expressions are intentional: the original reloads
// the global player for each member call rather than carrying one local.
// Attempt log (sa-66340ab1-command_select_building):
// - baseline typed reconstruction reached exact size, frame, calls, and CFG but
//   left 24 bytes: the common local continuation emitted xor eax,eax and delayed
//   the selected-object push until after the receiver global load.
// - duplicated the natural find_obj call in the null and matching continuation
//   arms. VC5 tail-merged the call while preserving push-before-get_player order;
//   this reached an exact 307-byte match with all 17 call sites aligned.
// - Main-agent audit restored canonical polymorphic object/player/game/view
//   ownership; exact bytes were revalidated after promotion.
```
<!-- end-recovered:30f1c2b4d9e0108458ec -->
