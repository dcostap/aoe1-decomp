# COM_SPD source-cleanup report

## Delivery

- Module: `src/com_spd.cpp`
- Branch: `cleanup/staging-20260915-107`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `1604a42cb8c509560becb37130e8cfdf47f32ef8`
- Assigned header: `include/com_spd.h` (read only; owner 12)
- Registry: `config/functions/src/com_spd.cpp.json`
- Registry build flags: `gx`
- PDB source: `C:\\msdev\\work\\age1_x1\\com_spd.cpp`
- Changed files:
  - `src/com_spd.cpp`
  - `workflow/decomp_notes/source_cleanup/wave02/com_spd.md`

The source commit restores procedure-scoped PDB names and applies 1TBS brace
placement. It keeps types, scopes, declarations, storage, expressions, calls,
literals, and source order unchanged.

## Evidence checked

I inspected all 27 registry functions in these packets:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432620_RGE_Communications_Speed.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432780_RGE_Communications_Speed.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/004327C0_SetPlayerTurnSpeed.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432800_SetActualLatency.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432840_SetFutureSpeedChange.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432870_EnableSpeedControl.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432880_GetBufferGranularity.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432890_GetAdjustmentCount.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/004328A0_GetBufferGranularityAdjusted.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/004328C0_BufferFramesRemaining.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/004328D0_WaitingOnAcknowledgement.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/004328E0_AdjustLocalSpeed.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432940_ReloadBufferFrames.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432970_BufferTimeToUse.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432A70_Skip.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432A90_GetHighLatencyCenti.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432B00_GetPlayerLatency.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432B20_GetLatencyInfo.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432BD0_GetSelfPlayerOptimalSpeedStr.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432C10_GetPlayerSpeedStatusStr.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432C70_GetMachineSpeedInfo.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432D20_GetRecommendedBufferFrames.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432D90_GetAvgFrameRate.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432DA0_GetRecommendedBufferGranularity.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432DE0_AnalyzeGameSpeed.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432FB0_SetV1.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/00432FD0_SetV2.txt`

I selected those paths from `config/functions/src/com_spd.cpp.json`. I checked
the original assembly and source line span in every packet. The packet review
summary is `build/evidence/com_spd_function_packets.txt`, with SHA256
`7229d179f9beb3eb6cadd7076194ab58b210e54edf65f87c3b7cfbc59ae2d0c1`.

I inspected every procedure-scoped parameter, local, function static, and
register record in:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The PDB index SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The selected record summary is `build/evidence/com_spd_scoped_symbols.tsv`,
with SHA256 `2420f4b3597b20ee1189eef58e62e12c8a53f335697355854c6ecaf0dda6806b`.
All 27 procedures have a `this` register in `ecx` with type
`RGE_Communications_Speed*`.

The original executable checked as a behavior reference is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`

Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved pre-cleanup object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/com_spd.obj`.
Its SHA256 is
`3ea964eb12845ac8f088bafdda894113134077d073ae065acccf3928974d5de5`.

## Original-name recovery coverage

The table lists every PDB scoped record. A dash means that the procedure has
no stack, local, or static record beyond the listed `this` register.

| VA | Function | PDB stack and static records | Source result |
| --- | --- | --- | --- |
| `00432620` | Constructor | `c: TCommunications_Handler*` | Restored `handler` to `c`. |
| `00432780` | Destructor | none | No local record. Kept `tslc`. |
| `004327C0` | `SetPlayerTurnSpeed` | `PlayerNo: unsigned int`; `AvgFramesMsec: unsigned char`; `HiLatencyCenti: unsigned char` | Restored all three parameter names. |
| `00432800` | `SetActualLatency` | `PlayerNo: unsigned int`; `Msec: unsigned long` | Restored both parameter names. |
| `00432840` | `SetFutureSpeedChange` | `BuffCount: unsigned int`; `BuffGran: unsigned int`; `ExecTurn: unsigned long` | Restored all three parameter names. |
| `00432870` | `EnableSpeedControl` | `TorF: int` | Restored the parameter name. |
| `00432880` | `GetBufferGranularity` | none | No local record. |
| `00432890` | `GetAdjustmentCount` | none | No local record. |
| `004328A0` | `GetBufferGranularityAdjusted` | none | No local record. |
| `004328C0` | `BufferFramesRemaining` | none | No local record. |
| `004328D0` | `WaitingOnAcknowledgement` | none | No local record. |
| `004328E0` | `AdjustLocalSpeed` | none | No local record. Kept existing cleanup names. |
| `00432940` | `ReloadBufferFrames` | none | No local record. |
| `00432970` | `BufferTimeToUse` | `current_turn: unsigned long` | Restored `value` to `current_turn`. |
| `00432A70` | `Skip` | none | No local record. |
| `00432A90` | `GetHighLatencyCenti` | none | No local record. Kept existing cleanup names. |
| `00432B00` | `GetPlayerLatency` | `PlayerNo: unsigned int` | Restored `player` to `PlayerNo`. |
| `00432B20` | `GetLatencyInfo` | `buf: char[24]` | `buf` already matched. |
| `00432BD0` | `GetSelfPlayerOptimalSpeedStr` | static `buf: char[150]` at `0062D170` | Restored the static name from `s_self_player_optimal_speed_text`. |
| `00432C10` | `GetPlayerSpeedStatusStr` | `PlayerNo: int`; static `speedstr: char[256]` at `0062CF70` | Restored the parameter and static names. |
| `00432C70` | `GetMachineSpeedInfo` | `buf: char[24]`; static `Info: char[255]` at `0062D070` | `buf` already matched. Restored the static name from `s_machine_speed_info_text`. |
| `00432D20` | `GetRecommendedBufferFrames` | none | No local record. Kept existing cleanup names. |
| `00432D90` | `GetAvgFrameRate` | none | No local record. |
| `00432DA0` | `GetRecommendedBufferGranularity` | none | No local record. |
| `00432DE0` | `AnalyzeGameSpeed` | `NewGranularity: unsigned int*`; `NewBufferFrames: unsigned int*`; `ChangeAlso: int`; local `SyncTurn: unsigned long` | All names already matched. |
| `00432FB0` | `SetV1` | `v1: unsigned long` | Restored `value` to `v1`. |
| `00432FD0` | `SetV2` | `v2: unsigned long` | Restored `value` to `v2`. |

### Recovered names

These names are recovered from positive procedure-scoped PDB records:

- `c` in the constructor.
- `PlayerNo`, `AvgFramesMsec`, and `HiLatencyCenti` in `SetPlayerTurnSpeed`.
- `PlayerNo` and `Msec` in `SetActualLatency`.
- `BuffCount`, `BuffGran`, and `ExecTurn` in `SetFutureSpeedChange`.
- `TorF` in `EnableSpeedControl`.
- `current_turn` in `BufferTimeToUse`.
- `PlayerNo` in `GetPlayerLatency` and `GetPlayerSpeedStatusStr`.
- `buf`, `speedstr`, and `Info` for the three function statics.
- `v1` and `v2` in `SetV1` and `SetV2`.

The PDB names `buf` in `GetLatencyInfo` and `GetMachineSpeedInfo` already
matched the source locals. The PDB names in `AnalyzeGameSpeed` also already
matched the source.

No new descriptive names were added. Existing non-PDB names remain because
the PDB has no record for them. These include `tslc`,
`next_latency_change_turn`, `comm`, `adjustment_count`, `frames`,
`granularity`, `hi_lo_info`, `high_latency`, `player`, `latency`, and `i`.
No reused stack slot was mapped by guesswork.

## Unresolved declaration mappings

The PDB types for the function statics report `char[150]` for `buf` and
`char[255]` for `Info`. The source declarations remain `char[152]` and
`char[256]`. The packet listing reports `0062D170` as `align(152)` and
`0062CF70` as `align(256)`. The `Info` address is `0062D070`. This wave
restores names only and does not copy a different buffer size or declaration
type.

The PDB has no records for the other source locals listed above. Their current
names remain unresolved, but their declarations and scopes remain unchanged.

## Constants, resources, and comments

- No constant or enum was added or changed.
- Player bounds, latency limits, timing thresholds, and sample count literals
  remain unchanged. No reviewed shared symbol proves a better replacement.
- No resource lookup or resource ID occurs in this module.
- No resource extraction was needed. The language files were not read:
  `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`,
  `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`, and
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`.
- No resource declaration or mapping request is needed.
- No source comment was added. The existing constructor comment remains.

