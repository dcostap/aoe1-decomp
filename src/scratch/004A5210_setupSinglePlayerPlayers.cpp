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
//   first-any locals follow the executable's actual roles: the scenario index
//   is first_any_civ, its civilization is first_any_color, and its palette
//   color is local_4; first_any_player is the register-only post-loop copy.
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
// - Fresh claim: moving active-loop declarations to function scope, putting
//   the random assignment in the do-while condition, and flattening the
//   same-size screen base were codegen duplicates. Restored the pinned source.
// - Scoped the screen alias to the scenario branch and called the final
//   refresh through this; codegen stayed identical, so restored the clean form.
// - Swapped the typed scenario-player and active-player declarations; the
//   saved-source diff grew from 20 to 21 bytes, so restored the clean order.
// - Revisit: using the direct player+1 expression and then assigning that
//   value back to player reproduces the random-loop tail.  The removed color
//   temporary had caused a compare-before-move schedule.
// - Revisit: the proven complete screen member surface and 128 ambient
//   declaration samples did not change the remaining register coloring.
// - Current clean candidate: 556 bytes with 15 differing bytes.  All calls,
//   blocks, size, frame, and CFG signals match.  Remaining drift is only the
//   EBX/EBP assignment for this and the active-player count.

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
    TPanel* title;                 // +0x478
    TPanel* playerTitle;           // +0x47C
    TPanel* civTitle;              // +0x480
    TPanel* settingsTitle;         // +0x484
    TPanel* colorTitle;            // +0x488
    TPanel* teamTitle;             // +0x48C
    TPanel* playerNameText[8];     // +0x490
    TPanel* playerCivText[8];      // +0x4B0
    TPanel* scenarioPlayerText[8]; // +0x4D0
    TPanel* playerCDText[8];       // +0x4F0
    TPanel* playerVersionText[8];  // +0x510
    TPanel* playerColorText[8];    // +0x530
    TPanel* playerTeamText[8];     // +0x550
    TPanel* playerColor[8];        // +0x570
    TPanel* playerTeam[8];         // +0x590
    TPanel* playerNameDrop[8];     // +0x5B0
    TPanel* playerCivDrop[8];      // +0x5D0
    TPanel* scenarioPlayerDrop[8];// +0x5F0
    TPanel* chatInput;             // +0x610
    TPanel* chatTitle;             // +0x614
    TPanel* chatBox;               // +0x618
    TPanel* chatScrollbar;         // +0x61C
    TPanel* gameSettingsButton;    // +0x620
    TPanel* scenarioName;          // +0x624
    TPanel* victoryFixedText;      // +0x628
    TPanel* settingText[20];       // +0x62C
    TPanel* settingValue[20];      // +0x67C
    TPanel* mapSizeLabel;          // +0x6CC
    TPanel* mapSizeDrop;           // +0x6D0
    TPanel* mapTypeLabel;          // +0x6D4
    TPanel* mapTypeDrop;           // +0x6D8
    TPanel* numberPlayersTitle;    // +0x6DC
    TPanel* numberPlayersDrop;     // +0x6E0
    TPanel* numberPlayersText;     // +0x6E4
    TPanel* hiddenMapButton;       // +0x6E8
    TPanel* hiddenMapText;         // +0x6EC
    TPanel* victoryTypeLabel;       // +0x6F0
    TPanel* victoryTypeDrop;        // +0x6F4
    TPanel* victoryAmountLabel;     // +0x6F8
    TPanel* victoryAmountInput;     // +0x6FC
    TPanel* startButton;            // +0x700
    TPanel* readyButtons[2];        // +0x704
    TPanel* cancelButton;           // +0x70C
    TPanel* help_button;            // +0x710
    TPanel* ready_button;           // +0x714
    TPanel* close_button;           // +0x718
    TPanel* ready_button_label;     // +0x71C
    int cancelMode;                 // +0x720
    int playerToKick;               // +0x724
    int scenarioPlayerCount; // +0x728
    int myCivilization;      // +0x72C
    int myScenarioPlayer;    // +0x730
    int myPlayerColor;       // +0x734
    int myPlayerTeam;        // +0x738
    int myScenarioChecksum;  // +0x73C
    char saveScenarioName[0x100]; // +0x740
    int saveRandomGame;      // +0x840
    int saveScenarioChecksum; // +0x844
    RGE_Scenario* scenarioInfo; // +0x848
    virtual ~TribeMPSetupScreen();

    void setupSinglePlayerPlayers();
    void fillNumberPlayers();
};

extern TRIBE_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern "C" int __cdecl debug_rand(char* file, int line);

void TribeMPSetupScreen::setupSinglePlayerPlayers() {
    int first_any_civ;
    int first_any_player;
    int first_any_color;
    int first_any_color_index;
    TribeMPSetupScreen* screen = this;
    if (rge_base_game->scenarioGame() != 0) {
        first_any_civ = -1;
        first_any_player = -1;
        first_any_color = -1;
        first_any_color_index = -1;

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
                        first_any_civ == -1) {
                        first_any_civ = scenario_player;
                        first_any_color =
                            screen->scenarioInfo->Get_player_Civ(scenario_player);
                        first_any_color_index = scenario_player + 1;
                    }
                    first_any_player = first_any_civ;
                    ++player_count;
                }
                ++scenario_player;
            } while (scenario_player < 9);
        }

        rge_base_game->setNumberPlayers(screen->scenarioPlayerCount);
        if (first_any_player != -1) {
            int player = 1;
            if (screen->scenarioPlayerCount > 1) {
                while (player < screen->scenarioPlayerCount) {
                    if (((TRIBE_Game*)rge_base_game)->scenarioPlayer(player) ==
                        first_any_player) {
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
                0, first_any_player);
            ((TRIBE_Game*)rge_base_game)->setCivilization(0, first_any_color);
            ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                0, first_any_color_index);
        }
    } else {
        int player = 0;
        do {
            int civilization =
                debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0xB31) %
                    16 + 1;
            ((TRIBE_Game*)rge_base_game)->setCivilization(player, civilization);
            ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                player, player + 1);
            player = player + 1;
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
