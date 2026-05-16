// 0053C6F0 RGE_Visible_Map::explore_terrain(int,int,int,int,int,int)
// Source: visible.cpp lines 521-658
// FLAGS: config/flags/0053C6F0_explore_terrain.rsp
// Attempt log:
// - Initial natural source from packet/decompiler.
// - Default /O2 /Oy compiled without EBP frame; original has EBP frame and stack locals, so added narrow /Oy- flags in config/flags/0053C6F0_explore_terrain.rsp.
// - Corrected RGE_Visible_Map local layout: map_offsets +0, world +4, player +8, map +0xC, width +0x14, height +0x18, numberTilesExplored +0x1C, visible/explored masks +0x24/+0x2C, checksum +0x34.
// - Modeled RGE_Tile_List as 0x14 bytes so player tile_list is at +0x58 and diam_tile_list at +0x6C; adjusted mutualAlly to +0xAC.
// - Fixed source bug from decompiler stack reuse: do not assign radius=0; use a separate tile pointer local so radius remains in ESI for LOS table indexing/capping.
// - Changed version of suppression check to compare against a zero temp; VC5 still kept object .text at 0x220.
// - Current state: compiles but check_function stops before diff because rebuilt .text is 544 bytes while configured/original function size is 546. Dump shows broad structure very close (EBP frame, same stack size, prologue/log_map_call, main loop shape, calls, masks), but checksum/setup and some local-slot allocation still differ. Left in scratch; no inline asm.

extern "C" unsigned int __cdecl _rotl(unsigned int, int);
extern int Map_Update_Suppresion;
extern int* NormalLOS[17];
extern int* SquareLOS[17];
extern int* unified_map_offsets[];

void __cdecl log_map_call(int world_time, int player_id, int one, int p6, int p1, int p2, int p3, int p4, int suppressed);

class RGE_Tile_List {
public:
    char gap_000[0x14];
    void add_node(int x, int y);
};

class RGE_Player {
public:
    char gap_000[0x4A];
    short id;
    char gap_04C[0x58 - 0x4C];
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    char gap_080[0xAC - 0x80];
    int mutualAlly[32];
};

class RGE_World {
public:
    char gap_000[4];
    int world_time;
    char gap_008[0x40 - 0x08];
    RGE_Player** players;
    char gap_044[0x7C - 0x44];
    short curr_player;
};

class RGE_Map {
public:
    char gap_000[0x8D8C];
    void** map_row_offset;
};

class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    RGE_World* world;
    RGE_Player* player;
    RGE_Map* map;
    char gap_010[0x14 - 0x10];
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;
    char gap_020[0x24 - 0x20];
    int PlayerVisibleMaskValue;
    char gap_028[0x2C - 0x28];
    int PlayerExploredMaskValue;
    char gap_030[0x34 - 0x30];
    int input_csum;

    int explore_terrain(int x, int y, int radius, int square, int update_tiles, int p6);
};

int RGE_Visible_Map::explore_terrain(int x, int y, int radius, int square, int update_tiles, int p6)
{
    int Revealed;
    int checksum;
    RGE_Player* curPlayer;
    int VisibleToCurPlayer;
    RGE_Player* curVisPlayer;
    int* offsets;
    int offY;
    int y2;
    int x1;
    int x2;
    unsigned char* vis;
    int* unified;
    char* tile;
    unsigned char v;

    Revealed = 0;
    log_map_call(this->world->world_time, this->player->id, 1, p6, x, y, radius, square, Map_Update_Suppresion);
    checksum = 0;
    if (Map_Update_Suppresion != checksum) {
        return 0;
    }

    p6 = this->input_csum;
    checksum = this->player->id;
    p6 = _rotl(p6, 3);
    p6 ^= 0x01010101;
    p6 = _rotl(p6, 2);
    p6 ^= checksum;
    p6 = _rotl(p6, 3);
    p6 ^= x;
    p6 = _rotl(p6, 4);
    p6 ^= y;
    p6 = _rotl(p6, 3);
    p6 ^= radius;
    p6 += square;
    this->input_csum = p6;

    curPlayer = this->world->players[this->world->curr_player];
    if (curPlayer != 0) {
        VisibleToCurPlayer = (curPlayer->mutualAlly[this->player->id] == 1);
    }
    else {
        VisibleToCurPlayer = 0;
    }
    tile = 0;
    curVisPlayer = 0;
    if (VisibleToCurPlayer) {
        curVisPlayer = curPlayer;
    }

    if (radius > 0x10) {
        radius = 0x10;
    }

    if (square != 0) {
        offsets = SquareLOS[radius];
    }
    else {
        offsets = NormalLOS[radius];
    }

    offY = offsets[0];
    while (offY != 999) {
        y2 = y + offY;
        if (y2 >= 0 && y2 < this->heightValue) {
            x1 = x + offsets[1];
            if (x1 < 0) {
                x1 = 0;
            }
            x2 = x + offsets[2];
            if (x2 >= this->widthValue) {
                x2 = this->widthValue - 1;
            }
            vis = this->map_offsets[y2] + x1;
            unified = unified_map_offsets[y2] + x1;
            if (update_tiles != 0) {
                tile = (char*)this->map->map_row_offset[y2] + x1 * 24;
            }
            while (x1 <= x2) {
                v = (unsigned char)(*vis + 1);
                if (v == 0) {
                    Revealed++;
                    this->numberTilesExploredValue++;
                    this->player->tile_list.add_node(x1, y2);
                    if (VisibleToCurPlayer) {
                        curVisPlayer->diam_tile_list.add_node(x1, y2);
                    }
                    v = 1;
                    *unified |= this->PlayerExploredMaskValue;
                }
                if (v == 1) {
                    if (update_tiles != 0) {
                        tile[9] = 0x0F;
                    }
                    *unified |= this->PlayerVisibleMaskValue;
                }
                if (v == 0xFA) {
                    v = 0xF9;
                }
                *vis = v;
                vis++;
                unified++;
                x1++;
                tile += 24;
            }
        }
        offsets += 3;
        offY = offsets[0];
    }
    return Revealed;
}
