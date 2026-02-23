#include "../include/RGE_RMM_Elevation_Generator.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Tile.h"
#include "../include/debug_helpers.h"

#include <math.h>
#include <string.h>

RGE_RMM_Elevation_Generator::RGE_RMM_Elevation_Generator(
    RGE_Map* param_1,
    RGE_Random_Map_Module* param_2,
    RGE_Elevation_Info* param_3)
    // Fully verified. Source of truth: rmm_elev.cpp.decomp @ 0x004846C0
    : RGE_Random_Map_Module(param_1, param_2, 1) {
    this->schedule = 1.5f;
    memset(&this->info, 0, sizeof(this->info));
    if (param_3 != nullptr) {
        memcpy(&this->info, param_3, sizeof(this->info));
    }
}

uchar RGE_RMM_Elevation_Generator::generate() {
    // Fully verified. Source of truth: rmm_elev.cpp.decomp @ 0x00484700
    if (this->map == nullptr || this->map_row_offset == nullptr || this->search_map == nullptr || this->search_map_rows == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }

    this->clear_stack();

    if (this->info.elevation_num > 0) {
        uchar base_elevation = (uchar)this->info.elevation[0].base_elevation;
        for (long y = 0; y < this->map_height; ++y) {
            for (long x = 0; x < this->map_width; ++x) {
                this->map_row_offset[y][x].height = base_elevation;
            }
        }
    }

    this->generate_modifiers();

    for (long i = 0; i < this->info.elevation_num; ++i) {
        RGE_Elevation_Info_Line line;
        memcpy(&line, &this->info.elevation[i], sizeof(line));
        this->base_elevation_generate(line);
        if (this->map != nullptr) {
            this->map->clean_elevation(0, 0, this->map_width - 1, this->map_height - 1, 8);
        }
    }

    return 1;
}

uchar RGE_RMM_Elevation_Generator::check_start_elevation(
    long param_1,
    long param_2,
    uchar param_3,
    uchar param_4,
    uchar param_5) {
    // Fully verified. Source of truth: rmm_elev.cpp.decomp @ 0x004847C0
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }

    long r = (long)(uint)param_5;
    long x0 = param_1 - r;
    long y0 = param_2 - r;
    long x1 = param_1 + r;
    long y1 = param_2 + r;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= this->map_width) x1 = this->map_width - 1;
    if (y1 >= this->map_height) y1 = this->map_height - 1;

    for (long y = y0; y <= y1; ++y) {
        for (long x = x0; x <= x1; ++x) {
            RGE_Tile* t = &this->map_row_offset[y][x];
            if (param_3 != 0xff && (uchar)(t->terrain_type & 0x1f) != param_3) {
                return 0;
            }
            if (t->height < param_4) {
                return 0;
            }
        }
    }

    return 1;
}

uchar RGE_RMM_Elevation_Generator::check_elevation(
    uchar param_1,
    long param_2,
    long param_3,
    long param_4,
    uchar param_5,
    uchar param_6) {
    // Fully verified. Source of truth: rmm_elev.cpp.decomp @ 0x004848A0
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }

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
                RGE_Tile* t = &this->map_row_offset[y][x];
                if (param_5 != 0xff && (uchar)(t->terrain_type & 0x1f) != param_5) {
                    return 0;
                }
                if (t->height < param_6) {
                    return 0;
                }
            }
        }
    }

    uchar count = 0;
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
            if (this->map_row_offset[y][x].height == param_1) {
                count = (uchar)(count + 1);
            }
        }
    }

    return count;
}

