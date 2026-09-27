# Harness save fixtures

These saved games are pinned harness inputs. They are not input recordings.

`late_game_match.gmx` came from the supplied game files. Its original filename was:

`partida larga y controlada, monjes al poder xD (en proceso) (3-08-2014).gmx`

The copy has the same bytes as the supplied file:

- Size: 875,400 bytes.
- SHA-256: `fccd0ca0ccd98a6658a1eeb3b306c89afee3af9caf58ab518ee04eae434687f4`.

`late_game_match_2.gmx` and `new_game_15mins_in.gmx` came from the user's play sessions.
The latter was previously named `test.gmx`. They are personal gameplay data and are not
committed. `../savegames.json` pins them with `"local": true`; the files live in the
gitignored `local/harness/savegames/` folder. Without them, the pool contains only the
committed saves, and a recording that needs them fails its save contract check.

| File | Size | SHA-256 |
| --- | ---: | --- |
| `late_game_match_2.gmx` | 881,104 bytes | `169165e6afa68fc55e18f892f68b55817d62f2489ffec6a7ff128ccccb79d34f` |
| `new_game_15mins_in.gmx` | 239,135 bytes | `b54559781b0889bfea867070326e666ab6543cd317bf93c855c3c7aa1a676547` |

`../savegames.json` pins the fixture names, sizes, and hashes.
Harness runs copy only these saves into a fresh `savegame` directory.
They do not copy personal saves from `runtime/savegame`.
Each run uses private copies. Game writes cannot change these repository files.

Do not replace a fixture to repair a failing test. Add a separately named fixture instead.
Changing the fixture set changes the starting contract for new human recordings.
The harness rejects incompatible replay inputs instead of silently using a different save.

The recorded input cases are `../human-late-game-match.json`, and the local
`local/harness/recordings/human-late-game-match-2.json` and
`local/harness/recordings/human-new-game-15mins-in.json`.
The first case remains qualified on its original one-save contract.
Its first three controlled original runs matched the compared values but lacked
required clock-call counters. The strict checker rejected those runs.
Three fresh runs passed all pair checks with the required counters. These runs
show observed repeatability for this case, not general save compatibility.
After source repairs, three fresh rebuilt runs matched those originals in all 15 pair checks.
See [the check record](../../../decomp_notes/saved_game_fixture_20260916.md).
The two new cases were recorded from the original game using
`late_game_match_2.gmx` and `new_game_15mins_in.gmx`.
They are not suite cases and are not parity-qualified.
A controlled smoke replay of the first case stopped at its 397-second limit
after about 2,665 of 19,101 inputs. The recording contains 18,969 mouse-move messages.
The current replay budget cannot complete this recording. Do not treat the fixture
check as a gameplay pass.

The save files can contain player names and game state from their original sessions.
Renaming a file does not change its contents.

## Clone setup

Keep this folder and `../savegames.json` in the checkout. No personal save path is required.
Prepare the local game assets as described in [runtime setup](../../../runtime/README.md).
Then run `game.cmd setup` to install harness dependencies.
Run `game.cmd test-parity` to include the qualified saved-game case in the standard gameplay tests.

Record inputs with `game.cmd record-original --seconds 180`.
Select Single Player, then Saved Game, then one of the pinned saves.
Press F10 to save the input recording and stop the game.
Do not use the mouse wheel or switch applications while recording.

Replay the printed recording path with `game.cmd replay-original PATH --controlled`.
For the preserved case, use `game.cmd replay-original config/harness/human-late-game-match.json --controlled`.
Use three original runs before comparing the rebuilt game.
Controlled timing and pinned inputs do not alone prove equal game behavior.
See [human recording and replay](../../../docs/human_replay.md) for the checks and limits.
