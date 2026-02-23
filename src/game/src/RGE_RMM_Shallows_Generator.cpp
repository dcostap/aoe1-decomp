#include "../include/RGE_RMM_Shallows_Generator.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Tile.h"
#include "../include/debug_helpers.h"

#include <string.h>

RGE_RMM_Shallows_Generator::RGE_RMM_Shallows_Generator(
    RGE_Map* param_1,
    RGE_Random_Map_Module* param_2,
    RGE_Shallows_Info* param_3)
    // Fully verified. Source of truth: rmm_shal.cpp.decomp @ 0x00487010
    : RGE_Random_Map_Module(param_1, param_2, 1) {
    this->schedule = 1.1f;
    memset(&this->info, 0, sizeof(this->info));
    if (param_3 != nullptr) {
        memcpy(&this->info, param_3, sizeof(this->info));
    }
}

static long rmm_shal_rand_coord(long max_minus_1, int line_no) {
    if (max_minus_1 <= 0) {
        return 0;
    }
    long r = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", line_no);
    return (long)(((long long)r * (long long)max_minus_1) / 0x7fffLL);
}

uchar RGE_RMM_Shallows_Generator::generate() {
    // Fully verified. Source of truth: rmm_shal.cpp.decomp @ 0x00487050
    this->clear_stack();

    long num = this->info.shallows_num;
    if (num < 0) num = 0;
    if (num > 99) num = 99;
    this->info.shallows_num = num;

    for (long i = 0; i < num; ++i) {
        for (long j = i + 1; j < num; ++j) {
            this->make_tribe_connections(i, j);
        }
    }

    // Add two random pairs.
    this->info.shallows_num = num + 2;
    int pair_count = 2;
    while (pair_count > 0) {
        int found = 0;
        while (found == 0) {
            long x = rmm_shal_rand_coord(this->map_width - 1, 0x45);
            long y = rmm_shal_rand_coord(this->map_height - 1, 0x46);
            uchar tt = (uchar)(this->map_row_offset[y][x].terrain_type & 0x1f);
            if (tt != 1 && tt != 0x16 && tt != 4) {
                this->info.shallows[num + 1].x = x;
                this->info.shallows[num + 1].y = y;
                found = 1;
            }
        }

        found = 0;
        while (found == 0) {
            long x = rmm_shal_rand_coord(this->map_width - 1, 0x54);
            long y = rmm_shal_rand_coord(this->map_height - 1, 0x55);
            uchar tt = (uchar)(this->map_row_offset[y][x].terrain_type & 0x1f);
            if (tt != 1 && tt != 0x16 && tt != 4) {
                this->info.shallows[num].x = x;
                this->info.shallows[num].y = y;
                found = 1;
            }
        }

        this->make_tribe_connections(num + 1, num);
        pair_count = pair_count - 1;
    }

    return 1;
}

