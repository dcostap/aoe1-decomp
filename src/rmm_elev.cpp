// Map tiles and stack nodes use their canonical typed owners.

#include "../include/rmm_elev.h"
#include "../include/map.h"

#include <math.h>
#include <string.h>

extern int __cdecl debug_rand(char* file, int line);

RGE_RMM_Elevation_Generator::RGE_RMM_Elevation_Generator(
    RGE_Map* in_map, RGE_Random_Map_Module* parent_module,
    RGE_Elevation_Info* in_info)
    : RGE_Random_Map_Module(in_map, parent_module, 1) {
    memcpy(&this->info, in_info, 0x3E0 * sizeof(long));
    this->schedule = 1.5f;
}

uchar RGE_RMM_Elevation_Generator::generate() {
    this->clear_stack();

    if (this->info.elevation_num > 0) {
        long row = 0;
        if (row < this->map_height) {
            do {
                long column = 0;
                if (this->map_width > 0) {
                    do {
                        RGE_Tile* tile = this->map_row_offset[row] + column;
                        tile->height =
                            (uchar)this->info.elevation[0].base_elevation;
                        ++column;
                    } while (column < this->map_width);
                }
                ++row;
            } while (row < this->map_height);
        }
    }

    this->generate_modifiers();

    long index = 0;
    if (this->info.elevation_num > 0) {
        RGE_Elevation_Info_Line* line = &this->info.elevation[0];
        do {
            this->base_elevation_generate(*line);
            this->map->clean_elevation(0, 0, this->map_width - 1,
                this->map_height - 1, 8);
            ++index;
            ++line;
        } while (index < this->info.elevation_num);
    }

    return 1;
}

uchar RGE_RMM_Elevation_Generator::check_start_elevation(
    long x, long y, uchar base_terrain, uchar base_elevation, uchar spacing) {
    long x0 = x - spacing;
    long y0 = y - spacing;
    RGE_Tile** row_ptr;
    RGE_Tile* row_base;
    long index1;
    long y1;
    long x1;
    y1 = y + spacing;
    x1 = x + spacing;

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

    index1 = y0;
    row_ptr = this->map_row_offset + y0;
    row_base = *row_ptr + x0;
    while (index1 <= y1) {
        if (x0 <= x1) {
            RGE_Tile* cell = row_base;
            long col = x0;
            do {
                if (base_terrain == 0xFF
                    || cell->terrain_type != base_terrain
                    || cell->height < base_elevation) {
                    return 0;
                }
                ++col;
                ++cell;
            } while (col <= x1);
        }
        ++row_ptr;
        ++index1;
        row_base = *row_ptr + x0;
    }
    return 1;
}

uchar RGE_RMM_Elevation_Generator::check_elevation(
    uchar target, long x, long y, long spacing, uchar base_terrain,
    uchar base_elevation) {
    long count = 0;
    if (spacing > 0) {
        long x1;
        long y1;
        long x2;
        long y2;
        RGE_Tile** row_ptr;
        RGE_Tile* row;
        long index1;
        x1 = x - spacing;
        y1 = y - spacing;
        x2 = spacing + x;
        y2 = y + spacing;
        if (x1 < 0) {
            x1 = 0;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (x2 >= this->map_width) {
            x2 = this->map_width - 1;
        }
        if (y2 >= this->map_height) {
            y2 = this->map_height - 1;
        }
        row_ptr = this->map_row_offset + y1;
        row = *row_ptr + x1;
        index1 = y1;
        while (index1 <= y2) {
            if (x1 <= x2) {
                RGE_Tile* cell = row;
                long xx = x1;
                do {
                    if (base_terrain == 0xFF
                        || cell->terrain_type != base_terrain
                        || cell->height < base_elevation) {
                        return 0;
                    }
                    ++xx;
                    ++cell;
                } while (xx <= x2);
            }
            ++index1;
            ++row_ptr;
            row = *row_ptr + x1;
        }
    }

    {
        long x1 = x - 2;
        long y1 = y - 2;
        long x2 = x + 2;
        long y2 = y + 2;
        if (x1 < 0) {
            x1 = 0;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (x2 >= this->map_width) {
            x2 = this->map_width - 1;
        }
        if (y2 >= this->map_height) {
            y2 = this->map_height - 1;
        }

        RGE_Tile* row_base2;
        RGE_Tile** row_ptr2;
        row_ptr2 = this->map_row_offset + y1;
        row_base2 = *row_ptr2 + x1;
        if (y1 <= y2) {
            long rows_left = y2 - y1 + 1;
            do {
                if (x1 <= x2) {
                    RGE_Tile* cell = row_base2;
                    long cols_left = x2 - x1 + 1;
                    do {
                        if (cell->height == target) {
                            ++count;
                        }
                        ++cell;
                        --cols_left;
                    } while (cols_left != 0);
                }
                ++row_ptr2;
                row_base2 = *row_ptr2 + x1;
                --rows_left;
            } while (rows_left != 0);
        }
    }

    return (uchar)count;
}

void RGE_RMM_Elevation_Generator::generate_modifiers() {
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

                            long distance = (long)sqrt(
                                (double)(dx * dx + dy * dy));
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
                        this->search_map_rows[y][x] = (uchar)modifier;
                    ++x;
                } while (x < this->map_width);
            }
            ++y;
        } while (y < this->map_height);
    }
}

