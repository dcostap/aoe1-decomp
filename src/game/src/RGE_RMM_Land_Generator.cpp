#include "../include/RGE_RMM_Land_Generator.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Tile.h"
#include "../include/debug_helpers.h"

#include <string.h>

RGE_RMM_Land_Generator::RGE_RMM_Land_Generator(
    RGE_Map* param_1,
    RGE_Random_Map_Module* param_2,
    RGE_Land_Info* param_3)
    // Fully verified. Source of truth: rmm_land.cpp.decomp @ 0x00485200
    : RGE_Random_Map_Module(param_1, param_2, 1) {
    this->schedule = 1.0f;
    memset(&this->info, 0, sizeof(this->info));
    if (param_3 != nullptr) {
        memcpy(&this->info, param_3, sizeof(this->info));
    }
}

uchar RGE_RMM_Land_Generator::generate() {
    // Fully verified. Source of truth: rmm_land.cpp.decomp @ 0x00485240
    if (this->map == nullptr || this->search_map == nullptr || this->search_map_rows == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }

    this->clear_stack();
    memset(this->search_map, (uchar)this->info.land_num, (size_t)this->map_width * (size_t)this->map_height);

    this->map->set_terrain(
        nullptr,
        nullptr,
        0,
        0,
        (short)(this->map_width - 1),
        (short)(this->map_height - 1),
        this->info.base_terrain,
        1,
        0);

    this->base_land_generate();
    this->map->clean_terrain(0, 0, this->map_width, this->map_height, this->info.base_terrain);
    return 1;
}

static long rmm_land_rand_scaled(long scale, int line_no) {
    if (scale <= 0) {
        return 0;
    }
    long r = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_land.cpp", line_no);
    return (long)(((long long)r * (long long)scale) / 0x7fffLL);
}

uchar RGE_RMM_Land_Generator::check_terrain_and_zone(
    uchar param_1,
    uchar param_2,
    long param_3,
    long param_4) {
    // Fully verified. Source of truth: rmm_land.cpp.decomp @ 0x004852D0
    (void)param_1;
    if (this->search_map_rows == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }
    if (param_2 >= 99 || param_4 < 0 || param_3 < 0 || param_4 >= this->map_height || param_3 >= this->map_width) {
        return 0;
    }

    if ((uint)this->search_map_rows[param_4][param_3] != (uint)this->info.land_num) {
        return 0;
    }

    RGE_Land_Info_Line* land = &this->info.land[param_2];
    long area = land->area;
    long octogon_y1 = 0;
    long cx0 = param_3 - 2;
    long cx1 = param_3 + 2;
    long y0 = param_4 - 2;
    long y1 = param_4 + 2;

    long row0 = param_4 - area;
    long row1 = param_4 + area;
    uchar zone = land->zone;

    for (long row = row0; row <= row1; ++row) {
        if (row < 0) {
            if (row > y0) {
                octogon_y1 = octogon_y1 + 5;
            }
            continue;
        }
        if (row >= this->map_height) {
            if (row < y1) {
                octogon_y1 = octogon_y1 + 5;
            }
            continue;
        }

        for (long col = param_3 - area; col <= param_3 + area; ++col) {
            if (col < 0) {
                if (col > cx0) {
                    octogon_y1 = octogon_y1 + 1;
                }
                continue;
            }
            if (col >= this->map_width) {
                if (col < cx1) {
                    octogon_y1 = octogon_y1 + 1;
                }
                continue;
            }

            uchar cur_zone = this->search_map_rows[row][col];
            if (cur_zone == zone) {
                if (row >= y0 && row <= y1 && col >= cx0 && col <= cx1) {
                    octogon_y1 = octogon_y1 + 1;
                }
            } else if ((long)(uint)cur_zone < this->info.land_num) {
                return 0;
            }
        }
    }

    return (uchar)octogon_y1;
}

