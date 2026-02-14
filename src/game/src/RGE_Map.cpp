#include "RGE_Map.h"
#include "RGE_Base_Game.h"
#include "globals.h"
#include "TSpan_List_Manager.h"
#include "RGE_Border_Set.h"
#include "RGE_Game_World.h"
#include "TShape.h"
#include "custom_debug.h"
#include "debug_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h> 

RGE_Map::RGE_Map()
{
    this->game_world = nullptr;
    this->map_width = 0;
    this->map_height = 0;
    this->world_width = 0.0f;
    this->world_height = 0.0f;
    this->map_row_offset = nullptr;
    this->search_map = nullptr;
    this->map = nullptr;
    this->num_terrain = 0;

    this->init_tile_sizes();
}

RGE_Map::RGE_Map(RGE_Game_World* world, long w, long h)
{
    this->game_world = world;
    this->map_width = 0;
    this->map_height = 0;
    this->world_width = 0.0f;
    this->world_height = 0.0f;
    this->map_row_offset = nullptr;
    this->search_map = nullptr;
    this->map = nullptr;
    this->num_terrain = 0;

    this->init_tile_sizes();

    if (w > 0 && h > 0) {
        this->new_map(w, h);
    }
}

RGE_Map::~RGE_Map()
{
}

void RGE_Map::init_tile_sizes()
{
    this->tile_width = 64;
    this->tile_height = 32;
    this->tile_half_width = 32;
    this->tile_half_height = 16;
    this->elev_height = 8;
}

void RGE_Map::new_map(long w, long h)
{
    this->map_width = w;
    this->map_height = h;
    this->world_width = (float)w;
    this->world_height = (float)h;

    size_t tile_count = (size_t)w * (size_t)h;
    this->map = (RGE_Tile*)calloc(tile_count, sizeof(RGE_Tile));
    this->search_map = (unsigned char*)calloc(tile_count, 1);
    this->map_row_offset = (RGE_Tile**)calloc((size_t)h, sizeof(RGE_Tile*));

    for (int i = 0; i < h; ++i) {
        this->map_row_offset[i] = &this->map[i * w];
    }

    this->set_map_screen_pos(0, 0, w - 1, h - 1);
}

void RGE_Map::set_map_screen_pos(int col1, int row1, int col2, int row2)
{
    for (int r = row1; r <= row2; ++r) {
        for (int c = col1; c <= col2; ++c) {
            RGE_Tile* tile = this->get_tile(c, r);
            if (tile) {
                // AoE1 Isometric Projection:
                // x = (col - row) * 32
                // y = (col + row) * 16 (Top to Bottom)
                tile->screen_xpos = (short)((c - r) * this->tile_half_width);
                tile->screen_ypos = (short)((c + r) * this->tile_half_height);
            }
        }
    }
}

RGE_Tile* RGE_Map::get_tile(int col, int row)
{
    if (col < 0 || col >= this->map_width || row < 0 || row >= this->map_height)
        return nullptr;
    return this->map_row_offset[row] + col;
}

RGE_Map::RGE_Map(int file_handle, RGE_Sound** sounds, uchar load_map)
{
    this->game_world = nullptr;
    
    // Read the entire object from the file handle
    // WARNING: This assumes RGE_Map layout in memory matches the file exactly, including vtable.
    // We must save/restore the vtable pointer because _read will overwrite it with garbage.
    void* vptr = *(void**)this;
    
    // Using _read from io.h (Windows)
    _read(file_handle, this, sizeof(RGE_Map));
    
    // Restore vtable
    *(void**)this = vptr;

    // Reset pointers that were overwritten with garbage from the file
    this->map = nullptr;
    this->map_row_offset = nullptr;
    this->search_map = nullptr;
    this->search_map_rows = nullptr;
    this->game_world = nullptr; // Will be set later or via param? params didn't pass world.
    this->random_map = nullptr;
    this->map_zones = nullptr;
    this->unified_vis_map = nullptr;
    this->unit_manager = nullptr;

    // Initialize tile sizes if needed (though file might have them)
    // this->init_tile_sizes(); // The file usually has standard sizes, but let's trust the file.

    if (load_map) {
        // Load terrain and border shapes
        this->load_terrain_types(sounds);
        this->load_border_types(sounds);
    }
}

RGE_Map::RGE_Map(char* terrain_file, char* border_file, char* terrain_obj_file, short tile_w, short tile_h, short elev_h, RGE_Sound** sounds)
{
    this->game_world = nullptr;
    this->map_width = 0;
    this->map_height = 0;
    this->world_width = 0.0f;
    this->world_height = 0.0f;
    this->map_row_offset = nullptr;
    this->search_map = nullptr;
    this->map = nullptr;
    this->num_terrain = 0;
    this->init_tile_sizes();
}

