#include "../include/rmm_terrain_generator.h"
#include "../include/map.h"
#include "../include/zone_map.h"
#include "../include/basegame.h"
#include <math.h>
#include <string.h>

extern "C" double __cdecl sqrt(double value);
#pragma intrinsic(sqrt)


RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator(
    RGE_Map* in_map, RGE_Random_Map_Module* parent_module, RGE_Terrain_Info* in_info)
    : RGE_Random_Map_Module(in_map, parent_module, 1) {
    this->info = *in_info;
    this->schedule = 2.0f;
}

unsigned char RGE_RMM_Terrain_Generator::generate() {
    long index;
    float terrain_table[99];

    this->generate_modifiers();
    index = 0;
    do {
        terrain_table[index] = (float)index;
        index++;
    } while (index < 99);

    // The executable reloads the map zone-list field for the second call.
    long zone_id = this->map->map_zones->create_zone_map(terrain_table, 99);
    this->map_zone = this->map->map_zones->get_zone_map(zone_id);

    index = 0;
    if (this->info.terrain_num > 0) {
        RGE_Terrain_Info_Line* terrain_line = this->info.terrain;
        do {
            this->base_terrain_generate(*terrain_line);
            index++;
            terrain_line++;
        } while (index < this->info.terrain_num);
    }
    this->check_borders();
    return 1;
}

unsigned char RGE_RMM_Terrain_Generator::water(unsigned char terrain) {
    if (terrain == 1) {
        return terrain;
    }
    if (terrain == 4) {
        return 1;
    }
    if (terrain == 0x16) {
        return 1;
    }
    return 0;
}

