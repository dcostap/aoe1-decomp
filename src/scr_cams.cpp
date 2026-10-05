
#include "../include/scr_cams.h"
#include "../include/game_globals.h"
#include "../include/resource_ids.h"
#include "../include/scr_name.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/Pnl_scbr.h"
#include "../include/pnl_drop.h"
#include "../include/gameinfo.h"
#include "../include/com_hand.h"
#include "../include/scenario.h"
#include "../include/tribegam.h"
#include <stdlib.h>

TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection() : TScreenPanel("Campaign Selection Screen") {
    init_vars();
    if (!setup(rge_base_game->draw_area, "scr2", 0xC384, 1)) {
        error_code = 1;
        return;
    }
    setup_shadow_area(0);
    set_ideal_size(640, 480);
    if (create_text(this, &title, STRING_ID_CAMPAIGN_LABEL, 20, 10, 600, 30, RGE_FONT_COPPERPLATE_21_BOLD, 1, 0, 0)) {
        campaignListX = 20;
        campaignListY = 70;
        campaignListWidth = 600;
        campaignListHeight = 130;
        if (create_list(this, &campaignList, 20, 70, 600, 130, RGE_FONT_STANDARD)) {
            if (create_auto_scrollbar(&campaignScrollbar, campaignList, 20)) {
                if (create_text(
                        this, &campaignTitle, STRING_ID_SELECT_CAMPAIGN, campaignListX - 5, campaignListY - 20, 200, 20,
                        RGE_FONT_COPPERPLATE_12_BOLD_ALT, 0, 0, 0
                    )) {
                    campaignList->set_text(STRING_ID_CAMPAIGN_LIST_LOADING);
                    scenarioListX = 20;
                    scenarioListY = campaignListY + campaignListHeight + 30;
                    scenarioListWidth = 600;
                    scenarioListHeight = 130;
                    if (create_list(
                            this, &scenarioList, scenarioListX, scenarioListY, scenarioListWidth, scenarioListHeight,
                            RGE_FONT_STANDARD
                        )) {
                        if (create_auto_scrollbar(&scenarioScrollbar, scenarioList, 20)) {
                            if (create_text(
                                    this, &scenarioTitle, STRING_ID_SCENARIO_LIST_TITLE, scenarioListX - 5,
                                    scenarioListY - 20, 200, 20, RGE_FONT_COPPERPLATE_12_BOLD_ALT, 0, 0, 0
                                )) {
                                scenarioList->sorted = 0;
                                if (create_text(
                                        this, &difficultyTitle, STRING_ID_DIFFICULTY_LABEL, 15, 370, 200, 20,
                                        RGE_FONT_COPPERPLATE_12_BOLD_ALT, 0, 0, 0
                                    )) {
                                    if (create_drop_down(
                                            this, &difficultyDrop, 130, 100, 20, 390, 130, 24, RGE_FONT_STANDARD
                                        )) {
                                        difficultyDrop->empty_list();
                                        difficultyDrop->append_line(
                                            STRING_ID_DIFFICULTY_EASIEST, RGE_DIFFICULTY_EASIEST
                                        );
                                        difficultyDrop->append_line(STRING_ID_DIFFICULTY_EASY, RGE_DIFFICULTY_EASY);
                                        difficultyDrop->append_line(
                                            STRING_ID_DIFFICULTY_MODERATE, RGE_DIFFICULTY_MODERATE
                                        );
                                        difficultyDrop->append_line(STRING_ID_DIFFICULTY_HARD, RGE_DIFFICULTY_HARD);
                                        difficultyDrop->append_line(
                                            STRING_ID_DIFFICULTY_HARDEST, RGE_DIFFICULTY_HARDEST
                                        );
                                        difficultyDrop->set_line(difficultyDrop->get_line(rge_base_game->difficulty()));
                                        if (create_button(
                                                this, &okButton, STRING_ID_BUTTON_OK, 0, 70, 440, 240, 30,
                                                RGE_FONT_COPPERPLATE_12_BOLD, 0, 0
                                            )) {
                                            if (create_button(
                                                    this, &cancelButton, STRING_ID_BUTTON_CANCEL, 0, 330, 440, 240, 30,
                                                    RGE_FONT_COPPERPLATE_12_BOLD, 0, 0
                                                )) {
                                                TButtonPanel* cancel = cancelButton;
                                                cancel->hotkey = VK_ESCAPE;
                                                cancel->hotkey_shift = 0;
                                                if (create_button(
                                                        this, &close_button, STRING_ID_BUTTON_CLOSE, 0, 0, 0, 0, 0, -1,
                                                        -1, 0
                                                    )) {
                                                    close_button->set_active(1);
                                                    close_button->set_positioning(
                                                        TPanel::PositionRightTop, 4, 4, 4, 4, 17, 17, 17, 17, 0, 0, 0, 0
                                                    );
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

void TRIBE_Screen_Campaign_Selection::init_vars() {
    title = 0;
    campaignTitle = 0;
    campaignList = 0;
    campaignScrollbar = 0;
    scenarioTitle = 0;
    scenarioList = 0;
    scenarioScrollbar = 0;
    difficultyTitle = 0;
    difficultyDrop = 0;
    okButton = 0;
    cancelButton = 0;
    close_button = 0;
    campaignsLoaded = 0;

    int difficulty = rge_base_game->get_single_player_difficulty();
    rge_base_game->setDifficulty(difficulty);
}

TRIBE_Screen_Campaign_Selection::~TRIBE_Screen_Campaign_Selection() {
    delete_panel((TPanel**) &title);
    delete_panel((TPanel**) &campaignTitle);
    delete_panel((TPanel**) &campaignList);
    delete_panel((TPanel**) &campaignScrollbar);
    delete_panel((TPanel**) &scenarioTitle);
    delete_panel((TPanel**) &scenarioList);
    delete_panel((TPanel**) &scenarioScrollbar);
    delete_panel((TPanel**) &difficultyTitle);
    delete_panel((TPanel**) &difficultyDrop);
    delete_panel((TPanel**) &okButton);
    delete_panel((TPanel**) &cancelButton);
    delete_panel((TPanel**) &close_button);
}

long TRIBE_Screen_Campaign_Selection::handle_idle() {
    if (campaignsLoaded == 0) {
        fillCampaigns();
        fillScenarios();
        set_curr_child(campaignList);
        campaignsLoaded = 1;
    }
    if (campaignsLoaded != 0 && rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

long TRIBE_Screen_Campaign_Selection::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    if (fromPanel != 0 && campaignsLoaded != 0) {
        TPanel* ok = okButton;
        if (fromPanel == ok && actionIn == 1) {
            startGame();
            return 1;
        }
        if (fromPanel == cancelButton && actionIn == 1) {
            rge_base_game->disable_input();
            new TRIBE_Screen_Name;
            panel_system.setCurrentPanel("Name Selection Screen", 0);
            panel_system.destroyPanel("Campaign Selection Screen");
            return 1;
        }
        if (fromPanel == close_button && actionIn == 1) {
            rge_base_game->close();
            return 1;
        }
        if (fromPanel == campaignList && actionIn == 1) {
            RGE_Game_Info* info = rge_base_game->player_game_info;
            info->set_current_campaign(campaignList->get_id());
            fillScenarios();
            return 1;
        }
        if (fromPanel == scenarioList && actionIn == 3) {
            action(ok, 1, 0, 0);
            return 1;
        }
    }
    return TEasy_Panel::action(fromPanel, actionIn, a1, a2);
}

void TRIBE_Screen_Campaign_Selection::fillCampaigns() {
    campaignList->empty_list();

    RGE_Game_Info* info = rge_base_game->player_game_info;
    char** campaigns = 0;
    long currentCampaign;
    long count = info->get_campaign_list(&campaigns, currentCampaign);

    if (count != 0) {
        campaignList->sorted = 1;
        {
            int i;
            for (i = 0; i < count; i++) {
                campaignList->append_line(campaigns[i], i);
            }
        }
        campaignList->set_line(campaignList->get_line(currentCampaign));
        {
            int i;
            for (i = 0; i < count; i++) {
                free(campaigns[i]);
            }
        }
        free(campaigns);

        long line = campaignList->get_line();
        if (line != -1) {
            RGE_Game_Info* info = rge_base_game->player_game_info;
            info->set_current_campaign(campaignList->get_id());
        }
    }
}

void TRIBE_Screen_Campaign_Selection::fillScenarios() {
    scenarioList->empty_list();

    RGE_Game_Info* info = rge_base_game->player_game_info;
    char** scenarios = 0;
    long currentScenario;
    long num = info->get_scenario_list(&scenarios, currentScenario);

    if (num != 0) {
        long i;
        for (i = 0; i < num; i++) {
            scenarioList->append_line(scenarios[i], i);
        }

        long line = scenarioList->get_line(currentScenario);
        scenarioList->set_line(line);
        for (i = 0; i < num; i++) {
            free(scenarios[i]);
        }
        free(scenarios);
        scenarioList->scroll_cur_line(7, 0, 1);
    }
}

void TRIBE_Screen_Campaign_Selection::startGame() {
    int player_count;
    if (this->scenarioList->get_line() == -1) {
        return;
    }

    RGE_Game_Info* info = rge_base_game->player_game_info;
    info->set_current_scenario(this->scenarioList->get_line());
    rge_base_game->setScenarioGame(1);
    rge_base_game->setCampaignGame(1);
    rge_base_game->setSavedGame(0);
    static_cast<TRIBE_Game*>(rge_base_game)->setVictoryType(TRIBE_Game::VictoryDefault, 0);
    rge_base_game->setDifficulty(this->difficultyDrop->get_id());
    rge_base_game->set_single_player_difficulty(this->difficultyDrop->get_id());
    static_cast<TRIBE_Game*>(rge_base_game)->setDeathMatch(0);
    static_cast<TRIBE_Game*>(rge_base_game)->setQuickStartGame(0);
    static_cast<TRIBE_Game*>(rge_base_game)->setAnimals(1);
    static_cast<TRIBE_Game*>(rge_base_game)->setPredators(1);
    rge_base_game->setFullVisibility(0);
    rge_base_game->setFogOfWar(1);
    rge_base_game->setAllowCheatCodes(1);
    static_cast<TRIBE_Game*>(rge_base_game)->setRandomizePositions(0);
    static_cast<TRIBE_Game*>(rge_base_game)->setLongCombat(0);
    static_cast<TRIBE_Game*>(rge_base_game)->setAllowTrading(1);
    static_cast<TRIBE_Game*>(rge_base_game)->setFullTechTree(0);
    static_cast<TRIBE_Game*>(rge_base_game)->setResourceLevel(TRIBE_Game::DefaultResources);
    static_cast<TRIBE_Game*>(rge_base_game)->setStartingAge(TRIBE_Game::DefaultAge);
    static_cast<TRIBE_Game*>(rge_base_game)->setStartingUnits(0);

    int first_human = -1;
    int first_color = 0;
    RGE_Scenario* scen = rge_base_game->get_scenario_info(0, 1);
    if (scen == 0) {
        this->popupOKDialog(STRING_ID_ERROR_TRIAL_SCENARIO, 0, TEASY_POPUP_WIDTH, 100);
        return;
    }

    player_count = 0;
    for (int i = 0; i < 9; ++i) {
        if (scen->Get_player_Active(i)) {
            static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(player_count, i);
            int color = i + 1;
            static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(player_count, color);
            rge_base_game->setPlayerTeam(player_count, 1);
            ++player_count;
            if (first_human == -1 && scen->Get_player_Type(i) == 1) {
                first_human = i;
                first_color = color;
            }
        }
    }

    delete scen;
    if (player_count == 0) {
        return;
    }
    rge_base_game->setNumberPlayers(player_count);

    if (first_human != -1) {
        int j;
        for (j = 1; j < player_count; ++j) {
            if (static_cast<TRIBE_Game*>(rge_base_game)->scenarioPlayer(j) == first_human) {
                static_cast<TRIBE_Game*>(rge_base_game)
                    ->setScenarioPlayer(j, static_cast<TRIBE_Game*>(rge_base_game)->scenarioPlayer(0));
                static_cast<TRIBE_Game*>(rge_base_game)
                    ->setPlayerColor(j, static_cast<TRIBE_Game*>(rge_base_game)->playerColor(0));
                break;
            }
        }
        static_cast<TRIBE_Game*>(rge_base_game)->setScenarioPlayer(0, first_human);
        static_cast<TRIBE_Game*>(rge_base_game)->setPlayerColor(0, first_color);
    }

    comm->SetPlayerHumanity(1, ME_HUMAN);
    for (int p = 1; p < player_count; ++p) {
        comm->SetPlayerHumanity(p + 1, ME_COMPUTER);
    }
    for (int q = player_count; q < 9; ++q) {
        comm->SetPlayerHumanity(q + 1, ME_ABSENT);
    }

    if (!static_cast<TRIBE_Game*>(rge_base_game)->start_game(0)) {
        this->popupOKDialog(STRING_ID_ERROR_START_GAME, 0, TEASY_POPUP_WIDTH, 100);
    }
}
