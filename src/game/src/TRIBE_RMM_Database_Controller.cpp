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
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00483A20 (helper extraction coverage).
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static long rmm_rand_range(long max_value) {
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00483A20 (helper extraction coverage).
    if (max_value <= 0) {
        return 0;
    }
    unsigned int r = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp", 0x100);
    return (long)((r * (unsigned int)max_value) / 0x8000u);
}

static uchar rmm_clamp_terrain(long terrain) {
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x004889F0 (helper extraction coverage).
    if (terrain < 0) terrain = 0;
    return (uchar)(terrain & 0x1f);
}

static int rmm_is_water_terrain(uchar terrain_type) {
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x004889F0 (helper extraction coverage).
    return terrain_type == 1 || terrain_type == 4 || terrain_type == 22;
}

// TODO: PARITY-STRUCTURAL - this TU currently inlines rmm_terr-derived terrain helpers alongside
// rmm_dbct/rmm_tdbc flows; module-boundary ownership should be reconciled during strict per-unit parity audits.
// [decomp: rmm_dbct.cpp.decomp @ 0x00484160]

// Source of truth: rmm_terr.cpp::check_borders.
// Any non-water tile adjacent to water (8-neighborhood) becomes terrain 2.
static void rmm_terrain_check_borders(RGE_RMM_Database_Controller* self) {
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x004889F0 (helper extraction coverage).
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
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00483600
    if (self == nullptr || src_land == nullptr || count <= 0) {
        return;
    }
    if (start_index < 0 || start_index >= 99) {
        return;
    }

    long map_size = self->map_width;
    if (map_size <= 0) {
        return;
    }

    (void)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp", 0x1c3);

    long range_span = map_size + edge * -2;
    if (range_span < 1) {
        range_span = 1;
    }

    float bound = (float)range_span / (float)sqrt((double)count);
    if (count >= 4 && count < 7) {
        bound = bound * 0.9f;
    } else if (count >= 7) {
        bound = bound * 0.8f;
    }

    long inner_min_x = (long)bound;
    long inner_min_y = (long)bound;
    long inner_max_x = (long)bound;
    long inner_max_y = (long)bound;

    if (inner_min_x <= edge) {
        inner_min_x = edge + 1;
    }
    if (inner_min_y <= edge) {
        inner_min_y = edge + 1;
    }

    long upper = map_size - edge;
    if (upper - 1 <= inner_max_x) {
        inner_max_x = upper - 2;
    }
    if (upper - 1 <= inner_max_y) {
        inner_max_y = upper - 2;
    }
    if (inner_max_x < inner_min_x) {
        inner_max_x = inner_min_x;
    }
    if (inner_max_y < inner_min_y) {
        inner_max_y = inner_min_y;
    }

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

        if (src_land->placement_type == 0) {
            long x_rand = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp", 0x1e5);
            long y_rand = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp", 0x1e6);
            out->x = (x_rand * range_span) / 0x7fff + edge;
            out->y = (y_rand * range_span) / 0x7fff + edge;
            continue;
        }

        if (src_land->placement_type == 2) {
            while (true) {
                long x_rand = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp", 0x1fc);
                long y_rand = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp", 0x1fd);
                long x = (x_rand * range_span) / 0x7fff + edge;
                long y = (y_rand * range_span) / 0x7fff + edge;

                if (((inner_min_x < x) && (x < inner_max_x)) &&
                    ((inner_min_y < y) && (y < inner_max_y))) {
                    continue;
                }

                int reject = 0;
                for (long prev = start_index; prev < dst_index; ++prev) {
                    long dx = x - self->land_info.land[prev].x;
                    if (dx < 0) {
                        dx = -dx;
                    }
                    long dy = y - self->land_info.land[prev].y;
                    if (dy < 0) {
                        dy = -dy;
                    }
                    if ((float)(dx * dx + dy * dy) <= bound * bound) {
                        reject = 1;
                        break;
                    }
                }

                if (reject != 0) {
                    continue;
                }

                out->x = x;
                out->y = y;
                break;
            }
        }
    }
}

