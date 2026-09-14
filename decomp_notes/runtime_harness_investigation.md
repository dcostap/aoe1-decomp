# Runtime harness investigation

Status: design proposal, not an approved implementation plan.

This investigation inspected local source, original instructions, earlier runtime evidence, and external tool documentation.
It did not install a graphics wrapper, instrument a live game, or change game source.
External tools still need tests with this exact beta and the rebuilt EXE.

## Goal

Run the original and rebuilt games under the same controlled environment.
Record external inputs, repeat executions, compare outputs, and locate the first meaningful difference.
Support visible play, automated tests, and focused debugging through the same control interface.

Visual defects establish that the complete game needs runtime validation.
They do not establish that every nonmatching function is behaviorally wrong.
Exact functions can also fail because of wrong initial data, layouts, callers, or linked references.
The earlier version-initializer fault provides a concrete example in `map_startup_crash.md`.

Keep byte matching, runtime comparison, and behavior approval as separate results.

## Local findings

### Existing controls

`src/basegame.cpp:1388-1505` parses `LOGRANDOM`, `FIXEDUPDATE=`, `AISPEED=`, `RANDOMGAME=`, and `RANDOMMAP=`.
These are useful test candidates, not proof of complete determinism.
The parser searches for `=` for value options. Do not supply those options without values.

Original `debug_rand` at `004230A0` calls CRT code at `0054CC70`.
Original `debug_srand` at `00423140` calls CRT code at `0054CC60`.
Both wrappers provide useful observation points without replacing the RNG algorithm.

Original `debug_timeGetTime` at `004231E0` has two modes.
Its debug mode advances time after a configured number of calls.
Otherwise, it jumps through the imported timer slot.
Its debug mode requires both control flags. It is not a process-wide virtual clock.

Original `RGE_Game_World::update` at `00542ED0` supplies a useful simulation boundary.
It obtains a cycle from `DoCycle`, can select a fixed cycle, and seeds from the world's saved RNG state.
It dispatches commands before scenario and player updates.
It records a new RNG state after the update.
The original instructions confirm these operations; see the extracted functions under `build/asm/`.

The source also uses time budgets inside AI work.
Examples occur in `src/taitacmd.cpp:3146`, `3182`, and `3333`.
Freezing all clocks during an update can change work limits or prevent loops from ending.
An extra timer call can also change the built-in debug clock's progression.

`src/Command.cpp:48` consumes queued commands.
`src/Command.cpp:814` submits orders, including duplicate-order handling.
`src/com_hand.cpp:551` accepts new command buffers.
These are command-recording candidates. Their exact replay boundary needs a short trace.
The source search did not identify an existing complete recorded-game replay facility.

### Input and process isolation

`src/basegame.cpp:1000` switches between message processing and idle work.
Inactive or paused states follow a different path.
Other source paths poll `GetCursorPos`, `GetKeyState`, and `GetAsyncKeyState`.
Sending mouse messages alone cannot reproduce all input observations.

`src/basegame.cpp:2414` creates a named mutex to reject another game instance.
Copies in different directories alone do not solve concurrent execution.
Registry values, save files, logs, focus, audio devices, and network endpoints also need isolation or fixed settings.

`src/scenario.cpp:37` uses wall-clock time for a checksum.
Startup also seeds from time. Determinism must start before world creation.

### Graphics

Original `TDrawSystem::Init` at `00442A90` rejects its legacy WING draw type.
Its windowed branch rejects any desktop depth other than eight bits.
Earlier debugger runs confirmed this failure in both EXEs on the current host.
See `executable_build_evidence/drawing_binary/startup_comparison.md`.

The current working launcher applies process-local `DWM8And16BitMitigation`.
Do not remove that baseline until a replacement passes original-game tests.

`src/drawarea.cpp:596` presents through `TDrawSystem::Paint` and a primary-surface `Blt`.
Capture cannot depend only on `Flip`, because this path uses `Blt`.
Drawing also uses locked surface memory and surface device contexts.
Text uses GDI operations, including `TextOutA` in `src/Pnl_txt.cpp`.
Any graphics adapter must preserve both paths and their palette behavior.

### Existing infrastructure

`tools/prepare_runtime.py` copies complete runtime files, verifies hashes, and writes a launcher and manifest.
Reuse it for initial isolated runs.
Existing runtime notes preserve x86 CDB sessions, exception dumps, and map-based function lookup.

`docs/executable_build.md` records the current debug-information limitation.
VC5 debug packing fails; normal builds provide linker maps rather than full source-level debugging.
Use original PDB evidence and rebuilt maps for function identities.
Do not require instruction-for-instruction alignment between different function bodies.

## External approaches

### cnc-ddraw: recommended graphics pilot

The project lists Windows 11, Age of Empires, and Rise of Rome support.
That does not establish support for this particular beta.
Its documented approach keeps the game in fullscreen mode while the wrapper provides a window.
This avoids the game's native windowed-depth branch without deleting that branch.

