# 0048F5D0 `TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen`

- PDB source: `scr_cam.cpp`, lines 59 to 144.
- Original size: 1,104 bytes.
- Flags: `config/flags/0048F5D0_TRIBE_Campaign_Editor_Screen.rsp`.

The prior fragment had an exact result.

The constructor builds the panel controls in the PDB owner order.

`create_edit` uses `filename_drop` as its parent. The call takes the direct `get_string` result.

## Module merge

The body now belongs to `src/scr_cam.cpp`.

The module uses `include/scr_cam.h`. The header holds the recovered class layout and method declarations.

The migration removes the wrapper, fallback declarations, and fragment file.

## Migration check

The complete rebuilt module matched all 13 registered owners.

Each owner reported `0.0000%` positional difference.
