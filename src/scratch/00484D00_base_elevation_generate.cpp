// 00484D00 RGE_RMM_Elevation_Generator::base_elevation_generate
// Source: rmm_elev.cpp lines 290-403
//
// Natural reconstruction of the elevation clump seeding/expansion routine.
// The executable proves the map-row, search-map, stack, helper ABI, and four
// weighted neighbor-random branches below; keep those ownership facts explicit.
// Initial scratch was a raw direct reconstruction with 21 calls and a 992-byte
// body. This source restores the period typed surfaces and all five debug_rand
// sites before any codegen tuning.
// Matching claim: replacing the first seed do-loop with a natural while loop
// removed a duplicated pop_stack site and aligned all 23 direct calls. Reusing
// the pop cost out-home removed one redundant local and reached the original
// 0x988 frame; restoring the explicit cost local is retained as the more
// period-plausible final source because it preserves the real pop ABI. Named
// clumps/base-elevation locals, stack declaration order, and nested neighbor
// guards were codegen duplicates. Final gap: +36 bytes / 0x98C frame, with
// calls and target order aligned; no raw/asm scaffolding retained.

#include <math.h>

struct Map_Stack {
    long x;
    long y;
    long cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

struct RGE_Map;
struct RGE_Random_Map_Module_List;

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
    unsigned char elevation : 3;
    unsigned char border_type : 4;
    unsigned char border_shape : 4;
    char objects[12];
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
    char hot_spots[99][0x10];
    long hot_spot_num;
};

extern int __cdecl debug_rand(char* file, int line);
extern char s_C__msdev_work_age1_x1_rmm_elev_c[];

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

    void init_stack(Map_Stack* stack);
    void deinit_stack(Map_Stack* stack);
    void add_stack_node(Map_Stack* target, Map_Stack* node);
    Map_Stack* pop_stack(Map_Stack* head, long* x, long* y, float* cost);
    void push_stack(Map_Stack* list, long x, long y, float cost, float tot_cost);
};

// Main-agent audit confirmed canonical elevation/map-stack ownership and kept
// the natural typed clump-expansion source.
class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
public:
    virtual unsigned char generate();
    RGE_Elevation_Info info;

    unsigned char check_start_elevation(long x, long y, unsigned char terrain,
        unsigned char elevation, unsigned char range);
    void remove_area_from_lists(long x, long y, long radius);
    unsigned char check_elevation(unsigned char elevation, long x, long y,
        long radius, unsigned char terrain, unsigned char min_elevation);
    float fig_chance(long p0, long p1, long p2);
    void link_stack_randomly(Map_Stack* stack);
    unsigned char base_elevation_generate(RGE_Elevation_Info_Line line);
};