The inspected implementation contains memory-backed surfaces and GDI device-context support.
Its screenshot implementation reads surface buffers rather than desktop screenshots.
These are useful starting points for indexed-pixel and palette capture.

It is not just a presentation adapter.
It has game profiles, input hooks, timing controls, affinity settings, and a render thread.
Pin the version and record the complete effective configuration.
Keep the same executable basename and profile for both game copies.
Audit overlapping hooks before combining it with instrumentation.

No headless renderer appeared among the documented renderer choices in the inspected configuration source.
A no-presentation mode would require further work and validation.
Do not claim that hiding its window already supplies deterministic headless execution.

Sources:
- https://github.com/FunkyFr3sh/cnc-ddraw
- https://github.com/FunkyFr3sh/cnc-ddraw/blob/master/src/ddsurface.c
- https://github.com/FunkyFr3sh/cnc-ddraw/blob/master/src/config.c
- https://github.com/FunkyFr3sh/cnc-ddraw/blob/master/src/screenshot.c

### Frida: recommended instrumentation pilot

Frida documents Windows and IA-32 support, memory access, interception, and native calling conventions.
Use it first for a few verified boundaries and API observations.
Use native callbacks and batched records if hot hooks become expensive.
Its documentation warns against frequent individual messages and unnecessary callbacks.
Stalker can trace selected execution, but full-time instruction tracing should not be the default.

Frida does not supply game determinism or cross-build replay automatically.
Validate early injection, hook bytes, calling conventions, register preservation, and interaction with the graphics wrapper.
Check floating-point state and Windows error state as part of hook transparency.

Sources:
- https://frida.re/docs/javascript-api/
- https://frida.re/docs/stalker/

### Other options

WinDbg/CDB is suitable for stops, stepping, watchpoints, and dumps.
Time Travel Debugging can support reverse investigation of one recorded execution.
It does not replay an original instruction trace against changed code.
Microsoft documents substantial recording overhead and potentially large traces.
Use it for a reduced failure, not every parallel test.

libTAS has useful design lessons, including time and input control.
Its README states that Wine support is limited and not actively developed.
Its documented allocation-zeroing approach can conceal uninitialized-memory defects in a reconstruction.
Do not adopt those semantics without a separate diagnostic profile.

Hourglass Resurrection targets native Windows tool-assisted replay.
Its README describes unfinished recovery and compatibility work.
Treat it as a reference or bounded experiment, not a proven Windows 11 foundation.

PANDA provides whole-system recording and replay through QEMU.
It is a fallback for machine-level investigation and stronger environment isolation.
It adds guest setup, graphics support, and execution cost.
A machine recording also does not automatically replay against a different EXE.

Sources:
- https://learn.microsoft.com/en-us/windows-hardware/drivers/debuggercmds/time-travel-debugging-overview
- https://learn.microsoft.com/en-us/windows-hardware/drivers/debuggercmds/time-travel-debugging-ttd-exe-command-line-util
- https://github.com/clementgallet/libTAS/blob/master/README.md
- https://clementgallet.github.io/libTAS/guides/how/
- https://github.com/Hourglass-Resurrection/Hourglass-Resurrection
- https://panda.re/

## Proposed smallest architecture

Use one controller, one process-side instrumentation component, and one shared graphics adapter.
Give every run a private output directory and a versioned manifest.
Expose a CLI with structured responses. Do not require a service, browser UI, or distributed scheduler.

Initial operations:

- Start and stop a selected build.
- Wait for a named boundary with a timeout.
- Advance one simulation update or one completed drawing pass.
- Deliver a scheduled external input event.
- Read a reviewed state region or capture a surface.
- Set a function breakpoint or data watchpoint.
- Capture registers, stacks, exceptions, and process memory.
- Compare two completed runs.

Keep simulation updates and drawing passes as separate counters.
One presentation call need not mean one complete frame; partial redraws and palette updates also matter.
Take snapshots at verified safe boundaries, with stable buffer and palette ownership.
Do not invoke arbitrary game methods from the controller's worker thread.

Use original VA as the stable function identity.
Resolve each rebuilt address through its exact build's map and registry symbol.
Check image hashes and expected bytes before installing hooks.
Record every hook and intervention in the run manifest.
Unknown addresses or unsupported behavior must produce an explicit failure, not guessed success.

Keep production game source and original files unchanged during the first pilot.
Apply harness changes to isolated runtime copies or process memory.
Use the same environment controls on both games. Never inject expected game results into the rebuilt game.

## Determinism contract

Start with offline single-player play, fixed assets, one resolution, one locale, and explicit settings.
Initially disable music and sound through the same game options in both runs.
That profile does not validate audio. Add audio events and sample capture in a later profile.

Control external seed inputs, wall clocks, timer delivery, message order, polled input, and focus.
Discover remaining sources through traces rather than assuming one seed makes the process deterministic.
Record thread creation and waits. No direct game thread-creation calls appeared in the focused source search.
That does not exclude threads created by Windows, multimedia libraries, or wrappers.

