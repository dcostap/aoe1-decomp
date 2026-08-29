# Recovery journal: 0051D4F0 `render_to_image_buffer`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tpnl_pop.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tpnl_pop.cpp`.
- Earlier recovery note: `recovery_notes/tpnl_pop_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:360d45a6c70a0e679c0d -->
### `target-session` `build/target_sessions/0051D4F0_render_to_image_buffer.json:1-50`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 2 layout; result=MISMATCH; diff=422; shape=86.17511520737327: H1: enlarge the local string from 256 to 260 bytes to test whether the original str+4 stack destination uses a 260-byte source buffer; inspect frame, first hunk, and size.
probe 4 layout; result=MISMATCH; diff=380; shape=88.47926267281106: H2: initialize width and height as panel bounds minus one, then express the four shadow rectangles and final inset from those aliases; this tests the original EBP/EDI bound basin.
probe 6 layout; result=MISMATCH; diff=422; shape=86.17511520737327: H3: shrink the local string to 252 bytes while retaining str+4; test whether the original destination comes from a smaller stack slot without frame growth.
probe 8 layout; result=MISMATCH; diff=418; shape=90.78341013824885: H4: remove the decompiler-only +4 from the local string at sprintf and all DrawTextA calls; test whether original stack addresses identify the array base as str rather than str+4.
probe 9 layout; result=MISMATCH; diff=380; shape=88.47926267281106: H5: retain the proven unshifted string base and use width/height minus-one aliases for all rectangle calls; test whether the improved bound basin survives with corrected text addresses.
probe 10 layout; result=MISMATCH; diff=418; shape=90.78341013824885: H6: change only the local width and height aliases from int to long; test whether VC5 preserves the original EBP/EDI arithmetic basin with period panel types. [same emitted code as probe 8]
probe 11 layout; result=MISMATCH; diff=381; shape=88.0184331797235: H7: separate the width/height updates into w-=2, h-=1, and ++w before the rectangle calls; test whether explicit source updates reproduce the original sub/dec/inc topology without extra aliases.
probe 12 layout; result=MISMATCH; diff=381; shape=88.0184331797235: H8: keep explicit width/height updates but spell the repeated second right bound as w-1-1; test whether a natural alternate expression removes the compiler spill and restores recomputation. [same emitted code as probe 11]
probe 14 layout; result=MISMATCH; diff=418; shape=90.78341013824885: H9: swap declaration order so height is declared before width while retaining direct rectangle expressions; test whether VC5 assigns width to EBP and height to EDI as in the original. [same emitted code as probe 10]
probe 15 abi; result=MISMATCH; diff=418; shape=90.78341013824885: H10: model TPanel width and height as period long fields rather than int; test whether canonical panel field types recover the original width/height register and arithmetic schedule. [same emitted code as probe 14]
probe 16 abi; result=MISMATCH; diff=234; shape=87.55760368663594: H11: declare repeated SetRect as a normal dllimport function instead of a const IAT pointer; test the original EBX import cache and rectangle call topology.
probe 17 abi; result=MISMATCH; diff=234; shape=87.55760368663594: H12: retain normal SetRect import caching and restore period long width/height locals in width-then-height declaration order; test saved-register coloring and frame size. [same emitted code as probe 16]
probe 18 liveness; result=MISMATCH; diff=234; shape=87.55760368663594: H13: test register-qualified width and height locals with the normal SetRect import; this probes whether explicit source register intent recovers the original EBP/EDI allocation. [same emitted code as probe 17]
probe 19 abi; result=MISMATCH; diff=430; shape=73.42342342342343: H14: use period dllimport declarations for all repeated GDI calls, not const function-pointer aliases; test whether the complete Windows API declaration surface matches the original import scheduling.
probe 20 layout; result=MISMATCH; diff=234; shape=87.55760368663594: H15: with normal SetRect import caching, move old_font before str in the local declaration order; test register allocation and stack slots against the original. [same emitted code as probe 18]
probe 21 layout; result=MISMATCH; diff=234; shape=87.55760368663594: H16: place RECT first, then old_font, then str while retaining normal SetRect import caching; test all-local declaration placement for the original stack and register topology. [same emitted code as probe 20]
probe 22 context; result=MISMATCH; diff=430; shape=73.42342342342343: H17: use Windows SDK declarations after removing duplicate local GDI prototypes; test the supported period header basin.
probe 23 liveness; result=MISMATCH; diff=234; shape=87.55760368663594: H18: retain the normal SetRect import and corrected str base, but declare long height before width; test the alternate source declaration order for original EBP/EDI coloring. [same emitted code as probe 21]
probe 24 layout; result=MISMATCH; diff=234; shape=87.55760368663594: H19: restore the natural str, old_font, RECT declaration order after ABI probes; retain the supported normal SetRect import and unshifted str use for final comparison. [same emitted code as probe 23]
probe 25 layout; result=MISMATCH; diff=230; shape=89.40092165898618: H20: reduce the local string to 252 bytes with normal SetRect import caching; test whether this cancels the four-byte import-cache spill while recovering the original sprintf and DrawText stack addresses.
probe 27 layout; result=MISMATCH; diff=644; shape=79.18552036199095: H1: remove named width and height locals; use direct canonical panel members in every rectangle expression to test whether VC5 restores original EBP/EDI dimensions and EBX SetRect cache.
probe 28 liveness; result=MISMATCH; diff=234; shape=87.55760368663594: H2: split width and height declarations from assignments after SetTextColor; test PDB line-banded natural scope and register-color scheduling without unsupported aliases. [same emitted code as probe 26]
probe 29 abi; result=MISMATCH; diff=234; shape=87.55760368663594: H3: narrow only the two local rectangle dimensions from long to int while preserving canonical field layout and normal imported SetRect; test period-width source typing. [same emitted code as probe 28]
probe 30 layout; result=MISMATCH; diff=234; shape=87.55760368663594: H4: restore PDB/Ghidra local declaration order RECT, old_font, str; use the decompiler-supported str+4 destination and text pointer with natural h-then-w declarations.
probe 31 context; result=MISMATCH; diff=234; shape=87.55760368663594: H6: replace synthetic panel gaps with the canonical same-TU TPanel/TRIBE_Panel_Pop field and virtual surfaces from exact 0051D060 donor; use proven pnl_wid/pnl_hgt/render_rect ownership and preserve protected target owner.
probe 32 abi; result=MISMATCH; diff=430; shape=73.42342342342343: H7: use SDK RECT, HDC, HRGN, HGDIOBJ, and natural Windows API declarations across the canonical same-TU class surface; test complete period Win32 ABI basin.
probe 33 layout; result=MISMATCH; diff=234; shape=87.55760368663594: H8: use exact same-TU dimension ownership names and declaration order (height then width), preserving natural repeated rectangle expressions and canonical fields. [same emitted code as probe 31]
probe 34 abi; result=MISMATCH; diff=234; shape=87.55760368663594: H9: use canonical same-TU panel fields but int locals for the rectangle dimensions, matching Ghidra integer temporaries and SetRect ABI. [same emitted code as probe 33]
probe 35 layout; result=MISMATCH; diff=234; shape=87.55760368663594: H10: restore the binary-proven text offset and natural same-TU source form: RECT, old_font, char[256], sprintf/DrawTextA through str+4, canonical width/height fields.
probe 36 layout; result=MISMATCH; diff=416; shape=88.07339449541284: H11: mirror exact Time-panel source scheduling: initialize canonical width/height to field-minus-one, use width/height minus-two for the four border rectangles, then decrement once for the center pass.
probe 37 layout; result=MISMATCH; diff=418; shape=87.61467889908256: H12: explicitly pre-adjust width/height in the binary instruction order (width-=2, height--, width++), then use the adjusted values for all four border rectangles.
probe 38 liveness; result=MISMATCH; diff=295; shape=87.09677419354838: H13: remove tail-only right/bottom aliases and use direct canonical panel expressions to test whether authentic member rereads recover original Used-rectangle scheduling.
probe 39 liveness; result=MISMATCH; diff=234; shape=87.55760368663594: H14: scope width and height to the render-text phase, including the second color call and center pass, to test authentic phase lifetime and register pressure. [same emitted code as probe 35]
probe 42 liveness; result=MISMATCH; diff=234; shape=87.55760368663594: H1: move width and height declarations to the PDB-aligned top local window, as in the analogous time-panel renderer, while preserving direct bounds and all calls. [same emitted code as probe 41]
probe 43 layout; result=MISMATCH; diff=234; shape=87.55760368663594: H2: use the PDB local-symbol order old_font, char[256] str, RECT rect without changing behavior or calls. [same emitted code as probe 42]
probe 44 layout; result=MISMATCH; diff=234; shape=87.55760368663594: H3: test alternate natural local declaration order RECT, char[256] text, old_font to test authentic stack packing without aliases or behavior changes. [same emitted code as probe 43]
probe 45 abi; result=MISMATCH; diff=416; shape=88.07339449541284: H4: mirror the analogous exact-context time-panel integer width/height lifetime and minus-one initialization, preserving all five draw rectangles and ordered calls. [same emitted code as probe 36]
probe 46 liveness; result=MISMATCH; diff=234; shape=87.55760368663594: H5: use natural declaration-initialization for old_font at SelectObject, matching the binary's materialized spill site while preserving cleanup order. [same emitted code as probe 44]
probe 47 context; result=MISMATCH; diff=234; shape=87.55760368663594: H6: restore the SDK tagRECT spelling as a local period-compatible type alias, preserving the same RECT layout, GDI ABI, calls, and fault order.
probe 48 layout; result=MISMATCH; diff=644; shape=79.18552036199095: H7: follow the authentic Ghidra source shape with direct canonical pnl_wid/pnl_hgt expressions for all five SetRect calls, while retaining the proven tail and text offset.
probe 49 liveness; result=MISMATCH; diff=393; shape=79.90867579908675: H8: retain one natural width local and use direct canonical pnl_hgt expressions, testing the target-sized one-local frame without aliases or forced scheduling.
probe 50 layout; result=MISMATCH; diff=393; shape=79.90867579908675: H9: combine the target-sized one-width-local model with PDB local order old_font, str, RECT, testing natural stack packing and the protected text path. [same emitted code as probe 49]
probe 51 liveness; result=MISMATCH; diff=420; shape=86.7579908675799: H10: retain one natural height local and use direct canonical pnl_wid expressions, testing the complementary target-sized frame and register basin.
probe 52 liveness; result=MISMATCH; diff=393; shape=79.90867579908675: H11: move the one natural width declaration to the top local window while keeping its assignment after SetTextColor, testing whether authentic declaration lifetime repairs the sprintf stack home. [same emitted code as probe 50]
probe 53 layout; result=MISMATCH; diff=393; shape=79.90867579908675: H12: scope RECT at the render phase, as suggested by its PDB line band, and keep one width local with direct height rereads; preserve draw and cleanup order. [same emitted code as probe 52]
probe 55 layout; result=MISMATCH; diff=234; shape=87.55760368663594: H15: reverse the natural local declaration order to str, old_font, RECT, testing whether VC5 overlaps old_font with the first unused str dword while preserving all calls, state publication, cleanup, and fault order. [same emitted code as probe 54]
probe 56 layout; result=MISMATCH; diff=232; shape=88.47926267281106: H16: model the proven old-font/string slot overlap as a natural local union with char[256], preserving the PDB-sized buffer, 23 calls, cleanup, publication, and fault order.
probe 57 layout; result=MISMATCH; diff=232; shape=88.47926267281106: H17: reverse the proven overlap union and RECT declaration order to test VC5 local placement, without changing the panel state, ordered calls, cleanup, publication, or fault order. [same emitted code as probe 56]
probe 58 layout; result=MISMATCH; diff=236; shape=83.87096774193549: H18: group the proven RECT plus old-font/string overlap into one natural LocalState aggregate, letting VC5 place the required four-byte top remainder without synthetic padding.
probe 59 liveness; result=MISMATCH; diff=420; shape=86.69724770642202: H19: use natural pre-adjusted width and height locals with the original sub/sub/add/add rectangle expressions, testing whether VC5 recovers EBP/EDI bounds and removes the extra rectangle spill.
```
<!-- end-recovered:360d45a6c70a0e679c0d -->

