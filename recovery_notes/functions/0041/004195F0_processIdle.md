# Recovery journal: 004195F0 `processIdle`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/aiuaimod.cpp`.
- PDB source: `C:\msdev\work\age1_x1\aiuaimod.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:c40f4f7642126e995cab -->
### `d050eea3c` `src/aiuaimod.cpp:4032-4034`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// --- matching/004195F0_processIdle.cpp ---
// VA: 004195F0 UnitAIModule::processIdle
// aiuaimod.cpp lines 5255-5282; protected virtual owner (PDB symbol MAEHH).
```
<!-- end-recovered:c40f4f7642126e995cab -->

<!-- recovered:0798dfd51112cccabb08 -->
### `d050eea3c` `src/aiuaimod.cpp:4036-4036`

Mapping: `strong`. comment lies after mapped function processIdle at old line 4030.

```text
// BLOCKER: The isolated view below emits the three original virtual calls.
```
<!-- end-recovered:0798dfd51112cccabb08 -->

<!-- recovered:b3cfec4da3db2b3c1cb5 -->
### `target-session` `build/target_sessions/004195F0_processIdle.json:1-4`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Qualified protected virtual UnitAIModule::processIdle owner from aiuaimod.cpp PDB symbol; bytes and 004195F0-00419642 body remain exact.
probe 2 abi; result=MATCH; diff=0; shape=100.0: Made the PDB-proven protected processIdle declaration virtual; rebuilt owner now must preserve the original protected virtual MAEHH symbol. [same emitted code as probe 1]
probe 3 abi; result=MATCH; diff=0; shape=100.0: Walkback: removing virtual keeps bytes exact but changes rebuilt owner to nonvirtual IAEHH, so the PDB-proven virtual qualifier is required. [same emitted code as probe 2]
probe 4 abi; result=MATCH; diff=0; shape=100.0: Walkback: removing protected access keeps bytes exact but emits public QAEHH, unlike original protected virtual MAEHH; access is required for qualified ownership. [same emitted code as probe 3]
```
<!-- end-recovered:b3cfec4da3db2b3c1cb5 -->

<!-- recovered:43dbde02f6c223e5d386 -->
### `5868718576a8` `src/scratch/004195F0_processIdle.cpp:1-15`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: full vtable (36 slots), .text 80 instead of 82
// attempt 2-3: minimal class, still 80
// attempt 4: if/else if/else structure, still 80
// attempt 5: early return guards, still 80
// attempt 6: match original control flow (no else), still 80
// attempt 7: include stdlib.h, still 80
// attempt 8: unsigned char return/params, still 80
// attempt 9: expanded conditions + /G5, still 80
// attempt 10: /GX, still 80
// attempt 11: /Od, still 80
// attempt 12: unused local var, still 80
// left in scratch: VC5 consistently compiles to 80 bytes regardless of source shape/flags
// behavior fully correct: param==1 guard -> vtable call -> cmp 8 -> return 6
// fallthrough: vtable call(1,0,0) -> cmp -1 -> vtable call -> cmp 1 -> return 6, else return 5
// remaining gap: 2-byte size deficit, codegen basin not found after 12 meaningful attempts
```
<!-- end-recovered:43dbde02f6c223e5d386 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
