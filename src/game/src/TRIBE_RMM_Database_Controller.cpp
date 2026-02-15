#include "../include/TRIBE_RMM_Database_Controller.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map_Data_Entry.h"
#include "../include/RGE_Land_Data.h"
#include "../include/RGE_Land_Data_Entry.h"
#include "../include/RGE_Terrain_Data.h"
#include "../include/RGE_Terrain_Data_Entry.h"
#include "../include/RGE_Object_Data.h"
#include "../include/RGE_Object_Data_Entry.h"
#include "../include/RGE_Elevation_Data.h"
#include "../include/RGE_Elevation_Data_Entry.h"
#include "../include/RGE_Player.h"
#include "../include/TRIBE_Game.h"
#include "../include/custom_debug.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long g_rmm_fail_search_closed = 0;
static long g_rmm_fail_terrain_mismatch = 0;
static long g_rmm_fail_no_player = 0;
static long g_rmm_fail_no_master_array = 0;
static long g_rmm_fail_objid_oob = 0;
static long g_rmm_fail_master_null = 0;
static long g_rmm_fail_make_new = 0;

static long rmm_clamp_long(long v, long lo, long hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static long rmm_rand_range(long max_value) {
    if (max_value <= 0) {
        return 0;
    }
    unsigned int r = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp", 0x100);
    return (long)((r * (unsigned int)max_value) / 0x8000u);
}

static uchar rmm_clamp_terrain(long terrain) {
    if (terrain < 0) terrain = 0;
    return (uchar)(terrain & 0x1f);
}

static uchar rmm_pick_loaded_terrain(RGE_Map* map, uchar preferred, uchar secondary) {
    if (map != nullptr) {
        if (preferred < 32) {
            RGE_Tile_Set* ts = &map->terrain_types[preferred];
            if (ts->loaded && ts->shape != nullptr) {
                return preferred;
            }
        }
        if (secondary < 32) {
            RGE_Tile_Set* ts = &map->terrain_types[secondary];
            if (ts->loaded && ts->shape != nullptr) {
                return secondary;
            }
        }
        int terrain_num = map->num_terrain;
        if (terrain_num < 0) terrain_num = 0;
        if (terrain_num > 32) terrain_num = 32;
        for (int i = 0; i < terrain_num; ++i) {
            RGE_Tile_Set* ts = &map->terrain_types[i];
            if (ts->loaded && ts->shape != nullptr) {
                return (uchar)i;
            }
        }
    }
    return 0;
}

static int rmm_is_water_terrain(uchar terrain_type) {
    return terrain_type == 1 || terrain_type == 4 || terrain_type == 22;
}

static long rmm_count_terrain_tiles(RGE_RMM_Database_Controller* self, uchar terrain_type) {
    if (self == nullptr || self->map_row_offset == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return 0;
    }
    long count = 0;
    terrain_type = rmm_clamp_terrain(terrain_type);
    for (long y = 0; y < self->map_height; ++y) {
        for (long x = 0; x < self->map_width; ++x) {
            if ((self->map_row_offset[y][x].terrain_type & 0x1f) == terrain_type) {
                ++count;
            }
        }
    }
    return count;
}

static void rmm_fill_search_map(RGE_RMM_Database_Controller* self, uchar value) {
    if (self == nullptr || self->search_map_rows == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return;
    }
    for (long y = 0; y < self->map_height; ++y) {
        memset(self->search_map_rows[y], value, (size_t)self->map_width);
    }
}

static int rmm_search_open(RGE_RMM_Database_Controller* self, long x, long y) {
    if (self == nullptr || x < 0 || y < 0 || x >= self->map_width || y >= self->map_height) {
        return 0;
    }
    if (self->search_map_rows == nullptr) {
        return 1;
    }
    return self->search_map_rows[y][x] != 0;
}

static void rmm_set_search_area(RGE_RMM_Database_Controller* self, long cx, long cy, long radius, uchar value) {
    if (self == nullptr || self->search_map_rows == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return;
    }
    if (radius < 0) {
        radius = 0;
    }
    long x0 = rmm_clamp_long(cx - radius, 0, self->map_width - 1);
    long x1 = rmm_clamp_long(cx + radius, 0, self->map_width - 1);
    long y0 = rmm_clamp_long(cy - radius, 0, self->map_height - 1);
    long y1 = rmm_clamp_long(cy + radius, 0, self->map_height - 1);
    for (long y = y0; y <= y1; ++y) {
        memset(self->search_map_rows[y] + x0, value, (size_t)(x1 - x0 + 1));
    }
}

static RGE_Player* rmm_get_player_for_object(RGE_RMM_Database_Controller* self, long requested_player, long fallback_player) {
    if (self == nullptr || self->world == nullptr || self->world->players == nullptr || self->world->player_num <= 0) {
        return nullptr;
    }

    long player_index = requested_player;
    if (player_index < 0) {
        player_index = fallback_player;
    }
    if (player_index < 0 || player_index >= self->world->player_num) {
        player_index = 0;
    }
    return self->world->players[player_index];
}

static int rmm_terrain_matches_object_rule(RGE_RMM_Database_Controller* self, RGE_Object_Info_Line* line, long x, long y) {
    if (self == nullptr || line == nullptr || self->map_row_offset == nullptr || x < 0 || y < 0 || x >= self->map_width || y >= self->map_height) {
        return 0;
    }
    if (line->terrain < 0) {
        return 1;
    }
    return (self->map_row_offset[y][x].terrain_type & 0x1f) == (line->terrain & 0x1f);
}

static int rmm_try_place_single_object(
    RGE_RMM_Database_Controller* self,
    RGE_Object_Info_Line* line,
    long x,
    long y,
    long requested_player,
    long fallback_player,
    long exclusion_radius) {
    if (self == nullptr || line == nullptr) {
        return 0;
    }
    if (x < 0 || y < 0 || x >= self->map_width || y >= self->map_height) {
        return 0;
    }
    if (!rmm_search_open(self, x, y)) {
        g_rmm_fail_search_closed = g_rmm_fail_search_closed + 1;
        return 0;
    }
    if (!rmm_terrain_matches_object_rule(self, line, x, y)) {
        g_rmm_fail_terrain_mismatch = g_rmm_fail_terrain_mismatch + 1;
        return 0;
    }

    RGE_Player* player = rmm_get_player_for_object(self, requested_player, fallback_player);
    if (player == nullptr) {
        g_rmm_fail_no_player = g_rmm_fail_no_player + 1;
        return 0;
    }
    if (player->master_objects == nullptr) {
        g_rmm_fail_no_master_array = g_rmm_fail_no_master_array + 1;
        return 0;
    }
    if (line->obj_id < 0 || line->obj_id >= player->master_object_num) {
        g_rmm_fail_objid_oob = g_rmm_fail_objid_oob + 1;
        return 0;
    }
    if (player->master_objects[line->obj_id] == nullptr) {
        g_rmm_fail_master_null = g_rmm_fail_master_null + 1;
        return 0;
    }

    RGE_Static_Object* placed = player->make_new_object(line->obj_id, (float)x + 0.5f, (float)y + 0.5f, 0.0f, 1);
    if (placed == nullptr) {
        g_rmm_fail_make_new = g_rmm_fail_make_new + 1;
        return 0;
    }

    if (exclusion_radius < 1) {
        exclusion_radius = 1;
    }
    rmm_set_search_area(self, x, y, exclusion_radius, 0);
    return 1;
}

static long rmm_place_group_objects(
    RGE_RMM_Database_Controller* self,
    RGE_Object_Info_Line* line,
    long root_x,
    long root_y,
    long requested_player,
    long fallback_player,
    long exclusion_radius) {
    if (self == nullptr || line == nullptr || line->group_flag == 0) {
        return 0;
    }

    long group_count = line->object_number_per_group;
    long var = line->object_number_varience;
    if (var < 0) {
        var = 0;
    }
    if (var > 0) {
        long rv = rmm_rand_range(var * 2 + 1);
        group_count += rv - var;
    }
    if (group_count < 1) {
        group_count = 1;
    }

    long area = line->group_area;
    if (area < 1) {
        area = 1;
    }
    if (line->group_flag == 2) {
        area *= 2;
    }

    long placed = 0;
    for (long n = 0; n < group_count; ++n) {
        int done = 0;
        for (long attempt = 0; attempt < 12 && !done; ++attempt) {
            long dx = rmm_rand_range(area * 2 + 1) - area;
            long dy = rmm_rand_range(area * 2 + 1) - area;
            long x = root_x + dx;
            long y = root_y + dy;
            if (rmm_try_place_single_object(self, line, x, y, requested_player, fallback_player, exclusion_radius)) {
                ++placed;
                done = 1;
            }
        }
    }

    return placed;
}

static long rmm_place_objects_pass(RGE_RMM_Database_Controller* self) {
    if (self == nullptr || self->map_row_offset == nullptr || self->map_width <= 0 || self->map_height <= 0 || self->object_info.object_num <= 0) {
        return 0;
    }

    long total_placed = 0;
    g_rmm_fail_search_closed = 0;
    g_rmm_fail_terrain_mismatch = 0;
    g_rmm_fail_no_player = 0;
    g_rmm_fail_no_master_array = 0;
    g_rmm_fail_objid_oob = 0;
    g_rmm_fail_master_null = 0;
    g_rmm_fail_make_new = 0;

    long map_area = self->map_width * self->map_height;
    if (map_area < 1) {
        map_area = 1;
    }

    for (long i = 0; i < self->object_info.object_num; ++i) {
        RGE_Object_Info_Line line = self->object_info.objects[i];
        if (line.obj_id < 0) {
            continue;
        }

        if (line.scale_flag != 0) {
            long scaled = (map_area * line.number_of_groups) / 0x5100;
            if (scaled < 1) {
                scaled = 1;
            }
            line.number_of_groups = scaled;
        }

        long groups = line.number_of_groups;
        if (groups < 1) {
            continue;
        }

        long exclusion = line.object_exclusion_zone;
        if (exclusion < 1) {
            exclusion = 1;
        }

        rmm_fill_search_map(self, 1);

        if (line.land_id == -2) {
            for (long li = 0; li < self->object_info.land_num; ++li) {
                RGE_Land_Point_Info_Line* land = &self->object_info.lands[li];
                rmm_set_search_area(self, land->x, land->y, line.land_inner_radius, 0);
            }
        }

        long placed_for_line = 0;

        if (line.land_id >= 0) {
            for (long li = 0; li < self->object_info.land_num; ++li) {
                RGE_Land_Point_Info_Line* land = &self->object_info.lands[li];
                if (land->id != line.land_id) {
                    continue;
                }

                long outer = line.land_outer_radius;
                if (outer < 1) {
                    outer = 6;
                }
                long inner = line.land_inner_radius;
                if (inner < 0) {
                    inner = 0;
                }

                for (long g = 0; g < groups; ++g) {
                    int done = 0;
                    for (long attempt = 0; attempt < 64 && !done; ++attempt) {
                        long dx = rmm_rand_range(outer * 2 + 1) - outer;
                        long dy = rmm_rand_range(outer * 2 + 1) - outer;
                        if (abs((int)dx) < inner && abs((int)dy) < inner) {
                            continue;
                        }

                        long x = land->x + dx;
                        long y = land->y + dy;
                        long req_player = (line.player_id >= 0) ? line.player_id : land->player_id;
                        if (rmm_try_place_single_object(self, &line, x, y, req_player, 0, exclusion)) {
                            ++placed_for_line;
                            placed_for_line += rmm_place_group_objects(self, &line, x, y, req_player, 0, exclusion);
                            done = 1;
                        }
                    }
                }
            }
        } else {
            long base_tries = groups * 32;
            if (base_tries < 128) {
                base_tries = 128;
            }
            if (base_tries > map_area * 2) {
                base_tries = map_area * 2;
            }

            for (long g = 0; g < groups; ++g) {
                int done = 0;
                for (long attempt = 0; attempt < base_tries && !done; ++attempt) {
                    long x = rmm_rand_range(self->map_width);
                    long y = rmm_rand_range(self->map_height);
                    if (rmm_try_place_single_object(self, &line, x, y, line.player_id, 0, exclusion)) {
                        ++placed_for_line;
                        placed_for_line += rmm_place_group_objects(self, &line, x, y, line.player_id, 0, exclusion);
                        done = 1;
                    }
                }
            }
        }

        total_placed += placed_for_line;
        CUSTOM_DEBUG_LOG_FMT(
            "  object[%ld]: obj=%ld groups=%ld land=%ld placed=%ld",
            i,
            line.obj_id,
            line.number_of_groups,
            line.land_id,
            placed_for_line);
    }

    CUSTOM_DEBUG_LOG_FMT(
        "  placement_failures: search_closed=%ld terrain_mismatch=%ld no_player=%ld no_master_array=%ld objid_oob=%ld master_null=%ld make_new_null=%ld",
        g_rmm_fail_search_closed,
        g_rmm_fail_terrain_mismatch,
        g_rmm_fail_no_player,
        g_rmm_fail_no_master_array,
        g_rmm_fail_objid_oob,
        g_rmm_fail_master_null,
        g_rmm_fail_make_new);

    return total_placed;
}

static void rmm_free_map_data(RGE_RMM_Database_Controller* self) {
    if (self == nullptr) {
        return;
    }
    if (self->map_info.maps == nullptr || self->map_info.map_num <= 0) {
        self->map_info.maps = nullptr;
        self->map_info.map_num = 0;
        return;
    }

    for (long i = 0; i < self->map_info.map_num; ++i) {
        RGE_Map_Data_Entry* map_entry = &self->map_info.maps[i];
        if (map_entry->land_info.land_num > 0 && map_entry->land_info.land != nullptr) {
            free(map_entry->land_info.land);
            map_entry->land_info.land = nullptr;
        }
        if (map_entry->terrain_info.terrain_num > 0 && map_entry->terrain_info.terrain != nullptr) {
            free(map_entry->terrain_info.terrain);
            map_entry->terrain_info.terrain = nullptr;
        }
        if (map_entry->object_info.object_num > 0 && map_entry->object_info.objects != nullptr) {
            free(map_entry->object_info.objects);
            map_entry->object_info.objects = nullptr;
        }
        if (map_entry->elevation_info.elevation_num > 0 && map_entry->elevation_info.elevation != nullptr) {
            free(map_entry->elevation_info.elevation);
            map_entry->elevation_info.elevation = nullptr;
        }
    }

    free(self->map_info.maps);
    self->map_info.maps = nullptr;
    self->map_info.map_num = 0;
}

static RGE_Map_Data_Entry* rmm_select_map_entry(RGE_RMM_Database_Controller* self) {
    if (self == nullptr || self->map_info.maps == nullptr || self->map_info.map_num <= 0) {
        return nullptr;
    }
    // Source of truth: rmm_dbct.cpp.decomp
    // Original code indexes maps directly with map_type.
    if (self->map_type >= 0 && self->map_type < self->map_info.map_num) {
        return &self->map_info.maps[self->map_type];
    }

    return &self->map_info.maps[0];
}

static long rmm_paint_disk(
    RGE_RMM_Database_Controller* self,
    long cx,
    long cy,
    long radius,
    uchar terrain_type,
    int use_base_filter,
    uchar base_filter) {
    if (self == nullptr || self->map_row_offset == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return 0;
    }

    if (radius < 1) radius = 1;
    terrain_type = rmm_clamp_terrain((long)terrain_type);
    base_filter = rmm_clamp_terrain((long)base_filter);

    long changed = 0;
    long radius_sq = radius * radius;
    long y0 = rmm_clamp_long(cy - radius, 0, self->map_height - 1);
    long y1 = rmm_clamp_long(cy + radius, 0, self->map_height - 1);

    for (long y = y0; y <= y1; ++y) {
        long dy = y - cy;
        long x_span_sq = radius_sq - dy * dy;
        if (x_span_sq < 0) {
            continue;
        }

        long x_span = (long)sqrt((double)x_span_sq);
        long x0 = rmm_clamp_long(cx - x_span, 0, self->map_width - 1);
        long x1 = rmm_clamp_long(cx + x_span, 0, self->map_width - 1);

        for (long x = x0; x <= x1; ++x) {
            RGE_Tile* tile = &self->map_row_offset[y][x];
            uchar cur = (uchar)(tile->terrain_type & 0x1f);
            if (use_base_filter && cur != base_filter) {
                continue;
            }
            if (cur != terrain_type) {
                tile->terrain_type = terrain_type;
                ++changed;
            }
        }
    }

    return changed;
}

static long rmm_raise_disk(
    RGE_RMM_Database_Controller* self,
    long cx,
    long cy,
    long radius,
    uchar target_height,
    int use_base_terrain_filter,
    uchar base_terrain_filter,
    int use_base_height_filter,
    uchar base_height_filter) {
    if (self == nullptr || self->map_row_offset == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return 0;
    }

    if (radius < 1) radius = 1;
    if (target_height > 7) target_height = 7;
    if (base_height_filter > 7) base_height_filter = 7;

    long changed = 0;
    long radius_sq = radius * radius;
    long y0 = rmm_clamp_long(cy - radius, 0, self->map_height - 1);
    long y1 = rmm_clamp_long(cy + radius, 0, self->map_height - 1);

    for (long y = y0; y <= y1; ++y) {
        long dy = y - cy;
        long x_span_sq = radius_sq - dy * dy;
        if (x_span_sq < 0) {
            continue;
        }

        long x_span = (long)sqrt((double)x_span_sq);
        long x0 = rmm_clamp_long(cx - x_span, 0, self->map_width - 1);
        long x1 = rmm_clamp_long(cx + x_span, 0, self->map_width - 1);

        for (long x = x0; x <= x1; ++x) {
            RGE_Tile* tile = &self->map_row_offset[y][x];
            uchar cur_tt = (uchar)(tile->terrain_type & 0x1f);
            if (use_base_terrain_filter && cur_tt != base_terrain_filter) {
                continue;
            }
            if (use_base_height_filter && tile->height < base_height_filter) {
                continue;
            }
            if (tile->height < target_height) {
                tile->height = target_height;
                ++changed;
            }
        }
    }

    return changed;
}

static int rmm_max_height_step(RGE_RMM_Database_Controller* self) {
    if (self == nullptr || self->map_row_offset == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return 0;
    }

    int max_step = 0;
    for (long y = 0; y < self->map_height; ++y) {
        for (long x = 0; x < self->map_width; ++x) {
            int h = (int)self->map_row_offset[y][x].height;
            if (x + 1 < self->map_width) {
                int hr = (int)self->map_row_offset[y][x + 1].height;
                int d = h - hr;
                if (d < 0) d = -d;
                if (d > max_step) max_step = d;
            }
            if (y + 1 < self->map_height) {
                int hb = (int)self->map_row_offset[y + 1][x].height;
                int d = h - hb;
                if (d < 0) d = -d;
                if (d > max_step) max_step = d;
            }
        }
    }
    return max_step;
}

// Non-original stabilization pass:
// keep local elevation transitions within one step so tile_type slope pieces can cover seams.
static void rmm_smooth_elevation(RGE_RMM_Database_Controller* self, int max_iters) {
    if (self == nullptr || self->map_row_offset == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return;
    }
    if (max_iters < 1) {
        max_iters = 1;
    }

    const long w = self->map_width;
    const long h = self->map_height;
    const long area = w * h;
    if (area <= 0) {
        return;
    }

    uchar* old_h = (uchar*)malloc((size_t)area);
    if (old_h == nullptr) {
        return;
    }

    for (int it = 0; it < max_iters; ++it) {
        for (long y = 0; y < h; ++y) {
            for (long x = 0; x < w; ++x) {
                old_h[y * w + x] = self->map_row_offset[y][x].height;
            }
        }

        long changed = 0;
        for (long y = 0; y < h; ++y) {
            for (long x = 0; x < w; ++x) {
                int cur = (int)old_h[y * w + x];
                int max_n = cur;
                int min_n = cur;

                for (long dy = -1; dy <= 1; ++dy) {
                    for (long dx = -1; dx <= 1; ++dx) {
                        if (dx == 0 && dy == 0) continue;
                        long nx = x + dx;
                        long ny = y + dy;
                        if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;

                        int nh = (int)old_h[ny * w + nx];
                        if (nh > max_n) max_n = nh;
                        if (nh < min_n) min_n = nh;
                    }
                }

                int lower = max_n - 1;
                int upper = min_n + 1;
                if (lower < 0) lower = 0;
                if (upper > 7) upper = 7;

                int next = cur;
                if (lower > upper) {
                    // Inconsistent neighborhood: move toward midpoint to converge in later passes.
                    next = (max_n + min_n) / 2;
                } else {
                    if (next < lower) next = lower;
                    if (next > upper) next = upper;
                }

                if (next < 0) next = 0;
                if (next > 7) next = 7;

                if (next != cur) {
                    self->map_row_offset[y][x].height = (uchar)next;
                    changed++;
                }
            }
        }

        if (changed == 0) {
            break;
        }
    }

    free(old_h);
}

static void rmm_log_terrain_histogram(RGE_RMM_Database_Controller* self, const char* tag) {
    if (self == nullptr || self->map_row_offset == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return;
    }

    long counts[32];
    memset(counts, 0, sizeof(counts));
    for (long y = 0; y < self->map_height; ++y) {
        for (long x = 0; x < self->map_width; ++x) {
            uchar tt = (uchar)(self->map_row_offset[y][x].terrain_type & 0x1f);
            counts[tt]++;
        }
    }

    long non_zero = 0;
    for (int i = 0; i < 32; ++i) {
        if (counts[i] != 0) non_zero++;
    }
    CUSTOM_DEBUG_LOG_FMT("%s: terrain types used=%ld", tag, non_zero);
    for (int i = 0; i < 32; ++i) {
        if (counts[i] > 0) {
            CUSTOM_DEBUG_LOG_FMT("  terrain[%d]=%ld", i, counts[i]);
        }
    }
}

static void rmm_log_height_histogram(RGE_RMM_Database_Controller* self, const char* tag) {
    if (self == nullptr || self->map_row_offset == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return;
    }

    long counts[8];
    memset(counts, 0, sizeof(counts));
    uchar min_h = 7;
    uchar max_h = 0;

    for (long y = 0; y < self->map_height; ++y) {
        for (long x = 0; x < self->map_width; ++x) {
            uchar h = self->map_row_offset[y][x].height;
            if (h > 7) h = 7;
            counts[h]++;
            if (h < min_h) min_h = h;
            if (h > max_h) max_h = h;
        }
    }

    CUSTOM_DEBUG_LOG_FMT("%s: height range=%u..%u", tag, (unsigned int)min_h, (unsigned int)max_h);
    for (int i = 0; i < 8; ++i) {
        if (counts[i] > 0) {
            CUSTOM_DEBUG_LOG_FMT("  height[%d]=%ld", i, counts[i]);
        }
    }
}

static void rmm_log_tile_type_histogram(RGE_RMM_Database_Controller* self, const char* tag) {
    if (self == nullptr || self->map_row_offset == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return;
    }

    long counts[32];
    memset(counts, 0, sizeof(counts));
    for (long y = 0; y < self->map_height; ++y) {
        for (long x = 0; x < self->map_width; ++x) {
            uchar tt = self->map_row_offset[y][x].tile_type;
            if (tt < 32) {
                counts[tt]++;
            }
        }
    }

    long non_zero = 0;
    for (int i = 0; i < 32; ++i) {
        if (counts[i] != 0) non_zero++;
    }
    CUSTOM_DEBUG_LOG_FMT("%s: tile types used=%ld", tag, non_zero);
    for (int i = 0; i < 32; ++i) {
        if (counts[i] > 0) {
            CUSTOM_DEBUG_LOG_FMT("  tile_type[%d]=%ld", i, counts[i]);
        }
    }
}

static void rmm_log_border_histogram(RGE_RMM_Database_Controller* self, const char* tag) {
    if (self == nullptr || self->map_row_offset == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return;
    }

    long type_counts[16];
    long shape_counts[16];
    memset(type_counts, 0, sizeof(type_counts));
    memset(shape_counts, 0, sizeof(shape_counts));

    for (long y = 0; y < self->map_height; ++y) {
        for (long x = 0; x < self->map_width; ++x) {
            RGE_Tile* t = &self->map_row_offset[y][x];
            if (t->border_type < 16) {
                type_counts[t->border_type]++;
            }
            if (t->border_shape < 16) {
                shape_counts[t->border_shape]++;
            }
        }
    }

    long non_zero_types = 0;
    for (int i = 0; i < 16; ++i) {
        if (type_counts[i] > 0) non_zero_types++;
    }
    CUSTOM_DEBUG_LOG_FMT("%s: border types used=%ld", tag, non_zero_types);
    for (int i = 0; i < 16; ++i) {
        if (type_counts[i] > 0) {
            CUSTOM_DEBUG_LOG_FMT("  border_type[%d]=%ld", i, type_counts[i]);
        }
    }

    long non_zero_shapes = 0;
    for (int i = 0; i < 16; ++i) {
        if (shape_counts[i] > 0) non_zero_shapes++;
    }
    CUSTOM_DEBUG_LOG_FMT("%s: border shapes used=%ld", tag, non_zero_shapes);
    for (int i = 0; i < 16; ++i) {
        if (shape_counts[i] > 0) {
            CUSTOM_DEBUG_LOG_FMT("  border_shape[%d]=%ld", i, shape_counts[i]);
        }
    }
}

RGE_Random_Map_Module::RGE_Random_Map_Module()
    : RGE_Random_Map_Module(nullptr, nullptr, 0) {
}

RGE_Random_Map_Module::RGE_Random_Map_Module(RGE_Map* param_1, RGE_Random_Map_Module* param_2, uchar param_3) {
    this->parent = param_2;
    this->list = nullptr;
    this->map = param_1;
    this->schedule = 0.0f;

    if (param_1 == nullptr) {
        this->map_row_offset = nullptr;
        this->map_width = 0;
        this->map_height = 0;
    } else {
        this->map_row_offset = param_1->map_row_offset;
        this->map_width = param_1->map_width;
        this->map_height = param_1->map_height;
    }

    this->search_map = nullptr;
    this->search_map_rows = nullptr;
    this->stack_array = nullptr;
    this->stack_offsets = nullptr;

    if (this->parent == nullptr) {
        if (param_3 != 0) {
            this->create_shared_resources();
        }
    } else {
        this->parent->add_module(this);
        this->parent->share_resources(&this->search_map, &this->search_map_rows, &this->stack_array, &this->stack_offsets);
    }
}

RGE_Random_Map_Module::~RGE_Random_Map_Module() {
    while (this->list != nullptr) {
        RGE_Random_Map_Module_List* head = this->list;
        RGE_Random_Map_Module* child = head->module;
        if (child != nullptr) {
            delete child;
        } else {
            this->list = head->next;
            free(head);
        }
    }

    if (this->parent != nullptr) {
        this->parent->remove_module(this);
        this->search_map = nullptr;
        this->search_map_rows = nullptr;
        this->stack_array = nullptr;
        this->stack_offsets = nullptr;
        this->map = nullptr;
        this->map_row_offset = nullptr;
        this->map_width = 0;
        this->map_height = 0;
        return;
    }

    this->destroy_shared_resources();
    this->map = nullptr;
    this->map_row_offset = nullptr;
    this->map_width = 0;
    this->map_height = 0;
}

float RGE_Random_Map_Module::get_schedule() {
    return this->schedule;
}

uchar RGE_Random_Map_Module::generate() {
    RGE_Random_Map_Module_List* sorted = nullptr;
    RGE_Random_Map_Module_List* node = this->list;

    while (node != nullptr) {
        RGE_Random_Map_Module_List* next = node->next;
        node->next = nullptr;

        if (sorted == nullptr) {
            sorted = node;
        } else {
            float node_sched = node->module ? node->module->get_schedule() : 0.0f;
            float head_sched = sorted->module ? sorted->module->get_schedule() : 0.0f;
            if (node_sched < head_sched) {
                node->next = sorted;
                sorted = node;
            } else {
                RGE_Random_Map_Module_List* ins = sorted;
                while (ins->next != nullptr) {
                    float next_sched = ins->next->module ? ins->next->module->get_schedule() : 0.0f;
                    if (node_sched < next_sched) {
                        break;
                    }
                    ins = ins->next;
                }
                node->next = ins->next;
                ins->next = node;
            }
        }

        node = next;
    }

    this->list = sorted;

    for (RGE_Random_Map_Module_List* it = this->list; it != nullptr; it = it->next) {
        if (it->module != nullptr) {
            if (it->module->generate() == 0) {
                return 0;
            }
        }
    }

    return 1;
}

uchar RGE_Random_Map_Module::add_module(RGE_Random_Map_Module* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    RGE_Random_Map_Module_List* node = (RGE_Random_Map_Module_List*)calloc(1, sizeof(RGE_Random_Map_Module_List));
    if (node == nullptr) {
        return 0;
    }
    node->next = this->list;
    node->module = param_1;
    this->list = node;
    return 1;
}

uchar RGE_Random_Map_Module::remove_module(RGE_Random_Map_Module* param_1) {
    RGE_Random_Map_Module_List* prev = nullptr;
    RGE_Random_Map_Module_List* it = this->list;

    while (it != nullptr) {
        if (it->module == param_1) {
            if (prev == nullptr) {
                this->list = it->next;
            } else {
                prev->next = it->next;
            }
            free(it);
            return 1;
        }
        prev = it;
        it = it->next;
    }
    return 0;
}

void RGE_Random_Map_Module::create_shared_resources() {
    if (this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    long count = this->map_width * this->map_height;

    this->search_map = (uchar*)calloc((size_t)count, 1);
    this->search_map_rows = (uchar**)calloc((size_t)this->map_height, sizeof(uchar*));
    for (long y = 0; y < this->map_height; ++y) {
        this->search_map_rows[y] = this->search_map + y * this->map_width;
    }

    this->stack_array = (Map_Stack*)calloc((size_t)count, sizeof(Map_Stack));
    this->stack_offsets = (Map_Stack**)calloc((size_t)this->map_height, sizeof(Map_Stack*));
    for (long y = 0; y < this->map_height; ++y) {
        this->stack_offsets[y] = this->stack_array + y * this->map_width;
    }

    for (long y = 0; y < this->map_height; ++y) {
        for (long x = 0; x < this->map_width; ++x) {
            this->stack_offsets[y][x].x = x;
            this->stack_offsets[y][x].y = y;
        }
    }
}

void RGE_Random_Map_Module::destroy_shared_resources() {
    if (this->search_map != nullptr) {
        free(this->search_map);
        this->search_map = nullptr;
    }
    if (this->search_map_rows != nullptr) {
        free(this->search_map_rows);
        this->search_map_rows = nullptr;
    }
    if (this->stack_array != nullptr) {
        free(this->stack_array);
        this->stack_array = nullptr;
    }
    if (this->stack_offsets != nullptr) {
        free(this->stack_offsets);
        this->stack_offsets = nullptr;
    }
}

void RGE_Random_Map_Module::update_child_resources() {
    for (RGE_Random_Map_Module_List* it = this->list; it != nullptr; it = it->next) {
        if (it->module != nullptr) {
            it->module->update_resources();
        }
    }
}

void RGE_Random_Map_Module::update_resources() {
    if (this->parent != nullptr) {
        this->parent->share_resources(&this->search_map, &this->search_map_rows, &this->stack_array, &this->stack_offsets);
    }
    this->update_child_resources();
}

void RGE_Random_Map_Module::update_child_map_info() {
    for (RGE_Random_Map_Module_List* it = this->list; it != nullptr; it = it->next) {
        if (it->module != nullptr) {
            it->module->update_map_info(this->map);
        }
    }
}

void RGE_Random_Map_Module::update_map_info(RGE_Map* param_1) {
    this->map = param_1;
    if (param_1 != nullptr) {
        this->map_row_offset = param_1->map_row_offset;
        this->map_width = param_1->map_width;
        this->map_height = param_1->map_height;
    } else {
        this->map_row_offset = nullptr;
        this->map_width = 0;
        this->map_height = 0;
    }
    this->update_child_map_info();
}

void RGE_Random_Map_Module::share_resources(uchar** param_1, uchar*** param_2, Map_Stack** param_3, Map_Stack*** param_4) {
    if (param_1 != nullptr) {
        *param_1 = this->search_map;
    }
    if (param_2 != nullptr) {
        *param_2 = this->search_map_rows;
    }
    if (param_3 != nullptr) {
        *param_3 = this->stack_array;
    }
    if (param_4 != nullptr) {
        *param_4 = this->stack_offsets;
    }
}

void RGE_Random_Map_Module::init_stack(Map_Stack* param_1) {
    if (param_1 == nullptr) return;
    param_1->x = -1;
    param_1->y = -1;
    param_1->next = nullptr;
    param_1->prev = nullptr;
    param_1->cost = 0.0f;
    param_1->tot_cost = 0.0f;
}

void RGE_Random_Map_Module::deinit_stack(Map_Stack* param_1) {
    if (param_1 == nullptr) return;
    if (param_1->next != nullptr) {
        param_1->next->prev = nullptr;
        param_1->next = nullptr;
    }
}

void RGE_Random_Map_Module::push_stack(Map_Stack* param_1, long param_2, long param_3, float param_4, float param_5) {
    if (param_1 == nullptr || this->stack_offsets == nullptr) {
        return;
    }
    if (param_2 < 0 || param_2 >= this->map_width || param_3 < 0 || param_3 >= this->map_height) {
        return;
    }

    Map_Stack* node = this->stack_offsets[param_3] + param_2;
    this->remove_stack_node(node);

    Map_Stack* it = param_1->next;
    if (it == nullptr || param_5 <= it->tot_cost) {
        this->add_stack_node(param_1, node);
        node->cost = param_4;
        node->tot_cost = param_5;
        return;
    }

    Map_Stack* prev = it;
    while (it != nullptr && it->tot_cost < param_5) {
        prev = it;
        it = it->next;
    }
    this->add_stack_node(prev, node);
    node->cost = param_4;
    node->tot_cost = param_5;
}

Map_Stack* RGE_Random_Map_Module::pop_stack(Map_Stack* param_1, long* param_2, long* param_3, float* param_4) {
    if (param_1 == nullptr) {
        return nullptr;
    }
    Map_Stack* node = param_1->next;
    if (node == nullptr) {
        return nullptr;
    }
    if (param_2 != nullptr) *param_2 = node->x;
    if (param_3 != nullptr) *param_3 = node->y;
    if (param_4 != nullptr) *param_4 = node->cost;
    this->remove_stack_node(node);
    return node;
}

void RGE_Random_Map_Module::add_stack_node(Map_Stack* param_1, Map_Stack* param_2) {
    if (param_1 == nullptr || param_2 == nullptr) {
        return;
    }

    if (param_2->next != nullptr || param_2->prev != nullptr) {
        this->remove_stack_node(param_2);
    }

    Map_Stack* next = param_1->next;
    param_2->prev = param_1;
    param_2->next = next;
    if (next != nullptr) {
        next->prev = param_2;
    }
    param_1->next = param_2;
}

void RGE_Random_Map_Module::remove_stack_node(Map_Stack* param_1) {
    if (param_1 == nullptr) {
        return;
    }
    if (param_1->prev != nullptr) {
        param_1->prev->next = param_1->next;
    }
    if (param_1->next != nullptr) {
        param_1->next->prev = param_1->prev;
    }
    param_1->next = nullptr;
    param_1->prev = nullptr;
}

RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(char* param_1, char* param_2, char* param_3, char* param_4)
    : RGE_Random_Map_Module(nullptr, nullptr, 0) {
    memset(&this->land_info, 0, sizeof(this->land_info));
    memset(&this->terrain_info, 0, sizeof(this->terrain_info));
    memset(&this->object_info, 0, sizeof(this->object_info));
    memset(&this->elevation_info, 0, sizeof(this->elevation_info));
    memset(&this->map_info, 0, sizeof(this->map_info));
    this->world = nullptr;
    this->map_type = -1;
    this->number_of_players = 0;

    FILE* map_file = fopen(param_4, "r");
    if (map_file != nullptr) {
        if (fscanf(map_file, "%ld", &this->map_info.map_num) != 1 || this->map_info.map_num < 1) {
            this->map_info.map_num = 0;
            this->map_info.maps = nullptr;
        } else {
            this->map_info.maps = (RGE_Map_Data_Entry*)calloc((size_t)this->map_info.map_num, sizeof(RGE_Map_Data_Entry));
            for (long i = 0; i < this->map_info.map_num; ++i) {
                long map_id = 0;
                if (fscanf(map_file, "%ld", &map_id) != 1) {
                    break;
                }
                this->map_info.maps[i].map_id = map_id;
            }
        }
        fclose(map_file);
    }

    if (this->map_info.map_num < 1 || this->map_info.maps == nullptr) {
        this->map_info.map_num = 0;
        this->map_info.maps = nullptr;
        return;
    }

    FILE* land_file = fopen(param_1, "r");
    if (land_file != nullptr) {
        long map_block_count = 0;
        if (fscanf(land_file, "%ld", &map_block_count) == 1 && map_block_count > 0) {
            for (long i = 0; i < map_block_count; ++i) {
                long map_index = -1;
                if (fscanf(land_file, "%ld", &map_index) != 1) {
                    break;
                }
                if (map_index < 0 || map_index >= this->map_info.map_num) {
                    continue;
                }

                RGE_Land_Data* land = &this->map_info.maps[map_index].land_info;
                if (fscanf(
                        land_file,
                        "%ld %ld %ld %ld %ld %ld %ld %ld %ld",
                        &land->land_num,
                        &land->map_edge_buffer[0],
                        &land->map_edge_buffer[1],
                        &land->map_edge_buffer[2],
                        &land->map_edge_buffer[3],
                        &land->map_edge_fade,
                        &land->land_placement_edge,
                        &land->base_terrain,
                        &land->grown_land_percent) != 9) {
                    break;
                }

                land->land = nullptr;
                if (land->land_num > 0) {
                    land->land = (RGE_Land_Data_Entry*)calloc((size_t)land->land_num, sizeof(RGE_Land_Data_Entry));
                    for (long n = 0; n < land->land_num; ++n) {
                        long terrain_type = 0;
                        long zone = 0;
                        long placement_type = 0;
                        long amount = 0;
                        long by_player = 0;
                        RGE_Land_Data_Entry* e = &land->land[n];
                        if (fscanf(
                                land_file,
                                "%ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
                                &e->land_id,
                                &terrain_type,
                                &e->land_avoidance_tiles,
                                &e->base_square_radius,
                                &zone,
                                &placement_type,
                                &e->x,
                                &e->y,
                                &amount,
                                &by_player,
                                &e->radius,
                                &e->fade) != 12) {
                            break;
                        }
                        e->terrain_type = (uchar)terrain_type;
                        e->zone = (uchar)zone;
                        e->placement_type = (uchar)placement_type;
                        e->amount_of_land_used_percent = (uchar)amount;
                        e->by_player_flag = (uchar)by_player;
                        e->clumpiness_factor = 8;
                    }
                }
            }
        }
        fclose(land_file);
    }

    FILE* terrain_file = fopen(param_2, "r");
    if (terrain_file != nullptr) {
        long map_block_count = 0;
        if (fscanf(terrain_file, "%ld", &map_block_count) == 1 && map_block_count > 0) {
            for (long i = 0; i < map_block_count; ++i) {
                long map_index = -1;
                if (fscanf(terrain_file, "%ld", &map_index) != 1) break;
                if (map_index < 0 || map_index >= this->map_info.map_num) continue;

                RGE_Terrain_Data* terr = &this->map_info.maps[map_index].terrain_info;
                if (fscanf(terrain_file, "%ld", &terr->terrain_num) != 1) break;

                terr->terrain = nullptr;
                if (terr->terrain_num > 0) {
                    terr->terrain = (RGE_Terrain_Data_Entry*)calloc((size_t)terr->terrain_num, sizeof(RGE_Terrain_Data_Entry));
                    for (long n = 0; n < terr->terrain_num; ++n) {
                        RGE_Terrain_Data_Entry* e = &terr->terrain[n];
                        if (fscanf(
                                terrain_file,
                                "%ld %ld %ld %ld %ld",
                                &e->terrain_percent,
                                &e->terrain_type,
                                &e->clumps,
                                &e->spacing,
                                &e->base_terrain_type) != 5) {
                            break;
                        }
                        e->clumpiness_factor = 0x14;
                    }
                }
            }
        }
        fclose(terrain_file);
    }

    FILE* object_file = fopen(param_3, "r");
    if (object_file != nullptr) {
        long map_block_count = 0;
        if (fscanf(object_file, "%ld", &map_block_count) == 1 && map_block_count > 0) {
            for (long i = 0; i < map_block_count; ++i) {
                long map_index = -1;
                if (fscanf(object_file, "%ld", &map_index) != 1) break;
                if (map_index < 0 || map_index >= this->map_info.map_num) continue;

                RGE_Object_Data* obj = &this->map_info.maps[map_index].object_info;
                if (fscanf(object_file, "%ld", &obj->object_num) != 1) break;

                obj->objects = nullptr;
                if (obj->object_num > 0) {
                    obj->objects = (RGE_Object_Data_Entry*)calloc((size_t)obj->object_num, sizeof(RGE_Object_Data_Entry));
                    for (long n = 0; n < obj->object_num; ++n) {
                        long group_flag = 0;
                        long scale_flag = 0;
                        RGE_Object_Data_Entry* e = &obj->objects[n];
                        if (fscanf(
                                object_file,
                                "%ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
                                &e->obj_id,
                                &e->terrain,
                                &group_flag,
                                &scale_flag,
                                &e->object_number_per_group,
                                &e->object_number_varience,
                                &e->number_of_groups,
                                &e->group_area,
                                &e->player_id,
                                &e->land_id,
                                &e->land_inner_radius,
                                &e->land_outer_radius) != 12) {
                            break;
                        }
                        e->group_flag = (uchar)group_flag;
                        e->scale_flag = (uchar)scale_flag;
                    }
                }
            }
        }
        fclose(object_file);
    }
}

RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(int param_1)
    : RGE_Random_Map_Module(nullptr, nullptr, 0) {
    memset(&this->land_info, 0, sizeof(this->land_info));
    memset(&this->terrain_info, 0, sizeof(this->terrain_info));
    memset(&this->object_info, 0, sizeof(this->object_info));
    memset(&this->elevation_info, 0, sizeof(this->elevation_info));
    memset(&this->map_info, 0, sizeof(this->map_info));
    this->world = nullptr;
    this->map_type = -1;
    this->number_of_players = 0;

    // Source of truth: rmm_dbct.cpp.decomp parses random-map DB from fd here.
    // Important: this constructor consumes bytes from the shared world data stream.
    // Do NOT rewind; later world_init stages must continue from the advanced position.
    const long saved_pos = rge_stream_tell(param_1);

    const long kMaxMapDefs = 128;
    const long kMaxLandDefs = 4096;
    const long kMaxTerrainDefs = 4096;
    const long kMaxObjectDefs = 8192;
    const long kMaxElevationDefs = 4096;

    int parse_ok = 1;
    int parse_fail_stage = 0;
    long parse_fail_index = -1;
    long parse_fail_value = 0;
    RGE_Map_Data hdr;
    memset(&hdr, 0, sizeof(hdr));
    rge_read(param_1, &hdr, (int)sizeof(hdr));
    if (hdr.map_num <= 0 || hdr.map_num > kMaxMapDefs) {
        parse_ok = 0;
        parse_fail_stage = 1;
        parse_fail_value = hdr.map_num;
    }

    if (parse_ok) {
        this->map_info.map_num = hdr.map_num;
        this->map_info.maps = (RGE_Map_Data_Entry*)calloc((size_t)this->map_info.map_num, sizeof(RGE_Map_Data_Entry));
        if (this->map_info.maps == nullptr) {
            parse_ok = 0;
            parse_fail_stage = 2;
        }
    }

    if (parse_ok) {
        rge_read(param_1, this->map_info.maps, this->map_info.map_num * (int)sizeof(RGE_Map_Data_Entry));

        for (long i = 0; i < this->map_info.map_num && parse_ok; ++i) {
            RGE_Map_Data_Entry* map_entry = &this->map_info.maps[i];

            rge_read(param_1, &map_entry->land_info, (int)sizeof(RGE_Land_Data));
            if (map_entry->land_info.land_num < 0 || map_entry->land_info.land_num > kMaxLandDefs) {
                parse_ok = 0;
                parse_fail_stage = 3;
                parse_fail_index = i;
                parse_fail_value = map_entry->land_info.land_num;
                break;
            }
            if (map_entry->land_info.land_num > 0) {
                map_entry->land_info.land = (RGE_Land_Data_Entry*)calloc((size_t)map_entry->land_info.land_num, sizeof(RGE_Land_Data_Entry));
                if (map_entry->land_info.land == nullptr) {
                    parse_ok = 0;
                    parse_fail_stage = 4;
                    parse_fail_index = i;
                    break;
                }
                rge_read(param_1, map_entry->land_info.land, map_entry->land_info.land_num * (int)sizeof(RGE_Land_Data_Entry));
            } else {
                map_entry->land_info.land = nullptr;
            }

            rge_read(param_1, &map_entry->terrain_info, (int)sizeof(RGE_Terrain_Data));
            if (map_entry->terrain_info.terrain_num < 0 || map_entry->terrain_info.terrain_num > kMaxTerrainDefs) {
                parse_ok = 0;
                parse_fail_stage = 5;
                parse_fail_index = i;
                parse_fail_value = map_entry->terrain_info.terrain_num;
                break;
            }
            if (map_entry->terrain_info.terrain_num > 0) {
                map_entry->terrain_info.terrain = (RGE_Terrain_Data_Entry*)calloc((size_t)map_entry->terrain_info.terrain_num, sizeof(RGE_Terrain_Data_Entry));
                if (map_entry->terrain_info.terrain == nullptr) {
                    parse_ok = 0;
                    parse_fail_stage = 6;
                    parse_fail_index = i;
                    break;
                }
                rge_read(param_1, map_entry->terrain_info.terrain, map_entry->terrain_info.terrain_num * (int)sizeof(RGE_Terrain_Data_Entry));
            } else {
                map_entry->terrain_info.terrain = nullptr;
            }

            rge_read(param_1, &map_entry->object_info, (int)sizeof(RGE_Object_Data));
            if (map_entry->object_info.object_num < 0 || map_entry->object_info.object_num > kMaxObjectDefs) {
                parse_ok = 0;
                parse_fail_stage = 7;
                parse_fail_index = i;
                parse_fail_value = map_entry->object_info.object_num;
                break;
            }
            if (map_entry->object_info.object_num > 0) {
                map_entry->object_info.objects = (RGE_Object_Data_Entry*)calloc((size_t)map_entry->object_info.object_num, sizeof(RGE_Object_Data_Entry));
                if (map_entry->object_info.objects == nullptr) {
                    parse_ok = 0;
                    parse_fail_stage = 8;
                    parse_fail_index = i;
                    break;
                }
                rge_read(param_1, map_entry->object_info.objects, map_entry->object_info.object_num * (int)sizeof(RGE_Object_Data_Entry));
            } else {
                map_entry->object_info.objects = nullptr;
            }

            rge_read(param_1, &map_entry->elevation_info, (int)sizeof(RGE_Elevation_Data));
            if (map_entry->elevation_info.elevation_num < 0 || map_entry->elevation_info.elevation_num > kMaxElevationDefs) {
                parse_ok = 0;
                parse_fail_stage = 9;
                parse_fail_index = i;
                parse_fail_value = map_entry->elevation_info.elevation_num;
                break;
            }
            if (map_entry->elevation_info.elevation_num > 0) {
                map_entry->elevation_info.elevation = (RGE_Elevation_Data_Entry*)calloc((size_t)map_entry->elevation_info.elevation_num, sizeof(RGE_Elevation_Data_Entry));
                if (map_entry->elevation_info.elevation == nullptr) {
                    parse_ok = 0;
                    parse_fail_stage = 10;
                    parse_fail_index = i;
                    break;
                }
                rge_read(param_1, map_entry->elevation_info.elevation, map_entry->elevation_info.elevation_num * (int)sizeof(RGE_Elevation_Data_Entry));
            } else {
                map_entry->elevation_info.elevation = nullptr;
            }
        }
    }

    if (!parse_ok) {
        CUSTOM_DEBUG_LOG_FMT(
            "RMM fd ctor parse failed: fd=%d start_pos=%ld end_pos=%ld map_num=%ld stage=%d idx=%ld val=%ld",
            param_1,
            saved_pos,
            rge_stream_tell(param_1),
            hdr.map_num,
            parse_fail_stage,
            parse_fail_index,
            parse_fail_value);
        rmm_free_map_data(this);
    } else {
        CUSTOM_DEBUG_LOG_FMT(
            "RMM fd ctor parse ok: fd=%d start_pos=%ld end_pos=%ld map_num=%ld",
            param_1,
            saved_pos,
            rge_stream_tell(param_1),
            this->map_info.map_num);
    }
}

RGE_RMM_Database_Controller::~RGE_RMM_Database_Controller() {
    rmm_free_map_data(this);
}

uchar RGE_RMM_Database_Controller::save(int param_1) {
    rge_write(param_1, &this->map_info, (int)sizeof(RGE_Map_Data));
    if (this->map_info.map_num <= 0 || this->map_info.maps == nullptr) {
        return 1;
    }

    rge_write(param_1, this->map_info.maps, this->map_info.map_num * (int)sizeof(RGE_Map_Data_Entry));
    for (long i = 0; i < this->map_info.map_num; ++i) {
        RGE_Map_Data_Entry* map_entry = &this->map_info.maps[i];
        rge_write(param_1, &map_entry->land_info, (int)sizeof(RGE_Land_Data));
        if (map_entry->land_info.land_num > 0 && map_entry->land_info.land != nullptr) {
            rge_write(param_1, map_entry->land_info.land, map_entry->land_info.land_num * (int)sizeof(RGE_Land_Data_Entry));
        }
        rge_write(param_1, &map_entry->terrain_info, (int)sizeof(RGE_Terrain_Data));
        if (map_entry->terrain_info.terrain_num > 0 && map_entry->terrain_info.terrain != nullptr) {
            rge_write(param_1, map_entry->terrain_info.terrain, map_entry->terrain_info.terrain_num * (int)sizeof(RGE_Terrain_Data_Entry));
        }
        rge_write(param_1, &map_entry->object_info, (int)sizeof(RGE_Object_Data));
        if (map_entry->object_info.object_num > 0 && map_entry->object_info.objects != nullptr) {
            rge_write(param_1, map_entry->object_info.objects, map_entry->object_info.object_num * (int)sizeof(RGE_Object_Data_Entry));
        }
        rge_write(param_1, &map_entry->elevation_info, (int)sizeof(RGE_Elevation_Data));
        if (map_entry->elevation_info.elevation_num > 0 && map_entry->elevation_info.elevation != nullptr) {
            rge_write(param_1, map_entry->elevation_info.elevation, map_entry->elevation_info.elevation_num * (int)sizeof(RGE_Elevation_Data_Entry));
        }
    }
    return 1;
}

uchar RGE_RMM_Database_Controller::generate() {
    if (RGE_Random_Map_Module::generate() == 0) {
        return 0;
    }

    if (this->map == nullptr || this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }

    long map_area = this->map_width * this->map_height;
    if (map_area <= 0) {
        return 0;
    }

    uchar base_terrain = rmm_clamp_terrain((long)this->land_info.base_terrain);
    for (long y = 0; y < this->map_height; ++y) {
        for (long x = 0; x < this->map_width; ++x) {
            RGE_Tile* tile = &this->map_row_offset[y][x];
            tile->terrain_type = base_terrain;
            tile->tile_type = 0;
            tile->border_type = 0;
            tile->border_shape = 0;
            tile->height = 1;
        }
    }

    long edge = 2;
    RGE_Map_Data_Entry* map_entry = rmm_select_map_entry(this);
    if (map_entry != nullptr && map_entry->land_info.land_placement_edge > 0) {
        edge = map_entry->land_info.land_placement_edge;
    }
    if (this->map_width > 2) edge = rmm_clamp_long(edge, 1, this->map_width / 2);
    if (this->map_height > 2) edge = rmm_clamp_long(edge, 1, this->map_height / 2);

    long land_num = this->land_info.land_num;
    if (land_num < 0) land_num = 0;
    if (land_num > 99) land_num = 99;
    for (long i = 0; i < land_num; ++i) {
        RGE_Land_Info_Line* land = &this->land_info.land[i];
        long cx = land->x;
        long cy = land->y;
        if (cx <= 0 || cx >= this->map_width || cy <= 0 || cy >= this->map_height) {
            long range_x = this->map_width - edge * 2;
            long range_y = this->map_height - edge * 2;
            if (range_x < 1) range_x = this->map_width;
            if (range_y < 1) range_y = this->map_height;
            cx = edge + rmm_rand_range(range_x);
            cy = edge + rmm_rand_range(range_y);
        }

        long target_size = land->land_size;
        if (target_size <= 0) target_size = map_area / 12;
        long radius = (long)sqrt((double)target_size / 3.0);
        if (radius < 4) radius = 4;
        if (land->base_size > 0 && land->base_size > radius) {
            radius = land->base_size;
        }

        uchar terrain = rmm_clamp_terrain(land->terrain_type);
        rmm_paint_disk(this, cx, cy, radius, terrain, 0, 0);
        rmm_paint_disk(this, cx + rmm_rand_range(radius + 1) - radius / 2, cy + rmm_rand_range(radius + 1) - radius / 2, (radius * 3) / 4, terrain, 0, 0);
        rmm_paint_disk(this, cx + rmm_rand_range(radius + 1) - radius / 2, cy + rmm_rand_range(radius + 1) - radius / 2, radius / 2, terrain, 0, 0);
    }

    long terr_num = this->terrain_info.terrain_num;
    if (terr_num < 0) terr_num = 0;
    if (terr_num > 99) terr_num = 99;
    for (long i = 0; i < terr_num; ++i) {
        RGE_Terrain_Info_Line* line = &this->terrain_info.terrain[i];
        if (line->terrain_size <= 0) {
            continue;
        }

        long target_tiles = 0;
        if (line->terrain_size <= 100) {
            target_tiles = (map_area * line->terrain_size) / 100;
        } else {
            target_tiles = line->terrain_size;
        }
        if (target_tiles <= 0) {
            continue;
        }

        uchar terrain = rmm_clamp_terrain(line->terrain_type);
        uchar base_filter = rmm_clamp_terrain(line->base_terrain_type);
        if (rmm_count_terrain_tiles(this, base_filter) == 0) {
            long best_count = -1;
            uchar best_tt = base_filter;
            for (int tt = 0; tt < 32; ++tt) {
                long c = rmm_count_terrain_tiles(this, (uchar)tt);
                if (c > best_count) {
                    best_count = c;
                    best_tt = (uchar)tt;
                }
            }
            if (best_count > 0) {
                base_filter = best_tt;
            }
        }
        long remaining = target_tiles;
        long tries = target_tiles * 4;
        if (tries < 64) tries = 64;

        while (remaining > 0 && tries > 0) {
            long cx = rmm_rand_range(this->map_width);
            long cy = rmm_rand_range(this->map_height);
            long radius = (line->clumps > 0) ? line->clumps : 3;
            radius += rmm_rand_range((line->clumpiness_factor > 1) ? line->clumpiness_factor : 4);
            radius = rmm_clamp_long(radius, 1, 24);

            long changed = rmm_paint_disk(this, cx, cy, radius, terrain, 1, base_filter);
            if (changed > 0) {
                remaining -= changed;
            }
            --tries;
        }
    }

    long elev_num = this->elevation_info.elevation_num;
    if (elev_num < 0) elev_num = 0;
    if (elev_num > 99) elev_num = 99;
    for (long i = 0; i < elev_num; ++i) {
        RGE_Elevation_Info_Line* line = &this->elevation_info.elevation[i];
        if (line->elevation_size <= 0) {
            continue;
        }

        long target_tiles = 0;
        if (line->elevation_size <= 100) {
            target_tiles = (map_area * line->elevation_size) / 100;
        } else {
            target_tiles = line->elevation_size;
        }
        if (target_tiles <= 0) {
            continue;
        }

        uchar target_height = (uchar)line->elevation;
        if (target_height > 7) target_height = 7;
        uchar base_height = (uchar)line->base_elevation;
        if (base_height > 7) base_height = 7;
        uchar base_filter = rmm_clamp_terrain(line->base_terrain_type);
        if (rmm_count_terrain_tiles(this, base_filter) == 0) {
            long best_count = -1;
            uchar best_tt = base_filter;
            for (int tt = 0; tt < 32; ++tt) {
                if (rmm_is_water_terrain((uchar)tt)) {
                    continue;
                }
                long c = rmm_count_terrain_tiles(this, (uchar)tt);
                if (c > best_count) {
                    best_count = c;
                    best_tt = (uchar)tt;
                }
            }
            if (best_count > 0) {
                base_filter = best_tt;
            }
        }

        long remaining = target_tiles;
        long tries = target_tiles * 4;
        if (tries < 64) tries = 64;
        long total_changed = 0;

        while (remaining > 0 && tries > 0) {
            long cx = rmm_rand_range(this->map_width);
            long cy = rmm_rand_range(this->map_height);
            long radius = (line->clumps > 0) ? line->clumps : 2;
            radius += rmm_rand_range(4);
            radius = rmm_clamp_long(radius, 1, 16);

            long changed = rmm_raise_disk(this, cx, cy, radius, target_height, 1, base_filter, 1, base_height);
            if (changed > 0) {
                remaining -= changed;
                total_changed += changed;
            }
            --tries;
        }

        CUSTOM_DEBUG_LOG_FMT(
            "  elev[%ld]: size=%ld elev=%ld base_tt=%ld base_h=%ld changed=%ld target=%ld",
            i,
            line->elevation_size,
            line->elevation,
            line->base_terrain_type,
            line->base_elevation,
            total_changed,
            target_tiles);
    }

    int max_step_before = rmm_max_height_step(this);
    rmm_smooth_elevation(this, 32);
    int max_step_after = rmm_max_height_step(this);
    CUSTOM_DEBUG_LOG_FMT(
        "RGE_RMM_Database_Controller::generate: height step before=%d after=%d",
        max_step_before,
        max_step_after);

    long placed_objects = rmm_place_objects_pass(this);
    CUSTOM_DEBUG_LOG_FMT(
        "RGE_RMM_Database_Controller::generate: object_defs=%ld placed=%ld",
        this->object_info.object_num,
        placed_objects);

    this->map->rebuild_tile_types(0, 0, (short)(this->map_width - 1), (short)(this->map_height - 1));
    this->map->rebuild_border_types(0, 0, (short)(this->map_width - 1), (short)(this->map_height - 1));
    this->map->set_map_screen_pos(0, 0, this->map_width - 1, this->map_height - 1);
    this->map->clear_map_view_info();

    rmm_log_terrain_histogram(this, "RGE_RMM_Database_Controller::generate");
    rmm_log_height_histogram(this, "RGE_RMM_Database_Controller::generate");
    rmm_log_tile_type_histogram(this, "RGE_RMM_Database_Controller::generate");
    rmm_log_border_histogram(this, "RGE_RMM_Database_Controller::generate");
    return 1;
}

void RGE_RMM_Database_Controller::add_land_module(uchar param_1) {
    (void)param_1;
    memset(&this->land_info, 0, sizeof(this->land_info));

    RGE_Map_Data_Entry* map_entry = rmm_select_map_entry(this);
    if (map_entry == nullptr) {
        // Fallback defaults until full fd-accurate DB parsing is wired.
        uchar base_tt = rmm_pick_loaded_terrain(this->map, 22, 0);
        uchar land_a = rmm_pick_loaded_terrain(this->map, 6, base_tt);
        uchar land_b = rmm_pick_loaded_terrain(this->map, 13, 1);

        this->land_info.base_terrain = base_tt;
        this->land_info.land_num = 2;
        this->land_info.land[0].land_size = (this->map_width * this->map_height) / 5;
        this->land_info.land[0].terrain_type = land_a;
        this->land_info.land[0].base_size = 12;
        this->land_info.land[0].x = this->map_width / 3;
        this->land_info.land[0].y = this->map_height / 3;
        this->land_info.land[1].land_size = (this->map_width * this->map_height) / 7;
        this->land_info.land[1].terrain_type = land_b;
        this->land_info.land[1].base_size = 10;
        this->land_info.land[1].x = (this->map_width * 2) / 3;
        this->land_info.land[1].y = (this->map_height * 2) / 3;
        return;
    }

    RGE_Land_Data* src = &map_entry->land_info;
    uchar base_tt = rmm_pick_loaded_terrain(this->map, rmm_clamp_terrain(src->base_terrain), 0);
    this->land_info.base_terrain = base_tt;
    this->land_info.wall_1_avoidance_line = src->map_edge_buffer[0];
    this->land_info.wall_2_avoidance_line = src->map_edge_buffer[1];
    this->land_info.wall_3_avoidance_line = src->map_edge_buffer[2];
    this->land_info.wall_4_avoidance_line = src->map_edge_buffer[3];
    this->land_info.wall_fade = (uchar)src->map_edge_fade;

    long land_num = src->land_num;
    if (land_num < 0) land_num = 0;
    if (land_num > 99) land_num = 99;
    this->land_info.land_num = land_num;

    long map_area = this->map_width * this->map_height;
    if (map_area < 1) map_area = 1;
    for (long i = 0; i < land_num; ++i) {
        RGE_Land_Data_Entry* s = &src->land[i];
        RGE_Land_Info_Line* d = &this->land_info.land[i];

        long pct = s->amount_of_land_used_percent;
        if (pct <= 0) pct = 4;
        long size = (map_area * pct) / 100;
        if (s->by_player_flag != 0 && this->number_of_players > 0) {
            size /= this->number_of_players;
        }
        if (size < 1) size = 1;

        d->land_size = size;
        d->terrain_type = (long)rmm_pick_loaded_terrain(this->map, rmm_clamp_terrain((long)s->terrain_type), base_tt);
        d->x = s->x;
        d->y = s->y;
        d->base_size = s->base_square_radius;
        d->area = s->radius;
        d->zone = s->zone;
        d->clumpiness_factor = s->clumpiness_factor;
        d->wall_1_avoidance_line = src->map_edge_buffer[0];
        d->wall_2_avoidance_line = src->map_edge_buffer[1];
        d->wall_3_avoidance_line = src->map_edge_buffer[2];
        d->wall_4_avoidance_line = src->map_edge_buffer[3];
        d->wall_fade = (uchar)s->fade;
    }
}

void RGE_RMM_Database_Controller::add_terrain_module() {
    memset(&this->terrain_info, 0, sizeof(this->terrain_info));

    RGE_Map_Data_Entry* map_entry = rmm_select_map_entry(this);
    if (map_entry == nullptr) {
        uchar base_tt = rmm_pick_loaded_terrain(this->map, 22, 0);
        uchar terr_a = rmm_pick_loaded_terrain(this->map, 6, base_tt);
        uchar terr_b = rmm_pick_loaded_terrain(this->map, 10, 1);
        uchar terr_c = rmm_pick_loaded_terrain(this->map, 13, 2);

        this->terrain_info.terrain_num = 3;
        this->terrain_info.terrain[0].terrain_size = 8;
        this->terrain_info.terrain[0].terrain_type = terr_a;
        this->terrain_info.terrain[0].base_terrain_type = base_tt;
        this->terrain_info.terrain[0].clumps = 5;
        this->terrain_info.terrain[0].clumpiness_factor = 8;

        this->terrain_info.terrain[1].terrain_size = 6;
        this->terrain_info.terrain[1].terrain_type = terr_b;
        this->terrain_info.terrain[1].base_terrain_type = base_tt;
        this->terrain_info.terrain[1].clumps = 4;
        this->terrain_info.terrain[1].clumpiness_factor = 7;

        this->terrain_info.terrain[2].terrain_size = 5;
        this->terrain_info.terrain[2].terrain_type = terr_c;
        this->terrain_info.terrain[2].base_terrain_type = base_tt;
        this->terrain_info.terrain[2].clumps = 3;
        this->terrain_info.terrain[2].clumpiness_factor = 6;
        return;
    }

    RGE_Terrain_Data* src = &map_entry->terrain_info;
    long terrain_num = src->terrain_num;
    if (terrain_num < 0) terrain_num = 0;
    if (terrain_num > 99) terrain_num = 99;
    this->terrain_info.terrain_num = terrain_num;

    uchar base_tt = rmm_pick_loaded_terrain(this->map, this->land_info.base_terrain, 0);
    for (long i = 0; i < terrain_num; ++i) {
        RGE_Terrain_Data_Entry* s = &src->terrain[i];
        RGE_Terrain_Info_Line* d = &this->terrain_info.terrain[i];
        d->terrain_size = s->terrain_percent;
        d->terrain_generated = 0;
        d->terrain_type = (long)rmm_pick_loaded_terrain(this->map, rmm_clamp_terrain(s->terrain_type), base_tt);
        d->clumps = s->clumps;
        d->spacing = s->spacing;
        d->base_terrain_type = (long)rmm_pick_loaded_terrain(this->map, rmm_clamp_terrain(s->base_terrain_type), base_tt);
        d->clumpiness_factor = s->clumpiness_factor;
        d->avoid_hot_spots = 0;
    }
}

void RGE_RMM_Database_Controller::add_object_module() {
    memset(&this->object_info, 0, sizeof(this->object_info));
    RGE_Map_Data_Entry* map_entry = rmm_select_map_entry(this);
    if (map_entry == nullptr) {
        return;
    }

    RGE_Object_Data* src = &map_entry->object_info;
    long object_num = src->object_num;
    if (object_num < 0) object_num = 0;
    if (object_num > 99) object_num = 99;
    this->object_info.object_num = object_num;

    for (long i = 0; i < object_num; ++i) {
        RGE_Object_Data_Entry* s = &src->objects[i];
        RGE_Object_Info_Line* d = &this->object_info.objects[i];
        d->obj_id = s->obj_id;
        d->terrain = s->terrain;
        d->group_flag = s->group_flag;
        d->scale_flag = s->scale_flag;
        d->object_number_per_group = s->object_number_per_group;
        d->object_number_varience = s->object_number_varience;
        d->number_of_groups = s->number_of_groups;
        d->group_area = s->group_area;
        d->player_id = s->player_id;
        d->land_id = s->land_id;
        d->land_inner_radius = s->land_inner_radius;
        d->land_outer_radius = s->land_outer_radius;
        d->object_exclusion_zone = 1;
    }

    long land_num = this->land_info.land_num;
    if (land_num < 0) land_num = 0;
    if (land_num > 99) land_num = 99;
    this->object_info.land_num = land_num;

    long src_land_num = map_entry->land_info.land_num;
    long by_player_cycle = 0;
    if (src_land_num > 0 && map_entry->land_info.land != nullptr && map_entry->land_info.land[0].by_player_flag != 0) {
        by_player_cycle = 1;
    }

    for (long i = 0; i < land_num; ++i) {
        RGE_Land_Point_Info_Line* d = &this->object_info.lands[i];
        d->x = this->land_info.land[i].x;
        d->y = this->land_info.land[i].y;

        long src_idx = i;
        if (src_idx < 0) src_idx = 0;
        if (src_land_num <= 0 || map_entry->land_info.land == nullptr) {
            d->id = i;
            d->player_id = 0;
            continue;
        }
        if (src_idx >= src_land_num) {
            src_idx = src_land_num - 1;
        }

        d->id = map_entry->land_info.land[src_idx].land_id;
        d->player_id = by_player_cycle;

        if (by_player_cycle > 0) {
            ++by_player_cycle;
            if (by_player_cycle > this->number_of_players) {
                by_player_cycle = 0;
            }
        }
    }
}

void RGE_RMM_Database_Controller::add_elevation_module() {
    memset(&this->elevation_info, 0, sizeof(this->elevation_info));
    RGE_Map_Data_Entry* map_entry = rmm_select_map_entry(this);

    long grown_land_percent = 60;
    if (map_entry != nullptr) {
        grown_land_percent = map_entry->land_info.grown_land_percent;
    }
    if (grown_land_percent < 0) grown_land_percent = 0;
    if (grown_land_percent > 100) grown_land_percent = 100;

    long grown_tiles = (this->map_width * grown_land_percent * this->map_height) / 100;
    if (grown_tiles < 0) grown_tiles = 0;

    // Source of truth: rmm_dbct.cpp.decomp @ 0x00484470
    this->elevation_info.elevation_num = 4;

    this->elevation_info.elevation[0].elevation = 1;
    this->elevation_info.elevation[0].clumps = 10;
    this->elevation_info.elevation[0].base_terrain_type = 0;
    this->elevation_info.elevation[0].base_elevation = 0;
    this->elevation_info.elevation[0].spacing = 2;
    this->elevation_info.elevation[0].elevation_size = (grown_tiles * 10) / 100;

    this->elevation_info.elevation[1].elevation = 2;
    this->elevation_info.elevation[1].elevation_size = (grown_tiles * 8) / 100;
    this->elevation_info.elevation[1].clumps = 8;
    this->elevation_info.elevation[1].base_terrain_type = 0;
    this->elevation_info.elevation[1].base_elevation = 1;
    this->elevation_info.elevation[1].spacing = 1;

    this->elevation_info.elevation[2].elevation_size = (grown_tiles * 6) / 100;
    this->elevation_info.elevation[2].elevation = 3;
    this->elevation_info.elevation[2].clumps = 6;
    this->elevation_info.elevation[2].base_terrain_type = 0;
    this->elevation_info.elevation[2].base_elevation = 2;
    this->elevation_info.elevation[2].spacing = 1;

    this->elevation_info.elevation[3].elevation_size = (grown_tiles * 4) / 100;
    this->elevation_info.elevation[3].elevation = 4;
    this->elevation_info.elevation[3].clumps = 4;
    this->elevation_info.elevation[3].base_terrain_type = 0;
    this->elevation_info.elevation[3].base_elevation = 3;
    this->elevation_info.elevation[3].spacing = 1;

    // Compatibility adaptation: with partially wired terrain DB paths, terrain 0 can be absent.
    // Fall back to a generated non-water land terrain so elevation can apply.
    uchar elevation_base_tt = 0;
    int found_base_tt = 0;
    for (long i = 0; i < this->land_info.land_num; ++i) {
        uchar tt = rmm_clamp_terrain(this->land_info.land[i].terrain_type);
        if (tt == 0) {
            elevation_base_tt = 0;
            found_base_tt = 1;
            break;
        }
    }
    if (!found_base_tt) {
        for (long i = 0; i < this->land_info.land_num; ++i) {
            uchar tt = rmm_clamp_terrain(this->land_info.land[i].terrain_type);
            if (!rmm_is_water_terrain(tt)) {
                elevation_base_tt = tt;
                found_base_tt = 1;
                break;
            }
        }
    }
    if (!found_base_tt) {
        elevation_base_tt = rmm_clamp_terrain(this->land_info.base_terrain);
    }
    for (long i = 0; i < this->elevation_info.elevation_num; ++i) {
        this->elevation_info.elevation[i].base_terrain_type = elevation_base_tt;
    }

    long hot_spot_index = 0;
    if (map_entry != nullptr && map_entry->land_info.land_num > 0 && map_entry->land_info.land != nullptr) {
        for (long i = 0; i < map_entry->land_info.land_num; ++i) {
            if (hot_spot_index >= 99 || hot_spot_index >= this->land_info.land_num) {
                break;
            }
            RGE_Land_Data_Entry* land = &map_entry->land_info.land[i];
            if (land->radius < 0) {
                continue;
            }

            if (land->by_player_flag == 0) {
                this->elevation_info.hot_spots[hot_spot_index].x = this->land_info.land[hot_spot_index].x;
                this->elevation_info.hot_spots[hot_spot_index].y = this->land_info.land[hot_spot_index].y;
                this->elevation_info.hot_spots[hot_spot_index].radius = land->radius;
                this->elevation_info.hot_spots[hot_spot_index].fade = land->fade;
                ++hot_spot_index;
            } else {
                long player_i = 0;
                while (player_i < this->number_of_players && hot_spot_index < 99 && hot_spot_index < this->land_info.land_num) {
                    this->elevation_info.hot_spots[hot_spot_index].x = this->land_info.land[hot_spot_index].x;
                    this->elevation_info.hot_spots[hot_spot_index].y = this->land_info.land[hot_spot_index].y;
                    this->elevation_info.hot_spots[hot_spot_index].radius = land->radius;
                    this->elevation_info.hot_spots[hot_spot_index].fade = land->fade;
                    ++hot_spot_index;
                    ++player_i;
                }
            }
        }
    }

    this->elevation_info.hot_spot_num = hot_spot_index;

    CUSTOM_DEBUG_LOG_FMT(
        "add_elevation_module: map_type=%ld grown=%ld elev_num=%ld hot_spots=%ld",
        this->map_type,
        grown_land_percent,
        this->elevation_info.elevation_num,
        this->elevation_info.hot_spot_num);
    for (long i = 0; i < this->elevation_info.elevation_num; ++i) {
        RGE_Elevation_Info_Line* e = &this->elevation_info.elevation[i];
        CUSTOM_DEBUG_LOG_FMT(
            "  elev_setup[%ld]: size=%ld elev=%ld clumps=%ld spacing=%ld base_h=%ld base_tt=%ld",
            i,
            e->elevation_size,
            e->elevation,
            e->clumps,
            e->spacing,
            e->base_elevation,
            e->base_terrain_type);
    }
}

uchar RGE_RMM_Database_Controller::init(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, uchar param_5) {
    this->world = param_2;
    this->map_type = (long)param_3;
    this->number_of_players = param_4;

    this->update_map_info(param_1);
    this->destroy_shared_resources();
    this->create_shared_resources();

    this->add_land_module(param_5);
    this->add_terrain_module();
    this->add_object_module();
    this->add_elevation_module();

    CUSTOM_DEBUG_LOG_FMT(
        "RGE_RMM_Database_Controller::init: map_type=%ld players=%ld map=%ldx%ld map_defs=%ld",
        this->map_type,
        this->number_of_players,
        this->map_width,
        this->map_height,
        this->map_info.map_num);
    if (this->map_info.maps != nullptr && this->map_info.map_num > 0) {
        for (long i = 0; i < this->map_info.map_num; ++i) {
            RGE_Map_Data_Entry* e = &this->map_info.maps[i];
            CUSTOM_DEBUG_LOG_FMT(
                "  map_def[%ld]: id=%ld land=%ld terr=%ld obj=%ld elev=%ld",
                i,
                e->map_id,
                e->land_info.land_num,
                e->terrain_info.terrain_num,
                e->object_info.object_num,
                e->elevation_info.elevation_num);
        }
    }

    return 1;
}

uchar RGE_RMM_Database_Controller::de_init() {
    this->world = nullptr;
    this->map_type = -1;
    this->number_of_players = 0;

    while (this->list != nullptr) {
        RGE_Random_Map_Module_List* head = this->list;
        RGE_Random_Map_Module* module = head->module;
        if (module != nullptr) {
            delete module;
        } else {
            this->list = head->next;
            free(head);
        }
    }

    this->destroy_shared_resources();
    this->update_map_info(nullptr);
    return 0;
}

TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(char* param_1, char* param_2, char* param_3, char* param_4)
    : RGE_RMM_Database_Controller(param_1, param_2, param_3, param_4) {
}

TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(int param_1)
    : RGE_RMM_Database_Controller(param_1) {
}

uchar TRIBE_RMM_Database_Controller::generate() {
    uchar ret = RGE_RMM_Database_Controller::generate();

    if (this->map_row_offset != nullptr && this->map_width > 0 && this->map_height > 0) {
        for (long y = 0; y < this->map_height; ++y) {
            for (long x = 0; x < this->map_width; ++x) {
                RGE_Tile* tile = &this->map_row_offset[y][x];
                if ((tile->terrain_type & 0x1f) == 0x10) {
                    tile->terrain_type = (uchar)(tile->terrain_type & 0xe0);
                }
            }
        }
    }

    return ret;
}

void TRIBE_RMM_Database_Controller::add_land_module(uchar param_1) {
    RGE_RMM_Database_Controller::add_land_module(param_1);
}

void TRIBE_RMM_Database_Controller::add_terrain_module() {
    RGE_RMM_Database_Controller::add_terrain_module();
}

void TRIBE_RMM_Database_Controller::add_object_module() {
    RGE_RMM_Database_Controller::add_object_module();
}

void TRIBE_RMM_Database_Controller::add_elevation_module() {
    RGE_RMM_Database_Controller::add_elevation_module();
}

uchar TRIBE_RMM_Database_Controller::init(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, uchar param_5) {
    // Source of truth: rmm_tdbc.cpp.decomp @ 0x00487710
    // TRIBE path overrides the final base-init flag using TRIBE_Game::randomizePositions().
    uchar land_randomization_flag = param_5;
    if (rge_base_game != nullptr) {
        TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
        land_randomization_flag = (game->randomizePositions() == 0) ? 1 : 0;
    }

    return RGE_RMM_Database_Controller::init(param_1, param_2, param_3, param_4, land_randomization_flag);
}

uchar TRIBE_RMM_Database_Controller::de_init() {
    return RGE_RMM_Database_Controller::de_init();
}
