struct TRIBE_Cliff_Info {
    int info[4];
};

struct CliffMasterEntry {
    int id;
    char gap_04[4];
};

class TRIBE_Map {
public:
    char gap_00[0x9B40];
    CliffMasterEntry cliff_master_table[0x1B1];

    unsigned char check_cliff_valid(TRIBE_Cliff_Info info);
};

unsigned char TRIBE_Map::check_cliff_valid(TRIBE_Cliff_Info info) {
    int index = info.info[3] + (info.info[2] + (info.info[1] + info.info[0] * 4) * 4) * 4;
    int id = this->cliff_master_table[index].id;

    return id >= 0;
}
