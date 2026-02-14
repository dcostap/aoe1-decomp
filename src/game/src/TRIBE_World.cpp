#include <time.h>
#include "../include/TRIBE_World.h"
#include "../include/custom_debug.h"
#include "../include/TRIBE_Game.h"
#include "../include/TRIBE_Tech.h"
#include "../include/TRIBE_Map.h"
#include "../include/RGE_Tile.h"
#include "../include/TRIBE_Command.h"
#include "../include/TRIBE_Effects.h"
#include "../include/T_Scenario.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_Gaia.h"
#include "../include/TRIBE_Master_Player.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Player_Info.h"
#include "../include/RGE_Map_Gen_Info.h"
#include "../include/RGE_Scenario.h"
#include "../include/RGE_Static_Object.h"
#include "../include/TCommunications_Handler.h"
#include "../include/TSound_Driver.h"
#include "../include/globals.h"

// Source of truth: tworld.cpp.decomp @ 0x0052DF40
TRIBE_World::TRIBE_World() : RGE_Game_World() {
    this->controllingComputerPlayer = 0xFF;
    this->tech = nullptr;
    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->sent_zone_score = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0.0f;
    this->score_displayed = 0;

    // Original creates TribeAIPlayBook and loads "data\\aoe.ply".
    // playbook is an AIPlayBook* member on RGE_Game_World at +0xA0.
    // TODO(accuracy): allocate TribeAIPlayBook and call loadPlays("data\\aoe.ply")
}

// Stub implementations for TRIBE_World virtual methods
// These mostly just call base class or return defaults

uchar TRIBE_World::data_load_world(FILE* param_1) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E350
    // Calls base class data_load_world, then reads tech file name and creates TRIBE_Tech.
    RGE_Game_World::data_load_world(param_1);

    // Original: fscanf(param_1, " %s", tech_file);
    // Then creates TRIBE_Tech from text file.
    char tech_file[24];
    if (param_1) {
        fscanf(param_1, " %s", tech_file);
    } else {
        tech_file[0] = '\0';
    }

    if (this->tech) {
        delete this->tech;
    }
    this->tech = new TRIBE_Tech(tech_file);

    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0.0f;
    this->score_displayed = 0;

    return 1;
}
uchar TRIBE_World::data_load_terrain_tables(char* param_1) { return RGE_Game_World::data_load_terrain_tables(param_1); }
uchar TRIBE_World::data_load_players(char* param_1) { return RGE_Game_World::data_load_players(param_1); }
uchar TRIBE_World::data_load_objects(char* param_1) { return RGE_Game_World::data_load_objects(param_1); }
uchar TRIBE_World::data_load_sounds(char* param_1) { return RGE_Game_World::data_load_sounds(param_1); }
uchar TRIBE_World::data_load_color_tables(char* param_1) { return RGE_Game_World::data_load_color_tables(param_1); }
uchar TRIBE_World::data_load_sprites(char* param_1) { return RGE_Game_World::data_load_sprites(param_1); }
void TRIBE_World::data_load_players_type(short param_1, short param_2, FILE* param_3) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E220
    // If param_2 == 1, create a TRIBE_Master_Player from file; otherwise delegate to base.
    if (param_2 != 1) {
        RGE_Game_World::data_load_players_type(param_1, param_2, param_3);
        return;
    }
    TRIBE_Master_Player* mp = new TRIBE_Master_Player(param_3);
    this->master_players[param_1] = (RGE_Master_Player*)mp;
}
void TRIBE_World::data_load_effects(char* param_1) { RGE_Game_World::data_load_effects(param_1); }
void TRIBE_World::data_load_map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8, char* param_9) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E2B0
    // Creates a TRIBE_Map from terrain data files, then loads terrain object types.
    this->map = new TRIBE_Map(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
    if (this->map) {
        this->map->load_terrain_obj_types(param_9);
    }
}
void TRIBE_World::data_load_random_map(char* param_1, char* param_2, char* param_3, char* param_4) { RGE_Game_World::data_load_random_map(param_1, param_2, param_3, param_4); }
uchar TRIBE_World::init_player_type(int param_1, short param_2, uchar param_3) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E400
    // If param_3 == 1, create a TRIBE_Master_Player; otherwise delegate to base.
    if (param_3 != 1) {
        return RGE_Game_World::init_player_type(param_1, param_2, param_3);
    }
    TRIBE_Master_Player* mp = new TRIBE_Master_Player(param_1);
    this->master_players[param_2] = (RGE_Master_Player*)mp;
    // Call finish_init on the newly created master player
    mp->finish_init(param_1, this->sprites, this->sounds);
    return 1;
}
uchar TRIBE_World::init_player(int param_1) { return RGE_Game_World::init_player(param_1); }
void TRIBE_World::load_player(int param_1, uchar param_2, short param_3) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E830
    if (param_2 == 1 || param_2 == 3) {
        // Human or scenario player -> TRIBE_Player
        TRIBE_Player* p = new TRIBE_Player(param_1, this, (uchar)param_3);
        this->players[param_3] = (RGE_Player*)p;
        p->load(param_1);
    } else if (param_2 == 2) {
        // Gaia player
        TRIBE_Gaia* g = new TRIBE_Gaia(param_1, this, (uchar)param_3);
        this->players[param_3] = (RGE_Player*)g;
        g->load(param_1);
    } else {
        RGE_Game_World::load_player(param_1, param_2, param_3);
    }
}
void TRIBE_World::color_table_init(int param_1) { RGE_Game_World::color_table_init(param_1); }
void TRIBE_World::terrain_tables_init(int param_1) { RGE_Game_World::terrain_tables_init(param_1); }
void TRIBE_World::init_sounds(int param_1, TSound_Driver* param_2) { RGE_Game_World::init_sounds(param_1, param_2); }
void TRIBE_World::init_sprites(int param_1) { RGE_Game_World::init_sprites(param_1); }
void TRIBE_World::map_init(int param_1, TSound_Driver* param_2) {
    CUSTOM_DEBUG_LOG_FMT("TRIBE_World::map_init: calling binary constructor with fd=%d", param_1);
    this->map = new TRIBE_Map(param_1, this->sounds, (char)1);
    if (this->map) {
         CUSTOM_DEBUG_LOG("TRIBE_World::map_init: map created successfully");
         
         // Fallback for corrupt/missing empires.dat map section
         if (this->map->num_terrain < 0 || this->map->num_terrain > 100) {
             CUSTOM_DEBUG_LOG("TRIBE_World::map_init: DETECTED CORRUPT MAP DATA! Initializing defaults.");
             this->map->num_terrain = 1;
             this->map->num_borders = 0;
             
             // Setup default Grass terrain (Slot 0)
             RGE_Tile_Set* ts = &this->map->terrain_types[0];
             strcpy(ts->name, "Grass");
             strcpy(ts->pict_name, "5000"); // Attempt to load by name if ID fails
             ts->resource_id = 15000; // Guessing a valid SLP ID for terrain
             ts->shape = nullptr;
             ts->loaded = 0;
             
             // Sanitize other critical members
             this->map->map_width = 120;
             this->map->map_height = 120;
             this->map->tile_width = 64;
             this->map->tile_height = 32;
             this->map->tile_half_width = 32;
             this->map->tile_half_height = 16;
             
             // Retry loading shapes with manual config
             this->map->load_terrain_types(this->sounds);
             
             // Populate the tile lookup table for the default terrain (Grass)
             // We map Tile Type 0 to Shape Frame 0
             // UNCONDITIONAL ASSIGNMENT (memory might be 0xCDCD)
             ts->tiles[0].count = 1;
             ts->tiles[0].animations = 1;
             ts->tiles[0].shape_index = 0;
         }
    } else {
         CUSTOM_DEBUG_LOG("TRIBE_World::map_init: FAILED to create map");
    }
}
void TRIBE_World::effects_init(int param_1) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E650
    // Original: this->effects = new TRIBE_Effects(param_1);
    // WORKAROUND: TRIBE_Effects(fd) reads effect data from empires.dat via rge_read,
    // but the file position is wrong (preceding stubs don't advance it).
    // Create an empty effects object instead.
    this->effects = nullptr;
}
void TRIBE_World::master_player_init(int param_1) { RGE_Game_World::master_player_init(param_1); }
void TRIBE_World::command_init(int param_1, TCommunications_Handler* param_2) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E530
    this->commands = new TRIBE_Command(this, param_2);
}
void TRIBE_World::world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E6B0
    // Calls base world_init, then creates TRIBE_Tech with (param_1, this).
    RGE_Game_World::world_init(param_1, param_2, param_3);

    if (this->tech) {
        delete this->tech;
    }
    // WORKAROUND: TRIBE_Tech(fd, world) reads tech tree from empires.dat via rge_read,
    // but the file position is wrong. Create a stub tech with zero entries.
    this->tech = new TRIBE_Tech((char*)nullptr);

    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0.0f;
    this->score_displayed = 0;
}
void TRIBE_World::setup_gaia() {
    // Source of truth: tworld.cpp.decomp @ 0x0052E920
    // Creates a TRIBE_Gaia player (player 0) using master_players[0].
    RGE_Master_Player* mp = (this->master_players && this->master_player_num > 0) ? this->master_players[0] : nullptr;
    TRIBE_Gaia* gaia = new TRIBE_Gaia(this, mp, '\0', "GAIA", '\0');
    this->players[0] = (RGE_Player*)gaia;
}
void TRIBE_World::setup_players(RGE_Player_Info* param_1) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E990
    // Creates TRIBE_Player objects for each player slot (1..player_num-1).
    // Decomp note: param_1->type[iVar4 + 8] is actually param_1->tribe[iVar4 - 1]
    // due to struct memory aliasing (type is at +0x249, tribe is at +0x252 = type + 9).
    for (int i = 1; i < this->player_num; i++) {
        uchar player_type = param_1->type[i - 1];
        uchar civ = param_1->tribe[i - 1]; // civilization/master_player index
        RGE_Master_Player* master = (this->master_players && civ < this->master_player_num) ? this->master_players[civ] : nullptr;
        char* player_name = param_1->name[i - 1];

        TRIBE_Player* player = nullptr;
        if (player_type == 0) {
            // Human player
            player = new TRIBE_Player(this, master, (uchar)i, player_name, civ, '\0', '\x01', nullptr, nullptr, nullptr);
        } else if (player_type == 4) {
            // Computer player
            if (useComputerPlayers == 0) {
                player = new TRIBE_Player(this, master, (uchar)i, player_name, civ, '\0', '\x01', nullptr, nullptr, nullptr);
            } else {
                player = new TRIBE_Player(this, master, (uchar)i, player_name, civ, '\x01', '\x01', nullptr, nullptr, nullptr);
            }
        }
        this->players[i] = (RGE_Player*)player;
    }
}
uchar TRIBE_World::new_random_game(RGE_Player_Info* param_1) {
    // Source of truth: tworld.cpp.decomp
    // The map should already be created by map_init() during world_init().
    // The real implementation calls map->map_generate() with full terrain generation.
    // WORKAROUND: just call base which creates a blank tile grid.
    return RGE_Game_World::new_random_game(param_1);
}
void TRIBE_World::save(int param_1) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E790
    RGE_Game_World::save(param_1);
    rge_write(param_1, &this->victory_type, 4);
    rge_write(param_1, &this->artifact_count, 4);
    rge_write(param_1, &this->ruin_count, 4);
    rge_write(param_1, &this->countdown_victory, 1);
    rge_write(param_1, &this->countdown_clock, 4);
    rge_write(param_1, &this->score_displayed, 1);
    rge_write(param_1, &this->controllingComputerPlayer, 1);
}
void TRIBE_World::scenario_make_player(short param_1, uchar param_2, uchar param_3, uchar param_4, char* param_5) {
    // Source of truth: tworld.cpp.decomp @ 0x0052ECF0
    // param_1 = player index, param_2 = civilization/master_player index
    // param_3 = player type (0=human, 4=computer), param_4 unused, param_5 = name
    TRIBE_Player* player = nullptr;
    if (param_3 == 0 || (param_3 != 4 && param_3 != 0)) {
        // Human player or unknown type -> create as human
        player = new TRIBE_Player(this, this->master_players[param_2], (uchar)param_1, param_5, param_2, '\0', '\x01', nullptr, nullptr, nullptr);
    } else if (param_3 == 4) {
        // Computer player
        player = new TRIBE_Player(this, this->master_players[param_2], (uchar)param_1, param_5, param_2, '\x01', '\x01', nullptr, nullptr, nullptr);
    }
    this->players[param_1] = (RGE_Player*)player;
}
void TRIBE_World::scenario_make_map(int param_1) { RGE_Game_World::scenario_make_map(param_1); }
uchar TRIBE_World::load_scenario(RGE_Player_Info* param_1) { return RGE_Game_World::load_scenario(param_1); }
uchar TRIBE_World::load_scenario(char* param_1, RGE_Player_Info* param_2) { return RGE_Game_World::load_scenario(param_1, param_2); }
void TRIBE_World::load_scenario1(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario1(param_1, param_2); }
void TRIBE_World::load_scenario2(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario2(param_1, param_2); }
void TRIBE_World::load_scenario3(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario3(param_1, param_2); }
void TRIBE_World::load_scenario4(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario4(param_1, param_2); }
void TRIBE_World::load_scenario5(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario5(param_1, param_2); }
void TRIBE_World::load_scenario6(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario6(param_1, param_2); }
void TRIBE_World::load_scenario7(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario7(param_1, param_2); }
void TRIBE_World::load_scenario8(int param_1, RGE_Player_Info* param_2) { RGE_Game_World::load_scenario8(param_1, param_2); }
void TRIBE_World::logStatus(FILE* param_1, int param_2) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E0B0
    // Writes game status info to AI log file.
    if (param_1 == nullptr || param_2 != 1) return;

    fprintf(param_1, "---------------------------------\n");

    time_t clock;
    time(&clock);
    struct tm* t = localtime(&clock);
    fprintf(param_1, "AI Log file for Game Started: %s", asctime(t));
    fprintf(param_1, "Number Players            %d\n", this->player_num - 1);

    // If scenario has a name, log it; otherwise log map/victory info
    if (this->scenario) {
        // TODO(accuracy): check scenario->scenario_name and log it
    }

    // Log map size, map type, victory condition from game settings
    // These use get_string through string table lookups in the original.
    // Simplified: just log the numeric values.
    if (rge_base_game) {
        TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
        fprintf(param_1, "Map Size                  %d\n", game->mapSize());
        fprintf(param_1, "Map Type                  %d\n", game->mapType());
        fprintf(param_1, "Victory Condition         %d\n", game->victoryType());
    }
}
TRIBE_World::~TRIBE_World() {
    if (this->tech) {
        delete this->tech;
        this->tech = nullptr;
    }
}
void TRIBE_World::setup_player_colors() { RGE_Game_World::setup_player_colors(); }
void TRIBE_World::setup_player_colors(RGE_Player_Info* param_1) { RGE_Game_World::setup_player_colors(param_1); }
uchar TRIBE_World::data_load(char* param_1, char* param_2) { return RGE_Game_World::data_load(param_1, param_2); }
uchar TRIBE_World::init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) { return RGE_Game_World::init(param_1, param_2, param_3); }
void TRIBE_World::turn_sound_off() { RGE_Game_World::turn_sound_off(); }
void TRIBE_World::del_game_info() { RGE_Game_World::del_game_info(); }
uchar TRIBE_World::update() { return RGE_Game_World::update(); }
uchar TRIBE_World::get_game_state() { return RGE_Game_World::get_game_state(); }
uchar TRIBE_World::check_game_state() { return RGE_Game_World::check_game_state(); }
uchar TRIBE_World::load_world(int param_1) {
    // Source of truth: tworld.cpp.decomp @ 0x0052EDF0
    uchar result = RGE_Game_World::load_world(param_1);
    if (result == 0) return 0;

    // Version-gated reads of TRIBE-specific save fields
    if (save_game_version < 5.6f) {
        this->victory_type = 0;
    } else {
        rge_read(param_1, &this->victory_type, 4);
    }

    if (save_game_version < 5.3f) {
        this->artifact_count = 0;
        this->ruin_count = 0;
    } else {
        rge_read(param_1, &this->artifact_count, 4);
        rge_read(param_1, &this->ruin_count, 4);
    }

    if (save_game_version < 5.4f) {
        this->countdown_victory = 0;
        this->countdown_clock = 0.0f;
    } else {
        rge_read(param_1, &this->countdown_victory, 1);
        rge_read(param_1, &this->countdown_clock, 4);
    }

    if (save_game_version < 6.6f) {
        this->score_displayed = 0;
    } else {
        rge_read(param_1, &this->score_displayed, 1);
    }

    if (save_game_version >= 6.97f) {
        rge_read(param_1, &this->controllingComputerPlayer, 1);
    } else {
        this->controllingComputerPlayer = 0x02;
    }

    return 1;
}
uchar TRIBE_World::load_game(char* param_1) { return RGE_Game_World::load_game(param_1); }
uchar TRIBE_World::new_game(RGE_Player_Info* param_1, int param_2) {
    // Source of truth: tworld.cpp.decomp @ 0x0052EF30
    this->score_displayed = 0;
    this->controllingComputerPlayer = 0xFF;

    uchar result = RGE_Game_World::new_game(param_1, param_2);

    // Reset countdown timers for all players (decomp line 1116-1118)
    for (int i = 0; i < this->player_num; i++) {
        rge_base_game->reset_countdown_timer(i);
    }

    // Victory condition setup (decomp LAB_0052f765, lines 1484-1548)
    if (result != 0) {
        this->victory_type = 4; // default: custom/scenario
        this->countdown_victory = 0;
        this->countdown_clock = 0.0f;

        int isCampaign = rge_base_game->campaignGame();
        int isRandom = rge_base_game->randomGame();

        if ((isCampaign == 0 && isRandom != 0) ||
            ((TRIBE_Game*)rge_base_game)->victoryType() != 0 /*VictoryDefault*/) {
            // Random game or non-default victory: set victory_type from game options
            int victoryAmount = ((TRIBE_Game*)rge_base_game)->victoryAmount();
            int vt = ((TRIBE_Game*)rge_base_game)->victoryType();

            // TODO(accuracy): T_Scenario::Set_victory_all_flag, Set_Multi_* calls
            // require scenario object which may not be allocated yet.

            switch (vt) {
            case 0: // VictoryDefault
            case 1: // VictoryStandard
                this->victory_type = 0;
                break;
            case 2: // VictoryConquest
                this->victory_type = 1;
                break;
            case 7: // VictoryTime
                this->victory_type = 2;
                this->countdown_victory = 1;
                this->countdown_clock = (float)victoryAmount;
                break;
            case 8: // VictoryScore
                this->victory_type = 3;
                break;
            default:
                // VictoryExplore, VictoryRuins, VictoryArtifacts, VictoryDiscoveries, VictoryGold
                // These set specific T_Scenario Multi_* flags — deferred until scenario is wired.
                break;
            }
        }

        // TODO(accuracy): RGE_RMM_Object_Generator for artifacts/discoveries/ruins placement
    }

    return result;
}
uchar TRIBE_World::new_scenario(RGE_Player_Info* param_1, int param_2) {
    // Source of truth: tworld.cpp.decomp @ 0x00530370
    uchar result = RGE_Game_World::new_scenario(param_1, param_2);
    // Set starting resources for non-gaia players
    // Attribute indices: 0=food, 1=wood, 2=gold, 3=stone
    // Hex: 0x43480000=200.0f, 0x42c80000=100.0f
    for (int i = 1; i < this->player_num; i++) {
        if (this->players[i] && this->players[i]->attributes && this->players[i]->attribute_num >= 4) {
            this->players[i]->attributes[0] = 200.0f; // food
            this->players[i]->attributes[1] = 200.0f; // wood
            this->players[i]->attributes[2] = 100.0f; // gold
            this->players[i]->attributes[3] = 0.0f;   // stone
        }
    }
    return result;
}
uchar TRIBE_World::save_game(char* param_1) { return RGE_Game_World::save_game(param_1); }
void TRIBE_World::base_save(char* param_1) { RGE_Game_World::base_save(param_1); }
void TRIBE_World::base_save(int param_1) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E770
    RGE_Game_World::base_save(param_1);
    if (this->tech) {
        this->tech->save(param_1);
    }
}
uchar TRIBE_World::save_scenario(char* param_1) { return RGE_Game_World::save_scenario(param_1); }
RGE_Scenario* TRIBE_World::get_scenario_info(char* param_1) { return RGE_Game_World::get_scenario_info(param_1); }
void TRIBE_World::pause(uchar param_1) { RGE_Game_World::pause(param_1); }
void TRIBE_World::scenario_init(RGE_Game_World* param_1) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E5F0
    this->scenario = new T_Scenario(param_1);
}
void TRIBE_World::scenario_init(int param_1, RGE_Game_World* param_2) {
    // Source of truth: tworld.cpp.decomp @ 0x0052E590
    this->scenario = new T_Scenario(param_1, param_2);
}
int TRIBE_World::addObject(RGE_Static_Object* param_1) { return RGE_Game_World::addObject(param_1); }
int TRIBE_World::removeObject(int param_1) { return RGE_Game_World::removeObject(param_1); }
