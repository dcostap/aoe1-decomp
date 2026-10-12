# Global initial-data audit

## Method

`tools/audit_global_initializers.py` compares original and rebuilt PE initial storage.
It reads named global records and primitive-array sizes from the original PDB through `cvdump -g` and `cvdump -t`.
It joins global names to the rebuilt linker map.
It reads values from the original beta EXE, not generated initializer text.
It includes the zero-filled portion of PE sections.

Run with `--build`, `--cvdump`, and `--output`. See `--help` for syntax.
Output must remain under `build/`.
The tool returns exit code one when it finds differing initial bytes.
It does not modify game source.

## Audited build

Main commit: `48e2aad22`.
Build: `build/executable/20260906T235619943798Z`.
EXE SHA-256: `6039ef9eccef85a9cb42ded6f5eac426a43e17058f9a8e0c0f41c19070f3c279`.
Report: `build/global_initializers/report.json`.

Counts refer to PDB records, not unique globals. Some names have multiple type records.

| Result | Records |
| --- | ---: |
| Equal initial bytes | 121 |
| Different initial bytes | 3 |
| Type or startup review required | 107 |
| No linked name found | 60 |
| Invalid original section | 1 |

## Differences

| Global | Original VA | Original value | Rebuilt value |
| --- | --- | --- | --- |
| `save_game_version` | `0058EBCC` | `7.23f` | `0.0f` |
| `fixed_update_time` | `0057F9E4` | `100` | `0` |

Both definitions are in `src/game_globals.cpp`.
`RGE_Game_World::update` uses `fixed_update_time` when fixed updates are enabled.
The startup crash investigation establishes a runtime effect for the wrong version value.

`src/tplayer.cpp` defines `tribe_group_properties` as forty unsigned long entries.
The PDB also reports 160 bytes. Six entries differ:

| Index | Original | Rebuilt |
| --- | ---: | ---: |
| 17 | 16 | 0 |
| 18 | 150 | 16 |
| 19 | 0 | 150 |
| 33 | 0 | 7 |
| 35 | 7 | 0 |
| 36 | 7 | 0 |

The original array starts at `0058ABA0`; the rebuilt array starts at `0056A0E0`.
The source uses these entries to accumulate selected-object properties.
No runtime effect test or source repair accompanies this audit.

## Limits

This first pass covers named PDB `S_GDATA32` records, not every global or function-static object.
It does not cover unnamed DAT symbols, missing names, or constructor effects.
Pointer values and constructed objects require separate review; the tool does not compare their raw addresses as values.
Relocations inside plain storage also prevent automatic comparison.
Sizes come from the original PDB. Rebuilt declarations and ownership still require review before repairs.
Equal initial bytes do not prove equal behavior after startup initialization.
The tool reports these limits instead of claiming a complete global-state audit.

## Validation

`python tests/test_global_initializers.py` passes four tests.
They cover stored bytes, zero tails, zero-only storage, and invalid ranges.
The live audit detects the known version defect and two additional data differences.

## Repair checkpoint

Corrected all three definitions to the original initial values.
Build `20260907T003157709284Z` compiles all 226 modules and links without errors.
The repaired audit reports 124 equal records and no differing records in its supported scope.
Report: `build/global_initializers/repaired.json`.

The affected translation-unit audit checks all 103 TPlayer owners; all 87 exact targets retain their results.
Report: `build/global_initializers/closure/report.json`.
The source dependency selector does not include consumers of separately linked global definitions.
The full executable build covers their compilation; only initial data changed, not their source or declarations.

Ran the rebuilt EXE through Single Player, Random Map, and Start Game without debugger memory changes.
Database loading passed. Object placement reproduced the later `005149EC` invalid-pointer fault.
Dump and log: `build/crash/map_setup/initializers.dmp` and `initializers.log`.
This checkpoint repairs initial data; it does not claim successful map startup.
