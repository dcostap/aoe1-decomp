# Function notes: 00490400 `remove_scenario`

## Earlier notes from `decomp_notes/functions/0049/00490400_remove_scenario.md`

This section is historical. Use the status query for current state.

## 00490400 `TRIBE_Campaign_Editor_Screen::remove_scenario`

- PDB source: `scr_cam.cpp`, lines 483 to 497.
- Original size: 124 bytes.
- Flags: `config/flags/0048F5D0_TRIBE_Campaign_Editor_Screen.rsp`.

The prior fragment had an exact result.

The list scroll call uses the current line after removal. It does not use the removed line value.

The body now belongs to `src/scr_cam.cpp`. The migration removes only fragment scaffolding.
