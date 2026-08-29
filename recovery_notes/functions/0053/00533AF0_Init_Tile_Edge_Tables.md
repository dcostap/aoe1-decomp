# Recovery journal: 00533AF0 `Init_Tile_Edge_Tables`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/view.cpp`.
- PDB source: `C:\msdev\work\age1_x1\view.cpp`.
- Earlier recovery note: `recovery_notes/view_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:680b384f5b6ae57e29f8 -->
### `target-session` `build/target_sessions/00533AF0_Init_Tile_Edge_Tables.json:1-45`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=341; shape=91.31944444444444: Baseline current typed table source: 800 bytes, 341 strict diff; calls/frame exact. First divergence is black-root loop and later bit-local homes.
probe 2 layout; result=MISMATCH; diff=453; shape=92.73356401384083: Hypothesis 2: use typed indexed Black_Edge_Tables[i] root relocation instead of a moving root pointer; tests whether canonical pointer-array indexing recovers the original offset loop.
probe 4 liveness; result=MISMATCH; diff=358; shape=90.27777777777777: Hypothesis 3: reorder the eight bit-local declarations (b4,b5 before b0,b1) while retaining the best root-pointer loop; tests whether VC5 stack-home assignment follows declaration order.
probe 6 liveness; result=MISMATCH; diff=341; shape=91.31944444444444: Hypothesis 4: move count after the bit locals in declaration order; tests whether the original B5/count home at entry-relative -0x10 is declaration-driven. [same emitted code as probe 1]
probe 7 variant; result=MISMATCH; diff=341; shape=91.31944444444444: variant lab build\variant_lab\00533AF0_Init_Tile_Edge_Tables\20260817_132141: 5 variants, 4 invariant-eligible, 0 exact
probe 9 layout; result=MISMATCH; diff=453; shape=92.73356401384083: Hypothesis 8: clone the known exact serialized-root offset loop used by Tile_Edge_Tables for Black_Edge_Tables; tests whether the original black root pass is the same byte-offset loop rather than a typed pointer walk. [same emitted code as probe 2]
probe 11 layout; result=MISMATCH; diff=341; shape=91.31944444444444: Hypothesis 9: represent the serialized black root array as int* and update black_data[i] in a typed count loop; tests whether scalar root width, not pointer type, selects the original loop lowering. [same emitted code as probe 7]
probe 13 context; result=MISMATCH; diff=341; shape=91.31944444444444: Hypothesis 10: reverse the serialized EdgeNumber address-add spelling to *(i + edge) for the two loop-indexed accesses; tests the original SIB base/index order without changing behavior. [same emitted code as probe 11]
probe 14 liveness; result=MISMATCH; diff=474; shape=86.55172413793103: Hypothesis 11: narrow only the validity flag ok to bool while retaining dword bit locals; tests whether the original flag's source type drives the early EDI path without the prior all-bool frame expansion.
probe 16 abi; result=MISMATCH; diff=341; shape=91.31944444444444: Hypothesis 12: widen count to unsigned int; tests whether the original count home and increment use unsigned source semantics rather than signed int. [same emitted code as probe 13]
probe 18 control-flow; result=MISMATCH; diff=483; shape=86.39455782312925: Hypothesis 13: spell b0 as (i & 1) != 0 instead of == 1; tests whether equivalent nonzero comparison is the period source form behind the original byte-test lowering.
probe 20 liveness; result=MISMATCH; diff=338; shape=96.875: Hypothesis 14: scope the eight bit locals inside each 0x100 loop, allowing VC5 to reuse homes across non-overlapping passes; tests whether the original stack permutation comes from block scope rather than function scope.
probe 21 abi; result=MISMATCH; diff=457; shape=88.19444444444444: Hypothesis 15: narrow only first-pass b0,b1,b2 to bool while keeping later bit locals dword; tests whether their source type yields the original EDX byte-result path.
probe 23 liveness; result=MISMATCH; diff=338; shape=96.875: Hypothesis 16: scope the validity flag ok inside the first edge-number loop as well; tests whether its short lifetime frees the original EDI/EDX register topology. [same emitted code as probe 20]
probe 24 layout; result=MISMATCH; diff=453; shape=98.26989619377163: Hypothesis 17: combine the scope-local bit reconstruction with the direct serialized black-root offset loop; tests whether the natural loop and corrected stack liveness jointly recover the full black-table block.
probe 25 control-flow; result=MISMATCH; diff=338; shape=96.875: Hypothesis 18: use a typed do-while root relocation with explicit i and black_roots updates; tests whether original do-loop rotation, not pointer type, controls the black root block. [same emitted code as probe 23]
probe 26 control-flow; result=MISMATCH; diff=338; shape=96.875: Hypothesis 19: express each edge validity predicate as nested outer-bit and inner-neighbor guards; tests whether the original branch topology comes from explicit nested ifs rather than && short-circuit syntax. [same emitted code as probe 25]
probe 27 liveness; result=MISMATCH; diff=338; shape=96.875: Hypothesis 20: declare the EdgeNumber pointer with the other function locals and assign it at first use, matching the decompiler's long-lived puVar11 lifetime; tests declaration placement effects on the bit-loop register map. [same emitted code as probe 26]
probe 28 liveness; result=MISMATCH; diff=338; shape=96.875: Hypothesis 21: split first-pass bit-local declarations into separate statements; tests whether VC5 declaration statement grouping affects EDX/ECX allocation while preserving block scope. [same emitted code as probe 27]
probe 29 control-flow; result=MISMATCH; diff=338; shape=96.875: Hypothesis 22: model both edge-number passes as explicit do-while loops, matching the decompiler's loop rotation and original body-first CFG. [same emitted code as probe 28]
probe 33 layout; result=MISMATCH; diff=453; shape=98.26989619377163: Hypothesis 1: duplicate the first file's signed byte-offset root relocation for Black_Edge_Tables; tests whether both global table publications use the same period loop shape. [same emitted code as probe 24]
probe 35 layout; result=MISMATCH; diff=469; shape=96.52777777777777: Hypothesis 2: keep a typed Black_Edge_Tables alias live across publication and member relocation; tests whether the original black base reload is source-alias driven.
probe 38 layout; result=MISMATCH; diff=481; shape=98.26388888888889: Hypothesis 3: use a typed black-table alias with the raw 0x44-byte relocation loop and reuse it for table reads; tests the decompiler-proven root alias without a count-reduced walk.
probe 40 layout; result=MISMATCH; diff=481; shape=98.26388888888889: Hypothesis 4: materialize the black relocation cursor as a typed int pointer each iteration, matching the binary's int* root owner and preserving the published root order. [same emitted code as probe 38]
probe 42 layout; result=MISMATCH; diff=449; shape=98.61111111111111: Hypothesis 5: reload Black_Edge_Tables as the direct address and relocation base in each root statement; tests whether direct member use preserves the original loop's field reload and address order.
probe 44 control-flow; result=MISMATCH; diff=455; shape=98.96551724137932: Hypothesis 6: use a body-first relocation loop with a named int cursor and post-address offset increment; tests the original root loop's address-before-increment schedule and bounds.
probe 46 layout; result=MISMATCH; diff=453; shape=98.26989619377163: Hypothesis 7: combine direct Black_Edge_Tables addressing with the named signed base local; tests the original field-reload order while keeping the relocation base live in its period register. [same emitted code as probe 33]
probe 49 layout; result=MISMATCH; diff=455; shape=98.96551724137932: Hypothesis 8: scope the int relocation cursor inside the black root loop and update the offset before the dereference; tests source scope and evaluation order against the original address schedule. [same emitted code as probe 44]
probe 52 abi; result=MISMATCH; diff=453; shape=98.26989619377163: Hypothesis 9: cast the black root publication through the proven eight-byte fog-table pointer surface; diagnostic only, tests whether pointer-table element type selects the original relocation lowering. [same emitted code as probe 46]
probe 54 abi; result=MISMATCH; diff=338; shape=96.875: Hypothesis 10: model the black root publication field as int** while retaining typed black records; diagnostic width/ownership test against the proven dword serialized roots. [same emitted code as probe 32]
probe 56 abi; result=MISMATCH; diff=338; shape=96.875: Hypothesis 11: restore the PDB/Ghidra protected member access so the decorated owner is IAEX, while keeping the clean typed-table reconstruction unchanged. [same emitted code as probe 54]
probe 57 layout; result=MISMATCH; diff=453; shape=98.26989619377163: Hypothesis 12: retain the black publication base as a typed pointer alias and use its integer conversion in the raw root loop; tests the original pointer-alias provenance without changing table ownership. [same emitted code as probe 52]
probe 60 layout; result=MISMATCH; diff=453; shape=98.26989619377163: Hypothesis 1: restore the binary-shaped 0x44-byte black root relocation loop, matching the already exact fog root pass, to test the first structural hunk without changing later table or edge logic. [same emitted code as probe 57]
probe 62 layout; result=MISMATCH; diff=453; shape=98.26989619377163: Hypothesis 2: keep the function-scope black root alias declaration but use the binary-shaped 0x44-byte dword relocation expression, testing declaration liveness separately from root-loop ownership. [same emitted code as probe 60]
probe 64 abi; result=MISMATCH; diff=338; shape=96.875: Hypothesis 3: use the reviewed eight-byte fog-table pointer surface for the black publication field while retaining black record access, testing whether the field's pointer type selects the original raw relocation schedule. [same emitted code as probe 59]
probe 66 layout; result=MISMATCH; diff=455; shape=98.96551724137932: Hypothesis 4: express each serialized black root relocation through scoped pointer and value locals, testing whether explicit load/add/store sequencing recovers the original byte-offset loop while limiting liveness.
probe 68 layout; result=MISMATCH; diff=455; shape=98.96551724137932: Hypothesis 5: bind each serialized black root dword to a scoped C++ reference before the RMW, testing whether proven lvalue ownership preserves the original address-before-load schedule without volatility. [same emitted code as probe 66]
probe 70 abi; result=MISMATCH; diff=338; shape=96.875: Hypothesis 6: represent the published black file image as a byte-addressed writable buffer and cast only proven root and record views, testing whether raw serialized ownership selects the original relocation lowering. [same emitted code as probe 64]
probe 72 layout; result=MISMATCH; diff=450; shape=99.65277777777777: Hypothesis 7: keep a typed black-table alias only for the inner records while the root pass rereads the published field with the proven dword loop, testing base provenance and later register coloring as separate concerns.
probe 73 liveness; result=MISMATCH; diff=450; shape=99.65277777777777: Hypothesis 8: split the serialized black root base from the later black-record relocation base, testing whether a natural phase-local value restores the original ESI base while retaining the newly exact root layout. [same emitted code as probe 72]
probe 75 layout; result=MISMATCH; diff=453; shape=98.26989619377163: Hypothesis 9: retain an explicit black publication alias but reload the published field for both raw roots and typed records, testing whether alias declaration alone changes the raw root register basin while preserving publication fault order. [same emitted code as probe 62]
probe 77 abi; result=MISMATCH; diff=450; shape=99.65277777777777: Hypothesis 10: keep the black publication typed as black records but use a distinct fog-pointer alias for the raw root and record address base, testing whether incompatible local pointer types preserve separate ESI and EDX loads. [same emitted code as probe 73]
probe 79 liveness; result=MISMATCH; diff=338; shape=96.875: Hypothesis 11: scope the typed black root cursor inside the successful black-file arm, testing whether the root cursor lifetime is the remaining source-level frame and register distinction. [same emitted code as probe 70]
probe 81 liveness; result=MISMATCH; diff=450; shape=99.65277777777777: Hypothesis 12: assign the integer relocation base before the typed black-table alias, then use the alias only for records, testing whether source order preserves separate base and publication registers for the near-exact raw-root basin. [same emitted code as probe 77]
probe 83 liveness; result=MISMATCH; diff=338; shape=96.875: Hypothesis 13: fetch the black table alias through a local RGE_View receiver after saving the integer base, testing whether an explicit receiver read prevents VC5 alias coalescing without changing the published owner. [same emitted code as probe 79]
```
<!-- end-recovered:680b384f5b6ae57e29f8 -->

