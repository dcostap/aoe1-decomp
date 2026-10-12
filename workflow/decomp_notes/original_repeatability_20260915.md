# Original replay repeatability investigation

## Result

The replay policy does not establish equal simulation time at equal input/update counters.
Fresh original-only runs prove this limitation. It is not a rebuilt-only defect.
Equal complete RNG traces also do not establish equal positions or animation state.

No game source, recording, clock policy, comparator, or expected result changed during this investigation.
All comparisons retain timing, RGB, and RNG differences.
This is a bounded investigation, not a repeatability repair or a gameplay qualification.

## Inputs and scope

Original executable SHA256:
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

Recording: `config/harness/human-candidate-20260915.json`, 1,361 messages.
Recording SHA256: `60c04e651b19d144cd033ffcc5ed2bdff1bfe75629b036f493d8db497e4b832e`.

All new runs use the explicit v1-to-v2 upgrade. They are not same-policy qualification runs.
The control template remains `1112a4ab54fef13f766d20da7fc1815b20f43aa844bbfdde23ce14eeabc862f4`.
The optional observer file remains `3ca08cbb3ceedfc0df0099cdd68a13fa34243ac1fc1aeb77eaeb21f33f83befa`.
Observer modes differ between the control groups and remain visible in capture reports.

Investigation root: `build/runtime/original-repeat-investigation-20260915/`.
No game runs overlap. The tools retain all captures and videos.

## Preserved originals: real RNG-state differences

Compared these existing full-RNG captures, in order:

1. `build/runtime/original-20260915T080644548228Z/capture/report.json`
2. `build/runtime/original-20260915T080947625124Z/capture/report.json`
3. `build/runtime/original-20260915T081250719379Z/capture/report.json`

Runs 1 and 2 first differ at RNG index 3,605,260.
The common value is 28,365. Run 1 calls `tplayer.cpp:607`; run 2 calls `asprite.cpp:183`.
The first differing world-entry segment has zero-based index 211.
The next world-entry seeds are 32,456 and 30,955.

Runs 1 and 3 first differ at RNG index 3,603,517.
The common value is 2,856. The same player/sprite call-site distinction appears.
The first differing world-entry segment has zero-based index 137.
The next world-entry seeds are 18,267 and 18,031.

These are not merely renamed logging sites. The following RNG values and world-entry seeds change.
The original animated-sprite constructor makes the identified RNG call; see binary evidence below.
The preserved RNG-only runs lack per-update world observations. They cannot identify the first simulation-time difference.

Reports: `pair-01-02/report.json`, `pair-01-03/report.json`, and `preserved-segments.json` beneath the investigation root.
Segment inspection uses world-entry `debug_srand` calls at `world.cpp:1698` as diagnostic markers.
It checks RNG file hashes and lengths. It does not replace or align the strict RNG comparison.

## Fresh world/clock controls

Command, after checking `--help`:

```cmd
build\harness-env\Scripts\python.exe tools\harness\human_session.py --recording config/harness/human-candidate-20260915.json --target original --runs 3 --observe --combat --upgrade-v1-to-v2 --output build/runtime/original-repeat-investigation-20260915/world-clock-controls
```

Captures:

1. `build/runtime/original-20260915T103212960726Z/capture/report.json`
2. `build/runtime/original-20260915T103516375683Z/capture/report.json`
3. `build/runtime/original-20260915T103819851498Z/capture/report.json`

The batch completed with exit zero. Each run delivered all 1,361 messages without drops.
Input messages, turn counters, and update counters agree. Exact input clock boundaries do not agree.
Exit zero means capture completion, not parity.

### Earliest recorded clock difference

Runs 1 and 2 deliver input 0 at turn 43 and controlled time 1,204 ms.
They deliver input 1 at turn 45, but its controlled times are 1,204 and 1,224 ms.
Both inputs are mouse moves in the main menu. No world update has occurred yet.
Run 3 also differs from run 1 at input 1.

The first world entry is turn 2,589, after 952 inputs, in all three runs.
Their controlled times are 29,701, 29,702, and 29,720 ms.
Their debug-clock call counts are 4,481, 4,482, and 4,480.
Their 20-ms main-loop idle advance counts are 1,261, 1,261, and 1,262.
Thus, equal turn counters already hide different clock-call and idle-origin histories.

### Same RNG, different simulation state

Runs 1 and 2 have identical complete 3,611,267-record RNG traces, including site identities.
Their first observed simulation-time difference occurs at the end of world update 51:

| Field | Run 1 | Run 2 |
|---|---:|---:|
| Previous sampled game clock | 44,807 | 44,828 |
| Current sampled game clock | 44,914 | 44,915 |
| Elapsed clock time | 107 | 87 |
| World delta after the 100-ms limit | 100 | 87 |
| World time | 4,896 | 4,883 |

One 20-ms main-loop advance occurs between these updates in run 1, but not run 2.
The original world's elapsed-time limit explains the observed 13-ms simulation difference exactly.

With 55 world updates complete, the first attack observation samples target object 16,361 at different positions:

- Run 1: X `164.61280822753906`, Y `165.61280822753906`.
- Run 2: X `164.59359741210938`, Y `165.59359741210938`.

