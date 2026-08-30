# Function notes: 004EF4E0 `save`

## Recovered attempt history

<!-- recovered:ff0001df249da0b4421f -->
### `6a2aef2e2` `src/taitacmd.cpp:2898-2915`

Mapping: `strong`. next mapped function definition is save at old line 2918.

```text
//
// four resize-backed task arrays, scalar/gatherer data, six legacy arrays
// with their inline grow-on-read bodies, the fixed strategic-number table,
// four more grow-on-read arrays, distributions/resource values, the group
// sentinel list, and the remaining tactical state.
//
//   3347B, 94/94 calls, 0x8 frame, 91.13% shape.
// - Guarded ManagedArray aliases for the four resize-backed arrays recovered
//   the original shared array-base accesses.
//   form across all ten manual growth blocks. Current: 3230B, 94/94 calls,
//   0x0 frame, 99.41% shape, 822 positional bytes / 187 edit bytes.
// - Moving the fixed `sn[226]` write-pointer assignment inside its positive
//   count guard reproduced the original test-before-`lea` block order.
// - Original tail serialization writes `zoomingToNextAge` before the adjacent
//   `lastCoopAttackDemandTime` field. Swapping those natural statements gives
//   an exact 3230B / 94-call match.
// - The canonical inline resize body stays visible for same-TU update. Four
//   early save resize sites remain out of line, as the executable requires.
```
<!-- end-recovered:ff0001df249da0b4421f -->

<!-- recovered:ca86443d097b3416f2ce -->
### `02919cecb976` `src/scratch/004EF4E0_save.cpp:1-24`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004EF4E0 TribeTacticalAIModule::save
// PDB: taitacmd.cpp:2276-2426
//
// Canonical serialization order recovered from the executable:
// four resize-backed task arrays, scalar/gatherer data, six legacy arrays
// with their inline grow-on-read bodies, the fixed strategic-number table,
// four more grow-on-read arrays, distributions/resource values, the group
// sentinel list, and the remaining tactical state.
//
// Attempt log:
// - Baseline: named binary-proven tactical fields/arrays and ordered writes;
//   3347B, 94/94 calls, 0x8 frame, 91.13% shape.
// - Scoped loop/grow locals alone were codegen-neutral; a named `newMax` on
//   the first manual grow removed the artificial frame and improved size.
// - Guarded ManagedArray aliases for the four resize-backed arrays recovered
//   the original shared array-base accesses.
// - Reused the matched ManagedArray donor's `newMax` plus bounded `for` copy
//   form across all ten manual growth blocks. Current: 3230B, 94/94 calls,
//   0x0 frame, 99.41% shape, 822 positional bytes / 187 edit bytes.
// - Remaining first mismatch is the fixed `sn[226]` count loop: the source
//   initializes its write pointer before the count test, while original asm
//   tests the count before `lea [this+194h]`. A later unitsTasked growth tail
//   is one byte short and changes the final scalar-call alignment. Budget
//   exhausted; leave this readable period-plausible reconstruction in scratch.
```
<!-- end-recovered:ca86443d097b3416f2ce -->
