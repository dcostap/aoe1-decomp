#include "../include/TRIBE_RMM_Database_Controller.h"
#include "../include/RGE_Map.h"
#include "../include/TRIBE_Map.h"
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
#include "../include/RGE_RMM_Land_Generator.h"
#include "../include/RGE_RMM_Terrain_Generator.h"
#include "../include/RGE_RMM_Object_Generator.h"
#include "../include/RGE_RMM_Elevation_Generator.h"
#include "../include/RGE_RMM_Shallows_Generator.h"
#include "../include/RGE_RMM_Cliffs_Generator.h"
#include "../include/RGE_Zone_Map_List.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/TRIBE_Game.h"
#include "../include/custom_debug.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <math.h>
#include <new>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static int rmm_is_water_terrain(uchar terrain_type) {
    return terrain_type == 1 || terrain_type == 4 || terrain_type == 22;
}

// Source of truth: rmm_terr.cpp::check_borders.
// Any non-water tile adjacent to water (8-neighborhood) becomes terrain 2.
static void rmm_terrain_check_borders(RGE_RMM_Database_Controller* self) {
    if (self == nullptr || self->map_row_offset == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return;
    }

    const long max_x = self->map_width - 1;
    const long max_y = self->map_height - 1;
    for (long y = 0; y < self->map_height; ++y) {
        for (long x = 0; x < self->map_width; ++x) {
            RGE_Tile* tile = &self->map_row_offset[y][x];
            uchar tt = (uchar)(tile->terrain_type & 0x1f);
            if (rmm_is_water_terrain(tt) != 0) {
                continue;
            }

            int near_water = 0;
            if (y > 0) {
                if (rmm_is_water_terrain((uchar)(self->map_row_offset[y - 1][x].terrain_type & 0x1f)) != 0) near_water = 1;
                if (x > 0 && rmm_is_water_terrain((uchar)(self->map_row_offset[y - 1][x - 1].terrain_type & 0x1f)) != 0) near_water = 1;
                if (x < max_x && rmm_is_water_terrain((uchar)(self->map_row_offset[y - 1][x + 1].terrain_type & 0x1f)) != 0) near_water = 1;
            }
            if (y < max_y) {
                if (rmm_is_water_terrain((uchar)(self->map_row_offset[y + 1][x].terrain_type & 0x1f)) != 0) near_water = 1;
                if (x > 0 && rmm_is_water_terrain((uchar)(self->map_row_offset[y + 1][x - 1].terrain_type & 0x1f)) != 0) near_water = 1;
                if (x < max_x && rmm_is_water_terrain((uchar)(self->map_row_offset[y + 1][x + 1].terrain_type & 0x1f)) != 0) near_water = 1;
            }
            if (x > 0 && rmm_is_water_terrain((uchar)(self->map_row_offset[y][x - 1].terrain_type & 0x1f)) != 0) near_water = 1;
            if (x < max_x && rmm_is_water_terrain((uchar)(self->map_row_offset[y][x + 1].terrain_type & 0x1f)) != 0) near_water = 1;

            if (near_water != 0) {
                tile->terrain_type = (uchar)((tile->terrain_type & 0xe0) | 2);
            }
        }
    }
}

static void rmm_calc_land_start(
    RGE_RMM_Database_Controller* self,
    long start_index,
    long edge,
    long count,
    RGE_Land_Data_Entry* src_land) {
    if (self == nullptr || src_land == nullptr || count <= 0) {
        return;
    }
    if (start_index < 0 || start_index >= 99) {
        return;
    }

    long map_w = self->map_width;
    long map_h = self->map_height;
    if (map_w <= 0 || map_h <= 0) {
        return;
    }

    long min_x = edge;
    long min_y = edge;
    long max_x = map_w - edge - 1;
    long max_y = map_h - edge - 1;
    if (max_x < min_x) {
        min_x = 0;
        max_x = map_w - 1;
    }
    if (max_y < min_y) {
        min_y = 0;
        max_y = map_h - 1;
    }

    double spacing = (double)(map_w - edge * 2);
    if (spacing < 1.0) {
        spacing = (double)map_w;
    }
    spacing = spacing / sqrt((double)((count > 0) ? count : 1));
    if (count >= 4 && count < 7) {
        spacing *= 0.9;
    } else if (count >= 7) {
        spacing *= 0.8;
    }
    if (spacing < 2.0) {
        spacing = 2.0;
    }
    long min_dist_sq = (long)(spacing * spacing);

    long span_x = max_x - min_x;
    long span_y = max_y - min_y;
    long mid_x1 = min_x + span_x / 3;
    long mid_x2 = max_x - span_x / 3;
    long mid_y1 = min_y + span_y / 3;
    long mid_y2 = max_y - span_y / 3;

    for (long i = 0; i < count; ++i) {
        long dst_index = start_index + i;
        if (dst_index < 0 || dst_index >= 99) {
            break;
        }

        RGE_Land_Info_Line* out = &self->land_info.land[dst_index];
        if (src_land->placement_type == 1) {
            out->x = src_land->x;
            out->y = src_land->y;
            continue;
        }

        long chosen_x = min_x;
        long chosen_y = min_y;
        int chosen = 0;

        long max_tries = (src_land->placement_type == 2) ? 2048 : 128;
        if (max_tries < 1) {
            max_tries = 1;
        }

        while (max_tries-- > 0) {
            long x = min_x + rmm_rand_range(max_x - min_x + 1);
            long y = min_y + rmm_rand_range(max_y - min_y + 1);

            if (src_land->placement_type == 2) {
                if (x > mid_x1 && x < mid_x2 && y > mid_y1 && y < mid_y2) {
                    continue;
                }

                int too_close = 0;
                for (long prev = start_index; prev < dst_index; ++prev) {
                    long dx = x - self->land_info.land[prev].x;
                    long dy = y - self->land_info.land[prev].y;
                    long d2 = dx * dx + dy * dy;
                    if (d2 <= min_dist_sq) {
                        too_close = 1;
                        break;
                    }
                }
                if (too_close) {
                    continue;
                }
            }

            chosen_x = x;
            chosen_y = y;
            chosen = 1;
            break;
        }

        if (!chosen && i > 0) {
            long anchor = start_index + (i - 1);
            if (anchor >= 0 && anchor < 99) {
                chosen_x = self->land_info.land[anchor].x;
                chosen_y = self->land_info.land[anchor].y;
            }
        }

        out->x = chosen_x;
        out->y = chosen_y;
    }
}

