#include "../include/TRIBE_Screen_Campaign_Selection.h"
#include "../include/TRIBE_Screen_Name.h"
#include "../include/TRIBE_Game.h"
#include "../include/TCommunications_Handler.h"
#include "../include/RGE_Game_Info.h"
#include "../include/RGE_Base_Game.h"
#include "../include/T_Scenario.h"
#include "../include/TPanelSystem.h"
#include "../include/TButtonPanel.h"
#include "../include/TDropDownPanel.h"
#include "../include/TListPanel.h"
#include "../include/TScrollBarPanel.h"
#include "../include/TTextPanel.h"
#include "../include/globals.h"

#include <stdlib.h>
#include <string.h>

static void cams_init_vars(TRIBE_Screen_Campaign_Selection* this_) {
    // Fully verified. Source of truth: scr_cams.cpp.decomp @ 0x00490E30
    this_->title = nullptr;
    this_->campaignTitle = nullptr;
    this_->campaignList = nullptr;
    this_->campaignScrollbar = nullptr;
    this_->scenarioTitle = nullptr;
    this_->scenarioList = nullptr;
    this_->scenarioScrollbar = nullptr;
    this_->difficultyTitle = nullptr;
    this_->difficultyDrop = nullptr;
    this_->okButton = nullptr;
    this_->cancelButton = nullptr;
    this_->close_button = nullptr;
    this_->campaignsLoaded = 0;
    if (rge_base_game) {
        rge_base_game->setDifficulty(rge_base_game->single_player_difficulty);
    }
}

static void cams_fillCampaigns(TRIBE_Screen_Campaign_Selection* this_) {
    // Fully verified. Source of truth: scr_cams.cpp.decomp @ 0x004911A0
    if (!this_ || !this_->campaignList) return;

    this_->campaignList->empty_list();

    char** campaigns = nullptr;
    long curr_index = 0;
    const long count = (rge_base_game && rge_base_game->player_game_info)
        ? rge_base_game->player_game_info->get_campaign_list(&campaigns, &curr_index)
        : 0;

    if (count != 0 && campaigns) {
        this_->campaignList->handle_mouse_input = 1;
        for (long i = 0; i < count; ++i) {
            this_->campaignList->append_line(campaigns[i], i);
        }

        const long line = this_->campaignList->get_line(curr_index);
        this_->campaignList->set_line(line);

        for (long i = 0; i < count; ++i) {
            free(campaigns[i]);
        }
        free(campaigns);

        const long cur_line = this_->campaignList->get_line();
        if (cur_line != -1 && rge_base_game && rge_base_game->player_game_info) {
            const long id = this_->campaignList->get_id();
            rge_base_game->player_game_info->set_current_campaign(id);
        }
    }
}

static void cams_fillScenarios(TRIBE_Screen_Campaign_Selection* this_) {
    // Fully verified. Source of truth: scr_cams.cpp.decomp @ 0x00491290
    if (!this_ || !this_->scenarioList) return;

    this_->scenarioList->empty_list();

    char** scenarios = nullptr;
    long curr_index = 0;
    const long count = (rge_base_game && rge_base_game->player_game_info)
        ? rge_base_game->player_game_info->get_scenario_list(&scenarios, &curr_index)
        : 0;

    if (count != 0 && scenarios) {
        for (long i = 0; i < count; ++i) {
            this_->scenarioList->append_line(scenarios[i], i);
        }

        const long line = this_->scenarioList->get_line(curr_index);
        this_->scenarioList->set_line(line);

        for (long i = 0; i < count; ++i) {
            free(scenarios[i]);
        }
        free(scenarios);

        this_->scenarioList->scroll_cur_line('\a', 0, 1);
    }
}

