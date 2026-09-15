
#include "../include/zone_map.h"

void rge_read(int handle, void* buffer, int count);
void rge_write(int file, void* data, int size);
#include <math.h>
#include <stdlib.h>
#include <string.h>

extern "C" void __cdecl free(void* block);
extern "C" void* __cdecl calloc(unsigned int num, unsigned int size);

unsigned char __cdecl zone_pop(Zone_Queue** zone_queue, Zone_Queue** zone_end, long& x, long& y) {
    Zone_Queue* node = *zone_queue;
    if (node == 0) {
        return 0;
    }

    x = node->x;
    y = node->y;
    *zone_queue = node->next;
    free(node);
    if (*zone_queue == 0) {
        *zone_end = 0;
    }
    return 1;
}

void __cdecl zone_push(Zone_Queue** zone_queue, Zone_Queue** zone_end, long x, long y) {
    Zone_Queue* node = (Zone_Queue*)calloc(1, 0xC);

    if (*zone_end != 0) {
        (*zone_end)->next = node;
    }
    node->x = x;
    node->y = y;
    *zone_end = node;
    if (*zone_queue == 0) {
        *zone_queue = node;
    }
}

// The shipped load constructor keeps the map pointer live across the row
// setup and restores the serialized fields before reading the map data.
RGE_Zone_Map::RGE_Zone_Map(int infile, RGE_Map* new_map) {
    this->map = new_map;

    this->zone_map = (uchar*)calloc(new_map->map_width * new_map->map_height, 1);
    this->zone_map_rows = (uchar**)calloc(new_map->map_height, 4);

    for (int i = 0; i < this->map->map_height; i++) {
        this->zone_map_rows[i] = this->zone_map + this->map->map_width * i;
    }

    rge_read(infile, this->zone_info, 0xFF);
    rge_read(infile, this, 0x3FC);

    rge_read(infile, this->zone_map, this->map->map_height * this->map->map_width);

    rge_read(infile, &this->terrain_passability_rules_num, 4);
    if (this->terrain_passability_rules_num > 0) {
        this->terrain_passability_rules =
            (float*)calloc(this->terrain_passability_rules_num, 4);
        rge_read(infile, this->terrain_passability_rules, this->terrain_passability_rules_num * 4);
    } else {
        this->terrain_passability_rules = NULL;
    }
}

RGE_Zone_Map::RGE_Zone_Map(RGE_Map* new_map, float* new_terrain_rules, long new_terrain_rules_num) {
    int i;

    this->map = new_map;
    this->zone_map = (uchar*)calloc(this->map->map_width * this->map->map_height, 1);
    memset(this->zone_map, 0xFF, this->map->map_width * this->map->map_height);
    this->zone_map_rows = (uchar**)calloc(this->map->map_height, 4);

    for (i = 0; i < this->map->map_height; i++) {
        this->zone_map_rows[i] = this->zone_map + this->map->map_width * i;
    }

    for (i = 0; i < 0xFF; i++) {
        this->zone_info[i] = 0xFF;
        this->numberTilesInZoneValue[i] = 0;
    }

    this->terrain_passability_rules_num = new_terrain_rules_num;
    this->terrain_passability_rules = (float*)calloc(this->terrain_passability_rules_num, 4);
    memcpy(this->terrain_passability_rules, new_terrain_rules, this->terrain_passability_rules_num * 4);
    this->do_zone_map();
}

RGE_Zone_Map::~RGE_Zone_Map() {
    free(this->zone_map);
    free(this->zone_map_rows);
    free(this->terrain_passability_rules);
}

void RGE_Zone_Map::save(int outfile) {
    rge_write(outfile, this->zone_info, 0xFF);
    rge_write(outfile, this, 0x3FC);
    rge_write(outfile, this->zone_map, this->map->map_height * this->map->map_width);
    rge_write(outfile, &this->terrain_passability_rules_num, 4);
    if (this->terrain_passability_rules_num > 0) {
        rge_write(outfile, this->terrain_passability_rules, this->terrain_passability_rules_num * 4);
    }
}

