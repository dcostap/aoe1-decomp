// VA: 00510110 make_new_cliff (399B)
// tmap.cpp
//
// Attempt log:
// baseline: clean typed reconstruction from the make_new_cliff packet and
// the exact RGE_Player::make_new_object / check_destructables ABIs.
// probes 2-9: direct full table indexing, curr_player tile ownership, local
// declaration/lifetime orders, coordinate locals, and top-level loop seeds
// changed only VC5 structural families; the clean typed family remained
// nonexact but retained the correct aggregate-parameter homes.
// probe 10: spelling id2 > -1 moved the compare and improved byte metrics,
// but shifted the aggregate field-home interpretation; rolled back in favor
// of the behavior-preserving id2 >= 0 source.
// left in scratch: calls and semantics are reconstructed; remaining drift is
// table/local scheduling and the late tile/check-destructables block.

struct TRIBE_Cliff_Info {
    long info[4];
};

struct CliffMasterEntry {
    long id;
    long facet;
    long id2;
    long facet2;
    long info[4];
    float offset_x;
    float offset_y;
};

class RGE_Static_Object {
public:
    char gap_00[0x35];
    unsigned char facet;
};

class RGE_Tile_List {
public:
    void add_node(int x, int y);
};

class RGE_Player {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual RGE_Static_Object* make_new_object(long id, float x, float y,
                                                float z, int unused);
    char gap_04[0x68];
    RGE_Tile_List tile_list;
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
};

class TRIBE_World : public RGE_Game_World {
public:
    void check_destructables(short player_id, short master_id,
                             float x, float y, unsigned char flag);
};

class TRIBE_Map {
public:
    char gap_00[0x8DC0];
    TRIBE_World* game_world;
    char gap_8DC4[0x34];
    CliffMasterEntry cliff_master_table[1];

    RGE_Static_Object* make_new_cliff(long x, long y,
                                      TRIBE_Cliff_Info info);
};

extern int __cdecl debug_rand(char* file, int line);

RGE_Static_Object* TRIBE_Map::make_new_cliff(long x, long y,
                                              TRIBE_Cliff_Info info)
{
    int table_index = info.info[2] + (info.info[1] + info.info[0] * 4) * 4;
    int cliff_index = table_index * 4 + info.info[3] + 0x55;
    long id;
    RGE_Static_Object* new_cliff;
    long facet;
    float x_pos = (float)(x * 3) +
        this->cliff_master_table[cliff_index].offset_x;
    float y_pos = (float)(y * 3) +
        this->cliff_master_table[cliff_index].offset_y;

    if (this->cliff_master_table[cliff_index].id2 >= 0 &&
        debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tmap.cpp", 0x221) * 2 > 0x7fff) {
        id = this->cliff_master_table[cliff_index].id2;
        facet = this->cliff_master_table[cliff_index].facet2;
    } else {
        id = this->cliff_master_table[cliff_index].id;
        facet = this->cliff_master_table[cliff_index].facet;
    }

    if (id < 0)
        return 0;

    new_cliff = this->game_world->players[0]->make_new_object(
        id, x_pos, y_pos, 0.0f, 0);

    for (long tile_offset = -1; tile_offset < 2; ++tile_offset) {
        for (long j = -1; j < 2; ++j) {
            this->game_world->players[this->game_world->curr_player]
                ->tile_list.add_node(
                (int)(tile_offset + (long)(x_pos)),
                (int)(j + (long)(y_pos)));
        }
    }

    if (new_cliff != 0)
        new_cliff->facet = (unsigned char)facet;

    this->game_world->check_destructables(0, (short)id, x_pos, y_pos, 1);
    return new_cliff;
}
