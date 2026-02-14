// Temporary game-view panel: renders isometric map with real terrain SLP sprites.
// This is scaffolding — will be replaced by the real TRIBE_Screen_Game once reimplemented.

#include "../include/GameViewPanel.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Tile.h"
#include "../include/RGE_Tile_Set.h"
#include "../include/RGE_Border_Set.h"
#include "../include/RGE_TOB_Picts.h"
#include "../include/TShape.h"
#include "../include/TDrawArea.h"
#include "../include/custom_debug.h"

#include <windows.h>
#include <stdio.h>
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

    // Source-of-truth quirk: original code indexes the 19x12 border table via a flattened
    // offset (shape + tile_type*12 + 10), not a direct [tile_type-1][shape+11] expression.
    const int flat_index = (int)border_shape + (int)tile_type * 12 + 10;
    if (flat_index < 0 || flat_index >= (19 * 12)) {
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

    int drawn_tiles = 0;
    int real_tiles = 0;
    int fallback_tiles = 0;
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

            long tile_draw_h = half_h * 2;
            if (tile_type < 19 && this->world_map->tilesizes[tile_type].height > 0) {
                tile_draw_h = this->world_map->tilesizes[tile_type].height;
            }

            // Early cull: skip if tile is fully outside the panel.
            if (sx + half_w < this->pnl_x || sx - half_w > this->pnl_x + scr_w) {
                culled_x++;
                continue;
            }
            if (sy + tile_draw_h < this->pnl_y || sy - half_h > this->pnl_y + scr_h) {
                culled_y++;
                continue;
            }

            // Look up the terrain type and get the SLP shape
            unsigned char terrain_idx = tile->terrain_type; // 5-bit field (0-31)

            if (terrain_idx >= 32) {
                bad_terrain_idx++;
                if (checked_tiles % 1000 == 0) CUSTOM_DEBUG_LOG_FMT("Bad terrain idx %d at %ld,%ld", terrain_idx, col, row);
                continue;
            }

            if (FORCE_FALLBACK_TILES) {
                draw_fallback_iso_tile(this->render_area, sx, sy, terrain_idx);
                drawn_tiles++;
                fallback_tiles++;
                continue;
            }

            RGE_Tile_Set* ts = &this->world_map->terrain_types[terrain_idx];
            if (!ts->loaded) {
                missing_shape++;
                draw_fallback_iso_tile(this->render_area, sx, sy, terrain_idx);
                drawn_tiles++;
                fallback_tiles++;
                continue;
            }
            if (!ts->shape) {
                missing_shape++;
                draw_fallback_iso_tile(this->render_area, sx, sy, terrain_idx);
                drawn_tiles++;
                fallback_tiles++;
                continue;
            }

            // Get the SLP frame index for this terrain at this tile position
            short frame = get_tile_picture(this->world_map, terrain_idx, tile_type,
                                           (short)col, (short)row);
            
            if (frame < 0) {
                missing_frame++;
                draw_fallback_iso_tile(this->render_area, sx, sy, terrain_idx);
                drawn_tiles++;
                fallback_tiles++;
                continue;
            }

            if (frame >= ts->shape->shape_count()) {
                missing_frame++;
                draw_fallback_iso_tile(this->render_area, sx, sy, terrain_idx);
                drawn_tiles++;
                fallback_tiles++;
                continue;
            }

            // Non-original seam stabilization:
            // Some transition/elevation tile frames appear to be partial overlays in the
            // current renderer path. Draw a flat same-terrain underlay first so transparent
            // portions never expose the clear color.
            if (tile_type != 0) {
                short underlay = get_tile_picture(this->world_map, terrain_idx, 0, (short)col, (short)row);
                if (underlay >= 0 && underlay < ts->shape->shape_count()) {
                    ts->shape->shape_draw(this->render_area, sx, sy, (long)underlay, 0, 0, nullptr);
                }
            }

            // Draw the terrain SLP sprite
            // TShape::shape_draw(draw_area, x, y, shape_idx, mode, flag, table)
            // The tile's SLP hotspot handles positioning — we draw at the tile's
            // screen position. The SLP frame's hotspot aligns it correctly.
            ts->shape->shape_draw(this->render_area, sx, sy, (long)frame, 0, 0, nullptr);

            // Border overlay pass (terrain transitions/cliff-edge blending).
            unsigned char border_idx = tile->border_type;
            if (border_idx != 0 && border_idx < 16) {
                RGE_Border_Set* bs = &this->world_map->border_types[border_idx];
                if (bs->loaded && bs->shape != nullptr) {
                    short border_frame = get_border_picture(this->world_map, border_idx, tile_type,
                                                            tile->border_shape, (short)col, (short)row);
                    if (border_frame >= 0 && border_frame < bs->shape->shape_count()) {
                        bs->shape->shape_draw(this->render_area, sx, sy, (long)border_frame, 0, 0, nullptr);
                        border_drawn++;
                    } else {
                        border_missing++;
                    }
                }
            }

            drawn_tiles++;
            real_tiles++;
        }
    }
    
    // Log summary (throttled)
    static int log_counter = 0;
    if (log_counter++ % 60 == 0) {
        CUSTOM_DEBUG_LOG_FMT("GameViewPanel::draw: cam=%ld,%ld drawn=%d real=%d fallback=%d borderDraw=%d borderMiss=%d checked=%d cullX=%d cullY=%d badTerrain=%d missShape=%d missFrame=%d sx=[%ld..%ld] sy=[%ld..%ld] map=%ldx%ld pnl=%d,%d %dx%d origin=%ld,%ld",
            this->cam_x, this->cam_y, drawn_tiles, real_tiles, fallback_tiles, border_drawn, border_missing, checked_tiles, culled_x, culled_y, bad_terrain_idx, missing_shape, missing_frame,
            min_sx, max_sx, min_sy, max_sy,
            map_w, map_h, this->pnl_x, this->pnl_y, scr_w, scr_h, origin_x, origin_y);
    }
}

long GameViewPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) {
    // param_1 = virtual key code, param_2 = repeat count
    // param_3 = shift, param_4 = ctrl

    if (!this->world_map) {
        return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5);
    }

    long map_w = this->world_map->map_width;
    long map_h = this->world_map->map_height;

    // Maximum camera bounds (world pixel extents)
    long world_pixel_w = (map_w + map_h) * TILE_HALF_W;
    long world_pixel_h = (map_w + map_h) * TILE_HALF_H;
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
        long mx = MouseSystem->mouse_x;
        long my = MouseSystem->mouse_y;
        
        // Mouse coordinates are relative to the window/screen.
        // We need them relative to the panel?
        // TMousePointer stores screen coordinates usually.
        // If the panel is full screen (or main view), screen coords are fine.
        // But we should subtract pnl_x/y if needed. 
        // For now assuming full screen or pnl_x=0.
        mx -= this->pnl_x;
        my -= this->pnl_y;

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
            long world_pixel_w = (map_w + map_h) * TILE_HALF_W;
            long world_pixel_h = (map_w + map_h) * TILE_HALF_H;
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
