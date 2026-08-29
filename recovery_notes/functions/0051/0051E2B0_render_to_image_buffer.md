# Recovery journal: 0051E2B0 `render_to_image_buffer`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tpnl_tim.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tpnl_tim.cpp`.
- Earlier recovery note: `recovery_notes/tpnl_tim_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:3a2a8f427fc4e586c268 -->
### `target-session` `build/target_sessions/0051E2B0_render_to_image_buffer.json:1-65`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=439; shape=90.54054054054055: Baseline existing typed reconstruction; assess original 0x114 frame blocker and current emitted calls before edits.
probe 2 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 1: declare text_flags before old_font/rect/bounds to test original EDI flags and EBP/EBX bounds basin indicated by +01A4 and +01C0. [same emitted code as probe 1]
probe 3 behavior; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 2: restore donor-decomp local order RECT, old_font, str and proven str+4 formatting/drawing destination. Original assembly and decomp both show +4 destination.
probe 5 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 3: use a direct GetDc success guard and assign old_font only from SelectObject, matching decomp's separate pvVar2 and old_font lifetimes. [same emitted code as probe 2]
probe 7 liveness; result=MISMATCH; diff=669; shape=86.55737704918033: Hypothesis 4: remove persistent width/height locals and use direct panel bounds, while retaining one flag temp and decomp-proven str+4. This tests compiler-temp recovery versus current spill basin.
probe 9 context; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 5: use period <stdio.h> declaration for sprintf instead of a local prototype, testing translation-unit declaration context while preserving behavior. [same emitted code as probe 5]
probe 10 abi; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 6: replace the target-local TDrawSystem global view with the reviewed RGE_Base_Game extern surface and world field at +0x3F4.
probe 12 behavior; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 7: apply the decomp-proven four-byte string offset alone, without changing local order or bounds, to separate destination semantics from frame/register effects. [same emitted code as probe 3]
probe 14 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 8: restore the PDB/decomp local declaration order RECT, old_font, str without changing string address semantics, testing local-home and frame allocation independently. [same emitted code as probe 9]
probe 16 liveness; result=MISMATCH; diff=715; shape=74.5928338762215: Hypothesis 9: keep named width/height locals as raw panel dimensions and express all rectangle edges directly as -1/-2/-3, matching the decomp's shared dimension registers and eliminating post-draw decrements.
probe 18 liveness; result=MISMATCH; diff=700; shape=86.68831168831169: Hypothesis 11: direct rectangle bounds to recover the 0x114 frame, plus a branch-local display_value cache to preserve the original rounded-time quotient register basin.
probe 20 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 12: place text_flags immediately before width/height locals, testing whether VC5 colors the long-lived flag in EDI and bounds in EBP/EBX as the oracle does. [same emitted code as probe 14]
probe 22 abi; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 13: type width/height as long to match the proven TPanel long fields and original decomp long arithmetic, testing width semantics without changing control flow. [same emitted code as probe 20]
probe 24 context; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 14: use the proven literal clock format string instead of an unresolved extern, testing string-pool relocation and format declaration context.
probe 26 context; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 15: define the proven tpnl_tim render tag as a local literal rather than an unresolved extern, testing string-pool placement and call relocation context.
probe 28 abi; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 16: qualify get_string through TPanel explicitly, matching the decomp's inherited nonvirtual call surface and testing direct-call identity. [same emitted code as probe 22]
probe 30 layout; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 17: correct the proven +0x10C field ownership from player_id to old_clock_format, preserving the same offset but testing canonical class semantics. [same emitted code as probe 28]
probe 32 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 18: declare old_font at its first real use, after the GetDc/clip setup, to test the proven short old_font lifetime and stack-home placement. [same emitted code as probe 30]
probe 34 abi; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 19: type the persistent DrawText format local as long to test period-compatible API-width typing against the original EDI flag and frame basin. [same emitted code as probe 32]
probe 36 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 20: declare height before width to test whether the original width EBP/height EBX coloring follows local declaration order. [same emitted code as probe 34]
probe 39 context; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 1: replace the narrow TPanel declaration with the canonical full tpnl_tim TPanel surface, add protected render ownership, and test whether authentic virtual/member context restores the oracle frame. [same emitted code as probe 38]
probe 40 layout; result=MISMATCH; diff=440; shape=89.86486486486487: Hypothesis 2: represent the contiguous decompiler old-font/text stack window as a typed local TextStorage aggregate while keeping the canonical full TPanel surface and all 26 calls.
probe 41 layout; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 3: reduce the text local by one dword to test whether the 0x114 oracle frame comes from compiler buffer-span allocation; retained only as an experiment because stack evidence names a 256-byte buffer.
probe 42 layout; result=MISMATCH; diff=436; shape=91.89189189189189: Hypothesis 4: test the next dword reduction of the text local to distinguish the 0x114 frame threshold from the 256-byte source contract.
probe 43 layout; result=MISMATCH; diff=440; shape=81.75675675675676: Hypothesis 5: model the proven contiguous RECT/old-font/text stack window as one period-plausible LocalStorage aggregate, rather than two separate local declarations.
probe 44 layout; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 6: model the text buffer as an 8-byte adjacent prefix plus a 248-byte text field, testing whether the target LEA is a real interior-field address rather than a stack-padding artifact.
probe 45 context; result=MISMATCH; diff=436; shape=91.89189189189189: Hypothesis 7: restore the derived TRIBE_Panel_Time virtual surface by declaring its proven draw override beside the protected render helper. [same emitted code as probe 42]
probe 46 liveness; result=MISMATCH; diff=436; shape=91.89189189189189: Hypothesis 8: combine the 0x114 buffer-span basin with the PDB local declaration order RECT, old_font, str to test whether the target stack homes depend on declaration order only at the frame threshold. [same emitted code as probe 45]
probe 47 liveness; result=MISMATCH; diff=437; shape=91.89189189189189: Hypothesis 9: carry explicit right and bottom aliases through the Used-rectangle stores to test whether the oracle's final register/load schedule comes from persistent adjusted bounds.
probe 48 liveness; result=MISMATCH; diff=436; shape=92.22972972972973: Hypothesis 10: delay right/bottom alias initialization until after the zero and origin stores, testing source lifetime order against the oracle's width/origin preloads.
probe 49 liveness; result=MISMATCH; diff=434; shape=93.91891891891892: Hypothesis 11: reconstruct the final Used-rectangle block with binary-observed width, left, height, top temporaries and update/store order.
probe 50 liveness; result=MISMATCH; diff=434; shape=94.25675675675676: Hypothesis 12: bind final display time, clock format, and clock type in binary-observed load order before the old-state stores.
probe 51 layout; result=MISMATCH; diff=435; shape=93.58108108108108: Hypothesis 13: test the decompiler-indicated old-font/text overlap with a union storage window, while preserving the 26-call behavior and canonical owner.
probe 53 baseline; result=MISMATCH; diff=439; shape=90.54054054054055: Fresh canonical tpnl_tim baseline. Test current PDB RECT, old_font, and char[256] source with full owner context. [same emitted code as probe 52]
probe 54 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 2: declare DrawText format before width and height. PDB line gap allows this natural top-level order, and the oracle keeps format in EDI before bounds load. [same emitted code as probe 53]
probe 55 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 3: declare and initialize width and height at PDB lines 512-513 after SetTextColor. This limits their natural scope and tests whether EDI remains the earlier format carrier. [same emitted code as probe 54]
probe 56 context; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 4: restore period windows.h and stdio.h context with RECT, HDC, HGDIOBJ, HRGN, and COLORREF. Same-TU GDI and PDB locals support these canonical Windows types. [same emitted code as probe 55]
probe 57 layout; result=MISMATCH; diff=464; shape=78.0: Hypothesis 5: use centered adjusted bounds, width=pnl_wid-2 and height=pnl_hgt-2, then draw at plus or minus one. The exact same-TU draw donor uses this source model.
probe 58 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 6: use GetDc only as the status guard and first assign old_font from SelectObject. This preserves the PDB local's real lifetime and the API result fault order. [same emitted code as probe 56]
probe 59 liveness; result=MISMATCH; diff=441; shape=90.20270270270271: Hypothesis 7: spell the binary-observed bound update sequence directly: load width and height, subtract two, decrement height, then increment width. PDB lines 512-515 support this natural update order.
probe 60 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 8: test a period register declaration on the long-lived DrawText format. This checks whether the oracle's EDI format carrier controls the compact 0x114 frame. [same emitted code as probe 58]
probe 61 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 9: reuse one function-scope value for displayed seconds or rounded time, then for DrawText format. The oracle carries seconds in EDI and later carries format in EDI. [same emitted code as probe 60]
probe 63 context; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 10: use the exact preceding tpnl_tim draw owner's local order: old_font, char[256], RECT, format, then bounds. Ghidra stack order does not prove source declaration order. [same emitted code as probe 61]
probe 64 liveness; result=MISMATCH; diff=437; shape=92.9054054054054: Hypothesis 11: combine char[256] with tail locals in the exact oracle load and store order. The packet proves these values, updates, and final state schedule.
probe 67 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 1: place the register-only text_flags declaration before width and height. Original carries EDI flags while EBP/EBX carry bounds; VC5 declaration order can color these independent locals. Keep the PDB-qualified TRIBE_Panel_Time owner, 26 calls, GDI order, cleanup, and publication unchanged. [same emitted code as probe 66]
probe 69 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 2: declare width and height at the PDB line-513 bound block after SetTextColor, while keeping text_flags function-scope. The original 0x114 frame has only RECT, old_font, and char[256] homes; late bounds may stay register-only and restore EBP/EBX allocation without changing calls or cleanup. [same emitted code as probe 67]
probe 71 layout; result=MISMATCH; diff=668; shape=88.19672131147541: Hypothesis 3: remove width/height temporaries and reread canonical pnl_wid/pnl_hgt in each rectangle expression. The PDB frame has only RECT, old_font, and char[256] homes; direct long member expressions test whether the original 0x114 frame and EBP/EBX bounds come from those rereads. Preserve all 26 calls, draw order, cleanup, publication, and fault order.
probe 73 context; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 4: compile the same proven field and call model under a TRIBE_Panel_Pop owner, as requested, to test whether authentic popup naming changes VC5 context while preserving target offsets and behavior. This is an audit only; PDB and dumpbin currently prove TRIBE_Panel_Time IA ownership. [same emitted code as probe 69]
probe 75 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 5: mark the three proven register-only arithmetic locals as register. The target PDB lists only RECT, old_font, and char[256] stack homes, while EDI/EBX/EBP carry flags and bounds. This period-plausible keyword tests register-only allocation without fake volatility or ABI changes. [same emitted code as probe 73]
probe 77 abi; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 6: restore the reviewed RGE_Base_Game global and world ownership instead of the local TDrawSystem alias. The target reads rge_base_game at +0x3F4 to world->game_speed; canonical type spelling may restore authentic symbol context while preserving the x87 argument order, calls, and fault order. [same emitted code as probe 10]
probe 78 abi; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 7: use the canonical RGE_Game_World owner for the +0x18 game_speed read, paired with RGE_Base_Game. The matching tpnl_tim donor uses this period surface; test whether authentic world ownership changes the FPU push schedule or local basin. [same emitted code as probe 77]
probe 79 abi; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 8: type rectangle dimensions as long, matching canonical TPanel pnl_wid/pnl_hgt and the period Win32 long surface. The target EBP/EBX bounds are full dwords; test whether signed long locals alter allocation while preserving the 26-call sequence and GDI cleanup. [same emitted code as probe 78]
probe 81 layout; result=MISMATCH; diff=441; shape=90.20270270270271: Hypothesis 1: recover the PDB-ordered bound update sequence by loading width and height first, subtracting two from width, decrementing height, then incrementing width. This tests the original EBP/EBX arithmetic basin without changing panel fields, calls, cleanup, or fault order.
probe 83 layout; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 2: use the exact donor declaration order old_font, str[256], rect used by the matching tpnl_tim draw owner. This tests whether the 0x114 target local window comes from declaration order while preserving all panel fields, calls, cleanup, and fault order. [same emitted code as probe 80]
probe 84 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 3: scope width and height to the rectangle phase and initialize them at the PDB line-512/513 bound block. This tests whether reduced local lifetime restores the 0x114 local window and EBP/EBX bounds without changing calls, cleanup, or fault order. [same emitted code as probe 83]
probe 86 layout; result=MISMATCH; diff=668; shape=88.19672131147541: Hypothesis 4: remove register width/height aliases and use direct inherited pnl_wid/pnl_hgt expressions for all five SetRect bounds. This tests whether the 0x114 target frame and target address lowering require direct panel fields, while preserving pixel bounds, calls, cleanup, and fault order.
probe 88 layout; result=MISMATCH; diff=436; shape=91.89189189189189: Hypothesis 5: test the only local-size change known to reach the oracle 0x114 frame, char str[248], with the canonical TRIBE_Panel_Time owner, panel fields, 26 calls, cleanup, and fault order. This is an evidence probe only; PDB says char str[256].
probe 91 layout; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 6: use the PDB/Ghidra local order str[256], old_font, rect, distinct from the preceding donor-order test. This tests the authentic stack-local order for the 0x114 frame while preserving canonical owner, panel fields, calls, cleanup, and fault order. [same emitted code as probe 84]
probe 93 behavior; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 7: preserve the binary-proven str+4 destination and text pointer used by the original sprintf and DrawTextA sites. The PDB places char str[256] at Stack[-0x104], while the oracle uses Stack[-0x100] for the text pointer. Test this supported local-address model with unchanged call order, cleanup, and fault order.
probe 94 layout; result=MISMATCH; diff=436; shape=91.89189189189189: Hypothesis 8: combine the binary str+4 address model with the char[248] local-size experiment. This tests whether the 0x114 frame plus the PDB Stack[-0x104] base can recover the oracle text-pointer addresses; char[248] remains a rejected evidence probe because PDB says 256.
probe 96 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 9: apply period register hints to the three register-only rectangle and DrawText locals. The target carries flags in EDI and bounds in EBP/EBX; test whether natural register hints recover that allocation without changing behavior, calls, cleanup, or fault order. [same emitted code as probe 91]
probe 98 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 10: reorder the three scalar locals to text_flags, width, height so VC5 may color the long-lived DrawText flags in EDI and bounds in EBP/EBX as the oracle does. No panel fields, calls, cleanup, or fault order changed. [same emitted code as probe 96]
probe 100 liveness; result=MISMATCH; diff=441; shape=90.20270270270271: Hypothesis 11: declare and initialize width/height at the PDB line-512/513 block, then use the binary-supported sub-two/decrement/increment sequence. This tests late local introduction and exact arithmetic source shape together, without changing panel fields, calls, cleanup, or fault order. [same emitted code as probe 81]
probe 102 liveness; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 12: reuse the clock value local as the later DrawText flags carrier. The oracle keeps current_display_value in EDI and then overwrites EDI with 0x20/0x22; this natural phase reuse tests that proven register lifetime while preserving the panel ABI, calls, cleanup, and fault order. [same emitted code as probe 98]
probe 105 layout; result=MISMATCH; diff=439; shape=90.54054054054055: Hypothesis 1 of resumed claim: use the exact PDB local symbol order old_font, str[256], rect, matching the exact tpnl_tim draw donor. The prior final source used str, old_font, rect. Test whether authentic debug-local order changes the 0x11C frame or register basin. [same emitted code as probe 104]
```
<!-- end-recovered:3a2a8f427fc4e586c268 -->