uchar RGE_RMM_Land_Generator::chance(long param_1, long param_2, long param_3) {
    // Fully verified. Source of truth: rmm_land.cpp.decomp @ 0x00485480
    if (param_3 < 0 || param_3 >= 99) {
        return 0;
    }

    RGE_Land_Info_Line* land = &this->info.land[param_3];
    long fade = (long)land->wall_fade;
    if (fade <= 0) {
        return 0;
    }

    long wall_1 = land->wall_1_avoidance_line;
    long wall_3 = land->wall_3_avoidance_line;
    long d_left = wall_1 - param_1;
    long d_right = param_1 - wall_3;
    long major_x = (d_left > d_right) ? d_left : d_right;

    long ext_left = d_left + wall_1;
    long ext_right = d_right + (this->map_width - wall_3);
    long major_ext = (ext_left > ext_right) ? ext_left : ext_right;

    long wall_2 = land->wall_2_avoidance_line;
    long wall_4 = land->wall_4_avoidance_line;
    long d_top;
    long d_bottom;
    if (major_ext < 1) {
        d_top = wall_2 - param_2;
        d_bottom = param_2 - wall_4;
    } else {
        d_bottom = major_ext - wall_4 + param_2;
        d_top = wall_2 + major_ext - param_2;
    }

    long major_y = (d_bottom > d_top) ? d_bottom : d_top;
    if (major_x < 0) major_x = 0;
    if (major_y < 0) major_y = 0;

    long v = (major_x + major_y) * fade;
    if (v >= 100) {
        return 0x65;
    }
    return (uchar)v;
}

