# Recovery journal: 0044E9E0 `setConnectionCount`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/infmap.cpp`.
- PDB source: `C:\msdev\work\age1_x1\infmap.cpp`.
- Earlier recovery note: `recovery_notes/infmap_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:5b56f137c933a39fb08a -->
### `6a2aef2e2` `src/infmap.cpp:426-426`

Mapping: `strong`. comment lies after mapped function setConnectionCount at old line 396.

```text
                            // VC5 merges this suffix with case 7.
```
<!-- end-recovered:5b56f137c933a39fb08a -->

<!-- recovered:012bf9c8a175c8fc009a -->
### `target-session` `build/target_sessions/0044E9E0_setConnectionCount.json:1-55`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=346; shape=84.6590909090909: Current clean typed source: 498-byte frame 0x24, no calls, 176 instructions; first mismatch saved-this home [esp+14] versus original [esp+10].
probe 2 liveness; result=MISMATCH; diff=346; shape=84.6590909090909: Swapped clean local declaration order: self before rowIndex/xOffset, testing original [esp+10] self and [esp+14] rowIndex ownership. [same emitted code as probe 1]
probe 4 liveness; result=MISMATCH; diff=346; shape=84.6590909090909: Swapped clean neighbor local declaration order to test original direction/neighborY register coloring without changing control flow. [same emitted code as probe 2]
probe 6 control-flow; result=MISMATCH; diff=346; shape=84.6590909090909: Changed only the eight-direction loop from for to natural do/while to test VC5 switch block placement and loop rotation.
probe 8 control-flow; result=MISMATCH; diff=353; shape=90.64327485380117: Reordered switch cases numerically and used one named common label for proven case-0/case-7 fallthrough; tests source-order-induced cold switch arms.
probe 9 liveness; result=MISMATCH; diff=353; shape=90.64327485380117: Common-label switch retained; permuted neighbor declaration order Y/X/row to recover original EBP direction and EDI/EBX/ESI neighbor coloring. [same emitted code as probe 8]
probe 10 liveness; result=MISMATCH; diff=353; shape=90.64327485380117: Common-label switch retained; permuted neighbor declaration order row/X/Y as second register-coloring test. [same emitted code as probe 9]
probe 11 liveness; result=MISMATCH; diff=353; shape=90.64327485380117: Common-label switch retained; hoisted direction declaration to function scope and initialized it at the inner-loop preheader. [same emitted code as probe 10]
probe 13 liveness; result=MISMATCH; diff=436; shape=73.71428571428571: Reordered inner-preheader declarations to read yReference before rows, testing original stack ownership of rows versus y-reference scale.
probe 15 liveness; result=MISMATCH; diff=346; shape=84.6590909090909: Moved rows/xReference/yReference declarations to function scope with assignment in the proven inner preheader, testing original rows stack lifetime. [same emitted code as probe 4]
probe 17 control-flow; result=MISMATCH; diff=346; shape=84.6590909090909: Added only a named common label for case 0 to case 7, while retaining the original source case order; tests whether explicit common control yields original cold arms.
probe 19 control-flow; result=MISMATCH; diff=353; shape=90.64327485380117: Numeric common-label switch plus separate neighbor declarations and assignments, testing whether explicit initialization restores original register coloring. [same emitted code as probe 11]
probe 22 liveness; result=MISMATCH; diff=346; shape=84.6590909090909: Moved rowIndex declaration into the proven inner preheader; tests whether original self and row-index stack homes follow source scope. [same emitted code as probe 21]
probe 23 liveness; result=MISMATCH; diff=346; shape=84.6590909090909: Initialized rowIndex at its inner-preheader declaration; tests original LEA and local-home timing without opaque compiler steering. [same emitted code as probe 22]
probe 24 liveness; result=MISMATCH; diff=355; shape=84.6590909090909: Moved the inner y declaration inside a direct from.y <= to.y guard; tests PDB-aligned load reuse and inner-preheader lifetime.
probe 26 liveness; result=MISMATCH; diff=346; shape=84.6590909090909: Removed the self alias and used direct this member expressions; tests the exact donor pattern for this-pointer spill timing.
probe 30 baseline; result=MISMATCH; diff=346; shape=84.6590909090909: Fresh baseline after ownership review: typed InfluenceMap fields and XYPoint reference ABI are supported; current clean source is 498-byte frame 0x24 but direction/row setup register topology differs. [same emitted code as probe 29]
probe 31 liveness; result=MISMATCH; diff=474; shape=83.05084745762711: Removed the inner yReference scalar and used direct field reads; tests whether original row setup keeps the y-reference multiply in a register instead of a local home.
probe 33 control-flow; result=MISMATCH; diff=346; shape=84.6590909090909: Converted the outer x for-loop to the binary-supported guarded do/while form; PDB line 405 owns both outer-entry and outer-update blocks, and Ghidra shows this rotation.
probe 35 liveness; result=MISMATCH; diff=346; shape=84.6590909090909: Moved neighbor coordinates, row cursor, and direction to function scope with inner-preheader assignments; tests the Ghidra-proven reused variable lifetimes rather than block-local declarations. [same emitted code as probe 30]
probe 37 liveness; result=MISMATCH; diff=346; shape=84.6590909090909: Hoisted the row-pointer local to function scope while keeping its assignment in the inner preheader; original stack local i persists through direction and outer-loop reloads. [same emitted code as probe 35]
probe 38 liveness; result=MISMATCH; diff=346; shape=84.6590909090909: Removed the xReference scalar and computed xOffset from the direct field; tests whether the original rows-first setup avoids the named xReference scheduling basin. [same emitted code as probe 26]
probe 40 liveness; result=MISMATCH; diff=474; shape=83.05084745762711: Combined direct y-reference field reads with a function-scope row pointer; tests the original stack pattern of rows plus this while keeping y-reference in a register. [same emitted code as probe 31]
probe 42 liveness; result=MISMATCH; diff=346; shape=84.6590909090909: Declared the self alias before rowIndex and xOffset; tests whether source declaration order assigns this to original [esp+10] and rowIndex to [esp+14]. [same emitted code as probe 37]
probe 43 liveness; result=MISMATCH; diff=367; shape=74.85714285714286: Cached to.y in a loop-local yEnd to release the to reference during the direction loop; this tests whether original EBP direction allocation comes from that lifetime choice.
probe 45 liveness; result=MISMATCH; diff=346; shape=84.6590909090909: Changed the self pointer alias to a reference alias and direct member syntax; tests whether VC5 assigns the saved this home from reference ownership rather than pointer liveness. [same emitted code as probe 42]
probe 47 liveness; result=MISMATCH; diff=346; shape=84.6590909090909: Hoisted y to function scope and assigned it at each outer iteration; Ghidra maps local_1c to a persistent stack home reused across the inner scan. [same emitted code as probe 45]
probe 49 liveness; result=MISMATCH; diff=346; shape=84.6590909090909: Removed the self alias and used direct this member expressions throughout; this is the donor-backed natural form and tests saved-this ownership without a local pointer. [same emitted code as probe 38]
probe 50 liveness; result=MISMATCH; diff=345; shape=84.0: Removed the rows alias and used direct this->rowValue indexing in both map reads; tests whether original rows stack home comes from a direct member expression.
probe 52 liveness; result=MISMATCH; diff=346; shape=84.6590909090909: Reordered inner-preheader source assignments so rowIndex initializes before xReference and xOffset; tests whether original LEA and field-load order follows Ghidra j initialization. [same emitted code as probe 47]
probe 54 control-flow; result=MISMATCH; diff=353; shape=90.64327485380117: Reordered switch labels and used one explicit diagonal label for case 0/7; tests whether original late common switch target is source-label-driven. [same emitted code as probe 19]
probe 57 baseline; result=MISMATCH; diff=346; shape=84.6590909090909: Fresh baseline in the PDB-authentic infmap.cpp owner context. The clean typed source preserves publication, bounds checks, row scans, and malformed-state fault behavior. [same emitted code as probe 56]
probe 58 control-flow; result=MISMATCH; diff=345; shape=91.2280701754386: Duplicated the case-0 y and row updates and kept case 7 as the final source arm. This tests natural VC5 common-tail merging supported by PDB lines 426 and 433.
probe 59 liveness; result=MISMATCH; diff=345; shape=91.2280701754386: Declared yReference at function scope but assigned it after xOffset. This tests the original long-lived ECX value while preserving the binary field-read order. [same emitted code as probe 58]
probe 60 layout; result=MISMATCH; diff=345; shape=91.2280701754386: Used direct typed rowValue expressions with the retained y-reference lifetime. This tests whether VC5 derives the original one-time row owner from member CSE after the natural switch merge.
probe 61 liveness; result=MISMATCH; diff=345; shape=91.2280701754386: Declared both rows and yReference at function scope but assigned them in the proven inner preheader. This tests which long-lived value VC5 keeps in ECX without changing read order. [same emitted code as probe 59]
probe 62 liveness; result=MISMATCH; diff=345; shape=91.2280701754386: Declared rowIndex with its initializer in the inner preheader. This tests whether a distinct scaled local keeps y intact and selects the original LEA instead of an in-place shift. [same emitted code as probe 61]
probe 63 context; result=MISMATCH; diff=354; shape=81.97674418604652: Moved row, reference, offset, and scaled-row declarations to the first inner-loop body statements. The exact same-TU setCoverageCount donor proves that VC5 hoists this source form into the preheader.
probe 64 context; result=MISMATCH; diff=418; shape=80.58823529411765: Moved only xOffset assignment to the first inner-loop body statement. The exact same-TU donor proves VC5 hoists this offset form while changing its source lifetime.
probe 65 liveness; result=MISMATCH; diff=345; shape=91.2280701754386: Assigned rowIndex after xOffset but before yReference. This follows the original rows, x-reference, scaled-row, then y-reference setup order without changing field reads. [same emitted code as probe 62]
probe 66 layout; result=MISMATCH; diff=482; shape=69.54022988505747: Used the binary-proven scaled row offsets in both typed row-pointer loads. This tests whether rowIndex and neighborRow are real source values rather than optimized shadow induction.
probe 67 variant; result=MISMATCH; diff=482; shape=69.54022988505747: variant lab build\variant_lab\0044E9E0_setConnectionCount\20260823_183249: 42 variants, 42 invariant-eligible, 0 exact
probe 68 context; result=MISMATCH; diff=418; shape=80.58823529411765: Declared xOffset as the first inner-loop body local while keeping its x-reference input in the preheader. This narrows the exact same-TU donor pattern without a function-scope offset. [same emitted code as probe 64]
probe 69 context; result=MISMATCH; diff=345; shape=91.2280701754386: Removed explicit rowIndex and neighborRow shadow induction. Typed row indexing already defines these scaled values, as the exact same-TU setCoverageCount donor proves.
probe 70 liveness; result=MISMATCH; diff=345; shape=91.2280701754386: Marked the read-only yReference local as register. This tests the binary-observed ECX lifetime against the competing row-pointer value without changing behavior or read order. [same emitted code as probe 69]
probe 71 liveness; result=MISMATCH; diff=345; shape=91.2280701754386: Declared xOffset in the inner preheader instead of function scope. This tests whether its block lifetime swaps the original self and scaled-row homes while preserving the exact setup phase. [same emitted code as probe 70]
probe 72 variant; result=MISMATCH; diff=345; shape=91.2280701754386: variant lab build\variant_lab\0044E9E0_setConnectionCount\20260823_183607: 4 variants, 4 invariant-eligible, 0 exact
probe 73 liveness; result=MISMATCH; diff=345; shape=91.2280701754386: Removed the xReference scalar and initialized xOffset directly after rows. This tests whether the named x-reference caused VC5 to load that field before the source-earlier row owner.
probe 74 context; result=MISMATCH; diff=402; shape=79.59183673469387: Restored the period CRT abs declaration and used abs(direction) parity, as the same-TU connectionsIncluding source family suggests. This tests the remaining register map after natural switch merging.
probe 76 layout; result=MISMATCH; diff=8; shape=94.67455621301775: Removed the yReference scalar and reread the typed y-reference member in both row expressions. Tests whether direct field ownership keeps the target scaled y-reference in ECX while preserving publication and validation order.
probe 77 liveness; result=MISMATCH; diff=8; shape=94.67455621301775: Removed the explicit self alias after direct y-reference rereads. Tests whether natural this ownership assigns the target self and row-offset homes without changing narrow field reads, malformed-count behavior, or switch anchors.
probe 78 liveness; result=MISMATCH; diff=8; shape=94.67455621301775: Changed the target receiver spelling to a natural reference alias while retaining direct y-reference rereads. Tests whether reference ownership changes VC5 stack-home order to the target without changing field or switch behavior. [same emitted code as probe 76]
probe 79 liveness; result=MISMATCH; diff=8; shape=94.67455621301775: Scoped the real self pointer to the validated scan while using direct this for publication and return. Tests whether alias lifetime changes the two stack homes without changing malformed-count fault order. [same emitted code as probe 78]
probe 80 liveness; result=MISMATCH; diff=8; shape=94.67455621301775: Reduced to the smallest typed form: natural self alias, rows before xOffset, direct y-reference rereads in both row accesses, and ordinary inner do/while. Direct field and alias variants all stay at the same 8-byte stack-home swap; the target keeps self at [esp+10h] and scaled row offset at [esp+14h], while VC5 emits the reverse. [same emitted code as probe 79]
probe 83 baseline; result=MISMATCH; diff=8; shape=94.67455621301775: Fresh standalone baseline for setConnectionCount before grouped repair. [same emitted code as probe 82]
```
<!-- end-recovered:012bf9c8a175c8fc009a -->