void RGE_RMM_Shallows_Generator::make_tribe_connections(long param_1, long param_2) {
    // Fully verified. Source of truth: rmm_shal.cpp.decomp @ 0x00487200
    if (this->map_row_offset == nullptr || this->search_map_rows == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return;
    }
    if (param_1 < 0 || param_2 < 0 || param_1 >= this->info.shallows_num || param_2 >= this->info.shallows_num) {
        return;
    }

    long end_x = this->info.shallows[param_1].x;
    long end_y = this->info.shallows[param_1].y;
    long start_x = this->info.shallows[param_2].x;
    long start_y = this->info.shallows[param_2].y;

    float terrain_cost[40];
    memset(terrain_cost, 0, sizeof(terrain_cost));
    terrain_cost[1] = 1.0f;
    terrain_cost[2] = 7.0f;
    terrain_cost[3] = 1.0f;
    terrain_cost[5] = 2.0f;
    terrain_cost[0x17] = 14.0f;

    long tx = start_x;
    long ty = start_y;
    this->find_path(end_x, end_y, &tx, &ty, &terrain_cost[1]);
    if (tx != start_x || ty != start_y || tx < 0 || ty < 0 || tx >= this->map_width || ty >= this->map_height) {
        return;
    }

    Map_Stack stack;
    this->init_stack(&stack);

    long done = 0;
    long walk_guard = this->map_width * this->map_height * 4;
    if (walk_guard < 1) walk_guard = 1;
    while (done == 0 && walk_guard-- > 0) {
        long nx = tx;
        long ny = ty;
        switch (this->search_map_rows[ty][tx]) {
            case 6:
                ny = ty + 1;
                break;
            case 7:
                ny = ty - 1;
                break;
            case 8:
                ny = ty + 1;
            case 4:
                nx = tx + 1;
                break;
            case 9:
                ny = ty - 1;
                nx = tx + 1;
                break;
            case 10:
                ny = ty + 1;
            case 5:
                nx = tx - 1;
                break;
            case 0xb:
                ny = ty - 1;
                nx = tx - 1;
                break;
            default:
                done = 1;
                break;
        }

        if (nx < 0 || ny < 0 || nx >= this->map_width || ny >= this->map_height) {
            done = 1;
        }

        if (done != 0) {
            long sx = 0;
            long sy = 0;
            float c = 0.0f;
            Map_Stack* it = this->pop_stack(&stack, &sx, &sy, &c);
            while (it != nullptr) {
                this->map_row_offset[sy][sx].terrain_type = 4;
                it = this->pop_stack(&stack, &sx, &sy, &c);
            }
            this->deinit_stack(&stack);
            return;
        }

        uchar tt = (uchar)(this->map_row_offset[ny][nx].terrain_type & 0x1f);
        if (tt == 1 || tt == 0x16) {
            long sx0 = nx - 1 - rmm_shal_rand_coord(2, 0xc6);
            long sy0 = ny - 1 - rmm_shal_rand_coord(2, 0xca);
            long sx1 = nx + 1 + rmm_shal_rand_coord(2, 0xce);
            long sy1 = ny + 1 + rmm_shal_rand_coord(3, 0xd2);

            if (sx0 < 0) sx0 = 0;
            if (sy0 < 0) sy0 = 0;
            if (sx1 >= this->map_width) sx1 = this->map_width - 1;
            if (sy1 >= this->map_height) sy1 = this->map_height - 1;

            for (long yy = sy0; yy <= sy1; ++yy) {
                for (long xx = sx0; xx <= sx1; ++xx) {
                    uchar wtt = (uchar)(this->map_row_offset[yy][xx].terrain_type & 0x1f);
                    if (wtt == 1 || wtt == 0x16) {
                        this->push_stack(&stack, xx, yy, 0.0f, 0.0f);
                    }
                }
            }
        } else {
            if (nx > 0) {
                uchar wtt = (uchar)(this->map_row_offset[ny][nx - 1].terrain_type & 0x1f);
                if (wtt == 1 || wtt == 0x16) {
                    this->push_stack(&stack, nx - 1, ny, 0.0f, 0.0f);
                }
            }
            if (nx < this->map_width - 1) {
                uchar wtt = (uchar)(this->map_row_offset[ny][nx + 1].terrain_type & 0x1f);
                if (wtt == 1 || wtt == 0x16) {
                    this->push_stack(&stack, nx + 1, ny, 0.0f, 0.0f);
                }
            }
            if (ny > 0) {
                uchar wtt = (uchar)(this->map_row_offset[ny - 1][nx].terrain_type & 0x1f);
                if (wtt == 1 || wtt == 0x16) {
                    this->push_stack(&stack, nx, ny - 1, 0.0f, 0.0f);
                }
            }
            if (ny < this->map_height - 1) {
                uchar wtt = (uchar)(this->map_row_offset[ny + 1][nx].terrain_type & 0x1f);
                if (wtt == 1 || wtt == 0x16) {
                    this->push_stack(&stack, nx, ny + 1, 0.0f, 0.0f);
                }
            }
        }

        this->search_map_rows[ty][tx] = 0xff;
        tx = nx;
        ty = ny;
    }

    this->deinit_stack(&stack);
}

