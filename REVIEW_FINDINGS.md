# Code Review: Game Init, Main Menu, and SP Random Game UI

## Scope
Compared implemented code against `*.cpp.decomp` source of truth for:
- `basegame.cpp` — game initialization, message loop, wnd_proc
- `tribegam.cpp` — TRIBE_Game overrides, screen management
- `Scr_main_impl.cpp` — main menu screen
- `Scr_sing_impl.cpp` — single player menu
- `scr_mps_impl.cpp` — MP setup screen (random game)
- Sound system wiring

---

## BUGS (likely regressions or crashes)

### B1. `run()` uses `game_mode` instead of `prog_mode` [basegame.cpp:1076]
**Decomp** (0x0041CFD0): The blocking GetMessage loop runs when `prog_active == 0 || (prog_mode != 4 && prog_mode != 2)`.
**Current code**: checks `game_mode == 4 || game_mode == 2` and doesn't check `prog_active`.
**Impact**: The message loop structure doesn't match original. Could cause hangs or missed idle processing.
**Fix**: Replace `game_mode` with `prog_mode` and add `prog_active` check.

### B2. `run()` has inverted `handle_message` return value check [basegame.cpp:1080,1090]
**Decomp**: `if (iVar1 != 0) { TranslateMessage; DispatchMessage; }` — dispatches when handle_message returns NON-zero.
**Current code**: `if (!this->handle_message(&msg))` — dispatches when handle_message returns ZERO.
**Impact**: Messages may be dispatched/swallowed incorrectly. The convention is: return non-zero = "not consumed, please dispatch", return zero = "consumed".
**Fix**: Change `!this->handle_message(&msg)` to `this->handle_message(&msg)` and ensure handle_message returns 1 by default (not 0).

### B3. `run()` quit detection wrong [basegame.cpp:1079,1089]
**Decomp**: Quit is detected by `msg.wParam == 0x12` after PeekMessage, not by `msg.message == WM_QUIT`.
**Current code**: checks `msg.message == WM_QUIT`.
**Impact**: Minor — WM_QUIT detection still works in practice because GetMessage returns 0 for WM_QUIT.

### B4. `run()` has spurious trailing GetMessage loop [basegame.cpp:1100-1104]
**Decomp**: No such loop exists. `run()` is a single `while(true)` with inner loops.
**Current code**: After the main loop exits, enters a second `while(GetMessage)` loop.
**Impact**: May cause the app to hang on exit instead of terminating.

### B5. `set_tab_order` out-of-bounds read [Scr_sing_impl.cpp:137]
```cpp
TPanel* tab_list[6];
for (int i = 0; i < 6; ++i) tab_list[i] = (TPanel*)this->button[i];
this->set_tab_order(tab_list + 1, 6);  // reads tab_list[1..6], but [6] is OOB
```
**Fix**: Change count from 6 to 5: `this->set_tab_order(tab_list + 1, 5);`

---

## SIGNIFICANT STUBS (functional gaps that should be filled next)

### S1. `wnd_proc` is massively simplified [basegame.cpp:595-627]
**Decomp** (0x004206D0): ~300 lines handling WM_SIZE, WM_PAINT, WM_ACTIVATEAPP, WM_SETCURSOR, WM_KEYDOWN/UP, WM_SYSCOMMAND, WM_MOUSEMOVE, WM_LBUTTONDOWN, WM_TIMER, WM_COMMAND, WM_CLOSE, WM_QUERYNEWPALETTE, WM_PALETTECHANGED, and more. Also routes through `currentPanel->wnd_proc()` first.
**Current code**: Only handles WM_DESTROY, WM_ACTIVATEAPP, WM_SETCURSOR.
**Impact**: Many Windows messages silently dropped. Palette changes, keyboard input, timer events, and close/destroy lifecycle all bypass game logic. This is the **#1 priority stub to fill**.

### S2. `handle_idle` is mostly empty [basegame.cpp:1125-1132]
**Decomp** (0x00420F60): Checks `prog_ready && prog_window`, handles palette restoration timing, calls `sound_system->handle_messages(prog_window, WM_TIMER, 0, 0)`, calls `currentPanel->handle_idle()`, receives comm messages, shows comm/AI info.
**Current code**: Just calls `action_update()`.
**Impact**: Sound timer processing not happening in base class idle. `prog_ready` gate missing.

### S3. `setup_cmd_options` stubbed as `return 1` [basegame.cpp:732]
**Decomp** (0x0041D0A0): Parses command line for NOSTARTUP, SYSTEMMEMORY, MIDIMUSIC, MSYNC, MFILL, NOSOUND, 640, 800, 1024, ALLCP, RESEND1=, RESEND2=, NOMOUSE, etc.
**Impact**: No command-line options work in the base class. TRIBE_Game::setup_cmd_options partially implements NOTERRAINSOUND and QUICK1 only.

### S4. `check_prog_argument` always returns 0 [basegame.cpp:584]
**Impact**: NOSTARTUP, NODXCHECK, LOBBY and other command-line flags are never detected.

### S5. `setup_shapes` stubbed [basegame.cpp:1050-1053]
**Decomp**: Loads mouse cursor shapes from DRS resources.
**Impact**: No custom mouse cursors. Minor for menu flow.

