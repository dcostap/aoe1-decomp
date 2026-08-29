# Recovery journal: 004C5610 `check_object_bounds`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/stat_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\stat_obj.cpp`.
- Earlier recovery note: `recovery_notes/stat_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:1fbdb7a117d0a3fbaaff -->
### `d050eea3c` `src/stat_obj.cpp:2340-2341`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// 004C5610 RGE_Static_Object::check_object_bounds
// BINARY NOTE: The executable's final X overlap accepts less, equal, and
```
<!-- end-recovered:1fbdb7a117d0a3fbaaff -->

<!-- recovered:ffd68d004636dd09077f -->
### `target-session` `build/target_sessions/004C5610_check_object_bounds.json:1-69`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=507; shape=83.04093567251462: Restored proven absolute zero and DAT_00574748/4c constants from original FPU and coordinate instructions.
probe 2 context; result=MISMATCH; diff=507; shape=83.04093567251462: Made the proven absolute zero sentinel const to avoid an entry FPU load while retaining its 00574720 address. [same emitted code as probe 1]
probe 3 abi; result=MISMATCH; diff=102; shape=88.4393063583815: Tested an extern DAT_00574720 declaration to obtain VC5's direct absolute fcomp form.
probe 4 liveness; result=MISMATCH; diff=102; shape=88.4393063583815: Swapped x2/y2 declaration order to test the observed two-home assignment; all other source remained unchanged. [same emitted code as probe 3]
probe 5 control-flow; result=MISMATCH; diff=102; shape=88.4393063583815: Rewrote the outer y-range guard as an early failure before the do-loop, matching the original early fail and fall-through backedge topology. [same emitted code as probe 4]
probe 6 layout; result=MISMATCH; diff=102; shape=88.4393063583815: Tried natural x1/y1/x2/y2 declaration order to recover the original x2/y2 stack-home assignment. [same emitted code as probe 5]
probe 7 control-flow; result=MISMATCH; diff=102; shape=88.4393063583815: Split the compound overlap predicate into nested positive guards to test whether VC5 preserves the original second fcompp topology. [same emitted code as probe 6]
probe 8 behavior; result=MISMATCH; diff=112; shape=86.1271676300578: Reversed overlap comparison operands to test source-side fcompp and branch polarity recovery.
probe 9 behavior; result=MISMATCH; diff=191; shape=70.58823529411765: Swapped dx/dy absolute-value guard order while restoring direct overlap predicate; tested FPU stack scheduling.
probe 10 liveness; result=MISMATCH; diff=98; shape=92.98245614035088: Marked the spilled dx temporary volatile as a diagnostic to force the original second FPU reload/fcompp shape.
probe 11 behavior; result=MISMATCH; diff=98; shape=90.7514450867052: With volatile dx, reversed only the second overlap comparison to remove the extra fxch and recover test-ah,41 branch polarity.
probe 12 liveness; result=MISMATCH; diff=102; shape=88.4393063583815: Removed volatile and split dx declaration from assignment to test a natural source form for the observed reload. [same emitted code as probe 7]
probe 13 liveness; result=MISMATCH; diff=102; shape=88.4393063583815: Took a natural address of dx and used the alias to test whether VC5 reproduces the original spilled reload without volatile. [same emitted code as probe 12]
probe 14 control-flow; result=MISMATCH; diff=98; shape=92.98245614035088: Used a source label and explicit positive backedge to test recovery of the original jle outer-loop branch and fall-through zero return. [same emitted code as probe 10]
probe 15 behavior; result=MISMATCH; diff=98; shape=92.98245614035088: Tested negated strict second overlap comparison as an FPU branch-shape axis; it preserves ordinary finite-value behavior but may alter NaN semantics. [same emitted code as probe 14]
probe 16 layout; result=MISMATCH; diff=377; shape=72.51461988304094: Marked x2 volatile as a diagnostic for the original x2 stack-home assignment; this tests compiler liveness rather than behavior.
probe 17 control-flow; result=MISMATCH; diff=98; shape=92.98245614035088: With volatile dx retained, split the two overlap checks into nested guards to test whether source nesting removes the extra FPU exchange. [same emitted code as probe 15]
probe 18 control-flow; result=MISMATCH; diff=98; shape=92.98245614035088: Tested the equivalent negative overlap-failure form to seek original fcompp polarity and tail layout. [same emitted code as probe 17]
probe 23 control-flow; result=MISMATCH; diff=102; shape=88.4393063583815: Restored the binary-supported positive outer y_index <= y2 guard around the do-loop; tests whether VC5 emits the original direct jle backedge instead of the negative-guard jg+jmp pair. [same emitted code as probe 22]
probe 24 liveness; result=MISMATCH; diff=102; shape=88.4393063583815: Grouped the natural radius and bound declarations without changing ownership or control flow; tests whether VC5 declaration grouping selects the original x2/y2 spill-home colors. [same emitted code as probe 23]
probe 25 liveness; result=MISMATCH; diff=102; shape=88.4393063583815: Moved the four bounds into declarations with immediate initialization inside the positive-radius arm; tests whether original source initialization scope selects the x2/y2 home assignment. [same emitted code as probe 24]
probe 26 behavior; result=MISMATCH; diff=102; shape=88.4393063583815: Reversed only the x-overlap comparison to the binary fcompp operand direction while retaining the natural combined predicate; tests whether source operand order recovers the unordered-accepting x87 branch. [same emitted code as probe 25]
probe 27 behavior; result=MISMATCH; diff=102; shape=88.4393063583815: Rewrote the x-overlap test as !(dx > radius_sum), which is natural and preserves unordered acceptance; tests whether VC5 emits the original test-ah,41 fcompp branch rather than the finite-only <= lowering. [same emitted code as probe 26]
probe 28 liveness; result=MISMATCH; diff=102; shape=88.4393063583815: Declared dx before dy but retained the observed dy-then-dx assignments; tests whether original local declaration order drives the final x87 fcompp topology without metric-only volatility. [same emitted code as probe 27]
probe 29 control-flow; result=MISMATCH; diff=102; shape=88.4393063583815: Expressed overlap as an explicit failure OR with an empty arm and success else; tests whether inverse source branch layout yields the original fcompp/test-ah,41 topology without volatility. [same emitted code as probe 28]
probe 30 behavior; result=MISMATCH; diff=364; shape=84.61538461538461: Swapped the source initialization order of the second y2/x2 pair; tests whether the original home colors come from a non-obvious source order or whether the binary call order is source-fixed.
probe 32 control-flow; result=MISMATCH; diff=102; shape=88.4393063583815: Reconstructed the outer scan as a positive guard plus an infinite loop with an explicit post-increment break; tests whether the original direct jle backedge and fall-through zero return came from this source CFG. [same emitted code as probe 29]
probe 33 control-flow; result=MISMATCH; diff=102; shape=88.4393063583815: Used the Ghidra-supported explicit return 0 after the outer y_index increment instead of break; tests whether the original separate normal-zero and outer-failure epilogues require this source return. [same emitted code as probe 32]
probe 34 control-flow; result=MISMATCH; diff=102; shape=88.4393063583815: Inverted the post-increment condition to continue on y_index <= y2 and fall through to return 0; tests whether this source orientation directly emits the original jle backedge. [same emitted code as probe 33]
probe 35 context; result=MISMATCH; diff=102; shape=88.4393063583815: Changed the proven explicit vptr field to a minimal polymorphic class declaration; tests whether the original RGE_Static_Object virtual surface affects nonvirtual body block layout. [same emitted code as probe 34]
probe 39 behavior; result=MISMATCH; diff=102; shape=88.4393063583815: Split the final overlap conjunction into nested y and x guards without volatility; tests whether a separate x return branch preserves the original FCOMPP C0/C3 unordered-accepting lowering. [same emitted code as probe 38]
probe 41 behavior; result=MISMATCH; diff=102; shape=88.4393063583815: Reversed only the x-radius sum operand order to test whether VC5 chooses the original dx-first FCOMPP while preserving the typed traversal and four calls. [same emitted code as probe 39]
probe 43 behavior; result=MISMATCH; diff=209; shape=93.52941176470588: Expanded only the final x <= sum into strict-less-or-equal equality branches; tests whether explicit C0/C3 source predicates produce the original FCOMPP and unordered path.
probe 45 liveness; result=MISMATCH; diff=98; shape=92.98245614035088: Diagnostic only: made dx volatile to expose whether the original x87 stack pair is a hidden memory/liveness boundary; not a retained source form unless natural evidence supports it. [same emitted code as probe 18]
probe 47 behavior; result=MISMATCH; diff=102; shape=88.4393063583815: Added an explicit dx != dx unordered acceptance beside the natural x <= sum; tests whether compiler-visible NaN handling selects the original FCOMPP C0/C3 branch. [same emitted code as probe 41]
probe 49 context; result=MISMATCH; diff=237; shape=69.23076923076923: Enabled VC5 improve-floating-point-consistency pragma for only this function; tests whether original final FCOMPP operand order came from a precision/codegen context rather than source structure.
probe 50 control-flow; result=MISMATCH; diff=237; shape=69.23076923076923: Rewrote the overlap success as two explicit failure gotos to the typed node advance; tests whether the original fall-through FCOMPP branch came from source label topology. [same emitted code as probe 49]
probe 52 behavior; result=MISMATCH; diff=102; shape=88.4393063583815: Reversed both final radius-sum operands to mirror a possible original source term order; tests whether source tree order selects the target x87 stack topology. [same emitted code as probe 47]
probe 54 control-flow; result=MISMATCH; diff=102; shape=88.4393063583815: Retested explicit two failure gotos from the clean default-flag source; distinguishes source label topology from the earlier accidental pragma context. [same emitted code as probe 52]
probe 57 baseline; result=MISMATCH; diff=43; shape=91.27906976744185: Baseline the named X-limit source. It preserves unordered x87 acceptance and reduces the strict mismatch to 43 bytes.
probe 58 liveness; result=MISMATCH; diff=43; shape=91.27906976744185: Declare y2 before x2 while retaining PDB evaluation order. This tests whether declaration order controls the swapped bound homes. [same emitted code as probe 57]
probe 60 liveness; result=MISMATCH; diff=43; shape=91.27906976744185: Transpose the two upper-bound variable identities while keeping X/Y values and uses unchanged. This tests whether the binary homes follow source variable identity. [same emitted code as probe 58]
probe 62 variant; result=MISMATCH; diff=43; shape=91.27906976744185: variant lab build\variant_lab\004C5610_check_object_bounds\20260823_170129: 6 variants, 6 invariant-eligible, 0 exact
probe 63 control-flow; result=MISMATCH; diff=44; shape=91.27906976744185: Combine the named X limit with the PDB/Ghidra outer infinite loop and explicit post-increment zero return. This targets the missing normal-zero epilogue.
probe 65 variant; result=MISMATCH; diff=44; shape=91.27906976744185: variant lab build\variant_lab\004C5610_check_object_bounds\20260823_170236: 4 variants, 4 invariant-eligible, 0 exact
probe 66 variant; result=MISMATCH; diff=44; shape=91.27906976744185: variant lab build\variant_lab\004C5610_check_object_bounds\20260823_170345: 8 variants, 8 invariant-eligible, 0 exact
probe 67 variant; result=MISMATCH; diff=44; shape=91.27906976744185: variant lab build\variant_lab\004C5610_check_object_bounds\20260823_170414: 3 variants, 3 invariant-eligible, 0 exact
probe 68 variant; result=MISMATCH; diff=44; shape=91.27906976744185: variant lab build\variant_lab\004C5610_check_object_bounds\20260823_170429: 4 variants, 4 invariant-eligible, 0 exact
probe 69 variant; result=MISMATCH; diff=44; shape=91.27906976744185: variant lab build\variant_lab\004C5610_check_object_bounds\20260823_170458: 5 variants, 4 invariant-eligible, 0 exact
probe 70 variant; result=MISMATCH; diff=44; shape=91.27906976744185: variant lab build\variant_lab\004C5610_check_object_bounds\20260823_170509: 144 variants, 100 invariant-eligible, 0 exact
probe 71 control-flow; result=MISMATCH; diff=43; shape=91.27906976744185: Use the binary-proved row-backedge label with a fall-through zero return. This tests the original near JLE and dedicated normal-zero epilogue. [same emitted code as probe 60]
probe 73 control-flow; result=MISMATCH; diff=43; shape=91.27906976744185: Add the distinct positive-radius scan-failure return before the outer fallback return. This tests the executable's separate normal-zero epilogue. [same emitted code as probe 71]
probe 75 variant; result=MISMATCH; diff=43; shape=91.27906976744185: variant lab build\variant_lab\004C5610_check_object_bounds\20260823_170653: 4 variants, 4 invariant-eligible, 0 exact
probe 76 liveness; result=MISMATCH; diff=98; shape=92.98245614035088: Combine the diagnostic volatile dx home with the named unordered-safe X limit. This tests whether their independent x87 improvements interact. [same emitted code as probe 45]
probe 78 liveness; result=MISMATCH; diff=142; shape=84.88372093023256: Make only dy volatile as a diagnostic. This tests whether a neighboring addressable delta selects the original bound homes without changing X unordered handling.
probe 80 variant; result=MISMATCH; diff=142; shape=84.88372093023256: variant lab build\variant_lab\004C5610_check_object_bounds\20260823_170807: 3 variants, 3 invariant-eligible, 0 exact
probe 82 liveness; result=MISMATCH; diff=43; shape=91.27906976744185: Scope x2 and y2 to the positive-radius arm with declaration-time initialization. This tests the PDB line-local upper bounds against the named X-limit basin. [same emitted code as probe 73]
probe 84 layout; result=MISMATCH; diff=413; shape=81.06508875739645: Use the PDB-listed y_index as the initial Y bound and loop counter. The original PDB has no y1 local, so the prior copy was not canonical.
probe 86 variant; result=MISMATCH; diff=413; shape=81.06508875739645: variant lab build\variant_lab\004C5610_check_object_bounds\20260823_171102: 5 variants, 5 invariant-eligible, 0 exact
probe 89 liveness; result=MISMATCH; diff=362; shape=86.3905325443787: Scope y_index to the validated y-range arm after the early guard. Test whether VC5 allocates the original x2/y2 stack homes without changing the x87 or map source.
probe 91 liveness; result=MISMATCH; diff=43; shape=92.89940828402366: Compile the corrected first-assignment coordinate declarations with y_index scoped to the same arm. The hypothesis targets original upper-bound stack-home coloring.
probe 93 liveness; result=MISMATCH; diff=43; shape=92.89940828402366: Test x2/y2 declarations before x1/y1 with unchanged coordinate evaluation, clamps, and loop use. This isolates declaration-order register and stack coloring. [same emitted code as probe 91]
probe 95 control-flow; result=MISMATCH; diff=43; shape=92.89940828402366: Use a binary-supported found label with a local result assigned only on overlap, then place the found return after the normal zero return. Test natural CFG placement for the original late success tail. [same emitted code as probe 93]
probe 98 control-flow; result=MISMATCH; diff=499; shape=86.3905325443787: Use one initialized result pointer and a common done label for both overlap and zero paths. This tests whether a period-natural break/result model produces the original late success block and direct near backedge.
probe 100 control-flow; result=MISMATCH; diff=102; shape=90.53254437869822: Inline the x overlap bound inside the dy guard while retaining the unordered-safe negated comparison. Test whether the original late success block is tied to the natural combined predicate rather than the named limit.
probe 102 control-flow; result=MISMATCH; diff=43; shape=92.89940828402366: Express the proven outer scan as an infinite loop with explicit positive continue and fall-through break. This tests whether VC5 emits the original direct near JLE and late success block. [same emitted code as probe 97]
probe 103 control-flow; result=MISMATCH; diff=43; shape=92.89940828402366: Use the PDB-aligned explicit outer_loop label and positive post-increment goto from the older stat_obj reconstruction. Test direct near-backedge and late success block placement without volatile steering. [same emitted code as probe 102]
probe 104 liveness; result=MISMATCH; diff=43; shape=92.89940828402366: Apply period-plausible register qualifiers to both mutable upper bounds. Test the compiler's register-color hint for the original x2/y2 home permutation without volatile memory effects. [same emitted code as probe 103]
probe 105 context; result=MISMATCH; diff=43; shape=92.89940828402366: Apply only the authentic target line number 2780 without changing the source file identity. Test VC5 line-based layout ranking as a TU-context lead. [same emitted code as probe 104]
```
<!-- end-recovered:ffd68d004636dd09077f -->

<!-- recovered:550e73a0d0aacd3e4e16 -->
### `0b3aa46fe5b9` `src/scratch/004C5610_check_object_bounds.cpp:1-79`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C5610 RGE_Static_Object::check_object_bounds
// Attempt log:
// 1: natural typed reconstruction from packet/decompiler: correct size but 68.7% diff; early float compare used reversed constant-load form and coord names swapped.
// 2: changed float compare spelling to `rx > 0.0f` and fixed x/y clamp names; first mismatch moved to stack-slot offsets, diff improved to 55.9%.
// 3: reordered local declarations to mirror Ghidra stack names; no codegen change.
// 4: inverted top-level radius test with `!(<= && <=)`; no codegen change.
// 5: added dummy local assignment to try stack slot shift; optimized away/no codegen change.
// 6: tried /GX; unchanged.
// 7: tried /O2 without /Oy; unchanged.
// 8: fixed overlap predicate to `dy <= ry+ry2` per decompiler/original branch sense; behavior fix, only tiny edit-diff improvement.
// 9: current best same-size 524 B, first mismatch at initial radius stack slots: original stores rx/ry at [esp+24]/[esp+1C], rebuilt at [esp+28]/[esp+20]. Later FPU/control-flow broadly close but shifted stack-slot topology cascades.
// 10: left in scratch: behavior/call surface understood, but remaining 55.9% positional diff is too broad for accepted_drift.
// 11: typed row/tile traversal with a short outer-row index recovered exact
// map setup, 0x2C frame, and 71.6% exact-block coverage; remaining drift is
// the x2/y2 spill-home swap and late return-compare block shape.
// 12: equivalent x-overlap operand reversal was a codegen duplicate; restored
// the direct `dx <= rx + rx2` spelling for source clarity.
// 13: adopted the same-TU make_object_bounds_list donor's named radius,
// bound-local order, and positive overlap arithmetic; codegen was unchanged,
// so the donor-backed natural source is retained.
// 14: reversed the typed x-overlap predicate to test the original fcompp
// branch shape; emitted code was unchanged, so the clean predicate is kept.
// 15: declared the natural outer y_index temp before y2 to test the first
// spill-home topology; emitted code was unchanged, so the clean order is kept.
// 16: named the x-overlap sum before the final comparison to test a derived
// bound matching the original fcompp; rebuilt 524 B with diff 120, so restored
// the clean direct predicate.
// 17: absolute zero and the 3/-3 coordinate constants are required for the
// original memory operands; the extern declarations preserve that context.
// 18: volatile dx recovered one stack reload and improved the diagnostic to
// 98 bytes, but added an FPU exchange and was rejected as metric-only steering.
// 19: final clean source restores nonvolatile dx, direct overlap arithmetic,
// and the early y-range failure. Validation remains a 524-byte mismatch.
// 20: positive y-range guard was codegen-equivalent to the early failure form.
// 21: grouped declarations and declaration-time bound initialization were
// codegen-equivalent; x2/y2 homes remained swapped.
// 22: x-overlap operand reversal, !(dx > limit), and explicit failure-OR
// forms were codegen-equivalent; none recovered the original fcompp.
// 23: declaring dx before dy while keeping dy-then-dx evaluation was a
// codegen duplicate. Reversing the second y2/x2 initialization pair worsened
// size and call scheduling, so the original order was restored.
// 24: positive guard plus infinite outer loop, explicit post-increment return,
// and inverted continue forms were all codegen-equivalent to the clean loop.
// 25: a minimal polymorphic RGE_Static_Object declaration was a codegen
// duplicate; the explicit vptr field remains the smaller local surface.
// BINARY NOTE: The executable's final X overlap accepts less, equal, and
// unordered x87 results. The named X limit preserves that shipped NaN behavior.
// TU context audit: same-module stat_obj.cpp owners were tested in address order.
// No tested authentic nearest-one or cumulative multi-owner prefix compiled
// with this standalone class surface. Padding-only owners were excluded. No
// context change is validated.
// Resume audit: build/stat_obj_context_r2.h compiles the smallest shared
// surface with real owners 004C1CF0-004C23F0 in PDB order, plus this body.
// /GX is required for the real allocation owners. The target remains 524 B.
// The named X limit reduces the strict difference from 102 to 43 bytes. The
// rebuilt final X predicate now matches the executable through FCOMPP and the
// C0-or-C3 status test. The first later normal owner, 004C2970,
// is blocked by missing TDrawArea/ScreenPoint/Win32 drawing surfaces. No
// config change was made. Earlier x2/y2 spill homes and the final loop exit
// shape remain unresolved.
// Continuation audit:
// - Original DIA locals prove nonvolatile float dx at entry ESP-0x2C, short
//   x2 at -0x14, short y2 at -0x10, and short y_index at -0x0C.
// - Declaration order, function scope, register hints, casts, named temporary
//   assignments, map/traversal scope, and debug flags reproduced one 43-byte
//   basin. These forms do not control the two upper-bound homes.
// - Volatile dx selects the original x2/y2 homes. It also adds a false x87
//   exchange at the final X test. DIA proves dx is not volatile, so reject it.
// - Reusing y_index for the initial Y bound changed the complete frame use.
//   The omitted optimized y1 PDB record does not prove source-variable reuse.
// - Separate row-failure returns and binary-shaped labels tail-merge to the
//   same late CFG. The remaining 43 bytes need a natural liveness or context
//   fact that selects both the original homes and the direct near backedge.
// Exact-finish audit:
// - Scoped and declaration-initialized bounds changed size or block shape;
//   reordered bounds did not change their homes.
// - Found labels, explicit outer-loop labels, positive continue forms,
//   register hints, and the authentic target line number did not change code.
// - The clean source remains the smallest tested natural reconstruction.
```
<!-- end-recovered:550e73a0d0aacd3e4e16 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
