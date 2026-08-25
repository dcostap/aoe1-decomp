// 005454D0 RGE_Game_World::load_scenario7
// World.cpp: PDB owner and source-order closure.
// The body uses the reviewed World.cpp context. It preserves the period
// stream order, player hash map, scenario object records, and post-load pass.

#include "../world_phase2_context.h"

void RGE_Game_World::load_scenario7(int file, RGE_Player_Info& info)
{
    long count;
    long id;
    float obj_angle;
    uchar obj_state;
    short master_id;
    float world_x;
    float world_y;
    float world_z;
    long obj_id;
    long player_id_hash[9];
    int outer;
    int i;
    long next_object_id;
    int j;
    long scenario_player_count;
    void* buffer;

    world_update_counter = 0;
    rge_read_uncompressed(file, &count, 4);
    if (count > 0) {
        buffer = malloc(count);
        if (buffer == 0) {
            rge_close(file);
            return;
        }
        rge_read_uncompressed(file, buffer, count);
        free(buffer);
    }

    rge_read(file, &next_object_id, 4);
    this->scenario_init(file, this);
    this->scenario_make_map(file);

    int n = this->player_num;
    if (n > 0) {
        do {
            for (i = 0; i < 9; ++i) player_id_hash[i] = -1;
        } while (n > 10);
    }

    i = 0;
    if (n > 0) {
        long* ids = info.player_id_hash;
        do {
            player_id_hash[*ids++] = i++;
        } while (i < n);
    }

    i = 0;
    if (n > 0) {
        do {
            this->players[i]->remake_visible_map();
            ++i;
        } while (i < this->player_num);
    }

    rge_read(file, &scenario_player_count, 4);
    i = 1;
    if (scenario_player_count > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i >= this->player_num || *map <= -1 ||
                this->players[*map] == 0) {
                this->players[0]->scenario_load(file, player_id_hash, 1.08f);
            } else {
                this->players[*map]->scenario_load(file, player_id_hash, 1.08f);
            }
            ++i;
            ++map;
        } while (i < scenario_player_count);
    }

    outer = 0;
    if (scenario_player_count > 0) {
        long* map = player_id_hash;
        do {
            rge_read(file, &obj_id, 4);
            j = 0;
            if (obj_id > 0) {
                do {
                    rge_read(file, &world_x, 4);
                    rge_read(file, &world_y, 4);
                    rge_read(file, &world_z, 4);
                    rge_read(file, &id, 4);
                    rge_read(file, &master_id, 2);
                    rge_read(file, &obj_state, 1);
                    rge_read(file, &obj_angle, 4);
                    int player_id = *map;
                    if (player_id >= 0 && this->players[player_id] != 0) {
                        this->scenario_object_flag = 1;
                        this->scenario_object_id = id;
                        this->players[player_id]->make_scenario_obj(
                            world_x, world_y, world_z, master_id, obj_state, obj_angle);
                        this->scenario_object_flag = 0;
                    }
                    ++j;
                } while (j < obj_id);
            }
            ++outer;
            ++map;
        } while (outer < scenario_player_count);
    }

    this->next_object_id = next_object_id;
    rge_read(file, &scenario_player_count, 4);
    i = 1;
    if (scenario_player_count > 1) {
        long* map = player_id_hash + 1;
        do {
            if (i >= this->player_num || *map <= -1 ||
                this->players[*map] == 0) {
                this->players[0]->scenario_postload(file, player_id_hash, 1.08f);
            } else {
                this->players[*map]->scenario_postload(file, player_id_hash, 1.08f);
            }
            ++i;
            ++map;
        } while (i < scenario_player_count);
    }

    rge_close(file);
    i = 1;
    while (i < this->player_num) {
        if (i >= scenario_player_count) return;
        if (this->players[i] != 0 && player_id_hash[i] > -1) {
            int player_index = i - 1;
            this->players[player_id_hash[i]]->loadAIInformation(
                this->scenario->Get_BuildList(player_index, 1),
                this->scenario->Get_CityPlan(player_index, 1),
                this->scenario->Get_player_AI(player_index, 1),
                this->scenario->GetPlayerPosture(player_index), -1);
        }
        ++i;
    }
}
