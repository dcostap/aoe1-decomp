
#include <string.h>
#include "../include/map.h"
#include "../include/rmm_land.h"

extern double dbl_571ED0;
extern "C" int __cdecl debug_rand(char* file, int line);

RGE_RMM_Land_Generator::RGE_RMM_Land_Generator(
    RGE_Map* map, RGE_Random_Map_Module* module, RGE_Land_Info* info)
    : RGE_Random_Map_Module(map, module, 1) {
    this->schedule = 1.0f;
    this->info = *info;
}

extern "C" void* memset(void* dst, int value, unsigned int size);

unsigned char RGE_RMM_Land_Generator::generate() {
    clear_stack();
    memset(search_map, info.land_num, map_height * map_width);
    map->set_terrain(0, 0, 0, 0,
                     map_width - 1, map_height - 1,
                     info.base_terrain, 1, 0);
    base_land_generate();
    map->clean_terrain(0, 0, map_width, map_height, info.base_terrain);
    return 1;
}

unsigned char RGE_RMM_Land_Generator::check_terrain_and_zone(
    unsigned char target, unsigned char land_id, long x, long y)
{
    long count = 0;
    RGE_Land_Info_Line& land = this->info.land[land_id];
    long area = land.area;
    long x0 = x - area;
    long x1 = x + area;
    long y1 = y + area;
    long y0 = y - area;
    long octogon = area * dbl_571ED0;
    long cx0 = x - 2;
    long cy0 = y - 2;
    long cx1 = x + 2;
    long cy1 = y + 2;

    if (this->search_map_rows[y][x] != this->info.land_num) {
        return 0;
    }

    if (octogon < 2) {
        octogon = 2;
    }
    long octogon_y0 = y - octogon;
    long octogon_y1 = y + octogon;

    long row = y0;
    long column;
    if (row > y1) {
        return count;
    }

    do {
        if (row < 0) {
            if (row > cy0) {
                count += 5;
            }
        } else if (row >= this->map_height) {
            if (row < cy1) {
                count += 5;
            }
        } else {
            column = x0;
            if (column <= x1) {
                do {
                    if (column < 0) {
                        if (column > cx0) {
                            count++;
                        }
                    } else if (column >= this->map_width) {
                        if (column < cx1) {
                            count++;
                        }
                    } else {
                        if (this->search_map_rows[row][column] == land.zone) {
                            if (row >= cy0 && row <= cy1 &&
                                column >= cx0 && column <= cx1) {
                                count++;
                            }
                        } else if (this->search_map_rows[row][column] <
                                   this->info.land_num) {
                            return 0;
                        }
                    }
                    column++;
                } while (column <= x1);
            }
        }
        row++;
    } while (row <= y1);

    return count;
}

