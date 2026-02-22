#include "../include/RGE_Game_World.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Unified_Visible_Map.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Player_Info.h"
#include "../include/RGE_Map_Gen_Info.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Sound.h"
#include "../include/RGE_Effects.h"
#include "../include/RGE_Master_Player.h"
#include "../include/RGE_Command.h"
#include "../include/RGE_Base_Game.h"
#include "../include/PathingSystem.h"
#include "../include/RGE_Scenario.h"
#include "../include/TCommunications_Handler.h"
#include "../include/globals.h"
#include "../include/custom_debug.h"
#include "../include/debug_helpers.h"

#include <io.h>
#include <fcntl.h>
#include <share.h>
#include <stdio.h>
#include <string.h>

static void rge_world_load_scenario_common(RGE_Game_World* world, int fd, RGE_Player_Info* info,
                                           float scenario_version, int has_uncompressed_header) {
    if (world == nullptr || fd < 0) {
        return;
    }

    world_update_counter = 0;

    if (has_uncompressed_header != 0) {
        long header_size = 0;
        rge_read(fd, &header_size, 4);
        if (header_size > 0) {
            void* header_data = malloc((size_t)header_size);
            if (header_data == nullptr) {
                rge_close(fd);
                return;
            }
            rge_read(fd, header_data, (int)header_size);
            free(header_data);
        }
    }

    long scenario_player_num = 0;
    rge_read(fd, &scenario_player_num, 4);

    world->scenario_init(fd, world);
    world->scenario_make_map(fd);

    int player_id_map[9];
    for (int i = 0; i < 9; ++i) {
        player_id_map[i] = -1;
    }

    if (info != nullptr) {
        for (int i = 0; i < world->player_num && i < 9; ++i) {
            int hash = (int)info->player_id_hash[i];
            if (hash >= 0 && hash < 9) {
                player_id_map[hash] = i;
            }
        }
    } else {
        for (int i = 0; i < world->player_num && i < 9; ++i) {
            player_id_map[i] = i;
        }
    }

    world->reset_player_visible_maps();

    long preload_player_count = 0;
    rge_read(fd, &preload_player_count, 4);
    for (int scen_player = 1; scen_player < preload_player_count; ++scen_player) {
        int mapped = (scen_player >= 0 && scen_player < 9) ? player_id_map[scen_player] : -1;
        RGE_Player* player = nullptr;
        if (mapped >= 0 && mapped < world->player_num && world->players != nullptr) {
            player = world->players[mapped];
        }
        if (player == nullptr && world->players != nullptr && world->player_num > 0) {
            player = world->players[0];
        }
        if (player != nullptr) {
            player->scenario_load(fd, (long*)player_id_map, scenario_version);
        }
    }

    for (int scen_player = 0; scen_player < preload_player_count; ++scen_player) {
        long object_count = 0;
        rge_read(fd, &object_count, 4);
        for (int obj_idx = 0; obj_idx < object_count; ++obj_idx) {
            float world_x = 0.0f;
            float world_y = 0.0f;
            float world_z = 0.0f;
            long obj_id = 0;
            short master_id = 0;
            uchar obj_state = 0;
            float obj_angle = 0.0f;

            rge_read(fd, &world_x, 4);
            rge_read(fd, &world_y, 4);
            rge_read(fd, &world_z, 4);
            rge_read(fd, &obj_id, 4);
            rge_read(fd, &master_id, 2);
            rge_read(fd, &obj_state, 1);
            rge_read(fd, &obj_angle, 4);

            int mapped = (scen_player >= 0 && scen_player < 9) ? player_id_map[scen_player] : -1;
            if (mapped >= 0 && mapped < world->player_num && world->players != nullptr && world->players[mapped] != nullptr) {
                world->scenario_object_flag = '\x01';
                world->scenario_object_id = obj_id;
                world->players[mapped]->make_scenario_obj(world_x, world_y, world_z, master_id, obj_state, obj_angle);
                world->scenario_object_flag = '\0';
            }
        }
    }

    rge_read(fd, &world->next_object_id, 4);

    long postload_player_count = 0;
    rge_read(fd, &postload_player_count, 4);
    for (int scen_player = 1; scen_player < postload_player_count; ++scen_player) {
        int mapped = (scen_player >= 0 && scen_player < 9) ? player_id_map[scen_player] : -1;
        RGE_Player* player = nullptr;
        if (mapped >= 0 && mapped < world->player_num && world->players != nullptr) {
            player = world->players[mapped];
        }
        if (player == nullptr && world->players != nullptr && world->player_num > 0) {
            player = world->players[0];
        }
        if (player != nullptr) {
            player->scenario_postload(fd, (long*)player_id_map, scenario_version);
        }
    }

    if (world->scenario != nullptr && world->players != nullptr) {
        for (int scen_player = 1; scen_player < world->player_num && scen_player < postload_player_count; ++scen_player) {
            int mapped = (scen_player >= 0 && scen_player < 9) ? player_id_map[scen_player] : -1;
            int scenario_idx = scen_player - 1;
            if (mapped >= 0 && mapped < world->player_num && world->players[mapped] != nullptr &&
                scenario_idx >= 0 && scenario_idx < 16) {
                world->players[mapped]->loadAIInformation(
                    world->scenario->BuildList[scenario_idx],
                    world->scenario->CityPlan[scenario_idx],
                    world->scenario->AiRules[scenario_idx],
                    world->scenario->PlayerPosture[scenario_idx],
                    -1);
            }
        }
    }

    rge_close(fd);
}

// Forward declarations for types used in function signatures
class RGE_Static_Object;
class TCommunications_Handler;
struct TSound_Driver;
class RGE_Scenario;

// Constructor — zero-init all members
RGE_Game_World::RGE_Game_World() {
    this->world_time = 0;
    this->old_world_time = 0;
    this->world_time_delta = 0;
    this->timer = 0.0f;
    this->old_time = 0;
    this->game_speed = 1.5f;
    this->temp_pause = 0;
    this->game_state = 0;
    this->game_end_condition = 0;
    this->sound_update_index = 0;
    this->sprite_update_index = 0;
    this->map = nullptr;
    this->sound_num = 0;
    this->sounds = nullptr;
    this->sprite_num = 0;
    this->sprites = nullptr;
    this->player_num = 0;
    this->players = nullptr;
    this->master_player_num = 0;
    this->master_players = nullptr;
    this->effects = nullptr;
    this->terrain_num = 0;
    this->terrain_size = 0;
    this->terrains = nullptr;
    this->commands = nullptr;
    this->scenario = nullptr;
    this->color_table_num = 0;
    this->color_tables = nullptr;
    this->next_object_id = 0;
    this->next_reusable_object_id = 0;
    this->scenario_object_id = 0;
    this->scenario_object_flag = 0;
    this->random_seed = 0;
    this->curr_player = 0;
    this->sound_driver = nullptr;
    this->world_time_delta_seconds = 0.0f;
    this->objectsValue = nullptr;
    this->numberObjectsValue = 0;
    this->maxNumberObjectsValue = 0;
    this->negativeObjectsValue = nullptr;
    this->numberNegativeObjectsValue = 0;
    this->maxNumberNegativeObjectsValue = 0;
    this->playbook = nullptr;
    this->campaign = 0;
    this->campaign_player = 0;
    this->campaign_scenario = 0;
    this->player_turn = 0;
    memset(this->player_time_delta, 0, sizeof(this->player_time_delta));
    this->reusable_static_objects = nullptr;
    this->reusable_animated_objects = nullptr;
    this->reusable_moving_objects = nullptr;
    this->reusable_action_objects = nullptr;
    this->reusable_combat_objects = nullptr;
    this->reusable_missile_objects = nullptr;
    this->reusable_doppleganger_objects = nullptr;
    this->maximumComputerPlayerUpdateTime = 0;
    this->availableComputerPlayerUpdateTime = 0;
    this->currentUpdateComputerPlayer = 0;
    this->difficultyLevelValue = 0;
}

