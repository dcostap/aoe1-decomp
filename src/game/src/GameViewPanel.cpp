// Temporary game-view panel: renders isometric map with real terrain SLP sprites.
// This is scaffolding — will be replaced by the real TRIBE_Screen_Game once reimplemented.

#include "../include/GameViewPanel.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Tile.h"
#include "../include/RGE_Tile_Set.h"
#include "../include/RGE_Border_Set.h"
#include "../include/RGE_TOB_Picts.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Sprite.h"
#include "../include/TShape.h"
#include "../include/TDrawArea.h"
#include "../include/custom_debug.h"

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/TMousePointer.h"

extern TMousePointer* MouseSystem;

// AoE1 standard tile dimensions
static const int TILE_HALF_W = 32; // half-width of isometric diamond
static const int TILE_HALF_H = 16; // half-height of isometric diamond
static const int FORCE_FALLBACK_TILES = 0;

// RGE_Map::set_map_screen_pos() stores coordinates as:
//   x = (row + col) * tile_half_width
//   y = (row - col) * tile_half_height - elevation
// Y can be negative, so we add a fixed map-space shift for viewport rendering.
static long gameview_origin_y(const RGE_Map* map) {
    if (!map || map->map_row_offset == nullptr || map->map_width <= 0 || map->map_height <= 0) {
        return 0;
    }

    long min_y = 0;
    int have_min = 0;
    for (long y = 0; y < map->map_height; ++y) {
        for (long x = 0; x < map->map_width; ++x) {
            RGE_Tile* tile = &map->map_row_offset[y][x];
            long draw_y = (long)tile->screen_ypos;
            if (!have_min || draw_y < min_y) {
                min_y = draw_y;
                have_min = 1;
            }
        }
    }

    long half_h = map->tile_half_height > 0 ? map->tile_half_height : TILE_HALF_H;
    if (min_y < 0) {
        return -min_y + half_h;
    }
    return half_h;
}

static void draw_fallback_iso_tile(TDrawArea* area, long sx, long sy, uchar terrain_idx) {
    if (!area) {
        return;
    }

    // Non-original fallback: draw a simple filled diamond when terrain SLP data is unavailable.
    uchar fill = (uchar)(170 + (terrain_idx % 12));
    if (fill == 0) fill = 170;
    uchar edge = (uchar)(fill > 8 ? fill - 8 : fill);

    // Upper half (16 rows): width grows by 4 pixels per row.
    for (int i = 0; i < TILE_HALF_H; ++i) {
        int y = (int)(sy + i);
        int x = (int)(sx - i * 2);
        int len = i * 4 + 1;
        area->DrawHorzLine(x, y, len, fill);
    }

    // Lower half (16 rows): width shrinks by 4 pixels per row.
    for (int i = 0; i < TILE_HALF_H; ++i) {
        int y = (int)(sy + TILE_HALF_H + i);
        int x = (int)(sx - (TILE_HALF_H - 1 - i) * 2);
        int len = (TILE_HALF_H - 1 - i) * 4 + 1;
        area->DrawHorzLine(x, y, len, fill);
    }

    // Outline to improve readability on flat backgrounds.
    area->DrawLine((int)sx, (int)sy, (int)(sx + TILE_HALF_W - 1), (int)(sy + TILE_HALF_H), edge);
    area->DrawLine((int)sx, (int)sy, (int)(sx - TILE_HALF_W + 1), (int)(sy + TILE_HALF_H), edge);
    area->DrawLine((int)(sx - TILE_HALF_W + 1), (int)(sy + TILE_HALF_H), (int)sx, (int)(sy + TILE_HALF_H * 2 - 1), edge);
    area->DrawLine((int)(sx + TILE_HALF_W - 1), (int)(sy + TILE_HALF_H), (int)sx, (int)(sy + TILE_HALF_H * 2 - 1), edge);
}

GameViewPanel::GameViewPanel(RGE_Map* map) : TScreenPanel((char*)"Game Screen") {
    this->world_map = map;
    this->cam_x = 0;
    this->cam_y = 0;
    this->scroll_speed = 16;  // pixels per tick
    this->scroll_left = 0;
    this->scroll_right = 0;
    this->scroll_up = 0;
    this->scroll_down = 0;

CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("GameViewPanel: created, map=%p w=%d h=%d",
        map, map ? map->map_width : 0, map ? map->map_height : 0);
CUSTOM_DEBUG_END
}

GameViewPanel::~GameViewPanel() {
    // world_map not owned by us
}

// get_tile_picture — transliterated from view.cpp.decomp @ 0x00539AA0
// Returns the SLP frame index for a given terrain type and tile type at (col, row).
// Returns -1 if no shape is available.
static short get_tile_picture(RGE_Map* map, unsigned char terrain_type, unsigned char tile_type,
                              short col, short row) {
    RGE_Tile_Set* ts = &map->terrain_types[terrain_type];
    if (!ts->shape) {
        return -1;
    }

    unsigned int tt = (unsigned int)tile_type;
    if (tt >= 19) tt = 0; // clamp to valid tile size index

    short count = ts->tiles[tt].count;
    if (count == 0) {
        return -1;
    }

    short sub_tile = 0;
    if (count > 1) {
        unsigned char rows = (unsigned char)ts->rows;
        unsigned char cols = (unsigned char)ts->cols;
        if (rows > 1 || cols > 1) {
            unsigned char row_mod = (rows == 0) ? 0 : (unsigned char)(row % (int)rows);
            unsigned char col_mod = (cols == 0) ? 0 : (unsigned char)(col % (int)cols);
            sub_tile = (short)((unsigned short)row_mod * (unsigned short)cols + (unsigned short)col_mod);
        }
    }

    if (sub_tile > count - 1) {
        sub_tile = 0;
    }

    return ts->tiles[tt].shape_index + ts->tiles[tt].animations * sub_tile;
}

