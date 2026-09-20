# Build, play, and compare

Run these commands from the repository root.

```bat
game.cmd setup
game.cmd build
game.cmd rebuilt
game.cmd original
```

- `setup` installs pinned harness dependencies under `build/`. It checks the graphics download hashes.
- `build` compiles the current game and prepares a new test folder. It does not launch the game.
- `rebuilt` prepares and launches the selected successful build.
- `original` prepares and launches the repository beta EXE with the same graphics profile.

Both launch commands print the test folder and its `Launch.cmd` path.
Each preparation creates a fresh folder. Use that folder's `Launch.cmd` to continue with its local saves and settings.
Interactive launches still use the original single-instance mutex. Close one interactive game before starting another.
Captured runs use private mutex names and can run separately.
Use a prepared folder's `Launch.cmd` to reopen that folder and retain its private saves.

Use `game.cmd --help` and command-specific `--help` for the command reference.

## Files and assets

There are two inputs, not two interchangeable installations:

- `runtime/` supplies the complete installed assets.
- `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe` supplies the original beta program.

The complete `runtime/` currently also contains that beta EXE. Its hash must match the pinned original.
The smaller beta directory does not supply a complete playable installation.
Neither input directory changes during preparation.

Prepared games live under `build/runtime/<target>-<timestamp>/`.
Build objects, linker maps, and build reports stay under `build/executable/`.
`build/game/rebuilt.json` identifies the selected successful build.
The tool verifies its EXE against its build report before using it.

Large DRS, WAV, and AVI assets use file hard links when possible.
This shares about 191 MiB per test folder on the current machine.
Other files use private copies, including EXEs, DLLs, profiles, scenarios, and saves.
Unsupported filesystems fall back to copying.
No directory junctions, filesystem driver, or execution-time path overlay is required.

**Hard links are not copy-on-write. Never edit shared assets in place.**
Use the override command to replace a link safely:

```bat
game.cmd override build/runtime/<run> data2/graphics.drs C:/patches/graphics.drs
```

The command creates a private file and replaces the directory entry.
It does not write through the old link. The runtime manifest records the override.
Use `--assets copy` when external tools might edit assets in place.

Use a specific successful build without rebuilding:

```bat
game.cmd rebuilt --exe build/executable/<run>/empiresx.exe
```

Add `--prepare-only` to prepare without launching.

## Graphics

The default uses pinned cnc-ddraw 7.1.0.0 with the profile in `config/harness/ddraw.ini`.
The game uses its fullscreen drawing path. The wrapper supplies a normal window.
Do not add the game's `WINDOW` option to this profile.
That selects the original eight-bit-desktop requirement, not the wrapper's windowed mode.

The test profile selects GDI presentation, disables resizing and saved wrapper settings, and disables its game-tick limiter.
It does not change game drawing functions or replace the drawing engine.
The launcher clears the old process-local compatibility setting for this profile.

For comparison with the earlier environment:

```bat
game.cmd original --graphics native
game.cmd rebuilt --graphics native
```

Native mode uses `DWM8And16BitMitigation` and does not add cnc-ddraw.
Initial surface capture supports only the pinned cnc-ddraw profile.

## Automated menu capture

```bat
game.cmd capture original
game.cmd capture rebuilt
game.cmd capture original --fixture config/harness/menu-random-map.json --clock calls
game.cmd capture rebuilt --fixture config/harness/menu-random-map.json --clock calls
game.cmd capture original --fixture config/harness/menu-random-map.json --clock calls --resolution 800x600
```

Capture starts a fresh process, collects evidence, and stops only that process.
**Capture and repeat use private Windows desktops by default. No game window appears on your desktop.**
The harness never switches to those desktops. It checks the game's desktop before resuming game code.
The game still creates its normal windows and executes drawing, but Windows keeps them on the private desktop.
Add `--visible` only when you explicitly want an automated run on your interactive desktop.

It uses `NOSTARTUP GAMECD NOSOUND NOMUSIC`.
The default deadline is eight seconds. Use `--seconds` to change it.

The initial fixtures cover the main menu, Single Player menu, Random Map setup, and Game Settings.
They post keyboard events after a specified number of Paint calls, at the game's outer idle boundary.
The harness records consumption of those events through the game's window procedure.
It checks the destination panel name before reporting success.
These are small menu scripts, not recordings of arbitrary human input.

`--clock real` preserves the original debug-clock function and is the capture default.
`--clock calls` replaces that function with a counter starting at 1,000.
Each call advances the counter by one millisecond.
The harness records RNG calls without replacing random results or internal reseeds.

