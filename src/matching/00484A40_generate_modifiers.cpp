// 00484A40 RGE_RMM_Elevation_Generator::generate_modifiers
// PDB: rmm_elev.cpp lines 159-193
// Baseline reconstruction: clear the shared search map, then accumulate the
// positive falloff contribution of each elevation hot spot for every tile.
// Attempt log:
// - Natural nested loops matched size/frame/calls but VC5 loaded map_width
//   first for the commutative clear-size expression.
// - A height-first accumulator restored the original clear-size load order.
// - The binary-proven hot-spot cursor is anchored at the y field; declaring
//   that cursor before the scoped count places the count-home store after the
//   LEA, producing the exact VC5 block.

#include <math.h>
#include <string.h>

struct RGE_Map;
struct RGE_Random_Map_Module_List;
struct Map_Stack;
struct RGE_Tile;

struct RGE_Elevation_Hot_Spots {
    long x;
    long y;
    long radius;
    long fade;
};

struct RGE_Elevation_Info_Line {
    long elevation_size;
    long elevation;
    long clumps;
    long spacing;
    long base_elevation;
    long base_terrain_type;
};

struct RGE_Elevation_Info {
    RGE_Elevation_Info_Line elevation[99];
    long elevation_num;
    RGE_Elevation_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate() = 0;
    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;
};

class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
public:
    RGE_Elevation_Info info;

    void generate_modifiers();
};

void RGE_RMM_Elevation_Generator::generate_modifiers()
{
    long modifier;

    long map_size = this->map_height;
    map_size *= this->map_width;
    memset(this->search_map, 0, map_size);

    long y = 0;
    if (y < this->map_height) {
        do {
            long x = 0;
            if (x < this->map_width) {
                do {
                    modifier = 0;
                    if (this->info.hot_spot_num > 0) {
                        long* hot_spot = &this->info.hot_spots[0].y;
                        long hot_spot_num = this->info.hot_spot_num;
                        do {
                            long dx = x - hot_spot[-1];
                            long dy = y - hot_spot[0];

                            if (dx < 0)
                                dx = -dx;
                            if (dy < 0)
                                dy = -dy;

                            long distance = (long)sqrt((double)(dx * dx + dy * dy));
                            long contribution = hot_spot[1] - distance;
                            if (contribution > 0)
                                modifier += hot_spot[2] * contribution;

                            hot_spot += 4;
                            --hot_spot_num;
                        } while (hot_spot_num != 0);
                    }

                    if (modifier > 100)
                        this->search_map_rows[y][x] = 101;
                    else
                        this->search_map_rows[y][x] = (unsigned char)modifier;
                    ++x;
                } while (x < this->map_width);
            }
            ++y;
        } while (y < this->map_height);
    }
}
