#include "RGE_Map.h"
#include "RGE_Base_Game.h"
#include "globals.h"
#include "TSpan_List_Manager.h"
#include "RGE_Border_Set.h"
#include "RGE_Game_World.h"
#include "RGE_RMM_Database_Controller.h"
#include "TShape.h"
#include "custom_debug.h"
#include "debug_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h> 

static void rge_map_check_for_border(RGE_Map* map, uchar terrain, uchar* neighbor) {
    if (map == nullptr || neighbor == nullptr) {
        return;
    }
    if (*neighbor == terrain) {
        return;
    }

    short border = map->terrain_types[terrain].borders[*neighbor];
    if (border == -1 || border < 0 || border > 0x0F) {
        *neighbor = terrain;
        return;
    }
    if (map->border_types[border].loaded == 0) {
        *neighbor = terrain;
    }
}

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
    if (this->map) {
        free(this->map);
        this->map = nullptr;
    }
    if (this->search_map) {
        free(this->search_map);
        this->search_map = nullptr;
    }
    if (this->map_row_offset) {
        free(this->map_row_offset);
        this->map_row_offset = nullptr;
    }
    if (this->search_map_rows) {
        free(this->search_map_rows);
        this->search_map_rows = nullptr;
    }
}

void RGE_Map::init_tile_sizes()
{
    // Source of truth: map.cpp.decomp @ 0x00455570.
    this->tile_width = 0x40;
    this->tile_height = 0x20;
    this->tile_half_width = 0x20;
    this->tile_half_height = 0x10;
    this->elev_height = 0x10;

    this->set_tile_size(0x00, 0x40, 0x20, 0);
    this->set_tile_size(0x01, this->tile_width, this->elev_height, -8);
    this->set_tile_size(0x02, this->tile_width, this->elev_height + this->tile_height, 8);
    this->set_tile_size(0x03, this->tile_width, this->tile_height, -8);
    this->set_tile_size(0x04, this->tile_width, this->tile_height, -8);
    this->set_tile_size(0x05, this->tile_width, this->elev_height, -8);
    this->set_tile_size(0x06, this->tile_width, this->elev_height + this->tile_height, 8);
    this->set_tile_size(0x07, this->tile_width, this->elev_height, -8);
    this->set_tile_size(0x08, this->tile_width, this->elev_height + this->tile_height, 8);
    this->set_tile_size(0x09, this->tile_width, this->elev_height, -8);
    this->set_tile_size(0x0A, this->tile_width, this->elev_height + this->tile_height, 8);
    this->set_tile_size(0x0B, this->tile_width, this->tile_height, -8);
    this->set_tile_size(0x0C, this->tile_width, this->tile_height, -8);
    this->set_tile_size(0x0D, this->tile_width, this->elev_height, -8);
    this->set_tile_size(0x0E, this->tile_width, this->elev_height + this->tile_height, 8);
    this->set_tile_size(0x0F, this->tile_width, this->tile_height, 8);
    this->set_tile_size(0x10, this->tile_width, this->tile_height, 8);
    this->set_tile_size(0x11, this->tile_half_width, this->tile_height, 0);
    this->set_tile_size(0x12, this->tile_half_width, this->tile_height, 0);
}

void RGE_Map::set_tile_size(uchar index, short width, short height, short y_delta)
{
    unsigned int i = (unsigned int)index;
    if (i >= 19) {
        return;
    }
    this->tilesizes[i].width = width;
    this->tilesizes[i].height = height;
    this->tilesizes[i].y_delta = y_delta;
}

