
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/tworld.h"
#include "../include/world_info.h"
#include "../include/player.h"
#include "../include/tplayer.h"
#include "../include/tech.h"
#include "../include/tmap.h"
#include "../include/tmplayer.h"
#include "../include/teffects.h"
#include "../include/tscenaro.h"
#include "../include/t_histry.h"
#include "../include/victory.h"
#include "../include/tribegam.h"
#include "../include/com_hand.h"
#include "../include/mst_play.h"
#include "../include/map.h"
#include "../include/obj_list.h"
#include "../include/m_s_obj.h"
#include "../include/stat_obj.h"
#include "../include/rge_fio.h"
#include "../include/main.h"
#include "../include/basegame.h"
#include "../include/scenario.h"
#include "../include/aipbook.h"
#include "../include/taipbook.h"
#include "../include/rge_base_game_global.h"
#include "../include/tcommand.h"
#include "../include/effects.h"
#include "../include/visible.h"
#include "../include/panel.h"
#include "../include/rmm_obj.h"
#include "../include/game_globals.h"

static char world_source_file[] = "C:\\msdev\\work\\age1_x1\\tworld.cpp";
static char newline_join_format[] = "%s\n%s";
static char nofoodcap_argument[] = "NOFOODCAP";
static char system2_argument[] = "SYSTEM2";
static const float one = 1.0f;
static const float minus_one = -1.0f;

char data_aoe_ply[] = "data\\aoe.ply";

TRIBE_World::TRIBE_World() : controllingComputerPlayer(-1) {
    tech = 0;
    victory_type = 0;
    artifact_count = 0;
    ruin_count = 0;
    sent_zone_score = 0;
    countdown_victory = 0;
    countdown_clock = 0;
    score_displayed = 0;

    TribeAIPlayBook* pb = new TribeAIPlayBook;
    playbook = pb;
    if (pb) {
        pb->loadPlays(data_aoe_ply);
    }
}

TRIBE_World::~TRIBE_World() {
    if (this->tech != 0) {
        delete this->tech;
        this->tech = 0;
    }
}

void TRIBE_World::logStatus(FILE* stream, int verbose)
{
    long clock;
    char tempString[256];

    if (stream != 0 && verbose == 1) {
        fprintf(stream, "\n\n\n****************************************\n");

        time(&clock);
        fprintf(stream, "AI Log file for Game Started %s", asctime(localtime(&clock)));
        fprintf(stream, "Number Players:          %d\n", static_cast<int>(this->player_num) - 1);

        if (this->scenario->scenario_name != 0 &&
            strlen(this->scenario->scenario_name) != 0) {
            fprintf(stream, "Scenario:                %s\n", this->scenario->scenario_name);
            return;
        }

        static_cast<TRIBE_Game*>(rge_base_game)->get_string(
            static_cast<TRIBE_Game*>(rge_base_game)->mapSize() + 0x2973,
            tempString, 0x100);
        fprintf(stream, "Map Size:                %s\n", tempString);

        static_cast<TRIBE_Game*>(rge_base_game)->get_string(
            static_cast<TRIBE_Game*>(rge_base_game)->mapType() + 0x296A,
            tempString, 0x100);
        fprintf(stream, "Map Type:                %s\n", tempString);

        static_cast<TRIBE_Game*>(rge_base_game)->get_string(
            static_cast<TRIBE_Game*>(rge_base_game)->victoryType() + 0x28A6,
            tempString, 0x100);
        fprintf(stream, "Victory Condition:       %s\n", tempString);
    }
}

void TRIBE_World::data_load_players_type(short p1, short p2, FILE* f)
{
    if (static_cast<int>(p2) - 1 != 0) {
        RGE_Game_World::data_load_players_type(p1, p2, f);
        return;
    }

    this->master_players[p1] = new TRIBE_Master_Player(f);
}

void TRIBE_World::data_load_map(char* p1, char* p2, char* p3, char* p4, short p5, short p6, short p7, RGE_Sound** p8, char* p9)
{
    TRIBE_Map* m = new TRIBE_Map(p1, p2, p3, p4, p5, p6, p7, p8);
    this->map = m;
    m->load_terrain_obj_types(p9);
}

unsigned char TRIBE_World::data_load_world(FILE* f)
{
    char tech_file[23];

    RGE_Game_World::data_load_world(f);
    fscanf(f, "%s ", tech_file);
    this->tech = new TRIBE_Tech(tech_file);
    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0.0f;
    this->score_displayed = 0;
    return 1;
}

unsigned char TRIBE_World::init_player_type(int player, short index, unsigned char type)
{
    switch (type) {
    case 1: {
        TRIBE_Master_Player* p = new TRIBE_Master_Player(player);
        this->master_players[index] = p;
        this->master_players[index]->finish_init(player, this->sprites, this->sounds);
        break;
    }
    default:
        return RGE_Game_World::init_player_type(player, index, type);
    }

    return 1;
}

void TRIBE_World::map_init(int param_1, TSound_Driver* param_2) {
    TRIBE_Map* p = new TRIBE_Map(param_1, this->sounds, 1);
    if (p == 0) {
        p = 0;
    }
    this->map = p;
}

void TRIBE_World::command_init(int unused, TCommunications_Handler* handler) {
    TRIBE_Command* cmd;
    cmd = new TRIBE_Command(this, handler);
    if (cmd == 0) {
        cmd = 0;
    }
    this->commands = cmd;
}

void TRIBE_World::scenario_init(int param_1, RGE_Game_World* param_2) {
    T_Scenario* s = new T_Scenario(param_1, param_2);
    if (s == 0) {
        s = 0;
    }
    this->scenario = s;
}

void TRIBE_World::scenario_init(RGE_Game_World* param_1) {
    T_Scenario* s = new T_Scenario(param_1);
    if (s == 0) {
        s = 0;
    }
    this->scenario = s;
}

void TRIBE_World::effects_init(int param_1) {
    TRIBE_Effects* e = new TRIBE_Effects(param_1);
    if (e == 0) {
        e = 0;
    }
    this->effects = e;
}

void TRIBE_World::world_init(int param_1, TSound_Driver* sound, TCommunications_Handler* comm)
{
    RGE_Game_World::world_init(param_1, sound, comm);

    TRIBE_Tech* new_tech = new TRIBE_Tech(param_1, this);
    this->tech = new_tech;
    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0;
    this->score_displayed = 0;
}

