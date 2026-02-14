// Temporary game-view panel: renders isometric map with real terrain SLP sprites.
// This is scaffolding — will be replaced by the real TRIBE_Screen_Game once reimplemented.

#include "../include/GameViewPanel.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Tile.h"
#include "../include/RGE_Tile_Set.h"
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

    // Origin offset: place tile (0,0) at the center-top of the isometric diamond
    long origin_x = (map_h - 1) * TILE_HALF_W;
    long origin_y = 0;

    int drawn_tiles = 0;
    int checked_tiles = 0;

    // Iterate all tiles and draw terrain SLP sprites.
    // For each tile, use the pre-computed screen_xpos/screen_ypos from RGE_Map,
    // or compute isometric coords directly.
    for (long row = 0; row < map_h; row++) {
        for (long col = 0; col < map_w; col++) {
            checked_tiles++;
            RGE_Tile* tile = &this->world_map->map_row_offset[row][col];

            // Use the tile's pre-computed screen position (set by set_map_screen_pos)
            // screen_xpos = (col - row) * tile_half_width
            // screen_ypos = (col + row) * tile_half_height
            long wx = origin_x + (long)tile->screen_xpos;
            long wy = origin_y + (long)tile->screen_ypos;

            // Convert to screen position with camera offset
            long sx = wx - this->cam_x + this->pnl_x;
            long sy = wy - this->cam_y + this->pnl_y;

            // Early cull: skip if tile is fully outside the panel
            // Terrain tiles are 64x32 (TILE_HALF_W*2 x TILE_HALF_H*2)
            if (sx + TILE_HALF_W < this->pnl_x || sx - TILE_HALF_W > this->pnl_x + scr_w)
                continue;
            if (sy + TILE_HALF_H * 2 < this->pnl_y || sy - TILE_HALF_H > this->pnl_y + scr_h)
                continue;

            // Look up the terrain type and get the SLP shape
            unsigned char terrain_idx = tile->terrain_type; // 5-bit field (0-31)
            unsigned char tile_type = tile->tile_type;

            if (terrain_idx >= 32) {
                 if (checked_tiles % 1000 == 0) CUSTOM_DEBUG_LOG_FMT("Bad terrain idx %d at %ld,%ld", terrain_idx, col, row);
                 continue;
            }

            RGE_Tile_Set* ts = &this->world_map->terrain_types[terrain_idx];
            if (!ts->loaded) {
                 if (checked_tiles % 1000 == 0) CUSTOM_DEBUG_LOG_FMT("Terrain %d not loaded at %ld,%ld", terrain_idx, col, row);
                 continue;
            }
            if (!ts->shape) {
                 if (checked_tiles % 1000 == 0) CUSTOM_DEBUG_LOG_FMT("Terrain %d no shape at %ld,%ld", terrain_idx, col, row);
                 continue;
            }

            // Get the SLP frame index for this terrain at this tile position
            short frame = get_tile_picture(this->world_map, terrain_idx, tile_type,
                                           (short)col, (short)row);
            
            if (frame < 0) {
                 if (checked_tiles % 1000 == 0) CUSTOM_DEBUG_LOG_FMT("Terrain %d frame < 0 at %ld,%ld", terrain_idx, col, row);
                 continue;
            }

            // Draw the terrain SLP sprite
            // TShape::shape_draw(draw_area, x, y, shape_idx, mode, flag, table)
            // The tile's SLP hotspot handles positioning — we draw at the tile's
            // screen position. The SLP frame's hotspot aligns it correctly.
            ts->shape->shape_draw(this->render_area, sx, sy, (long)frame, 0, 0, nullptr);
            drawn_tiles++;
        }
    }
    
    // Log summary (throttled)
    static int log_counter = 0;
    if (log_counter++ % 60 == 0) {
        CUSTOM_DEBUG_LOG_FMT("GameViewPanel::draw: cam=%ld,%ld drawn=%d checked=%d map=%ldx%ld pnl=%dx%d",
            this->cam_x, this->cam_y, drawn_tiles, checked_tiles, map_w, map_h, scr_w, scr_h);
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
