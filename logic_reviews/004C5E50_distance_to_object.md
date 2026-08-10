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

### Round 1 (partially returned)

- Broad adversarial machine-effect reviewer found three substantive differences:
  1. `dy` remained in x87 extended precision instead of being stored/reloaded as
     binary32. For opposite-sign `FLT_MAX` coordinates, the executable rounds to
     infinity while the candidate returned a finite result.
  2. Master/radius dereferences occurred in a different order, changing first
     faults and exceptional ordering on malformed inputs.
  3. The missing ECX stack home changed scratch writes and normal exit ECX state.
  Verdict: needs attention.
- FPU/ABI reviewer found ordinary predicates, field offsets, arithmetic grouping,
  special-value clamps, return and ABI correct. It independently observed the
  other-X/this-X radius read-order difference and a possible last-ulp rounding
  issue, but classified fault order as nonblocking and did not compile the
  candidate to establish its actual spill points.

## Main-agent adjudication

All three machine-effect findings are substantive under the executable-as-oracle rule.
The main agent integrated them rather than treating excess precision or
caller-volatile register state as harmless.

The FPU/ABI review does not rebut the broad adversarial review's concrete
`FLT_MAX` counterexample: it analyzed abstract float source and explicitly left
the candidate's actual spills unestablished, whereas the other reviewer compared
the emitted object. Its suggestion that radius fault order is nonbehavioral is
also rejected by project policy, which includes first-fault order.

The corrected rebuild now matches the executable from entry through +0x47:
`push ecx`, coordinate reads, the binary32 `dy` store/reloads, absolute-value
tests, `this->master_obj` then `other->master_obj`, and the first other-X radius
read/fault all occur in oracle order. It also restores ECX with `pop ecx`.

## Integrated changes

- Renamed the local radius-owner stub from `RGE_Master_Object` to the proven `RGE_Master_Static_Object`; emitted code and metrics were unchanged.
- Revalidated and repinned the normalized natural source.
- Made `dy` a narrowly justified volatile float home to require the executable's
  binary32 rounding and x87 flag behavior.
- Materialized `this_master` and `other_master` in executable order and made the
  other-X radius read a narrowly justified volatile float home. This preserves
  the oracle's pointer/radius first-fault order while retaining ordinary named
  ownership.
- Post-fix checker state: rebuilt/original 169/167 bytes, 81 strict differing
  bytes, first mismatch +0x47, 67.86% instruction shape, no calls. A fresh blind
  review is required after the pending first-round result returns.

## Final decision

Blocked; returned to matching after round-2 findings.

### Round 2 adversarial findings

The post-fix adversarial reviewer found four substantive machine-effect gaps:

- x was not rounded through the executable's binary32 scratch home before reuse;
- other-Y radius access occurred after the X clamp rather than between x's
  compare and status test;
- integer-staged radius values changed signaling-NaN/denormal x87 event order;
- the scratch value and caller-volatile residue differed.

Verdict: needs attention.

### Main-agent round-2 adjudication

A bounded ten-hypothesis pass accepted these findings and reconstructed the
natural x87 expression ownership with exact-valued `double` expression temps for
other-X, this-X, and this-Y. The retained object is 167/167 bytes with 22 strict
diff bytes and matches through +0x62, including binary32 dy/x homes, X-radius
load/event order, scratch x, and x-first squaring. Integer/volatile radius staging
was removed.

One substantive issue remains open: the rebuilt other-Y radius read still occurs
after the X branch, whereas the executable performs it after x's `fcomp` but
before consuming the status word. Moving the source read earlier either loaded it
before the compare or freed/coalesced the binary32 homes and changed precision.
The candidate is therefore not eligible for verified-logic promotion. A fresh
matching pass/review must resolve this fault/x87-exception ordering corner.

The concurrent FPU reviewer classified the current candidate as correct. It
verified binary32 dy/x homes, excess precision, NaN/inf/signed-zero behavior,
radius addresses, unconditional other-Y access, final sqrt, and ABI. It argued
that the +0x62 window preserves ordinary results and FPU arithmetic order, with
only the X-clamp scratch store moving across a hypothetical other-Y/unmasked-FPU
fault. Main-agent adjudication does not clear the blocker: this project treats
fault-handler-visible mutation order and unmasked exception timing as executable
behavior, not merely ABI-valid behavior. In the executable y arithmetic can
fault before the X clamp store/status branch; in the rebuild it occurs afterward.
The active matching follow-up must resolve that ordering or produce stronger
binary evidence that no observable handler/alias state can distinguish it.

### Post-round-2 matching follow-up

A fresh bounded worker isolated the remaining VC5 mechanism with dedicated mini
reproducers and approximately seventy source shapes, a 56-variant focused lab,
and more than twenty flag combinations. At two-deep x87 stack depth, evaluating
the Y expression before the X clamp makes VC5 eagerly load the volatile minuend;
this overlays the required binary32 homes and removes `push ecx`. At one-deep
depth after `fcomp` pops X, VC5 fuses the home read as `fsubr [esp+8]`, but only
after the source-level branch. No tested period-plausible spelling emitted the
executable's fused subtraction between `fcomp` and `fnstsw` while preserving both
homes.

The clean 167/167-byte candidate was restored and revalidated: 55/55
instructions, 4/4 conditional branches, no calls, 22 strict differing bytes in
one span beginning at +0x62, and 96.36% shape similarity. The narrow `volatile
float dy` remains behaviorally justified because it enforces the executable's
binary32 rounding and x87 exception behavior; no diagnostic fake volatility was
retained.

This strengthens matching-exhaustion evidence but does not clear semantic
review. Other-Y arithmetic and its possible memory/x87 fault still occur after
the X branch in the candidate rather than between the executable's X `fcomp` and
status consumption. Consequently the function remains in `src/scratch` and is
not eligible for either accepted drift or verified-logic promotion.

### Post-round-2 CSE follow-up

A fresh DeepSeek matching pass tested the remaining scheduler question rather
than repeating the earlier eager-load families. Duplicating
`y = dy - this_radius_y` in both X-clamp arms causes VC5 to CSE-hoist the fused
`fsubr [esp+8]` into the executable's `fcomp`-to-`fnstsw` window. This diagnostic
reaches 167/167 bytes, 98.18% shape, and 14 strict differing bytes, with the
first 104 bytes exact. It therefore proves that the compiler can recover the
first missing operation without changing the required binary32 homes.

The second Y operation remains unsolved: VC5 always emits
`fsub [ecx+34h]` at the arm join, or duplicates it inside both arms with an
additional jump. It never schedules that other-Y memory read between `fnstsw`
and `test`, where the executable performs it. Full-expression ternaries and
three focused mini-reproducer families confirmed the same boundary. The
duplicated-arm forms are not plausible original source and still preserve the
wrong other-Y fault order, so none was retained.

The clean 167-byte candidate was restored and revalidated at 22 strict differing
bytes and 96.36% shape. The semantic blocker is unchanged: the executable can
perform the other-Y read/x87 operation before the X-clamp branch and scratch
store, while the candidate performs it afterward. This pass adds strong matching
exhaustion evidence but does not justify verified-logic promotion.