unsigned char TRIBE_World::init(char* file, TSound_Driver* sound,
                        TCommunications_Handler* communications)
{
    return RGE_Game_World::init(file, sound, communications);
}

void TRIBE_World::base_save(int value) {
    RGE_Game_World::base_save(value);
    this->tech->save(value);
}

void TRIBE_World::save(int fd)
{
    RGE_Game_World::save(fd);
    rge_write(fd, &victory_type, 4);
    rge_write(fd, &artifact_count, 4);
    rge_write(fd, &ruin_count, 4);
    rge_write(fd, &countdown_victory, 1);
    rge_write(fd, &countdown_clock, 4);
    rge_write(fd, &score_displayed, 1);
    rge_write(fd, &controllingComputerPlayer, 1);
}

void TRIBE_World::load_player(int player, unsigned char type, short player_id)
{
    switch (type) {
    case 1:
    case 3:
        this->players[player_id] =
            static_cast<RGE_Player*>(new TRIBE_Player(
                player, this, static_cast<unsigned char>(player_id)));
        break;
    case 2:
        this->players[player_id] =
            static_cast<RGE_Player*>(new TRIBE_Gaia(
                player, this, static_cast<unsigned char>(player_id)));
        break;
    default:
        RGE_Game_World::load_player(player, type, player_id);
        return;
    }

    static_cast<TRIBE_Player*>(this->players[player_id])->load(player);
}

void TRIBE_World::setup_gaia() {
    TRIBE_Gaia* g;
    g = new TRIBE_Gaia(this,
        static_cast<RGE_Master_Player*>(this->master_players[0]),
        0, "GAIA", 0);
    if (g == 0) {
        g = 0;
    }
    this->players[0] = g;
}

void TRIBE_World::setup_players(RGE_Player_Info& info)
{
    int index = 1;

    if (this->player_num > 1) {
        do {
            TRIBE_Player* player;

            char type = info.type[index - 1];
            switch (type) {
            case 0:
                player = new TRIBE_Player(this,
                    this->master_players[info.tribe[index - 1]],
                    static_cast<unsigned char>(index), info.name[index - 1],
                    info.tribe[index - 1], 0, 1, 0, 0, 0);
                break;
            case 4:
                if (useComputerPlayers == 0) {
                    player = new TRIBE_Player(this,
                        this->master_players[info.tribe[index - 1]],
                        static_cast<unsigned char>(index), info.name[index - 1],
                        info.tribe[index - 1], 0, 1, 0, 0, 0);
                } else {
                    player = new TRIBE_Player(this,
                        this->master_players[info.tribe[index - 1]],
                        static_cast<unsigned char>(index), info.name[index - 1],
                        info.tribe[index - 1], 1, 1, 0, 0, 0);
                }
                break;
            default:
                ++index;
                continue;
            }

            this->players[index] = player;
        ++index;
        } while (index < this->player_num);
    }
}

void TRIBE_World::check_destructables(short player_id, short master_id,
                                      float x, float y, unsigned char flag)
{
    RGE_Master_Static_Object* master =
        players[player_id]->master_objects[master_id];

    if (master != 0) {
        float radius_x = master->radius_x;
        float radius_y = master->radius_y;
        if (radius_x > 0.0f || radius_y > 0.0f) {
            short x_min = static_cast<short>(x - 0.5f);
            short y_min = static_cast<short>(y - 0.5f);
            short x_max = static_cast<short>(x + 0.5f);
            short y_max = static_cast<short>(y + 0.5f);
            if (x_min < 0)
                x_min = 0;
            if (x_max >= map->map_width)
                x_max = static_cast<short>(map->map_width - 1);
            if (y_min < 0)
                y_min = 0;
            if (y_max >= map->map_height)
                y_max = map->map_height - 1;

            if (y_min <= y_max) {
                int row_index = y_min;
                int row_count = static_cast<int>(y_max) - static_cast<int>(y_min) + 1;
                do {
                    RGE_Tile* tile =
                        map->map_row_offset[row_index] + x_min;
                    if (x_min <= x_max) {
                        int columns = static_cast<int>(x_max) - static_cast<int>(x_min) + 1;
                        do {
                            RGE_Object_Node* node = tile->objects.list;
                            while (node != 0) {
                                RGE_Static_Object* object = node->node;
                                node = node->next;
                                RGE_Master_Static_Object* object_master = object->master_obj;

                                if (object_master->id != master_id &&
                                    object_master->can_be_built_on != 0) {
                                    float object_radius_x = object_master->radius_x;
                                    float object_radius_y = object_master->radius_y;
                                    float dy = object->world_y - y;
                                    float dx = object->world_x - x;
                                    if (dy < 0.0f)
                                        dy = -dy;
                                    if (dx < 0.0f)
                                        dx = -dx;

                                    if (dx < object_radius_x + radius_x &&
                                        dy < object_radius_y + radius_y) {
                                        if (flag != 0) {
                                            if (object != 0)
                                                delete object;
                                        } else {
                                            object->destroy_obj();
                                        }
                                    }
                                }
                            }
                            ++tile;
                            --columns;
                        } while (columns != 0);
                    }
                    ++row_index;
                    --row_count;
                } while (row_count != 0);
            }
        }
    }
}

void TRIBE_World::scenario_make_player(short player_id, unsigned char master_id,
    unsigned char type, unsigned char civ, char* player_info)
{
    if (type == 0) {
        this->players[player_id] = new TRIBE_Player(this, this->master_players[master_id],
            static_cast<unsigned char>(player_id), player_info, master_id,
            0, 1, 0, 0, 0);
    } else {
        if (type == 4) {
            this->players[player_id] = new TRIBE_Player(this, this->master_players[master_id],
                static_cast<unsigned char>(player_id), player_info, master_id,
                1, 1, 0, 0, 0);
        } else {
            this->players[player_id] = new TRIBE_Player(this, this->master_players[master_id],
                static_cast<unsigned char>(player_id), player_info, master_id,
                0, 1, 0, 0, 0);
        }
    }
}

