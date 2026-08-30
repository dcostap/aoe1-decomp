# Recovery journal: 00493D60 `TRIBE_Screen_Game`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_game.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_game.cpp`.
- Earlier recovery note: `recovery_notes/scr_game.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## 2026-08-30 proved constructor corrections

- Removed the early `reset_after_update = 0` store. The constructor sets this
  field to `1` only after the initial string reads, as shown by the original
  write sequence.
- Initialized `cheat_code_entry` before clearing
  `cheat_code_entry_str[0]`, matching the original member-store order.
- Replaced the pause-path `set_game_mode(6, 0)` call with the proved
  `set_prog_mode(6)` call. This preserves the original direct target and
  argument count.
- Baseline checkpoint `probe-058-baseline`: MISMATCH, 5866 rebuilt bytes,
  4770 strict differing bytes, 0x210 frame, 180 calls, and boundary
  00493D60-00495442. The current translation-unit source has unrelated
  structural drift before this correction.

## Final validation for this assignment

- Checkpoint `probe-059-control-flow` is MISMATCH, but the corrected build is
  5859 bytes with a 0x210 frame and 180 aligned calls. The owner symbol and
  boundary are correct: `00493D60-00495442`.
- The original and rebuilt initialization bands both write the dword at
  `this + 0x734` before the byte at `this + 0x738`. The early write at
  `this + 0x7A4` is absent, and the later `reset_after_update = 1` remains.
  This preserves the proved write and fault order.
- The pause tail now has `push 6` followed by the original virtual slot
  `+0x0C` call. It then writes `world->temp_pause`, in the original order.
- The target still differs by 1444 positional bytes because the live natural
  translation unit has four unrelated direct relocation target differences.
  These are outside this assignment and are not repaired here.
- Grouped audit: `build/audits/workers/sa-0dfb99b9-r1/scr_game/report.txt`.
  It compiled all 96 included functions and 65 registered owners. Immediate
  neighbors `004954A0`, `004959A0`, `004959B0`, and `00495A90` remain MATCH.
  Existing TU drift leaves other registered functions mismatched; this audit
  found no target boundary error.

## Recovered attempt history


<!-- recovered:fc869aacecb0527f4e03 -->
### `target-session` `build/target_sessions/00493D60_TRIBE_Screen_Game.json:1-33`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=3154; shape=98.82498453927025: Baseline current scratch source: size/frame/calls/CFG match; strict diff 3154 bytes, first mismatch +037E; draw-loop and later constructor region are current codegen frontier.
probe 2 layout; result=MISMATCH; diff=3256; shape=98.39307787391841: Hypothesis 1: model proven 0x69e-0x6b2 packed animation palette as seven 3-byte AnimPalEntry records, using direct typed table stores instead of OFF8 scalars. This tests source ownership and compiler scheduling for the tail.
probe 4 layout; result=MISMATCH; diff=3142; shape=99.07292954264524: Hypothesis 2: use direct typed AnimPalEntry member expressions at the proven 0x69e table base, without a long-lived table pointer. This tests whether packed field ownership can recover original byte-store scheduling without frame pressure.
probe 5 layout; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 3: preserve the Ghidra/source memory order for the typed 3-byte palette fields: preload 0x69f/0x6a1/0x6ad/0x6b1, load time-panel receiver, then store 0x69e through 0x6b2. This tests declaration/evaluation order as the tail codegen cause.
probe 7 layout; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 4: promote the proven 0x69e-0x6b2 palette table into TRIBE_Screen_Game as seven packed 3-byte AnimPalEntry members, split around the raw gaps, and use the original memory-order writes. This tests true owning-member layout versus cast overlays.
probe 8 liveness; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 5: use the same OFF32(0x20) draw-area spelling for the inventory constructor as the object and button constructors. This tests whether the original register color (ECX draw area, EAX font) depends on raw field-expression form.
probe 9 abi; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 6: use the period-derived TRIBE_Player* parameter type and an explicit derived-pointer cast for TRIBE_Panel_Inven. This tests whether the original constructor ABI type surface changes register scheduling.
probe 10 liveness; result=MISMATCH; diff=3812; shape=98.8875154511743: Hypothesis 7: cache the proven screen draw-area pointer in a local immediately before the inventory allocation and pass that local. This tests whether address liveness forces the original ECX/EAX argument colors.
probe 12 control-flow; result=MISMATCH; diff=3336; shape=98.14929056138186: Hypothesis 8: split the nested draw-button get_string expression into explicit draw_id and draw_text locals after the draw-type byte store. This tests whether the original compiler scheduled the nested receiver and output-buffer setup as separate source statements.
probe 13 context; result=MISMATCH; diff=3336; shape=98.14929056138186: Hypothesis 9: restore the period-standard <string.h> translation-unit declaration context while retaining the explicit extern C prototypes. This tests whether VC5 front-end context controls the constructor's REP zeroing and downstream schedule. [same emitted code as probe 12]
probe 15 abi; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 10: expose BaseGameStub::get_player as the period-derived TRIBE_Player* return type and add explicit base-pointer casts only at consumers that require RGE_Player*. This tests whether return-type provenance controls the inventory call's register colors.
probe 17 abi; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 11: declare TButtonPanel::setDrawType with the proven period enum DrawType and call its DrawTextA enumerator, instead of an int proxy. This tests whether the enum ABI decoration and source type surface reduce direct-call or scheduling drift.
probe 18 variant; result=MISMATCH; diff=3154; shape=98.82498453927025: variant lab build\variant_lab\00493D60_TRIBE_Screen_Game\20260817_155306: 8 variants, 0 invariant-eligible, 0 exact
probe 20 abi; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 12: rename the local BaseGameStub ABI surface to the reviewed RGE_Base_Game class and use that type in the draw-loop absolute fallback. This tests whether direct-call and global relocation identity, not behavior, is the remaining mismatch source.
probe 21 abi; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 13: combine the correctly named RGE_Base_Game ABI surface with the reviewed extern rge_base_game expression in the draw loop. The prior raw fallback used an accumulator load; this tests the canonical global relocation and register basin together.
probe 22 abi; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 14: correct the reviewed TShape constructor second parameter from int to long, as proved by the Shape.cpp PDB/decompiler surface. This tests direct constructor symbol identity without changing 32-bit call behavior.
probe 23 abi; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 15: correct TPanel::set_help_info parameters from int to the proven long,long ABI. This tests direct call decoration and preserves identical 32-bit argument lowering.
probe 24 abi; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 16: correct TPanel::set_z_order's second parameter from int to the proven short ABI. This tests direct call decoration while preserving the same 32-bit push.
probe 25 abi; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 17: correct TScreenPanel::setup's resource ID parameter from int to the proven long ABI. This tests direct setup-call decoration while preserving the same immediate argument.
probe 26 abi; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 18: correct TButtonPanel::set_text to the proven short,long ABI and cast its pointer-like text arguments to long. This tests direct call decoration and original pointer-as-long argument lowering.
probe 30 liveness; result=MISMATCH; diff=3720; shape=98.51668726823239: Hypothesis 1: materialize the inventory player, then the screen draw-area pointer, before the constructor. This tests whether explicit source sequencing recovers the original post-get_player draw-area read before font->font.
probe 32 liveness; result=MISMATCH; diff=3970; shape=98.76390605686032: Hypothesis 2: materialize only the inventory get_player result before the constructor. This tests whether a named player local lets VC5 preserve the original draw-area load between get_player and font->font without introducing a draw-area local.
probe 34 abi; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 3: use the matching TRIBE_Panel_Inven ABI surface (void* font, TRIBE_Player* player) with the proven explicit player cast. This tests whether constructor parameter provenance changes VC5 argument-load scheduling while preserving the known call target.
probe 35 liveness; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 4: split the first inventory font declaration from its get_font assignment. This tests the documented VC5 declaration/initialization scheduling axis around the constructor argument loads. [same emitted code as probe 34]
probe 37 control-flow; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 5: place a binary-supported draw-area reread in the font argument's comma expression. This tests whether explicit evaluation sequencing recovers the original get_player, draw-area, font order without a separate local. [same emitted code as probe 18]
probe 39 abi; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 6: restore the reviewed void* font ownership across RGE_Font and all panel font parameters. This tests canonical period ABI typing beyond the inventory constructor while preserving identical pointer widths and call surfaces.
probe 41 liveness; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 7: remove the inventory block scope so the constructor result local remains function-scoped. This tests whether original local lifetime or reuse controls the downstream register topology. [same emitted code as probe 29]
probe 43 control-flow; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 8: express the three draw-button iterations with a signed positive bound instead of an explicit nonzero test. This tests the natural loop predicate that controls the observed dec/jne topology. [same emitted code as probe 41]
probe 45 abi; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 9: use a void* first parameter only for TRIBE_Panel_Inven. This tests whether the draw-area parameter's incomplete type surface controls the observed ECX/EDX argument-load topology.
probe 47 layout; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 10: store the inventory allocation in a TPanel* local, matching the decompiler's proven base-owner use for error and help calls. This tests whether the source-facing static type changes the constructor argument scheduling. [same emitted code as probe 43]
probe 49 liveness; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 11: declare the reusable RGE_Font* at constructor scope and assign it after map setup, matching the decompiler's function-local font lifetime. This tests whether declaration scope changes the persistent register topology. [same emitted code as probe 47]
probe 51 liveness; result=MISMATCH; diff=3154; shape=98.82498453927025: Hypothesis 12: move the 512-byte string buffer declaration to constructor scope, matching the decompiler's function-local stack object. This tests whether early declaration scope changes stack-home reuse and later draw-button scheduling. [same emitted code as probe 49]
probe 54 context; result=MISMATCH; diff=3154; shape=98.88613861386139: Fresh standalone baseline after restoring the original local scr_game surface: 5858 bytes, 180 calls, 0x210 frame, strict diff 3154, first mismatch +0x37E. The shared scr_game_context layout changes world access and is not retained.
```
<!-- end-recovered:fc869aacecb0527f4e03 -->

