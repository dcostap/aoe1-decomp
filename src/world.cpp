
#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/world.h"
#include "../include/world_info.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/move_obj.h"
#include "../include/obj_list.h"
#include "../include/mst_play.h"
#include "../include/com_hand.h"
#include "../include/effects.h"
#include "../include/victory.h"
#include "../include/basegame.h"
#include "../include/main.h"
#include "../include/scenario.h"
#include "../include/gameinfo.h"
#include "../include/Command.h"
#include "../include/sound.h"
#include "../include/sprite.h"
#include "../include/color.h"
#include "../include/Mouseptr.h"
#include "../include/pathsys.h"
#include "../include/panel.h"
#include "../include/dpl_obj.h"
#include "../include/visible.h"
#include "../include/vis_unit.h"
#include "../include/debuglog.h"
#include "../include/game_globals.h"
#include "../include/rge_base_game_global.h"
#include "../include/rge_fio.h"

static const char version_101[] = "1.01";
static const char version_102[] = "1.02";
static const char version_103[] = "1.03";
static const char version_104[] = "1.04";
static const char version_105[] = "1.05";
static const char version_106[] = "1.06";
static const char version_107[] = "1.07";
static const char version_108[] = "1.08";
static const char version_109[] = "1.09";
static const char version_110[] = "1.10";
static const char version_111[] = "1.11";
static const char world_data_format[] =
    "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %hd %hd %hd";
static char base_save_version[] = "VER 3.7";

void __cdecl debug_random_reset();
int __cdecl debug_rand(char*, int);
void __cdecl debug_srand(char*, int, unsigned int);
unsigned long __cdecl debug_timeGetTime(char*, int);

RGE_Game_World::RGE_Game_World()
    : objectsValue(0),
      numberObjectsValue(0),
      maxNumberObjectsValue(10000),
      negativeObjectsValue(0),
      numberNegativeObjectsValue(0),
      maxNumberNegativeObjectsValue(1000),
      maximumComputerPlayerUpdateTime(2),
      availableComputerPlayerUpdateTime(2),
      currentUpdateComputerPlayer(-1),
      difficultyLevelValue(-1)
{
    world_update_counter = 0;
    objectsValue = new RGE_Static_Object*[maxNumberObjectsValue];
    negativeObjectsValue = new RGE_Static_Object*[maxNumberNegativeObjectsValue];
    VIS_UNIT_objectsValue = objectsValue;
    playbook = 0;
    sound_num = 0;
    sounds = 0;
    sprite_num = 0;
    sprites = 0;
    player_num = 0;
    players = 0;
    master_player_num = 0;
    master_players = 0;
    terrain_num = 0;
    terrains = 0;
    color_table_num = 0;
    color_tables = 0;
    commands = 0;
    scenario = 0;
    effects = 0;
    map = 0;
    world_time = 0;
    old_world_time = 0;
    world_time_delta = 0;
    world_time_delta_seconds = 0;
    timer = 0;
    old_time = 0;
    game_speed = 0;
    temp_pause = 0;
    next_object_id = 0;
    next_reusable_object_id = -1;
    random_seed = 14;
    curr_player = 1;
    sound_driver = 0;
    game_state = 2;
    game_end_condition = 0;
    sound_update_index = 0;
    sprite_update_index = 0;
    player_turn = 0;
    for (int i = 0; i < 9; i++) {
        player_time_delta[i] = 0;
    }
    reusable_static_objects = new RGE_Object_List;
    reusable_animated_objects = new RGE_Object_List;
    reusable_moving_objects = new RGE_Object_List;
    reusable_action_objects = new RGE_Object_List;
    reusable_combat_objects = new RGE_Object_List;
    reusable_missile_objects = new RGE_Object_List;
    reusable_doppleganger_objects = new RGE_Object_List;
    scenario_object_flag = 0;
    if (DVlogf == 0) {
        DVlogf = fopen("c:\\aoeWVlog.txt", "w");
    }
}

RGE_Game_World::~RGE_Game_World()
{
    delete this->commands;
    this->del_game_info();

    delete this->reusable_static_objects;
    delete this->reusable_animated_objects;
    delete this->reusable_moving_objects;
    delete this->reusable_action_objects;
    delete this->reusable_combat_objects;
    delete this->reusable_missile_objects;
    delete this->reusable_doppleganger_objects;

    if (this->master_players != 0) {
        for (int i = 0; i < this->master_player_num; i++) {
            if (this->master_players[i] != 0) {
                delete this->master_players[i];
                this->master_players[i] = 0;
            }
        }
        free(this->master_players);
        this->master_players = 0;
    }

    if (this->effects != 0) {
        delete this->effects;
        this->effects = 0;
    }

    if (this->map != 0) {
        delete this->map;
        this->map = 0;
    }

    if (this->sprites != 0) {
        for (int i = 0; i < this->sprite_num; i++) {
            if (this->sprites[i] != 0) {
                delete this->sprites[i];
            }
        }
        free(this->sprites);
        this->sprites = 0;
    }

    if (this->sounds != 0) {
        for (int i = 0; i < this->sound_num; i++) {
            if (this->sounds[i] != 0) {
                delete this->sounds[i];
            }
        }
        free(this->sounds);
        this->sounds = 0;
    }

    if (this->terrains != 0) {
        for (int i = 0; i < this->terrain_num; i++) {
            if (this->terrains[i] != 0) {
                free(this->terrains[i]);
            }
        }
        free(this->terrains);
        this->terrains = 0;
    }

    if (this->color_tables != 0) {
        for (int i = 0; i < this->color_table_num; i++) {
            if (this->color_tables[i] != 0) {
                delete this->color_tables[i];
            }
        }
        free(this->color_tables);
        this->color_tables = 0;
    }

    if (this->objectsValue != 0) {
        delete[] this->objectsValue;
        this->objectsValue = 0;
        VIS_UNIT_objectsValue = 0;
    }

    if (this->negativeObjectsValue != 0) {
        delete[] this->negativeObjectsValue;
        this->negativeObjectsValue = 0;
    }

    if (logStatusFile != 0) {
        fclose(logStatusFile);
        logStatusFile = 0;
    }

    if (this->playbook != 0) {
        delete this->playbook;
        this->playbook = 0;
    }

    if (DVlogf != 0) {
        fclose(DVlogf);
        DVlogf = 0;
    }
}

void RGE_Game_World::reset_object_count() {
    this->world_time = 0;
    this->old_world_time = 0;
    this->world_time_delta = 0;
    this->world_time_delta_seconds = 0.0f;
    this->timer = 0.0f;
    this->old_time = 0;
    this->temp_pause = 0;
    this->next_object_id = 0;
    this->player_turn = 0;

    for (int i = 0; i < 9; ++i) {
        this->player_time_delta[i] = 0;
    }
}

void RGE_Game_World::pause(unsigned char paused) {
    int i;

    if (paused != 0) {
        i = 0;
        if (this->sound_num > 0) {
            do {
                this->sounds[i]->stop();
                i = i + 1;
            } while (i < this->sound_num);
        }
    }
}

void RGE_Game_World::set_map_visible(unsigned char param) {
    if (this->map)
        this->map->set_map_visible(param);
}

void RGE_Game_World::set_map_fog(unsigned char param) {
    if (this->map)
        this->map->set_map_fog(param);
}

unsigned char RGE_Game_World::data_load_sounds(char* name) {
    FILE* fp = fopen(name, "r");
    if (fp != 0) {
        short count;
        short i;
        short index;
        int result;
        result = fscanf(fp, "%hd %hd", &this->sound_num, &count);
        if (result != -1) {
            this->sounds = (RGE_Sound**)calloc(this->sound_num, 4);
            for (i = 0; i < count; i++) {
                if (fscanf(fp, "%hd", &index) != -1) {
                    RGE_Sound* s = new RGE_Sound(fp, index);
                    this->sounds[index] = s;
                }
            }
        } else {
            this->sound_num = 0;
            this->sounds = 0;
        }
        fclose(fp);
    }
    return 1;
}

unsigned char RGE_Game_World::data_load_terrain_tables(char* filename)
{
    FILE* f = fopen(filename, "r");
    if (f != 0) {
        if (fscanf(f, "%hd %hd", &this->terrain_num, &this->terrain_size) != -1) {
            this->terrains = (float**)calloc(this->terrain_num, 4);

            short outer = 0;
            if (outer < this->terrain_num) {
                do {
                    short type;
                    short index;

                    if (fscanf(f, "%hd %hd", &type, &index) != -1) {
                        this->terrains[type] = (float*)calloc(this->terrain_size, 4);

                        short si = 0;
                        if (si < index) {
                            do {
                                short local_6;
                                fscanf(f, "%hd", &local_6);
                                fscanf(f, "%f", &this->terrains[type][local_6]);
                                ++si;
                            } while (si < index);
                        }
                    }

                    ++outer;
                } while (outer < this->terrain_num);
            }
        } else {
            this->terrain_num = 0;
            this->terrains = 0;
        }

        fclose(f);
    }
    return 1;
}

uchar RGE_Game_World::data_load_color_tables(char* filename)
{
    short count;
    FILE* f = fopen(filename, "r");
    if (f == NULL)
        goto epilogue;

    if (fscanf(f, "%hd %hd", &this->color_table_num, &count) != -1) {
        this->color_tables = (RGE_Color_Table**)calloc(this->color_table_num, 4);
        for (short i = 0; i < count; i++) {
            short index;
            if (fscanf(f, "%hd", &index) != -1) {
                RGE_Color_Table* ct = new RGE_Color_Table(f, index);
                this->color_tables[index] = ct;
            }
        }
    } else {
        this->color_table_num = 0;
        this->color_tables = NULL;
    }

    fclose(f);

epilogue:
    return 1;
}

unsigned char RGE_Game_World::data_load_sprites(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file != 0) {
        short file_sprite_count;
        short i;
        short id;

        if (fscanf(file, "%hd %hd", &this->sprite_num, &file_sprite_count) != -1) {
            this->sprites = (RGE_Sprite**)calloc(this->sprite_num, 4);

            for (i = 0; i < file_sprite_count; i++) {
                if (fscanf(file, "%hd", &id) != -1) {
                    RGE_Sprite* sprite = new RGE_Sprite(file, id, this->sounds);
                    this->sprites[id] = sprite;
                }
            }

            for (i = 0; i < file_sprite_count; i++) {
                if (this->sprites[i] == 0) {
                    RGE_Sprite* sprite = new RGE_Sprite(i);
                    this->sprites[i] = sprite;
                }
            }
        } else {
            this->sprite_num = 0;
            this->sprites = 0;
        }
        fclose(file);
    }
    return 1;
}

void RGE_Game_World::data_load_players_type(short player_id, short flag, FILE* file) {
    if (flag == 0) {
        this->master_players[player_id] = new RGE_Master_Player(file);
    }
}

unsigned char RGE_Game_World::data_load_players(char* param_1) {
    FILE* fp;
    short master_player_count;
    short type;
    short id;

    fp = fopen(param_1, "r");
    if (fp == NULL)
        goto done;

    if (fscanf(fp, "%hd %hd", &this->master_player_num, &master_player_count) != -1) {
        this->master_players = (RGE_Master_Player**)calloc(this->master_player_num, 4);
        for (short i = 0; i < master_player_count; i++) {
            if (fscanf(fp, "%hd %hd", &type, &id) != -1) {
                this->data_load_players_type(type, id, fp);
            }
        }
        fclose(fp);
        return 1;
    }

    this->master_player_num = 0;
    this->master_players = 0;
    fclose(fp);

done:
    return 1;
}

unsigned char RGE_Game_World::data_load_objects(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp != 0) {
        short player_count;
        short object_id;
        short player_idx;
        short master_player_index;
        if (fscanf(fp, "%hd", &player_count) != -1 && (player_idx = 0, player_count > 0)) {
            do {
                if (fscanf(fp, "%hd", &master_player_index) != -1) {
                    fscanf(fp, "%hd", &object_id);
                    master_players[master_player_index]->create_master_object_space(object_id);

                    fscanf(fp, "%hd", &object_id);
                    short j = 0;
                    if (j < object_id) {
                        short v1, v2;
                        do {
                            if (fscanf(fp, "%hd %hd", &v2, &v1) != -1) {
                                master_players[master_player_index]->load_object(fp, v2, sprites, sounds, v1);
                            }
                            ++j;
                        } while (j < object_id);
                    }
                }
                ++player_idx;
            } while (player_idx < player_count);
        }

        fclose(fp);
    }
    return 1;
}

