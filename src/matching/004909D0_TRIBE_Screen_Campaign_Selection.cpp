// VA 004909D0 TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection
// scr_cams.cpp:48-125
// Attempt log:
// 1: Natural constructor from packet/decompiler, with /GX expected for EH frame.
// 2: Added TScreenPanel/TEasy_Panel inheritance and create_text/list/scrollbar/dropdown/button surfaces; first build exact size but broad due base size wrong.
// 3: Added TPanel 0xF0 payload so derived member offsets land at +0x478..+0x4C8; mismatch improved to 17.57%, first mismatch branch displacement near first create_text failure target.
// 4: Removed explicit tabList[0]=this after base ctor; this eliminated an extra mov after EH state and improved to 17.57% -> 17.57% with first mismatch later (offset 202), matching the main constructor body through early widget creation.
// 5: Modeled virtual set_string at vtable +0xE4 and close-button virtual calls at +0x14/+0x18; direct call order now matches large middle region.
// 6: Tried local cancel pointer for hotkey/hotkey_shift before close-button creation; compiler delayed stores across argument pushes and shifted close-button block.
// 7: Tried closePtr local for &close_button; no codegen change.
// 8: Found tab-order source needs five entries plus a cancel-button value in the adjacent local slot; array[6]/out-of-bounds tabList[5] improved body to 2.6679% but forced stack frame sub esp,1C instead of original sub esp,18.
// 9: Tried removing cancel local/direct cancelButton hotkey stores; stack stayed 1C or broad block regressed.
// 10: Tried separate cancelTab local instead of tabList[5]; restored sub esp,18 but lost the near-exact tab-order block, leaving 12.5115% mismatch, first mismatch offset 202.
// 11: Replaced cancelTab and the decompiler index order with one late five-element TPanel array in campaign, scenario, dropdown, cancel, ok slot order; set_tab_order now receives its base. This restored the original frame and reduced the mismatch to 13 bytes.
// 12: Aggregate initialization, assignment permutations, and late declaration checks did not change the 13-byte result or improve the clean source model.
// 13: Restored the binary-backed TButtonPanel* surface for ok/close outputs and
//     removed generic create_button output casts, following the exact same-TU
//     screen donor; this is the direct first-hunk type lead for cancel/ok loads.
//     Result: unchanged 13-byte mismatch and unchanged +03D4 load order; keep
//     the typed form as the more canonical source reconstruction.
// 14: Tested a late tabCancel alias; VC5 emitted the same 13-byte mismatch.
// 15: Tested named tabCancel/tabOk aliases through tab order and current-child;
//     this caused a broad 569-byte drift and was restored.
// 16: Ran a focused direct/aggregate/typed tab-array variant lab; no invariant
//     candidate was produced, and the lab template lacked the target /GX setup.
// 17: Reused the existing cancel hotkey local for tabList[3]; frame grew to
//     0x1C with a 201-byte drift, so the clean source was restored.
// 18: Swapped the final tab entries to the binary-backed order OK then Cancel;
//     VC5 emitted the original cancel/OK load schedule and matched exactly.
// 19: Declared the proven virtual derived destructor surface and removed the
//     raw vtable store; VC5 emitted its compiler-owned derived vtable store
//     with unchanged exact output.
// EXACT: 1087 bytes, 0.0000%; direct call relocations and function boundary
// validated. The five-entry tab order is campaign, scenario, difficulty, OK,
// then Cancel, matching the original stack writes and source behavior.
// FLAGS: /GX
// POLICY: the derived vtable is now compiler-owned through the virtual
// destructor declaration proven by same-class exact donors.

#include "../../include/scr_cams_context.h"

TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection()
    : TScreenPanel("Campaign Selection Screen")
{
    init_vars();
    if (!setup(rge_base_game->draw_area, "scr2", 0xC384, 1)) {
        *(int*)((char*)this + 0xD8) = 1;
        return;
    }
    setup_shadow_area(0);
    set_ideal_size(0x280, 0x1E0);
    if (create_text((TPanel*)this, &title, 0x2BCD, 0x14, 10, 600, 0x1E, 1, 1, 0, 0)) {
        campaignListX = 0x14; campaignListY = 0x46; campaignListWidth = 600; campaignListHeight = 0x82;
        if (create_list((TPanel*)this, (TPanel**)&campaignList, 0x14, 0x46, 600, 0x82, 0x0B)) {
            if (create_auto_scrollbar(&campaignScrollbar, campaignList, 0x14)) {
                if (create_text((TPanel*)this, &campaignTitle, 0x2BCE, campaignListX - 5, campaignListY - 0x14, 200, 0x14, 4, 0, 0, 0)) {
                    campaignList->set_string(0x2B5D);
                    scenarioListX = 0x14; scenarioListY = campaignListY + campaignListHeight + 0x1E; scenarioListWidth = 600; scenarioListHeight = 0x82;
                    if (create_list((TPanel*)this, (TPanel**)&scenarioList, scenarioListX, scenarioListY, scenarioListWidth, scenarioListHeight, 0x0B)) {
                        if (create_auto_scrollbar(&scenarioScrollbar, scenarioList, 0x14)) {
                            if (create_text((TPanel*)this, &scenarioTitle, 0x25FE, scenarioListX - 5, scenarioListY - 0x14, 200, 0x14, 4, 0, 0, 0)) {
                                scenarioList->sort_flag = 0;
                                if (create_text((TPanel*)this, &difficultyTitle, 0x2BCF, 0x0F, 0x172, 200, 0x14, 4, 0, 0, 0)) {
                                    if (create_drop_down((TPanel*)this, (TPanel**)&difficultyDrop, 0x82, 100, 0x14, 0x186, 0x82, 0x18, 0x0B)) {
                                        difficultyDrop->empty_list();
                                        difficultyDrop->append_line(0x2BD4, 4);
                                        difficultyDrop->append_line(0x2BD3, 3);
                                        difficultyDrop->append_line(0x2BD2, 2);
                                        difficultyDrop->append_line(0x2BD1, 1);
                                        difficultyDrop->append_line(0x2BD0, 0);
                                        difficultyDrop->set_line(difficultyDrop->get_line(rge_base_game->difficulty()));
                                        if (create_button((TPanel*)this, &okButton, 0x0FA1, 0, 0x46, 0x1B8, 0x0F0, 0x1E, 0, 0, 0)) {
                                            if (create_button((TPanel*)this, &cancelButton, 0x0FA2, 0, 0x14A, 0x1B8, 0x0F0, 0x1E, 0, 0, 0)) {
                                                TButtonPanel* cancel = cancelButton;
                                                cancel->hotkey = 0x1B;
                                                cancel->hotkey_shift = 0;
                                                if (create_button((TPanel*)this, &close_button, 0x03EA, 0, 0, 0, 0, 0, -1, -1, 0)) {
                                                    close_button->set_active(1);
                                                    close_button->set_positioning(9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
                                                    TPanel* tabList[5];
                                                    tabList[0] = campaignList;
                                                    tabList[1] = scenarioList;
                                                    tabList[2] = difficultyDrop;
                                                    tabList[3] = okButton;
                                                    tabList[4] = cancelButton;
                                                    set_tab_order(tabList, 5);
                                                    set_curr_child(okButton);
                                                    fillCampaigns();
                                                    fillScenarios();
                                                    set_curr_child(campaignList);
                                                    campaignsLoaded = 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