// get_border_picture — transliterated from view.cpp.decomp @ 0x00539B90 / view.cpp.asm.
// Returns the SLP frame index for a given border type/tile context, or -1 if unavailable.
static short get_border_picture(RGE_Map* map, unsigned char border_type, unsigned char tile_type,
                                unsigned char border_shape, short col, short row) {
    if (!map || border_type >= 16) {
        return -1;
    }

    RGE_Border_Set* bs = &map->border_types[border_type];
    if (!bs->shape) {
        return -1;
    }

    // Source of truth: view.cpp.decomp @ 0x00539B90.
    // borders[tile_type - 1][border_shape + 0x0B] => flattened:
    // (tile_type * 12) + border_shape - 1
    const int kMaxBorderPicts = 19 * 12;
    int flat_index = (int)tile_type * 12 + (int)border_shape - 1;
    if (flat_index < 0 || flat_index >= kMaxBorderPicts) {
        return -1;
    }

    RGE_TOB_Picts* pict = &bs->borders[0][0] + flat_index;
    short count = pict->count;
    if (count == 0) {
        return -1;
    }

    short sub_index = 0;
    if (count > 1) {
        short border_style = bs->border_style;
        if (((border_style == 0) && (border_shape == 0x0B || border_shape == 0x0C)) ||
            ((border_style == 1) && (border_shape == 0x03 || border_shape == 0x02))) {
            sub_index = (short)(row % count);
        } else if (((border_style == 0) && (border_shape == 0x09 || border_shape == 0x0A)) ||
                   ((border_style == 1) && (border_shape == 0x01 || border_shape == 0x04))) {
            sub_index = (short)(col % count);
        } else {
            sub_index = 0;
        }
    }

    if (sub_index > count - 1) {
        sub_index = 0;
    }

    return (short)(pict->animations * sub_index + pict->shape_index);
}

static int get_border_edge_pictures(
    RGE_Map* map,
    unsigned char border_type,
    unsigned char tile_type,
    unsigned char border_shape_bits,
    short col,
    short row,
    int* left_index,
    int* bottom_index,
    int* right_index,
    int* center_index) {
    if (left_index) *left_index = -1;
    if (bottom_index) *bottom_index = -1;
    if (right_index) *right_index = -1;
    if (center_index) *center_index = -1;

    if (!map || border_type >= 16) {
        return 0;
    }
    if (map->border_types[border_type].shape == nullptr) {
        return 0;
    }
    if (border_shape_bits == 0) {
        return 0;
    }

    if ((border_shape_bits & 0x01) != 0) {
        short s = get_border_picture(map, border_type, tile_type, 0x01, col, row);
        if (left_index) *left_index = (int)s;
    }
    if ((border_shape_bits & 0x02) != 0) {
        short s = get_border_picture(map, border_type, tile_type, 0x04, col, row);
        if (center_index) *center_index = (int)s;
    }
    if ((border_shape_bits & 0x04) != 0) {
        short s = get_border_picture(map, border_type, tile_type, 0x03, col, row);
        if (right_index) *right_index = (int)s;
    }
    if ((border_shape_bits & 0x08) != 0) {
        short s = get_border_picture(map, border_type, tile_type, 0x02, col, row);
        if (bottom_index) *bottom_index = (int)s;
    }
    return 1;
}

static void gameview_try_load_sprite_shape(RGE_Sprite* spr) {
    if (spr == nullptr || spr->shape != nullptr) {
        return;
    }
    if (spr->pict_name[0] == '\0') {
        return;
    }

    char shp_name[64];
    _snprintf(shp_name, sizeof(shp_name), "%s.shp", spr->pict_name);
    shp_name[sizeof(shp_name) - 1] = '\0';

    TShape* loaded_shape = new TShape(shp_name, spr->resource_id);
    if (loaded_shape != nullptr && loaded_shape->is_loaded() != 0) {
        spr->shape = loaded_shape;
        spr->loaded = 1;
    } else if (loaded_shape != nullptr) {
        delete loaded_shape;
    }
}

static int gameview_ascii_contains_ci(const char* text, const char* token) {
    if (text == nullptr || token == nullptr || token[0] == '\0') {
        return 0;
    }

    size_t text_len = strlen(text);
    size_t token_len = strlen(token);
    if (token_len == 0 || token_len > text_len) {
        return 0;
    }

    for (size_t i = 0; i + token_len <= text_len; ++i) {
        int match = 1;
        for (size_t j = 0; j < token_len; ++j) {
            char a = text[i + j];
            char b = token[j];
            if (a >= 'a' && a <= 'z') a = (char)(a - 'a' + 'A');
            if (b >= 'a' && b <= 'z') b = (char)(b - 'a' + 'A');
            if (a != b) {
                match = 0;
                break;
            }
        }
        if (match != 0) {
            return 1;
        }
    }

    return 0;
}