// Stub implementations for RGE_Game_World virtual methods
// TODO: implement actual logic for each method (see worldload.cpp.asm, world.cpp.asm, etc.)

// Data loading virtuals
uchar RGE_Game_World::data_load_world(FILE* param_1) {
    // TODO: implement (see worldload.cpp.asm)
    return 1;
}

uchar RGE_Game_World::data_load_terrain_tables(char* param_1) {
    // TODO: implement
    return 1;
}

uchar RGE_Game_World::data_load_players(char* param_1) {
    // TODO: implement
    return 1;
}

uchar RGE_Game_World::data_load_objects(char* param_1) {
    // TODO: implement
    return 1;
}

uchar RGE_Game_World::data_load_sounds(char* param_1) {
    // TODO: implement
    return 1;
}

uchar RGE_Game_World::data_load_color_tables(char* param_1) {
    // TODO: implement
    return 1;
}

uchar RGE_Game_World::data_load_sprites(char* param_1) {
    // TODO: implement
    return 1;
}

void RGE_Game_World::data_load_players_type(short param_1, short param_2, FILE* param_3) {
    // TODO: implement
}

void RGE_Game_World::data_load_effects(char* param_1) {
    // TODO: implement
}

void RGE_Game_World::data_load_map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8, char* param_9) {
    // TODO: implement
}

void RGE_Game_World::data_load_random_map(char* param_1, char* param_2, char* param_3, char* param_4) {
    // TODO: implement
}

// Initialization virtuals
uchar RGE_Game_World::init_player_type(int param_1, short param_2, uchar param_3) {
    if (param_3 == '\0') {
        RGE_Master_Player* mp = new RGE_Master_Player(param_1);
        if (this->master_players != nullptr && param_2 >= 0 && param_2 < this->master_player_num) {
            this->master_players[param_2] = mp;
            if (mp != nullptr) {
                mp->finish_init(param_1, this->sprites, this->sounds);
                int non_null = 0;
                for (short i = 0; i < mp->master_object_num; ++i) {
                    if (mp->master_objects != nullptr && mp->master_objects[i] != nullptr) {
                        non_null = non_null + 1;
                    }
                }
                CUSTOM_DEBUG_LOG_FMT(
                    "RGE_Game_World::init_player_type idx=%d type=%u master_object_num=%d loaded=%d",
                    (int)param_2,
                    (unsigned int)param_3,
                    (int)mp->master_object_num,
                    non_null);
            }
        }
    } else {
        CUSTOM_DEBUG_LOG_FMT(
            "RGE_Game_World::init_player_type idx=%d type=%u (not handled by base)",
            (int)param_2,
            (unsigned int)param_3);
    }
    return 1;
}

uchar RGE_Game_World::init_player(int param_1) {
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::init_player begin stream_pos=%ld", rge_stream_tell(param_1));
    short* count = &this->master_player_num;
    rge_read(param_1, count, 2);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::init_player read master_player_num=%d stream_pos=%ld", (int)*count, rge_stream_tell(param_1));
    if (*count > 0) {
        this->master_players = (RGE_Master_Player**)calloc((int)*count, sizeof(RGE_Master_Player*));
        for (short i = 0; i < *count; ++i) {
            uchar player_type = 0;
            rge_read(param_1, &player_type, 1);
            CUSTOM_DEBUG_LOG_FMT(
                "RGE_Game_World::init_player slot=%d type=%u stream_pos=%ld",
                (int)i,
                (unsigned int)player_type,
                rge_stream_tell(param_1));
            this->init_player_type(param_1, i, player_type);
        }
    }
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::init_player end stream_pos=%ld", rge_stream_tell(param_1));
    return 1;
}

void RGE_Game_World::load_player(int param_1, uchar param_2, short param_3) {
    // TODO: implement
}

void RGE_Game_World::color_table_init(int fd) {
    if (fd <= 0) return;
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::color_table_init fd=%d stream_pos=%ld", fd, rge_stream_tell(fd));
    rge_read(fd, &this->color_table_num, 2);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::color_table_init: color_table_num=%d stream_pos=%ld", (int)this->color_table_num, rge_stream_tell(fd));
    if (this->color_table_num > 0) {
        this->color_tables = (RGE_Color_Table**)calloc(this->color_table_num, sizeof(RGE_Color_Table*));
        for (short i = 0; i < this->color_table_num; i++) {
            this->color_tables[i] = new RGE_Color_Table(fd);
        }
    }
}

void RGE_Game_World::terrain_tables_init(int fd) {
    if (fd <= 0) return;
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::terrain_tables_init fd=%d stream_pos=%ld", fd, rge_stream_tell(fd));
    rge_read(fd, &this->terrain_num, 2);
    rge_read(fd, &this->terrain_size, 2);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::terrain_tables_init: terrain_num=%d terrain_size=%d stream_pos=%ld",
        (int)this->terrain_num, (int)this->terrain_size, rge_stream_tell(fd));
    if (this->terrain_num > 0 && this->terrain_size > 0) {
        // Source of truth: world.cpp.decomp @ 0x00541880.
        // Serialized data stores pointer-presence flags first, then optional float tables.
        this->terrains = (float**)calloc(this->terrain_num, sizeof(float*));
        rge_read(fd, this->terrains, (long)this->terrain_num * (long)sizeof(float*));
        for (short i = 0; i < this->terrain_num; i++) {
            if (this->terrains[i] != nullptr) {
                this->terrains[i] = (float*)calloc(this->terrain_size, sizeof(float));
                rge_read(fd, this->terrains[i], (long)this->terrain_size * (long)sizeof(float));
            }
        }
    }
}

void RGE_Game_World::init_sounds(int fd, TSound_Driver* param_2) {
    if (fd <= 0) return;
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::init_sounds fd=%d stream_pos=%ld", fd, rge_stream_tell(fd));
    rge_read(fd, &this->sound_num, 2);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::init_sounds: sound_num=%d stream_pos=%ld", (int)this->sound_num, rge_stream_tell(fd));
    if (this->sound_num > 0) {
        this->sounds = (RGE_Sound**)calloc(this->sound_num, sizeof(RGE_Sound*));
        for (short i = 0; i < this->sound_num; i++) {
            this->sounds[i] = new RGE_Sound(fd, param_2);
        }
    }
}

void RGE_Game_World::init_sprites(int fd) {
    if (fd <= 0) return;
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::init_sprites fd=%d stream_pos=%ld", fd, rge_stream_tell(fd));
    rge_read(fd, &this->sprite_num, 2);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::init_sprites: sprite_num=%d stream_pos=%ld", (int)this->sprite_num, rge_stream_tell(fd));
    if (this->sprite_num <= 0) {
        this->sprites = nullptr;
        return;
    }

    // Source of truth: world.cpp.decomp @ 0x00541A80.
    // Read serialized sprite pointer flags first; only non-null entries are materialized.
    this->sprites = (RGE_Sprite**)calloc(this->sprite_num, sizeof(RGE_Sprite*));
    rge_read(fd, this->sprites, (long)this->sprite_num * (long)sizeof(RGE_Sprite*));

    for (short i = 0; i < this->sprite_num; i++) {
        if (this->sprites[i] != nullptr) {
            this->sprites[i] = new RGE_Sprite(fd, this->sounds, this->color_tables);
        }
    }

    for (short i = 0; i < this->sprite_num; i++) {
        if (this->sprites[i] != nullptr) {
            this->sprites[i]->rehook(this->sprites);
        }
    }
}

void RGE_Game_World::map_init(int fd, TSound_Driver* param_2) {
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::map_init fd=%d stream_pos=%ld", fd, rge_stream_tell(fd));
    if (this->map) delete this->map;
    this->map = new RGE_Map(fd, this->sounds, 1);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::map_init done stream_pos=%ld", rge_stream_tell(fd));
}