unsigned char TRIBE_World::load_world(int handle)
{
    if (!RGE_Game_World::load_world(handle))
        return 0;

    if (save_game_version >= 5.6f) {
        rge_read(handle, &this->victory_type, 4);
    } else {
        this->victory_type = 0;
    }

    if (save_game_version >= 5.3f) {
        rge_read(handle, &this->artifact_count, 4);
        rge_read(handle, &this->ruin_count, 4);
    } else {
        this->artifact_count = 0;
        this->ruin_count = 0;
    }

    if (save_game_version >= 5.4f) {
        rge_read(handle, &this->countdown_victory, 1);
        rge_read(handle, &this->countdown_clock, 4);
    } else {
        this->countdown_victory = 0;
        this->countdown_clock = 0.0f;
    }

    if (save_game_version >= 6.6f) {
        rge_read(handle, &this->score_displayed, 1);
    } else {
        this->score_displayed = 0;
    }

    if (save_game_version >= 6.97f) {
        rge_read(handle, &this->controllingComputerPlayer, 1);
    } else {
        this->controllingComputerPlayer = 2;
    }

    return 1;
}

static __inline int count_objects(TRIBE_World* world, short id) {
    int count = 0;
    int player_count = world->player_num;
    if (player_count > 0) {
        RGE_Player** player = world->players;
        do {
        RGE_Object_Node* node = (*player)->objects->list;
        while (node != 0) {
            if (node->node->master_obj->id == id) {
                ++count;
            }
            node = node->next;
        }
        ++player;
        --player_count;
        } while (player_count != 0);
    }
    return count;
}

static __inline int count_ruins(TRIBE_World* world) {
    int count = 0;
    int player_count = world->player_num;
    if (player_count > 0) {
        RGE_Player** player = world->players;
        do {
        RGE_Object_Node* node = (*player)->objects->list;
        while (node != 0) {
            short id = node->node->master_obj->id;
            if (id == 0x9e || id == 0xa3) {
                ++count;
            }
            node = node->next;
        }
        ++player;
        --player_count;
        } while (player_count != 0);
    }
    return count;
}

static __inline void append_line(char* description, char* temp, const char* fmt, int text_id, char* value) {
    sprintf(temp, rge_base_game->get_string(text_id), value);
    sprintf(description, newline_join_format, description, temp);
}

