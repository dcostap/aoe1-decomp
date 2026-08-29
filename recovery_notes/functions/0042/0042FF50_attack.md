# Recovery journal: 0042FF50 `attack`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/com_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\com_obj.cpp`.
- Earlier recovery note: `recovery_notes/com_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:f335c4f5811e090e73f6 -->
### `target-session` `build/target_sessions/0042FF50_attack.json:1-43`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=366; shape=76.66666666666667: Current clean named-radius natural source from prior pause; establish baseline metrics and call alignment.
probe 2 liveness; result=MISMATCH; diff=373; shape=78.0: Removed the named sine local; original Ghidra exposes only c while sine stays on x87, so direct sin calls test the proven stack shape.
probe 4 liveness; result=MISMATCH; diff=366; shape=76.66666666666667: Inline range expression in init_missile: 378-byte rebuilt code, 385 strict diff, EBP frame; worse than clean 392/366. Discarded.
probe 5 control-flow; result=MISMATCH; diff=366; shape=76.66666666666667: Negative missile-id source branch emitted fallback first, 390-byte code, 368 strict diff, calls misaligned 6/7. Discarded.
probe 6 liveness; result=MISMATCH; diff=366; shape=76.66666666666667: Explicit late fallback goto emitted same 390-byte/368-diff basin as negative branch. Discarded.
probe 7 liveness; result=MISMATCH; diff=366; shape=76.66666666666667: Self pointer alias emitted the clean 392-byte/366-diff artifact unchanged. No source benefit.
probe 8 liveness; result=MISMATCH; diff=366; shape=76.66666666666667: Split range assignment improved size to 400 bytes and shape to 78%, but strict diff worsened to 367. Discarded.
probe 9 liveness; result=MISMATCH; diff=366; shape=76.66666666666667: Block-local initialized c/s/range, separate missile declaration, c-only scope split, and direct radius members all duplicated the clean 392-byte/366-diff basin. Discarded.
probe 11 liveness; result=MISMATCH; diff=372; shape=72.66666666666667: Split range into sqrt assignment, weapon-range addition, and global subtraction to test whether original reloads the x87 range or changes coordinate scheduling.
probe 13 liveness; result=MISMATCH; diff=366; shape=76.66666666666667: Swap natural c/s declaration order while retaining the proven expression order, testing x87 local-home and late EBX scheduling. [same emitted code as probe 10]
probe 15 liveness; result=MISMATCH; diff=366; shape=76.66666666666667: Remove the named missile-id local and use direct typed member indexing to test whether VC5 shrink-wraps EBX when the ID is not live across the branch. [same emitted code as probe 13]
probe 17 liveness; result=MISMATCH; diff=366; shape=73.50993377483444: Swap natural radius local declarations while keeping radius_x-squared plus radius_y-squared semantics, testing the observed radius_y-first x87 setup.
probe 19 abi; result=MISMATCH; diff=366; shape=76.66666666666667: Use a typed missile return from the proven virtual factory instead of a static-object return plus cast, testing whether return ownership changes register preservation without changing calls. [same emitted code as probe 15]
probe 21 liveness; result=MISMATCH; diff=366; shape=76.66666666666667: Compute the typed radius range before c and s, testing source statement order against the original interleaved x87 setup. [same emitted code as probe 19]
probe 23 liveness; result=MISMATCH; diff=366; shape=78.0: Name the typed sqrt radius before adding weapon range and the global constant, testing whether the original late sqrt home is a real local.
probe 24 liveness; result=MISMATCH; diff=374; shape=76.66666666666667: Keep a named typed radius but reverse the square-term source order, testing radius expression ownership against the observed x87 operand order.
probe 26 liveness; result=MISMATCH; diff=369; shape=78.66666666666667: Name typed x, y, and z coordinate temporaries before the factory call to test whether the original local_14/local_18/local_1c homes are source locals.
probe 27 liveness; result=MISMATCH; diff=375; shape=74.66666666666667: Mirror the typed sibling attack source order: radius_y/radius_x range, duplicated angle locals, owner and factory-entry locals, then s and coordinate locals.
probe 29 liveness; result=MISMATCH; diff=366; shape=76.66666666666667: Use const typed c, s, and range locals within the missile arm to test whether immutable values force the original FPU reload pattern. [same emitted code as probe 21]
probe 31 liveness; result=MISMATCH; diff=366; shape=76.66666666666667: Name the first notification target ID and reuse it only for that typed call, testing natural argument-load register selection. [same emitted code as probe 29]
probe 33 abi; result=MISMATCH; diff=367; shape=66.0: Remove redundant float casts around intrinsic cos, sin, and sqrt while preserving typed destinations, testing the old math header overload basin.
probe 35 abi; result=MISMATCH; diff=367; shape=66.0: Remove only the sqrt float cast while retaining proven trig casts, isolating the old math ABI effect. [same emitted code as probe 33]
probe 37 abi; result=MISMATCH; diff=366; shape=76.66666666666667: Declare the proven read-only global constants as const, testing whether VC5 uses a different load and x87 scheduling basin.
probe 40 control-flow; result=MISMATCH; diff=368; shape=66.01307189542484: Invert missile-id guard to the decompiler-proven negative early fallback, testing shrink-wrapped EBX and original entry push-ecx shape.
probe 42 abi; result=MISMATCH; diff=390; shape=77.77777777777777: Pass this as the fallback attack's third argument, matching the original [esp+20] load after the saved entry ECX rather than the named other home.
probe 43 control-flow; result=MISMATCH; diff=390; shape=77.77777777777777: Use a positive missile arm with its own return and a following fallback statement, matching the original late fallback block and duplicated return tails without a source else. [same emitted code as probe 42]
probe 45 abi; result=MISMATCH; diff=366; shape=76.66666666666667: Declare the target/object overload virtual in its proven vtable order after the float overload, testing canonical symbol and body effects.
probe 47 liveness; result=MISMATCH; diff=366; shape=76.66666666666667: Scope c, s, and range inside the missile arm, matching their use after the missile-id guard and testing entry stack-home allocation. [same emitted code as probe 39]
probe 49 liveness; result=MISMATCH; diff=366; shape=75.33333333333333: Reverse radius declaration and square-term order to mirror sibling com_obj.cpp attack's radius_y-first source and original fld/mov order.
probe 51 liveness; result=MISMATCH; diff=385; shape=68.0: Inline the proven sqrt radius plus weapon-range expression at init_missile, matching the decompiler's absent range local and testing argument evaluation scheduling.
probe 54 liveness; result=MISMATCH; diff=366; shape=76.66666666666667: Hoist radius_x and radius_y declarations to function scope while keeping assignments in the missile arm, testing whether original target-home reuse and late EBX save depend on their lifetimes. [same emitted code as probe 53]
probe 56 liveness; result=MISMATCH; diff=366; shape=76.66666666666667: Swap the function-scope c and s declaration order without changing evaluation order, testing whether the original x87 temporary-home rotation depends on declaration order. [same emitted code as probe 54]
probe 58 other; result=MISMATCH; diff=366; shape=68.66666666666667: Parenthesize weapon_range minus DAT_0056f4ac inside the range sum, testing whether the original fadd/fsub x87 grouping comes from a source grouping boundary.
probe 61 liveness; result=MISMATCH; diff=360; shape=72.0: Mirror the sibling com_obj.cpp angle1/angle2, owner, and factory-entry lifetimes without introducing coordinate locals, testing whether the original trig/factory interleave needs those natural aliases.
probe 63 liveness; result=MISMATCH; diff=361; shape=73.33333333333333: Keep the baseline radius-before-trig and range-after-trig order, but name angle1/angle2 and cache owner/entry between cosine and sine, isolating alias lifetime from the prior full sibling form.
probe 65 other; result=MISMATCH; diff=366; shape=82.0: Parenthesize the x and y offset sums while preserving operand order, testing whether source grouping controls the original x87 coordinate stack topology.
probe 67 other; result=MISMATCH; diff=370; shape=79.33333333333333: Parenthesize only the x offset subtraction, leaving y left-associative, to isolate which coordinate grouping drives the improved x87 topology.
probe 69 other; result=MISMATCH; diff=355; shape=77.33333333333333: Parenthesize only the y offset sum, leaving x left-associative, to isolate the second coordinate grouping effect.
probe 71 liveness; result=MISMATCH; diff=374; shape=78.66666666666667: Remove the named sine local and reuse direct sin(angle) expressions, with the y offset still grouped, testing the decompiler's unmapped-s hypothesis and target-home reuse.
probe 73 liveness; result=MISMATCH; diff=385; shape=68.0: Inline the natural radius and weapon-range expression into init_missile while grouping only the y offset sum, testing whether the decompiler's missing range local and y87 topology interact. [same emitted code as probe 51]
probe 75 liveness; result=MISMATCH; diff=366; shape=75.33333333333333: Combine the productive y-offset grouping with radius_y-first declaration and square-term order, testing whether sibling math order unlocks the original fld/mov/x87 basin. [same emitted code as probe 49]
probe 77 liveness; result=MISMATCH; diff=355; shape=77.33333333333333: Keep c function-scope but make s and range missile-arm locals, with the productive y offset grouping, testing the decompiler's mapped-c versus unmapped-s lifetime split. [same emitted code as probe 69]
probe 80 abi; result=MISMATCH; diff=366; shape=76.66666666666667: FPO symbol requires virtual two-object attack overload; body remains scratch mismatch.
```
<!-- end-recovered:f335c4f5811e090e73f6 -->

