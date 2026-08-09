// VA: 00510A50 do_cliff_brush (434B)
// tmap.cpp
//
// Attempt log:
// baseline: canonical reconstruction from the RGE_Map brush delegation,
// clipped /3 cliff coordinates, and the TRIBE_Map cliff-state fields.
// probe 2: reused the clipped-y local for the old-cliff fallback; this
// removed the decompiler-shaped temporary and reduced the drift to 2 bytes.
// probe 3: factored the delta bounds into shared control flow; reduced the
// remaining drift to 5 bytes and aligned all five calls and the frame-less CFG.
// probe 4: reversed the x-direction comparison operands; reduced drift to 2.
// probe 5: wrote the equal-x y comparison as old_cliff_y >= cliff_y; MATCH.

class RGE_Player;
class RGE_Game_World;
class RGE_Player_Info;

class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void data_load_random_map(int file);
    virtual void load_random_map(char* a, char* b, char* c, char* d);
    virtual unsigned char do_terrain_brush(long x, long y, long r,
                                           unsigned char type);
    virtual unsigned char do_terrain_brush_stroke(long a, long b, long c,
                                                  long d, long e,
                                                  unsigned char type);
    virtual unsigned char do_elevation_brush(long x, long y, long r,
                                             unsigned char type);
    virtual unsigned char do_elevation_brush_stroke(long a, long b, long c,
                                                    long d, long e,
                                                    unsigned char type);
    virtual unsigned char do_cliff_brush(long x, long y, unsigned char a,
                                         unsigned char b);
    virtual unsigned char do_cliff_brush_stroke(long a, long b, long c,
                                                long d, unsigned char e,
                                                unsigned char f);
    virtual void map_generate(RGE_Player* player, RGE_Game_World* world,
                              RGE_Player_Info* info, unsigned char* data);
    virtual void map_generate2(RGE_Game_World* world, long a, long b,
                               unsigned char c, long d);
    virtual void save(int file);
    virtual void delete_cliff(long x, long y);

    char gap_04[0x04];
    long map_width;
    long map_height;
    char gap_10[0x8DD4];
};

class TRIBE_Map : public RGE_Map {
public:
    int old_cliff_x;
    int old_cliff_y;
    int safe_cliff_x;
    int safe_cliff_y;
    int old_cliff_direction;

    virtual void delete_cliff(long x, long y);
    long add_cliff_edge(long x, long y, long direction, long existing,
                        long other_direction);
    long reverse_cliff_direction(long direction);
    unsigned char do_cliff_brush(long x, long y, unsigned char a,
                                 unsigned char b);
};

unsigned char TRIBE_Map::do_cliff_brush(long x, long y, unsigned char a,
                                        unsigned char b)
{
    int cliff_x = x / 3;
    int cliff_y = y / 3;

    if (RGE_Map::do_cliff_brush(x, y, a, b))
        return 1;

    int old_x = this->old_cliff_x;
    this->safe_cliff_x = cliff_x;
    this->safe_cliff_y = cliff_y;

    if (old_x == cliff_x && this->old_cliff_y == cliff_y)
        return 0;

    if (cliff_x * 3 + 2 >= this->map_width ||
        cliff_y * 3 + 2 >= this->map_height ||
        cliff_x < 0 || cliff_y < 0)
        return 0;

    if (old_x != -1 && this->old_cliff_y != -1) {
        int delta_x = x - old_x * 3;
        int delta_y = y - this->old_cliff_y * 3;

        if (delta_x >= 3 || delta_x <= -1) {
            cliff_y = this->old_cliff_y;
        } else if (delta_y < 3 && delta_y > -1) {
            return 0;
        } else {
            cliff_x = old_x;
        }
    }

    if (cliff_x == old_x && cliff_y == this->old_cliff_y)
        return 1;

    if (b != 0) {
        this->delete_cliff(cliff_x, cliff_y);
        return 1;
    }

    if (old_x == -1) {
        this->old_cliff_direction = -1;
        this->old_cliff_x = cliff_x;
        this->old_cliff_y = cliff_y;
        return 1;
    }

    long direction;
    if (cliff_x > old_x)
        direction = 0;
    else if (old_x > cliff_x)
        direction = 2;
    else {
        direction = 1;
        if (this->old_cliff_y >= cliff_y)
            direction = 3;
    }

    long edge = this->add_cliff_edge(old_x, this->old_cliff_y,
                                     direction, 0,
                                     this->old_cliff_direction);
    direction = this->reverse_cliff_direction(direction);
    this->old_cliff_direction = direction;
    this->old_cliff_x = cliff_x;
    this->old_cliff_y = cliff_y;
    this->add_cliff_edge(cliff_x, cliff_y, direction, edge, -1);
    return 1;
}
