// 00510430 TRIBE_Map::add_cliff_edge
// Attempt log:
// try 1: direct control-flow reconstruction from packet, local cliff-info array and helper calls: exact-size comparable but broad mismatch (59.8330% positional, 38.3447% edit, first mismatch +6).
// try 2: /GX had no effect; rolled back.
// try 3: swapped x/y parameter spelling to match initial [esp+2c] load; first mismatch moved to +10 but edit diff worsened (40.3189%), rolled back.
// try 4: /O1 too small (.text 987 vs 1317), rolled back.
// try 5: /Od exact-size comparable but debug-basin mismatch (92.4070% positional), rolled back.
// left in scratch: broad but useful behavior skeleton; remaining mismatch is not accepted_drift quality and likely needs the exact original high-level cliff-info control-flow topology and real TRIBE_Cliff_Info/TRIBE_Map declarations.
// shardA4-510430-r1: removed the named old-edge temporary and used direct typed
// cliff_info[facing] guards/returns; VC5 emitted the unchanged 1262-byte family.
//
// sa-e4d7ed85-10430 baseline: restored the proven struct-return cliff-info ABI,
// RGE_Game_World/player/tile-list ownership, scalar-deleting destructor surface,
// and make_new_cliff signature before any register or loop-shape tuning.
// Candidate facing/direction declaration/assignment orders, int offset counters,
// early-return/goto variants, and a truthy existing guard did not improve the
// canonical 1262-byte family. Calls/frame/cleanup are exact; remaining drift is
// local-slot coloring and cold block placement around candidate validation.
// orch-510430-a: full-width int `found` follows the oracle's ESI xor/set/test
// shape and improves structural size to 1286 bytes, but positional diff worsens;
// keep the clean bool source. Candidate initialization order, int candidate
// locals, typed field pointers, and tile operand order were codegen duplicates.
// orch-510430-a: the oracle returns the existing parameter (zero) when the
// requested facing already exists and existing is zero; keep that behavior in
// the final clean source despite the common-return codegen gap.
//
// sa-ae373c87-r1 final pass: ran 22 source-led probes after the baseline.
// The clean baseline remains the smallest natural source model. It has 1270
// rebuilt bytes versus 1317 original bytes, 23/23 ordered calls, frame 0x24,
// and 1166 differing positions (88.5345%). The best experimental basin used
// an explicit empty zero arm and bool found: 1274 bytes and 1130 differences,
// but that arm is not a supported source reconstruction. It was rolled back.
//
// Evidence learned: helper ABI, aggregate return storage, object layout,
// tile-list ownership, destructor call, frame, and call order are stable.
// The remaining drift starts at the facing local and candidate slot colors.
// The original uses direction1/facing1/direction2/facing2 homes at entry
// offsets -0x24/-0x20/-0x1C/-0x18. VC5 keeps a different color basin here.
// The original also uses a shared zero-return edge and a larger cold layout.
//
// Tested and rolled back: combined and inverted early guards, a common-return
// goto, direction/facing declaration and assignment orders, register and const
// facing, narrow facing, narrow counters, int candidate locals, scoped aliases,
// split aggregate assignment, int found, tile temporaries, and a full RGE_Map
// base. These tests were neutral, worse, or reached a broad different basin.
// Follow-up pass: inverting the save_direction arm to put removal on the
// fall-through path recovered the original cold-block order and reduced the
// mismatch to 890 bytes with 92.79% shape similarity, 1308 bytes, and 23/23
// ordered calls. Reordering the sentinel and candidate stores recovered the
// observed local-store order. The original zero-return edge, add_node register
// order, and no-existing found/pointer color remain unresolved.
// Tested and rolled back in this pass: shared-return goto, widened found,
// function-scope found, split found initialization, receiver/player aliases,
// candidate pointers, explicit initial guard inversion, and chained assignment.
// Grouped TU audit: the canonical RGE_Player surface names the +0x6C list
// diam_tile_list.  Keep that owner name in this local declaration as well.
// sa-7e83054e-r1 fresh context gate: module tmap.cpp, source band 631-815,
// owner TRIBE_Map, address sequence follows 005102A0 and precedes 00510960,
// with exact anchors 00510110, 00510410, and 00510960 in the wrapper. Fresh
// grouped evidence keeps the 23 ordered calls and the 0x24 frame, but not the
// cold control-flow layout or local-slot colors. Prior grouped and walkback
// reports were reviewed; their rejected guard and local forms are not reused.

