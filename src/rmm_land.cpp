
#include <string.h>
#include "../include/map.h"
#include "../include/rmm_land.h"
#include "../include/game_globals.h"

extern int __cdecl debug_rand(char* file, int line);

RGE_RMM_Land_Generator::RGE_RMM_Land_Generator(
    RGE_Map* map, RGE_Random_Map_Module* module, RGE_Land_Info* info)
    : RGE_Random_Map_Module(map, module, 1) {
    this->schedule = 1.0f;
    this->info = *info;
}

extern "C" void* memset(void* dst, int value, unsigned int size);

unsigned char RGE_RMM_Land_Generator::generate() {
    clear_stack();
    long width = map_width;
    memset(search_map, info.land_num, width * map_height);
    map->set_terrain(0, 0, 0, 0,
                     map_width - 1, map_height - 1,
                     info.base_terrain, 1, 0);
    base_land_generate();
    map->clean_terrain(0, 0, map_width, map_height, info.base_terrain);
    return 1;
}

unsigned char RGE_RMM_Land_Generator::check_terrain_and_zone(
    uchar unused, uchar land_id, long x, long y)
{
    long count = 0;
    long area = this->info.land[land_id].area;
    long x0 = x - area;
    long y0 = y - area;
    long x1 = x + area;
    long y1 = y + area;
    volatile long octogon = (long)(area * DAT_00571ed0);
    long cx0 = x - 2;
    long cy0 = y - 2;
    long cx1 = x + 2;
    long cy1 = y + 2;
    uchar zone = this->info.land[land_id].zone;

    if (this->search_map_rows[y][x] != this->info.land_num) {
        return 0;
    }

    if (octogon < 2) {
        octogon = 2;
    }

    long row = y0;
    if (row <= y1) {
        do {
            if (row < 0) {
                if (row > cy0) {
                    count += 5;
                }
            } else if (row < this->map_height) {
                long column = x0;
                if (column <= x1) {
                    do {
                        if (column < 0) {
                            if (column > cx0) {
                                ++count;
                            }
                        } else if (column < this->map_width) {
                            uchar state = this->search_map_rows[row][column];
                            if (state == zone) {
                                if (row >= cy0 && row <= cy1 &&
                                    column >= cx0 && column <= cx1) {
                                    ++count;
                                }
                            } else if (state < this->info.land_num) {
                                return 0;
                            }
                        } else if (column < cx1) {
                            ++count;
                        }
                        ++column;
                    } while (column <= x1);
                }
            } else if (row < cy1) {
                count += 5;
            }
            ++row;
        } while (row <= y1);
    }

    return (unsigned char)count;
}

// boundary under the canonical header.
unsigned char RGE_RMM_Land_Generator::chance(long x, long y, long land_id)
{
    unsigned char fade;
    long wall_1;
    long wall_3;

    fade = this->info.land[land_id].wall_fade;
    if (fade > 0) {
        wall_1 = this->info.land[land_id].wall_1_avoidance_line;
        wall_3 = this->info.land[land_id].wall_3_avoidance_line;
        long a = wall_1 - x;
        long xpos = x - wall_3;
        long x_chance = a;
        if (a <= xpos)
            x_chance = xpos;

        long right = this->map_width;
        a += wall_1;
        right -= wall_3;
        xpos += right;
        if (a <= xpos)
            a = xpos;

        long wall_2 = this->info.land[land_id].wall_2_avoidance_line;
        if (a > 0) {
            long wall_4 = this->info.land[land_id].wall_4_avoidance_line;
            wall_2 += a;
            a -= wall_4;
            wall_2 -= y;
            a += y;
        } else {
            a = y;
            long wall_4 = this->info.land[land_id].wall_4_avoidance_line;
            wall_2 -= a;
            a -= wall_4;
        }

        if (wall_2 > a)
            a = wall_2;
        if (x_chance < 0)
            x_chance = 0;
        if (a < 0)
            a = 0;

        a += x_chance;
        a *= fade;
        if (a >= 100)
            return 101;
        return a;
    }
    return 0;
}

