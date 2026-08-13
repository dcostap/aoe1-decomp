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
// orch-tmap-02 fresh pass: baseline revalidated the exact donor-derived
// behavior/call surface. Full RGE_Map/TRIBE_Map virtual context, initialized
// aggregate return, mixed map aliases, unqualified donor-style calls, long
// reverse local, and counter/lifetime variants did not recover the saved-this
// family. The oracle proves case-2/case-3 use test+jle, so the living source
// keeps x <= 0/y <= 0 and the donor-shaped long-outer/int-inner do/while;
// this improves aligned blocks but leaves the 360-byte VC5 family. Remaining
// blocker: oracle homes this in [esp+10] and uses EBP/ESI for outer/inner,
// while the rebuild keeps this in EBP and spills outer to [esp+10].
// left in scratch: behavior/calls/CFG are understood; remaining mismatch is
// VC5 saved-this/register and pre-switch scheduling, not a semantic gap.
// sa-0a6dbc5b-r1 fresh pass: revalidated the clean baseline and tested
// register-qualified/int-vs-long outer counters, a canonical RGE_Map base,
// address-taken info, scalar/aggregate saved-this overlays, and a narrow
// volatile self-pointer. The five-word overlay did force EBP/ESI loop roles
// but widened the frame to 0x28; volatile self reached exact size but a broad
// wrong EBX/volatile-reload family. All diagnostic variants were rolled back.
// final clean source remains the typed donor-shaped reconstruction; blocker is
// the binary's saved-this [esp+10] versus VC5's EBP=this/outer home choice.
// tu-tmap-5102A0 probe 1: moving the natural info local before the switch was
// codegen-neutral; the frame still loaded dir before allocation.
// tu-tmap-5102A0 probe 2: a named map receiver with the donor do/while was also
// codegen-neutral; restored the clean typed donor reconstruction.
// sa7b8c14ff-edge baseline: revalidated the clean donor-shaped source at
// 360 rebuilt bytes versus the 339-byte oracle.
// sa7b8c14ff-edge probe: a partial map alias used direct this for the switch
// and find/info calls, then map for the live-cliff arm; codegen was neutral.
// sa7b8c14ff-edge probe: a late map alias inside the live-cliff arm was also
// neutral. Restored the clean typed source.
// sa7b8c14ff-edge final: retain canonical map, cliff-info, and tile ownership.
// The blocker remains saved-this [esp+10] versus VC5 EBP=this allocation.
// shardC5-5102A0 baseline: revalidated the typed donor-shaped source and its
// 8-call ABI surface. A natural pre-switch cliff_info.info[0] = (long)this
// lead, supported by add_cliff_edge, was codegen-neutral and was rolled back.

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
        if (x <= 0)
            return;
        --x;
        break;
    case 3:
        if (y <= 0)
            return;
        --y;
        break;
    }

    TRIBE_Cliff_Info cliff_info;
    RGE_Static_Object* cliff = this->find_cliff(x, y);
    cliff_info = this->get_cliff_info(cliff);

    if (cliff != 0) {
        long outer = -1;
        do {
            int inner = -1;
            do {
                this->game_world->players[this->game_world->curr_player]
                    ->tile_list.add_node(outer + (long)cliff->y,
                                         inner + (long)cliff->z);
                ++inner;
            } while (inner < 2);
            ++outer;
        } while (outer < 2);

        delete cliff;

        int reverse = this->reverse_cliff_direction(dir);
        cliff_info.info[reverse] = 0;
        this->make_new_cliff(x, y, cliff_info);
    }
}