<!-- recovered:519ebdcf5a74e0cbd08d -->
### `056a20c24f68` `src/scratch/0042FF50_attack.cpp:1-35`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0042FF50 RGE_Combat_Object::attack(RGE_Static_Object*, RGE_Combat_Object*)
// Source: com_obj.cpp lines 269-315
// attempt log:
// attempt 1: natural source from packet/decompiler; initial compile was 400B vs 407B so too small to extract.
// attempt 2: added Static_Object notify vtable surface at +0x148; fixed compile error for target notification.
// attempt 3: result local did not change codegen size or prologue.
// attempt 4: naming hp local and reversing comparisons made no size/codegen difference.
// attempt 5: volatile hp forced extractable size, but was artificial and produced broad mismatch (93.9% positional).
// attempt 6: fixed RGE_Player::objects offset from +0x20 to +0x24; corrects missile factory table load.
// attempt 7: introduced attacked local to try to keep target distinct from this/master; still 400B in natural form.
// attempt 8: changed missile-id branch to positive if (missile_id >= 0) with fallback in trailing else; matches original block order better.
// attempt 9: volatile-size diagnostic after branch reorder improved only to broad mismatch (87.96% positional); prologue still uses EBX/EBP, unlike original push-ecx/ESI/EDI then late EBX.
// attempt 10: reverted artificial volatile; left natural 400B scratch. Remaining blocker is source/register shape for target/master lifetimes plus x87 missile math interleave.
// session probes: canonicalized the missile factory to player->master_objects[]->make_new_obj, tested direct target/master ownership, block-scoped versus function-scoped locals, radius term order, and binary global constants.
// best emitted candidate: direct member source reaches 392B with all 7 calls aligned and 201-byte edit/resync drift; original still has a distinct x87 radius/trig schedule and shrink-wrapped EBX save.
// later probe: same-TU inherited Static/Animated/Moving/Action/Combat and Master_* surfaces plus the observed master hp notification argument produced 400B and 361 positional diff; retained as the best canonical source.
// later probes: named radius locals reproduced the original x87 block shape but not bytes; a named missile-master entry and an initialized c home were nonproductive or worse and were rolled back.
// current probe: passed the second attack parameter `other` to typed init_missile; this aligned the reload/push argument shape and improved structural similarity, but positional diff worsened by 10 bytes and size grew to 408B.
// orch-42FF50-a baseline: retained typed init_missile(this, target, range); the exact donor and original call values support this source ownership.
// orch-42FF50-a probes: hoisted c/s/range declarations (duplicate); named radius_x/radius_y with direct angle calls improved shape to 75.33% and diff 366B.
// orch-42FF50-a probe: reversed radius-square terms to match the original fld radius_y, mov radius_x, then x87 square order; shape improved to 76.67%, diff stayed 366B.
// orch-42FF50-a probe: inlined owner member (duplicate); marking the wrapper virtual changed the fallback call to vslot+22C and was reverted.
// orch-42FF50-a probe: naming a master local added EBP and widened drift to 386B; restored the named-radius source.
// orch-42FF50-a pause: source now keeps canonical fields, direct owner/member calls, and exact init_missile argument values. Remaining structural blocker is entry EBX save versus original late EBX save; all seven calls align.
// paused after bounded matching: no artificial volatility, aliases, raw offsets, or register-forcing scaffolding retained.
// worker sa-d0d31327: clean baseline rebuilt 392 effective bytes vs original 407, 366 strict diff, all 7 calls aligned.
// worker probes: inline range, negative/goto fallback, self alias, split range assignment, local declaration scopes, and direct radius members did not improve the natural basin; negative/goto also broke call order.
// worker conclusion: current exact blocker remains VC5 x87 expression scheduling plus late EBX save and entry push-ecx home; no artificial source steering retained.
// worker sa-86c22b60: rechecked typed range, radius, coordinate, factory, global, and declaration-order forms. Named radius and coordinate locals improved shape but worsened or preserved strict drift; sibling-style angle/owner aliases reached 407B but worsened drift. All seven calls stayed aligned.
// worker sa-86c22b60 conclusion: restored the pinned 392B natural source. The unresolved evidence remains the original late EBX save, entry push-ecx home, and x87 reload order.
// worker sa-7d40fde9 revisit: inverted missile-id control flow worsened to 390B/368B and broke call order; restored.
// worker sa-7d40fde9 revisit: passing this in the fallback improved shape but worsened to 390B; separate positive return was a codegen duplicate.
// worker sa-7d40fde9 revisit: virtualizing the target overload moved the fallback to vslot +0x22C; block-local c/s/range was a duplicate; radius_y-first terms worsened shape; inline range worsened to 378B/385B. Restored the pinned source.
// worker sa-c26e0e77: hoisting radius locals and swapping c/s declarations were codegen duplicates. Parenthesizing the y offset sum alone reached 396B/355 strict diff and 77.33% shape; the x-only form reached 400B/370, while both sums reached 396B/366. This is a useful x87 lead but remains unpinned because the asymmetric source grouping is not established by a donor.
// worker sa-c26e0e77: direct sine expressions and inline range were worse (398B/374 and 378B/385); radius_y-first with the y grouping reproduced the earlier 392B/366 basin. All probes kept seven ordered calls aligned. Clean source restored.
```
<!-- end-recovered:519ebdcf5a74e0cbd08d -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
