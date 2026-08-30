# Function notes: 004848A0 `check_elevation`

Module notes: `decomp_notes/rmm_elev_natural_candidate.md`.

## Recovered attempt history

<!-- recovered:00eb75beff4bb355aa00 -->
### `target-session` `build/target_sessions/004848A0_check_elevation.json:1-46`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=323; shape=83.55263157894737: Canonical current scratch reconstruction after full packet, dossier, same-TU donors, and ABI review; measure current boundary and structural mismatch before new probes.
probe 2 variant; result=MISMATCH; diff=323; shape=83.55263157894737: Reordered the natural result declaration after first-scan locals to test whether VC5 assigns result to the oracle's -0x10 home while preserving row/cursor ownership. [same emitted code as probe 1]
probe 4 control-flow; result=MISMATCH; diff=320; shape=84.21052631578948: Swapped natural first-scan x2/y2 declaration and initialization order. Original loads y2 into EAX and retains x2 in EBX; current source had the reverse lifetime/color pattern.
probe 5 liveness; result=MISMATCH; diff=320; shape=84.21052631578948: Added a period-plausible register qualifier to x because the oracle loads x into EDI while the clean source loads it into ESI; test whether this restores the original x1/x2 register topology. [same emitted code as probe 4]
probe 7 liveness; result=MISMATCH; diff=323; shape=83.55263157894737: Reordered second-scan row-table cursor before row-offset declaration to test the oracle's row-pointer EDI versus x1 EBP allocation and preserve natural cursor ownership. [same emitted code as probe 2]
probe 8 layout; result=MISMATCH; diff=323; shape=83.55263157894737: Mirrored the exact sibling's bound-local declaration order: lower bounds, row locals, then upper bounds, with x2 expressed x+radius. This tests natural declaration lifetime and initial register coloring against the oracle. [same emitted code as probe 7]
probe 9 control-flow; result=MISMATCH; diff=352; shape=88.31168831168831: Rewrote the first scan in the sibling's natural carried-row form: explicit row index, row base including x offset, while guard, and bottom row advance. Original assembly carries row offset plus next row base across the outer increment.
probe 10 control-flow; result=MISMATCH; diff=352; shape=88.31168831168831: Kept the carried-row source but restored the period-style radius+x expression. The prior carried-row build had exact prologue colors except the x2/y2 arithmetic order. [same emitted code as probe 9]
probe 11 layout; result=MISMATCH; diff=352; shape=88.31168831168831: With the carried-row source retained, swapped upper-bound declaration order so x2 precedes y2. This tests the oracle's x2-in-EBX and y2-in-radius-home allocation. [same emitted code as probe 10]
probe 12 abi; result=MISMATCH; diff=365; shape=88.8157894736842: Reused the long radius parameter as the clipped first-scan y2 bound. Original writes y2 into the radius home and reads that home in both first-scan row setup and loop update; this is supported by the decompiler and same-TU donor pattern.
probe 14 layout; result=MISMATCH; diff=348; shape=88.96103896103897: Carried-row source with natural x2-before-y2 assignment order. Test whether use order maps x2 to EBX and y2 to the reused radius home as in the oracle.
probe 16 abi; result=MISMATCH; diff=350; shape=83.00653594771242: Baseline source with explicit reuse of radius as clipped first-scan y2. Test whether the original radius-home write can arise naturally without the carried-row rewrite.
probe 19 baseline; result=MISMATCH; diff=323; shape=83.55263157894737: Fresh claim baseline: readable typed two-scan map/terrain reconstruction with row-pointer-before-offset ordering; establish current structural gap before new source hypotheses. [same emitted code as probe 18]
probe 20 control-flow; result=MISMATCH; diff=356; shape=80.26315789473684: Carry the typed first-scan row base plus x offset before the row guard and after each row advance, matching the oracle's add row-base,offset before x1/x2 test; test natural traversal rather than raw cursor plumbing.
probe 22 liveness; result=MISMATCH; diff=373; shape=81.16883116883118: Introduce a separate natural first-scan row_index while retaining the clean source's uncarried typed row address; test whether the proven original row-counter home can coexist with the baseline branch topology.
probe 24 abi; result=MISMATCH; diff=377; shape=81.93548387096774: Use the binary-proven byte result local for the second elevation scan; let the existing natural first-scan y bound absorb register pressure instead of adding an artificial row counter.
probe 25 abi; result=MISMATCH; diff=350; shape=83.66013071895425: Reuse the dead radius parameter home as the clipped first-scan upper row bound, supported by original writes at [esp+34] and the sibling area-scan pattern; retain typed row and tile traversal.
probe 26 control-flow; result=MISMATCH; diff=350; shape=83.00653594771242: Reverse first-bound assignments to natural radius-then-x2 order, as the oracle loads y+radius before the x upper bound and the prior local history supports this radius-home basin. [same emitted code as probe 16]
probe 28 layout; result=MISMATCH; diff=320; shape=84.21052631578948: Swap first-scan x2/y2 declaration assignment order to the natural x-bound-then-y-bound form; prior same-TU history showed this exact local basin at 320 differing bytes. [same emitted code as probe 5]
probe 29 layout; result=MISMATCH; diff=374; shape=79.60526315789474: Swap natural first lower-bound assignment order to y1 then x1, testing whether VC5 rotates the x/y register colors toward the oracle without changing ownership or traversal.
probe 31 liveness; result=MISMATCH; diff=377; shape=84.21052631578948: Combine the binary-motivated first-scan row_index spill with carried typed row-base plus offset; test the local-home topology that previously matched result, row counter, saved this, row pointer, and offset coordinates.
probe 32 layout; result=MISMATCH; diff=386; shape=84.21052631578948: With carried row-base and row_index retained, swap first x2/y2 assignment order to the prior source form that aligned the saved-this and local-home window.
probe 34 control-flow; result=MISMATCH; diff=352; shape=88.31168831168831: Correctly combine row_index with carried row-base plus offset: cell now uses row+5, avoiding the prior double-offset probe. This is the historical natural typed traversal form. [same emitted code as probe 11]
probe 35 layout; result=MISMATCH; diff=348; shape=88.96103896103897: Retain the corrected carried-row/index form and use x2-before-y2 initialization; compare the historical 408-byte basin against the current 352-byte result. [same emitted code as probe 14]
probe 39 layout; result=MISMATCH; diff=323; shape=83.55263157894737: Move the result declaration after first-scan bounds and row locals. Original initializes the dword result at local [esp+14] while the first-scan counter uses [esp+10]; test natural declaration order without parameter-home reuse. [same emitted code as probe 38]
probe 41 layout; result=MISMATCH; diff=350; shape=83.55263157894737: Use typed RGE_Tile cell traversal and bitfield members in the first elevation scan, with a binary-proven explicit row index. This removes raw byte-cell masking while preserving the 24-byte typed tile stride.
probe 43 layout; result=MISMATCH; diff=373; shape=79.60526315789474: Use the natural typed row-pointer form from the same-TU terrain scan: RGE_Tile* row = *row_ptr + x1, typed tile members, and ++cell. This removes the first scan's raw row/cell cursor and keeps ownership explicit.
probe 45 liveness; result=MISMATCH; diff=375; shape=80.0: Use the binary-supported for-header outer counter , matching the original stack-local counter initialized after row/offset setup. Keep typed ownership in the surrounding map surface and avoid parameter-home reuse.
probe 47 context; result=MISMATCH; diff=316; shape=83.55263157894737: Restore same-TU period header context from exact rmm_elev.cpp donors: math.h and string.h precede the shared elevation declarations. Test supported translation-unit context, not compiler steering.
probe 48 layout; result=MISMATCH; diff=313; shape=84.21052631578948: With same-TU headers retained, order the first upper-bound declarations and assignments as x2 then y2. This is a period-plausible source ordering axis supported by the prior local 320-byte basin; it tests register rotation without parameter reuse.
probe 49 control-flow; result=MISMATCH; diff=379; shape=78.84615384615384: Carry the typed row-base plus x offset across the first scan, so each cell uses row+5 and each row refreshes row_base = next_row + offset. This follows the original add row-base,offset topology and avoids a duplicated offset.
probe 51 liveness; result=MISMATCH; diff=393; shape=81.04575163398692: Keep the supported same-TU headers and x2-before-y2 order, then give the first scan a function-scope index initialized immediately after row setup. The original has a distinct first-scan counter home; test this natural lifetime without a for-header declaration or parameter reuse.
probe 53 liveness; result=MISMATCH; diff=375; shape=80.0: Place a distinct first-scan index declaration before the result declaration, then assign it after row setup. This tests whether natural declaration order recovers the original index [esp+10] and result [esp+14] homes. [same emitted code as probe 45]
probe 55 behavior; result=MISMATCH; diff=374; shape=78.28947368421052: Replace both raw byte-cell cursors with typed RGE_Tile row and cell pointers, typed bitfield reads, and ++cell. This is the policy-compliant period source model; measure it before deciding the unresolved clean form.
probe 56 behavior; result=MISMATCH; diff=374; shape=78.28947368421052: Use the reviewed RGE_Tile byte field at offset +5, with typed tile pointers and explicit terrain/elevation masks. Inventory proves the terrain byte; this avoids an invented elevation bitfield and all raw byte cursors. [same emitted code as probe 55]
probe 61 liveness; result=MISMATCH; diff=344; shape=84.86842105263158: Keep a distinct first-scan index local initialized from the clipped lower row before the loop. The oracle homes the first row counter at [esp+10] while the result stays at [esp+14]; test this natural lifetime split in the minimal inherited context.
probe 62 layout; result=MISMATCH; diff=340; shape=85.52631578947368: With the separate first-scan index retained, declare and initialize x2 before y2. The oracle keeps x2 in EBX and homes y2 in the radius argument slot; this tests the supported bound declaration/order axis.
probe 63 layout; result=MISMATCH; diff=344; shape=84.86842105263158: Retain x2-before-y2 declaration order from the bound-home evidence, but restore y2-before-x2 evaluation order. This separates declaration coloring from statement order and tests the original add-y2/LEA-x2 arithmetic topology. [same emitted code as probe 61]
probe 64 liveness; result=MISMATCH; diff=340; shape=85.52631578947368: Keep the recovered separate first-scan index, but declare the authentic row-table and row locals before it. This tests declaration-scope coloring for the oracle row pointer [esp+18] and offset [esp+20] without changing traversal. [same emitted code as probe 62]
probe 65 liveness; result=MISMATCH; diff=339; shape=84.86842105263158: Swap second-scan local declaration order so the row base precedes the row-table cursor. The oracle carries the row-table cursor in EDI and row base in ECX; test this natural lifetime order while preserving typed tile ownership.
probe 66 liveness; result=MISMATCH; diff=340; shape=85.52631578947368: Promote the second-scan row-base and row-table locals to function scope, while keeping their use in the fixed-radius scan. The original carries row-table state in EDI across the second scan; test this lifetime without raw overlays. [same emitted code as probe 64]
probe 67 behavior; result=MISMATCH; diff=339; shape=84.86842105263158: Direct validation after the no-op address-add and alias probes: the minimal virtual-destructor base, authentic object-list tile, separate first-scan index, typed narrow bitfields, and block-scoped second scan remain at 403 bytes and 339 differing bytes. No raw cursor or fake context was retained. [same emitted code as probe 65]
probe 69 control-flow; result=MISMATCH; diff=339; shape=84.86842105263158: Typed row-base plus x1 inside each row removed the preserved frame and widened the function to 391 bytes. Restore the pinned row-plus-offset cursor form. [same emitted code as probe 68]
probe 70 layout; result=MISMATCH; diff=339; shape=84.86842105263158: A named typed row offset preserved the 0x14 frame but moved to 409 bytes / 385 differing bytes and changed the prologue. Restore the pinned carried-row source; the oracle offset home cannot be recovered by this natural alias. [same emitted code as probe 69]
probe 71 layout; result=MISMATCH; diff=339; shape=84.86842105263158: Swapping natural upper-bound assignments to compute y2 before x2 moved from 339 to 343 differing bytes and did not recover the oracle's x2/y2 register roles. Restore the original x2-before-y2 source order. [same emitted code as probe 70]
probe 72 liveness; result=MISMATCH; diff=339; shape=84.86842105263158: Reusing the radius parameter as the first-scan y2 row bound changed the prologue and widened to 399 bytes / 358 differing bytes. The natural separate y2 still gives the closest typed basin; restore it. [same emitted code as probe 71]
```
<!-- end-recovered:00eb75beff4bb355aa00 -->

<!-- recovered:cb27a1eca0deb52c0810 -->
### `561715f8ab6d` `src/scratch/004848A0_check_elevation.cpp:1-97`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004848A0 RGE_RMM_Elevation_Generator::check_elevation
// Source: rmm_elev.cpp lines 100-153
// Attempt log:
// 1: initial reconstruction from packet/decompiler; wrong first-phase register topology and too-short text.
// 2: literal decompiler-style temporaries/order; too-short 0x10 frame due byte counter.
// 3: int local_10/row-count literal decompiler form even shorter/worse.
// 4: original-asm-inspired loop topology still too short/broad.
// 5: restore initial source as best behavioral baseline.
// 6: /Ob0, /O1, and /Gs flag probes did not reach original size/layout; removed flags.
// New claim: carry the second scan's row base plus x-offset across the row
// increment, matching the original `mov next_row; add offset` topology instead
// of recomputing the offset inside each cell LEA.
// Next ABI/layout probe: reuse the check_start_elevation sibling's byte-row
// ownership (`char**` plus byte row bases) instead of `int**`/`int*` aliases.
// Next liveness probe: model the binary-proven `count` stack local as the first
// scan's row counter, while keeping the second scan's byte result separate.
// Final source-width probe: use the period code's natural `long` coordinate,
// offset, and count locals throughout both scans instead of decompiler `int`s.
// Clean-source result: second-scan row-base carry is retained (408B boundary
// still lacks 11 effective bytes); first-scan row-base carry, result/row-count
// split, combined predicate, and inherited-class context were rolled back as
// worse or duplicate. No source-shape path reached the original first-scan
// stack homes.
// Left in scratch: behavior modeled, but first/second scan register topology and stack-slot layout remain broad.
// Continuation (sa-ab4dd300-r1): rmm_base/rmm_terr donors support the full
// inherited map-row and 24-byte tile surface; it compiled identically to the
// gap-only surface. A first-scan row_index and explicit self pointer were
// binary-motivated but formed a 370-byte-diff basin. Declaring the first
// row-pointer before its row base, while retaining byte-level tile access,
// improved the clean reconstruction to a 349-byte diff. Carrying the first
// row offset or swapping the second row-base/pointer order moved into broader
// structural basins; the latter reached 322 bytes but lost 13 bytes of code
// and kept the countdown in a register, so it was restored. Remaining gap is
// structural first-scan/second-countdown topology.
// Main-agent audit removed the diagnostic self alias and non-target padding
// helper; direct member ownership remains authoritative.
// Current claim: rechecked the full packet, dossier, same-TU donors, and ABI
// evidence. Prior bounded probes already exhausted first-scan row/count and
// second-scan liveness/layout families; no new source-supported lead justified
// replacing this readable 397-byte canonical reconstruction.
// Fresh worker (shardE-4848A0):
// - Baseline repeated the canonical typed two-scan source (397 bytes, diff 349).
// - Loading the second row base through row_ptr2 improved block/edit alignment
//   without changing size or strict diff; retained as a natural cursor form.
// - Reusing short-range names, hoisting first-scan declarations, and counted
//   while/for variants were duplicate or broader basins. Explicit radius-home
//   reuse was broader and was rolled back.
// - Reordering first row_ptr before row_offset was the best new lead: 394 bytes,
//   diff 323, shape 83.55%, with the oracle's saved-this, row-pointer, and
//   offset homes aligned. It still misses the count/y2/x2 home rotation and
//   remains structurally non-exact. A final index1 local probe broadened to 375
//   bytes and was rolled back.
// Paused: retain the readable row_ptr-before-offset reconstruction. Remaining
// blocker is the first-scan local-home rotation; no further blind variants fit
// the evidence budget.
// Fresh worker probes (orch-rmmelev-fresh-03):
// - Reusing the dead radius home for the first-scan clipped upper row bound
//   improved the diagnostic output to 398 bytes / 322 differing bytes, but
//   changed the prologue and remained a broad structural basin; rolled back.
// - Separate row_index declaration/scope and declaration-order variants were
//   exact-size or duplicate broad basins; none recovered the original
//   result/row-pointer/saved-this local rotation.
// - The typed Map_Stack/tile/base surface from the new same-TU two-byte stack
//   sibling is retained as canonical context; it is codegen-neutral here.
// Paused: clean source remains 397 bytes / 349 differing bytes. The remaining
// evidence-backed blocker is the first-scan local-window topology (original
// row counter [esp+10], result [esp+14], row pointer [esp+18], saved this
// [esp+1c], and offset [esp+20]) versus the natural compiler allocation;
// second-scan behavior and canonical map ownership are modeled.
// Revisit (sa-1f308ade-r1):
// - The clean typed baseline rebuilt to 394 bytes with 323 differing bytes.
// - Reusing the radius home, a byte result, or a separate row index alone
//   moved to broader structural basins and was rolled back.
// - A natural x2-before-y2 order reached 394 bytes and 320 differing bytes,
//   the best strict metric, but did not improve structural resynchronization.
// - A corrected row_index plus carried typed row-base form reached the exact
//   408-byte boundary and 348 differing bytes, with 88.96% shape, but its
//   local allocation remained farther from the oracle than the clean source.
// Retain the pinned clean source. The unresolved evidence-backed blocker is
// the first-scan register and local-home rotation, not map or terrain ownership.
// Revisit (sa-7c3536d6-r1):
// - The pinned source rebuilt unchanged at 394 bytes and 323 differing bytes.
// - Same-TU math/string headers plus x2-before-y2 ordering improved the
//   diagnostic result to 396 bytes and 313 differing bytes, but did not fix
//   the first local-home mismatch; this context lead was rolled back.
// - A for-header or function-scope first-row index reached 408 bytes but
//   entered the known broad 375/393-byte structural basins.
// - A row-base carry, including its corrected non-duplicated offset, was
//   broader and was rolled back.
// - The final policy-compliant source uses typed RGE_Tile rows and cells,
//   the reviewed terrain byte at offset +5, and no byte cursor. It rebuilt to
//   399 bytes and 374 differing bytes. No exact source lead was found.
// [non-comment lines omitted during migration]
// Main-agent audit confirmed canonical elevation-map ownership and retained the
// natural two-scan bounds check; padding remains non-target scaffolding only.
```
<!-- end-recovered:cb27a1eca0deb52c0810 -->
