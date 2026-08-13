// 005111A0 TRIBE_Map::tribe_clean_terrain
// Attempt log:
// try 1: direct behavioral skeleton from packet: clamp/expand brush rect, scan neighbor passability, place terrain around edges, redraw/final cleanup; default /O2 too small (.text 1392 vs 1562).
// try 2: /GX no change from try 1; rolled back.
// try 3: /Od exact-size comparable but debug-basin broad mismatch: 93.8540% positional / 154.0333% edit, first mismatch prologue; rolled back.
// try 4: /O1 too small (.text 1179); rolled back.
// try 5: /O2 without /Oy no change from default; rolled back.
// left in scratch: no custom flags retained. Not accepted_drift quality; likely needs exact original nested condition topology and real TRIBE_Map/terrain helper declarations; current skeleton captures main behavior but not VC5 local/register/frame shape.
//
// sa-e4d7ed85-111a0 baseline: model the RGE_Map row table as 0x18-byte tiles,
// use terrain byte +5 and water/do_terrain_brush_check/set_terrain helper ABIs,
// and use the decorated four-long/two-uchar parameter ABI.
// probe: function-scope tile/neighbor locals and packet-derived short offset order did not change the initial basin.
// probe: executable bVar placement predicates (two straight passes plus four staged diagonal tests) recovered 178 bytes and brought the emitted size to 1570 vs 1562; all 21 calls and the 0x44 frame align.
// probe: long loop cursors and register qualifications were codegen duplicates.
// probe: grouped the diagonal water checks under top/bottom row guards from the packet; size 1562 and first mismatch moved to 005111F9.
// left in scratch: remaining drift is the VC5 local/register basin and loop/prologue topology; current source keeps the named tile/neighbor ownership and executable predicate structure.

typedef unsigned char uchar;

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    uchar tile_type;
    uchar terrain;
    char gap_06[0x18 - 0x06];
};

class RGE_Player;
class RGE_Game_World;

class RGE_Map {
public:
    void* vtable;
    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    char gap_18[0x8D8C - 0x18];
    RGE_Tile** map_row_offset;
    char gap_8D90[0x30];
    void* game_world;

    void set_terrain(void* world, short x, short y, uchar terrain, int a, int b);
    void set_terrain(RGE_Player* player, RGE_Game_World* world,
                     int x1, int y1, long x2, long y2,
                     uchar terrain, uchar apply_terrain, int behavior);
};

class TRIBE_Map : public RGE_Map {
public:
    uchar water(uchar terrain);
    uchar do_terrain_brush_check(long x, long y);
    void clean_borders(long x1, long y1, long x2, long y2, uchar terrain);
    void tribe_clean_terrain(long x1, long y1, long x2, long y2,
                             uchar flag, uchar terrain);
};

