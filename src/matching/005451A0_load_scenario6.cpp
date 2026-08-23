// 005451A0 RGE_Game_World::load_scenario6 (World.cpp:3089-3207)
// Shared World.cpp context reconstruction. Exact: 812/812 bytes, 0.0000%,
// 28 ordered calls, matching frame and owner symbol.
// BINARY NOTE: Version-6 records keep long dwords, float coordinates/value,
// a short angle, and a uchar object id. Negative counts follow shipped flow.
// BINARY NOTE: Both player passes duplicate mapped and fallback calls. This
// preserves receiver setup, fallback selection, cleanup, and fault order.
// Exact-finish: shared scenario_load reverted to 344 bytes; shared
// scenario_postload reverted to 25 bytes. Both duplicated branches are needed.
// Direct indexed object ownership gives the exact object guard and call setup.
// Long dword locals, no-op cast removal, and the unused receiver removal were
// reduced without codegen change. The two duplicated branch groups are required.
#include "../../include/world_scenario_context.h"

void RGE_Game_World::load_scenario6(int file, RGE_Player_Info& info)
{
    long count;
    long next_object_id;
    long header_size;
    uchar id;
    short obj_angle;
    float world_z;
    float world_y;
    float world_x;
    float object_value;
    long player_id_hash[9];
    long scenario_player_count;
    long obj_count;
    int i,j;
    int outer;
    void* buf;
    world_update_counter = 0;
    rge_read_uncompressed(file, &count, 4);
    // BINARY NOTE: A non-positive count skips allocation. A failed allocation
    // closes the file and returns before any later publication or read.
    if (count > 0) {
        buf = malloc(count);
        if (buf == 0) { rge_close(file); return; }
        rge_read_uncompressed(file, buf, count);
        free(buf);
    }
    rge_read(file, &next_object_id, 4);
    this->scenario_init(file, this);
    this->scenario_make_map(file);
    int n = this->player_num;
    if (n > 0) {
        do { for (i=0;i<9;i++) player_id_hash[i] = -1; } while (n > 10);
    }
    for (i=0; i<n; i++) player_id_hash[info.player_id_hash[i]] = i;
    for (i=0; i<this->player_num; i++) this->players[i]->remake_visible_map();
    rge_read(file, &scenario_player_count, 4);
    for (i=1; i<scenario_player_count; i++) {
        if (i >= this->player_num || player_id_hash[i] <= -1 ||
            this->players[player_id_hash[i]]==0)
            this->players[0]->scenario_load(file, player_id_hash, 1.07f);
        else
            this->players[player_id_hash[i]]->scenario_load(file, player_id_hash, 1.07f);
    }
    outer = 0;
    if (scenario_player_count > 0) {
        long* map = player_id_hash;
        do {
            rge_read(file, &obj_count, 4);
            for (j=0; j<obj_count; j++) {
                rge_read(file, &world_z, 4); rge_read(file, &world_y, 4); rge_read(file, &world_x, 4); rge_read(file, &header_size, 4); rge_read(file, &obj_angle, 2); rge_read(file, &id, 1); rge_read(file, &object_value, 4);
                long player_id = *map;
                // BINARY NOTE: Publication brackets the virtual object call.
                if (player_id >= 0 && this->players[player_id] != 0) {
                    this->scenario_object_flag=1;
                    this->scenario_object_id=header_size;
                    this->players[player_id]->make_scenario_obj(world_z, world_y, world_x, obj_angle, id, object_value);
                    this->scenario_object_flag=0;
                }
            }
            ++outer;
            ++map;
        } while (outer < scenario_player_count);
    }
    this->next_object_id = next_object_id;
    rge_read(file, &scenario_player_count, 4);
    for (i=1; i<scenario_player_count; i++) {
        if (i >= this->player_num || player_id_hash[i] <= -1 ||
            this->players[player_id_hash[i]]==0)
            this->players[0]->scenario_postload(file, player_id_hash, 1.07f);
        else
            this->players[player_id_hash[i]]->scenario_postload(file, player_id_hash, 1.07f);
    }
    rge_close(file);
    for (i=1; i<this->player_num && i<scenario_player_count; i++)
        if (this->players[i] && player_id_hash[i] > -1) {
            int k=i-1;
            this->players[player_id_hash[i]]->loadAIInformation(
                this->scenario->Get_BuildList(k,1),
                this->scenario->Get_CityPlan(k,1),
                this->scenario->Get_player_AI(k,1),
                this->scenario->GetPlayerPosture(k), -1);
        }
}
