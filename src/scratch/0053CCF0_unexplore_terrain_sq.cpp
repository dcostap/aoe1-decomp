// VA: 0053CCF0 RGE_Visible_Map::unexplore_terrain_sq
// Source: visible.cpp lines 891-975
// Attempt log:
// baseline candidate: canonical visible-map/world/player/map layout and the natural
// paired unexplore loop; tile advances are unconditional as in the executable.
// self alias plus absolute global surfaces improved relocation/edit alignment but
// did not change the default emitted structure.
// /Oy- reproduced the 381-byte size and moved the frame/register basin closer,
// but still lacked the original two-slot frame and was rolled back as a flag crutch.
// Named width/height and negative-return/control-flow variants were nonproductive.
// Typed unified_map_offsets[256] and full visible.cpp world/player/map/tile record
// surfaces were emitted identically to the clean candidate. A separate typed
// checksum accumulator was likewise optimized to the same code.
// A natural start-column local reached exact size but retained the wrong register
// basin (339 positional bytes); a start-row local improved edit/resync similarity
// to 59.06% and 354 positional bytes, yet still omitted the original EBP frame and
// parameter-home topology. Delaying the self owner made no further change.
// Those source-shape experiments were diagnostic only and were restored.
// This session: hoisted row cursors, reused a function-scope inner count, and
// added string.h context; each emitted the clean 356-byte code unchanged.
// An ordinary self/reference alias for the late mask reload was likewise
// optimized away. A contiguous typed self/tile local aggregate forced an 8-byte
// stack allocation and a 363-byte result but not the oracle's EBP frame, and
// reversing its member order plus old-TU top-level scan locals was unchanged;
// those layout probes were restored.
// Left in scratch: default code is 25 bytes short with broad prologue/register
// drift; canonical behavior and field ownership are stable, but source/ABI context
// still needs a donor-level explanation for the original EBP/local topology.

#include <stdlib.h>
#pragma intrinsic(_rotl)

extern int Map_Update_Suppresion;
extern unsigned long* unified_map_offsets[];
extern "C" void __cdecl log_map_call(int world_time, int player_id, int type,
                                     int p6, int x1, int y1, int x2, int y2,
                                     int suppression);

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x46];
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
    char gap_0004[0x8D88];
    RGE_Tile** map_row_offset;
};

// Main-agent audit replaced raw absolute globals and retained canonical visible
// map/world/player/map ownership with natural square traversal.
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

    void unexplore_terrain_sq(int x1, int y1, int x2, int y2,
                              int update_tiles, int p6);
};

void RGE_Visible_Map::unexplore_terrain_sq(int x1, int y1, int x2, int y2,
                                           int update_tiles, int p6)
{
    RGE_Visible_Map* self = this;
    RGE_Tile* tile = 0;

    log_map_call(self->world->world_time, (int)self->player->id, 4, p6,
                 x1, y1, x2, y2, Map_Update_Suppresion);

    if (Map_Update_Suppresion == 0) {
        p6 = self->input_csum;
        p6 = _rotl(p6, 3);
        p6 ^= 0x56565656;
        p6 = _rotl(p6, 2);
        p6 ^= x1;
        p6 = _rotl(p6, 4);
        p6 ^= y1;
        p6 = _rotl(p6, 3);
        p6 ^= x2;
        p6 = _rotl(p6, 3);
        p6 ^= y2;
        self->input_csum = p6;

        if ((x1 >= self->widthValue) || (x2 < 0) ||
            (y1 >= self->heightValue) || (y2 < 0)) {
            return;
        }
        if (x1 < 0) {
            x1 = 0;
        }
        if (x2 >= self->widthValue) {
            x2 = self->widthValue - 1;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (y2 >= self->heightValue) {
            y2 = self->heightValue - 1;
        }

        for (; y1 <= y2; ++y1) {
                unsigned char* visible = self->map_offsets[y1] + x1;
                unsigned long* explored = unified_map_offsets[y1] + x1;

                if (update_tiles != 0) {
                    tile = self->map->map_row_offset[y1] + x1;
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
}
}
