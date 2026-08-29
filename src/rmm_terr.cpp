#include "../include/rmm_terrain_generator.h"
#include "../include/map.h"
#include "../include/zone_map.h"
#include "../include/basegame.h"
#include <math.h>
#include <string.h>

extern "C" double __cdecl sqrt(double value);
#pragma intrinsic(sqrt)

// PDB source order for C:\\msdev\\work\\age1_x1\\rmm_terr.cpp.

RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator(
    RGE_Map* map, RGE_Random_Map_Module* parent, RGE_Terrain_Info* info)
    : RGE_Random_Map_Module(map, parent, 1)
{
    this->info = *info;
    this->schedule = 2.0f;
}

unsigned char RGE_RMM_Terrain_Generator::generate()
{
    long index;
    float terrain_table[99];

    this->generate_modifiers();
    index = 0;
    do {
        terrain_table[index] = (float)index;
        index++;
    } while (index < 99);

    // The executable reloads the map zone-list field for the second call.
    long zid = this->map->map_zones->create_zone_map(terrain_table, 99);
    this->map_zone = this->map->map_zones->get_zone_map(zid);

    index = 0;
    if (this->info.terrain_num > 0) {
        RGE_Terrain_Info_Line* p = this->info.terrain;
        do {
            this->base_terrain_generate(*p);
            index++;
            p++;
        } while (index < this->info.terrain_num);
    }
    this->check_borders();
    return 1;
}

unsigned char RGE_RMM_Terrain_Generator::water(unsigned char value)
{
    if (value == 1) {
        return value;
    }
    if (value == 4) {
        return 1;
    }
    if (value == 0x16) {
        return 1;
    }
    return 0;
}

void RGE_RMM_Terrain_Generator::check_borders()
{
    int y = 0;
    int max_y = this->map_height - 1;
    int max_x = this->map_width - 1;

    if (this->map_height > 0) {
        do {
            int x = 0;
            if (this->map_width > 0) {
                do {
                    uchar t = this->map_row_offset[y][x].terrain_type;
                    if (!this->water(t)) {
                        uchar border = 0;
                        if (y > 0 &&
                            this->water(this->map_row_offset[y - 1][x].terrain_type)) {
                            border = 1;
                        } else if (y < max_y &&
                                   this->water(this->map_row_offset[y + 1][x].terrain_type)) {
                            border = 1;
                        }

                        if (x > 0) {
                            if (this->water(this->map_row_offset[y][x - 1].terrain_type) ||
                                (y > 0 &&
                                 this->water(this->map_row_offset[y - 1][x - 1].terrain_type)) ||
                                (y < max_y &&
                                 this->water(this->map_row_offset[y + 1][x - 1].terrain_type))) {
                                border = 1;
                            }
                        }

                        if (x < max_x) {
                            if (this->water(this->map_row_offset[y][x + 1].terrain_type) ||
                                (y > 0 &&
                                 this->water(this->map_row_offset[y - 1][x + 1].terrain_type)) ||
                                (y < max_y &&
                                 this->water(this->map_row_offset[y + 1][x + 1].terrain_type))) {
                                border = 1;
                            }
                        }

                        if (border == 1) {
                            this->map_row_offset[y][x].terrain_type = 2;
                        }
                    }
                    ++x;
                } while (x < this->map_width);
            }
            ++y;
        } while (y < this->map_height);
    }
}

uchar RGE_RMM_Terrain_Generator::check_terrain(
    uchar terrain, long x, long y, long radius, uchar avoid_terrain)
{
    // BINARY NOTE: Both scans use clipped inclusive bounds and preserve the
    // executable's terrain predicate and byte-count return.
    long count = 1;
    long base_terrain =
        this->map->terrain_types[avoid_terrain].impassable_terrain;
    long row_index;

    if (radius > 0) {
        long min_x = x - radius;
        long max_x = x + radius;
        long min_y = y - radius;
        long max_y = y + radius;

        if (min_x < 0) min_x = 0;
        if (min_y < 0) min_y = 0;
        if (max_x >= this->map_width) max_x = this->map_width - 1;
        if (max_y >= this->map_height) max_y = this->map_height - 1;

        RGE_Tile** row_ptr = this->map_row_offset + min_y;
        RGE_Tile* row = *row_ptr + min_x;

        row_index = min_y;
        if (row_index <= max_y) {
            do {
                if (min_x <= max_x) {
                    long xx = min_x;
                    RGE_Tile* tile = row;
                    do {
                        if (((tile->terrain_type & 0x1f) != avoid_terrain) &&
                            ((tile->terrain_type & 0x1f) != base_terrain) &&
                            ((tile->terrain_type & 0x1f) != terrain)) {
                            return 0;
                        }
                        ++xx;
                        ++tile;
                    } while (xx <= max_x);
                }
                ++row_ptr;
                ++row_index;
                row = *row_ptr + min_x;
            } while (row_index <= max_y);
        }
    }

    long min_x = x - 2;
    long min_y = y - 2;
    long max_x = x + 2;
    long max_y = y + 2;

    if (min_x < 0) min_x = 0;
    if (min_y < 0) min_y = 0;
    if (max_x >= this->map_width) max_x = this->map_width - 1;
    if (max_y >= this->map_height) max_y = this->map_height - 1;

    RGE_Tile** row_ptr = this->map_row_offset + min_y;
    RGE_Tile* row = *row_ptr + min_x;
    if (min_y <= max_y) {
        long row_count = max_y - min_y + 1;
        do {
            if (min_x <= max_x) {
                RGE_Tile* tile = row;
                long col_count = max_x - min_x + 1;
                do {
                    if ((tile->terrain_type & 0x1f) == terrain) {
                        ++count;
                    }
                    ++tile;
                    --col_count;
                } while (col_count != 0);
            }
            ++row_ptr;
            row = *row_ptr + min_x;
            --row_count;
        } while (row_count != 0);
    }
    return (uchar)count;
}

