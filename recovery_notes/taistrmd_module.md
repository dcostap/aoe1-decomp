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

## Scratch owner

The update body has 1391 target bytes and 762 differing bytes in its best clean
source. It has the target frame, boundary, 430 instructions, and 20 ordered
calls. The first mismatch is at entry offset +8. The target saves EDI, clears
EBP, then reads `victoryConditionChangeTimeout`. The rebuild clears EBX and EBP,
reads the member, then saves EDI. This changes invalid-`this` fault order and
keeps exact matching unresolved.

No byte forcing, inline assembly, wrapper, or duplicate owner is used in the
reunified source.