void RGE_Game_World::data_load_effects(char* filename) {
    RGE_Effects* e;
    e = new RGE_Effects(filename);
    this->effects = e;
}

void RGE_Game_World::data_load_map(char* p1, char* p2, char* p3, char* p4, short p5, short p6, short p7, RGE_Sound** p8, char* p9) {
    RGE_Map* m;

    m = new RGE_Map(p1, p3, p4, p5, p6, p7, p8);
    this->map = m;
    m->load_terrain_obj_types(p9);
}

void RGE_Game_World::data_load_random_map(char* a, char* b, char* c, char* d) {
    this->map->load_random_map(a, b, c, d);
}

unsigned char RGE_Game_World::data_load_world(FILE* file) {
    short elev_height;
    short tile_width;
    short tile_height;
    char effects_file[23];
    char map_file[23];
    char color_file[23];
    char terrain_file[23];
    char sprite_file[23];
    char overlay_file[23];
    char object_file[23];
    char border_file[23];
    char terrain_object_file[23];
    char rmm_object_file[23];
    char player_file[23];
    char rmm_terrain_file[23];
    char sound_file[23];
    char rmm_land_file[23];
    char terrain_table_file[23];
    char rmm_map_file[23];

    fscanf(file, world_data_format,
        terrain_table_file + 4, color_file + 4, sound_file + 4,
        border_file + 4, overlay_file + 4, terrain_file + 4, map_file + 4,
        sprite_file + 4, player_file + 4, object_file + 4, effects_file + 4,
        terrain_object_file + 4, rmm_map_file + 4, rmm_land_file + 4,
        rmm_terrain_file + 4, rmm_object_file + 4, &tile_height,
        &elev_height, &tile_width);

    this->data_load_terrain_tables(terrain_table_file + 4);
    this->data_load_color_tables(color_file + 4);
    this->data_load_sounds(sound_file + 4);
    this->data_load_sprites(sprite_file + 4);
    this->data_load_players(player_file + 4);
    this->data_load_objects(object_file + 4);
    this->data_load_effects(effects_file + 4);
    this->data_load_map(border_file + 4, overlay_file + 4, terrain_file + 4,
        map_file + 4, tile_height, elev_height, tile_width, this->sounds,
        terrain_object_file + 4);
    this->data_load_random_map(rmm_map_file + 4, rmm_land_file + 4,
        rmm_terrain_file + 4, rmm_object_file + 4);
    return 1;
}

unsigned char RGE_Game_World::data_load(char* param_1, char* param_2) {
    FILE* f = fopen(param_2, "r");
    if (f != 0) {
        this->data_load_world(f);
        fclose(f);
        this->base_save(param_1);
        return 1;
    }
    return 0;
}

unsigned char RGE_Game_World::init_player_type(int param_1, short param_2, unsigned char param_3) {
    if (param_3 == 0) {
        this->master_players[param_2] = new RGE_Master_Player(param_1);
        this->master_players[param_2]->finish_init(param_1, this->sprites, this->sounds);
    }
    return 1;
}

unsigned char RGE_Game_World::init_player(int fileHandle) {
    rge_read(fileHandle, &this->master_player_num, 2);

    if (this->master_player_num > 0) {
        this->master_players = (RGE_Master_Player**)calloc(this->master_player_num, 4);
        for (int i = 0; (short)i < this->master_player_num; i++) {
            unsigned char tempByte;
            rge_read(fileHandle, &tempByte, 1);
            this->init_player_type(fileHandle, (short)i, tempByte);
        }
    }
    return 1;
}

void RGE_Game_World::terrain_tables_init(int fd) {
    rge_read(fd, &terrain_num, 2);
    rge_read(fd, &terrain_size, 2);

    if (terrain_num > 0 && terrain_size > 0) {
        terrains = (float**)calloc(terrain_num, 4);
        rge_read(fd, terrains, terrain_num * 4);

        for (int i = 0; i < terrain_num; i++) {
            if (terrains[i] != 0) {
                terrains[i] = (float*)calloc(terrain_size, 4);
                rge_read(fd, terrains[i], terrain_size * 4);
            }
        }
    }
}

void RGE_Game_World::color_table_init(int fd) {
    rge_read(fd, &color_table_num, 2);

    if (color_table_num > 0) {
        color_tables = (RGE_Color_Table**)calloc(color_table_num, 4);
        for (int i = 0; i < color_table_num; i++) {
            color_tables[i] = new RGE_Color_Table(fd);
        }
    }
}

void RGE_Game_World::init_sounds(int param_1, TSound_Driver* param_2)
{
    rge_read(param_1, &this->sound_num, 2);
    this->sounds = (RGE_Sound**)calloc(this->sound_num, 4);
    for (int i = 0; i < this->sound_num; i++) {
        this->sounds[i] = new RGE_Sound(param_1, this->sound_driver);
    }
}

void RGE_Game_World::init_sprites(int param_1)
{
    rge_read(param_1, &sprite_num, 2);

    sprites = (RGE_Sprite**)calloc(sprite_num, 4);

    rge_read(param_1, sprites, sprite_num * 4);

    for (int ii = 0; ii < sprite_num; ii++) {
        if (sprites[ii]) {
            sprites[ii] = new RGE_Sprite(param_1, sounds, color_tables);
        }
    }

    for (int j = 0; j < sprite_num; j++) {
        if (sprites[j]) {
            sprites[j]->rehook(sprites);
        }
    }
}

void RGE_Game_World::scenario_init(int param1, RGE_Game_World* param2) {
    RGE_Scenario* p = new RGE_Scenario(param1, param2);
    if (p == 0) {
        p = 0;
    }
    scenario = p;
}

void RGE_Game_World::scenario_init(RGE_Game_World* param_1) {
    RGE_Scenario* s = new RGE_Scenario(param_1);
    if (s == 0) {
        s = 0;
    }
    this->scenario = s;
}

void RGE_Game_World::map_init(int param_1, TSound_Driver* param_2) {
    RGE_Map* new_map = new RGE_Map(param_1, this->sounds, 1);
    if (new_map == 0) {
        new_map = 0;
    }
    this->map = new_map;
}

void RGE_Game_World::effects_init(int param_1) {
    RGE_Effects* e = new RGE_Effects(param_1);
    if (e == 0) { e = 0; }
    this->effects = e;
}

void RGE_Game_World::master_player_init(int val) {
    this->init_player(val);
}

void RGE_Game_World::command_init(int param1, TCommunications_Handler* param2) {
    RGE_Command* p = new RGE_Command(this, param2);
    this->commands = p;
}

void RGE_Game_World::world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) {
    this->terrain_tables_init(param_1);
    this->color_table_init(param_1);
    this->init_sounds(param_1, param_2);
    this->init_sprites(param_1);
    this->map_init(param_1, param_2);
    this->effects_init(param_1);
    this->master_player_init(param_1);
    this->command_init(param_1, param_3);
}

unsigned char RGE_Game_World::init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) {
    char version[8];

    this->sound_driver = param_2;
    this->next_object_id = 0;

    int fd = rge_open(param_1, 0x8000);
    if (fd != -1) {
        rge_read(fd, version, 8);

        if (strcmp(version, "VER 3.7") != 0) {
            rge_close(fd);
            return 0;
        }

        this->world_init(fd, param_2, param_3);
        rge_close(fd);
        return 1;
    }

    return 0;
}

void RGE_Game_World::turn_sound_off(void) {
    int i = 0;
    if (0 < this->sound_num) {
        do {
            this->sounds[i]->stop();
            ++i;
        } while (i < this->sound_num);
    }
}

void RGE_Game_World::reset_communications(TCommunications_Handler* communications) {
    this->commands->reset_communications(communications);
}

void RGE_Game_World::reset_player_visible_maps(void) {
    int i = 0;

    if (i < this->player_num) {
        do {
            if (this->players[i] != 0) {
                this->players[i]->remake_visible_map();
            }
            i = i + 1;
        } while (i < this->player_num);
    }
}

void RGE_Game_World::del_game_info()
{
    int i;
    world_update_counter = 0;

    this->game_state = 2;
    this->game_end_condition = 0;
    this->reusable_static_objects->removeAllObjects();
    this->reusable_animated_objects->removeAllObjects();
    this->reusable_moving_objects->removeAllObjects();
    this->reusable_action_objects->removeAllObjects();
    this->reusable_combat_objects->removeAllObjects();
    this->reusable_missile_objects->removeAllObjects();
    this->reusable_doppleganger_objects->removeAllObjects();

    this->next_reusable_object_id = -1;
    this->campaign = -1;
    this->campaign_player = -1;
    this->campaign_scenario = -1;
    this->difficultyLevelValue = -1;
    this->next_object_id = 0;

    i = 0;
    if (this->maxNumberObjectsValue > 0) {
        do {
            this->objectsValue[i] = 0;
            i++;
        } while (i < this->maxNumberObjectsValue);
    }

    i = 0;
    if (this->maxNumberNegativeObjectsValue > 0) {
        do {
            this->negativeObjectsValue[i] = 0;
            i++;
        } while (i < this->maxNumberNegativeObjectsValue);
    }

    this->turn_sound_off();

    if (this->scenario != 0) {
        delete this->scenario;
        this->scenario = 0;
    }

    short num = this->player_num;
    if (num > 0 && this->players != 0) {
        for (i = 0; i < this->player_num; i++) {
            if (this->players[i] != 0) {
                this->players[i]->destroy_objects();
            }
        }
    }

    num = this->player_num;
    if (num > 0 && this->players != 0) {
        for (i = 0; i < this->player_num; i++) {
            if (this->players[i] != 0) {
                delete this->players[i];
                this->players[i] = 0;
            }
        }
        this->player_num = 0;
        free(this->players);
        this->players = 0;
    }

    this->next_object_id = 0;
    this->sound_update_index = 0;
    this->sprite_update_index = 0;
    this->player_turn = 0;
    for (i = 0; i < 9; i++) {
        this->player_time_delta[i] = 0;
    }
}

void RGE_Game_World::load_player(int param_1, unsigned char param_2, short param_3) {
    RGE_Game_World* self = this;
    if (param_2 != 0)
        return;

    RGE_Player* player = new RGE_Player(param_1, self, param_3);
    self->players[param_3] = player;
    self->players[param_3]->load(param_1);
}

unsigned char RGE_Game_World::load_world(int file) {
    int i;
    unsigned long* p;
    int count;
    int player_type;
    int f = file;
    unsigned char saved_game_state;

    this->game_state = 2;
    this->game_end_condition = 0;
    rge_read(f, &this->world_time, 4);
    rge_read(f, &this->old_world_time, 4);
    rge_read(f, &this->world_time_delta, 4);
    rge_read(f, &this->world_time_delta_seconds, 4);
    rge_read(f, &this->timer, 4);
    rge_read(f, &this->game_speed, 4);
    rge_read(f, &this->temp_pause, 1);
    rge_read(f, &this->next_object_id, 4);
    rge_read(f, &this->next_reusable_object_id, 4);
    rge_read(f, &this->random_seed, 4);
    rge_read(f, &this->curr_player, 2);

    rge_read(f, &this->player_num, 2);
    rge_read(f, &saved_game_state, 1);
    rge_read(f, &this->campaign, 4);
    rge_read(f, &this->campaign_player, 4);
    rge_read(f, &this->campaign_scenario, 4);
    rge_read(f, &this->player_turn, 4);

    p = this->player_time_delta;
    count = 9;
    do {
        rge_read(f, p, 4);
        p++;
        count--;
    } while (count != 0);

    i = 0;
    this->old_time = 0;
    this->map->load_map(f);
    this->initializePathingSystem();
    this->currentUpdateComputerPlayer = -1;

    if (0 < this->player_num) {
        this->players = (RGE_Player**)calloc(4, this->player_num);
        if (0 < this->player_num) {
            do {
                rge_read(f, &player_type, 1);
                this->load_player(f, player_type, (short)i);
                i++;
            } while (i < this->player_num);
        }
    }

    this->update_mutual_allies();
    this->map->unified_vis_map->suppress_updates(1);
    i = 0;
    if (0 < this->player_num) {
        do {
            this->players[i]->load_info(f);
            i++;
        } while (i < this->player_num);
    }
    this->map->unified_vis_map->suppress_updates(0);
    this->scenario_init(f, this);

    if (save_game_version >= DAT_00577a10) {
        rge_read(f, &this->difficultyLevelValue, 4);
    } else {
        this->difficultyLevelValue = -1;
    }
    if (rge_base_game->singlePlayerGame()) {
        this->game_speed = rge_base_game->get_game_speed();
    }
    this->game_state = saved_game_state;
    return 1;
}