void RGE_Map::new_map(long w, long h)
{
    if (w <= 0 || h <= 0) {
        return;
    }

    if (this->map != nullptr) {
        free(this->map);
        this->map = nullptr;
    }
    if (this->search_map != nullptr) {
        free(this->search_map);
        this->search_map = nullptr;
    }
    if (this->map_row_offset != nullptr) {
        free(this->map_row_offset);
        this->map_row_offset = nullptr;
    }
    if (this->search_map_rows != nullptr) {
        free(this->search_map_rows);
        this->search_map_rows = nullptr;
    }

    this->map_width = w;
    this->map_height = h;
    this->world_width = this->tile_width * w;
    this->world_height = this->tile_height * h;

    size_t tile_count = (size_t)w * (size_t)h;
    this->map = (RGE_Tile*)calloc(tile_count, sizeof(RGE_Tile));
    this->search_map = (unsigned char*)calloc(tile_count, 1);
    this->map_row_offset = (RGE_Tile**)calloc((size_t)h + 1, sizeof(RGE_Tile*));
    this->search_map_rows = (unsigned char**)calloc((size_t)h + 1, sizeof(unsigned char*));

    for (int i = 0; i < h; ++i) {
        this->map_row_offset[i] = &this->map[i * w];
        this->search_map_rows[i] = &this->search_map[i * w];
    }
    this->map_row_offset[h] = this->map;
    this->search_map_rows[h] = this->search_map;

    for (int row = 0; row < h; ++row) {
        RGE_Tile* tile = this->map_row_offset[row];
        for (int col = 0; col < w; ++col) {
            tile[col].height = 1;
        }
    }

    this->set_map_screen_pos(0, 0, w - 1, h - 1);
}

