# Local game runtime

This folder is the local runtime source for build and startup tests.

It must contain the complete Rise of Rome installation files. The file
`empiresx.exe` must be the 1998-07-17 beta executable.

Required beta EXE SHA256:

```text
88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90
```

The other files provide the complete release installation. Do not replace
`EMPIRES.EXE`, `data/`, `data2/`, `avi/`, `sound/`, or the language files.

`tools/prepare_runtime.py` uses this folder by default. It copies the files to
`build/runtime/` before it starts a test. It does not change this folder.

Harness runs do not copy this folder's `savegame` directory.
They use only the repository saves pinned by `config/harness/savegames.json`.
Normal `game.cmd original` and `game.cmd rebuilt` launches still copy local saves.
See [save fixtures](../config/harness/savegames/README.md) for setup and replay limits.

The game files are ignored by Git. Keep this README tracked. Do not modify the
original files under `orig/` or the user's installed game.

Keep `runtime` included in sparse checkouts.
Before changing sparse rules, preserve a verified copy of these ignored files.
