# Recovery journal: 0053C050 `Get_Closest_Resource`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/vis_unit.cpp`.
- PDB source: `C:\msdev\work\age1_x1\vis_unit.cpp`.
- Earlier recovery note: `recovery_notes/vis_unit_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:45fe9d00fac6c6a28ac4 -->
### `target-session` `build/target_sessions/0053C050_Get_Closest_Resource.json:1-51`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=321; shape=89.51612903225806: Clean scratch reconstruction baseline; verify behavior, calls, frame, and current byte drift.
probe 2 layout; result=MISMATCH; diff=321; shape=89.51612903225806: Hypothesis: preserve the binary-proven type*4 LEA as a named byte offset for both used and resource list accesses.
probe 4 layout; result=MISMATCH; diff=327; shape=89.51612903225806: Hypothesis: direct member indexing should preserve the original deferred VR_List load while keeping the used-count access first.
probe 6 abi; result=MISMATCH; diff=321; shape=89.51612903225806: Hypothesis: use the period constructor-side void** VR_List declaration and cast the selected record pointer. [same emitted code as probe 1]
probe 8 liveness; result=MISMATCH; diff=321; shape=88.70967741935483: Hypothesis: declare the best-record pointer before bestDistance to recover the original post-loop load order and register coloring.
probe 10 liveness; result=MISMATCH; diff=321; shape=89.51612903225806: Hypothesis: keep an explicit manager alias alive across the guarded scan to force the original early ECX receiver save. [same emitted code as probe 6]
probe 12 liveness; result=MISMATCH; diff=327; shape=89.51612903225806: Hypothesis: delay the VR_List pointer alias until after the used-count guard, matching the original deferred [this] load. [same emitted code as probe 4]
probe 14 layout; result=MISMATCH; diff=321; shape=89.51612903225806: Hypothesis: form a used-entry pointer with VR_ListUsed + type so VC5 emits the original index LEA and deferred list access. [same emitted code as probe 10]
probe 16 layout; result=MISMATCH; diff=321; shape=89.51612903225806: Hypothesis: preserve type in a separate index local so VC5 can retain a reusable scaled index across both array accesses. [same emitted code as probe 14]
probe 18 liveness; result=MISMATCH; diff=321; shape=89.51612903225806: Hypothesis: bind self at function scope and use it in the initial guards, making the receiver live before the early branch. [same emitted code as probe 16]
probe 20 liveness; result=MISMATCH; diff=321; shape=89.51612903225806: Hypothesis: reverse the two array-base declarations so VC5 schedules VR_ListUsed before VR_List like the original. [same emitted code as probe 18]
probe 22 liveness; result=MISMATCH; diff=321; shape=89.51612903225806: Hypothesis: move the record cursor to function scope and assign it inside the nonempty-count arm, extending its source lifetime. [same emitted code as probe 20]
probe 24 liveness; result=MISMATCH; diff=321; shape=89.51612903225806: Hypothesis: bind a result pointer after clamping, forcing the original post-clamp best reload and return register. [same emitted code as probe 22]
probe 26 layout; result=MISMATCH; diff=327; shape=89.51612903225806: Hypothesis: keep only the used-list alias and access VR_List directly after the count guard. [same emitted code as probe 12]
probe 29 layout; result=MISMATCH; diff=327; shape=89.51612903225806: Diagnostic hypothesis: keep direct count guard but use one natural typeOffset value for both typed arrays, testing whether EDX retains type*4 before the used count and list load.
probe 31 layout; result=MISMATCH; diff=321; shape=89.51612903225806: Diagnostic hypothesis: split typeOffset declaration from assignment while retaining typed array aliases, testing whether VC5 uses an LEA temporary and preserves the original index register coloring. [same emitted code as probe 2]
probe 33 abi; result=MISMATCH; diff=321; shape=89.51612903225806: Canonical ownership hypothesis: use the reviewed RGE_Player* owner field instead of void*, while preserving the typed resource arrays and natural selection body. [same emitted code as probe 28]
probe 35 layout; result=MISMATCH; diff=327; shape=89.51612903225806: Natural direct member access: load VR_ListUsed[type] before VR_List[type], matching the original count-before-list sequence. [same emitted code as probe 26]
probe 37 liveness; result=MISMATCH; diff=324; shape=84.7457627118644: Binary decomp shows a separate result pointer refreshed from best after each scan iteration; retain that natural alias to test the original ECX return/store basin.
probe 39 layout; result=MISMATCH; diff=321; shape=89.51612903225806: Explicit byte offset local with typed pointer arithmetic, testing the original LEA index without changing the reviewed array ownership. [same emitted code as probe 31]
probe 41 liveness; result=MISMATCH; diff=321; shape=89.51612903225806: Reference alias for the receiver, testing whether natural addressable receiver ownership recovers the original ESI save and later ECX result. [same emitted code as probe 34]
probe 43 layout; result=MISMATCH; diff=327; shape=89.51612903225806: Reference to the indexed used-count slot, testing natural addressable indexing for the original separate LEA offset and count register. [same emitted code as probe 35]
probe 45 liveness; result=MISMATCH; diff=321; shape=91.0569105691057: Move best initialization before record load, matching the original early zeroing before the count test and record-pointer materialization.
probe 46 layout; result=MISMATCH; diff=321; shape=91.0569105691057: Combine early best initialization with explicit shared type offset, testing whether the improved result lifetime and original LEA index can coexist.
probe 47 liveness; result=MISMATCH; diff=317; shape=90.2439024390244: Hoist the best pointer initialization to the count-guard scope, matching the original zero store before the inner count test and record load.
probe 48 liveness; result=MISMATCH; diff=317; shape=90.2439024390244: Keep best at count-guard scope with natural typed array indexing, removing metric-only cursor arithmetic while preserving the improved early initialization lifetime.
probe 49 liveness; result=MISMATCH; diff=325; shape=91.0569105691057: Use direct count-before-list member expressions with hoisted best initialization, testing receiver lifetime across the nonzero guard.
probe 50 layout; result=MISMATCH; diff=317; shape=90.2439024390244: Reverse array-pointer declaration order while keeping hoisted best initialization, testing source declaration coloring for list/used loads. [same emitted code as probe 48]
probe 51 liveness; result=MISMATCH; diff=325; shape=91.0569105691057: Keep only the used-list alias before the count guard and defer the resource-list member load, while retaining hoisted best initialization. [same emitted code as probe 49]
probe 52 liveness; result=MISMATCH; diff=317; shape=90.2439024390244: Explicit receiver pointer alias with hoisted best initialization, testing whether the long-lived self and best locals recover original callee-save colors. [same emitted code as probe 50]
probe 55 layout; result=MISMATCH; diff=325; shape=91.0569105691057: Direct count-before-list member expressions with the hoisted best initialization, retesting natural source order against the receiver-save and index-LEA basin. [same emitted code as probe 51]
probe 57 liveness; result=MISMATCH; diff=317; shape=90.2439024390244: Reuse incoming type parameter as best-distance storage while keeping the hoisted result initialization, testing original PDB ResType write/read evidence against register coloring. [same emitted code as probe 54]
probe 58 liveness; result=MISMATCH; diff=317; shape=90.2439024390244: Move all distance, reject, cursor, count, result, and best-distance locals to function scope, matching the original PDB local lifetime surface rather than inner declarations. [same emitted code as probe 57]
probe 59 liveness; result=MISMATCH; diff=321; shape=89.51612903225806: Delay best initialization until after the count guard and record load, matching original C08D/C096/C09E store order and testing final result-register coloring. [same emitted code as probe 41]
probe 61 liveness; result=MISMATCH; diff=317; shape=90.2439024390244: Add a natural post-scan result alias before the distance store, testing whether the original final ECX result register reflects a separate source result local. [same emitted code as probe 58]
probe 62 control-flow; result=MISMATCH; diff=308; shape=94.95798319327731: Replace the guarded do/while scan with a natural top-tested while(count > 0), testing source loop form against the original test-before-body and dec/jne backedge.
probe 63 control-flow; result=MISMATCH; diff=308; shape=94.95798319327731: Remove the redundant positive-count wrapper and retain one natural while(count > 0) scan, testing whether the compiler's source guard nesting caused the improved LEA and loop shape. [same emitted code as probe 62]
probe 64 control-flow; result=MISMATCH; diff=323; shape=95.7983193277311: Combine the improved top-tested resource scan with direct count-before-list member expressions, testing whether natural read order can preserve the while-loop codegen basin.
probe 65 layout; result=MISMATCH; diff=323; shape=95.7983193277311: Keep the used-list alias before the count guard and defer the resource-list member load inside the nonzero branch, combining fault-order recovery with the improved while scan. [same emitted code as probe 64]
probe 66 control-flow; result=MISMATCH; diff=308; shape=94.95798319327731: Restore the two outer typed array aliases while retaining one natural while scan, confirming the 308-byte codegen frontier after fault-order variants. [same emitted code as probe 63]
probe 67 liveness; result=MISMATCH; diff=308; shape=96.63865546218487: Combine the while-loop basin with delayed best initialization after record load and best-distance setup, matching the original late zero store while preserving top-tested CFG.
probe 68 layout; result=MISMATCH; diff=326; shape=96.63865546218487: Use only the used-list alias before the count guard, direct-load VR_List inside the nonzero arm, while retaining delayed best initialization and the improved while shape.
probe 69 layout; result=MISMATCH; diff=308; shape=96.63865546218487: Restore the full outer typed array alias pair with delayed best initialization and the top-tested while scan; this is the strongest measured natural-shape basin. [same emitted code as probe 67]
probe 70 liveness; result=MISMATCH; diff=308; shape=96.63865546218487: Combine the explicit receiver alias with the improved while scan and delayed best initialization, testing whether the changed liveness basin restores the original ESI self save. [same emitted code as probe 69]
probe 71 layout; result=MISMATCH; diff=308; shape=96.63865546218487: Reverse the two typed array alias declarations while retaining the while scan and delayed best initialization, testing declaration order for the early index and self basin. [same emitted code as probe 70]
probe 72 liveness; result=MISMATCH; diff=308; shape=96.63865546218487: Use a reference receiver alias instead of a pointer alias with the improved while and delayed-best structure, testing whether C++ reference lowering selects the original saved self register. [same emitted code as probe 71]
probe 75 layout; result=MISMATCH; diff=326; shape=97.45762711864407: Direct VR_ListUsed-before-VR_List with delayed best initialization tests authentic member-read order while retaining the improved top-tested scan.
probe 77 liveness; result=MISMATCH; diff=326; shape=97.45762711864407: Manager alias retained across the delayed resource-list load while count stays a direct pre-guard read; tests whether a live this alias recovers original ESI publication. [same emitted code as probe 75]
probe 79 liveness; result=MISMATCH; diff=326; shape=97.45762711864407: Address-taken VR_List slot keeps the manager live through the count guard and delayed list read; tests a natural pointer-to-member slot against the original ESI owner save. [same emitted code as probe 77]
probe 83 layout; result=MISMATCH; diff=326; shape=97.45762711864407: Split resource-list declaration from assignment and delay it until after VR_ListUsed count; tests natural read-order and owner liveness with the retained delayed-best body. [same emitted code as probe 79]
probe 84 liveness; result=MISMATCH; diff=326; shape=97.45762711864407: Combine delayed direct VR_List read with function-scope candidate cursor; tests whether the original saved owner is driven by record lifetime plus authentic member-read order. [same emitted code as probe 83]
```
<!-- end-recovered:45fe9d00fac6c6a28ac4 -->