static void cams_startGame(TRIBE_Screen_Campaign_Selection* this_) {
    // Best-effort transliteration. Source of truth: scr_cams.cpp.decomp @ 0x00491350
    if (!this_ || !rge_base_game) return;

    const long line = this_->scenarioList ? this_->scenarioList->get_line() : -1;
    if (line == -1) return;

    if (rge_base_game->player_game_info) {
        rge_base_game->player_game_info->set_current_scenario(line);
    }

    rge_base_game->setScenarioGame(1);
    rge_base_game->setCampaignGame(1);
    rge_base_game->setSavedGame(0);

    // VictoryDefault / DefaultResources / DefaultAge are 0 in this scaffold.
    ((TRIBE_Game*)rge_base_game)->setVictoryType(0, 0);

    const long difficulty = this_->difficultyDrop ? this_->difficultyDrop->get_id() : rge_base_game->single_player_difficulty;
    rge_base_game->setDifficulty((int)difficulty);
    rge_base_game->single_player_difficulty = (int)difficulty;

    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
    game->setDeathMatch(0);
    game->setQuickStartGame(0);
    game->setAnimals(1);
    game->setPredators(1);
    rge_base_game->setFullVisibility(0);
    rge_base_game->setFogOfWar(1);
    rge_base_game->setAllowCheatCodes(1);
    game->setRandomizePositions(0);
    game->setLongCombat(0);
    game->setAllowTrading(1);
    game->setFullTechTree(0);
    game->setResourceLevel(0);
    game->setStartingAge(0);
    game->setStartingUnits(0);

    RGE_Scenario* scen = rge_base_game->get_scenario_info(nullptr, 1);
    if (!scen) {
        this_->popupOKDialog(0x9CA, (char*)0, 0x1c2, 100);
        return;
    }

    uint num_players = 0;
    int human_scen_player = -1;
    int human_color = -1;
    for (int scen_player = 0; scen_player < 9; ++scen_player) {
        if (scen->PlActive[scen_player] != 0) {
            game->setScenarioPlayer((int)num_players, scen_player);
            game->setPlayerColor((int)num_players, scen_player + 1);
            rge_base_game->setPlayerTeam((int)num_players, 1);
            if (human_scen_player == -1 && scen->PlType[scen_player] == 1) {
                human_scen_player = scen_player;
                human_color = scen_player + 1;
            }
            num_players++;
        }
    }
    delete scen;

    if (num_players == 0) {
        return;
    }

    rge_base_game->setNumberPlayers((int)num_players);

    // Fully verified. Source of truth: scr_cams.cpp.asm @ 0x00491554
    if (human_scen_player != -1) {
        for (int i = 1; i < (int)num_players; ++i) {
            if (game->tribe_game_options.scenarioPlayerValue[i] == human_scen_player) {
                const int old_scen = game->tribe_game_options.scenarioPlayerValue[0];
                const int old_color = (int)game->tribe_game_options.playerColorValue[0];
                game->setScenarioPlayer(i, old_scen);
                game->setPlayerColor(i, old_color);
                break;
            }
        }
        game->setScenarioPlayer(0, human_scen_player);
        game->setPlayerColor(0, human_color);
    }

    TCommunications_Handler* comm_handler = (TCommunications_Handler*)comm;
    if (comm_handler) {
        // Matches existing code usage: 2=human, 4=computer, 0=absent.
        comm_handler->SetPlayerHumanity(1, 2);
        for (uint i = 2; i <= num_players; ++i) {
            comm_handler->SetPlayerHumanity(i, 4);
        }
        for (uint i = num_players + 1; i <= 9; ++i) {
            comm_handler->SetPlayerHumanity(i, 0);
        }
    }

    if (game->start_game(0) == 0) {
        this_->popupOKDialog(0x961, (char*)0, 0x1c2, 100);
    }
}

TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection() : TScreenPanel((char*)"Campaign Selection Screen") {
    // Fully verified. Source of truth: scr_cams.cpp.decomp @ 0x004909D0
    cams_init_vars(this);

    if (!rge_base_game || !rge_base_game->draw_area) {
        this->error_code = 1;
        return;
    }

    if (!TScreenPanel::setup(rge_base_game->draw_area, (char*)"scr2", 0xC384, 1)) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1e0);

    if (!this->create_text((TPanel*)this, &this->title, 0x2BCD, 0x14, 10, 600, 0x1e, 1, 1, 0, 0)) return;

    this->campaignListX = 0x14;
    this->campaignListY = 0x46;
    this->campaignListWidth = 600;
    this->campaignListHeight = 0x82;

    if (!this->create_list((TPanel*)this, &this->campaignList, 0x14, 0x46, 600, 0x82, 0xB)) return;
    if (!this->create_auto_scrollbar(&this->campaignScrollbar, (TTextPanel*)this->campaignList, 0x14)) return;
    if (!this->create_text((TPanel*)this, &this->campaignTitle, 0x2BCE, this->campaignListX - 5, this->campaignListY - 0x14, 200, 0x14, 4, 0, 0, 0)) return;

    // Loading placeholder
    this->campaignList->set_text((long)0x2B5D);

    this->scenarioListX = 0x14;
    this->scenarioListY = this->campaignListY + this->campaignListHeight + 0x1e;
    this->scenarioListWidth = 600;
    this->scenarioListHeight = 0x82;

    if (!this->create_list((TPanel*)this, &this->scenarioList, 0x14, this->scenarioListY, 600, 0x82, 0xB)) return;
    if (!this->create_auto_scrollbar(&this->scenarioScrollbar, (TTextPanel*)this->scenarioList, 0x14)) return;
    if (!this->create_text((TPanel*)this, &this->scenarioTitle, 0x25FE, this->scenarioListX - 5, this->scenarioListY - 0x14, 200, 0x14, 4, 0, 0, 0)) return;

    // No mouse capture on scenario list by default (matches decomp `_padding_ = 0`).
    this->scenarioList->handle_mouse_input = 0;

    if (!this->create_text((TPanel*)this, &this->difficultyTitle, 0x2BCF, 0xF, 0x172, 200, 0x14, 4, 0, 0, 0)) return;
    if (!this->create_drop_down((TPanel*)this, &this->difficultyDrop, 0x82, 100, 0x14, 0x186, 0x82, 0x18, 0xB)) return;

    this->difficultyDrop->empty_list();
    this->difficultyDrop->append_line(0x2BD4, 4);
    this->difficultyDrop->append_line(0x2BD3, 3);
    this->difficultyDrop->append_line(0x2BD2, 2);
    this->difficultyDrop->append_line(0x2BD1, 1);
    this->difficultyDrop->append_line(0x2BD0, 0);

    const long diff_line = this->difficultyDrop->get_line(rge_base_game ? rge_base_game->rge_game_options.difficultyValue : 2);
    this->difficultyDrop->set_line(diff_line);

    if (!this->create_button((TPanel*)this, &this->okButton, 0xFA1, 0, 0x46, 0x1b8, 0xf0, 0x1e, 0, 0, 0)) return;
    if (!this->create_button((TPanel*)this, &this->cancelButton, 0xFA2, 0, 0x14a, 0x1b8, 0xf0, 0x1e, 0, 0, 0)) return;
    this->cancelButton->hotkey = 0x1B;
    this->cancelButton->hotkey_shift = 0;

    if (!this->create_button((TPanel*)this, &this->close_button, 0x3EA, 0, 0, 0, 0, 0, -1, -1, 0)) return;
    this->close_button->set_active(1);
    this->close_button->set_positioning((PositionMode)9, 4, 4, 4, 4, 0x11, 0x11, 0x11, 0x11, (TPanel*)0, (TPanel*)0, (TPanel*)0, (TPanel*)0);

    TPanel* tabList[4];
    tabList[0] = (TPanel*)this->campaignList;
    tabList[1] = (TPanel*)this->scenarioList;
    tabList[2] = (TPanel*)this->difficultyDrop;
    tabList[3] = (TPanel*)this->okButton;
    this->set_tab_order(tabList, 4);

    this->set_curr_child((TPanel*)this->okButton);

    cams_fillCampaigns(this);
    cams_fillScenarios(this);
    this->set_curr_child((TPanel*)this->campaignList);
    this->campaignsLoaded = 1;
}

TRIBE_Screen_Campaign_Selection::~TRIBE_Screen_Campaign_Selection() {
    // Fully verified. Source of truth: scr_cams.cpp.decomp @ 0x00490EA0
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->campaignTitle);
    this->delete_panel((TPanel**)&this->campaignList);
    this->delete_panel((TPanel**)&this->campaignScrollbar);
    this->delete_panel((TPanel**)&this->scenarioTitle);
    this->delete_panel((TPanel**)&this->scenarioList);
    this->delete_panel((TPanel**)&this->scenarioScrollbar);
    this->delete_panel((TPanel**)&this->difficultyTitle);
    this->delete_panel((TPanel**)&this->difficultyDrop);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->close_button);
}

