// 00491350 TRIBE_Screen_Campaign_Selection::startGame
// Attempt log:
// 1: natural reconstruction from packet with local UI/game/scenario surfaces.
// 2: added full body; compiles size-equal but broad mismatch, first diff is saved-this register (rebuilt ESI, original EDI).
// 3: explicit self local did not change saved-this register; original likely uses EDI because ESI is taken by scenario/player count liveness early.
// 4: moving player_count declaration/init to function top forced this into EDI, but emitted early xor esi before original; rolled to delayed init.
// 5: split rge_base_game->game_info into a local to encourage original ESI=game_info before set_current_scenario.

#define rge_base_game (*(TRIBE_Game**)0x0062C574)
#define comm_handler (*(TCommunications_Handler**)0x0062C4C0)

class TTextPanel { public: long get_line(); };
class TDropDownPanel { public: long get_id(); };
class TCommunications_Handler { public: void set_player(int, int); };
class RGE_Game_Info { public: unsigned char set_current_scenario(int); };
class RGE_Scenario {
public:
    virtual void v0();
    virtual void vdtor(int);
    int Get_player_Type(int);
    int Get_player_Active(int);
};
class TRIBE_Game {
public:
    char pad[4];
    RGE_Game_Info* game_info;
    void setScenarioGame(int);
    void setCampaignGame(int);
    void setSavedGame(int);
    void setDifficulty(int);
    void set_single_player_difficulty(int);
    void setFullVisibility(int);
    void setFogOfWar(int);
    void setAllowCheatCodes(int);
    void setNumberPlayers(int);
    RGE_Scenario* get_scenario_info(int, int);
    void setPlayerTeam(int, int);
    void setVictoryType(int, int);
    void setDeathMatch(unsigned char);
    void setQuickStartGame(unsigned char);
    void setAnimals(int);
    void setPredators(int);
    void setScenarioPlayer(int, int);
    int getScenarioPlayer(int);
    void setPlayerColor(int, int);
    int getPlayerColor(int);
    void setAllowTrading(int);
    void setLongCombat(int);
    void setRandomizePositions(int);
    void setFullTechTree(int);
    void setResourceLevel(int);
    void setStartingAge(int);
    void setStartingUnits(int);
    int start_game(int);
};
class TRIBE_Screen_Campaign_Selection {
public:
    char pad[0x4ac];
    TTextPanel* scenario_list;
    char pad2[8];
    TDropDownPanel* difficulty;
    void popupOKDialog(long, int, int, int);
    void startGame();
};

void TRIBE_Screen_Campaign_Selection::startGame()
{
    TRIBE_Screen_Campaign_Selection* self = this;
    int player_count;
    if (self->scenario_list->get_line() == -1) {
        return;
    }

    RGE_Game_Info* info = rge_base_game->game_info;
    info->set_current_scenario(self->scenario_list->get_line());
    rge_base_game->setScenarioGame(1);
    rge_base_game->setCampaignGame(1);
    rge_base_game->setSavedGame(0);
    rge_base_game->setVictoryType(0, 0);
    rge_base_game->setDifficulty(self->difficulty->get_id());
    rge_base_game->set_single_player_difficulty(self->difficulty->get_id());
    rge_base_game->setDeathMatch(0);
    rge_base_game->setQuickStartGame(0);
    rge_base_game->setAnimals(1);
    rge_base_game->setPredators(1);
    rge_base_game->setFullVisibility(0);
    rge_base_game->setFogOfWar(1);
    rge_base_game->setAllowCheatCodes(1);
    rge_base_game->setRandomizePositions(0);
    rge_base_game->setLongCombat(0);
    rge_base_game->setAllowTrading(1);
    rge_base_game->setFullTechTree(0);
    rge_base_game->setResourceLevel(0);
    rge_base_game->setStartingAge(0);
    rge_base_game->setStartingUnits(0);

    int first_human = -1;
    int first_color = 0;
    RGE_Scenario* scen = rge_base_game->get_scenario_info(0, 1);
    if (scen == 0) {
        self->popupOKDialog(0x9ca, 0, 0x1c2, 100);
        return;
    }

    player_count = 0;
    for (int i = 0; i < 9; ++i) {
        if (scen->Get_player_Active(i)) {
            rge_base_game->setScenarioPlayer(player_count, i);
            int color = i + 1;
            rge_base_game->setPlayerColor(player_count, color);
            rge_base_game->setPlayerTeam(player_count, 1);
            ++player_count;
            if (first_human == -1 && scen->Get_player_Type(i) == 1) {
                first_human = i;
                first_color = color;
            }
        }
    }

    scen->vdtor(1);
    if (player_count == 0) return;
    rge_base_game->setNumberPlayers(player_count);

    if (first_human != -1) {
        int j;
        for (j = 1; j < player_count; ++j) {
            if (rge_base_game->getScenarioPlayer(j) == first_human) {
                rge_base_game->setScenarioPlayer(j, rge_base_game->getScenarioPlayer(0));
                rge_base_game->setPlayerColor(j, rge_base_game->getPlayerColor(0));
                break;
            }
        }
        rge_base_game->setScenarioPlayer(0, first_human);
        rge_base_game->setPlayerColor(0, first_color);
    }

    comm_handler->set_player(1, 2);
    for (int p = 1; p < player_count; ++p) {
        comm_handler->set_player(p + 1, 4);
    }
    for (int q = player_count; q < 9; ++q) {
        comm_handler->set_player(q + 1, 0);
    }

    if (!rge_base_game->start_game(0)) {
        self->popupOKDialog(0x961, 0, 0x1c2, 100);
    }
}
