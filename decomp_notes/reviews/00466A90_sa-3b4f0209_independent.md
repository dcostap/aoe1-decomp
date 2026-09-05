# Independent review: `00466A90` `setup`

- Workflow: matching with reviewers.
- Reviewer: independent current-session reviewer.
- Worker: `sa-3b4f0209` (`sa-3b4f0209-panel-ez`).
- Worktree: `C:/Projects/my_decomps/aoe1_reviewer_wave_09`.
- Base: `f62004614d1250c437abc96e32fbabe364e3ced1`.
- Scope: `src/Panel_ez.cpp`, scratch target `00466A90`.
- Review result: `APPROVE` evidence-only retention after correction.

## Behavior

The current source is the natural `TEasy_Panel::setup` owner. The target
keeps the reviewed resource-load, parse, width-branch, color-pack, and cleanup
sequence. No runtime behavior harness or test event is present for this work.
Malformed input, external-call side effects, exception paths, fault order, and
allocation or I/O failures remain untested.

The source snapshots use these discarded forms:

- `sa-3b4f0209-00466A90-temp-tail` uses `temp_label + 0xFC` for the file name.
  This is a storage-overlap diagnostic. It is not behavior proof.
- `parameter-defaults` changes the geometry parameters and has the temp-tail
  state as its parent. Its result therefore combines two source changes.
- `xy-locals`, `x-lifetime`, `params-nonfull-first`, and `xy-decl-init` test
  geometry lifetime or control-flow forms from the clean baseline.

The geometry forms appear intended to preserve defined values on the normal
paths. Static inspection does not prove equal memory effects or fault order.
The temp-tail form can change storage effects because it writes through an
interior pointer near another local. No discarded form is accepted as a
behavior repair.

## Source

The target dossier records `TEasy_Panel::setup` in `Panel_ez.obj`. It records
`TDrawArea* render_area_in` at `+0x4`, `int own_mem` at `-0xCC8`, `int f2g` at
`-0xCC4`, `int f2r` at `-0xCC0`, and `char[260] popup_info_file_name_in` at
`-0x104`. It records no function-local statics. These records support names,
types, and ownership. They do not prove source lifetime or register
allocation.

The current source hash is
`a5673f7512b01a97ffb9096c17ba7f7cd247d7def416bd138163011666f651ba`.
It matches baseline state
`59acb680f0f62b6272295e610abc02e22bf3914706c731d614bc44bdaedd04d9`.
`git diff -- src/Panel_ez.cpp` is empty. No header, flag, registry, inventory,
test, or candidate patch change is retained. The function registry still
reports status `scratch`.

The worker corrected the function-note `Current mismatch` section. It now
reports 1641 bytes, 590 differences, frame `0xCCC` versus `0xCC8`, first
mismatch `+0x2`, aligned calls, matching owner and CFG, and scratch status.
Correction event `544642c5113eba7e663477a6359591c62d4c9695ba6c8e280723f4e5f097f10b`
records the change. Its saved note object hash matches the current file.

## Bytes

The authoritative no-build check reports:

- `MISMATCH`, 1641 compared bytes, 590 differing positions.
- Original frame `0xCC8`; rebuilt frame `0xCCC`.
- First strict mismatch at `+0x2`.
- 491 original instructions and 493 rebuilt instructions.
- 67.95% shape similarity and 18.13% exact-block coverage.
- 33/33 calls aligned, with no site gaps, replacements, or target-count gap.
- 25/36 call relocations safely masked.
- Owner symbol matches.
- CFG counts match: 23 conditionals, 6 jumps, and 2 returns.

The target therefore is not exact. It does not meet `MATCH`, `0.0000%`,
boundary, frame, or positional-byte requirements.

The target-session records five meaningful probes and one final validation:

| checkpoint | state source hash prefix | result | diff | frames | wrong targets |
|---|---:|---:|---:|---:|---:|
| `probe-001-layout` | `5580a1aa` | MISMATCH | 1428 | `0xCC8/0xCC8` | 0 |
| `probe-002-layout` | `e8f99e4d` | MISMATCH | 1400 | `0xCC8/0xCD0` | 0 |
| `probe-003-liveness` | `e0ff298d` | MISMATCH | 1401 | `0xCC8/0xCD0` | 0 |
| `probe-004-control-flow` | `c92effaa` | MISMATCH | 1487 | `0xCC8/0xCCC` | 0 |
| `probe-005-liveness` | `f2f1e0fa` | MISMATCH | 1524 | `0xCC8/0xCD0` | 1 |
| `probe-006-validation` | `a5673f75` | MISMATCH | 590 | `0xCC8/0xCCC` | 0 |

All six target-session records show fresh fingerprints, matching owner
symbols, and 33 aligned calls. The final record is validation, not a new
candidate. Its rebuilt output hash is
`f85dc37447d462b1cbf0f917a8318b58fe9012c1320ae416d9f01e2e5f085ead`.