unsigned char RGE_Game_World::load_game(char* param_1)
{
    char buf[308];

    world_update_counter = 0;

    this->del_game_info();

    sprintf(buf + 8, "%s%s", rge_base_game->prog_info->save_dir, param_1);

    int fh = rge_open(buf + 8, 0x8000);
    if (fh != -1) {
        rge_read(fh, buf, 8);
        rge_read(fh, &save_game_version, 4);

        if (strcmp(buf, "VER 8.6") != 0) {
            rge_close(fh);
            return 0;
        }

        this->load_world(fh);
        rge_close(fh);
        return 1;
    }
    return 0;
}

void RGE_Game_World::set_game_speed(float v) { this->game_speed = v; }

void RGE_Game_World::setup_gaia() {
    RGE_Player* p = new RGE_Player(this, *master_players, 0, "GAIA", 0, 1);
    if (p == 0) {
        p = 0;
    }
    *players = p;
}

void RGE_Game_World::setup_players(RGE_Player_Info& info) {
    short index = 1;

    if (player_num > 1) {
        do {
            if (info.type[index - 1] != -1) {
                RGE_Player* player = new RGE_Player(this,
                    master_players[info.tribe[index - 1]],
                    index, info.name[index - 1],
                    info.tribe[index - 1], 1);
                players[index] = player;
            }
            index++;
        } while (index < player_num);
    }
}

void RGE_Game_World::setup_player_colors(RGE_Player_Info& info) {
    int colorIdx = -1;

    this->players[0]->set_color_table(7);

    int maxPlayerNum = this->player_num + 1;
    int maxIter = info.player_num;
    if (maxIter > maxPlayerNum) {
        maxIter = maxPlayerNum;
    }

    int i = 1;
    unsigned char* colorsUsed = (unsigned char*)calloc(this->color_table_num, 1);
    unsigned char* playersDone = (unsigned char*)calloc(this->player_num, 1);

    if (this->player_num > 1) {
        do {
            if (i - 1 < maxIter && info.color[i - 1] >= 0 &&
                colorsUsed[info.color[i - 1]] == 0) {
                this->players[i]->set_color_table((unsigned char)info.color[i - 1]);
                colorsUsed[info.color[i - 1]] = 1;
                playersDone[i] = 1;
            }
            ++i;
        } while (i < this->player_num);
    }

    i = 1;
    if (this->player_num > 1) {
        do {
            if (playersDone[i] == 0) {
                do {
                    ++colorIdx;
                } while (colorsUsed[colorIdx] == 1 ||
                         this->color_tables[colorIdx]->type != 1);

                this->players[i]->set_color_table((unsigned char)colorIdx);
                colorsUsed[colorIdx] = 1;
            }
            ++i;
        } while (i < this->player_num);
    }

    free(colorsUsed);
    free(playersDone);
}

void RGE_Game_World::setup_player_colors() {
    int color = -1;

    this->players[0]->set_color_table(7);

    unsigned char* used = (unsigned char*)calloc(this->color_table_num, 1);

    for (int p = 1; p < this->player_num; p++) {
        do {
            color++;
        } while (used[color] == 1 || this->color_tables[color]->type != 1);

        this->players[p]->set_color_table((unsigned char)color);
        used[color] = 1;
    }

    free(used);
}

unsigned char RGE_Game_World::new_game(RGE_Player_Info& info, int mode)
{
    char randomString[256];
    int mapTeam;
    unsigned char retval;
    int i, j, id1, id2;

    world_update_counter = 0;
    pathSystem.zeroObstructionMap();
    aiPathSystem.zeroObstructionMap();
    for (i = 0; i < 13; i++) computerPlayerSetup[i] = 0;
    this->currentUpdateComputerPlayer = -1;
    this->del_game_info();
    debug_random_reset();
    debug_timeGetTime_cnt = 0;
    debug_timeGetTime_time = 0;
    this->game_state = 3;
    this->curr_player = (short)mode;

    int initial_seed;
    if (rge_base_game->multiplayerGame()) {
        initial_seed = this->commands->com_hand->GetRandomSeed();
    } else {
        initial_seed = rge_base_game->random_game_seed;
        if (initial_seed == -1) {
            initial_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x509);
        }
    }
    this->random_seed = initial_seed;
    debug_srand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x50c, this->random_seed);
    rge_base_game->random_map_seed = this->random_seed;
    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x50f);
    L->Log("World: new_game (rand=%d)", this->random_seed);

    this->player_num = info.player_num + 1;
    this->map->new_map(info.map_width, info.map_height);
    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x516);
    L->Log("  World: after_new_map (rand=%d)", this->random_seed);

    this->player_num = info.player_num + 1;
    this->players = (RGE_Player**)calloc(4, (int)this->player_num);
    this->setup_gaia();
    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x520);
    L->Log("  World: after_gaia (rand=%d)", this->random_seed);
    this->setup_players(info);
    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x526);
    L->Log("  World: after_players (rand=%d)", this->random_seed);

    for (i = 1; i < 9; i++) {
        int h = this->commands->com_hand->GetPlayerHumanity(i);
        if (h == 2 || h == 4) {
            int team = rge_base_game->playerTeam(i - 1);
            if (team > 1) {
                for (j = 1; j < 9; j++) {
                    int h2 = this->commands->com_hand->GetPlayerHumanity(j);
                    if ((h2 == 2 || h2 == 4) && rge_base_game->playerTeam(j - 1) == team) {
                        id1 = rge_base_game->playerID(i);
                        id2 = rge_base_game->playerID(j);
                        if (id1 != id2) {
                            this->players[id1]->set_relation(id2, 0);
                            this->players[id1]->set_allied_victory(1);
                        }
                    }
                }
            }
        }
    }

    if (rge_base_game->randomGame() && !rge_base_game->campaignGame()) {
        for (i = 1; i < 9; i++) {
            int h = this->commands->com_hand->GetPlayerHumanity(i);
            if (h == 4 || all_cp == 1 || (all_cp == 2 && i > 1)) {
                if (rge_base_game->playerTeam(i - 1) == 1) {
                    for (j = 1; j < 9; j++) {
                        int h2 = this->commands->com_hand->GetPlayerHumanity(j);
                        if (h2 == 4 || h2 == 2) {
                            id1 = rge_base_game->playerID(i);
                            id2 = rge_base_game->playerID(j);
                            if (id1 != id2) {
                                this->players[id1]->set_relation(id2, 1);
                                this->players[id1]->set_allied_victory(1);
                            }
                        }
                    }
                }
            }
        }
    }

    this->world_time = 0;
    this->old_world_time = 0;
    this->world_time_delta = 0;
    this->old_time = 0;
    if (rge_base_game->singlePlayerGame()) {
        this->game_speed = rge_base_game->get_game_speed();
    } else {
        this->game_speed = 1.0f;
    }
    this->temp_pause = 0;
    this->world_time_delta_seconds = 0;

    mapTeam = 0;
    if (info.scenario) {
        retval = this->load_scenario(info.scenario, info);
    } else if (info.campaign) {
        retval = this->load_scenario(info);
    } else {
        retval = this->new_random_game(info);
        mapTeam = 1;
    }

    this->initializePathingSystem();
    for (i = 0; i < this->player_num; i++) {
        if (this->players[i]) this->players[i]->random_start();
    }
    if (retval) this->game_state = 0;

    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x5b2);
    L->Log("  World: end_of_new_game (rand=%d)", this->random_seed);
    RGE_Base_Game* base_game = rge_base_game;
    base_game->get_string(0x277b, randomString, 0x100);
    if (mapTeam == 1) {
        for (i = 1; i < this->player_num; i++) {
            if (this->players[i]) {
                this->players[i]->loadAIInformation(randomString, randomString, randomString, 0, info.map_type);
            }
        }
    }
    return retval;
}

unsigned char RGE_Game_World::new_scenario(RGE_Player_Info& info, int seed) {
    world_update_counter = 0;
    this->del_game_info();

    curr_player = 0;

    if (seed == 0) {
        seed = commands->com_hand->GetRandomSeed();
    }

    random_seed = seed;
    debug_srand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x5D5, seed);

    this->map->new_map(info.map_width, info.map_height);
    this->map->clear_map((unsigned char)info.map_info->base_terrain, 1);

    player_num = info.player_num + 1;
    players = (RGE_Player**)calloc(4, player_num);

    this->setup_gaia();
    this->setup_players(info);

    world_time = 0;
    old_world_time = 0;
    world_time_delta = 0;
    old_time = 0;
    game_speed = 1.0f;
    temp_pause = 0;
    world_time_delta_seconds = 0.0f;

    unsigned char result;
    if (info.scenario != 0) {
        result = this->load_scenario(info.scenario, info);
    } else {
        this->setup_player_colors(info);
        this->scenario_init(this);
        result = 1;
    }

    if (result != 0) {
        int i;
        for (i = 0; i < (int)player_num; i++) {
            players[i]->set_map_visible();
        }
    }

    return result;
}

unsigned char RGE_Game_World::new_random_game(RGE_Player_Info& param_1)
{
    short saved_curr_player;
    int loop_count;
    short i;
    RGE_Player* player;

    world_update_counter = 0;
    this->setup_player_colors(param_1);
    this->scenario_init(this);

    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x612);
    L->Log("  World: before_map_gen (rand=%d)", this->random_seed);

    this->map->map_generate2(this, -1, -1, (unsigned char)param_1.map_type, this->player_num - 1);

    this->initializePathingSystem();

    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x61A);
    L->Log("  World: after_map_gen (rand=%d)", this->random_seed);

    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x622);
    L->Log("  World: after_player_random_start (rand=%d)", this->random_seed);

    saved_curr_player = this->curr_player;
    this->curr_player = -1;

    loop_count = 3;
    do {
        world_update_counter++;
        for (i = 0; i < this->player_num; i++) {
            player = this->players[i];
            if (player != 0) {
                player->update();
            }
        }
        loop_count--;
    } while (loop_count != 0);

    this->curr_player = saved_curr_player;
    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x631);
    L->Log("  World: after_player_update (rand=%d)", this->random_seed);

    return 1;
}

void RGE_Game_World::update_sounds(unsigned long value) {
    if (this->sound_update_index >= (int)this->sound_num) {
        this->sound_update_index = 0;
    }
    this->sounds[this->sound_update_index]->update(value);
    this->sound_update_index = this->sound_update_index + 1;
}

void RGE_Game_World::update_sprites(unsigned long param) {
    if (this->sprite_update_index >= this->sprite_num) {
        this->sprite_update_index = 0;
    }
    if (this->sprites[this->sprite_update_index] != 0) {
        this->sprites[this->sprite_update_index]->update(param);
    }
    this->sprite_update_index++;
}