static int gameview_is_tree_object(RGE_Static_Object* obj) {
    if (obj == nullptr || obj->master_obj == nullptr) {
        return 0;
    }

    const char* name = obj->master_obj->name;
    if (name == nullptr || name[0] == '\0') {
        return 0;
    }

    if (gameview_ascii_contains_ci(name, "TREE") != 0) {
        return 1;
    }
    if (gameview_ascii_contains_ci(name, "FOREST") != 0) {
        return 1;
    }
    return 0;
}

static int gameview_draw_object_sprite(TDrawArea* area, RGE_Static_Object* obj, long sx, long sy) {
    if (area == nullptr || obj == nullptr || obj->master_obj == nullptr) {
        return 0;
    }

    RGE_Sprite* spr = obj->sprite;
    if (spr == nullptr) {
        spr = obj->master_obj->sprite;
    }
    if (spr == nullptr) {
        return 0;
    }
    gameview_try_load_sprite_shape(spr);

    // Source of truth: sprite.cpp.decomp @ 0x004C0510 (RGE_Sprite::draw).
    // Important parity point:
    // calling shape_draw() directly bypasses sprite color_flag/color_table handling
    // (including SLP shadow op decode behavior), which can produce white/garbled shadows.
    int facet = (int)obj->facet;
    if (facet < 0) {
        facet = 0;
    }
    if (spr->facet_num > 0 && facet >= spr->facet_num) {
        facet = 0;
    }

    return spr->draw((long)facet, 0, sx, sy, sx, sy, nullptr, area, 0) != 0;
}

static int gameview_object_bounds(RGE_Static_Object* obj, long anchor_x, long anchor_y,
                                  long* out_l, long* out_t, long* out_r, long* out_b) {
    if (obj == nullptr || out_l == nullptr || out_t == nullptr || out_r == nullptr || out_b == nullptr) {
        return 0;
    }

    RGE_Sprite* spr = obj->sprite;
    if (spr == nullptr && obj->master_obj != nullptr) {
        spr = obj->master_obj->sprite;
    }
    if (spr == nullptr) {
        return 0;
    }

    int facet = (int)obj->facet;
    if (facet < 0) {
        facet = 0;
    }
    if (spr->facet_num > 0 && facet >= spr->facet_num) {
        facet = 0;
    }

    int have = 0;
    long l = 0;
    long t = 0;
    long r = 0;
    long b = 0;

    if (spr->draw_list_num > 0 && spr->draw_list != nullptr) {
        for (int di = 0; di < spr->draw_list_num; ++di) {
            RGE_Picture_List* dl = &spr->draw_list[di];
            if (dl == nullptr) {
                continue;
            }

            int list_facet = (int)dl->facet;
            if (list_facet >= 0 && list_facet != facet) {
                continue;
            }

            RGE_Sprite* ds = dl->sprite;
            if (ds == nullptr && dl->picture_num == -1) {
                ds = spr;
            }
            if (ds == nullptr) {
                continue;
            }

            long dl_l = (long)dl->offset_x + (long)ds->box_x1;
            long dl_t = (long)dl->offset_y + (long)ds->box_y1;
            long dl_r = (long)dl->offset_x + (long)ds->box_x2;
            long dl_b = (long)dl->offset_y + (long)ds->box_y2;

            if (!have) {
                l = dl_l;
                t = dl_t;
                r = dl_r;
                b = dl_b;
                have = 1;
            } else {
                if (dl_l < l) l = dl_l;
                if (dl_t < t) t = dl_t;
                if (dl_r > r) r = dl_r;
                if (dl_b > b) b = dl_b;
            }
        }
    }

    if (!have) {
        l = (long)spr->box_x1;
        t = (long)spr->box_y1;
        r = (long)spr->box_x2;
        b = (long)spr->box_y2;
        have = 1;
    }

    *out_l = anchor_x + l;
    *out_t = anchor_y + t;
    *out_r = anchor_x + r;
    *out_b = anchor_y + b;
    return have;
}

struct GameViewObjDrawEntry {
    RGE_Static_Object* obj;
    long sx;
    long sy;
    long sort_y;
    long sort_x;
};

static int gameview_obj_draw_cmp(const void* a, const void* b) {
    const GameViewObjDrawEntry* ea = (const GameViewObjDrawEntry*)a;
    const GameViewObjDrawEntry* eb = (const GameViewObjDrawEntry*)b;
    if (ea->sort_y < eb->sort_y) return -1;
    if (ea->sort_y > eb->sort_y) return 1;
    if (ea->sort_x < eb->sort_x) return -1;
    if (ea->sort_x > eb->sort_x) return 1;
    if (ea->obj < eb->obj) return -1;
    if (ea->obj > eb->obj) return 1;
    return 0;
}

struct GameViewTreeEntry {
    RGE_Static_Object* obj;
    RGE_Sprite* sprite;
};

