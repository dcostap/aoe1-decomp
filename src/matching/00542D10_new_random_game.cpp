// 00542D10 RGE_Game_World::new_random_game (World.cpp:1541-1589)
// Exact owner under the shared World.cpp scenario context.
#include "../../include/world_scenario_context.h"

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
