// VA: 00483A20 RGE_RMM_Database_Controller::add_land_module
// rmm_dbct.cpp  (PDB lines 549-844)
// __thiscall, ret 4, no EH frame.
//
// Attempt log:
// 1 (dsb2 baseline): fresh canonical reset. Land records are NOT at this+0x14;
//    the exact destructor/init donors prove RGE_Random_Map_Module base fields
//    (map_width +0x14, map_height +0x18), controller world/map_type/
//    number_of_players at +0x30/+0x34/+0x38, and RGE_Land_Info at +0x3C with
//    RGE_Land_Info_Line records (stride 0x34) first, header fields at the end
//    (land_num +0x141C, base_terrain +0x1420, walls +0x1424..+0x1430,
//    wall_fade +0x1434); map_info.maps at +0x4F58 with 0x48-byte entries whose
//    land_info (RGE_Land_Data) sits at entry+4. Full phase-A transcription
//    (land count, header copy, per-entry copy + calc_land_start, team branch)
//    plus phase B (distances/sort/team partition/land reassignment) transcribed
//    from the Ghidra decompiler with corrected 1-based team_size vs 0-based
//    distances indexing.
// 2 (dsb2): removed materialized entry pointer -> direct land_data->land[edge]
//    field access; diff 1792 -> 1167, shape 65.7% -> 71.6%; register basin
//    recovered (this->ebp, land_data->esi, offset->edi, record->ebx).
// 3 (dsb2): declare all scalars at function top in the binary's slot order
//    (index, index1, edge, local_180, land_wanted, local_178, local_174,
//    swap, start_land) and size the local arrays ty[9]/team_size[8]/
//    player_teams[9]/distances[8][8] so the packed layout reproduces the
//    original 0x190 frame (arrays at +0x38/+0x5C/+0x7C/+0xA0) and slot reuse
//    (local_180 = placement -> team_size cursor, local_178 = total ->
//    other_land, index/edge reused across phases). Frame now matches.
// 4 (dsb2): natural `this->world->players[index1+1]->relation(j+1)` team
//    partition gave the best diff (1167) but VC5 miscompiles the seed load:
//    it emits players[this*4+4] (this's home slot substituted for index1).
//    Do NOT reintroduce the natural spelling; the binary's addressing proves
//    the original source walked player_teams with cursors.
// 5 (dsb2): cursor team partition (ppt/psize cursors, local_174 = 4 - &pt[1],
//    swap = local_174 + ppt hoisted before the inner loop, store cursor) is
//    semantically correct and reaches the best shape metrics (78.7% shape,
//    27.5% exact blocks, frame 0x190) with diff 1561; remaining drift is
//    register/slot coloring (this-home slot position, index/index1 slot
//    permutation) plus loop-shape details in the allocation block.
// Left in scratch: phase A is byte-close (only this-home [esp+18h] vs
// [esp+10h] and a few slot permutations); phase B is correct and close but
// not exact. Probe 4's miscompile is documented negative evidence.

typedef unsigned char uchar;

class RGE_Player;
class RGE_Game_World;

struct RGE_Land_Data_Entry {
    long land_id;                       // +0x00
    uchar terrain_type;                 // +0x04
    uchar gap_05[3];
    long land_avoidance_tiles;          // +0x08
    long base_square_radius;            // +0x0C
    uchar zone;                         // +0x10
    char gap_11[0x0B];
    uchar amount_of_land_used_percent;  // +0x1C
    uchar by_player_flag;               // +0x1D
    char gap_1E[0x0A];
    long clumpiness_factor;             // +0x28
};                                      // sizeof 0x2C

struct RGE_Land_Data {
    long map_edge_buffer[4];            // +0x00
    long map_edge_fade;                 // +0x10
    long land_placement_edge;           // +0x14
    long base_terrain;                  // +0x18
    long grown_land_percent;            // +0x1C
    long id;                            // +0x20
    long land_num;                      // +0x24
    RGE_Land_Data_Entry* land;          // +0x28
};                                      // sizeof 0x2C

