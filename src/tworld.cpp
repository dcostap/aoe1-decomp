
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
#include "../include/resource_ids.h"

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

void TRIBE_World::logStatus(FILE* out, int firstTime) {
    long clock;
    char tempString[256];

    if (out != 0 && firstTime == 1) {
        fprintf(out, "\n\n\n****************************************\n");

        time(&clock);
        fprintf(out, "AI Log file for Game Started %s", asctime(localtime(&clock)));
        fprintf(out, "Number Players:          %d\n", static_cast<int>(this->player_num) - 1);

        if (this->scenario->scenario_name != 0 && strlen(this->scenario->scenario_name) != 0) {
            fprintf(out, "Scenario:                %s\n", this->scenario->scenario_name);
            return;
        }

        static_cast<TRIBE_Game*>(rge_base_game)
            ->get_string(static_cast<TRIBE_Game*>(rge_base_game)->mapSize() + STRING_ID_MAP_SIZE_BASE, tempString, 256);
        fprintf(out, "Map Size:                %s\n", tempString);

        static_cast<TRIBE_Game*>(rge_base_game)
            ->get_string(static_cast<TRIBE_Game*>(rge_base_game)->mapType() + STRING_ID_MAP_TYPE_BASE, tempString, 256);
        fprintf(out, "Map Type:                %s\n", tempString);

        // The checked resource files contain no text for this legacy log range.
        static_cast<TRIBE_Game*>(rge_base_game)
            ->get_string(
                static_cast<TRIBE_Game*>(rge_base_game)->victoryType() + STRING_ID_VICTORY_LOG_BASE, tempString, 256
            );
        fprintf(out, "Victory Condition:       %s\n", tempString);
    }
}

void TRIBE_World::data_load_players_type(short id, short type, FILE* infile) {
    if (type != 1) {
        RGE_Game_World::data_load_players_type(id, type, infile);
        return;
    }

    this->master_players[id] = new TRIBE_Master_Player(infile);
}

void TRIBE_World::data_load_map(
    char* border_file, char* overlay_file, char* terrain_file, char* map_file, short tile_width, short tile_height,
    short elev_height, RGE_Sound** sounds, char* terr_obj_file
) {
    TRIBE_Map* m =
        new TRIBE_Map(border_file, overlay_file, terrain_file, map_file, tile_width, tile_height, elev_height, sounds);
    this->map = m;
    m->load_terrain_obj_types(terr_obj_file);
}

unsigned char TRIBE_World::data_load_world(FILE* infile) {
    char tech_file[23];

    RGE_Game_World::data_load_world(infile);
    fscanf(infile, "%s ", tech_file);
    this->tech = new TRIBE_Tech(tech_file);
    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0.0f;
    this->score_displayed = 0;
    return 1;
}

unsigned char TRIBE_World::init_player_type(int infile, short index, unsigned char type) {
    switch (type) {
        case 1: {
            TRIBE_Master_Player* p = new TRIBE_Master_Player(infile);
            this->master_players[index] = p;
            this->master_players[index]->finish_init(infile, this->sprites, this->sounds);
            break;
        }
        default:
            return RGE_Game_World::init_player_type(infile, index, type);
    }

    return 1;
}

void TRIBE_World::map_init(int infile, TSound_Driver* sound_dvr) {
    TRIBE_Map* p = new TRIBE_Map(infile, this->sounds, 1);
    this->map = p;
}

void TRIBE_World::command_init(int infile, TCommunications_Handler* com_hand) {
    TRIBE_Command* cmd;
    cmd = new TRIBE_Command(this, com_hand);
    this->commands = cmd;
}

void TRIBE_World::scenario_init(int infile, RGE_Game_World* world) {
    T_Scenario* s = new T_Scenario(infile, world);
    this->scenario = s;
}

void TRIBE_World::scenario_init(RGE_Game_World* world) {
    T_Scenario* s = new T_Scenario(world);
    this->scenario = s;
}

void TRIBE_World::effects_init(int infile) {
    TRIBE_Effects* e = new TRIBE_Effects(infile);
    this->effects = e;
}

void TRIBE_World::world_init(int infile, TSound_Driver* sound_dvr, TCommunications_Handler* com_hand) {
    RGE_Game_World::world_init(infile, sound_dvr, com_hand);

    TRIBE_Tech* new_tech = new TRIBE_Tech(infile, this);
    this->tech = new_tech;
    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0;
    this->score_displayed = 0;
}

unsigned char TRIBE_World::init(char* base_name, TSound_Driver* sound_dvr, TCommunications_Handler* com_hand) {
    return RGE_Game_World::init(base_name, sound_dvr, com_hand);
}

void TRIBE_World::base_save(int outfile) {
    RGE_Game_World::base_save(outfile);
    this->tech->save(outfile);
}

void TRIBE_World::save(int outfile) {
    RGE_Game_World::save(outfile);
    rge_write(outfile, &victory_type, 4);
    rge_write(outfile, &artifact_count, 4);
    rge_write(outfile, &ruin_count, 4);
    rge_write(outfile, &countdown_victory, 1);
    rge_write(outfile, &countdown_clock, 4);
    rge_write(outfile, &score_displayed, 1);
    rge_write(outfile, &controllingComputerPlayer, 1);
}

void TRIBE_World::load_player(int infile, unsigned char type, short index) {
    switch (type) {
        case 1:
        case 3:
            this->players[index] =
                static_cast<RGE_Player*>(new TRIBE_Player(infile, this, static_cast<unsigned char>(index)));
            break;
        case 2:
            this->players[index] =
                static_cast<RGE_Player*>(new TRIBE_Gaia(infile, this, static_cast<unsigned char>(index)));
            break;
        default:
            RGE_Game_World::load_player(infile, type, index);
            return;
    }

    static_cast<TRIBE_Player*>(this->players[index])->load(infile);
}

