#include "../include/RGE_Map.h"
#include "../include/RGE_Base_Game.h"
#include "../include/globals.h"
#include "../include/TShape.h"
#include "../include/RGE_Border_Set.h"
#include "../include/RGE_Game_World.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================================================
// Constructors — transliterated from map.cpp.decomp
// ============================================================================

// Default constructor — zero-init for scaffolding
RGE_Map::RGE_Map() {
    memset(&this->map, 0, sizeof(RGE_Map) - offsetof(RGE_Map, map));
}

// Binary constructor — reads terrain data from empires.dat file handle
// Source of truth: map.cpp.decomp (RGE_Map @ 0x00455000)
RGE_Map::RGE_Map(int file_handle, RGE_Sound** sounds, uchar load_map) {
    // Zero the map_zones pointer before the bulk read
    this->map_zones = nullptr;

    // Read 0x8DD0 bytes from empires.dat directly into this struct.
    // This overwrites the vtable pointer and all inline data (terrain_types[32],
    // border_types[16], tilesizes[19], dimensions, etc.). The vtable and pointer
    // fields are re-set afterward. This is the standard AoE1 binary load pattern.
    rge_read(file_handle, this, 0x8DD0);

    // Re-set fields that were overwritten by the bulk read
    this->game_world = rge_base_game ? rge_base_game->world : nullptr;
    this->map = nullptr;
    this->search_map = nullptr;
    this->map_row_offset = nullptr;
    this->search_map_rows = nullptr;
    this->unified_vis_map = nullptr;
    this->unit_manager = nullptr;
    this->random_map = nullptr;

    // Construct TShape SLPs for each loaded terrain type and border type
    this->load_terrain_types(sounds);
    this->load_border_types(sounds);

    // Initialize tile size lookup tables (tile_width=64, tile_height=32, elev=16)
    this->init_tile_sizes();

    // Optionally load random map database
    if (load_map != '\0') {
        this->data_load_random_map(file_handle);
    }
}

// Text-file constructor — reads terrain definitions from text data files
// Source of truth: map.cpp.decomp (RGE_Map @ 0x004550A0)
RGE_Map::RGE_Map(char* terrain_file, char* border_file, char* terrain_obj_file,
                 short tile_w, short tile_h, short elev_h, RGE_Sound** sounds) {
    this->map_zones = nullptr;
    this->random_map = nullptr;
    this->game_world = rge_base_game ? rge_base_game->world : nullptr;

    // Set tile dimensions
    this->tile_width = tile_w;
    this->tile_half_width = tile_w / 2;
    this->tile_height = tile_h;
    this->tile_half_height = tile_h / 2;
    this->elev_height = elev_h;

    this->map_width = 0;
    this->map_height = 0;
    this->world_width = 0;
    this->world_height = 0;

    // Set tile sizes for all 19 tile types
    this->set_tile_size(0, tile_w, tile_h, 0);
    this->set_tile_size(1, tile_width, elev_height, -100);
    this->set_tile_size(2, tile_width, (short)(elev_height + tile_height), 100);
    this->set_tile_size(3, tile_width, tile_height, -100);
    this->set_tile_size(4, tile_width, tile_height, -100);
    this->set_tile_size(5, tile_width, elev_height, -100);
    this->set_tile_size(6, tile_width, (short)(elev_height + tile_height), 100);
    this->set_tile_size(7, tile_width, elev_height, -100);
    this->set_tile_size(8, tile_width, (short)(elev_height + tile_height), 100);
    this->set_tile_size(9, tile_width, elev_height, -100);
    this->set_tile_size(10, tile_width, (short)(elev_height + tile_height), 100);
    this->set_tile_size(11, tile_width, tile_height, -100);
    this->set_tile_size(12, tile_width, tile_height, -100);
    this->set_tile_size(13, tile_width, elev_height, -100);
    this->set_tile_size(14, tile_width, (short)(elev_height + tile_height), 100);
    this->set_tile_size(15, tile_width, tile_height, 100);
    this->set_tile_size(16, tile_width, tile_height, 100);
    this->set_tile_size(17, tile_half_width, tile_height, 0);
    this->set_tile_size(18, tile_half_width, tile_height, 0);

    this->cur_row = 0;
    this->cur_col = 0;
    this->num_terrain = 0;
    this->max_terrain = 0;
    this->block_beg_row = 0;
    this->block_end_row = 0;
    this->block_beg_col = 0;
    this->block_end_col = 0;
    this->any_frame_change = '\0';
    this->map_visible_flag = '\0';
    this->fog_flag = '\x01';

    // Zero terrain types: shape, sound, rows, cols, etc.
    for (int i = 0; i < 32; i++) {
        this->terrain_types[i].shape = nullptr;
        this->terrain_types[i].sound = nullptr;
        this->terrain_types[i].rows = 0;
        this->terrain_types[i].cols = 0;
        this->terrain_types[i].num_obj_type = 0;
        for (int j = 0; j < 30; j++) {
            this->terrain_types[i].obj_types[j] = 0;
            this->terrain_types[i].obj_density[j] = 0;
        }
        for (int j = 0; j < 32; j++) {
            this->terrain_types[i].borders[j] = 0;
        }
    }

    // Zero border types: shape, sound
    for (int i = 0; i < 16; i++) {
        this->border_types[i].shape = nullptr;
        this->border_types[i].sound = nullptr;
    }

    // Load terrain/border definitions from text files
    this->load_terrain_types(terrain_file, sounds);
    this->load_border_types(border_file, sounds);

    this->map = nullptr;
    this->search_map = nullptr;
    this->map_row_offset = nullptr;
    this->search_map_rows = nullptr;
    this->unified_vis_map = nullptr;
    this->unit_manager = nullptr;
}

