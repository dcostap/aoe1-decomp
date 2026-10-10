# Strategic-number names

## Scope

The starting commit is `278c55b5c`.
This change names 601 strategic-number index uses with 110 macros in `include/taitacmd.h`.
The macros use the original developers' spelling, such as `SNPercentCivilianExplorers`.
That spelling follows the user's instruction, so the names do not follow the project's usual macro style.
Values are unsuffixed decimal integers. The arrays, accessors, signatures, and layouts are unchanged.

Edited modules: `taistrmd.cpp`, `taitacmd.cpp`, `tplayer.cpp`, `taimdmd.cpp`, `taiinfmd.cpp`,
`taiuaimd.cpp`, and `taibldmd.cpp`.

## Evidence for the names

The shipped AI personality files supply the names. The files are
`orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/data2/*.per`.
There are 32 files, and the SHA256 of their sorted `sha256sum` listing is
`e9bda826c2ffbef4c59b89074056d1449353801132b9b5c776de307569a73652`.
Each setting line has the form `index value //SNName`:

```
36    4     //SNNumberAttackGroups
```

The files name 110 distinct indices. Every index has exactly one name across all files.
The extraction is `build/cleanup-2026-10-10/sn_names.txt`.

These are original names in the shipped data, and that is stronger evidence than a cleanup inference.
Neither the data files nor the PDB shows whether the original source used macros, an enum, or something else for them.

## Evidence for the index domain

- `VictoryConditionRuleSystem::loadRules` parses this exact `.per` format into `sn[ruleIndex]`.
  It skips `//` comments, and the index must be below `0xE2` (226).
- `TribeStrategyAIModule::setRule` logs `"Setting SN[%d] to %d."` before it writes `vcRules.sn`.
  The strategy "rules" are therefore strategic numbers.
- `VictoryConditionRuleSystem::execute` copies `this->sn[i]` with `tacticalAI.setStrategicNumber(i, ...)`.
- `TribeTacticalAIModule::attackLimiterTime(int snType)` compares `snType` with strategic-number indices.

Named contexts: `sn[...]`, `setStrategicNumber(i, ...)`, `strategicNumber(i)`, `setRule(i, ...)`, `.rule(i)`,
`attackLimiterTime(i)`, and `snType == i`.
The `case` labels in `execute` are rule numbers and remain numeric.

## Values left numeric

- **Indices 105 through 225.** 100 indices in this range (396 uses) never appear in a shipped `.per` file.
- **`src/aiuaimod.cpp`.** This module was numeric at first. A follow-up named its four uses of 218 and 219.

In `aiuaimod.cpp`, the value of `SNEasierReactionPercentage` (219) is assigned to a local named `maxReactDistance`.
This note does not decide whether that local name or the original use is unusual.

## Compiler context

The first form was a new `include/strategic_numbers.h`, included from `taitacmd.h` and `aivcrule.h`.
It changed `taiconmd`, `taiinfmd`, and `tplayer`.
Three exact claims regressed: `canPlace` (`004D5F00`), `storeAttackMemory` (`004E0FD0`), and
`objectCostByType` (`00514590`).

Probes on `taiinfmd` and `tplayer` with the numeric source unchanged:

| Probe at the include position | Result |
| --- | --- |
| New header with all 110 macros | Both objects changed |
| Same, included on the first line | Both objects changed |
| New header with 10 macros | Both objects changed |
| New empty header with only the guard | Both objects changed |
| `// probe` comment line | Both objects equal |
| Inline `#define SNProbe 1` | Both objects equal |

Opening an additional file changed these objects. Macro count and content did not.
The retained form places the macros in `taitacmd.h`, which already owns `TribeTacticalAIModule::sn`.
`taiuaimd.cpp` gains `#include "../include/taitacmd.h"`, and its object is unchanged.
The same include changed both code and symbols in `aiuaimod.cpp`, so that module stayed numeric at first.

## Validation

Artifacts are under `build/cleanup-2026-10-10/`. The final run is `sn-final`, and the probes are `sn-exp-*`.
The baseline is the full audit at `c41e6039a`.

- All 225 groups compiled. All 5,013 exact claims passed.
- All category counts equal the baseline.
- All 225 non-debug object payloads match the baseline.
- `git diff --check` and the line-ending check passed. clang-format 21.1.8 was applied.

No linked executable build, image audit, automated tests, or runtime suites ran.

## Follow-up: move to `player.h`

The starting commit is `759e8aa20`.
The 110 macros moved without change from `include/taitacmd.h` to `include/player.h`.
They now sit beside the base accessor `RGE_Player::strategicNumber`.
`player.h` was already in every translation unit that uses the names, including `aiuaimod.cpp` through `aiuaimod.h`.
The move adds no include, so it avoids the new-file effect described above.

`UnitAIModule::bestUnitToAttack` in `aiuaimod.cpp` now uses `SNEasierReactionPercentage` (219) for the Easy
difficulty and `SNEasiestReactionPercentage` (218) for the lower difficulty.
The `taiuaimd.cpp` include of `taitacmd.h` from the first change remains.

Validation of the follow-up:

- A full audit, `build/cleanup-2026-10-10/sn-player`, compiled all 225 groups. All 5,013 exact claims passed,
  and every category count equals the baseline.
- All 225 non-debug object payloads equal the `c41e6039a` baseline.

No linked executable build, image audit, automated tests, or runtime suites ran.
