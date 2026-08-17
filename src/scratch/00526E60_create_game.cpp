// VA: 00526E60 TRIBE_Game::create_game (2512 bytes)
// PDB: tribegam.cpp:3234-3697
//
// Attempt log:
// - baseline reconstruction: canonical PlayerInfo/MapGenInfo locals, scenario setup,
//   player assignment/name selection, world finalization, and natural typed calls.
//   First check is intentionally a source-recovery baseline before codegen tuning.
// - shared scenario-mode selection removed repeated campaign/scenario/get_scenario_info
//   calls and reached exact size with 99/100 calls; the remaining gap was one merged
//   setPlayerID site.
// - direct player-slot search (while rather than do/while) removed a duplicate
//   playerID call site without changing size; qualified calls, a temporary, and a
//   shared continuation did not defeat VC5 tail merging.
// - explicit quick-build if/else improved the prologue basin (diff 2331, +4 bytes).
// - final behavior reconstruction: the executable scans position_used[1..8] with
//   a pointer cursor and color index for computer colors. This restores the
//   binary-observed multi-color behavior and all 100 call targets, but is 67 bytes
//   larger than the exact-size codegen basin. No further blind codegen probes remain.
// - notification_y pointer-cursor probe followed the original LEA/store shape,
//   but grew the function by 16 bytes and worsened the first-hunk metrics; restored.
// - fresh source-model probes restored the signed debug_rand remainder used by
//   the executable; removing abs() reduced the size gap from 67 to 54 bytes.
// - explicit shared labels for the campaign/scenario get_scenario_info call
//   removed the mode sentinel compare and improved the structural frontier.
// - MapType spelling, one selector local, pointer-cursor palette initialization,
//   and the ground-truth map prefix were tested. They were duplicate or worse.
// - final clean frontier: 2566 rebuilt bytes, 2352 strict differing bytes,
//   79.32% shape, 42.80% exact-block coverage, and 100/100 ordered calls.
//   No exact result. Restore this source before any new claim.

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" int debug_rand(const char*, int);
extern "C" void debug_srand(const char*, int, int);

#define QUICKBUILD_STRING ((const char*)0x0058BFA4)
#define TRIBE_GAME_SOURCE ((const char*)0x0058BB98)
#define PALSET_BASE (*(unsigned int*)0x0086BCAC)
#define OUT_OF_SYNC (*(int*)0x0062C560)
#define OUT_OF_SYNC2 (*(int*)0x0062C564)
#define NO_OTHER_HUMANS_COUNT (*(int*)0x0086BE00)
#define QUICK_START_GAME_MODE (*(int*)0x0086BDEC)
#define ALL_CP (*(int*)0x0062C51C)
#define NUMBER_PATHING_ITERATIONS (*(int*)0x0057F9F4)
#define COMM (*(TCommunications_Handler**)0x0062C4C0)

enum MapSize {
    MAP_SIZE_TINY = 0,
    MAP_SIZE_SMALL = 1,
    MAP_SIZE_MEDIUM = 2,
    MAP_SIZE_LARGE = 3
};

enum MapType {
    MAP_TYPE_NONE = 0
};

struct RGE_Info_Line {
    char bytes[0x14];
};

// The stack object is used as the map-info payload beginning at land.  Keep the
// proven 0x520 footprint; only land is addressed by this function.
struct RGE_Map_Gen_Info {
    RGE_Info_Line land;
    char rest[0x50C];
};

struct RGE_Player_Info {
    char name[9][65];
    char type[9];
    char tribe[9];
    unsigned char pad_25b;
    short color[9];
    unsigned char pad_26e[2];
    long player_id_hash[9];
    short player_num;
    unsigned char pad_296[2];
    char* scenario;
    RGE_Map_Gen_Info* map_info;
    short map_type;
    short map_width;
    short map_height;
    short ai_info;
    unsigned char campaign;
    unsigned char pad_end[3];
};

class RGE_Game_Info {
public:
    char* get_current_player_name();
};

class TSound_Driver;

class TCommunications_Handler {
public:
    unsigned int GetRandomSeed();
    int GetPlayerHumanity(unsigned int player);
    int WhoAmI();
    char* GetPlayerName(unsigned int player);
    void SetPlayerName(unsigned int player, char* name);
};

class RGE_Visible_Map {
public:
    void explore_all();
};

class RGE_Player {
public:
    void* vtable_ptr;
    char gap_04[0x34];
    RGE_Visible_Map* visible;

    int computerPlayer() const;
};

class RGE_Scenario {
public:
    virtual void v0();
    virtual void release(int flags);
    int Get_player_Civ(int player);
    char* GetPlayerName(int player);
};

class RGE_Game_World {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual unsigned char v52(char* name, int player);

    char gap_04[0x38];
    short player_num; // +0x3C
    char gap_3E[2];
    RGE_Player** players;

