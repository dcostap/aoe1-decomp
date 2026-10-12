# Game runtime

Copy a complete retail install here, so the game has its data to run with:

- Age of Empires 1.0b (`EMPIRES.EXE`, `language.dll`, `data/`, `sound/`, `avi/`)
- Rise of Rome 1.0 (`languagex.dll`, `data2/`, and the rest of the expansion files)

Then copy the beta `empiresx.exe` from `orig/` over the retail one. Its SHA-256 must be
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The beta's own data files are not enough to run the game: they lack the base game
and some AI files the beta expects.

`game.cmd` never runs the game from here. It copies this folder into `build/runtime/`
first and leaves this folder unchanged. The harness uses only the saved games pinned in
`config/harness/savegames.json`, not the `savegame/` folder here.

Everything in this folder except this README is ignored by Git.