The calls profile controls one timer boundary. It does not control every Windows clock, timer, thread, or input source.
Do not describe it as full-process determinism or use it as proof of gameplay equivalence.

Captured runs redirect the game's registry-key creation to private, per-run copies under HKCU.
Automated runs use `config/harness/automated-registry.json` instead of the current 32-bit game registry values.
Feature-lab workers use the same profile.
The selected resolution replaces its `Screen Size` value in the private copy.
The harness records those input values and deletes its private keys after stopping the game.
Fixtures can provide a complete `registry_inputs` object to select another private profile.
Interactive launch commands retain normal registry behavior; they do not load the instrumentation component.

The hidden worker uses a Windows job object. Closing that job stops its worker and game descendants.
Timeout cleanup also removes the private game registry copies.
`hidden-worker.log` and its JSON report record the worker result and desktop names.
Repeat commands write their hidden-worker logs directly under `build/runtime/`.

Avoid keyboard and mouse activity in game windows during explicitly visible automated tests.
The harness checks the scripted key sequence, but it does not yet virtualize all polled input or focus behavior.

## Capture artifacts

Each capture writes a `capture/` directory within its runtime:

- `report.json`: build, graphics, registry, hook, input, RNG, and module evidence.
- `instrumentation.js`: the actual injected script and resolved addresses.
- `capture-tool.py`: the controller source used by that run.
- `frame-*.bin`: raw surface rows, followed by 256 four-byte palette entries.
- `frame-*.png`: a viewable, indexed image without row padding.

Capture observes the offscreen draw surface at `TDrawSystem::Paint` entry.
It reads the memory-backed surface through `GetSurfaceDesc` and the palette through `GetEntries`.
It does not use desktop screenshots or count host display frames.
Legacy captures allow 120 Paint captures. The UI group allows 480.
Exceeding the limit fails the run rather than comparing a stale final frame.

The harness verifies the EXE, map, graphics DLL, configuration, and hook entry bytes.
It checks the loaded graphics DLL and the three redirected registry handles.
It also checks shared source-asset hashes after capture.
Hardware exceptions, unexpected software exceptions, and failed fixture execution produce failure results.
First-chance MSVC exceptions remain in the event log. Windows still handles them normally; the harness does not swallow them.
Private-desktop runs encounter caught MSVC exceptions from system runtimes during menu setup.
An unhandled exception or early process exit still fails the run.

## Compare and repeat

```bat
game.cmd compare build/runtime/<original>/capture/report.json build/runtime/<rebuilt>/capture/report.json --output build/runtime/<comparison>
game.cmd repeat original --count 20 --fixture config/harness/menu-random-map.json
game.cmd repeat rebuilt --count 5 --fixture config/harness/menu-random-map.json
```

Repeat uses the calls clock by default. It stops on the first failed capture or comparison.
It compares each final surface against the first run in that batch.

Comparison writes pixel counts, a difference image, and a side-by-side image.
It compares active pixel indices and palette entries separately.
With the calls clock, it also compares the complete recorded RNG trace, within its stated size limit.
Different assets, fixtures, registry inputs, graphics profiles, or instrumentation versions invalidate a comparison.

**A passing result covers the final captured menu surface and the declared RNG observations only.**
It does not prove equal intermediate frames, full RAM, simulation, audio, multiplayer, or native presentation.
The destination screen can be correct even when an earlier drawing pass differs.

## Game UI main menu tests

```bat
game.cmd test-captures --list
game.cmd test-captures
game.cmd test-captures --case "settings-*"
game.cmd test-captures --case campaign-name-mouse --original-runs 2
game.cmd test-captures --case main-buttons --resolution 800x600
```

Cases run one at a time. Each hidden UI case uses its own desktop, process job,
registry namespace, and output folder. `--jobs` set to one is allowed. Values above one
fail before a game starts because parallel runs showed drift. Visible mode stays
serial because all visible cases share the interactive desktop.

The permanent group lives in `config/harness/game-ui-main-menu.json`.
It defines 41 cases. These include three safety tests that must stop before game or map execution.
The default run uses two fresh original processes and one rebuilt process per case.
Each process has private files, registry keys, and a private desktop.
The UI profile rejects game socket creation with `WSAEACCES` before Windows creates a socket.
This prevents DirectPlay listener prompts without changing firewall rules or enabling network access.
Frida's own transport remains available. The socket block is not a general security sandbox.
Interactive launches and the older capture profile retain their normal network behavior.
The suite compares the original runs before accepting cross-build results.
A failed rebuilt capture does not prevent comparison between completed original captures.

