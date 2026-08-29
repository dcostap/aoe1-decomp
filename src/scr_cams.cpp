
#include "../include/scr_cams.h"
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

extern TCommunications_Handler* comm;

TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection()
    : TScreenPanel("Campaign Selection Screen")
{
    init_vars();
    if (!setup(rge_base_game->draw_area, "scr2", 0xC384, 1)) {
        error_code = 1;
        return;
    }
    setup_shadow_area(0);
    set_ideal_size(0x280, 0x1E0);
    if (create_text(this, &title, 0x2BCD, 0x14, 10, 600, 0x1E, 1, 1, 0, 0)) {
        campaignListX = 0x14;
        campaignListY = 0x46;
        campaignListWidth = 600;
        campaignListHeight = 0x82;
        if (create_list(this, &campaignList, 0x14, 0x46, 600, 0x82, 0x0B)) {
            if (create_auto_scrollbar(&campaignScrollbar, campaignList, 0x14)) {
                if (create_text(this, &campaignTitle, 0x2BCE,
                                campaignListX - 5, campaignListY - 0x14,
                                200, 0x14, 4, 0, 0, 0)) {
                    campaignList->set_text(0x2B5D);
                    scenarioListX = 0x14;
                    scenarioListY = campaignListY + campaignListHeight + 0x1E;
                    scenarioListWidth = 600;
                    scenarioListHeight = 0x82;
                    if (create_list(this, &scenarioList, scenarioListX,
                                    scenarioListY, scenarioListWidth,
                                    scenarioListHeight, 0x0B)) {
                        if (create_auto_scrollbar(&scenarioScrollbar,
                                                  scenarioList, 0x14)) {
                            if (create_text(this, &scenarioTitle, 0x25FE,
                                            scenarioListX - 5,
                                            scenarioListY - 0x14, 200, 0x14,
                                            4, 0, 0, 0)) {
                                scenarioList->sorted = 0;
                                if (create_text(this, &difficultyTitle, 0x2BCF,
                                                0x0F, 0x172, 200, 0x14, 4,
                                                0, 0, 0)) {
                                    if (create_drop_down(this, &difficultyDrop,
                                                         0x82, 100, 0x14,
                                                         0x186, 0x82, 0x18,
                                                         0x0B)) {
                                        difficultyDrop->empty_list();
                                        difficultyDrop->append_line(0x2BD4, 4);
                                        difficultyDrop->append_line(0x2BD3, 3);
                                        difficultyDrop->append_line(0x2BD2, 2);
                                        difficultyDrop->append_line(0x2BD1, 1);
                                        difficultyDrop->append_line(0x2BD0, 0);
                                        difficultyDrop->set_line(
                                            difficultyDrop->get_line(
                                                rge_base_game->difficulty()));
                                        if (create_button(this, &okButton, 0x0FA1,
                                                          0, 0x46, 0x1B8,
                                                          0x0F0, 0x1E, 0, 0,
                                                          0)) {
                                            if (create_button(this, &cancelButton,
                                                              0x0FA2, 0, 0x14A,
                                                              0x1B8, 0x0F0,
                                                              0x1E, 0, 0, 0)) {
                                                TButtonPanel* cancel =
                                                    cancelButton;
                                                cancel->hotkey = 0x1B;
                                                cancel->hotkey_shift = 0;
                                                if (create_button(
                                                        this, &close_button,
                                                        0x03EA, 0, 0, 0, 0, 0,
                                                        -1, -1, 0)) {
                                                    close_button->set_active(1);
                                                    close_button->set_positioning(
                                                        TPanel::PositionRightTop,
                                                        4, 4, 4, 4, 0x11, 0x11,
                                                        0x11, 0x11, 0, 0, 0, 0);
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

void TRIBE_Screen_Campaign_Selection::init_vars()
{
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

TRIBE_Screen_Campaign_Selection::~TRIBE_Screen_Campaign_Selection()
{
    delete this->title;
    delete this->campaignTitle;
    delete this->campaignList;
    delete this->campaignScrollbar;
    delete this->scenarioTitle;
    delete this->scenarioList;
    delete this->scenarioScrollbar;
    delete this->difficultyTitle;
    delete this->difficultyDrop;
    delete this->okButton;
    delete this->cancelButton;
    delete this->close_button;
}

long TRIBE_Screen_Campaign_Selection::handle_idle()
{
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

long TRIBE_Screen_Campaign_Selection::action(TPanel* panel, long code,
                                             unsigned long p3,
                                             unsigned long p4)
{
    if (panel != 0 && campaignsLoaded != 0) {
        TPanel* ok = okButton;
        if (panel == ok && code == 1) {
            startGame();
            return 1;
        }
        if (panel == cancelButton && code == 1) {
            rge_base_game->disable_input();
            new TRIBE_Screen_Name;
            panel_system.setCurrentPanel("Name Selection Screen", 0);
            panel_system.destroyPanel("Campaign Selection Screen");
            return 1;
        }
        if (panel == close_button && code == 1) {
            rge_base_game->close();
            return 1;
        }
        if (panel == campaignList && code == 1) {
            RGE_Game_Info* info = rge_base_game->player_game_info;
            info->set_current_campaign(campaignList->get_id());
            fillScenarios();
            return 1;
        }
        if (panel == scenarioList && code == 3) {
            action(ok, 1, 0, 0);
            return 1;
        }
    }
    return TEasy_Panel::action(panel, code, p3, p4);
}

void TRIBE_Screen_Campaign_Selection::fillCampaigns()
{
    campaignList->empty_list();

    RGE_Game_Info* info = rge_base_game->player_game_info;
    char** campaigns = 0;
    long current;
    long count = info->get_campaign_list(&campaigns, current);

    if (count != 0) {
        campaignList->sorted = 1;
        {
            int i;
            for (i = 0; i < count; i++) {
                campaignList->append_line(campaigns[i], i);
            }
        }
        campaignList->set_line(campaignList->get_line(current));
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

void TRIBE_Screen_Campaign_Selection::fillScenarios()
{
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

void TRIBE_Screen_Campaign_Selection::startGame()
{
    TRIBE_Game* game = static_cast<TRIBE_Game*>(rge_base_game);
    int player_count;
    if (this->scenarioList->get_line() == -1) {
        return;
    }

    RGE_Game_Info* info = rge_base_game->player_game_info;
    info->set_current_scenario(this->scenarioList->get_line());
    rge_base_game->setScenarioGame(1);
    rge_base_game->setCampaignGame(1);
    rge_base_game->setSavedGame(0);
    game->setVictoryType(TRIBE_Game::VictoryDefault, 0);
    rge_base_game->setDifficulty(this->difficultyDrop->get_id());
    rge_base_game->set_single_player_difficulty(
        this->difficultyDrop->get_id());
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
    game->setResourceLevel(TRIBE_Game::DefaultResources);
    game->setStartingAge(TRIBE_Game::DefaultAge);
    game->setStartingUnits(0);

    int first_human = -1;
    int first_color = 0;
    RGE_Scenario* scen = rge_base_game->get_scenario_info(0, 1);
    if (scen == 0) {
        this->popupOKDialog(0x9ca, 0, 0x1c2, 100);
        return;
    }

    player_count = 0;
    for (int i = 0; i < 9; ++i) {
        if (scen->Get_player_Active(i)) {
            game->setScenarioPlayer(player_count, i);
            int color = i + 1;
            game->setPlayerColor(player_count, color);
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
            if (game->scenarioPlayer(j) == first_human) {
                game->setScenarioPlayer(j, game->scenarioPlayer(0));
                game->setPlayerColor(j, game->playerColor(0));
                break;
            }
        }
        game->setScenarioPlayer(0, first_human);
        game->setPlayerColor(0, first_color);
    }

    comm->SetPlayerHumanity(1, ME_HUMAN);
    for (int p = 1; p < player_count; ++p) {
        comm->SetPlayerHumanity(p + 1, ME_COMPUTER);
    }
    for (int q = player_count; q < 9; ++q) {
        comm->SetPlayerHumanity(q + 1, ME_ABSENT);
    }

    if (!game->start_game(0)) {
        this->popupOKDialog(0x961, 0, 0x1c2, 100);
    }
}
