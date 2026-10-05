
#include "../include/rmm_clif.h"
#include "../include/map.h"
#include <string.h>

extern int __cdecl debug_rand(char* file, int line);

RGE_RMM_Cliffs_Generator::RGE_RMM_Cliffs_Generator(
    RGE_Map* in_map, RGE_Random_Map_Module* parent_module, RGE_Cliffs_Info cliff_info
) : RGE_Random_Map_Module(in_map, parent_module, 1) {
    this->info = cliff_info;
    this->schedule = 1.75f;
}

uchar RGE_RMM_Cliffs_Generator::generate() {
    int i;

    this->setup_cliff_maps();
    debug_rand("C:\\msdev\\work\\age1_x1\\rmm_clif.cpp", 50);
    i = 0;
    if (this->info.number_of_cliffs > 0) {
        do {
            this->generate_cliff();
            i++;
        } while (i < this->info.number_of_cliffs);
    }
    return 1;
}

void RGE_RMM_Cliffs_Generator::setup_cliff_maps() {
    long cliff_width = this->map_width / 3;
    long cliff_height = this->map_height / 3;
    long terrain_width = cliff_width;
    long cliff_width2 = cliff_width - 1;
    long cliff_height2 = cliff_height - 1;

    this->clear_stack();
    this->init_stack(this->valid_cliff_sites);

    memset(this->search_map, 1, this->map_height * this->map_width);

    long cliff_y = 0;
    if (cliff_height > 0) {
        long row_offset = 0;
        do {
            long cliff_x = 0;
            if (terrain_width > 0) {
                long column_offset = 0;
                do {
                    long area = -1;
                    unsigned char valid = 1;
                    unsigned char water_area = 0;
                    RGE_Tile** tile_row = (RGE_Tile**) ((char*) this->map_row_offset + row_offset);
                    long tile_rows = 3;
                    do {
                        long tile_columns = 3;
                        unsigned char* tile = (unsigned char*) *tile_row + 5 + column_offset;
                        do {
                            unsigned char value = *tile;
                            unsigned char terrain = value & 0x1f;
                            if (terrain == 0 || terrain == 6) {
                                unsigned char elevation = value >> 5;
                                if (area < 0) {
                                    area = elevation;
                                } else if (area != elevation) {
                                    valid = 0;
                                }
                            } else {
                                valid = 0;
                                if (terrain == 1 || terrain == 4 || terrain == 0x16) {
                                    water_area = 1;
                                }
                            }
                            tile += 24;
                            tile_columns--;
                        } while (tile_columns != 0);
                        tile_row++;
                        tile_rows--;
                    } while (tile_rows != 0);

                    if (valid != 0) {
                        unsigned char* cell = this->search_map_rows[cliff_y] + cliff_x;
                        if (*cell != 0) {
                            *cell = (unsigned char) (area + 1);
                            this->push_stack(this->valid_cliff_sites, cliff_x, cliff_y, 0.0f, 0.0f);
                        }
                    } else {
                        if (water_area != 0) {
                            this->invalidate_cliff_area(cliff_x, cliff_y, this->info.cliff_terrain_spacing);
                        }
                        this->search_map_rows[cliff_y][cliff_x] = 0;
                    }
                    cliff_x++;
                    column_offset += 72;
                } while (cliff_x < terrain_width);
            }
            cliff_y++;
            row_offset += 12;
        } while (cliff_y < cliff_height);
    }

    long hot_spot_index = 0;
    if (this->info.hot_spot_num > 0) {
        // The shipped cursor starts at the first hot spot's y field.
        long* hot_spot = &this->info.hot_spots[0].y;
        do {
            this->invalidate_cliff_area(hot_spot[-1] / 3, hot_spot[0] / 3, hot_spot[1] / 3 + 2);
            hot_spot_index++;
            hot_spot += 3;
        } while (hot_spot_index < this->info.hot_spot_num);
    }

    long y = 0;
    if (cliff_height > 0) {
        do {
            long x = 0;
            if (terrain_width > 0) {
                do {
                    unsigned char* cell = this->search_map_rows[y] + x;
                    if (this->search_map_rows[y][x] != 0 && (y <= 0 || this->search_map_rows[y - 1][x] == 0)
                        && (x <= 0 || cell[-1] == 0) && (y >= cliff_height2 || this->search_map_rows[y + 1][x] == 0)
                        && (x >= cliff_width2 || cell[1] == 0)) {
                        *cell = 0;
                        this->remove_stack_node(this->stack_offsets[y] + x);
                    }
                    x++;
                } while (x < terrain_width);
            }
            y++;
        } while (y < cliff_height);
    }

    this->randomize_stack(&this->valid_cliff_sites);
}

