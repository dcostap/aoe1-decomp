// 00510430 TRIBE_Map::add_cliff_edge
// Attempt log:
// try 1: direct control-flow reconstruction from packet, local cliff-info array and helper calls: exact-size comparable but broad mismatch (59.8330% positional, 38.3447% edit, first mismatch +6).
// try 2: /GX had no effect; rolled back.
// try 3: swapped x/y parameter spelling to match initial [esp+2c] load; first mismatch moved to +10 but edit diff worsened (40.3189%), rolled back.
// try 4: /O1 too small (.text 987 vs 1317), rolled back.
// try 5: /Od exact-size comparable but debug-basin mismatch (92.4070% positional), rolled back.
// left in scratch: broad but useful behavior skeleton; remaining mismatch is not accepted_drift quality and likely needs the exact original high-level cliff-info control-flow topology and real TRIBE_Cliff_Info/TRIBE_Map declarations.
//
// sa-e4d7ed85-10430 baseline: restored the proven struct-return cliff-info ABI,
// RGE_Game_World/player/tile-list ownership, scalar-deleting destructor surface,
// and make_new_cliff signature before any register or loop-shape tuning.
// Candidate facing/direction declaration/assignment orders, int offset counters,
// early-return/goto variants, and a truthy existing guard did not improve the
// canonical 1262-byte family. Calls/frame/cleanup are exact; remaining drift is
// local-slot coloring and cold block placement around candidate validation.

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
    char gap_00[0x8DC0];
    RGE_Game_World* game_world;

    RGE_Static_Object* find_cliff(long x, long y);
    TRIBE_Cliff_Info get_cliff_info(RGE_Static_Object* cliff);
    unsigned char check_cliff_valid(TRIBE_Cliff_Info info);
    void remove_cliff_edge(long x, long y, long facing);
    RGE_Static_Object* make_new_cliff(long x, long y, TRIBE_Cliff_Info info);
    long add_cliff_edge(long x, long y, long facing, long existing, long other_facing);
};

long TRIBE_Map::add_cliff_edge(long x, long y, long facing, long existing, long other_facing)
{
    RGE_Static_Object* cliff = this->find_cliff(x, y);
    TRIBE_Cliff_Info cliff_info = this->get_cliff_info(cliff);

    long possible_facing1;
    long possible_direction1;
    long possible_facing2;
    long possible_direction2;
    possible_direction1 = 0;
    possible_facing1 = -1;
    possible_direction2 = 0;
    possible_facing2 = -1;

    long old = cliff_info.info[facing];
    if (old != 0) {
        if (existing == 0)
            return old;
        if (existing == old)
            return existing;
    }

    if (cliff != 0) {
        long y_offset = -1;
        do {
            long x_offset = -1;
            do {
                RGE_Game_World* world = this->game_world;
                world->players[world->curr_player]->tile_list.add_node(
                    y_offset + (long)cliff->y,
                    x_offset + (long)cliff->z);
                ++x_offset;
            } while (x_offset < 2);
            ++y_offset;
        } while (y_offset < 2);

        delete cliff;
    }

    if (other_facing == facing)
        other_facing = -1;

    if (other_facing < 0) {
        long count = 0;
        long i = 0;
        do {
            if (cliff_info.info[i] != 0 && i != facing)
                ++count;
            ++i;
        } while (i < 4);

        if (count == 2) {
            i = 0;
            do {
                if (cliff_info.info[i] != 0 && i != facing) {
                    if (possible_facing1 < 0) {
                        possible_direction1 = cliff_info.info[i];
                        possible_facing1 = i;
                    } else {
                        possible_direction2 = cliff_info.info[i];
                        possible_facing2 = i;
                    }
                    cliff_info.info[i] = 0;
                }
                ++i;
            } while (i < 4);
        }
    } else {
        long i = 0;
        do {
            if (i != other_facing) {
                this->remove_cliff_edge(x, y, i);
                cliff_info.info[i] = 0;
            }
            ++i;
        } while (i < 4);
    }

    if (existing) {
        cliff_info.info[facing] = existing;

        if (possible_facing1 > -1) {
            cliff_info.info[possible_facing1] = possible_direction1;
            if (!this->check_cliff_valid(cliff_info)) {
                cliff_info.info[possible_facing1] = 0;
                this->remove_cliff_edge(x, y, possible_facing1);
            }
        }

        if (possible_facing2 > -1) {
            cliff_info.info[possible_facing2] = possible_direction2;
            if (!this->check_cliff_valid(cliff_info)) {
                cliff_info.info[possible_facing2] = 0;
                this->remove_cliff_edge(x, y, possible_facing2);
            }
        }

        if (!this->check_cliff_valid(cliff_info)) {
            long i = 0;
            do {
                if (i != facing && cliff_info.info[i] != 0) {
                    this->remove_cliff_edge(x, y, i);
                    cliff_info.info[i] = 0;
                }
                ++i;
            } while (i < 4);
        }
    } else {
        bool found = false;
        existing = 1;
        cliff_info.info[facing] = 1;

        if (possible_facing1 > -1) {
            cliff_info.info[possible_facing1] = possible_direction1;
            if (!this->check_cliff_valid(cliff_info))
                cliff_info.info[possible_facing1] = 0;
            else {
                found = true;
                possible_direction1 = 0;
            }
        }

        if (!found && possible_facing2 > -1) {
            cliff_info.info[possible_facing2] = possible_direction2;
            if (!this->check_cliff_valid(cliff_info))
                cliff_info.info[possible_facing2] = 0;
            else {
                found = true;
                possible_direction2 = 0;
            }
        }

        if (!found && !this->check_cliff_valid(cliff_info)) {
            cliff_info.info[facing] = -1;
            existing = -1;
            found = false;

            if (possible_facing1 > -1) {
                cliff_info.info[possible_facing1] = possible_direction1;
                if (!this->check_cliff_valid(cliff_info))
                    cliff_info.info[possible_facing1] = 0;
                else {
                    found = true;
                    possible_direction1 = 0;
                }
            }

            if (!found && possible_facing2 > -1) {
                cliff_info.info[possible_facing2] = possible_direction2;
                if (!this->check_cliff_valid(cliff_info))
                    cliff_info.info[possible_facing2] = 0;
                else {
                    found = true;
                    possible_direction2 = 0;
                }
            }

            if (!found && !this->check_cliff_valid(cliff_info)) {
                long i = 0;
                do {
                    if (i != facing && cliff_info.info[i] != 0) {
                        this->remove_cliff_edge(x, y, i);
                        cliff_info.info[i] = 0;
                    }
                    ++i;
                } while (i < 4);
            }
        }
    }

    if (possible_direction1 != 0)
        this->remove_cliff_edge(x, y, possible_facing1);
    if (possible_direction2 != 0)
        this->remove_cliff_edge(x, y, possible_facing2);

    this->make_new_cliff(x, y, cliff_info);
    return existing;
}
