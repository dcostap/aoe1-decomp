# Recovery journal: 00448340 `_WaveCopyUselessChunks`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Dsutil.c`.
- PDB source: `C:\msdev\work\age1_x1\Dsutil.c`.
- Earlier recovery note: `recovery_notes/dsutil_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:eab5119324610791f60a -->
### `target-session` `build/target_sessions/00448340_WaveCopyUselessChunks.json:1-3`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MATCH; diff=0; shape=100.0: Unique Dsutil wrapper build after authentic C identifier rename emitted _WaveCopyUselessChunks but the custom MMCKINFO overlay still differed at two field-load bytes.
probe 3 control-flow; result=MATCH; diff=0; shape=100.0: Tested combined while-condition and nested while-break forms with native MMCKINFO. Both emit exact bytes; retained nested while-break because PDB line bands separate lines 1116 and 1120.
probe 4 abi; result=MATCH; diff=0; shape=100.0: Replaced the local MMCKINFO overlay with the period SDK MMCKINFO declaration. Full Dsutil wrapper then matched the target at 189 bytes with the original FPO symbol.
```
<!-- end-recovered:eab5119324610791f60a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