// ============================================================================
// Destructor — transliterated from map.cpp.decomp (~RGE_Map @ 0x00455430)
// ============================================================================

RGE_Map::~RGE_Map() {
    // Free map tiles
    if (this->map) {
        free(this->map);
        this->map = nullptr;
    }

    // Free search map
    if (this->search_map) {
        free(this->search_map);
        this->search_map = nullptr;
    }

    // Free row offset pointers
    if (this->map_row_offset) {
        free(this->map_row_offset);
        this->map_row_offset = nullptr;
    }

    // Free search map row pointers
    if (this->search_map_rows) {
        free(this->search_map_rows);
        this->search_map_rows = nullptr;
    }

    // Delete terrain type TShape objects (iterate 31..0)
    for (int i = 31; i >= 0; i--) {
        TShape* s = this->terrain_types[i].shape;
        if (s) {
            delete s;
            this->terrain_types[i].shape = nullptr;
        }
    }

    // Delete border type TShape objects (iterate 15..0)
    for (int i = 15; i >= 0; i--) {
        TShape* s = this->border_types[i].shape;
        if (s) {
            delete s;
            this->border_types[i].shape = nullptr;
        }
    }

    // Zone map list, random map, unified_vis_map, unit_manager — stubs for now
    // TODO(accuracy): delete map_zones, random_map, unified_vis_map, unit_manager
}

// ============================================================================
// init_tile_sizes — transliterated from map.cpp.decomp (0x00455570)
// ============================================================================

void RGE_Map::init_tile_sizes() {
    // Hardcoded AoE1 tile dimensions
    this->tile_width = 0x40;      // 64
    this->tile_height = 0x20;     // 32
    this->tile_half_width = 0x20; // 32
    this->tile_half_height = 0x10;// 16
    this->elev_height = 0x10;     // 16

    set_tile_size(0, 0x40, 0x20, 0);
    set_tile_size(1, tile_width, elev_height, -8);
    set_tile_size(2, tile_width, (short)(elev_height + tile_height), 8);
    set_tile_size(3, tile_width, tile_height, -8);
    set_tile_size(4, tile_width, tile_height, -8);
    set_tile_size(5, tile_width, elev_height, -8);
    set_tile_size(6, tile_width, (short)(elev_height + tile_height), 8);
    set_tile_size(7, tile_width, elev_height, -8);
    set_tile_size(8, tile_width, (short)(elev_height + tile_height), 8);
    set_tile_size(9, tile_width, elev_height, -8);
    set_tile_size(10, tile_width, (short)(elev_height + tile_height), 8);
    set_tile_size(11, tile_width, tile_height, -8);
    set_tile_size(12, tile_width, tile_height, -8);
    set_tile_size(13, tile_width, elev_height, -8);
    set_tile_size(14, tile_width, (short)(elev_height + tile_height), 8);
    set_tile_size(15, tile_width, tile_height, 8);
    set_tile_size(16, tile_width, tile_height, 8);
    set_tile_size(17, tile_half_width, tile_height, 0);
    set_tile_size(18, tile_half_width, tile_height, 0);
}

