// 00481A00 RGE_RMM_Cliffs_Generator::setup_cliff_maps()
// Source: rmm_clif.cpp lines 60-173
// Attempt log:
// - Reconstructed the canonical RGE_Random_Map_Module resources from rmm_base:
//   RGE_Tile** map_row_offset (+10), search_map (+20), search_map_rows (+24),
//   stack_offsets (+2c), and the 0x18-byte Map_Stack rows.
// - Reconstructed RGE_Cliffs_Info at +30 and valid_cliff_sites at +4f0 from the
//   generated class/type evidence and the same-TU constructor/callers.
// - The unconditional rep stosd/stosb fill comes from the natural memset
//   surface, not a guarded byte loop.
// - A +5 terrain-byte cursor with 0x18 tile stride, repeated first-cell row
//   indexing, and <=0 edge guards reproduce the original tile/isolation CFG.
// - Exact under default flags; no custom response file or compiler-only hack.

#include <string.h>

struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_code;
    char gap_06[6];
    char objects[12];
};

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate(void);

    void* parent;
    void* list;
    void* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;

    void clear_stack(void);
    void init_stack(Map_Stack* stack);
    void push_stack(Map_Stack* stack, long x, long y, float cost, float total_cost);
    void randomize_stack(Map_Stack* stack);
    void remove_stack_node(Map_Stack* node);
};

struct RGE_Cliffs_Hot_Spots {
    long x;
    long y;
    long radius;
};

struct RGE_Cliffs_Info {
    long number_of_cliffs;
    long number_of_cliffs_variance;
    long average_cliff_size;
    long cliff_size_variance;
    long cliff_terrain_spacing;
    long cliff_to_cliff_spacing;
    RGE_Cliffs_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

class RGE_RMM_Cliffs_Generator : public RGE_Random_Map_Module {
public:
    virtual unsigned char generate(void);

    RGE_Cliffs_Info info;
    Map_Stack valid_cliff_sites;

    void invalidate_cliff_area(long x, long y, long spacing);
    void setup_cliff_maps(void);
};

void RGE_RMM_Cliffs_Generator::setup_cliff_maps(void) {
    long cliff_width = this->map_width / 3;
    long terrain_height = this->map_height / 3;
    long terrain_width = cliff_width;
    long cliff_width_m1 = cliff_width - 1;
    long terrain_height_m1 = terrain_height - 1;

    this->clear_stack();
    this->init_stack(&this->valid_cliff_sites);

    memset(this->search_map, 1, this->map_height * this->map_width);

    long row = 0;
    if (terrain_height > 0) {
        long row_offset = 0;
        do {
            long column = 0;
            if (terrain_width > 0) {
                long column_offset = 0;
                do {
                    long area = -1;
                    unsigned char valid = 1;
                    unsigned char water_area = 0;
                    RGE_Tile** tile_row = (RGE_Tile**)((char*)this->map_row_offset + row_offset);
                    long tile_rows = 3;
                    do {
                        long tile_columns = 3;
                        unsigned char* tile = (unsigned char*)*tile_row + 5 + column_offset;
                        do {
                            unsigned char value = *tile;
                            unsigned char terrain = value & 0x1f;
                            if (terrain == 0 || terrain == 6) {
                                unsigned char elevation = value >> 5;
                                if (area < 0) {
                                    area = elevation;
                                } else if (area != elevation) {
                                    valid = 0;
                                }
                            } else {
                                valid = 0;
                                if (terrain == 1 || terrain == 4 || terrain == 0x16) {
                                    water_area = 1;
                                }
                            }
                            tile += 24;
                            tile_columns--;
                        } while (tile_columns != 0);
                        tile_row++;
                        tile_rows--;
                    } while (tile_rows != 0);

                    if (valid != 0) {
                        unsigned char* cell = this->search_map_rows[row] + column;
                        if (*cell != 0) {
                            *cell = (unsigned char)(area + 1);
                            this->push_stack(&this->valid_cliff_sites, column, row, 0.0f, 0.0f);
                        }
                    } else {
                        if (water_area != 0) {
                            this->invalidate_cliff_area(column, row, this->info.cliff_terrain_spacing);
                        }
                        this->search_map_rows[row][column] = 0;
                    }
                    column++;
                    column_offset += 72;
                } while (column < terrain_width);
            }
            row++;
            row_offset += 12;
        } while (row < terrain_height);
    }

    long hot_spot_index = 0;
    if (this->info.hot_spot_num > 0) {
        // VC5 preserves the original cursor into the first hot-spot's y field.
        // The cursor walks complete x/y/radius triples after using x at [-1].
        long* hot_spot = &this->info.hot_spots[0].y;
        do {
            this->invalidate_cliff_area(hot_spot[-1] / 3, hot_spot[0] / 3,
                                        hot_spot[1] / 3 + 2);
            hot_spot_index++;
            hot_spot += 3;
        } while (hot_spot_index < this->info.hot_spot_num);
    }

    long y = 0;
    if (terrain_height > 0) {
        do {
            long x = 0;
            if (terrain_width > 0) {
                do {
                    unsigned char* cell = this->search_map_rows[y] + x;
                    if (this->search_map_rows[y][x] != 0 &&
                        (y <= 0 || this->search_map_rows[y - 1][x] == 0) &&
                        (x <= 0 || cell[-1] == 0) &&
                        (y >= terrain_height_m1 || this->search_map_rows[y + 1][x] == 0) &&
                        (x >= cliff_width_m1 || cell[1] == 0)) {
                        *cell = 0;
                        this->remove_stack_node(this->stack_offsets[y] + x);
                    }
                    x++;
                } while (x < terrain_width);
            }
            y++;
        } while (y < terrain_height);
    }

    this->randomize_stack(&this->valid_cliff_sites);
}