<!-- recovered:3bb5ed8b8d08a8fa2ef5 -->
### `c0c15a8201e7` `src/scratch/0044E9E0_setConnectionCount.cpp:1-83`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0044E9E0 InfluenceMap::setConnectionCount
// PDB: infmap.cpp:394-458, 498 bytes
// Attempt log:
// - baseline: reconstructed the row scan and eight-direction switch from the
//   executable, but used explicit gotos and raw row-address arithmetic.
// - natural typed reconstruction: named the complete InfluenceMap layout,
//   restored ordinary validation and loops, and kept the switch fall-through
//   effects shown by the original dispatch table.
// - hoisted xOffset and signed direction % 2 reproduce the 0x24 frame,
//   remainder sequence, and most switch block placement.
// - count-pointer, declaration-order, and virtual-surface probes did not move
//   codegen. Remaining drift starts at saved-this placement and local slots.
// - an explicit vfptr donor surface was codegen-neutral. Restored the natural
//   virtual class surface because raw vptr modeling adds no evidence.
// - donor declaration order with abs parity improved positional drift by 7
//   bytes but lost exact blocks; restored the cleaner signed-parity form.
// - fresh TU lead: hoisted direction to function scope to match the original
//   EBP loop state and switch-arm placement; emitted code was unchanged, so
//   restored the clean typed loop source.
// - named xSize/ySize after the negative from checks moved the first mismatch
//   no bytes, improved positional diff by 1 byte, but lost block alignment;
//   restored the clean typed source.
// - named rows, xReference, and yReference in the inner-loop preheader;
//   this moved the saved-this slot to [esp+10h] and reduced positional diff
//   from 479 to 346 bytes, but the remaining block-shape drift is unresolved.
// - removed the explicit self alias while retaining the named rows and
//   coordinate references; codegen was unchanged, so restored the clean alias.
// - original local evidence confirms the typed switch behavior: case 0 and
//   case 7 share the y decrement; cases 1/2, 3/4, and 5/6 use cold arms. A
//   numeric common-label probe used an unsupported source label and was dropped.
// - fresh declaration-order, loop-form, scope, and switch-label probes either
//   stayed in the same basin or lost the clean result. The natural typed source
//   remains pinned; exact switch layout and register coloring need new donor or
//   compiler-context evidence.
// - this pass moved rowIndex into the inner preheader and changed its
//   assignment to a declaration initializer; both emitted the same 346-byte
//   mismatch. A direct from.y <= to.y guard moved the y load and worsened the
//   result to 355 bytes, so it was restored. Direct this member expressions
//   changed one setup hunk but kept the 346-byte result; the alias is retained.
// - ownership review confirms InfluenceMap offsets +0x04, +0x08, +0x0C,
//   +0x10, +0x18, and +0x20, plus the XYPoint reference ABI, from exact donors
//   and the target assembly. No shared declarations were changed.
// - this pass tested direct y-reference reads, persistent row and coordinate
//   locals, outer do/while form, and declaration order. Most stayed at 346.
//   Caching to.y changed the frame to 0x28 and worsened the result to 367.
// - direct rowValue reads reached 345 bytes but lost exact blocks. A source
//   switch label matching the cold arms reached 353 bytes and improved shape.
//   Both forms were restored because they are not smaller exact sources.
// - duplicating the natural case-0 and case-7 y updates let VC5 merge their
//   common tail. It also moved the other switch arms to the exact cold layout.
//   Shape rose from 84.66% to 91.23%, with a 345-byte positional mismatch.
// - explicit rowIndex and neighborRow variables were compiler shadows. Their
//   removal was codegen-neutral. The typed indexed source is authoritative.
// - a 42-variant declaration-order lab produced two nonexact code groups. A
//   four-form typed row-expression lab produced one nonexact code group.
//   Function-scope references, register, direct fields, and block-local offset
//   forms stayed in the 345-byte basin. Using abs(direction) widened the body.
// - final blocker: the target stores self at [esp+10h] and its scaled row at
//   [esp+14h]. The rebuild swaps those homes. The target keeps scaled
//   yReference in ECX and rows at [esp+1Ch]; the rebuild swaps those roles.
//   This changes the preheader by four bytes and shifts all later addresses.
// - fresh exact-finish pass: removing the yReference local and rereading the
//   typed member in both row accesses reduced the mismatch from 345 to 8
//   bytes. The natural source then matched all non-stack bytes, CFG shape,
//   frame, owner symbol, boundary, and the target's zero-call set.
// - exact-finish reduction tested plain, const, reference, top-scope, and
//   inner-scope self aliases; row and xOffset scopes; row-index naming; loop
//   spelling; and the donor object-header surface. These either duplicated
//   the 8-byte result or widened the body. The reduced typed source is kept.
// - final validation: fresh grouped bytes remain an 8-byte stack-home swap.
//   Original self homes are [esp+10h] and row offset [esp+14h]. VC5 emits
//   those homes in reverse. The target has no direct or indirect calls.
// - captain context pass: the PDB module is infmap.cpp, with lines 394-458
//   spanning validation, nested scans, and the eight-direction switch. The
//   target uses the InfluenceMap +0x04/+0x08 bounds, +0x0C/+0x10 references,
//   +0x18 rows, and +0x20 count fields. Direct-this use, function-scope
//   xOffset, split self assignment, and an explicit row-index local did not
//   improve the 8-byte standalone result; the row-index probe widened it to
//   374 bytes and was restored.
// Accepted-drift audit: do not promote. The current source matches the
// executable's rowValue, xReferencePointValue, and yReferencePointValue read
// order. The remaining mismatch is only the compiler's stack-home choice.
// Invalid object storage keeps the executable fault order documented here.
```
<!-- end-recovered:3bb5ed8b8d08a8fa2ef5 -->

<!-- recovered:a27be0bffb513b76276a -->
### `c0c15a8201e7` `src/scratch/0044E9E0_setConnectionCount.cpp:143-143`

Mapping: `exact`. historical standalone source path names this target VA.

```text
                            // BINARY NOTE: VC5 merges this suffix with case 7.
```
<!-- end-recovered:a27be0bffb513b76276a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
