# Original-only human recorder qualification

## Scope

This change adds human input recording, original-only replay, and game-window videos.
It does not change recovered game source or compare the rebuilt executable.
Human acceptance remains open until the user records and reviews a session.

The commands are `game.cmd record-original` and `game.cmd replay-original RECORDING`.
See `docs/human_replay.md` for the input policy and limits.

## Evidence

The final automated input source is `build/runtime/human-smoke-07/recording.json`.
It contains 22 received messages. They exercise menu clicks, camera movement, keyboard input, dragging, and right-clicking.
The keyboard input also produces a recorded character message.
F10 stops the source recording without reaching the game as a gameplay key.

Three fresh original replays completed:

`build/runtime/human-replay-07-repeat/report.json`

All three received the same 22 message parameters and owned-window routes.
Their corresponding idle-return counts, world-update counts, and panel names agree.
Their controlled clock values do not always agree. The largest difference from the first replay is 31 milliseconds.
The report correctly retains `input_repeatable: false`, which includes exact clock equality.
Equal game boundaries do not prove equal simulation state or equal pixels.

The first replay video is:

`build/runtime/original-20260914T191739977526Z/capture/video.mp4`

The source video is:

`build/runtime/original-20260914T191628592259Z/capture/video.mp4`

A sampled replay overview is `build/runtime/human-replay-07-repeat/video-overview.png`.
Its sampled images show menu navigation, the match, keyboard selection, and a selection rectangle.
This review is not a frame-by-frame video comparison.

## Development findings

- The earlier debug-clock-call policy could stop advancing in static menus.
  The new profile advances at main-loop idle returns too. Existing replay profiles keep their earlier policy.
- The encoder requires a zero-based video timeline.
  Video now starts at the first captured Paint boundary. The report retains its offset against input time.
- Posting one input per later idle introduced avoidable delivery gaps.
  Replay now posts messages in groups using recorded idle-return boundaries.
- Main-loop idle counts alone compress drag input incorrectly.
  Mouse handling runs nested idle calls. Recording and replay count those returns too.
- Calling Windows dispatch synchronously from an instrumentation callback did not produce the expected receipts.
  That experiment failed closed. The retained implementation uses the normal game message loop.
- Visible recording needs an external worker deadline and a process job.
  The existing isolated worker launcher now supports an explicit visible mode without switching desktops.
- FFmpeg uses no console window, so it cannot take focus from the recorded game.

Rejected attempts remain under `build/runtime/human-smoke-01` through `human-smoke-06` and their referenced runtimes.
Their reports and videos remain available. No expected outputs were replaced to obtain a pass.

## Validation

The repository test run passed 648 tests and 31 subtests during development.
The final focused run passed 150 tests after the delivery, validation, and encoder changes.
Both JavaScript syntax checks and `git diff --check` passed.
The visible worker launch test passed without switching desktops:
`build/human-visible-worker-check-01.json`.

Static review found validation gaps, missing visible deadlines, and ambiguous native-control identities.
The implementation now rejects malformed recordings and ambiguous input routes before accepting a session.
The existing menu gameplay guards remain separate and unchanged.

## Open work

The next step is the user's short recording on the original game, followed by video review.
Do not treat the automated source as a human-play qualification.

Clock drift remains visible in the reports. Exact replay repeatability remains unproved.
Native controls require unique child identities. Wheel and extra mouse buttons remain unsupported.
Videos contain no audio. They omit borders, title bars, and blinking native text carets.
Broad object-state probes, full RNG comparison, and rebuilt execution remain outside this first profile.

## First human recording: cursor offset and normal close

The user reported unwanted camera movement during the first visible recording.
The user then closed the window normally rather than pressing F10.
Evidence: `build/runtime/original-20260914T192329350756Z/capture/report.json`.
The report shows an incomplete terminal boundary, not a reported game exception. Its video remains saved.

The recorder incorrectly converted its logical cursor position into real desktop coordinates before returning `GetCursorPos`.
The pinned cnc-ddraw wrapper already uses logical game coordinates for that API.
Its game-window `ClientToScreen` and `ScreenToClient` hooks leave the point unchanged.
Thus the recorder added a window offset that the game did not remove. This can trigger edge scrolling.

Reference: [cnc-ddraw 7.1.0.0 winapi_hooks.c](https://github.com/FunkyFr3sh/cnc-ddraw/blob/v7.1.0.0/src/winapi_hooks.c),
`fake_GetCursorPos`, `fake_ClientToScreen`, and `fake_ScreenToClient`.
Original code at `004202E0` also skips `ScreenToClient` when `prog_info->full_screen` is nonzero.
The original instructions read `prog_info` at receiver offset `0x0C` and `full_screen` at program-info offset `0x894`.

The input callback now returns logical cursor coordinates directly. No recovered game function changed.
A read-only camera probe records position changes for focused diagnosis.
The normal close button now requests a terminal frame before window destruction, like F10.
The old failed recording and earlier experimental recordings remain preserved.
The instrumentation contract rejects old recordings after this correction; record a new session.

The stationary-cursor and close-request check completed:
`build/runtime/human-cursor-close-check-01/report.json`.
It saved `recording.json` and video after receiving `WM_CLOSE`, with `stop_reason: window-close`.
The camera probe recorded no position changes after world updates started, across 26 update calls.

Three fresh original replays completed:
`build/runtime/human-cursor-close-replay-01/report.json`.
Each completed 27 world-update calls with no later camera-position writes through the monitored setter.
All input messages and game input boundaries repeated. Exact clock equality still failed and remains reported separately.
The final focused test run passed 152 tests. No recovered game source changed.

## Second human recording: dead-character message

`build/runtime/human-20260914T193455395942Z/report.json` reports an incomplete session.
Its runtime is `build/runtime/original-20260914T193455501453Z`.
The recorder stopped on message 259 (`WM_DEADCHAR`) after 337 recorded inputs.
The 48.6-second video and input log remain preserved. No complete recording was published.

The input whitelist now accepts `WM_DEADCHAR` and `WM_SYSDEADCHAR` without changing their parameters.
Replay already suppresses automatic character translation, so it must replay these recorded messages too.
Schema and source-contract tests cover both message IDs. A new human recording is still required.

## Completed human recording and original replay

The next human recording completed successfully:
`build/runtime/human-20260914T193807898696Z/recording.json`.
It contains 324 input messages and a 60.15-second source video.

Three fresh original replays completed:
`build/runtime/human-user-replay-193807/report.json`.
All received the same messages, routes, idle counts, world-update counts, and panel names as the source recording.
No replay dropped an unrequested input message.

Clock fidelity remains limited. The largest input clock difference from the source recording is 898 milliseconds.
The second and third replays differ from the first by at most 20 milliseconds at input receipts.
The report therefore records repeated game input boundaries but rejects exact input-clock repeatability.
These results do not prove equal hidden state or equal pixels.

The first replay video is:
`build/runtime/original-20260914T193926918237Z/capture/video.mp4`.
The source video is:
`build/runtime/original-20260914T193807974719Z/capture/video.mp4`.

Sampled source and replay overviews show corresponding navigation, selection, movement, and camera travel.
This sampling is not a complete video comparison. The user's video review remains the acceptance step.
No rebuilt game ran for this qualification.