    void update_mutual_allies();
};

class TSound_Driver {
public:
    unsigned char pad_00;
    unsigned char sound_enabled;
};

class RGE_Prog_Info {
public:
    char gap_00[0xC17];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual char* get_string(long id, char* buffer, int size); // +0x20

    RGE_Game_Info* player_game_info; // +0x04
    char gap_08[4];
    RGE_Prog_Info* prog_info; // +0x0C
    char gap_10[0x18];
    int random_game_seed; // +0x28
    char gap_2C[0x60 - 0x2C];
    TSound_Driver* sound_system; // +0x60
    char gap_64[0x18C - 0x64];
    TCommunications_Handler* comm_handler; // +0x18C
    char gap_190[0x3F4 - 0x190];
    RGE_Game_World* world; // +0x3F4
    char gap_3F8[0x8E8 - 0x3F8];
    int do_show_timings; // +0x8E8
    int do_show_comm; // +0x8EC
    int do_show_ai; // +0x8F0
    char gap_8F4[0x9A0 - 0x8F4];
    int campaignGameValue; // +0x9A0
    int savedGameValue; // +0x9A4
    int quick_build; // +0x9A8
    char gap_9AC[0xA14 - 0x9AC];
    unsigned char pathFindingValue; // +0xA14
    unsigned char resigned[9]; // +0xA15
    unsigned char gap_A1E[2];
    void* map_save_area; // +0xA20

    unsigned char check_prog_argument(const char* value);
    void set_map_visible(unsigned char value);
    void set_map_fog(unsigned char value);
    int campaignGame() const;
    int scenarioGame() const;
    char* scenarioName();
    int multiplayerGame() const;
    int numberPlayers() const;
    int mapXSize() const;
    int mapYSize() const;
    RGE_Scenario* get_scenario_info(char* scenario, int campaign);
    void setPlayerID(int player, int value);
    int playerID(int player);
    long reset_countdown_timer(long player);
    int fullVisibility() const;
    int fogOfWar() const;
    unsigned char mpPathFinding();
    unsigned char pathFinding();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0x10];
    long queue_is_waiting_on_pop_counter[9]; // +0xA34
    int random_civ[9]; // +0xA58
    char gap_A7C[0xC28 - 0xA7C];
    long notification_loc_x[5]; // +0xC28
    long notification_loc_y[5]; // +0xC3C
    long current_notification_loc; // +0xC50
    long current_notification_recalled; // +0xC54
    char gap_C58[0x116C - 0xC58];
    int save_humanity[9]; // +0x116C
    char gap_1190[0x1250 - 0x1190];
    int inHandleIdle; // +0x1250

    unsigned char quickStartGame();
    void setMapSize(MapSize size);
    void setMapType(MapType type);
    void resetRandomComputerName();
    int civilization(int player);
    void setCivilization(int player, int civ);
    int randomComputerName(int civ);
    void setComputerName(int player, int name);
    MapType mapType() const;
    int playerColor(int player);
    void setPlayerColor(int player, int color);
    int computerName(int player);
    int randomGame();

    int create_game(int param_1);
};

typedef RGE_Scenario T_Scenario;