void RGE_Game_World::effects_init(int fd) {
    if (fd <= 0) return;
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::effects_init fd=%d stream_pos=%ld", fd, rge_stream_tell(fd));
    this->effects = new RGE_Effects(fd);
    CUSTOM_DEBUG_LOG_FMT(
        "RGE_Game_World::effects_init done effect_num=%ld stream_pos=%ld",
        (this->effects != nullptr) ? this->effects->effect_num : -1,
        rge_stream_tell(fd));
}

void RGE_Game_World::master_player_init(int fd) {
    if (fd <= 0) return;
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::master_player_init fd=%d stream_pos=%ld", fd, rge_stream_tell(fd));
    this->init_player(fd);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::master_player_init: master_player_num=%d stream_pos=%ld", (int)this->master_player_num, rge_stream_tell(fd));
}

void RGE_Game_World::command_init(int fd, TCommunications_Handler* param_2) {
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::command_init fd=%d stream_pos=%ld", fd, (fd > 0 ? rge_stream_tell(fd) : -1L));
    this->commands = new RGE_Command(this, param_2);
}

void RGE_Game_World::world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) {
    // Inferred from TRIBE_World::world_init override pattern and call chain.
    // param_1 = file descriptor from data_load (or 0 if stub)
    // param_2 = TSound_Driver*
    // param_3 = TCommunications_Handler*
    //
    // Calls sub-init functions which TRIBE_World overrides to create TRIBE-specific types.
    // Source of truth: world.cpp.decomp @ 0x00541D60.
    // vtable order call sequence is terrain first, then color.
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::world_init begin stream_pos=%ld", rge_stream_tell(param_1));
    this->terrain_tables_init(param_1);
    this->color_table_init(param_1);
    this->init_sounds(param_1, param_2);
    this->init_sprites(param_1);
    this->map_init(param_1, param_2);
    this->effects_init(param_1);
    this->master_player_init(param_1);
    this->command_init(param_1, param_3);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::world_init end stream_pos=%ld", rge_stream_tell(param_1));
}

void RGE_Game_World::setup_gaia() {
    RGE_Master_Player* master = nullptr;
    if (this->master_players != nullptr && this->master_player_num > 0) {
        master = this->master_players[0];
    }

    RGE_Player* gaia = new RGE_Player(this, master, 0, (char*)"GAIA", 0, '\0', '\x01', nullptr, nullptr, nullptr);
    if (this->players != nullptr) {
        this->players[0] = gaia;
    }
}

void RGE_Game_World::setup_players(RGE_Player_Info* param_1) {
    if (param_1 == nullptr || this->players == nullptr) {
        return;
    }

    for (short i = 1; i < this->player_num; ++i) {
        char player_type = param_1->type[i - 1];
        if (player_type == -1) {
            continue;
        }

        uchar master_id = (uchar)param_1->tribe[i - 1];
        RGE_Master_Player* master = nullptr;
        if (this->master_players != nullptr && master_id < (uchar)this->master_player_num) {
            master = this->master_players[master_id];
        }

        this->players[i] = new RGE_Player(
            this,
            master,
            (uchar)i,
            param_1->name[i - 1],
            master_id,
            '\0',
            '\x01',
            nullptr,
            nullptr,
            nullptr);
    }
}

uchar RGE_Game_World::new_random_game(RGE_Player_Info* param_1) {
    // Source of truth: world.cpp.decomp @ 0x00542D10.
    CUSTOM_DEBUG_LOG("RGE_Game_World::new_random_game enter");
    if (param_1 == nullptr || this->map == nullptr) {
        return 0;
    }

    world_update_counter = 0;

    this->setup_player_colors(param_1);
    this->scenario_init(this);

    this->random_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x612);

    int player_count_minus_one = (int)this->player_num - 1;
    this->map->map_generate2(this, -1, -1, (uchar)param_1->map_type, player_count_minus_one);
    CUSTOM_DEBUG_LOG("RGE_Game_World::new_random_game after map_generate2");
    this->initializePathingSystem();

    this->random_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x61a);
    this->random_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x622);

    short saved_curr_player = this->curr_player;
    this->curr_player = -1;

    for (int pass = 0; pass < 3; ++pass) {
        CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::new_random_game update pass=%d", pass);
        world_update_counter = world_update_counter + 1;
        for (int i = 0; i < this->player_num; ++i) {
            CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::new_random_game updating player=%d", i);
            if (this->players != nullptr && this->players[i] != nullptr) {
                this->players[i]->update();
            }
        }
    }

    this->curr_player = saved_curr_player;
    this->random_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x631);
    CUSTOM_DEBUG_LOG("RGE_Game_World::new_random_game exit");
    return 1;
}

void RGE_Game_World::save(int param_1) {
    // TODO: implement
}

// Scenario loading virtuals
void RGE_Game_World::scenario_make_player(short param_1, uchar param_2, uchar param_3, uchar param_4, char* param_5) {
    // Source of truth: world.cpp.decomp @ 0x00544250
    (void)param_2;
    if (param_3 == '\0') {
        RGE_Master_Player* master = nullptr;
        if (this->master_players != nullptr && param_4 >= 0 && param_4 < this->master_player_num) {
            master = this->master_players[param_4];
        }
        RGE_Player* player = new RGE_Player(this, master, (uchar)param_1, param_5, param_4, '\0', '\x01',
                                            nullptr, nullptr, nullptr);
        if (this->players != nullptr && param_1 >= 0 && param_1 < this->player_num) {
            this->players[param_1] = player;
        } else if (player != nullptr) {
            delete player;
        }
    }
}

void RGE_Game_World::scenario_make_map(int param_1) {
    // Source of truth: world.cpp.decomp @ 0x005442E0
    if (this->map != nullptr) {
        this->map->scenario_load(param_1, nullptr);
    }
}

uchar RGE_Game_World::load_scenario(RGE_Player_Info* param_1) {
    // Source of truth: world.cpp.decomp @ 0x00544090
    world_update_counter = 0;
    if (rge_base_game == nullptr) {
        return 0;
    }

    int fd = rge_base_game->campaign_open_scenario();
    if (fd == -1) {
        return 0;
    }

    char version_tag[4];
    rge_read(fd, version_tag, 4);

    if (memcmp(version_tag, "1.01", 4) == 0) {
        this->load_scenario1(fd, param_1);
    } else if (memcmp(version_tag, "1.02", 4) == 0) {
        this->load_scenario2(fd, param_1);
    } else if (memcmp(version_tag, "1.03", 4) == 0) {
        long header_size = 0;
        rge_read(fd, &header_size, 4);
        if (header_size > 0) {
            void* header = malloc((size_t)header_size);
            if (header == nullptr) {
                rge_close(fd);
                return 0;
            }
            rge_read(fd, header, (int)header_size);
            free(header);
        }
        this->load_scenario2(fd, param_1);
    } else if (memcmp(version_tag, "1.04", 4) == 0) {
        this->load_scenario4(fd, param_1);
    } else if (memcmp(version_tag, "1.05", 4) == 0) {
        this->load_scenario5(fd, param_1);
    } else if (memcmp(version_tag, "1.06", 4) == 0) {
        this->load_scenario6(fd, param_1);
    } else if (memcmp(version_tag, "1.07", 4) == 0) {
        this->load_scenario7(fd, param_1);
    } else if (memcmp(version_tag, "1.08", 4) == 0 ||
               memcmp(version_tag, "1.09", 4) == 0 ||
               memcmp(version_tag, "1.10", 4) == 0 ||
               memcmp(version_tag, "1.11", 4) == 0) {
        this->load_scenario8(fd, param_1);
    } else {
        rge_close(fd);
        return 0;
    }

    this->setup_player_colors(param_1);
    rge_base_game->get_campaign_info(&this->campaign, &this->campaign_player, &this->campaign_scenario);
    return 1;
}