// ============================================================================
// set_tile_size — transliterated from map.cpp.decomp (0x004556F0)
// ============================================================================

void RGE_Map::set_tile_size(uchar index, short width, short height, short y_delta) {
    if (index < 19) {
        this->tilesizes[index].width = width;
        this->tilesizes[index].height = height;
        this->tilesizes[index].y_delta = y_delta;
    }
}

// ============================================================================
// load_terrain_types (binary path) — transliterated from map.cpp.decomp
// Constructs TShape SLPs from the terrain_types[] data that was bulk-read
// from empires.dat.
// ============================================================================

void RGE_Map::load_terrain_types(RGE_Sound** sounds) {
    // Source of truth: map.cpp.decomp load_terrain_types
    // Iterates terrain_types[31..0], checks if loaded, constructs TShape
    // from pict_name + resource_id, assigns sound from sounds array.

    for (int i = 31; i >= 0; i--) {
        RGE_Tile_Set* ts = &this->terrain_types[i];

        // Delete any existing shape
        if (ts->shape) {
            delete ts->shape;
            ts->shape = nullptr;
        }

        if (ts->loaded == '\0') {
            continue;
        }

        // Construct the SLP filename from pict_name: "terrain\<pict_name>.shp"
        char filename[260];
        sprintf(filename, "%s.shp", ts->pict_name);

        // Create TShape — loads SLP from DRS using resource_id
        ts->shape = new TShape(filename, (int)ts->resource_id);

        // Assign sound if sounds array provided
        // The sound index is based on terrain index
        // TODO(accuracy): verify the exact sound array indexing
        if (sounds) {
            // Original uses: ts->sound = sounds[some_index];
            // For now, leave sound as-is (was read from binary)
        }

        // Track max terrain index
        if (i > this->max_terrain) {
            this->max_terrain = (short)(i + 1);
        }
        this->num_terrain = this->max_terrain;
    }
}

// ============================================================================
// load_border_types (binary path) — stub (borders are secondary)
// ============================================================================

void RGE_Map::load_border_types(RGE_Sound** sounds) {
    // Source of truth: map.cpp.decomp
    // Similar pattern to load_terrain_types but for border_types[16]

    for (int i = 15; i >= 0; i--) {
        RGE_Border_Set* bs = &this->border_types[i];

        if (bs->shape) {
            delete bs->shape;
            bs->shape = nullptr;
        }

        if (bs->loaded == '\0') {
            continue;
        }

        char filename[260];
        sprintf(filename, "%s.shp", bs->pict_name);
        bs->shape = new TShape(filename, (int)bs->resource_id);

        this->num_borders = (short)(i + 1);
    }
}

// ============================================================================
// load_terrain_types (text file path) — stub for now
// ============================================================================

void RGE_Map::load_terrain_types(char* filename, RGE_Sound** sounds) {
    // Source of truth: map.cpp.decomp (second overload)
    // Reads terrain definitions from a text file (tr_wrld.txt)
    // TODO(accuracy): implement text file parsing
    (void)filename;
    (void)sounds;
}

// ============================================================================
// load_border_types (text file path) — stub for now
// ============================================================================

void RGE_Map::load_border_types(char* filename, RGE_Sound** sounds) {
    // TODO(accuracy): implement text file parsing for borders
    (void)filename;
    (void)sounds;
}

// ============================================================================
// new_map — transliterated from map.cpp.decomp (0x00455910)
// Allocates tile grid, row offset arrays, search maps.
// ============================================================================