int TRIBE_Game::create_game(int param_1)
{
    int i;
    int player_index;
    int scenario_player;
    int humanity;
    int position_used[8];
    RGE_Player_Info player_info;
    char scenario_file[260];
    _finddata_t file_info;
    RGE_Map_Gen_Info map_info;

    i = 0;
    this->inHandleIdle = 0;
    for (; i < 5; ++i) {
        this->notification_loc_x[i] = -1;
        this->notification_loc_y[i] = -1;
    }
    this->current_notification_loc = -1;
    this->current_notification_recalled = -1;

    if (this->check_prog_argument(QUICKBUILD_STRING)) {
        this->quick_build = 1;
    }
    else {
        this->quick_build = 0;
    }
    this->do_show_timings = 0;
    this->do_show_comm = 0;
    this->do_show_ai = 0;
    this->set_map_visible(0);
    this->set_map_fog(0);

    for (i = 1; i < 9; ++i) {
        this->resigned[i] = 0;
        (&PALSET_BASE)[i - 1] = 0;
        this->queue_is_waiting_on_pop_counter[i] = 0;
    }
    OUT_OF_SYNC = 0;
    OUT_OF_SYNC2 = 0;
    NO_OTHER_HUMANS_COUNT = 0;

    if (this->quickStartGame()) {
        MapType map_type;
        if (QUICK_START_GAME_MODE == 1) {
            this->setMapSize(MAP_SIZE_MEDIUM);
            map_type = (MapType)4;
        }
        else {
            this->setMapSize(MAP_SIZE_LARGE);
            int random_map_type = debug_rand(TRIBE_GAME_SOURCE, 0xCDD) % 10;
            if (random_map_type < 2) {
                map_type = (MapType)4;
            }
            else if (random_map_type == 2) {
                map_type = (MapType)3;
            }
            else if (random_map_type == 3) {
                map_type = (MapType)2;
            }
            else if (random_map_type == 4) {
                map_type = (MapType)1;
            }
            else if (random_map_type == 5) {
                map_type = (MapType)random_map_type;
            }
            else if (random_map_type == 6) {
                map_type = (MapType)random_map_type;
            }
            else if (random_map_type == 7) {
                map_type = (MapType)random_map_type;
            }
            else {
                map_type = (MapType)((random_map_type == 8) ? 8 : 0);
            }
        }
        this->setMapType(map_type);
        this->resetRandomComputerName();
        for (i = 0; i < this->numberPlayers(); ++i) {
            int civ = debug_rand(TRIBE_GAME_SOURCE, 0xCF8) % 16 + 1;
            this->setCivilization(i, civ);
            this->setComputerName(i, this->randomComputerName(civ));
        }
    }

    memset(player_info.name, 0, sizeof(player_info));
    memset(&map_info, 0, sizeof(map_info));

    if (this->campaignGame()) {
        player_info.campaign = 1;
    }
    else if (this->scenarioGame()) {
        if (this->scenarioName() == 0) {
            return 0;
        }
        sprintf(scenario_file, "%s%s.scn",
                (char*)this->prog_info + 0xC17, this->scenarioName());
        if (_findfirst(scenario_file, &file_info) == -1) {
            sprintf(scenario_file, "%s.scx", this->scenarioName());
        }
        else {
            sprintf(scenario_file, "%s.scn", this->scenarioName());
        }
        player_info.scenario = scenario_file;
    }
    else {
        player_info.map_info = (RGE_Map_Gen_Info*)&map_info.land;
        player_info.map_type = (short)this->mapType();
        player_info.map_width = (short)this->mapXSize();
        player_info.map_height = (short)this->mapYSize();
    }

    int seed_line;
    int seed;
    if (this->multiplayerGame()) {
        seed = COMM->GetRandomSeed();
        seed_line = 0xD24;
    }
    else if (this->random_game_seed == -1) {
        seed = debug_rand(TRIBE_GAME_SOURCE, 0xD2A);
        seed_line = 0xD2A;
    }
    else {
        seed = this->random_game_seed;
        seed_line = 0xD28;
    }
    debug_srand(TRIBE_GAME_SOURCE, seed_line, seed);

    player_info.player_num = 0;
    short* player_colors = player_info.color;
    long* player_hashes = player_info.player_id_hash;
    for (i = 0; i < 9; ++i) {
        player_info.type[i] = -1;
        player_info.name[i][0] = 0;
        player_hashes[i] = i;
        player_info.tribe[i] = 1;
        player_colors[i] = -1;
        this->random_civ[i] = 0;

        int civ = this->civilization(i);
        if (civ > 16 || this->civilization(i) < 0) {
            this->setCivilization(i, (debug_rand(TRIBE_GAME_SOURCE, 0xD3B) * 16) / 0x7FFF + 1);
            this->random_civ[i] = 1;
        }
    }

    this->resetRandomComputerName();
    for (i = 0; i < this->numberPlayers(); ++i) {
        int player = i + 1;
        if (COMM->GetPlayerHumanity(player) == 4) {
            this->setComputerName(i, this->randomComputerName(this->civilization(i)));
        }
    }

    int scenario_mode = -1;
    char* scenario_name = 0;
    if (this->campaignGame()) {
        scenario_mode = 1;
        scenario_name = 0;
        goto load_scenario_info;
    }
    if (this->scenarioGame()) {
        scenario_mode = 0;
        scenario_name = player_info.scenario;
        goto load_scenario_info;
    }
    player_index = 0;
    goto scenario_info_done;

load_scenario_info:
    {
        player_index = (int)this->get_scenario_info(scenario_name, scenario_mode);
        if (player_index == 0) {
            return 0;
        }
    }

scenario_info_done:

    for (i = 0; i < 9; ++i) {
        position_used[i] = -1;
        this->setPlayerID(i, 0);
    }

    scenario_player = 0;
    i = 1;
    while (i <= this->numberPlayers()) {
        if (COMM->GetPlayerHumanity(i) == 2) {
            int color = this->playerColor(i - 1) - 1;
            if (position_used[color] == -1) {
                position_used[color] = scenario_player;
                ++scenario_player;
            }
            this->setPlayerID(i, position_used[color] + 1);
        }
        else if (COMM->GetPlayerHumanity(i) == 4) {
            int* position = &position_used[1];
            for (int color = 0; color < 8; ++color, ++position) {
                if (*position != -1) {
                    continue;
                }
                int found = 0;
                for (int j = 1; j < 9; ++j) {
                    if (COMM->GetPlayerHumanity(j) == 2 &&
                        this->playerColor(j - 1) - 1 == color) {
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    this->setPlayerColor(i - 1, color + 1);
                    *position = scenario_player++;
                    this->setPlayerID(i, *position + 1);
                }
            }
        }
        ++i;
    }

    this->resetRandomComputerName();
    long* player_hash = player_info.player_id_hash + 1;
    short* player_color = player_info.color;
    i = 0;
    do {
        int player = i + 1;
        scenario_player = 0;
        int slot = 1;
        while (slot < 9) {
            if (this->playerID(slot) == player) {
                scenario_player = slot;
                break;
            }
            ++slot;
        }
        if (scenario_player == 0) {
            break;
        }

        humanity = COMM->GetPlayerHumanity(scenario_player);
        int color = this->playerColor(scenario_player - 1) - 1;
        if (humanity == 4 || ALL_CP == 1 || (ALL_CP == 2 && i > 0)) {
            player_info.type[i] = 4;
        }
        else {
            player_info.type[i] = 0;
        }

        if (this->campaignGame()) {
            player_info.tribe[i] = ((RGE_Scenario*)player_index)->Get_player_Civ(color);
        }
        else {
            player_info.tribe[i] = (char)this->civilization(scenario_player - 1);
        }

        char* source_name = 0;
        if (this->multiplayerGame() && humanity == 2) {
            strncpy(player_info.name[i], COMM->GetPlayerName(scenario_player), 0x40);
        }
        else {
            if (this->campaignGame() == 0 && player_info.type[i] == 0) {
                source_name = this->player_game_info->get_current_player_name();
            }
            else if (this->campaignGame() == 0 && this->randomGame() != 0 && player_info.type[i] == 0) {
                this->get_string(0x286D, player_info.name[i], 0x41);
            }
            else if (this->campaignGame() != 0 || this->scenarioGame() != 0) {
                source_name = ((RGE_Scenario*)player_index)->GetPlayerName(color);
            }
            if (source_name != 0) {
                strcpy(player_info.name[i], source_name);
            }
        }

        if (player_info.name[i][0] == 0) {
            if (player_info.type[i] == 0) {
                this->get_string(0x286D, player_info.name[i], 0x41);
            }
            else if (this->campaignGame() == 0 && this->computerName(scenario_player) != 0) {
                this->get_string(this->computerName(scenario_player) + 0x1130,
                                 player_info.name[i], 0x41);
            }
            else {
                this->get_string(this->randomComputerName((int)player_info.tribe[i]) + 0x1130,
                                 player_info.name[i], 0x41);
            }
        }
        COMM->SetPlayerName(scenario_player, player_info.name[i]);

        *player_hash = color + 1;
        *player_color = (short)color;
        ++player_hash;
        ++player_color;
        ++player_info.player_num;
        ++i;
    } while (i < 8);

    if (player_index != 0) {
        ((RGE_Scenario*)player_index)->release(1);
    }
    if (player_info.player_num == 0) {
        return 0;
    }

    if (this->sound_system != 0) {
        ((TSound_Driver*)this->sound_system)->sound_enabled = 1;
    }

    unsigned char result;
    int local_player;
    if (this->multiplayerGame()) {
        local_player = COMM->WhoAmI();
    }
    else {
        local_player = 1;
    }
    result = ((RGE_Game_World*)this->world)->v52(player_info.name[0],
                                                  this->playerID(local_player));
    if (result != 0 && this->world->player_num < 2) {
        result = 0;
        this->world->v46();
    }

    if (this->sound_system != 0) {
        ((TSound_Driver*)this->sound_system)->sound_enabled = 0;
    }

    for (i = 0; i < this->world->player_num; ++i) {
        this->reset_countdown_timer(i);
    }
    this->world->update_mutual_allies();
    this->set_map_visible(0);
    if (this->fullVisibility() != 0) {
        for (i = 1; i < this->world->player_num; ++i) {
            if (this->world->players[i]->computerPlayer() == 0) {
                this->world->players[i]->visible->explore_all();
            }
        }
    }
    this->set_map_fog(this->fogOfWar());

    unsigned char pathfinding;
    if (this->multiplayerGame()) {
        pathfinding = this->mpPathFinding();
    }
    else {
        pathfinding = this->pathFinding();
    }
    switch (pathfinding) {
    case 1:
        NUMBER_PATHING_ITERATIONS = 5000;
        break;
    case 2:
        NUMBER_PATHING_ITERATIONS = 0x1D4C;
        break;
    default:
        NUMBER_PATHING_ITERATIONS = 0x9C4;
        break;
    }

    for (i = 1; i < 9; ++i) {
        this->save_humanity[i] = COMM->GetPlayerHumanity(i);
    }
    return result;
}