<!-- recovered:7a5f92cbedbd37c55ab2 -->
### `434b724dbf24` `src/scratch/0051D4F0_render_to_image_buffer.cpp:1-69`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// Attempt log for 0051D4F0 TRIBE_Panel_Pop::render_to_image_buffer
// baseline: typed TPanel-owned fields, TDrawArea calls, GDI calls, and natural
// pop text plus five DrawTextA passes. Frame and early setup match.
// ABI probe: inherited one-argument TPanel::get_string is the correct period
// source surface. It leaves all 23 calls aligned, but sprintf starts 4 bytes high.
// layout probe: PDB local declaration order did not move the string destination.
// liveness probe: direct pop/max members and no named copies were codegen-neutral.
// control-flow probe: reordered Used* tail stores improved resync only; restored.
// rectangle probe: width/height update spelling improved resync but grew the frame;
// restored the natural direct bounds form.
// liveness probe: using str as the old-font spill was an unsupported compiler hack;
// it changed the frame and was restored.
// layout probe: original RECT/old_font/str declaration order was a codegen duplicate;
// restored the clean source.
// layout probe: using str instead of the decompiler's str+4 moved the first hunk
// four bytes earlier and improved shape. The simpler base form is retained.
// ABI probe: a normal imported SetRect reproduces the original repeated EBX call
// surface and reduced the positional diff from 419 to 234 bytes.
// PDB ABI: this is the protected owner
// ?render_to_image_buffer@TRIBE_Panel_Pop@@IAEHXZ, not a public QAE method.
// exact-finish probe: the original stack listing and decompiler show a
// contiguous rect/old-font/text window and text through str + 4. Natural
// str + 4 forms did not reproduce the VC5 stack overlap; they stayed 0x118.
// exact-finish probe: char str[252] with the natural dimension order restored
// the 0x114 frame and reduced the diff to 230, but it conflicts with the
// binary char[256] local evidence and is not retained.
// exact-finish probe: typed local aggregates, unions, old-font aliases,
// declaration scopes, Windows-header declarations, and explicit bound-update
// forms did not improve the supported source. The clean 234-byte candidate is
// restored.
// layout probe: str[252] restored the 0x114 frame and reduced the diff to 230,
// but the smaller buffer is not supported by the local evidence; restored str[256].
// Fresh hard pass: the PDB/Ghidra local window is RECT, old_font, char[256].
// Ghidra also proves that sprintf and all DrawTextA calls use str + 4. Keep
// that partial-output behavior even though the emitted bytes remain in the
// 234-byte basin.
// Fresh hard pass: the exact same-TU TPanel and TRIBE_Panel_Pop surfaces from
// 0051D060 restore canonical pnl_wid/pnl_hgt and render_rect ownership without
// changing output. The SDK Win32 header/API basin was tested and worsened the
// result to 430 bytes, so the narrow imported-call declarations remain.
// Fresh hard pass: Time-panel minus-one bounds, explicit pre-adjustment,
// direct tail member rereads, and a render-phase dimension scope were tested.
// The first two and direct rereads worsened the result; the scope was a codegen
// duplicate. The natural direct-bound form remains the smallest source.
// Exact-finish context pass: PDB symbols prove the protected owner
// ?render_to_image_buffer@TRIBE_Panel_Pop@@IAEHXZ and locals old_font at -0x104,
// str as char[256] at -0x100, and RECT at -0x114. The tagRECT alias retains this
// period SDK type without changing codegen.
// Exact-finish probes: moving dimension declarations, changing local order,
// declaring old_font at initialization, and using the analogous time-panel
// integer or minus-one bounds were duplicate or worse. Direct canonical field
// rereads worsened the body to 644 bytes. One-local width or height forms did
// reach the 0x114 frame, but changed the sprintf home and worsened the body to
// 393 or 420 bytes. All probes preserved the 23-call sequence and cleanup.
// Exact-finish probe H15: reversing the RECT, old_font, and str declarations
// was codegen-neutral. H16: a natural union for the proven old-font/string
// overlap reached the 0x114 frame and 232-byte diff, but did not reach exact
// output and did not match the separate PDB local surface. H17: reversing that
// union and RECT was duplicate. H18: grouping RECT and the union worsened the
// body to 236 bytes. H19: pre-adjusted bounds grew the body to 420 bytes and
// seven bytes past the target boundary. Restore the direct PDB-shaped source.
// BLOCKER: exact 668B remains blocked by the four-byte local-frame placement
// and downstream rectangle scheduling. Calls, ABI, pixel layout, cleanup, and
// fault order are understood.
// TU PASS: the authentic tpnl_pop.cpp wrapper uses PDB owner order and the
// /O2 /Oy /GX response file. It compiled 10 entries: 7/8 exact owners match,
// the generated deleting destructor matches, and the observed target is 430
// bytes different with one boundary escape. The grouped set_rect owner is
// 228 bytes different under shared context. No exact tuning follows this pass.
```
<!-- end-recovered:7a5f92cbedbd37c55ab2 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