uchar RGE_Zone_Map::do_zone_map() {
    int map_width;
    int map_height;
    int group;
    uchar visible;
    int y;
    int group_counter;
    int row;
    int col;

    map_width = this->map->map_width;
    map_height = this->map->map_height;
    group_counter = 0;

    memset(this->zone_info, 0xFF, 255);

    for (row = 0; row < map_width; row++) {
        for (col = 0; col < map_height; col++) {
            this->zone_map_rows[row][col] = 0xFF;
        }
    }

    group = 0;
    if (map_width > 0) {
        do {
            int x = 0;
            if (x < map_height) {
                y = 0;
                do {
                    if (this->zone_map_rows[group][x] == 0xFF) {
                        if (group_counter >= 255)
                            group_counter = 0;

                        int terrainByte =
                            ((unsigned char*)this->map->map_row_offset[group])[y + 5]
                            & 0x1F;
                        float passability =
                            this->terrain_passability_rules[terrainByte];
                        visible = 1;
                        if (!(passability > 0.0))
                            visible = 0;

                        this->zone_map_rows[group][x] = (uchar)group_counter;
                        do_zone_map_area(x, group, visible, (uchar)group_counter);
                        group_counter++;
                    }
                    x++;
                    y += 0x18;
                } while (x < map_height);
            }
            group++;
        } while (group < map_width);
    }

    return 1;
}

extern double DAT_00577a20;

void RGE_Zone_Map::do_zone_map_area(long x, long y, unsigned char group, unsigned char zone) {
    Zone_Queue* zone_end = 0;
    Zone_Queue* zone_queue = 0;
    long max_x = this->map->map_width - 1;
    long max_y = this->map->map_height - 1;
    do {
        if (x > 0) {
            RGE_Tile* tile = this->map->map_row_offset[y] + x - 1;
            unsigned char* cell = this->zone_map_rows[y] + x - 1;
            if (*cell == 0xff) {
                if (((this->terrain_passability_rules[tile->terrain_type] >
                      DAT_00577a20) ? 1 : 0) == (group & 0xff)) {
                    *cell = zone;
                    zone_push(&zone_end, &zone_queue, x - 1, y);
                }
            }
        }
        if (y > 0) {
            RGE_Tile* tile = this->map->map_row_offset[y - 1] + x;
            if (this->zone_map_rows[y - 1][x] == 0xff) {
                if (((this->terrain_passability_rules[tile->terrain_type] >
                      DAT_00577a20) ? 1 : 0) == (group & 0xff)) {
                    this->zone_map_rows[y - 1][x] = zone;
                    zone_push(&zone_end, &zone_queue, x, y - 1);
                }
            }
        }
        if (x < max_x) {
            RGE_Tile* tile = this->map->map_row_offset[y] + x + 1;
            unsigned char* cell = this->zone_map_rows[y] + x + 1;
            if (*cell == 0xff) {
                if (((this->terrain_passability_rules[tile->terrain_type] >
                      DAT_00577a20) ? 1 : 0) == (group & 0xff)) {
                    *cell = zone;
                    zone_push(&zone_end, &zone_queue, x + 1, y);
                }
            }
        }
        if (y < max_y) {
            RGE_Tile* tile = this->map->map_row_offset[y + 1] + x;
            if (this->zone_map_rows[y + 1][x] == 0xff) {
                if (((this->terrain_passability_rules[tile->terrain_type] >
                      DAT_00577a20) ? 1 : 0) == (group & 0xff)) {
                    this->zone_map_rows[y + 1][x] = zone;
                    zone_push(&zone_end, &zone_queue, x, y + 1);
                }
            }
        }
    } while (zone_pop(&zone_end, &zone_queue, x, y));
}