static void gameview_draw_tree_debug_grid(GameViewPanel* self) {
    if (self == nullptr || self->render_area == nullptr || self->world_map == nullptr) {
        return;
    }

    TDrawArea* area = self->render_area;
    RGE_Game_World* world = self->world_map->game_world;
    if (world == nullptr || world->objectsValue == nullptr || world->numberObjectsValue <= 0) {
        tagRECT clearRect;
        clearRect.left = self->pnl_x;
        clearRect.top = self->pnl_y;
        clearRect.right = self->pnl_x + self->pnl_wid - 1;
        clearRect.bottom = self->pnl_y + self->pnl_hgt - 1;
        area->Clear(&clearRect, 0);
        return;
    }

    GameViewTreeEntry entries[96];
    short seen_sprite_ids[192];
    int entry_count = 0;
    int seen_count = 0;

    int max_obj = world->numberObjectsValue;
    if (world->maxNumberObjectsValue > 0 && max_obj > world->maxNumberObjectsValue) {
        max_obj = world->maxNumberObjectsValue;
    }

    for (int i = 0; i < max_obj; ++i) {
        RGE_Static_Object* obj = world->objectsValue[i];
        if (obj == nullptr || obj->master_obj == nullptr || obj->object_state >= 7) {
            continue;
        }
        if (gameview_is_tree_object(obj) == 0) {
            continue;
        }

        RGE_Sprite* spr = obj->sprite;
        if (spr == nullptr) {
            spr = obj->master_obj->sprite;
        }
        if (spr == nullptr) {
            continue;
        }

        int already_seen = 0;
        for (int s = 0; s < seen_count; ++s) {
            if (seen_sprite_ids[s] == spr->id) {
                already_seen = 1;
                break;
            }
        }
        if (already_seen != 0) {
            continue;
        }

        if (entry_count < (int)(sizeof(entries) / sizeof(entries[0])) &&
            seen_count < (int)(sizeof(seen_sprite_ids) / sizeof(seen_sprite_ids[0]))) {
            entries[entry_count].obj = obj;
            entries[entry_count].sprite = spr;
            seen_sprite_ids[seen_count] = spr->id;
            entry_count++;
            seen_count++;
        }
    }

    tagRECT clearRect;
    clearRect.left = self->pnl_x;
    clearRect.top = self->pnl_y;
    clearRect.right = self->pnl_x + self->pnl_wid - 1;
    clearRect.bottom = self->pnl_y + self->pnl_hgt - 1;
    area->Clear(&clearRect, 0);

    if (entry_count == 0) {
        CUSTOM_DEBUG_LOG("DEBUGTREEGRID: no tree sprites found in current world object list");
        return;
    }

    static int tree_grid_log_once = 0;
    if (tree_grid_log_once == 0) {
        tree_grid_log_once = 1;
        CUSTOM_DEBUG_LOG_FMT("DEBUGTREEGRID: drawing %d unique tree sprites", entry_count);
        for (int i = 0; i < entry_count; ++i) {
            RGE_Static_Object* obj = entries[i].obj;
            RGE_Sprite* spr = entries[i].sprite;
            CUSTOM_DEBUG_LOG_FMT(
                "DEBUGTREEGRID[%d]: obj=%ld master=%d name=%s sprite=%d color_flag=%u color_table=%d draw_list=%d draw_level=%u facet=%u",
                i,
                obj ? obj->id : -1L,
                (obj && obj->master_obj) ? (int)obj->master_obj->id : -1,
                (obj && obj->master_obj && obj->master_obj->name) ? obj->master_obj->name : "(null)",
                spr ? (int)spr->id : -1,
                spr ? (unsigned int)spr->color_flag : 0U,
                spr ? (int)spr->color_table : -1,
                spr ? (int)spr->draw_list_num : 0,
                spr ? (unsigned int)spr->draw_level : 0U,
                obj ? (unsigned int)obj->facet : 0U);
        }
    }

    const int cell_w = 200;
    const int cell_h = 110;
    int cols = self->pnl_wid / cell_w;
    if (cols < 1) cols = 1;

    for (int i = 0; i < entry_count; ++i) {
        int col = i % cols;
        int row = i / cols;

        long x0 = self->pnl_x + col * cell_w;
        long y0 = self->pnl_y + row * cell_h;
        long x1 = x0 + cell_w - 2;
        long y1 = y0 + cell_h - 2;

        if (y0 > self->pnl_y + self->pnl_hgt - 1) {
            break;
        }
        if (y1 > self->pnl_y + self->pnl_hgt - 1) {
            y1 = self->pnl_y + self->pnl_hgt - 1;
        }

        area->FillRect(x0, y0, x1, y1, 8);

        long split_x = x0 + cell_w / 2;
        area->FillRect(x0 + 1, y0 + 1, split_x - 2, y1 - 1, 35);
        area->FillRect(split_x + 1, y0 + 1, x1 - 1, y1 - 1, 60);
        area->DrawVertLine(split_x, y0 + 2, cell_h - 6, 220);

        long anchor_y = y0 + cell_h - 20;
        long left_anchor_x = x0 + 44;
        long right_anchor_x = split_x + 44;

        RGE_Static_Object* obj = entries[i].obj;
        RGE_Sprite* spr = entries[i].sprite;

        int left_ok = gameview_draw_object_sprite(area, obj, left_anchor_x, anchor_y);
        int right_ok = 0;
        if (obj != nullptr && spr != nullptr) {
            int facet = (int)obj->facet;
            if (facet < 0) facet = 0;
            right_ok = spr->draw((long)facet, 0, right_anchor_x, anchor_y, right_anchor_x, anchor_y, nullptr, area, 0) != 0;
        }

        if (left_ok == 0) {
            area->DrawLine((int)left_anchor_x - 8, (int)anchor_y - 8, (int)left_anchor_x + 8, (int)anchor_y + 8, 250);
            area->DrawLine((int)left_anchor_x - 8, (int)anchor_y + 8, (int)left_anchor_x + 8, (int)anchor_y - 8, 250);
        }
        if (right_ok == 0) {
            area->DrawLine((int)right_anchor_x - 8, (int)anchor_y - 8, (int)right_anchor_x + 8, (int)anchor_y + 8, 250);
            area->DrawLine((int)right_anchor_x - 8, (int)anchor_y + 8, (int)right_anchor_x + 8, (int)anchor_y - 8, 250);
        }
    }
}

