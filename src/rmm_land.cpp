
#include <string.h>
#include "../include/map.h"
#include "../include/rmm_land.h"
#include "../include/game_globals.h"

extern int __cdecl debug_rand(char* file, int line);

RGE_RMM_Land_Generator::RGE_RMM_Land_Generator(
    RGE_Map* in_map, RGE_Random_Map_Module* parent_module,
    RGE_Land_Info* in_info)
    : RGE_Random_Map_Module(in_map, parent_module, 1) {
    this->schedule = 1.0f;
    this->info = *in_info;
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
    uchar target, uchar land_num, long x, long y) {
    long count = 0;
    long area = this->info.land[land_num].area;
    long x0 = x - area;
    long y0 = y - area;
    long x1 = x + area;
    long y1 = y + area;
    // The converted radius remains separate from the fixed +/-2 scan bounds.
    volatile long octogon = (long)(area * DAT_00571ed0);
    long cx0 = x - 2;
    long cy0 = y - 2;
    long cx1 = x + 2;
    long cy1 = y + 2;
    uchar zone = this->info.land[land_num].zone;

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

unsigned char RGE_RMM_Land_Generator::chance(long x, long y, long land_type) {
    unsigned char fade;
    long wall_1;
    long wall_3;

    fade = this->info.land[land_type].wall_fade;
    if (fade > 0) {
        wall_1 = this->info.land[land_type].wall_1_avoidance_line;
        wall_3 = this->info.land[land_type].wall_3_avoidance_line;
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

        long wall_2 = this->info.land[land_type].wall_2_avoidance_line;
        if (a > 0) {
            long wall_4 = this->info.land[land_type].wall_4_avoidance_line;
            wall_2 += a;
            a -= wall_4;
            wall_2 -= y;
            a += y;
        } else {
            a = y;
            long wall_4 = this->info.land[land_type].wall_4_avoidance_line;
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

uchar RGE_RMM_Land_Generator::base_land_generate() {
    long land_size[99];
    Map_Stack stack[99];
    long x;
    long y;
    long index3;
    long max_x = this->map_width - 1;
    long max_y = this->map_height - 1;
    float stack_cost;
    uchar done;

    index3 = 0;
    if (this->info.land_num > 0) {
        RGE_Land_Info_Line* line = this->info.land;
        Map_Stack* stack_ptr = stack;
        do {
            this->init_stack(*stack_ptr);
            land_size[index3] = 0;

            long x0 = line->x - line->base_size;
            long y0 = line->y - line->base_size;
            long x1 = line->x + line->base_size;
            long y1 = line->y + line->base_size;

            if (x0 < 0) {
                x0 = 0;
            }
            if (y0 < 0) {
                y0 = 0;
            }
            if (x1 >= this->map_width) {
                x1 = this->map_width - 1;
            }
            if (y1 >= this->map_height) {
                y1 = this->map_height - 1;
            }

            this->map->set_terrain(
                0, 0, (short)x0, (short)y0, (short)x1, (short)y1,
                (uchar)line->terrain_type, 1, 0);

            uchar zone = line->zone;
            long area = (x1 - x0 + 1) * (y1 - y0 + 1);
            land_size[zone] = area;
            if (y0 <= y1) {
                for (long row = y0; row <= y1; ++row) {
                    if (x0 <= x1) {
                        for (long column = x0; column <= x1; ++column) {
                            this->search_map_rows[row][column] = zone;
                        }
                    }
                }
            }

            if (x0 > 0 && y0 <= y1) {
                for (long row = y0; row <= y1; ++row) {
                    this->push_stack(*stack_ptr, x0 - 1, row,
                        (float)index3, 0.0f);
                }
            }
            if (y0 > 0 && x0 <= x1) {
                for (long column = x0; column <= x1; ++column) {
                    this->push_stack(*stack_ptr, column, y0 - 1,
                        (float)index3, 0.0f);
                }
            }
            if (x1 < max_x && y0 <= y1) {
                for (long row = y0; row <= y1; ++row) {
                    this->push_stack(*stack_ptr, x1 + 1, row,
                        (float)index3, 0.0f);
                }
            }
            if (y1 < max_y && x0 <= x1) {
                for (long column = x0; column <= x1; ++column) {
                    this->push_stack(*stack_ptr, column, y1 + 1,
                        (float)index3, 0.0f);
                }
            }

            ++index3;
            ++line;
            ++stack_ptr;
        } while (index3 < this->info.land_num);
    }

    do {
        done = 1;
        index3 = 0;
        if (this->info.land_num > 0) {
            long* size_ptr = land_size;
            RGE_Land_Info_Line* line = this->info.land;
            Map_Stack* stack_ptr = stack;
            do {
                long index2 = *size_ptr;
                if (index2 < line->land_size) {
                    if (this->pop_stack(*stack_ptr, x, y, stack_cost) != 0) {
                        done = 0;

                        uchar placement_chance = this->chance(x, y, index3);
                        long random_value = debug_rand(
                            (char*)"C:\\msdev\\work\\age1_x1\\rmm_land.cpp",
                            0x12B);
                        if (placement_chance >
                            (random_value * 100) / 0x7FFF) {
                            this->search_map_rows[y][x] = 0xFF;
                        } else {
                            RGE_Tile* tile = &this->map_row_offset[y][x];
                            uchar terrain = (uchar)line->terrain_type;
                            uchar count = this->check_terrain_and_zone(
                                terrain, (uchar)index3, x, y);

                            if (this->search_map_rows[y][x] ==
                                    this->info.land_num && count > 0) {
                                tile->terrain_type = terrain;
                                this->search_map_rows[y][x] = line->zone;

                                if (x > 0 &&
                                    this->search_map_rows[y][x - 1] ==
                                        this->info.land_num) {
                                    long random_value = debug_rand(
                                        (char*)"C:\\msdev\\work\\age1_x1\\rmm_land.cpp",
                                        0x138);
                                    long cost =
                                        (random_value * 100) / 0x7FFF -
                                        (long)count * line->clumpiness_factor +
                                        0xFA;
                                    this->push_stack(*stack_ptr, x - 1, y,
                                        0.0f, (float)cost);
                                }
                                if (x < max_x &&
                                    this->search_map_rows[y][x + 1] ==
                                        this->info.land_num) {
                                    long random_value = debug_rand(
                                        (char*)"C:\\msdev\\work\\age1_x1\\rmm_land.cpp",
                                        0x13B);
                                    long cost =
                                        (random_value * 100) / 0x7FFF -
                                        (long)count * line->clumpiness_factor +
                                        0xFA;
                                    this->push_stack(*stack_ptr, x + 1, y,
                                        0.0f, (float)cost);
                                }
                                if (y > 0 &&
                                    this->search_map_rows[y - 1][x] ==
                                        this->info.land_num) {
                                    long random_value = debug_rand(
                                        (char*)"C:\\msdev\\work\\age1_x1\\rmm_land.cpp",
                                        0x13E);
                                    long cost =
                                        (random_value * 100) / 0x7FFF -
                                        (long)count * line->clumpiness_factor +
                                        0xFA;
                                    this->push_stack(*stack_ptr, x, y - 1,
                                        0.0f, (float)cost);
                                }
                                if (y < max_y &&
                                    this->search_map_rows[y + 1][x] ==
                                        this->info.land_num) {
                                    long random_value = debug_rand(
                                        (char*)"C:\\msdev\\work\\age1_x1\\rmm_land.cpp",
                                        0x141);
                                    long cost =
                                        (random_value * 100) / 0x7FFF -
                                        (long)count * line->clumpiness_factor +
                                        0xFA;
                                    this->push_stack(*stack_ptr, x, y + 1,
                                        0.0f, (float)cost);
                                }
                                *size_ptr = index2 + 1;
                            }
                        }
                    }
                }

                ++index3;
                ++line;
                ++size_ptr;
                ++stack_ptr;
            } while (index3 < this->info.land_num);
        }
    } while (done == 0);

    index3 = 0;
    if (this->info.land_num > 0) {
        Map_Stack* stack_ptr = stack;
        do {
            uchar terrain = (uchar)this->info.land[index3].terrain_type;
            uchar zone = this->info.land[index3].zone;
            while (this->pop_stack(*stack_ptr, x, y, stack_cost) != 0) {
                RGE_Tile* tile = &this->map_row_offset[y][x];
                if ((x > 0 &&
                     this->search_map_rows[y][x - 1] == zone &&
                     x < max_x &&
                     this->search_map_rows[y][x + 1] == zone) ||
                    (y > 0 &&
                     this->search_map_rows[y - 1][x] == zone &&
                     y < max_y &&
                     this->search_map_rows[y + 1][x] == zone)) {
                    tile->terrain_type = terrain;
                }
            }
            ++index3;
            ++stack_ptr;
        } while (index3 < this->info.land_num);
    }

    index3 = 0;
    if (this->info.land_num > 0) {
        Map_Stack* stack_ptr = stack;
        do {
            this->deinit_stack(*stack_ptr);
            ++index3;
            ++stack_ptr;
        } while (index3 < this->info.land_num);
    }

    return 1;
}
