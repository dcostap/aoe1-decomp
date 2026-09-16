# V7 editor recording

The original human run used `game.cmd record-original --editor --seconds 120`.
The run started at `2026-09-16T19:39:06Z` and reached its 120-second limit.

The capture is at:

`build/runtime/original-20260916T193906848567Z/capture/report.json`

It contains 3,729 delivered input events, 146 camera samples, and 1,398 input
frames. The run saved `scenario/default2.scx`. The original video is 120.15
seconds long and has SHA-256
`7936ae7b756d8128cf4c85156c1fab3f97c6b19e182d8b380fe754483fb9f28e`.

## Recovery

The first finalization pass did not write `recording.json`. V7 routes use
`id`, `cls`, and `vis`. The validator still required the old `index` field.
The validator now accepts the old index form and the V7 visibility form.
The record path now writes V7 as its top-level policy.

The recovered recording is:

`config/harness/human-editor-20260916.json`

Its SHA-256 is
`4cac2eb68eb4ef6202eecbf3dacf23fb7c4bc9c48d08fc34618f8976779ed953`.

## Replay check

Three fresh original runs and three fresh rebuilt runs completed. All six
runs received the same 3,729 messages and game input boundaries. The run
used no world or RNG observer. The case compares only delivered inputs,
camera values and receipts, and exact pre-encode RGB hashes.

The comparison report is:

`build/editor-recovery/qualification/report.json`

The comparison is complete but does not pass the visual checks. Camera values,
camera receipts, and RGB hashes differ in the original repeats and across the
two executables. Input timing also varies, while input messages and game
boundaries remain equal. The report keeps these differences. It does not use
masks, tolerances, or state alignment.

The editor case is available with `game.cmd test-parity --editor`. It remains
separate from the default observer-based gameplay suite.