<!-- recovered:9f84f5eb21109c056860 -->
### `127e4aa977f5` `src/scratch/0053C050_Get_Closest_Resource.cpp:1-69`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// vis_unit.cpp target: Visible_Resource_Manager::Get_Closest_Resource
// initial natural reconstruction from packet/decompiler; scans one resource list for closest non-rejected record.
// Attempt log:
// - Baseline has exact size/frame and both __ftol calls, but VC5 keeps this in ECX through the guards instead of the original ESI save.
// - Split versus combined guards and direct versus manager-alias spelling did not change the prologue basin.
// - Replaced guessed distance constants with the binary-proven DAT_005776D0/DAT_005776D8 double globals; fmul/fsubr sites and several body blocks moved closer.
// - Named used/list array pointers and register-qualified manager were diagnostic only; both worsened or duplicated codegen, so the clean typed direct-member form is retained.
// - A top-tested reject-list while loop plus a branch-local cursor recovered the
//   original single compare/backedge topology, stack homes, and persistent
//   reject_count register; mutating the incoming reject_list did not.
// - Explicit typed used/resource-list locals recovered the original list-before-
//   used load order and improved the localized diff to 321 bytes; a register hint
//   on the list pointer was unchanged and was removed from the living source.
// - Retry session: an explicit manager pointer, same-TU RGE_Static_Object context,
//   and the canonical RGE_Player owner type were codegen duplicates.
// - A diagnostic pointer-typed alias for VR_ListUsed preserved the index LEA and
//   raised shape coverage to 96%, but worsened positional diff by 5 bytes and did
//   not restore the original early ESI=this save; it was rolled back as opaque.
// - Member-slot, volatile-manager, function-scope-local, and delayed-count variants
//   likewise did not move the receiver-save basin; all were restored.
// - Direct member indexing worsened the positional diff by 6 bytes and emitted
//   a shifted count/list block; a named VR_ListUsed element pointer duplicated
//   that result. Both natural typed probes were restored.
// - This pass tested the packet's pointer/index reject-loop coloring with the
//   natural indexed form `reject_list[i]`; it preserved the exact inner loop
//   register/CFG topology and improved edit similarity, but positional bytes
//   stayed at 321. It is retained as the cleanest source spelling.
// - Reusing the incoming type parameter for the distance bound emitted the
//   same 321-byte code and was rolled back. Three explicit early returns grew
//   the function by 12 bytes and were also rolled back.
// - Taking explicit addresses of the used/list elements emitted a duplicate
//   327-byte result and was rolled back.
// - Follow-up probes for a named type offset, direct or delayed member access,
//   pointer-entry locals, reversed array-base declarations, and a function-scope
//   record cursor were unchanged or six bytes worse; all were rolled back.
// - Void-list casts, top-level self aliases, result rebinding after the clamp,
//   and swapped best/bestDistance declarations were duplicate or less natural;
//   none moved the early receiver-save basin.
// - This pass tested a typed-array byte offset in both direct and split local
//   forms; the direct form was 327 bytes different and the split form was a
//   codegen duplicate, so both were restored.
// - Replaced the unused owner void pointer with the canonical RGE_Player*
//   field type. This is codegen-identical and preserves the reviewed ownership.
// - Hoisting best initialization to the count-guard scope improves the current
//   result to 317 differing bytes, 90.24% shape, and 80.51% exact blocks.
//   Other natural alias and offset forms were worse or codegen duplicates.
// - Replaced the guarded do/while resource scan with one top-tested
//   `while (count > 0)` loop. Delaying best initialization until after the
//   record load preserves the natural store order and improves the result to
//   308 differing bytes, 96.64% shape, 82.20% exact blocks, and 32 edit bytes.
//   Direct count-before-list variants preserve the blocker fault order but are
//   323-326 bytes different; they do not improve the current codegen basin.
//   Receiver aliases and reversed array declarations are codegen duplicates.
// - Specialist follow-up restored the pinned source after direct member-order,
//   manager-alias, address-taken slot, and function-scope cursor probes. These
//   forms stayed in the same 326-byte basin or duplicated the 308-byte clean
//   result; none recovered the original ESI receiver save.
// - The reviewed player context cannot be included in this isolated owner: it
//   defines Visible_Resource_Manager and causes a type redefinition. No context
//   edit was retained. Fresh grouped view anchors, including 0053DBA0, remain
//   exact and were not changed by this pass.
// Left in scratch: remaining drift is the early receiver-save/index LEA basin
//   and associated register coloring; behavior, size/frame, calls, and inner
//   reject-loop CFG are established. The current source uses the stronger
//   top-tested scan shape but retains the member-read-order blocker below.
// BLOCKER: the executable reads VR_ListUsed[type] and rejects a zero count
// before it reads VR_List. The rebuild reads VR_List first. An empty list thus
// adds a member read, and the nonempty path changes member-read and fault order.
// Keep the typed resource scan in scratch.
```
<!-- end-recovered:9f84f5eb21109c056860 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

### `wave21-closest-resource-integrate` (2026-08-30)

- Applied the natural PDB-local candidate in `src/vis_unit.cpp`.
- The source uses the original parameter names `Xpos`, `Ypos`, `Zone`,
  `ResType`, `excList`, and `elSize`.
- The source sets up `bestdist`, `c`, and `record` in the PDB-supported order.
- The candidate preserves the proven two `__ftol` calls, loop order, and byte
  distance store.
- Variant lab validation matched 351/351 bytes: `MATCH`, `0.0000%`, frame
  `0x10`, two direct `ftol` calls, six relocations, and the original boundary.
  Evidence: `build/variant_lab/0053C050_Get_Closest_Resource/20260830_010451/`.
- The leased validation recorded the same exact result as probe `#88`.
  Evidence: `build/variant_lab/0053C050_Get_Closest_Resource/20260830_010626/`.