uchar RGE_Game_World::load_scenario(char* param_1, RGE_Player_Info* param_2) {
    // Source of truth: world.cpp.decomp @ 0x00543E00
    world_update_counter = 0;
    if (param_1 == nullptr || rge_base_game == nullptr || rge_base_game->prog_info == nullptr) {
        return 0;
    }

    char scenario_name[300];
    memset(scenario_name, 0, sizeof(scenario_name));
    sprintf(scenario_name, "%s%s", rge_base_game->prog_info->scenario_dir, param_1);

    int fd = rge_open(scenario_name, _O_RDONLY | _O_BINARY);
    if (fd == -1) {
        return 0;
    }

    char version_tag[4];
    memset(version_tag, 0, sizeof(version_tag));
    rge_read(fd, version_tag, 4);

    if (memcmp(version_tag, "1.01", 4) == 0) {
        this->load_scenario1(fd, param_2);
    } else if (memcmp(version_tag, "1.02", 4) == 0) {
        this->load_scenario2(fd, param_2);
    } else if (memcmp(version_tag, "1.03", 4) == 0) {
        long header_size = 0;
        rge_read(fd, &header_size, 4);
        if (header_size > 0) {
            void* temp = malloc((size_t)header_size);
            if (temp == nullptr) {
                rge_close(fd);
                return 0;
            }
            rge_read(fd, temp, (int)header_size);
            free(temp);
        }
        this->load_scenario2(fd, param_2);
    } else if (memcmp(version_tag, "1.04", 4) == 0) {
        this->load_scenario4(fd, param_2);
    } else if (memcmp(version_tag, "1.05", 4) == 0) {
        this->load_scenario5(fd, param_2);
    } else if (memcmp(version_tag, "1.06", 4) == 0) {
        this->load_scenario6(fd, param_2);
    } else if (memcmp(version_tag, "1.07", 4) == 0) {
        this->load_scenario7(fd, param_2);
    } else if (memcmp(version_tag, "1.08", 4) == 0 ||
               memcmp(version_tag, "1.09", 4) == 0 ||
               memcmp(version_tag, "1.10", 4) == 0 ||
               memcmp(version_tag, "1.11", 4) == 0) {
        this->load_scenario8(fd, param_2);
    } else {
        rge_close(fd);
        return 0;
    }

    this->setup_player_colors(param_2);
    return 1;
}

void RGE_Game_World::load_scenario1(int param_1, RGE_Player_Info* param_2) {
    // Source of truth: world.cpp.decomp @ 0x00544300
    rge_world_load_scenario_common(this, param_1, param_2, 1.0f, 0);
}

void RGE_Game_World::load_scenario2(int param_1, RGE_Player_Info* param_2) {
    // Source of truth: world.cpp.decomp @ 0x005445C0
    rge_world_load_scenario_common(this, param_1, param_2, 1.03f, 0);
}

void RGE_Game_World::load_scenario3(int param_1, RGE_Player_Info* param_2) {
    // Source of truth: world.cpp.decomp @ 0x00544880
    rge_world_load_scenario_common(this, param_1, param_2, 1.04f, 1);
}

void RGE_Game_World::load_scenario4(int param_1, RGE_Player_Info* param_2) {
    // Source of truth: world.cpp.decomp @ 0x00544B90
    rge_world_load_scenario_common(this, param_1, param_2, 1.06f, 1);
}

void RGE_Game_World::load_scenario5(int param_1, RGE_Player_Info* param_2) {
    // Source of truth: world.cpp.decomp @ 0x00544E70
    rge_world_load_scenario_common(this, param_1, param_2, 1.06f, 1);
}

void RGE_Game_World::load_scenario6(int param_1, RGE_Player_Info* param_2) {
    // Source of truth: world.cpp.decomp @ 0x005451A0
    rge_world_load_scenario_common(this, param_1, param_2, 1.07f, 1);
}

void RGE_Game_World::load_scenario7(int param_1, RGE_Player_Info* param_2) {
    // Source of truth: world.cpp.decomp @ 0x005454D0
    rge_world_load_scenario_common(this, param_1, param_2, 1.08f, 1);
}

void RGE_Game_World::load_scenario8(int param_1, RGE_Player_Info* param_2) {
    // Source of truth: world.cpp.decomp @ 0x00545800
    rge_world_load_scenario_common(this, param_1, param_2, 1.11f, 1);
}

void RGE_Game_World::logStatus(FILE* param_1, int param_2) {
    // TODO: implement
}

// Destructor
RGE_Game_World::~RGE_Game_World() {
    // Clean up allocated arrays. Since most are stubs returning null,
    // only free what was actually allocated.
    if (this->players) {
        for (short i = 0; i < this->player_num; i++) {
            if (this->players[i]) {
                delete this->players[i];
            }
        }
        free(this->players);
        this->players = nullptr;
    }
    if (this->master_players) {
        for (short i = 0; i < this->master_player_num; i++) {
            if (this->master_players[i]) {
                delete this->master_players[i];
            }
        }
        free(this->master_players);
        this->master_players = nullptr;
    }
    if (this->sounds) {
        for (short i = 0; i < this->sound_num; i++) {
            if (this->sounds[i]) delete this->sounds[i];
        }
        free(this->sounds);
        this->sounds = nullptr;
    }
    if (this->sprites) {
        for (short i = 0; i < this->sprite_num; i++) {
            if (this->sprites[i]) delete this->sprites[i];
        }
        free(this->sprites);
        this->sprites = nullptr;
    }
    if (this->terrains) {
        for (short i = 0; i < this->terrain_num; i++) {
            if (this->terrains[i]) free(this->terrains[i]);
        }
        free(this->terrains);
        this->terrains = nullptr;
    }
    if (this->color_tables) {
        for (short i = 0; i < this->color_table_num; i++) {
            if (this->color_tables[i]) delete this->color_tables[i];
        }
        free(this->color_tables);
        this->color_tables = nullptr;
    }
    if (this->objectsValue) {
        free(this->objectsValue);
        this->objectsValue = nullptr;
    }
    if (this->negativeObjectsValue) {
        free(this->negativeObjectsValue);
        this->negativeObjectsValue = nullptr;
    }
    if (this->map) {
        delete this->map;
        this->map = nullptr;
    }
    if (this->effects) {
        delete this->effects;
        this->effects = nullptr;
    }
    if (this->commands) {
        delete this->commands;
        this->commands = nullptr;
    }
    if (this->scenario) {
        delete this->scenario;
        this->scenario = nullptr;
    }
    // playbook, reusable_* lists — not yet allocated by stubs
}

// Utility virtuals
void RGE_Game_World::setup_player_colors() {
    if (this->players == nullptr || this->player_num <= 0) {
        return;
    }

    if (this->players[0] != nullptr) {
        this->players[0]->set_color_table('\a');
    }

    if (this->color_table_num <= 0 || this->color_tables == nullptr) {
        return;
    }

    uchar* colors_used = (uchar*)calloc((int)this->color_table_num, 1);
    if (colors_used == nullptr) {
        return;
    }

    int color_cursor = -1;
    for (int i = 1; i < this->player_num; ++i) {
        if (this->players[i] == nullptr) {
            continue;
        }

        int guard = 0;
        do {
            color_cursor = color_cursor + 1;
            guard = guard + 1;
        } while (color_cursor < this->color_table_num &&
                 (colors_used[color_cursor] != 0 || this->color_tables[color_cursor] == nullptr || this->color_tables[color_cursor]->type != '\x01') &&
                 guard <= this->color_table_num);

        if (color_cursor >= this->color_table_num) {
            break;
        }

        this->players[i]->set_color_table((uchar)color_cursor);
        colors_used[color_cursor] = 1;
    }

    free(colors_used);
}