<!-- recovered:6499d39e4bc6d0a291fc -->
### `434b724dbf24` `src/scratch/0051E2B0_render_to_image_buffer.cpp:1-45`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// Fresh typed reconstruction: TDrawArea::PtrClear/SetClipRect, typed image
// rects, direct panel fields, and the ordered GDI calls match the donor family.
// Probe: natural /60 remainder operators introduced idiv and were rolled back.
// Probe: direct quotient and subtraction spelling retained the original magic
// divide, but did not move the quotient into the original ECX basin.
// Probe: named width/height bounds improved the body to 911 bytes and 436
// positional diff bytes. The frame grew to 0x11c and GDI argument stores remain.
// Probe: declaration order, register locals, and width-minus-two spelling were
// duplicates or slightly worse. The clean named-bounds form is retained.
// Probe: UsedScreenRect uses the TPanel render_rect origin, not panel size;
// this is required by the original +8c/+90 reads. Store order was also aligned.
// Probe: direct typed pnl_wid/pnl_hgt bounds restored the 0x114 frame without
// padding, but made VC5 cache GDI imports and expanded the body; rolled back.
// Probe: unsigned int text_flags matched the DrawText format ABI but emitted
// duplicate 0x11c/931-byte code; restored the int local.
// Canonical-context probe: the full TPanel virtual/member surface, the derived
// draw slot, and protected IA ownership changed no emitted bytes; retain them.
// Exact-finish probes: TextStorage aggregates and an old-font/text union did
// not repair the frame or stack homes. A 248-byte buffer reached 0x114/436,
// but the binary local evidence requires char[256] and it is not retained.
// Exact-finish probes: binary-ordered Used-rectangle aliases improved the
// final scheduling basin to 434 bytes, but still required the unsupported
// 248-byte buffer. The PDB-order char[256] source is restored below.
// Managed reassessment: the clean source has 26/26 ordered calls and 8/8 CFG
// signals, but emits 931 bytes, a 0x11c frame, EDI/EBX bounds, and EBP flags;
// the oracle has 916 bytes, a 0x114 frame, EBP/EBX bounds, and EDI flags.
// Managed reassessment: direct bounds removed the extra frame bytes (917 or
// 923 bytes), but changed the quotient basin at +0xbc and raised the diff.
// Twenty source, ABI, layout, lifetime, and context probes found no better
// clean result. Keep the typed source and do not pad the frame.
// Fresh exact pass: windows.h GDI types, GetDc guard lifetime, exact-donor
// declaration order, bound scopes, register spelling, and value reuse were
// codegen duplicates. The centered-bound model grew to 955 bytes and 0x120.
// Fresh exact pass: char[256] with binary-ordered tail locals emitted 923
// bytes and a 0x11c frame. It improved tail shape but did not swap EBP/EDI.
// The two extra bound-argument spills occupy the eight bytes below old_font.
// PDB OWNER NOTE: cvdump and the original symbol table prove
// ?render_to_image_buffer@TRIBE_Panel_Time@@IAEHXZ at 0051E2B0. A Pop-owner
// compile kept the same bytes but failed the owner-symbol check. Do not rename
// this owner to TRIBE_Panel_Pop.
// Specialist finish: declaration order, register locals, canonical RGE world
// types, long bounds, direct member bounds, and the Pop-owner audit were tested.
// The canonical RGE type surface is retained when it emits duplicate bytes.
// BLOCKER: original frame is 0x114 with EBP/EBX bounds and EDI flags; current
// typed source uses a 0x11c frame with a different local/register basin.
```
<!-- end-recovered:6499d39e4bc6d0a291fc -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
