// 00544880 RGE_Game_World::load_scenario3 (World.cpp:2733-2852)
// Exact owner under the shared World.cpp scenario context.
#include "../../include/world_scenario_context.h"

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