unsigned char TRIBE_World::new_game(RGE_Player_Info& param_1, int param_2) {
    int victoryAmount;
    RGE_RMM_Object_Generator* generator;
    unsigned char ret_num;
    char str1[256];
    char str2[256];
    char str3[256];
    char description[4096];
    int i;
    int age;
    int res;
    int want;
    int missing;

    this->score_displayed = 0;
    this->controllingComputerPlayer = 0xff;
    ret_num = RGE_Game_World::new_game(param_1, param_2);

    for (i = 0; i < this->player_num; ++i) {
        static_cast<TRIBE_Game*>(rge_base_game)->reset_countdown_timer(i);
    }

    if (!((static_cast<TRIBE_Game*>(rge_base_game)->campaignGame() || !static_cast<TRIBE_Game*>(rge_base_game)->randomGame()) && static_cast<TRIBE_Game*>(rge_base_game)->victoryType() == 0)) {
        if (!static_cast<TRIBE_Game*>(rge_base_game)->campaignGame() && static_cast<TRIBE_Game*>(rge_base_game)->randomGame()) {
        static_cast<T_Scenario*>(this->scenario)->Set_scenario_name(s_592A40);
        }

    switch (static_cast<TRIBE_Game*>(rge_base_game)->victoryType()) {
    case 0:
    case 9:
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x265c, description, 0x1000);
        break;
    case 1:
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x265f, description, 0x1000);
        break;
    case 7:
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x265d, description, 0x1000);
        break;
    case 8:
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x265e, description, 0x1000);
        break;
    default:
        break;
    }

    switch (static_cast<TRIBE_Game*>(rge_base_game)->mapSize()) {
    case 0: strcpy(str1, rge_base_game->get_string(0x2973)); break;
    case 1: strcpy(str1, rge_base_game->get_string(0x2974)); break;
    case 2: strcpy(str1, rge_base_game->get_string(0x2975)); break;
    case 3: strcpy(str1, rge_base_game->get_string(0x2976)); break;
    case 4: strcpy(str1, rge_base_game->get_string(0x2977)); break;
    case 5: strcpy(str1, rge_base_game->get_string(0x2978)); break;
    }
    append_line(description, str2, "%s", 0x25da, str1);

    if (static_cast<TRIBE_Game*>(rge_base_game)->randomGame()) {
        switch (static_cast<TRIBE_Game*>(rge_base_game)->mapType()) {
        case 0: strcpy(str1, rge_base_game->get_string(0x296a)); break;
        case 1: strcpy(str1, rge_base_game->get_string(0x296b)); break;
        case 2: strcpy(str1, rge_base_game->get_string(0x296c)); break;
        case 3: strcpy(str1, rge_base_game->get_string(0x296d)); break;
        case 4: strcpy(str1, rge_base_game->get_string(0x296e)); break;
        case 5: strcpy(str1, rge_base_game->get_string(0x296f)); break;
        case 6: strcpy(str1, rge_base_game->get_string(0x2970)); break;
        case 7: strcpy(str1, rge_base_game->get_string(0x2971)); break;
        case 8: strcpy(str1, rge_base_game->get_string(0x2972)); break;
        }
        append_line(description, str2, "%s", 0x25b6, str1);
    }

    age = static_cast<TRIBE_Game*>(rge_base_game)->startingAge();
    if (age == 0) {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x10e7, str1, 0x100);
    } else if (age == 1) {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x106e, str1, 0x100);
    } else {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(age + 0x1067, str1, 0x100);
    }
    append_line(description, str2, "%s", 0x25e4, str1);

    res = static_cast<TRIBE_Game*>(rge_base_game)->resourceLevel();
    if (res == 0) {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x10e7, str1, 0x100);
    } else {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(res + 0x25e5, str1, 0x100);
    }
    append_line(description, str2, "%s", 0x25e5, str1);

    static_cast<TRIBE_Game*>(rge_base_game)->difficulty();
    static_cast<TRIBE_Game*>(rge_base_game)->get_string(static_cast<TRIBE_Game*>(rge_base_game)->difficulty() + 0x2bd0, str1, 0x100);
    static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x25e0, str2, 0x100);
    sprintf(str3, str2, str1);
    sprintf(description, newline_join_format, description, str3);

    if (static_cast<TRIBE_Game*>(rge_base_game)->randomizePositions() == 0) {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x0fa3, str1, 0x100);
    } else {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x0fa4, str1, 0x100);
    }
    append_line(description, str2, "%s", 0x25e9, str1);
    if (static_cast<TRIBE_Game*>(rge_base_game)->fullVisibility() == 0) {
        strcpy(str1, rge_base_game->get_string(0x0fa4));
    } else {
        strcpy(str1, rge_base_game->get_string(0x0fa3));
    }
    append_line(description, str2, "%s", 0x25b8, str1);
    if (static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree() == 0) {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x0fa4, str1, 0x100);
    } else {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x0fa3, str1, 0x100);
    }
    append_line(description, str2, "%s", 0x25ec, str1);

    if (static_cast<TRIBE_Game*>(rge_base_game)->multiplayerGame()) {
        if (static_cast<TRIBE_Game*>(rge_base_game)->allowCheatCodes() == 0) {
            strcpy(str1, rge_base_game->get_string(0x0fa4));
        } else {
            strcpy(str1, rge_base_game->get_string(0x0fa3));
        }
        append_line(description, str2, "%s", 0x25bb, str1);
    }

    rge_base_game->get_string((static_cast<TRIBE_Game*>(rge_base_game)->multiplayerGame() ? static_cast<TRIBE_Game*>(rge_base_game)->mpPathFinding() : static_cast<TRIBE_Game*>(rge_base_game)->pathFinding()) + 0x260e, str1, 0x100);
    append_line(description, str2, "%s", 0x25f1, str1);

    sprintf(str2, rge_base_game->get_string(0x25f0),
        static_cast<int>(static_cast<TRIBE_Game*>(rge_base_game)->popLimit()));
    sprintf(description, newline_join_format, description, str2);
        static_cast<T_Scenario*>(this->scenario)->add_description(description);
    }

    if (ret_num) {
        this->victory_type = 4;
        this->countdown_victory = 0;
        this->countdown_clock = 0.0f;

        if ((!static_cast<TRIBE_Game*>(rge_base_game)->campaignGame() && static_cast<TRIBE_Game*>(rge_base_game)->randomGame()) || static_cast<TRIBE_Game*>(rge_base_game)->victoryType() != 0) {
            static_cast<T_Scenario*>(this->scenario)->Set_victory_all_flag(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Ruins(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Artifacts(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Discoveries(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Exploration(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Gold(0);
            victoryAmount = static_cast<TRIBE_Game*>(rge_base_game)->victoryAmount();
            switch (static_cast<TRIBE_Game*>(rge_base_game)->victoryType()) {
            case 0:
            case 9:
                this->victory_type = 0;
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(1);
                break;
            case 1:
                this->victory_type = 1;
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(1);
                break;
            case 7:
                this->victory_type = 2;
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(1);
                break;
            case 8:
                this->victory_type = 3;
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(1);
                break;
            case 3:
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Ruins(victoryAmount);
                break;
            case 4:
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Artifacts(victoryAmount);
                break;
            case 5:
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Discoveries(victoryAmount);
                break;
            case 2:
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Exploration(victoryAmount);
                break;
            case 6:
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Gold(victoryAmount);
                break;
            }
            static_cast<T_Scenario*>(this->scenario)->Save_victory_conditions_into_players(0);
            switch (static_cast<TRIBE_Game*>(rge_base_game)->victoryType()) {
            case 7:
                this->countdown_victory = 1;
                this->countdown_clock = static_cast<float>(victoryAmount);
                break;
            case 8:
                for (i = 1; i < this->player_num; ++i) {
                    this->players[i]->victory_conditions->add_victory_points(0, victoryAmount, 1);
                }
                break;
            }
        } else {
            if (static_cast<TRIBE_Game*>(rge_base_game)->campaignGame() || static_cast<TRIBE_Game*>(rge_base_game)->scenarioGame()) {
                switch (static_cast<T_Scenario*>(this->scenario)->GetMPVictory()) {
                case 0:
                    this->victory_type = 0;
                    break;
                case 1:
                    this->victory_type = 1;
                    break;
                case 3:
                    this->victory_type = 2;
                    this->countdown_victory = 1;
                    this->countdown_clock = static_cast<float>(
                        static_cast<T_Scenario*>(this->scenario)->GetVictoryTime());
                    break;
                case 2: {
                    this->victory_type = 3;
                    victoryAmount = static_cast<T_Scenario*>(this->scenario)->GetVictoryScore();
                    for (i = 1; i < this->player_num; ++i) {
                        this->players[i]->victory_conditions->add_victory_points(0, victoryAmount, 1);
                    }
                    break;
                }
                }
            }
        }

        generator = new RGE_RMM_Object_Generator(this->map, 0, this, 0, 0);

        want = static_cast<T_Scenario*>(this->scenario)->Get_Multi_Artifacts();
        if (want > 0) {
            missing = want - count_objects(this, 0x9f);
            if (missing > 0) generator->add_quick_obj(0x9f, missing, 0);
        }
        want = static_cast<T_Scenario*>(this->scenario)->Get_Multi_Discoveries();
        if (want > 0) {
            missing = want - count_objects(this, 10);
            if (missing > 0) generator->add_quick_obj(10, missing, 0);
        }
        want = static_cast<T_Scenario*>(this->scenario)->Get_Multi_Ruins();
        if (want > 0) {
            missing = want - count_ruins(this);
            if (missing > 0) generator->add_quick_obj(0x9e, missing, 0);
        }

        if (!static_cast<TRIBE_Game*>(rge_base_game)->campaignGame() && static_cast<TRIBE_Game*>(rge_base_game)->randomGame()) {
            if (this->victory_type == 3 || debug_rand(world_source_file, 0x38d) % 100 < 50) {
                generator->add_quick_obj(0x9f, 5, this->map->map_width / 5);
                this->artifact_count = 5;
            }
            if (debug_rand(world_source_file, 0x394) % 100 < 50) {
                generator->add_quick_obj(0x9e, 5, this->map->map_width / 5);
                this->ruin_count = 5;
            }
        } else {
            int player_count = this->player_num;
            this->artifact_count = 0;
            if (player_count > 0) {
                RGE_Player** player = this->players;
                int count = player_count;
                do {
                    RGE_Object_Node* node = (*player)->objects->list;
                    while (node != 0) {
                        if (node->node->master_obj->id == 0x9f) {
                            ++this->artifact_count;
                        }
                        node = node->next;
                    }
                    ++player;
                    --count;
                } while (count != 0);
            }

            this->ruin_count = 0;
            if (player_count > 0) {
                RGE_Player** player = this->players;
                int count = player_count;
                do {
                    RGE_Object_Node* node = (*player)->objects->list;
                    while (node != 0) {
                        short id = node->node->master_obj->id;
                        if (id == 0x9e || id == 0xa3) {
                            ++this->ruin_count;
                        }
                        node = node->next;
                    }
                    ++player;
                    --count;
                } while (count != 0);
            }
        }

        generator->generate();
        if (generator != 0) {
            delete generator;
        }
    }

    if (!static_cast<TRIBE_Game*>(rge_base_game)->allowTrading()) {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(0x69,
                static_cast<TRIBE_Player*>(this->players[i]));
        }
    }
    if (static_cast<TRIBE_Game*>(rge_base_game)->longCombat() == 1) {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(0x64,
                static_cast<TRIBE_Player*>(this->players[i]));
        }
    }

    if (!static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree() && !static_cast<T_Scenario*>(this->scenario)->GetScenarioOption(2)) {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(this->players[i]->culture,
                static_cast<TRIBE_Player*>(this->players[i]));
        }
    } else {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(0xd2,
                static_cast<TRIBE_Player*>(this->players[i]));
        }
    }

    switch (static_cast<TRIBE_Game*>(rge_base_game)->resourceLevel()) {
    case 1:
        for (i = 1; i < this->player_num; ++i) {
            this->players[i]->attributes[0] = 200.0f;
            this->players[i]->attributes[1] = 200.0f;
            this->players[i]->attributes[3] = 0.0f;
            this->players[i]->attributes[2] = 100.0f;
        }
        break;
    case 2:
        for (i = 1; i < this->player_num; ++i) {
            this->players[i]->attributes[0] = 500.0f;
            this->players[i]->attributes[1] = 500.0f;
            this->players[i]->attributes[3] = 0.0f;
            this->players[i]->attributes[2] = 250.0f;
        }
        break;
    case 3:
        for (i = 1; i < this->player_num; ++i) {
            this->players[i]->attributes[0] = 1000.0f;
            this->players[i]->attributes[1] = 1000.0f;
            this->players[i]->attributes[3] = 0.0f;
            this->players[i]->attributes[2] = 750.0f;
        }
        break;
    }

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch()) {
        for (i = 1; i < this->player_num; ++i) {
            this->players[i]->attributes[0] = 20000.0f;
            this->players[i]->attributes[1] = 20000.0f;
            this->players[i]->attributes[3] = 10000.0f;
            this->players[i]->attributes[2] = 5000.0f;
        }
    }

    switch (static_cast<TRIBE_Game*>(rge_base_game)->startingAge()) {
    case 3:
        for (i = 1; i < this->player_num; ++i)
            static_cast<TRIBE_Player*>(this->players[i])->rev_tech(0x19);
        break;
    case 4:
        for (i = 1; i < this->player_num; ++i)
            static_cast<TRIBE_Player*>(this->players[i])->rev_tech(0x17);
        break;
    case 5:
        for (i = 1; i < this->player_num; ++i)
            static_cast<TRIBE_Player*>(this->players[i])->rev_tech(0x18);
        break;
    }

    if (static_cast<TRIBE_Game*>(rge_base_game)->check_prog_argument(nofoodcap_argument)) {
        for (i = 1; i < this->player_num; ++i) {
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(0x20, 50.0f);
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(0x21, 0.0f);
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(0x1e, 500.0f);
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(0x1f, 5000.0f);
        }
    } else if (static_cast<TRIBE_Game*>(rge_base_game)->check_prog_argument(system2_argument)) {
        for (i = 1; i < this->player_num; ++i) {
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(0x20, 50.0f);
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(0x21, 0.0f);
        }
    } else {
        for (i = 1; i < this->player_num; ++i) {
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(
                0x20, static_cast<float>(static_cast<TRIBE_Game*>(rge_base_game)->popLimit()));
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(0x21, 0.0f);
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(0x1e, 500.0f);
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(0x2d, 1.0f);
            this->players[i]->victory_conditions->add_points_attribute_amount(0, 0, 0x14, 2, 1);
            this->players[i]->victory_conditions->add_points_attribute_amount(0, 1, 0x2b, 1, 1);
            this->players[i]->victory_conditions->add_points_attribute_amount(0, 2, 0x2c, 1, 1);
            this->players[i]->victory_conditions->add_points_high_attribute_once(0, 3, 0x28, 1, 0x19);
            this->players[i]->victory_conditions->add_points_attribute_amount(1, 4, 0x31, 100, 1);
            this->players[i]->victory_conditions->add_points_attribute_amount(1, 9, 0x35, 0x3c, 1);
            this->players[i]->victory_conditions->add_points_high_attribute_amount(1, 5, 0x25, 1, 1);
            this->players[i]->victory_conditions->add_points_high_attribute_once(1, 6, 0x25, 1, 0x19);
            this->players[i]->victory_conditions->add_points_attribute_amount(1, 7, 0x16, 3, 1);
            if (!static_cast<TRIBE_Game*>(rge_base_game)->fullVisibility()) {
                this->players[i]->victory_conditions->add_points_highest_attribute(1, 8, 0x16, 1, 0x19);
            }
            this->players[i]->victory_conditions->add_points_attribute_amount(2, 10, 0x29, 1, 2);
            this->players[i]->victory_conditions->add_points_highest_attribute(2, 11, 0x29, 1, 0x19);
            this->players[i]->victory_conditions->add_points_attribute_amount(2, 12, 0x0e, 1, 10);
            this->players[i]->victory_conditions->add_points_attribute_amount(2, 13, 7, 1, 10);
            this->players[i]->victory_conditions->add_points_attribute_amount(2, 14, 0x34, 1, 3);
            this->players[i]->victory_conditions->add_points_attribute_amount(2, 16, 0x37, 1, 0x32);
            this->players[i]->victory_conditions->add_points_attribute_amount(2, 15, 0x36, 1, 0x32);
            this->players[i]->victory_conditions->add_points_attribute_amount(3, 17, 0x15, 1, 2);
            this->players[i]->victory_conditions->add_points_highest_attribute(3, 18, 0x15, 1, 0x32);
            this->players[i]->victory_conditions->add_points_attribute_first(3, 19, 6, 3, 0x19);
            this->players[i]->victory_conditions->add_points_attribute_first(3, 20, 6, 4, 0x19);
            this->players[i]->victory_conditions->add_points_attribute_amount(4, 22, 0x2d, 1, 100);
            this->players[i]->victory_conditions->add_points_attribute_amount(4, 23, 0x2a, 1, 100);
            static_cast<TRIBE_Player*>(this->players[i])->add_population_entry();
        }    }

    return ret_num;
}