void GameViewPanel::draw() {
    if (!this->render_area || !this->world_map || !this->world_map->map) {
        CUSTOM_DEBUG_LOG("GameViewPanel::draw: SKIPPING - missing render_area/map/tiles");
        return;
    }

    long scr_w = this->pnl_wid;
    long scr_h = this->pnl_hgt;

    // Clear the screen to dark background (palette index 0 = usually black)
    tagRECT clearRect;
    clearRect.left = this->pnl_x;
    clearRect.top = this->pnl_y;
    clearRect.right = this->pnl_x + scr_w - 1;
    clearRect.bottom = this->pnl_y + scr_h - 1;
    this->render_area->Clear(&clearRect, 0);

    long map_w = this->world_map->map_width;
    long map_h = this->world_map->map_height;

    if (map_w <= 0 || map_h <= 0) {
        CUSTOM_DEBUG_LOG_FMT("GameViewPanel::draw: invalid map dims %ldx%ld", map_w, map_h);
        return;
    }

    // screen_xpos/screen_ypos are already in world-space from RGE_Map::set_map_screen_pos.
    // Only Y needs a positive shift because map-space Y spans negative..positive.
    long origin_x = 0;
    long origin_y = gameview_origin_y(this->world_map);
    long half_w = this->world_map->tile_half_width > 0 ? this->world_map->tile_half_width : TILE_HALF_W;
    long half_h = this->world_map->tile_half_height > 0 ? this->world_map->tile_half_height : TILE_HALF_H;

    tagRECT saved_clip = this->render_area->ClipRect;
    tagRECT draw_clip = this->clip_rect;
    this->render_area->SetClipRect(&draw_clip);

    int area_locked_here = 0;
    if (!this->render_area->Bits) {
        if (!this->render_area->Lock((char*)"GameViewPanel::draw", 0)) {
            CUSTOM_DEBUG_LOG("GameViewPanel::draw: render_area lock failed");
            this->render_area->SetClipRect(&saved_clip);
            return;
        }
        area_locked_here = 1;
    }

    int drawn_tiles = 0;
    int real_tiles = 0;
    int fallback_tiles = 0;
    int objects_drawn = 0;
    int objects_fallback = 0;
    int objects_culled = 0;
    int bad_terrain_idx = 0;
    int missing_shape = 0;
    int missing_frame = 0;
    int border_drawn = 0;
    int border_missing = 0;
    int checked_tiles = 0;
    int culled_x = 0;
    int culled_y = 0;
    long min_sx = 2147483647L;
    long max_sx = -2147483647L - 1;
    long min_sy = 2147483647L;
    long max_sy = -2147483647L - 1;

    RGE_Game_World* world = this->world_map ? this->world_map->game_world : nullptr;
    int max_obj = 0;
    if (world != nullptr && world->objectsValue != nullptr && world->numberObjectsValue > 0) {
        max_obj = world->numberObjectsValue;
        if (world->maxNumberObjectsValue > 0 && max_obj > world->maxNumberObjectsValue) {
            max_obj = world->maxNumberObjectsValue;
        }
    }

    GameViewObjDrawEntry* obj_draw_list = nullptr;
    int obj_draw_cap = max_obj;
    int obj_draw_count = 0;
    if (obj_draw_cap > 0) {
        obj_draw_list = new GameViewObjDrawEntry[obj_draw_cap];
    }

    // Draw in diagonal order with constant (row-col), top-to-bottom in screen space.
    long min_diff = -(map_w - 1);
    long max_diff = map_h - 1;
    for (long diff = min_diff; diff <= max_diff; ++diff) {
        long row0 = (diff > 0) ? diff : 0;
        long row1 = diff + (map_w - 1);
        if (row1 > map_h - 1) row1 = map_h - 1;

        for (long row = row0; row <= row1; ++row) {
            long col = row - diff;
            if (col < 0 || col >= map_w) continue;

            checked_tiles++;
            RGE_Tile* tile = &this->world_map->map_row_offset[row][col];

            unsigned char tile_type = tile->tile_type;

            // Source of truth: map.cpp::set_map_screen_pos already applies elevation and
            // tile_type-specific vertical adjustments for terrain draw.
            long wx = origin_x + (long)tile->screen_xpos;
            long wy = origin_y + (long)tile->screen_ypos;

            // Convert to screen position with camera offset
            long sx = wx - this->cam_x + this->pnl_x;
            long sy = wy - this->cam_y + this->pnl_y;
            if (sx < min_sx) min_sx = sx;
            if (sx > max_sx) max_sx = sx;
            if (sy < min_sy) min_sy = sy;
            if (sy > max_sy) max_sy = sy;

            long tile_draw_w = half_w * 2;
            long tile_draw_h = half_h * 2;
            if (tile_type < 19 && this->world_map->tilesizes[tile_type].height > 0) {
                tile_draw_h = this->world_map->tilesizes[tile_type].height;
            }
            if (tile_type < 19 && this->world_map->tilesizes[tile_type].width > 0) {
                tile_draw_w = this->world_map->tilesizes[tile_type].width;
            }

            // Early cull: match RGE_View terrain bounds checks (x..x+tile_w, y..y+tile_h).
            long ex = sx + tile_draw_w;
            long ey = sy + tile_draw_h;
            if (ex < this->pnl_x || sx > this->pnl_x + scr_w) {
                culled_x++;
                continue;
            }
            if (ey < this->pnl_y || sy > this->pnl_y + scr_h) {
                culled_y++;
                continue;
            }

            // Look up the terrain type and get the SLP shape
            unsigned char terrain_idx = (unsigned char)(tile->terrain_type & 0x1F); // 5-bit field (0-31)
            unsigned char draw_terrain_idx = terrain_idx;
            if (terrain_idx < 32) {
                short terrain_to_draw = this->world_map->terrain_types[terrain_idx].terrain_to_draw;
                if (terrain_to_draw >= 0 && terrain_to_draw < this->world_map->num_terrain) {
                    draw_terrain_idx = (unsigned char)terrain_to_draw;
                }
            }

            if (terrain_idx >= 32) {
                bad_terrain_idx++;
                if (checked_tiles % 1000 == 0) CUSTOM_DEBUG_LOG_FMT("Bad terrain idx %d at %ld,%ld", terrain_idx, col, row);
                continue;
            }

            // Mirror RGE_View::draw_tile transition logic:
            // decide border + draw_terrain first (border_style 0 can suppress base terrain draw).
            int draw_border = 0;
            int draw_terrain = 1;
            int left_index = -1;
            int bottom_index = -1;
            int right_index = -1;
            int center_index = -1;

            unsigned char border_idx = (unsigned char)(tile->border_type & 0x0F);
            unsigned char border_shape_bits = (unsigned char)(tile->border_shape & 0x0F);
            if (border_idx != 0 && border_idx < 16) {
                RGE_Border_Set* bs = &this->world_map->border_types[border_idx];
                if (bs->loaded && bs->shape != nullptr) {
                    if (bs->border_style == 0) {
                        short border_frame = get_border_picture(
                            this->world_map,
                            border_idx,
                            tile_type,
                            border_shape_bits,
                            (short)col,
                            (short)row);
                        if (border_frame >= 0) {
                            draw_border = 1;
                            center_index = (int)border_frame;
                            draw_terrain = (int)bs->draw_tile;
                        }
                    } else {
                        if (get_border_edge_pictures(
                                this->world_map,
                                border_idx,
                                tile_type,
                                border_shape_bits,
                                (short)col,
                                (short)row,
                                &left_index,
                                &bottom_index,
                                &right_index,
                                &center_index)) {
                            draw_border = 1;
                            draw_terrain = 1;
                        }
                    }
                }
            }

            if (FORCE_FALLBACK_TILES) {
                draw_fallback_iso_tile(this->render_area, sx, sy, terrain_idx);
                drawn_tiles++;
                fallback_tiles++;
                continue;
            }

            if (draw_terrain != 0) {
                RGE_Tile_Set* ts = &this->world_map->terrain_types[draw_terrain_idx];
                if (!ts->loaded || ts->shape == nullptr) {
                    missing_shape++;
                    draw_fallback_iso_tile(this->render_area, sx, sy, terrain_idx);
                    drawn_tiles++;
                    fallback_tiles++;
                    continue;
                }

                // Get the SLP frame index for this terrain at this tile position.
                short frame = get_tile_picture(
                    this->world_map,
                    draw_terrain_idx,
                    tile_type,
                    (short)col,
                    (short)row);
                if (frame < 0 || frame >= ts->shape->shape_count()) {
                    missing_frame++;
                    draw_fallback_iso_tile(this->render_area, sx, sy, terrain_idx);
                    drawn_tiles++;
                    fallback_tiles++;
                    continue;
                }

                ts->shape->shape_draw(this->render_area, sx, sy, (long)frame, 0, 0, nullptr);
            }

            if (draw_border != 0 && border_idx != 0 && border_idx < 16) {
                RGE_Border_Set* bs = &this->world_map->border_types[border_idx];
                if (bs->loaded && bs->shape != nullptr) {
                    if (bs->border_style == 0) {
                        if (center_index >= 0 && center_index < bs->shape->shape_count()) {
                            bs->shape->shape_draw(this->render_area, sx, sy, (long)center_index, 0, 0, nullptr);
                            border_drawn++;
                        } else {
                            border_missing++;
                        }
                    } else {
                        if (left_index >= 0 && left_index < bs->shape->shape_count()) {
                            bs->shape->shape_draw(this->render_area, sx, sy, (long)left_index, 0, 0, nullptr);
                            border_drawn++;
                        }
                        if (right_index >= 0 && right_index < bs->shape->shape_count()) {
                            bs->shape->shape_draw(this->render_area, sx, sy, (long)right_index, 0, 0, nullptr);
                            border_drawn++;
                        }
                        if (bottom_index >= 0 && bottom_index < bs->shape->shape_count()) {
                            bs->shape->shape_draw(this->render_area, sx, sy, (long)bottom_index, 0, 0, nullptr);
                            border_drawn++;
                        }
                        if (center_index >= 0 && center_index < bs->shape->shape_count()) {
                            bs->shape->shape_draw(this->render_area, sx, sy, (long)center_index, 0, 0, nullptr);
                            border_drawn++;
                        }
                    }
                }
            }

            drawn_tiles++;
            real_tiles++;

        }
    }

    // Global object gather pass (independent from terrain tile culling).
    // This avoids edge despawn when an object's anchor tile is culled but sprite still overlaps view.
    if (world != nullptr && world->objectsValue != nullptr && obj_draw_list != nullptr) {
        for (int i = 0; i < max_obj; ++i) {
            RGE_Static_Object* obj = world->objectsValue[i];
            if (obj == nullptr || obj->master_obj == nullptr || obj->object_state >= 7) {
                continue;
            }

            RGE_Tile* ot = obj->tile;
            if (ot == nullptr) {
                long ox = (long)obj->world_x;
                long oy = (long)obj->world_y;
                if (ox < 0 || oy < 0 || ox >= map_w || oy >= map_h) {
                    continue;
                }
                ot = &this->world_map->map_row_offset[oy][ox];
            }
            if (ot == nullptr) {
                continue;
            }

            long wx = origin_x + (long)ot->screen_xpos;
            // Match RGE_View object anchor behavior: cancel terrain elevation offset for object sprite anchor.
            long wy = origin_y + (long)ot->screen_ypos + (long)ot->height * half_h;

            long osx = wx - this->cam_x + this->pnl_x + (long)obj->screen_x_offset;
            long osy = wy - this->cam_y + this->pnl_y + (long)obj->screen_y_offset;

            long obj_l = 0;
            long obj_t = 0;
            long obj_r = 0;
            long obj_b = 0;
            long sort_y = osy;
            if (gameview_object_bounds(obj, osx, osy, &obj_l, &obj_t, &obj_r, &obj_b) != 0) {
                sort_y = obj_b;
            }

            if (obj_draw_count < obj_draw_cap) {
                obj_draw_list[obj_draw_count].obj = obj;
                obj_draw_list[obj_draw_count].sx = osx;
                obj_draw_list[obj_draw_count].sy = osy;
                obj_draw_list[obj_draw_count].sort_y = sort_y;
                obj_draw_list[obj_draw_count].sort_x = osx;
                obj_draw_count++;
            }
        }
    }

    if (obj_draw_list != nullptr && obj_draw_count > 1) {
        qsort(obj_draw_list, (size_t)obj_draw_count, sizeof(GameViewObjDrawEntry), gameview_obj_draw_cmp);
    }

    long tile_w = this->world_map->tile_width > 0 ? this->world_map->tile_width : TILE_HALF_W * 2;
    long tile_h = this->world_map->tile_height > 0 ? this->world_map->tile_height : TILE_HALF_H * 2;
    long cull_l = this->pnl_x - tile_w * 2;
    long cull_t = this->pnl_y - tile_h * 4;
    long cull_r = this->pnl_x + scr_w + tile_w * 2;
    long cull_b = this->pnl_y + scr_h + tile_h * 10;

    for (int i = 0; i < obj_draw_count; ++i) {
        GameViewObjDrawEntry* e = &obj_draw_list[i];
        if (e->obj == nullptr || e->obj->master_obj == nullptr || e->obj->object_state >= 7) {
            continue;
        }

        long obj_l = 0;
        long obj_t = 0;
        long obj_r = 0;
        long obj_b = 0;
        if (gameview_object_bounds(e->obj, e->sx, e->sy, &obj_l, &obj_t, &obj_r, &obj_b) != 0) {
            if (obj_r < cull_l || obj_l > cull_r || obj_b < cull_t || obj_t > cull_b) {
                objects_culled++;
                continue;
            }
        }

        if (gameview_draw_object_sprite(this->render_area, e->obj, e->sx, e->sy) != 0) {
            objects_drawn++;
        } else {
            this->render_area->DrawLine((int)e->sx - 4, (int)e->sy - 4, (int)e->sx + 4, (int)e->sy + 4, 250);
            this->render_area->DrawLine((int)e->sx - 4, (int)e->sy + 4, (int)e->sx + 4, (int)e->sy - 4, 250);
            objects_fallback++;
        }
    }

    // Log summary (throttled)
    static int log_counter = 0;
    if (log_counter++ % 60 == 0) {
        CUSTOM_DEBUG_LOG_FMT("GameViewPanel::draw: cam=%ld,%ld drawn=%d real=%d fallback=%d borderDraw=%d borderMiss=%d objs=%d objFb=%d objCull=%d checked=%d cullX=%d cullY=%d badTerrain=%d missShape=%d missFrame=%d sx=[%ld..%ld] sy=[%ld..%ld] map=%ldx%ld pnl=%d,%d %dx%d origin=%ld,%ld",
            this->cam_x, this->cam_y, drawn_tiles, real_tiles, fallback_tiles, border_drawn, border_missing, objects_drawn, objects_fallback, objects_culled, checked_tiles, culled_x, culled_y, bad_terrain_idx, missing_shape, missing_frame,
            min_sx, max_sx, min_sy, max_sy,
            map_w, map_h, this->pnl_x, this->pnl_y, scr_w, scr_h, origin_x, origin_y);
    }

    if (area_locked_here) {
        this->render_area->Unlock((char*)"GameViewPanel::draw");
    }

    delete[] obj_draw_list;

    this->render_area->SetClipRect(&saved_clip);

}

long GameViewPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) {
    // param_1 = virtual key code, param_2 = repeat count
    // param_3 = shift, param_4 = ctrl

    if (!this->world_map) {
        return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5);
    }

    long map_w = this->world_map->map_width;
    long map_h = this->world_map->map_height;
    long half_w = this->world_map->tile_half_width > 0 ? this->world_map->tile_half_width : TILE_HALF_W;
    long half_h = this->world_map->tile_half_height > 0 ? this->world_map->tile_half_height : TILE_HALF_H;

    // Maximum camera bounds (world pixel extents)
    long world_pixel_w = (map_w + map_h) * half_w;
    long world_pixel_h = (map_w + map_h) * half_h;
    long max_cam_x = world_pixel_w - this->pnl_wid;
    long max_cam_y = world_pixel_h - this->pnl_hgt;
    if (max_cam_x < 0) max_cam_x = 0;
    if (max_cam_y < 0) max_cam_y = 0;

    int handled = 1;
    switch (param_1) {
    case VK_LEFT:
        this->cam_x -= this->scroll_speed;
        CUSTOM_DEBUG_LOG_FMT("Scroll LEFT -> %ld", this->cam_x);
        break;
    case VK_RIGHT:
        this->cam_x += this->scroll_speed;
        CUSTOM_DEBUG_LOG_FMT("Scroll RIGHT -> %ld", this->cam_x);
        break;
    case VK_UP:
        this->cam_y -= this->scroll_speed;
        CUSTOM_DEBUG_LOG_FMT("Scroll UP -> %ld", this->cam_y);
        break;
    case VK_DOWN:
        this->cam_y += this->scroll_speed;
        CUSTOM_DEBUG_LOG_FMT("Scroll DOWN -> %ld", this->cam_y);
        break;
    default:
        handled = 0;
        break;
    }

    // Clamp camera
    if (this->cam_x < 0) this->cam_x = 0;
    if (this->cam_y < 0) this->cam_y = 0;
    if (this->cam_x > max_cam_x) this->cam_x = max_cam_x;
    if (this->cam_y > max_cam_y) this->cam_y = max_cam_y;

    if (handled) {
        this->set_redraw(TPanel::Redraw);
        return 0; // consumed
    }

    return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5);
}

