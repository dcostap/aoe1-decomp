#include "../include/RGE_Game_World.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Player_Info.h"
#include "../include/RGE_Map_Gen_Info.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Sound.h"
#include "../include/RGE_Effects.h"
#include "../include/RGE_Master_Player.h"
#include "../include/RGE_Command.h"
#include "../include/globals.h"
#include "../include/custom_debug.h"
#include "../include/debug_helpers.h"

#include <io.h>
#include <fcntl.h>
#include <share.h>
#include <stdio.h>
#include <string.h>

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
    // TODO: implement
    return 1;
}

uchar RGE_Game_World::init_player(int param_1) {
    // TODO: implement
    return 1;
}

void RGE_Game_World::load_player(int param_1, uchar param_2, short param_3) {
    // TODO: implement
}

void RGE_Game_World::color_table_init(int fd) {
    if (fd <= 0) return;
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::color_table_init fd=%d pos=%ld", fd, _tell(fd));
    rge_read(fd, &this->color_table_num, 2);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::color_table_init: color_table_num=%d", (int)this->color_table_num);
    if (this->color_table_num > 0) {
        this->color_tables = (RGE_Color_Table**)calloc(this->color_table_num, sizeof(RGE_Color_Table*));
        for (short i = 0; i < this->color_table_num; i++) {
            this->color_tables[i] = new RGE_Color_Table(fd);
        }
    }
}

void RGE_Game_World::terrain_tables_init(int fd) {
    if (fd <= 0) return;
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::terrain_tables_init fd=%d pos=%ld", fd, _tell(fd));
    rge_read(fd, &this->terrain_num, 2);
    rge_read(fd, &this->terrain_size, 2);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::terrain_tables_init: terrain_num=%d terrain_size=%d",
        (int)this->terrain_num, (int)this->terrain_size);
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
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::init_sounds fd=%d pos=%ld", fd, _tell(fd));
    rge_read(fd, &this->sound_num, 2);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::init_sounds: sound_num=%d", (int)this->sound_num);
    if (this->sound_num > 0) {
        this->sounds = (RGE_Sound**)calloc(this->sound_num, sizeof(RGE_Sound*));
        for (short i = 0; i < this->sound_num; i++) {
            this->sounds[i] = new RGE_Sound(fd, param_2);
        }
    }
}

void RGE_Game_World::init_sprites(int fd) {
    if (fd <= 0) return;
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::init_sprites fd=%d pos=%ld", fd, _tell(fd));
    rge_read(fd, &this->sprite_num, 2);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::init_sprites: sprite_num=%d", (int)this->sprite_num);
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
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::map_init fd=%d pos=%ld", fd, _tell(fd));
    if (this->map) delete this->map;
    this->map = new RGE_Map(fd, this->sounds, 1);
}

void RGE_Game_World::effects_init(int fd) {
    if (fd <= 0) return;
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::effects_init fd=%d pos=%ld", fd, _tell(fd));
    this->effects = new RGE_Effects(fd);
}

void RGE_Game_World::master_player_init(int fd) {
    if (fd <= 0) return;
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::master_player_init fd=%d pos=%ld", fd, _tell(fd));
    rge_read(fd, &this->master_player_num, 2);
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::master_player_init: master_player_num=%d", (int)this->master_player_num);
    if (this->master_player_num > 0) {
        this->master_players = (RGE_Master_Player**)calloc(this->master_player_num, sizeof(RGE_Master_Player*));
        for (short i = 0; i < this->master_player_num; i++) {
            this->master_players[i] = new RGE_Master_Player(fd);
        }
    }
}

void RGE_Game_World::command_init(int fd, TCommunications_Handler* param_2) {
    CUSTOM_DEBUG_LOG_FMT("RGE_Game_World::command_init fd=%d pos=%ld", fd, (fd > 0 ? _tell(fd) : -1L));
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
    this->terrain_tables_init(param_1);
    this->color_table_init(param_1);
    this->init_sounds(param_1, param_2);
    this->init_sprites(param_1);
    this->map_init(param_1, param_2);
    this->effects_init(param_1);
    this->master_player_init(param_1);
    this->command_init(param_1, param_3);
}

void RGE_Game_World::setup_gaia() {
    // TODO: implement
}

void RGE_Game_World::setup_players(RGE_Player_Info* param_1) {
    // TODO: implement
}

uchar RGE_Game_World::new_random_game(RGE_Player_Info* param_1) {
    // Source of truth: world.cpp.decomp @ 0x00542D10.
    if (param_1 == nullptr || this->map == nullptr) {
        return 0;
    }

    world_update_counter = 0;

    this->setup_player_colors(param_1);
    this->scenario_init(this);

    this->random_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x612);

    int player_count_minus_one = (int)this->player_num - 1;
    this->map->map_generate2(this, -1, -1, (uchar)param_1->map_type, player_count_minus_one);
    this->initializePathingSystem();

    this->random_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x61a);
    this->random_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x622);

    short saved_curr_player = this->curr_player;
    this->curr_player = -1;

    for (int pass = 0; pass < 3; ++pass) {
        world_update_counter = world_update_counter + 1;
        for (int i = 0; i < this->player_num; ++i) {
            if (this->players != nullptr && this->players[i] != nullptr) {
                this->players[i]->update();
            }
        }
    }

    this->curr_player = saved_curr_player;
    this->random_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x631);
    return 1;
}

void RGE_Game_World::save(int param_1) {
    // TODO: implement
}

// Scenario loading virtuals
void RGE_Game_World::scenario_make_player(short param_1, uchar param_2, uchar param_3, uchar param_4, char* param_5) {
    // TODO: implement
}

void RGE_Game_World::scenario_make_map(int param_1) {
    // TODO: implement
}

uchar RGE_Game_World::load_scenario(RGE_Player_Info* param_1) {
    // TODO: implement
    return 1;
}

uchar RGE_Game_World::load_scenario(char* param_1, RGE_Player_Info* param_2) {
    // TODO: implement
    return 1;
}

void RGE_Game_World::load_scenario1(int param_1, RGE_Player_Info* param_2) {
    // TODO: implement
}

void RGE_Game_World::load_scenario2(int param_1, RGE_Player_Info* param_2) {
    // TODO: implement
}

void RGE_Game_World::load_scenario3(int param_1, RGE_Player_Info* param_2) {
    // TODO: implement
}

void RGE_Game_World::load_scenario4(int param_1, RGE_Player_Info* param_2) {
    // TODO: implement
}

void RGE_Game_World::load_scenario5(int param_1, RGE_Player_Info* param_2) {
    // TODO: implement
}

void RGE_Game_World::load_scenario6(int param_1, RGE_Player_Info* param_2) {
    // TODO: implement
}

void RGE_Game_World::load_scenario7(int param_1, RGE_Player_Info* param_2) {
    // TODO: implement
}

void RGE_Game_World::load_scenario8(int param_1, RGE_Player_Info* param_2) {
    // TODO: implement
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
    // TODO: implement
}

void RGE_Game_World::setup_player_colors(RGE_Player_Info* param_1) {
    // TODO: implement
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
    // TODO: implement
}

void RGE_Game_World::del_game_info() {
    // TODO: implement
}

uchar RGE_Game_World::update() {
    // Source of truth: World.cpp.asm (update @ various offsets)
    // Minimal world tick: advance world time based on real time and game speed.
    // TODO(accuracy): full update chain — player updates, object updates, AI ticks,
    //                 command processing, pathing, etc.

    if (this->game_state != 1) {
        return 0; // not playing
    }

    if (this->temp_pause != 0) {
        return 1; // paused — don't advance time
    }

    unsigned long now = GetTickCount();
    if (this->old_time == 0) {
        this->old_time = now;
    }

    unsigned long elapsed_ms = now - this->old_time;
    this->old_time = now;

    // Apply game speed (default 1.5)
    unsigned long game_ms = (unsigned long)(elapsed_ms * this->game_speed);

    this->old_world_time = this->world_time;
    this->world_time += game_ms;
    this->world_time_delta = this->world_time - this->old_world_time;
    this->world_time_delta_seconds = (float)this->world_time_delta / 1000.0f;

    // Update all players
    if (this->players) {
        for (short i = 0; i < this->player_num; i++) {
            if (this->players[i]) {
                this->players[i]->update();
            }
        }
    }

    // Check victory/defeat conditions
    this->check_game_state();

    return 1;
}

uchar RGE_Game_World::get_game_state() {
    return this->game_state;
}

uchar RGE_Game_World::check_game_state() {
    // TODO: implement
    return this->game_state;
}

uchar RGE_Game_World::load_world(int param_1) {
    // TODO: implement
    return 1;
}

uchar RGE_Game_World::load_game(char* param_1) {
    // TODO: implement
    return 1;
}

uchar RGE_Game_World::new_game(RGE_Player_Info* param_1, int param_2) {
    // Inferred from TRIBE_World::new_game decomp and call chain.
    // param_1 = RGE_Player_Info with player setup data
    // param_2 = scenario type flag

    if (!param_1) return 0;

    // player_num = player_info.player_num + 1 (gaia is player 0)
    this->player_num = param_1->player_num + 1;

    if (this->map != nullptr) {
        this->map->new_map((long)param_1->map_width, (long)param_1->map_height);
    }

    // Allocate players array
    if (this->players) {
        for (short i = 0; i < this->player_num; i++) {
            if (this->players[i]) {
                delete this->players[i];
                this->players[i] = nullptr;
            }
        }
        free(this->players);
    }
    this->players = (RGE_Player**)calloc(this->player_num, sizeof(RGE_Player*));

    // Setup gaia (player 0) and human/computer players (1..player_num-1)
    this->setup_gaia();
    this->setup_players(param_1);

    // Reset world time
    this->world_time = 0;
    this->old_world_time = 0;
    this->world_time_delta = 0;
    this->old_time = 0;
    this->timer = 0.0f;
    this->game_speed = 1.5f; // default game speed
    this->game_state = 1; // playing
    this->temp_pause = 0;
    this->curr_player = 1; // human player

    // Generate random map
    this->new_random_game(param_1);

    // Setup player colors
    this->setup_player_colors(param_1);

    return 1;
}

uchar RGE_Game_World::new_scenario(RGE_Player_Info* param_1, int param_2) {
    // TODO: implement
    return 1;
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
    // TODO(accuracy): call RGE_Player::remake_visible_map for each player slot.
}

int RGE_Game_World::initializePathingSystem() {
    // TODO(accuracy): call PathingSystem::initialize(pathSystem/aiPathSystem).
    return (this->map != nullptr) ? 1 : 0;
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
    // TODO: implement (see world.cpp.asm)
    return 0;
}

int RGE_Game_World::removeObject(int param_1) {
    // TODO: implement (see world.cpp.asm)
    return 0;
}
