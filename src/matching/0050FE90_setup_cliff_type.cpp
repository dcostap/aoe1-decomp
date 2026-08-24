// 0050FE90 setup_cliff_type (137 bytes) — MATCHED
// PDB: tmap.cpp (TRIBE_Map::setup_cliff_type)

#ifndef TMAP_GROUP_CONTEXT
struct CliffMasterEntry {
    int id;
    int facet;
    int id2;
    int facet2;
    int slot_info[4];
    float offset_x;
    float offset_y;
};

class TRIBE_Map {
public:
    char gap_8DF8[0x8DF8];
    CliffMasterEntry cliff_master_table[1];

    void setup_cliff_type(long param_1, long param_2, long param_3,
                          long param_4, long param_5, long param_6,
                          long param_7, long param_8, float param_9,
                          float param_10);
};
#endif

void TRIBE_Map::setup_cliff_type(long param_1, long param_2, long param_3,
                                 long param_4, long param_5, long param_6,
                                 long param_7, long param_8, float param_9,
                                  float param_10)
{
    int iVar1;
    int idx;

    iVar1 = param_3 + (param_2 + param_1 * 4) * 4;
    idx = iVar1 * 4 + param_4 + 0x55;

    this->cliff_master_table[idx].id = param_5;
    this->cliff_master_table[idx].facet = param_6;
    this->cliff_master_table[idx].id2 = param_7;
    this->cliff_master_table[idx].facet2 = param_8;
    this->cliff_master_table[idx].offset_x = param_9;
    this->cliff_master_table[idx].offset_y = param_10;
    this->cliff_master_table[idx].slot_info[0] = param_1;
    this->cliff_master_table[idx].slot_info[1] = param_2;
    this->cliff_master_table[idx].slot_info[2] = param_3;
    this->cliff_master_table[idx].slot_info[3] = param_4;
}
