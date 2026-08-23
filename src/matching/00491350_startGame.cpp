// 00491350 TRIBE_Screen_Campaign_Selection::startGame
// Attempt log:
// 1: natural reconstruction from packet with local UI/game/scenario surfaces.
// 2: added full body; compiles size-equal but broad mismatch, first diff is saved-this register (rebuilt ESI, original EDI).
// 3: explicit self local did not change saved-this register; original likely uses EDI because ESI is taken by scenario/player count liveness early.
// 4: moving player_count declaration/init to function top forced this into EDI, but emitted early xor esi before original; rolled to delayed init.
// 5: split rge_base_game->game_info into a local to encourage original ESI=game_info before set_current_scenario.

#include "../../include/scr_cams_context.h"

void TRIBE_Screen_Campaign_Selection::startGame()
{
    TRIBE_Screen_Campaign_Selection* self = this;
    int player_count;
    if (self->scenarioList->get_line() == -1) {
        return;
    }

    RGE_Game_Info* info = ((TRIBE_Game*)rge_base_game)->game_info;
    info->set_current_scenario(self->scenarioList->get_line());
    ((TRIBE_Game*)rge_base_game)->setScenarioGame(1);
    ((TRIBE_Game*)rge_base_game)->setCampaignGame(1);
    ((TRIBE_Game*)rge_base_game)->setSavedGame(0);
    ((TRIBE_Game*)rge_base_game)->setVictoryType(0, 0);
    ((TRIBE_Game*)rge_base_game)->setDifficulty(self->difficultyDrop->get_id());
    ((TRIBE_Game*)rge_base_game)->set_single_player_difficulty(self->difficultyDrop->get_id());
    ((TRIBE_Game*)rge_base_game)->setDeathMatch(0);
    ((TRIBE_Game*)rge_base_game)->setQuickStartGame(0);
    ((TRIBE_Game*)rge_base_game)->setAnimals(1);
    ((TRIBE_Game*)rge_base_game)->setPredators(1);
    ((TRIBE_Game*)rge_base_game)->setFullVisibility(0);
    ((TRIBE_Game*)rge_base_game)->setFogOfWar(1);
    ((TRIBE_Game*)rge_base_game)->setAllowCheatCodes(1);
    ((TRIBE_Game*)rge_base_game)->setRandomizePositions(0);
    ((TRIBE_Game*)rge_base_game)->setLongCombat(0);
    ((TRIBE_Game*)rge_base_game)->setAllowTrading(1);
    ((TRIBE_Game*)rge_base_game)->setFullTechTree(0);
    ((TRIBE_Game*)rge_base_game)->setResourceLevel(0);
    ((TRIBE_Game*)rge_base_game)->setStartingAge(0);
    ((TRIBE_Game*)rge_base_game)->setStartingUnits(0);

    int first_human = -1;
    int first_color = 0;
    RGE_Scenario* scen = ((TRIBE_Game*)rge_base_game)->get_scenario_info(0, 1);
    if (scen == 0) {
        self->popupOKDialog(0x9ca, 0, 0x1c2, 100);
        return;
    }

    player_count = 0;
    for (int i = 0; i < 9; ++i) {
        if (scen->Get_player_Active(i)) {
            ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(player_count, i);
            int color = i + 1;
            ((TRIBE_Game*)rge_base_game)->setPlayerColor(player_count, color);
            ((TRIBE_Game*)rge_base_game)->setPlayerTeam(player_count, 1);
            ++player_count;
            if (first_human == -1 && scen->Get_player_Type(i) == 1) {
                first_human = i;
                first_color = color;
            }
        }
    }

    delete scen;
    if (player_count == 0) return;
    ((TRIBE_Game*)rge_base_game)->setNumberPlayers(player_count);

    if (first_human != -1) {
        int j;
        for (j = 1; j < player_count; ++j) {
            if (((TRIBE_Game*)rge_base_game)->scenarioPlayer(j) == first_human) {
                ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(j, ((TRIBE_Game*)rge_base_game)->scenarioPlayer(0));
                ((TRIBE_Game*)rge_base_game)->setPlayerColor(j, ((TRIBE_Game*)rge_base_game)->playerColor(0));
                break;
            }
        }
        ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(0, first_human);
        ((TRIBE_Game*)rge_base_game)->setPlayerColor(0, first_color);
    }

    comm->setPlayerHumanity(1, 2);
    for (int p = 1; p < player_count; ++p) {
        comm->setPlayerHumanity(p + 1, 4);
    }
    for (int q = player_count; q < 9; ++q) {
        comm->setPlayerHumanity(q + 1, 0);
    }

    if (!((TRIBE_Game*)rge_base_game)->start_game(0)) {
        self->popupOKDialog(0x961, 0, 0x1c2, 100);
    }
}