void RGE_RMM_Cliffs_Generator::generate_cliff() {
    long x = -1;
    long variance = this->info.cliff_size_variance;
    long start_y = -1;
    long y;
    long valid_height;
    long index;
    long this_cliff_size;
    long direction;
    long cost;
    unsigned char first_cliff;
    unsigned char cliff_end_found;
    Map_Stack cliff;
    cost = ((debug_rand((char*) "C:\\msdev\\work\\age1_x1\\rmm_clif.cpp", 196) * variance * 2) / 0x7fff
            + this->info.average_cliff_size)
           - variance;
    first_cliff = 1;
    if (this->valid_cliff_sites.next == 0) {
        return;
    }
    if (cost < 3) {
        return;
    }

    float stack_cost;
    this->init_stack(cliff);
    unsigned char* map_row;
    long column;
    while (1) {
        this->pop_stack(this->valid_cliff_sites, y, valid_height, stack_cost);
        map_row = this->search_map_rows[valid_height];
        column = y;
        if (map_row[column] != 0) {
            break;
        }
        if (this->valid_cliff_sites.next == 0) {
            return;
        }
    }

    index = this->search_map_rows[valid_height][y];
    this->push_stack(cliff, y, valid_height, 0.0f, 0.0f);
    this->search_map_rows[valid_height][y] = 0;

    direction = (debug_rand((char*) "C:\\msdev\\work\\age1_x1\\rmm_clif.cpp", 221) * 4) / 0x7fff;
    this_cliff_size = 0;
    if (cost > 0) {
        do {
            cliff_end_found = 0;
            long turn = (debug_rand((char*) "C:\\msdev\\work\\age1_x1\\rmm_clif.cpp", 227) * 100) / 0x7fff;
            if (turn < 0x12) {
                if (direction <= 0) {
                    direction = 3;
                } else {
                    direction--;
                }
            } else if (turn < 0x24) {
                if (direction >= 3) {
                    direction = 0;
                } else {
                    direction++;
                }
            }

            if (this->check_for_valid_cliff_site(direction, y, valid_height, index) == 0) {
                if (this->check_for_valid_cliff_site(direction + 1, y, valid_height, index) == 0) {
                    if (this->check_for_valid_cliff_site(direction - 1, y, valid_height, index) == 0) {
                        if (first_cliff == 0) {
                            cliff_end_found = 1;
                        } else if (this->check_for_valid_cliff_site(direction - 2, y, valid_height, index) == 0) {
                            cliff_end_found = 1;
                        }
                    }
                }
            }
            first_cliff = 0;
            if (cliff_end_found != 0) {
                break;
            }
            this->push_stack(cliff, y, valid_height, 0.0f, 0.0f);
            this->search_map_rows[valid_height][y] = 0;
            this_cliff_size++;
        } while (this_cliff_size < cost);
    }

    while (cliff.next != 0) {
        this->pop_stack(cliff, y, valid_height, stack_cost);
        if (x == -1) {
            x = y;
            start_y = valid_height;
        }
        this->map->do_terrain_brush_stroke(x * 3 + 1, start_y * 3 + 1, y * 3 + 1, valid_height * 3 + 1, 1, 0x10);
        this->map->do_cliff_brush_stroke(x * 3 + 1, start_y * 3 + 1, y * 3 + 1, valid_height * 3 + 1, 0, 0);
        x = y;
        start_y = valid_height;
        this->invalidate_cliff_area(y, valid_height, this->info.cliff_to_cliff_spacing);
    }
}

uchar RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site(long direction, long& x, long& y, long valid_height) {
    long* height_pointer = &y;
    long* width_pointer = &x;
    long width = *width_pointer;
    long height = *height_pointer;

    if (direction > 3) {
        unsigned long count = ((unsigned long) direction - 1) / 3;
        do {
            direction -= 3;
            count--;
        } while (count != 0);
    }

    if (direction < 0) {
        direction = ((unsigned long) (2 - direction) / 3) * 3 + direction;
    }

    switch (direction) {
        case 0:
            if (height <= 0)
                goto invalid;
            height--;
            break;
        case 1:
            if (width >= this->map_width / 3 - 1)
                goto invalid;
            width++;
            break;
        case 2:
            if (height >= this->map_height / 3 - 1)
                goto invalid;
            height++;
            break;
        case 3:
            if (width <= 0)
                goto invalid;
            width--;
            break;
    }

    if ((unsigned char) this->search_map_rows[height][width] == valid_height) {
        *width_pointer = width;
        *height_pointer = height;
        return 1;
    }

invalid:
    return 0;
}

void RGE_RMM_Cliffs_Generator::invalidate_cliff_area(long x, long y, long radius) {
    long cliff_width2 = this->map_width / 3 - 1;
    long cliff_height2 = this->map_height / 3 - 1;
    long x1 = x - radius;
    long min_y = y - radius;
    long max_x = x + radius;
    long max_y = y + radius;

    if (x1 < 0) {
        x1 = 0;
    }
    if (min_y < 0) {
        min_y = 0;
    }
    if (max_x > cliff_width2) {
        max_x = cliff_width2;
    }
    // The shipped code compares the upper x endpoint with the height bound.
    if (max_x > cliff_height2) {
        max_y = cliff_height2;
    }

    for (long row = min_y; row <= max_y; row++) {
        for (long column = x1; column <= max_x; column++) {
            if (this->search_map_rows[row][column] != 0) {
                this->search_map_rows[row][column] = 0;
                this->remove_stack_node(this->stack_offsets[row] + column);
            }
        }
    }
}