unsigned char RGE_Game_World::update()
{
    char fileName[256];
    int cycle;
    int i;
    unsigned long start_time;
    unsigned long end_time;
    unsigned long now;
    long seconds;
    long minutes;
    long hours;
    unsigned long elapsed;
    unsigned long statusLogTime;
    unsigned char first_update = 0;

    this->availableComputerPlayerUpdateTime = this->maximumComputerPlayerUpdateTime;
    start_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\World.cpp", 0x68e);
    cycle = this->commands->com_hand->DoCycle(this->world_time);
    end_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\World.cpp", 0x690);
    rge_base_game->add_to_timing(0xe, (int)(end_time - start_time));
    if (cycle == 0) {
        this->world_time_delta = 0;
        return this->game_state;
    }

    visible_combats = 0;
    debug_random_on = 1;
    debug_timeGetTime_on = 1;
    if (do_fixed_update != 0) cycle = fixed_update_time;

    debug_srand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x6a2, this->random_seed);
    now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\World.cpp", 0x6a4);
    this->update_sounds(now);
    this->update_sprites(now);

    if (cycle == -1) {
        if (this->old_time == 0) {
            first_update = 1;
            elapsed = 0;
        } else {
            elapsed = now - this->old_time;
        }
        if (elapsed > 100) elapsed = 100;
    } else {
        elapsed = cycle;
    }

    this->old_time = now;
    this->old_world_time = this->world_time;
    if (this->temp_pause != 0) {
        if (cycle != -1) {
            this->world_time = this->old_world_time +
                (unsigned long)(elapsed * this->game_speed);
        }
        this->temp_pause = 0;
    } else {
        this->world_time = this->old_world_time +
            (unsigned long)(elapsed * this->game_speed);
    }
    this->world_time_delta = this->world_time - this->old_world_time;

    if (this->world_time_delta != 0 || first_update) {
        this->commands->do_commands();
        this->scenario->update();
        this->world_time_delta_seconds = this->world_time_delta * DAT_00577a14;
        world_update_counter = world_update_counter + 1;
        for (i = 0; i < this->player_num; ++i) {
            if (this->players[i] != 0) {
                this->player_time_delta[i] =
                    this->player_time_delta[i] + this->world_time_delta;
                this->players[i]->update();
                this->players[i]->tile_list.del_list();
            }
        }
        if (MouseSystem != 0) MouseSystem->Poll();
        now = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x6e2);
        for (i = 0; i < this->player_num; ++i) {
            if (this->players[i] != 0) {
                this->players[i]->doppleganger_objects->update();
            }
        }
        for (i = 0; i < this->player_num; ++i) {
            if (this->players[i] != 0) {
                this->players[i]->doppleganger_creator->perform_doppleganger_checks();
            }
        }
        debug_srand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x6f6, now);
        this->player_time_delta[this->player_turn] = 0;
        this->player_turn = this->player_turn + 1;
        if (this->player_turn >= this->player_num) this->player_turn = 0;
        this->check_game_state();
    }

    now = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x71a);
    this->random_seed = now;
    debug_random_on = 0;
    debug_timeGetTime_on = 0;
    this->commands->com_hand->LastWorldRandom(this->random_seed);

    if (logStatusOn == 1 && this->game_state != 1) {
        statusLogTime = lastStatusLogTime;
        if (30000 < this->world_time - statusLogTime ||
            statusLogTime == 0) {
            FILE* statusFile = logStatusFile;
            if (statusFile == 0) {
                sprintf(fileName, "AILog\\%s.log",
                        rge_base_game->player_game_info->get_current_player_name());
                statusFile = fopen(fileName, "a");
                logStatusFile = statusFile;
                if (statusFile == 0) return this->game_state;
            }
            seconds = this->world_time / 1000;
            minutes = 0;
            hours = 0;
            if (seconds > 59) {
                minutes = seconds / 60;
                seconds = seconds - minutes * 60;
                if (minutes > 59) {
                    hours = minutes / 60;
                    minutes = minutes - hours * 60;
                }
            }
            if (lastStatusLogTime == 0) {
                this->logStatus(statusFile, 1);
            } else {
                fprintf(statusFile,
                        "\nStatus Log at GameTime %02ld:%02ld:%02ld\n",
                        hours, minutes, seconds);
            }
            for (i = 1; i < this->player_num; ++i) {
                if (this->players[i] != 0) {
                    if (lastStatusLogTime == 0) {
                        this->players[i]->logStatus(logStatusFile, 1);
                    } else {
                        this->players[i]->logStatus(logStatusFile, 0);
                    }
                }
            }
            lastStatusLogTime = this->world_time + 1;
        }
    }

    if (this->game_state == 1 && logStatusOn == 1 && logStatusFile != 0) {
        fprintf(logStatusFile, "\nGAME OVER!\n");
        for (i = 1; i < this->player_num; ++i) {
            if (this->players[i] != 0) {
                if (this->players[i]->game_status == 1) {
                    fprintf(logStatusFile, "\nPlayer %d Won!\n", i);
                } else {
                    fprintf(logStatusFile, "\nPlayer %d Lost!\n", i);
                }
            }
        }
        fclose(logStatusFile);
        logStatusFile = 0;
    }
    return this->game_state;
}

int RGE_Game_World::is_player_turn(int param) {
    return this->player_turn == param;
}

unsigned long RGE_Game_World::get_accum_time_delta(int idx) { return this->player_time_delta[idx]; }

unsigned char RGE_Game_World::get_game_state() { return this->game_state; }

unsigned char RGE_Game_World::check_game_state(void)
{
    long local_4 = 0;
    long games_lost = 0;
    long games_on = 0;
    long candidate = 0;
    long candidate_state = 0;

    for (long i = 1; i < this->player_num; ++i) {
        unsigned int state = this->players[i]->check_victory();
        switch (state) {
        case 0:
            ++local_4;
            if (candidate <= 0 || candidate_state == 0) {
                candidate = i;
                candidate_state = 1;
            }
            else if (this->players[i]->allied_victory == 0 ||
                     this->players[candidate]->relation(i) != 0 ||
                     this->players[i]->relation(candidate) != 0) {
                candidate_state = -1;
            }
            break;
        case 1:
            ++games_lost;
            break;
        case 2:
            ++games_on;
            break;
        }
    }

    if (games_lost > 0) {
        this->game_state = 1;
        for (long i = 1; i < this->player_num; ++i) {
            this->players[i]->loss_if_game_on();
        }
    }
    else if (this->scenario->Get_conquest_victory()) {
        if ((games_on > 0 && candidate_state > 0) || local_4 == 0) {
            this->game_state = 1;
            for (long i = 1; i < this->player_num; ++i) {
                this->players[i]->victory_if_game_on();
            }
            this->game_end_condition = 1;
        }
    }

    if (this->game_state == 1 && this->campaign >= 0) {
        if (rge_base_game->set_campaign_info(this->campaign, this->campaign_player, this->campaign_scenario)) {
            if (this->players[this->curr_player]->game_status == 1) {
                rge_base_game->set_campaign_win();
                return this->game_state;
            }
        }
        else {
            this->campaign = -1;
        }
    }

    return this->game_state;
}

void RGE_Game_World::save(int file)
{
    color_log('$', '$', 1);
    save_game_version = 7.23f;
    rge_write(file, &this->world_time, 4);
    rge_write(file, &this->old_world_time, 4);
    rge_write(file, &this->world_time_delta, 4);
    rge_write(file, &this->world_time_delta_seconds, 4);
    rge_write(file, &this->timer, 4);
    rge_write(file, &this->game_speed, 4);
    rge_write(file, &this->temp_pause, 1);
    rge_write(file, &this->next_object_id, 4);
    rge_write(file, &this->next_reusable_object_id, 4);
    rge_write(file, &this->random_seed, 4);
    rge_write(file, &this->curr_player, 2);
    rge_write(file, &this->player_num, 2);
    rge_write(file, &this->game_state, 1);
    rge_write(file, &this->campaign, 4);
    rge_write(file, &this->campaign_player, 4);
    rge_write(file, &this->campaign_scenario, 4);
    rge_write(file, &this->player_turn, 4);
    for (int i = 0; i < 9; i++) rge_write(file, &this->player_time_delta[i], 4);
    this->map->save_map(file);
    for (int j = 0; j < this->player_num; j++) {
        color_log('$', 'L', 1);
        this->players[j]->save(file);
        color_log('$', 0x16, 1);
        this->players[j]->save2(file);
    }
    color_log('$', '2', 1);
    for (int k = 0; k < this->player_num; k++) {
        this->players[k]->save_info(file);
    }
    color_log('$', 'E', 1);
    this->scenario->save(file);
    color_log('$', '_', 1);
    if (this->difficultyLevelValue == -1) {
        this->difficultyLevelValue = rge_base_game->difficulty();
    }
    rge_write(file, &this->difficultyLevelValue, 4);
}

unsigned char RGE_Game_World::save_game(char* name) {
    char tempname[300];

    save_game_version = 7.23f;
    sprintf(tempname, "%s%s", rge_base_game->prog_info->save_dir, name);
    int fd = rge_open(tempname, 0x8309, 0x180);
    if (fd != -1) {
        rge_write_error = 0;
        rge_write(fd, "VER 8.6", 8);
        rge_write(fd, &save_game_version, 4);

        this->save(fd);

        rge_close(fd);

        if (rge_write_error != 0) {
            _unlink(tempname);
            return 0;
        }
        return 1;
    }
    return 0;
}

void RGE_Game_World::base_save(int file) {
    int i;

    rge_write(file, base_save_version, 8);
    rge_write(file, &this->terrain_num, 2);
    rge_write(file, &this->terrain_size, 2);

    if (this->terrain_num > 0 && this->terrain_size > 0) {
        rge_write(file, this->terrains, (int)this->terrain_num << 2);
        for (i = 0; i < this->terrain_num; i++) {
            if (this->terrains[i] != 0) {
                rge_write(file, this->terrains[i], (int)this->terrain_size << 2);
            }
        }
    }

    rge_write(file, &this->color_table_num, 2);
    for (i = 0; i < this->color_table_num; i++) {
        this->color_tables[i]->save(file);
    }

    rge_write(file, &this->sound_num, 2);
    for (i = 0; i < this->sound_num; i++) {
        this->sounds[i]->save(file);
    }

    rge_write(file, &this->sprite_num, 2);
    rge_write(file, this->sprites, (int)this->sprite_num << 2);
    for (i = 0; i < this->sprite_num; i++) {
        if (this->sprites[i] != 0) {
            this->sprites[i]->save(file);
        }
    }

    this->map->save(file);
    this->effects->save(file);

    rge_write(file, &this->master_player_num, 2);
    for (i = 0; i < this->master_player_num; i++) {
        this->master_players[i]->save(file);
    }
}

void RGE_Game_World::base_save(char* param_1) {
    int fileHandle = rge_open(param_1, 0x8309, 0x180);
    if (fileHandle != -1) {
        this->base_save(fileHandle);
        rge_close(fileHandle);
    }
}

typedef unsigned char byte;

