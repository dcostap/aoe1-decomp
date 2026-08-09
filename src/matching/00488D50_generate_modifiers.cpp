// 00488D50 RGE_RMM_Terrain_Generator::generate_modifiers
// PDB: rmm_terr.cpp lines 179-213
// Attempt log:
// - baseline: canonical terrain search-map ownership and natural nested
//   hot-spot falloff loops, matching the sibling elevation generator's source
//   family.
// - anchoring the hot-spot cursor at the proven y field reduced the baseline
//   27-byte drift to 21 bytes while preserving the typed 16-byte record owner.
// - the exact source shape uses a direct hot-spot guard, declares the y-anchored
//   cursor before the scoped count, and keeps modifier function-scoped; this
//   reproduces the original initialization block and output register coloring.

#include <math.h>
#include <string.h>

struct RGE_Map;
struct RGE_Random_Map_Module_List;
struct Map_Stack;

struct RGE_Terrain_Hot_Spot {
    long x;
    long y;
    long radius;
    long fade;
};

struct RGE_Terrain_Info {
    long terrain[99 * 8];
    long terrain_num;
    RGE_Terrain_Hot_Spot hot_spots[99];
    long hot_spot_num;
};

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate() = 0;
    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    void* map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;
};

class RGE_RMM_Terrain_Generator : public RGE_Random_Map_Module {
public:
    RGE_Terrain_Info info;

    void generate_modifiers();
};

void RGE_RMM_Terrain_Generator::generate_modifiers()
{
    long modifier;

    memset(this->search_map, 0, this->map_width * this->map_height);

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