static int rmm_randomize_land_positions_by_team(RGE_RMM_Database_Controller* self) {
    if (self == nullptr) {
        return 0;
    }

    const long land_count = self->land_info.land_num;
    if (land_count <= 1 || land_count > 8) {
        return 0;
    }

    long distances[8][8];
    long sorted_indices[8][8];
    for (long i = 0; i < land_count; ++i) {
        for (long j = 0; j < land_count; ++j) {
            long dx = self->land_info.land[i].x - self->land_info.land[j].x;
            long dy = self->land_info.land[i].y - self->land_info.land[j].y;
            distances[i][j] = dx * dx + dy * dy;
            sorted_indices[i][j] = j;
        }

        for (long pass = 1; pass < land_count; ++pass) {
            int changed = 0;
            for (long j = 1; j < land_count; ++j) {
                long a = sorted_indices[i][j - 1];
                long b = sorted_indices[i][j];
                if (distances[i][b] < distances[i][a]) {
                    sorted_indices[i][j - 1] = b;
                    sorted_indices[i][j] = a;
                    changed = 1;
                }
            }
            if (!changed) {
                break;
            }
        }
    }

    long player_teams[8];
    long team_sizes[8];
    long slot_teams[8];
    uchar source_used[8];
    memset(player_teams, 0xFF, sizeof(player_teams));
    memset(team_sizes, 0, sizeof(team_sizes));
    memset(slot_teams, 0xFF, sizeof(slot_teams));
    memset(source_used, 0, sizeof(source_used));

    long team_count = 0;
    for (long i = 0; i < land_count; ++i) {
        if (player_teams[i] != -1) {
            continue;
        }

        long current_team = team_count;
        if (current_team >= 8) {
            break;
        }
        player_teams[i] = current_team;
        team_sizes[current_team] = 1;

        if (self->world != nullptr && self->world->players != nullptr) {
            long world_index = i + 1;
            RGE_Player* player_i = nullptr;
            if (world_index >= 0 && world_index < self->world->player_num) {
                player_i = self->world->players[world_index];
            }
            if (player_i != nullptr) {
                for (long j = 0; j < land_count; ++j) {
                    if (j == i || player_teams[j] != -1) {
                        continue;
                    }
                    if (player_i->relation(j + 1) == 0) {
                        player_teams[j] = current_team;
                        team_sizes[current_team] = team_sizes[current_team] + 1;
                    }
                }
            }
        }

        team_count = team_count + 1;
    }

    for (long i = 0; i < land_count; ++i) {
        if (player_teams[i] != -1) {
            continue;
        }
        if (team_count >= 8) {
            break;
        }
        player_teams[i] = team_count;
        team_sizes[team_count] = 1;
        team_count = team_count + 1;
    }

    for (long team = 0; team < team_count; ++team) {
        long seed_slot = -1;
        for (long s = 0; s < land_count; ++s) {
            if (slot_teams[s] == -1) {
                seed_slot = s;
                break;
            }
        }
        if (seed_slot < 0) {
            break;
        }

        slot_teams[seed_slot] = team;
        long remaining = team_sizes[team] - 1;
        if (remaining < 0) {
            remaining = 0;
        }

        while (remaining > 0) {
            long best_slot = -1;
            long best_dist = 0x7FFFFFFF;

            for (long src_slot = 0; src_slot < land_count; ++src_slot) {
                if (slot_teams[src_slot] != team) {
                    continue;
                }
                for (long order = 0; order < land_count; ++order) {
                    long cand_slot = sorted_indices[src_slot][order];
                    if (slot_teams[cand_slot] != -1) {
                        continue;
                    }
                    long d = distances[src_slot][cand_slot];
                    if (best_slot < 0 || d < best_dist) {
                        best_slot = cand_slot;
                        best_dist = d;
                    }
                    break;
                }
            }

            if (best_slot < 0) {
                break;
            }
            slot_teams[best_slot] = team;
            remaining = remaining - 1;
        }
    }

    long remap[8];
    for (long i = 0; i < 8; ++i) {
        remap[i] = -1;
    }

    for (long slot = 0; slot < land_count; ++slot) {
        long team = slot_teams[slot];
        if (team < 0) {
            continue;
        }

        for (long src = 0; src < land_count; ++src) {
            if (source_used[src] != 0) {
                continue;
            }
            if (player_teams[src] == team) {
                remap[slot] = src;
                source_used[src] = 1;
                break;
            }
        }
    }

    for (long slot = 0; slot < land_count; ++slot) {
        if (remap[slot] != -1) {
            continue;
        }
        for (long src = 0; src < land_count; ++src) {
            if (source_used[src] == 0) {
                remap[slot] = src;
                source_used[src] = 1;
                break;
            }
        }
    }

    long remap_x[8];
    long remap_y[8];
    for (long slot = 0; slot < land_count; ++slot) {
        long src = remap[slot];
        if (src < 0 || src >= land_count) {
            remap_x[slot] = self->land_info.land[slot].x;
            remap_y[slot] = self->land_info.land[slot].y;
        } else {
            remap_x[slot] = self->land_info.land[src].x;
            remap_y[slot] = self->land_info.land[src].y;
        }
    }

    for (long slot = 0; slot < land_count; ++slot) {
        self->land_info.land[slot].x = remap_x[slot];
        self->land_info.land[slot].y = remap_y[slot];
    }

    return 1;
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
    if (self->map_type < 0 || self->map_type >= self->map_info.map_num) {
        return nullptr;
    }
    return &self->map_info.maps[self->map_type];
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

static uchar rmm_generate_land_stage(RGE_RMM_Database_Controller* self, RGE_Land_Info* land_info) {
    if (self == nullptr || land_info == nullptr || self->map == nullptr ||
        self->map_row_offset == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return 0;
    }

    const long map_area = self->map_width * self->map_height;
    if (map_area <= 0) {
        return 0;
    }

    const uchar base_terrain = rmm_clamp_terrain((long)land_info->base_terrain);
    for (long y = 0; y < self->map_height; ++y) {
        for (long x = 0; x < self->map_width; ++x) {
            RGE_Tile* tile = &self->map_row_offset[y][x];
            tile->terrain_type = base_terrain;
            tile->tile_type = 0;
            tile->border_type = 0;
            tile->border_shape = 0;
            tile->height = 1;
        }
    }

    long edge = 2;
    RGE_Map_Data_Entry* map_entry = rmm_select_map_entry(self);
    if (map_entry != nullptr && map_entry->land_info.land_placement_edge > 0) {
        edge = map_entry->land_info.land_placement_edge;
    }
    if (self->map_width > 2) edge = rmm_clamp_long(edge, 1, self->map_width / 2);
    if (self->map_height > 2) edge = rmm_clamp_long(edge, 1, self->map_height / 2);

    long land_num = land_info->land_num;
    if (land_num < 0) land_num = 0;
    if (land_num > 99) land_num = 99;
    for (long i = 0; i < land_num; ++i) {
        RGE_Land_Info_Line* land = &land_info->land[i];
        long cx = land->x;
        long cy = land->y;
        if (cx <= 0 || cx >= self->map_width || cy <= 0 || cy >= self->map_height) {
            long range_x = self->map_width - edge * 2;
            long range_y = self->map_height - edge * 2;
            if (range_x < 1) range_x = self->map_width;
            if (range_y < 1) range_y = self->map_height;
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

        const uchar terrain = rmm_clamp_terrain(land->terrain_type);
        rmm_paint_disk(self, cx, cy, radius, terrain, 0, 0);
        rmm_paint_disk(self, cx + rmm_rand_range(radius + 1) - radius / 2, cy + rmm_rand_range(radius + 1) - radius / 2, (radius * 3) / 4, terrain, 0, 0);
        rmm_paint_disk(self, cx + rmm_rand_range(radius + 1) - radius / 2, cy + rmm_rand_range(radius + 1) - radius / 2, radius / 2, terrain, 0, 0);
    }

    self->map->clean_terrain(0, 0, self->map_width - 1, self->map_height - 1, base_terrain);
    return 1;
}

static uchar rmm_generate_terrain_stage(RGE_RMM_Database_Controller* self, RGE_Terrain_Info* terrain_info) {
    if (self == nullptr || terrain_info == nullptr || self->map_row_offset == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return 0;
    }

    const long map_area = self->map_width * self->map_height;
    if (map_area <= 0) {
        return 0;
    }

    long terr_num = terrain_info->terrain_num;
    if (terr_num < 0) terr_num = 0;
    if (terr_num > 99) terr_num = 99;
    for (long i = 0; i < terr_num; ++i) {
        RGE_Terrain_Info_Line* line = &terrain_info->terrain[i];
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

        const uchar terrain = rmm_clamp_terrain(line->terrain_type);
        uchar base_filter = rmm_clamp_terrain(line->base_terrain_type);
        if (rmm_count_terrain_tiles(self, base_filter) == 0) {
            long best_count = -1;
            uchar best_tt = base_filter;
            for (int tt = 0; tt < 32; ++tt) {
                long c = rmm_count_terrain_tiles(self, (uchar)tt);
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
            long cx = rmm_rand_range(self->map_width);
            long cy = rmm_rand_range(self->map_height);
            long radius = (line->clumps > 0) ? line->clumps : 3;
            radius += rmm_rand_range((line->clumpiness_factor > 1) ? line->clumpiness_factor : 4);
            radius = rmm_clamp_long(radius, 1, 24);

            long changed = rmm_paint_disk(self, cx, cy, radius, terrain, 1, base_filter);
            if (changed > 0) {
                remaining -= changed;
            }
            --tries;
        }
    }

    rmm_terrain_check_borders(self);
    return 1;
}

static uchar rmm_generate_elevation_stage(RGE_RMM_Database_Controller* self, RGE_Elevation_Info* elevation_info) {
    if (self == nullptr || elevation_info == nullptr || self->map_row_offset == nullptr || self->map_width <= 0 || self->map_height <= 0) {
        return 0;
    }

    const long map_area = self->map_width * self->map_height;
    if (map_area <= 0) {
        return 0;
    }

    long elev_num = elevation_info->elevation_num;
    if (elev_num < 0) elev_num = 0;
    if (elev_num > 99) elev_num = 99;
    for (long i = 0; i < elev_num; ++i) {
        RGE_Elevation_Info_Line* line = &elevation_info->elevation[i];
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
        if (rmm_count_terrain_tiles(self, base_filter) == 0) {
            long best_count = -1;
            uchar best_tt = base_filter;
            for (int tt = 0; tt < 32; ++tt) {
                if (rmm_is_water_terrain((uchar)tt)) {
                    continue;
                }
                long c = rmm_count_terrain_tiles(self, (uchar)tt);
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
            long cx = rmm_rand_range(self->map_width);
            long cy = rmm_rand_range(self->map_height);
            long radius = (line->clumps > 0) ? line->clumps : 2;
            radius += rmm_rand_range(4);
            radius = rmm_clamp_long(radius, 1, 16);

            long changed = rmm_raise_disk(self, cx, cy, radius, target_height, 1, base_filter, 1, base_height);
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

    int max_step_before = rmm_max_height_step(self);
    rmm_smooth_elevation(self, 32);
    int max_step_after = rmm_max_height_step(self);
    CUSTOM_DEBUG_LOG_FMT(
        "RGE_RMM_Database_Controller::generate: height step before=%d after=%d",
        max_step_before,
        max_step_after);
    return 1;
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

void RGE_Random_Map_Module::clear_stack() {
    if (this->stack_offsets == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    for (long y = 0; y < this->map_height; ++y) {
        for (long x = 0; x < this->map_width; ++x) {
            this->stack_offsets[y][x].next = nullptr;
            this->stack_offsets[y][x].prev = nullptr;
        }
    }
}

uchar RGE_Random_Map_Module::check_stack(Map_Stack* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    if (param_1->next == nullptr && param_1->prev == nullptr) {
        return 0;
    }
    return 1;
}

void RGE_Random_Map_Module::randomize_stack(Map_Stack* param_1) {
    if (param_1 == nullptr) {
        return;
    }

    Map_Stack sub_stacks[100];
    for (int i = 0; i < 100; ++i) {
        this->init_stack(&sub_stacks[i]);
    }

    int pass_count = 2;
    while (pass_count > 0) {
        while (param_1->next != nullptr) {
            int r = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 0x1e8);
            int idx = (r * 100) / 0x7fff;
            if (idx < 0) idx = 0;
            if (idx > 99) idx = 99;
            this->add_stack_node(&sub_stacks[idx], param_1->next);
        }

        for (int i = 0; i < 100; ++i) {
            while (sub_stacks[i].next != nullptr) {
                this->add_stack_node(param_1, sub_stacks[i].next);
            }
        }

        pass_count = pass_count - 1;
    }
}

uchar RGE_Random_Map_Module::find_path(long param_1, long param_2, long* param_3, long* param_4, float* param_5) {
    Map_Stack path_stack;
    this->init_stack(&path_stack);
    uchar ret = this->find_path(&path_stack, param_1, param_2, param_3, param_4, param_5);
    this->deinit_stack(&path_stack);
    return ret;
}

uchar RGE_Random_Map_Module::find_path(
    Map_Stack* param_1,
    long param_2,
    long param_3,
    long* param_4,
    long* param_5,
    float* param_6) {
    if (param_1 == nullptr || param_4 == nullptr || param_5 == nullptr || param_6 == nullptr) {
        return 0;
    }
    if (this->map_row_offset == nullptr || this->search_map == nullptr || this->search_map_rows == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }
    if (param_2 < 0 || param_2 >= this->map_width || param_3 < 0 || param_3 >= this->map_height) {
        return 0;
    }
    if (*param_4 < 0 || *param_4 >= this->map_width || *param_5 < 0 || *param_5 >= this->map_height) {
        return 0;
    }

    long cur_x = param_2;
    long cur_y = param_3;
    long max_x = this->map_width - 1;
    long max_y = this->map_height - 1;

    this->clear_stack();
    memset(this->search_map, 0, (size_t)this->map_height * (size_t)this->map_width);

    this->search_map_rows[cur_y][cur_x] = 3;
    uchar start_tt = (uchar)(this->map_row_offset[*param_5][*param_4].terrain_type & 0x1f);
    this->search_map_rows[*param_5][*param_4] = 2;

    if (!(0.0f < param_6[start_tt])) {
        return 0;
    }

    float cur_cost = 0.0f;
    long start_y = *param_5;
    long dist_sq = (cur_x - *param_4) * (cur_x - *param_4) + (cur_y - start_y) * (cur_y - start_y);

    while (1) {
        float dist = (float)sqrt((double)dist_sq);
        if (dist == 0.0f) {
            if (param_1->next == nullptr) {
                return 1;
            }
            param_1->next->prev = nullptr;
            return 1;
        }

        bool south_ok = false;
        bool north_ok = false;
        bool west_ok = false;

        if (cur_y < max_y) {
            float h = (cur_y < *param_5) ? 1.0f : -1.0f;
            long ny = cur_y + 1;
            uchar* mark = this->search_map_rows[ny] + cur_x;
            uchar state = *mark;
            if (state == 0) {
                uchar tt = (uchar)(this->map_row_offset[ny][cur_x].terrain_type & 0x1f);
                if (param_6[tt] <= 0.0f) {
                    *mark = 1;
                } else {
                    float step = param_6[tt];
                    *mark = 7;
                    this->push_stack(param_1, cur_x, ny, cur_cost + step, cur_cost + step + (dist - h));
                    south_ok = true;
                }
            } else if (state == 2) {
                this->search_map_rows[ny][cur_x] = 7;
                *param_4 = cur_x;
                *param_5 = ny;
                return 1;
            } else {
                south_ok = (state != 1);
            }
        }

        if (cur_y > 0) {
            float h = (*param_5 < cur_y) ? 1.0f : -1.0f;
            long ny = cur_y - 1;
            uchar* mark = this->search_map_rows[ny] + cur_x;
            uchar state = *mark;
            if (state == 0) {
                uchar tt = (uchar)(this->map_row_offset[ny][cur_x].terrain_type & 0x1f);
                if (param_6[tt] <= 0.0f) {
                    *mark = 1;
                } else {
                    float step = param_6[tt];
                    *mark = 6;
                    this->push_stack(param_1, cur_x, ny, cur_cost + step, cur_cost + step + (dist - h));
                    north_ok = true;
                }
            } else if (state == 2) {
                this->search_map_rows[ny][cur_x] = 6;
                *param_4 = cur_x;
                *param_5 = ny;
                return 1;
            } else {
                north_ok = (state != 1);
            }
        }

        if (cur_x > 0) {
            float h = (*param_4 < cur_x) ? 1.0f : -1.0f;
            float d = dist - h;
            long nx = cur_x - 1;
            uchar* mark = this->search_map_rows[cur_y] + nx;
            uchar state = *mark;
            if (state == 0) {
                uchar tt = (uchar)(this->map_row_offset[cur_y][nx].terrain_type & 0x1f);
                if (param_6[tt] <= 0.0f) {
                    *mark = 1;
                } else {
                    float step = param_6[tt];
                    *mark = 4;
                    this->push_stack(param_1, nx, cur_y, cur_cost + step, cur_cost + step + d);
                    west_ok = true;
                }
            } else if (state == 2) {
                this->search_map_rows[cur_y][nx] = 4;
                *param_4 = nx;
                *param_5 = cur_y;
                return 1;
            } else {
                west_ok = (state != 1);
            }

            if (cur_y > 0) {
                long ny = cur_y - 1;
                mark = this->search_map_rows[ny] + nx;
                if (*mark == 0) {
                    uchar tt = (uchar)(this->map_row_offset[ny][nx].terrain_type & 0x1f);
                    if (param_6[tt] <= 0.0f) {
                        *mark = 1;
                    } else if (north_ok && west_ok) {
                        float step = cur_cost + param_6[tt] * 1.36f;
                        *mark = 8;
                        float bias = (*param_5 < cur_y) ? 0.41f : -0.41f;
                        this->push_stack(param_1, nx, ny, step, step + (d - bias));
                    }
                } else if (*mark == 2) {
                    this->search_map_rows[ny][nx] = 8;
                    *param_4 = nx;
                    *param_5 = ny;
                    return 1;
                }
            }

            if (cur_y < max_y) {
                long ny = cur_y + 1;
                mark = this->search_map_rows[ny] + nx;
                if (*mark == 0) {
                    uchar tt = (uchar)(this->map_row_offset[ny][nx].terrain_type & 0x1f);
                    if (param_6[tt] <= 0.0f) {
                        *mark = 1;
                    } else if (south_ok && west_ok) {
                        float step = cur_cost + param_6[tt] * 1.36f;
                        *mark = 9;
                        float bias = (cur_y < *param_5) ? 0.41f : -0.41f;
                        this->push_stack(param_1, nx, ny, step, step + (d - bias));
                    }
                } else if (*mark == 2) {
                    this->search_map_rows[ny][nx] = 9;
                    *param_4 = nx;
                    *param_5 = ny;
                    return 1;
                }
            }
        }

        if (cur_x < max_x) {
            float h = (cur_x < *param_4) ? 1.0f : -1.0f;
            dist = dist - h;
            long nx = cur_x + 1;
            uchar* mark = this->search_map_rows[cur_y] + nx;
            uchar state = *mark;
            if (state == 0) {
                uchar tt = (uchar)(this->map_row_offset[cur_y][nx].terrain_type & 0x1f);
                if (param_6[tt] <= 0.0f) {
                    *mark = 1;
                    west_ok = false;
                } else {
                    float step = param_6[tt];
                    *mark = 5;
                    this->push_stack(param_1, nx, cur_y, cur_cost + step, cur_cost + step + dist);
                    west_ok = true;
                }
            } else if (state == 2) {
                this->search_map_rows[cur_y][nx] = 5;
                *param_4 = nx;
                *param_5 = cur_y;
                return 1;
            } else {
                west_ok = (state != 1);
            }

            if (cur_y > 0) {
                long ny = cur_y - 1;
                mark = this->search_map_rows[ny] + nx;
                state = *mark;
                if (state == 0) {
                    uchar tt = (uchar)(this->map_row_offset[ny][nx].terrain_type & 0x1f);
                    if (param_6[tt] <= 0.0f) {
                        *mark = 1;
                    } else if (north_ok && west_ok) {
                        float step = cur_cost + param_6[tt] * 1.36f;
                        *mark = 10;
                        float bias = (*param_5 < cur_y) ? 0.4f : -0.4f;
                        this->push_stack(param_1, nx, ny, step, step + (dist - bias));
                    }
                } else if (state == 2) {
                    this->search_map_rows[ny][nx] = 10;
                    *param_4 = nx;
                    *param_5 = ny;
                    return 1;
                }
            }

            if (cur_y < max_y) {
                long ny = cur_y + 1;
                mark = this->search_map_rows[ny] + nx;
                state = *mark;
                if (state == 0) {
                    uchar tt = (uchar)(this->map_row_offset[ny][nx].terrain_type & 0x1f);
                    if (param_6[tt] <= 0.0f) {
                        *mark = 1;
                    } else if (south_ok && west_ok) {
                        float step = cur_cost + param_6[tt] * 1.36f;
                        *mark = 11;
                        float bias = (cur_y < *param_5) ? 0.4f : -0.4f;
                        this->push_stack(param_1, nx, ny, step, step + (dist - bias));
                    }
                } else if (state == 2) {
                    this->search_map_rows[ny][nx] = 11;
                    *param_4 = nx;
                    *param_5 = ny;
                    return 1;
                }
            }
        }

        Map_Stack* popped = this->pop_stack(param_1, &cur_x, &cur_y, &cur_cost);
        if (popped == nullptr) {
            break;
        }
        start_y = *param_5;
        dist_sq = (cur_x - *param_4) * (cur_x - *param_4) + (cur_y - start_y) * (cur_y - start_y);
    }

    return 0;
}

#if 0
// NOTE: The core RMM generator implementations were originally in this TU during bring-up,
// but are now split into dedicated translation units for Task 49 parity work:
//   - src/game/src/RGE_RMM_Land_Generator.cpp
//   - src/game/src/RGE_RMM_Terrain_Generator.cpp
//   - src/game/src/RGE_RMM_Object_Generator.cpp
//   - src/game/src/RGE_RMM_Elevation_Generator.cpp
//   - src/game/src/RGE_RMM_Shallows_Generator.cpp
//
// Keep the old in-file copies disabled to avoid duplicate symbols at link time.

RGE_RMM_Land_Generator::RGE_RMM_Land_Generator(
    RGE_Map* param_1,
    RGE_Random_Map_Module* param_2,
    RGE_Land_Info* param_3)
    : RGE_Random_Map_Module(param_1, param_2, 1) {
    this->schedule = 1.0f;
    memset(&this->info, 0, sizeof(this->info));
    if (param_3 != nullptr) {
        memcpy(&this->info, param_3, sizeof(this->info));
    }
}

uchar RGE_RMM_Land_Generator::generate() {
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

RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator(
    RGE_Map* param_1,
    RGE_Random_Map_Module* param_2,
    RGE_Terrain_Info* param_3)
    : RGE_Random_Map_Module(param_1, param_2, 1) {
    this->schedule = 2.0f;
    memset(&this->info, 0, sizeof(this->info));
    if (param_3 != nullptr) {
        memcpy(&this->info, param_3, sizeof(this->info));
    }
    this->map_zone = nullptr;
}

uchar RGE_RMM_Terrain_Generator::generate() {
    if (this->map == nullptr) {
        return 0;
    }

    this->generate_modifiers();

    float terrain_table[99];
    terrain_table[0] = 0.0f;
    for (int i = 1; i < 99; ++i) {
        terrain_table[i] = terrain_table[0];
        terrain_table[0] = terrain_table[0] + 1.0f;
    }

    if (this->map->map_zones == nullptr) {
        this->map->map_zones = new (std::nothrow) RGE_Zone_Map_List(this->map);
    }
    if (this->map->map_zones != nullptr) {
        long index = this->map->map_zones->create_zone_map(terrain_table + 1, 99);
        this->map_zone = this->map->map_zones->get_zone_map(index);
    } else {
        this->map_zone = nullptr;
    }

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
    if (param_1 == 1) {
        return 1;
    }
    if (param_1 == 4) {
        return 1;
    }
    return (uchar)(param_1 == 0x16);
}

void RGE_RMM_Terrain_Generator::check_borders() {
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
                tile->terrain_type = (uchar)((tile->terrain_type & 0xe2) | 2);
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
    (void)param_2;
    (void)param_3;
    return (float)(250 - param_4 * param_1);
}

long RGE_RMM_Terrain_Generator::count_map_tiles(uchar param_1) {
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
                           (max_y < ty) &&
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

RGE_RMM_Object_Generator::RGE_RMM_Object_Generator(
    RGE_Map* param_1,
    RGE_Random_Map_Module* param_2,
    RGE_Game_World* param_3,
    RGE_Object_Info* param_4,
    uchar param_5)
    : RGE_Random_Map_Module(param_1, param_2, 1) {
    this->schedule = 3.0f;
    this->world = param_3;
    memset(&this->info, 0, sizeof(this->info));
    if (param_4 != nullptr) {
        memcpy(&this->info, param_4, sizeof(this->info));
    }
    memset(this->terrain_table, 0, sizeof(this->terrain_table));
    this->add_terrain = param_5;
}

static long rmm_obj_rand_scaled(long scale, int line_no) {
    if (scale <= 0) {
        return 0;
    }
    long r = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", line_no);
    return (long)(((long long)r * (long long)scale) / 0x7fffLL);
}

static float rmm_obj_adjust_coord(float tile, float radius) {
    long i = (long)radius;
    if ((radius - (float)i) > 0.0f) {
        tile += 0.5f;
    }
    return tile;
}

static int rmm_obj_terrain_matches(RGE_RMM_Object_Generator* self, RGE_Object_Info_Line& line, long x, long y) {
    if (self == nullptr || self->map_row_offset == nullptr ||
        x < 0 || y < 0 || x >= self->map_width || y >= self->map_height) {
        return 0;
    }
    if (line.terrain < 0) {
        return 1;
    }
    uchar tt = (uchar)(self->map_row_offset[y][x].terrain_type & 0x1f);
    return tt == line.terrain;
}

static RGE_Player* rmm_obj_get_player_safe(RGE_RMM_Object_Generator* self, long player_index) {
    if (self == nullptr || self->world == nullptr || self->world->players == nullptr || self->world->player_num <= 0) {
        return nullptr;
    }
    if (player_index < 0 || player_index >= self->world->player_num) {
        player_index = 0;
    }
    return self->world->players[player_index];
}

void RGE_RMM_Object_Generator::add_quick_obj(long param_1, long param_2, long param_3) {
    if (this->info.object_num < 0 || this->info.object_num >= 99) {
        return;
    }

    RGE_Object_Info_Line* line = &this->info.objects[this->info.object_num];
    line->obj_id = param_1;
    line->terrain = -1;
    line->group_flag = 0;
    line->scale_flag = 0;
    line->object_number_per_group = 1;
    line->object_number_varience = 1;
    line->number_of_groups = param_2;
    line->group_area = 2;
    line->player_id = 0;
    line->land_id = -1;
    line->land_inner_radius = 0;
    line->land_outer_radius = 1;
    line->object_exclusion_zone = param_3;
    this->info.object_num = this->info.object_num + 1;
}

void RGE_RMM_Object_Generator::generate_objects(RGE_Object_Info_Line& param_1) {
    if (param_1.scale_flag != 0) {
        long groups = (this->map_width * this->map_height * param_1.number_of_groups) / 0x5100;
        param_1.number_of_groups = groups;
        if (groups < 1) {
            param_1.number_of_groups = 1;
        }
    }

    if (param_1.land_id < 0) {
        if (param_1.land_id == -1) {
            this->place_objects(param_1);
            return;
        }
        if (param_1.land_id == -2) {
            this->place_avoid_objects(param_1, param_1.land_inner_radius);
        }
        return;
    }

    for (long i = 0; i < this->info.land_num; ++i) {
        if (this->info.lands[i].id == param_1.land_id) {
            this->place_land_objects(
                param_1,
                this->info.lands[i].x,
                this->info.lands[i].y,
                param_1.land_inner_radius,
                param_1.land_outer_radius,
                i);
        }
    }
}

void RGE_RMM_Object_Generator::make_placement_stack(
    Map_Stack& param_1,
    long param_2,
    long param_3,
    long param_4,
    long param_5) {
    (void)param_4;
    param_1.next = nullptr;
    param_1.prev = nullptr;

    if (this->search_map_rows == nullptr || this->stack_offsets == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    long x0;
    long y0;
    long x1;
    long y1;

    if ((param_2 < 0) || (param_3 < 0) || (param_5 < 0)) {
        x0 = 0;
        y0 = 0;
        x1 = this->map_width - 1;
        y1 = this->map_height - 1;
    } else {
        x0 = param_2 - param_5;
        y0 = param_3 - param_5;
        x1 = param_2 + param_5;
        y1 = param_3 + param_5;
        if (x0 < 0) x0 = 0;
        if (y0 < 0) y0 = 0;
        if (x1 >= this->map_width) x1 = this->map_width - 1;
        if (y1 >= this->map_height) y1 = this->map_height - 1;
    }

    Map_Stack* last = &param_1;
    for (long y = y0; y <= y1; ++y) {
        for (long x = x0; x <= x1; ++x) {
            if (this->search_map_rows[y][x] != 0) {
                Map_Stack* node = &this->stack_offsets[y][x];
                this->add_stack_node(last, node);
                last = node;
            }
        }
    }

    long span_x = (x1 - x0) - 1;
    long span_y = (y1 - y0) - 1;
    if (span_x > 1 && span_y > 1) {
        long count = (span_y * span_x) / 4;
        while (count > 0) {
            long rx = rmm_obj_rand_scaled(span_x, 0xaf) + x0;
            long ry = rmm_obj_rand_scaled(span_y, 0xb0) + y0;
            if (rx >= 0 && ry >= 0 && rx < this->map_width && ry < this->map_height &&
                this->search_map_rows[ry][rx] != 0) {
                this->add_stack_node(&param_1, &this->stack_offsets[ry][rx]);
            }
            count = count - 1;
        }
    }
}

uchar RGE_RMM_Object_Generator::to_close(RGE_Object_Info_Line& param_1, long param_2, long param_3) {
    for (long i = 0; i < this->info.land_num; ++i) {
        long dx = param_2 - this->info.lands[i].x;
        long dy = param_3 - this->info.lands[i].y;
        if (dx < 0) dx = -dx;
        if (dy < 0) dy = -dy;
        if (dx < param_1.land_inner_radius && dy < param_1.land_inner_radius) {
            return 1;
        }
    }
    return 0;
}

void RGE_RMM_Object_Generator::set_search_area(long param_1, long param_2, long param_3, uchar param_4) {
    if (this->search_map_rows == nullptr || this->map_width <= 0 || this->map_height <= 0) {
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
            this->search_map_rows[y][x] = param_4;
        }
    }
}

void RGE_RMM_Object_Generator::remove_area_from_lists(long param_1, long param_2, long param_3) {
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

void RGE_RMM_Object_Generator::place_avoid_objects(RGE_Object_Info_Line& param_1, long param_2) {
    (void)param_2;
    if (this->search_map == nullptr || this->search_map_rows == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    memset(this->search_map, 1, (size_t)this->map_width * (size_t)this->map_height);
    for (long i = 0; i < this->info.land_num; ++i) {
        this->set_search_area(this->info.lands[i].x, this->info.lands[i].y, param_1.land_inner_radius, 0);
    }

    Map_Stack obj_stack;
    this->init_stack(&obj_stack);
    this->make_placement_stack(obj_stack, -1, -1, -1, -1);

    long player_index = (param_1.player_id < 0) ? 0 : param_1.player_id;
    RGE_Player* player = rmm_obj_get_player_safe(this, player_index);
    if (player == nullptr) {
        this->deinit_stack(&obj_stack);
        return;
    }

    long remaining = param_1.number_of_groups;
    float pop_cost = 0.0f;
    long tile_x = 0;
    long tile_y = 0;
    Map_Stack* node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    while (node != nullptr && remaining > 0) {
        if (rmm_obj_terrain_matches(this, param_1, tile_x, tile_y) != 0 &&
            player->master_objects != nullptr &&
            param_1.obj_id >= 0 && param_1.obj_id < player->master_object_num) {
            RGE_Master_Static_Object* master = player->master_objects[param_1.obj_id];
            if (master != nullptr) {
                float place_x = rmm_obj_adjust_coord((float)tile_x, master->radius_x);
                float place_y = rmm_obj_adjust_coord((float)tile_y, master->radius_y);
                uchar blocked = master->check_placement(player, place_x, place_y, 0, 0, 1, 1, 1, 0, 1);
                if (blocked == 0) {
                    this->remove_area_from_lists(tile_x, tile_y, param_1.object_exclusion_zone);
                    if (param_1.group_flag == 0) {
                        player->make_new_object(param_1.obj_id, place_x, place_y, 0.0f, 1);
                    } else if (param_1.group_flag == 1) {
                        this->place_group(param_1, tile_x, tile_y, player);
                    } else if (param_1.group_flag == 2) {
                        this->place_cluster(param_1, tile_x, tile_y, player);
                    }
                    remaining = remaining - 1;
                }
            }
        }
        node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    }

    this->deinit_stack(&obj_stack);
}

void RGE_RMM_Object_Generator::place_objects(RGE_Object_Info_Line& param_1) {
    if (this->search_map == nullptr || this->search_map_rows == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    memset(this->search_map, 1, (size_t)this->map_width * (size_t)this->map_height);

    Map_Stack obj_stack;
    this->init_stack(&obj_stack);
    this->make_placement_stack(obj_stack, -1, -1, -1, -1);

    long player_index = (param_1.player_id < 0) ? 0 : param_1.player_id;
    RGE_Player* player = rmm_obj_get_player_safe(this, player_index);
    if (player == nullptr) {
        this->deinit_stack(&obj_stack);
        return;
    }

    long remaining = param_1.number_of_groups;
    float pop_cost = 0.0f;
    long tile_x = 0;
    long tile_y = 0;
    Map_Stack* node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    while (node != nullptr && remaining > 0) {
        if (rmm_obj_terrain_matches(this, param_1, tile_x, tile_y) != 0 &&
            player->master_objects != nullptr &&
            param_1.obj_id >= 0 && param_1.obj_id < player->master_object_num) {
            RGE_Master_Static_Object* master = player->master_objects[param_1.obj_id];
            if (master != nullptr) {
                float place_x = rmm_obj_adjust_coord((float)tile_x, master->radius_x);
                float place_y = rmm_obj_adjust_coord((float)tile_y, master->radius_y);
                uchar blocked = master->check_placement(player, place_x, place_y, 0, 0, 1, 1, 1, 0, 1);
                if (blocked == 0) {
                    this->remove_area_from_lists(tile_x, tile_y, param_1.object_exclusion_zone);
                    if (param_1.group_flag == 0) {
                        player->make_new_object(param_1.obj_id, place_x, place_y, 0.0f, 1);
                    } else if (param_1.group_flag == 1) {
                        this->place_group(param_1, tile_x, tile_y, player);
                    } else if (param_1.group_flag == 2) {
                        this->place_cluster(param_1, tile_x, tile_y, player);
                    }
                    remaining = remaining - 1;
                }
            }
        }
        node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    }

    this->deinit_stack(&obj_stack);
}

void RGE_RMM_Object_Generator::place_land_objects(
    RGE_Object_Info_Line& param_1,
    long param_2,
    long param_3,
    long param_4,
    long param_5,
    long param_6) {
    if (this->search_map == nullptr || this->search_map_rows == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    long min_x1 = param_2 - param_4;
    long min_y1 = param_3 - param_4;
    long min_y0 = param_2 + param_4;
    long local_28 = param_3 + param_4;

    if (min_x1 < 0) min_x1 = 0;
    if (min_y1 < 0) min_y1 = 0;
    if (min_y0 >= this->map_width) min_y0 = this->map_width - 1;
    if (local_28 >= this->map_height) local_28 = this->map_height - 1;

    memset(this->search_map, 1, (size_t)this->map_width * (size_t)this->map_height);
    for (long i = 0; i < this->info.land_num; ++i) {
        this->set_search_area(this->info.lands[i].x, this->info.lands[i].y, param_4, 0);
    }

    Map_Stack obj_stack;
    this->init_stack(&obj_stack);
    this->make_placement_stack(obj_stack, param_2, param_3, param_4, param_5);

    long player_index = param_1.player_id;
    if (player_index < 0) {
        player_index = 0;
        if (param_6 >= 0 && param_6 < this->info.land_num && this->info.lands[param_6].player_id > 0) {
            player_index = this->info.lands[param_6].player_id;
        }
    }

    RGE_Player* player = rmm_obj_get_player_safe(this, player_index);
    if (player == nullptr || player->master_objects == nullptr ||
        param_1.obj_id < 0 || param_1.obj_id >= player->master_object_num) {
        this->deinit_stack(&obj_stack);
        return;
    }

    RGE_Master_Static_Object* master = player->master_objects[param_1.obj_id];
    if (master == nullptr || this->map == nullptr || this->map->map_zones == nullptr ||
        this->world == nullptr || this->world->terrains == nullptr) {
        this->deinit_stack(&obj_stack);
        return;
    }

    short terrain_index = master->terrain;
    if (terrain_index < 0 || terrain_index >= this->world->terrain_num) {
        this->deinit_stack(&obj_stack);
        return;
    }

    int zone_map_index = 0;
    RGE_Zone_Map* zone_map = this->map->map_zones->get_zone_map(this->world->terrains[terrain_index], 0x20, &zone_map_index);
    if (zone_map == nullptr) {
        this->deinit_stack(&obj_stack);
        return;
    }

    uchar center_zone = zone_map->get_zone_info(param_2, param_3);
    long remaining = param_1.number_of_groups;
    float pop_cost = 0.0f;
    long tile_x = 0;
    long tile_y = 0;
    Map_Stack* node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);

    while (node != nullptr && remaining > 0) {
        uchar tile_zone = zone_map->get_zone_info(tile_x, tile_y);
        if (tile_zone == center_zone &&
            rmm_obj_terrain_matches(this, param_1, tile_x, tile_y) != 0 &&
            ((tile_x <= min_x1) || (tile_x >= min_y0) || (tile_y <= min_y1) || (tile_y >= local_28))) {
            float place_x = rmm_obj_adjust_coord((float)tile_x, master->radius_x);
            float place_y = rmm_obj_adjust_coord((float)tile_y, master->radius_y);
            uchar blocked = master->check_placement(player, place_x, place_y, 0, 0, 1, 1, 1, 1, 1);
            if (blocked == 0) {
                this->remove_area_from_lists(tile_x, tile_y, param_1.object_exclusion_zone);
                if (param_1.group_flag == 0) {
                    player->make_new_object(param_1.obj_id, place_x, place_y, 0.0f, 1);
                } else if (param_1.group_flag == 1) {
                    this->place_group(param_1, tile_x, tile_y, player);
                } else if (param_1.group_flag == 2) {
                    this->place_cluster(param_1, tile_x, tile_y, player);
                }
                remaining = remaining - 1;
            } else if (param_1.group_flag == 0 && obj_stack.prev == nullptr) {
                player->make_new_object(param_1.obj_id, place_x, place_y, 0.0f, 1);
            }
        }

        node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    }

    this->deinit_stack(&obj_stack);
}

void RGE_RMM_Object_Generator::place_group(
    RGE_Object_Info_Line& param_1,
    long param_2,
    long param_3,
    RGE_Player* param_4) {
    if (param_4 == nullptr) {
        return;
    }

    Map_Stack obj_stack;
    this->init_stack(&obj_stack);
    this->make_placement_stack(obj_stack, param_2, param_3, 0, param_1.group_area);

    long rv = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x212);
    long remaining = param_1.object_number_per_group +
        (long)(((long long)rv * (long long)param_1.object_number_varience * 2LL) / 0x7fffLL) -
        param_1.object_number_varience;
    if (remaining < 1) {
        remaining = 1;
    }

    float pop_cost = 0.0f;
    long tile_x = 0;
    long tile_y = 0;
    Map_Stack* node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    while (node != nullptr && remaining > 0) {
        if (rmm_obj_terrain_matches(this, param_1, tile_x, tile_y) != 0 &&
            param_4->master_objects != nullptr &&
            param_1.obj_id >= 0 && param_1.obj_id < param_4->master_object_num) {
            RGE_Master_Static_Object* master = param_4->master_objects[param_1.obj_id];
            if (master != nullptr) {
                float place_x = rmm_obj_adjust_coord((float)tile_x, master->radius_x);
                float place_y = rmm_obj_adjust_coord((float)tile_y, master->radius_y);
                if (master->check_placement(param_4, place_x, place_y, 0, 0, 1, 1, 1, 0, 1) == 0) {
                    param_4->make_new_object(param_1.obj_id, place_x, place_y, 0.0f, 1);
                    remaining = remaining - 1;
                }
            }
        }
        node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    }

    this->deinit_stack(&obj_stack);
}

void RGE_RMM_Object_Generator::place_cluster(
    RGE_Object_Info_Line& param_1,
    long param_2,
    long param_3,
    RGE_Player* param_4) {
    if (param_4 == nullptr || this->search_map_rows == nullptr || this->stack_offsets == nullptr) {
        return;
    }

    Map_Stack obj_stack;
    obj_stack.prev = nullptr;
    this->init_stack(&obj_stack);

    if (param_2 >= 0 && param_2 < this->map_width && param_3 >= 0 && param_3 < this->map_height) {
        this->add_stack_node(&obj_stack, &this->stack_offsets[param_3][param_2]);
    }

    long area = param_1.group_area;
    long min_y = param_3 - area;
    long max_x = param_2 + area;
    long max_y = param_3 + area;
    long min_x = param_2 - area;

    if (min_x < 0) min_x = 0;
    if (min_y < 0) min_y = 0;
    if (max_x >= this->map_width) max_x = this->map_width - 1;
    if (max_y >= this->map_height) max_y = this->map_height - 1;

    for (long y = min_y; y <= max_y; ++y) {
        for (long x = min_x; x <= max_x; ++x) {
            this->search_map_rows[y][x] = 1;
        }
    }

    long rv = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x256);
    long remaining = param_1.object_number_per_group +
        (long)(((long long)rv * (long long)param_1.object_number_varience * 2LL) / 0x7fffLL) -
        param_1.object_number_varience;
    if (remaining < 1) {
        remaining = 1;
    }

    float pop_cost = 0.0f;
    long tile_x = 0;
    long tile_y = 0;
    Map_Stack* node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    while (node != nullptr && remaining > 0) {
        if (param_4->master_objects != nullptr &&
            param_1.obj_id >= 0 && param_1.obj_id < param_4->master_object_num) {
            RGE_Master_Static_Object* master = param_4->master_objects[param_1.obj_id];
            if (master != nullptr) {
                float place_x = rmm_obj_adjust_coord((float)tile_x, master->radius_x);
                float place_y = rmm_obj_adjust_coord((float)tile_y, master->radius_y);
                master->alignment(&place_x, &place_y, this->world, 1);
                if (master->check_placement(param_4, place_x, place_y, 0, 0, 1, 1, 1, 0, 1) == 0) {
                    param_4->make_new_object(param_1.obj_id, place_x, place_y, 0.0f, 1);
                    remaining = remaining - 1;
                    if (tile_x >= 0 && tile_x < this->map_width && tile_y >= 0 && tile_y < this->map_height) {
                        this->search_map_rows[tile_y][tile_x] = 0;
                    }

                    if ((min_x < tile_x) && this->search_map_rows[tile_y][tile_x - 1] != 0) {
                        this->push_stack(
                            &obj_stack,
                            tile_x - 1,
                            tile_y,
                            0.0f,
                            (float)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x270));
                    }
                    if ((tile_x < max_x) && this->search_map_rows[tile_y][tile_x + 1] != 0) {
                        this->push_stack(
                            &obj_stack,
                            tile_x + 1,
                            tile_y,
                            0.0f,
                            (float)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x273));
                    }
                    if ((min_y < tile_y) && this->search_map_rows[tile_y - 1][tile_x] != 0) {
                        this->push_stack(
                            &obj_stack,
                            tile_x,
                            tile_y - 1,
                            0.0f,
                            (float)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x276));
                    }
                    if ((tile_y < max_y) && this->search_map_rows[tile_y + 1][tile_x] != 0) {
                        this->push_stack(
                            &obj_stack,
                            tile_x,
                            tile_y + 1,
                            0.0f,
                            (float)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x279));
                    }
                }
            }
        }
        node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    }

    this->deinit_stack(&obj_stack);
}

uchar RGE_RMM_Object_Generator::generate() {
    if (this->parent == nullptr) {
        return 0;
    }
    if (this->add_terrain != 0 && this->map != nullptr && this->world != nullptr &&
        this->world->players != nullptr && this->world->player_num > 0 && this->map_width > 0 && this->map_height > 0) {
        RGE_Player* gaia = this->world->players[0];
        this->map->set_terrain(
            gaia,
            this->world,
            0,
            0,
            (short)(this->map_width - 1),
            (short)(this->map_height - 1),
            1,
            0,
            0);
    }
    this->clear_stack();
    memset(this->terrain_table, 0, sizeof(this->terrain_table));
    for (long i = 0; i < this->info.object_num; ++i) {
        this->generate_objects(this->info.objects[i]);
    }
    if (this->map != nullptr && this->map->map_zones != nullptr) {
        this->map->map_zones->delete_zone_maps();
    }
    return 1;
}

RGE_RMM_Elevation_Generator::RGE_RMM_Elevation_Generator(
    RGE_Map* param_1,
    RGE_Random_Map_Module* param_2,
    RGE_Elevation_Info* param_3)
    : RGE_Random_Map_Module(param_1, param_2, 1) {
    this->schedule = 1.5f;
    memset(&this->info, 0, sizeof(this->info));
    if (param_3 != nullptr) {
        memcpy(&this->info, param_3, sizeof(this->info));
    }
}

uchar RGE_RMM_Elevation_Generator::generate() {
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

static long rmm_elev_rand_scaled(long scale, int line_no) {
    if (scale <= 0) {
        return 0;
    }
    long r = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_elev.cpp", line_no);
    return (long)(((long long)r * (long long)scale) / 0x7fffLL);
}

uchar RGE_RMM_Elevation_Generator::check_start_elevation(
    long param_1,
    long param_2,
    uchar param_3,
    uchar param_4,
    uchar param_5) {
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
            if (param_3 == 0xff || t->terrain_type != param_3 || t->height < param_4) {
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
                if (param_5 == 0xff || t->terrain_type != param_5 || t->height < param_6) {
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
    (void)param_2;
    (void)param_3;
    return (float)(-15 * param_1 + 250);
}

long RGE_RMM_Elevation_Generator::count_map_tiles(uchar param_1) {
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

void RGE_RMM_Elevation_Generator::link_stack_randomly(Map_Stack* param_1) {
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
    if (this->stack_offsets == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    long x0 = param_1 - param_3;
    long y0 = param_2 - param_3;
    long x1 = param_1 + param_3;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= this->map_width) x1 = this->map_width - 1;

    long y1 = x1;
    if (y1 >= this->map_height) y1 = this->map_height - 1;
    for (long y = y0; y <= y1; ++y) {
        for (long x = x0; x <= x1; ++x) {
            this->remove_stack_node(&this->stack_offsets[y][x]);
        }
    }
}

uchar RGE_RMM_Elevation_Generator::base_elevation_generate(RGE_Elevation_Info_Line param_1) {
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

RGE_RMM_Shallows_Generator::RGE_RMM_Shallows_Generator(
    RGE_Map* param_1,
    RGE_Random_Map_Module* param_2,
    RGE_Shallows_Info* param_3)
    : RGE_Random_Map_Module(param_1, param_2, 1) {
    this->schedule = 1.1f;
    memset(&this->info, 0, sizeof(this->info));
    if (param_3 != nullptr) {
        memcpy(&this->info, param_3, sizeof(this->info));
    }
}

uchar RGE_RMM_Shallows_Generator::generate() {
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

    this->info.shallows_num = num + 2;
    int pair_count = 2;
    while (pair_count > 0) {
        int found = 0;
        while (found == 0) {
            long x = rmm_rand_range(this->map_width);
            long y = rmm_rand_range(this->map_height);
            uchar tt = (uchar)(this->map_row_offset[y][x].terrain_type & 0x1f);
            if (tt != 1 && tt != 22 && tt != 4) {
                this->info.shallows[num + 1].x = x;
                this->info.shallows[num + 1].y = y;
                found = 1;
            }
        }

        found = 0;
        while (found == 0) {
            long x = rmm_rand_range(this->map_width);
            long y = rmm_rand_range(this->map_height);
            uchar tt = (uchar)(this->map_row_offset[y][x].terrain_type & 0x1f);
            if (tt != 1 && tt != 22 && tt != 4) {
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
    terrain_cost[23] = 14.0f;

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
            case 11:
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
        if (tt == 1 || tt == 22) {
            long sx0 = nx - 1 - rmm_rand_range(2);
            long sy0 = ny - 1 - rmm_rand_range(2);
            long sx1 = nx + 1 + rmm_rand_range(2);
            long sy1 = ny + 1 + rmm_rand_range(3);

            if (sx0 < 0) sx0 = 0;
            if (sy0 < 0) sy0 = 0;
            if (sx1 >= this->map_width) sx1 = this->map_width - 1;
            if (sy1 >= this->map_height) sy1 = this->map_height - 1;

            for (long yy = sy0; yy <= sy1; ++yy) {
                for (long xx = sx0; xx <= sx1; ++xx) {
                    uchar wtt = (uchar)(this->map_row_offset[yy][xx].terrain_type & 0x1f);
                    if (wtt == 1 || wtt == 22) {
                        this->push_stack(&stack, xx, yy, 0.0f, 0.0f);
                    }
                }
            }
        } else {
            if (nx > 0) {
                uchar wtt = (uchar)(this->map_row_offset[ny][nx - 1].terrain_type & 0x1f);
                if (wtt == 1 || wtt == 22) {
                    this->push_stack(&stack, nx - 1, ny, 0.0f, 0.0f);
                }
            }
            if (nx < this->map_width - 1) {
                uchar wtt = (uchar)(this->map_row_offset[ny][nx + 1].terrain_type & 0x1f);
                if (wtt == 1 || wtt == 22) {
                    this->push_stack(&stack, nx + 1, ny, 0.0f, 0.0f);
                }
            }
            if (ny > 0) {
                uchar wtt = (uchar)(this->map_row_offset[ny - 1][nx].terrain_type & 0x1f);
                if (wtt == 1 || wtt == 22) {
                    this->push_stack(&stack, nx, ny - 1, 0.0f, 0.0f);
                }
            }
            if (ny < this->map_height - 1) {
                uchar wtt = (uchar)(this->map_row_offset[ny + 1][nx].terrain_type & 0x1f);
                if (wtt == 1 || wtt == 22) {
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

#endif // 0

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
    if (this->map == nullptr || this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }
    (void)new (std::nothrow) RGE_RMM_Terrain_Generator(this->map, this, &this->terrain_info);
    (void)new (std::nothrow) RGE_RMM_Land_Generator(this->map, this, &this->land_info);
    (void)new (std::nothrow) RGE_RMM_Object_Generator(this->map, this, this->world, &this->object_info, 1);
    (void)new (std::nothrow) RGE_RMM_Elevation_Generator(this->map, this, &this->elevation_info);

    if (RGE_Random_Map_Module::generate() == 0) {
        return 0;
    }

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
    memset(&this->land_info, 0, sizeof(this->land_info));

    RGE_Map_Data_Entry* map_entry = rmm_select_map_entry(this);
    if (map_entry == nullptr) {
        return;
    }

    RGE_Land_Data* src = &map_entry->land_info;
    if (src->land == nullptr || src->land_num <= 0) {
        return;
    }

    uchar base_tt = (uchar)src->base_terrain;
    this->land_info.base_terrain = base_tt;
    this->land_info.wall_1_avoidance_line = src->map_edge_buffer[0];
    this->land_info.wall_2_avoidance_line = src->map_edge_buffer[1];
    this->land_info.wall_3_avoidance_line = this->map_width - src->map_edge_buffer[2];
    this->land_info.wall_4_avoidance_line = this->map_height - src->map_edge_buffer[3];
    this->land_info.wall_fade = (uchar)src->map_edge_fade;

    long land_num = 0;
    for (long i = 0; i < src->land_num; ++i) {
        if (src->land[i].by_player_flag == 0) {
            land_num += 1;
        } else {
            land_num += this->number_of_players;
        }
    }
    if (land_num < 0) land_num = 0;
    if (land_num > 99) land_num = 99;
    this->land_info.land_num = land_num;

    long grown_land_tiles = (src->grown_land_percent * this->map_width * this->map_height) / 100;
    if (grown_land_tiles < 1) {
        grown_land_tiles = this->map_width * this->map_height;
    }

    long edge = src->land_placement_edge;
    if (edge < 0) edge = 0;
    long dst_index = 0;

    for (long i = 0; i < src->land_num && dst_index < this->land_info.land_num; ++i) {
        RGE_Land_Data_Entry* s = &src->land[i];
        long terrain_type = (long)s->terrain_type;
        long land_size = ((long)s->amount_of_land_used_percent * grown_land_tiles) / 100;
        if (land_size < 1) {
            land_size = 1;
        }

        if (s->by_player_flag == 0 || this->number_of_players <= 0) {
            rmm_calc_land_start(this, dst_index, edge, 1, s);

            RGE_Land_Info_Line* d = &this->land_info.land[dst_index];
            d->land_size = land_size;
            d->terrain_type = terrain_type;
            d->base_size = s->base_square_radius;
            d->area = s->land_avoidance_tiles;
            d->zone = s->zone;
            d->clumpiness_factor = s->clumpiness_factor;
            d->wall_1_avoidance_line = this->land_info.wall_1_avoidance_line;
            d->wall_2_avoidance_line = this->land_info.wall_2_avoidance_line;
            d->wall_3_avoidance_line = this->land_info.wall_3_avoidance_line;
            d->wall_4_avoidance_line = this->land_info.wall_4_avoidance_line;
            d->wall_fade = this->land_info.wall_fade;
            ++dst_index;
            continue;
        }

        rmm_calc_land_start(this, dst_index, edge, this->number_of_players, s);
        long per_player_size = land_size / this->number_of_players;
        if (per_player_size < 1) {
            per_player_size = 1;
        }

        for (long player_i = 0; player_i < this->number_of_players && dst_index < this->land_info.land_num; ++player_i) {
            RGE_Land_Info_Line* d = &this->land_info.land[dst_index];
            d->land_size = per_player_size;
            d->terrain_type = terrain_type;
            d->base_size = s->base_square_radius;
            d->area = s->land_avoidance_tiles;
            d->zone = (s->by_player_flag == 1) ? s->zone : (uchar)player_i;
            d->clumpiness_factor = s->clumpiness_factor;
            d->wall_1_avoidance_line = this->land_info.wall_1_avoidance_line;
            d->wall_2_avoidance_line = this->land_info.wall_2_avoidance_line;
            d->wall_3_avoidance_line = this->land_info.wall_3_avoidance_line;
            d->wall_4_avoidance_line = this->land_info.wall_4_avoidance_line;
            d->wall_fade = this->land_info.wall_fade;
            ++dst_index;
        }
    }

    this->land_info.land_num = dst_index;

    if (param_1 != 0 && this->land_info.land_num > 1) {
        if (rmm_randomize_land_positions_by_team(this) == 0) {
            for (long i = 0; i < this->land_info.land_num; ++i) {
                long rem = this->land_info.land_num - i;
                if (rem <= 1) {
                    break;
                }
                long j = i + rmm_rand_range(rem);
                if (j < i) j = i;
                if (j >= this->land_info.land_num) j = this->land_info.land_num - 1;
                if (j == i) {
                    continue;
                }

                long tx = this->land_info.land[i].x;
                long ty = this->land_info.land[i].y;
                this->land_info.land[i].x = this->land_info.land[j].x;
                this->land_info.land[i].y = this->land_info.land[j].y;
                this->land_info.land[j].x = tx;
                this->land_info.land[j].y = ty;
            }
        }
    }
}

void RGE_RMM_Database_Controller::add_terrain_module() {
    memset(&this->terrain_info, 0, sizeof(this->terrain_info));

    RGE_Map_Data_Entry* map_entry = rmm_select_map_entry(this);
    if (map_entry == nullptr) {
        return;
    }

    RGE_Terrain_Data* src = &map_entry->terrain_info;
    long terrain_num = src->terrain_num;
    if (terrain_num < 0) terrain_num = 0;
    if (terrain_num > 99) terrain_num = 99;
    this->terrain_info.terrain_num = terrain_num;

    for (long i = 0; i < terrain_num; ++i) {
        RGE_Terrain_Data_Entry* s = &src->terrain[i];
        RGE_Terrain_Info_Line* d = &this->terrain_info.terrain[i];
        d->terrain_size = s->terrain_percent;
        d->terrain_generated = 0;
        d->terrain_type = (long)s->terrain_type;
        d->clumps = s->clumps;
        d->spacing = s->spacing;
        d->base_terrain_type = (long)s->base_terrain_type;
        d->clumpiness_factor = s->clumpiness_factor;
        d->avoid_hot_spots = 1;
    }

    long hot_spot_index = 0;
    if (map_entry->land_info.land_num > 0 && map_entry->land_info.land != nullptr) {
        for (long i = 0; i < map_entry->land_info.land_num; ++i) {
            if (hot_spot_index >= 99 || hot_spot_index >= this->land_info.land_num) {
                break;
            }
            RGE_Land_Data_Entry* land = &map_entry->land_info.land[i];
            if (land->radius < 0) {
                continue;
            }

            if (land->by_player_flag == 0) {
                this->terrain_info.hot_spots[hot_spot_index].x = this->land_info.land[hot_spot_index].x;
                this->terrain_info.hot_spots[hot_spot_index].y = this->land_info.land[hot_spot_index].y;
                this->terrain_info.hot_spots[hot_spot_index].radius = land->radius;
                this->terrain_info.hot_spots[hot_spot_index].fade = land->fade;
                ++hot_spot_index;
            } else {
                long player_i = 0;
                while (player_i < this->number_of_players && hot_spot_index < 99 && hot_spot_index < this->land_info.land_num) {
                    this->terrain_info.hot_spots[hot_spot_index].x = this->land_info.land[hot_spot_index].x;
                    this->terrain_info.hot_spots[hot_spot_index].y = this->land_info.land[hot_spot_index].y;
                    this->terrain_info.hot_spots[hot_spot_index].radius = land->radius;
                    this->terrain_info.hot_spots[hot_spot_index].fade = land->fade;
                    ++hot_spot_index;
                    ++player_i;
                }
            }
        }
    }
    this->terrain_info.hot_spot_num = hot_spot_index;
}

void RGE_RMM_Database_Controller::add_object_module() {
    memset(&this->object_info, 0, sizeof(this->object_info));
    RGE_Map_Data_Entry* map_entry = rmm_select_map_entry(this);
    if (map_entry == nullptr) {
        return;
    }

    long object_num = 0;
    if (map_entry->object_info.objects != nullptr && map_entry->object_info.object_num > 0) {
        RGE_Object_Data* src = &map_entry->object_info;
        object_num = src->object_num;
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
    }

    long land_num = this->land_info.land_num;
    if (land_num < 0) land_num = 0;
    if (land_num > 99) land_num = 99;
    this->object_info.land_num = land_num;

    long src_land_num = 0;
    RGE_Land_Data_Entry* src_land = nullptr;
    if (map_entry != nullptr && map_entry->land_info.land != nullptr && map_entry->land_info.land_num > 0) {
        src_land_num = map_entry->land_info.land_num;
        src_land = map_entry->land_info.land;
    }

    long src_land_index = 0;
    long by_player_cycle = 0;
    if (src_land_num > 0 && src_land[0].by_player_flag != 0) {
        by_player_cycle = 1;
    }

    for (long i = 0; i < land_num; ++i) {
        RGE_Land_Point_Info_Line* d = &this->object_info.lands[i];
        d->x = this->land_info.land[i].x;
        d->y = this->land_info.land[i].y;

        if (src_land_num <= 0 || src_land == nullptr) {
            d->id = i;
            d->player_id = 0;
            continue;
        }
        if (src_land_index < 0) {
            src_land_index = 0;
        }
        if (src_land_index >= src_land_num) {
            src_land_index = src_land_num - 1;
        }

        d->id = src_land[src_land_index].land_id;
        d->player_id = by_player_cycle;

        if (by_player_cycle != 0) {
            ++by_player_cycle;
            if (by_player_cycle > this->number_of_players) {
                by_player_cycle = 0;
            }
        }

        if (by_player_cycle == 0) {
            long next_src = src_land_index + 1;
            if (next_src < src_land_num && src_land[next_src].by_player_flag != 0) {
                by_player_cycle = 1;
            }
            src_land_index = next_src;
            if (src_land_index >= src_land_num) {
                src_land_index = src_land_num - 1;
            }
        }
    }
}

void RGE_RMM_Database_Controller::add_elevation_module() {
    memset(&this->elevation_info, 0, sizeof(this->elevation_info));
    RGE_Map_Data_Entry* map_entry = rmm_select_map_entry(this);
    if (map_entry == nullptr) {
        return;
    }

    long grown_land_percent = map_entry->land_info.grown_land_percent;
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
    long map_type = this->map_type;
    long saved_land_placement_edge = 0;
    RGE_Map_Data_Entry* map_entry = nullptr;
    if (this->map_info.maps != nullptr && map_type >= 0 && map_type < this->map_info.map_num) {
        map_entry = &this->map_info.maps[map_type];
        saved_land_placement_edge = map_entry->land_info.land_placement_edge;
        if ((map_type == 5 || map_type == 8) && this->map_width < 100) {
            map_entry->land_info.land_placement_edge = (((0x4f < this->map_width) - 1) & 0xfffffffb) + 0x19;
        }
    }

    RGE_RMM_Database_Controller::add_land_module(param_1);

    if (map_entry != nullptr) {
        map_entry->land_info.land_placement_edge = saved_land_placement_edge;
    }

    if (this->map_type < 5) {
        if (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0xb9) < 0x3fff) {
            this->land_info.wall_1_avoidance_line = -1;
            for (long i = 0; i < this->land_info.land_num; ++i) {
                this->land_info.land[i].wall_1_avoidance_line = -1;
            }
        }

        if (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0xc0) < 0x3fff) {
            this->land_info.wall_2_avoidance_line = -1;
            for (long i = 0; i < this->land_info.land_num; ++i) {
                this->land_info.land[i].wall_2_avoidance_line = -1;
            }
        }

        if (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 199) < 0x3fff) {
            this->land_info.wall_3_avoidance_line = this->map_width;
            for (long i = 0; i < this->land_info.land_num; ++i) {
                this->land_info.land[i].wall_3_avoidance_line = this->map_width;
            }
        }

        if (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0xce) < 0x3fff) {
            this->land_info.wall_4_avoidance_line = this->map_height;
            for (long i = 0; i < this->land_info.land_num; ++i) {
                this->land_info.land[i].wall_4_avoidance_line = this->map_height;
            }
        }
    }

    if (this->map_type == 8) {
        if (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0xd8) < 0x3fff) {
            this->land_info.wall_3_avoidance_line = this->map_width;
            this->land_info.wall_1_avoidance_line = -1;
            for (long i = 0; i < this->land_info.land_num; ++i) {
                this->land_info.land[i].wall_1_avoidance_line = -1;
                this->land_info.land[i].wall_3_avoidance_line = this->map_width;
            }
        } else {
            this->land_info.wall_4_avoidance_line = this->map_height;
            this->land_info.wall_2_avoidance_line = -1;
            for (long i = 0; i < this->land_info.land_num; ++i) {
                this->land_info.land[i].wall_2_avoidance_line = -1;
                this->land_info.land[i].wall_4_avoidance_line = this->map_height;
            }
        }
    }

    long mt = this->map_type;
    if (((1 < mt) && (mt < 7)) || (mt == 8)) {
        if (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0xf1) < 0x3fff) {
            if (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0xf7) < 0x3fff) {
                for (long i = 0; i < this->land_info.land_num; i += 2) {
                    this->land_info.land[i].zone = 0;
                }
            } else {
                long zone = 0;
                for (long i = 0; i < this->land_info.land_num; i += 2) {
                    this->land_info.land[i].zone = (uchar)zone;
                    zone = zone + 2;
                }
            }

            if (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0xff) < 0x3fff) {
                if (this->land_info.land_num > 1) {
                    for (long zone = 1; zone < this->land_info.land_num; zone += 2) {
                        this->land_info.land[zone].zone = 1;
                    }
                    this->add_shallows_module();
                    goto tribe_land_finalize;
                }
            } else if (this->land_info.land_num > 1) {
                for (long zone = 1; zone < this->land_info.land_num; zone += 2) {
                    this->land_info.land[zone].zone = (uchar)zone;
                }
            }

            this->add_shallows_module();
        } else if (this->map_type == 4) {
            for (long i = 0; i < this->land_info.land_num; ++i) {
                this->land_info.land[i].zone = 0;
            }
            this->land_info.base_terrain = 0;
        } else if (this->map_type > 4) {
            for (long i = 0; i < this->land_info.land_num; ++i) {
                this->land_info.land[i].zone = 0;
            }
        }
    }

tribe_land_finalize:
    if (this->map_type == 5 || this->map_type == 8) {
        long edge = 0x14;
        long width = this->map_width;
        if (width < 100) {
            edge = (((0x4f < width) - 1) & 0xfffffffb) + 0xf;

            if (this->land_info.wall_1_avoidance_line > 0) {
                this->land_info.wall_1_avoidance_line = edge;
            }
            if (this->land_info.wall_2_avoidance_line > 0) {
                this->land_info.wall_2_avoidance_line = edge;
            }
            if (this->land_info.wall_3_avoidance_line < width) {
                this->land_info.wall_3_avoidance_line = width - edge;
            }
            if (this->land_info.wall_4_avoidance_line < this->map_height) {
                this->land_info.wall_4_avoidance_line = this->map_height - edge;
            }

            for (long i = 0; i < this->land_info.land_num; ++i) {
                RGE_Land_Info_Line* land = &this->land_info.land[i];
                if (land->wall_1_avoidance_line > 0) {
                    land->wall_1_avoidance_line = edge;
                }
                if (land->wall_2_avoidance_line > 0) {
                    land->wall_2_avoidance_line = edge;
                }
                if (land->wall_3_avoidance_line < this->map_width) {
                    land->wall_3_avoidance_line = this->map_width - edge;
                }
                if (land->wall_4_avoidance_line < this->map_height) {
                    land->wall_4_avoidance_line = this->map_height - edge;
                }
            }
        }

        long open_width = this->map_width - edge * 2;
        long open_height = this->map_height - edge * 2;
        long land_size = (long)((double)(open_width * open_height) * 0.8);
        for (long i = 0; i < this->land_info.land_num; ++i) {
            if (this->land_info.land_num != 0) {
                this->land_info.land[i].land_size = land_size / this->land_info.land_num;
            }
        }
    }

    (void)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x137);
}

void TRIBE_RMM_Database_Controller::add_terrain_module() {
    long grown_land_percent = 0;
    if (this->map_info.maps != nullptr && this->map_type >= 0 && this->map_type < this->map_info.map_num) {
        grown_land_percent = this->map_info.maps[this->map_type].land_info.grown_land_percent;
    }

    long land_tile_num = (grown_land_percent * this->map_height * this->map_width) / 100;
    RGE_RMM_Database_Controller::add_terrain_module();

    float scale = (float)land_tile_num * 5.0e-05f;
    for (long i = 0; i < this->terrain_info.terrain_num; ++i) {
        RGE_Terrain_Info_Line* terr = &this->terrain_info.terrain[i];
        if (terr->terrain_type != 6 && scale > 1.0f) {
            terr->clumps = (long)((float)terr->clumps * scale);
        }
    }

    if (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x154) < 0x1fff) {
        for (long i = 0; i < this->terrain_info.terrain_num; ++i) {
            RGE_Terrain_Info_Line* terr = &this->terrain_info.terrain[i];
            long terrain_type = terr->terrain_type;
            if (terrain_type == 0xd) {
                terr->terrain_size = terr->terrain_size * 3;
                terr->clumps = terr->clumps * 3;
                terr->avoid_hot_spots = 2;
            } else if (terrain_type == 0x14) {
                terr->terrain_size = terr->terrain_size / 2;
                terr->clumps = terr->clumps / 2;
            } else if (terrain_type == 0x13) {
                terr->terrain_size = terr->terrain_size / 2;
                terr->clumps = terr->clumps / 2;
            } else if (terrain_type == 10) {
                terr->terrain_size = terr->terrain_size / 2;
                terr->clumps = terr->clumps / 2;
                terr->avoid_hot_spots = 2;
            } else if (terrain_type == 6) {
                terr->terrain_size = terr->terrain_size << 1;
                terr->avoid_hot_spots = 0;
            }
        }
    } else {
        for (long i = 0; i < this->terrain_info.terrain_num; ++i) {
            RGE_Terrain_Info_Line* terr = &this->terrain_info.terrain[i];
            if (terr->terrain_type == 6) {
                terr->avoid_hot_spots = 0;
            } else if (terr->terrain_type == 10 || terr->terrain_type == 0xd) {
                terr->avoid_hot_spots = 2;
            }
        }
    }

    (void)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x180);
}

void TRIBE_RMM_Database_Controller::add_object_module() {
    RGE_RMM_Database_Controller::add_object_module();
    (void)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x198);

    if (rge_base_game != nullptr) {
        TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
        if (game->startingAge() == 1) {
            for (long i = 0; i < this->object_info.object_num; ++i) {
                if (this->object_info.objects[i].obj_id == 0x53) {
                    this->object_info.objects[i].number_of_groups = 1;
                }
            }
            for (long i = 0; i < this->object_info.object_num; ++i) {
                if (this->object_info.objects[i].obj_id == 0x6d) {
                    this->object_info.objects[i].number_of_groups = 0;
                }
            }
        }
    }

    if (this->map_type == 6) {
        long land_num = this->land_info.land_num;
        if (land_num > 0) {
            for (long i = land_num; i > 0; --i) {
                memcpy(&this->land_info.land[i], &this->land_info.land[i - 1], sizeof(RGE_Land_Info_Line));
            }
        }

        long edge = this->map_width / 6;
        this->land_info.land[0].zone = (uchar)this->land_info.land_num;
        this->land_info.land[0].terrain_type = 1;
        this->land_info.land[0].area = 7;
        this->land_info.land[0].base_size = 2;

        long open_w = this->map_width - edge * 2;
        long open_h = this->map_height - edge * 2;
        this->land_info.land[0].land_size = (long)((double)(open_w * open_h) * 0.7);
        this->land_info.land[0].clumpiness_factor = 10;

        if (this->map != nullptr) {
            this->land_info.land[0].x = this->map->map_width / 2;
            this->land_info.land[0].y = this->map->map_height / 2;
        } else {
            this->land_info.land[0].x = this->map_width / 2;
            this->land_info.land[0].y = this->map_height / 2;
        }

        this->land_info.land[0].wall_1_avoidance_line = edge;
        this->land_info.land[0].wall_2_avoidance_line = edge;
        this->land_info.land[0].wall_3_avoidance_line = this->map_width - edge;
        this->land_info.land[0].wall_4_avoidance_line = this->map_height - edge;
        this->land_info.land[0].wall_fade = 10;
        this->land_info.land_num = this->land_info.land_num + 1;
    }

    if (this->map_type < 2) {
        long extra_islands =
            ((long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x1c3) * 4) / 0x7fff + 1;
        if (extra_islands + this->number_of_players > 10) {
            extra_islands = 10 - this->number_of_players;
        }

        if (this->land_info.land_num > 0) {
            long dec = ((this->map_height + this->map_width) * extra_islands) / this->land_info.land_num;
            for (long i = 0; i < this->land_info.land_num; ++i) {
                this->land_info.land[i].land_size = this->land_info.land[i].land_size - dec;
            }
        }

        long add_i = 0;
        while (add_i < extra_islands) {
            long new_land_idx = this->land_info.land_num + add_i;
            RGE_Land_Info_Line* land = &this->land_info.land[new_land_idx];
            land->terrain_type = 0;
            land->area = 7;
            land->base_size = 3;
            land->zone = (uchar)new_land_idx;
            land->land_size = (long)((double)(this->map_height + this->map_width) * 1.25);
            land->clumpiness_factor = 10;
            land->wall_1_avoidance_line = this->land_info.wall_1_avoidance_line;
            land->wall_2_avoidance_line = this->land_info.wall_2_avoidance_line;
            land->wall_3_avoidance_line = this->land_info.wall_3_avoidance_line;
            land->wall_4_avoidance_line = this->land_info.wall_4_avoidance_line;
            land->wall_fade = this->land_info.wall_fade;

            long x = 0;
            long y = 0;
            long tries = 0;
            while (true) {
                tries = tries + 1;
                uchar valid = 1;

                x = ((long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x1de) * (this->map_width - 0x10)) / 0x7fff + 8;
                y = ((long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x1df) * (this->map_height - 0x10)) / 0x7fff + 8;

                for (long j = 0; j < this->land_info.land_num; ++j) {
                    if (valid == 0) {
                        break;
                    }
                    long dx = x - this->land_info.land[j].x;
                    long dy = y - this->land_info.land[j].y;
                    if (dx * dx + dy * dy < 400) {
                        valid = 0;
                    }
                }

                if (valid != 0) {
                    break;
                }
                if (tries >= 1000) {
                    break;
                }
            }

            if (tries >= 1000) {
                extra_islands = add_i;
            }

            land->x = x;
            land->y = y;

            long obj_idx = this->object_info.object_num;
            RGE_Object_Info_Line* obj = &this->object_info.objects[obj_idx];
            obj->terrain = -1;
            obj->group_flag = 2;
            obj->scale_flag = 0;
            obj->object_number_per_group = 8;
            obj->object_number_varience = 0;
            obj->number_of_groups = 1;
            obj->group_area = 4;
            obj->player_id = 0;
            obj->land_id = new_land_idx;
            obj->land_inner_radius = 0;
            obj->land_outer_radius = 0x1a;
            obj->object_exclusion_zone = 0;

            if (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x1fd) < 0x3fff) {
                obj->obj_id = 0x66;
            } else {
                obj->obj_id = 0x42;
            }
            this->object_info.object_num = this->object_info.object_num + 1;

            long land_pt_idx = this->object_info.land_num;
            this->object_info.lands[land_pt_idx].x = x;
            this->object_info.lands[land_pt_idx].y = y;
            this->object_info.lands[land_pt_idx].id = new_land_idx;
            this->object_info.lands[land_pt_idx].player_id = 0;
            this->object_info.land_num = this->object_info.land_num + 1;

            add_i = add_i + 1;
        }

        this->land_info.land_num = this->land_info.land_num + extra_islands;
    }

    for (long i = 0; i < this->object_info.object_num; ++i) {
        RGE_Object_Info_Line* obj = &this->object_info.objects[i];
        if (obj->player_id >= 0) {
            switch (obj->obj_id) {
                case 0x3b:
                case 0x41:
                case 0x42:
                case 0x66:
                    obj->object_exclusion_zone = 0xc;
                    break;
                default:
                    break;
            }
        } else if (obj->player_id == -2) {
            switch (obj->obj_id) {
                case 0x3b:
                case 0x42:
                case 0x66:
                    if (this->map != nullptr) {
                        obj->object_exclusion_zone = this->map->map_width / 6;
                    }
                    break;
                case 0x41:
                    if (this->map != nullptr) {
                        obj->object_exclusion_zone = this->map->map_width / 8;
                    }
                    break;
                default:
                    break;
            }
        }
    }

    (void)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x236);
}

void TRIBE_RMM_Database_Controller::add_elevation_module() {
    RGE_RMM_Database_Controller::add_elevation_module();

    long rand_value = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x243);
    float scale = (70.0f - ((float)rand_value * -0.0018311106f)) * 0.01f;
    if (this->map_type == 7) {
        scale = scale * 5.0f;
    }

    for (long i = 0; i < this->elevation_info.elevation_num; ++i) {
        RGE_Elevation_Info_Line* elev = &this->elevation_info.elevation[i];
        elev->elevation_size = (long)((float)elev->elevation_size * scale);
    }

    (void)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x24b);
}

void TRIBE_RMM_Database_Controller::add_shallows_module() {
    if (this->map == nullptr || this->land_info.land_num <= 0) {
        return;
    }

    RGE_Shallows_Info shallows_info;
    memset(&shallows_info, 0, sizeof(shallows_info));

    long n = this->land_info.land_num;
    if (n > 99) n = 99;
    if (n < 0) n = 0;
    shallows_info.shallows_num = n;
    for (long i = 0; i < n; ++i) {
        shallows_info.shallows[i].x = this->land_info.land[i].x;
        shallows_info.shallows[i].y = this->land_info.land[i].y;
    }

    (void)new (std::nothrow) RGE_RMM_Shallows_Generator(this->map, this, &shallows_info);
    (void)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x25f);
}