### S6. `setup_blank_screen` stubbed [basegame.cpp:1055-1058]
**Decomp**: Creates initial blank TScreenPanel shown during loading.
**Impact**: No loading screen. Minor.

### S7. `~RGE_Base_Game` destructor incomplete [basegame.cpp:197-202]
**Decomp**: Deletes sound_system, music_system, sounds[], draw_system, draw_area, mouse_pointer, fonts[], shapes[], world, comm_handler, registry, debugLog, and restores system parameters.
**Current**: Only deletes panel_system.
**Impact**: Resource leaks on shutdown. Low priority but accumulates.

### S8. `handle_message` missing most messages [basegame.cpp:1108-1123]
**Decomp**: Handles WM_PAINT, WM_ACTIVATE, WM_KEYDOWN, WM_MOUSEMOVE, WM_CLOSE, WM_TIMER, WM_COMMAND, and more.
**Current**: Only handles WM_PAINT, WM_ACTIVATE, WM_KEYDOWN, WM_MOUSEMOVE, WM_CLOSE.
**Impact**: WM_TIMER (critical for game updates) not routed.

### S9. Campaign button shows MessageBox [Scr_sing_impl.cpp:240]
The Campaign button (button[1]) shows a MessageBox instead of navigating to the campaign screen.

### S10. Non-original screen management system [tribegam.cpp:20-170]
`gCurrentScreen`, `gPendingScreen`, `gRetiredScreens[]`, `tribe_apply_screen_switch`, etc. are custom shims not in the original. The original uses `TPanelSystem::setCurrentPanel` and `TPanelSystem::destroyPanel` directly.
**Impact**: Works but diverges from original flow. Should be replaced with proper TPanelSystem lifecycle once panel teardown is fully implemented.

### S11. `start_video` completely stubbed [tribegam.cpp:676-685]
Skips all AVI playback, jumps straight to menu or game screen.

### S12. `start_menu` missing menu music [tribegam.cpp:670]
TODO comment about playing open.mid / open.wav / CD track 2 but doesn't actually do it.

---

## MINOR ISSUES / STYLE

### M1. Double `setup_music_system` call [basegame.cpp:352 + 1234]
`setup()` calls `setup_music_system()` at line 352, and `setup_sound_system()` calls it again at line 1234. Both paths end up calling it. Harmless because `TRIBE_Game::setup_music_system()` is stubbed as `return 1`, but should be cleaned up to match decomp flow.

### M2. Debug logging in production paths
`setup_sound_system` and `setup_sounds` have CUSTOM_DEBUG_LOG calls outside of CUSTOM_DEBUG_BEGIN/END blocks. Should be wrapped.

### M3. `SystemParametersInfoA` calls look swapped [basegame.cpp:380-387]
The decomp saves screen saver / power settings and disables them. The field names `screen_saver_enabled` and `low_power_enabled` may not match what SPI_GETMOUSE and SPI_GETSCREENSAVEACTIVE actually return. Needs ASM audit for correct SPI_ constants and struct offsets.

---

## COMPLETED FIXES

- [x] **B1-B4**: `run()` rewritten to match decomp — uses `prog_mode`/`prog_active`, correct handle_message return convention, correct quit detection, no spurious trailing loop
- [x] **B5**: `set_tab_order` count fixed from 6 to 5 in Scr_sing_impl.cpp
- [x] **M2**: Debug logging wrapped in CUSTOM_DEBUG_BEGIN/END blocks
- [x] **S1**: `wnd_proc` fully rewritten from decomp — handles WM_SIZE, WM_PAINT, WM_CLOSE, WM_ACTIVATEAPP, WM_SETCURSOR, WM_KEYDOWN, WM_SYSKEYDOWN, WM_SYSKEYUP, WM_COMMAND, WM_SYSCOMMAND, WM_TIMER, WM_MOUSEMOVE, WM_EXITMENULOOP, WM_POWERBROADCAST, WM_QUERYNEWPALETTE, WM_PALETTECHANGED, MM_MCINOTIFY, WM_USER. Routes through currentPanel->wnd_proc first.
- [x] **S2**: `handle_idle` rewritten — prog_ready gate, palette restoration timing, sound system timer processing, current panel idle routing, comm message receiving
- [x] **S3+S4**: `setup_cmd_options` implemented with ~20 command-line options. `check_prog_argument` implemented with uppercase strstr matching.
- [x] **S7**: Destructor fully implemented — cleans up all subsystems (world, draw_system, sound/music, fonts, shapes, mouse pointer, comm handler, registry, debug log, palette, mutex, window, string table)
- [x] **S8**: `handle_message` fixed to return 1 per decomp (base class doesn't route, all routing in wnd_proc)

## REMAINING ITEMS (future work)

1. **S9**: Campaign button shows MessageBox instead of real campaign screen
2. **S10**: Replace custom screen management (`gCurrentScreen`/`gPendingScreen`) with proper TPanelSystem lifecycle
3. **S11**: `start_video` completely stubbed (no AVI playback)
4. **S12**: Wire up menu music in `start_menu`
5. **S5/S6**: `setup_shapes` and `setup_blank_screen` still stubbed (minor)
