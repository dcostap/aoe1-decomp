# Function notes: 004DC1B0 `addObject`

Module notes: `decomp_notes/taiinfmd_module.md`.

## Recovered attempt history

<!-- recovered:7fbc637372b7b0055d95 -->
### `d050eea3c` `src/taitacmd.cpp:4943-4945`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// - probe 8: operator[] copy loop as combined `&&` bound (max && index+1) per
//   004DC1B0 lesson; grow copy loops now match the original shape exactly.
// - probe 11: task_done dispatch written as `if (highLevelTaskGatherer(...)
```
<!-- end-recovered:7fbc637372b7b0055d95 -->

<!-- recovered:aaa671eeb4e7b6e12f68 -->
### `fc4b000c6e8f` `src/scratch/004DC1B0_addObject.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004DC1B0 TribeInformationAIModule::addObject
// Attempt log:
// 1: Natural reconstruction from packet and matching removeObject array layout: helper outlined, too small.
// 2: Inline duplicate managed-array append logic.
// 3: Use register object local to try EDI param preservation: no change.
// 4: Rewrite loop conditions as combined && instead of explicit breaks.
```
<!-- end-recovered:aaa671eeb4e7b6e12f68 -->