// boundary under the canonical header.
unsigned char RGE_RMM_Land_Generator::chance(long x, long y, long land_id)
{
    RGE_Land_Info_Line& land = this->info.land[land_id];
    unsigned char fade = land.wall_fade;
    if (fade > 0) {
        long wall_1 = land.wall_1_avoidance_line;
        long xpos = x;
        long wall_3 = land.wall_3_avoidance_line;
        long a = wall_1 - xpos;
        xpos -= wall_3;
        long x_chance = a;
        if (a <= xpos)
            x_chance = xpos;

        long right = this->map_width;
        a += wall_1;
        right -= wall_3;
        xpos += right;
        if (a <= xpos)
            a = xpos;

        long wall_2 = land.wall_2_avoidance_line;
        if (a > 0) {
            long wall_4 = land.wall_4_avoidance_line;
            long ypos = y;
            wall_2 += a;
            a -= wall_4;
            wall_2 -= ypos;
            a += ypos;
        } else {
            a = y;
            long wall_4 = land.wall_4_avoidance_line;
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
    long land_size[100];
    Map_Stack stack[99];

    long land_id;
    long row;
    long column;
    float pop_cost;
    long spread_cost;
    unsigned char done;
    long edge;
    long left;
    long max_column;
    long max_row;

    land_id = 0;
    max_column = this->map_width - 1;
    max_row = this->map_height - 1;

    // Phase A: expand each base tile and seed its edge stack.
    if (this->info.land_num > 0) {
        do {
            RGE_Land_Info_Line& land = this->info.land[land_id];
            this->init_stack(stack[land_id]);

            long right = land.x;
            long bottom = land.y;
            land_size[land_id + 1] = 0;
            long radius = land.base_size;
            left = right - radius;
            long top = bottom - radius;
            right += radius;
            bottom += radius;
            if (left < 0) left = 0;
            if (top < 0) top = 0;
            if (right >= this->map_width) right = this->map_width - 1;
            if (bottom >= this->map_height) bottom = this->map_height - 1;

            this->map->set_terrain(0, 0, left, top, right, bottom,
                                   land.terrain_type, 1, 0);

            unsigned char zone = land.zone;
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
                        this->push_stack(stack[land_id], left - 1, edge,
                                         land_id, 0.0f);
                        edge++;
                    } while (edge <= bottom);
                }
            }
            if (0 < top) {
                edge = left;
                if (edge <= right) {
                    do {
                        this->push_stack(stack[land_id], edge, top - 1,
                                         land_id, 0.0f);
                        edge++;
                    } while (edge <= right);
                }
            }
            if (right < this->map_width - 1 && top <= bottom) {
                edge = top;
                do {
                    this->push_stack(stack[land_id], right + 1, edge,
                                     land_id, 0.0f);
                    edge++;
                } while (edge <= bottom);
            }
            if (bottom < this->map_height - 1 && left <= right) {
                edge = left;
                do {
                    this->push_stack(stack[land_id], edge, bottom + 1,
                                     land_id, 0.0f);
                    edge++;
                } while (edge <= right);
            }

            land_id++;
        } while (land_id < this->info.land_num);
    }

    // Phase B: flood-fill each land stack.
    do {
        done = 1;
        land_id = 0;
        if (0 < this->info.land_num) {
            do {
                RGE_Land_Info_Line& land = this->info.land[land_id];
                long current_size = land_size[land_id + 1];
                if (current_size < land.land_size &&
                    this->pop_stack(stack[land_id], column, row, pop_cost) != 0) {
                    done = 0;
                    unsigned char chance_value = this->chance(column, row, land_id);
                    long random_value = debug_rand(
                        "C:\\msdev\\work\\age1_x1\\rmm_land.cpp", 299);
                    if (chance_value <= (random_value * 100) / 0x7fff) {
                        RGE_Tile& tile = this->map_row_offset[row][column];
                        unsigned char terrain_count =
                            this->check_terrain_and_zone(
                                land.terrain_type, land_id, column, row);
                        if (this->search_map_rows[row][column] ==
                                this->info.land_num && terrain_count > 0) {
                            tile.terrain_type = land.terrain_type;
                            this->search_map_rows[row][column] = land.zone;

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
                                this->push_stack(stack[land_id], column - 1,
                                                 row, 0.0f, spread_cost);
                            }
                            if (column < max_column &&
                                this->search_map_rows[row][column + 1] ==
                                    this->info.land_num) {
                                spread_cost =
                                    ((debug_rand(
                                         "C:\\msdev\\work\\age1_x1\\rmm_land.cpp",
                                         0x13b) * 100) /
                                         0x7fff -
                                     terrain_count * land.clumpiness_factor) +
                                    0xfa;
                                this->push_stack(stack[land_id], column + 1,
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
                                this->push_stack(stack[land_id], column,
                                                 row - 1, 0.0f, spread_cost);
                            }
                            if (row < max_row &&
                                this->search_map_rows[row + 1][column] ==
                                    this->info.land_num) {
                                spread_cost =
                                    ((debug_rand(
                                         "C:\\msdev\\work\\age1_x1\\rmm_land.cpp",
                                         0x141) * 100) /
                                         0x7fff -
                                     terrain_count * land.clumpiness_factor) +
                                    0xfa;
                                this->push_stack(stack[land_id], column,
                                                 row + 1, 0.0f, spread_cost);
                            }
                            land_size[land_id + 1] = current_size + 1;
                        }
                    } else {
                        this->search_map_rows[row][column] = 0xff;
                    }
                }
                land_id++;
            } while (land_id < this->info.land_num);
        }
    } while (done == 0);

    // Phase C: drain each land stack and set enclosed tiles.
    land_id = 0;
    if (0 < this->info.land_num) {
        do {
            RGE_Land_Info_Line& land = this->info.land[land_id];
            while (this->pop_stack(stack[land_id], column, row, pop_cost) != 0) {
                RGE_Tile& tile = this->map_row_offset[row][column];
                if (((column >= 1 &&
                      this->search_map_rows[row][column - 1] == land.zone &&
                      column < max_column &&
                      this->search_map_rows[row][column + 1] == land.zone)) ||
                    ((row >= 1 &&
                      this->search_map_rows[row - 1][column] == land.zone &&
                      row < max_row &&
                      this->search_map_rows[row + 1][column] == land.zone))) {
                    tile.terrain_type = land.terrain_type;
                }
            }
            land_id++;
        } while (land_id < this->info.land_num);
    }

    // Phase D: deinit each land stack.
    land_id = 0;
    if (0 < this->info.land_num) {
        do {
            this->deinit_stack(stack[land_id]);
            land_id++;
        } while (land_id < this->info.land_num);
    }

    return 1;
}
