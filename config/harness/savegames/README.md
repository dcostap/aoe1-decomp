# Harness save fixtures

`late_game_match.gmx` is a saved game supplied by the user. It is not an input recording.
The original filename was:

`partida larga y controlada, monjes al poder xD (en proceso) (3-08-2014).gmx`

The copy has the same bytes as the supplied file:

- Size: 875,400 bytes.
- SHA-256: `fccd0ca0ccd98a6658a1eeb3b306c89afee3af9caf58ab518ee04eae434687f4`.

`../savegames.json` pins the fixture names, sizes, and hashes.
Harness runs copy only these saves into a fresh `savegame` directory.
They do not copy personal saves from `runtime/savegame`.
Each run uses private copies. Game writes cannot change these repository files.

Do not replace a fixture to repair a failing test. Add a separately named fixture instead.
Changing the fixture set changes the starting contract for new human recordings.
The harness rejects incompatible replay inputs instead of silently using a different save.

The recorded input case is `../human-late-game-match.json`.
Its first three controlled original runs matched all compared values, but lacked required clock-call counters.
The strict checker therefore failed those runs.
Three fresh runs with the required counters passed all three pair comparisons.
These runs establish observed original repeatability for this case, not general save compatibility.
After source repairs, three fresh rebuilt runs matched all three qualified originals in all 15 pair checks.
The recording is now a default case in `game.cmd test-parity`, with three runs per executable and all 15 comparisons.
See [the check record](../../../decomp_notes/saved_game_fixture_20260916.md).
The save can contain internal player names and game state from the original session.
Its renamed file does not change that content.

## Clone setup

Keep this folder and `../savegames.json` in the checkout. No personal save path is required.
Prepare the local game assets as described in [runtime setup](../../../runtime/README.md).
Then run `game.cmd setup` to install harness dependencies.
Run `game.cmd test-parity` to include the preserved saved-game case in the standard gameplay tests.

Record inputs with `game.cmd record-original --seconds 180`.
Select Single Player, then Saved Game, then `late_game_match`.
Press F10 to save the input recording and stop the game.
Do not use the mouse wheel or switch applications while recording.

Replay the printed recording path with `game.cmd replay-original PATH --controlled`.
For the preserved case, use `game.cmd replay-original config/harness/human-late-game-match.json --controlled`.
Use three original runs before comparing the rebuilt game.
Controlled timing and pinned inputs do not alone prove equal game behavior.
See [human recording and replay](../../../docs/human_replay.md) for the checks and limits.