<!-- recovered:b9f80da39af5aba86f07 -->
### `84eff22b9de5` `src/scratch/00533AF0_Init_Tile_Edge_Tables.cpp:1-38`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00533AF0 RGE_View::Init_Tile_Edge_Tables()
// Attempt log:
// 1: initial raw-offset reconstruction from the packet; call set and frame match.
// 2: typed table ownership and the two file-load/relocation passes are now the
//    living reconstruction. The downloaded pointer values are file-relative,
//    so the small integer relocation loop is required by the data format.
// 3: direct typed fields and indexed table roots introduced division and a
//    large prologue/layout drift; rolled back.
// 4: typed record members with fixed byte-offset roots preserved the 806-byte
//    basin (453 positional bytes, 133 edit bytes, 92.73% shape).
// 5: a scoped black-table alias reached the original 799-byte size but changed
//    liveness and raised positional drift to 481 bytes; rolled back.
// 6: reading through that alias worsened the second file block to 529 bytes;
//    rolled back.
// 7: a named black root-entry pointer changed the block shape but gave 455
//    positional bytes; rolled back as weaker than the typed baseline.
// 8: direct named RGE_View fields remained a 780-byte, 615-byte-diff basin;
//    restored the typed fixed-offset lvalues. No fake volatility or asm is used.
// 9: replaced the black serialized-root byte-offset loop with a typed
//    Tile_BlackEdge_Table** walk; the diff fell to 341 bytes and size to 800,
//    but the first structural hunk remains at the second relocation loop.
// 10: typed-base, do-while, separate-index, and array-index byte-offset
//     variants restored the original relocation block but stayed at 806 bytes
//     and 453-455 bytes; rolled back. The typed 0x11-root walk remains best.
// 11: Restored named file literals and RGE_View fields. The macro lvalues and
//     raw addresses were diagnostic forms, not living source ownership.
// 12: changed the edge predicate and bit locals to bool from the decompiler's
//     bool labels; VC5 expanded the frame to 0x24 and 930 bytes, so restored int
//     locals. The binary's dword homes are not source-level bool evidence here.
// 13-19: typed root indexing, scalar aliases, declaration order, address-add
//     spelling, width, comparison, and nested-guard variants did not improve
//     the typed root basin.
// 20: scoping the eight bit locals inside each edge pass recovered the original
//     dword homes and most late blocks. Best result is 800 bytes and 338 strict
//     changed bytes. The remaining structural hunk is the black-root relocation
//     loop, where the original uses a byte-offset lowering.
// 21-22: separate declaration statements and explicit do-while forms were
//     codegen duplicates. No policy-valid exact source was found in this pass.
```
<!-- end-recovered:b9f80da39af5aba86f07 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