unsigned char TRIBE_World::new_scenario(RGE_Player_Info& info, int flags) {
    unsigned char result = RGE_Game_World::new_scenario(info, flags);
    int i = 1;
    if (this->player_num > 1) {
        do {
            ++i;
            this->players[i - 1]->attributes[0] = 200.0f;
            this->players[i - 1]->attributes[1] = 200.0f;
            this->players[i - 1]->attributes[3] = 0;
            this->players[i - 1]->attributes[2] = 100.0f;
        } while (i < this->player_num);
    }
    return result;
}

unsigned char TRIBE_World::check_game_state()
{
    int i;
    int held_time;
    int local_1a0;
    int team_count;
    int local_198;
    int team_size[9];
    int player_team[9];
    TRIBE_Player* team_player[9][9];

    if (this->game_state == 0) {
        if (this->victory_type == 2 && this->countdown_victory != 0 &&
            this->countdown_clock >= one) {
            if ((this->countdown_clock =
                     this->countdown_clock - (this->world_time_delta_seconds + this->world_time_delta_seconds)) <
                one) {
                for (i = 0; i < 9; ++i)
                    team_size[i] = -1;
                for (i = 1; i < this->player_num; ++i) {
                    team_size[i] = this->players[i]->victory_conditions->get_victory_points();
                    held_time = 1;
                    if (this->players[i]->allied_victory != 0) {
                        local_1a0 = 1;
                        if (this->player_num > 1) {
                            do {
                                if (local_1a0 != i &&
                                    this->players[i]->relation(local_1a0) == 0 &&
                                    this->players[local_1a0]->relation(i) == 0 &&
                                    this->players[local_1a0]->allied_victory != 0) {
                                    team_size[i] += this->players[local_1a0]->victory_conditions->get_victory_points();
                                    ++held_time;
                                }
                                ++local_1a0;
                            } while (local_1a0 < this->player_num);
                        }
                    }
                    team_size[i] /= held_time;
                }
                TRIBE_Player* winner = 0;
                int best = -1;
                for (i = 1; i < this->player_num; ++i) {
                    if (team_size[i] > best) {
                    winner = static_cast<TRIBE_Player*>(this->players[i]);
                        best = team_size[i];
                    }
                }
                if (winner != 0) {
                    winner->win_game_now();
                    this->game_end_condition = 0x67;
                }
            }
        }

        if (this->artifact_count > 0 || this->ruin_count > 0) {
            int player_count = this->player_num;
            if (player_count > 0) {
                for (i = 0; i < player_count; ++i)
                    team_size[i] = 0;
                for (i = 0; i < player_count; ++i)
                    player_team[i] = -1;
            }
            local_198 = 0;
            held_time = 1;
            team_count = 0;
            for (i = 1; i < this->player_num; ++i) {
                if (player_team[i] == -1) {
                    player_team[i] = local_198;
                    team_player[local_198][team_size[local_198]] = static_cast<TRIBE_Player*>(this->players[i]);
                    ++team_size[local_198];
                    if (this->players[i]->allied_victory != 0) {
                        local_1a0 = 1;
                        for (; local_1a0 < this->player_num; ++local_1a0) {
                            if (player_team[local_1a0] == -1 &&
                                this->players[local_1a0]->allied_victory != 0 &&
                                this->players[i]->relation(local_1a0) == 0 &&
                                this->players[local_1a0]->relation(i) == 0) {
                                player_team[local_1a0] = local_198;
                                    team_player[local_198][team_size[local_198]] =
                                        static_cast<TRIBE_Player*>(this->players[local_1a0]);
                                ++team_size[local_198];
                            }
                        }
                    }
                    ++local_198;
                    team_count += 9;
                }
            }

            if (this->artifact_count > 0 && local_198 > 0) {
                for (i = 0; i < local_198; ++i) {
                    int count = team_size[i];
                    int total = 0;
                    for (int j = 0; j < count; ++j)
                        total += static_cast<int>(team_player[i][j]->attributes[7]);
                    if (total == this->artifact_count) {
                        TRIBE_Player* p = team_player[i][0];
                        float held = p->artifact_held_time;
                        if (held == minus_one) {
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->attributes[55] = 1.0f;
                            if (this->victory_type == 0) {
                                for (int j = 0; j < count; ++j)
                                    team_player[i][j]->artifact_held_time = 2000.0f;
                                rge_base_game->notification(0x72,
                                    p->id, 0, 0, 0);
                            }
                        }
                        else if (held >= one && this->victory_type == 0) {
                            held = held - (this->world_time_delta_seconds + this->world_time_delta_seconds);
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->artifact_held_time = held;
                            if (held < one) {
                                p->win_game_now();
                                this->game_end_condition = 0x65;
                            }
                        }
                    }
                    else {
                        TRIBE_Player* p = team_player[i][0];
                        if (p->artifact_held_time != -1.0f) {
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->attributes[55] = 0.0f;
                            if (this->victory_type == 0) {
                                for (int j = 0; j < count; ++j)
                                    team_player[i][j]->artifact_held_time = -1.0f;
                                rge_base_game->notification(0x73,
                                    p->id, 0, 0, 0);
                            }
                        }
                    }
                }
            }

            if (this->ruin_count > 0 && local_198 > 0) {
                for (i = 0; i < local_198; ++i) {
                    int count = team_size[i];
                    int total = 0;
                    for (int j = 0; j < count; ++j)
                        total += static_cast<int>(team_player[i][j]->attributes[14]);
                    if (total == this->ruin_count) {
                        TRIBE_Player* p = team_player[i][0];
                        float held = p->ruin_held_time;
                        if (held == minus_one) {
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->attributes[54] = 1.0f;
                            if (this->victory_type == 0) {
                                for (int j = 0; j < count; ++j)
                                    team_player[i][j]->ruin_held_time = 2000.0f;
                                RGE_Base_Game* game = rge_base_game;
                                game->notification(0x74, p->id, 0, 0, 0);
                            }
                        }
                        else if (held >= one && this->victory_type == 0) {
                            held = held - (this->world_time_delta_seconds + this->world_time_delta_seconds);
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->ruin_held_time = held;
                            if (held < one) {
                                p->win_game_now();
                                this->game_end_condition = 0x66;
                            }
                        }
                    }
                    else {
                        TRIBE_Player* p = team_player[i][0];
                        if (p->ruin_held_time != -1.0f) {
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->attributes[54] = 0.0f;
                            if (this->victory_type == 0) {
                                for (int j = 0; j < count; ++j)
                                    team_player[i][j]->ruin_held_time = -1.0f;
                                rge_base_game->notification(0x75, p->id, 0, 0, 0);
                            }
                        }
                    }
                }
            }
        }
    }

    return RGE_Game_World::check_game_state();
}