void RGE_Game_World::setup_player_colors(RGE_Player_Info* param_1) {
    if (this->players == nullptr || this->player_num <= 0) {
        return;
    }

    if (this->players[0] != nullptr) {
        this->players[0]->set_color_table('\a');
    }

    if (this->color_table_num <= 0 || this->color_tables == nullptr) {
        return;
    }

    int info_player_num = 0;
    if (param_1 != nullptr) {
        info_player_num = (int)param_1->player_num;
        int max_info = (int)this->player_num + 1;
        if (max_info < info_player_num) {
            info_player_num = max_info;
        }
    }

    uchar* colors_used = (uchar*)calloc((int)this->color_table_num, 1);
    uchar* players_done = (uchar*)calloc((int)this->player_num, 1);
    if (colors_used == nullptr || players_done == nullptr) {
        if (colors_used != nullptr) free(colors_used);
        if (players_done != nullptr) free(players_done);
        return;
    }

    for (int i = 1; i < this->player_num; ++i) {
        if (this->players[i] == nullptr || param_1 == nullptr) {
            continue;
        }

        short requested = param_1->color[i - 1];
        if ((i - 1) < info_player_num && requested >= 0 && requested < this->color_table_num && colors_used[requested] == 0) {
            this->players[i]->set_color_table((uchar)requested);
            colors_used[requested] = 1;
            players_done[i] = 1;
        }
    }

    int color_cursor = -1;
    for (int i = 1; i < this->player_num; ++i) {
        if (this->players[i] == nullptr || players_done[i] != 0) {
            continue;
        }

        while (1) {
            color_cursor = color_cursor + 1;
            if (color_cursor >= this->color_table_num) {
                break;
            }
            if (colors_used[color_cursor] != 0) {
                continue;
            }
            if (this->color_tables[color_cursor] == nullptr || this->color_tables[color_cursor]->type != '\x01') {
                continue;
            }
            break;
        }

        if (color_cursor >= this->color_table_num) {
            break;
        }

        this->players[i]->set_color_table((uchar)color_cursor);
        colors_used[color_cursor] = 1;
    }

    free(colors_used);
    free(players_done);
}

uchar RGE_Game_World::data_load(char* param_1, char* param_2) {
    // Source of truth: inferred from call chain. param_1 = "data2\\empires.dat".
    // Opens the binary game data file and stores the file descriptor.
    // The fd is then used by world_init → map_init → TRIBE_Map(fd, sounds, 1).
    //
    // We store the fd on data_load_fd (a member we track) so init() can pass it.
    // The actual binary parsing happens in map_init via rge_read.
    //
    // param_2 is the text-based world database file (tr_wrld.txt) — not used for binary path.
    return 1;
}

uchar RGE_Game_World::init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) {
    // Source of truth: world.cpp.decomp @ 0x00541DB0.
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::init enter file='%s'", (param_1 != nullptr) ? param_1 : "(null)");
    this->sound_driver = param_2;
    this->next_object_id = 0;

    int fd = rge_open(param_1, _O_RDONLY | _O_BINARY);
    if (fd == -1) {
        CUSTOM_DEBUG_LOG("RGE_Game_World::init: open failed");
        return 0;
    }

    char version[8];
    memset(version, 0, sizeof(version));
    rge_read(fd, version, 8);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::init: version bytes='%c%c%c%c%c%c%c%c' pos=%ld",
        version[0], version[1], version[2], version[3],
        version[4], version[5], version[6], version[7], _tell(fd));

    // Exact binary gate from original: file must begin with "VER 3.7\0".
    if (memcmp(version, "VER 3.7", 8) != 0) {
        CUSTOM_DEBUG_LOG("RGE_Game_World::init: version mismatch");
        rge_close(fd);
        return 0;
    }

    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::init: calling world_init fd=%d pos=%ld", fd, _tell(fd));
    this->world_init(fd, param_2, param_3);
    rge_close(fd);
    CUSTOM_DEBUG_LOG("RGE_Game_World::init: success");
    return 1;
}

void RGE_Game_World::turn_sound_off() {
    // Source of truth: world.cpp.decomp @ 0x00541DC0
    for (int i = 0; i < this->sound_num; ++i) {
        if (this->sounds != nullptr && this->sounds[i] != nullptr) {
            this->sounds[i]->stop();
        }
    }
}

void RGE_Game_World::del_game_info() {
    // Source of truth: world.cpp.decomp @ 0x00541EE0
    world_update_counter = 0;
    this->game_state = '\x02';
    this->game_end_condition = '\0';
    this->next_reusable_object_id = -1;
    this->campaign = -1;
    this->campaign_player = -1;
    this->campaign_scenario = -1;
    this->difficultyLevelValue = -1;
    this->next_object_id = 0;
    this->numberObjectsValue = 0;
    this->numberNegativeObjectsValue = 0;

    if (this->objectsValue != nullptr && this->maxNumberObjectsValue > 0) {
        memset(this->objectsValue, 0, (size_t)this->maxNumberObjectsValue * sizeof(RGE_Static_Object*));
    }
    if (this->negativeObjectsValue != nullptr && this->maxNumberNegativeObjectsValue > 0) {
        memset(this->negativeObjectsValue, 0, (size_t)this->maxNumberNegativeObjectsValue * sizeof(RGE_Static_Object*));
    }

    if (this->scenario != nullptr) {
        delete this->scenario;
        this->scenario = nullptr;
    }

    if (this->players != nullptr && this->player_num > 0) {
        for (int i = 0; i < this->player_num; ++i) {
            if (this->players[i] != nullptr) {
                delete this->players[i];
                this->players[i] = nullptr;
            }
        }
        free(this->players);
        this->players = nullptr;
    }
    this->player_num = 0;

    this->sound_update_index = 0;
    this->sprite_update_index = 0;
    this->player_turn = 0;
    for (int i = 0; i < 9; ++i) {
        this->player_time_delta[i] = 0;
    }
}

void RGE_Game_World::selectNextComputerPlayer(int param_1) {
    // Fully verified. Source of truth: world.cpp.decomp @ 0x00545B30
    int current = this->currentUpdateComputerPlayer;
    if (current == -1) {
        for (int i = 0; i < this->player_num; ++i) {
            if ((uint)this->players[i]->type == (uint)param_1) {
                this->currentUpdateComputerPlayer = i;
                return;
            }
        }
        return;
    }

    int player_count = (int)this->player_num;
    int checked = 0;
    int idx = current;
    if (current < player_count) {
        while (checked < player_count) {
            if ((uint)this->players[idx]->type == (uint)param_1 && idx != current) {
                this->currentUpdateComputerPlayer = idx;
                return;
            }
            idx = (idx + 1) % player_count;
            checked = checked + 1;
            if (player_count <= idx) {
                return;
            }
        }
    }
}

