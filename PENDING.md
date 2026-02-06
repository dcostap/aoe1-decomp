# PENDING

Last updated: 2026-02-06

## Latest User-Observed Regressions (Main Menu)

- Footer symbol issue: missing `(R)` character to the left of `1997` vs original.
  - Latest fix passes:
    - `TPicturePanel` now follows original `load_pic/free_pic/draw` flow (SHP first, BMP fallback, own/non-own cleanup).
    - Added a minimal `TPicture` implementation (`src/game/src/Picture.cpp`) and wired it into `build.bat` so `%s.bmp` fallback can actually render.
    - **New (exhaustive parity pass)**: `TPanel` constructor/setup defaults were mismatched vs `panel.cpp` source-of-truth.
      - The critical mismatch was `overlapping_children` defaulting to `0` in our build; original defaults it to `1`.
      - This can make later text panels redraw parent background over earlier sibling panels (which can hide `circlep2` and leave a blank gap before `1997`).
      - `TPanel` now restores original defaults (`overlapping_children=1`, `handle_mouse_input=1`, `visible=0`, `need_redraw=RedrawFull`, etc.) and closer `set_color` / `set_active` redraw semantics.
  - Additional placement fix (2026-02-06):
    - Adjusted `TRIBE_Screen_Main_Menu` footer placement in `src/game/src/Scr_main_impl.cpp` to match the original effective coordinate usage from `Scr_main.cpp.asm`:
      - `circlep2` Y now derives from the first copyright text top coordinate path,
      - `ms_copy_text2` Y now uses the same top baseline path (instead of a hardcoded bottom-line value).
  - Follow-up placement correction (2026-02-06):
    - Corrected a remaining swapped axis/parity issue in `Scr_main_impl.cpp` for `circlep2` setup:
      - `circlep2` X now matches original effective path: `(copy1_text_right - pnl_x) + 3`,
      - `circlep2` Y now matches original effective path: `copy1_text_top + 1`.
  - Status: **runtime-verified by user** (no remaining blank-space regression observed in main menu).
- Footer instability/flicker: bottom text occasionally changes on button clicks (example: non-expansion text flickers to expansion text).
  - Updated hypothesis: previous `TPanel` default mismatch (`overlapping_children=0`) likely caused redraw overlap artifacts.
  - Status: **no current user-visible regression** in latest verification pass.

## Main Menu Visual Parity (High Priority)

- Re-verify footer text composition/placement after latest fixes in:
  - `Scr_main_impl.cpp` (deterministic footer string assembly),
  - `Pnl_pic.cpp` (`circlep2` SHP/BMP load path + draw/free behavior),
  - `Picture.cpp` (new minimal BMP loader/draw path used by `TPicturePanel` fallback),
  - `TPanel.cpp` (restored constructor/setup defaults and redraw behavior),
  - `tribegam.cpp` (single active main-menu instance + consistent panel ownership).
- Confirm final parity for:
  - footer copy line centering and symbol placement (`\xA9`/`\xAE`/`\x2122`),
  - button font weight/size,
  - button text color tone (currently can still look yellow-ish vs original orange/pink),
  - background appearance (original looks smoother).
- Keep comparing against original EXE side-by-side screenshots.

## `TEasy_Panel` Config Parsing / Styling Gaps

- `src/game/src/Panel_ez.cpp` parser is still a simplified/loose parser, not exact ASM-style sscanf layout.
- This can still cause color/style divergence in `text_color*`, `focus_color*`, `state_color*`, bevel, and background behavior.
- `RGE_Base_Game::get_sound(int)` path is now wired for created buttons; keep validating in runtime flows.

## Button Rendering Parity (`TButtonPanel`)

- `src/game/src/TButtonPanel.cpp` received a strict parity pass (defaults, setup, destructor cleanup, restart sound, draw state behavior), but still requires broader runtime validation.
- Several inherited virtual handlers remain stubbed/no-op and may matter for edge-case behavior.