RGE_Zone_Map* RGE_Zone_Map::check_info(float* new_terrain_rules, long new_terrain_rules_num) {
    int n = this->terrain_passability_rules_num;
    if (new_terrain_rules_num == n) {
        int i = 0;
        if (n > 0) {
            do {
                if (new_terrain_rules[i] <= DAT_00577a20) {
                    if (this->terrain_passability_rules[i] > DAT_00577a20)
                        return 0;
                } else {
                    if (this->terrain_passability_rules[i] <= DAT_00577a20)
                        return 0;
                }
                ++i;
            } while (i < n);
        }
        return this;
    }
    return 0;
}

unsigned char RGE_Zone_Map::get_zone_info(long x, long y) {
    return zone_map_rows[y][x];
}

int RGE_Zone_Map::withinRange(XYPoint start, XYPoint goal, float range) {
    return withinRange(this->zone_map_rows[start.y][start.x], goal, range);
}

int RGE_Zone_Map::withinRange(uchar startZone, XYPoint goal, float range) {
    int min_x = goal.x - (int)range;
    int min_y = goal.y - (int)range;

    if (min_x < 0)
        min_x = 0;
    if (min_y < 0)
        min_y = 0;

    XYPoint max;
    max.x = goal.x + (int)range;
    max.y = goal.y + (int)range;

    if (max.x > this->map->map_width - 1)
        max.x = this->map->map_width - 1;
    if (max.y > this->map->map_height - 1)
        max.y = this->map->map_height - 1;

    for (int x = min_x; x <= max.x; ++x) {
        int x_distance = goal.x - x;
        int y = min_y;
        if (y <= max.y) {
            int x_squared = x_distance * x_distance;
            int y_distance = goal.y - min_y;
            do {
                if (sqrtf((float)(x_squared + y_distance * y_distance)) <= range &&
                    this->zone_map_rows[y][x] == startZone)
                    return 1;
                ++y;
                --y_distance;
            } while (y <= max.y);
        }
    }
    return 0;
}

int RGE_Zone_Map::numberTilesInZone(unsigned char zone) {
    int* cached;
    int mapWidth;
    int height;
    int x;
    int count;

    cached = &this->numberTilesInZoneValue[(unsigned int)zone];
    if (*cached > 0) {
        return *cached;
    }

    mapWidth = this->map->map_width;
    height = this->map->map_height;
    count = 0;
    x = 0;
    if (mapWidth > 0) {
        do {
            if (height > 0) {
                unsigned char** row = this->zone_map_rows;
                int y = height;
                do {
                    if ((*row)[x] == zone) {
                        count++;
                    }
                    row++;
                    y--;
                } while (y != 0);
            }
            x++;
        } while (x < mapWidth);
    }
    *cached = count;
    return count;
}

int RGE_Zone_Map::findClosestPointInTerrainType(XYPoint p, XYPoint& rVal, int type1, int type2, int range) {
    int x_value = p.x;
    int y_value = p.y;
    XYPoint max;
    XYPoint min;

    min.x = x_value - range;
    min.y = y_value - range;

    if (min.x < 0) {
        min.x = 0;
    }
    if (min.y < 0) {
        min.y = 0;
    }

    max.x = x_value + range;
    max.y = y_value + range;
    if (max.x > this->map->map_width - 1) {
        max.x = this->map->map_width - 1;
    }
    if (max.y > this->map->map_height - 1) {
        max.y = this->map->map_height - 1;
    }

    int best = -1;
    if (min.x <= max.x) {
        range = x_value - min.x;
        do {
            if (min.y <= max.y) {
                int y_distance = y_value - min.y;
                int y = min.y;
                do {
                    int terrain = this->map->get_terrain((short)min.x, (short)y);
                    if (terrain == type1 || terrain == type2) {
                        int distance = range * range + y_distance * y_distance;
                        if (best == -1 || best > distance) {
                            best = distance;
                            rVal.x = min.x;
                            rVal.y = y;
                        }
                    }
                    ++y;
                    --y_distance;
                } while (y <= max.y);
            }
            ++min.x;
            --range;
        } while (min.x <= max.x);
    }

    return best != -1;
}