void RGE_RMM_Terrain_Generator::generate_modifiers()
{
    long modifier;

    long map_size = this->map_width;
    map_size *= this->map_height;
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

                            long distance =
                                (long)sqrt((double)(dx * dx + dy * dy));
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

float RGE_RMM_Terrain_Generator::fig_chance(
    long p0, long p1, long p2, long p3)
{
    return (float)(0xFA - p3 * p0);
}

long RGE_RMM_Terrain_Generator::count_map_tiles(unsigned char tileType)
{
    // BINARY NOTE: The executable scans +0x10 rows with +0x18 tile records.
    RGE_Tile* tile = this->map_row_offset[0];
    RGE_Tile* end = tile + this->map_width * this->map_height;
    long count = 0;

    while (tile < end) {
        if (tile->terrain_type == tileType) {
            count++;
        }
        ++tile;
    }
    return count;
}

void RGE_RMM_Terrain_Generator::link_stack_randomly(
    Map_Stack* param_1, unsigned char param_2)
{
    Map_Stack* list = param_1;
    long max_x = this->map_width - 1;
    long max_y = this->map_height - 1;
    Map_Stack* first = this->stack_array;
    Map_Stack* last = first + this->map_height * this->map_width - 1;

    first->prev = list;
    first->next = first + 1;
    list->next = first;
    last->next = 0;
    last->prev = last - 1;

    first = first + 1;
    while (first < last) {
        first->next = first + 1;
        first->prev = first - 1;
        first = first + 1;
    }

    long count = this->map_height * this->map_width / 8;
    if (count > 0) {
        long loop_count = count;
        do {
            long x = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 0x10F)
                      * max_x) / 0x7FFF;
            long y = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 0x110)
                      * max_y) / 0x7FFF;
            this->add_stack_node(list, this->stack_offsets[y] + x);
            --loop_count;
        } while (loop_count != 0);
    }
}

void RGE_RMM_Terrain_Generator::remove_area_from_lists(
    long p1, long p2, long p3)
{
    long xmin = p1 - p3;
    long ymin = p2 - p3;
    long xmax = p1 + p3;
    long ymax = p2 + p3;

    if (xmin < 0) xmin = 0;
    if (ymin < 0) ymin = 0;

    if (xmax >= map_width) {
        xmax = map_width - 1;
    }
    if (ymax >= map_height) {
        ymax = map_height - 1;
    }

    for (long y = ymin; y <= ymax; y++) {
        if (xmin <= xmax) {
            long base = xmin;
            long count = xmax - xmin;
            count++;
            do {
                Map_Stack* row = this->stack_offsets[y];
                remove_stack_node(row + base);
                base++;
                count--;
            } while (count != 0);
        }
    }
}