void TRIBE_World::setup_gaia() {
    this->players[0] = new TRIBE_Gaia(this, this->master_players[CIVILIZATION_GAIA], 0, "GAIA", CIVILIZATION_GAIA);
}

void TRIBE_World::setup_players(RGE_Player_Info& info) {
    int index = 1;

    if (this->player_num > 1) {
        do {
            TRIBE_Player* player;

            char type = info.type[index - 1];
            switch (type) {
                case 0:
                    player = new TRIBE_Player(
                        this, this->master_players[info.tribe[index - 1]], static_cast<unsigned char>(index),
                        info.name[index - 1], info.tribe[index - 1], 0, 1, 0, 0, 0
                    );
                    break;
                case 4:
                    if (useComputerPlayers == 0) {
                        player = new TRIBE_Player(
                            this, this->master_players[info.tribe[index - 1]], static_cast<unsigned char>(index),
                            info.name[index - 1], info.tribe[index - 1], 0, 1, 0, 0, 0
                        );
                    } else {
                        player = new TRIBE_Player(
                            this, this->master_players[info.tribe[index - 1]], static_cast<unsigned char>(index),
                            info.name[index - 1], info.tribe[index - 1], 1, 1, 0, 0, 0
                        );
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

void TRIBE_World::check_destructables(short player_id, short obj_id, float col, float row, unsigned char delete_flag) {
    RGE_Master_Static_Object* master = players[player_id]->master_objects[obj_id];

    if (master != 0) {
        float radius_x = master->radius_x;
        float radius_y = master->radius_y;
        if (radius_x > 0.0f || radius_y > 0.0f) {
            // Original 0057755C/00577560 hold +3.0/-3.0, not half a tile.
            short x_min = static_cast<short>(col - 3.0f);
            short y_min = static_cast<short>(row - 3.0f);
            short x_max = static_cast<short>(col + 3.0f);
            short y_max = static_cast<short>(row + 3.0f);
            if (x_min < 0)
                x_min = 0;
            if (x_max >= map->map_width)
                x_max = static_cast<short>(map->map_width - 1);
            if (y_min < 0)
                y_min = 0;
            if (y_max >= map->map_height)
                y_max = map->map_height - 1;

            if (y_min <= y_max) {
                for (short map_row = y_min; map_row <= y_max; ++map_row) {
                    RGE_Tile* tile = map->map_row_offset[map_row] + x_min;
                    if (x_min <= x_max) {
                        for (short column = x_min; column <= x_max; ++column) {
                            RGE_Object_Node* node = tile->objects.list;
                            while (node != 0) {
                                RGE_Object_Node* next = node->next;
                                RGE_Static_Object* object = node->node;
                                RGE_Master_Static_Object* object_master = object->master_obj;

                                if (object_master->id != obj_id && object_master->can_be_built_on != 0) {
                                    float object_radius_x = object_master->radius_x;
                                    float object_radius_y = object_master->radius_y;
                                    float dy = object->world_y - row;
                                    float dx = object->world_x - col;
                                    if (dy < 0.0f)
                                        dy = -dy;
                                    if (dx < 0.0f)
                                        dx = -dx;

                                    if (dx < object_radius_x + radius_x && dy < object_radius_y + radius_y) {
                                        if (delete_flag != 0) {
                                            if (object != 0)
                                                delete object;
                                        } else {
                                            object->destroy_obj();
                                        }
                                    }
                                }
                                node = next;
                            }
                            ++tile;
                        }
                    }
                }
            }
        }
    }
}

void TRIBE_World::scenario_make_player(
    short index, unsigned char player_type, unsigned char info_type, unsigned char master_player_id, char* name
) {
    if (info_type == 0) {
        this->players[index] = new TRIBE_Player(
            this, this->master_players[player_type], static_cast<unsigned char>(index), name, player_type, 0, 1, 0, 0, 0
        );
    } else {
        if (info_type == 4) {
            this->players[index] = new TRIBE_Player(
                this, this->master_players[player_type], static_cast<unsigned char>(index), name, player_type, 1, 1, 0,
                0, 0
            );
        } else {
            this->players[index] = new TRIBE_Player(
                this, this->master_players[player_type], static_cast<unsigned char>(index), name, player_type, 0, 1, 0,
                0, 0
            );
        }
    }
}

unsigned char TRIBE_World::load_world(int infile1) {
    if (!RGE_Game_World::load_world(infile1))
        return 0;

    if (save_game_version >= 5.6f) {
        rge_read(infile1, &this->victory_type, 4);
    } else {
        this->victory_type = 0;
    }

    if (save_game_version >= 5.3f) {
        rge_read(infile1, &this->artifact_count, 4);
        rge_read(infile1, &this->ruin_count, 4);
    } else {
        this->artifact_count = 0;
        this->ruin_count = 0;
    }

    if (save_game_version >= 5.4f) {
        rge_read(infile1, &this->countdown_victory, 1);
        rge_read(infile1, &this->countdown_clock, 4);
    } else {
        this->countdown_victory = 0;
        this->countdown_clock = 0.0f;
    }

    if (save_game_version >= 6.6f) {
        rge_read(infile1, &this->score_displayed, 1);
    } else {
        this->score_displayed = 0;
    }

    if (save_game_version >= 6.97f) {
        rge_read(infile1, &this->controllingComputerPlayer, 1);
    } else {
        this->controllingComputerPlayer = 2;
    }

    return 1;
}

unsigned char TRIBE_World::new_game(RGE_Player_Info& info, int myPlayerNum) {
    int victoryAmount;
    RGE_RMM_Object_Generator* generator;
    unsigned char ret_num;
    char str1[256];
    char str2[256];
    char str3[256];
    char description[4096];
    int i;
    TRIBE_Game::Age age;
    TRIBE_Game::ResourceLevel res;
    int want;
    int missing;

    this->score_displayed = 0;
    this->controllingComputerPlayer = 0xff;
    ret_num = RGE_Game_World::new_game(info, myPlayerNum);

    for (i = 0; i < this->player_num; ++i) {
        static_cast<TRIBE_Game*>(rge_base_game)->reset_countdown_timer(i);
    }

    if (!((static_cast<TRIBE_Game*>(rge_base_game)->campaignGame()
           || !static_cast<TRIBE_Game*>(rge_base_game)->randomGame())
          && static_cast<TRIBE_Game*>(rge_base_game)->victoryType() == TRIBE_Game::VictoryDefault)) {
        if (!static_cast<TRIBE_Game*>(rge_base_game)->campaignGame()
            && static_cast<TRIBE_Game*>(rge_base_game)->randomGame()) {
            static_cast<T_Scenario*>(this->scenario)->Set_scenario_name(s_empty_string);
        }

        switch (static_cast<TRIBE_Game*>(rge_base_game)->victoryType()) {
            case TRIBE_Game::VictoryDefault:
            case TRIBE_Game::VictoryStandard:
                static_cast<TRIBE_Game*>(rge_base_game)
                    ->get_string(STRING_ID_VICTORY_DESCRIPTION_STANDARD, description, 4096);
                break;
            case TRIBE_Game::VictoryConquest:
                static_cast<TRIBE_Game*>(rge_base_game)
                    ->get_string(STRING_ID_VICTORY_DESCRIPTION_CONQUEST, description, 4096);
                break;
            case TRIBE_Game::VictoryTime:
                static_cast<TRIBE_Game*>(rge_base_game)
                    ->get_string(STRING_ID_VICTORY_DESCRIPTION_TIME_LIMIT, description, 4096);
                break;
            case TRIBE_Game::VictoryScore:
                static_cast<TRIBE_Game*>(rge_base_game)
                    ->get_string(STRING_ID_VICTORY_DESCRIPTION_SCORE, description, 4096);
                break;
            default:
                break;
        }

        switch (static_cast<TRIBE_Game*>(rge_base_game)->mapSize()) {
            case TRIBE_Game::Tiny:
                strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_SIZE_TINY));
                break;
            case TRIBE_Game::Small:
                strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_SIZE_SMALL));
                break;
            case TRIBE_Game::Medium:
                strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_SIZE_MEDIUM));
                break;
            case TRIBE_Game::Large:
                strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_SIZE_LARGE));
                break;
            case TRIBE_Game::Huge:
                strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_SIZE_HUGE));
                break;
            case TRIBE_Game::Humongous:
                strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_SIZE_HUMONGOUS));
                break;
        }
        sprintf(str2, rge_base_game->get_string(STRING_ID_MAP_SIZE_FORMAT), str1);
        sprintf(description, newline_join_format, description, str2);

        if (static_cast<TRIBE_Game*>(rge_base_game)->randomGame()) {
            switch (static_cast<TRIBE_Game*>(rge_base_game)->mapType()) {
                case TRIBE_Game::AllWater:
                    strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_TYPE_ALL_WATER));
                    break;
                case TRIBE_Game::MostlyWater:
                    strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_TYPE_MOSTLY_WATER));
                    break;
                case TRIBE_Game::WaterAndLand:
                    strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_TYPE_WATER_AND_LAND));
                    break;
                case TRIBE_Game::MostlyLand:
                    strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_TYPE_MOSTLY_LAND));
                    break;
                case TRIBE_Game::AllLand:
                    strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_TYPE_ALL_LAND));
                    break;
                case TRIBE_Game::Continental:
                    strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_TYPE_CONTINENTAL));
                    break;
                case TRIBE_Game::Lake:
                    strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_TYPE_LAKE));
                    break;
                case TRIBE_Game::Hilly:
                    strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_TYPE_HILLY));
                    break;
                case TRIBE_Game::Isthmas:
                    strcpy(str1, rge_base_game->get_string(STRING_ID_MAP_TYPE_ISTHMAS));
                    break;
            }
            sprintf(str2, rge_base_game->get_string(STRING_ID_MAP_TYPE_FORMAT), str1);
            sprintf(description, newline_join_format, description, str2);
        }

        age = static_cast<TRIBE_Game*>(rge_base_game)->startingAge();
        if (age == TRIBE_Game::DefaultAge) {
            static_cast<TRIBE_Game*>(rge_base_game)->get_string(STRING_ID_OPTION_DEFAULT, str1, 256);
        } else if (age == TRIBE_Game::NomadAge) {
            static_cast<TRIBE_Game*>(rge_base_game)->get_string(STRING_ID_AGE_NOMAD, str1, 256);
        } else {
            static_cast<TRIBE_Game*>(rge_base_game)->get_string(age + STRING_ID_AGE_NAME_BASE, str1, 256);
        }
        sprintf(str2, rge_base_game->get_string(STRING_ID_STARTING_AGE_FORMAT), str1);
        sprintf(description, newline_join_format, description, str2);

        res = static_cast<TRIBE_Game*>(rge_base_game)->resourceLevel();
        if (res == TRIBE_Game::DefaultResources) {
            static_cast<TRIBE_Game*>(rge_base_game)->get_string(STRING_ID_OPTION_DEFAULT, str1, 256);
        } else {
            static_cast<TRIBE_Game*>(rge_base_game)->get_string(res + STRING_ID_RESOURCE_LEVEL_BASE, str1, 256);
        }
        sprintf(str2, rge_base_game->get_string(STRING_ID_RESOURCE_LEVEL_FORMAT), str1);
        sprintf(description, newline_join_format, description, str2);

        static_cast<TRIBE_Game*>(rge_base_game)->difficulty();
        static_cast<TRIBE_Game*>(rge_base_game)
            ->get_string(static_cast<TRIBE_Game*>(rge_base_game)->difficulty() + STRING_ID_DIFFICULTY_BASE, str1, 256);
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(STRING_ID_DIFFICULTY_FORMAT, str2, 256);
        sprintf(str3, str2, str1);
        sprintf(description, newline_join_format, description, str3);

        if (static_cast<TRIBE_Game*>(rge_base_game)->randomizePositions() == 0) {
            static_cast<TRIBE_Game*>(rge_base_game)->get_string(STRING_ID_BUTTON_YES, str1, 256);
        } else {
            static_cast<TRIBE_Game*>(rge_base_game)->get_string(STRING_ID_BUTTON_NO, str1, 256);
        }
        sprintf(str2, rge_base_game->get_string(STRING_ID_FIXED_POSITIONS_FORMAT), str1);
        sprintf(description, newline_join_format, description, str2);
        if (static_cast<TRIBE_Game*>(rge_base_game)->fullVisibility() == 0) {
            strcpy(str1, rge_base_game->get_string(STRING_ID_BUTTON_NO));
        } else {
            strcpy(str1, rge_base_game->get_string(STRING_ID_BUTTON_YES));
        }
        sprintf(str2, rge_base_game->get_string(STRING_ID_REVEAL_MAP_FORMAT), str1);
        sprintf(description, newline_join_format, description, str2);
        if (static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree() == 0) {
            static_cast<TRIBE_Game*>(rge_base_game)->get_string(STRING_ID_BUTTON_NO, str1, 256);
        } else {
            static_cast<TRIBE_Game*>(rge_base_game)->get_string(STRING_ID_BUTTON_YES, str1, 256);
        }
        sprintf(str2, rge_base_game->get_string(STRING_ID_FULL_TECH_TREE_FORMAT), str1);
        sprintf(description, newline_join_format, description, str2);

        if (static_cast<TRIBE_Game*>(rge_base_game)->multiplayerGame()) {
            if (static_cast<TRIBE_Game*>(rge_base_game)->allowCheatCodes() == 0) {
                strcpy(str1, rge_base_game->get_string(STRING_ID_BUTTON_NO));
            } else {
                strcpy(str1, rge_base_game->get_string(STRING_ID_BUTTON_YES));
            }
            sprintf(str2, rge_base_game->get_string(STRING_ID_CHEATING_ENABLED_FORMAT), str1);
            sprintf(description, newline_join_format, description, str2);
        }

        rge_base_game->get_string(
            (static_cast<TRIBE_Game*>(rge_base_game)->multiplayerGame()
                 ? static_cast<TRIBE_Game*>(rge_base_game)->mpPathFinding()
                 : static_cast<TRIBE_Game*>(rge_base_game)->pathFinding())
                + STRING_ID_PATH_FINDING_OPTION_BASE,
            str1, 256
        );
        sprintf(str2, rge_base_game->get_string(STRING_ID_PATH_FINDING_FORMAT), str1);
        sprintf(description, newline_join_format, description, str2);

        sprintf(
            str2, rge_base_game->get_string(STRING_ID_POPULATION_LIMIT_FORMAT),
            static_cast<int>(static_cast<TRIBE_Game*>(rge_base_game)->popLimit())
        );
        sprintf(description, newline_join_format, description, str2);
        static_cast<T_Scenario*>(this->scenario)->add_description(description);
    }

    if (ret_num) {
        this->victory_type = 4;
        this->countdown_victory = 0;
        this->countdown_clock = 0.0f;

        if ((!static_cast<TRIBE_Game*>(rge_base_game)->campaignGame()
             && static_cast<TRIBE_Game*>(rge_base_game)->randomGame())
            || static_cast<TRIBE_Game*>(rge_base_game)->victoryType() != TRIBE_Game::VictoryDefault) {
            static_cast<T_Scenario*>(this->scenario)->Set_victory_all_flag(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Ruins(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Artifacts(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Discoveries(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Exploration(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Gold(0);
            victoryAmount = static_cast<TRIBE_Game*>(rge_base_game)->victoryAmount();
            switch (static_cast<TRIBE_Game*>(rge_base_game)->victoryType()) {
                case TRIBE_Game::VictoryDefault:
                case TRIBE_Game::VictoryStandard:
                    this->victory_type = 0;
                    static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(1);
                    break;
                case TRIBE_Game::VictoryConquest:
                    this->victory_type = 1;
                    static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(1);
                    break;
                case TRIBE_Game::VictoryTime:
                    this->victory_type = 2;
                    static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(1);
                    break;
                case TRIBE_Game::VictoryScore:
                    this->victory_type = 3;
                    static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(1);
                    break;
                case TRIBE_VICTORY_TYPE_RUINS:
                    static_cast<T_Scenario*>(this->scenario)->Set_Multi_Ruins(victoryAmount);
                    break;
                case TRIBE_VICTORY_TYPE_ARTIFACTS:
                    static_cast<T_Scenario*>(this->scenario)->Set_Multi_Artifacts(victoryAmount);
                    break;
                case TRIBE_VICTORY_TYPE_DISCOVERIES:
                    static_cast<T_Scenario*>(this->scenario)->Set_Multi_Discoveries(victoryAmount);
                    break;
                case TRIBE_VICTORY_TYPE_EXPLORATION:
                    static_cast<T_Scenario*>(this->scenario)->Set_Multi_Exploration(victoryAmount);
                    break;
                case TRIBE_VICTORY_TYPE_GOLD:
                    static_cast<T_Scenario*>(this->scenario)->Set_Multi_Gold(victoryAmount);
                    break;
            }
            static_cast<T_Scenario*>(this->scenario)->Save_victory_conditions_into_players(0);
            switch (static_cast<TRIBE_Game*>(rge_base_game)->victoryType()) {
                case TRIBE_Game::VictoryTime:
                    this->countdown_victory = 1;
                    this->countdown_clock = static_cast<float>(victoryAmount);
                    break;
                case TRIBE_Game::VictoryScore:
                    for (i = 1; i < this->player_num; ++i) {
                        this->players[i]->victory_conditions->add_victory_points(0, victoryAmount, 1);
                    }
                    break;
            }
        } else {
            if (static_cast<TRIBE_Game*>(rge_base_game)->campaignGame()
                || static_cast<TRIBE_Game*>(rge_base_game)->scenarioGame()) {
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
                        this->countdown_clock =
                            static_cast<float>(static_cast<T_Scenario*>(this->scenario)->GetVictoryTime());
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
            int count = 0;
            int player_count = this->player_num;
            if (player_count > 0) {
                RGE_Player** player = this->players;
                do {
                    RGE_Object_Node* node = (*player)->objects->list;
                    while (node != 0) {
                        if (node->node->master_obj->id == MASTER_OBJECT_ARTIFACT1) {
                            ++count;
                        }
                        node = node->next;
                    }
                    ++player;
                    --player_count;
                } while (player_count != 0);
            }
            missing = want - count;
            if (missing > 0)
                generator->add_quick_obj(0x9f, missing, 0);
        }
        want = static_cast<T_Scenario*>(this->scenario)->Get_Multi_Discoveries();
        if (want > 0) {
            int count = 0;
            int player_count = this->player_num;
            if (player_count > 0) {
                RGE_Player** player = this->players;
                do {
                    RGE_Object_Node* node = (*player)->objects->list;
                    while (node != 0) {
                        if (node->node->master_obj->id == MASTER_OBJECT_ARTIFACT_DISCOVERY1) {
                            ++count;
                        }
                        node = node->next;
                    }
                    ++player;
                    --player_count;
                } while (player_count != 0);
            }
            missing = want - count;
            if (missing > 0)
                generator->add_quick_obj(10, missing, 0);
        }
        want = static_cast<T_Scenario*>(this->scenario)->Get_Multi_Ruins();
        if (want > 0) {
            int count = 0;
            int player_count = this->player_num;
            if (player_count > 0) {
                RGE_Player** player = this->players;
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
            missing = want - count;
            if (missing > 0)
                generator->add_quick_obj(0x9e, missing, 0);
        }

        if (!static_cast<TRIBE_Game*>(rge_base_game)->campaignGame()
            && static_cast<TRIBE_Game*>(rge_base_game)->randomGame()) {
            if (this->victory_type == 3 || debug_rand(world_source_file, 909) % 100 < 50) {
                generator->add_quick_obj(0x9f, 5, this->map->map_width / 5);
                this->artifact_count = 5;
            }
            if (debug_rand(world_source_file, 916) % 100 < 50) {
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
                        if (node->node->master_obj->id == MASTER_OBJECT_ARTIFACT1) {
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
            this->effects->do_effect(0x69, static_cast<TRIBE_Player*>(this->players[i]));
        }
    }
    if (static_cast<TRIBE_Game*>(rge_base_game)->longCombat() == 1) {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(0x64, static_cast<TRIBE_Player*>(this->players[i]));
        }
    }

    //! @bug This applies the civ tech-tree effect with no lower-bound guard on tribe_effect.
    //! A civ without a tech tree sends a negative id, and TRIBE_Effects::do_effect reads effects[-1].
    //! RGE_Player and TRIBE_Player check tribe_effect >= 0 before use.
    if (!static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree()
        && !static_cast<T_Scenario*>(this->scenario)->GetScenarioOption(2)) {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(
                static_cast<short>(this->players[i]->tribe_effect), static_cast<TRIBE_Player*>(this->players[i])
            );
        }
    } else {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(0xd2, static_cast<TRIBE_Player*>(this->players[i]));
        }
    }

    switch (static_cast<TRIBE_Game*>(rge_base_game)->resourceLevel()) {
        case TRIBE_Game::LowResources:
            for (i = 1; i < this->player_num; ++i) {
                this->players[i]->attributes[RGE_RESOURCE_FOOD] = 200.0f;
                this->players[i]->attributes[RGE_RESOURCE_WOOD] = 200.0f;
                this->players[i]->attributes[RGE_RESOURCE_GOLD] = 0.0f;
                this->players[i]->attributes[RGE_RESOURCE_STONE] = 100.0f;
            }
            break;
        case TRIBE_Game::MediumResources:
            for (i = 1; i < this->player_num; ++i) {
                this->players[i]->attributes[RGE_RESOURCE_FOOD] = 500.0f;
                this->players[i]->attributes[RGE_RESOURCE_WOOD] = 500.0f;
                this->players[i]->attributes[RGE_RESOURCE_GOLD] = 0.0f;
                this->players[i]->attributes[RGE_RESOURCE_STONE] = 250.0f;
            }
            break;
        case TRIBE_Game::HighResources:
            for (i = 1; i < this->player_num; ++i) {
                this->players[i]->attributes[RGE_RESOURCE_FOOD] = 1000.0f;
                this->players[i]->attributes[RGE_RESOURCE_WOOD] = 1000.0f;
                this->players[i]->attributes[RGE_RESOURCE_GOLD] = 0.0f;
                this->players[i]->attributes[RGE_RESOURCE_STONE] = 750.0f;
            }
            break;
    }

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch()) {
        for (i = 1; i < this->player_num; ++i) {
            this->players[i]->attributes[RGE_RESOURCE_FOOD] = 20000.0f;
            this->players[i]->attributes[RGE_RESOURCE_WOOD] = 20000.0f;
            this->players[i]->attributes[RGE_RESOURCE_GOLD] = 10000.0f;
            this->players[i]->attributes[RGE_RESOURCE_STONE] = 5000.0f;
        }
    }

    switch (static_cast<TRIBE_Game*>(rge_base_game)->startingAge()) {
        case TRIBE_Game::ToolAge:
            for (i = 1; i < this->player_num; ++i)
                static_cast<TRIBE_Player*>(this->players[i])->rev_tech(PLAYER_ATTRIBUTE_TOOL_AGE_TECH);
            break;
        case TRIBE_Game::BronzeAge:
            for (i = 1; i < this->player_num; ++i)
                static_cast<TRIBE_Player*>(this->players[i])->rev_tech(PLAYER_ATTRIBUTE_BRONZE_AGE_TECH);
            break;
        case TRIBE_Game::IronAge:
            for (i = 1; i < this->player_num; ++i)
                static_cast<TRIBE_Player*>(this->players[i])->rev_tech(PLAYER_ATTRIBUTE_IRON_AGE_TECH);
            break;
    }

    if (static_cast<TRIBE_Game*>(rge_base_game)->check_prog_argument(nofoodcap_argument)) {
        for (i = 1; i < this->player_num; ++i) {
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(PLAYER_ATTRIBUTE_POPULATION_LIMIT, 50.0f);
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(PLAYER_ATTRIBUTE_FOOD_MAINTENANCE, 0.0f);
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(0x1e, 500.0f);
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(0x1f, 5000.0f);
        }
    } else if (static_cast<TRIBE_Game*>(rge_base_game)->check_prog_argument(system2_argument)) {
        for (i = 1; i < this->player_num; ++i) {
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(PLAYER_ATTRIBUTE_POPULATION_LIMIT, 50.0f);
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(PLAYER_ATTRIBUTE_FOOD_MAINTENANCE, 0.0f);
        }
    } else {
        for (i = 1; i < this->player_num; ++i) {
            static_cast<TRIBE_Player*>(this->players[i])
                ->new_attribute_num(
                    PLAYER_ATTRIBUTE_POPULATION_LIMIT,
                    static_cast<float>(static_cast<TRIBE_Game*>(rge_base_game)->popLimit())
                );
            static_cast<TRIBE_Player*>(this->players[i])->new_attribute_num(PLAYER_ATTRIBUTE_FOOD_MAINTENANCE, 0.0f);
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
        }
    }

    return ret_num;
}

unsigned char TRIBE_World::new_scenario(RGE_Player_Info& info, int random_seed_in) {
    unsigned char result = RGE_Game_World::new_scenario(info, random_seed_in);
    int i = 1;
    if (this->player_num > 1) {
        do {
            ++i;
            this->players[i - 1]->attributes[RGE_RESOURCE_FOOD] = 200.0f;
            this->players[i - 1]->attributes[RGE_RESOURCE_WOOD] = 200.0f;
            this->players[i - 1]->attributes[RGE_RESOURCE_GOLD] = 0;
            this->players[i - 1]->attributes[RGE_RESOURCE_STONE] = 100.0f;
        } while (i < this->player_num);
    }
    return result;
}

unsigned char TRIBE_World::check_game_state() {
    int i;

    if (this->game_state == 0) {
        if (this->victory_type == 2 && this->countdown_victory != 0 && this->countdown_clock >= 1.0f) {
            this->countdown_clock -= this->world_time_delta_seconds * 2.0f;
            if (this->countdown_clock < 1.0f) {
                long team_score[9];
                for (i = 0; i < 9; ++i)
                    team_score[i] = -1;

                for (i = 1; i < this->player_num; ++i) {
                    int player_count = 1;
                    team_score[i] = this->players[i]->victory_conditions->get_victory_points();

                    if (this->players[i]->allied_victory != 0) {
                        for (int j = 1; j < this->player_num; ++j) {
                            if (j != i && this->players[i]->relation(j) == RGE_RELATION_ALLY
                                && this->players[j]->relation(i) == RGE_RELATION_ALLY
                                && this->players[j]->allied_victory != 0) {
                                team_score[i] += this->players[j]->victory_conditions->get_victory_points();
                                ++player_count;
                            }
                        }
                    }
                    team_score[i] /= player_count;
                }

                long high_score = -1;
                RGE_Player* high_player = 0;
                for (i = 1; i < this->player_num; ++i) {
                    if (team_score[i] > high_score) {
                        high_player = this->players[i];
                        high_score = team_score[i];
                    }
                }
                if (high_player != 0) {
                    high_player->win_game_now();
                    this->game_end_condition = 0x67;
                }
            }
        }

        if (this->artifact_count > 0 || this->ruin_count > 0) {
            int team_size[9];
            int player_team[9];
            TRIBE_Player* team_player[9][9];

            for (i = 0; i < this->player_num; ++i)
                team_size[i] = 0;

            for (i = 0; i < this->player_num; ++i)
                player_team[i] = -1;

            int team_count = 0;
            for (i = 1; i < this->player_num; ++i) {
                if (player_team[i] == -1) {
                    player_team[i] = team_count;
                    team_player[team_count][team_size[team_count]++] = static_cast<TRIBE_Player*>(this->players[i]);

                    if (this->players[i]->allied_victory != 0) {
                        for (int j = 1; j < this->player_num; ++j) {
                            if (player_team[j] == -1 && this->players[j]->allied_victory != 0
                                && this->players[i]->relation(j) == RGE_RELATION_ALLY
                                && this->players[j]->relation(i) == RGE_RELATION_ALLY) {
                                player_team[j] = team_count;
                                team_player[team_count][team_size[team_count]++] =
                                    static_cast<TRIBE_Player*>(this->players[j]);
                            }
                        }
                    }
                    ++team_count;
                }
            }

            if (this->artifact_count > 0 && team_count > 0) {
                for (i = 0; i < team_count; ++i) {
                    int total = 0;
                    int j;
                    for (j = 0; j < team_size[i]; ++j)
                        total += static_cast<int>(team_player[i][j]->attributes[PLAYER_ATTRIBUTE_ARTIFACTS]);

                    TRIBE_Player* first_player = team_player[i][0];
                    if (total == this->artifact_count) {
                        float held_time = first_player->artifact_held_time;
                        if (held_time == -1.0f) {
                            for (j = 0; j < team_size[i]; ++j)
                                team_player[i][j]->attributes[PLAYER_ATTRIBUTE_ALL_ARTIFACTS] = 1.0f;

                            if (this->victory_type == 0) {
                                for (j = 0; j < team_size[i]; ++j)
                                    team_player[i][j]->artifact_held_time = 2000.0f;
                                rge_base_game->notification(GAME_NOTIFY_ARTIFACTS_CAPTURED, first_player->id, 0, 0, 0);
                            }
                        } else if (held_time >= 1.0f && this->victory_type == 0) {
                            held_time -= this->world_time_delta_seconds * 2.0f;
                            for (j = 0; j < team_size[i]; ++j)
                                team_player[i][j]->artifact_held_time = held_time;
                            if (held_time < 1.0f) {
                                first_player->win_game_now();
                                this->game_end_condition = 0x65;
                            }
                        }
                    } else if (first_player->artifact_held_time != -1.0f) {
                        for (j = 0; j < team_size[i]; ++j)
                            team_player[i][j]->attributes[PLAYER_ATTRIBUTE_ALL_ARTIFACTS] = 0.0f;

                        if (this->victory_type == 0) {
                            for (j = 0; j < team_size[i]; ++j)
                                team_player[i][j]->artifact_held_time = -1.0f;
                            rge_base_game->notification(GAME_NOTIFY_ARTIFACTS_LOST, first_player->id, 0, 0, 0);
                        }
                    }
                }
            }

            if (this->ruin_count > 0 && team_count > 0) {
                for (i = 0; i < team_count; ++i) {
                    int total = 0;
                    int j;
                    for (j = 0; j < team_size[i]; ++j)
                        total += static_cast<int>(team_player[i][j]->attributes[PLAYER_ATTRIBUTE_RUINS]);

                    TRIBE_Player* first_player = team_player[i][0];
                    if (total == this->ruin_count) {
                        float held_time = first_player->ruin_held_time;
                        if (held_time == -1.0f) {
                            for (j = 0; j < team_size[i]; ++j)
                                team_player[i][j]->attributes[PLAYER_ATTRIBUTE_ALL_RUINS] = 1.0f;

                            if (this->victory_type == 0) {
                                for (j = 0; j < team_size[i]; ++j)
                                    team_player[i][j]->ruin_held_time = 2000.0f;
                                rge_base_game->notification(GAME_NOTIFY_RUINS_CAPTURED, first_player->id, 0, 0, 0);
                            }
                        } else if (held_time >= 1.0f && this->victory_type == 0) {
                            held_time -= this->world_time_delta_seconds * 2.0f;
                            for (j = 0; j < team_size[i]; ++j)
                                team_player[i][j]->ruin_held_time = held_time;
                            if (held_time < 1.0f) {
                                first_player->win_game_now();
                                this->game_end_condition = 0x66;
                            }
                        }
                    } else if (first_player->ruin_held_time != -1.0f) {
                        for (j = 0; j < team_size[i]; ++j)
                            team_player[i][j]->attributes[PLAYER_ATTRIBUTE_ALL_RUINS] = 0.0f;

                        if (this->victory_type == 0) {
                            for (j = 0; j < team_size[i]; ++j)
                                team_player[i][j]->ruin_held_time = -1.0f;
                            rge_base_game->notification(GAME_NOTIFY_RUINS_LOST, first_player->id, 0, 0, 0);
                        }
                    }
                }
            }
        }
    }

    return RGE_Game_World::check_game_state();
}

long TRIBE_World::get_achievement(unsigned char achievement, char** info) {
    int player = 1;

    if (this->player_num > 1) {
        do {
            TRIBE_Player* p = static_cast<TRIBE_Player*>(this->players[player]);
            if (p != 0) {
                p->get_achievement(achievement, info[player]);
            }
            player++;
        } while (player < this->player_num);
    }

    return this->player_num;
}

void TRIBE_World::send_cheat(short cheat_code) {
    static_cast<TRIBE_Command*>(this->commands)->command_cheat(this->curr_player, cheat_code);
}

void TRIBE_World::cheat(short player, short cheat_code) {
    if (rge_base_game->allowCheatCodes() != 0) {
        switch (cheat_code) {
            case 0:
                if (player > 0) {
                    RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                        0x6d, -1.0f, -1.0f, 1, RGE_OBJECT_STATE_ACTIVE, 0
                    );
                    if (object != 0)
                        static_cast<TRIBE_Command*>(this->commands)->command_make(object, 0x112);
                }
                break;
            case 1:
                if (player > 0) {
                    RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                        0x6d, -1.0f, -1.0f, 1, RGE_OBJECT_STATE_ACTIVE, 0
                    );
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
                        0x6d, -1.0f, -1.0f, 1, RGE_OBJECT_STATE_ACTIVE, 0
                    );
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
                        0x6d, -1.0f, -1.0f, 1, RGE_OBJECT_STATE_ACTIVE, 0
                    );
                    if (object != 0)
                        static_cast<TRIBE_Command*>(this->commands)->command_make(object, 0x18d);
                }
                break;
            case 17:
                if (player > 0)
                    this->players[player]->objects->find_by_master_id(
                        0x6d, -1.0f, -1.0f, 1, RGE_OBJECT_STATE_ACTIVE, 0
                    );
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
                        if (i != player || this->players[player]->isAlly(i) == 0
                            || this->players[i]->isAlly(player) == 0) {
                            RGE_Object_Node* node = this->players[i]->objects->list;
                            while (node != 0) {
                                RGE_Static_Object* object = node->node;
                                if (object->object_state < RGE_OBJECT_STATE_DYING
                                    && object->master_obj->object_group != OBJECT_GROUP_ARTIFACT)
                                    object->die_die_die();
                                node = node->next;
                            }
                        }
                        ++i;
                    } while (i < this->player_num);
                }
                break;
            }
            case 101: {
                RGE_Object_Node* node = this->players[player]->objects->list;
                while (node != 0) {
                    RGE_Static_Object* object = node->node;
                    if (object->object_state < RGE_OBJECT_STATE_DYING
                        && object->master_obj->object_group != OBJECT_GROUP_ARTIFACT)
                        object->die_die_die();
                    node = node->next;
                }
            } break;
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
                if ((other_player != player || this->players[player]->isAlly(other_player) == 0
                     || this->players[other_player]->isAlly(player) == 0)
                    && this->players[other_player]->objects->list != 0) {
                    RGE_Object_Node* node = this->players[other_player]->objects->list;
                    while (node != 0) {
                        RGE_Static_Object* object = node->node;
                        if (object->object_state < RGE_OBJECT_STATE_DYING
                            && object->master_obj->object_group != OBJECT_GROUP_ARTIFACT)
                            object->die_die_die();
                        node = node->next;
                    }
                }
                break;
            }
            case 220: {
                RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, RGE_OBJECT_STATE_ACTIVE, 0
                );
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

