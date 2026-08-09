// VA: 0053C920 RGE_Visible_Map::unexplore_terrain
// Source: visible.cpp lines 665-767
// Attempt log:
// baseline candidate: canonical visible-map/world/player/map ownership and natural
// LOS-table traversal paired with unexplore_terrain_sq.
// /Oy- moved the candidate into the correct EBP basin and to 384 bytes; absolute
// binary-proven LOS table bases improved relocation/edit alignment, while canonical
// polymorphic map/player surfaces were codegen-neutral.
// Player-id ordering, checksum naming, and LOS skip/control-flow variants were
// nonproductive.  The remaining gap is the original three-local frame and its
// parameter-home reuse; no call or field ownership mismatch is indicated.

#include <stdlib.h>
#pragma intrinsic(_rotl)

extern int Map_Update_Suppresion;
extern unsigned long* unified_map_offsets[];
extern int* NormalLOS[];
extern int* SquareLOS[];

extern "C" void __cdecl log_map_call(int world_time, int player_id, int type,
                                     int p6, int x, int y, int radius, int square,
                                     int suppression);

class RGE_Map;
class RGE_Player;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
    char gap_08[0x28 - 0x08];
    RGE_Map* map;
    char gap_2C[0x40 - 0x2C];
    RGE_Player** players;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char gap_21[1];
    short master_object_num;
    char gap_24[0x18];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

struct RGE_Tile {
    char gap_00[9];
    unsigned char flags_09;
    char gap_0A[0x18 - 0x0A];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_0004[0x8D8C - 4];
    RGE_Tile** map_row_offset;
};

// Main-agent audit replaced raw absolute LOS/unified-map globals and retained
// canonical visible-map ownership with natural row traversal.
class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    unsigned char* visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;
    int numberTotalTilesValue;
    unsigned long PlayerVisibleMaskValue;
    unsigned long PlayerVisibleMaskInvertValue;
    unsigned long PlayerExploredMaskValue;
    unsigned long PlayerExploredMaskInvertValue;
    unsigned long input_csum;

    void unexplore_terrain(int x, int y, int radius, int square,
                           int update_tiles, int p6);
};

void RGE_Visible_Map::unexplore_terrain(int x, int y, int radius, int square,
                                        int update_tiles, int p6)
{
    RGE_Visible_Map* self = this;
    RGE_Tile* tile = 0;
    int player_id;

    log_map_call(self->world->world_time, (int)self->player->id, 3, p6,
                 x, y, radius, square, Map_Update_Suppresion);

    if (Map_Update_Suppresion == 0) {
        player_id = (int)self->player->id;
        p6 = self->input_csum;
        p6 = _rotl(p6, 3);
        p6 ^= 0x20202020;
        p6 = _rotl(p6, 2);
        p6 ^= player_id;
        p6 = _rotl(p6, 3);
        p6 ^= x;
        p6 = _rotl(p6, 4);
        p6 ^= y;
        p6 = _rotl(p6, 3);
        p6 ^= radius;
        p6 += square;
        self->input_csum = p6;

        if (radius > 0x10) {
            radius = 0x10;
        }

        int* offsets;
        if (square != 0) {
            offsets = SquareLOS[radius];
        } else {
            offsets = NormalLOS[radius];
        }

        int off_y = offsets[0];
        while (off_y != 999) {
            off_y += y;
            if ((off_y >= 0) && (off_y < self->heightValue)) {
                int x1 = offsets[1] + x;
                if (x1 < 0) {
                    x1 = 0;
                }
                int x2 = offsets[2] + x;
                if (x2 >= self->widthValue) {
                    x2 = self->widthValue - 1;
                }

                unsigned char* visible = self->map_offsets[off_y] + x1;
                unsigned long* explored = unified_map_offsets[off_y] + x1;
                if (update_tiles != 0) {
                    tile = self->map->map_row_offset[off_y] + x1;
                }

                if (x1 <= x2) {
                    int count = x2 - x1 + 1;
                    do {
                        unsigned char value = *visible;
                        --value;
                        if (value == 0xff) {
                            value = 0;
                        }
                        if (value == 0) {
                            if (update_tiles != 0) {
                                tile->flags_09 = 0x80;
                            }
                            *explored &= self->PlayerVisibleMaskInvertValue;
                        }
                        *visible = value;
                        ++visible;
                        ++explored;
                        ++tile;
                        --count;
                    } while (count != 0);
                }
            }

            offsets += 3;
            off_y = offsets[0];
        }
    }
}
