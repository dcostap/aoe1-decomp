#include "RGE_Map.h"
#include "RGE_Game_World.h"
#include "RGE_Base_Game.h"
#include "TDrawArea.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// ========================================================================
// Constructor / Destructor
// ========================================================================

// Address: 0x00470600
RGE_Map::RGE_Map() {
    this->map = nullptr;
    this->map_width = 0;
    this->map_height = 0;
    this->world_width = 0;
    this->world_height = 0;
    
    memset(this->tilesizes, 0, sizeof(this->tilesizes));
    memset(this->terrain_types, 0, sizeof(this->terrain_types));
    memset(this->border_types, 0, sizeof(this->border_types));

    this->map_row_offset = nullptr;
    this->num_terrain = 0;
    this->num_borders = 0;
    this->max_terrain = 0;
    this->tile_width = 0;
    this->tile_height = 0;
    this->tile_half_height = 0;
    this->tile_half_width = 0;
    this->elev_height = 0;
    this->cur_row = 0;
    this->cur_col = 0;
    this->block_beg_row = 0;
    this->block_end_row = 0;
    this->block_beg_col = 0;
    this->block_end_col = 0;
    this->any_frame_change = 0;
    this->search_map = nullptr;
    this->search_map_rows = nullptr;
    this->map_visible_flag = 0;
    this->fog_flag = 1;
    this->random_map = nullptr;
    this->game_world = rge_base_game ? rge_base_game->world : nullptr;
    this->map_zones = nullptr;
    this->unified_vis_map = nullptr;
    this->unit_manager = nullptr;
}

// Address: 0x004707a0
RGE_Map::~RGE_Map() {
    if (this->map) {
        free(this->map);
    }
    if (this->map_row_offset) {
        free(this->map_row_offset);
    }
    if (this->search_map) {
        free(this->search_map);
    }
    if (this->search_map_rows) {
        free(this->search_map_rows);
    }
}

// ========================================================================
// Virtual Methods (Stubs)
// ========================================================================

void RGE_Map::data_load_random_map(int param_1) { /* Stub */ }

void RGE_Map::load_random_map(char *param_1, char *param_2, char *param_3, char *param_4) { /* Stub */ }

uchar RGE_Map::do_terrain_brush(long param_1, long param_2, long param_3, uchar param_4) { return 0; }

uchar RGE_Map::do_terrain_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6) { return 0; }

uchar RGE_Map::do_elevation_brush(long param_1, long param_2, long param_3, uchar param_4) { return 0; }

uchar RGE_Map::do_elevation_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6) { return 0; }

uchar RGE_Map::do_cliff_brush(long param_1, long param_2, uchar param_3, uchar param_4) { return 0; }

uchar RGE_Map::do_cliff_brush_stroke(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6) { return 0; }

void RGE_Map::map_generate(struct RGE_Player *param_1, struct RGE_Game_World *param_2, struct RGE_Player_Info *param_3, uchar *param_4) { /* Stub */ }

void RGE_Map::map_generate2(struct RGE_Game_World *param_1, long param_2, long param_3, uchar param_4, long param_5) { /* Stub */ }

void RGE_Map::save(int param_1) { /* Stub */ }

// ========================================================================
// Non-virtual Methods
// ========================================================================

// Address: 0x004708a0
void RGE_Map::new_map(long width, long height) {
    if (this->map) {
        free(this->map);
    }
    if (this->map_row_offset) {
        free(this->map_row_offset);
    }

    this->map_width = width;
    this->map_height = height;
    this->world_width = width;
    this->world_height = height;

    this->map = (RGE_Tile *)malloc(width * height * sizeof(RGE_Tile));
    memset(this->map, 0, width * height * sizeof(RGE_Tile));

    this->map_row_offset = (RGE_Tile **)malloc(height * sizeof(RGE_Tile *));
    for (int i = 0; i < height; ++i) {
        this->map_row_offset[i] = &this->map[i * width];
    }

#ifdef _DEBUG
    // Initialize tiles with some default terrain
    for (int i = 0; i < width * height; ++i) {
        this->map[i].terrain_type = 0; // Grass?
        this->map[i].height = 0;
    }
#endif
}

// Address: 0x00471000
void RGE_Map::draw(TDrawArea *render_area, int x, int y, int width, int height) {
#ifdef _DEBUG
    static int map_draw_count = 0;
    if (map_draw_count % 1000 == 0) {
        printf("RGE_Map::draw: count=%d map=%p render_area=%p\n", map_draw_count, this->map, render_area);
    }
    map_draw_count++;
#endif
    if (!this->map || !render_area) return;

#ifdef _DEBUG
    RECT rect = {x, y, x + width, y + height};
    render_area->Clear(&rect, 3); // Green in our 8-bit palette
#endif

    // Draw a blue square in the middle to verify multiple colors
    RECT blue_rect = { 350, 250, 450, 350 };
    render_area->Clear(&blue_rect, 4); // Blue in our 8-bit palette
}

void RGE_Map::load_terrain_types(RGE_Sound **sounds) {
    // STUB
}

void RGE_Map::load_border_types(RGE_Sound **sounds) {
    // STUB
}
