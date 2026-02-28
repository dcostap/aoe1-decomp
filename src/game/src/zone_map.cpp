#include "../include/RGE_Zone_Map.h"
#include "../include/RGE_Zone_Map_List.h"
#include "../include/RGE_Map.h"
#include "../include/globals.h"

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <new>

struct Zone_Queue {
    Zone_Queue* next;
    long x;
    long y;
};

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00546720
static uchar zone_pop(Zone_Queue** head, Zone_Queue** tail, long* x, long* y) {
    Zone_Queue* n = *head;
    if (n == nullptr) {
        return 0;
    }
    *x = n->x;
    *y = n->y;
    *head = n->next;
    free(n);
    if (*head == nullptr) {
        *tail = nullptr;
    }
    return 1;
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00546770
static void zone_push(Zone_Queue** head, Zone_Queue** tail, long x, long y) {
    Zone_Queue* n = (Zone_Queue*)calloc(1, sizeof(Zone_Queue));
    if (*tail != nullptr) {
        (*tail)->next = n;
    }
    n->x = x;
    n->y = y;
    *tail = n;
    if (*head == nullptr) {
        *head = n;
    }
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x005467B0
RGE_Zone_Map::RGE_Zone_Map(int param_1, RGE_Map* param_2) {
    this->map = param_2;
    memset(this->numberTilesInZoneValue, 0, sizeof(this->numberTilesInZoneValue));
    memset(this->zone_info, 0xff, sizeof(this->zone_info));
    this->terrain_passability_rules = nullptr;
    this->terrain_passability_rules_num = 0;
    this->zone_map = nullptr;
    this->zone_map_rows = nullptr;

    const long map_w = this->map->map_width;
    const long map_h = this->map->map_height;
    this->zone_map = (uchar*)calloc((size_t)(map_w * map_h), 1);
    this->zone_map_rows = (uchar**)calloc((size_t)map_h, sizeof(uchar*));
    for (long y = 0; y < map_h; ++y) {
        this->zone_map_rows[y] = this->zone_map + y * map_w;
    }

    rge_read(param_1, this->zone_info, 0xff);
    rge_read(param_1, this, 0x3fc);
    rge_read(param_1, this->zone_map, map_w * map_h);

    rge_read(param_1, &this->terrain_passability_rules_num, 4);
    if (this->terrain_passability_rules_num > 0) {
        this->terrain_passability_rules = (float*)calloc((size_t)this->terrain_passability_rules_num, sizeof(float));
        rge_read(param_1, this->terrain_passability_rules, this->terrain_passability_rules_num * (long)sizeof(float));
    } else {
        this->terrain_passability_rules = nullptr;
    }
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x005468C0
RGE_Zone_Map::RGE_Zone_Map(RGE_Map* param_1, float* param_2, long param_3) {
    this->map = param_1;
    memset(this->numberTilesInZoneValue, 0, sizeof(this->numberTilesInZoneValue));
    memset(this->zone_info, 0xff, sizeof(this->zone_info));
    this->terrain_passability_rules = nullptr;
    this->terrain_passability_rules_num = 0;
    this->zone_map = nullptr;
    this->zone_map_rows = nullptr;

    const long map_w = this->map->map_width;
    const long map_h = this->map->map_height;
    this->zone_map = (uchar*)calloc((size_t)(map_w * map_h), 1);
    memset(this->zone_map, 0xff, (size_t)(map_w * map_h));
    this->zone_map_rows = (uchar**)calloc((size_t)map_h, sizeof(uchar*));
    for (long y = 0; y < map_h; ++y) {
        this->zone_map_rows[y] = this->zone_map + y * map_w;
    }

    this->terrain_passability_rules_num = param_3;
    this->terrain_passability_rules = (float*)calloc((size_t)param_3, sizeof(float));
    if (param_3 > 0) {
        memcpy(this->terrain_passability_rules, param_2, (size_t)param_3 * sizeof(float));
    }

    this->do_zone_map();
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x005469C0
RGE_Zone_Map::~RGE_Zone_Map() {
    free(this->zone_map);
    free(this->zone_map_rows);
    free(this->terrain_passability_rules);
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00546A00
void RGE_Zone_Map::save(int param_1) {
    rge_write(param_1, this->zone_info, 0xff);
    rge_write(param_1, this, 0x3fc);
    rge_write(param_1, this->zone_map, this->map->map_height * this->map->map_width);
    rge_write(param_1, &this->terrain_passability_rules_num, 4);
    if (this->terrain_passability_rules_num > 0) {
        rge_write(param_1, this->terrain_passability_rules, this->terrain_passability_rules_num * (int)sizeof(float));
    }
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00546A90
uchar RGE_Zone_Map::do_zone_map() {
    const long map_w = this->map->map_width;
    const long map_h = this->map->map_height;

    memset(this->zone_info, 0xff, sizeof(this->zone_info));
    memset(this->zone_map, 0xff, (size_t)(map_w * map_h));

    int zone_id = 0;
    for (long y = 0; y < map_h; ++y) {
        for (long x = 0; x < map_w; ++x) {
            if (this->zone_map_rows[y][x] != 0xff) {
                continue;
            }
            if (zone_id > 0xfe) {
                zone_id = 0;
            }
            const uchar tt = (uchar)(this->map->map_row_offset[y][x].terrain_type & 0x1f);
            uchar passable = 0;
            if (this->terrain_passability_rules[tt] > 0.0f) {
                passable = 1;
            }
            this->zone_map_rows[y][x] = (uchar)zone_id;
            this->do_zone_map_area(x, y, passable, (uchar)zone_id);
            zone_id++;
        }
    }
    return 1;
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00546BB0
void RGE_Zone_Map::do_zone_map_area(long param_1, long param_2, uchar param_3, uchar param_4) {
    const long max_x = this->map->map_width - 1;
    const long max_y = this->map->map_height - 1;
    Zone_Queue* queue_head = nullptr;
    Zone_Queue* queue_tail = nullptr;

    long x = param_1;
    long y = param_2;
    do {
        if (x > 0) {
            long nx = x - 1;
            long ny = y;
            if (this->zone_map_rows[ny][nx] == 0xff) {
                const uchar tt = (uchar)(this->map->map_row_offset[ny][nx].terrain_type & 0x1f);
                uchar passable = 0;
                if (this->terrain_passability_rules[tt] > 0.0f) {
                    passable = 1;
                }
                if (passable == param_3) {
                    this->zone_map_rows[ny][nx] = param_4;
                    zone_push(&queue_head, &queue_tail, nx, ny);
                }
            }
        }
        if (y > 0) {
            long nx = x;
            long ny = y - 1;
            if (this->zone_map_rows[ny][nx] == 0xff) {
                const uchar tt = (uchar)(this->map->map_row_offset[ny][nx].terrain_type & 0x1f);
                uchar passable = 0;
                if (this->terrain_passability_rules[tt] > 0.0f) {
                    passable = 1;
                }
                if (passable == param_3) {
                    this->zone_map_rows[ny][nx] = param_4;
                    zone_push(&queue_head, &queue_tail, nx, ny);
                }
            }
        }
        if (x < max_x) {
            long nx = x + 1;
            long ny = y;
            if (this->zone_map_rows[ny][nx] == 0xff) {
                const uchar tt = (uchar)(this->map->map_row_offset[ny][nx].terrain_type & 0x1f);
                uchar passable = 0;
                if (this->terrain_passability_rules[tt] > 0.0f) {
                    passable = 1;
                }
                if (passable == param_3) {
                    this->zone_map_rows[ny][nx] = param_4;
                    zone_push(&queue_head, &queue_tail, nx, ny);
                }
            }
        }
        if (y < max_y) {
            long nx = x;
            long ny = y + 1;
            if (this->zone_map_rows[ny][nx] == 0xff) {
                const uchar tt = (uchar)(this->map->map_row_offset[ny][nx].terrain_type & 0x1f);
                uchar passable = 0;
                if (this->terrain_passability_rules[tt] > 0.0f) {
                    passable = 1;
                }
                if (passable == param_3) {
                    this->zone_map_rows[ny][nx] = param_4;
                    zone_push(&queue_head, &queue_tail, nx, ny);
                }
            }
        }
    } while (zone_pop(&queue_head, &queue_tail, &x, &y) != 0);
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00546E50
RGE_Zone_Map* RGE_Zone_Map::check_info(float* param_1, long param_2) {
    if (param_2 != this->terrain_passability_rules_num) {
        return nullptr;
    }
    for (long i = 0; i < param_2; ++i) {
        const int a = (param_1[i] > 0.0f) ? 1 : 0;
        const int b = (this->terrain_passability_rules[i] > 0.0f) ? 1 : 0;
        if (a != b) {
            return nullptr;
        }
    }
    return this;
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00546EB0
uchar RGE_Zone_Map::get_zone_info(long param_1, long param_2) {
    return this->zone_map_rows[param_2][param_1];
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00546ED0
int RGE_Zone_Map::withinRange(XYPoint param_1, XYPoint param_2, float param_3) {
    return this->withinRange(this->zone_map_rows[param_1.y][param_1.x], param_2, param_3);
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00546F00
int RGE_Zone_Map::withinRange(uchar param_1, XYPoint param_2, float param_3) {
    int r = (int)param_3;
    int min_x = param_2.x - r;
    int min_y = param_2.y - r;
    if (min_x < 0) min_x = 0;
    if (min_y < 0) min_y = 0;

    int max_x = param_2.x + r;
    int max_y = param_2.y + r;
    if (max_x > this->map->map_width - 1) max_x = this->map->map_width - 1;
    if (max_y > this->map->map_height - 1) max_y = this->map->map_height - 1;

    for (int x = min_x; x <= max_x; ++x) {
        int dx = param_2.x - x;
        for (int y = min_y; y <= max_y; ++y) {
            int dy = param_2.y - y;
            if (std::sqrt((float)(dx * dx + dy * dy)) <= param_3 && this->zone_map_rows[y][x] == param_1) {
                return 1;
            }
        }
    }
    return 0;
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00547000
int RGE_Zone_Map::numberTilesInZone(uchar param_1) {
    const unsigned int zone = (unsigned int)param_1;
    int cached = this->numberTilesInZoneValue[zone];
    if (cached < 1) {
        int count = 0;
        for (long y = 0; y < this->map->map_height; ++y) {
            for (long x = 0; x < this->map->map_width; ++x) {
                if (this->zone_map_rows[y][x] == param_1) {
                    count++;
                }
            }
        }
        this->numberTilesInZoneValue[zone] = count;
        cached = count;
    }
    return cached;
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00547080
int RGE_Zone_Map::findClosestPointInTerrainType(
    XYPoint param_1,
    XYPoint* param_2,
    int param_3,
    int param_4,
    int param_5) {
    int min_x = param_1.x - param_5;
    int min_y = param_1.y - param_5;
    if (min_x < 0) min_x = 0;
    if (min_y < 0) min_y = 0;

    int max_x = param_1.x + param_5;
    int max_y = param_1.y + param_5;
    if (max_x > this->map->map_width - 1) max_x = this->map->map_width - 1;
    if (max_y > this->map->map_height - 1) max_y = this->map->map_height - 1;

    int best_d2 = -1;
    for (int x = min_x; x <= max_x; ++x) {
        int dx = param_1.x - x;
        for (int y = min_y; y <= max_y; ++y) {
            int dy = param_1.y - y;
            uchar tt = this->map->get_terrain((short)x, (short)y);
            if ((int)tt == param_3 || (int)tt == param_4) {
                int d2 = dx * dx + dy * dy;
                if (best_d2 == -1 || d2 < best_d2) {
                    best_d2 = d2;
                    param_2->x = x;
                    param_2->y = y;
                }
            }
        }
    }

    return (best_d2 != -1) ? 1 : 0;
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00547180
RGE_Zone_Map_List::RGE_Zone_Map_List(int param_1, RGE_Map* param_2) {
    this->zone_maps = nullptr;
    this->zone_map_num = 0;
    this->map = param_2;

    rge_read(param_1, &this->zone_map_num, 4);
    if (this->zone_map_num > 0) {
        this->zone_maps = (RGE_Zone_Map**)calloc((size_t)this->zone_map_num, sizeof(RGE_Zone_Map*));
        for (long i = 0; i < this->zone_map_num; ++i) {
            this->zone_maps[i] = new (std::nothrow) RGE_Zone_Map(param_1, this->map);
        }
    }
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00547240
RGE_Zone_Map_List::RGE_Zone_Map_List(RGE_Map* param_1) {
    this->map = param_1;
    this->zone_maps = nullptr;
    this->zone_map_num = 0;
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00547260
RGE_Zone_Map_List::~RGE_Zone_Map_List() {
    this->delete_zone_maps();
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x00547270
void RGE_Zone_Map_List::save(int param_1) {
    rge_write(param_1, &this->zone_map_num, 4);
    if (this->zone_map_num > 0) {
        for (long i = 0; i < this->zone_map_num; ++i) {
            this->zone_maps[i]->save(param_1);
        }
    }
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x005472B0
long RGE_Zone_Map_List::create_zone_map(float* param_1, long param_2) {
    for (long i = 0; i < this->zone_map_num; ++i) {
        RGE_Zone_Map* zm = this->zone_maps[i];
        if (zm->check_info(param_1, param_2) != nullptr) {
            return (zm->do_zone_map() != 0) ? i : -1;
        }
    }

    RGE_Zone_Map** next = (RGE_Zone_Map**)calloc((size_t)(this->zone_map_num + 1), sizeof(RGE_Zone_Map*));
    if (this->zone_maps != nullptr) {
        memcpy(next, this->zone_maps, (size_t)this->zone_map_num * sizeof(RGE_Zone_Map*));
        free(this->zone_maps);
    }

    RGE_Zone_Map* created = new (std::nothrow) RGE_Zone_Map(this->map, param_1, param_2);
    next[this->zone_map_num] = created;
    long index = this->zone_map_num;
    this->zone_maps = next;
    this->zone_map_num = this->zone_map_num + 1;
    return index;
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x005473B0
RGE_Zone_Map* RGE_Zone_Map_List::get_zone_map(float* param_1, long param_2, int* param_3) {
    for (long i = 0; i < this->zone_map_num; ++i) {
        RGE_Zone_Map* zm = this->zone_maps[i];
        if (zm->check_info(param_1, param_2) != nullptr) {
            *param_3 = (int)i;
            return zm;
        }
    }

    RGE_Zone_Map** next = (RGE_Zone_Map**)calloc((size_t)(this->zone_map_num + 1), sizeof(RGE_Zone_Map*));
    if (this->zone_maps != nullptr) {
        memcpy(next, this->zone_maps, (size_t)this->zone_map_num * sizeof(RGE_Zone_Map*));
        free(this->zone_maps);
    }

    RGE_Zone_Map* created = new (std::nothrow) RGE_Zone_Map(this->map, param_1, param_2);
    next[this->zone_map_num] = created;
    long idx = this->zone_map_num;
    this->zone_maps = next;
    this->zone_map_num = this->zone_map_num + 1;
    *param_3 = (int)idx;
    return created;
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x005474B0
RGE_Zone_Map* RGE_Zone_Map_List::get_zone_map(long param_1) {
    if (param_1 < 0 || param_1 >= this->zone_map_num) {
        return nullptr;
    }
    return this->zone_maps[param_1];
}

// Fully verified. Source of truth: zone_map.cpp.decomp @ 0x005474D0
void RGE_Zone_Map_List::delete_zone_maps() {
    if (this->zone_maps != nullptr && this->zone_map_num > 0) {
        for (long i = 0; i < this->zone_map_num; ++i) {
            if (this->zone_maps[i] != nullptr) {
                delete this->zone_maps[i];
            }
        }
        free(this->zone_maps);
        this->zone_maps = nullptr;
        this->zone_map_num = 0;
    }
}