float RGE_RMM_Elevation_Generator::fig_chance(long count, long x, long y) {
    return (float)(0xFA - count * 15);
}

long RGE_RMM_Elevation_Generator::count_map_tiles(uchar terrain) {
    RGE_Tile* tile = this->map_row_offset[0];
    RGE_Tile* end = tile + this->map_width * this->map_height;
    long count = 0;
    while (tile < end) {
        if (tile->terrain_type == terrain) {
            ++count;
        }
        ++tile;
    }
    return count;
}

void RGE_RMM_Elevation_Generator::link_stack_randomly(Map_Stack* loc_stack) {
    Map_Stack* stack;
    long width = this->map_width;
    long height = this->map_height;
    stack = this->stack_array;
    long max_x = width - 1;
    long max_y = height - 1;

    stack->prev = loc_stack;
    Map_Stack* last = &stack[height * width - 1];
    stack->next = &stack[1];
    last->next = 0;
    last->prev = &last[-1];

    Map_Stack* node = &stack[1];
    while (node < last) {
        node->next = &node[1];
        node->prev = &node[-1];
        ++node;
    }

    for (long count = this->map_height * this->map_width / 16;
         count > 0; --count) {
        long x = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_elev.cpp", 0xFA)
            * max_x / 0x7FFF;
        long y = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_elev.cpp", 0xFB)
            * max_y / 0x7FFF;
        this->add_stack_node(loc_stack, &this->stack_offsets[y][x]);
    }
}

void RGE_RMM_Elevation_Generator::remove_area_from_lists(
    long x, long y, long spacing) {
    long start_x = x - spacing;
    long start_y = y - spacing;
    long max_x = x + spacing;

    if (start_x < 0) {
        start_x = 0;
    }
    if (start_y < 0) {
        start_y = 0;
    }
    if (max_x >= this->map_width) {
        max_x = this->map_width - 1;
    }

    long y_index = start_y;
    while (y_index <= max_x) {
        if (start_x <= max_x) {
            long column = start_x;
            while (column <= max_x) {
                this->remove_stack_node(this->stack_offsets[y_index] + column);
                ++column;
            }
        }
        ++y_index;
    }
}