byte RGE_Game_World::save_scenario(char* name)
{
    char scenario_name[300];
    char kill_name[300];
    int scenario_player_num = (short)this->player_num;
    int i;
    float obj_angle;
    int count;
    char* p = name;
    int n = 0;

    do {
        kill_name[n++] = *p++;
    } while (*p != '.');
    kill_name[n] = 0;

    sprintf(scenario_name, "%s%s.scn", rge_base_game->prog_info->scenario_dir, kill_name);
    unlink(scenario_name);
    sprintf(scenario_name, "%s%s", rge_base_game->prog_info->scenario_dir, name);
    int fd = rge_open(scenario_name, 0x8301, 0x180);
    if (fd != -1) {
        rge_write_error = 0;
        if (rge_base_game->check_prog_argument("TRIAL") == 1) {
            rge_write_uncompressed(fd, "1.10", 4);
        } else {
            rge_write_uncompressed(fd, "1.11", 4);
        }
        rge_base_game->write_scenario_header(fd);
        rge_write(fd, &this->next_object_id, 4);
        this->scenario->save(fd);
        this->map->scenario_save(fd);
        rge_write(fd, &scenario_player_num, 4);

        for (i = 1; i < (short)this->player_num; ++i) {
            this->players[i]->scenario_save(fd);
        }

        for (i = 0; i < (short)this->player_num; ++i) {
            count = 0;
            RGE_Object_Node* o = this->players[i]->objects->list;
            while (o) {
                if (o->node->master_obj->master_type != 0x19) ++count;
                o = o->next;
            }
            o = this->players[i]->sleeping_objects->list;
            while (o) {
                if (o->node->master_obj->master_type != 0x19) ++count;
                o = o->next;
            }
            rge_write(fd, &count, 4);

            o = this->players[i]->objects->list;
            while (o) {
                if (o->node->master_obj->master_type != 0x19) {
                    rge_write(fd, &o->node->world_x, 4);
                    rge_write(fd, &o->node->world_y, 4);
                    rge_write(fd, &o->node->world_z, 4);
                    rge_write(fd, &o->node->id, 4);
                    rge_write(fd, &o->node->master_obj->id, 2);
                    rge_write(fd, &o->node->object_state, 1);
                    if (o->node->master_obj->master_type > 0x1e &&
                        o->node->master_obj->master_type < 0x5a) {
                        obj_angle = static_cast<RGE_Moving_Object*>(o->node)->angle;
                    } else {
                        obj_angle = (float)o->node->facet;
                    }
                    rge_write(fd, &obj_angle, 4);
                }
                o = o->next;
            }

            o = this->players[i]->sleeping_objects->list;
            while (o) {
                if (o->node->master_obj->master_type != 0x19) {
                    rge_write(fd, &o->node->world_x, 4);
                    rge_write(fd, &o->node->world_y, 4);
                    rge_write(fd, &o->node->world_z, 4);
                    rge_write(fd, &o->node->id, 4);
                    rge_write(fd, &o->node->master_obj->id, 2);
                    rge_write(fd, &o->node->object_state, 1);
                    if (o->node->master_obj->master_type > 0x1e &&
                        o->node->master_obj->master_type < 0x5a) {
                        obj_angle = static_cast<RGE_Moving_Object*>(o->node)->angle;
                    } else {
                        obj_angle = (float)o->node->facet;
                    }
                    rge_write(fd, &obj_angle, 4);
                }
                o = o->next;
            }
        }

        rge_write(fd, &scenario_player_num, 4);
        for (i = 1; i < (short)this->player_num; ++i) {
            this->players[i]->scenario_postsave(fd);
        }
        rge_close(fd);
        if (rge_write_error) {
            unlink(scenario_name);
            return 0;
        }
        return 1;
    }
    return 0;
}

unsigned char RGE_Game_World::load_scenario(char* name, RGE_Player_Info& info)
{
    char scenario_name[300];
    char scenario_version[5];
    int version;
    int file;
    world_update_counter = 0;
    sprintf(scenario_name, "%s%s", rge_base_game->prog_info->scenario_dir, name);
    if (name != 0) {
        file = rge_open(scenario_name, 0x8000);
        if (file != -1) {
            rge_read_uncompressed(file, scenario_version, 4);
            scenario_version[4] = 0;
            if (strcmp(scenario_version, version_101) == 0) {
                this->load_scenario1(file, info);
                goto success;
            }
            if (strcmp(scenario_version, version_102) == 0) {
                goto version2;
            }
            if (strcmp(scenario_version, version_103) == 0) {
                rge_read_uncompressed(file, &version, 4);
                if (version <= 0) {
                    goto version2;
                }
                void* buf = malloc(version);
                if (buf == 0) {
                    goto close_failed;
                }
                rge_read_uncompressed(file, buf, version);
                free(buf);
                goto version2;
            }
            if (strcmp(scenario_version, version_104) == 0) {
                this->load_scenario3(file, info);
                goto success;
            }
            if (strcmp(scenario_version, version_105) == 0) {
                this->load_scenario4(file, info);
                goto success;
            }
            if (strcmp(scenario_version, version_106) == 0) {
                this->load_scenario5(file, info);
                goto success;
            }
            if (strcmp(scenario_version, version_107) == 0) {
                this->load_scenario6(file, info);
                goto success;
            }
            if (strcmp(scenario_version, version_108) == 0) {
                this->load_scenario7(file, info);
                goto success;
            }
            if (strcmp(scenario_version, version_109) != 0 &&
                strcmp(scenario_version, version_111) != 0 &&
                strcmp(scenario_version, version_110) != 0) {
                goto close_failed;
            }
            this->load_scenario8(file, info);
success:
            this->setup_player_colors(info);
            return 1;
close_failed:
            rge_close(file);
        }
    }
    return 0;

version2:
    this->load_scenario2(file, info);
    goto success;
}

unsigned char RGE_Game_World::load_scenario(RGE_Player_Info& info) {
    char scenario_version[5];
    int version;
    int file;

    world_update_counter = 0;
    file = rge_base_game->campaign_open_scenario();
    if (file == -1) {
        goto cleanup;
    }

    rge_read_uncompressed(file, scenario_version, 4);
    scenario_version[4] = 0;

    if (strcmp(scenario_version, version_101) == 0) {
        this->load_scenario1(file, info);
        goto success;
    }

    if (strcmp(scenario_version, version_102) == 0) {
        goto shared_80;
    }

    if (strcmp(scenario_version, version_103) == 0) {
        rge_read_uncompressed(file, &version, 4);
        if (version > 0) {
            void* buffer = malloc(version);
            if (buffer == 0) {
                goto fail;
            }
            rge_read_uncompressed(file, buffer, version);
            free(buffer);
        }
        goto shared_80;
    }

    if (strcmp(scenario_version, version_104) == 0) {
        this->load_scenario3(file, info);
        goto success;
    }
    if (strcmp(scenario_version, version_105) == 0) {
        this->load_scenario4(file, info);
        goto success;
    }
    if (strcmp(scenario_version, version_106) == 0) {
        this->load_scenario5(file, info);
        goto success;
    }
    if (strcmp(scenario_version, version_107) == 0) {
        this->load_scenario6(file, info);
        goto success;
    }
    if (strcmp(scenario_version, version_108) == 0) {
        this->load_scenario7(file, info);
        goto success;
    }
    if (strcmp(scenario_version, version_109) == 0 ||
        strcmp(scenario_version, version_111) == 0 ||
        strcmp(scenario_version, version_110) == 0) {
        this->load_scenario8(file, info);
        goto success;
    } else {
        goto fail;
    }

shared_80:
    this->load_scenario2(file, info);
    goto success;

success:
    this->setup_player_colors(info);
    rge_base_game->get_campaign_info(this->campaign,
                                     this->campaign_player,
                                     this->campaign_scenario);
    return 1;

fail:
    rge_close(file);
cleanup:
    return 0;
}

void RGE_Game_World::scenario_make_player(short param_1, unsigned char param_2,
    unsigned char param_3, unsigned char param_4, char* param_5) {
    if (param_3 != 0)
        return;

    this->players[param_1] = new RGE_Player(
        this,
        this->master_players[param_4],
        (unsigned char)param_1,
        param_5,
        param_4,
        1
    );
}

void RGE_Game_World::scenario_make_map(int file)
{
    this->map->scenario_load(file, (unsigned char*)0);
}

void RGE_Game_World::load_scenario1(int file, RGE_Player_Info& info)
{
    long player_id_hash[9];
    int next_object_id;
    int scenario_player_num;
    int count;
    int object_id;
    float object_angle;
    unsigned char object_state;
    short master_id;
    float world_x;
    float world_y;
    float world_z;
    char rem[13];
    unsigned char player_id;
    unsigned char master_player_id;
    int i;
    int j;
    int player_num;

    rge_read(file, &next_object_id, 4);
    this->scenario_init(file, this);
    this->scenario_make_map(file);
    player_num = this->player_num;

    if (player_num > 0) {
        do {
            for (i = 0; i < 9; ++i) {
                player_id_hash[i] = -1;
            }
        } while (player_num > 10);
    }

    i = 0;
    if (i < player_num) {
        do {
            player_id_hash[info.player_id_hash[i]] = i;
            ++i;
        } while (i < player_num);
    }

    i = 0;
    if (i < this->player_num) {
        do {
            this->players[i]->remake_visible_map();
            ++i;
        } while (i < this->player_num);
    }

    rge_read(file, &scenario_player_num, 4);
    i = 0;
    if (i < scenario_player_num) {
        do {
            rge_read(file, &player_id, 1);
            rge_read(file, &master_player_id, 1);
            ++i;
        } while (i < scenario_player_num);
    }

    i = 0;
    if (i < scenario_player_num) {
        do {
            rge_read(file, &count, 4);
            j = 0;
            if (j < count) {
                do {
                    rge_read(file, &world_x, 4);
                    rge_read(file, &world_y, 4);
                    rge_read(file, &world_z, 4);
                    rge_read(file, &object_id, 4);
                    rge_read(file, &master_id, 2);
                    rge_read(file, &object_state, 1);
                    rge_read(file, &object_angle, 4);
                    if (i < this->player_num && player_id_hash[i] >= 0 &&
                        this->players[i] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = object_id;
                        this->players[player_id_hash[i]]->make_scenario_obj(
                            world_x, world_y, world_z, master_id, object_state, object_angle);
                        this->scenario_object_flag = 0;
                    }
                    ++j;
                } while (j < count);
            }
            ++i;
        } while (i < scenario_player_num);
    }

    this->next_object_id = next_object_id;
    rge_read(file, rem, 13);

    i = 1;
    if (i < scenario_player_num) {
        long* player_map = player_id_hash + 1;
        do {
            if (i < this->player_num && *player_map > -1 &&
                this->players[*player_map] != 0) {
                this->players[*player_map]->scenario_load(file, player_id_hash, 1.0f);
            } else {
                this->players[0]->scenario_load(file, player_id_hash, 1.0f);
            }
            ++i;
            ++player_map;
        } while (i < scenario_player_num);
    }

    rge_close(file);

    i = 1;
    if (this->player_num > 1) {
        do {
            if (i < scenario_player_num) {
                if (this->players[i] != 0) {
                    this->players[player_id_hash[i]]->loadAIInformation(
                        this->scenario->Get_BuildList(i - 1, 1),
                        this->scenario->Get_CityPlan(i - 1, 1),
                        this->scenario->Get_player_AI(i - 1, 1),
                        this->scenario->GetPlayerPosture(i - 1), -1);
                }
            } else {
                return;
            }
            ++i;
        } while (i < this->player_num);
    }
}

void RGE_Game_World::load_scenario2(int handle, RGE_Player_Info& info)
{
    long player_id_hash[9];
    int next_object_id;
    char rem[13];
    int obj_id;
    float world_x;
    float world_y;
    float world_z;
    short master_id;
    unsigned char obj_state;
    float obj_angle;
    int count;
    int scenario_player_num;
    unsigned char player_id;
    unsigned char master_player_id;

    world_update_counter = 0;
    rge_read(handle, &next_object_id, 4);
    this->scenario_init(handle, this);
    this->scenario_make_map(handle);

    int player_num = this->player_num;
    if (player_num > 0) {
        do { for (int k = 0; k < 9; k++) player_id_hash[k] = -1; } while (player_num > 10);
    }
    int i = 0;
    if (player_num > 0) {
        long* p = &info.player_id_hash[0];
        do { int idx = *p++; player_id_hash[idx] = i; i++; } while (i < player_num);
    }
    int j = 0;
    if (player_num > 0) {
        do { this->players[j]->remake_visible_map(); j++; } while (j < this->player_num);
    }

    rge_read(handle, &scenario_player_num, 4);
    j = 0;
    if (scenario_player_num > 0) { do { rge_read(handle, &player_id, 1); rge_read(handle, &master_player_id, 1); j++; } while (j < scenario_player_num); }

    int outer = 0;
    if (scenario_player_num > 0) {
        long* map = player_id_hash;
        do {
            rge_read(handle, &count, 4);
            j = 0;
            if (count > 0) {
                do {
                    rge_read(handle, &world_z, 4);
                    rge_read(handle, &world_y, 4);
                    rge_read(handle, &world_x, 4);
                    rge_read(handle, &obj_id, 4);
                    rge_read(handle, &master_id, 2);
                    rge_read(handle, &obj_state, 1);
                    rge_read(handle, &obj_angle, 4);
                    int mapped = *map;
                    if (mapped >= 0 && this->players[mapped] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = obj_id;
                        this->players[mapped]->make_scenario_obj(world_z, world_y, world_x, master_id, obj_state, obj_angle);
                        this->scenario_object_flag = 0;
                    }
                    j++;
                } while (j < count);
            }
            outer++; map++;
        } while (outer < scenario_player_num);
    }

    this->next_object_id = next_object_id;
    rge_read(handle, rem, 13);
    j = 1;
    if (scenario_player_num > 1) {
        long* map = &player_id_hash[1];
        do {
            if (j < this->player_num && *map > -1 && this->players[*map] != 0) {
                this->players[*map]->scenario_load(handle, player_id_hash, 1.03f);
            } else {
                this->players[0]->scenario_load(handle, player_id_hash, 1.03f);
            }
            j++; map++;
        } while (j < scenario_player_num);
    }

    rge_close(handle);
    j = 1;
    if (this->player_num > 1) {
        do {
            if (j < scenario_player_num) {
                if (this->players[j] != 0 && player_id_hash[j] > -1) {
                    int s = j - 1;
                    this->players[player_id_hash[j]]->loadAIInformation(
                        this->scenario->Get_BuildList(s, 1),
                        this->scenario->Get_CityPlan(s, 1),
                        this->scenario->Get_player_AI(s, 1),
                        this->scenario->GetPlayerPosture(s), -1);
                }
            } else {
                return;
            }
            ++j;
        } while (j < this->player_num);
    }
}