void RGE_Map::clear_map(RGE_Player* player, RGE_Game_World* world, uchar terrain, long w, long h)
{
    this->new_map(w, h);
}

void RGE_Map::clear_map(uchar terrain, uchar height)
{
    // Stub
}

void RGE_Map::set_terrain(RGE_Player* player, RGE_Game_World* world, short col, short row, uchar terrain, uchar unknown1, uchar unknown2)
{
    // Stub
}

void RGE_Map::load_terrain_obj_types(char* filename)
{
    // Stub
}

void RGE_Map::data_load_random_map(int param_1) {}
void RGE_Map::load_random_map(char* param_1, char* param_2, char* param_3, char* param_4) {}
uchar RGE_Map::do_terrain_brush(long param_1, long param_2, long param_3, uchar param_4) { return 0; }
uchar RGE_Map::do_terrain_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6) { return 0; }
uchar RGE_Map::do_elevation_brush(long param_1, long param_2, long param_3, uchar param_4) { return 0; }
uchar RGE_Map::do_elevation_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6) { return 0; }
uchar RGE_Map::do_cliff_brush(long param_1, long param_2, uchar param_3, uchar param_4) { return 0; }
uchar RGE_Map::do_cliff_brush_stroke(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6) { return 0; }
void RGE_Map::map_generate(RGE_Player* param_1, RGE_Game_World* param_2, RGE_Player_Info* param_3, uchar* param_4) {}
void RGE_Map::map_generate2(RGE_Game_World* param_1, long param_2, long param_3, uchar param_4, long param_5) {}
void RGE_Map::save(int param_1) {}

void RGE_Map::load_terrain_types(RGE_Sound** sounds)
{
    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("RGE_Map::load_terrain_types: num_terrain=%d", this->num_terrain);
    CUSTOM_DEBUG_END

    for (int i = 0; i < this->num_terrain; i++) {
        RGE_Tile_Set* ts = &this->terrain_types[i];
        
        // Ensure name is null terminated just in case
        ts->name[12] = 0;
        ts->pict_name[12] = 0;

        if (ts->resource_id > 0) {
            // Load shape using resource ID (assume it's in loaded DRS files)
            ts->shape = new TShape(ts->pict_name, ts->resource_id);
            if (ts->shape->shape_count() > 0) {
                ts->loaded = 1;
                CUSTOM_DEBUG_BEGIN
                if (i < 5 || i == this->num_terrain - 1) { // Log first few and last to avoid spam
                    CUSTOM_DEBUG_LOG_FMT("  Terrain[%d] loaded: id=%d name='%s' shapes=%d", 
                        i, ts->resource_id, ts->pict_name, ts->shape->shape_count());
                }
                CUSTOM_DEBUG_END
            } else {
                // If failed to load, maybe try just name?
                // ts->loaded = 0;
                // delete ts->shape;
                // ts->shape = nullptr;
                CUSTOM_DEBUG_BEGIN
                CUSTOM_DEBUG_LOG_FMT("  Terrain[%d] FAILED to load shapes: id=%d name='%s'", 
                    i, ts->resource_id, ts->pict_name);
                CUSTOM_DEBUG_END
            }
        } else {
            ts->shape = nullptr;
            ts->loaded = 0;
            // CUSTOM_DEBUG_LOG_FMT("  Terrain[%d] SKIPPED (no resource_id)", i);
        }
    }
}

void RGE_Map::load_border_types(RGE_Sound** sounds)
{
    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("RGE_Map::load_border_types: num_borders=%d", this->num_borders);
    CUSTOM_DEBUG_END

    for (int i = 0; i < this->num_borders; i++) {
        RGE_Border_Set* bs = &this->border_types[i];
        
        bs->name[12] = 0;
        bs->pict_name[12] = 0;

        if (bs->resource_id > 0) {
            bs->shape = new TShape(bs->pict_name, bs->resource_id);
            // We assume border shape loading works similarly
            if (bs->shape->shape_count() > 0) {
                 // Log success if needed
            } else {
                 CUSTOM_DEBUG_BEGIN
                 CUSTOM_DEBUG_LOG_FMT("  Border[%d] FAILED to load shapes: id=%d name='%s'", 
                    i, bs->resource_id, bs->pict_name);
                 CUSTOM_DEBUG_END
            }
        } else {
            bs->shape = nullptr;
        }
    }
}
void RGE_Map::load_terrain_types(char* filename, RGE_Sound** sounds) {}
void RGE_Map::load_border_types(char* filename, RGE_Sound** sounds) {}
void RGE_Map::coordinate_map() {}
void RGE_Map::set_map_visible(uchar flag) {}
void RGE_Map::set_map_fog(uchar flag) {}
void RGE_Map::request_redraw(int col0, int row0, int col1, int row1, uchar attr) {}
void RGE_Map::clear_map_view_info() {}
uchar RGE_Map::get_border_type(short col, short row) { return 0; }