void RGE_RMM_Terrain_Generator::check_borders() {
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
                        if (y > 0 && this->water(this->map_row_offset[y - 1][x].terrain_type)) {
                            border = 1;
                        } else if (y < max_y && this->water(this->map_row_offset[y + 1][x].terrain_type)) {
                            border = 1;
                        }

                        if (x > 0) {
                            if (this->water(this->map_row_offset[y][x - 1].terrain_type) || (y > 0 &&
                                 this->water(this->map_row_offset[y - 1][x - 1].terrain_type)) || (y < max_y &&
                                 this->water(this->map_row_offset[y + 1][x - 1].terrain_type))) {
                                border = 1;
                            }
                        }

                        if (x < max_x) {
                            if (this->water(this->map_row_offset[y][x + 1].terrain_type) || (y > 0 &&
                                 this->water(this->map_row_offset[y - 1][x + 1].terrain_type)) || (y < max_y &&
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
    uchar target, long x, long y, long spacing, uchar base_terrain) {
    // Both scans use clipped inclusive bounds and preserve the
    // executable's terrain predicate and byte-count return.
    long index1 = 1;
    long i_base_terrain =
        this->map->terrain_types[base_terrain].impassable_terrain;

    if (spacing > 0) {
        long min_x = x - spacing;
        long max_x = x + spacing;
        long min_y = y - spacing;
        long max_y = y + spacing;

        if (min_x < 0) min_x = 0;
        if (min_y < 0) min_y = 0;
        if (max_x >= this->map_width) max_x = this->map_width - 1;
        if (max_y >= this->map_height) max_y = this->map_height - 1;

        RGE_Tile** row_ptr = this->map_row_offset + min_y;
        RGE_Tile* row = *row_ptr + min_x;

        long row_index = min_y;
        if (row_index <= max_y) {
            do {
                if (min_x <= max_x) {
                    long xx = min_x;
                    RGE_Tile* tile = row;
                    do {
                        if (((tile->terrain_type & 0x1f) != base_terrain) &&
                            ((tile->terrain_type & 0x1f) != i_base_terrain) && ((tile->terrain_type & 0x1f) != target)) {
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
                    if ((tile->terrain_type & 0x1f) == target) {
                        ++index1;
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
    return (uchar)index1;
}

void RGE_RMM_Terrain_Generator::generate_modifiers() {
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
    long count, long x, long y, long clumpiness_factor) {
    return (float)(0xFA - clumpiness_factor * count);
}

long RGE_RMM_Terrain_Generator::count_map_tiles(unsigned char terrain) {
    // The executable scans +0x10 rows with +0x18 tile records.
    RGE_Tile* tile = this->map_row_offset[0];
    RGE_Tile* end = tile + this->map_width * this->map_height;
    long count = 0;

    while (tile < end) {
        if (tile->terrain_type == terrain) {
            count++;
        }
        ++tile;
    }
    return count;
}

void RGE_RMM_Terrain_Generator::link_stack_randomly(
    Map_Stack* loc_stack, unsigned char base_terrain_type) {
    Map_Stack* list = loc_stack;
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
            long x = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 271)
                      * max_x) / 0x7FFF;
            long y = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 272)
                      * max_y) / 0x7FFF;
            this->add_stack_node(list, this->stack_offsets[y] + x);
            --loop_count;
        } while (loop_count != 0);
    }
}

void RGE_RMM_Terrain_Generator::remove_area_from_lists(
    long x, long p2, long spacing) {
    long xmin = x - spacing;
    long ymin = p2 - spacing;
    long xmax = x + spacing;
    long ymax = p2 + spacing;

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
    RGE_Terrain_Info_Line info_line) {
    // pop_stack writes adjacent long x and y outputs.
    struct Stack_Coordinates {
        long x;
        long y;
    } coordinates;
    long& x = coordinates.x;
    long& y = coordinates.y;

    // The shipped body reuses the fairness-count home for its float
    // score after the fairness phase.
    union {
        float score;
        long terrain_fairness_zones_visited_count;
    };
    uchar done;
    long base_area;
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
    long max_y;
    Map_Stack* stack_ptr;
    uchar terrain_fairness_zones_visited[99];
    uchar terrain_fairness_zones[99];
    Map_Stack stack[99];

    max_y = this->map_width - 1;
    max_x = this->map_height - 1;
    {
        terrain_fairness_zones_visited_count = 0;

        if (info_line.avoid_hot_spots == 2 && this->info.hot_spot_num > 0) {
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
        this->link_stack_randomly(&loc_stack, (uchar)info_line.base_terrain_type);

        base_area = (long)sqrt((double)info_line.terrain_size / (double)info_line.clumps);
        base_area += base_area;
        if (base_area < 2) {
            base_area = 2;
        }

        clump_size = 0;
        if (clump_size < info_line.clumps) {
            stack_ptr = stack;
            while (clump_size < info_line.clumps) {
                if (this->pop_stack(loc_stack, y, x, cost) == 0) {
                    break;
                }

                if ((this->map_row_offset[x][y].terrain_type & 0x1f) == info_line.base_terrain_type &&
                    this->check_terrain((uchar)info_line.terrain_type, y, x,
                                        info_line.spacing, (uchar)info_line.base_terrain_type) > 0 &&
                    (info_line.avoid_hot_spots == 0 || this->search_map_rows[x][y] == 0)) {
                    this->remove_area_from_lists(y, x, base_area);

                    this->map_row_offset[x][y].terrain_type =
                        (uchar)info_line.terrain_type;

                    if (y > 0) {
                        this->push_stack(*stack_ptr, y - 1, x, 0.0f, 0.0f);
                    }
                    if (x > 0) {
                        this->push_stack(*stack_ptr, y, x - 1, 0.0f, 0.0f);
                    }
                    if (y < this->map_width - 1) {
                        this->push_stack(*stack_ptr, y + 1, x, 0.0f, 0.0f);
                    }
                    if (x < this->map_height - 1) {
                        this->push_stack(*stack_ptr, y, x + 1, 0.0f, 0.0f);
                    }

                    ++in_zone;
                    ++clump_size;
                    ++stack_ptr;

                    uchar zone = this->map_zone->get_zone_info(y, x);
                    if (info_line.avoid_hot_spots == 2) {
                        fair_i = 0;
                        if (this->info.hot_spot_num > 0) {
                            do {
                                if (terrain_fairness_zones[fair_i] == zone && terrain_fairness_zones_visited[fair_i] == 0) {
                                    terrain_fairness_zones_visited[fair_i] = 1;
                                    ++terrain_fairness_zones_visited_count;
                                }
                                ++fair_i;
                            } while (fair_i < this->info.hot_spot_num);
                        }
                    }
                }
            }
        }

        if (info_line.avoid_hot_spots == 2 && terrain_fairness_zones_visited_count < this->info.hot_spot_num) {
            stack_ptr = &stack[clump_size];
            while (terrain_fairness_zones_visited_count < this->info.hot_spot_num) {
                if (this->pop_stack(loc_stack, y, x, cost) == 0) {
                    break;
                }

                if ((this->map_row_offset[x][y].terrain_type & 0x1f) == info_line.base_terrain_type &&
                    this->check_terrain((uchar)info_line.terrain_type, y, x,
                                        info_line.spacing, (uchar)info_line.base_terrain_type) > 0 &&
                    this->search_map_rows[x][y] < 0x1e) {
                    uchar zone = this->map_zone->get_zone_info(y, x);
                    fair_i = 0;
                    if (this->info.hot_spot_num > 0) {
                        do {
                            if (terrain_fairness_zones[fair_i] == zone && terrain_fairness_zones_visited[fair_i] == 0) {
                                break;
                            }
                            ++fair_i;
                        } while (fair_i < this->info.hot_spot_num);
                    }

                    if (fair_i != this->info.hot_spot_num) {
                        ++terrain_fairness_zones_visited_count;
                        terrain_fairness_zones_visited[fair_i] = 1;
                        this->remove_area_from_lists(y, x, base_area);

                        this->map_row_offset[x][y].terrain_type =
                            (uchar)info_line.terrain_type;

                        if (y > 0) {
                            this->push_stack(*stack_ptr, y - 1, x, 0.0f, 0.0f);
                        }
                        if (x > 0) {
                            this->push_stack(*stack_ptr, y, x - 1, 0.0f, 0.0f);
                        }
                        if (y < this->map_width - 1) {
                            this->push_stack(*stack_ptr, y + 1, x, 0.0f, 0.0f);
                        }
                        if (x < this->map_height - 1) {
                            this->push_stack(*stack_ptr, y, x + 1, 0.0f, 0.0f);
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
            base_area = clump_size;
            do {
                if (in_zone < info_line.terrain_size && this->pop_stack(*stack_ptr, y, x, cost) != 0) {
                    done = 0;

                    if (info_line.avoid_hot_spots == 0 || this->search_map_rows[x][y] <=
                        (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 454) * 100) / 0x7fff) {
                        RGE_Tile* tile = &this->map_row_offset[x][y];
                        long ok = this->check_terrain((uchar)info_line.terrain_type, y, x, info_line.spacing,
                                                      (uchar)info_line.base_terrain_type);
                        if ((tile->terrain_type & 0x1f) == info_line.base_terrain_type && ok > 0) {
                            score = this->fig_chance(ok, y, x, info_line.clumpiness_factor);
                            if (info_line.avoid_hot_spots != 0) {
                                index1 = this->search_map_rows[x][y];
                                score += (float)index1;
                            }

                            tile->terrain_type = (uchar)info_line.terrain_type;

                            if (y > 0 && (tile[-1].terrain_type & 0x1f) == info_line.base_terrain_type) {
                                index1 = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 469) * 100) /
                                    0x7fff;
                                this->push_stack(*stack_ptr, y - 1, x, 0.0f, (float)index1 + score);
                            }
                            if (y < max_y && (tile[1].terrain_type & 0x1f) == info_line.base_terrain_type) {
                                index1 = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 471) * 100) /
                                    0x7fff;
                                this->push_stack(*stack_ptr, y + 1, x, 0.0f, (float)index1 + score);
                            }
                            if (x > 0 && (tile[-this->map_width].terrain_type & 0x1f) == info_line.base_terrain_type) {
                                index1 = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 473) * 100) /
                                    0x7fff;
                                this->push_stack(*stack_ptr, y, x - 1, 0.0f, (float)index1 + score);
                            }
                            if (x < max_x && (tile[this->map_width].terrain_type & 0x1f) == info_line.base_terrain_type) {
                                index1 = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 475) * 100) /
                                    0x7fff;
                                this->push_stack(*stack_ptr, y, x + 1, 0.0f, (float)index1 + score);
                            }
                            ++in_zone;
                        }
                    }
                }
                ++stack_ptr;
                --base_area;
            } while (base_area != 0);
        }
    } while (done == 0);

    if (info_line.clumps > 0) {
        stack_ptr = stack;
        base_area = info_line.clumps;
        do {
            while (this->pop_stack(*stack_ptr, y, x, cost) != 0) {
                RGE_Tile* tile = &this->map_row_offset[x][y];
                if ((y > 0 && (tile[-1].terrain_type & 0x1f) == (uchar)info_line.terrain_type && y < max_y &&
                    (tile[1].terrain_type & 0x1f) == (uchar)info_line.terrain_type) || (x > 0 &&
                    (tile[-this->map_width].terrain_type & 0x1f) == (uchar)info_line.terrain_type && x > max_x &&
                    (tile[this->map_width].terrain_type & 0x1f) == (uchar)info_line.terrain_type)) {
                    tile->terrain_type = (uchar)info_line.terrain_type;
                }
            }
            ++stack_ptr;
            --base_area;
        } while (base_area != 0);
    }

    for (cleanup_i = 0; cleanup_i < 99; ++cleanup_i) {
        this->deinit_stack(stack[cleanup_i]);
    }
    return 1;
}
