// PDB source module: C:\\msdev\\work\\age1_x1\\rmm_elev.cpp.
// Definitions follow the original source order from lines 21 through 403.
// Map tiles and stack nodes use their canonical typed owners.

#include "../include/rmm_elev.h"
#include "../include/map.h"

#include <math.h>
#include <string.h>

extern "C" int __cdecl debug_rand(char* file, int line);

RGE_RMM_Elevation_Generator::RGE_RMM_Elevation_Generator(
    RGE_Map* map, RGE_Random_Map_Module* parent, RGE_Elevation_Info* info)
    : RGE_Random_Map_Module(map, parent, 1)
{
    memcpy(&this->info, info, 0x3E0 * sizeof(long));
    this->schedule = 1.5f;
}

uchar RGE_RMM_Elevation_Generator::generate()
{
    this->clear_stack();

    if (this->info.elevation_num > 0) {
        long row = 0;
        if (row < this->map_height) {
            do {
                RGE_Tile* tile = this->map_row_offset[row];
                long col = 0;
                if (col < this->map_width) {
                    do {
                        tile->height =
                            (uchar)this->info.elevation[0].base_elevation;
                        ++col;
                        ++tile;
                    } while (col < this->map_width);
                }
                ++row;
            } while (row < this->map_height);
        }
    }

    this->generate_modifiers();

    long i = 0;
    if (this->info.elevation_num > 0) {
        RGE_Elevation_Info_Line* line = this->info.elevation;
        do {
            this->base_elevation_generate(*line);
            this->map->clean_elevation(0, 0, this->map_width - 1,
                this->map_height - 1, 8);
            ++i;
            ++line;
        } while (i < this->info.elevation_num);
    }

    return 1;
}

