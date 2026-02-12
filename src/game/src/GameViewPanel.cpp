// Temporary game-view panel: renders flat isometric tile grid with camera scrolling.
// This is scaffolding — will be replaced by the real TRIBE_Screen_Game once reimplemented.

#include "../include/GameViewPanel.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Tile.h"
#include "../include/TDrawArea.h"
#include "../include/custom_debug.h"

#include <windows.h>

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

void GameViewPanel::draw() {
    if (!this->render_area || !this->world_map || !this->world_map->map) {
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

    if (map_w <= 0 || map_h <= 0) return;

    // For each tile at (col, row), isometric screen position (before camera) is:
    //   sx = (col - row) * TILE_HALF_W + origin_x
    //   sy = (col + row) * TILE_HALF_H + origin_y
    //
    // We set origin such that tile (0,0) is centered horizontally.
    // With camera offset, screen pos = iso_pos - cam.

    // Origin offset: place the top tile at the center-top of the world
    long origin_x = (map_h - 1) * TILE_HALF_W;
    long origin_y = 0;

    // Get a GDI DC for polygon drawing
    HDC hdc = (HDC)this->render_area->GetDc((char*)"GameViewPanel::draw");
    if (!hdc) {
        return;
    }

    // Palette-based green shades for terrain variety
    // Using palette indices that are typically green-ish in AoE1 palette
    // We'll use GDI Polygon with solid brush fills.
    // Since we're 8-bit palettized, we use PALETTEINDEX colors.
    COLORREF grass_colors[4] = {
        PALETTEINDEX(0xB0),  // medium green
        PALETTEINDEX(0xB1),  // slightly different green
        PALETTEINDEX(0xB2),  // another green shade
        PALETTEINDEX(0xB3),  // fourth variant
    };

    HPEN gridPen = CreatePen(PS_SOLID, 1, PALETTEINDEX(0xA0)); // darker outline
    HPEN oldPen = (HPEN)SelectObject(hdc, gridPen);

    // Compute visible tile range based on camera position
    // We'll iterate all tiles but skip those outside the screen rect.
    // For a large map this is wasteful, but sufficient for scaffolding.
    for (long row = 0; row < map_h; row++) {
        for (long col = 0; col < map_w; col++) {
            // Isometric center of this tile in world coords
            long wx = origin_x + (col - row) * TILE_HALF_W;
            long wy = origin_y + (col + row) * TILE_HALF_H;

            // Screen position
            long sx = wx - this->cam_x + this->pnl_x;
            long sy = wy - this->cam_y + this->pnl_y;

            // Early cull: skip if diamond is fully outside the panel
            if (sx + TILE_HALF_W < this->pnl_x || sx - TILE_HALF_W > this->pnl_x + scr_w)
                continue;
            if (sy + TILE_HALF_H < this->pnl_y || sy - TILE_HALF_H > this->pnl_y + scr_h)
                continue;

            // Diamond vertices: top, right, bottom, left
            POINT pts[4];
            pts[0].x = sx;                  pts[0].y = sy - TILE_HALF_H;  // top
            pts[1].x = sx + TILE_HALF_W;    pts[1].y = sy;                // right
            pts[2].x = sx;                  pts[2].y = sy + TILE_HALF_H;  // bottom
            pts[3].x = sx - TILE_HALF_W;    pts[3].y = sy;                // left

            // Pick color based on checkerboard pattern for visual variety
            int color_idx = (col + row) % 4;
            HBRUSH brush = CreateSolidBrush(grass_colors[color_idx]);
            HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

            Polygon(hdc, pts, 4);

            SelectObject(hdc, oldBrush);
            DeleteObject(brush);
        }
    }

    SelectObject(hdc, oldPen);
    DeleteObject(gridPen);

    this->render_area->ReleaseDc((char*)"GameViewPanel::draw");
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
        break;
    case VK_RIGHT:
        this->cam_x += this->scroll_speed;
        break;
    case VK_UP:
        this->cam_y -= this->scroll_speed;
        break;
    case VK_DOWN:
        this->cam_y += this->scroll_speed;
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
    // For now, just delegate to parent. Edge scrolling can be added later.
    return TScreenPanel::handle_idle();
}
