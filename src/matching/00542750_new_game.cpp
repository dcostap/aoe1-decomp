// 00542750 RGE_Game_World::new_game (World.cpp:1254-1474)
// Attempt log:
// - Baseline had the right frame and call count but used virtual diplomacy
//   methods, wrong Player_Info offsets, and the wrong Player vtable slots.
// - Restored direct set_relation/set_allied_victory calls, Player_Info
//   scenario/victory/map/campaign ownership, and the distinct +0x84/+0xfc
//   World fields. This brought the candidate to exact size and ordered calls.
// - Deferred the initial seed member store until after seed selection, swapped
//   new_map to width/height order, and passed the scenario string to the
//   two-argument load_scenario slot; these reconstructed the early blocks.
// - The executable passes the same language buffer for all three
//   loadAIInformation arguments. A local base-game pointer reproduces the
//   final get_string register schedule without changing behavior.
// - Final source normalization uses donor-backed World/Player method names.
//   Current default flags produce an exact 1184-byte match.
// Source audit: the initial virtual call is the binary-proven
// RGE_Game_World::del_game_info slot (+0xB8). All World, Player, and Base_Game
// slots use names from the ABI surface. The image-address macros remain only
// for singleton globals whose extern forms change exact load scheduling.
// The source uses no manual vtable or inline assembly steering.

#include "../../include/world_scenario_context.h"

// BINARY NOTE: these reviewed image-owned singletons preserve the exact
// absolute-load schedule. The equivalent extern surfaces change this owner.
#define L (*(void**)0x62C4FC)
#define rge_base_game (*(RGE_Base_Game**)0x62C574)
#define world_update_counter (*(int*)0x886C10)
#define computerPlayerSetup ((int*)0x886C18)
#define debug_timeGetTime_cnt (*(int*)0x62C4EC)
#define debug_timeGetTime_time (*(int*)0x62C4F0)
#define all_cp (*(int*)0x62C51C)
#define pathSystem (*(PathingSystem*)0x74D440)
#define aiPathSystem (*(PathingSystem*)0x62F348)

unsigned char RGE_Game_World::new_game(RGE_Player_Info& info, int mode)
{
    char randomString[256];
    int mapTeam;
    volatile unsigned char retval;
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
        initial_seed = *(int*)((char*)rge_base_game + 0x28);
        if (initial_seed == -1) {
            initial_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x509);
        }
    }
    this->random_seed = initial_seed;
    debug_srand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x50c, this->random_seed);
    *(int*)((char*)rge_base_game + 0x30) = this->random_seed;
    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x50f);
    ((TDebuggingLog*)L)->Log("World: new_game (rand=%d)", this->random_seed);

    this->player_num = info.player_num_minus1 + 1;
    this->map->new_map(info.map_width, info.map_height);
    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x516);
    ((TDebuggingLog*)L)->Log("  World: after_new_map (rand=%d)", this->random_seed);

    this->player_num = info.player_num_minus1 + 1;
    this->players = (RGE_Player**)calloc(4, (int)this->player_num);
    this->setup_gaia();
    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x520);
    ((TDebuggingLog*)L)->Log("  World: after_gaia (rand=%d)", this->random_seed);
    this->setup_players(info);
    this->random_seed = debug_rand("C:\\msdev\\work\\age1_x1\\World.cpp", 0x526);
    ((TDebuggingLog*)L)->Log("  World: after_players (rand=%d)", this->random_seed);

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
    ((TDebuggingLog*)L)->Log("  World: end_of_new_game (rand=%d)", this->random_seed);
    RGE_Base_Game* base_game = rge_base_game;
    base_game->get_string(0x277b, randomString, 0x100);
    if (mapTeam == 1) {
        for (i = 1; i < this->player_num; i++) {
            if (this->players[i]) {
                this->players[i]->loadAIInformation(randomString, randomString, randomString, 0, info.victory);
            }
        }
    }
    return retval;
}

#undef L
#undef rge_base_game
#undef world_update_counter
#undef computerPlayerSetup
#undef debug_timeGetTime_cnt
#undef debug_timeGetTime_time
#undef all_cp
#undef pathSystem
#undef aiPathSystem
