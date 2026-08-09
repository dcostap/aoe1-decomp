// VA: 00531350 TRIBE_World::send_zone_score_info (877 B)
// PDB source: tworld.cpp lines 1641-1757
// Baseline reconstruction: build the 0x1fc-byte zone message from the world,
// player history, score summaries, game options, and communication state.
// Attempt log:
// - Replaced the packet scaffold with typed period-plausible ownership for the
//   TRIBE_Zone_Info/TRIBE_Game_Options buffers and the five score summaries.
// - Baseline had the exact 15-call multiset but a 0x274 frame and an emitted
//   sparse-switch table beyond the original boundary.  An if/else mapping for
//   the sparse game-end values removes that table and reaches an 891 B body.
// - Polymorphic/flattened world stubs were codegen-neutral.  A saved player
//   array alias and a long-lived player pointer regressed liveness; both were
//   removed.  The binary reloads this->players[player] for the later history
//   phase, so the final source follows those direct reloads.
// - Corrected history rewards to event->world_time (+8), removed an unsupported
//   history-null guard, and modeled the 1-based random-civ/WasKicked accesses
//   against the proven preceding array slots.  These preserve the 15 calls.
// - Final bounded candidate is 877 B/frame 0x270, all 15 calls aligned, and
//   76.54% instruction-shape similarity.  The first remaining source-shape
// - Main-agent audit restored the binary-proven total-score group value 0xff;
//   this is semantically distinct from the diagnostic signed -1 spelling and
//   improved the strict diff from 687 to 402 bytes (77.27% shape), while
//   exposing a remaining two-byte size/frame-home shift.

#include <string.h>

class RGE_Victory_Conditions {
public:
    long get_victory_points();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x30];
    RGE_Victory_Conditions* victory_conditions; // +0x34
    char gap_38[0x0c];
    char* name;                                  // +0x44
    char gap_48[0x38];
    unsigned char game_status;                  // +0x80
    char gap_81[0x19f];

    int computerPlayer();
};

class TRIBE_History_Events {
public:
    unsigned char event;
    char gap_01[3];
    long time;
    long world_time;
    TRIBE_History_Events* next;
};

class TRIBE_History_Info {
public:
    void* history;
    TRIBE_History_Events* events;
    long number_of_events;
    long number_of_entries;
    long max_number_of_entries;
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_220[0x61c];
    TRIBE_History_Info* history; // +0x83c
};

struct TRIBE_Zone_High_Score_Info {
    long score;
    unsigned char civ;
    char player_name[16];
    unsigned char num_allies;
    unsigned char gap_16[2];
};

struct TRIBE_Zone_Player_Info {
    char name[16];
    long score;
    unsigned char winner;
    unsigned char civ_played;
    unsigned char civ_random;
    unsigned char player_no;
    unsigned char team_no;
    unsigned char game_outcome;
    unsigned char gap_1A[2];
    long tool_time;
    long bronze_time;
    long iron_time;
};

struct TRIBE_Zone_Map_Info {
    unsigned char Map_Size;
    unsigned char Map_Type;
    short Pop_Limit;
    unsigned char Victory_Condition;
    unsigned char Start_Age;
    unsigned char Resources;
    unsigned char Full_Tech;
    unsigned char Fixed_Pos;
    unsigned char Reveal_Map;
    unsigned char Death_Match;
    unsigned char gap_0B;
};

struct TRIBE_Zone_Info {
    unsigned char number_of_players;
    unsigned char number_of_computer_players;
    char scenario_name[32];
    unsigned char gap_22[2];
    unsigned long game_time;
    TRIBE_Zone_High_Score_Info total_score;
    TRIBE_Zone_High_Score_Info religion_score;
    TRIBE_Zone_High_Score_Info economy_score;
    TRIBE_Zone_High_Score_Info combat_score;
    TRIBE_Zone_High_Score_Info research_score;
    TRIBE_Zone_Player_Info player_info[8];
    TRIBE_Zone_Map_Info map_info;
    unsigned char cheats_enabled;
    unsigned char game_end_condition_code;
    unsigned char gap_1EE[2];
    unsigned long database_checksum;
    unsigned long code_checksum;
    unsigned long program_version;
};

struct TRIBE_Game_Options {
    int mapSizeValue;
    int mapTypeValue;
    int animalsValue;
    int predatorsValue;
    int victoryTypeValue;
    int victoryAmountValue;
    unsigned char civilizationValue[9];
    unsigned char gap_21[3];
    int scenarioPlayerValue[9];
    unsigned char playerColorValue[9];
    unsigned char computerNameValue[9];
    unsigned char allowTradingValue;
    unsigned char longCombatValue;
    unsigned char randomizePositionsValue;
    unsigned char fullTechTreeValue;
    unsigned char gap_5E[2];
    int resourceLevelValue;
    int startingAgeValue;
    unsigned char startingUnitsValue;
    unsigned char deathMatchValue;
    unsigned char popLimitValue;
    unsigned char gap_6B;
};

class RGE_Base_Game {
public:
    char gap_00[0xa24];
    int allowCheatCodes();
    int fullVisibility();
    int playerTeam(int player);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_a24[0x30];
    int random_civ[9];

    int civilization(int player);
    int playerColor(int player);
    void get_tribe_options(TRIBE_Game_Options* options);
};

class RGE_Scenario {
public:
    char gap_00[0x1010];
    char* Get_scenario_name();
};

class TCommunications_Handler {
public:
    char gap_00[0x1748];
    int WasKicked[10];

    int SendZoneMessage(char* message, unsigned long length);
};

