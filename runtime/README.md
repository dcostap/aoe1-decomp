# Game runtime

Copy a complete retail install here, so the game has its data to run with:

- Age of Empires 1.0b (`EMPIRES.EXE`, `language.dll`, `data/`, `sound/`, `avi/`)
- Rise of Rome 1.0 (`languagex.dll`, `data2/`, and the rest of the expansion files)

Leave the retail `empiresx.exe` in place. `game.cmd` replaces it with the rebuilt or
original executable in its own copy of this folder. The build also extracts the program
icon from the retail `EMPIRES.EXE` here.

The beta's own data files are not enough to run the game: they lack the base game
and some AI files the beta expects.

`game.cmd` never runs the game from here. It copies this folder into `build/runtime/`
first and leaves this folder unchanged. The harness uses only the saved games pinned in
`config/harness/savegames.json`, not the `savegame/` folder here.

Everything in this folder except this README is ignored by Git.