uchar RGE_RMM_Land_Generator::base_land_generate() {
    // Fully verified. Source of truth: rmm_land.cpp.decomp @ 0x00485520
    if (this->map == nullptr || this->map_row_offset == nullptr || this->search_map_rows == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }

    long land_size[99];
    memset(land_size, 0, sizeof(land_size));
    Map_Stack stack[99];

    const long land_num = this->info.land_num;
    const long max_x = this->map_width - 1;
    const long max_y = this->map_height - 1;

    for (long i = 0; i < land_num && i < 99; ++i) {
        this->init_stack(&stack[i]);

        RGE_Land_Info_Line* land = &this->info.land[i];
        long x0 = land->x - land->base_size;
        long y0 = land->y - land->base_size;
        long x1 = land->x + land->base_size;
        long y1 = land->y + land->base_size;

        if (x0 < 0) x0 = 0;
        if (y0 < 0) y0 = 0;
        if (x1 > max_x) x1 = max_x;
        if (y1 > max_y) y1 = max_y;

        this->map->set_terrain(
            nullptr,
            nullptr,
            (short)x0,
            (short)y0,
            (short)x1,
            (short)y1,
            (uchar)land->terrain_type,
            1,
            0);

        uchar zone = land->zone;
        long zone_index = (long)(uint)zone + 1;
        if (zone_index >= 0 && zone_index < 99) {
            land_size[zone_index] = ((x1 - x0) + 1) * ((y1 - y0) + 1);
        }

        for (long y = y0; y <= y1; ++y) {
            for (long x = x0; x <= x1; ++x) {
                this->search_map_rows[y][x] = zone;
            }
        }

        float seed_cost = (float)i;
        if (x0 > 0) {
            for (long y = y0; y <= y1; ++y) {
                this->push_stack(&stack[i], x0 - 1, y, seed_cost, 0.0f);
            }
        }
        if (y0 > 0) {
            for (long x = x0; x <= x1; ++x) {
                this->push_stack(&stack[i], x, y0 - 1, seed_cost, 0.0f);
            }
        }
        if (x1 < max_x) {
            for (long y = y0; y <= y1; ++y) {
                this->push_stack(&stack[i], x1 + 1, y, seed_cost, 0.0f);
            }
        }
        if (y1 < max_y) {
            for (long x = x0; x <= x1; ++x) {
                this->push_stack(&stack[i], x, y1 + 1, seed_cost, 0.0f);
            }
        }
    }

    for (;;) {
        uchar loop_done = 1;
        for (long i = 0; i < land_num && i < 99; ++i) {
            RGE_Land_Info_Line* land = &this->info.land[i];
            long area_index = i + 1;
            if (area_index < 0 || area_index >= 99) {
                continue;
            }

            if (land_size[area_index] < land->land_size) {
                long x = 0;
                long y = 0;
                float pop_cost = 0.0f;
                if (this->pop_stack(&stack[i], &x, &y, &pop_cost) != nullptr) {
                    loop_done = 0;

                    uchar wall_chance = this->chance(x, y, i);
                    if ((long)(uint)wall_chance > rmm_land_rand_scaled(100, 0x12b)) {
                        this->search_map_rows[y][x] = 0xff;
                    } else {
                        RGE_Tile* tile = &this->map_row_offset[y][x];
                        uchar terrain = (uchar)land->terrain_type;
                        uchar zone_score = this->check_terrain_and_zone(terrain, (uchar)i, x, y);
                        if ((long)(uint)this->search_map_rows[y][x] == this->info.land_num && zone_score != 0) {
                            tile->terrain_type = (uchar)(((terrain ^ tile->terrain_type) & 0x1f) ^ tile->terrain_type);
                            this->search_map_rows[y][x] = land->zone;

                            long zone_penalty = (long)(uint)zone_score * land->clumpiness_factor;
                            if (x > 0 && (long)(uint)this->search_map_rows[y][x - 1] == this->info.land_num) {
                                float score = (float)(rmm_land_rand_scaled(100, 0x138) - zone_penalty + 0xfa);
                                this->push_stack(&stack[i], x - 1, y, 0.0f, score);
                            }
                            if (x < max_x && (long)(uint)this->search_map_rows[y][x + 1] == this->info.land_num) {
                                float score = (float)(rmm_land_rand_scaled(100, 0x13b) - zone_penalty + 0xfa);
                                this->push_stack(&stack[i], x + 1, y, 0.0f, score);
                            }
                            if (y > 0 && (long)(uint)this->search_map_rows[y - 1][x] == this->info.land_num) {
                                float score = (float)(rmm_land_rand_scaled(100, 0x13e) - zone_penalty + 0xfa);
                                this->push_stack(&stack[i], x, y - 1, 0.0f, score);
                            }
                            if (y < max_y && (long)(uint)this->search_map_rows[y + 1][x] == this->info.land_num) {
                                float score = (float)(rmm_land_rand_scaled(100, 0x141) - zone_penalty + 0xfa);
                                this->push_stack(&stack[i], x, y + 1, 0.0f, score);
                            }

                            land_size[area_index] = land_size[area_index] + 1;
                        }
                    }
                }
            }
        }

        if (loop_done != 0) {
            break;
        }
    }

    for (long i = 0; i < land_num && i < 99; ++i) {
        RGE_Land_Info_Line* land = &this->info.land[i];
        uchar zone = land->zone;
        uchar terrain = (uchar)land->terrain_type;

        long x = 0;
        long y = 0;
        float pop_cost = 0.0f;
        Map_Stack* node = this->pop_stack(&stack[i], &x, &y, &pop_cost);
        while (node != nullptr) {
            if (((x > 0 && this->search_map_rows[y][x - 1] == zone) &&
                 (x < max_x && this->search_map_rows[y][x + 1] == zone)) ||
                ((y > 0 && this->search_map_rows[y - 1][x] == zone) &&
                 (y < max_y && this->search_map_rows[y + 1][x] == zone))) {
                RGE_Tile* tile = &this->map_row_offset[y][x];
                tile->terrain_type = (uchar)(((terrain ^ tile->terrain_type) & 0x1f) ^ tile->terrain_type);
            }

            node = this->pop_stack(&stack[i], &x, &y, &pop_cost);
        }
    }

    for (long i = 0; i < land_num && i < 99; ++i) {
        this->deinit_stack(&stack[i]);
    }
    return 1;
}

