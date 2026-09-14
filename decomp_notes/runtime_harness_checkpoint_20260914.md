# Runtime harness checkpoint, 2026-09-14

## Scope

This pass adds build, launch, asset sharing, menu replay, and direct surface comparison.
It does not change game source, the original EXE, or function registry statuses.
The earlier audit-repair edits remain separate and uncommitted.

## Build and runtime arrangement

`game.cmd` is the main entry point. See `docs/runtime_harness.md` for commands.
`runtime/` supplies the complete assets. The repository beta supplies the original EXE.
The beta EXE in both input directories retains SHA256:
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

`game.cmd build` compiled all 226 C/C++ modules and the active assembly source.
It linked with zero unresolved symbols and zero link errors.
Build evidence:
`build/executable/user/20260914T120559776841Z/20260914T120559963391Z/report.json`.

Prepared folders share DRS, WAV, and AVI assets through file hard links.
The current shared size is 200,649,592 bytes per folder.
Profiles, saves, scenarios, DLLs, and EXEs remain private copies.
An explicit override command replaces a link with a private file before changing an asset.
No filesystem overlay driver or directory junction is required.

## Graphics and capture

The pinned cnc-ddraw 7.1.0.0 profile uses GDI presentation and memory-backed eight-bit surfaces.
Its archive and DLL hashes reside in `config/harness/dependencies.json`.
The profile keeps the game in its fullscreen code path while the adapter manages presentation.

Capture reads the game's draw surface and active palette at `TDrawSystem::Paint` entry.
It stores the raw rows and palette, then encodes a viewable PNG.
The comparison uses active pixel indices and palette entries, not desktop pixels.
Padding remains in the raw artifact but does not enter the active-pixel hash.

One separate desktop diagnostic was performed during the visible launcher test.
It was not part of comparison. Its images were removed after the user rejected desktop capture.
The automated capture tools do not use desktop screenshots.

## Hidden execution

Capture and repeat now default to a private Windows desktop.
The controller creates a worker with `STARTUPINFO.lpDesktop`; it never calls `SwitchDesktop`.
Frida then starts the game from that worker, so the game inherits the private desktop.
A separate probe checks the game process desktop before resuming game code.
The game still renders normally. Its windows do not appear on the user's input desktop.

This avoids changing window visibility, focus handlers, or game drawing code just to hide the window.
It is not a renderer without a Windows desktop dependency.

A kill-on-close job owns the worker and its descendants.
Timeout tests confirm that it also stops a worker's child process.
The parent removes its private registry copies after job cleanup.
Captured games also use private instance-mutex names.
Interactive `original` and `rebuilt` commands remain ordinary visible launches.

## Controls and evidence checks

- Verify the original or rebuilt image hash before instrumentation.
- Verify the rebuilt map against its successful build report.
- Resolve hooks through original identities and rebuilt symbols.
- Check entry bytes before attaching hooks.
- Verify the loaded graphics DLL and profile.
- Copy the game's two registry value sets into private keys and record their input values.
- Verify the three redirected registry handles and one private instance mutex.
- Schedule menu keys at `TRIBE_Game::handle_idle`, after drawing and the previous message handler return.
- Record key consumption through the game's window procedure.
- Require the fixture's destination panel.
- Compare recorded RNG operations without replacing their results.
- Verify shared source-asset hashes after each capture.

The optional calls clock replaces only `debug_timeGetTime`.
It starts at 1,000 and advances one millisecond per call.
This is a declared menu-test environment, not full-process determinism.
Other clocks, arbitrary human input, and full simulation state remain outside its coverage.

## Reviewed observation points

| Original VA | Purpose |
| --- | --- |
| `00443520` | `TDrawSystem::Paint`: capture before presentation |
| `00529610` | Actual `TRIBE_Game::handle_idle` override: schedule input |
| `0041CFD0` | Outer run owner: check the idle caller |
| `0041E7A0` | Game window procedure: record key consumption |
| `004231E0` | Debug clock |
| `004230A0` | RNG results |
| `00423140` | RNG seeds |
| `0062E870` | `panel_system`: observe the current panel |

Original `TPanel::wnd_proc` instructions use `0062E870` as the panel-system receiver.
PDB public evidence also identifies `panel_system` at section four, offset `000AF870`.
The rebuilt map identifies its separately linked address.

## Rejected experiments

All listed run directories remain under `build/runtime/`.

