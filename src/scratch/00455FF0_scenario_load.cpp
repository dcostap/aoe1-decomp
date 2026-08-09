// VA: 00455FF0 RGE_Map::scenario_load (map.cpp:550-581)
// Attempt log:
// - Baseline reconstruction follows the exact scenario_save donor: named map
//   dimensions, a 24-byte RGE_Tile row table, natural nested short loops, and
//   the two post-load map rebuild calls.
// - Swapping the inner state to an int index plus long incrementing y and
//   repeating typed row-tile expressions recovered exact size/frame/call set;
//   the remaining drift is five bytes at the overlay XOR register schedule.
// - Reversed XOR spellings, old-byte/low-byte temporaries, and an int byte-read
//   local were tested; the former forms were codegen duplicates and the latter
//   changed the frame.  The clean typed form is retained below.
// - Left in scratch: all eight calls, bounds, loops, stack homes, and post-load
//   effects align; only the one-byte overlay load/XOR ordering remains.
// - Current worker: sequential low-byte accumulators and reusing overlay_info
//   as the destination were separately tested; both retained the same exact-
//   size five-byte hunk. Restored the clean typed XOR source.

class RGE_Player;
class RGE_Game_World;

struct RGE_Tile {
    char gap_00[5];
    unsigned char terrain_info;
    char gap_06[18];
};

class RGE_Map {
public:
    char gap_00[8];
    long map_width;
    long map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;

    void new_map(long width, long height);
    void set_elev(short col0, short row0, short col1, short row1,
                  unsigned char elevation, short param6,
                  unsigned char param7);
    void set_terrain(RGE_Player* player, RGE_Game_World* world,
                     short col0, short row0, short col1, short row1,
                     unsigned char terrain, unsigned char apply_terrain,
                     int object_behavior);
    void scenario_load(int file, unsigned char* param2);
};

void rge_read(int file, void* data, int size);

void RGE_Map::scenario_load(int file, unsigned char* param2)
{
    long map_width;
    long map_height;

    rge_read(file, &map_width, 4);
    rge_read(file, &map_height, 4);
    this->new_map(map_width, map_height);

    long height_count = this->map_height;
    long h = 0;
    if (height_count > 0) {
        do {
            int i = 0;
            long y = 0;
            if (height_count > 0) {
                short x = (short)h;
                do {
                    unsigned char overlay_info;
                    unsigned char height_info;
                    unsigned char unused_info;

                    rge_read(file, &overlay_info, 1);
                    rge_read(file, &height_info, 1);
                    rge_read(file, &unused_info, 1);

                    this->map_row_offset[x][i].terrain_info =
                        (unsigned char)((overlay_info ^
                                         this->map_row_offset[x][i].terrain_info) &
                                        0x1F) ^
                        this->map_row_offset[x][i].terrain_info;
                    this->map_row_offset[x][i].terrain_info =
                        (unsigned char)(height_info << 5) |
                        (this->map_row_offset[x][i].terrain_info & 0x1F);

                    y = y + 1;
                    i = (int)(short)y;
                } while (i < this->map_height);
            }
            height_count = this->map_height;
            ++h;
        } while ((short)h < height_count);
    }

    this->set_elev(0, 0, (short)this->map_width - 1,
                   (short)this->map_height - 1, 0, 0, 0);
    this->set_terrain(0, 0, 0, 0, (short)this->map_width - 1,
                      (short)this->map_height - 1, 0, 0, 0);
}
