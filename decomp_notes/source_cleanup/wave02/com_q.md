# Wave 02 source cleanup: `src/com_q.cpp`

## Delivery

- Module: `src/com_q.cpp`
- Branch: `cleanup/staging-20260915-104`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Source cleanup commit: `6ed37f20af52505b7d632bbddb6819378f11b1a7`
- Formatting correction commit: `dfdfa04fda23e9c58af7354c684fbc5a27341a14`
- Base source SHA256: `76c05dbf17eac0a9e098cddf026dc1b8ebee2aae77f704149e279edafbc55500`
- Final source SHA256: `d4140e11e55cb7cadae2439363caaeee107980de7f78d4d1ee36745924509d72`
- Changed files: `src/com_q.cpp`, this report
- Header owner: owner 12 owns `include/com_q.h`

The source commit changes names only. The report is a separate assigned-file commit.
The final report commit hash is recorded in the delivery message after Git creates it.

## Formatting correction

The follow-up source commit changes two standalone `else` lines to `} else {`.
It changes whitespace and brace placement only. It adds and removes no tokens.
No validation command was run for this correction.

## Evidence

All 18 source-owned procedures were inspected. The two inline header procedures were
also inspected because their registry entries emit from this source.

- Source registry: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/com_q.cpp.json`
- Header registry: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/include/com_q.h.json`
- Function packets: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/`
- Scoped PDB records: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- Scoped PDB SHA256: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`
- Source registry SHA256: `a39fe81923033b7915297c0b23637e1995e697b1a5b95da1e2a20d5774fc9c23`
- Header registry SHA256: `713f3715a030183c66e4a204a40d07c92afccfabd29634eeaedec8a6c305204a`

The packet list came from both source registries. Each assigned VA had one packet.
The PDB records supplied parameters, stack locals, function statics, and registers.
The `this` register is `ecx` for every procedure.

## Original-name recovery

The names below are recovered original PDB names. Existing names not listed below
were not changed. No new descriptive names were invented.

| VA | Procedure | Recovery |
| --- | --- | --- |
| `00431720` | `RGE_Communications_Queue` | `param_1` to `MaxSize`; PDB stack name `MaxSize` at `+0x4`. |
| `00431760` | `~RGE_Communications_Queue` | No scoped parameter or local names. `this` is `ecx`. |
| `00431810` | `AllocateQueue` | `param_1` to `NewQSize`; PDB also records local `i` at `-0x1c`. |
| `004319E0` | `ExpectedNextSequence` | `turn` to `TurnID`; `from` to `PlayerNo`; static `Count` was retained. |
| `00431A40` | `QueuedForTurn` | `turn` to `TurnID`. |
| `00431A70` | `FlushAll` | No scoped parameter or local names. |
| `00431A80` | `FlushTurnRange` | `param_1` to `LowRange`; `param_2` to `HiRange`; return counter `i` to `Count`; index `index` to `i`. PDB offsets are `Count` at `-0x8` and `i` at `-0x4`. |
| `00431B10` | `FlushForPlayer` | `param_1` to `p`; loop `i` already matched the PDB local `i`. |
| `00431BD0` | `FlushForTurn` | `turn` to `TurnID`. |
| `00431BE0` | `FlushThruTurn` | `turn` to `TurnID`. |
| `00431BF0` | `AddItem` | `turn` to `ExecuteOnTurn`; `data` to `command`; `size` to `nBytes`; `from` to `PFrom`; `sequence` to `InSequence`; `control` to `ControlCommand`; local `i` was retained. |
| `00431D10` | `GetQueueDepth` | No scoped parameter or local names. |
| `00431D20` | `GetHighQueueDepth` | No scoped parameter or local names. |
| `00431D30` | `GetSpecificItem` | `player` to `FromPlayer`; `turn` to `ExecuteOnTurn`; `sequence` to `Seq`; `size` to `Size`; static `retptr` was retained. |
| `00431DD0` | `GetNextItemSingle` | No scoped parameter or local names; static `retptr` was retained. |
| `00431E40` | `GetNextItemOrdered` | `turn` to `ThisTurn`; `bestIndex` to `SendMsg`; static `retptr` was retained. PDB records `SendMsg` at `-0x4`. |
| `00431F10` | `GetNextSequence` | `turn` to `ThisTurn`. |
| `00431F50` | `TestShowQueue` | No scoped parameter or local names. |