void RGE_Map::new_map(long width, long height) {
    if (width <= 0 || height <= 0) {
        return;
    }

    // Free existing allocations
    if (this->map) {
        // TODO(accuracy): remove all objects from player lists before freeing
        free(this->map);
    }
    if (this->search_map) {
        free(this->search_map);
    }
    if (this->map_row_offset) {
        free(this->map_row_offset);
    }
    if (this->search_map_rows) {
        free(this->search_map_rows);
    }

    // Set dimensions
    this->map_width = width;
    this->map_height = height;
    this->world_width = this->tile_width * width;
    this->world_height = this->tile_height * height;

    // Allocate tiles (each RGE_Tile is 0x18 bytes)
    this->map = (RGE_Tile*)calloc(width * height, sizeof(RGE_Tile));

    // Allocate search map (1 byte per tile)
    this->search_map = (unsigned char*)calloc(this->map_width * this->map_height, 1);

    // Allocate row offset arrays (height+1 entries, +1 for wrap-around sentinel)
    this->map_row_offset = (RGE_Tile**)calloc(this->map_height + 1, sizeof(RGE_Tile*));
    this->search_map_rows = (unsigned char**)calloc(this->map_height + 1, sizeof(unsigned char*));

    // Build row offset pointers
    for (long r = 0; r < this->map_height; r++) {
        this->map_row_offset[r] = this->map + r * this->map_width;
        this->search_map_rows[r] = this->search_map + r * this->map_width;
    }

    // Wrap-around sentinel row
    this->map_row_offset[this->map_height] = this->map;
    this->search_map_rows[this->map_height] = this->search_map;

    // Set default height = 1 on all tiles (field_0x5 = terrain_type:5 | height:3)
    // Original: (&map_row_offset[row]->field_0x5)[col_offset] & 0x1f | 0x20
    // This sets height bits to 1 (0x20 = height 1 << 5)
    for (long r = 0; r < this->map_height; r++) {
        for (long c = 0; c < this->map_width; c++) {
            RGE_Tile* tile = &this->map_row_offset[r][c];
            // Keep terrain_type (low 5 bits), set height to 1 (bits 5-7)
            // In the bitfield: terrain_type : 5, height : 3
            // height = 1 means ((tile_byte & 0x1F) | 0x20)
            // Direct bitfield access:
            tile->height = 1;
        }
    }

    // Compute screen positions for all tiles
    this->set_map_screen_pos(0, 0, (int)(this->map_width - 1), (int)(this->map_height - 1));

    // Zone map, unified vis map, unit manager — create placeholders
    // TODO(accuracy): create RGE_Zone_Map_List, RGE_Unified_Visible_Map, Visible_Unit_Manager
    // For now, leave them as whatever they were (likely null from constructor)
}

// ============================================================================
// set_map_screen_pos — transliterated from map.cpp.decomp
// Computes screen pixel positions for each tile in the given range.
// AoE1 uses diamond (isometric) projection:
//   screen_x = (col - row) * tile_half_width
//   screen_y = (col + row) * tile_half_height
// ============================================================================

void RGE_Map::set_map_screen_pos(int col0, int row0, int col1, int row1) {
    if (!this->map_row_offset) return;

    for (int r = row0; r <= row1 && r < this->map_height; r++) {
        for (int c = col0; c <= col1 && c < this->map_width; c++) {
            RGE_Tile* tile = &this->map_row_offset[r][c];
            tile->screen_xpos = (short)((c - r) * this->tile_half_width);
            tile->screen_ypos = (short)((c + r) * this->tile_half_height);
        }
    }
}

// ============================================================================
// clear_map (5-arg version) — transliterated from map.cpp.decomp (0x004558B0)
// ============================================================================

void RGE_Map::clear_map(RGE_Player* player, RGE_Game_World* world, uchar terrain, long w, long h) {
    this->new_map(w, h);
    // TODO(accuracy): RGE_Game_World::reset_object_count(world) if world != null
    // TODO(accuracy): set_terrain(player, world, 0, 0, w-1, h-1, terrain, 1, 0)
    // For now, just set all tiles to the given terrain type
    for (long r = 0; r < this->map_height; r++) {
        for (long c = 0; c < this->map_width; c++) {
            this->map_row_offset[r][c].terrain_type = terrain & 0x1F;
        }
    }
}

// ============================================================================
// clear_map (2-arg version) — transliterated from map.cpp.decomp (0x00455C20)
// ============================================================================