void RGE_Game_World::load_scenario3(int file, RGE_Player_Info& info)
{
    uchar player_id;
    uchar master_player_id;
    long scenario_player_num;
    long next_object_id;
    long count;
    long object_count;
    long id;
    float obj_angle;
    uchar obj_state;
    short master_id;
    float world_z;
    float world_y;
    float world_x;
    char rem[13];
    long player_id_hash[9];
    int outer;

    world_update_counter = 0;
    rge_read_uncompressed(file, &count, 4);
    if (count > 0) {
        void* p = malloc(count);
        if (p == 0) {
            rge_close(file);
            return;
        }
        rge_read_uncompressed(file, p, count);
        free(p);
    }
    rge_read(file, &next_object_id, 4);
    this->scenario_init(file, this);
    this->scenario_make_map(file);
    int n = this->player_num;
    if (n > 0) {
        do {
            for (int k = 0; k < 9; k++) player_id_hash[k] = -1;
        } while (n > 10);
    }
    int i = 0;
    if (n > 0) {
        long* ids = info.player_id_hash;
        do {
            player_id_hash[*ids++] = i;
            i++;
        } while (i < n);
    }
    i = 0;
    if (n > 0) {
        do {
            this->players[i]->remake_visible_map();
            i++;
        } while (i < this->player_num);
    }
    rge_read(file, &scenario_player_num, 4);
    i = 0;
    if (scenario_player_num > 0) {
        do {
            rge_read(file, &player_id, 1);
            rge_read(file, &master_player_id, 1);
            i++;
        } while (i < scenario_player_num);
    }
    outer = 0;
    if (scenario_player_num > 0) {
        long* map = player_id_hash;
        do {
            rge_read(file, &object_count, 4);
            int j = 0;
            if (object_count > 0) {
                do {
                    rge_read(file, &world_z, 4);
                    rge_read(file, &world_y, 4);
                    rge_read(file, &world_x, 4);
                    rge_read(file, &id, 4);
                    rge_read(file, &master_id, 2);
                    rge_read(file, &obj_state, 1);
                    rge_read(file, &obj_angle, 4);
                    int pid = *map;
                    if (pid >= 0 && this->players[pid] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = id;
                        this->players[pid]->make_scenario_obj(
                            world_z, world_y, world_x, master_id, obj_state,
                            obj_angle);
                        this->scenario_object_flag = 0;
                    }
                    j++;
                } while (j < object_count);
            }
            outer++;
            map++;
        } while (outer < scenario_player_num);
    }
    this->next_object_id = next_object_id;
    rge_read(file, rem, 13);
    i = 1;
    if (scenario_player_num > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i >= this->player_num || *map <= -1 || this->players[*map] == 0) {
                this->players[0]->scenario_load(file, player_id_hash, 1.04f);
            } else {
                this->players[*map]->scenario_load(file, player_id_hash, 1.04f);
            }
            i++;
            map++;
        } while (i < scenario_player_num);
    }
    rge_close(file);
    i = 1;
    if (this->player_num > 1) {
        do {
            if (i < scenario_player_num) {
                if (this->players[i] != 0 && player_id_hash[i] > -1) {
                    int idx = i - 1;
                    this->players[player_id_hash[i]]->loadAIInformation(this->scenario->Get_BuildList(idx,1), this->scenario->Get_CityPlan(idx,1), this->scenario->Get_player_AI(idx,1), this->scenario->GetPlayerPosture(idx), -1);
                }
            } else {
                return;
            }
            i++;
        } while (i < this->player_num);
    }
}

void RGE_Game_World::load_scenario4(int file, RGE_Player_Info& info)
{
    long next_object_id;
    long count;
    long object_count;
    long id;
    float obj_angle;
    uchar obj_state;
    short master_id;
    float world_z;
    float world_y;
    float world_x;
    long player_id_hash[9];
    long outer;

    world_update_counter = 0;
    rge_read_uncompressed(file, &count, 4);
    if (count > 0) {
        void* p = malloc(count);
        if (p == 0) {
            rge_close(file);
            return;
        }
        rge_read_uncompressed(file, p, count);
        free(p);
    }

    rge_read(file, &next_object_id, 4);
    this->scenario_init(file, this);
    this->scenario_make_map(file);

    int n = this->player_num;
    if (n > 0) {
        do {
            for (int k = 0; k < 9; ++k) player_id_hash[k] = -1;
        } while (n > 10);
    }

    int i = 0;
    if (n > 0) {
        long* ids = info.player_id_hash;
        do {
            player_id_hash[*ids++] = i;
            ++i;
        } while (i < n);
    }

    i = 0;
    if (n > 0) {
        do {
            this->players[i]->remake_visible_map();
            ++i;
        } while (i < this->player_num);
    }

    long scenario_player_num;
    rge_read(file, &scenario_player_num, 4);
    i = 1;
    if (scenario_player_num > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i < this->player_num && *map > -1 &&
                this->players[*map] != 0) {
                this->players[*map]->scenario_load(file, player_id_hash, 1.04f);
            } else {
                this->players[0]->scenario_load(file, player_id_hash, 1.04f);
            }
            ++i;
            ++map;
        } while (i < scenario_player_num);
    }

    outer = 0;
    if (scenario_player_num > 0) {
        long* map = player_id_hash;
        do {
            rge_read(file, &object_count, 4);
            int j = 0;
            if (object_count > 0) {
                do {
                    rge_read(file, &world_x, 4);
                    rge_read(file, &world_y, 4);
                    rge_read(file, &world_z, 4);
                    rge_read(file, &id, 4);
                    rge_read(file, &master_id, 2);
                    rge_read(file, &obj_state, 1);
                    rge_read(file, &obj_angle, 4);
                    int player_id = *map;
                    if (player_id >= 0 && this->players[player_id] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = id;
                        this->players[player_id]->make_scenario_obj(
                            world_x, world_y, world_z, master_id, obj_state, obj_angle);
                        this->scenario_object_flag = 0;
                    }
                    ++j;
                } while (j < object_count);
            }
            ++outer;
            ++map;
        } while (outer < scenario_player_num);
    }

    this->next_object_id = next_object_id;
    rge_close(file);

    i = 1;
    while (i < this->player_num) {
        if (i >= scenario_player_num) return;
        if (this->players[i] != 0 && player_id_hash[i] > -1) {
            int player_index = i - 1;
            this->players[player_id_hash[i]]->loadAIInformation(
                this->scenario->Get_BuildList(player_index, 1),
                this->scenario->Get_CityPlan(player_index, 1),
                this->scenario->Get_player_AI(player_index, 1),
                this->scenario->GetPlayerPosture(player_index),
                -1);
        }
        ++i;
    }
}

void RGE_Game_World::load_scenario5(int file, RGE_Player_Info& info)
{
    long count;
    long id;
    float obj_angle;
    uchar obj_state;
    short master_id;
    float world_x;
    float world_y;
    float world_z;
    long obj_id;
    long player_id_hash[9];
    int outer;
    int i;
    long next_object_id;
    int j;
    long scenario_player_count;
    void* buffer;

    world_update_counter = 0;
    rge_read_uncompressed(file, &count, 4);
    if (count > 0) {
        buffer = malloc(count);
        if (buffer == 0) {
            rge_close(file);
            return;
        }
        rge_read_uncompressed(file, buffer, count);
        free(buffer);
    }

    rge_read(file, &next_object_id, 4);
    this->scenario_init(file, this);
    this->scenario_make_map(file);

    int n = this->player_num;
    if (n > 0) {
        do {
            for (i = 0; i < 9; ++i) player_id_hash[i] = -1;
        } while (n > 10);
    }

    i = 0;
    if (n > 0) {
        long* ids = info.player_id_hash;
        do {
            player_id_hash[*ids++] = i++;
        } while (i < n);
    }

    i = 0;
    if (n > 0) {
        do {
            this->players[i]->remake_visible_map();
            ++i;
        } while (i < this->player_num);
    }

    rge_read(file, &scenario_player_count, 4);
    i = 1;
    if (scenario_player_count > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i >= this->player_num || *map <= -1 ||
                this->players[*map] == 0) {
                this->players[0]->scenario_load(file, player_id_hash, 1.06f);
            } else {
                this->players[*map]->scenario_load(file, player_id_hash, 1.06f);
            }
            ++i;
            ++map;
        } while (i < scenario_player_count);
    }

    outer = 0;
    if (scenario_player_count > 0) {
        long* map = player_id_hash;
        do {
            rge_read(file, &obj_id, 4);
            j = 0;
            if (obj_id > 0) {
                do {
                    rge_read(file, &world_x, 4);
                    rge_read(file, &world_y, 4);
                    rge_read(file, &world_z, 4);
                    rge_read(file, &id, 4);
                    rge_read(file, &master_id, 2);
                    rge_read(file, &obj_state, 1);
                    rge_read(file, &obj_angle, 4);
                    int player_id = *map;
                    if (player_id >= 0 && this->players[player_id] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = id;
                        this->players[player_id]->make_scenario_obj(
                            world_x, world_y, world_z, master_id, obj_state, obj_angle);
                        this->scenario_object_flag = 0;
                    }
                    ++j;
                } while (j < obj_id);
            }
            ++outer;
            ++map;
        } while (outer < scenario_player_count);
    }

    this->next_object_id = next_object_id;
    rge_read(file, &scenario_player_count, 4);
    i = 1;
    if (scenario_player_count > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i >= this->player_num || *map <= -1 ||
                this->players[*map] == 0) {
                this->players[0]->scenario_postload(file, player_id_hash, 1.06f);
            } else {
                this->players[*map]->scenario_postload(file, player_id_hash, 1.06f);
            }
            ++i;
            ++map;
        } while (i < scenario_player_count);
    }

    rge_close(file);
    i = 1;
    while (i < this->player_num) {
        if (i >= scenario_player_count) return;
        if (this->players[i] != 0 && player_id_hash[i] > -1) {
            int player_index = i - 1;
            this->players[player_id_hash[i]]->loadAIInformation(
                this->scenario->Get_BuildList(player_index, 1),
                this->scenario->Get_CityPlan(player_index, 1),
                this->scenario->Get_player_AI(player_index, 1),
                this->scenario->GetPlayerPosture(player_index), -1);
        }
        ++i;
    }
}

