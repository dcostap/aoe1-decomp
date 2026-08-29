# Recovery journal: 00540A40 `~RGE_Game_World`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/world.cpp`.
- PDB source: `C:\msdev\work\age1_x1\World.cpp`.
- Earlier recovery note: `recovery_notes/world_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:95fb92053bdec930da4e -->
### `target-session` `build/target_sessions/00540A40_RGE_Game_World.json:1-2`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=66; shape=99.16317991631799: Fresh accepted-drift baseline before canonical World.cpp recovery.
probe 2 abi; result=MATCH; diff=0; shape=100.0: Replaced local overlays, manual vptr, absolute globals, and CRT shims with canonical World members and natural delete.
```
<!-- end-recovered:95fb92053bdec930da4e -->

<!-- recovered:d1524ebb7c90f396e0bc -->
### `a31dfd78d9df` `src/accepted_drift/00540A40_RGE_Game_World.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00540A40 RGE_Game_World::~RGE_Game_World
// Attempt log:
// 1: natural destructor implementation from packet with local class surfaces and delete/free calls: too short 560B; compiler looped first 7 object-list deletes and doubled explicit destructor+delete calls.
// 2: switch to explicit operator delete after destructor and unroll the seven object-list fields: same size 674, edit diff 59; remaining drift includes gameInfo vcall slot and first zeroing schedule.
// 3: add dummy virtual before RGE_Game_Info deleting destructor to call [vftable+4] like original: first 607 bytes exact, only fclose call staging differs near two globals.
// 4: declare fclose as void/int and globals as pointer/int: no change; remaining mismatch is only two fclose argument staging blocks.
// 5: best check: same size 674/674, first 607 bytes exact, edit diff 24 (3.56%), positional diff 56 (8.31%).
// 6: accepted_drift candidate: original pushes EAX directly for fclose(logStatusFile/DVlogf); rebuilt copies EAX to EDX/ECX then pushes that register and compensates with shifted add esp/branch distances. Memory effects and calls are equivalent.
```
<!-- end-recovered:d1524ebb7c90f396e0bc -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