uchar RGE_Game_World::update() {
    // Source of truth: world.cpp.decomp / world.cpp.asm (update @ 0x00542ED0).
    // Keep timing/cycle flow close to original so single-player simulation advances.
    this->availableComputerPlayerUpdateTime = this->maximumComputerPlayerUpdateTime;

    int cycle_time = -1;
    if (this->commands != nullptr && this->commands->com_hand != nullptr) {
        cycle_time = this->commands->com_hand->DoCycle(this->world_time);
        if (cycle_time == 0) {
            this->world_time_delta = 0;
            this->world_time_delta_seconds = 0.0f;
            return this->game_state;
        }
    } else {
        cycle_time = 1;
    }

    const unsigned long now = GetTickCount();
    unsigned long elapsed_ms = 0;
    int first_tick = 0;

    if (cycle_time == -1) {
        if (this->old_time == 0) {
            first_tick = 1;
        } else {
            elapsed_ms = now - this->old_time;
            if (elapsed_ms > 100) {
                elapsed_ms = 100;
            }
        }
    } else {
        elapsed_ms = (unsigned long)cycle_time;
    }

    this->old_time = now;
    this->old_world_time = this->world_time;

    if (this->temp_pause == 0) {
        this->world_time += (unsigned long)((float)elapsed_ms * this->game_speed);
    } else {
        if (cycle_time != -1) {
            this->world_time += (unsigned long)((float)elapsed_ms * this->game_speed);
        }
        this->temp_pause = 0;
    }

    this->world_time_delta = this->world_time - this->old_world_time;
    if (this->world_time_delta != 0 || first_tick != 0) {
        this->commands->do_commands();
        this->scenario->update();

        this->world_time_delta_seconds = (float)this->world_time_delta * 0.001f;
        world_update_counter = world_update_counter + 1;

        if (this->players != nullptr) {
            for (short i = 0; i < this->player_num; ++i) {
                if (this->players[i] != nullptr) {
                    this->player_time_delta[i] = this->player_time_delta[i] + this->world_time_delta;
                    this->players[i]->update();
                    this->players[i]->tile_list.del_list();
                }
            }
        }

        // Keep the same per-tick player rotation bookkeeping used by the original.
        this->player_time_delta[this->player_turn] = 0;
        this->player_turn = this->player_turn + 1;
        if (this->player_turn >= this->player_num) {
            this->player_turn = 0;
        }

        this->check_game_state();
    } else {
        this->world_time_delta_seconds = 0.0f;
    }

    this->random_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x71a);
    if (this->commands != nullptr && this->commands->com_hand != nullptr) {
        this->commands->com_hand->last_world_random = (int)this->random_seed;
    }

    return this->game_state;
}

uchar RGE_Game_World::get_game_state() {
    return this->game_state;
}

uchar RGE_Game_World::check_game_state() {
    // Fully verified. Source of truth: world.cpp.decomp @ 0x005433C0 (audited vs world.cpp.asm).
    uchar victory_status = 0;
    int current_allies_ok = 0;
    int reference_player = 0;
    long games_won = 0;
    long games_lost = 0;
    long games_on = 0;

    // Only iterate real players (index 1..player_num-1). Player 0 is GAIA.
    for (int i = 1; i < this->player_num; ++i) {
        victory_status = this->players[i]->check_victory();
        if (victory_status == '\0') {
            games_won = games_won + 1;
            if (reference_player < 1 || current_allies_ok == 0) {
                current_allies_ok = 1;
                reference_player = i;
            } else {
                // Conquest ally-group check: all remaining "game on" players must be mutual allies and have allied victory enabled.
                if (this->players[i]->allied_victory == '\0' ||
                    this->players[reference_player]->relation(i) != '\0' ||
                    this->players[i]->relation(reference_player) != '\0') {
                    current_allies_ok = -1;
                }
            }
        } else if (victory_status == '\x01') {
            games_lost = games_lost + 1;
        } else if (victory_status == '\x02') {
            games_on = games_on + 1;
        }
    }

    if (games_lost < 1) {
        uchar conquest_victory = this->scenario->Get_conquest_victory();
        if (conquest_victory != '\0' &&
            (((0 < games_on && (0 < current_allies_ok)) || (games_won == 0)))) {
            this->game_state = '\x01';
            for (int i = 1; i < this->player_num; ++i) {
                this->players[i]->victory_if_game_on();
            }
            this->game_end_condition = '\x01';
        }
    } else {
        this->game_state = '\x01';
        for (int i = 1; i < this->player_num; ++i) {
            this->players[i]->loss_if_game_on();
        }
    }

    if ((this->game_state == '\x01') && (-1 < this->campaign)) {
        uchar ok = rge_base_game->set_campaign_info(this->campaign, this->campaign_player, this->campaign_scenario);
        if (ok == '\0') {
            this->campaign = -1;
        } else if (this->players[this->curr_player]->game_status == '\x01') {
            rge_base_game->set_campaign_win();
            return this->game_state;
        }
    }
    return this->game_state;
}

uchar RGE_Game_World::load_world(int param_1) {
    // Fully verified. Source of truth: world.cpp.decomp @ 0x005420F0 (audited vs world.cpp.asm).
    const int fd = param_1;
    uchar saved_game_state = '\0';

    this->game_state = '\x02';
    this->game_end_condition = '\0';

    rge_read(fd, &this->world_time, 4);
    rge_read(fd, &this->old_world_time, 4);
    rge_read(fd, &this->world_time_delta, 4);
    rge_read(fd, &this->world_time_delta_seconds, 4);
    rge_read(fd, &this->timer, 4);
    rge_read(fd, &this->game_speed, 4);
    rge_read(fd, &this->temp_pause, 1);
    rge_read(fd, &this->next_object_id, 4);
    rge_read(fd, &this->next_reusable_object_id, 4);
    rge_read(fd, &this->random_seed, 4);
    rge_read(fd, &this->curr_player, 2);
    rge_read(fd, &this->player_num, 2);
    rge_read(fd, &saved_game_state, 1);
    rge_read(fd, &this->campaign, 4);
    rge_read(fd, &this->campaign_player, 4);
    rge_read(fd, &this->campaign_scenario, 4);
    rge_read(fd, &this->player_turn, 4);

    for (int i = 0; i < 9; ++i) {
        rge_read(fd, &this->player_time_delta[i], 4);
    }

    this->old_time = 0;

    this->map->load_map(fd);
    this->initializePathingSystem();

    this->currentUpdateComputerPlayer = -1;

    if (this->player_num > 0) {
        this->players = (RGE_Player**)calloc((size_t)this->player_num, sizeof(RGE_Player*));
        for (int i = 0; i < this->player_num; ++i) {
            uchar type = 0;
            rge_read(fd, &type, 1);
            this->load_player(fd, type, (short)i);
        }
    }

    this->update_mutual_allies();

    this->map->unified_vis_map->suppress_updates(1);

    for (int i = 0; i < this->player_num; ++i) {
        this->players[i]->load_info(fd);
    }

    this->map->unified_vis_map->suppress_updates(0);

    this->scenario_init(fd, this);

    if (save_game_version < 7.16f) {
        this->difficultyLevelValue = -1;
    } else {
        rge_read(fd, &this->difficultyLevelValue, 4);
    }

    if (rge_base_game->singlePlayerGame() != 0) {
        this->game_speed = rge_base_game->get_game_speed();
    }

    this->game_state = saved_game_state;
    return '\x01';
}

uchar RGE_Game_World::load_game(char* param_1) {
    // Fully verified. Source of truth: world.cpp.decomp @ 0x00542360 (audited vs world.cpp.asm).
    world_update_counter = 0;
    this->del_game_info();

    char tempname[300];
    memset(tempname, 0, sizeof(tempname));
    sprintf(tempname, "%s%s", rge_base_game->prog_info->save_dir, param_1);

    int fd = rge_open(tempname, _O_BINARY);
    if (fd == -1) {
        return '\0';
    }

    char version[8];
    memset(version, 0, sizeof(version));
    rge_read(fd, version, 8);
    rge_read(fd, &save_game_version, 4);

    if (memcmp(version, "VER 8.6", 8) != 0) {
        rge_close(fd);
        return '\0';
    }

    this->load_world(fd);
    rge_close(fd);
    return '\x01';
}

