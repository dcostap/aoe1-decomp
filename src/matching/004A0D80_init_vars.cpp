// VA: 004A0D80 TribeMPSetupScreen::init_vars
// PDB donor: scr_mps.cpp:443-663
//
// Canonical typed reconstruction of the screen's pointer/member initialization
// and the single-player/multiplayer game-default setup paths.
// Attempt log:
// - typed parallel member-array loops replaced raw offset/cursor scaffolding;
//   the proven screen base gap places the first fields at +0x478.
// - corrected +0x728 ownership, saveScenarioName[0], and adjacent default
//   assignment order; the fixed zero loop reproduces the +0x868 rep-stosd.
// - int,int setPlayerColor reproduces the caller's explicit zero extension.
// - kept the random remainder separate from its mapped result for the exact
//   VC5 branch shape; only map-size/type setup is scenario-game guarded.
// - exact: 1403/1403 bytes, 62/62 calls, all relocations and CFG signals.

#ifndef SCR_MPS_TU_CONTEXT

#include <string.h>

class TPanel;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual void* new_scenario_header(void*);
    virtual void* new_scenario_header(int);
    virtual void* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void beginStart(); // slot 18, +0x48

    int randomGame();
    int multiplayerGame();
    int scenarioGame();
    void setCampaignGame(int value);
    void setSavedGame(int value);
    void setScenarioGame(int value);
    void setScenarioName(char* name);
    void setNumberPlayers(int value);
    void setPlayerTeam(int player, unsigned char team);
    void setFullVisibility(int value);
    void setFogOfWar(int value);
    void setAllowCheatCodes(int value);
    int get_single_player_difficulty();
    void setDifficulty(int value);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void setMapSize(int value);
    void setMapType(int value);
    void setVictoryType(int type, int amount);
    void setAnimals(int value);
    void setPredators(int value);
    void setRandomizePositions(int value);
    void setLongCombat(int value);
    void setAllowTrading(int value);
    void setFullTechTree(int value);
    void setResourceLevel(int value);
    void setStartingAge(int value);
    void setStartingUnits(int value);
    void setDeathMatch(int value);
    void setQuickStartGame(int value);

    void setCivilization(int player, int civilization);
    void setScenarioPlayer(int player, int scenario_player);
    void setPlayerHasCD(int player, int value);
    void setPlayerVersion(int player, int value);
    void setPlayerColor(int player, int color);
    void setPlayerTeam(int player, unsigned char team);
    void setComputerName(int player, int name);
};

class TCommunications_Handler {
public:
    int IsHost();
};

extern TRIBE_Game* rge_base_game;
extern TCommunications_Handler* comm;

extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern "C" void __cdecl debug_srand(char* file, int line, unsigned long seed);
extern "C" int __cdecl debug_rand(char* file, int line);

class TribeMPSetupScreen {
public:
    virtual ~TribeMPSetupScreen();
    char base_gap_04[0x474];

    TPanel* title;                 // +0x478
    TPanel* playerTitle;           // +0x47C
    TPanel* civTitle;              // +0x480
    TPanel* settingsTitle;         // +0x484
    TPanel* colorTitle;            // +0x488
    TPanel* teamTitle;             // +0x48C
    TPanel* playerNameText[8];     // +0x490
    TPanel* playerCivText[8];      // +0x4B0
    TPanel* scenarioPlayerText[8];// +0x4D0
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
    TPanel* victoryTypeLabel;      // +0x6F0
    TPanel* victoryTypeDrop;       // +0x6F4
    TPanel* victoryAmountLabel;    // +0x6F8
    TPanel* victoryAmountInput;    // +0x6FC
    TPanel* startButton;            // +0x700
    TPanel* readyButtons[2];        // +0x704
    TPanel* cancelButton;           // +0x70C
    TPanel* help_button;            // +0x710
    TPanel* ready_button;           // +0x714
    TPanel* close_button;           // +0x718
    TPanel* ready_button_label;     // +0x71C
    int cancelMode;                 // +0x720
    int playerToKick;               // +0x724
    int scenarioPlayerCount;        // +0x728
    int myCivilization;             // +0x72C
    int myScenarioPlayer;           // +0x730
    int myPlayerColor;              // +0x734
    int myPlayerTeam;               // +0x738
    int myScenarioChecksum;         // +0x73C
    char saveScenarioName[0x100];   // +0x740
    int saveRandomGame;             // +0x840
    int saveScenarioChecksum;       // +0x844
    void* scenarioInfo;             // +0x848
    int settingsFixed;              // +0x84C
    int numberAnyPlayers;           // +0x850
    int sent_cd_status;             // +0x854
    TPanel* netInfoButton;          // +0x858
    int i_am_ready;                 // +0x85C
    unsigned char defaultColor[8];  // +0x860
    long scenarioCheckSum[8];       // +0x868
    int last_send_shared;           // +0x888
    int resend_game_options;        // +0x88C

