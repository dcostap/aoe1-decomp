// VA: 004A5210 setupSinglePlayerPlayers
// PDB donor: scr_mps.cpp:2793-2886
//
// Natural reconstruction of the single-player/scenario player initialization.
// The screen fields and the narrow game/communications setter parameters use
// the period ABI surfaces established by same-TU donors.
//
// Recovery notes:
// - PDB evidence assigns this method to scr_mps.cpp lines 2793-2886.
// - The screen owns scenarioPlayerCount (+0x728) and scenarioInfo (+0x848).
// - The game and communications objects own the player publication calls.
// - The executable uses int setter arguments and PLAYERHUMANITY values.
// - The executable publishes scenario players, civilizations, colors, teams,
//   and humanity in the order shown below.
// - BINARY NOTE: the decompiler-only first_any_player copy is not needed.
//   first_any_civ carries that value through the later lookup and publication.
// - Removing that copy changed the saved-register assignment to the original:
//   EBX holds this and EBP holds the active-player count.
// - Exact-finish walkback restored the copy and returned to the 15-byte drift.
// - Removing the screen pointer alias also kept the exact result.
// - Fresh exact check: 556 bytes, 27 ordered calls, correct owner, and 0 bytes
//   differ. The checker reported MATCH and 0.0000%.

#ifndef SCR_MPS_TU_CONTEXT

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

#endif

void TribeMPSetupScreen::setupSinglePlayerPlayers() {
    int first_any_civ;
    int first_any_color;
    int first_any_color_index;
    if (rge_base_game->scenarioGame() != 0) {
        first_any_civ = -1;
        first_any_color = -1;
        first_any_color_index = -1;

        if (this->scenarioInfo != 0) {
            int player_count = 0;
            int scenario_player = 0;
            do {
                if (this->scenarioInfo->Get_player_Active(scenario_player) != 0) {
                    ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(
                        player_count, scenario_player);
                    int civilization =
                        this->scenarioInfo->Get_player_Civ(scenario_player);
                    ((TRIBE_Game*)rge_base_game)->setCivilization(
                        player_count, civilization);
                    ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                        player_count, scenario_player + 1);

                    if (this->scenarioInfo->Get_player_Type(scenario_player) == 1 &&
                        first_any_civ == -1) {
                        first_any_civ = scenario_player;
                        first_any_color =
                            this->scenarioInfo->Get_player_Civ(scenario_player);
                        first_any_color_index = scenario_player + 1;
                    }
                    ++player_count;
                }
                ++scenario_player;
            } while (scenario_player < 9);
        }

        rge_base_game->setNumberPlayers(this->scenarioPlayerCount);
        if (first_any_civ != -1) {
            int player = 1;
            if (this->scenarioPlayerCount > 1) {
                while (player < this->scenarioPlayerCount) {
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

            ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(0, first_any_civ);
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
    this->fillNumberPlayers();
}