#ifndef TMAP_GROUP_CONTEXT
struct TRIBE_Cliff_Info {
    long info[4];
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
    virtual ~RGE_Player();
    char gap_04[0x68];
    RGE_Tile_List diam_tile_list;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x3C];
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
#endif

long TRIBE_Map::add_cliff_edge(long x, long y, long facing, long existing, long other_facing)
{
    RGE_Static_Object* cliff = this->find_cliff(x, y);
    TRIBE_Cliff_Info cliff_info = this->get_cliff_info(cliff);

    long possible_facing2;
    long possible_direction1;
    long possible_facing1;
    long possible_direction2;
    possible_direction1 = 0;
    possible_facing2 = -1;
    possible_facing1 = -1;
    possible_direction2 = 0;

    if (cliff_info.info[facing] != 0) {
        if (existing == 0)
            return existing;
        if (existing == cliff_info.info[facing])
            return existing;
    }

    if (cliff != 0) {
        long y_offset = -1;
        do {
            long x_offset = -1;
            do {
                RGE_Game_World* world = this->game_world;
                world->players[world->curr_player]->diam_tile_list.add_node(
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

    if (other_facing >= 0) {
        long i = 0;
        do {
            if (i != other_facing) {
                this->remove_cliff_edge(x, y, i);
                cliff_info.info[i] = 0;
            }
            ++i;
        } while (i < 4);
    } else {
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
                    if (possible_facing2 < 0) {
                        possible_facing2 = i;
                        possible_direction1 = cliff_info.info[i];
                    } else {
                        possible_facing1 = i;
                        possible_direction2 = cliff_info.info[i];
                    }
                    cliff_info.info[i] = 0;
                }
                ++i;
            } while (i < 4);
        }
    }

    if (existing) {
        cliff_info.info[facing] = existing;

        if (possible_facing2 > -1) {
            cliff_info.info[possible_facing2] = possible_direction1;
            if (!this->check_cliff_valid(cliff_info)) {
                cliff_info.info[possible_facing2] = 0;
                this->remove_cliff_edge(x, y, possible_facing2);
            }
        }

        if (possible_facing1 > -1) {
            cliff_info.info[possible_facing1] = possible_direction2;
            if (!this->check_cliff_valid(cliff_info)) {
                cliff_info.info[possible_facing1] = 0;
                this->remove_cliff_edge(x, y, possible_facing1);
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

        if (possible_facing2 > -1) {
            cliff_info.info[possible_facing2] = possible_direction1;
            if (!this->check_cliff_valid(cliff_info))
                cliff_info.info[possible_facing2] = 0;
            else {
                found = true;
                possible_direction1 = 0;
            }
        }

        if (!found && possible_facing1 > -1) {
            cliff_info.info[possible_facing1] = possible_direction2;
            if (!this->check_cliff_valid(cliff_info))
                cliff_info.info[possible_facing1] = 0;
            else {
                found = true;
                possible_direction2 = 0;
            }
        }

        if (!found && !this->check_cliff_valid(cliff_info)) {
            cliff_info.info[facing] = -1;
            existing = -1;
            found = false;

            if (possible_facing2 > -1) {
                cliff_info.info[possible_facing2] = possible_direction1;
                if (!this->check_cliff_valid(cliff_info))
                    cliff_info.info[possible_facing2] = 0;
                else {
                    found = true;
                    possible_direction1 = 0;
                }
            }

            if (!found && possible_facing1 > -1) {
                cliff_info.info[possible_facing1] = possible_direction2;
                if (!this->check_cliff_valid(cliff_info))
                    cliff_info.info[possible_facing1] = 0;
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
        this->remove_cliff_edge(x, y, possible_facing2);
    if (possible_direction2 != 0)
        this->remove_cliff_edge(x, y, possible_facing1);

    this->make_new_cliff(x, y, cliff_info);
    return existing;
}