- The grouped `vis_unit` audit kept all nine registered exact neighbors exact.
- The normal checker cannot select this migrated target because the shared
  header emits the class-tag return symbol while the original symbol uses the
  struct-tag spelling. No header edit was permitted in this assignment.
- Record-kind blocker for the coordinator: `include/vis_unit.h:60` declares
  `class VISIBLE_RESOURCE_REC`. The current emitted owner is
  `?Get_Closest_Resource@Visible_Resource_Manager@@QAEPAVVISIBLE_RESOURCE_REC@@HHHHPAHH@Z`.
  The oracle owner is
  `?Get_Closest_Resource@Visible_Resource_Manager@@QAEPAUVISIBLE_RESOURCE_REC@@HHHHPAHH@Z`.
  Repairing this shared declaration needs its dependency audit.

### `wave21-closest-resource-exact` (2026-08-30)

- Applied the atomic PDB-proven record-kind repair. `VISIBLE_RESOURCE_REC` is
  now a `struct` in `include/vis_unit.h:54` and in the forward declaration at
  `include/game_types.h:463`. No source access syntax changed.
- Fresh target validation reports `MATCH`, `0.0000%`, and 351/351 bytes.
  The rebuilt owner is the oracle PAU symbol
  `?Get_Closest_Resource@Visible_Resource_Manager@@QAEPAUVISIBLE_RESOURCE_REC@@HHHHPAHH@Z`.
  Frame is `0x10`, calls are 2/2, relocations are 6/6, and the boundary is
  exact. Evidence: target-session probe `#89` and `check_function.py --no-build`.
- The candidate ABI probe passed with VC5 and all size and field-offset checks.
- The registered-owner audit covered 491 rows across `vis_unit`, `visible`,
  `aiuaimod`, `taiuaimd`, `tplayer`, `player`, `map`, `world`, and
  `t_c_obj_complete_fresh`. It reports 490 registered matches and one known
  unrelated `map` exception at `0045A500`; no dependency regression is tied to
  this header repair. The dependent `00415E50` row remains `MATCH` with zero
  relocation or boundary errors, and its fresh candidate relocation targets
  the PAU symbol. Evidence: `build/audits/workers/wave21-closest-resource-exact/visible-resource-record-kind/`.
- Focused metadata tests passed: 37 tests, `OK`. A full 297-test run had one
  unrelated `test_history_lock_serializes_processes` timing error.
- Source search finds one compiler-facing definition at
  `src/vis_unit.cpp:507`, one declaration in `include/vis_unit.h`, and no
  duplicate owner. The known map debt was not part of this patch.