uchar TRIBE_RMM_Database_Controller::init(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, uchar param_5) {
    uchar land_randomization_flag = param_5;
    if (rge_base_game != nullptr) {
        TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
        land_randomization_flag = (game->randomizePositions() == 0) ? 1 : 0;
    }

    (void)RGE_RMM_Database_Controller::init(param_1, param_2, param_3, param_4, land_randomization_flag);

    long cliff_count = 0;
    long base_cliff_size = 0;

    if (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp", 0x40) > 0x1fff) {
        long map_size = this->map_width;
        if (map_size <= 0x48) {
            cliff_count = 3;
            base_cliff_size = 10;
        } else if (map_size <= 0x60) {
            cliff_count = 4;
            base_cliff_size = 12;
        } else if (map_size <= 0x78) {
            cliff_count = 6;
            base_cliff_size = 14;
        } else if (map_size <= 0x90) {
            cliff_count = 8;
            base_cliff_size = 16;
        } else if (map_size <= 0xc8) {
            cliff_count = 0x12;
            base_cliff_size = 0x14;
        } else {
            cliff_count = 0x1c;
            base_cliff_size = 0x14;
        }

        switch (this->map_type) {
            case 0:
                cliff_count = 0;
                base_cliff_size = 0;
                break;
            case 1:
                cliff_count = cliff_count - 5;
                base_cliff_size = base_cliff_size - 6;
                break;
            case 2:
                cliff_count = cliff_count - 3;
                base_cliff_size = base_cliff_size - 2;
                break;
            case 5:
            case 6:
            case 8:
                base_cliff_size = base_cliff_size - 4;
                break;
            default:
                break;
        }

        if (base_cliff_size < 3) {
            base_cliff_size = 3;
        }

        RGE_Cliffs_Info cliff_info;
        memset(&cliff_info, 0, sizeof(cliff_info));
        cliff_info.number_of_cliffs = cliff_count;
        cliff_info.average_cliff_size = 2;
        cliff_info.cliff_to_cliff_spacing = 2;
        cliff_info.hot_spots[0].x = 2;

        long terrain_spacing = 0;
        if (base_cliff_size - 3 > 0) {
            terrain_spacing = (base_cliff_size - 3) / 2;
        }
        cliff_info.cliff_terrain_spacing = terrain_spacing;
        cliff_info.cliff_size_variance = base_cliff_size - terrain_spacing;

        long hot_spot_num = this->terrain_info.hot_spot_num;
        if (hot_spot_num < 0) hot_spot_num = 0;
        if (hot_spot_num > 99) hot_spot_num = 99;
        cliff_info.hot_spot_num = hot_spot_num;
        for (long i = 0; i < hot_spot_num; ++i) {
            cliff_info.hot_spots[i].x = this->terrain_info.hot_spots[i].x;
            cliff_info.hot_spots[i].y = this->terrain_info.hot_spots[i].y;
            cliff_info.hot_spots[i].radius = this->terrain_info.hot_spots[i].radius;
        }

        if (cliff_info.cliff_size_variance > 0 && cliff_info.number_of_cliffs > 0) {
            cliff_info.number_of_cliffs_variance = cliff_info.number_of_cliffs;
            (void)new (std::nothrow) RGE_RMM_Cliffs_Generator(this->map, this, cliff_info);
        }
    }

    return 1;
}

uchar TRIBE_RMM_Database_Controller::de_init() {
    (void)RGE_RMM_Database_Controller::de_init();
    return 1;
}
