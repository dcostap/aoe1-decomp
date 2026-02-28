#include "../include/RGE_RMM_Terrain_Generator.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Tile.h"
#include "../include/RGE_Zone_Map.h"
#include "../include/RGE_Zone_Map_List.h"
#include "../include/debug_helpers.h"

#include <math.h>
#include <string.h>

RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator(
    RGE_Map* param_1,
    RGE_Random_Map_Module* param_2,
    RGE_Terrain_Info* param_3)
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x004888E0
    : RGE_Random_Map_Module(param_1, param_2, 1) {
    this->schedule = 2.0f;
    memset(&this->info, 0, sizeof(this->info));
    if (param_3 != nullptr) {
        memcpy(&this->info, param_3, sizeof(this->info));
    }
    this->map_zone = nullptr;
}

uchar RGE_RMM_Terrain_Generator::generate() {
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x00488920
    this->generate_modifiers();

    float terrain_table[99];
    terrain_table[0] = 0.0f;
    for (int i = 1; i < 99; ++i) {
        terrain_table[i] = terrain_table[0];
        terrain_table[0] = terrain_table[0] + 1.0f;
    }

    long index = this->map->map_zones->create_zone_map(terrain_table + 1, 99);
    this->map_zone = this->map->map_zones->get_zone_map(index);

    for (long i = 0; i < this->info.terrain_num; ++i) {
        RGE_Terrain_Info_Line line;
        memcpy(&line, &this->info.terrain[i], sizeof(line));
        this->base_terrain_generate(line);
    }

    this->check_borders();
    return 1;
}

static long rmm_terr_rand_scaled(long scale, int line_no) {
    if (scale <= 0) {
        return 0;
    }
    long r = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", line_no);
    return (long)(((long long)r * (long long)scale) / 0x7fffLL);
}

uchar RGE_RMM_Terrain_Generator::water(uchar param_1) {
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x004889D0
    if (param_1 == 1) {
        return 1;
    }
    if (param_1 == 4) {
        return 1;
    }
    return (uchar)(param_1 == 0x16);
}

void RGE_RMM_Terrain_Generator::check_borders() {
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x004889F0
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    const long max_x = this->map_width - 1;
    const long max_y = this->map_height - 1;

    for (long y = 0; y < this->map_height; ++y) {
        for (long x = 0; x < this->map_width; ++x) {
            RGE_Tile* tile = &this->map_row_offset[y][x];
            if (this->water((uchar)(tile->terrain_type & 0x1f)) != 0) {
                continue;
            }

            int near_water = 0;
            if (y > 0) {
                if (this->water((uchar)(this->map_row_offset[y - 1][x].terrain_type & 0x1f)) != 0) near_water = 1;
                if (x > 0 && this->water((uchar)(this->map_row_offset[y - 1][x - 1].terrain_type & 0x1f)) != 0) near_water = 1;
                if (x < max_x && this->water((uchar)(this->map_row_offset[y - 1][x + 1].terrain_type & 0x1f)) != 0) near_water = 1;
            }
            if (y < max_y) {
                if (this->water((uchar)(this->map_row_offset[y + 1][x].terrain_type & 0x1f)) != 0) near_water = 1;
                if (x > 0 && this->water((uchar)(this->map_row_offset[y + 1][x - 1].terrain_type & 0x1f)) != 0) near_water = 1;
                if (x < max_x && this->water((uchar)(this->map_row_offset[y + 1][x + 1].terrain_type & 0x1f)) != 0) near_water = 1;
            }
            if (x > 0 && this->water((uchar)(this->map_row_offset[y][x - 1].terrain_type & 0x1f)) != 0) near_water = 1;
            if (x < max_x && this->water((uchar)(this->map_row_offset[y][x + 1].terrain_type & 0x1f)) != 0) near_water = 1;

            if (near_water != 0) {
                tile->terrain_type = 2;
            }
        }
    }
}

