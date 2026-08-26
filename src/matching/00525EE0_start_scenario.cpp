// VA: 00525EE0 TRIBE_Game::start_scenario (653 B)
// PDB source: tribegam.cpp:2670-2781
// Attempt log:
// baseline: reconstructed the scenario-start state setup, scenario-file
// selection, player mapping, failure returns, and communication ownership
// from the executable and same-TU startGame donor.
// control-flow: spelling the absent-player tail as increment then <= 9
// reproduced the original cmp 9 branch polarity; the equivalent < 10 form
// was rolled back.
// layout: declaration reordering and a 264-byte path buffer were duplicates or
// worse. The period path payload is 256 bytes in the 260-byte stack window.
// abi: the CRT find-data destination is the time_create field at offset 4;
// the 0x11c local work window reproduces the original stack address. A full
// canonical field expansion changed the path address and was rolled back.
// exact: current source matches all 653 bytes, 46 ordered calls, and the
// original 0x220 frame without inline assembly or raw codegen helpers.

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" long __cdecl _findfirst(const char* filespec, void* fileinfo);

#ifndef TRIBEGAM_TU_CONTEXT
class RGE_Prog_Info {
public:
    char gap_00[0xC17];
    char scenario_dir[261];
};

class TCommunications_Handler {
public:
    void SetPlayerHumanity(unsigned int player, int humanity);
};

class RGE_Static_Object;

struct ScenarioFileInfo {
    int attrib;
    long time_create;
    char rest[0x114];
};

class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int player);
    virtual ~RGE_Scenario();
    virtual void rehook();
    virtual void save(int file);

    int Get_player_Active(int player);
    int Get_player_Civ(int player);
    int Get_player_Type(int player);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char gap_04[8];
    RGE_Prog_Info* prog_info; // +0x0C
    char gap_10[0x17C];
    TCommunications_Handler* comm_handler; // +0x18C

    void disable_input();
    void enable_input();
    void setSinglePlayerGame(int value);
    void setCampaignGame(int value);
    void setSavedGame(int value);
    void setScenarioGame(int value);
    void setScenarioName(char* name);
    void setFullVisibility(int value);
    void setFogOfWar(int value);
    void setAllowCheatCodes(int value);
    void setPlayerTeam(int player, int team);
    RGE_Scenario* get_scenario_info(char* name, int mode);
    void setNumberPlayers(int number_players);
    int get_single_player_difficulty();
    void setDifficulty(int difficulty);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    enum VictoryType { VictoryType_Unknown = 0 };
    enum ResourceLevel { ResourceLevel_Unknown = 0 };
    enum Age { Age_Unknown = 0 };

    void setVictoryType(VictoryType type, int amount);
    void setRandomizePositions(int value);
    void setLongCombat(int value);
    void setAllowTrading(int value);
    void setFullTechTree(int value);
    void setResourceLevel(ResourceLevel value);
    void setStartingAge(Age value);
    void setStartingUnits(int value);
    void setDeathMatch(unsigned char value);
    void setPopLimit(unsigned char value);
    void setQuickStartGame(unsigned char value);
    void setScenarioPlayer(int player, int scenario_player);
    void setCivilization(int player, int civilization);
    void setPlayerColor(int player, int color);
    void setComputerName(int player, int value);
    int scenarioPlayer(int player);
    int start_game(int mode);

    int start_scenario(char* scenario);
};
#endif

int TRIBE_Game::start_scenario(char* scenario)
{
    char scenario_file2[256];
    ScenarioFileInfo file_info;
    int first_any_player;
    int player_count;
    RGE_Scenario* scenario_info;

    this->disable_input();
    this->setSinglePlayerGame(1);
    this->setCampaignGame(0);
    this->setSavedGame(0);
    this->setScenarioGame(1);
    this->setScenarioName(scenario);
    this->setVictoryType((TRIBE_Game::VictoryType)0, 0);
    this->setFullVisibility(0);
    this->setFogOfWar(1);
    this->setAllowCheatCodes(1);
    this->setRandomizePositions(0);
    this->setLongCombat(0);
    this->setAllowTrading(1);
    this->setFullTechTree(0);
    this->setResourceLevel((TRIBE_Game::ResourceLevel)0);
    this->setStartingAge((TRIBE_Game::Age)0);
    this->setStartingUnits(0);
    this->setDeathMatch(0);
    this->setPopLimit(50);
    this->setDifficulty(this->get_single_player_difficulty());
    this->setQuickStartGame(0);

    player_count = 0;
    first_any_player = -1;
    sprintf(scenario_file2, "%s%s.scn", this->prog_info->scenario_dir,
            scenario);
    if (_findfirst(scenario_file2, &file_info.time_create) == -1) {
        sprintf(scenario_file2, "%s.scx", scenario);
    } else {
        sprintf(scenario_file2, "%s.scn", scenario);
    }

    scenario_info = this->get_scenario_info(scenario_file2, 0);
    if (scenario_info == 0) {
        this->enable_input();
        return 0;
    }

    for (int i = 0; i < 9; ++i) {
        if (scenario_info->Get_player_Active(i) != 0) {
            this->setScenarioPlayer(player_count, i);
            this->setCivilization(i, scenario_info->Get_player_Civ(i));
            this->setPlayerColor(i, i + 1);
            this->setPlayerTeam(i, 1);
            this->setComputerName(i, 0);
            ++player_count;
            if (first_any_player == -1 &&
                scenario_info->Get_player_Type(i) == 1) {
                first_any_player = i;
            }
        }
    }

    delete scenario_info;
    if (player_count == 0) {
        this->enable_input();
        return 0;
    }

    this->setNumberPlayers(player_count);
    if (first_any_player != -1) {
        int i;
        for (i = 1; i < player_count; ++i) {
            if (this->scenarioPlayer(i) == first_any_player) {
                this->setScenarioPlayer(i, this->scenarioPlayer(0));
                break;
            }
        }
        this->setScenarioPlayer(0, first_any_player);
    }

    this->comm_handler->SetPlayerHumanity(1, 2);
    for (int player = 2; player <= player_count; ++player) {
        this->comm_handler->SetPlayerHumanity(player, 4);
    }
    ++player_count;
    while (player_count <= 9) {
        this->comm_handler->SetPlayerHumanity(player_count, 0);
        ++player_count;
    }

    return this->start_game(1);
}