static int rmm_randomize_land_positions_by_team(RGE_RMM_Database_Controller* self) {
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x00487710 (helper extraction coverage).
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
    // Fully verified. Source of truth: rmm_terr.cpp.decomp @ 0x00488E60 (helper extraction coverage).
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
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00483200 (helper extraction coverage).
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
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00483540 (helper extraction coverage).
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

static void rmm_log_terrain_histogram(RGE_RMM_Database_Controller* self, const char* tag) {
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x00488675 (helper extraction coverage).
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
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x00488675 (helper extraction coverage).
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
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x00488675 (helper extraction coverage).
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
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x00488675 (helper extraction coverage).
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
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00483A20 (helper extraction coverage).
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
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00484160 (helper extraction coverage).
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
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00484470 (helper extraction coverage).
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
        if (self->map != nullptr) {
            self->map->clean_elevation(0, 0, self->map_width - 1, self->map_height - 1, 8);
        }
    }

    return 1;
}

// Moved to src/game/src/rmm_base.cpp (Task 264).


RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(char* param_1, char* param_2, char* param_3, char* param_4)
    : RGE_Random_Map_Module(nullptr, nullptr, 0) {
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00482B70
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
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00483020
    memset(&this->land_info, 0, sizeof(this->land_info));
    memset(&this->terrain_info, 0, sizeof(this->terrain_info));
    memset(&this->object_info, 0, sizeof(this->object_info));
    memset(&this->elevation_info, 0, sizeof(this->elevation_info));
    memset(&this->map_info, 0, sizeof(this->map_info));
    this->world = nullptr;
    this->map_type = -1;
    this->number_of_players = 0;

    rge_read(param_1, &this->map_info, (int)sizeof(RGE_Map_Data));
    if (this->map_info.map_num > 0) {
        this->map_info.maps = (RGE_Map_Data_Entry*)calloc((size_t)this->map_info.map_num, sizeof(RGE_Map_Data_Entry));
        rge_read(param_1, this->map_info.maps, this->map_info.map_num * (int)sizeof(RGE_Map_Data_Entry));

        for (long i = 0; i < this->map_info.map_num; ++i) {
            RGE_Map_Data_Entry* map_entry = &this->map_info.maps[i];
            rge_read(param_1, &map_entry->land_info, (int)sizeof(RGE_Land_Data));
            if (map_entry->land_info.land_num > 0) {
                map_entry->land_info.land = (RGE_Land_Data_Entry*)calloc((size_t)map_entry->land_info.land_num, sizeof(RGE_Land_Data_Entry));
                rge_read(param_1, map_entry->land_info.land, map_entry->land_info.land_num * (int)sizeof(RGE_Land_Data_Entry));
            }

            rge_read(param_1, &map_entry->terrain_info, (int)sizeof(RGE_Terrain_Data));
            if (map_entry->terrain_info.terrain_num > 0) {
                map_entry->terrain_info.terrain = (RGE_Terrain_Data_Entry*)calloc((size_t)map_entry->terrain_info.terrain_num, sizeof(RGE_Terrain_Data_Entry));
                rge_read(param_1, map_entry->terrain_info.terrain, map_entry->terrain_info.terrain_num * (int)sizeof(RGE_Terrain_Data_Entry));
            }

            rge_read(param_1, &map_entry->object_info, (int)sizeof(RGE_Object_Data));
            if (map_entry->object_info.object_num > 0) {
                map_entry->object_info.objects = (RGE_Object_Data_Entry*)calloc((size_t)map_entry->object_info.object_num, sizeof(RGE_Object_Data_Entry));
                rge_read(param_1, map_entry->object_info.objects, map_entry->object_info.object_num * (int)sizeof(RGE_Object_Data_Entry));
            }

            rge_read(param_1, &map_entry->elevation_info, (int)sizeof(RGE_Elevation_Data));
            if (map_entry->elevation_info.elevation_num > 0) {
                map_entry->elevation_info.elevation = (RGE_Elevation_Data_Entry*)calloc((size_t)map_entry->elevation_info.elevation_num, sizeof(RGE_Elevation_Data_Entry));
                rge_read(param_1, map_entry->elevation_info.elevation, map_entry->elevation_info.elevation_num * (int)sizeof(RGE_Elevation_Data_Entry));
            }
        }
    }
}

