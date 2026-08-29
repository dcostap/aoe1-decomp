# Recovery journal: 00514590 `objectCostByType`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tplayer.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tplayer.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:2cf70863bf1b8964e111 -->
### `target-session` `build/target_sessions/00514590_objectCostByType.json:1-5`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Baseline: exact bytes and calls, but the current grouped symbol is non-virtual QAE while original FPO records virtual UAE.
probe 2 abi; result=MATCH; diff=0; shape=100.0: Probe 2: add virtual to canonical TRIBE_Player::objectCostByType declaration, matching original FPO UAE symbol. [same emitted code as probe 1]
probe 3 abi; result=MATCH; diff=0; shape=100.0: Probe 3: mirror the virtual declaration in the owner fallback surface; isolated and grouped objects now define the original FPO UAE symbol. [same emitted code as probe 2]
probe 4 abi; result=MATCH; diff=0; shape=100.0: Walkback A: reverting only the shared tplayer context declaration restores grouped QAE, proving the header declaration controls the grouped symbol. [same emitted code as probe 3]
probe 5 abi; result=MATCH; diff=0; shape=100.0: Walkback B: reverting only the standalone owner declaration restores isolated QAE while grouped context stays UAE; both declarations are required for one canonical ABI surface.
```
<!-- end-recovered:2cf70863bf1b8964e111 -->

<!-- recovered:b87c8016464384d25974 -->
### `caa20929b406` `src/matching/00514590_objectCostByType.cpp:5-5`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // BINARY NOTE: the original FPO symbol is virtual.
```
<!-- end-recovered:b87c8016464384d25974 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