uchar RGE_RMM_Terrain_Generator::base_terrain_generate(
    RGE_Terrain_Info_Line line)
{
    // BINARY NOTE: pop_stack writes adjacent long x and chance outputs.
    struct Stack_Coordinates {
        long x;
        long chance;
    } coordinates;
    long& x = coordinates.x;
    long& chance = coordinates.chance;

    // BINARY NOTE: The shipped body reuses the fair_count home for its float
    // score after the fairness phase.
    union {
        float fStack_a4c;
        long fair_count;
    };
    uchar done;
    long local_a44;
    long clump_size;
    long in_zone = 0;
    float cost;
    long max_x;
    int hot_i;
    int stack_i;
    int fair_i;
    int scan_i;
    int cleanup_i;
    Map_Stack loc_stack;
    long loc_stack_x;
    Map_Stack* stack_ptr;
    uchar terrain_fairness_zones_visited[99];
    uchar terrain_fairness_zones[99];
    Map_Stack stack[99];

    loc_stack_x = this->map_width - 1;
    max_x = this->map_height - 1;
    {
    fair_count = 0;

    if (line.avoid_hot_spots == 2 && this->info.hot_spot_num > 0) {
        hot_i = 0;
        RGE_Terrain_Hot_Spots* hot_spot = this->info.hot_spots;
        do {
            terrain_fairness_zones[hot_i] =
                this->map_zone->get_zone_info(hot_spot->x, hot_spot->y);
            terrain_fairness_zones_visited[hot_i] = 0;
            ++hot_i;
            ++hot_spot;
        } while (hot_i < this->info.hot_spot_num);
    }

    for (stack_i = 0; stack_i < 99; ++stack_i) {
        this->init_stack(stack[stack_i]);
    }

    loc_stack.next = 0;
    loc_stack.prev = 0;
    this->link_stack_randomly(&loc_stack, (uchar)line.base_terrain_type);

    local_a44 = (long)sqrt((double)line.terrain_size / (double)line.clumps);
    local_a44 += local_a44;
    if (local_a44 < 2) {
        local_a44 = 2;
    }

    clump_size = 0;
    if (clump_size < line.clumps) {
        stack_ptr = stack;
        while (clump_size < line.clumps) {
            if (this->pop_stack(loc_stack, chance, x, cost) == 0) {
                break;
            }

            if ((this->map_row_offset[x][chance].terrain_type & 0x1f) ==
                    line.base_terrain_type &&
                this->check_terrain((uchar)line.terrain_type, chance, x,
                    line.spacing, (uchar)line.base_terrain_type) > 0 &&
                (line.avoid_hot_spots == 0 ||
                 this->search_map_rows[x][chance] == 0)) {
                this->remove_area_from_lists(chance, x, local_a44);

                this->map_row_offset[x][chance].terrain_type =
                    (uchar)line.terrain_type;

                if (chance > 0) {
                    this->push_stack(*stack_ptr, chance - 1, x, 0.0f, 0.0f);
                }
                if (x > 0) {
                    this->push_stack(*stack_ptr, chance, x - 1, 0.0f, 0.0f);
                }
                if (chance < this->map_width - 1) {
                    this->push_stack(*stack_ptr, chance + 1, x, 0.0f, 0.0f);
                }
                if (x < this->map_height - 1) {
                    this->push_stack(*stack_ptr, chance, x + 1, 0.0f, 0.0f);
                }

                ++in_zone;
                ++clump_size;
                ++stack_ptr;

                uchar zone = this->map_zone->get_zone_info(chance, x);
                if (line.avoid_hot_spots == 2) {
                    fair_i = 0;
                    if (this->info.hot_spot_num > 0) {
                        do {
                            if (terrain_fairness_zones[fair_i] == zone &&
                                terrain_fairness_zones_visited[fair_i] == 0) {
                                terrain_fairness_zones_visited[fair_i] = 1;
                                ++fair_count;
                            }
                            ++fair_i;
                        } while (fair_i < this->info.hot_spot_num);
                    }
                }
            }
        }
    }

    if (line.avoid_hot_spots == 2 &&
        fair_count < this->info.hot_spot_num) {
        stack_ptr = &stack[clump_size];
        while (fair_count < this->info.hot_spot_num) {
            if (this->pop_stack(loc_stack, chance, x, cost) == 0) {
                break;
            }

            if ((this->map_row_offset[x][chance].terrain_type & 0x1f) ==
                    line.base_terrain_type &&
                this->check_terrain((uchar)line.terrain_type, chance, x,
                    line.spacing, (uchar)line.base_terrain_type) > 0 &&
                this->search_map_rows[x][chance] < 0x1e) {
                uchar zone = this->map_zone->get_zone_info(chance, x);
                fair_i = 0;
                if (this->info.hot_spot_num > 0) {
                    do {
                        if (terrain_fairness_zones[fair_i] == zone &&
                            terrain_fairness_zones_visited[fair_i] == 0) {
                            break;
                        }
                        ++fair_i;
                    } while (fair_i < this->info.hot_spot_num);
                }

                if (fair_i != this->info.hot_spot_num) {
                    ++fair_count;
                    terrain_fairness_zones_visited[fair_i] = 1;
                    this->remove_area_from_lists(chance, x, local_a44);

                    this->map_row_offset[x][chance].terrain_type =
                        (uchar)line.terrain_type;

                    if (chance > 0) {
                        this->push_stack(*stack_ptr, chance - 1, x, 0.0f, 0.0f);
                    }
                    if (x > 0) {
                        this->push_stack(*stack_ptr, chance, x - 1, 0.0f, 0.0f);
                    }
                    if (chance < this->map_width - 1) {
                        this->push_stack(*stack_ptr, chance + 1, x, 0.0f, 0.0f);
                    }
                    if (x < this->map_height - 1) {
                        this->push_stack(*stack_ptr, chance, x + 1, 0.0f, 0.0f);
                    }

                    ++in_zone;
                    ++clump_size;
                    ++stack_ptr;
                }
            }
        }
    }

    }

    long index1;
    do {
        done = 1;
        if (clump_size > 0) {
            stack_ptr = stack;
            local_a44 = clump_size;
            do {
                if (in_zone < line.terrain_size &&
                    this->pop_stack(*stack_ptr, chance, x, cost) != 0) {
                    done = 0;

                    if (line.avoid_hot_spots == 0 ||
                        this->search_map_rows[x][chance] <=
                            (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 0x1c6) * 100) /
                                0x7fff) {
                        RGE_Tile* tile = &this->map_row_offset[x][chance];
                        long ok = this->check_terrain((uchar)line.terrain_type,
                            chance, x, line.spacing,
                            (uchar)line.base_terrain_type);
                        if ((tile->terrain_type & 0x1f) ==
                                line.base_terrain_type && ok > 0) {
                            fStack_a4c = this->fig_chance(ok, chance, x,
                                line.clumpiness_factor);
                            if (line.avoid_hot_spots != 0) {
                                index1 = this->search_map_rows[x][chance];
                                fStack_a4c += (float)index1;
                            }

                            tile->terrain_type = (uchar)line.terrain_type;

                            if (chance > 0 &&
                                (tile[-1].terrain_type & 0x1f) ==
                                    line.base_terrain_type) {
                                index1 = (debug_rand(
                                    "C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 0x1d5) * 100) /
                                    0x7fff;
                                this->push_stack(*stack_ptr, chance - 1, x,
                                    0.0f, (float)index1 + fStack_a4c);
                            }
                            if (chance < loc_stack_x &&
                                (tile[1].terrain_type & 0x1f) ==
                                    line.base_terrain_type) {
                                index1 = (debug_rand(
                                    "C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 0x1d7) * 100) /
                                    0x7fff;
                                this->push_stack(*stack_ptr, chance + 1, x,
                                    0.0f, (float)index1 + fStack_a4c);
                            }
                            if (x > 0 &&
                                (tile[-this->map_width].terrain_type & 0x1f) ==
                                    line.base_terrain_type) {
                                index1 = (debug_rand(
                                    "C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 0x1d9) * 100) /
                                    0x7fff;
                                this->push_stack(*stack_ptr, chance, x - 1,
                                    0.0f, (float)index1 + fStack_a4c);
                            }
                            if (x < max_x &&
                                (tile[this->map_width].terrain_type & 0x1f) ==
                                    line.base_terrain_type) {
                                index1 = (debug_rand(
                                    "C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 0x1db) * 100) /
                                    0x7fff;
                                this->push_stack(*stack_ptr, chance, x + 1,
                                    0.0f, (float)index1 + fStack_a4c);
                            }
                            ++in_zone;
                        }
                    }
                }
                ++stack_ptr;
                --local_a44;
            } while (local_a44 != 0);
        }
    } while (done == 0);

    if (line.clumps > 0) {
        stack_ptr = stack;
        local_a44 = line.clumps;
        do {
            while (this->pop_stack(*stack_ptr, chance, x, cost) != 0) {
                RGE_Tile* tile = &this->map_row_offset[x][chance];
                if ((chance > 0 &&
                    (tile[-1].terrain_type & 0x1f) ==
                        (uchar)line.terrain_type &&
                    chance < loc_stack_x &&
                    (tile[1].terrain_type & 0x1f) ==
                        (uchar)line.terrain_type) ||
                    (x > 0 &&
                    (tile[-this->map_width].terrain_type & 0x1f) ==
                        (uchar)line.terrain_type &&
                    x > max_x &&
                    (tile[this->map_width].terrain_type & 0x1f) ==
                        (uchar)line.terrain_type)) {
                    tile->terrain_type = (uchar)line.terrain_type;
                }
            }
            ++stack_ptr;
            --local_a44;
        } while (local_a44 != 0);
    }

    for (cleanup_i = 0; cleanup_i < 99; ++cleanup_i) {
        this->deinit_stack(stack[cleanup_i]);
    }
    return 1;
}