The actor's animation elapsed values also differ: `0.37300020456314087` versus `0.3600001931190491`.
The actor, target, and sampled sprite identities agree. These are not merely frame presentation differences.

### Timing difference followed by RNG divergence

Runs 1 and 3 first differ in observed world time at update 60: 5,729 versus 5,742 ms.
Their RNG traces still agree at that point.

Their first RNG difference occurs at index 3,605,448, within world update 220.
Run 1 calls `tplayer.cpp:607`; run 3 calls `tact_mob.cpp:192`. Both initially return 7,839.
The latter site belongs to object placement. More placement and object-construction RNG calls follow.

At the end of update 220:

| Field | Run 1 | Run 3 |
|---|---:|---:|
| World time | 21,490 | 21,503 |
| Registrations | 18,257 | 18,259 |
| RNG records | 3,605,471 | 3,605,478 |

Run 1 reaches 18,259 registrations at update 221 instead.
Registrations count registration operations, not live units.
The next world-entry seeds differ: 13,872 versus 23,655.

The evidence supports object creation occurring one update earlier after a preceding timing difference.
The probes did not capture the production action's exact work counter. That final threshold connection remains unproved.

Reports: `clock-pair-01-02/report.json`, `clock-pair-01-03/report.json`, and `clock-segments.json`.

## Controls without optional observers

Repeated the same command with `--runs 2`, without `--observe` or `--combat`.
Output: `no-optional-observer-controls/report.json` beneath the investigation root.

Captures:

1. `build/runtime/original-20260915T104400005805Z/capture/report.json`
2. `build/runtime/original-20260915T104702985315Z/capture/report.json`

Both captures completed without reported errors. Each delivered all inputs without drops and completed 463 world updates.
Both report `observer_sha256: null`.
The same first clock split remains: input 1, turn 45, at 1,204 versus 1,224 ms.
Therefore, the optional full-RNG and world observers are not required for this timing variation.

Both terminal RNG counters are 3,611,233. Only their initial RNG prefixes were retained.
This does not establish complete RNG equality between these two runs.
Their terminal world time is 45,700 ms, versus 45,780 ms in the three observed controls.
Both retain 18,279 terminal registrations.
The comparison finds 56 differing raw RGB sample positions out of 3,604; the first is at video time 7,750 ms.

These controls still use the main harness, clock replacement, input hooks, and video capture.
They are not uninstrumented executions. The groups ran sequentially, not as a randomized neutrality experiment.
Their different results do not isolate observer effects from other scheduling variation.

Report: `no-optional-observer-comparison.json`. Procedure: `compare_no_observers.py` beneath the investigation root.

## Why the policy permits this

`tools/harness/human.js` increments `human.turn` after game-thread idle calls.
It adds 20 ms only when an idle call returns into the main `run` loop.
Each replaced debug-clock call separately adds 1 ms.
`pumpReplay` schedules recorded input by turn; it does not reproduce the idle origins or clock-call history.

Original binary inspection confirms three distinct idle call paths:

- Main loop: virtual slot `+0xBC` at `0041D056`; return address `0041D05C`.
- Timer message `0x113`: the same slot at `00420BF8`; return address `00420BFE`.
- Mouse move: the same slot at `004211B8`; return address `004211BE`.

The timer branch tests `message - 0x112 - 1` at `00420BB1–00420BB9`.
The input filter in `human.js` records keyboard and mouse messages, not timer messages.
Therefore, the turn counter can advance through paths with different virtual-time effects.
The fresh counter observations prove that their distribution varies.
We did not trace the exact native message responsible for the earliest split; timer scheduling remains the leading explanation.

Original world-update instructions at `00542F8D` read the clock.
Instructions `00542FB9–00542FC2` subtract the previous clock and limit elapsed time to 100 ms.
They support the update-51 calculation above independently of recovered source comments.

The original animated-sprite constructor pushes line `0xB7` at `0041B07A`.
It calls `debug_rand` at `0041B092`.
The original placement function calls `debug_rand` at `004D1317`, using the line-192 path.

Binary extraction checks the pinned original SHA before disassembly.
Artifacts: `inspect_original.py`, `original-instructions.txt`, and `original-instructions-with-production.txt` beneath the investigation root.
`inspect_segments.py` preserves the RNG inspection procedure there.

## Limits and next step

This establishes a replay timing limitation and real original-versus-original simulation differences.
It does not identify every Windows scheduling input or prove observer neutrality.
It does not prove that every rebuilt difference comes from the same cause.

Do not repair this by forcing world state, RNG results, or clock values to match the other run.
Do not change the existing recordings or silently change their control policy.

The smallest next diagnostic is to record idle origins and native timer dispatch around the first clock split.
A corrected scheduling policy needs its own version and explicit validation.
The old recording lacks the full timer/clock history; do not claim an exact reconstruction of that missing history.

Another possible new test is the game's native `FIXEDUPDATE` option.
Recovered command parsing recognizes it; original world-update instructions also support a fixed-cycle path.
Its argument parsing and complete runtime effects still need original-binary validation before use.
It would define a new test environment, not restore the old recording's original timing.
