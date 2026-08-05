# Logic review: 0041A910 `RGE_Active_Sprite_List::add_sprite`

## Phase transition

The main agent suspended ordinary exact matching after numerous independent passes, 27 meaningful target-session hypotheses, additional May experiments, and three variant-lab runs repeatedly converged on the same exact-size register/CFG basin. An independent phase-readiness audit found no credible high-value exact lead and no unresolved behavior, ABI, layout, call, ownership, or memory-effect fact.

The candidate remains `src/scratch/0041A910_add_sprite.cpp`. Before phase entry, matching-era traversal labels/gotos were normalized to ordinary typed `while` loops; emitted code and metrics were unchanged.

Current validated checker state:

- original/rebuilt size: 158/158 bytes;
- frame: none/none;
- saved registers: `ebx, ebp, esi, edi` / `ebx, ebp, esi, edi`;
- calls: 5/5, ordered and target/relocation aligned;
- original/rebuilt instructions: 68/68;
- CFG: 8/9 conditional branches, 1/0 jumps, 2/2 returns;
- instruction-shape similarity: 95.59%; exact-block coverage: 82.35%;
- strict difference: 36 bytes in 17 spans, first mismatch `0041A936`;
- edit/resync cost: 26 raw, 8.23% bounded, 134 equal bytes.

The stable residual is VC5 register/induction topology. The executable preserves `ESI=this` and uses `EDI` as the pointer-to-predecessor; the candidate folds ESI into `&list`, changing traversal, duplicate-hit, allocation, and insertion register roles while preserving the source-level operations.

### Cumulative matching evidence

- Sequential passes tested natural list loops, predecessor initialization/scope, typed and raw list aliases, complete polymorphic sprite surfaces, declaration order, node/allocation locals, shadow-check surfaces, call argument order, focused flags, and variant labs.
- Every natural non-regressing family remained at the same 158-byte/36-byte basin; fake volatility and broader alias scaffolding regressed.
- Exact donors and packet evidence prove node size/fields, active-sprite virtual surface, list ownership, and call identities.
- The normalized source contains typed fields and ordinary loops, with no fake volatility, manual vtable call, inline assembly, or decompiler control-flow residue.

### Semantic questions at entry

Blind reviewers must establish directly from the executable:

1. Null-input behavior and exact shadow-check/removal predicates and call order.
2. Duplicate detection, byte-count overflow behavior, and early return.
3. Unsigned/signed order comparison used to find the insertion point.
4. Allocation size/count, zero initialization, allocation-failure behavior, and all node writes.
5. Active-sprite creation, virtual `set_offset` arguments/order, and list-link mutation order.
6. Calling convention, parameter widths, `ret 0x10`, malformed-list fault/read order, and any transient observable difference from traversal scheduling.

## Review rounds

No formal blind cohort has yet been adjudicated.

## Main-agent adjudication

Pending a complete concurrent blind cohort.

## Integrated changes

- Replaced two explicit traversal labels/gotos with ordinary typed `while` loops.
- Revalidated and repinned the normalized candidate; emitted code was unchanged.

## Final decision

Pending.
