// 005445C0 RGE_Game_World::load_scenario2 (World.cpp:2608-2729)
// Exact owner under the shared World.cpp scenario context.
#include "../../include/world_scenario_context.h"

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
