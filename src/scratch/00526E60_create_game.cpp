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
// - direct debug_srand branches recovered the oracle's immediate line pushes and
//   shared call tail; duplicate setMapType arms recovered the mode-1 push shape.
// - BINARY NOTE: after assigning a free computer color, the shipped code breaks
//   to the outer player loop. It does not scan later colors for that player.
// - the natural typed scenario pointer and expanded scenario_player update were
//   codegen-neutral; retained to remove integer pointer casts and match ownership.
// - final clean frontier: 2566 rebuilt bytes, 2352 strict differing bytes,
//   79.32% shape, 42.80% exact-block coverage, and 100/100 ordered calls.
// - current behavior frontier: 2557 rebuilt bytes, 2371 strict differing bytes,
//   80.58% shape, 45.08% exact-block coverage, and 100/100 ordered calls.
//   No exact result.
// - source-policy cleanup: standalone declarations now use natural player,
//   scenario, world, and base-game surfaces. Delete, new_game, and
//   del_game_info retain the observed virtual calls. The owner remains
//   unresolved in scratch.

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _finddata_t { char bytes[0x118]; };
extern "C" long __cdecl _findfirst(const char* filespec, void* fileinfo);

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

class RGE_Player_Info {
public:
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

class RGE_Static_Object;
class RGE_Sound;

#ifndef TRIBEGAM_TU_CONTEXT
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

#endif

class RGE_Visible_Map {
public:
    void explore_all();
};

#ifndef TRIBEGAM_TU_CONTEXT
#include "../../include/rge_player_context.h"
#endif

#ifndef TRIBEGAM_TU_CONTEXT
class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int player);
    virtual ~RGE_Scenario();
    virtual void rehook();
    virtual void save(int file);
    int Get_player_Civ(int player);
    char* GetPlayerName(int player);
};
#endif

#ifndef TRIBEGAM_TU_CONTEXT
class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE* file);
    virtual unsigned char data_load_terrain_tables(char* name);
    virtual unsigned char data_load_players(char* name);
    virtual unsigned char data_load_objects(char* name);
    virtual unsigned char data_load_sounds(char* name);
    virtual unsigned char data_load_color_tables(char* name);
    virtual unsigned char data_load_sprites(char* name);
    virtual void data_load_players_type(short player, short type, FILE* file);
    virtual void data_load_effects(char* name);
    virtual void data_load_map(char* map, char* terrain, char* effect,
                               char* random, short width, short height,
                               short tile_set, RGE_Sound** sounds,
                               char* name);
    virtual void data_load_random_map(char* map, char* terrain,
                                      char* effect, char* random);
    virtual unsigned char init_player_type(int player, short type,
                                           unsigned char active);
    virtual unsigned char init_player(int player);
    virtual void load_player(int player, unsigned char type, short id);
    virtual void color_table_init(int table);
    virtual void terrain_tables_init(int table);
    virtual void init_sounds(int count, TSound_Driver* driver);
    virtual void init_sprites(int count);
    virtual void map_init(int count, TSound_Driver* driver);
    virtual void effects_init(int count);
    virtual void master_player_init(int count);
    virtual void command_init(int count, TCommunications_Handler* comm);
    virtual void world_init(int count, TSound_Driver* driver,
                            TCommunications_Handler* comm);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info& info);
    virtual unsigned char new_random_game(RGE_Player_Info& info);
    virtual void save(int file);
    virtual void scenario_make_player(short player, unsigned char active,
                                      unsigned char type, unsigned char civ,
                                      char* name);
    virtual void scenario_make_map(int map);
    virtual unsigned char load_scenario(char* name, RGE_Player_Info* info);
    virtual unsigned char load_scenario(RGE_Player_Info& info);
    virtual void load_scenario1(int player, RGE_Player_Info& info);
    virtual void load_scenario2(int player, RGE_Player_Info& info);
    virtual void load_scenario3(int player, RGE_Player_Info& info);
    virtual void load_scenario4(int player, RGE_Player_Info& info);
    virtual void load_scenario5(int player, RGE_Player_Info& info);
    virtual void load_scenario6(int player, RGE_Player_Info& info);
    virtual void load_scenario7(int player, RGE_Player_Info& info);
    virtual void load_scenario8(int player, RGE_Player_Info& info);
    virtual void logStatus(FILE* file, int verbose);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(RGE_Player_Info* info);
    virtual unsigned char data_load(char* first, char* second);
    virtual unsigned char init(char* name, TSound_Driver* driver,
                               TCommunications_Handler* comm);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int file);
    virtual unsigned char load_game(char* name);
    virtual unsigned char new_game(RGE_Player_Info& info, int flags);
    virtual unsigned char new_scenario(RGE_Player_Info& info, int flags);
    virtual unsigned char save_game(char* name);
    virtual void base_save(char* name);
    virtual void base_save(int file);
    virtual unsigned char save_scenario(char* name);
    virtual RGE_Scenario* get_scenario_info(char* name);
    virtual void pause(unsigned char value);
    virtual void scenario_init(int file, RGE_Game_World* world);
    virtual void scenario_init(RGE_Game_World* world);

    char gap_04[0x38];
    short player_num; // +0x3C
    char gap_3E[2];
    RGE_Player** players;

    void update_mutual_allies();
};
#endif