void RGE_Map::set_map_screen_pos(int col1, int row1, int col2, int row2)
{
    if (this->map == nullptr || this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    if (col1 < 0) col1 = 0;
    if (row1 < 0) row1 = 0;
    if (col2 < 0) col2 = 0;
    if (row2 < 0) row2 = 0;

    if (col1 >= this->map_width) col1 = this->map_width - 1;
    if (row1 >= this->map_height) row1 = this->map_height - 1;
    if (col2 >= this->map_width) col2 = this->map_width - 1;
    if (row2 >= this->map_height) row2 = this->map_height - 1;

    for (int row = row1; row <= row2; ++row) {
        RGE_Tile* tile = this->map_row_offset[row] + col1;
        for (int col = col1; col <= col2; ++col) {
            tile->screen_xpos = (short)((row + col) * this->tile_half_width);
            int ypos = (row - col) * this->tile_half_height - ((int)tile->height * this->elev_height);
            switch (tile->tile_type) {
                case 2:
                case 6:
                case 8:
                case 10:
                case 14:
                case 15:
                case 16:
                    ypos -= this->elev_height;
                    break;
                default:
                    break;
            }
            tile->screen_ypos = (short)ypos;
            ++tile;
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
    this->init_tile_sizes();
    
    // Source of truth: map.cpp.decomp @ 0x00455000.
    // This constructor deserializes the full map struct through rge_read.
    // Save/restore vtable because serialized bytes overwrite it.
    void* vptr = *(void**)this;

    rge_read(file_handle, this, (int)sizeof(RGE_Map));

    // Restore vtable
    *(void**)this = vptr;

    // Reset pointers that were overwritten with garbage from the file
    this->map = nullptr;
    this->map_row_offset = nullptr;
    this->search_map = nullptr;
    this->search_map_rows = nullptr;
    this->game_world = (rge_base_game != nullptr) ? rge_base_game->world : nullptr;
    this->random_map = nullptr;
    this->map_zones = nullptr;
    this->unified_vis_map = nullptr;
    this->unit_manager = nullptr;

    // load_terrain_types/load_border_types/init_tile_sizes are always called.
    this->load_terrain_types(sounds);
    this->load_border_types(sounds);
    this->init_tile_sizes();

    if (load_map) {
        this->data_load_random_map(file_handle);
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
    if (world != nullptr) {
        world->reset_object_count();
    }

    // TODO(accuracy): replace with full RGE_Map::set_terrain area write.
    this->clear_map(terrain, 1);

    if (world != nullptr) {
        world->reset_player_visible_maps();
    }
}

void RGE_Map::clear_map(uchar terrain, uchar height)
{
    if (this->map == nullptr || this->map_row_offset == nullptr) {
        return;
    }

    for (int row = 0; row < this->map_height; ++row) {
        RGE_Tile* tile = this->map_row_offset[row];
        for (int col = 0; col < this->map_width; ++col) {
            tile->tile_type = 0;
            tile->border_type = 0;
            tile->border_shape = 0;
            tile->screen_xpos = 0;
            tile->terrain_type = terrain & 0x1f;
            tile->height = height;
            tile->screen_ypos = 0;
            tile->last_drawn_as = 0;
            tile->last_drawn_shape = 0xff;
            tile->draw_as = 0;
            tile->draw_attribute = 0;
            tile->last_drawn_shape2 = 0xff;
            ++tile;
        }
    }
    this->set_map_screen_pos(0, 0, this->map_width - 1, this->map_height - 1);
}

void RGE_Map::set_terrain(RGE_Player* player, RGE_Game_World* world, short col, short row, uchar terrain, uchar unknown1, uchar unknown2)
{
    // Stub
}

void RGE_Map::load_terrain_obj_types(char* filename)
{
    // Stub
}

void RGE_Map::data_load_random_map(int param_1) {
    // Source of truth: map.cpp.decomp @ 0x004557C0.
    if (this->random_map != nullptr) {
        delete this->random_map;
        this->random_map = nullptr;
    }
    this->random_map = new RGE_RMM_Database_Controller(param_1);
}

void RGE_Map::load_random_map(char* param_1, char* param_2, char* param_3, char* param_4) {
    // Source of truth: map.cpp.decomp @ 0x00455820.
    // Constructor argument order from decomp is (param_2, param_3, param_4, param_1).
    if (this->random_map != nullptr) {
        delete this->random_map;
        this->random_map = nullptr;
    }
    this->random_map = new RGE_RMM_Database_Controller(param_2, param_3, param_4, param_1);
}
uchar RGE_Map::do_terrain_brush(long param_1, long param_2, long param_3, uchar param_4) { return 0; }
uchar RGE_Map::do_terrain_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6) { return 0; }
uchar RGE_Map::do_elevation_brush(long param_1, long param_2, long param_3, uchar param_4) { return 0; }
uchar RGE_Map::do_elevation_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6) { return 0; }
uchar RGE_Map::do_cliff_brush(long param_1, long param_2, uchar param_3, uchar param_4) { return 0; }
uchar RGE_Map::do_cliff_brush_stroke(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6) { return 0; }
void RGE_Map::map_generate(RGE_Player* param_1, RGE_Game_World* param_2, RGE_Player_Info* param_3, uchar* param_4) {}
void RGE_Map::map_generate2(RGE_Game_World* param_1, long param_2, long param_3, uchar param_4, long param_5) {
    // Source of truth: map.cpp.decomp @ 0x004578B0.
    if (this->game_world == nullptr) {
        this->game_world = param_1;
    }

    uchar old_game_state = 0;
    if (this->game_world != nullptr) {
        old_game_state = this->game_world->game_state;
        this->game_world->game_state = 3;
    }

    unsigned int seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x5ce);
    if (rge_base_game != nullptr) {
        unsigned int forced_seed = (unsigned int)rge_base_game->random_map_seed;
        if (forced_seed != 0xffffffffu) {
            seed = forced_seed;
        }
        rge_base_game->save_random_map_seed = (int)seed;
    }

    debug_srand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x5da, seed);

    long map_w = param_2;
    long map_h = param_3;
    if ((map_w <= 0 || map_h <= 0) && this->map_width > 0 && this->map_height > 0) {
        map_w = this->map_width;
        map_h = this->map_height;
    }
    if (map_w <= 0) map_w = 120;
    if (map_h <= 0) map_h = 120;

    this->clear_map((RGE_Player*)nullptr, param_1, 0, map_w, map_h);

    debug_srand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x5dd, seed);

    // TODO(accuracy): random map DB controller is still partially stubbed in this tree.
    if (this->random_map != nullptr) {
        using RMM_Generate_Fn = uchar(__thiscall*)(void*);
        using RMM_Init_Fn = uchar(__thiscall*)(void*, RGE_Map*, RGE_Game_World*, uchar, long, uchar);
        using RMM_DeInit_Fn = uchar(__thiscall*)(void*);

        void** vtable = *(void***)this->random_map;
        RMM_Init_Fn init_fn = reinterpret_cast<RMM_Init_Fn>(vtable[5]);
        RMM_Generate_Fn generate_fn = reinterpret_cast<RMM_Generate_Fn>(vtable[0]);
        RMM_DeInit_Fn de_init_fn = reinterpret_cast<RMM_DeInit_Fn>(vtable[6]);

        if (init_fn != nullptr) {
            init_fn(this->random_map, this, param_1, param_4, param_5, 1);
        }
        debug_srand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x5e0, seed);
        if (generate_fn != nullptr) {
            generate_fn(this->random_map);
        }
        if (de_init_fn != nullptr) {
            de_init_fn(this->random_map);
        }
        (void)debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x5e5);
    }

    if (this->game_world != nullptr) {
        this->game_world->game_state = old_game_state;
    }
}
void RGE_Map::save(int param_1) {}