void RGE_RMM_Elevation_Generator::generate_modifiers() {
    // Fully verified. Source of truth: rmm_elev.cpp.decomp @ 0x00484A40
    if (this->search_map == nullptr || this->search_map_rows == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    memset(this->search_map, 0, (size_t)this->map_width * (size_t)this->map_height);
    for (long y = 0; y < this->map_height; ++y) {
        for (long x = 0; x < this->map_width; ++x) {
            long modifier = 0;
            for (long i = 0; i < this->info.hot_spot_num; ++i) {
                RGE_Elevation_Hot_Spots* hot = &this->info.hot_spots[i];
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
            if (modifier > 100) modifier = 0x65;
            this->search_map_rows[y][x] = (uchar)modifier;
        }
    }
}

float RGE_RMM_Elevation_Generator::fig_chance(long param_1, long param_2, long param_3) {
    // Fully verified. Source of truth: rmm_elev.cpp.decomp @ 0x00484B30
    (void)param_2;
    (void)param_3;
    return (float)(-15 * param_1 + 250);
}

long RGE_RMM_Elevation_Generator::count_map_tiles(uchar param_1) {
    // Fully verified. Source of truth: rmm_elev.cpp.decomp @ 0x00484B50
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

static long rmm_elev_rand_scaled(long scale, int line_no) {
    if (scale <= 0) {
        return 0;
    }
    long r = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_elev.cpp", line_no);
    return (long)(((long long)r * (long long)scale) / 0x7fffLL);
}

void RGE_RMM_Elevation_Generator::link_stack_randomly(Map_Stack* param_1) {
    // Fully verified. Source of truth: rmm_elev.cpp.decomp @ 0x00484B90
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

    long random_count = map_area / 16;
    for (long i = 0; i < random_count; ++i) {
        long x = 0;
        long y = 0;
        if (this->map_width > 1) {
            x = rmm_elev_rand_scaled(this->map_width - 1, 0xfa);
        }
        if (this->map_height > 1) {
            y = rmm_elev_rand_scaled(this->map_height - 1, 0xfb);
        }
        this->add_stack_node(param_1, &this->stack_offsets[y][x]);
    }
}

void RGE_RMM_Elevation_Generator::remove_area_from_lists(long param_1, long param_2, long param_3) {
    // Fully verified. Source of truth: rmm_elev.cpp.decomp @ 0x00484C80
    long x0 = param_1 - param_3;
    long y0 = param_2 - param_3;
    long x1 = param_1 + param_3;

    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= this->map_width) x1 = this->map_width - 1;

    // NOTE: The source-of-truth decomp/asm uses x1 as the upper bound for both axes.
    for (long y = y0; y <= x1; ++y) {
        for (long x = x0; x <= x1; ++x) {
            this->remove_stack_node(&this->stack_offsets[y][x]);
        }
    }
}

uchar RGE_RMM_Elevation_Generator::base_elevation_generate(RGE_Elevation_Info_Line param_1) {
    // Fully verified. Source of truth: rmm_elev.cpp.decomp @ 0x00484D00
    if (this->map_row_offset == nullptr || this->search_map_rows == nullptr || this->stack_offsets == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }

    Map_Stack stack[99];
    Map_Stack loc_stack;
    long clumps = param_1.clumps;
    if (clumps > 99) clumps = 99;
    if (clumps < 0) clumps = 0;

    for (long i = 0; i < clumps; ++i) {
        this->init_stack(&stack[i]);
    }

    this->init_stack(&loc_stack);
    loc_stack.x = this->map_width - 1;
    loc_stack.prev = nullptr;
    if (clumps > 0) {
        stack[0].x = 0;
    }
    this->link_stack_randomly(&loc_stack);

    long remove_size = 2;
    if (param_1.clumps > 0) {
        long seed = (long)sqrt((double)param_1.elevation_size / (double)param_1.clumps);
        remove_size = seed / 2;
        if (remove_size < 2) {
            remove_size = 2;
        }
    }

    long seed_count = 0;
    float placed = 0.0f;
    long max_y = this->map_height - 1;
    if (clumps > 0) {
        Map_Stack* seed_stack = &stack[0];
        while (seed_count < clumps) {
            long tx = 0;
            long ty = 0;
            float pop_cost = 0.0f;
            if (this->pop_stack(&loc_stack, &tx, &ty, &pop_cost) == nullptr) {
                break;
            }

            if (this->search_map_rows[ty][tx] == 0 &&
                this->check_start_elevation(
                    tx,
                    ty,
                    (uchar)param_1.base_terrain_type,
                    (uchar)param_1.base_elevation,
                    (uchar)param_1.spacing) != 0) {
                this->remove_area_from_lists(tx, ty, remove_size);
                this->map_row_offset[ty][tx].height = (uchar)param_1.elevation;

                if (tx > 0) {
                    this->push_stack(seed_stack, tx - 1, ty, 0.0f, 0.0f);
                }
                if (ty > 0) {
                    this->push_stack(seed_stack, tx, ty - 1, 0.0f, 0.0f);
                }
                if (tx < this->map_width - 1) {
                    this->push_stack(seed_stack, tx + 1, ty, 0.0f, 0.0f);
                }
                if (ty < this->map_height - 1) {
                    this->push_stack(seed_stack, tx, ty + 1, 0.0f, 0.0f);
                }

                placed = placed + 1.0f;
                seed_count = seed_count + 1;
                seed_stack = seed_stack + 1;
            }
        }
    }

    for (;;) {
        uchar loop_done = 1;
        if (clumps > 0) {
            Map_Stack* cur_stack = &stack[0];
            long stack_count = clumps;
            while (stack_count > 0) {
                if ((long)placed < param_1.elevation_size) {
                    long tx = 0;
                    long ty = 0;
                    float pop_cost = 0.0f;
                    if (this->pop_stack(cur_stack, &tx, &ty, &pop_cost) != nullptr) {
                        loop_done = 0;
                        uchar* modifier = &this->search_map_rows[ty][tx];
                        if (rmm_elev_rand_scaled(100, 0x171) < (long)(uint)*modifier) {
                            *modifier = 0x65;
                        } else {
                            uchar touch = this->check_elevation(
                                (uchar)param_1.elevation,
                                tx,
                                ty,
                                param_1.spacing,
                                (uchar)param_1.base_terrain_type,
                                (uchar)param_1.base_elevation);
                            if (this->map_row_offset[ty][tx].height == (uchar)param_1.base_elevation && touch != 0) {
                                float chance = this->fig_chance((long)(uint)touch, tx, ty);
                                this->map_row_offset[ty][tx].height = (uchar)param_1.elevation;

                                if (tx > 0 && this->map_row_offset[ty][tx - 1].height == (uchar)param_1.base_elevation) {
                                    float score = (float)rmm_elev_rand_scaled(100, 0x17d) + chance;
                                    this->push_stack(cur_stack, tx - 1, ty, 0.0f, score);
                                }
                                if (tx < loc_stack.x && this->map_row_offset[ty][tx + 1].height == (uchar)param_1.base_elevation) {
                                    float score = (float)rmm_elev_rand_scaled(100, 0x17f) + chance;
                                    this->push_stack(cur_stack, tx + 1, ty, 0.0f, score);
                                }
                                if (ty > 0 && this->map_row_offset[ty - 1][tx].height == (uchar)param_1.base_elevation) {
                                    float score = (float)rmm_elev_rand_scaled(100, 0x181) + chance;
                                    this->push_stack(cur_stack, tx, ty - 1, 0.0f, score);
                                }
                                if (ty < max_y && this->map_row_offset[ty + 1][tx].height == (uchar)param_1.base_elevation) {
                                    float score = (float)rmm_elev_rand_scaled(100, 0x183) + chance;
                                    this->push_stack(cur_stack, tx, ty + 1, 0.0f, score);
                                }

                                placed = placed + 1.0f;
                            }
                        }
                    }
                }

                cur_stack = cur_stack + 1;
                stack_count = stack_count - 1;
            }
        }

        if (loop_done != 0) {
            break;
        }
    }

    for (long i = 0; i < clumps; ++i) {
        this->deinit_stack(&stack[i]);
    }
    return 1;
}

