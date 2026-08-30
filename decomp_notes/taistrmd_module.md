# taistrmd.cpp source reunification

## Context

The PDB names `C:\\msdev\\work\\age1_x1\\taistrmd.cpp` as the owner for 33 normal functions.
Their source lines run from 34 through 1626. Their addresses are monotonic.
The two deleting destructors at 004E7410 and 004E9240 are compiler-generated.
They have no handwritten owner.

The source uses `include/taistrmd.h` for `TribeStrategyAIModule` and its
module-local access surfaces. `include/aivcrule.h` owns
`VictoryConditionRuleSystem`. It has only its PDB-proven data and methods.

## Status

The source now owns all 33 normal functions in PDB order.
Thirty-two functions retain `matching` status.
`TribeStrategyAIModule::update` at 004E9820 retains `scratch` status.
The module TU entry is `taistrmd` and points to `src/taistrmd.cpp`.

### 2026-08-29 `wave21-resize-taistrmd-correct`

Changed the idle-rule append in `TribeStrategyAIModule::update` to one
reviewed public `ManagedArray<int>::add` operation. Removed the old manual
`numberValue` increment because `add` publishes the value and increments the
count.

The protected-provider candidate regressed the registered exact
`setVictoryCondition` owner. The coordinator restored its 13 explicit growth
calls. A fresh focused check is `MATCH`, `0.0000%`, and the grouped audit keeps
all 31 registered owners exact. Do not make `resize` protected until a legal
source form preserves this owner.

Restored audit: `build/audits/integration/checkpoint-taistrmd-restored`.
The protected-provider checkpoint remains blocked.

## Scratch owner

The update body has 1391 target bytes and 762 differing bytes in its best clean
source. It has the target frame, boundary, 430 instructions, and 20 ordered
calls. The first mismatch is at entry offset +8. The target saves EDI, clears
EBP, then reads `victoryConditionChangeTimeout`. The rebuild clears EBX and EBP,
reads the member, then saves EDI. This changes invalid-`this` fault order and
keeps exact matching unresolved.

No byte forcing, inline assembly, wrapper, or duplicate owner is used in the
reunified source.
