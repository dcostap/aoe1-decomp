// map.h is source-private because the public module header needs only pointer
// and base declarations.

#include "../include/rmm_shal.h"
#include "../include/map.h"

extern int __cdecl debug_rand(char*, int);

RGE_RMM_Shallows_Generator::RGE_RMM_Shallows_Generator(
    RGE_Map* in_map, RGE_Random_Map_Module* parent_module,
    RGE_Shallows_Info* in_info)
    : RGE_Random_Map_Module(in_map, parent_module, 1)
{
    this->schedule = 1.1f;
    this->info = *in_info;
}

// inner loop at line 57, and connection call at line 58.
uchar RGE_RMM_Shallows_Generator::generate()
{
    this->clear_stack();

    long i, j;
    long x, y;
    for (i = 0; i < this->info.shallows_num; ++i) {
        for (j = i + 1; j < this->info.shallows_num; ++j) {
            this->make_tribe_connections(i, j);
        }
    }

    long count = 2;
    this->info.shallows_num += 2;
    long index1 = this->info.shallows_num - 1;
    long index2 = this->info.shallows_num - 2;

    do {
        int found = 0;
        do {
            x = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x45) *
                 (this->map_width - 1)) / 0x7FFF;
            y = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x46) *
                 (this->map_height - 1)) / 0x7FFF;
            uchar terrain = this->map_row_offset[y][x].terrain_type & 0x1f;
            if (terrain != 1 && terrain != 0x16 && terrain != 4) {
                this->info.shallows[index1].x = x;
                found = 1;
                this->info.shallows[index1].y = y;
            }
        } while (!found);

        found = 0;
        do {
            x = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x54) *
                 (this->map_width - 1)) / 0x7FFF;
            y = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x55) *
                 (this->map_height - 1)) / 0x7FFF;
            uchar terrain = this->map_row_offset[y][x].terrain_type & 0x1f;
            if (terrain != 1 && terrain != 0x16 && terrain != 4) {
                this->info.shallows[index2].x = x;
                found = 1;
                this->info.shallows[index2].y = y;
            }
        } while (!found);

        this->make_tribe_connections(index1, index2);
        --count;
    } while (count != 0);

    return 1;
}

void RGE_RMM_Shallows_Generator::make_tribe_connections(
    long point1, long point2)
{
    long start_x = this->info.shallows[point1].x;
    long start_y = this->info.shallows[point1].y;
    long target_x = this->info.shallows[point2].x;
    long target_y = this->info.shallows[point2].y;
    long path_x = target_x;
    long path_y = target_y;
    long x;
    long y;
    long done;
    float cost;
    float terrain[40] = {0};
    Map_Stack stack;

    this->init_stack(stack);

    terrain[0] = 1.0f;
    terrain[1] = 7.0f;
    terrain[2] = 1.0f;
    terrain[4] = 2.0f;
    terrain[22] = 14.0f;

    this->find_path(start_x, start_y, path_x, path_y, terrain);

    if (path_x != target_x || path_y != target_y) {
        return;
    }

    x = path_x;
    y = path_y;
    if (x < 0 || x >= this->map_width ||
        y < 0 || y >= this->map_height) {
        return;
    }

    stack.next = 0;
    stack.prev = 0;
    done = 0;

    while (!done) {
        switch (this->search_map_rows[path_y][path_x]) {
        case 4:
            ++x;
            break;
        case 5:
            --x;
            break;
        case 6:
            ++y;
            break;
        case 7:
            --y;
            break;
        case 8:
            ++y;
            ++x;
            break;
        case 9:
            --y;
            ++x;
            break;
        case 10:
            ++y;
            --x;
            break;
        case 11:
            --y;
            --x;
            break;
        default:
            done = 1;
            break;
        }

        if (x < 0 || x >= this->map_width ||
            y < 0 || y >= this->map_height) {
            done = 1;
        }

        if (done) {
            break;
        }

        uchar terrain_type =
            this->map_row_offset[y][x].terrain_type & 0x1f;
        if (terrain_type == 1 || terrain_type == 0x16) {
            long min_x =
                x - (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0xc6) * 2) /
                        0x7fff -
                1;
            if (min_x < 0) {
                min_x = 0;
            }

            long min_y =
                y - (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0xca) * 2) /
                        0x7fff -
                1;
            if (min_y < 0) {
                min_y = 0;
            }

            long max_x =
                x + (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0xce) * 2) /
                        0x7fff +
                1;
            if (max_x >= this->map_width) {
                max_x = this->map_width - 1;
            }

            long max_y =
                y + (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0xd2) * 3) /
                        0x7fff +
                1;
            if (max_y >= this->map_height) {
                max_y = this->map_height - 1;
            }

            for (long fill_y = min_y; fill_y <= max_y; ++fill_y) {
                for (long fill_x = min_x; fill_x <= max_x; ++fill_x) {
                    if ((this->map_row_offset[fill_y][fill_x].terrain_type &
                         0x1f) == 1 ||
                        (this->map_row_offset[fill_y][fill_x].terrain_type &
                         0x1f) == 0x16) {
                        this->push_stack(stack, fill_x, fill_y, 0.0f, 0.0f);
                    }
                }
            }
        } else {
            if (x > 0) {
                terrain_type =
                    this->map_row_offset[y][x - 1].terrain_type & 0x1f;
                if (terrain_type == 1 || terrain_type == 0x16) {
                    this->push_stack(stack, x - 1, y, 0.0f, 0.0f);
                }
            }
            if (x < this->map_width - 1) {
                terrain_type =
                    this->map_row_offset[y][x + 1].terrain_type & 0x1f;
                if (terrain_type == 1 || terrain_type == 0x16) {
                    this->push_stack(stack, x + 1, y, 0.0f, 0.0f);
                }
            }
            if (y > 0) {
                terrain_type =
                    this->map_row_offset[y - 1][x].terrain_type & 0x1f;
                if (terrain_type == 1 || terrain_type == 0x16) {
                    this->push_stack(stack, x, y - 1, 0.0f, 0.0f);
                }
            }
            if (y < this->map_height - 1) {
                terrain_type =
                    this->map_row_offset[y + 1][x].terrain_type & 0x1f;
                if (terrain_type == 1 || terrain_type == 0x16) {
                    this->push_stack(stack, x, y + 1, 0.0f, 0.0f);
                }
            }
        }

        this->search_map_rows[path_y][path_x] = 0xff;
        path_x = x;
        path_y = y;
    }

    while (this->pop_stack(stack, x, y, cost)) {
        this->map_row_offset[y][x].terrain_type = 4;
    }
    this->deinit_stack(stack);
}