uchar RGE_RMM_Elevation_Generator::base_elevation_generate(
    RGE_Elevation_Info_Line info_line) {
    long x;
    long y;
    long chance_count = 0;
    long clump_count;
    long area;
    long max_x = this->map_width - 1;
    long max_y = this->map_height - 1;
    float in_zone;
    float chance;
    uchar done;
    Map_Stack loc_stack;
    Map_Stack stack[99];

    if (info_line.clumps > 0) {
        Map_Stack* stack_ptr = stack;
        long count = info_line.clumps;
        do {
            this->init_stack(*stack_ptr);
            ++stack_ptr;
            --count;
        } while (count != 0);
    }

    loc_stack.next = 0;
    loc_stack.prev = 0;
    this->link_stack_randomly(&loc_stack);

    area = (long)sqrt(
        (double)info_line.elevation_size / (double)info_line.clumps);
    area /= 2;
    if (area < 2) {
        area = 2;
    }

    clump_count = 0;
    if (clump_count < info_line.clumps) {
        Map_Stack* stack_ptr = stack;
        do {
            if (this->pop_stack(loc_stack, x, y, in_zone) == 0) {
                break;
            }

            if (this->search_map_rows[y][x] == 0 &&
                this->check_start_elevation(
                    x, y, (uchar)info_line.base_terrain_type,
                    (uchar)info_line.base_elevation,
                    (uchar)info_line.spacing) != 0) {
                this->remove_area_from_lists(x, y, area);

                this->map_row_offset[y][x].height =
                    (uchar)info_line.elevation;

                if (x > 0) {
                    this->push_stack(*stack_ptr, x - 1, y,
                                     0.0f, 0.0f);
                }
                if (y > 0) {
                    this->push_stack(*stack_ptr, x, y - 1,
                                     0.0f, 0.0f);
                }
                if (x < max_x) {
                    this->push_stack(*stack_ptr, x + 1, y,
                                     0.0f, 0.0f);
                }
                if (y < max_y) {
                    this->push_stack(*stack_ptr, x, y + 1,
                                     0.0f, 0.0f);
                }

                ++chance_count;
                ++clump_count;
                ++stack_ptr;
            }
        } while (clump_count < info_line.clumps);
    }

    do {
        done = 1;
        if (info_line.clumps > 0) {
            Map_Stack* stack_ptr = stack;
            long count = info_line.clumps;
            do {
                if (chance_count < info_line.elevation_size &&
                    this->pop_stack(*stack_ptr, x, y, in_zone) != 0) {
                    done = 0;

                    uchar* modifier = &this->search_map_rows[y][x];
                    long random_value =
                        (debug_rand(
                             "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp",
                             0x171) * 100) /
                        0x7fff;
                    if (*modifier <= random_value) {
                        RGE_Tile* tile = &this->map_row_offset[y][x];
                        uchar elevation_count = this->check_elevation(
                            (uchar)info_line.elevation, x, y,
                            info_line.spacing,
                            (uchar)info_line.base_terrain_type,
                            (uchar)info_line.base_elevation);

                        if (tile->height == info_line.base_elevation &&
                            elevation_count != 0) {
                            chance = this->fig_chance(
                                elevation_count, x, y);
                            tile->height = (uchar)info_line.elevation;

                            if (x > 0 &&
                                tile[-1].height ==
                                    info_line.base_elevation) {
                                long clump_size =
                                    (debug_rand(
                                         "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp",
                                         0x17d) * 100) /
                                    0x7fff;
                                this->push_stack(
                                    *stack_ptr, x - 1, y, 0.0f,
                                    (float)clump_size + chance);
                            }
                            if (x < max_x &&
                                tile[1].height ==
                                    info_line.base_elevation) {
                                long clump_size =
                                    (debug_rand(
                                         "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp",
                                         0x17f) * 100) /
                                    0x7fff;
                                this->push_stack(
                                    *stack_ptr, x + 1, y, 0.0f,
                                    (float)clump_size + chance);
                            }
                            if (y > 0 &&
                                tile[-this->map_width].height ==
                                    info_line.base_elevation) {
                                long clump_size =
                                    (debug_rand(
                                         "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp",
                                         0x181) * 100) /
                                    0x7fff;
                                this->push_stack(
                                    *stack_ptr, x, y - 1, 0.0f,
                                    (float)clump_size + chance);
                            }
                            if (y < max_y &&
                                tile[this->map_width].height ==
                                    info_line.base_elevation) {
                                long clump_size =
                                    (debug_rand(
                                         "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp",
                                         0x183) * 100) /
                                    0x7fff;
                                this->push_stack(
                                    *stack_ptr, x, y + 1, 0.0f,
                                    (float)clump_size + chance);
                            }
                            ++chance_count;
                        }
                    } else {
                        *modifier = 101;
                    }
                }
                ++stack_ptr;
                --count;
            } while (count != 0);
        }
    } while (done == 0);

    if (info_line.clumps > 0) {
        Map_Stack* stack_ptr = stack;
        long count = info_line.clumps;
        do {
            this->deinit_stack(*stack_ptr);
            ++stack_ptr;
            --count;
        } while (count != 0);
    }

    return 1;
}