The group covers menu navigation, dialogs, settings, player controls, credits, campaign metadata, and saved-game lists.
Interactions include hover, button press, drag cancellation, dropdown selection, scrollbar dragging, checkboxes, and native text editing.
Campaign saving writes a private package. It does not start a scenario or create a game map.

The UI profile posts Windows messages at idle boundaries and records their dispatch.
It does not call control action methods directly.
It controls key-down state and game cursor queries through the process's input API imports.
It also sets the private thread's keyboard state for native edit controls.
The fixture does not model key-toggle bits or the asynchronous key API's recent-press bit.
Mouse coordinates use a canonical 640 by 480 game client.
The harness scales those coordinates to the selected game resolution.
Supported resolutions are 640x480, 800x600, 1024x768, and 1280x1024.
Set a resolution with `--resolution WIDTHxHEIGHT` or the fixture's `resolution` field.
The command-line value overrides the fixture value for that run.
Mouse messages target captured windows or the child control under that position.
An unhandled native modal window blocks scripted input rather than allowing clicks through it.

Each named checkpoint compares:

- Game-surface pixel indices and palette entries.
- Composite RGB images, including visible native edit controls.
- Panel names, control bounds, and selected control state.
- The observed RNG trace up to that checkpoint.

Native edit controls draw into memory through `WM_PRINT`. The harness never captures the desktop.
Native system cursor shapes and caret blink timing are outside this image comparison.
Named checkpoints do not cover every intermediate drawing pass.

The suite writes `build/runtime/ui-main-menu-<timestamp>/report.json` and a frozen copy of its definition.
Each comparison has numbered checkpoint folders with these files:

- `composite-side-by-side.png`: original reference on the left; compared run on the right.
- `composite-difference.png`: RGB differences, including native controls.
- `controls.json`: both control snapshots and checkpoint metadata.
- `report.json`: raw surface comparison results.

Scripted replay also accepts a per-run resolution:

```bat
game.cmd replay --fixture config/harness/replay-random-smoke.json --resolution 800x600
```

The replay stores the selected resolution in its frozen scenario.
Runs with different resolutions are not comparable.

With two original runs, `comparison-00` checks original repeatability.
`comparison-01` compares the first original with the rebuilt game.
The suite returns failure for capture errors, unstable original output, or rebuilt differences.
Do not treat a failed capture as a pixel comparison result.

The guards stop new-game start, saved-game loading, scenario launch, and map-editor entry.
Three cases exercise start, saved-game load, and map-editor guards on both programs.
The scenario guard exists but does not yet have a dedicated qualification case.
These guards bound this suite. They are not a general sandbox for arbitrary scripts.

The offline lobby case covers game-title editing and cancellation without creating a session.
Refresh did not return to an idle checkpoint under the offline profile. It remains outside the qualified cases.
Connected multiplayer sessions and provider dialogs still need separate qualification.
Gameplay, audio, cinematics, and full-process state remain outside this group.

## Current limits and next work

The separate [gameplay replay mode](behavior_replay.md) compares selected typed state and complete debug RNG traces.
It does not remove gameplay guards from the menu test group.

- No full input recorder or general replay format exists yet. The UI group uses bounded input scripts.
- Private desktops hide windows without skipping rendering. A renderer with no Windows desktop dependency does not exist yet.
- No process restore exists yet. Parallel process batches stay disabled while runtime drift is under review.

## Current validation

All 41 UI-group cases passed after three source repairs, with two originals and one rebuilt run per case.
All 38 normal UI cases passed original repeat and cross-build comparisons. All three safety cases stopped at their expected boundaries.
The regression suite passed 518 tests and 31 subtests.
See `decomp_notes/game_ui_main_menu_tests_20260914.md` for batch paths, image pairs, failures, and limits.

Earlier final-frame qualification:

Twenty original and twenty rebuilt Game Settings runs passed on two private desktops, with both batches running together.
Their final pixel indices, palettes, RGB images, and recorded RNG traces match.
The full test suite passed 491 tests and 31 subtests.
See `decomp_notes/runtime_harness_checkpoint_20260914.md` for evidence paths and limits.
- Function entry hooks and exception context work. A general debugger control interface remains future work.
- The four-byte `currentPanel` getter could not accept a normal Frida hook. The harness reads its reviewed data instead.
- Interior message-loop hooks were rejected after a failed experiment. Input now uses the actual TRIBE idle override.

Keep the existing native launcher as a control while extending graphics and input tests.
The group caught dialog positioning, list switch-table, and state-color parser defects. Their proved source repairs now pass this group.

See `decomp_notes/runtime_harness_investigation.md` for the wider design.