## Shape Rendering (`TShape`)

- SHP/SLP mixed path is improved and runtime spam (`shape_draw: No FShape or shape_info`) is currently not recurring in menu smoke runs.
- Remaining parity item: SLP path still uses current software decode path, not a stricter port of original sprite-draw routine.

## Picture Rendering (`TPicture`)

- New file `src/game/src/Picture.cpp` currently implements:
  - ctor/dtor basics,
  - BMP file/resource load for 8-bit uncompressed data,
  - software draw into `TDrawArea`.
- Explicit TODOs left in code:
  - exact original transparency path (`TransInfo`/`DibCheckTrans`),
  - exact `DibBlt` / `TransDibBlt` behavior for all pixel formats,
  - broader format coverage beyond current minimal path.

## Draw/Span Infrastructure

- `src/game/src/spanlist.cpp` currently implements only a subset.
- TODO in code: add only required missing ops (`DeleteSpan`, `Merge`, etc.) if parity/debug shows they are needed.

## Menu Logic / Screen Flow

- `src/game/src/Scr_main_impl.cpp`:
  - Main-menu flow now implements source-of-truth structure for:
    - `handle_idle` input re-enable behavior,
    - `key_down_action` handling for `C` (credits screen path) and developer `L` reload path,
    - button actions for Single Player / Multiplayer / Help / Scenario Builder / Exit,
    - CD gate checks for Single Player (`0x7d8`) and Scenario Builder (`0x7da`).
  - **Important temporary limitation (documented in code):**
    - target screens are currently stub screens (`MainMenuStubScreen`) because full classes are not yet compiled in this branch (`TribeSPMenuScreen`, `TribeMPStartupScreen`, `TRIBE_Screen_Sed_Menu`, `TRIBE_Credits_Screen`).
    - help confirm dialog path is still direct `WinHelpA` (original uses a named confirm dialog path).
- `src/game/src/tribegam.cpp`:
  - Added queued screen switching (`tribe_queue_screen_switch`) to avoid deleting/replacing active screens during input dispatch.
  - `TRIBE_Game::handle_idle` / `handle_paint` now apply pending switches safely.
  - Added explicit `TRIBE_Game::load_db_files()` stub (returns success; TODO remains for original behavior).
  - Keep tightening `start_video`/`start_menu` and full panel-system parity as next phase.

## `TRIBE_Game` / `RGE_Base_Game` Stubs (Non-Menu Flow)

- `src/game/src/tribegam.cpp` TODOs still open:
  - `close_game_screens` (0x00523E10),
  - `start_scenario` (0x00523620),
  - `load_game` (0x00523C60),
  - `start_video` (0x00523910),
  - accurate video shutdown/menu music startup behavior,
  - `TRIBE_Screen_Game` mode-change callback when that type is fully implemented.
- `src/game/src/basegame.cpp` TODOs still open:
  - `setPlayerHasCD`, `setPlayerVersion`,
  - `check_for_cd` full logic,
  - `DriveInformation` setup path,
  - `clear_map_view_info` call once `RGE_Map` side is complete,
  - minor error-code parity note around memory/DX checks.

## Next Steps

1. Runtime-test the new main-menu transitions end-to-end:
   - Single Player button path,
   - Multiplayer button path,
   - Scenario Builder button path,
   - hidden `C` credits hotkey path,
   - stub-screen Back/ESC return to main menu.
2. Replace `MainMenuStubScreen` transitions with real screen classes once those source files are compiled in this branch:
   - `Scr_sing` / `TribeSPMenuScreen`,
   - `scr_mp` / `TribeMPStartupScreen`,
   - `scr_sedm` / `TRIBE_Screen_Sed_Menu`,
   - `scr_cred` / `TRIBE_Credits_Screen`.
3. Implement original confirm-dialog help path (`"Confirm Dialog"` panel flow) instead of direct `WinHelpA`.
4. Keep tightening `TEasy_Panel` parser toward original `sscanf` behavior where it still diverges.
