# Logic review: 004C5E50 `RGE_Static_Object::distance_to_object`

## Phase transition

The main agent suspended ordinary exact matching after five or more independent bounded assignments, roughly seventy source/type/FPU/liveness hypotheses, seven focused variant-lab runs covering roughly seventy variants, and repeated convergence on the same natural and size-matching VC5 basins. An independent phase-readiness audit found no credible unexplored exact lead and no unresolved source-level behavior, ABI, layout, call, or memory-effect fact.

The candidate remains `src/scratch/004C5E50_distance_to_object.cpp` and was normalized to the proven `RGE_Master_Static_Object` radius-owner name before phase entry.

Current validated checker state:

- original/rebuilt meaningful size: 167/147 bytes (160 extracted with padding);
- frame: none/none; saved registers: none/none;
- calls: 0/0;
- CFG: 4/4 conditional branches, 0/0 jumps, 1/1 return;
- original/rebuilt instructions: 55/62;
- instruction-shape similarity: 40.32%; exact-block coverage: 10.91%;
- strict difference: 166 bytes, first mismatch `004C5E50`;
- edit/resync cost: 119 raw, 36.39% bounded, 94 equal bytes.

The natural source keeps the coordinate deltas and radius expressions in a different x87 stack/spill topology. The executable reserves one local with `push ecx`, reuses the incoming parameter home for one delta, computes the radius-adjusted axes in a different order, and homes one intermediate without popping it. Plausible source repeatedly emits the current 147-byte family; exact-size variants require fake volatility or unsuitable `/Op` scheduling and remain broadly wrong.

### Cumulative matching evidence

- Independent May and August passes tested natural expression orders, declarations, parameter-home reuse, typed full-class surfaces, clamp forms, zero-constant surfaces, explicit temporaries, narrow/whole volatility diagnostics, `/Op` and other focused flags, and seven variant labs.
- No lab produced an exact candidate. Size-matching groups share the wrong prologue/FPU topology.
- Metric-best variants require fake volatile or unused-local scaffolding and were correctly rejected; the retained candidate is ordinary readable C++.
- Exact same-TU sibling evidence establishes the field layout. The authoritative accepted-drift sibling `004C5F00 distance_to_position` exhibits the same FPU spill-selection obstacle, but this function is being reviewed independently.

### Semantic questions at entry

Blind reviewers must establish directly from the executable:

1. Exact coordinate and radius field offsets, operand order, and subtraction grouping.
2. Absolute-value behavior for signed zero, NaN, infinities, and exceptional x87 values.
3. Clamp predicates and unordered-comparison behavior for each axis.
4. Final squared-distance expression, precision, x87 stack behavior, and square-root result.
5. Pointer-read and fault order for null/invalid `this`, `other`, and master-object pointers.
6. Calling convention, parameter cleanup, return channel, and whether any memory outside transient stack slots is written.

## Review rounds

No formal blind cohort has yet been adjudicated.

## Main-agent adjudication

Pending a complete concurrent blind cohort.

## Integrated changes

- Renamed the local radius-owner stub from `RGE_Master_Object` to the proven `RGE_Master_Static_Object`; emitted code and metrics were unchanged.
- Revalidated and repinned the normalized natural source.

## Final decision

Pending.