Preserve internal RNG calls and reseeds, including map and per-update reseeds.
Compare their sequence, arguments, results, and saved state.
Do not replace every seed with one constant or feed original random results into the rebuilt game.
Both approaches can conceal a missing or extra RNG call.

Test the built-in fixed-update controls before replacing them.
Define simulation time, UI time, and timing-budget behavior explicitly.
Keep harness timeout clocks separate from game clocks.
Do not let debugger pauses advance game time.

Treat memory-initialization controls as diagnostic variants, not silent baseline fixes.
Pin the initial floating-point environment and report unexpected changes rather than resetting it after every function.

## Replay and comparisons

Record external UI events when the game consumes them, with phase, sequence, modifiers, and virtual cursor state.
Replay them at the same logical boundary, not after a real-time sleep.
Do not blindly inject internal messages that the game will generate again.

Also record the resulting player-command stream at a reviewed queue boundary.
Use UI replay to test menus, selection, hit testing, camera movement, and command generation.
Use command replay to isolate simulation behavior from UI behavior.
Command replay does not validate the UI path it bypasses.
Do not replay the original AI's decisions as inputs when testing the rebuilt AI.

Compare several outputs:

1. External input consumption and environment API observations.
2. RNG calls and saved RNG state.
3. Ordered player commands and generated AI commands.
4. World, players, objects, map, actions, and selected UI state.
5. Indexed surface pixels, active palette, and composed image.
6. File outputs and, later, audio and network behavior.

Use raw memory dumps for investigation, not whole-process equality.
Pointers, vtables, heaps, handles, padding, and module addresses differ between builds.
Compare reviewed fields using stable object IDs and symbol identities.
Preserve raw bytes beside decoded values. Compare floating-point bits before considering any tolerance.
Record each excluded or translated field and its reason. Do not normalize unexplained differences away.
Keep collection order when it affects behavior; do not sort it merely to obtain equality.

Capture rendered surfaces before host scaling and presentation.
Compare palette indices and palette entries separately, then compose an image for inspection.
Separate active pixels from row padding while retaining full buffers for memory diagnostics.
Include GDI output, palette-only changes, partial redraws, and cursor composition in the capture design.
Avoid desktop screenshots as the authoritative pixel source.

Full process dumps do not provide restartable checkpoints by themselves.
Windows handles, device contexts, graphics resources, threads, and files contain external state.
Start with deterministic restart and replay to a target boundary.
Do not transfer original heap snapshots into the rebuilt process.
Save/load and VM snapshots can become later acceleration options after their limits are tested.

## Proposed stages and gates

### 1. Reproduce one visual defect

Choose a short menu action or a supplied scenario that shows a defect.
Run the original and rebuilt game with identical runtime files and settings.
Capture pre-presentation pixels, palette, build identities, and the reproduction steps.
First distinguish an incorrect game buffer from an incorrect presentation result.

### 2. Qualify the harness against the original

Test the original through the current launcher and through the proposed graphics wrapper.
Then repeat the original under the controlled harness before comparing different builds.
Start with the same menu sequence over repeated cold launches.
Add a short seeded match after that succeeds.
Compare the declared state and output set; unobserved state remains outside the claim.

Proposed initial target: twenty repeated runs without differences in the declared observations.
Vary host load and add a controlled pause to check that host timing does not leak into results.
Deliberately change a seed, command, and palette value in separate tests to confirm that comparison detects them.

### 3. Compare both builds

Repeat the rebuilt game against itself too.
Then compare original and rebuilt runs using the same input fixture.
Stop on the earliest observed difference.
Rerun with more detailed probes around that boundary.
Use a watchpoint or short instruction trace to find the write that caused it.
Expand the test set through menus, map creation, orders, AI, saving, loading, and graphics effects.

### 4. Add interactive recording and hidden execution

Record a short original-game session and verify repeatable replay on that same original first.
Add a no-presentation graphics mode that still executes drawing and updates surfaces.
Virtualize focus and input state; a minimized game alone is not a headless test.
Require visible and hidden modes to agree on the declared observations.

### 5. Scale measured workloads

Namespace the single-instance mutex and isolate other shared state.
Measure two instances, then eight, then larger batches.
Measure CPU, memory, GDI handles, trace size, and storage bandwidth before promising hundreds of instances.
Use lightweight hashes normally and detailed traces only for failures.
Support many test cases without requiring every case to run simultaneously.

## Decisions for discussion

Recommended first route: native Windows, a pinned cnc-ddraw pilot, Frida boundary probes, and existing CDB support.
Do not build a DirectDraw replacement or general emulator before testing that route.
Keep a VM-based approach as a fallback if wrapper or OS behavior blocks repeatability.

The next useful input is one reliably visible defect and its shortest reproduction.
The first implementation should prove stable capture and original-versus-original repeatability for that case.
Full-match recording, restartable snapshots, and hundreds of instances should follow evidence, not lead the design.