void TRIBE_World::fill_in_score(TRIBE_Zone_High_Score_Info& info, long score_group) {
    int player = 1;
    long high_score = 0;
    int hi_player = 1;

    if (1 < this->player_num) {
        do {
            if (this->players[player]->computerPlayer() == 0) {
                if (this->players[player]->victory_conditions->get_victory_points_group(
                        static_cast<unsigned char>(score_group)
                    )
                    > high_score) {
                    high_score = this->players[player]->victory_conditions->get_victory_points_group(
                        static_cast<unsigned char>(score_group)
                    );
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
            if ((player != hi_player) && (this->players[player]->relation(hi_player) == RGE_RELATION_ALLY)
                && (this->players[hi_player]->relation(player) == RGE_RELATION_ALLY)) {
                count++;
            }
            player++;
        } while (player < this->player_num);
    }
    info.num_allies = static_cast<unsigned char>(count);
}

void TRIBE_World::send_zone_score_info() {
    TRIBE_Zone_Info info;
    TRIBE_Game::TRIBE_Game_Options options;
    int count = 0;
    int index;

    if (this->sent_zone_score == 0) {
        this->sent_zone_score = 1;
        info.number_of_players = 0;
        count = 0;
        index = 1;
        if (index < this->player_num) {
            do {
                if (this->players[index]->computerPlayer() == 0)
                    info.number_of_players++;
                else
                    count++;
                index++;
            } while (index < this->player_num);
        }
        info.number_of_computer_players = static_cast<unsigned char>(count);

        strcpy(info.scenario_name, this->scenario->Get_scenario_name());
        info.game_time = this->world_time / 1000;

        this->fill_in_score(info.total_score, 0xFF);
        this->fill_in_score(info.religion_score, 2);
        this->fill_in_score(info.economy_score, 1);
        this->fill_in_score(info.combat_score, 0);
        this->fill_in_score(info.research_score, 3);

        index = 1;
        if (index < this->player_num) {
            do {
                strcpy(info.player_info[index - 1].name, this->players[index]->name);
                info.player_info[index - 1].score = this->players[index]->victory_conditions->get_victory_points();
                info.player_info[index - 1].winner = (this->players[index]->game_status == 1);
                info.player_info[index - 1].civ_played =
                    static_cast<unsigned char>(static_cast<TRIBE_Game*>(rge_base_game)->civilization(index - 1));
                info.player_info[index - 1].civ_random =
                    static_cast<unsigned char>(static_cast<TRIBE_Game*>(rge_base_game)->random_civ[index - 1]);
                info.player_info[index - 1].player_no =
                    static_cast<unsigned char>(static_cast<TRIBE_Game*>(rge_base_game)->playerColor(index - 1));
                info.player_info[index - 1].team_no =
                    static_cast<unsigned char>(static_cast<TRIBE_Game*>(rge_base_game)->playerTeam(index - 1));
                int game_outcome = comm->WasKicked[index - 1];
                info.player_info[index - 1].game_outcome = static_cast<unsigned char>(game_outcome);
                info.player_info[index - 1].tool_time = -1;
                info.player_info[index - 1].bronze_time = -1;
                info.player_info[index - 1].iron_time = -1;

                TRIBE_History_Events* event = static_cast<TRIBE_Player*>(this->players[index])->history->events;
                while (event != 0) {
                    switch (event->event) {
                        case 0:
                            info.player_info[index - 1].tool_time = event->world_time;
                            break;
                        case 1:
                            info.player_info[index - 1].bronze_time = event->world_time;
                            break;
                        case 2:
                            info.player_info[index - 1].iron_time = event->world_time;
                            break;
                    }
                    event = event->next;
                }
                index++;
            } while (index < this->player_num);
        }

        info.cheats_enabled = static_cast<unsigned char>(static_cast<TRIBE_Game*>(rge_base_game)->allowCheatCodes());
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
        info.map_info.Reveal_Map =
            static_cast<unsigned char>(static_cast<TRIBE_Game*>(rge_base_game)->fullVisibility());
        info.map_info.Death_Match = options.deathMatchValue;
        info.map_info.Pop_Limit = static_cast<short>(options.popLimitValue);

        info.database_checksum = 0;
        info.code_checksum = 0;
        info.program_version = 0;

        this->commands->com_hand->SendZoneMessage(static_cast<char*>(static_cast<void*>(&info)), 0x1fc);
    }
}