unsigned char RGE_RMM_Elevation_Generator::base_elevation_generate(
    RGE_Elevation_Info_Line line)
{
    long x = 0;
    long y = 0;
    long max_x = this->map_width - 1;
    long max_y = this->map_height - 1;
    long i;
    long chance = 0;
    long clump_size;
    float cost = 0.0f;
    float local_chance = 0.0f;
    long base_elevation = line.base_elevation;
    unsigned char done;
    Map_Stack stack[99];
    Map_Stack local_stack;

    if (line.clumps > 0) {
        for (i = 0; i < line.clumps; ++i) {
            this->init_stack(&stack[i]);
        }
    }

    local_stack.x = max_x;
    local_stack.prev = 0;
    stack[0].x = 0;
    this->link_stack_randomly(&local_stack);

    clump_size = (long)sqrt((double)line.elevation_size / (double)line.clumps);
    clump_size /= 2;
    if (clump_size < 2) {
        clump_size = 2;
    }

    i = 0;
    while (i < line.clumps) {
        Map_Stack* node = this->pop_stack(&local_stack, &x, &y, &cost);
            if (node == 0) {
                break;
            }

            if (this->search_map_rows[x][y] == 0
                && this->check_start_elevation(y, x,
                    (unsigned char)line.base_terrain_type,
                    (unsigned char)line.base_elevation,
                    (unsigned char)line.spacing) != 0) {
                this->remove_area_from_lists(y, x, clump_size);

                unsigned char* tile = (unsigned char*)this->map_row_offset[x]
                    + y * 0x18;
                tile[5] = (unsigned char)(line.elevation << 5)
                    | (tile[5] & 0x1F);

                if (y > 0) {
                    this->push_stack(&stack[i], y - 1, x, 0.0f, 0.0f);
                }
                if (x > 0) {
                    this->push_stack(&stack[i], y, x - 1, 0.0f, 0.0f);
                }
                if (y < max_y) {
                    this->push_stack(&stack[i], y + 1, x, 0.0f, 0.0f);
                }
                if (x < max_x) {
                    this->push_stack(&stack[i], y, x + 1, 0.0f, 0.0f);
                }

                ++chance;
                ++i;
            }
    }

    do {
        done = 1;
        if (line.clumps > 0) {
            i = 0;
            do {
                if (chance < line.elevation_size) {
                    Map_Stack* node = this->pop_stack(&stack[i], &x, &y, &cost);
                    if (node != 0) {
                        done = 0;
                        unsigned char* mark = &this->search_map_rows[x][y];
                        long random_value = (debug_rand(
                            s_C__msdev_work_age1_x1_rmm_elev_c, 0x171) * 100)
                            / 0x7FFF;
                        if (random_value < *mark) {
                            *mark = 0x65;
                        } else {
                            unsigned char* tile =
                                (unsigned char*)this->map_row_offset[x]
                                + y * 0x18;
                            unsigned char ok = this->check_elevation(
                                (unsigned char)line.elevation, y, x,
                                line.spacing,
                                (unsigned char)line.base_terrain_type,
                                (unsigned char)line.base_elevation);

                            if (((tile[5] >> 5) == base_elevation)
                                && ok != 0) {
                                local_chance = this->fig_chance(ok, y, x);
                                tile[5] = (unsigned char)(line.elevation << 5)
                                    | (tile[5] & 0x1F);

                                if (y > 0) {
                                    if ((tile[-0x13] >> 5) == base_elevation) {
                                        long random_value = (debug_rand(
                                            s_C__msdev_work_age1_x1_rmm_elev_c,
                                            0x17D) * 100) / 0x7FFF;
                                        this->push_stack(&stack[i], y - 1, x,
                                            0.0f,
                                            (float)random_value + local_chance);
                                    }
                                }
                                if (y < max_y) {
                                    if ((tile[0x1D] >> 5) == base_elevation) {
                                        long random_value = (debug_rand(
                                            s_C__msdev_work_age1_x1_rmm_elev_c,
                                            0x17F) * 100) / 0x7FFF;
                                        this->push_stack(&stack[i], y + 1, x,
                                            0.0f,
                                            (float)random_value + local_chance);
                                    }
                                }
                                if (x > 0) {
                                    if ((tile[-this->map_width * 0x18 + 5] >> 5)
                                        == base_elevation) {
                                        long random_value = (debug_rand(
                                            s_C__msdev_work_age1_x1_rmm_elev_c,
                                            0x181) * 100) / 0x7FFF;
                                        this->push_stack(&stack[i], y, x - 1,
                                            0.0f,
                                            (float)random_value + local_chance);
                                    }
                                }
                                if (x < max_x) {
                                    if ((tile[this->map_width * 0x18 + 5] >> 5)
                                        == base_elevation) {
                                        long random_value = (debug_rand(
                                            s_C__msdev_work_age1_x1_rmm_elev_c,
                                            0x183) * 100) / 0x7FFF;
                                        this->push_stack(&stack[i], y, x + 1,
                                            0.0f,
                                            (float)random_value + local_chance);
                                    }
                                }

                                ++chance;
                            }
                        }
                    }
                }
                ++i;
            } while (i < line.clumps);
        }
    } while (done == 0);

    if (line.clumps > 0) {
        for (i = 0; i < line.clumps; ++i) {
            this->deinit_stack(&stack[i]);
        }
    }
    return 1;
}