long TRIBE_World::get_achievement(unsigned char achievement_id, char** buffers) {
    int player = 1;

    if (this->player_num > 1) {
        do {
            TRIBE_Player* p = static_cast<TRIBE_Player*>(this->players[player]);
            if (p != 0) {
                p->get_achievement(achievement_id, buffers[player]);
            }
            player++;
        } while (player < this->player_num);
    }

    return this->player_num;
}

void TRIBE_World::send_cheat(short code) {
    static_cast<TRIBE_Command*>(this->commands)->command_cheat(
        this->curr_player, code);
}

void TRIBE_World::cheat(short player, short cheat_code)
{
    if (rge_base_game->allowCheatCodes() != 0) {
        switch (cheat_code) {
        case 0:
            if (player > 0) {
                RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
                if (object != 0)
                    static_cast<TRIBE_Command*>(this->commands)->command_make(object, 0x112);
            }
            break;
        case 1:
            if (player > 0) {
                RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
                if (object != 0)
                    static_cast<TRIBE_Command*>(this->commands)->command_make(object, 0xf8);
            }
            break;
        case 2:
            if (player > 0)
                this->effects->do_effect(0x7f, this->players[player]);
            break;
        case 3:
            if (player > 0)
                this->effects->do_effect(0x80, this->players[player]);
            break;
        case 4:
            if (player > 0)
                this->effects->do_effect(0x81, this->players[player]);
            break;
        case 5:
            this->effects->do_effect(0x82, this->players[0]);
            break;
        case 6:
            if (player > 0)
                this->effects->do_effect(0x83, this->players[player]);
            break;
        case 7:
            if (player > 0)
                this->effects->do_effect(0x84, this->players[player]);
            break;
        case 8:
            if (player > 0)
                this->effects->do_effect(0x85, this->players[player]);
            break;
        case 9:
            if (player > 0)
                this->effects->do_effect(0x86, this->players[player]);
            break;
        case 10:
            if (player > 0)
                this->effects->do_effect(0x87, this->players[player]);
            break;
        case 11:
            if (player > 0)
                this->effects->do_effect(0x88, this->players[player]);
            break;
        case 12:
            if (player > 0)
                this->effects->do_effect(0x89, this->players[player]);
            break;
        case 13:
            if (player > 0)
                this->effects->do_effect(0x8a, this->players[player]);
            break;
        case 14:
            if (player > 0) {
                RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
                if (object != 0)
                    static_cast<TRIBE_Command*>(this->commands)->command_make(object, 0x182);
            }
            break;
        case 15:
            if (player > 0)
                this->effects->do_effect(0xd7, this->players[player]);
            break;
        case 16:
            if (player > 0) {
                RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
                if (object != 0)
                    static_cast<TRIBE_Command*>(this->commands)->command_make(object, 0x18d);
            }
            break;
        case 17:
            if (player > 0)
                this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
            break;
        case 18:
            this->effects->do_effect(0xd8, this->players[0]);
            break;
        case 19:
            this->effects->do_effect(0xd9, this->players[0]);
            break;
        case 100: {
            int i = 1;
            die_die_die = 1;
            if (this->player_num > 1) {
                do {
                    if (i != player || this->players[player]->isAlly(i) == 0 ||
                        this->players[i]->isAlly(player) == 0)
                    {
                        RGE_Object_Node* node = this->players[i]->objects->list;
                        while (node != 0) {
                            RGE_Static_Object* object = node->node;
                            if (object->object_state < 3 &&
                                object->master_obj->object_group != 1)
                                object->die_die_die();
                            node = node->next;
                        }
                    }
                    ++i;
                } while (i < this->player_num);
            }
            break;
        }
        case 101:
            {
                RGE_Object_Node* node = this->players[player]->objects->list;
                while (node != 0) {
                    RGE_Static_Object* object = node->node;
                    if (object->object_state < 3 &&
                        object->master_obj->object_group != 1)
                        object->die_die_die();
                    node = node->next;
                }
            }
            break;
        case 102:
            this->players[player]->win_game_now();
            this->game_end_condition = 0x68;
            break;
        case 103:
            this->players[player]->loss_if_game_on();
            break;
        case 200:
        case 201:
        case 202:
        case 203:
        case 204:
        case 205:
        case 206:
        case 207:
        case 208:
        case 209: {
            int other_player = cheat_code - 200;
            if ((other_player != player ||
                 this->players[player]->isAlly(other_player) == 0 ||
                 this->players[other_player]->isAlly(player) == 0) &&
                this->players[other_player]->objects->list != 0) {
                RGE_Object_Node* node = this->players[other_player]->objects->list;
                while (node != 0) {
                    RGE_Static_Object* object = node->node;
                    if (object->object_state < 3 &&
                        object->master_obj->object_group != 1)
                        object->die_die_die();
                    node = node->next;
                }
            }
            break;
        }
        case 220: {
            RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                0x6d, -1.0f, -1.0f, 1, 2, 0);
            if (object != 0)
                static_cast<TRIBE_Command*>(this->commands)->command_make(object, 0x174);
            break;
        }
        case 230:
            rge_base_game->set_map_visible(1);
            rge_base_game->get_view_panel()->set_redraw(TPanel::RedrawImmediate);
            rge_base_game->get_map_panel()->set_redraw(TPanel::RedrawImmediate);
            break;
        case 231:
            rge_base_game->set_map_fog(0);
            rge_base_game->get_view_panel()->set_redraw(TPanel::RedrawImmediate);
            break;
        }
    }
}

