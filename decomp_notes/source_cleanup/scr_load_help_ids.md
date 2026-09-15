# Load-screen help IDs

## Result

`0x7531` (30001) identifies help text for the OK button.
`0x7532` (30002) identifies help text for the Cancel button.
These are string lookup IDs, not button captions, action codes, or help-page numbers.

Suggested cleanup names are `IDS_HELP_OK` and `IDS_HELP_CANCEL`.
These are descriptive names, not recovered original macro names.
The exact historical text remains unknown.

## Evidence

The repo-local original executable directly supplies both IDs in the load-screen constructor:

- `0049DF98`: push `0x7531`; `0049DF9D`: call `004668B0`.
- `0049DFA6`: push `0x7532`; `0049DFAB`: call `004668B0`.
- Both calls also supply `-1` as their second argument.

Original `TPanel::set_help_info` at `004668B0` stores its first argument at panel offset `0xE4`.
It stores its second argument at `0xE8`.
The reviewed declarations identify these fields as `help_string_id` and `help_page_id`.

Original `TPanel::get_help_info` reads `0xE4` at `0046692E`.
At `00466939`, it passes that value to `TPanel::get_string` (`00466870`).
Thus the lookup path establishes the resource type even when the selected DLLs lack those IDs.

Source call sites independently identify the button roles:

- `src/scr_load.cpp`, `src/scr_save.cpp`, `src/scr_set.cpp`, and `src/scr_name.cpp` assign both IDs consistently.
- `src/scr_mp.cpp` and `src/dlg_dip.cpp` use the same assignments.
- `src/scr_mps.cpp` assigns `0x7532` to Cancel buttons.
- `src/dlg_smsg.cpp` assigns `0x7531` to its OK button.

The pilot's resource report establishes that both IDs are missing from these checked files:

- `runtime/language.dll`
- `runtime/languagex.dll`
- `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`

Additional read-only extraction found both IDs missing from:

- `E:/GamesInstalled/Age of Empires/language.dll`
- `E:/GamesInstalled/Age of Empires_gold_og_nt4/language.dll`
- `E:/GamesInstalled/Age of Empires/language_up.dll`

Both installed base DLLs have the same SHA-256 as the runtime base DLL:
`3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.

The checked `language_up.dll` SHA-256 is:
`68898333485d09ca9c5d1cea6be4b170184faa7f6fc504cd5aa17b3063109798`.
That additional file is reference evidence, not a replacement runtime asset.

`TRIBE_Game::get_string` tries the expansion table before the base table.
The original base lookup at `0041C9C0` clears the buffer when the string lookup fails.
With the checked runtime files, these missing IDs therefore supply empty text through this lookup path.
This conclusion does not assert a visually observed tooltip result.

## Limits and guidance

Missing text does not make the resource type or button role unknown when the executable establishes the lookup path.
Keep the historical text unknown. Do not invent a help sentence or supply replacement resource data.
Names can describe the proven role without claiming that text was recovered.

This investigation inspected source, original executable instructions, and resource bytes.
No builds, matching checks, audits, tests, or games ran.
No pilot source, header, or commit changed.