    void init_vars();
};

#endif

void TribeMPSetupScreen::init_vars() {
    int i;

    this->title = 0;
    this->playerTitle = 0;
    this->civTitle = 0;
    this->settingsTitle = 0;
    this->colorTitle = 0;
    this->teamTitle = 0;

    for (i = 0; i < 8; ++i) {
        this->playerNameDrop[i] = 0;
        this->playerCivDrop[i] = 0;
        this->scenarioPlayerDrop[i] = 0;
        this->playerColor[i] = 0;
        this->playerTeam[i] = 0;
        this->playerNameText[i] = 0;
        this->playerCivText[i] = 0;
        this->scenarioPlayerText[i] = 0;
        this->playerCDText[i] = 0;
        this->playerVersionText[i] = 0;
        this->playerColorText[i] = 0;
        this->playerTeamText[i] = 0;
    }

    this->chatInput = 0;
    this->chatTitle = 0;
    this->chatScrollbar = 0;
    this->chatBox = 0;
    this->gameSettingsButton = 0;
    this->scenarioName = 0;
    this->victoryFixedText = 0;

    for (i = 0; i < 20; ++i) {
        this->settingText[i] = 0;
        this->settingValue[i] = 0;
    }

    this->mapSizeLabel = 0;
    this->mapSizeDrop = 0;
    this->mapTypeLabel = 0;
    this->mapTypeDrop = 0;
    this->numberPlayersTitle = 0;
    this->numberPlayersDrop = 0;
    this->numberPlayersText = 0;
    this->hiddenMapButton = 0;
    this->hiddenMapText = 0;
    this->victoryTypeLabel = 0;
    this->victoryTypeDrop = 0;
    this->victoryAmountLabel = 0;
    this->victoryAmountInput = 0;
    this->ready_button_label = 0;
    this->startButton = 0;
    this->readyButtons[0] = 0;
    this->readyButtons[1] = 0;
    this->cancelButton = 0;
    this->help_button = 0;
    this->ready_button = 0;
    this->close_button = 0;
    this->cancelMode = 0;
    this->playerToKick = 0;
    this->myCivilization = 0;
    this->myScenarioPlayer = -1;
    this->myPlayerColor = 0;
    this->myPlayerTeam = 0;
    this->myScenarioChecksum = 0;
    this->saveScenarioName[0] = 0;
    this->saveRandomGame = rge_base_game->randomGame();
    int* zero_block = this->scenarioCheckSum;
    this->saveScenarioChecksum = 0;
    this->scenarioInfo = 0;
    this->numberAnyPlayers = 8;
    this->scenarioPlayerCount = 8;
    this->settingsFixed = 0;
    this->sent_cd_status = 0;
    this->netInfoButton = 0;
    this->i_am_ready = 0;
    for (i = 0; i < 8; ++i) {
        zero_block[i] = 0;
    }
    this->last_send_shared = 0;
    this->resend_game_options = 0;

    if (rge_base_game->multiplayerGame() != 0) {
        rge_base_game->setCampaignGame(0);
        rge_base_game->setSavedGame(0);
        rge_base_game->setScenarioGame(0);
        rge_base_game->setScenarioName("");
        ((TRIBE_Game*)rge_base_game)->setMapSize(3);
        ((TRIBE_Game*)rge_base_game)->setMapType(3);
        ((TRIBE_Game*)rge_base_game)->setVictoryType(0, 0);
        ((TRIBE_Game*)rge_base_game)->setAnimals(1);
        ((TRIBE_Game*)rge_base_game)->setPredators(1);
        rge_base_game->setNumberPlayers(8);
        rge_base_game->setFullVisibility(0);
        rge_base_game->setFogOfWar(1);
        rge_base_game->setAllowCheatCodes(0);
        ((TRIBE_Game*)rge_base_game)->setRandomizePositions(0);
        ((TRIBE_Game*)rge_base_game)->setLongCombat(0);
        ((TRIBE_Game*)rge_base_game)->setAllowTrading(1);
        ((TRIBE_Game*)rge_base_game)->setFullTechTree(0);
        ((TRIBE_Game*)rge_base_game)->setResourceLevel(0);
        ((TRIBE_Game*)rge_base_game)->setStartingAge(0);
        ((TRIBE_Game*)rge_base_game)->setStartingUnits(0);
        rge_base_game->setDifficulty(
            rge_base_game->get_single_player_difficulty());
        ((TRIBE_Game*)rge_base_game)->setDeathMatch(0);
        ((TRIBE_Game*)rge_base_game)->setQuickStartGame(0);
        unsigned long now = debug_timeGetTime(
            "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x243);
        debug_srand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x243, now);

        for (i = 0; i < 8; ++i) {
            this->defaultColor[i] = (unsigned char)(i + 1);
            ((TRIBE_Game*)rge_base_game)->setCivilization(
                i,
                debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x248) %
                        16 +
                    1);
            ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(i, i);
            ((TRIBE_Game*)rge_base_game)->setPlayerHasCD(i, 0);
            ((TRIBE_Game*)rge_base_game)->setPlayerVersion(i, 0);
            ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                i, this->defaultColor[i]);
            ((TRIBE_Game*)rge_base_game)->setPlayerTeam(i, 1);
            ((TRIBE_Game*)rge_base_game)->setComputerName(i, 0);
        }

        if (((TCommunications_Handler*)comm)->IsHost() != 0) {
            ((TRIBE_Game*)rge_base_game)->setPlayerVersion(0, 1);
            rge_base_game->beginStart();
            this->resend_game_options = 0;
            return;
        }
    } else {
        if (rge_base_game->scenarioGame() == 0) {
            ((TRIBE_Game*)rge_base_game)->setMapSize(3);
            int random_map = debug_rand(
                                  "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x26A) %
                              10;
            int map_type;
            if (random_map < 2) {
                map_type = 4;
            } else if (random_map == 2) {
                map_type = 3;
            } else if (random_map == 3) {
                map_type = 2;
            } else if (random_map == 4) {
                map_type = 1;
            } else if (random_map == 5) {
                map_type = random_map;
            } else if (random_map == 6) {
                map_type = random_map;
            } else if (random_map == 7) {
                map_type = random_map;
            } else {
                map_type = (random_map == 8) ? 8 : 0;
            }
            ((TRIBE_Game*)rge_base_game)->setMapType(map_type);
        }
        ((TRIBE_Game*)rge_base_game)->setVictoryType(0, 0);
        rge_base_game->setNumberPlayers(4);
        rge_base_game->setCampaignGame(0);
        rge_base_game->setSavedGame(0);
        ((TRIBE_Game*)rge_base_game)->setAnimals(1);
        ((TRIBE_Game*)rge_base_game)->setPredators(1);
        rge_base_game->setFullVisibility(0);
        rge_base_game->setFogOfWar(1);
        rge_base_game->setAllowCheatCodes(1);
        ((TRIBE_Game*)rge_base_game)->setRandomizePositions(0);
        ((TRIBE_Game*)rge_base_game)->setLongCombat(0);
        ((TRIBE_Game*)rge_base_game)->setAllowTrading(1);
        ((TRIBE_Game*)rge_base_game)->setFullTechTree(0);
        ((TRIBE_Game*)rge_base_game)->setResourceLevel(0);
        ((TRIBE_Game*)rge_base_game)->setStartingAge(0);
        ((TRIBE_Game*)rge_base_game)->setStartingUnits(0);
        rge_base_game->setDifficulty(
            rge_base_game->get_single_player_difficulty());
        ((TRIBE_Game*)rge_base_game)->setQuickStartGame(0);
    }
}