uchar RGE_RMM_Terrain_Generator::check_terrain(
    uchar param_1,
    long param_2,
    long param_3,
    long param_4,
    uchar param_5) {
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x00488B90
    if (this->map_row_offset == nullptr || this->map == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }

    uchar pass_terrain = this->map->terrain_types[param_5 & 0x1f].passable_terrain;
    long index1 = 1;

    if (param_4 > 0) {
        long x0 = param_2 - param_4;
        long y0 = param_3 - param_4;
        long x1 = param_2 + param_4;
        long y1 = param_3 + param_4;
        if (x0 < 0) x0 = 0;
        if (y0 < 0) y0 = 0;
        if (x1 >= this->map_width) x1 = this->map_width - 1;
        if (y1 >= this->map_height) y1 = this->map_height - 1;

        for (long y = y0; y <= y1; ++y) {
            for (long x = x0; x <= x1; ++x) {
                uchar tt = (uchar)(this->map_row_offset[y][x].terrain_type & 0x1f);
                if (tt != param_5 && tt != pass_terrain && tt != param_1) {
                    return 0;
                }
            }
        }
    }

    long x0 = param_2 - 2;
    long y0 = param_3 - 2;
    long x1 = param_2 + 2;
    long y1 = param_3 + 2;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= this->map_width) x1 = this->map_width - 1;
    if (y1 >= this->map_height) y1 = this->map_height - 1;

    for (long y = y0; y <= y1; ++y) {
        for (long x = x0; x <= x1; ++x) {
            if ((this->map_row_offset[y][x].terrain_type & 0x1f) == param_1) {
                index1 = index1 + 1;
            }
        }
    }

    return (uchar)index1;
}

void RGE_RMM_Terrain_Generator::generate_modifiers() {
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x00488D50
    if (this->search_map == nullptr || this->search_map_rows == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    memset(this->search_map, 0, (size_t)this->map_width * (size_t)this->map_height);

    for (long y = 0; y < this->map_height; ++y) {
        for (long x = 0; x < this->map_width; ++x) {
            long modifier = 0;
            for (long i = 0; i < this->info.hot_spot_num; ++i) {
                RGE_Terrain_Hot_Spots* hot = &this->info.hot_spots[i];
                long dx = x - hot->x;
                long dy = y - hot->y;
                if (dx < 0) dx = -dx;
                if (dy < 0) dy = -dy;
                long dist = (long)sqrt((double)(dx * dx + dy * dy));
                long delta = hot->radius - dist;
                if (delta > 0) {
                    modifier = modifier + hot->fade * delta;
                }
            }
            if (modifier > 100) modifier = 101;
            this->search_map_rows[y][x] = (uchar)modifier;
        }
    }
}

float RGE_RMM_Terrain_Generator::fig_chance(long param_1, long param_2, long param_3, long param_4) {
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x00488E40
    (void)param_2;
    (void)param_3;
    return (float)(250 - param_4 * param_1);
}

long RGE_RMM_Terrain_Generator::count_map_tiles(uchar param_1) {
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x00488E60
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }
    long count = 0;
    for (long y = 0; y < this->map_height; ++y) {
        for (long x = 0; x < this->map_width; ++x) {
            if ((this->map_row_offset[y][x].terrain_type & 0x1f) == param_1) {
                count = count + 1;
            }
        }
    }
    return count;
}