class RGE_Command {
public:
    char gap_00[0x14];
    TCommunications_Handler* comm;
};

class RGE_Game_World {
public:
    char gap_00[4];
    unsigned long world_time; // +0x04
    char gap_08[0x16];
    unsigned char game_end_condition; // +0x1e
    char gap_1f[0x1d];
    short player_num; // +0x3c
    char gap_3e[2];
    RGE_Player** players; // +0x40
    char gap_44[0x14];
    RGE_Command* commands; // +0x58
    RGE_Scenario* scenario; // +0x5c
    char gap_60[0xc0];
    int sent_zone_score; // +0x120
};

class TRIBE_World {
public:
    virtual unsigned char data_load_world(void* file);
    unsigned long world_time; // +0x04
    char gap_08[0x16];
    unsigned char game_end_condition; // +0x1e
    char gap_1f[0x1d];
    short player_num; // +0x3c
    char gap_3e[2];
    RGE_Player** players; // +0x40
    char gap_44[0x14];
    RGE_Command* commands; // +0x58
    RGE_Scenario* scenario; // +0x5c
    char gap_60[0xc0];
    int sent_zone_score; // +0x120

    void fill_in_score(TRIBE_Zone_High_Score_Info& info, long group);
    void send_zone_score_info();
};

extern TRIBE_Game* rge_base_game;
extern TCommunications_Handler* comm;

void TRIBE_World::send_zone_score_info()
{
    TRIBE_Zone_Info info;
    TRIBE_Game_Options options;
    int computer_players = 0;
    int player;

    if (this->sent_zone_score == 0) {
        this->sent_zone_score = 1;
        info.number_of_players = 0;
        computer_players = 0;
        player = 1;
        if (player < this->player_num) {
            do {
                if (this->players[player]->computerPlayer() == 0)
                    info.number_of_players++;
                else
                    computer_players++;
                player++;
            } while (player < this->player_num);
        }
        info.number_of_computer_players = (unsigned char)computer_players;

        strcpy(info.scenario_name, this->scenario->Get_scenario_name());
        info.game_time = this->world_time / 1000;

        this->fill_in_score(info.total_score, 0xFF);
        this->fill_in_score(info.religion_score, 2);
        this->fill_in_score(info.economy_score, 1);
        this->fill_in_score(info.combat_score, 0);
        this->fill_in_score(info.research_score, 3);

        player = 1;
        if (player < this->player_num) {
            TRIBE_Zone_Player_Info* player_info = info.player_info;
            do {
                strcpy(player_info->name, this->players[player]->name);
                player_info->score =
                    this->players[player]->victory_conditions->get_victory_points();
                player_info->winner = (this->players[player]->game_status == 1);
                player_info->civ_played =
                    (unsigned char)rge_base_game->civilization(player - 1);
                player_info->civ_random =
                    (unsigned char)rge_base_game->random_civ[player];
                player_info->player_no =
                    (unsigned char)rge_base_game->playerColor(player - 1);
                player_info->team_no =
                    (unsigned char)rge_base_game->playerTeam(player - 1);
                player_info->game_outcome =
                    (unsigned char)comm->WasKicked[player];
                player_info->tool_time = -1;
                player_info->bronze_time = -1;
                player_info->iron_time = -1;

                TRIBE_History_Events* event =
                    ((TRIBE_Player*)this->players[player])->history->events;
                while (event != 0) {
                    if (event->event == 0)
                        player_info->tool_time = event->world_time;
                    else if (event->event == 1)
                        player_info->bronze_time = event->world_time;
                    else if (event->event == 2)
                        player_info->iron_time = event->world_time;
                    event = event->next;
                }

                player++;
                player_info++;
            } while (player < this->player_num);
        }

        info.cheats_enabled = (unsigned char)rge_base_game->allowCheatCodes();
        if (this->game_end_condition == 0) {
            info.game_end_condition_code = 0;
        } else if (this->game_end_condition == 1) {
            info.game_end_condition_code = 1;
        } else if (this->game_end_condition == 2) {
            info.game_end_condition_code = 6;
        } else if (this->game_end_condition == 100) {
            info.game_end_condition_code = 2;
        } else if (this->game_end_condition == 101) {
            info.game_end_condition_code = 3;
        } else if (this->game_end_condition == 102) {
            info.game_end_condition_code = 4;
        } else if (this->game_end_condition == 103) {
            info.game_end_condition_code = 5;
        } else if (this->game_end_condition == 104) {
            info.game_end_condition_code = 7;
        } else {
            info.game_end_condition_code = 8;
        }

        rge_base_game->get_tribe_options(&options);
        info.map_info.Map_Size = (unsigned char)options.mapSizeValue;
        info.map_info.Map_Type = (unsigned char)options.mapTypeValue;
        info.map_info.Pop_Limit = (short)options.popLimitValue;
        info.map_info.Victory_Condition = (unsigned char)options.victoryTypeValue;
        info.map_info.Start_Age = (unsigned char)options.startingAgeValue;
        info.map_info.Resources = (unsigned char)options.resourceLevelValue;
        info.map_info.Full_Tech = options.fullTechTreeValue;
        info.map_info.Fixed_Pos = options.randomizePositionsValue;
        info.map_info.Reveal_Map = (unsigned char)rge_base_game->fullVisibility();
        info.map_info.Death_Match = options.deathMatchValue;

        info.database_checksum = 0;
        info.code_checksum = 0;
        info.program_version = 0;

        this->commands->comm->SendZoneMessage((char*)&info, 0x1fc);
    }
}