long GameViewPanel::handle_idle() {
    if (MouseSystem) {
        POINT pt;
        pt.x = MouseSystem->mouse_x;
        pt.y = MouseSystem->mouse_y;

        if (this->render_area && this->render_area->Wnd) {
            ScreenToClient((HWND)this->render_area->Wnd, &pt);
        }

        long mx = (long)pt.x - this->pnl_x;
        long my = (long)pt.y - this->pnl_y;

        if (mx < 0 || my < 0 || mx >= this->pnl_wid || my >= this->pnl_hgt) {
            return TScreenPanel::handle_idle();
        }

        int scroll_margin = 10;
        int scroll_needed = 0;

        if (mx < scroll_margin) {
            this->cam_x -= this->scroll_speed;
            scroll_needed = 1;
        } else if (mx > this->pnl_wid - scroll_margin) {
            this->cam_x += this->scroll_speed;
            scroll_needed = 1;
        }

        if (my < scroll_margin) {
            this->cam_y -= this->scroll_speed;
            scroll_needed = 1;
        } else if (my > this->pnl_hgt - scroll_margin) {
            this->cam_y += this->scroll_speed;
            scroll_needed = 1;
        }

        if (scroll_needed) {
            long map_w = this->world_map->map_width;
            long map_h = this->world_map->map_height;
            long half_w = this->world_map->tile_half_width > 0 ? this->world_map->tile_half_width : TILE_HALF_W;
            long half_h = this->world_map->tile_half_height > 0 ? this->world_map->tile_half_height : TILE_HALF_H;
            long world_pixel_w = (map_w + map_h) * half_w;
            long world_pixel_h = (map_w + map_h) * half_h;
            long max_cam_x = world_pixel_w - this->pnl_wid;
            long max_cam_y = world_pixel_h - this->pnl_hgt;
            if (max_cam_x < 0) max_cam_x = 0;
            if (max_cam_y < 0) max_cam_y = 0;

            if (this->cam_x < 0) this->cam_x = 0;
            if (this->cam_y < 0) this->cam_y = 0;
            if (this->cam_x > max_cam_x) this->cam_x = max_cam_x;
            if (this->cam_y > max_cam_y) this->cam_y = max_cam_y;

            this->set_redraw(TPanel::Redraw);
        }
    }
    return TScreenPanel::handle_idle();
}
