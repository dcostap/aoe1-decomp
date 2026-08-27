# BuildAIModule::insertItem (00409950)

Status: `scratch`.

## Proven context

- PDB source: `aibldmod.cpp`, lines 513-592.
- Body: `00409950-00409B6D`.
- Class owner: `BuildAIModule`.
- Field anchors: `buildList.next` at `+0x15C`, the embedded list at `+0xF0`, and `buildListLengthValue` at `+0x1A0`.
- Call anchors: `strncpy`, `operator new` at `0054B6F0`, `BuildItem` constructor at `00408220`, and setters `004085C0-004086A0`.

## Current result

The authentic `aibldmod.cpp` build has the original size and call set. It differs by eight positional bytes. Boundaries and direct call targets match. The source keeps the natural list insertion and the proven special-item and master-object arms.

## Open issue

The remaining bytes come from the order of the `objType` and `player` parameter loads in the master-object arm. The executable also uses a shared late exception-cleanup tail. Natural VC5 source variants did not recover that topology.

Do not mark this owner exact without a fresh check that reports `MATCH` and `0.0000%`.
