// 00545800 RGE_Game_World::load_scenario8
// World.cpp: PDB owner and source-order closure.
// The body uses the reviewed World.cpp context and preserves the period
// scenario stream order, object records, and post-load AI pass.

#include "../world_phase2_context.h"

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
