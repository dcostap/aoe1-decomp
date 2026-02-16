#include "../include/RGE_RMM_Cliffs_Generator.h"
#include "../include/RGE_Map.h"
#include "../include/debug_helpers.h"

#include <string.h>

RGE_RMM_Cliffs_Generator::RGE_RMM_Cliffs_Generator(
    RGE_Map* param_1,
    RGE_Random_Map_Module* param_2,
    RGE_Cliffs_Info param_3)
    : RGE_Random_Map_Module(param_1, param_2, 1) {
    memcpy(&this->info, &param_3, sizeof(this->info));
    this->schedule = 1.75f;
}

uchar RGE_RMM_Cliffs_Generator::generate() {
    this->setup_cliff_maps();
    (void)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_clif.cpp", 0x32);

    for (long i = 0; i < this->info.number_of_cliffs; ++i) {
        this->generate_cliff();
    }
    return 1;
}

void RGE_RMM_Cliffs_Generator::setup_cliff_maps() {
    long cliff_width = this->map_width / 3;
    long cliff_height = this->map_height / 3;

    this->clear_stack();
    this->init_stack(&this->valid_cliff_sites);

    long map_area = this->map_width * this->map_height;
    if (map_area > 0 && this->search_map != nullptr) {
        memset(this->search_map, 1, (size_t)map_area);
    }

    for (long cy = 0; cy < cliff_height; ++cy) {
        for (long cx = 0; cx < cliff_width; ++cx) {
            long terrain_height = -1;
            uchar valid_cliff_site = 1;
            uchar water_area = 0;

            long base_y = cy * 3;
            long base_x = cx * 3;
            for (long y = 0; y < 3; ++y) {
                for (long x = 0; x < 3; ++x) {
                    RGE_Tile* tile = &this->map_row_offset[base_y + y][base_x + x];
                    uchar terrain_type = (uchar)(tile->terrain_type & 0x1f);
                    if (terrain_type == 0 || terrain_type == 6) {
                        uchar h = tile->height;
                        if (terrain_height < 0) {
                            terrain_height = (long)h;
                        } else if (terrain_height != (long)h) {
                            valid_cliff_site = 0;
                        }
                    } else {
                        valid_cliff_site = 0;
                        if (terrain_type == 1 || terrain_type == 4 || terrain_type == 0x16) {
                            water_area = 1;
                        }
                    }
                }
            }

            if (valid_cliff_site != 0) {
                if (this->search_map_rows[cy][cx] != 0) {
                    this->search_map_rows[cy][cx] = (uchar)(terrain_height + 1);
                    this->push_stack(&this->valid_cliff_sites, cx, cy, 0.0f, 0.0f);
                }
            } else {
                if (water_area != 0) {
                    this->invalidate_cliff_area(cx, cy, this->info.cliff_terrain_spacing);
                }
                this->search_map_rows[cy][cx] = 0;
            }
        }
    }

    for (long i = 0; i < this->info.hot_spot_num; ++i) {
        this->invalidate_cliff_area(
            this->info.hot_spots[i].x / 3,
            this->info.hot_spots[i].y / 3,
            this->info.hot_spots[i].radius / 3 + 2);
    }

    long max_y = cliff_height - 1;
    long max_x = cliff_width - 1;
    for (long y = 0; y < cliff_height; ++y) {
        for (long x = 0; x < cliff_width; ++x) {
            if (this->search_map_rows[y][x] == 0) {
                continue;
            }

            if (y > 0 && this->search_map_rows[y - 1][x] != 0) {
                continue;
            }
            if (x > 0 && this->search_map_rows[y][x - 1] != 0) {
                continue;
            }
            if (y < max_y && this->search_map_rows[y + 1][x] != 0) {
                continue;
            }
            if (x < max_x && this->search_map_rows[y][x + 1] != 0) {
                continue;
            }

            this->search_map_rows[y][x] = 0;
            this->remove_stack_node(&this->stack_offsets[y][x]);
        }
    }

    this->randomize_stack(&this->valid_cliff_sites);
}

