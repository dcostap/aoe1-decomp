// VA: 004AD960 TRIBE_Screen_Sed::command_save_as
// Attempt log:
// baseline: natural scr_sed.cpp reconstruction with the proven scenario world,
// validation gates, and Save Game Screen construction surface.
// probe: default flags omitted the original EH registration (224 bytes, frame 0xE0).
// probe: /GX restored the 0xE4 frame and all 10 ordered calls, but emitted 313 bytes.
// probe: nested/positive guards, returns, gotos, and a do/while were tested; the
// do/while and positive form merged the two popup call sites, while nested negative
// guards returned to the same 313-byte /GX basin.
// probe: pointer-overlay struct added 8 bytes; a union overlay was codegen-neutral.
// blocker: original popup failures jump at 004AD9BD/004AD9EA to one cleanup at
// 004ADA58; VC5 keeps separate /GX cleanup-and-return blocks for the natural source,
// leaving +41 bytes past the original boundary despite matching frame and calls.
// probe: adding the proven polymorphic Save Game Screen base/destructor surface
// preserved the 313-byte basin; the class model is retained for source plausibility.
// probe: scoping scenario_name to the success arm was codegen-identical; the
// function-scope array is retained because the PDB local begins at the function band.
// probe: a named screen result and an explicit success return were codegen-neutral;
// the 313-byte /GX cleanup-tail basin is independent of those source spellings.
// probe: the decompiler's merged stack window was split experimentally; a separate
// 220-byte name tail changed the frame/CFG, while retaining a 224-byte name and
// zeroing/passing its actual base restored the late constructor/panel blocks and
// raised exact-block coverage to 59.70% (the binary supports name[0], not name[4]).
// probe: the natural else-if spelling is codegen-identical to the nested guards.
// probe: adding the exact 004AD700 same-TU command_save declaration after
// command_save_as did not change the /GX cleanup basin or any emitted byte.
// blocker: both popup failure arms still receive duplicated /GX cleanup-and-return
// blocks instead of the original shared jmp tail at 004ADA58; current source is
// retained as the best canonical reconstruction with the late stack/name topology.
// FLAGS: config/flags/004AD960_command_save_as.rsp (/GX; original EH frame and
// same-TU command_save donor both require the historical exception basin).
// Main-agent audit restored canonical world/panel destructor ownership; emitted
// code and the shared-cleanup blocker are unchanged.
// shardE probe: explicit common done labels with goto, including all three
// arms, remained the 313-byte duplicated-EH basin; restored natural source.
// shardE probe: switch-shaped guards worsened to 330 bytes; named boolean
// predicates worsened to 327 bytes; neither changed the shared-tail blocker.
// sa-b7d0516a pass: explicit done goto, do/while-break, positive nested guards,
// positive nested goto, final return, and a null-panel alias were rechecked;
// none changed the best 313-byte basin or restored the shared cleanup tail.
// sa-4131dd60 pass: immediate popup returns, success-only name scope with failure
// gotos, full donor scenario/world virtual surfaces, the SaveScenario enum cast,
// and an empty RAII scope were tested; the first four were codegen-neutral and
// the RAII scope worsened the frame/CFG. Restored the pinned natural source.
// sa-cd410ac2-r1 pass: flat and full screen layout surfaces, explicit base calls,
// enum types, named count results, control-flow labels, period header contexts,
// and symbol-backed panel strings were tested. Only the last source cleanup was
// retained for policy; the shared /GX cleanup-tail blocker remains unchanged.
// sa-e800da1c-r1 revisit: /O1, /G5, /Oy-, and /Ob0 flag probes either lost the
// EH/frame basin or were codegen duplicates. Reviewed popup int/int parameter
// types, canonical panel constructor ownership, scenario-mode and save-screen
// enum surfaces, a for-loop validation form, and an explicit derived destructor;
// none changed the 313-byte basin. A typed validation status reached 272 bytes
// but merged one popup call and lost the original ordered call set. A 64-sample
// ambient declaration context sweep was codegen-identical in all samples.
// sa-e800da1c-r2 focused TU pass: exact same-file command-save context reached a
// 272-byte exact result even with an empty command_save body. Reduction showed
// that the result needs the narrow full-slot T_Scenario and WorldHolder facades;
// removing those surfaces or inheriting RGE_Scenario restored the 313-byte basin.
// The facades conflict with reviewed RGE_Scenario/T_Scenario/RGE_Game_World
// ownership, so the exact result failed policy audit and was not retained.
// Canonical panel ownership, destructor-owned screen members, and world dtor
// declarations did not change that result. Real throw() specifications on the
// screen constructor/destructors and popup call were neutral or removed EH.
// A period stdio.h context was neutral. Final source is restored to the pinned
// natural typed reconstruction; shared /GX cleanup-tail drift remains.
// sa-3397897f-r1 independent audit: direct popup ownership, save-screen base and
// destructor surfaces, scenario/world virtual surfaces, nested allocation scope,
// cached scenario receiver, and <= 0 predicate variants were tested and restored.
// The current source preserves the observed call order, null-allocation path,
// constructor lifetime, panel side effects, and both validation guards. No
// supported semantic or lifetime variant explains the duplicated normal EH exits.
// BINARY NOTE: both popup failure arms jump to 004ADA58, while natural /GX source
// emits two cleanup-and-return tails and adds 41 bytes after the original boundary.
// The original EH handler is the constructor-allocation cleanup at 0055F50E; it
// does not prove a source branch or object-lifetime difference in the popup arms.
// sa-abc15279-r1 audit: named panel, dialog, scenario, and game-world ownership
// now replaces the former narrow facade types. The audit emits the same 313-byte
// /GX body. The original popup target is TEasy_Panel::popupOKDialog(long, char*,
// int, int), and the world field is the proven TRIBE_World surface.
// sa-f048709a-r1 pass: twenty focused probes kept the canonical source and 10 calls.
// Natural save-screen pointer locals, inner construction blocks, and destructor
// visibility changes were codegen-neutral. Full screen member and base-constructor
// declarations were also neutral. Delayed scenario_name declaration and inner
// buffer lifetime were neutral. A 228-byte +4 buffer model widened the frame to
// 0xE8 and lost exact blocks. Positive >0 or >=1 guards merged the two popup calls.
// A can_save status reached 272 bytes but emitted only 9 calls. The original
// negative <1 guards preserve both popup sites. A byte constructor parameter
// reached 307 bytes but lost late exact blocks. Explicit byte extension was neutral.
// Same-TU command_save declaration order was neutral. The historical clean
// 313-byte /GX source lacked the shared normal cleanup tail.