struct RGE_Land_Info_Line {
    long land_size;                     // +0x00
    long terrain_type;                  // +0x04
    long x;                             // +0x08
    long y;                             // +0x0C
    long base_size;                     // +0x10
    long area;                          // +0x14
    uchar zone;                         // +0x18
    uchar gap_19[3];
    long clumpiness_factor;             // +0x1C
    long wall_1_avoidance_line;         // +0x20
    long wall_2_avoidance_line;         // +0x24
    long wall_3_avoidance_line;         // +0x28
    long wall_4_avoidance_line;         // +0x2C
    uchar wall_fade;                    // +0x30
    uchar gap_31[3];
};                                      // sizeof 0x34

struct RGE_Land_Info {
    RGE_Land_Info_Line land[99];        // +0x00
    long land_num;                      // +0x141C
    uchar base_terrain;                 // +0x1420
    uchar gap_1421[3];
    long wall_1_avoidance_line;         // +0x1424
    long wall_2_avoidance_line;         // +0x1428
    long wall_3_avoidance_line;         // +0x142C
    long wall_4_avoidance_line;         // +0x1430
    uchar wall_fade;                    // +0x1434
    uchar gap_1435[3];
};                                      // sizeof 0x1438

struct RGE_Map_Data_Entry {
    long map_id;                        // +0x00
    RGE_Land_Data land_info;            // +0x04
    char terrain_info[8];               // +0x30
    char object_info[8];                // +0x38
    char elevation_info[8];             // +0x40
};                                      // sizeof 0x48

class RGE_Random_Map_Module {
public:
    virtual uchar generate();
    RGE_Random_Map_Module* parent;      // +0x04
    void* list;                         // +0x08
    void* map;                          // +0x0C
    void** map_row_offset;              // +0x10
    long map_width;                     // +0x14
    long map_height;                    // +0x18
    float schedule;                     // +0x1C
    uchar* search_map;                  // +0x20
    uchar** search_map_rows;            // +0x24
    void* stack_array;                  // +0x28
    void* stack_offsets;                // +0x2C
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;               // +0x40
};

class RGE_Player {
public:
    uchar relation(long param_1);
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;              // +0x30
    long map_type;                      // +0x34
    long number_of_players;             // +0x38
    RGE_Land_Info land_info;            // +0x3C
    char terrain_info[0x1298];          // +0x1474
    char object_info[0x18C8];           // +0x270C
    char elevation_info[0xF80];         // +0x3FD4
    long map_num;                       // +0x4F54
    RGE_Map_Data_Entry* maps;           // +0x4F58

    void calc_land_start(long start, long radius, long count, RGE_Land_Data_Entry* land);

    virtual void add_land_module(uchar param_1);
    virtual void add_terrain_module();
    virtual void add_object_module();
    virtual void add_elevation_module();
    virtual uchar init();
    virtual uchar de_init();
};