RGE_Zone_Map_List::RGE_Zone_Map_List(int infile, RGE_Map* in_map) {
    this->zone_maps = 0;
    this->map = in_map;
    rge_read(infile, &this->zone_map_num, 4);

    if (this->zone_map_num > 0) {
        this->zone_maps = (RGE_Zone_Map**)calloc(this->zone_map_num, 4);
        for (int i = 0; i < this->zone_map_num; i++) {
            this->zone_maps[i] = new RGE_Zone_Map(infile, this->map);
        }
    } else {
        this->zone_maps = 0;
    }
}

RGE_Zone_Map_List::RGE_Zone_Map_List(RGE_Map* in_map) {
    this->map = in_map;
    this->zone_maps = 0;
    this->zone_map_num = 0;
}

RGE_Zone_Map_List::~RGE_Zone_Map_List() {
    this->delete_zone_maps();
}

void RGE_Zone_Map_List::save(int outfile) {
    int i;

    rge_write(outfile, &zone_map_num, 4);
    if (zone_map_num > 0) {
        for (i = 0; i < zone_map_num; i++) {
            zone_maps[i]->save(outfile);
        }
    }
}

long RGE_Zone_Map_List::create_zone_map(float* new_terrain_rules, long new_terrain_rules_num) {
    long i;

    for (i = 0; i < this->zone_map_num; i++) {
        if (this->zone_maps[i]->check_info(new_terrain_rules, new_terrain_rules_num) != 0) {
            if (this->zone_maps[i]->do_zone_map() != 0)
                return i;
            i = -1;
            return i;
        }
    }

    RGE_Zone_Map** new_zone_maps = (RGE_Zone_Map**)calloc(this->zone_map_num + 1, sizeof(RGE_Zone_Map*));
    if (this->zone_maps != 0) {
        memcpy(new_zone_maps, this->zone_maps, this->zone_map_num * sizeof(RGE_Zone_Map*));
        free(this->zone_maps);
    }

    RGE_Zone_Map* new_zone_map = new RGE_Zone_Map(this->map, new_terrain_rules, new_terrain_rules_num);
    new_zone_maps[this->zone_map_num] = new_zone_map;
    this->zone_maps = new_zone_maps;
    this->zone_map_num++;
    return this->zone_map_num - 1;
}

RGE_Zone_Map* RGE_Zone_Map_List::get_zone_map(float* new_terrain_rules, long new_terrain_rules_num, int& zoneMapIndex) {
    int i = 0;
    RGE_Zone_Map** new_zone_maps;

    if (this->zone_map_num > 0) {
        while (i < this->zone_map_num) {
            if (this->zone_maps[i]->check_info(new_terrain_rules, new_terrain_rules_num) != 0) {
                zoneMapIndex = i;
                return this->zone_maps[i];
            }
            i++;
        }
    }

    new_zone_maps = (RGE_Zone_Map**)calloc(this->zone_map_num + 1, 4);
    if (this->zone_maps != 0) {
        memcpy(new_zone_maps, this->zone_maps, this->zone_map_num * 4);
        free(this->zone_maps);
    }
    new_zone_maps[this->zone_map_num] = new RGE_Zone_Map(this->map, new_terrain_rules, new_terrain_rules_num);
    this->zone_maps = new_zone_maps;
    this->zone_map_num++;
    zoneMapIndex = this->zone_map_num - 1;
    return new_zone_maps[this->zone_map_num - 1];
}

RGE_Zone_Map* RGE_Zone_Map_List::get_zone_map(long id) {
    if (id < this->zone_map_num) {
        if (id >= 0) {
            return this->zone_maps[id];
        }
    }
    return 0;
}

void RGE_Zone_Map_List::delete_zone_maps() {
    if (this->zone_maps == 0 || this->zone_map_num <= 0) {
        return;
    }
    for (long i = 0; i < this->zone_map_num; i++) {
        RGE_Zone_Map* zm = this->zone_maps[i];
        if (zm != 0) {
            delete zm;
        }
    }
    free(this->zone_maps);
    this->zone_maps = 0;
    this->zone_map_num = 0;
}