void RGE_Game_World::load_scenario6(int file, RGE_Player_Info& info)
{
    long count;
    long next_object_id;
    long header_size;
    uchar id;
    short obj_angle;
    float world_z;
    float world_y;
    float world_x;
    float object_value;
    long player_id_hash[9];
    long scenario_player_count;
    long obj_count;
    int i,j;
    int outer;
    void* buf;
    world_update_counter = 0;
    rge_read_uncompressed(file, &count, 4);
    if (count > 0) {
        buf = malloc(count);
        if (buf == 0) { rge_close(file); return; }
        rge_read_uncompressed(file, buf, count);
        free(buf);
    }
    rge_read(file, &next_object_id, 4);
    this->scenario_init(file, this);
    this->scenario_make_map(file);
    int n = this->player_num;
    if (n > 0) {
        do { for (i=0;i<9;i++) player_id_hash[i] = -1; } while (n > 10);
    }
    for (i=0; i<n; i++) player_id_hash[info.player_id_hash[i]] = i;
    for (i=0; i<this->player_num; i++) this->players[i]->remake_visible_map();
    rge_read(file, &scenario_player_count, 4);
    for (i=1; i<scenario_player_count; i++) {
        if (i >= this->player_num || player_id_hash[i] <= -1 ||
            this->players[player_id_hash[i]]==0)
            this->players[0]->scenario_load(file, player_id_hash, 1.07f);
        else
            this->players[player_id_hash[i]]->scenario_load(file, player_id_hash, 1.07f);
    }
    outer = 0;
    if (scenario_player_count > 0) {
        long* map = player_id_hash;
        do {
            rge_read(file, &obj_count, 4);
            for (j=0; j<obj_count; j++) {
                rge_read(file, &world_z, 4); rge_read(file, &world_y, 4); rge_read(file, &world_x, 4); rge_read(file, &header_size, 4); rge_read(file, &obj_angle, 2); rge_read(file, &id, 1); rge_read(file, &object_value, 4);
                long player_id = *map;
                if (player_id >= 0 && this->players[player_id] != 0) {
                    this->scenario_object_flag=1;
                    this->scenario_object_id=header_size;
                    this->players[player_id]->make_scenario_obj(world_z, world_y, world_x, obj_angle, id, object_value);
                    this->scenario_object_flag=0;
                }
            }
            ++outer;
            ++map;
        } while (outer < scenario_player_count);
    }
    this->next_object_id = next_object_id;
    rge_read(file, &scenario_player_count, 4);
    for (i=1; i<scenario_player_count; i++) {
        if (i >= this->player_num || player_id_hash[i] <= -1 ||
            this->players[player_id_hash[i]]==0)
            this->players[0]->scenario_postload(file, player_id_hash, 1.07f);
        else
            this->players[player_id_hash[i]]->scenario_postload(file, player_id_hash, 1.07f);
    }
    rge_close(file);
    for (i=1; i<this->player_num && i<scenario_player_count; i++)
        if (this->players[i] && player_id_hash[i] > -1) {
            int k=i-1;
            this->players[player_id_hash[i]]->loadAIInformation(
                this->scenario->Get_BuildList(k,1),
                this->scenario->Get_CityPlan(k,1),
                this->scenario->Get_player_AI(k,1),
                this->scenario->GetPlayerPosture(k), -1);
        }
}

void RGE_Game_World::load_scenario7(int file, RGE_Player_Info& info)
{
    long count;
    long id;
    float obj_angle;
    uchar obj_state;
    short master_id;
    float world_x;
    float world_y;
    float world_z;
    long obj_id;
    long player_id_hash[9];
    int outer;
    int i;
    long next_object_id;
    int j;
    long scenario_player_count;
    void* buffer;

    world_update_counter = 0;
    rge_read_uncompressed(file, &count, 4);
    if (count > 0) {
        buffer = malloc(count);
        if (buffer == 0) {
            rge_close(file);
            return;
        }
        rge_read_uncompressed(file, buffer, count);
        free(buffer);
    }

    rge_read(file, &next_object_id, 4);
    this->scenario_init(file, this);
    this->scenario_make_map(file);

    int n = this->player_num;
    if (n > 0) {
        do {
            for (i = 0; i < 9; ++i) player_id_hash[i] = -1;
        } while (n > 10);
    }

    i = 0;
    if (n > 0) {
        long* ids = info.player_id_hash;
        do {
            player_id_hash[*ids++] = i++;
        } while (i < n);
    }

    i = 0;
    if (n > 0) {
        do {
            this->players[i]->remake_visible_map();
            ++i;
        } while (i < this->player_num);
    }

    rge_read(file, &scenario_player_count, 4);
    i = 1;
    if (scenario_player_count > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i >= this->player_num || *map <= -1 ||
                this->players[*map] == 0) {
                this->players[0]->scenario_load(file, player_id_hash, 1.08f);
            } else {
                this->players[*map]->scenario_load(file, player_id_hash, 1.08f);
            }
            ++i;
            ++map;
        } while (i < scenario_player_count);
    }

    outer = 0;
    if (scenario_player_count > 0) {
        long* map = player_id_hash;
        do {
            rge_read(file, &obj_id, 4);
            j = 0;
            if (obj_id > 0) {
                do {
                    rge_read(file, &world_x, 4);
                    rge_read(file, &world_y, 4);
                    rge_read(file, &world_z, 4);
                    rge_read(file, &id, 4);
                    rge_read(file, &master_id, 2);
                    rge_read(file, &obj_state, 1);
                    rge_read(file, &obj_angle, 4);
                    int player_id = *map;
                    if (player_id >= 0 && this->players[player_id] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = id;
                        this->players[player_id]->make_scenario_obj(
                            world_x, world_y, world_z, master_id, obj_state, obj_angle);
                        this->scenario_object_flag = 0;
                    }
                    ++j;
                } while (j < obj_id);
            }
            ++outer;
            ++map;
        } while (outer < scenario_player_count);
    }

    this->next_object_id = next_object_id;
    rge_read(file, &scenario_player_count, 4);
    i = 1;
    if (scenario_player_count > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i >= this->player_num || *map <= -1 ||
                this->players[*map] == 0) {
                this->players[0]->scenario_postload(file, player_id_hash, 1.08f);
            } else {
                this->players[*map]->scenario_postload(file, player_id_hash, 1.08f);
            }
            ++i;
            ++map;
        } while (i < scenario_player_count);
    }

    rge_close(file);
    i = 1;
    while (i < this->player_num) {
        if (i >= scenario_player_count) return;
        if (this->players[i] != 0 && player_id_hash[i] > -1) {
            int player_index = i - 1;
            this->players[player_id_hash[i]]->loadAIInformation(
                this->scenario->Get_BuildList(player_index, 1),
                this->scenario->Get_CityPlan(player_index, 1),
                this->scenario->Get_player_AI(player_index, 1),
                this->scenario->GetPlayerPosture(player_index), -1);
        }
        ++i;
    }
}

void RGE_Game_World::load_scenario8(int handle, RGE_Player_Info& info)
{
    long count;
    long next_object_id;
    long object_count;
    long obj_id;
    float obj_angle;
    unsigned char obj_state;
    short master_id;
    float world_z;
    float world_y;
    float world_x;
    long player_id_hash[9];
    long outer;
    long scenario_player_num;

    world_update_counter = 0;
    rge_read_uncompressed(handle, &count, 4);
    if (count > 0) {
        char* buf = (char*)malloc(count);
        if (buf == 0) { rge_close(handle); return; }
        rge_read_uncompressed(handle, buf, count);
        free(buf);
    }
    rge_read(handle, &next_object_id, 4);
    this->scenario_init(handle, this);
    this->scenario_make_map(handle);
    int n = this->player_num;
    if (n > 0) { do { for (int k = 0; k < 9; ++k) player_id_hash[k] = -1; } while (n > 10); }
    int i = 0;
    if (n > 0) { long* ids = info.player_id_hash; do { player_id_hash[*ids++] = i; ++i; } while (i < n); }
    i = 0;
    if (n > 0) { do { this->players[i]->remake_visible_map(); ++i; } while (i < this->player_num); }
    rge_read(handle, &scenario_player_num, 4);
    i = 1;
    if (scenario_player_num > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i < this->player_num && *map > -1 && this->players[*map] != 0) {
                this->players[*map]->scenario_load(handle, player_id_hash, 1.11f);
            } else {
                this->players[0]->scenario_load(handle, player_id_hash, 1.11f);
            }
            ++i;
            ++map;
        } while (i < scenario_player_num);
    }
    outer = 0;
    if (scenario_player_num > 0) {
        long* map = player_id_hash;
        do {
            rge_read(handle, &object_count, 4);
            int j = 0;
            if (object_count > 0) {
                do {
                    rge_read(handle, &world_z, 4);
                    rge_read(handle, &world_y, 4);
                    rge_read(handle, &world_x, 4);
                    rge_read(handle, &obj_id, 4);
                    rge_read(handle, &master_id, 2);
                    rge_read(handle, &obj_state, 1);
                    rge_read(handle, &obj_angle, 4);
                    if (*map >= 0 && this->players[*map] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = obj_id;
                        this->players[*map]->make_scenario_obj(
                            world_z, world_y, world_x, master_id, obj_state, obj_angle);
                        this->scenario_object_flag = 0;
                    }
                    ++j;
                } while (j < object_count);
            }
            ++outer;
            ++map;
        } while (outer < scenario_player_num);
    }
    this->next_object_id = next_object_id;
    rge_read(handle, &scenario_player_num, 4);
    i = 1;
    if (scenario_player_num > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i < this->player_num && *map > -1 && this->players[*map] != 0) {
                this->players[*map]->scenario_postload(handle, player_id_hash, 1.11f);
            } else {
                this->players[0]->scenario_postload(handle, player_id_hash, 1.11f);
            }
            ++i;
            ++map;
        } while (i < scenario_player_num);
    }
    rge_close(handle);
    i = 1;
    if (this->player_num > 1) {
        do {
            if (i < scenario_player_num) {
                if (this->players[i] != 0 && player_id_hash[i] > -1) {
                    int s = i - 1;
                    this->players[player_id_hash[i]]->loadAIInformation(
                        this->scenario->Get_BuildList(s, 1),
                        this->scenario->Get_CityPlan(s, 1),
                        this->scenario->Get_player_AI(s, 1),
                        this->scenario->GetPlayerPosture(s), -1);
                }
            } else {
                return;
            }
            ++i;
        } while (i < this->player_num);
    }
}

void RGE_Game_World::selectNextComputerPlayer(int param_1) {
    int current = this->currentUpdateComputerPlayer;
    if (current == -1) {
        int i = 0;
        int n = this->player_num;
        if (i < n) {
            RGE_Player** ptr = this->players;
            for (; i < n; ++i, ++ptr) {
                if ((*ptr)->type == param_1) {
                    this->currentUpdateComputerPlayer = i;
                    return;
                }
            }
        }
        return;
    }

    int n = this->player_num;
    int start = this->currentUpdateComputerPlayer;
    int counter = 0;
    if (start >= n)
        return;
    while (start < n) {
        if (counter >= n)
            return;
        RGE_Player* p = this->players[start];
        if (p->type == param_1 && start != this->currentUpdateComputerPlayer) {
            this->currentUpdateComputerPlayer = start;
            return;
        }
        start = (start + 1) % n;
        ++counter;
    }
}

void RGE_Game_World::useComputerPlayerUpdateTime(unsigned long amount) {
    if (this->availableComputerPlayerUpdateTime < amount) {
        this->availableComputerPlayerUpdateTime = 0;
    } else {
        this->availableComputerPlayerUpdateTime -= amount;
    }
}

int RGE_Game_World::computerPlayerUpdateTimeAvailable() {
    return 0 < this->availableComputerPlayerUpdateTime;
}

int RGE_Game_World::objectGroupOnTile(int owner_id, int object_group, int tile_x, int tile_y, int& output)
{
    if (tile_x >= 0) {
        if (tile_y >= 0) {
            RGE_Map* map = this->map;
            if (tile_x < map->map_width) {
                if (tile_y < map->map_height) {
                    output = map->map_row_offset[tile_y][tile_x].objects.number_of_objects;
                    RGE_Object_Node* node = this->map->map_row_offset[tile_y][tile_x].objects.list;
                    if (node != 0) {
                        RGE_Static_Object* object;
                        while (node != 0) {
                            object = node->node;
                            if (object == 0) {
                                break;
                            }
                            if ((owner_id == -1 || object->owner->id == owner_id) &&
                                object->master_obj->object_group == object_group) {
                                return object->id;
                            }
                            node = node->next;
                        }
                    }
                    return -1;
                }
            }
        }
    }
    output = 0;
    return -1;
}