void TRIBE_World::fill_in_score(TRIBE_Zone_High_Score_Info& info, long group)
{
    int player = 1;
    long high_score = 0;
    int hi_player = 1;

    if (1 < this->player_num) {
        do {
            if (this->players[player]->computerPlayer() == 0) {
                if (this->players[player]->victory_conditions->get_victory_points_group(
                        static_cast<unsigned char>(group)) > high_score) {
                    high_score = this->players[player]->victory_conditions->get_victory_points_group(
                        static_cast<unsigned char>(group));
                    hi_player = player;
                }
            }
            player++;
        } while (player < this->player_num);
    }

    info.score = high_score;
    info.civ = this->players[hi_player]->culture;
    strcpy(info.player_name, this->players[hi_player]->name);

    long count = 0;
    player = 1;
    if (1 < this->player_num) {
        do {
            if ((player != hi_player) &&
                (this->players[player]->relation(hi_player) == 0) &&
                (this->players[hi_player]->relation(player) == 0)) {
                count++;
            }
            player++;
        } while (player < this->player_num);
    }
    info.num_allies = static_cast<unsigned char>(count);
}

void TRIBE_World::send_zone_score_info()
{
    TRIBE_Zone_Info info;
    TRIBE_Game::TRIBE_Game_Options options;
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
        info.number_of_computer_players = static_cast<unsigned char>(computer_players);

        strcpy(info.scenario_name, this->scenario->Get_scenario_name());
        info.game_time = this->world_time / 1000;

        this->fill_in_score(info.total_score, 0xFF);
        this->fill_in_score(info.religion_score, 2);
        this->fill_in_score(info.economy_score, 1);
        this->fill_in_score(info.combat_score, 0);
        this->fill_in_score(info.research_score, 3);

        player = 1;
        if (player < this->player_num) {
            do {
                strcpy(info.player_info[player - 1].name,
                    this->players[player]->name);
                info.player_info[player - 1].score =
                    this->players[player]->victory_conditions->get_victory_points();
                info.player_info[player - 1].winner =
                    (this->players[player]->game_status == 1);
                info.player_info[player - 1].civ_played =
                    static_cast<unsigned char>(
                        static_cast<TRIBE_Game*>(rge_base_game)->civilization(player - 1));
                info.player_info[player - 1].civ_random =
                    static_cast<unsigned char>(
                        static_cast<TRIBE_Game*>(rge_base_game)->random_civ[player - 1]);
                info.player_info[player - 1].player_no =
                    static_cast<unsigned char>(
                        static_cast<TRIBE_Game*>(rge_base_game)->playerColor(player - 1));
                info.player_info[player - 1].team_no =
                    static_cast<unsigned char>(
                        static_cast<TRIBE_Game*>(rge_base_game)->playerTeam(player - 1));
                int game_outcome = comm->WasKicked[player - 1];
                info.player_info[player - 1].game_outcome =
                    static_cast<unsigned char>(game_outcome);
                info.player_info[player - 1].tool_time = -1;
                info.player_info[player - 1].bronze_time = -1;
                info.player_info[player - 1].iron_time = -1;

                TRIBE_History_Events* event =
                    static_cast<TRIBE_Player*>(this->players[player])->history->events;
                while (event != 0) {
                    switch (event->event) {
                    case 0:
                        info.player_info[player - 1].tool_time = event->world_time;
                        break;
                    case 1:
                        info.player_info[player - 1].bronze_time = event->world_time;
                        break;
                    case 2:
                        info.player_info[player - 1].iron_time = event->world_time;
                        break;
                    }
                    event = event->next;
                }
                player++;
            } while (player < this->player_num);
        }

        info.cheats_enabled = static_cast<unsigned char>(
            static_cast<TRIBE_Game*>(rge_base_game)->allowCheatCodes());
        switch (this->game_end_condition) {
        case 0:
            info.game_end_condition_code = 0;
            break;
        case 1:
            info.game_end_condition_code = 1;
            break;
        case 100:
            info.game_end_condition_code = 2;
            break;
        case 101:
            info.game_end_condition_code = 3;
            break;
        case 102:
            info.game_end_condition_code = 4;
            break;
        case 103:
            info.game_end_condition_code = 5;
            break;
        case 2:
            info.game_end_condition_code = 6;
            break;
        case 104:
            info.game_end_condition_code = 7;
            break;
        default:
            info.game_end_condition_code = 8;
            break;
        }

        static_cast<TRIBE_Game*>(rge_base_game)->get_tribe_options(&options);
        info.map_info.Map_Size = static_cast<unsigned char>(options.mapSizeValue);
        info.map_info.Map_Type = static_cast<unsigned char>(options.mapTypeValue);
        info.map_info.Victory_Condition = static_cast<unsigned char>(options.victoryTypeValue);
        info.map_info.Start_Age = static_cast<unsigned char>(options.startingAgeValue);
        info.map_info.Resources = static_cast<unsigned char>(options.resourceLevelValue);
        info.map_info.Full_Tech = options.fullTechTreeValue;
        info.map_info.Fixed_Pos = options.randomizePositionsValue;
        info.map_info.Reveal_Map = static_cast<unsigned char>(
            static_cast<TRIBE_Game*>(rge_base_game)->fullVisibility());
        info.map_info.Death_Match = options.deathMatchValue;
        info.map_info.Pop_Limit = static_cast<short>(options.popLimitValue);

        info.database_checksum = 0;
        info.code_checksum = 0;
        info.program_version = 0;

        this->commands->com_hand->SendZoneMessage(
            static_cast<char*>(static_cast<void*>(&info)), 0x1fc);
    }
}
