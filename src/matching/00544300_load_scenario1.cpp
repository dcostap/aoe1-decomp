// 00544300 RGE_Game_World::load_scenario1 (World.cpp:2489-2604)
// Exact owner under the shared World.cpp scenario context.
#include "../../include/world_scenario_context.h"

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