void RGE_Map::clear_map(uchar terrain, uchar height) {
    for (long r = 0; r < this->map_height; r++) {
        for (long c = 0; c < this->map_width; c++) {
            RGE_Tile* tile = &this->map_row_offset[r][c];
            tile->tile_type = '\0';
            tile->screen_xpos = 0;
            tile->screen_ypos = 0;
            tile->terrain_type = terrain & 0x1F;
            tile->height = height & 0x7;
            tile->border_type = 0;
            tile->border_shape = 0;
            tile->last_drawn_as = '\0';
            tile->last_drawn_shape = 0xFF;
            tile->draw_as = '\0';
            tile->draw_attribute = '\0';
            tile->last_drawn_shape2 = 0xFF;
        }
    }
    this->set_map_screen_pos(0, 0, (int)(this->map_width - 1), (int)(this->map_height - 1));
}

// ============================================================================
// Remaining stubs
// ============================================================================

void RGE_Map::set_terrain(RGE_Player* player, RGE_Game_World* world,
                          short col, short row, uchar terrain, uchar u1, uchar u2) {
    // TODO(accuracy): implement from map.cpp.decomp
    (void)player; (void)world; (void)col; (void)row; (void)terrain; (void)u1; (void)u2;
}

void RGE_Map::coordinate_map() {
    // TODO(accuracy): implement from map.cpp.decomp — recalculates borders between terrain types
}

void RGE_Map::set_map_visible(uchar flag) {
    this->map_visible_flag = flag;
}

void RGE_Map::set_map_fog(uchar flag) {
    this->fog_flag = flag;
}

void RGE_Map::request_redraw(int col0, int row0, int col1, int row1, uchar attr) {
    // TODO(accuracy): implement
    (void)col0; (void)row0; (void)col1; (void)row1; (void)attr;
}

void RGE_Map::clear_map_view_info() {
    // TODO(accuracy): implement
}

uchar RGE_Map::get_border_type(short col, short row) {
    // TODO(accuracy): implement
    (void)col; (void)row;
    return 0;
}

// ============================================================================
// Virtual method stubs — unchanged from original
// ============================================================================

void RGE_Map::data_load_random_map(int param_1) {
    // Source of truth: map.cpp.decomp (0x004557C0)
    // Creates RGE_RMM_Database_Controller from binary data
    // TODO(accuracy): implement RGE_RMM_Database_Controller
    (void)param_1;
}

void RGE_Map::load_random_map(char* param_1, char* param_2, char* param_3, char* param_4) {
    // TODO: implement (see RGE_Map.cpp.asm)
    (void)param_1; (void)param_2; (void)param_3; (void)param_4;
}

uchar RGE_Map::do_terrain_brush(long param_1, long param_2, long param_3, uchar param_4) {
    (void)param_1; (void)param_2; (void)param_3; (void)param_4;
    return 0;
}

uchar RGE_Map::do_terrain_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6) {
    (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5; (void)param_6;
    return 0;
}

uchar RGE_Map::do_elevation_brush(long param_1, long param_2, long param_3, uchar param_4) {
    (void)param_1; (void)param_2; (void)param_3; (void)param_4;
    return 0;
}

uchar RGE_Map::do_elevation_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6) {
    (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5; (void)param_6;
    return 0;
}

uchar RGE_Map::do_cliff_brush(long param_1, long param_2, uchar param_3, uchar param_4) {
    (void)param_1; (void)param_2; (void)param_3; (void)param_4;
    return 0;
}

uchar RGE_Map::do_cliff_brush_stroke(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6) {
    (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5; (void)param_6;
    return 0;
}

void RGE_Map::map_generate(RGE_Player* param_1, RGE_Game_World* param_2, RGE_Player_Info* param_3, uchar* param_4) {
    (void)param_1; (void)param_2; (void)param_3; (void)param_4;
}

void RGE_Map::map_generate2(RGE_Game_World* param_1, long param_2, long param_3, uchar param_4, long param_5) {
    (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5;
}

void RGE_Map::save(int param_1) {
    (void)param_1;
}

void RGE_Map::load_terrain_obj_types(char* param_1) {
    // TODO: implement (see RGE_Map.cpp.asm)
    (void)param_1;
}
