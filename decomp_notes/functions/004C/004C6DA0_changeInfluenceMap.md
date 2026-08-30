# Function notes: 004C6DA0 `changeInfluenceMap`

Module notes: `decomp_notes/stat_obj_module.md`.

## Recovered attempt history

<!-- recovered:6d484a4efbfb48d48582 -->
### `a31dfd78d9df` `src/scratch/004C6DA0_changeInfluenceMap.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C6DA0 RGE_Static_Object::changeInfluenceMap
// Attempt log:
// 1: direct reconstruction from packet with local offset stubs and natural floor/ceil/cell loops.
// 2: corrected InfluenceMap calls to incrementValue/decrementValue and probed min/max compare polarity; default source still compiles 608B vs original 647B, indicating FPU/topology source shape is still too simple.
// 3: fixed master object offsets (los +28, radius_x +30, radius_y +34) and duplicated mode call inside gradient/non-gradient branches to mirror original call blocks.
// 4: removed persistent ObjectType* local and used direct member access; major improvement to same-size 647B, exact through tile-bound calculations until FPU object-bounds stack-order region.
// 5: probed min/max compare polarity for lower bounds toward original `test ah,41` branches; edit diff improved but positional worsened, rolled back to best same-size source.
// left in scratch: same-size 647B and exact through first tile-bound phase; remaining mismatch begins at offset 0x104 in the FPU object-bounds setup. Rebuilt computes equivalent min/max floats but stores/fxch them in a different FPU stack order, then cascades through gradient min/max comparisons and loop tail. Not accepted_drift-safe.
```
<!-- end-recovered:6d484a4efbfb48d48582 -->