void TRIBE_Map::tribe_clean_terrain(long x1, long y1, long x2, long y2,
                                    uchar flag, uchar terrain)
{
    uchar change_flag;
    RGE_Tile* tile;
    short up;
    short upper_right;
    short right;
    short lower_right;
    short down;
    short lower_left;
    short left;
    short upper_left;
    short width = (short)this->map_width;
    short up_left_offset = (short)(-1 - width);
    short down_offset = width;
    short up_offset = (short)-width;
    short up_right_offset = (short)(1 - width);
    short down_right_offset = (short)(width + 1);
    short down_left_offset = (short)(width - 1);

    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (x2 >= this->map_width)
        x2 = this->map_width - 1;
    if (y2 >= this->map_height)
        y2 = this->map_height - 1;

    do {
        change_flag = 0;
        if (x1 > 0)
            --x1;
        if (y1 > 0)
            --y1;
        if (x2 < this->map_width - 1)
            ++x2;
        if (y2 < this->map_height - 1)
            ++y2;

        for (long pass = 0; pass < 2; ++pass) {
            for (long y = y1; y <= y2; ++y) {
                long x = x1;
                tile = this->map_row_offset[y] + x;
                if (x <= x2) {
                    do {
                        if (!this->water(tile->terrain & 0x1f)) {
                            up = 0;
                            upper_right = 0;
                            right = 0;
                            lower_right = 0;
                            down = 0;
                            lower_left = 0;
                            left = 0;
                            upper_left = 0;

                            if (y > 0 && this->water((tile[up_offset]).terrain & 0x1f))
                                up = 1;
                            if (y < this->map_height - 1 &&
                                this->water((tile[down_offset]).terrain & 0x1f))
                                down = 1;
                            if (x > 0 && this->water((tile - 1)->terrain & 0x1f))
                                left = 1;
                            if (x < this->map_width - 1 &&
                                this->water((tile + 1)->terrain & 0x1f))
                                right = 1;
                            if (y > 0) {
                                if (x > 0 &&
                                    this->water((tile[up_left_offset]).terrain & 0x1f))
                                    upper_left = 1;
                                if (x < this->map_width - 1 &&
                                    this->water((tile[up_right_offset]).terrain & 0x1f))
                                    upper_right = 1;
                            }
                            if (y < this->map_height - 1) {
                                if (x > 0 &&
                                    this->water((tile[down_left_offset]).terrain & 0x1f))
                                    lower_left = 1;
                                if (x < this->map_width - 1 &&
                                    this->water((tile[down_right_offset]).terrain & 0x1f))
                                    lower_right = 1;
                            }

                            uchar place = 0;
                            if (pass == 0) {
                                if ((up && down) || (left && right))
                                    place = 1;
                            } else {
                                if (upper_left) {
                                    if ((upper_right && !up) ||
                                        (right && !upper_right) ||
                                        (lower_left && !left) ||
                                        (down && !lower_left))
                                        place = 1;
                                    else if (lower_right && !down && !right)
                                        place = 1;
                                }
                                if (upper_right && !place) {
                                    if ((upper_left && !up) ||
                                        (left && !upper_left) ||
                                        (lower_right && !right) ||
                                        (down && !lower_right) ||
                                        (lower_left && !left && !down))
                                        place = 1;
                                }
                                if (lower_right && !place) {
                                    if ((upper_right && !right) ||
                                        (up && !upper_right) ||
                                        (lower_left && !down) ||
                                        (left && !lower_left) ||
                                        (upper_left && !left && !up))
                                        place = 1;
                                }
                                if (lower_left && !place) {
                                    if ((upper_left && !left) ||
                                        (up && !upper_left) ||
                                        (lower_right && !down) ||
                                        (right && !lower_right) ||
                                        (upper_right && !right && !up))
                                        place = 1;
                                }
                            }

                            if (place) {
                                if (this->water(terrain)) {
                                    if (this->do_terrain_brush_check(x, y))
                                        this->set_terrain(this->game_world,
                                                          (short)x, (short)y,
                                                          terrain, 0, 0);
                                } else {
                                    if (upper_left)
                                        this->set_terrain(this->game_world,
                                                          (short)(x - 1), (short)(y - 1), terrain, 0, 0);
                                    if (up)
                                        this->set_terrain(this->game_world,
                                                          (short)x, (short)(y - 1), terrain, 0, 0);
                                    if (upper_right)
                                        this->set_terrain(this->game_world,
                                                          (short)(x + 1), (short)(y - 1), terrain, 0, 0);
                                    if (right)
                                        this->set_terrain(this->game_world,
                                                          (short)(x + 1), (short)y, terrain, 0, 0);
                                    if (lower_right)
                                        this->set_terrain(this->game_world,
                                                          (short)(x + 1), (short)(y + 1), terrain, 0, 0);
                                    if (down)
                                        this->set_terrain(this->game_world,
                                                          (short)x, (short)(y + 1), terrain, 0, 0);
                                    if (lower_left)
                                        this->set_terrain(this->game_world,
                                                          (short)(x - 1), (short)(y + 1), terrain, 0, 0);
                                    if (left)
                                        this->set_terrain(this->game_world,
                                                          (short)(x - 1), (short)y, terrain, 0, 0);
                                }
                                change_flag = 1;
                            }
                        }
                        ++x;
                        ++tile;
                    } while (x <= x2);
                }
            }
        }
    } while (change_flag);

    this->clean_borders(x1, y1, x2, y2, terrain);
    this->set_terrain(0, 0, x1, y1, x2, y2, 0, 0, 0);
}