void RGE_RMM_Cliffs_Generator::generate_cliff() {
    long previous_x = -1;
    long previous_y = -1;

    long variance = this->info.cliff_size_variance;
    long cliff_length =
        (((long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_clif.cpp", 0xc4) * variance * 2) / 0x7fff) +
        this->info.average_cliff_size - variance;
    uchar first_cliff = 1;

    if (this->valid_cliff_sites.next == nullptr) {
        return;
    }
    if (cliff_length < 3) {
        return;
    }

    Map_Stack cliff;
    this->init_stack(&cliff);

    long x = 0;
    long y = 0;
    float cost = 0.0f;
    while (true) {
        Map_Stack* popped = this->pop_stack(&this->valid_cliff_sites, &x, &y, &cost);
        if (popped == nullptr) {
            return;
        }
        if (this->search_map_rows[y][x] != 0) {
            break;
        }
        if (this->valid_cliff_sites.next == nullptr) {
            return;
        }
    }

    long valid_height = (long)this->search_map_rows[y][x];
    this->push_stack(&cliff, x, y, 0.0f, 0.0f);
    this->search_map_rows[y][x] = 0;

    long dir = ((long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_clif.cpp", 0xdd) * 4) / 0x7fff;
    long placed = 0;
    while (placed < cliff_length) {
        uchar cliff_end_found = 0;
        long turn = ((long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_clif.cpp", 0xe3) * 100) / 0x7fff;
        if (turn < 0x12) {
            if (dir < 1) {
                dir = 3;
            } else {
                dir = dir - 1;
            }
        } else if (turn < 0x24) {
            if (dir < 3) {
                dir = dir + 1;
            } else {
                dir = 0;
            }
        }

        uchar valid = this->check_for_valid_cliff_site(dir, &x, &y, valid_height);
        if (valid == 0) valid = this->check_for_valid_cliff_site(dir + 1, &x, &y, valid_height);
        if (valid == 0) valid = this->check_for_valid_cliff_site(dir - 1, &x, &y, valid_height);
        if (valid == 0 && first_cliff != 0) {
            valid = this->check_for_valid_cliff_site(dir - 2, &x, &y, valid_height);
        }
        if (valid == 0) {
            cliff_end_found = 1;
        }

        first_cliff = 0;
        if (cliff_end_found != 0) {
            break;
        }

        this->push_stack(&cliff, x, y, 0.0f, 0.0f);
        this->search_map_rows[y][x] = 0;
        placed = placed + 1;
    }

    while (cliff.prev != nullptr) {
        this->pop_stack(&cliff, &x, &y, &cost);
        if (previous_x == -1) {
            previous_x = x;
            previous_y = y;
        }

        long x0 = previous_x * 3 + 1;
        long y0 = previous_y * 3 + 1;
        long x1 = x * 3 + 1;
        long y1 = y * 3 + 1;

        this->map->do_terrain_brush_stroke(x0, y0, x1, y1, 1, 0x10);
        this->map->do_cliff_brush_stroke(x0, y0, x1, y1, 0, 0);

        previous_x = x;
        previous_y = y;
        this->invalidate_cliff_area(x, y, this->info.cliff_to_cliff_spacing);
    }
}

uchar RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site(
    long param_1,
    long* param_2,
    long* param_3,
    long param_4) {
    long row = *param_3;
    long col = *param_2;

    if (param_1 > 3) {
        unsigned long count = (unsigned long)(param_1 - 1) / 3;
        while (count != 0) {
            param_1 = param_1 - 3;
            count = count - 1;
        }
    }
    if (param_1 < 0) {
        param_1 = (long)(((unsigned long)(2 - param_1) / 3) * 3 + param_1);
    }

    switch (param_1) {
        case 0:
            if (row < 1) {
                return 0;
            }
            row = row - 1;
            break;
        case 1: {
            long max_col = this->map_width / 3 - 1;
            if (max_col <= col) {
                return 0;
            }
            col = col + 1;
            break;
        }
        case 2: {
            long max_row = this->map_height / 3 - 1;
            if (max_row <= row) {
                return 0;
            }
            row = row + 1;
            break;
        }
        case 3:
            if (col < 1) {
                return 0;
            }
            col = col - 1;
            break;
        default:
            break;
    }

    if ((long)(uchar)this->search_map_rows[row][col] != param_4) {
        return 0;
    }

    *param_2 = col;
    *param_3 = row;
    return 1;
}

void RGE_RMM_Cliffs_Generator::invalidate_cliff_area(long param_1, long param_2, long param_3) {
    long max_x = this->map_width / 3 - 1;
    long max_y = this->map_height / 3 - 1;

    long x0 = param_1 - param_3;
    long y0 = param_2 - param_3;
    long x1 = param_3 + param_1;
    long y1 = param_3 + param_2;

    if (x0 < 0) {
        x0 = 0;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (max_x < x1) {
        x1 = max_x;
    }
    if (max_y < x1) {
        y1 = max_y;
    }

    if (y0 <= y1) {
        for (long y = y0; y <= y1; ++y) {
            if (x0 <= x1) {
                for (long x = x0; x <= x1; ++x) {
                    if (this->search_map_rows[y][x] != 0) {
                        this->search_map_rows[y][x] = 0;
                        this->remove_stack_node(&this->stack_offsets[y][x]);
                    }
                }
            }
        }
    }
}