- Posting during Paint reached the first submenu but lost the next action during a transition.
- Intercepting system message functions did not reliably identify the outer game loop through the graphics adapter.
- `original-20260914T122149738927Z` could not attach to the four-byte `currentPanel` getter.
- `original-20260914T122445243084Z` did not schedule input through the inactive message-loop path.
- `original-20260914T122556318372Z` exited early during an interior call-site hook experiment. That hook was rejected.
- `original-20260914T122748782379Z` hooked the base idle implementation but filtered for its wrong direct caller.
- The actual TRIBE idle override then reached Random Map setup reliably.

The first hidden run is `original-20260914T124732072319Z`.
It reached the expected screen and captured equal pixels, but reported twelve first-chance software exceptions.
The exception policy incorrectly treated every first-chance exception as a crash.
Later probes identified MSVC exception code `E06D7363`, raised through system CRTs.
The policy now records those throws and lets Windows handle them normally.
Hardware faults, unexpected exceptions, early exit, and incomplete fixture execution still fail.
This is not exception suppression inside the game.

Later runs retain their injected script and controller source beside the raw captures.
The earliest exploratory runs retain reports and captures but not every intermediate script body.

## Validation completed before hidden batching

The visible-control sequence reached Random Map setup twenty times in the original and five times in the rebuilt game.
Every final pixel index, palette entry, and recorded RNG operation matched within each batch.
The original and rebuilt final observations also matched each other.

- `build/runtime/repeat-original-20260914T123453033091Z/report.json`
- `build/runtime/repeat-rebuilt-20260914T123644094957Z/report.json`
- `build/runtime/compare-qualified-menu-20260914/report.json`

The first successful hidden original/rebuilt comparison also reports zero differing pixels or palette entries and equal RNG traces:
`build/runtime/compare-hidden-menu-20260914/report.json`.

Manual hash comparison of that hidden original capture with the earlier visible original capture finds equal final pixels and palette.
Their complete recorded RNG traces also agree.
Their exception instrumentation differs, so this is a bounded output comparison, not equal full execution.

The hidden Game Settings comparison also reports exact final observations:
`build/runtime/compare-hidden-settings-20260914/report.json`.
It captures 25 Paint boundaries and reaches `Game Settings Screen` in both versions.

The full test suite passed 484 tests and 31 subtests before the hidden-run additions.
The hidden-worker, comparison, and asset tests then passed all 26 focused tests.

## Final hidden qualification

Two batches ran at the same time on separate private desktops:

- Original: 20 requested, 20 completed, all comparisons passed.
- Rebuilt: 20 requested, 20 completed, all comparisons passed.
- Each run reached Game Settings through five consumed key actions and captured 25 Paint boundaries.
- Every run checked three private registry handles and one private instance mutex.
- The cross-build comparison found zero differing pixel indices, palette entries, or RGB pixels.
- Recorded RNG traces matched within both batches and across the two EXEs.
- Both worker reports record `Default` as the input desktop before and after execution.
- No game process or private registry copy remained after completion.

Evidence:

- `build/runtime/repeat-original-20260914T125739135000Z/report.json`
- `build/runtime/repeat-rebuilt-20260914T125743908847Z/report.json`
- `build/runtime/compare-hidden-qualified-settings-20260914/report.json`
- `build/runtime/hidden-repeat-20260914T125738853232Z.json`
- `build/runtime/hidden-repeat-20260914T125743650150Z.json`

The rebuilt EXE used by these batches has SHA256:
`573d6ffc9b2d67c25b3a3b085f06ae21d5df442c0e21af41ec1d53d98447e9e3`.

The final Game Settings active-pixel hash is:
`ada8f3fc476af0f378368a634d0d11fe8be014679ecd3f4e592624214cb36d5b`.
The final RGB hash is:
`d0fd0ec85ac30aa1dee3720519e2788e5a2f6cceddac56507c45788d62c89d71`.

The final full suite passed 491 tests and 31 subtests, including the `capture --prepare-only` guard.
Negative tests detect changed indices, palettes, seeds, fixtures, assets, and executable hashes.
`git diff --check` also passed.

Windows still loads `apphelp.dll` and `AcLayers.DLL`, as the module records show.
Clearing inherited `__COMPAT_LAYER` does not remove Windows' built-in application compatibility behavior.
Only the explicit graphics adapter and its configuration are pinned by this pilot.

## Limits

The user's reported visual defect has not been reproduced in these tested menus under the new graphics profile.
Do not infer that every menu, native presentation, or gameplay behavior now matches.

Current comparison covers the final captured surface and its palette, plus RNG observations with the calls clock.
It does not compare the entire intermediate-frame sequence or all process RAM.
No full human-input recorder, general debugger interface, save-state restoration, audio comparison, or multiplayer replay exists yet.