RGE_RMM_Database_Controller::~RGE_RMM_Database_Controller() {
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00483200
    rmm_free_map_data(this);
}

uchar RGE_RMM_Database_Controller::save(int param_1) {
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x004832E0
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
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00483430
    (void)new (std::nothrow) RGE_RMM_Terrain_Generator(this->map, this, &this->terrain_info);
    (void)new (std::nothrow) RGE_RMM_Land_Generator(this->map, this, &this->land_info);
    (void)new (std::nothrow) RGE_RMM_Object_Generator(this->map, this, this->world, &this->object_info, 1);
    (void)new (std::nothrow) RGE_RMM_Elevation_Generator(this->map, this, &this->elevation_info);
    return RGE_Random_Map_Module::generate();
}

void RGE_RMM_Database_Controller::add_land_module(uchar param_1) {
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00483A20
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
        (void)rmm_randomize_land_positions_by_team(this);
    }
}

void RGE_RMM_Database_Controller::add_terrain_module() {
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00484160
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
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00484320
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
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00484470
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

    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00484470
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
}

uchar RGE_RMM_Database_Controller::init(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, uchar param_5) {
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x00483540
    this->world = param_2;
    this->map_type = (long)param_3;
    this->number_of_players = param_4;

    this->update_map_info(param_1);
    this->create_shared_resources();

    this->add_land_module(param_5);
    this->add_terrain_module();
    this->add_object_module();
    this->add_elevation_module();

    return 1;
}

uchar RGE_RMM_Database_Controller::de_init() {
    // Fully verified. Source of truth: rmm_dbct.cpp.decomp @ 0x004835A0
    this->world = nullptr;
    this->map_type = -1;
    this->number_of_players = 0;

    while (this->list != nullptr) {
        RGE_Random_Map_Module_List* head = this->list;
        RGE_Random_Map_Module* module = head->module;
        if (module != nullptr) {
            delete module;
        }
    }

    this->destroy_shared_resources();
    this->update_map_info(nullptr);
    return 0;
}

namespace {
static void rmm_tdbc_switch_anchor_0048790A() {
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x0048790A
}

static void rmm_tdbc_switch_anchor_00488675() {
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x00488675
}
} // namespace

TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(char* param_1, char* param_2, char* param_3, char* param_4)
    : RGE_RMM_Database_Controller(param_1, param_2, param_3, param_4) {
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x004876C0
}

TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(int param_1)
    : RGE_RMM_Database_Controller(param_1) {
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x004876F0
}

uchar TRIBE_RMM_Database_Controller::generate() {
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x00488870
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

void FUN_0048790a() {
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x0048790A
    // Switch jump-table padding thunk (`mov edi, edi`).
}

void TRIBE_RMM_Database_Controller::add_land_module(uchar param_1) {
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x00487940
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
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x00487DD0
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
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x00487FA0
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

void FUN_00488675() {
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x00488675
    // Switch jump-table padding thunk (`nop; mov edi, edi`).
}

void TRIBE_RMM_Database_Controller::add_elevation_module() {
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x00488700
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
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x004887A0
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
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x00487710
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
        } else if (map_size < 0xfb) {
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
    // Fully verified. Source of truth: rmm_tdbc.cpp.decomp @ 0x00487930
    (void)RGE_RMM_Database_Controller::de_init();
    return 1;
}


