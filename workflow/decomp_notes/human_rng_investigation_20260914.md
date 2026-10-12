# Human replay RNG investigation

## Behavior

The starting source commit is `65e97974b`. The accepted recording remains unchanged:
`build/runtime/human-20260914T193807898696Z/recording.json`.

Its SHA256 is `a320c5d68b8b6f2e49d5d9963e60bc3455c177deac2909d5795ab19e02510e4d`.
The starting rebuilt EXE hash is `b1f6197038f049e731a8df6dd394b65d1de6fbe1a9d7cbac3bf369d65dab9546`.

### First RNG difference: a timing effect

The first combat pair agrees through RNG record 1,221,403.
At index 1,221,404, both receive 8855. Their callers differ:
original `com_obj.cpp:379`, rebuilt `tplayer.cpp:607`.

The second pair reverses these callers without changing either EXE.
Report: `build/runtime/human-rng-investigation-02/report.json`.
Original capture: `original-20260914T212916109927Z`.
Rebuilt capture: `rebuilt-20260914T213019170329Z`.

At world-update 30, original advances 86 ms. Rebuilt advances 100 ms.
Both sample 11763 for world timing. Their previous world-clock samples differ by 20 ms.
The world clamps elapsed time to 100 ms. Thus 86 and 106 become 86 and 100.
The idle counter alone does not distinguish main-loop calls from nested calls.
Only main-loop calls advance the controlled clock by 20 ms.

Hunter 4964, owner 2, attacks animal 1090. Before the 69th update:

- Original animation: frame 10, elapsed 0.11400022357702255, no loop.
- Rebuilt animation: frame 0, elapsed 0.011000223457813263, loop set.
- Both have `need_to_attack = 1`.

The loop permits the rebuilt hit-chance roll first in this pair.
This is not evidence of a defective RNG generator or AI planner.
Observer neutrality remains unproved. These captures are diagnostic evidence, not qualification passes.

### Later RNG difference: enemy villager movement

Original pair-02 and rebuilt pair-01 share simulation time through world-update 200.
Their RNG streams first differ at index 1,221,989, during update 112.
Original calls `asprite.cpp:183`; rebuilt calls `tplayer.cpp:607`. Both receive 1224.
These captures use different observer versions. This comparison is a lead only.

Pair-03 sprite probes identify enemy villager 4969, master 83, owner 4.
Original installs sprite 285 during update 112. Rebuilt installs it during update 122.
This sprite has flags 7, including the random initial-frame flag.

Pair-04 observes different movement speeds: original 1.3, rebuilt 1.1.
Pair-05 traces that difference back to the first world update.
Report: `build/runtime/human-rng-investigation-05/report.json`.

At its first observation, villager 4969 has identical position `(127.5,119.5,0)` and HP 25.
Both captures have input counter 67, update counter 0, clock 5700, and RNG counter 1,220,534.
Neither villager has an action. Both current speeds and velocities are zero.
Their master speeds differ:

- Original: 1.3000000715255737, bytes `67 66 A6 3F`.
- Rebuilt: 1.100000023841858, bytes `CD CC 8C 3F`.

This difference precedes simulation timing divergence. It can change movement and later RNG call order.
It does not prove that it explains every final enemy-unit position.

## Source

`TRIBE_World::new_game`, original `0052EF30`, applies civilization effects after map generation.
The source incorrectly supplies `player->culture`, the byte at player offset `0x54`.

The original instruction at `0052FD30` is:

```text
66 8B 80 0C 01 00 00    mov ax, word ptr [eax + 0x10c]
50                      push eax
FF 52 08                call dword ptr [edx + 8]
```

Offset `0x10C` is `RGE_Player::tribe_effect`, not `culture`.
The original passes its low 16 bits to the effects method.
Use `static_cast<short>(player->tribe_effect)` in the natural source owner, `src/tworld.cpp`.
Keep the full-tech-tree branch and its effect `0xD2` unchanged.
This repair has original instruction evidence independent of observer timing.

## Bytes

The function registry remains `scratch`. This repair does not establish whole-function equality.

- Prior state: `cce268d73caef08a0aa7741ef706c3bcc80fcff105dfcf7f4a7bc63403c7a16d`.
- Repaired state: `95b540bef062b20d252eac8df25c099faa16c81b5901bb8cfc12d7e45be2fd4f`.
- Prior check: 4301 positional differences; repaired check: 4547.
- Both translation-unit closure checks report no exact-owner regressions.

The pinned build compiles all 226 sources and links successfully:
`build/executable/human-civ-effect-repair/20260914T215953270395Z/report.json`.
EXE SHA256: `75ea997f420d64395b314f25d0b3b6bf75bb121c5dc962ee41f8f425bf58278b`.
Its linked instruction at `00515CB2` reads the same low word at player offset `0x10C`.
Only `src/tworld.cpp` changes between the prior and repaired compiler-input manifests.

## Integration

Keep all five diagnostic pairs and earlier traces. Do not replace prior reports or recordings.
The probes read state only. They do not copy original state into rebuilt execution.
`--combat` is a focused diagnostic for this recording, not a general state-equivalence test.
It records full RNG, world clocks, attack animation, sprite additions, and villager 4969.

`tools/harness/rng_investigate.py` separates clock, simulation, action, sprite, and RNG comparisons.
It requires matching observer scripts and modes. Missing tails remain differences.
Observation counts distinguish absent probes from streams with no reported difference.

### First repaired runtime check

Fresh original: `build/runtime/original-20260914T220547760024Z/capture/report.json`.
Fresh rebuilt: `build/runtime/rebuilt-20260914T220651008084Z/capture/report.json`.
Comparison: `build/runtime/human-civ-effect-focused-comparison/report.json`.

Both master speeds now equal 1.3000000715255737. All villager observations match.
All 1,224,978 full RNG records match, including sites, values, and seeds.
Both RNG files have SHA256 `921b566f0e6549853074074edffd468faa3f5c6b24573a17cd2a6672f39bc5d5`.
This pair still has transient simulation-clock differences. The comparison reports them separately.

The full test suite passes: 688 tests and 31 subtests.
An earlier foreground attempt reached its 200-second timeout. The background rerun completed without failures.
### Default-profile repeat checks

All three fresh original runs and three fresh rebuilt runs completed.
Reports: `build/runtime/human-civ-effect-original-qualified/report.json` and
`build/runtime/human-civ-effect-rebuilt-qualified/report.json`.
Comparison: `build/runtime/human-civ-effect-comparison/report.json`.

All 324 input game boundaries and all 36 camera positions match across builds.
Exact clock boundaries do not match.

| Executable | Updates, by run | RNG totals, by run |
| --- | --- | --- |
| Original | 331, 330, 331 | 1224951, 1224937, 1224951 |
| Rebuilt | 331, 331, 330 | 1224951, 1224951, 1224937 |

At 331 updates, both have world time 32524 and RNG count 1224951.
At 330 updates, both have world time 32424 and RNG count 1224937.
All six registration counters equal 5778. The prior extra 36 rebuilt RNG observations no longer appear at the shared endpoint.
These default runs retain only the first 10000 RNG records. Their equal totals do not prove equal full streams.
The separate diagnostic pair supplies the complete-stream comparison above.

The source repair, tests, and evidence are ready to retain. No other game source changed.
Keep timing differences visible. Do not classify remaining differences as AI defects without further evidence.
