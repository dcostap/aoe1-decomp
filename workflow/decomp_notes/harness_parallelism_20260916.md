# Harness parallelism

## Scope

The harness now runs independent work together. Each hidden game worker keeps
its own runtime, desktop, registry namespace, and process job.

The default is all workers. Use `--jobs N` to limit concurrency. Use
Set `--jobs` to one for a serial diagnostic. Visible UI mode stays serial because all
visible cases share the interactive desktop.

The parity suite runs its scripted, human, editor, and native-feature workers
in parallel. Human replay runs also start their independent captures together.
The replay tool starts all six captures together. The UI suite starts each
selected case in a nested private-desktop worker. The feature lab starts its
capture runs together and its two civilization sets together.

## Race repair

The first UI trial found a real output-path collision. Windows returned
`WinError 183` when two workers received the same microsecond timestamp.
`tools/game.py:stamp` now adds a UUID suffix. Runtime output paths are unique
across threads and processes.

## Evidence

- `build/runtime/ui-main-menu-20260916T223830462310Z-72482a6d10a0/report.json`
  passed 10 selected settings cases with two UI workers and one original run.
- `build/runtime/replay-20260916T224035547393Z-380f92c1624c/report.json`
  passed six concurrent gameplay captures. State, input, RNG, and three RGB
  checkpoints passed.
- `build/feature-lab/parallel-full-20260916/report.json` passed four concurrent
  feature captures and all six comparison pairs with full 800-turn coverage.
- `build/runtime/human-20260916T224355892272Z-646dfda34673/report.json`
  passed two concurrent controlled human replays. Input sequence and exact
  repeat boundaries passed.
- `build/feature-lab/parallel-smoke-20260916/report.json` also launched four
  workers and passed all six pairs. Its 100-turn run did not meet full feature
  coverage, so its process exit was correctly nonzero.

The focused harness tests passed 225 tests after the first implementation.
The full project test result is recorded with the task validation.

This evidence does not prove that every host resource scales without a limit.
Use `--jobs` when CPU, memory, or private-desktop limits require a smaller
batch.