<!-- recovered:0d1b2c3b2731a7737c1c -->
### `7f9d273d677d` `src/scratch/00493D60_TRIBE_Screen_Game.cpp:1-106`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00493D60 TRIBE_Screen_Game::TRIBE_Screen_Game
// Starting point copied from the repo-local Ghidra approximation in
// orig/ghidra_decomp/scr_game.cpp.decomp.  This file intentionally keeps the
// raw offset surface first: TRIBE_Screen_Game's working shared layout is not yet
// promoted, and this constructor is large enough that a compiling behavioral
// baseline is more useful than speculative pretty fields.
// pass 1: established a compiling constructor skeleton through the pre-setup
// initialization band (PDB lines 201-232) plus the first setup call.
// pass 2: grew through button TShape loading, main/map view construction,
// inventory/object panels, command button allocation, and first message/time
// panels.
// pass 3: added chat panels, age/fps panels, score panels, toolbox creation,
// z-order/curr-child/timer startup tail, pause flag, and raw anim-pal bootstrap.
// pass 4: copied more of the Ghidra constructor tail: detailed command-button
// text/bevel setup, pause/quit and log text widgets, toolbox tail calls, player
// change/clock/score startup, and PAUSE argument side effects.
// current: exact early initialization through the first setup/test band (first
// mismatch is now the downstream failure-branch displacement after offset 0x37e,
// not frame size); TShape size, cached world/draw-area uses, toolbox sound temp,
// direct text/log field out-params, virtual TPanel::setup for message panels,
// raw Ghidra-style message-panel validation, age/fps split setup failures,
// alignment enum values, and score font slot reuse are durable wins.
// pass 5: fixed TButtonPanel::set_id surface from 4 params to 3 after original
// command-button setup showed only three pushes per call; identified
// rge_base_game->get_string(int,int,int,char*,int) as vtable+0x28 dispatch
// instead of direct. Keeping direct draw_buttons reloads plus the 3-param set_id
// signature improved edit diff to ~6.04%, with remaining draw-button loop drift
// in scheduling/byte-register order. Palette-tail lab variants (int/uchar/
// signed/immediate constants), pal3f/pal7b declaration-order swap, a volatile
// 0x5f store, and comma-operator scheduling in the get_string str argument all
// collapsed to the same emitted code or worsened diff, so they were rolled back.
// Additional rolled-back probes: explicit game_for_text/str_arg locals around
// get_string widened edit diff (~6.50%); per-iteration button local widened it
// badly (~16.30%); inven_area local for the inventory-panel constructor widened
// it badly (~23.83%); casting font->font through *(TFont**)font, making the
// 0x69c palette word store volatile, and moving pal27 between the palette word
// stores emitted the same code. Modeled TButtonPanel byte +0x2c0 as a local
// field (same code, but documents the observed layout). Additional draw-loop
// probes: &str[0], sizeof(str), str_arg local, button temp, comma-store in the
// get_string str arg, volatile +0x2c0 store, and draw_buttons[0] spelling all
// emitted the same current loop; game_for_text local after the byte store fixed
// the following bevel register cycle but widened get_string scheduling/spilled
// the game pointer, worsening edit diff to ~6.21% (before-store form ~6.50%).
// Kept a raw load through *(BaseGameStub**)0x62c574 for this loop's get_string
// call: behavior is the same stable rge_base_game global, but avoiding the
// object relocation on these two loads reduces edit diff to 349 / 5.9566%.
// It still uses eax (original uses edx) and the loop remains one byte short.
// 2026-05-12 pass: revalidated current baseline (edit diff 349 / 5.9566%).
// Rolled back: per-iteration button local (widened to 15.79% edit), normal
// rge_base_game get_string in draw loop (6.04%), buffer cast / str+(i-i) no
// change, volatile palette stores worsened to 6.23%. Palette source-order tweak
// around pal27 emitted identical code; remaining durable gap is still draw-loop
// get_string scheduling/bevel arg register cycle plus palette-store scheduling.
// Follow-up lab: comma_str/comma_zero/comma_id/split_outer draw-loop variants all
// collapsed to baseline; temp_id became a much worse 1688 edit diff. Forcing
// game_for_text before setDrawType widened to ~14.85%; volatile global load and
// post-store game local both widened to ~6.21%. Flag probes /O1 and /Os emitted
// undersized text; /Ob0 widened badly; /Gf no change. Palette pal7b arithmetic
// or late declaration still collapsed to baseline.
// 2026-08-13 shardA6-493D60-r1: naming the screen draw area before the inventory
// panel constructor was a natural ownership probe, but added 4 bytes and widened
// the positional diff from 3154 to 3999. Restored the clean reconstruction.
// 2026-08-13 orch-493D60-a: named TPanel+0x20 draw_area, used TRIBE_Player for
// inventory, typed the button array as TRIBE_Panel_Button**, and added stdio;
// each emitted the baseline code. Restored the clean source.
// 2026-08-13 orch-493D60-a: draw-loop lab tested baseline, plus4, count-local,
// buffer-local, split, and comma forms. Baseline, plus4, and split grouped.
// The count-local form was much worse. No source-backed lead remains.
// 2026-08-13 orch-493D60-a: proven string-address macros kept strict diff at
// 3154 and improved resync only. Restored named globals and clean source.
// 2026-08-17 sustained pass: twenty meaningful probes completed. The clean
// baseline remains authoritative: size 5859, frame 0x210, 180 calls, and
// strict diff 3154 bytes. The first mismatch is +0x37E. Edit cost is 577.
// BINARY NOTE: offsets 0x69E-0x6B2 are seven packed three-byte palette entries.
// A typed table improved one local metric to 3142, but lost seven code bytes.
// It was not retained because its structural result was worse.
// BINARY NOTE: the draw loop loads the game vtable through EDX in the original.
// The clean source uses the raw global fallback and still loads it through EAX.
// This remains the strongest codegen lead. Address and temporary variants failed.
// Tested and rolled back: typed palette ownership, palette statement order,
// draw-area locals, staged draw text values, standard headers, and ABI proxies.
// Proven ABI forms tested without emitted changes include RGE_Base_Game,
// TShape(char*,long), set_help_info(long,long), set_z_order(unsigned char,short),
// TScreenPanel::setup(...,long,int), and TButtonPanel::set_text(short,long).
// LIKELY INTENT: the remaining drift is a historical source or compiler-context
// difference around draw-button argument scheduling and palette initialization.
// BLOCKER: For the inventory-panel constructor, the executable reads the screen
// draw area before font->font. The rebuild reads font->font first. Constructor
// arguments and all 180 calls match, but invalid-pointer fault order differs.
// 2026-08-22 claim sa-db4c643e: tested player and draw-area locals, canonical
// void* font ABI surfaces, comma sequencing, loop predicates, local scopes,
// base-pointer ownership, and a function-scope string buffer. The player and
// draw-area locals worsened structure or call order. Other probes emitted the
// clean 5859-byte baseline with diff 3154. Restored the clean source.
// 2026-08-23 subagent sa-727c2e97: fresh validation kept this standalone
// scr_game.cpp owner. The grouped scr_game_context surface moved the base-game
// world field by four bytes and changed message-panel setup calls. It was not
// retained. The local TPanel surface now follows the proven full slot order
// and size. Panel constructors use reviewed pointer and long types.
// TRIBE_Main_View now uses its implicit constructor. This removes the old raw
// constructor pointer write. A typed AnimPalEntry trial reproduced more original blocks but
// lost seven bytes. It was restored because exactness is the first gate.
// Final unresolved evidence: one byte is missing. The ordered 180-call list,
// frame, saved registers, owner symbol, and CFG signals match. Inventory and
// object constructor loads remain reordered. The draw loop still loads the
// game receiver through EAX, not EDX. Do not claim exactness.
```
<!-- end-recovered:0d1b2c3b2731a7737c1c -->

<!-- recovered:731a2b14c4dfa67349ed -->
### `7f9d273d677d` `src/scratch/00493D60_TRIBE_Screen_Game.cpp:574-575`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // Raw palette/bootstrap bytes from the tail of the Ghidra approximation.
    // Keep raw until the packed anim-pal structs are proven.
```
<!-- end-recovered:731a2b14c4dfa67349ed -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
