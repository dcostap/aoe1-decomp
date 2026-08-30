# Function notes: 00529A70 `action_user_command`

Module notes: `decomp_notes/tribegam_module.md`.

## Recovered attempt history

<!-- recovered:219aaf3eece644809bbe -->
### `056a20c24f68` `src/scratch/00529A70_action_user_command.cpp:1-24`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00529A70 TRIBE_Game::action_user_command
// tribegam.cpp:5115-5280
//
// Attempt log:
// - baseline: the old scratch used unrelated panel/chat helpers and missed
//   most of the packet calls.  Rebuilt the dispatcher from the source bands.
// - behavior: restored the reset-communications drop path, game-over path,
//   sync-save path, chat-received path, and player communication warning.
//   The fields remain named through the period base-game, world, and screen
//   surfaces.
// - control-flow: packet source-line order for the second switch and an
//   explicit shared drop-popup tail recovered all 49 calls and 1135 bytes.
// - ABI/layout: world +0x58 owns the command object, RGE_Player::name is
//   +0x44, and WhoAmI(param2)/IsPlayerOutOfSync(player) are overloaded calls.
// - layout: temp_str is 260 bytes because get_string writes 0x100 bytes at
//   temp_str + 4.  This restores the oracle's 0x208 frame.
// - layout: msg[260] or msg[252] changed the frame or moved temp_str; the
//   period-plausible msg[256]/temp_str[260] pair is the stable layout.
// - behavior: save_game uses the msg base.  The matching source uses msg as
//   the output buffer; the old msg + 4 forms were decompiler stack aliases.
// - exact: natural msg-base uses match all 1135 bytes, 49 calls, and the EH
//   frame under /GX.
// - ABI: standalone fallback declarations now use the proven command,
//   player_num, and TPanel names. They do not change emitted bytes.
```
<!-- end-recovered:219aaf3eece644809bbe -->
