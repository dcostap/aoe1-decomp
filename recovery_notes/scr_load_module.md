# scr_load.cpp recovery

## Context

- PDB module: `C:\msdev\work\age1_x1\scr_load.cpp`.
- PDB order: constructor, destructor, `fillList`, `handle_idle`, and `action`.
- The module ends at `0049E6CC`. Bytes through `0049E6CF` are padding.
- `Scr_main.cpp` starts at `0049E6D0`.
- The direct owner is `src/scr_load.cpp`.
- The target header is `include/scr_load.h`.

The module uses the canonical screen, panel, control, base-game, program-info,
and `TRIBE_Game` headers. It uses the VC5 `<io.h>` `_finddata_t` provider.
`TribeSPMenuScreen` comes from `include/scr_sing.h`.

## Current bodies

| VA | Body | Status | Evidence |
| --- | --- | --- | --- |
| `0049DD40` | `TribeLoadSavedGameScreen` | matching | Direct source reports `MATCH` and `0.0000%`. |
| `0049E0A0` | destructor | matching | Direct source reports `MATCH` and `0.0000%`. |
| `0049E150` | `fillList` | matching | Direct source reports `MATCH` and `0.0000%`. |
| `0049E2B0` | `handle_idle` | matching | Direct source reports `MATCH` and `0.0000%`. |
| `0049E2E0` | `action` | scratch | Natural source is a ten-byte local-frame drift. |

The compiler-generated vector-deleting destructor at `0049E080` also matches.

## Constructor exact finish

The constructor uses a real `TDrawArea* draw_area` local before `setup`.
The original loads `rge_base_game->draw_area` before `get_info_id`.
Using the direct member expression moved that load after `get_info_id`.

The local restores the original order. The final direct check reports 822 bytes,
matched boundary, matched owner symbol, and `0.0000%` difference. Removing the
local restores the 50-byte mismatch. The local has a normal source purpose.

## Action

`action` uses the real `_finddata_t` for `_findfirst`. It uses a normal 512-byte
confirmation buffer. It reloads `save_dir` before the second delete format.
The reload preserves the original global and fault order.

The action now has the original 1005-byte size, 271 instructions, 36 calls, and
CFG counts. The direct check reports ten positional bytes different. The only
remaining difference is the local frame: original `0x438`, rebuilt `0x40C`.

A prior exact source used one untyped `0x22C` buffer as both text workspace and
`_finddata_t` storage. Do not restore that form. It is not a canonical file
provider and has no established source type. The direct source keeps the real
file type and remains scratch.

`fillList` does not close either search handle. The original has no close call.
Do not add one without new binary evidence.