void RGE_Map::load_terrain_types(RGE_Sound** sounds)
{
    (void)sounds;
    int terrain_count = this->num_terrain;
    if (terrain_count < 0) terrain_count = 0;
    if (terrain_count > 32) {
        CUSTOM_DEBUG_LOG_FMT("RGE_Map::load_terrain_types: clamping num_terrain %d -> 32", terrain_count);
        terrain_count = 32;
    }

    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("RGE_Map::load_terrain_types: num_terrain=%d", terrain_count);
    CUSTOM_DEBUG_END

    for (int i = 0; i < terrain_count; i++) {
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
                if (i < 5 || i == terrain_count - 1) { // Log first few and last to avoid spam
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
    (void)sounds;
    int border_count = this->num_borders;
    if (border_count < 0) border_count = 0;
    if (border_count > 16) {
        CUSTOM_DEBUG_LOG_FMT("RGE_Map::load_border_types: clamping num_borders %d -> 16", border_count);
        border_count = 16;
    }

    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("RGE_Map::load_border_types: num_borders=%d", border_count);
    CUSTOM_DEBUG_END

    for (int i = 0; i < border_count; i++) {
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
void RGE_Map::coordinate_map() {
    this->set_map_screen_pos(0, 0, this->map_width - 1, this->map_height - 1);
}
void RGE_Map::set_map_visible(uchar flag) {
    this->map_visible_flag = flag;
}
void RGE_Map::set_map_fog(uchar flag) {
    this->fog_flag = flag;
}
void RGE_Map::request_redraw(int col0, int row0, int col1, int row1, uchar attr) {}
void RGE_Map::clear_map_view_info() {
    if (this->map == nullptr || this->map_row_offset == nullptr) {
        return;
    }

    for (int row = 0; row < this->map_height; ++row) {
        RGE_Tile* tile = this->map_row_offset[row];
        for (int col = 0; col < this->map_width; ++col) {
            tile->last_drawn_as = 0;
            tile->last_drawn_shape = 0xff;
            tile->draw_as = 0;
            tile->draw_attribute = 0;
            tile->last_drawn_shape2 = 0xff;
            ++tile;
        }
    }
}

// Source of truth: map.cpp.decomp @ 0x00459D20.
uchar RGE_Map::get_tile_type(short col, short row) {
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }
    if (col < 0 || row < 0 || col >= this->map_width || row >= this->map_height) {
        return 0;
    }

    const int map_w = this->map_width;
    const int map_h = this->map_height;
    const int x = (int)col;
    const int y = (int)row;

    RGE_Tile** rows = this->map_row_offset;
    RGE_Tile* cur_row = rows[y];

    ushort ech = (ushort)cur_row[x].height;
    ushort up = (ushort)(ech + 1);
    ushort down = (ushort)(ech - 1);

    ushort etr = ech;
    if (row > 0 && x < map_w - 1) {
        etr = (ushort)rows[y - 1][x + 1].height;
    }

    ushort et = ech;
    if (row > 0) {
        et = (ushort)rows[y - 1][x].height;
    }

    ushort er = ech;
    if (x < map_w - 1) {
        er = (ushort)cur_row[x + 1].height;
    }

    ushort ebl = ech;
    if (col > 0 && y < map_h - 1) {
        ebl = (ushort)rows[y + 1][x - 1].height;
    }

    ushort el = ech;
    if (col > 0) {
        el = (ushort)cur_row[x - 1].height;
    }

    ushort eb = ech;
    if (y < map_h - 1) {
        eb = (ushort)rows[y + 1][x].height;
    }

    ushort etl = ech;
    if (row > 0 && col > 0) {
        etl = (ushort)rows[y - 1][x - 1].height;
    }

    ushort ebr = ech;
    if (y < map_h - 1 && x < map_w - 1) {
        ebr = (ushort)rows[y + 1][x + 1].height;
    }

    if (et == up && er == up) return 0x0E;
    if (el == up && eb == up) return 0x0D;
    if (et == up && el == up) return 0x10;
    if (er == up && eb == up) return 0x0F;

    if (et == up) return 0x06;
    if (er == up) return 0x08;
    if (el == up) return 0x05;
    if (eb == up) return 0x07;

    if (etr == up) {
        if (el == down && eb == down) return 0x02;
        return 0x0A;
    }
    if (ebl == up) {
        if (et == down && er == down) return 0x01;
        return 0x09;
    }
    if (etl == up) {
        if (er == down && eb == down) return 0x03;
        return 0x0B;
    }
    if (ebr == up) {
        if (et == down && el == down) return 0x04;
        return 0x0C;
    }

    return 0;
}

void RGE_Map::rebuild_tile_types(short col0, short row0, short col1, short row1) {
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    int x0 = (int)col0;
    int y0 = (int)row0;
    int x1 = (int)col1;
    int y1 = (int)row1;
    if (x0 > x1) {
        int t = x0;
        x0 = x1;
        x1 = t;
    }
    if (y0 > y1) {
        int t = y0;
        y0 = y1;
        y1 = t;
    }
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= this->map_width) x1 = this->map_width - 1;
    if (y1 >= this->map_height) y1 = this->map_height - 1;
    if (x0 > x1 || y0 > y1) {
        return;
    }

    for (int y = y0; y <= y1; ++y) {
        for (int x = x0; x <= x1; ++x) {
            this->map_row_offset[y][x].tile_type = this->get_tile_type((short)x, (short)y);
        }
    }
}

uchar RGE_Map::get_border_type(short col, short row) {
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }
    if (col < 0 || row < 0 || col >= this->map_width || row >= this->map_height) {
        return 0;
    }

    const int x = (int)col;
    const int y = (int)row;
    const int max_x = this->map_width - 1;
    const int max_y = this->map_height - 1;

    RGE_Tile* tile = &this->map_row_offset[y][x];
    uchar cur_terrain = (uchar)(tile->terrain_type & 0x1F);

    uchar n_top = cur_terrain;
    if (row > 0) {
        n_top = (uchar)(this->map_row_offset[y - 1][x].terrain_type & 0x1F);
    }

    uchar n_bottom = cur_terrain;
    if (y < max_y) {
        n_bottom = (uchar)(this->map_row_offset[y + 1][x].terrain_type & 0x1F);
    }

    uchar n_left = cur_terrain;
    if (col > 0) {
        n_left = (uchar)(this->map_row_offset[y][x - 1].terrain_type & 0x1F);
    }

    uchar n_right = cur_terrain;
    if (x < max_x) {
        n_right = (uchar)(this->map_row_offset[y][x + 1].terrain_type & 0x1F);
    }

    uchar n_top_left = cur_terrain;
    if (row > 0 && col > 0) {
        n_top_left = (uchar)(this->map_row_offset[y - 1][x - 1].terrain_type & 0x1F);
    }

    uchar n_top_right = cur_terrain;
    if (row > 0 && x < max_x) {
        n_top_right = (uchar)(this->map_row_offset[y - 1][x + 1].terrain_type & 0x1F);
    }

    uchar n_bottom_left = cur_terrain;
    if (y < max_y && col > 0) {
        n_bottom_left = (uchar)(this->map_row_offset[y + 1][x - 1].terrain_type & 0x1F);
    }

    uchar n_bottom_right = cur_terrain;
    if (y < max_y && x < max_x) {
        n_bottom_right = (uchar)(this->map_row_offset[y + 1][x + 1].terrain_type & 0x1F);
    }

    rge_map_check_for_border(this, cur_terrain, &n_top);
    rge_map_check_for_border(this, cur_terrain, &n_bottom);
    rge_map_check_for_border(this, cur_terrain, &n_left);
    rge_map_check_for_border(this, cur_terrain, &n_right);
    rge_map_check_for_border(this, cur_terrain, &n_top_left);
    rge_map_check_for_border(this, cur_terrain, &n_top_right);
    rge_map_check_for_border(this, cur_terrain, &n_bottom_left);
    rge_map_check_for_border(this, cur_terrain, &n_bottom_right);

    uchar diff = n_top;
    if ((n_top != cur_terrain) ||
        ((diff = n_bottom), n_bottom != cur_terrain) ||
        ((diff = n_left), n_left != cur_terrain) ||
        ((diff = n_right), n_right != cur_terrain) ||
        ((diff = n_top_left), n_top_left != cur_terrain) ||
        ((diff = n_top_right), n_top_right != cur_terrain) ||
        ((diff = n_bottom_left), n_bottom_left != cur_terrain) ||
        ((diff = n_bottom_right), n_bottom_right != cur_terrain)) {
        short border = this->terrain_types[cur_terrain].borders[diff];
        if (border == -1 || border < 0 || border > 0x0F || this->border_types[border].loaded == 0) {
            tile->border_type = 0;
            tile->border_shape = 0;
            return 0;
        }

        uchar shape = 0;
        if (this->border_types[border].border_style == 1) {
            if (this->terrain_types[cur_terrain].borders[n_top] == border) shape += 1;
            if (this->terrain_types[cur_terrain].borders[n_bottom] == border) shape += 2;
            if (this->terrain_types[cur_terrain].borders[n_left] == border) shape += 4;
            if (this->terrain_types[cur_terrain].borders[n_right] == border) shape += 8;

            tile->border_type = (uchar)(border & 0x0F);
            tile->border_shape = (uchar)(shape & 0x0F);
            return (uchar)(tile->border_type | (tile->border_shape << 4));
        }

        short b_top = this->terrain_types[cur_terrain].borders[n_top];
        short b_bottom = this->terrain_types[cur_terrain].borders[n_bottom];
        short b_left = this->terrain_types[cur_terrain].borders[n_left];
        short b_right = this->terrain_types[cur_terrain].borders[n_right];
        short b_top_left = this->terrain_types[cur_terrain].borders[n_top_left];
        short b_top_right = this->terrain_types[cur_terrain].borders[n_top_right];
        short b_bottom_left = this->terrain_types[cur_terrain].borders[n_bottom_left];
        short b_bottom_right = this->terrain_types[cur_terrain].borders[n_bottom_right];

        if (b_top == border && b_left == border) {
            shape = 1;
        } else if (b_top == border && b_right == border) {
            shape = 2;
        } else {
            if (b_bottom == border) {
                if (b_left == border) {
                    shape = 3;
                    tile->border_type = (uchar)(border & 0x0F);
                    tile->border_shape = (uchar)(shape & 0x0F);
                    return (uchar)(tile->border_type | (tile->border_shape << 4));
                }
                if (b_right == border) {
                    shape = 4;
                    tile->border_type = (uchar)(border & 0x0F);
                    tile->border_shape = (uchar)(shape & 0x0F);
                    return (uchar)(tile->border_type | (tile->border_shape << 4));
                }
            }

            if (b_top == border) {
                shape = 9;
            } else if (b_bottom == border) {
                shape = 10;
            } else if (b_left == border) {
                shape = 11;
            } else if (b_right == border) {
                shape = 12;
            } else if (b_top_left == border) {
                shape = 5;
            } else if (b_top_right == border) {
                shape = 6;
            } else if (b_bottom_left == border) {
                shape = 7;
            } else if (b_bottom_right == border) {
                shape = 8;
            } else {
                tile->border_type = 0;
                tile->border_shape = 0;
                return 0;
            }
        }

        tile->border_type = (uchar)(border & 0x0F);
        tile->border_shape = (uchar)(shape & 0x0F);
        return (uchar)(tile->border_type | (tile->border_shape << 4));
    }

    tile->border_type = 0;
    tile->border_shape = 0;
    return 0;
}

void RGE_Map::rebuild_border_types(short col0, short row0, short col1, short row1) {
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    int x0 = (int)col0;
    int y0 = (int)row0;
    int x1 = (int)col1;
    int y1 = (int)row1;
    if (x0 > x1) {
        int t = x0;
        x0 = x1;
        x1 = t;
    }
    if (y0 > y1) {
        int t = y0;
        y0 = y1;
        y1 = t;
    }
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= this->map_width) x1 = this->map_width - 1;
    if (y1 >= this->map_height) y1 = this->map_height - 1;
    if (x0 > x1 || y0 > y1) {
        return;
    }

    for (int y = y0; y <= y1; ++y) {
        for (int x = x0; x <= x1; ++x) {
            this->get_border_type((short)x, (short)y);
        }
    }
}