long TRIBE_Screen_Campaign_Selection::handle_idle() {
    // Fully verified. Source of truth: scr_cams.cpp.decomp @ 0x00490F90
    if (this->campaignsLoaded == 0) {
        cams_fillCampaigns(this);
        cams_fillScenarios(this);
        this->set_curr_child((TPanel*)this->campaignList);
        this->campaignsLoaded = 1;
    }

    if (rge_base_game && rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

long TRIBE_Screen_Campaign_Selection::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // Fully verified. Source of truth: scr_cams.cpp.decomp @ 0x00490FF0
    (void)param_3;
    (void)param_4;

    if (param_1 && this->campaignsLoaded != 0) {
        if ((TButtonPanel*)param_1 == this->okButton && param_2 == 1) {
            cams_startGame(this);
            return 1;
        }
        if ((TButtonPanel*)param_1 == this->cancelButton && param_2 == 1) {
            if (rge_base_game) rge_base_game->disable_input();
            TRIBE_Screen_Name* scr = new TRIBE_Screen_Name();
            if (panel_system) {
                if (scr) panel_system->add_panel((TPanel*)scr);
                panel_system->setCurrentPanel((char*)"Name Selection Screen", 0);
                panel_system->destroyPanel((char*)"Campaign Selection Screen");
            }
            return 1;
        }
        if ((TButtonPanel*)param_1 == this->close_button && param_2 == 1) {
            if (rge_base_game) rge_base_game->close();
            return 1;
        }
        if ((TListPanel*)param_1 == this->campaignList && param_2 == 1) {
            if (rge_base_game && rge_base_game->player_game_info) {
                const long id = this->campaignList->get_id();
                rge_base_game->player_game_info->set_current_campaign(id);
            }
            cams_fillScenarios(this);
            return 1;
        }
        if ((TListPanel*)param_1 == this->scenarioList && param_2 == 3) {
            return this->action((TPanel*)this->okButton, 1, 0, 0);
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Virtual wrappers: forward to TScreenPanel unless overridden.
long TRIBE_Screen_Campaign_Selection::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TRIBE_Screen_Campaign_Selection::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TRIBE_Screen_Campaign_Selection::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Campaign_Selection::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TRIBE_Screen_Campaign_Selection::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TRIBE_Screen_Campaign_Selection::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TRIBE_Screen_Campaign_Selection::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Campaign_Selection::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TRIBE_Screen_Campaign_Selection::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TRIBE_Screen_Campaign_Selection::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TRIBE_Screen_Campaign_Selection::draw_finish() { TScreenPanel::draw_finish(); }
void TRIBE_Screen_Campaign_Selection::draw() { TScreenPanel::draw(); }
void TRIBE_Screen_Campaign_Selection::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TRIBE_Screen_Campaign_Selection::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TRIBE_Screen_Campaign_Selection::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TRIBE_Screen_Campaign_Selection::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TRIBE_Screen_Campaign_Selection::paint() { TScreenPanel::paint(); }
long TRIBE_Screen_Campaign_Selection::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Campaign_Selection::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TRIBE_Screen_Campaign_Selection::handle_paint() { return TScreenPanel::handle_paint(); }
long TRIBE_Screen_Campaign_Selection::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Campaign_Selection::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TRIBE_Screen_Campaign_Selection::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TRIBE_Screen_Campaign_Selection::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TRIBE_Screen_Campaign_Selection::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TRIBE_Screen_Campaign_Selection::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TRIBE_Screen_Campaign_Selection::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Campaign_Selection::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Campaign_Selection::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Campaign_Selection::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Campaign_Selection::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Campaign_Selection::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Campaign_Selection::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Campaign_Selection::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Campaign_Selection::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Campaign_Selection::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Campaign_Selection::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Campaign_Selection::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Campaign_Selection::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Campaign_Selection::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Campaign_Selection::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TRIBE_Screen_Campaign_Selection::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TRIBE_Screen_Campaign_Selection::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TRIBE_Screen_Campaign_Selection::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TRIBE_Screen_Campaign_Selection::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TRIBE_Screen_Campaign_Selection::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TRIBE_Screen_Campaign_Selection::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TRIBE_Screen_Campaign_Selection::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TRIBE_Screen_Campaign_Selection::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TRIBE_Screen_Campaign_Selection::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TRIBE_Screen_Campaign_Selection::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TRIBE_Screen_Campaign_Selection::take_snapshot() { TScreenPanel::take_snapshot(); }
void TRIBE_Screen_Campaign_Selection::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TRIBE_Screen_Campaign_Selection::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TRIBE_Screen_Campaign_Selection::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TRIBE_Screen_Campaign_Selection::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Campaign_Selection::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Campaign_Selection::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Campaign_Selection::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Campaign_Selection::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Campaign_Selection::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Campaign_Selection::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TRIBE_Screen_Campaign_Selection::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TRIBE_Screen_Campaign_Selection::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TRIBE_Screen_Campaign_Selection::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Campaign_Selection::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TRIBE_Screen_Campaign_Selection::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TRIBE_Screen_Campaign_Selection::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TRIBE_Screen_Campaign_Selection::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TRIBE_Screen_Campaign_Selection::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TRIBE_Screen_Campaign_Selection::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }

