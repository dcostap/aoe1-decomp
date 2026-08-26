// 00542BF0 RGE_Game_World::new_scenario (World.cpp:1478-1537)
// Shared World.cpp context reconstruction. This owner remains non-exact:
// 275 bytes, 221 differing bytes, with the first mismatch at +0x2D.
// The remaining schedule changes the proven map fault order, so this is not
// accepted drift.
// Context gate: PDB World.cpp lines 1478-1537 owns 00542BF0-00542D02.
// Exact anchors are the World vslot calls, GetRandomSeed, debug_srand, the
// map calls, calloc, and the final RGE_Player::set_map_visible loop.
// Recovery log: phase2 context, explicit this qualifiers, result and index
// scope changes, seed and map locals, terrain casts, and explicit long map
// arguments did not change the 221-byte result. The natural source is kept.
// Final validation: MISMATCH, rebuilt 273 bytes, first mismatch +0x2D.
#include "../../include/world_scenario_context.h"

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