The header-owned emitted procedures `00431F60` (`MsgQueue`) and `00431F80`
(`~MsgQueue`) have no scoped parameter or local names. They were not changed.

### Unresolved declaration mappings

The PDB has no scoped names for several current locals. I left those names unchanged.
This avoids forced mappings and storage changes.

- `AllocateQueue`: `result`, `count`, `newQueue`, `size`, `source`, and `data`.
- `ExpectedNextSequence`: `seq`, `i`, and `c`.
- `QueuedForTurn`: `count`, `execTurn`, and `remaining`.
- `FlushTurnRange`: `execTurn` and `entry`.
- `FlushForPlayer`: `from`, `entry`, and `data`.
- `AddItem`: `high_depth`, `slot`, and `message`.
- `GetSpecificItem`: `targetCode`, `idx`, and `entry`.
- `GetNextItemSingle`: `q`, `i`, and `entry`.
- `GetNextItemOrdered`: `bestControlCommand`, `i`, and `mq`.

These names remain hypotheses or existing descriptive names. They are not claimed as
original names. No reused stack slot received an uncertain forced name.

## Constants, resources, and comments

No constants changed. Existing values and types remain unchanged, including `0x14`,
`0xFFFFFFFF`, `0xff`, and the queue code multiplier `1000`.

This module has no resource lookup. No resource ID request is needed.
There is no resource file, text payload, language, fallback path, or override path
for this module to report.

No comments were added. The existing code did not need a new proven lifetime or
compatibility comment.

## Header and shared-file requests

Please ask owner 12 to rename declaration parameters in `include/com_q.h`.
Use the recovered PDB spellings below. These are parameter-name changes only.

- Constructor: `MaxSize`.
- `AllocateQueue`: `NewQSize`.
- `ExpectedNextSequence`: `TurnID`, `PlayerNo`.
- `QueuedForTurn`: `TurnID`.
- `FlushTurnRange`: `LowRange`, `HiRange`.
- `FlushForPlayer`: `p`.
- `FlushForTurn`: `TurnID`.
- `FlushThruTurn`: `TurnID`.
- `AddItem`: `ExecuteOnTurn`, `command`, `nBytes`, `PFrom`, `InSequence`, `ControlCommand`.
- `GetSpecificItem`: `FromPlayer`, `ExecuteOnTurn`, `Seq`, `Size`.
- `GetNextItemOrdered`: `ThisTurn`.
- `GetNextSequence`: `ThisTurn`.

No type, layout, calling convention, symbol, or shared constant request exists.
The root retains `include/resource_ids.h` and `include/game_globals.h`; no change is
needed in either file.

## Code-generation risks

The source edit changes only identifiers. It keeps types, scopes, declaration order,
initialization points, operators, control flow, calls, literals, and storage behavior.
The `FlushTurnRange` names follow PDB stack offsets without changing the two counters.
No ABI symbol or public function name changed.

Compiler output was not checked during this wave. Debug-name and line-record effects
remain possible until final validation.

## Validation status

Evidence extraction and full Git diff review were run. The evidence tools were run
with `--help` first.

Compilation, matching, audits, and tests were not run.
No build, executable, game, or runtime validation command was run.
The preserved baseline object is available at:
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/com_q.obj`

Its SHA256 is `cf8438eab48b86d6525170bff857b0703d3ca2e886ae3a35b738b85253e03d90`.
The original executable evidence file is:
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
Its SHA256 is `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