uchar RGE_RMM_Elevation_Generator::check_start_elevation(
    long x, long y, uchar terrain, uchar elevation, uchar range)
{
    long x0 = x - range;
    long y0 = y - range;
    RGE_Tile** row_ptr;
    RGE_Tile* row_base;
    long index1;
    long y1;
    long x1;
    y1 = y + range;
    x1 = x + range;

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
                if (terrain == 0xFF
                    || cell->terrain_type != terrain
                    || cell->height < elevation) {
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
    uchar elev, long x, long y, long radius, uchar terrain, uchar min_elev)
{
    long count = 0;
    if (radius > 0) {
        long x1;
        long y1;
        long x2;
        long y2;
        RGE_Tile** row_ptr;
        RGE_Tile* row;
        long index1;
        x1 = x - radius;
        y1 = y - radius;
        x2 = radius + x;
        y2 = y + radius;
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
        for (; index1 <= y2; ++index1) {
            if (x1 <= x2) {
                RGE_Tile* cell = row;
                long xx = x1;
                do {
                    if (terrain == 0xFF || cell->terrain_type != terrain
                        || cell->height < min_elev) {
                        return 0;
                    }
                    ++xx;
                    ++cell;
                } while (xx <= x2);
            }
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
                        if (cell->height == elev) {
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
                        RGE_Elevation_Hot_Spots* hot_spot =
                            this->info.hot_spots;
                        long hot_spot_num = this->info.hot_spot_num;
                        do {
                            long dx = x - hot_spot->x;
                            long dy = y - hot_spot->y;

                            if (dx < 0)
                                dx = -dx;
                            if (dy < 0)
                                dy = -dy;

                            long distance = (long)sqrt(
                                (double)(dx * dx + dy * dy));
                            long contribution = hot_spot->radius - distance;
                            if (contribution > 0)
                                modifier += hot_spot->fade * contribution;

                            ++hot_spot;
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

float RGE_RMM_Elevation_Generator::fig_chance(long p0, long p1, long p2)
{
    return (float)(0xFA - p0 * 15);
}

long RGE_RMM_Elevation_Generator::count_map_tiles(uchar tile_type)
{
    long count = 0;
    long row = 0;
    if (row < this->map_height) {
        do {
            RGE_Tile* tile = this->map_row_offset[row];
            long col = 0;
            if (col < this->map_width) {
                do {
                    if (tile->terrain_type == tile_type) {
                        ++count;
                    }
                    ++col;
                    ++tile;
                } while (col < this->map_width);
            }
            ++row;
        } while (row < this->map_height);
    }
    return count;
}

void RGE_RMM_Elevation_Generator::link_stack_randomly(Map_Stack* param_1)
{
    Map_Stack* stack;
    long width = this->map_width;
    long height = this->map_height;
    stack = this->stack_array;
    long max_x = width - 1;
    long max_y = height - 1;

    stack->prev = param_1;
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
        this->add_stack_node(param_1, &this->stack_offsets[y][x]);
    }
}

void RGE_RMM_Elevation_Generator::remove_area_from_lists(
    long x, long y, long radius)
{
    long start_x = x - radius;
    long start_y = y - radius;
    long max_x = x + radius;

    if (start_x < 0) {
        start_x = 0;
    }
    if (start_y < 0) {
        start_y = 0;
    }
    if (max_x >= this->map_width) {
        max_x = this->map_width - 1;
    }

    long row = start_y;
    while (row <= max_x) {
        if (start_x <= max_x) {
            Map_Stack* node = this->stack_offsets[row] + start_x;
            long count = max_x - start_x + 1;
            do {
                this->remove_stack_node(node);
                ++node;
                --count;
            } while (count != 0);
        }
        ++row;
    }
}

uchar RGE_RMM_Elevation_Generator::base_elevation_generate(
    RGE_Elevation_Info_Line line)
{
    long x;
    long y;
    uchar ok;
    char done;
    long clump_size;
    long chance;
    float local_chance;
    long max_x;
    long max_y;
    float stack_cost;
    Map_Stack local_stack;
    Map_Stack stack[99];

    max_x = this->map_width - 1;
    chance = 0;
    max_y = this->map_height - 1;

    if (line.clumps > 0) {
        for (long i = 0; i < line.clumps; ++i) {
            this->init_stack(stack[i]);
        }
    }

    local_stack.prev = 0;
    stack[0].x = 0;
    this->link_stack_randomly(&local_stack);

    clump_size = (long)sqrt((double)line.elevation_size / (double)line.clumps);
    clump_size /= 2;
    if (clump_size < 2) {
        clump_size = 2;
    }

    {
        long i = 0;
        while (i < line.clumps) {
            Map_Stack* node = this->pop_stack(local_stack, y, x,
                stack_cost);
            if (node == 0) {
                break;
            }

            if (this->search_map_rows[x][y] == 0
                && this->check_start_elevation(y, x,
                    (uchar)line.base_terrain_type,
                    (uchar)line.base_elevation,
                    (uchar)line.spacing) != 0) {
                this->remove_area_from_lists(y, x, clump_size);

                RGE_Tile* tile = &this->map_row_offset[x][y];
                tile->height = (uchar)line.elevation;

                if (y > 0) {
                    this->push_stack(stack[i], y - 1, x, 0.0f, 0.0f);
                }
                if (x > 0) {
                    this->push_stack(stack[i], y, x - 1, 0.0f, 0.0f);
                }
                if (y < max_x) {
                    this->push_stack(stack[i], y + 1, x, 0.0f, 0.0f);
                }
                if (x < max_y) {
                    this->push_stack(stack[i], y, x + 1, 0.0f, 0.0f);
                }

                ++chance;
                ++i;
            }
        }
    }

    do {
        done = 1;
        if (line.clumps > 0) {
            Map_Stack* stack_ptr = stack;
            long phase_count = line.clumps;
            do {
                if (chance < line.elevation_size) {
                    Map_Stack* node = this->pop_stack(*stack_ptr, y, x,
                        stack_cost);
                    if (node != 0) {
                        done = 0;
                        uchar* mark = &this->search_map_rows[x][y];
                        long random_value = (debug_rand(
                            "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp", 0x171) * 100)
                            / 0x7FFF;
                        if (*mark <= random_value) {
                            RGE_Tile* tile = &this->map_row_offset[x][y];
                            ok = this->check_elevation(
                                (uchar)line.elevation, y, x, line.spacing,
                                (uchar)line.base_terrain_type,
                                (uchar)line.base_elevation);

                            if (tile->height
                                == (uchar)line.base_elevation
                                && ok > 0) {
                                local_chance = this->fig_chance(ok, y, x);
                                tile->height = (uchar)line.elevation;

                                if (y > 0) {
                                    if (tile[-1].height
                                        == (uchar)line.base_elevation) {
                                        long random_value = (debug_rand(
                                            "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp",
                                            0x17D) * 100) / 0x7FFF;
                                        this->push_stack(*stack_ptr, y - 1, x,
                                            0.0f,
                                            (float)random_value + local_chance);
                                    }
                                }
                                if (y < max_x) {
                                    if (tile[1].height
                                        == (uchar)line.base_elevation) {
                                        long random_value = (debug_rand(
                                            "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp",
                                            0x17F) * 100) / 0x7FFF;
                                        this->push_stack(*stack_ptr, y + 1, x,
                                            0.0f,
                                            (float)random_value + local_chance);
                                    }
                                }
                                if (x > 0) {
                                    if (tile[-this->map_width].height
                                        == (uchar)line.base_elevation) {
                                        long random_value = (debug_rand(
                                            "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp",
                                            0x181) * 100) / 0x7FFF;
                                        this->push_stack(*stack_ptr, y, x - 1,
                                            0.0f,
                                            (float)random_value + local_chance);
                                    }
                                }
                                if (x < max_y) {
                                    if (tile[this->map_width].height
                                        == (uchar)line.base_elevation) {
                                        long random_value = (debug_rand(
                                            "C:\\msdev\\work\\age1_x1\\rmm_elev.cpp",
                                            0x183) * 100) / 0x7FFF;
                                        this->push_stack(*stack_ptr, y, x + 1,
                                            0.0f,
                                            (float)random_value + local_chance);
                                    }
                                }

                                ++chance;
                            }
                        } else {
                            *mark = 0x65;
                        }
                    }
                }
                ++stack_ptr;
                --phase_count;
            } while (phase_count != 0);
        }
    } while (done == 0);

    if (line.clumps > 0) {
        for (long i = 0; i < line.clumps; ++i) {
            this->deinit_stack(stack[i]);
        }
    }
    return 1;
}