#ifndef TRIBEGAM_TU_CONTEXT
class TSound_Driver {
public:
    unsigned char pad_00;
    unsigned char game_loading;
};

class RGE_Prog_Info {
public:
    char gap_00[0xC17];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* window, unsigned int message,
                          unsigned int wparam, long lparam);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int sub_mode);
    virtual void set_player(short player);
    virtual int get_error_code();
    virtual char* get_string(long id, char* buffer, int size); // +0x20
    virtual char* get_string(int id, long param, char* buffer, int size);

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
#endif

#ifndef TRIBEGAM_TU_CONTEXT
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

protected:
    int create_game(int param_1);
};
#endif

int TRIBE_Game::create_game(int param_1)
{
    int i;
    int scenario_player;
    RGE_Scenario* scenario_info;
    unsigned char pathfinding;
    int humanity;
    int position_used[8];
    long* player_hash;
    short* player_color;
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
        if (QUICK_START_GAME_MODE == 1) {
            this->setMapSize(MAP_SIZE_MEDIUM);
            this->setMapType((MapType)4);
        }
        else {
            MapType map_type;
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
            this->setMapType(map_type);
        }
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

    if (this->multiplayerGame()) {
        debug_srand(TRIBE_GAME_SOURCE, 0xD24, COMM->GetRandomSeed());
    }
    else if (this->random_game_seed == -1) {
        debug_srand(TRIBE_GAME_SOURCE, 0xD2A,
                    debug_rand(TRIBE_GAME_SOURCE, 0xD2A));
    }
    else {
        debug_srand(TRIBE_GAME_SOURCE, 0xD28, this->random_game_seed);
    }

    player_info.player_num = 0;
    long* player_hashes = player_info.player_id_hash;
    short* player_colors = player_info.color;
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
    scenario_info = 0;
    goto scenario_info_done;

load_scenario_info:
    {
        scenario_info = this->get_scenario_info(scenario_name, scenario_mode);
        if (scenario_info == 0) {
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
                    *position = scenario_player;
                    ++scenario_player;
                    this->setPlayerID(i, *position + 1);
                    break;
                }
            }
        }
        ++i;
    }

    this->resetRandomComputerName();
    player_color = player_info.color;
    player_hash = player_info.player_id_hash + 1;
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
            player_info.tribe[i] = scenario_info->Get_player_Civ(color);
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
                source_name = scenario_info->GetPlayerName(color);
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

    if (scenario_info != 0) {
        delete scenario_info;
    }
    if (player_info.player_num == 0) {
        return 0;
    }

    if (this->sound_system != 0) {
        ((TSound_Driver*)this->sound_system)->game_loading = 1;
    }

    unsigned char result;
    int local_player;
    if (this->multiplayerGame()) {
        local_player = COMM->WhoAmI();
    }
    else {
        local_player = 1;
    }
    result = ((RGE_Game_World*)this->world)->new_game(
        player_info, this->playerID(local_player));
    if (result != 0 && this->world->player_num < 2) {
        result = 0;
        this->world->del_game_info();
    }

    if (this->sound_system != 0) {
        ((TSound_Driver*)this->sound_system)->game_loading = 0;
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
