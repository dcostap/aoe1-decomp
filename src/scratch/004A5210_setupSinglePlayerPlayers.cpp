// VA: 004A5210 setupSinglePlayerPlayers
// PDB donor: scr_mps.cpp:2793-2886
//
// Natural reconstruction of the single-player/scenario player initialization.
// The screen fields and the narrow game/communications setter parameters use
// the period ABI surfaces established by same-TU donors.
//
// Attempt log (sa64f8-single):
// - Baseline recovered the 0xC frame, four saved registers, and 27 of the 27
//   ordered call sites after correcting the scenario/game/player surfaces.
// - Capturing the screen pointer and using dword expressions at the narrow
//   setter call boundaries removed the extra scenarioPlayer call and brought
//   the candidate to 561 bytes (original 556), 94.22% shape, with all calls
//   aligned.  The first remaining hunk is the whole-function saved-this and
//   induction-register coloring (rebuilt EBP=this/ESI count/EBX scenario vs
//   original EBX=this/EBP count/ESI scenario).
// - The first-any spill/reload order and the observed old-value local_4 are
//   retained as executable behavior; declaration, register, and same-TU
//   TRIBE_Game-global context probes were codegen duplicates.  No further
//   blind variants remain in this assignment; leave the readable typed source
//   in scratch for a later worker to pursue the register basin.

class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    int Get_player_Active(int index);
    int Get_player_Civ(int index);
    int Get_player_Type(int index);
};

class RGE_Base_Game {
public:
    int scenarioGame();
    void setNumberPlayers(unsigned char number);
    void setPlayerTeam(int player, unsigned char team);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void setScenarioPlayer(int player, int scenario_player);
    void setCivilization(int player, int civilization);
    void setPlayerColor(int player, unsigned char color);
    int scenarioPlayer(int player);
    int civilization(int player);
    int playerColor(int player);
};

class TCommunications_Handler {
public:
    void SetPlayerHumanity(unsigned int player, int humanity);
};

class TribeMPSetupScreen {
public:
    virtual ~TribeMPSetupScreen();
    char gap_04[0x724];
    int scenarioPlayerCount; // +0x728
    char gap_72C[0x11C];
    RGE_Scenario* scenarioInfo; // +0x848

    void setupSinglePlayerPlayers();
    void fillNumberPlayers();
};

extern TRIBE_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern "C" int __cdecl debug_rand(char* file, int line);

void TribeMPSetupScreen::setupSinglePlayerPlayers() {
    int player_count;
    int scenario_player;
    int first_any_player;
    int first_any_civ;
    int first_any_color;
    int previous_any_scenario_player;
    TribeMPSetupScreen* screen = this;

    if (rge_base_game->scenarioGame() != 0) {
        first_any_player = -1;
        first_any_civ = -1;
        first_any_color = -1;
        previous_any_scenario_player = -1;

        if (screen->scenarioInfo != 0) {
            player_count = 0;
            scenario_player = 0;
            do {
                if (screen->scenarioInfo->Get_player_Active(scenario_player) != 0) {
                    ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(
                        player_count, scenario_player);
                    int civilization =
                        screen->scenarioInfo->Get_player_Civ(scenario_player);
                    ((TRIBE_Game*)rge_base_game)->setCivilization(
                        player_count, civilization);
                    ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                        player_count, scenario_player + 1);

                    if (screen->scenarioInfo->Get_player_Type(scenario_player) == 1 &&
                        first_any_player == -1) {
                        first_any_player = scenario_player;
                        first_any_color =
                            screen->scenarioInfo->Get_player_Civ(scenario_player);
                        previous_any_scenario_player = first_any_civ;
                    }
                    first_any_civ = first_any_player;
                    ++player_count;
                }
                ++scenario_player;
            } while (scenario_player < 9);
        }

        rge_base_game->setNumberPlayers(screen->scenarioPlayerCount);
        if (first_any_civ != -1) {
            int player = 1;
            if (screen->scenarioPlayerCount > 1) {
                while (player < screen->scenarioPlayerCount) {
                    if (((TRIBE_Game*)rge_base_game)->scenarioPlayer(player) ==
                        first_any_civ) {
                        int scenario_player =
                            ((TRIBE_Game*)rge_base_game)->scenarioPlayer(0);
                        ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(
                            player, scenario_player);
                        int civilization =
                            ((TRIBE_Game*)rge_base_game)->civilization(0);
                        ((TRIBE_Game*)rge_base_game)->setCivilization(
                            player, civilization);
                        int color =
                            ((TRIBE_Game*)rge_base_game)->playerColor(0);
                        ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                            player, color);
                        break;
                    }
                    ++player;
                }
            }

            ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(
                0, first_any_civ);
            ((TRIBE_Game*)rge_base_game)->setCivilization(0, first_any_color);
            ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                0, previous_any_scenario_player);
        }
    } else {
        int player = 0;
        do {
            int civilization =
                debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0xB31) %
                    16 + 1;
            ((TRIBE_Game*)rge_base_game)->setCivilization(player, civilization);
            int color = player + 1;
            ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                player, color);
            player = color;
        } while (player < 8);
    }

    int player = 0;
    do {
        rge_base_game->setPlayerTeam(player, 1);
        ++player;
    } while (player < 8);

    comm->SetPlayerHumanity(1, 2);
    player = 2;
    do {
        comm->SetPlayerHumanity(player, 4);
        ++player;
    } while (player <= 8);
    comm->SetPlayerHumanity(9, 0);
    screen->fillNumberPlayers();
}
