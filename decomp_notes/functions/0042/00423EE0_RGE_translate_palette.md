# Function notes: 00423EE0 `RGE_translate_palette`

Module notes: `decomp_notes/color_module.md`.

## Recovered attempt history

<!-- recovered:5988c4df70b3b0995131 -->
### `target-session` `build/target_sessions/00423EE0_RGE_translate_palette.json:1-44`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=450; shape=83.55263157894737: Baseline clean typed channel-cursor reconstruction from prior attempt log; establish current behavior and metrics.
probe 2 variant; result=MISMATCH; diff=449; shape=85.52631578947368: Reordered cursor and delta declarations/initializers to test target entry load order and natural line-32 setup.
probe 3 liveness; result=MISMATCH; diff=449; shape=85.52631578947368: Moved the long intensity array before index and cursor locals to test binary stack-slot reuse and target prologue topology. [same emitted code as probe 2]
probe 4 layout; result=MISMATCH; diff=449; shape=85.52631578947368: Replaced member-address cursor initializers with explicit byte offsets to test direct LEA topology without changing behavior. [same emitted code as probe 3]
probe 5 liveness; result=MISMATCH; diff=450; shape=83.55263157894737: Initialized the byte delta before both cursors to test whether VC5 preserves destination-first setup and parameter-home reuse. [same emitted code as probe 1]
probe 6 variant; result=MISMATCH; diff=449; shape=85.52631578947368: Initialized source cursor before destination cursor and delta as a natural declaration-order basin test. [same emitted code as probe 4]
probe 7 liveness; result=MISMATCH; diff=449; shape=85.52631578947368: Hoisted local4 to function scope while preserving natural palette math, testing stack-slot ownership and inner-counter register pressure.
probe 8 liveness; result=MISMATCH; diff=452; shape=84.86842105263158: Assigned the blue-channel scratch before intensity array members to test whether declaration/use order spills local4 and frees ESI for the sort counter.
probe 9 abi; result=MISMATCH; diff=412; shape=83.22147651006712: Replaced delta-indexed green stores with direct destination member stores to test typed ownership against the target address lowering.
probe 10 context; result=MISMATCH; diff=450; shape=83.55263157894737: Used declaration initializers for delta and cursors to test source-line initialization scheduling while keeping typed pointer ownership.
probe 12 context; result=MISMATCH; diff=450; shape=74.83870967741936: Restored the period Windows PALETTEENTRY declaration context to test header-driven VC5 lowering.
probe 14 variant; result=MISMATCH; diff=450; shape=83.55263157894737: Widened the inner two-step sort counter to long to test the target ESI decrement topology under period integer widths. [same emitted code as probe 5]
probe 15 layout; result=MISMATCH; diff=437; shape=92.71523178807946: Modeled the four contiguous intensity slots as one long intense[4] array, testing whether the decompiler's local4 is the array's fourth element.
probe 16 variant; result=MISMATCH; diff=437; shape=92.71523178807946: Kept the four-slot intensity array and folded the max-plus-mid expression to test target x86 operand load order. [same emitted code as probe 15]
probe 17 liveness; result=MISMATCH; diff=437; shape=92.71523178807946: Reordered cursor, delta, index, and four-slot intensity declarations to test the target prologue while preserving the strong array[4] body basin. [same emitted code as probe 16]
probe 18 context; result=MISMATCH; diff=437; shape=92.71523178807946: Tested the shared period game_globals header context around the strong intensity-array body.
probe 19 liveness; result=MISMATCH; diff=437; shape=90.06622516556291: Reordered array[4] cursor and delta assignments to test the exact body basin with alternate natural initialization order.
probe 20 layout; result=MISMATCH; diff=437; shape=92.71523178807946: Tested explicit byte-offset cursor bases with array[4] to see if direct pointer arithmetic recovers the target LEAs. [same emitted code as probe 18]
probe 21 variant; result=MISMATCH; diff=437; shape=93.37748344370861: Reversed the commutative intensity add operands to test the target's EDX=mid/EAX=max load order.
probe 22 abi; result=MISMATCH; diff=437; shape=93.37748344370861: Completed the int-array width variant with int pointer arithmetic after the type-correctness repair. [same emitted code as probe 21]
probe 23 abi; result=MISMATCH; diff=437; shape=93.37748344370861: Widened the byte-pointer delta local to long to test the target's stack-home and tail register color with period pointer arithmetic. [same emitted code as probe 22]
probe 25 liveness; result=MISMATCH; diff=437; shape=93.37748344370861: Matched Ghidra declaration order: initialize intense[0] before source cursor to test the target prologue basin. [same emitted code as probe 24]
probe 31 liveness; result=MISMATCH; diff=437; shape=90.72847682119205: Declaration initializers for destination cursor, source cursor, and delta test whether VC5 schedules destination before source and removes the synthetic prologue relation.
probe 33 liveness; result=MISMATCH; diff=437; shape=90.72847682119205: Reorder cursor and delta assignments to destination cursor, source cursor, then delta; test whether source statement order selects the target ECX/EDX prologue basin. [same emitted code as probe 31]
probe 34 abi; result=MISMATCH; diff=437; shape=93.37748344370861: Use direct byte-offset cursor bases with the four-slot body; test whether pointer arithmetic spelling removes the compiler's dst/src relation and restores the target prologue. [same emitted code as probe 32]
probe 35 liveness; result=MISMATCH; diff=450; shape=83.55263157894737: Use a block-scoped local4 beside the three-element intensity array, matching the PDB/Ghidra separate local and its short live range. [same emitted code as probe 14]
probe 36 liveness; result=MISMATCH; diff=437; shape=93.37748344370861: Introduce natural source/target aliases before cursor setup; test whether named palette ownership changes VC5 load order without changing layout or arithmetic. [same emitted code as probe 34]
probe 38 abi; result=MISMATCH; diff=437; shape=93.37748344370861: Use explicit 32-bit integer cursor offsets to test whether the target's direct LEA pair comes from period pointer-integer arithmetic. [same emitted code as probe 37]
probe 39 variant; result=MISMATCH; diff=437; shape=93.37748344370861: Sequence cursor, delta, source, and outer-index setup with one comma expression; test PDB line-32 sequencing as a source-level prologue control. [same emitted code as probe 38]
probe 40 abi; result=MISMATCH; diff=437; shape=93.37748344370861: Use period pointer increment/decrement forms for the palette cursor bases; test whether compiler normalization emits independent target and source LEAs. [same emitted code as probe 39]
probe 41 liveness; result=MISMATCH; diff=437; shape=93.37748344370861: Move pointer cursor declarations after scalar scratch declarations while keeping destination, delta, source assignment order; test the target saved-register coloring basin. [same emitted code as probe 40]
probe 42 variant; result=MISMATCH; diff=437; shape=93.37748344370861: variant lab build\variant_lab\00423EE0_RGE_translate_palette\20260823_185006: 7 variants, 0 invariant-eligible, 0 exact
probe 43 liveness; result=MISMATCH; diff=437; shape=90.72847682119205: Reverse source and destination cursor assignment order while retaining direct delta computation; test whether source-first declaration order selects target register colors. [same emitted code as probe 33]
probe 44 context; result=MISMATCH; diff=417; shape=84.41558441558442: Add the color.cpp exact-donor string header; test standard-header front-end state as the remaining authentic TU context axis.
probe 46 liveness; result=MISMATCH; diff=437; shape=90.72847682119205: Reorder source, destination, and delta initializers to test whether the target's ECX=destination and EDX=source prologue is a natural declaration-order basin. [same emitted code as probe 43]
probe 48 layout; result=MISMATCH; diff=450; shape=75.0: Restore the earlier three-slot intense array with a separate local4 and direct destination member publication; test the binary stack ownership model against the four-slot array.
probe 50 layout; result=MISMATCH; diff=450; shape=83.55263157894737: Recreate the prior three-slot scratch model with declaration order index1, intense, cursors, and block local4; this is a source-backed stack-lifetime hypothesis from the prior best basin. [same emitted code as probe 35]
probe 52 context; result=MISMATCH; diff=417; shape=84.41558441558442: Add the exact color.cpp donor's period string header; test authentic standard-header front-end state without changing palette semantics. [same emitted code as probe 44]
probe 54 abi; result=MISMATCH; diff=437; shape=93.37748344370861: Use period pointer-plus-offset forms for the destination flags and source green cursors while retaining the four-slot body; test whether direct LEA lowering removes the synthetic cursor relation. [same emitted code as probe 45]
probe 56 variant; result=MISMATCH; diff=437; shape=93.37748344370861: variant lab build\variant_lab\00423EE0_RGE_translate_palette\20260823_211034: 49 variants, 28 invariant-eligible, 0 exact
probe 57 liveness; result=MISMATCH; diff=437; shape=93.37748344370861: Qualify source and destination pointer parameters as register candidates; test whether period VC5 register hints select the original pre-push ECX/EDX colors without changing the ABI. [same emitted code as probe 54]
probe 59 liveness; result=MISMATCH; diff=437; shape=93.37748344370861: Qualify only the destination byte cursor as register-qualified; test whether its long loop lifetime forces the original early destination load and EBP cursor. [same emitted code as probe 57]
probe 61 layout; result=MISMATCH; diff=450; shape=83.55263157894737: Use a natural long local4 beside long intense[3], preserving byte-derived channel width and loop order; test whether VC5 overlaps the fourth scratch word without a synthetic array slot. [same emitted code as probe 50]
probe 63 layout; result=MISMATCH; diff=437; shape=93.37748344370861: Model the proven four contiguous scratch words as one natural local aggregate with intense[3] and local4; test whether member ownership reproduces the original stack homes without an array-only overlay. [same emitted code as probe 59]
```
<!-- end-recovered:5988c4df70b3b0995131 -->

<!-- recovered:a7e23e5e7f2bf9ad55e1 -->
### `c0dc2d6ab3e9` `src/scratch/00423EE0_RGE_translate_palette.cpp:1-47`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00423EE0 RGE_translate_palette (color.cpp:23-67)
// Attempt log:
// 1: Pointer implementation with s/d locals: size 448, broad diff; compiler kept pct in EBP and used different pointer basis.
// 2: d-before-s and d[-3] stores: no material improvement.
// 3: Natural indexed PALETTEENTRY loop: worse (95.3% diff), rolled back.
// 4: Pointer form with register d/s hints: no material change, still 448 bytes.
// 5: Use unsigned int color parameter: worsened padded diff to 96.2%; rolled back to struct color.
// 6: Fresh typed PALETTEENTRY array reconstruction: 476 bytes and a 0x24 frame; rolled back.
// 7: Removed unsigned channel casts in the typed pointer form; signed VC5 divisions improved resync similarity.
// 8: Separated the palette index from the three intensity values; 0x14 frame and no positional gain.
// 9: Reordered locals, counted loops, and pointer declarations; emitted code stayed unchanged.
// 10: Restored the binary-backed long index1/intense[3] lifetime shape. The outer loop counter shares
// intense[0], while the inner counter stays a block local; this tests the original 0x10-frame reuse.
// 11: Use typed source/target entry pointers and direct member ownership instead of channel cursors;
// this expanded the frame to 0x24 and broke the exact branch islands, so it was rolled back.
// 12: Declare the destination cursor, byte delta, and source cursor in the original evidence order.
// 13: Separate the pointer/delta initializers from their declarations to test source-line scheduling.
// 14: Split the local4 declaration from its source-channel assignment to test stack home reuse.
// 15: Keep the two-step sort counter in a register, matching the observed ESI inner-loop lifetime.
// 16: Widen the inner sort counter to long, matching the long index variables in the source packet.
// 17: Restore local4 to int; the binary lists it as a 4-byte scratch separate from long intense[].
// 18: Form the channel cursors from explicit byte offsets; emitted code was unchanged, so the
// named PALETTEENTRY member addresses remain the living source.
// Final pass: the long index/intense lifetime reaches the 0x10 frame and 85.53% shape basin;
// pointer-order, local declaration, counter-width, and cursor-offset variants were duplicates.
// Left in scratch: the best period-plausible typed reconstruction. The original uses a 0x10 frame,
// reuses a parameter home for the byte delta, and starts the channel loop seven bytes earlier.
// Follow-up TU pass: declaration initializers and split delta subtraction were duplicates.
// The historical typed entry-pointer form reached 420 bytes but used a 0x24 frame and
// 42.67% shape; named channel locals reached 431 bytes with a 0x14 frame. Both were restored.
// New pass: the original writes the destination-minus-source delta into the incoming source
// parameter home. Reusing the saved source cursor and mutating that parameter reached 384 bytes,
// 86.58% shape, and 455 bytes, but the parameter-as-integer form is not a clean source baseline.
// Scoping the sort counter, moving local4, and widening local4 were codegen duplicates. Restored
// the clean typed channel-cursor source; remaining blocker is structural VC5 stack/register
// allocation around the proven parameter-home reuse and local4/inner-counter overlap.
// Matching-worker pass: modeling the four contiguous scratch slots as long intense[4] made the
// body align with the original after a seven-byte prologue shift: 456 bytes, 93.38% shape,
// 33.11% exact-block coverage, and 51 edit-diff bytes. The fourth array slot explains the
// decompiler's local4 and frees ESI for the inner two-step sort counter. Reversed
// (intense[2] + intense[3]) operands recover the original mid/max load order. The remaining
// mismatch is the destination/source cursor prologue and the late diff-load scheduling.
// Windows and shared game_globals header contexts, pointer/delta declaration orders, explicit
// byte offsets, and int/long width variants did not change this codegen basin. Keep this
// ordinary four-slot array reconstruction as the clean unresolved source.
// Revisit: matching the Ghidra declaration order by initializing intense[0] before s was a
// codegen duplicate. Final validation remains 437 differing bytes and a 456-byte rebuild.
```
<!-- end-recovered:a7e23e5e7f2bf9ad55e1 -->
