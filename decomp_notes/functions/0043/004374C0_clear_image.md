# Function notes: 004374C0 `clear_image`

Module notes: `decomp_notes/diam_map_module.md`.

## Recovered attempt history

<!-- recovered:0af5375a145a8f8108ec -->
### `target-session` `build/target_sessions/004374C0_clear_image.json:1-59`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=216; shape=81.73913043478261: Current clean typed-record/int-span source; establish baseline metrics and call/frame evidence.
probe 2 variant; result=MISMATCH; diff=222; shape=80.0: Tested binary-supported interior line_len cursor with line[-1]/line[0] and +3 stepping; compare setup and loop topology.
probe 4 variant; result=MISMATCH; diff=222; shape=80.0: Tested explicit short-pointer cast plus two-word offset for the proven six-byte image-line stride. [same emitted code as probe 2]
probe 6 layout; result=MISMATCH; diff=287; shape=68.10344827586206: Corrected proven TPanel coordinate widths to short and retained short image-line geometry; test original word-load arithmetic.
probe 8 layout; result=MISMATCH; diff=285; shape=80.17241379310344: Tested short coordinate fields with explicit padding to preserve proven TPanel offsets, plus short span intermediates.
probe 11 behavior; result=MISMATCH; diff=285; shape=80.17241379310344: Isolated short local geometry with canonical long TPanel layout; test word-width lowering without changing field ABI. [same emitted code as probe 8]
probe 13 liveness; result=MISMATCH; diff=236; shape=80.8695652173913: Named promoted pitch before scan setup and used it for row stepping; test spill timing against original local_4.
probe 15 control-flow; result=MISMATCH; diff=283; shape=81.19658119658119: Rewrote clipping intermediates as short values and removed int adjustment temporary, matching observed word arithmetic and signed extensions.
probe 17 variant; result=MISMATCH; diff=286; shape=77.77777777777777: Combined raw two-word image-line cursor with short clipping arithmetic; test whether decompiler cursor and narrow locals share the oracle basin.
probe 19 liveness; result=MISMATCH; diff=216; shape=81.73913043478261: Moved line-pointer declaration to function scope while preserving assignment and typed access; test register-color pressure source order. [same emitted code as probe 1]
probe 21 abi; result=MISMATCH; diff=216; shape=81.73913043478261: Tested period-plausible char pointer types for TDrawArea Bits, Lock result, and scan pointer; compare ABI and register basin.
probe 24 liveness; result=MISMATCH; diff=216; shape=81.73913043478261: Reordered natural local declarations to save area/start/pitch before image pointer; test orientation register coloring without changing typed ownership or loop form. [same emitted code as probe 23]
probe 26 behavior; result=MISMATCH; diff=283; shape=81.19658119658119: Used natural short start/end spans with compound clipping assignment; test the original word arithmetic while retaining typed line records. [same emitted code as probe 15]
probe 28 behavior; result=MISMATCH; diff=283; shape=81.19658119658119: Used short span locals with an uncast compound clipping expression; test whether VC5 emits the observed word clip loads without an explicit adjustment local. [same emitted code as probe 26]
probe 30 liveness; result=MISMATCH; diff=216; shape=81.73913043478261: Removed the local draw-area alias and used direct typed save_area member expressions; test whether the original orientation register basin reloads the owner naturally. [same emitted code as probe 24]
probe 32 liveness; result=MISMATCH; diff=216; shape=81.73913043478261: Combined Lock assignment with its null guard in one natural condition; test whether early result liveness selects the original EBX image-pointer basin. [same emitted code as probe 30]
probe 34 abi; result=MISMATCH; diff=313; shape=75.63025210084034: Initialized and used a typed save-area receiver before Lock; test whether natural owner lifetime matches the original receiver reload and register allocation.
probe 36 liveness; result=MISMATCH; diff=216; shape=81.73913043478261: Moved the typed image-line declaration after natural row-bound locals; test declaration order for original setup stores without cursor or layout changes. [same emitted code as probe 32]
probe 38 liveness; result=MISMATCH; diff=220; shape=80.8695652173913: Reordered natural orientation assignments to form the image pointer before pitch; test the original persistent EBX pointer and EBP pitch colors.
probe 41 behavior; result=MISMATCH; diff=272; shape=81.57894736842105: Replaced typed line record with a natural short line_len cursor and narrow clipping spans to reproduce the original word arithmetic and +4 setup.
probe 42 liveness; result=MISMATCH; diff=282; shape=78.8135593220339: Moved the natural short line_len cursor declaration before the orientation setup to test whether VC5 preserves the original EBX image pointer without a spill.
probe 44 control-flow; result=MISMATCH; diff=272; shape=81.57894736842105: Tested a natural short line_len cursor assigned after the y counter, with sequential narrow spans and cursor stride, to match original setup and clipping arithmetic. [same emitted code as probe 41]
probe 46 abi; result=MISMATCH; diff=283; shape=81.19658119658119: Kept the typed image-line owner for orientation liveness, then used a scoped short cursor alias for narrow word clipping; test whether VC5 preserves the original pointer basin. [same emitted code as probe 28]
probe 51 layout; result=MISMATCH; diff=222; shape=80.0: H1 structural owner: use a short cursor anchored at line_len, with line[-1]/[*] and +=3, matching decompiler pointer and 6-byte records. [same emitted code as probe 4]
probe 53 layout; result=MISMATCH; diff=216; shape=81.73913043478261: H2 field-layout lowering: retain the six-byte typed record and cursor lifetime, but read start_x/line_len through short-array offsets to test whether VC5 preserves the original word-load schedule. [same emitted code as probe 50]
probe 55 layout; result=MISMATCH; diff=211; shape=81.57894736842105: H3 proven-width layout: model pnl_x and pnl_y as short fields with explicit padding at their fixed offsets, matching the original word loads at +0C/+10 before changing arithmetic.
probe 56 behavior; result=MISMATCH; diff=285; shape=80.17241379310344: H4 narrow arithmetic: with proven short pnl_x/pnl_y, make s2 and ex short temporaries so VC5 must emit the original word add/sub/compare and later sign extensions. [same emitted code as probe 11]
probe 58 behavior; result=MISMATCH; diff=250; shape=75.89285714285714: H5 isolated width: keep only the start coordinate as short while retaining an int clipped end, separating original word-s2 lowering from the end-value lifetime.
probe 60 behavior; result=MISMATCH; diff=275; shape=80.0: H6 isolated width: keep int s2 but narrow only the clipped end to short, testing whether the original word line-length add controls the size gap independently.
probe 62 behavior; result=MISMATCH; diff=207; shape=81.41592920353982: H7 casted narrow arithmetic: keep int s2 lifetime and frame, but cast the short pnl_x+sx sum to short before widening, testing word add without the short-local basin.
probe 63 behavior; result=MISMATCH; diff=204; shape=87.38738738738739: H8 casted end arithmetic: retain int ex lifetime but narrow its line-length sum at the assignment boundary, testing word end lowering without the extra short local.
probe 64 behavior; result=MISMATCH; diff=283; shape=81.19658119658119: H9 natural narrow clipping: use short s2/ex and remove the named adjustment temporary, keeping the original short values while reducing lifetime pressure that caused the earlier 0x14-frame probe. [same emitted code as probe 46]
probe 66 control-flow; result=MISMATCH; diff=204; shape=87.38738738738739: H10 loop-control source: use predecrement and explicit nonzero do-while condition, testing the original near back-edge and update ordering without changing behavior. [same emitted code as probe 63]
probe 67 layout; result=MISMATCH; diff=204; shape=87.38738738738739: H11 packed-record cursor: represent the proven six-byte line as a char cursor with explicit +2/+4 short reads and +=6, testing pointer-update topology against the original add-4/add-6 pattern. [same emitted code as probe 66]
probe 69 liveness; result=MISMATCH; diff=204; shape=87.38738738738739: H12 declaration order: place the proven short pitch before the image pointer and owner locals, testing whether VC5 restores original p=EBX and pi=EBP colors while retaining H8 widths. [same emitted code as probe 67]
probe 71 layout; result=MISMATCH; diff=212; shape=83.78378378378379: H13 canonical-layout width: keep pnl_x/pnl_y as long fields, but explicitly narrow pnl_x before addition and the end sum, testing supported casts instead of a false short field layout.
probe 72 behavior; result=MISMATCH; diff=262; shape=78.57142857142857: H14 canonical field plus short local: retain long pnl_x layout, but bind the clipped start to a short local after an explicit narrow field cast.
probe 74 liveness; result=MISMATCH; diff=211; shape=81.57894736842105: H15 local width alias: cache the proven narrow pnl_x value in a short local before the int sum, testing a supported local overlay without changing TPanel layout. [same emitted code as probe 55]
probe 76 behavior; result=MISMATCH; diff=283; shape=81.19658119658119: H16 canonical natural clipping: use short start/end locals with a direct clipped-left adjustment while preserving long TPanel fields and fixed offsets. [same emitted code as probe 64]
probe 78 variant; result=MISMATCH; diff=283; shape=81.19658119658119: variant lab build\variant_lab\004374C0_clear_image\20260822_125544: 12 variants, 3 invariant-eligible, 0 exact
probe 79 behavior; result=MISMATCH; diff=285; shape=80.34188034188034: H17 decompiler-owned clipping: keep distinct short initial, end, and clipped-start locals, matching the observed AX/CX/EDX value roles and avoiding an unsupported field overlay.
probe 81 behavior; result=MISMATCH; diff=218; shape=78.15126050420169: H18 branch width: preserve long rectangle ownership and int spans, but cast only branch assignments to short, matching original word loads for clip-left adjustment and clip-right clamp.
probe 83 layout; result=MISMATCH; diff=241; shape=80.8695652173913: H20 proven cursor alias: retain the six-byte record owner while also naming its line_len interior pointer, then advance both, testing the original add-4/add-6 cursor topology.
probe 85 variant; result=MISMATCH; diff=241; shape=80.8695652173913: variant lab build\variant_lab\004374C0_clear_image\20260822_125819: 4 variants, 0 invariant-eligible, 0 exact
probe 86 liveness; result=MISMATCH; diff=212; shape=83.78378378378379: H22 combined canonical narrowing: cache pnl_x as a short local and narrow ex at assignment, testing a natural local lifetime that carries both observed word-width operations. [same emitted code as probe 71]
probe 87 liveness; result=MISMATCH; diff=212; shape=83.78378378378379: H23 H22 declaration order: place owner, start, and pitch before the image pointer to test the original saved-register color sequence under the improved narrow arithmetic. [same emitted code as probe 86]
probe 89 behavior; result=MISMATCH; diff=283; shape=73.72881355932203: H24 direct decompiler-shaped source: preserve short clipping locals, interior line_len cursor, and original local declaration order; test structural source ownership against the observed narrow loads and four stack homes.
probe 91 liveness; result=MISMATCH; diff=212; shape=83.78378378378379: H25 declaration order: place pitch before start_y to test the observed original start_y=DX and pitch=AX color split without changing behavior or layout.
probe 92 liveness; result=MISMATCH; diff=212; shape=83.78378378378379: H26 remove the save_area alias and retain direct this->save_area ownership through orientation; test whether the original row pointer EBX and pitch AX basin comes from alias lifetime. [same emitted code as probe 91]
probe 94 context; result=MISMATCH; diff=212; shape=83.78378378378379: H27 authentic standard string header context: include period string declarations before the explicit direct memset surface, testing TU context without changing calls or ownership. [same emitted code as probe 92]
probe 96 liveness; result=MISMATCH; diff=204; shape=87.38738738738739: H29 restore the prior best natural basin: declare the lock pointer first and narrow the origin sum at assignment, without changing line ownership, bounds, or calls.
probe 97 context; result=MISMATCH; diff=204; shape=87.38738738738739: H30 canonical diam_map context: use the reviewed full RGE_Diamond_Map/TPanel declaration and full TDrawArea field surface, preserving the exact set_bitmap/set_world layouts while testing authentic TU ownership. [same emitted code as probe 96]
probe 98 layout; result=MISMATCH; diff=213; shape=81.08108108108108: H31 combine the prior best H12 arithmetic basin with the binary-proven interior line_len cursor and +3 short-step topology; test setup ownership and six-byte row stride together.
probe 99 liveness; result=MISMATCH; diff=204; shape=87.38738738738739: H32 split the Lock result from the published row pointer: keep lock_result only for the early guard, then assign p in orientation branches; test whether distinct natural lifetimes recover p=EBX without altering fault order. [same emitted code as probe 97]
probe 100 behavior; result=MISMATCH; diff=285; shape=80.17241379310344: H33 narrow clipping values: make s2 and ex short locals with canonical p-first declarations, testing the binary word add/sub/compare basin while preserving overlap and bounds. [same emitted code as probe 56]
probe 101 behavior; result=MISMATCH; diff=262; shape=79.27927927927928: H36 narrow only the clipped start while retaining an int end lifetime and the canonical p-first/header context; test whether one original word value reduces register pressure without adding unsupported state.
probe 102 context; result=MISMATCH; diff=208; shape=88.28828828828829: H37 period standard-library context: add stdlib declarations to the canonical diameter-map TU without changing the direct memset surface or target ownership.
probe 103 context; result=MISMATCH; diff=208; shape=88.28828828828829: H38 authentic include ordering: place stdlib before the direct memset declaration, matching normal period TU header placement while preserving the same ABI and call target. [same emitted code as probe 102]
probe 106 context; result=MISMATCH; diff=204; shape=87.38738738738739: H40 final context-order test: place the reviewed diam_map header before the direct memset declaration, matching normal period translation-unit order. [same emitted code as probe 105]
```
<!-- end-recovered:0af5375a145a8f8108ec -->

<!-- recovered:6e9a55718a734e10c823 -->
### `5c06e112e88d` `src/scratch/004374C0_clear_image.cpp:1-82`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004374C0 RGE_Diamond_Map::clear_image (diam_map.cpp:519-569)
// Attempt log (sa-d55a5d35-clear_image, bounded 10-probe pass):
// - Baseline guessed TDA/DMap offsets, inlined memset, and missed the direct memset call.
// - Reconstructed the binary-backed TPanel/TDrawArea/RGE_Diamond_Map layouts and external memset;
//   size/calls became exact and the canonical typed source reached 216 differing bytes (310B).
// - A typed RGE_Map_Image_Line scan loaded before row bounds improved setup/block alignment;
//   the remaining 24-byte size gap is a natural VC5 short-branch basin, not accepted drift.
// - Short clipping intermediates were tested as a binary arithmetic hypothesis; they changed the
//   frame and cleanup and were rolled back. Best retained source is the typed-record/int-span form.
// - Paused: orientation register coloring and the compact-vs-near loop branch remain unresolved.
// - Follow-up pass: an interior line_len cursor and declaration-order changes were duplicate or
//   worse. Compound short clipping arithmetic reproduced the oracle's word-load body but added a
//   stack slot/frame and broad drift; a scoped widened pitch step reached 346 bytes with better
//   resynchronization but still had the wrong cursor allocation and was rolled back.
// - Follow-up pause: clean typed-record/int-span source remains authoritative; ordered calls,
//   frame, and behavior are aligned, while orientation register coloring and 24-byte loop drift
//   remain unresolved after 10 additional meaningful hypotheses.
// - Top-up pass: block-scoped post-lock locals and a scoped line cursor were tested; the former
//   was duplicate and the latter worsened loop topology. Short x/end arithmetic reproduced a
//   prior stack-slot basin and was rolled back. FillRect-style pointer-before-pitch ordering
//   worsened the orientation block. Boundary-local probes were duplicate; a temporary bottom
//   boundary test was rolled back because the binary's late load is clip-right, not clip-bottom.
// - Top-up pause: the clean typed-record/int-span reconstruction is restored. The remaining
//   evidence-backed gap is the original orientation register coloring and 24-byte loop shape.
// - Current pass: moving the natural scan step and line cursor into the positive-row block
//   worsened setup and loop topology; a named orientation local was codegen-identical.
// - Current pause: restored the prior clean source. No new lead remains before the structural
//   orientation and loop-shape gap is understood.
// - Follow-up pass (sa-4ab9d209): baseline remained 216 differing bytes (310 vs 334),
//   frame 0x10, three ordered calls, and 81.74% shape similarity. An interior line_len
//   cursor, an explicit short-pointer cursor, promoted pitch, short coordinate fields with
//   padding, short clipping intermediates, raw cursor plus short clipping, function-scope
//   line declaration, and char pointer types were tested. The cursor and char-pointer forms
//   were duplicate or worse; narrow-field and narrow-clipping forms added a 0x14 frame.
// - Follow-up pause: restored the pinned typed-record/int-span source. The remaining gap is
//   evidence-backed orientation register coloring plus the original narrow loop topology and
//   near back-edge. No exact result was found without opaque compiler steering.
// - Revisit pass (sa-85d5417c): natural declaration and owner-alias changes were duplicate or
//   worse. Short span locals reproduced word clipping but added a frame and broad drift. Direct
//   Lock guards, row declaration order, and orientation assignment order gave no improvement.
// - Revisit pause: restored the typed image-line ownership and natural do-loop source. Three
//   calls, the 0x10 frame, and behavior remain aligned; the 216-byte structural gap remains.
// - Revisit pass (sa-61f31cf1-r1): a natural short line_len cursor with narrow clipping
//   spans reproduced the word-width inner blocks, but changed the orientation register
//   basin, added control-flow drift, and reached 272 differing bytes (346-byte body).
//   A scoped cursor alias added a 0x14 frame and 283 differing bytes. Both were restored.
// - Revisit pause: the pinned typed-record/int-span source remains the clean natural
//   reconstruction. No policy-valid exact result was found.
// - Current claim (sa-7d176878): H1 interior short line_len cursor with +=3 worsened to
//   222 bytes; H2 raw short-array member reads were a 216-byte duplicate; H3 short
//   pnl_x/pnl_y fields with padding improved to 211 bytes but conflict with canonical
//   TPanel long fields; H4 both short span locals added a 0x14 frame and 285 bytes.
// - H5 short s2 alone reached exact size but broad drift (250 bytes); H6 short ex alone
//   added a 0x14 frame and 275 bytes; H7 casted short s2 with int lifetime reached 207;
//   H8 also casted ex reached 204 bytes, 319 bytes, 0x10 frame, and 87.39% shape.
// - H9 direct natural short clipping added a 0x14 frame and 283 bytes; H10 explicit
//   predecrement/nonzero loop control was an H8 duplicate; H11 char packed cursor was
//   an H8 duplicate; H12 declaration reorder was an H8 duplicate.
// - H13 retained canonical long TPanel fields and cast pnl_x/ex at expression boundaries:
//   212 bytes, 318 bytes, 0x10 frame, 83.78% shape. H14 canonical short s2 worsened to
//   262 bytes; H15 a short origin alias without the ex cast was a 211-byte H3 duplicate.
// - H16 canonical short s2/ex with direct clipping added a 0x14 frame and 283 bytes;
//   H17 distinct decompiler clipping locals added a 0x14 frame and 285 bytes; H18 branch
//   clip casts reached exact size but worsened to 218 bytes and 78.15% shape.
// - H20 a record owner plus interior cursor alias worsened to 241 bytes; H22 combined
//   canonical short origin and ex casts reproduced H13; H23 declaration reorder was
//   identical. An arithmetic/update variant lab produced no exact result; the best
//   invariant group used short-start arithmetic at 334 bytes but remained 253 bytes
//   different. A vc5-debug-context flag lab produced one 310-byte group for all flags.
// - Current retained natural candidate: canonical long TPanel fields with H13/H22
//   narrow expression casts. Ordered calls remain exact, frame is 0x10, and the latest
//   check is 212 differing bytes with 109 instructions versus 111 original.
// - Exact-finish pass: the direct decompiler-shaped short-local reconstruction added a
//   0x14 frame and reached 283 bytes. It is not a source template.
// - A p-first declaration and narrow origin sum reached 204 differing bytes in 319 bytes;
//   the reviewed full diam_map context changed the owner to protected IAEX with no body
//   change. The interior line_len cursor, Lock-result alias, short s2, and header-only
//   context probes were duplicate or worse. The reduced canonical candidate is retained.
// - Final unresolved validation: frame 0x10, three ordered direct calls, exact boundary
//   owner, and correct six-byte row stride remain aligned; 204 positional bytes differ.
// - Current claim: widening the pitch-step local to int worsened the result to 250
//   bytes and lost exact loop blocks. The short step remains authoritative.
```
<!-- end-recovered:6e9a55718a734e10c823 -->
