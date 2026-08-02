# Logic review: 00487FA0 `TRIBE_RMM_Database_Controller::add_object_module`

## Phase transition

The main agent suspended ordinary exact matching on 2026-08-02 after multiple
independent assignments, at least 99 documented meaningful hypotheses, focused
micro-tests, donor and same-TU analysis, and a final ten-probe closure pass. The
last assignment resolved the long-standing B025/B039 index-register family with
a nonvolatile reference alias and reduced the strict difference from 1192 to 95
bytes. It also exhausted the remaining defined switch-tail and TU-context leads.
No credible exact-match route remains without genuinely new compiler-IR or
whole-TU evidence.

Current validated checker state:

- source remains `src/scratch/00487FA0_add_object_module.cpp`;
- original/rebuilt size: 1749/1749 bytes;
- frame: `0x14`/`0x14`;
- saved registers: `ebx, ebp, esi, edi` / `ebx, ebp, esi, edi`;
- calls: 11/11 ordered and target-aligned;
- CFG signals: 30/30 conditional branches, 5/4 jumps, 1/1 returns;
- instructions: 480/484;
- instruction shape: 97.73%; exact-block coverage: 94.38%;
- strict difference: 95 bytes in 9 spans, first mismatch `0048813A`;
- edit/resync cost: 41 raw, 1.17% bounded.

The remaining machine-code differences are a small early SIB/base-order hunk and
the late exclusion-zone switch layout, where original physical blocks B050/B051
remain absent from the rebuilt CFG. Calls, established layouts, frame topology,
the large generated-land region, and almost all basic blocks align. This is not
eligible for `accepted_drift`: the missing switch blocks and any associated
memory-effect ordering must be verified semantically rather than presumed
harmless.

### Cumulative matching evidence

- Exact controller/base sizes and offsets were established for land and object
  information, map dimensions, vtable surface, globals, and constants.
- The descending aggregate land shift, starting-age object adjustments, map-type
  6 insertion, random extra-land generation, collision retry loop, object/point
  records, exclusion-zone switch, logging, and all eleven calls are represented.
- Broad expression, operand-order, cast, pointer/index, loop, scope, case-order,
  tail-sharing, context, flag, and variant-lab families were exhausted.
- Exact-register micro-tests and corpus donor scans isolated the index issue; the
  retained `land_count_ref` source recovered the original three-operation index
  register family without volatile or undefined behavior.
- The final pass tested same-TU virtual context and several defined per-arm
  temporary surfaces. None recovered the two missing `/6` physical blocks.

### Semantic questions at entry

Blind reviewers must establish these directly from the executable:

1. Exact predicates, iteration bounds, and write effects of the starting-age
   scans for object IDs `0x53` and `0x6D`.
2. Exact descending-copy behavior for map type 6, including overlap, boundary
   indices, field widths, inserted land contents, and `land_num` update order.
3. Arithmetic signedness, overflow, division, and divide-by-zero behavior in the
   random count, clamp, land-size adjustment, map-size, and coordinate formulas.
4. The collision retry loop's precise ordering: random calls, x/y writes, distance
   arithmetic, `done`, index increments, early exit, the 1000-attempt cutoff, and
   how `count = i` changes the enclosing loop and final `land_num` increment.
5. Every object and land-point field written for generated lands, including
   widths, array indices, ID formulas, counters, and the random `0x66`/`0x42`
   object choice threshold.
6. Exact exclusion-zone behavior for player/land selector values, object IDs
   `0x3B`, `0x41`, `0x42`, and `0x66`, division by 6 or 8, default cases, and
   memory-write ordering. Reviewers must specifically determine whether the
   missing physical B050/B051 blocks encode any observable distinction absent
   from the candidate.
7. Whether cached/reference views of `land_num` observe exactly the same values
   as the original on every reachable path and under any aliasing possibility.
8. Exact final random/log call arguments and ordering, plus every early or
   exceptional path that could skip or precede them.
9. Out-of-range counts, negative values, malformed controller state, and other
   binary-permitted edge cases even if normal game data avoids them.

## Review rounds

No formal blind review round has been integrated yet.

## Main-agent adjudication

Pending independent review.

## Integrated changes

None during logic review yet.

## Final decision

Pending. The function remains in `src/scratch` and must not move to
`src/verified_logic` while any substantive finding is unresolved.