uchar RGE_Game_World::new_game(RGE_Player_Info* param_1, int param_2) {
    CUSTOM_DEBUG_LOG("RGE_Game_World::new_game enter");
    if (param_1 == nullptr) {
        return 0;
    }

    world_update_counter = 0;
    pathSystem.zeroObstructionMap();
    aiPathSystem.zeroObstructionMap();
    this->currentUpdateComputerPlayer = -1;
    this->game_state = '\x03';
    this->curr_player = (short)param_2;

    unsigned int seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x509);
    if (rge_base_game != nullptr) {
        if (rge_base_game->multiplayerGame() == 0) {
            unsigned int configured_seed = (unsigned int)rge_base_game->random_game_seed;
            if (configured_seed != 0xffffffffu) {
                seed = configured_seed;
            }
        } else if (this->commands != nullptr && this->commands->com_hand != nullptr) {
            seed = this->commands->com_hand->GetRandomSeed();
        }
    }

    this->random_seed = seed;
    debug_srand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x50c, seed);
    if (rge_base_game != nullptr) {
        rge_base_game->save_random_game_seed = (int)this->random_seed;
    }

    this->random_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x50f);

    short old_player_num = this->player_num;
    short new_player_num = (short)(param_1->player_num + 1);
    if (this->map != nullptr) {
        this->map->new_map((long)param_1->map_width, (long)param_1->map_height);
    }

    this->random_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x516);

    if (this->players != nullptr) {
        for (short i = 0; i < old_player_num; ++i) {
            if (this->players[i] != nullptr) {
                delete this->players[i];
            }
        }
        free(this->players);
        this->players = nullptr;
    }

    this->player_num = new_player_num;
    this->players = (RGE_Player**)calloc((int)this->player_num, sizeof(RGE_Player*));

    this->setup_gaia();
    this->random_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x520);
    this->setup_players(param_1);
    this->random_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x526);

    if (this->commands != nullptr && this->commands->com_hand != nullptr && rge_base_game != nullptr) {
        for (unsigned int p = 1; p < 9; ++p) {
            int humanity = this->commands->com_hand->GetPlayerHumanity(p);
            int team = (int)rge_base_game->rge_game_options.playerTeamValue[p - 1];
            if ((humanity == 2 || humanity == 4) && team > 1) {
                for (unsigned int q = 1; q < 9; ++q) {
                    int humanity_q = this->commands->com_hand->GetPlayerHumanity(q);
                    int team_q = (int)rge_base_game->rge_game_options.playerTeamValue[q - 1];
                    if ((humanity_q == 2 || humanity_q == 4) && team_q == team) {
                        int pid = rge_base_game->playerID((int)p);
                        int qid = rge_base_game->playerID((int)q);
                        if (pid != qid && pid >= 0 && pid < this->player_num && qid >= 0 && qid < this->player_num && this->players[pid] != nullptr) {
                            this->players[pid]->set_relation(qid, '\0');
                            this->players[pid]->set_allied_victory('\x01');
                        }
                    }
                }
            }
        }

        if (rge_base_game->randomGame() != 0 && rge_base_game->campaignGame() == 0) {
            for (unsigned int p = 1; p < 9; ++p) {
                int humanity = this->commands->com_hand->GetPlayerHumanity(p);
                int team = (int)rge_base_game->rge_game_options.playerTeamValue[p - 1];
                if ((((humanity == 4) || (all_cp == 1)) || ((all_cp == 2) && (p > 1))) && team == 1) {
                    for (unsigned int q = 1; q < 9; ++q) {
                        int humanity_q = this->commands->com_hand->GetPlayerHumanity(q);
                        if (humanity_q == 2 || humanity_q == 4) {
                            int pid = rge_base_game->playerID((int)p);
                            int qid = rge_base_game->playerID((int)q);
                            if (pid != qid && pid >= 0 && pid < this->player_num && qid >= 0 && qid < this->player_num && this->players[pid] != nullptr) {
                                this->players[pid]->set_relation(qid, '\x01');
                                this->players[pid]->set_allied_victory('\x01');
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
    if (rge_base_game != nullptr && rge_base_game->singlePlayerGame() != 0) {
        this->game_speed = rge_base_game->game_speed;
    } else {
        this->game_speed = 1.0f;
    }
    this->temp_pause = '\0';
    this->world_time_delta_seconds = 0.0f;

    uchar result = 0;
    if (param_1->scenario == nullptr) {
        if (param_1->campaign == '\0') {
            CUSTOM_DEBUG_LOG("RGE_Game_World::new_game calling new_random_game");
            result = this->new_random_game(param_1);
            CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::new_game new_random_game result=%d", (int)result);
        } else {
            result = this->load_scenario(param_1);
        }
    } else {
        result = this->load_scenario(param_1->scenario, param_1);
    }

    CUSTOM_DEBUG_LOG("RGE_Game_World::new_game initializePathingSystem");
    this->initializePathingSystem();
    CUSTOM_DEBUG_LOG("RGE_Game_World::new_game random_start loop");
    for (int i = 0; i < this->player_num; ++i) {
        if (this->players != nullptr && this->players[i] != nullptr) {
            this->players[i]->random_start();
        }
    }

    if (result != 0) {
        this->game_state = '\0';
    }

    this->random_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x5b2);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::new_game exit result=%d", (int)result);
    return result;
}

uchar RGE_Game_World::new_scenario(RGE_Player_Info* param_1, int param_2) {
    // Source of truth: world.cpp.decomp @ 0x00542BF0
    if (param_1 == nullptr || this->map == nullptr) {
        return 0;
    }

    world_update_counter = 0;
    this->del_game_info();
    this->curr_player = 0;

    if (param_2 == 0 && this->commands != nullptr && this->commands->com_hand != nullptr) {
        param_2 = this->commands->com_hand->GetRandomSeed();
    }

    this->random_seed = (unsigned int)param_2;
    debug_srand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x5d5, (unsigned int)param_2);

    this->map->new_map((int)param_1->map_width, (int)param_1->map_height);
    if (param_1->map_info != nullptr) {
        this->map->clear_map((uchar)param_1->map_info->base_terrain, '\x01');
    } else {
        this->map->clear_map((uchar)0, '\x01');
    }

    this->player_num = (short)(param_1->player_num + 1);
    this->players = (RGE_Player**)calloc((int)this->player_num, sizeof(RGE_Player*));
    this->setup_gaia();
    this->setup_players(param_1);

    this->world_time = 0;
    this->old_world_time = 0;
    this->world_time_delta = 0;
    this->old_time = 0;
    this->game_speed = 1.0f;
    this->temp_pause = '\0';
    this->world_time_delta_seconds = 0.0f;

    uchar result = 0;
    if (param_1->scenario == nullptr) {
        this->load_scenario(param_1);
        this->scenario_init(this);
        result = 1;
    } else {
        result = this->load_scenario(param_1->scenario, param_1);
    }

    if (result != 0) {
        for (int i = 0; i < this->player_num; ++i) {
            if (this->players[i] != nullptr) {
                this->players[i]->set_map_visible();
            }
        }
    }

    return result;
}

uchar RGE_Game_World::save_game(char* param_1) {
    // TODO: implement
    return 1;
}

void RGE_Game_World::base_save(char* param_1) {
    // TODO: implement
}

void RGE_Game_World::base_save(int param_1) {
    // TODO: implement
}

uchar RGE_Game_World::save_scenario(char* param_1) {
    // TODO: implement
    return 1;
}

RGE_Scenario* RGE_Game_World::get_scenario_info(char* param_1) {
    // TODO: implement
    return this->scenario;
}

void RGE_Game_World::pause(uchar param_1) {
    // param_1: 1 = pause, 0 = unpause
    this->temp_pause = param_1;
}

void RGE_Game_World::set_map_visible(uchar param_1) {
    if (this->map != nullptr) {
        this->map->set_map_visible(param_1);
    }
}

void RGE_Game_World::set_map_fog(uchar param_1) {
    if (this->map != nullptr) {
        this->map->set_map_fog(param_1);
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

void RGE_Game_World::reset_player_visible_maps() {
    // Source of truth: world.cpp.decomp @ 0x00541E90
    if (this->players == nullptr) {
        return;
    }
    for (int i = 0; i < this->player_num; ++i) {
        if (this->players[i] != nullptr) {
            this->players[i]->remake_visible_map();
        }
    }
}

void RGE_Game_World::update_mutual_allies() {
    // Source of truth: world.cpp.decomp @ 0x005462D0
    if (this->players == nullptr || this->player_num <= 0) {
        return;
    }

    for (int i = 0; i < this->player_num; ++i) {
        RGE_Player* player = this->players[i];
        if (player == nullptr) {
            continue;
        }

        player->mutualExploredMask = 0;
        player->mutualVisibleMask = 0;
        player->nonMutualVisibleMask = 0;
        memset(player->RemoveVisibleBits, 0, sizeof(player->RemoveVisibleBits));

        for (int j = 0; j < 9; ++j) {
            if (j == i) {
                player->mutualAlly[j] = 1;
                player->mutualVisibleMask = (1UL << (j & 0x1F));
                player->mutualExploredMask = (1UL << ((j + 0x10) & 0x1F));
            } else {
                player->mutualAlly[j] = 0;
            }
        }
    }

    for (int i = 1; i < this->player_num; ++i) {
        RGE_Player* player = this->players[i];
        if (player == nullptr || player->allied_LOS_Enable != 1 || player->relations == nullptr) {
            continue;
        }

        for (int j = 1; j < this->player_num; ++j) {
            if (j == i) {
                continue;
            }

            RGE_Player* other = this->players[j];
            if (other == nullptr || other->relations == nullptr) {
                continue;
            }

            if (player->relations[j] == 0 && other->relations[i] == 0) {
                player->mutualAlly[j] = 1;
                player->mutualVisibleMask = player->mutualVisibleMask | (1UL << (j & 0x1F));
                player->mutualExploredMask = player->mutualExploredMask | (1UL << ((j + 0x10) & 0x1F));
            }
        }
    }

    for (int owner = 0; owner < this->player_num; ++owner) {
        RGE_Player* owner_player = this->players[owner];
        if (owner_player == nullptr || owner_player->relations == nullptr) {
            continue;
        }

        for (int p_num = 1; p_num < this->player_num; ++p_num) {
            if (p_num == owner || owner_player->mutualAlly[p_num] != 0) {
                continue;
            }

            for (int via = 1; via < this->player_num; ++via) {
                RGE_Player* via_player = this->players[via];
                if (via_player == nullptr) {
                    continue;
                }

                if (owner_player->relations[via] == 0 &&
                    via_player->mutualAlly[p_num] == 1 &&
                    via_player->mutualAlly[owner] == 1) {
                    owner_player->nonMutualVisibleMask =
                        owner_player->nonMutualVisibleMask | (1UL << (p_num & 0x1F));
                    owner_player->RemoveVisibleBits[p_num] =
                        owner_player->RemoveVisibleBits[p_num] | (1UL << (via & 0x1F));
                }
            }
        }
    }
}

int RGE_Game_World::initializePathingSystem() {
    // Source of truth: world.cpp.decomp @ 0x00546030
    RGE_Map* map_ptr = this->map;
    if (map_ptr == nullptr) {
        return 0;
    }

    pathSystem.initialize(map_ptr->map_width, map_ptr->map_height, map_ptr, this);
    map_ptr = this->map;
    aiPathSystem.initialize(map_ptr->map_width, map_ptr->map_height, map_ptr, this);
    return 1;
}

int RGE_Game_World::numberObjects() {
    // Source of truth: world.cpp.decomp @ 0x00545D10
    return this->numberObjectsValue;
}

int RGE_Game_World::numberNegativeObjects() {
    // Source of truth: world.cpp.decomp @ 0x00545D20
    return this->numberNegativeObjectsValue;
}

RGE_Static_Object* RGE_Game_World::object(int param_1) {
    // Source of truth: world.cpp.decomp @ 0x00545D30
    if (param_1 < 0) {
        int neg_idx = -param_1;
        if (neg_idx < this->maxNumberNegativeObjectsValue && this->negativeObjectsValue != nullptr) {
            return this->negativeObjectsValue[neg_idx];
        }
    } else if (param_1 < this->maxNumberObjectsValue && this->objectsValue != nullptr) {
        return this->objectsValue[param_1];
    }

    return nullptr;
}

RGE_Static_Object* RGE_Game_World::object_ptr(int param_1) {
    // Source of truth: world.cpp.decomp @ 0x00545D80
    return this->object(param_1);
}

uchar RGE_Game_World::recycle_object_out_of_game(uchar param_1, RGE_Static_Object* param_2) {
    // Source of truth: world.cpp.decomp @ 0x00546070
    switch (param_1) {
    case 0x0A:
        this->reusable_static_objects->add_node(param_2);
        return 1;
    case 0x14:
        this->reusable_animated_objects->add_node(param_2);
        return 1;
    case 0x19:
        this->reusable_doppleganger_objects->add_node(param_2);
        return 1;
    case 0x1E:
        this->reusable_moving_objects->add_node(param_2);
        return 1;
    case 0x28:
        this->reusable_action_objects->add_node(param_2);
        return 1;
    case 0x32:
        this->reusable_combat_objects->add_node(param_2);
        return 1;
    case 0x3C:
        this->reusable_missile_objects->add_node(param_2);
        return 1;
    default:
        return 0;
    }
}

void RGE_Game_World::scenario_init(RGE_Game_World* param_1) {
    (void)param_1;
    // TODO: implement
}

void RGE_Game_World::scenario_init(int param_1, RGE_Game_World* param_2) {
    (void)param_1;
    (void)param_2;
    // TODO: implement
}

// Object management virtuals
int RGE_Game_World::addObject(RGE_Static_Object* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }

    int object_id = (int)param_1->id;
    if (object_id < 0) {
        int idx = -object_id;
        if (idx >= this->maxNumberNegativeObjectsValue) {
            int new_max = this->maxNumberNegativeObjectsValue * 2;
            if (new_max <= idx) {
                new_max = idx + 1;
            }
            if (new_max < 1) {
                new_max = 1;
            }

            RGE_Static_Object** new_arr = (RGE_Static_Object**)calloc((size_t)new_max, sizeof(RGE_Static_Object*));
            if (new_arr == nullptr) {
                return 0;
            }

            for (int i = 0; i < this->maxNumberNegativeObjectsValue; ++i) {
                new_arr[i] = this->negativeObjectsValue[i];
            }

            if (this->negativeObjectsValue != nullptr) {
                free(this->negativeObjectsValue);
            }
            this->negativeObjectsValue = new_arr;
            this->maxNumberNegativeObjectsValue = new_max;
        }

        this->negativeObjectsValue[idx] = param_1;
        this->numberNegativeObjectsValue = this->numberNegativeObjectsValue + 1;
        return 1;
    }

    if (object_id >= this->maxNumberObjectsValue) {
        int new_max = this->maxNumberObjectsValue * 2;
        if (new_max <= object_id) {
            new_max = object_id + 1;
        }
        if (new_max < 1) {
            new_max = 1;
        }

        RGE_Static_Object** new_arr = (RGE_Static_Object**)calloc((size_t)new_max, sizeof(RGE_Static_Object*));
        if (new_arr == nullptr) {
            return 0;
        }

        for (int i = 0; i < this->maxNumberObjectsValue; ++i) {
            new_arr[i] = this->objectsValue[i];
        }

        if (this->objectsValue != nullptr) {
            free(this->objectsValue);
        }
        this->objectsValue = new_arr;
        this->maxNumberObjectsValue = new_max;
    }

    RGE_Static_Object* replaced = this->objectsValue[object_id];
    this->objectsValue[object_id] = param_1;
    this->numberObjectsValue = this->numberObjectsValue + 1;

    if (replaced != nullptr && this->scenario_object_flag != 0) {
        // TODO(accuracy): world.cpp.decomp calls RGE_Static_Object::change_unique_id(replaced).
        this->scenario_object_flag = 0;
    }

    return 1;
}

int RGE_Game_World::removeObject(int param_1) {
    if (param_1 < 0) {
        int idx = -param_1;
        if (idx < this->maxNumberNegativeObjectsValue && this->negativeObjectsValue != nullptr) {
            this->negativeObjectsValue[idx] = nullptr;
            return 1;
        }
        return 0;
    }

    if (param_1 < this->maxNumberObjectsValue && this->objectsValue != nullptr) {
        this->objectsValue[param_1] = nullptr;
        return 1;
    }

    return 0;
}