An independent `panel_ez` closure audit compiled 76 configured functions. It
reported 73 matching results, two accepted-drift observations, and one grouped
mismatch at `00466A90`. The accepted-drift observations are existing owners
`004675C0` and `00468000`. This audit supports the prior closure count. It does
not prove target semantic equality.

## Integration

- Source integration: approve no integration. No source change is proposed.
- Status: keep `00466A90` as `scratch`.
- Exact proposal: none.
- Accepted-drift proposal: none. The unresolved frame and local topology
  difference do not support semantic acceptance.
- Behavior disposition: evidence-only retention. Do not claim runtime
  equivalence for any probe.
- Experiment preservation: approve. The worker added durable run events and
  artifact objects for all five missing candidate states.

Immutable state manifests and source objects exist for the worker baseline,
temp-tail state, and the five geometry states:

- baseline: `59acb680f0f62b6272295e610abc02e22bf3914706c731d614bc44bdaedd04d9`
- temp-tail: `faff46d553902ab93b5c03ab107897feb4add6ff9d7918b2f05bcea9e3cd9ee7`
- parameter-defaults: `2efdf73395fce65be27c285669a3ebdc8076f6bd5fddde01bed71f6938491f8a`
- xy-locals: `04830953a5c9f351c911c8de4bae4b5afcbbcab8d60453615f2dd39990e93ebf`
- x-lifetime: `2045e5f5109b385e3c7526ded06261c2e45aae058f45ce059b3932115a4e54f0`
- params-nonfull-first: `74f2ff962ff34990f6f7d0503d05ce1ccd461f3216a8f18b11a3f3d5d0f7d9a1`
- xy-decl-init: `af54d9437ddbc1721b97773df51c43faf4ad085230043644ea216b4b019f1931`

The baseline has durable run event
`6a16aaa07c0a693d8688eeea7e1e74dd978ee7c4d451e46b05dfbc5b63377abd` and
finding event `24d1ddbc2616eb0ec3546c49d097521695def1480fd302fa660ad2a086c5f4b5`.
The temp-tail state has durable run event
`649902707d9538e7d0242d7ebc0dc05c5480ed3e04613bb89820fd3bf2a00321`.

The worker added durable run events for all five target-session candidate
states. The event summaries match the target-session results. Each event has
three present, hash-valid artifact objects: rebuilt bytes, diff JSON, and
checker output.

- `parameter-defaults`: `fdba93041b2627058481d460a6aa2681df4e906704fd3cdc000b406982944431`
  (`MISMATCH`, 1428 differences; event record ID `c4c3fee331ac4aecb88c158b13e880d0`)
- `xy-locals`: `a796321bc446e349b5af709914cf3a765ec03035a8d098dd9f5e27b6703d4a27`
  (`MISMATCH`, 1400 differences; event record ID `abb5fac912854e7d905b92884b6076da`)
- `x-lifetime`: `d841f51e56e12daf6171ef64ef6f50943feb06fd2f775b4332d8187c0ed83e17`
  (`MISMATCH`, 1401 differences; event record ID `a2d1eb5339114ae7a1ab6add096d79bc`)
- `params-nonfull-first`: `589513e09ec31d5a7dc63d3563d3bc99fbd804f53b20e9bf9881548bda0dd299`
  (`MISMATCH`, 1487 differences; event record ID `65b95ae7ed7d4bedad87efa602c2e162`)
- `xy-decl-init`: `2c80e839cf0af2649221f49222ce3c6408d0a141d38e5ae51a063b3b452e32aa`
  (`MISMATCH`, 1524 differences; event record ID `782a90f152fc4205ad8f011271d6e8b0`)

Finding event `9b4e1b05facb8c2574e11d266e1f20e3a14da90e55fa495da58a1eb6ff078885`
records that `parameter-defaults` is derived from the temp-tail state. The
worker did not overwrite an immutable state.

The prior review finding preserved the target-session, history, and closure
artifacts as immutable objects. The correction events now link each candidate
result to its state. The corrected function note is the only tracked
source-adjacent change. No source, header, flag, registry, inventory, or test
change is present. Evidence preservation is complete, subject to the
integrator committing the new states, objects, events, and review.

This review does not request a source, header, registry, flag, inventory, or
test change.

Validation reviewed:

- `python tools/check_function.py --va 00466A90 --no-build --no-history --detail concise --call-map --stack-map`
- `python tools/audit_translation_unit_functions.py --group panel_ez --jobs 1 --output-dir build/review_sa_3b4f0209_closure`
- `python tools/experiment_history.py show --va 00466A90`
- `python tools/experiment_history.py inspect` for all listed states
- `build/target_sessions/00466A90_setup.json`
- `build/history/00466A90_setup/history.json`
- `build/dossiers/00466A90_setup.txt`
- `decomp_notes/functions/0046/00466A90.md`
- `config/functions/src/Panel_ez.cpp.json`
- `git diff -- src/Panel_ez.cpp`
