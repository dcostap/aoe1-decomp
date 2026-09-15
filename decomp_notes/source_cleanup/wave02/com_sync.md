# `com_sync.cpp` cleanup report

## Scope and commits

- Module: `src/com_sync.cpp`
- Registry: `config/functions/src/com_sync.cpp.json`
- Header owner: owner 12, `include/com_sync.h`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Source cleanup commit: `ccf8c2ef4f8c259b2bcc229cdef7b11b9e8e4883`
- Changed files: `src/com_sync.cpp`; this report

The source registry lists 12 functions at `00432FF0`, `00433070`, `004330A0`,
`00433180`, `00433290`, `00433450`, `00433460`, `00433A90`, `00433AA0`,
`00433AB0`, `00433AC0`, and `00433AD0`. I inspected the matching packet for
each registry entry under `inventory/functions/0043/`.

## PDB name recovery

I inspected procedure-scoped parameters, locals, and registers for every
registry function in `inventory/pdb/scoped_symbols.json`. Each procedure has
`this` in `ecx`. No function statics were recorded.

Recovered names in `src/com_sync.cpp` are:

- `00432FF0` constructor: `handler` to `c`.
- `00433070` destructor: no named parameter or local change.
- `004330A0 Add`: `turn` to `player`, `wRandom` to `worldtime`, `checksum1` to
  `worldturn`, `checksum2` to `worldrandom`, `chatCrc` to `cs1`, `dataCrc` to
  `cs2`, `a7` to `cs3`, `a8` to `cs4`, and `a9` to `cs5`.
- `00433180 ValidateChecksums`: the same nine parameter mappings as `Add`.
- `00433290 DoChecksum`: `turn`, `cs4`, `cs3`, `cs2`, and `tmp` already match
  the PDB records. Other locals have no scoped PDB records and remain unchanged.
- `00433450 SetLastWorldRandom`: `value` to `lwr`.
- `00433460 LogChecksums`: `playerNo` to `player`, `worldTime` to `worldtime`,
  `commTurn` to `worldturn`, `unifiedVisible` to `cs1`, `checksumNew` to `cs2`,
  `position` to `cs3`, `action` to `cs4`, and `obstruction` to `cs5`.
  `random` and `TBuff` already match the PDB records.
- `00433A90 EnableSyncChecking`, `00433AA0 SetStopOnFail`, `00433AB0
  SetDialogOnFail`, and `00433AC0 SendChatMsgsAtChecksum`: `value` to `Status`.
- `00433AD0 IsPlayerOutOfSync`: `pnum`, `worldturn`, `NumPlayers`, `mycs5`,
  `mycs4`, `mycs3`, `NumDiff`, `mycs2`, `foundMine`, `myRandom`, and `NumSame`
  already match the PDB records.

The `LogChecksums` parameter `player` conflicts with an existing second-loop
local named `player`. I renamed that existing local to the new cleanup name
`player_index`. This keeps its type, scope, declaration point, and uses.
`player_index` is not a recovered original name.

Unresolved names remain unchanged when the scoped PDB has no matching record.
These include `i`, `worldTime`, `world`, `unifiedChecksum`, and `pathChecksum`
in `DoChecksum`; `bad`, `i`, and `check` in `ValidateChecksums`; `file`,
`count`, `index`, `entry`, `visible`, and `player_index` in `LogChecksums`; and
`myWorldTime`, `i`, and `entry` in `IsPlayerOutOfSync`. Constructor and
 destructor loop locals also have no scoped PDB records. I did not force mappings
for optimized or reused storage.

All recovered spellings preserve the PDB case and underscore style. The only
new invented name is `player_index`.

## Evidence and limits

- PDB evidence: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
  SHA256 `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
- Original executable evidence:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Existing module notes record 11 exact owners and the `00433AD0` scratch owner.
  This cleanup did not run matching or change those status records.
- No constants, resource IDs, resource lookups, or comments changed.
  No resource request is needed.

The edit changes identifier spelling only. It does not change types, casts,
expressions, calls, literals, control flow, storage, layout, or symbol names.
Compilation and output checks remain required because this wave defers compiler
validation.

## Header request

Owner 12 should align parameter names in `include/com_sync.h` with the recovered
source names. Do not change types or signatures:

- Constructor `comm` to `c`.
- `Add` and `ValidateChecksums`: use `player`, `worldtime`, `worldturn`,
  `worldrandom`, `cs1`, `cs2`, `cs3`, `cs4`, and `cs5`.
- `SetLastWorldRandom`: `value` to `lwr`.
- `LogChecksums`: use `player`, `worldtime`, `worldturn`, `cs1`, `cs2`, `cs3`,
  `cs4`, `cs5`, and `random`.
- The four setter declarations: `value` to `Status`.
- `IsPlayerOutOfSync`: `playerNo` to `pnum` and `commTurn` to `worldturn`.

## Validation statement

I ran evidence-tool help commands before inspection. I did not run compilation,
builds, matching, audits, tests, games, or executable validation.