void RGE_RMM_Terrain_Generator::link_stack_randomly(Map_Stack* param_1, uchar param_2) {
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x00488EA0
    (void)param_2;
    if (param_1 == nullptr || this->stack_array == nullptr || this->stack_offsets == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    long map_area = this->map_width * this->map_height;
    if (map_area <= 0) {
        return;
    }

    Map_Stack* first = this->stack_array;
    Map_Stack* last = this->stack_array + map_area - 1;

    param_1->next = first;
    first->prev = param_1;

    if (map_area > 1) {
        first->next = first + 1;
        last->next = nullptr;
        last->prev = last - 1;
        for (Map_Stack* it = first + 1; it < last; ++it) {
            it->next = it + 1;
            it->prev = it - 1;
        }
    } else {
        first->next = nullptr;
    }

    long random_count = map_area / 8;
    for (long i = 0; i < random_count; ++i) {
        long x = 0;
        long y = 0;
        if (this->map_width > 1) {
            x = rmm_terr_rand_scaled(this->map_width - 1, 0x10f);
        }
        if (this->map_height > 1) {
            y = rmm_terr_rand_scaled(this->map_height - 1, 0x110);
        }
        this->add_stack_node(param_1, &this->stack_offsets[y][x]);
    }
}

void RGE_RMM_Terrain_Generator::remove_area_from_lists(long param_1, long param_2, long param_3) {
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x00488F90
    if (this->stack_offsets == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    long x0 = param_1 - param_3;
    long y0 = param_2 - param_3;
    long x1 = param_1 + param_3;
    long y1 = param_2 + param_3;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= this->map_width) x1 = this->map_width - 1;
    if (y1 >= this->map_height) y1 = this->map_height - 1;

    for (long y = y0; y <= y1; ++y) {
        for (long x = x0; x <= x1; ++x) {
            this->remove_stack_node(&this->stack_offsets[y][x]);
        }
    }
}

uchar RGE_RMM_Terrain_Generator::base_terrain_generate(RGE_Terrain_Info_Line param_1) {
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x00489030
    if (this->map_row_offset == nullptr || this->search_map_rows == nullptr || this->stack_offsets == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }

    Map_Stack stack[99];
    uchar terrain_fairness_zones[99];
    uchar terrain_fairness_zones_visited[99];
    memset(terrain_fairness_zones, 0, sizeof(terrain_fairness_zones));
    memset(terrain_fairness_zones_visited, 0, sizeof(terrain_fairness_zones_visited));

    float in_zone = 0.0f;
    float fairness_hit = 0.0f;
    long clump_size = 0;
    long max_x = this->map_width - 1;
    long max_y = this->map_height - 1;

    if (param_1.avoid_hot_spots == 2 && this->info.hot_spot_num > 0 && this->map_zone != nullptr) {
        for (long i = 0; i < this->info.hot_spot_num && i < 99; ++i) {
            RGE_Terrain_Hot_Spots* hot = &this->info.hot_spots[i];
            terrain_fairness_zones[i] = this->map_zone->get_zone_info(hot->x, hot->y);
            terrain_fairness_zones_visited[i] = 0;
        }
    }

    for (int i = 0; i < 99; ++i) {
        this->init_stack(&stack[i]);
    }

    Map_Stack loc_stack;
    this->init_stack(&loc_stack);

    uchar base_terrain = (uchar)param_1.base_terrain_type;
    uchar terrain_type = (uchar)param_1.terrain_type;
    this->link_stack_randomly(&loc_stack, base_terrain);

    long clear_radius = 2;
    if (param_1.clumps > 0) {
        clear_radius = (long)(sqrt((double)param_1.terrain_size / (double)param_1.clumps) * 2.0);
        if (clear_radius < 2) {
            clear_radius = 2;
        }
    }

    if (param_1.clumps > 0) {
        Map_Stack* clump_stack = &stack[0];
        while (clump_size < param_1.clumps) {
            long tx = 0;
            long ty = 0;
            float pop_cost = 0.0f;
            if (this->pop_stack(&loc_stack, &tx, &ty, &pop_cost) == nullptr) {
                break;
            }

            RGE_Tile* tile = &this->map_row_offset[ty][tx];
            if (((tile->terrain_type & 0x1f) == base_terrain) &&
                (this->check_terrain(terrain_type, tx, ty, param_1.spacing, base_terrain) != 0) &&
                (param_1.avoid_hot_spots == 0 || this->search_map_rows[ty][tx] == 0)) {
                this->remove_area_from_lists(tx, ty, clear_radius);
                tile->terrain_type = (uchar)(((terrain_type ^ tile->terrain_type) & 0x1f) ^ tile->terrain_type);

                if (tx > 0) {
                    this->push_stack(clump_stack, tx - 1, ty, 0.0f, 0.0f);
                }
                if (ty > 0) {
                    this->push_stack(clump_stack, tx, ty - 1, 0.0f, 0.0f);
                }
                if (tx < max_x) {
                    this->push_stack(clump_stack, tx + 1, ty, 0.0f, 0.0f);
                }
                if (ty < max_y) {
                    this->push_stack(clump_stack, tx, ty + 1, 0.0f, 0.0f);
                }

                in_zone = in_zone + 1.0f;
                clump_size = clump_size + 1;
                clump_stack = clump_stack + 1;

                if (param_1.avoid_hot_spots == 2 && this->map_zone != nullptr) {
                    uchar zone = this->map_zone->get_zone_info(tx, ty);
                    for (long i = 0; i < this->info.hot_spot_num && i < 99; ++i) {
                        if (terrain_fairness_zones[i] == zone && terrain_fairness_zones_visited[i] == 0) {
                            terrain_fairness_zones_visited[i] = 1;
                            fairness_hit = fairness_hit + 1.0f;
                        }
                    }
                }
            }
        }
    }

    if (param_1.avoid_hot_spots == 2 && (long)fairness_hit < this->info.hot_spot_num) {
        Map_Stack* clump_stack = &stack[clump_size];
        while ((long)fairness_hit < this->info.hot_spot_num) {
            long tx = 0;
            long ty = 0;
            float pop_cost = 0.0f;
            if (this->pop_stack(&loc_stack, &tx, &ty, &pop_cost) == nullptr) {
                break;
            }

            RGE_Tile* tile = &this->map_row_offset[ty][tx];
            if (((tile->terrain_type & 0x1f) == base_terrain) &&
                (this->check_terrain(terrain_type, tx, ty, param_1.spacing, base_terrain) != 0) &&
                this->search_map_rows[ty][tx] < 0x1e &&
                this->map_zone != nullptr) {
                uchar zone = this->map_zone->get_zone_info(tx, ty);
                long hit_index = this->info.hot_spot_num;
                for (long i = 0; i < this->info.hot_spot_num && i < 99; ++i) {
                    if (terrain_fairness_zones[i] == zone && terrain_fairness_zones_visited[i] == 0) {
                        hit_index = i;
                        break;
                    }
                }
                if (hit_index != this->info.hot_spot_num) {
                    fairness_hit = fairness_hit + 1.0f;
                    terrain_fairness_zones_visited[hit_index] = 1;

                    this->remove_area_from_lists(tx, ty, clear_radius);
                    tile->terrain_type = (uchar)(((terrain_type ^ tile->terrain_type) & 0x1f) ^ tile->terrain_type);

                    if (tx > 0) {
                        this->push_stack(clump_stack, tx - 1, ty, 0.0f, 0.0f);
                    }
                    if (ty > 0) {
                        this->push_stack(clump_stack, tx, ty - 1, 0.0f, 0.0f);
                    }
                    if (tx < max_x) {
                        this->push_stack(clump_stack, tx + 1, ty, 0.0f, 0.0f);
                    }
                    if (ty < max_y) {
                        this->push_stack(clump_stack, tx, ty + 1, 0.0f, 0.0f);
                    }

                    in_zone = in_zone + 1.0f;
                    clump_size = clump_size + 1;
                    clump_stack = clump_stack + 1;
                }
            }
        }
    }

    for (;;) {
        uchar loop_done = 1;
        if (clump_size > 0) {
            Map_Stack* clump_stack = &stack[0];
            long stack_count = clump_size;
            while (stack_count > 0) {
                if ((long)in_zone < param_1.terrain_size) {
                    long tx = 0;
                    long ty = 0;
                    float pop_cost = 0.0f;
                    if (this->pop_stack(clump_stack, &tx, &ty, &pop_cost) != nullptr) {
                        loop_done = 0;
                        if (param_1.avoid_hot_spots == 0 ||
                            (long)this->search_map_rows[ty][tx] <= rmm_terr_rand_scaled(100, 0x1c6)) {
                            RGE_Tile* tile = &this->map_row_offset[ty][tx];
                            uchar terrain_touch_count = this->check_terrain(terrain_type, tx, ty, param_1.spacing, base_terrain);
                            if (((tile->terrain_type & 0x1f) == base_terrain) && terrain_touch_count != 0) {
                                float chance = this->fig_chance((long)(uint)terrain_touch_count, tx, ty, param_1.clumpiness_factor);
                                if (param_1.avoid_hot_spots != 0) {
                                    chance = chance + (float)this->search_map_rows[ty][tx];
                                }

                                tile->terrain_type = (uchar)(((terrain_type ^ tile->terrain_type) & 0x1f) ^ tile->terrain_type);

                                if (tx > 0 && ((this->map_row_offset[ty][tx - 1].terrain_type & 0x1f) == base_terrain)) {
                                    float push_cost = (float)rmm_terr_rand_scaled(100, 0x1d5) + chance;
                                    this->push_stack(clump_stack, tx - 1, ty, 0.0f, push_cost);
                                }
                                if (tx < max_x && ((this->map_row_offset[ty][tx + 1].terrain_type & 0x1f) == base_terrain)) {
                                    float push_cost = (float)rmm_terr_rand_scaled(100, 0x1d7) + chance;
                                    this->push_stack(clump_stack, tx + 1, ty, 0.0f, push_cost);
                                }
                                if (ty > 0 && ((this->map_row_offset[ty - 1][tx].terrain_type & 0x1f) == base_terrain)) {
                                    float push_cost = (float)rmm_terr_rand_scaled(100, 0x1d9) + chance;
                                    this->push_stack(clump_stack, tx, ty - 1, 0.0f, push_cost);
                                }
                                if (ty < max_y && ((this->map_row_offset[ty + 1][tx].terrain_type & 0x1f) == base_terrain)) {
                                    float push_cost = (float)rmm_terr_rand_scaled(100, 0x1db) + chance;
                                    this->push_stack(clump_stack, tx, ty + 1, 0.0f, push_cost);
                                }

                                in_zone = in_zone + 1.0f;
                            }
                        }
                    }
                }

                clump_stack = clump_stack + 1;
                stack_count = stack_count - 1;
            }
        }

        if (loop_done != 0) {
            break;
        }
    }

    if (param_1.clumps > 0) {
        Map_Stack* clump_stack = &stack[0];
        long clump_num = param_1.clumps;
        while (clump_num > 0) {
            long tx = 0;
            long ty = 0;
            float pop_cost = 0.0f;
            Map_Stack* node = this->pop_stack(clump_stack, &tx, &ty, &pop_cost);
            while (node != nullptr) {
                RGE_Tile* tile = &this->map_row_offset[ty][tx];
                int fill = 0;

                if (tx > 0 &&
                    ((this->map_row_offset[ty][tx - 1].terrain_type & 0x1f) == terrain_type) &&
                    (tx < max_x) &&
                    ((this->map_row_offset[ty][tx + 1].terrain_type & 0x1f) == terrain_type)) {
                    fill = 1;
                } else if (ty > 0 &&
                           ((this->map_row_offset[ty - 1][tx].terrain_type & 0x1f) == terrain_type) &&
                           (ty < max_y) &&
                           ((this->map_row_offset[ty + 1][tx].terrain_type & 0x1f) == terrain_type)) {
                    fill = 1;
                }

                if (fill != 0) {
                    tile->terrain_type = (uchar)(((terrain_type ^ tile->terrain_type) & 0x1f) ^ tile->terrain_type);
                }

                node = this->pop_stack(clump_stack, &tx, &ty, &pop_cost);
            }

            clump_stack = clump_stack + 1;
            clump_num = clump_num - 1;
        }
    }

    for (int i = 0; i < 99; ++i) {
        this->deinit_stack(&stack[i]);
    }
    return 1;
}