void RGE_RMM_Database_Controller::add_land_module(uchar param_1)
{
    long index;          // +14: team inner counter (A) / distances row ptr + team counter (B)
    long index1;         // +18: phase B outer counter
    long edge;           // +1C: phase A loop counter / phase B land ptr / alloc counter
    long local_180;      // +20: placement (A) / team_size cursor (B)
    long land_wanted;    // +24: phase B
    long local_178;      // +28: total (A) / other_land (B)
    long local_174;      // +2C: phase B
    long swap;           // +30: phase B
    long start_land;     // +34: phase B
    long ty[9];          // +38
    long team_size[8];   // +5C
    long player_teams[9];// +7C
    long distances[8][8];// +A0

    RGE_Land_Data* land_data = &this->maps[this->map_type].land_info;
    local_178 = land_data->grown_land_percent * this->map_width * this->map_height / 100;
    local_180 = land_data->land_placement_edge;

    this->land_info.land_num = 0;
    for (int i = 0; i < land_data->land_num; i++) {
        if (land_data->land[i].by_player_flag != 0)
            this->land_info.land_num += this->number_of_players;
        else
            this->land_info.land_num++;
    }

    this->land_info.base_terrain = (uchar)land_data->base_terrain;
    this->land_info.wall_1_avoidance_line = land_data->map_edge_buffer[0];
    this->land_info.wall_2_avoidance_line = land_data->map_edge_buffer[1];
    this->land_info.wall_3_avoidance_line = this->map_width - land_data->map_edge_buffer[2];
    this->land_info.wall_4_avoidance_line = this->map_height - land_data->map_edge_buffer[3];
    this->land_info.wall_fade = (uchar)land_data->map_edge_fade;

    long record = 0;
    for (edge = 0; edge < land_data->land_num; edge++) {
        if (land_data->land[edge].by_player_flag != 0) {
            calc_land_start(record, local_180, this->number_of_players, &land_data->land[edge]);
            for (index = 0; index < this->number_of_players; index++) {
                this->land_info.land[record].terrain_type = land_data->land[edge].terrain_type;
                this->land_info.land[record].area = land_data->land[edge].land_avoidance_tiles;
                this->land_info.land[record].base_size = land_data->land[edge].base_square_radius;
                if (land_data->land[edge].by_player_flag == 1)
                    this->land_info.land[record].zone = land_data->land[edge].zone;
                else
                    this->land_info.land[record].zone = (uchar)index;
                this->land_info.land[record].land_size =
                    (land_data->land[edge].amount_of_land_used_percent * local_178) / (this->number_of_players * 100);
                this->land_info.land[record].clumpiness_factor = land_data->land[edge].clumpiness_factor;
                this->land_info.land[record].wall_1_avoidance_line = this->land_info.wall_1_avoidance_line;
                this->land_info.land[record].wall_2_avoidance_line = this->land_info.wall_2_avoidance_line;
                this->land_info.land[record].wall_3_avoidance_line = this->land_info.wall_3_avoidance_line;
                this->land_info.land[record].wall_4_avoidance_line = this->land_info.wall_4_avoidance_line;
                this->land_info.land[record].wall_fade = this->land_info.wall_fade;
                record++;
            }
        } else {
            this->land_info.land[record].terrain_type = land_data->land[edge].terrain_type;
            this->land_info.land[record].area = land_data->land[edge].land_avoidance_tiles;
            this->land_info.land[record].base_size = land_data->land[edge].base_square_radius;
            this->land_info.land[record].zone = land_data->land[edge].zone;
            calc_land_start(record, local_180, 1, &land_data->land[edge]);
            this->land_info.land[record].land_size =
                (land_data->land[edge].amount_of_land_used_percent * local_178) / 100;
            this->land_info.land[record].clumpiness_factor = land_data->land[edge].clumpiness_factor;
            this->land_info.land[record].wall_1_avoidance_line = this->land_info.wall_1_avoidance_line;
            this->land_info.land[record].wall_2_avoidance_line = this->land_info.wall_2_avoidance_line;
            this->land_info.land[record].wall_3_avoidance_line = this->land_info.wall_3_avoidance_line;
            this->land_info.land[record].wall_4_avoidance_line = this->land_info.wall_4_avoidance_line;
            this->land_info.land[record].wall_fade = this->land_info.wall_fade;
            record++;
        }
    }

    if (param_1 != 0) {
        land_wanted = this->land_info.land_num;
        index1 = 0;
        if (land_wanted > 0) {
            index = (long)&distances[0][1];
            edge = (long)&this->land_info.land[0].y;
            do {
                for (long j = 0; j < land_wanted; j++) {
                    long dx = *(long*)(edge - 4) - this->land_info.land[j].x;
                    long dy = *(long*)edge - this->land_info.land[j].y;
                    team_size[j + 1] = dx * dx + dy * dy;
                }
                {
                    long* rowp = (long*)index;
                    for (long k = 0; k < land_wanted; k++) {
                        *rowp = k;
                        rowp++;
                    }
                }
                int changed;
                do {
                    changed = 1;
                    for (long l = 1; l < land_wanted; l++) {
                        if (team_size[l + 1] < team_size[l]) {
                            long t = team_size[l];
                            team_size[l] = team_size[l + 1];
                            team_size[l + 1] = t;
                            long d = distances[index1][l];
                            distances[index1][l] = distances[index1][l - 1];
                            distances[index1][l - 1] = d;
                            changed = 0;
                        }
                    }
                } while (!changed);
                index1++;
                edge += 0x34;
                index += 0x20;
            } while (index1 < land_wanted);
        }

        for (long j = 0; j < land_wanted; j++)
            player_teams[j + 1] = -1;
        index = 0;
        index1 = 0;
        if (land_wanted > 0) {
            long* ppt = &player_teams[1];
            long* psize = &team_size[1];
            local_174 = 4 - (long)&player_teams[1];
            do {
                if (*ppt == -1) {
                    *ppt = index;
                    *psize = 1;
                    swap = local_174 + (long)ppt;
                    long* store = &player_teams[1];
                    for (long j = 0; j < land_wanted - 1; j++) {
                        RGE_Player* seed =
                            *(RGE_Player**)((int)this->world->players + swap);
                        if (seed->relation(j + 1) == 0) {
                            *store = index;
                            (*psize)++;
                        }
                        store++;
                    }
                    index++;
                }
                index1++;
                ppt++;
                psize++;
            } while (index1 < land_wanted);
        }

        for (long k = 0; k < land_wanted; k++)
            ty[k + 1] = -1;
        index1 = 0;
        if (index > 0) {
            local_180 = (long)&team_size[1];
            do {
                ty[0] = 0;
                if (land_wanted > 0) {
                    for (long j = 0; j < land_wanted && ty[j + 1] != -1; j++)
                        ty[0] = j + 1;
                }
                edge = 0;
                swap = *(long*)local_180;
                team_size[0] = swap;
                if (swap > 0) {
                    do {
                        long j = 0;
                        for (; j < swap; j++) {
                            if (ty[distances[ty[0]][j] + 1] == -1) {
                                ty[distances[ty[0]][j] + 1] = index1;
                                break;
                            }
                        }
                        if (j >= swap) {
                            if (swap < land_wanted)
                                swap++;
                            for (long k = land_wanted - 1; k >= 0; k--) {
                                if (ty[distances[ty[0]][k] + 1] == -1) {
                                    start_land = distances[ty[0]][k];
                                    break;
                                }
                            }
                            long other_team = -1;
                            if (land_wanted > 0) {
                                for (long k = 0; k < land_wanted; k++) {
                                    long land = distances[start_land][k];
                                    if (ty[land + 1] != index1 && ty[land + 1] >= 0) {
                                        other_team = ty[land + 1];
                                        local_178 = land;
                                        if (swap > 0) {
                                            for (long m = 0; m < swap; m++) {
                                                long land2 = distances[ty[0]][m];
                                                if (ty[land2 + 1] == other_team) {
                                                    local_178 = land2;
                                                    break;
                                                }
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                            ty[start_land + 1] = other_team;
                            ty[local_178 + 1] = -1;
                            if (land_wanted - 1 >= 0) {
                                for (long k = land_wanted - 1; k >= 0; k--) {
                                    long land = distances[other_team][k];
                                    if (ty[land + 1] == other_team) {
                                        for (long m = 0; m < land_wanted; m++) {
                                            long land2 = distances[start_land][m];
                                            if (ty[land2 + 1] == -1 && land2 != local_178) {
                                                ty[land + 1] = -1;
                                                ty[land2 + 1] = other_team;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        edge++;
                    } while (edge < team_size[0]);
                }
                index1++;
                local_180 += 4;
            } while (index1 < index);
        }

        for (long l = 0; l < land_wanted; l++)
            team_size[l + 1] = -1;
        for (long i = 0; i < land_wanted; i++) {
            for (long j = 0; j < land_wanted; j++) {
                if (team_size[j + 1] == -1 && player_teams[j + 1] == ty[i + 1]) {
                    team_size[j + 1] = i;
                    break;
                }
            }
        }
        for (long n = 0; n < land_wanted; n++) {
            player_teams[n + 1] = this->land_info.land[team_size[n + 1]].x;
            ty[n + 1] = this->land_info.land[team_size[n + 1]].y;
        }
        for (long o = 0; o < land_wanted; o++) {
            this->land_info.land[o].x = player_teams[o + 1];
            this->land_info.land[o].y = ty[o + 1];
        }
    }
}
