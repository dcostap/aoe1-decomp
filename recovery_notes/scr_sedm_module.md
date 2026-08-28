# scr_sedm.cpp module recovery

## Source context

The PDB source is `C:\\msdev\\work\\age1_x1\\scr_sedm.cpp`.
The four normal owners stay in source-line and address order:

- `004B2EF0` constructor, lines 41-86;
- `004B3110` destructor, lines 91-97;
- `004B31A0` `handle_idle`, lines 103-108;
- `004B31D0` `action`, lines 114-154.

All four owners belong to `TRIBE_Screen_Sed_Menu`. The vector deleting
destructor at `004B30F0` is compiler generated.

The constructor proves `title` at `+0x478`, `button[0..3]` at
`+0x47C..+0x488`, and `close_button` at `+0x48C`. The idle method proves
`RGE_Base_Game::input_enabled`. The action method proves the button dispatch,
open-screen construction, campaign-screen construction, main-menu
construction, and panel transitions.

## Missing canonical declarations

The action has two missing canonical provider declarations:

- `TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen()` with
  `??0TRIBE_Campaign_Editor_Screen@@QAE@XZ`. The provider needs the real
  `TScreenPanel` base and complete `0x4C4` object size.
- `TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu()` with
  `??0TRIBE_Screen_Main_Menu@@QAE@XZ`. The provider needs the real
  `TScreenPanel` base and complete `0x4B0` object size.

The complete open-screen declaration is available from `include/scr_sedo.h`.
Do not replace the two missing providers with a size-only class in `include`
or `src`.

The five matching symbols are:

- `??0TRIBE_Screen_Sed_Menu@@QAE@XZ`;
- `??1TRIBE_Screen_Sed_Menu@@UAE@XZ`;
- `?handle_idle@TRIBE_Screen_Sed_Menu@@MAEJXZ`;
- `?action@TRIBE_Screen_Sed_Menu@@MAEJPAVTPanel@@JKK@Z`;
- `??_ETRIBE_Screen_Sed_Menu@@UAEPAXI@Z` (generated scalar deleting
  destructor; the compared fallback is `??_GTRIBE_Screen_Sed_Menu@@UAEPAXI@Z`).

## Temporary recovery

`build/scr_sedm_natural.cpp` is a build-only complete source study. It uses
these canonical providers:

- `include/scr_sedm.h` and `include/Pnl_scr.h`;
- `include/pnl_btn.h` and `include/Pnl_txt.h`;
- `include/basegame.h`, `include/tribegam.h`, and
  `include/rge_base_game_global.h`;
- `include/scr_sedo.h` for the complete open-screen owner.

The study defines temporary size-only records for
`TRIBE_Campaign_Editor_Screen` and `TRIBE_Screen_Main_Menu`. These records
stay under `build` and are not compiler-facing providers.

The current registered wrapper and four matching fragments remain in place
until those two screen owners publish canonical, composable headers. Do not
move the build-only records into `include` or `src`.

## Validation

Candidate metadata: `build/scr_sedm_natural_candidate.json`.
The pinned VC5 build produced these results:

- `004B2EF0`: `MATCH`, 504 of 504 bytes;
- `004B3110`: `MATCH`, 129 of 129 bytes;
- `004B31A0`: `MATCH`, 33 of 33 bytes;
- `004B31D0`: `MATCH`, 502 of 502 bytes;
- generated `004B30F0`: `MATCH`, 30 of 30 bytes.

The comparison reports zero boundary escapes and zero byte differences for
all five entries. The result is build-only evidence. It does not register the
study source or promote the temporary provider records.

The current fragments still use address casts for typed panel-pointer arrays.
A natural direct source needs a typed tab-order API and a typed child-deletion
API before those casts can be removed without hiding an ABI change. This is an
open provider need, not a reason to add a fake vtable or a packed layout.