//
// map rows use [row][column]. The stack outputs are column then
// row, and the helper calls use that same coordinate order.
unsigned char RGE_RMM_Land_Generator::base_land_generate() {
    float pop_cost;
    long row;
    long column;
    Map_Stack* stack_cursor;
    long* cursor;
    long* size_cursor;
    long land_id;
    RGE_Tile* tile;
    long spread_cost;
    unsigned char done;
    unsigned char zone;
    long index2;
    long edge;
    unsigned char terrain;
    long max_y;
    long max_x;
    long land_size[99];
    Map_Stack stack[99];

    land_id = 0;
    max_x = this->map_width - 1;
    max_y = this->map_height - 1;

    // Phase A: expand each base tile and seed its edge stack.
    if (this->info.land_num > 0) {
        stack_cursor = &stack[0];
        long left;
        size_cursor = &land_size[1];
        cursor = &this->info.land[0].base_size;
        do {
            this->init_stack(*stack_cursor);

            long right = cursor[-2];
            long bottom = cursor[-1];
            *size_cursor = 0;
            long radius = *cursor;
            left = right - radius;
            long top = bottom - radius;
            right += radius;
            bottom += radius;
            if (left < 0) left = 0;
            if (top < 0) top = 0;
            if (right >= this->map_width) right = this->map_width - 1;
            if (bottom >= this->map_height) bottom = this->map_height - 1;

            this->map->set_terrain(0, 0, left, top, right, bottom,
                                   (unsigned char)cursor[-3], 1, 0);

            zone = *((unsigned char*)(cursor + 6));
            land_size[zone + 1] = (right - left + 1) * (bottom - top + 1);

            for (long fill_row = top; fill_row <= bottom; fill_row++) {
                for (long fill_column = left; fill_column <= right;
                     fill_column++) {
                    this->search_map_rows[fill_row][fill_column] = zone;
                }
            }

            if (0 < left) {
                edge = top;
                if (edge <= bottom) {
                    do {
                        this->push_stack(*stack_cursor, left - 1, edge,
                                         land_id, 0.0f);
                        edge++;
                    } while (edge <= bottom);
                }
            }
            if (0 < top) {
                edge = left;
                if (edge <= right) {
                    do {
                        this->push_stack(*stack_cursor, edge, top - 1,
                                         land_id, 0.0f);
                        edge++;
                    } while (edge <= right);
                }
            }
            if (right < this->map_width - 1 && top <= bottom) {
                edge = top;
                do {
                    this->push_stack(*stack_cursor, right + 1, edge,
                                     land_id, 0.0f);
                    edge++;
                } while (edge <= bottom);
            }
            if (bottom < this->map_height - 1 && left <= right) {
                edge = left;
                do {
                    this->push_stack(*stack_cursor, edge, bottom + 1,
                                     land_id, 0.0f);
                    edge++;
                } while (edge <= right);
            }

            land_id++;
            stack_cursor++;
            size_cursor++;
            cursor += 13;
        } while (land_id < this->info.land_num);
    }

    // Phase B: flood-fill each land stack.
    do {
        done = 1;
        land_id = 0;
        if (0 < this->info.land_num) {
            cursor = &land_size[1];
            stack_cursor = &stack[0];
            do {
                RGE_Land_Info_Line& land = this->info.land[land_id];
                index2 = *cursor;
                if (index2 < land.land_size &&
                    this->pop_stack(*stack_cursor, column, row, pop_cost) != 0) {
                    done = 0;
                    long chance_value = this->chance(column, row, land_id);
                    long random_value = debug_rand(
                        "C:\\msdev\\work\\age1_x1\\rmm_land.cpp", 299);
                    if (chance_value <= (random_value * 100) / 0x7fff) {
                        tile = &this->map_row_offset[row][column];
                        terrain = land.terrain_type;
                        unsigned char terrain_count =
                            this->check_terrain_and_zone(
                                terrain, land_id, column, row);
                        if (this->search_map_rows[row][column] ==
                                this->info.land_num && terrain_count > 0) {
                            tile->terrain_type = terrain;
                            this->search_map_rows[row][column] =
                                land.zone;

                            if (0 < column &&
                                this->search_map_rows[row][column - 1] ==
                                    this->info.land_num) {
                                spread_cost =
                                    ((debug_rand(
                                         "C:\\msdev\\work\\age1_x1\\rmm_land.cpp",
                                         0x138) * 100) /
                                         0x7fff -
                                     terrain_count * land.clumpiness_factor) +
                                    0xfa;
                                this->push_stack(*stack_cursor, column - 1,
                                                 row, 0.0f, spread_cost);
                            }
                            if (column < max_x &&
                                this->search_map_rows[row][column + 1] ==
                                    this->info.land_num) {
                                spread_cost =
                                    ((debug_rand(
                                         "C:\\msdev\\work\\age1_x1\\rmm_land.cpp",
                                         0x13b) * 100) /
                                         0x7fff -
                                     terrain_count * land.clumpiness_factor) +
                                    0xfa;
                                this->push_stack(*stack_cursor, column + 1,
                                                 row, 0.0f, spread_cost);
                            }
                            if (0 < row &&
                                this->search_map_rows[row - 1][column] ==
                                    this->info.land_num) {
                                spread_cost =
                                    ((debug_rand(
                                         "C:\\msdev\\work\\age1_x1\\rmm_land.cpp",
                                         0x13e) * 100) /
                                         0x7fff -
                                     terrain_count * land.clumpiness_factor) +
                                    0xfa;
                                this->push_stack(*stack_cursor, column,
                                                 row - 1, 0.0f, spread_cost);
                            }
                            if (row < max_y &&
                                this->search_map_rows[row + 1][column] ==
                                    this->info.land_num) {
                                spread_cost =
                                    ((debug_rand(
                                         "C:\\msdev\\work\\age1_x1\\rmm_land.cpp",
                                         0x141) * 100) /
                                         0x7fff -
                                     terrain_count * land.clumpiness_factor) +
                                    0xfa;
                                this->push_stack(*stack_cursor, column,
                                                 row + 1, 0.0f, spread_cost);
                            }
                            *cursor = index2 + 1;
                        }
                    } else {
                        this->search_map_rows[row][column] = 0xff;
                    }
                }
                land_id++;
                cursor++;
                stack_cursor++;
            } while (land_id < this->info.land_num);
        }
    } while (done == 0);

    // Phase C: drain each land stack and set enclosed tiles.
    land_id = 0;
    if (0 < this->info.land_num) {
        stack_cursor = &stack[0];
        do {
            RGE_Land_Info_Line& land = this->info.land[land_id];
            zone = land.zone;
            terrain = land.terrain_type;
            while (this->pop_stack(*stack_cursor, column, row, pop_cost) != 0) {
                tile = &this->map_row_offset[row][column];
                if (((column >= 1 &&
                      this->search_map_rows[row][column - 1] == zone &&
                      column < max_x &&
                      this->search_map_rows[row][column + 1] == zone)) ||
                    ((row >= 1 &&
                      this->search_map_rows[row - 1][column] == zone &&
                      row < max_y &&
                      this->search_map_rows[row + 1][column] == zone))) {
                    tile->terrain_type = terrain;
                }
            }
            land_id++;
            stack_cursor++;
        } while (land_id < this->info.land_num);
    }

    // Phase D: deinit each land stack.
    land_id = 0;
    if (0 < this->info.land_num) {
        stack_cursor = &stack[0];
        do {
            this->deinit_stack(*stack_cursor);
            land_id++;
            stack_cursor++;
        } while (land_id < this->info.land_num);
    }

    return 1;
}