// EXACT FINISH: the PDB-qualified owner is TRIBE_Screen_Sed::command_save_as in
// scr_sed.cpp, lines 3548-3580. The authentic grouped context keeps the real
// earlier 004AD680 scr_sed owner before this definition. Fresh validation gives
// 272 bytes, the 0xE4 EH frame, one ESI save, one reachable boundary, and all
// ten ordered calls. The two popup failures, file-name buffer publication,
// panel changes, constructor cleanup, and final EH exit are byte-identical.
// The target is compiler-owned only by scr_sed_save_as_tu.cpp. The separate
// scr_sed prefix context does not include this body or the 004AD680 body.
// BINARY NOTE: scenario_name[0] and the constructor buffer argument retain the
// shipped malformed-name behavior. Do not move the zero write to a guessed +4.

#include "../../include/scr_sed_context.h"

void TRIBE_Screen_Sed::command_save_as(unsigned char post_action)
{
    char scenario_name[224];

    this->set_scenario_mode(ScenarioModeSave);
    static_cast<T_Scenario*>(this->world->scenario)->Save_victory_conditions_into_players(1);
    if (this->world->scenario->active_player_count() < 1) {
        static_cast<TEasy_Panel*>(this)->popupOKDialog(0x2742, (char*)0, 0x1C2, 100);
    } else if (this->world->scenario->any_player_count() < 1) {
        static_cast<TEasy_Panel*>(this)->popupOKDialog(0x2743, (char*)0, 0x1C2, 100);
    } else {
        scenario_name[0] = 0;
        new TribeSaveGameScreen(TribeSaveGameScreen::SaveScenarioEdit,
                                scenario_name, post_action);
        panel_system.setCurrentPanel(s_Save_Game_Screen, 0);
        panel_system.destroyPanel(s_Scenario_Menu_Dialog);
    }
    return;
}

// Exact translation-unit finish: the real earlier scr_sed.cpp owner at 004AD680
// selects VC5's original shared EH cleanup tail. The grouped build keeps both
// owners once and matches all 272 bytes and ten calls. Target-only compilation
// emits the old 313-byte duplicated-cleanup basin. Dummy and empty definitions
// proved that one prior out-of-line body controls this compiler state; the
// retained group uses the real prior source instead of synthetic context.
// Exact-finish audit supersedes the earlier 313-byte drift note: the grouped
// scr_sed.cpp context now restores the original shared exit and one return.
