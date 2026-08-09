// VA: 005102A0 remove_cliff_edge (339B)
// tmap.cpp
//
// Attempt log:
// baseline: clean reconstruction from the exact tmap.cpp delete_cliff donor;
// remaining metrics are recorded by target_session.
// probes 2-9: top declarations, named receiver, do/while counters, inherited
// map context, loop-local world, seed/liveness, ABI spelling, and declaration
// order all emitted the same 360-byte structural family (338-byte diff).
// probe 10: a typed map-plus-info aggregate widened the frame to 0x28 and
// worsened the topology; rolled back.
// left in scratch: behavior/calls/CFG are understood; remaining mismatch is
// VC5 saved-this/register and pre-switch scheduling, not a semantic gap.

struct TRIBE_Cliff_Info {
    int info[4];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x34];
    float y;
    float z;
};

class RGE_Tile_List {
public:
    char gap_00[0x14];
    void add_node(int col, int row);
};

class RGE_Player {
public:
    char gap_00[0x6C];
    RGE_Tile_List tile_list;
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
};

class TRIBE_Map {
public:
    char gap_00[0x8];
    long map_width;
    long map_height;
    char gap_10[0x8DB0];
    RGE_Game_World* game_world;

    RGE_Static_Object* find_cliff(long x, long y);
    TRIBE_Cliff_Info get_cliff_info(RGE_Static_Object* obj);
    long reverse_cliff_direction(long dir);
    RGE_Static_Object* make_new_cliff(long x, long y, TRIBE_Cliff_Info info);
    void remove_cliff_edge(long x, long y, long dir);
};

void TRIBE_Map::remove_cliff_edge(long x, long y, long dir)
{
    switch (dir) {
    case 0:
        ++x;
        if (x >= this->map_width)
            return;
        break;
    case 1:
        ++y;
        if (y >= this->map_height)
            return;
        break;
    case 2:
        if (x < 1)
            return;
        --x;
        break;
    case 3:
        if (y < 1)
            return;
        --y;
        break;
    }

    TRIBE_Cliff_Info cliff_info;
    RGE_Static_Object* cliff = this->find_cliff(x, y);
    cliff_info = this->get_cliff_info(cliff);

    if (cliff != 0) {
        for (int outer = -1; outer < 2; ++outer) {
            for (int inner = -1; inner < 2; ++inner) {
                this->game_world->players[this->game_world->curr_player]
                    ->tile_list.add_node(outer + (int)cliff->y,
                                         inner + (int)cliff->z);
            }
        }

        delete cliff;

        int reverse = this->reverse_cliff_direction(dir);
        cliff_info.info[reverse] = 0;
        this->make_new_cliff(x, y, cliff_info);
    }
}