int RGE_Game_World::difficultyLevel(void) {
    if (this->difficultyLevelValue == -1) {
        this->difficultyLevelValue = rge_base_game->difficulty();
    }
    return this->difficultyLevelValue;
}

RGE_Scenario* RGE_Game_World::get_scenario_info(char* file) { return 0; }

int RGE_Game_World::maxNumberObjects() { return this->maxNumberObjectsValue; }

int RGE_Game_World::maxNumberNegativeObjects() {
    return this->maxNumberNegativeObjectsValue;
}

int RGE_Game_World::numberObjects() { return this->numberObjectsValue; }

int RGE_Game_World::numberNegativeObjects() {
    return this->numberNegativeObjectsValue;
}

RGE_Static_Object* RGE_Game_World::object(int index) {
    int neg_index;
    if (index < 0) {
        neg_index = -index;
        if (neg_index < this->maxNumberNegativeObjectsValue) {
            return this->negativeObjectsValue[neg_index];
        }
    }
    if (index > -1 && index < this->maxNumberObjectsValue) {
        return this->objectsValue[index];
    }
    return 0;
}

RGE_Static_Object* RGE_Game_World::object_ptr(int index) {
    return object(index);
}

long RGE_Game_World::get_next_object_id() {
    if (!this->scenario_object_flag) {
        for (; this->maxNumberObjectsValue - 1 >= this->next_object_id &&
               this->objectsValue[this->next_object_id] != 0;
             this->next_object_id++) {}

        int result = this->next_object_id;
        this->next_object_id = result + 1;
        return result;
    }
    return this->scenario_object_id;
}

long RGE_Game_World::get_next_reusable_object_id() {
    if (this->scenario_object_flag) {
        if (this->scenario_object_id < this->next_reusable_object_id) {
            this->next_reusable_object_id = this->scenario_object_id - 1;
        }
        return this->scenario_object_id;
    }

    return this->next_reusable_object_id--;
}

int RGE_Game_World::addObject(RGE_Static_Object* obj)
{
    int newMax;
    RGE_Static_Object** newList;
    int i;
    int id = obj->id;
    if (id >= 0) {
        if (this->maxNumberObjectsValue - 1 < id) {
            newMax = this->maxNumberObjectsValue * 2;
            if (newMax < id) {
                newMax = (float)id * 1.5f;
            }
            newList = new RGE_Static_Object*[newMax];
            if (newList == 0) return 0;
            i = 0;
            if (this->maxNumberObjectsValue > 0) {
                do {
                    newList[i] = this->objectsValue[i];
                    i++;
                } while (i < this->maxNumberObjectsValue);
            }
            if (i < newMax) {
                for (; i < newMax; i++) {
                    newList[i] = 0;
                }
            }
            delete[] this->objectsValue;
            this->objectsValue = newList;
            VIS_UNIT_objectsValue = newList;
            this->maxNumberObjectsValue = newMax;
        }
        RGE_Static_Object* old = this->objectsValue[obj->id];
        this->objectsValue[obj->id] = obj;
        this->numberObjectsValue++;
        if (old != 0 && this->scenario_object_flag != 0) {
            this->scenario_object_flag = 0;
            old->change_unique_id();
            return 1;
        }
    } else {
        int slot = -id;
        if (this->maxNumberNegativeObjectsValue - 1 < slot) {
            newMax = this->maxNumberNegativeObjectsValue * 2;
            if (newMax < slot) {
                newMax = (float)slot * 1.5f;
            }
            newList = new RGE_Static_Object*[newMax];
            if (newList == 0) return 0;
            i = 0;
            if (this->maxNumberNegativeObjectsValue > 0) {
                do {
                    newList[i] = this->negativeObjectsValue[i];
                    i++;
                } while (i < this->maxNumberNegativeObjectsValue);
            }
            if (i < newMax) {
                for (; i < newMax; i++) {
                    newList[i] = 0;
                }
            }
            delete[] this->negativeObjectsValue;
            this->negativeObjectsValue = newList;
            this->maxNumberNegativeObjectsValue = newMax;
        }
        this->negativeObjectsValue[slot] = obj;
        this->numberNegativeObjectsValue++;
    }
    return 1;
}

int RGE_Game_World::removeObject(int param_1) {
    int edx = param_1;

    if (edx < 0) {
        int esi = this->maxNumberNegativeObjectsValue;
        int eax = edx;
        eax = -eax;
        if (eax < esi) {
            this->negativeObjectsValue[eax] = 0;
            return 1;
        }
    }
    if ((edx > -1) && (edx < this->maxNumberObjectsValue)) {
        this->objectsValue[edx] = 0;
        return 1;
    }
    return 0;
}

int RGE_Game_World::initializePathingSystem(void) {
    RGE_Map* pRVar1 = this->map;
    if (pRVar1 == 0) {
        return 0;
    }

    pathSystem.initialize(pRVar1->map_width, pRVar1->map_height, pRVar1, this);
    pRVar1 = this->map;
    aiPathSystem.initialize(pRVar1->map_width, pRVar1->map_height, pRVar1, this);
    return 1;
}

unsigned char RGE_Game_World::recycle_object_out_of_game(unsigned char param_1, RGE_Static_Object* param_2) {
    switch (param_1) {
    case 0x0A:
        reusable_static_objects->add_node(param_2);
        return 1;
    case 0x14:
        reusable_animated_objects->add_node(param_2);
        return 1;
    case 0x1E:
        reusable_moving_objects->add_node(param_2);
        return 1;
    case 0x28:
        reusable_action_objects->add_node(param_2);
        return 1;
    case 0x32:
        reusable_combat_objects->add_node(param_2);
        return 1;
    case 0x3C:
        reusable_missile_objects->add_node(param_2);
        return 1;
    case 0x19:
        reusable_doppleganger_objects->add_node(param_2);
        return 1;
    default:
        return 0;
    }
}

RGE_Static_Object* RGE_Game_World::recycle_object_in_to_game(unsigned char param_1) {
    RGE_Static_Object* result = 0;
    RGE_Object_List* lst;
    RGE_Object_Node* nod;

    switch (param_1) {
    case 0x0A:
        lst = this->reusable_static_objects;
        nod = lst->list;
        if (nod) {
            result = nod->node;
            lst->remove_node(result, 0);
            return result;
        }
        break;

    case 0x14:
        lst = this->reusable_animated_objects;
        nod = lst->list;
        if (nod) {
            result = nod->node;
            lst->remove_node(result, 0);
            return result;
        }
        break;

    case 0x1E:
        lst = this->reusable_moving_objects;
        nod = lst->list;
        if (nod) {
            result = nod->node;
            lst->remove_node(result, 0);
            return result;
        }
        break;

    case 0x28:
        lst = this->reusable_action_objects;
        nod = lst->list;
        if (nod) {
            result = nod->node;
            lst->remove_node(result, 0);
            return result;
        }
        break;

    case 0x32:
        lst = this->reusable_combat_objects;
        nod = lst->list;
        if (nod) {
            result = nod->node;
            lst->remove_node(result, 0);
            return result;
        }
        break;

    case 0x3C:
        lst = this->reusable_missile_objects;
        nod = lst->list;
        if (nod) {
            result = nod->node;
            lst->remove_node(result, 0);
            return result;
        }
        break;

    case 0x19:
        lst = this->reusable_doppleganger_objects;
        nod = lst->list;
        if (nod) {
            result = nod->node;
            lst->remove_node(result, 0);
        }
        break;
    }

    return result;
}

static const char s_update_visibilities[] =
    "updating player visibilities @ wt=%d\n";
static const char s_player[] = "player %d\n";
static const char s_masks[] =
    "  mutualExploredMask = %8.8x   mutualVisibleMask = %8.8x   "
    "nonMutualVisibleMask = %8.8x\n";
static const char s_player_flags[] =
    "  allied_LOS_Enable = %d   allied_victory = %d \n";
static const char s_diplomacy[] = "  unitDiplomacy = [";
static const char s_mutual_allies[] = "  mututalAlly = [";
static const char s_removed_visible_bits[] = "  RemoveVisibleBits = [";
static const char s_decimal[] = "%d";
static const char s_separator[] = ", ";
static const char s_list_end[] = "]\n";

void RGE_Game_World::update_mutual_allies() {
    int one = 1;
    int i,j;
    int pNum, index;
    fprintf(DVlogf, s_update_visibilities, world_time);
    i=0;
    if (i < player_num) do {
        this->players[i]->mutualExploredMask=0;
        this->players[i]->mutualVisibleMask=0;
        this->players[i]->nonMutualVisibleMask=0;
        for (j=0; j<9; ++j) this->players[i]->RemoveVisibleBits[j]=0;
        int* mutual = this->players[i]->mutualAlly;
        j=0;
        do {
            if (j==i) {
                *mutual=1;
                this->players[i]->mutualVisibleMask = 1 << i;
                this->players[i]->mutualExploredMask = 1 << (i+16);
            } else *mutual=0;
            ++j;
            ++mutual;
        } while (j < 9);
        ++i;
    } while (i < player_num);

    {
        i = 1;
        if (i < player_num) do {
            if (players[i]->allied_LOS_Enable == one) {
                j = 1;
                if (j < player_num) do {
                    if (j != i) {
                        if (!players[i]->relations[j] && !players[j]->relations[i]) {
                            players[i]->mutualAlly[j] = one;
                            players[i]->mutualVisibleMask |= 1 << j;
                            players[i]->mutualExploredMask |= 1 << (j + 16);
                        }
                    }
                } while (++j < player_num);
            }
            ++i;
        } while (i < player_num);
    }

    for (i=0; i < player_num; ++i) {
        for (pNum=one; pNum < player_num; ++pNum) {
            if (pNum != i && players[i]->mutualAlly[pNum] == 0) {
                for (index=one; index < player_num; ++index) {
                    if (players[i]->mutualAlly[index] == 0 &&
                        players[index]->mutualAlly[pNum] == 1 &&
                        players[index]->mutualAlly[i] == 1) {
                        players[i]->nonMutualVisibleMask |= 1 << pNum;
                        players[i]->RemoveVisibleBits[pNum] |= 1 << index;
                    }
                }
            }
        }
    }

    for (i=0;i<player_num;i++) {
        fprintf(DVlogf, s_player, i);
        fprintf(DVlogf, s_masks, players[i]->mutualExploredMask, players[i]->mutualVisibleMask, players[i]->nonMutualVisibleMask);
        fprintf(DVlogf, s_player_flags, players[i]->allied_LOS_Enable, players[i]->culture);
        fprintf(DVlogf, s_diplomacy);
        for (j=0;j<9;j++) {
            fprintf(DVlogf, s_decimal, players[i]->unitDiplomacy[j]);
            if (j < 8) fprintf(DVlogf, s_separator);
            else fprintf(DVlogf, s_list_end);
        }
        fprintf(DVlogf, s_mutual_allies);
        for (j=0;j<9;j++) {
            fprintf(DVlogf, s_decimal, players[i]->mutualAlly[j]);
            if (j < 8) fprintf(DVlogf, s_separator);
            else fprintf(DVlogf, s_list_end);
        }
        fprintf(DVlogf, s_removed_visible_bits);
        for (j=0;j<9;j++) {
            fprintf(DVlogf, s_decimal, players[i]->RemoveVisibleBits[j]);
            if (j < 8) fprintf(DVlogf, s_separator);
            else fprintf(DVlogf, s_list_end);
        }
    }
    TPanel* panel;
    if ((panel = rge_base_game->get_view_panel()) != 0)
        panel->set_redraw(TPanel::RedrawImmediate);
    if ((panel = rge_base_game->get_map_panel()) != 0)
        panel->set_redraw(TPanel::RedrawImmediate);
}
