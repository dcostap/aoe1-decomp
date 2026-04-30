// 00510960 TRIBE_Map::delete_cliff(long, long)
// Source: tmap.cpp lines 819-838
// Size: 228 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: PARKED — VC5 codegen drift (70.2% positional, 52.6% edit diff)
//
// Attempt log:
// Probe 1: initial impl — 72.4% positional, full 228 bytes
// Probe 2: fix game_world offset + virtual dispatch — 72.4%
// Probe 3: minimize locals, direct float access — 70.2%
// Probe 4: use (long) cast for ftol — 70.2%, virtual call matches pattern
//
// Key findings:
// - this->game_world at +0x8DC0 (RGE_Map base, confirmed via type dump)
// - game_world->players at +0x40, game_world->curr_player at +0x7C
// - player->diam_tile_list at +0x6C (RGE_Tile_List, 0x14 bytes)
// - cliff->y at +0x38 (float), cliff->z at +0x3C (float)
// - RGE_Tile_List::add_node is a direct call, not virtual
// - Unused find_cliff result after first get_cliff_info call is normal
// - cliff release via vtable[0] with arg 1
// - Prologue first 7 bytes match (mov/sub pattern)
//
// Remaining drift (VC5 register/scheduling):
// - Register allocation: this in edi(me) vs ebp(orig), cliff in ebp(me) vs ebx(orig)
// - Info copy from stack slots vs get_cliff_info return pointer
// - Epilogue register save order + truncated (no room for add esp,ret)

// __ftol is an intrinsic — use (long) cast instead

struct RGE_Tile_List {
    char gap_00[0x14];
    void add_node(int, int);
};

struct RGE_Game_World {
    char gap_00[0x40];
    char* players;              // +0x40
    char gap_44[0x38];
    short curr_player;           // +0x7C
};

struct RGE_Map {
    char pad_00[0x8DC0];
    RGE_Game_World* game_world;  // +0x8DC0
};

struct TRIBE_Map : RGE_Map {
    void* find_cliff(long, long);
    void* get_cliff_info(void* info, void* cliff);
    void remove_cliff_edge(long, long, int);
    void delete_cliff(long, long);
};

struct RGE_Static_Object {
    virtual void release(int);
};

struct RGE_Player {
    char gap_00[0x6C];
    RGE_Tile_List tile_list;
};

void TRIBE_Map::delete_cliff(long param_1, long param_2)
{
    void* cliff = find_cliff(param_1, param_2);

    int info[4];
    get_cliff_info(info, cliff);

    if (cliff != 0) {
        int pInfo[4];
        get_cliff_info(pInfo, cliff);

        info[0] = pInfo[0];
        info[1] = pInfo[1];
        info[2] = pInfo[2];
        info[3] = pInfo[3];

        for (int i = 0; i < 4; i++) {
            if (info[i] != 0)
                remove_cliff_edge(param_1, param_2, i);
        }

        int* pFloats = (int*)((char*)cliff + 0x38);
        RGE_Game_World* world = game_world;

        long outer = -1;
        do {
            int inner = -1;
            do {
                float fz = *(float*)(pFloats + 1);
                int y = (long)fz + inner;
                float fy = *(float*)(pFloats);
                int x = (long)fy + outer;

                RGE_Player* player = *(RGE_Player**)(world->players + world->curr_player * 4);
                player->tile_list.add_node(x, y);

                inner++;
            } while (inner < 2);
            outer++;
        } while (outer < 2);

        ((RGE_Static_Object*)cliff)->release(1);
    }
}