## Header and shared requests

I did not edit `include/com_spd.h`, which owner 12 owns. Owner 12 should
restore these declaration names. They do not change the ABI:

```cpp
RGE_Communications_Speed(TCommunications_Handler* c);
void SetPlayerTurnSpeed(unsigned int PlayerNo, unsigned char AvgFramesMsec,
                        unsigned char HiLatencyCenti);
void SetActualLatency(unsigned int PlayerNo, unsigned long Msec);
void SetFutureSpeedChange(unsigned int BuffCount, unsigned int BuffGran,
                          unsigned long ExecTurn);
void EnableSpeedControl(int TorF);
unsigned int BufferTimeToUse(unsigned long current_turn);
unsigned long GetPlayerLatency(unsigned int PlayerNo);
char* GetPlayerSpeedStatusStr(int PlayerNo);
void SetV1(unsigned long v1);
void SetV2(unsigned long v2);
```

The header currently uses other parameter names for these declarations. No
layout, type, or shared constant change is requested. No root-owned shared
header change is requested.

## Code-generation-sensitive review

- Renames change identifier spelling only.
- Brace edits move opening braces to 1TBS lines.
- No scope, declaration point, storage duration, type, cast, expression, call,
  literal, source order, virtual slot, or public symbol changed.
- Static storage names changed to the positive PDB names. Static sizes stayed
  at their baseline values.
- No inline assembly, wrapper, helper, or structural rewrite was added.
- PDB line records can change after brace edits. This is not a byte-equality
  claim.

I reviewed the complete source diff against the base commit. `git diff --check`
passed.

## Validation status

Compilation, matching, audits, and tests were not run. No build, compiler,
executable, game, or runtime validation command was run.
