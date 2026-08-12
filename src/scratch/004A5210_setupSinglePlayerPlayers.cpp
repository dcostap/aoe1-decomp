// VA: 004A5210 setupSinglePlayerPlayers
// PDB donor: scr_mps.cpp:2793-2886
//
// Natural reconstruction of the single-player/scenario player initialization.
// The screen fields and the narrow game/communications setter parameters use
// the period ABI surfaces established by same-TU donors.
//
// Attempt log (orch-scrmps-fresh-03):
// - Re-established the binary-backed ownership before probing codegen: the
//   screen owns scenarioPlayerCount (+0x728) and scenarioInfo (+0x848), while
//   the TRIBE_Game and communications globals provide the player setters.
// - Fresh baseline: natural scenario-player compaction, first-any selection,
//   random-game initialization, teams, humanity, and dropdown refresh.  The
//   first-any locals follow the executable's actual roles: scenario-player
//   index, civilization, palette color, and the register-only post-loop copy.
// - Corrected ABI evidence from basegame.cpp, tribegam.cpp, and com_hand.cpp:
//   setNumberPlayers/setPlayerTeam/setPlayerColor take int values, while
//   SetPlayerHumanity takes the PLAYERHUMANITY enum.  This reduced the clean
//   candidate from a 560-byte/400-byte-diff build to 556 bytes with a 20-byte
//   diff and all 49 relocation identities exact.
// - Declaration-order, direct-this/ordinary screen-alias, inherited
//   TScreenPanel, induction-scope, and register-qualification probes were
//   codegen duplicates.  The remaining localized drift is saved-this/count
//   register coloring (original EBX=this/EBP=count versus rebuilt
//   EBP=this/EBX=count) plus the random-loop tail's compare/move order.
// - Final unresolved source is restored to the simplest typed form; leave in
//   scratch for a later worker rather than retain compiler-steering aliases.
// - Fresh claim: function-scope declarations, assignment in the random-loop
//   condition, and a flat screen base were codegen duplicates. Keep the clear
//   role names and pinned natural source.

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
    void setNumberPlayers(int number);
    void setPlayerTeam(int player, int team);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void setScenarioPlayer(int player, int scenario_player);
    void setCivilization(int player, int civilization);
    void setPlayerColor(int player, int color);
    int scenarioPlayer(int player);
    int civilization(int player);
    int playerColor(int player);
};

enum PLAYERHUMANITY {
    ME_ABSENT = 0,
    ME_HUMAN = 2,
    ME_COMPUTER = 4
};

class TCommunications_Handler {
public:
    void SetPlayerHumanity(unsigned int player, PLAYERHUMANITY humanity);
};

class TPanel {
public:
    virtual ~TPanel();
};

class TScreenPanel : public TPanel {
public:
    char gap_04[0x474];
};

class TribeMPSetupScreen : public TScreenPanel {
public:
    char gap_478[0x2B0];
    int scenarioPlayerCount; // +0x728
    char gap_72C[0x11C];
    RGE_Scenario* scenarioInfo; // +0x848
    virtual ~TribeMPSetupScreen();

    void setupSinglePlayerPlayers();
    void fillNumberPlayers();
};

extern TRIBE_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern "C" int __cdecl debug_rand(char* file, int line);

void TribeMPSetupScreen::setupSinglePlayerPlayers() {
    int first_any_scenario_player;
    int selected_scenario_player;
    int first_any_civilization;
    int first_any_player_color;
    TribeMPSetupScreen* screen = this;
    if (rge_base_game->scenarioGame() != 0) {
        first_any_scenario_player = -1;
        selected_scenario_player = -1;
        first_any_civilization = -1;
        first_any_player_color = -1;

        if (screen->scenarioInfo != 0) {
            int player_count = 0;
            int scenario_player = 0;
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
                        first_any_scenario_player == -1) {
                        first_any_scenario_player = scenario_player;
                        first_any_civilization =
                            screen->scenarioInfo->Get_player_Civ(scenario_player);
                        first_any_player_color = scenario_player + 1;
                    }
                    selected_scenario_player = first_any_scenario_player;
                    ++player_count;
                }
                ++scenario_player;
            } while (scenario_player < 9);
        }

        rge_base_game->setNumberPlayers(screen->scenarioPlayerCount);
        if (selected_scenario_player != -1) {
            int player = 1;
            if (screen->scenarioPlayerCount > 1) {
                while (player < screen->scenarioPlayerCount) {
                    if (((TRIBE_Game*)rge_base_game)->scenarioPlayer(player) ==
                        selected_scenario_player) {
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
                0, selected_scenario_player);
            ((TRIBE_Game*)rge_base_game)->setCivilization(0, first_any_civilization);
            ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                0, first_any_player_color);
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

    comm->SetPlayerHumanity(1, ME_HUMAN);
    player = 2;
    do {
        comm->SetPlayerHumanity(player, ME_COMPUTER);
        ++player;
    } while (player <= 8);
    comm->SetPlayerHumanity(9, ME_ABSENT);
    screen->fillNumberPlayers();
}
