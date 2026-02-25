#include "RGE_Map.h"
#include "RGE_Base_Game.h"
#include "globals.h"
#include "TSpan_List_Manager.h"
#include "RGE_Border_Set.h"
#include "RGE_Game_World.h"
#include "RGE_Player.h"
#include "RGE_Static_Object.h"
#include "RGE_Master_Static_Object.h"
#include "RGE_Object_Node.h"
#include "RGE_RMM_Database_Controller.h"
#include "RGE_Zone_Map_List.h"
#include "RGE_Unified_Visible_Map.h"
#include "TShape.h"
#include "custom_debug.h"
#include "debug_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h> 
#include <stdint.h>
#include <math.h>
#include <new>

static void rge_convert_us(char* text) {
    if (text == nullptr) {
        return;
    }
    while (*text != '\0') {
        if (*text == '_') {
            *text = ' ';
        }
        ++text;
    }
}

static void rge_copy_fixed_text(char* dst, size_t dst_size, const char* src) {
    if (dst == nullptr || dst_size == 0) {
        return;
    }
    if (src == nullptr) {
        dst[0] = '\0';
        return;
    }
    strncpy(dst, src, dst_size - 1);
    dst[dst_size - 1] = '\0';
}

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

static void rge_map_remove_tile_node(RGE_Tile* tile, RGE_Static_Object* obj) {
    if (tile == nullptr || obj == nullptr) {
        return;
    }

    RGE_Object_Node* node = tile->objects.list;
    while (node != nullptr && node->node != obj) {
        node = node->next;
    }

    if (node == nullptr) {
        return;
    }

    if (node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        tile->objects.list = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }

    if (tile->objects.number_of_objects > 0) {
        tile->objects.number_of_objects = (short)(tile->objects.number_of_objects - 1);
    }

    free(node);
}

static void rge_map_delete_object_now(RGE_Static_Object* obj) {
    if (obj == nullptr) {
        return;
    }

    RGE_Player* owner = obj->owner;
    RGE_Tile* tile = obj->tile;

    if (owner != nullptr) {
        owner->removeObject(obj, (int)obj->sleep_flag, (int)obj->dopple_flag, obj->player_object_node);
    }

    rge_map_remove_tile_node(tile, obj);
    obj->player_object_node = nullptr;
    obj->tile = nullptr;
    delete obj;
}

static uchar rge_tile_pack_terrain_height(const RGE_Tile* tile) {
    return (uchar)((tile->terrain_type & 0x1f) | ((tile->height & 7) << 5));
}

static void rge_tile_set_packed_terrain_height(RGE_Tile* tile, uchar packed) {
    tile->terrain_type = (uchar)(packed & 0x1f);
    tile->height = (uchar)((packed >> 5) & 7);
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

    // Source of truth: map.cpp.decomp new_map() constructs fresh zone maps + unified vis map.
    // Required for doppleganger checks (unified_map_offsets) during New Game random map generation.
    if (this->map_zones != nullptr) {
        delete this->map_zones;
        this->map_zones = nullptr;
    }
    this->map_zones = new (std::nothrow) RGE_Zone_Map_List(this);

    if (this->unified_vis_map != nullptr) {
        if (this->unified_vis_map->UnifiedVisibleMap != nullptr) {
            free(this->unified_vis_map->UnifiedVisibleMap);
            this->unified_vis_map->UnifiedVisibleMap = nullptr;
        }
        free(this->unified_vis_map);
        this->unified_vis_map = nullptr;
    }

    this->unified_vis_map = (RGE_Unified_Visible_Map*)calloc(1, sizeof(RGE_Unified_Visible_Map));
    if (this->unified_vis_map != nullptr) {
        this->unified_vis_map->mapWidth = (int)w;
        this->unified_vis_map->mapHeight = (int)h;
        this->unified_vis_map->UnifiedVisibleMap =
            (ulong*)calloc((size_t)w * (size_t)h, sizeof(ulong));
        this->unified_vis_map->Set_Map_Offsets();
    }
}

void RGE_Map::load_map(int param_1) {
    // Fully verified. Source of truth: map.cpp.decomp @ 0x004579C0 (audited vs map.cpp.asm).
    long width = 0;
    long height = 0;
    rge_read(param_1, &width, 4);
    rge_read(param_1, &height, 4);

    this->new_map(width, height);

    if (this->map_zones != nullptr) {
        delete this->map_zones;
        this->map_zones = nullptr;
    }
    this->map_zones = new (std::nothrow) RGE_Zone_Map_List(param_1, this);

    rge_read(param_1, &this->map_visible_flag, 1);
    rge_read(param_1, &this->fog_flag, 1);

    if (save_game_version < 7.0f) {
        const int tile_bytes = (int)(this->map_width * this->map_height * (long)sizeof(RGE_Tile));
        if (this->map != nullptr && tile_bytes > 0) {
            rge_read(param_1, this->map, tile_bytes);

            // Clear pointer-backed tile list state (saved pointers aren't valid after load).
            for (int y = 0; y < this->map_height; ++y) {
                for (int x = 0; x < this->map_width; ++x) {
                    RGE_Tile* t = &this->map_row_offset[y][x];
                    t->objects.list = nullptr;
                    t->objects.number_of_objects = 0;
                }
            }
        }
    } else {
        for (int y = 0; y < this->map_height; ++y) {
            RGE_Tile* row = this->map_row_offset[y];
            for (int x = 0; x < this->map_width; ++x) {
                RGE_Tile* t = &row[x];
                rge_read(param_1, &t->screen_xpos, 2);
                rge_read(param_1, &t->screen_ypos, 2);
                rge_read(param_1, &t->tile_type, 1);

                uchar tmp = 0;
                rge_read(param_1, &tmp, 1);
                t->terrain_type = tmp & 0x1F;
                rge_read(param_1, &tmp, 1);
                t->height = tmp & 0x07;
                rge_read(param_1, &tmp, 1);
                t->border_type = tmp & 0x0F;
                rge_read(param_1, &tmp, 1);
                t->border_shape = tmp & 0x0F;

                t->last_drawn_as = '\0';
                t->last_drawn_shape = 0xFF;
                t->objects.list = nullptr;
                t->objects.number_of_objects = 0;
                t->draw_as = '\0';
                t->draw_attribute = '\0';
                t->last_drawn_shape2 = 0xFF;
            }
        }
    }

    int created_unified = 0;
    if (this->unified_vis_map == nullptr) {
        this->unified_vis_map = (RGE_Unified_Visible_Map*)calloc(1, sizeof(RGE_Unified_Visible_Map));
        created_unified = 1;
    }
    if (this->unified_vis_map != nullptr) {
        this->unified_vis_map->load(param_1);
        // Source of truth: offsets must reflect the loaded UnifiedVisibleMap regardless of allocation path.
        Map_Update_Suppresion = 0;
        this->unified_vis_map->Set_Map_Offsets();
    }
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

RGE_Map::RGE_Map(char* border_file, char* terrain_file, char* terrain_obj_file, short tile_w, short tile_h, short elev_h, RGE_Sound** sounds)
{
    this->random_map = nullptr;
    this->game_world = (rge_base_game != nullptr) ? rge_base_game->world : nullptr;
    this->tile_width = tile_w;
    this->tile_half_width = (short)(tile_w / 2);
    this->tile_height = tile_h;
    this->tile_half_height = (short)(tile_h / 2);
    this->elev_height = elev_h;
    this->map_width = 0;
    this->map_height = 0;
    this->world_width = 0;
    this->world_height = 0;

    // Source of truth: map.cpp.decomp @ 0x004550A0.
    this->set_tile_size(0x00, tile_w, tile_h, 0);
    this->set_tile_size(0x01, this->tile_width, this->elev_height, -100);
    this->set_tile_size(0x02, this->tile_width, (short)(this->elev_height + this->tile_height), 100);
    this->set_tile_size(0x03, this->tile_width, this->tile_height, -100);
    this->set_tile_size(0x04, this->tile_width, this->tile_height, -100);
    this->set_tile_size(0x05, this->tile_width, this->elev_height, -100);
    this->set_tile_size(0x06, this->tile_width, (short)(this->elev_height + this->tile_height), 100);
    this->set_tile_size(0x07, this->tile_width, this->elev_height, -100);
    this->set_tile_size(0x08, this->tile_width, (short)(this->elev_height + this->tile_height), 100);
    this->set_tile_size(0x09, this->tile_width, this->elev_height, -100);
    this->set_tile_size(0x0A, this->tile_width, (short)(this->elev_height + this->tile_height), 100);
    this->set_tile_size(0x0B, this->tile_width, this->tile_height, -100);
    this->set_tile_size(0x0C, this->tile_width, this->tile_height, -100);
    this->set_tile_size(0x0D, this->tile_width, this->elev_height, -100);
    this->set_tile_size(0x0E, this->tile_width, (short)(this->elev_height + this->tile_height), 100);
    this->set_tile_size(0x0F, this->tile_width, this->tile_height, 100);
    this->set_tile_size(0x10, this->tile_width, this->tile_height, 100);
    this->set_tile_size(0x11, this->tile_half_width, this->tile_height, 0);
    this->set_tile_size(0x12, this->tile_half_width, this->tile_height, 0);

    this->cur_row = 0;
    this->cur_col = 0;
    this->num_terrain = 0;
    this->max_terrain = 0;
    this->block_beg_row = 0;
    this->block_end_row = 0;
    this->block_beg_col = 0;
    this->block_end_col = 0;
    this->any_frame_change = 0;
    this->map_visible_flag = 0;
    this->fog_flag = 1;

    memset(this->terrain_types, 0, sizeof(this->terrain_types));
    memset(this->border_types, 0, sizeof(this->border_types));

    // Source of truth: map.cpp.decomp @ 0x004550A0
    // load_terrain_types(param_2), load_border_types(param_1)
    (void)terrain_obj_file;
    this->load_terrain_types(terrain_file, sounds);
    this->load_border_types(border_file, sounds);

    this->map = nullptr;
    this->search_map = nullptr;
    this->map_row_offset = nullptr;
    this->search_map_rows = nullptr;
    this->unified_vis_map = nullptr;
    this->unit_manager = nullptr;
    this->map_zones = nullptr;
}

void RGE_Map::clear_map(RGE_Player* player, RGE_Game_World* world, uchar terrain, long w, long h)
{
    this->new_map(w, h);
    if (world != nullptr) {
        world->reset_object_count();
    }

    this->set_terrain(player, world, 0, 0, (short)(w - 1), (short)(h - 1), terrain, 1, 0);

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
    (void)player;
    this->set_terrain(world, col, row, terrain, (int)unknown1, (int)unknown2);
}

void RGE_Map::set_terrain(RGE_Game_World* world, short col, short row, uchar terrain, int param_6, int param_7) {
    if (this->map_row_offset == nullptr || col < 0 || row < 0 || col >= this->map_width || row >= this->map_height) {
        return;
    }

    RGE_Player* gaia = nullptr;
    if (world != nullptr && world->players != nullptr) {
        gaia = world->players[0];
    }

    RGE_Player* current_player = nullptr;
    if (this->game_world != nullptr && this->game_world->players != nullptr &&
        this->game_world->curr_player >= 0 && this->game_world->curr_player < this->game_world->player_num) {
        current_player = this->game_world->players[this->game_world->curr_player];
    }

    RGE_Tile* tile = &this->map_row_offset[(int)row][(int)col];
    uchar old_terrain = (uchar)(tile->terrain_type & 0x1f);

    if (old_terrain != (terrain & 0x1f)) {
        tile->terrain_type = (terrain & 0x1f);
        if (gaia != nullptr) {
            this->request_redraw((int)col, (int)row, (int)col, (int)row, 0);
            if (world != nullptr && world->game_state != '\x03' && current_player != nullptr) {
                current_player->diam_tile_list.add_node((int)col, (int)row);
            }
            int cleared_id = this->clear_terrain_object(world, row, col, (short)old_terrain, 1, param_6, param_7);
            this->place_terrain_object(gaia, world, row, col, cleared_id, 0);
            this->get_border_type(col, row);
            return;
        }
    }

    this->get_border_type(col, row);
}

void RGE_Map::set_terrain_absolute(RGE_Game_World* world, short col, short row, uchar terrain, int param_6, int param_7) {
    if (this->map_row_offset == nullptr || col < 0 || row < 0 || col >= this->map_width || row >= this->map_height) {
        return;
    }

    RGE_Player* gaia = nullptr;
    if (world != nullptr && world->players != nullptr) {
        gaia = world->players[0];
    }

    RGE_Tile* tile = &this->map_row_offset[(int)row][(int)col];
    tile->terrain_type = (terrain & 0x1f);

    if (gaia != nullptr) {
        int cleared_id = this->clear_terrain_object(world, row, col, -1, 1, param_6, param_7);
        this->place_terrain_object(gaia, world, row, col, cleared_id, 1);
    }

    this->get_border_type(col, row);
}

void RGE_Map::set_terrain(RGE_Player* player, RGE_Game_World* world, short col0, short row0, short col1, short row1, uchar terrain, uchar apply_terrain, int object_behavior) {
    if (terrain >= this->num_terrain) {
        return;
    }

    unsigned int terrain_idx = (unsigned int)terrain;
    if (this->terrain_types[terrain_idx].loaded == 0) {
        short draw_terrain = this->terrain_types[terrain_idx].terrain_to_draw;
        if (draw_terrain < 0 || draw_terrain >= this->num_terrain || this->terrain_types[(unsigned int)draw_terrain].loaded != '\x01') {
            return;
        }
    }

    short min_row = row0;
    short max_row = row1;
    if (row1 < row0) {
        min_row = row1;
        max_row = row0;
    }

    short min_col = col0;
    short max_col = col1;
    if (col1 < col0) {
        min_col = col1;
        max_col = col0;
    }

    if (min_row < 0) {
        min_row = 0;
    }
    if (max_row >= this->map_height) {
        max_row = (short)(this->map_height - 1);
    }
    if (min_col < 0) {
        min_col = 0;
    }
    if (max_col >= this->map_width) {
        max_col = (short)(this->map_width - 1);
    }

    if ((apply_terrain != 0 || player != nullptr) && min_row <= max_row) {
        for (short row = min_row; row <= max_row; ++row) {
            if (min_col <= max_col) {
                RGE_Tile* tile = this->map_row_offset[(int)row] + (int)min_col;
                for (short col = min_col; col <= max_col; ++col) {
                    if (this->terrain_types[terrain_idx].tiles[(int)tile->tile_type].count > 0) {
                        uchar old_terrain = (uchar)(tile->terrain_type & 0x1f);
                        if (old_terrain != (terrain & 0x1f) && apply_terrain != 0) {
                            tile->terrain_type = (terrain & 0x1f);
                        }
                        if (player != nullptr) {
                            this->create_terrain_object(player, world, row, col, (short)old_terrain, object_behavior, -1, -1);
                        }
                    }
                    ++tile;
                }
            }
        }
    }

    if (min_row > 0) {
        min_row = (short)(min_row - 1);
    }
    if (max_row < this->map_height - 1) {
        max_row = (short)(max_row + 1);
    }
    if (min_col > 0) {
        min_col = (short)(min_col - 1);
    }
    if (max_col < this->map_width - 1) {
        max_col = (short)(max_col + 1);
    }

    for (short row = min_row; row <= max_row; ++row) {
        for (short col = min_col; col <= max_col; ++col) {
            this->get_border_type(col, row);
        }
    }

    this->request_redraw((int)min_col, (int)min_row, (int)max_col, (int)max_row, 0);
}

uchar RGE_Map::postclean_elevation(long param_1, long param_2, long param_3, long param_4, uchar param_5) {
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }

    if (param_1 > 0) param_1 = param_1 - 1;
    if (param_2 > 0) param_2 = param_2 - 1;
    if (param_3 < this->map_width - 1) param_3 = param_3 + 1;
    if (param_4 < this->map_height - 1) param_4 = param_4 + 1;

    uchar was_bad = 0;
    const short stride = (short)this->map_width;
    const short off_ul = (short)(-1 - stride);
    const short off_u = (short)(-stride);
    const short off_ur = (short)(1 - stride);
    const short off_l = -1;
    const short off_r = 1;
    const short off_dl = (short)(stride - 1);
    const short off_d = stride;
    const short off_dr = (short)(stride + 1);

    for (long y = param_2; y <= param_4; ++y) {
        RGE_Tile* tile = this->map_row_offset[y] + param_1;
        for (long x = param_1; x <= param_3; ++x) {
            uchar cur_h = tile->height;
            int next_h = (int)cur_h;
            bool bad = false;

            if (cur_h < param_5) {
                next_h = (int)cur_h + 1;
                if (y > 0 && next_h < (int)tile[off_u].height) bad = true;
                if (y < this->map_height - 1 && next_h < (int)tile[off_d].height) bad = true;
                if (x > 0 && next_h < (int)tile[off_l].height) bad = true;
                if (x < this->map_width - 1 && next_h < (int)tile[off_r].height) bad = true;
                if (y > 0 && x > 0 && next_h < (int)tile[off_ul].height) bad = true;
                if (y > 0 && x < this->map_width - 1 && next_h < (int)tile[off_ur].height) bad = true;
                if (y < this->map_height - 1 && x > 0 && next_h < (int)tile[off_dl].height) bad = true;
                if (y < this->map_height - 1 && x < this->map_width - 1 && next_h < (int)tile[off_dr].height) bad = true;
            } else if (param_5 < cur_h) {
                next_h = (int)cur_h - 1;
                if (y > 0 && (int)tile[off_u].height < next_h) bad = true;
                if (y < this->map_height - 1 && (int)tile[off_d].height < next_h) bad = true;
                if (x > 0 && (int)tile[off_l].height < next_h) bad = true;
                if (x < this->map_width - 1 && (int)tile[off_r].height < next_h) bad = true;
                if (y > 0 && x > 0 && (int)tile[off_ul].height < next_h) bad = true;
                if (y > 0 && x < this->map_width - 1 && (int)tile[off_ur].height < next_h) bad = true;
                if (y < this->map_height - 1 && x > 0 && (int)tile[off_dl].height < next_h) bad = true;
                if (y < this->map_height - 1 && x < this->map_width - 1 && (int)tile[off_dr].height < next_h) bad = true;
            }

            if (bad) {
                uchar packed = (uchar)((next_h << 5) | (tile->terrain_type & 0x1f));
                rge_tile_set_packed_terrain_height(tile, packed);
                was_bad = 1;
            }

            ++tile;
        }
    }

    return was_bad;
}

void RGE_Map::preclean_elevation(long param_1, long param_2, long param_3, long param_4, uchar param_5) {
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    const short stride = (short)this->map_width;
    const short off_ul = (short)(-1 - stride);
    const short off_u = (short)(-stride);
    const short off_ur = (short)(1 - stride);
    const short off_l = -1;
    const short off_r = 1;
    const short off_dl = (short)(stride - 1);
    const short off_d = stride;
    const short off_dr = (short)(stride + 1);

    long left = param_1;
    long row_base = left * 0x18;
    for (;;) {
        bool changed = false;
        if (left > 0) {
            left = left - 1;
            row_base = row_base - 0x18;
            param_1 = left;
        }
        if (param_2 > 0) param_2 = param_2 - 1;
        if (param_3 < this->map_width - 1) param_3 = param_3 + 1;
        if (param_4 < this->map_height - 1) param_4 = param_4 + 1;

        for (long y = param_2; y <= param_4; ++y) {
            RGE_Tile* tile = this->map_row_offset[y] + left;
            for (long x = left; x <= param_3; ++x) {
                uchar h = tile->height;
                bool up_left = false;
                bool up = false;
                bool up_right = false;
                bool right = false;
                bool down_right = false;
                bool down = false;
                bool down_left = false;
                bool left_n = false;

                if (y > 0) up = h < tile[off_u].height;
                if (y < this->map_height - 1) down = h < tile[off_d].height;
                if (x > 0) left_n = h < tile[off_l].height;
                if (x < this->map_width - 1) right = h < tile[off_r].height;
                if (y > 0) {
                    if (x > 0) up_left = h < tile[off_ul].height;
                    if (x < this->map_width - 1) up_right = h < tile[off_ur].height;
                }
                if (y < this->map_height - 1) {
                    if (x > 0) down_left = h < tile[off_dl].height;
                    if (x < this->map_width - 1) down_right = h < tile[off_dr].height;
                }

                bool join = false;
                if ((up && down) || (right && left_n)) {
                    join = true;
                }
                if (join) {
                    if (h < param_5) {
                        uchar packed = (uchar)(((h + 1) << 5) | (tile->terrain_type & 0x1f));
                        rge_tile_set_packed_terrain_height(tile, packed);
                    } else {
                        if (up_left) tile[off_ul].height = h;
                        if (up) tile[off_u].height = h;
                        if (up_right) tile[off_ur].height = h;
                        if (right) tile[off_r].height = h;
                        if (down_right) tile[off_dr].height = h;
                        if (down) tile[off_d].height = h;
                        if (down_left) tile[off_dl].height = h;
                        if (left_n) tile[off_l].height = h;
                    }
                    changed = true;
                }
                ++tile;
            }
        }

        (void)row_base;
        if (!changed) {
            break;
        }
    }
}

void RGE_Map::clean_elevation(long param_1, long param_2, long param_3, long param_4, uchar param_5) {
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    const short stride = (short)this->map_width;
    const short off_ul = (short)(-1 - stride);
    const short off_u = (short)(-stride);
    const short off_ur = (short)(1 - stride);
    const short off_l = -1;
    const short off_r = 1;
    const short off_dl = (short)(stride - 1);
    const short off_d = stride;
    const short off_dr = (short)(stride + 1);

    if (param_1 < 0) param_1 = 0;
    if (param_2 < 0) param_2 = 0;
    if (param_3 >= this->map_width) param_3 = this->map_width - 1;
    if (param_4 >= this->map_height) param_4 = this->map_height - 1;

    for (;;) {
        param_1 = param_1 - 2;
        param_2 = param_2 - 2;
        param_3 = param_3 + 2;
        param_4 = param_4 + 2;
        bool changed = false;

        if (param_1 < 0) param_1 = 0;
        if (param_2 < 0) param_2 = 0;
        if (param_3 >= this->map_width) param_3 = this->map_width - 1;
        if (param_4 >= this->map_height) param_4 = this->map_height - 1;

        this->preclean_elevation(param_1, param_2, param_3, param_4, param_5);

        for (long y = param_2; y <= param_4; ++y) {
            RGE_Tile* tile = this->map_row_offset[y] + param_1;
            for (long x = param_1; x <= param_3; ++x) {
                bool up_left = false;
                uchar h = tile->height;
                bool up = false;
                bool up_right = false;
                bool right = false;
                bool down_right = false;
                bool down = false;
                bool down_left = false;
                bool left_n = false;

                if (y > 0 && h < tile[off_u].height) up = true;
                if (y < this->map_height - 1 && h < tile[off_d].height) down = true;
                if (x > 0 && h < tile[off_l].height) left_n = true;
                if (x < this->map_width - 1 && h < tile[off_r].height) right = true;
                if (y > 0) {
                    if (x > 0 && h < tile[off_ul].height) up_left = true;
                    if (x < this->map_width - 1 && h < tile[off_ur].height) up_right = true;
                }
                if (y < this->map_height - 1) {
                    if (x > 0 && h < tile[off_dl].height) down_left = true;
                    if (x < this->map_width - 1 && h < tile[off_dr].height) down_right = true;
                }

                bool bad = false;
                if (up_left) {
                    if (((up_right && !up) || (right && !up_right) || (down_left && !left_n) || (down && !down_left))) {
                        bad = true;
                    } else if (down_right && !down && !right) {
                        bad = true;
                    }
                }
                if (up_right && !bad) {
                    if ((down_right && !right) || (down && !down_right) || (up_left && !up) ||
                        (left_n && !up_left) || (down_left && !left_n && !down)) {
                        bad = true;
                    }
                }
                if (down_right && !bad) {
                    if ((down_left && !down) || (left_n && !down_left) || (up_right && !right) ||
                        (up && !up_right) || (up_left && !up && !left_n)) {
                        bad = true;
                    }
                }

                if (down_left) {
                    if (!bad) {
                        if ((up_left && !left_n) || (up && !up_left) || (down_right && !down) ||
                            (right && !down_right) || (up_right && !right && !up)) {
                            bad = true;
                        }
                        if (!bad) {
                            ++tile;
                            continue;
                        }
                    }

                    if (h < param_5) {
                        uchar packed = (uchar)(((h + 1) << 5) | (tile->terrain_type & 0x1f));
                        rge_tile_set_packed_terrain_height(tile, packed);
                    } else {
                        if (up_left) tile[off_ul].height = h;
                        if (up) tile[off_u].height = h;
                        if (up_right) tile[off_ur].height = h;
                        if (right) tile[off_r].height = h;
                        if (down_right) tile[off_dr].height = h;
                        if (down) tile[off_d].height = h;
                        if (down_left) tile[off_dl].height = h;
                        if (left_n) tile[off_l].height = h;
                    }
                    changed = true;
                } else if (bad) {
                    if (h < param_5) {
                        uchar packed = (uchar)(((h + 1) << 5) | (tile->terrain_type & 0x1f));
                        rge_tile_set_packed_terrain_height(tile, packed);
                    } else {
                        if (up_left) tile[off_ul].height = h;
                        if (up) tile[off_u].height = h;
                        if (up_right) tile[off_ur].height = h;
                        if (right) tile[off_r].height = h;
                        if (down_right) tile[off_dr].height = h;
                        if (down) tile[off_d].height = h;
                        if (down_left) tile[off_dl].height = h;
                        if (left_n) tile[off_l].height = h;
                    }
                    changed = true;
                }

                ++tile;
            }
        }

        if (this->postclean_elevation(param_1, param_2, param_3, param_4, param_5) != 0) {
            changed = true;
        }

        if (!changed) {
            this->set_elev((short)param_1, (short)param_2, (short)param_3, (short)param_4, 0, 0, 0);
            return;
        }
    }
}

void RGE_Map::set_elev(
    short param_1,
    short param_2,
    short param_3,
    short param_4,
    uchar param_5,
    short param_6,
    uchar param_7) {
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    RGE_Player* cur_player = nullptr;
    if (this->game_world != nullptr && this->game_world->players != nullptr) {
        short idx = this->game_world->curr_player;
        if (idx >= 0 && idx < this->game_world->player_num) {
            cur_player = this->game_world->players[idx];
        }
    }

    short min_row = param_2;
    short max_row = param_4;
    if (param_4 < param_2) {
        min_row = param_4;
        max_row = param_2;
    }
    short min_col = param_1;
    short max_col = param_3;
    if (param_3 < param_1) {
        min_col = param_3;
        max_col = param_1;
    }

    if (min_row < 0) min_row = 0;
    if (max_row >= this->map_height) max_row = (short)(this->map_height - 1);
    if (min_col < 0) min_col = 0;
    if (max_col >= this->map_width) max_col = (short)(this->map_width - 1);

    if (param_7 != 0) {
        if (param_6 == 0) {
            if (param_5 > 8) {
                param_5 = 8;
            }
            for (short row = min_row; row <= max_row; ++row) {
                for (short col = min_col; col <= max_col; ++col) {
                    RGE_Tile* tile = &this->map_row_offset[row][col];
                    uchar packed = (uchar)((tile->terrain_type & 0x1f) | (param_5 << 5));
                    rge_tile_set_packed_terrain_height(tile, packed);
                }
            }
        } else {
            for (short row = min_row; row <= max_row; ++row) {
                for (short col = min_col; col <= max_col; ++col) {
                    RGE_Tile* tile = &this->map_row_offset[row][col];
                    int h = (int)tile->height + (int)param_6;
                    if (h < 0) h = 0;
                    else if (h > 0xff) h = 0xff;

                    uchar old_packed = rge_tile_pack_terrain_height(tile);
                    uchar packed = (uchar)(((uchar)h << 5) | (old_packed & 0x1f));
                    rge_tile_set_packed_terrain_height(tile, packed);

                    if (((packed >> 5) & 0xff) > 8) {
                        rge_tile_set_packed_terrain_height(tile, (uchar)(old_packed & 0x1f));
                    }
                }
            }
        }
    }

    if (min_row > 0) min_row = (short)(min_row - 1);
    if (max_row < this->map_height - 1) max_row = (short)(max_row + 1);
    if (min_col > 0) min_col = (short)(min_col - 1);
    if (max_col < this->map_width - 1) max_col = (short)(max_col + 1);

    for (short row = min_row; row <= max_row; ++row) {
        for (short col = min_col; col <= max_col; ++col) {
            RGE_Tile* tile = &this->map_row_offset[row][col];
            tile->tile_type = this->get_tile_type(col, row);

            for (RGE_Object_Node* node = tile->objects.list; node != nullptr; node = node->next) {
                if (node->node != nullptr) {
                    node->node->teleport(node->node->world_x, node->node->world_y, 0.0f);
                }
            }

            if (this->game_world != nullptr && this->game_world->game_state != '\x03' && cur_player != nullptr) {
                cur_player->diam_tile_list.add_node((int)col, (int)row);
            }
        }
    }

    this->set_map_screen_pos((int)min_col, (int)min_row, (int)max_col, (int)max_row);
    this->request_redraw((int)min_col, (int)min_row, (int)max_col, (int)max_row, 0);
}

void RGE_Map::clean_terrain(long param_1, long param_2, long param_3, long param_4, uchar param_5) {
    if (this->map_row_offset == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    const uchar target_terrain = (uchar)(param_5 & 0x1f);
    const short map_w = (short)this->map_width;
    const short offset3 = (short)(-1 - map_w);
    const short offset_top = (short)(-map_w);
    const short offset7 = (short)(1 - map_w);
    const short offset_br = (short)(map_w + 1);
    const short offset_bl = (short)(map_w - 1);

    if (param_1 < 0) param_1 = 0;
    if (param_2 < 0) param_2 = 0;
    if (this->map_width <= param_3) param_3 = this->map_width - 1;

    int max_y = (int)param_4;
    int min_x = (int)param_1;
    if (this->map_height <= param_4) {
        max_y = this->map_height - 1;
        param_4 = max_y;
    }

    while (1) {
        bool changed_any = false;
        if (0 < min_x) {
            min_x = min_x - 1;
            param_1 = min_x;
        }
        if (0 < param_2) {
            param_2 = param_2 - 1;
        }
        if (param_3 < this->map_width - 1) {
            param_3 = param_3 + 1;
        }
        if (max_y < this->map_height - 1) {
            max_y = max_y + 1;
            param_4 = max_y;
        }

        int pass_index = 0;
        do {
            int y = (int)param_2;
            int x = min_x;
            int reset_x = min_x;

            if ((int)param_2 <= max_y) {
                do {
                    RGE_Tile* tile = this->map_row_offset[y] + min_x;
                    reset_x = x;

                    for (; x <= (int)param_3; ++x) {
                        if ((tile->terrain_type & 0x1f) != target_terrain) {
                            bool left = false;
                            bool down_left = false;
                            bool up_left = false;
                            bool up = false;
                            bool mark = false;
                            bool up_right = false;
                            bool right = false;
                            bool down_right = false;
                            bool down = false;

                            if (0 < y && ((tile[offset_top].terrain_type & 0x1f) == target_terrain)) {
                                up = true;
                            }
                            max_y = this->map_height - 1;
                            if (y < max_y && ((tile[map_w].terrain_type & 0x1f) == target_terrain)) {
                                down = true;
                            }
                            if (0 < x && ((tile[-1].terrain_type & 0x1f) == target_terrain)) {
                                left = true;
                            }
                            reset_x = this->map_width - 1;
                            if (x < reset_x && ((tile[1].terrain_type & 0x1f) == target_terrain)) {
                                right = true;
                            }

                            if (pass_index == 1) {
                                up_right = mark;
                                if (0 < y) {
                                    if (0 < x && ((tile[offset3].terrain_type & 0x1f) == target_terrain)) {
                                        up_left = true;
                                    }
                                    if (x < reset_x && ((tile[offset7].terrain_type & 0x1f) == target_terrain)) {
                                        up_right = true;
                                    }
                                }
                                if (y < max_y) {
                                    down_left = false;
                                    if (0 < x && ((tile[offset_bl].terrain_type & 0x1f) == target_terrain)) {
                                        down_left = true;
                                    }
                                    if (x < reset_x && ((tile[offset_br].terrain_type & 0x1f) == target_terrain)) {
                                        down_right = true;
                                    }
                                }
                            }

                            mark = false;
                            if (pass_index == 0) {
                                if ((up && down) || (right && left)) {
                                    mark = true;
                                }
                                if (!mark) {
                                    goto NEXT_TILE;
                                }
                            } else {
                                if (up_left) {
                                    if ((((up_right && !up) || (right && !up_right)) || (down_left && !left)) ||
                                        (down && !down_left)) {
                                        mark = true;
                                    } else if (down_right && !down && !right) {
                                        mark = true;
                                    }
                                }
                                if (up_right && !mark) {
                                    if ((((up_left && !up) || (left && !up_left)) || (down_right && !right)) ||
                                        ((down && !down_right) || (down_left && !left && !down))) {
                                        mark = true;
                                    }
                                }
                                if (down_right && !mark) {
                                    if ((((up_right && !right) || (up && !up_right)) || (down_left && !down)) ||
                                        ((left && !down_left) || (up_left && !left && !up))) {
                                        mark = true;
                                    }
                                }
                                if (!down_left) {
                                    goto FINISH_MARK;
                                }
                                if (!mark) {
                                    if ((((up_left && !left) || (up && !up_left)) || (down_right && !down)) ||
                                        ((right && !down_right) || ((up_right && !right) && !up))) {
                                        mark = true;
                                    }
                                    goto FINISH_MARK;
                                }
                            }

                            this->set_terrain(this->game_world, (short)x, (short)y, target_terrain, 0, 0);
                            changed_any = true;
                        }
FINISH_MARK:
NEXT_TILE:
                        tile = tile + 1;
                        max_y = (int)param_4;
                        reset_x = (int)param_1;
                    }

                    y = y + 1;
                    x = reset_x;
                } while (y <= max_y);
            }

            pass_index = pass_index + 1;
            min_x = reset_x;
        } while (pass_index < 2);

        if (!changed_any) {
            return;
        }
    }
}

void RGE_Map::load_terrain_obj_types(char* filename)
{
    FILE* infile = fopen(filename, "r");
    if (infile != nullptr) {
        short header_count = 0;
        fscanf(infile, "%hd", &header_count);

        short terrain_id = 0;
        short obj_type = 0;
        short obj_density = 0;
        short placement_flag = 0;
        int scan_ret = fscanf(infile, "%hd %hd %hd %hd", &terrain_id, &obj_type, &obj_density, &placement_flag);
        while (scan_ret != EOF) {
            int idx = (int)terrain_id;
            if (idx >= 0 && idx < 32 && this->terrain_types[idx].loaded != 0) {
                short slot = this->terrain_types[idx].num_obj_type;
                if (slot < 30) {
                    this->terrain_types[idx].obj_types[slot] = obj_type;
                    this->terrain_types[idx].obj_density[slot] = obj_density;
                    this->terrain_types[idx].obj_placement_flag[slot] = (uchar)placement_flag;
                    this->terrain_types[idx].num_obj_type = (short)(slot + 1);
                }
            }

            scan_ret = fscanf(infile, "%hd %hd %hd %hd", &terrain_id, &obj_type, &obj_density, &placement_flag);
        }
    }

    if (infile != nullptr) {
        fclose(infile);
    }
}

uchar RGE_Map::get_terrain(short col, short row) {
    if (this->map_row_offset == nullptr || col < 0 || row < 0 || col >= this->map_width || row >= this->map_height) {
        return 0;
    }

    uchar terrain = (uchar)(this->map_row_offset[(int)row][(int)col].terrain_type & 0x1f);
    if (terrain > 0x20 || (this->terrain_types[terrain].loaded == 0 && this->terrain_types[terrain].terrain_to_draw < 0)) {
        return 0;
    }

    return terrain;
}

void RGE_Map::create_terrain_object(RGE_Player* player, RGE_Game_World* world, short row, short col, short old_terrain, int remove_now, int min_obj_id, int max_obj_id) {
    (void)world;
    if (player == nullptr || this->map_row_offset == nullptr || row < 0 || col < 0 || row >= this->map_height || col >= this->map_width) {
        return;
    }

    uchar terrain = this->get_terrain(col, row);
    short end_i = this->terrain_types[terrain].num_obj_type;
    if (end_i <= 0) {
        return;
    }

    RGE_Object_Node* node = this->map_row_offset[(int)row][(int)col].objects.list;
    while (node != nullptr) {
        RGE_Static_Object* obj = node->node;
        node = node->next;
        if (obj == nullptr || obj->master_obj == nullptr) {
            continue;
        }

        short obj_id = obj->master_obj->id;
        if (obj->owner == player && (obj_id < min_obj_id || max_obj_id < obj_id)) {
            if (old_terrain < 0) {
                if (remove_now == 0) {
                    obj->destroy_obj();
                } else {
                    rge_map_delete_object_now(obj);
                }
            } else if (old_terrain >= 0 && old_terrain < 32) {
                short scan = this->terrain_types[(int)old_terrain].num_obj_type;
                if (scan > 29) {
                    scan = 29;
                }
                while (scan >= 0 && this->terrain_types[(int)old_terrain].obj_types[(int)scan] != obj_id) {
                    scan = (short)(scan - 1);
                }
                if (scan >= 0) {
                    if (remove_now == 0) {
                        obj->destroy_obj();
                    } else {
                        rge_map_delete_object_now(obj);
                    }
                }
            }
        }
    }

    if (player->master_objects == nullptr) {
        return;
    }

    if (end_i > 30) {
        end_i = 30;
    }

    for (short i = 0; i < end_i; ++i) {
        short master_id = this->terrain_types[(int)terrain].obj_types[(int)i];
        if (master_id == -1 || master_id < 0 || master_id >= player->master_object_num) {
            continue;
        }

        short density = this->terrain_types[(int)terrain].obj_density[(int)i];
        uchar placement_flag = this->terrain_types[(int)terrain].obj_placement_flag[(int)i];
        RGE_Master_Static_Object* master = player->master_objects[(int)master_id];
        if (master == nullptr || density <= 0) {
            continue;
        }

        short remaining = density;
        int chance_threshold = (int)density;
        do {
            float world_x = 0.0f;
            float world_y = 0.0f;

            if (placement_flag == 0) {
                int rand_x = debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x813);
                world_x = (float)(int)col - (float)rand_x * -3.051851e-05f;
                int rand_y = debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x814);
                world_y = (float)(int)row - (float)rand_y * -3.051851e-05f;
            } else if (placement_flag == 1) {
                world_x = (float)(int)col - -0.5f;
                world_y = (float)(int)row - -0.5f;
            }

            int should_place = 1;
            if (remaining < 1000) {
                int r = debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x820);
                should_place = (((r * 1000) / 0x7fff) < chance_threshold) ? 1 : 0;
            }

            if (should_place != 0) {
                if (master->check_placement(player, world_x, world_y, 0, 0, 1, 0, 1, 0, 1) == '\0') {
                    master->make_new_obj(player, world_x, world_y, 0.0f);
                }
            }

            remaining = (short)(remaining - 1000);
            chance_threshold = chance_threshold - 1000;
        } while (remaining > 0);
    }
}

int RGE_Map::clear_terrain_object(RGE_Game_World* world, short row, short col, short old_terrain, int remove_now, int min_obj_id, int max_obj_id) {
    (void)world;
    (void)this->get_terrain(col, row);
    if (this->map_row_offset == nullptr || row < 0 || col < 0 || row >= this->map_height || col >= this->map_width) {
        return -1;
    }

    RGE_Object_Node* node = this->map_row_offset[(int)row][(int)col].objects.list;
    short ret_obj_id = -1;

    while (node != nullptr) {
        RGE_Object_Node* current = node;
        node = node->next;

        RGE_Static_Object* obj = current->node;
        if (obj == nullptr || obj->master_obj == nullptr) {
            continue;
        }

        short obj_id = obj->master_obj->id;
        if (min_obj_id <= obj_id && obj_id <= max_obj_id) {
            continue;
        }

        if (old_terrain < 0) {
            if (remove_now == 0) {
                obj->destroy_obj();
            } else {
                rge_map_delete_object_now(obj);
            }
            continue;
        }

        ret_obj_id = obj_id;

        short scan = -1;
        if (old_terrain >= 0 && old_terrain < 32) {
            scan = this->terrain_types[(int)old_terrain].num_obj_type;
            if (scan > 29) {
                scan = 29;
            }
            while (scan >= 0 && this->terrain_types[(int)old_terrain].obj_types[(int)scan] != obj_id) {
                scan = (short)(scan - 1);
            }
        }

        if (scan >= 0) {
            if (remove_now == 0) {
                obj->destroy_obj();
            } else {
                rge_map_delete_object_now(obj);
            }
            continue;
        }

        if (obj->master_obj->check_placement(obj->owner, obj->world_x, obj->world_y, 0, 0, 1, 1, 1, 0, 0) != '\0') {
            if (remove_now == 0) {
                obj->destroy_obj();
            } else {
                rge_map_delete_object_now(obj);
            }
        }
    }

    return (int)ret_obj_id;
}

void RGE_Map::place_terrain_object(RGE_Player* player, RGE_Game_World* world, short row, short col, int object_id, int single_placement) {
    (void)world;
    (void)object_id;
    if (player == nullptr || player->master_objects == nullptr || this->map_row_offset == nullptr || row < 0 || col < 0 || row >= this->map_height || col >= this->map_width) {
        return;
    }

    uchar terrain = this->get_terrain(col, row);
    int end_i = (int)this->terrain_types[(int)terrain].num_obj_type;
    if (end_i < 1) {
        return;
    }
    if (end_i > 30) {
        end_i = 30;
    }

    for (int idx = 0; idx < end_i; ++idx) {
        short master_id = this->terrain_types[(int)terrain].obj_types[idx];
        if (master_id == -1 || master_id < 0 || master_id >= player->master_object_num) {
            continue;
        }

        RGE_Master_Static_Object* master = player->master_objects[(int)master_id];
        short density = this->terrain_types[(int)terrain].obj_density[idx];
        uchar placement_flag = this->terrain_types[(int)terrain].obj_placement_flag[idx];
        if (master == nullptr) {
            continue;
        }

        if (single_placement == 0) {
            if (density <= 0) {
                continue;
            }

            short remaining = density;
            int chance_threshold = (int)density;
            do {
                float world_x = 0.0f;
                float world_y = 0.0f;

                if (placement_flag == 0) {
                    int rand_x = debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x894);
                    world_x = (float)(int)col - (float)rand_x * -3.051851e-05f;
                    int rand_y = debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x895);
                    world_y = (float)(int)row - (float)rand_y * -3.051851e-05f;
                } else {
                    world_x = (float)(int)col - -0.5f;
                    world_y = (float)(int)row - -0.5f;
                }

                int should_place = 1;
                if (remaining < 1000) {
                    int r = debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x8a2);
                    should_place = (((r * 1000) / 0x7fff) < chance_threshold) ? 1 : 0;
                }

                if (should_place != 0) {
                    if (master->check_placement(player, world_x, world_y, 0, 0, 1, 0, 1, 0, 1) == '\0') {
                        master->make_new_obj(player, world_x, world_y, 0.0f);
                    }
                }

                remaining = (short)(remaining - 1000);
                chance_threshold = chance_threshold - 1000;
            } while (remaining > 0);
        } else if (single_placement == 1) {
            float world_x = 0.0f;
            float world_y = 0.0f;

            if (placement_flag == 0) {
                int rand_x = debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x8af);
                world_x = (float)(int)col - (float)rand_x * -3.051851e-05f;
                int rand_y = debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x8b0);
                world_y = (float)(int)row - (float)rand_y * -3.051851e-05f;
            } else {
                world_x = (float)(int)col - -0.5f;
                world_y = (float)(int)row - -0.5f;
            }

            if (master->check_placement(player, world_x, world_y, 0, 0, 1, 0, 1, 0, 1) == '\0') {
                master->make_new_obj(player, world_x, world_y, 0.0f);
                return;
            }
        }
    }
}

void RGE_Map::create_terrain_objects(RGE_Player* player, RGE_Game_World* world) {
    if (player == nullptr || this->map_row_offset == nullptr) {
        return;
    }

    for (short row = 0; row < this->map_height; ++row) {
        for (short col = 0; col < this->map_width; ++col) {
            this->create_terrain_object(player, world, row, col, -1, 0, -1, -1);
        }
    }
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
uchar RGE_Map::do_terrain_brush(long param_1, long param_2, long param_3, uchar param_4) {
    long x0 = param_1 - param_3;
    long x1 = param_1 + param_3;
    long y0 = param_2 - param_3;
    long y1 = param_2 + param_3;

    if (x0 < 0) {
        x0 = 0;
    }
    if (x1 >= this->map_width) {
        x1 = this->map_width - 1;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (y1 >= this->map_height) {
        y1 = this->map_height - 1;
    }

    for (long y = y0; y <= y1; ++y) {
        for (long x = x0; x <= x1; ++x) {
            this->set_terrain(this->game_world, (short)x, (short)y, param_4, 0, 0);
        }
    }

    return 1;
}

uchar RGE_Map::do_terrain_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6) {
    long radius = param_5 >> 1;

    if (param_1 < 0) {
        param_1 = 0;
    }
    if (param_3 >= this->map_width) {
        param_3 = this->map_width - 1;
    }
    if (param_2 < 0) {
        param_2 = 0;
    }
    if (param_4 >= this->map_height) {
        param_4 = this->map_height - 1;
    }

    long dx_i = param_3 - param_1;
    long dy_i = param_4 - param_2;
    long steps = (long)sqrt((double)(dx_i * dx_i + dy_i * dy_i));

    double dx = 0.0;
    double dy = 0.0;
    if (steps != 0) {
        dx = (double)dx_i / (double)steps;
        dy = (double)dy_i / (double)steps;
    }

    double x = (double)param_1;
    double y = (double)param_2;

    this->do_terrain_brush(param_1, param_2, radius, param_6);

    for (long index = steps; index > 0; --index) {
        x = x + dx;
        y = y + dy;
        this->do_terrain_brush((long)x, (long)y, radius, param_6);
    }

    if (((double)param_3 != x) || ((double)param_4 != y)) {
        this->do_terrain_brush(param_3, param_4, radius, param_6);
    }

    return 1;
}

uchar RGE_Map::do_elevation_brush(long param_1, long param_2, long param_3, uchar param_4) {
    long x0 = param_1 - param_3;
    long x1 = param_1 + param_3;
    long y0 = param_2 - param_3;
    long y1 = param_2 + param_3;

    if (x0 < 0) {
        x0 = 0;
    }
    if (x1 >= this->map_width) {
        x1 = this->map_width - 1;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (y1 >= this->map_height) {
        y1 = this->map_height - 1;
    }

    for (long y = y0; y <= y1; ++y) {
        for (long x = x0; x <= x1; ++x) {
            RGE_Tile* tile = &this->map_row_offset[y][x];
            tile->terrain_type = (uchar)((tile->terrain_type & 0x1f) | (param_4 << 5));
        }
    }

    return 1;
}

uchar RGE_Map::do_elevation_brush_stroke(long param_1, long param_2, long param_3, long param_4, long param_5, uchar param_6) {
    long radius = param_5 >> 1;

    if (param_1 < 0) {
        param_1 = 0;
    }
    if (param_3 >= this->map_width) {
        param_3 = this->map_width - 1;
    }
    if (param_2 < 0) {
        param_2 = 0;
    }
    if (param_4 >= this->map_height) {
        param_4 = this->map_height - 1;
    }

    long dx_i = param_3 - param_1;
    long dy_i = param_4 - param_2;
    long steps = (long)sqrt((double)(dx_i * dx_i + dy_i * dy_i));

    double dx = 0.0;
    double dy = 0.0;
    if (steps != 0) {
        dx = (double)dx_i / (double)steps;
        dy = (double)dy_i / (double)steps;
    }

    double x = (double)param_1;
    double y = (double)param_2;

    this->do_elevation_brush(param_1, param_2, radius, param_6);

    for (long index = steps; index > 0; --index) {
        x = x + dx;
        y = y + dy;
        this->do_elevation_brush((long)x, (long)y, radius, param_6);
    }

    if (((double)param_3 != x) || ((double)param_4 != y)) {
        this->do_elevation_brush(param_3, param_4, radius, param_6);
    }

    long clean_x0 = param_1;
    long clean_x1 = param_3;
    if (param_1 < param_3) {
        clean_x0 = param_1 - radius;
        clean_x1 = param_3 + radius;
    } else {
        clean_x0 = param_3 - radius;
        clean_x1 = param_1 + radius;
    }

    long clean_y0 = param_2;
    long clean_y1 = param_4;
    if (param_2 < param_4) {
        clean_y0 = param_2 - radius;
        clean_y1 = param_4 + radius;
    } else {
        clean_y0 = param_4 - radius;
        clean_y1 = param_2 + radius;
    }

    this->clean_elevation(clean_x0, clean_y0, clean_x1, clean_y1, param_6);

    return 1;
}

uchar RGE_Map::do_cliff_brush(long param_1, long param_2, uchar param_3, uchar param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    return 0;
}

uchar RGE_Map::do_cliff_brush_stroke(long param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6) {
    if (param_1 < 0) {
        param_1 = 0;
    }
    if (param_3 >= this->map_width) {
        param_3 = this->map_width - 1;
    }
    if (param_2 < 0) {
        param_2 = 0;
    }
    if (param_4 >= this->map_height) {
        param_4 = this->map_height - 1;
    }

    long dx_i = param_3 - param_1;
    long dy_i = param_4 - param_2;
    long steps = (long)sqrt((double)(dx_i * dx_i + dy_i * dy_i));

    double dx = 0.0;
    double dy = 0.0;
    if (steps != 0) {
        dx = (double)dx_i / (double)steps;
        dy = (double)dy_i / (double)steps;
    }

    double x = (double)param_1;
    double y = (double)param_2;

    this->do_cliff_brush(param_1, param_2, param_5, param_6);

    for (long index = steps; index > 0; --index) {
        x = x + dx;
        y = y + dy;
        this->do_cliff_brush((long)x, (long)y, param_5, param_6);
    }

    if (((double)param_3 != x) || ((double)param_4 != y)) {
        this->do_cliff_brush(param_3, param_4, param_5, param_6);
    }

    return 1;
}

void RGE_Map::scenario_save(int param_1) {
    // Fully verified. Source of truth: map.cpp.decomp @ 0x00455F10 (audited vs map.cpp.asm).
    rge_write(param_1, &this->map_width, 4);
    rge_write(param_1, &this->map_height, 4);

    // Parity: both loops are bounded by map_height (original has an apparent width/height mix-up).
    for (int y = 0; y < this->map_height; ++y) {
        for (int x = 0; x < this->map_height; ++x) {
            RGE_Tile* tile = &this->map_row_offset[y][x];
            const uchar packed = *(uchar*)((uint8_t*)tile + 5);

            uchar terrain_info = (uchar)(packed & 0x1F);
            uchar height_info = (uchar)(packed >> 5);
            uchar overlay_info = 0;

            rge_write(param_1, &terrain_info, 1);
            rge_write(param_1, &height_info, 1);
            rge_write(param_1, &overlay_info, 1);
        }
    }
}

void RGE_Map::scenario_load(int param_1, uchar* param_2) {
    // Fully verified. Source of truth: map.cpp.decomp @ 0x00455FF0 (audited vs map.cpp.asm).
    (void)param_2;

    long w = 0;
    long h = 0;
    rge_read(param_1, &w, 4);
    rge_read(param_1, &h, 4);
    this->new_map(w, h);

    for (int y = 0; y < this->map_height; ++y) {
        // Parity: both loops are bounded by map_height (original has an apparent width/height mix-up).
        for (int x = 0; x < this->map_height; ++x) {
            uchar terrain_info = 0;
            uchar height_info = 0;
            uchar overlay_info = 0;
            rge_read(param_1, &terrain_info, 1);
            rge_read(param_1, &height_info, 1);
            rge_read(param_1, &overlay_info, 1);
            (void)overlay_info;

            RGE_Tile* tile = &this->map_row_offset[y][x];
            uchar* packed = (uchar*)((uint8_t*)tile + 5);

            // Low 5 bits (terrain)
            uchar old = *packed;
            *packed = ((terrain_info ^ old) & 0x1F) ^ old;

            // High 3 bits (height)
            *packed = (uchar)((height_info << 5) | (*packed & 0x1F));
        }
    }

    this->set_elev(0, 0, (short)(this->map_width - 1), (short)(this->map_height - 1), 0, 0, 0);
    this->set_terrain((RGE_Player*)nullptr, (RGE_Game_World*)nullptr, 0, 0,
                      (short)(this->map_width - 1), (short)(this->map_height - 1), 0, 0, 0);
}

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

    // Random map DB controller path is active; module internals are decomp-audited incrementally.
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

void RGE_Map::save_map(int param_1) {
    // Fully verified. Source of truth: map.cpp.decomp @ 0x00457C50 (audited vs map.cpp.asm).
    rge_write(param_1, &this->map_width, 4);
    rge_write(param_1, &this->map_height, 4);

    this->map_zones->save(param_1);

    rge_write(param_1, &this->map_visible_flag, 1);
    rge_write(param_1, &this->fog_flag, 1);

    if (save_game_version < 7.0f) {
        const int tile_bytes = (int)(this->map_width * this->map_height * (long)sizeof(RGE_Tile));
        rge_write(param_1, this->map, tile_bytes);
    } else {
        for (int y = 0; y < this->map_height; ++y) {
            RGE_Tile* tile = this->map_row_offset[y];
            for (int x = 0; x < this->map_width; ++x) {
                rge_write(param_1, &tile->screen_xpos, 2);
                rge_write(param_1, &tile->screen_ypos, 2);
                rge_write(param_1, &tile->tile_type, 1);

                const uchar field_0x5 = *(uchar*)((uint8_t*)tile + 5);
                const uchar field_0x6 = *(uchar*)((uint8_t*)tile + 6);

                uchar terrain_info = (uchar)(field_0x5 & 0x1F);
                uchar height_info = (uchar)(field_0x5 >> 5);
                uchar border_info = (uchar)(field_0x6 & 0x0F);
                uchar border_shape = (uchar)(field_0x6 >> 4);

                rge_write(param_1, &terrain_info, 1);
                rge_write(param_1, &height_info, 1);
                rge_write(param_1, &border_info, 1);
                rge_write(param_1, &border_shape, 1);

                tile = tile + 1;
            }
        }
    }

    this->unified_vis_map->save(param_1);
}

void RGE_Map::save(int param_1) {
    // Fully verified. Source of truth: map.cpp.decomp @ 0x00457DF0 (audited vs map.cpp.asm).
    uint8_t* temp = (uint8_t*)calloc(1, sizeof(RGE_Map));
    memcpy(temp, this, sizeof(RGE_Map));

    // Rewrite sound pointers in the temp blob to serialized sound IDs (-1 for null).
    for (int i = 0; i < 32; ++i) {
        RGE_Tile_Set* ts = &this->terrain_types[i];
        if (ts->loaded != 0) {
            int32_t id = -1;
            if (ts->sound != nullptr) {
                id = (int32_t)ts->sound->id;
            }
            const size_t off = (size_t)((uint8_t*)&ts->sound - (uint8_t*)this);
            *(int32_t*)(temp + off) = id;
        }
    }

    for (int i = 0; i < 16; ++i) {
        RGE_Border_Set* bs = &this->border_types[i];
        int32_t id = -1;
        if (bs->loaded != 0 && bs->sound != nullptr) {
            id = (int32_t)bs->sound->id;
        }
        const size_t off = (size_t)((uint8_t*)&bs->sound - (uint8_t*)this);
        *(int32_t*)(temp + off) = id;
    }

    rge_write(param_1, temp, (int)sizeof(RGE_Map));
    this->random_map->save(param_1);
    free(temp);
}

void RGE_Map::load_terrain_types(RGE_Sound** sounds)
{
    // Source of truth: map.cpp.asm @ 0x00457EB0.
    // This pass always iterates all 32 terrain slots, honoring serialized loaded flags.
    for (int i = 0; i < 32; ++i) {
        RGE_Tile_Set* ts = &this->terrain_types[i];
        if (ts->loaded != 0) {
            char shp_name[32];
            shp_name[0] = '\0';
            _snprintf(shp_name, sizeof(shp_name), "%s.shp", ts->pict_name);
            shp_name[sizeof(shp_name) - 1] = '\0';

            if (ts->shape != nullptr) {
                delete ts->shape;
                ts->shape = nullptr;
            }

            ts->shape = new TShape(shp_name, ts->resource_id);
            if (ts->shape == nullptr || ts->shape->is_loaded() == 0) {
                ts->loaded = 0;
            }

            intptr_t sound_idx = (intptr_t)ts->sound;
            if (sound_idx >= 0 && sounds != nullptr) {
                ts->sound = sounds[sound_idx];
            } else {
                ts->sound = nullptr;
            }
        } else {
            ts->shape = nullptr;
        }
    }
}

void RGE_Map::load_border_types(RGE_Sound** sounds)
{
    // Source of truth: map.cpp.asm @ 0x00458280.
    // This pass always iterates all 16 border slots, honoring serialized loaded flags.
    for (int i = 0; i < 16; ++i) {
        RGE_Border_Set* bs = &this->border_types[i];
        if (bs->loaded != 0) {
            char shp_name[32];
            shp_name[0] = '\0';
            _snprintf(shp_name, sizeof(shp_name), "%s.shp", bs->pict_name);
            shp_name[sizeof(shp_name) - 1] = '\0';

            if (bs->shape != nullptr) {
                delete bs->shape;
                bs->shape = nullptr;
            }

            bs->shape = new TShape(shp_name, bs->resource_id);
            if (bs->shape == nullptr || bs->shape->is_loaded() == 0) {
                bs->loaded = 0;
            }

            intptr_t sound_idx = (intptr_t)bs->sound;
            if (sound_idx >= 0 && sounds != nullptr) {
                bs->sound = sounds[sound_idx];
            } else {
                bs->sound = nullptr;
            }
        } else {
            bs->shape = nullptr;
        }
    }
}
void RGE_Map::load_terrain_types(char* filename, RGE_Sound** sounds) {
    for (int i = 0; i < 32; ++i) {
        this->terrain_types[i].loaded = 0;
    }

    FILE* infile = fopen(filename, "r");
    if (infile == nullptr) {
        return;
    }

    fscanf(infile, "%hd", &this->num_terrain);
    short count = (short)(this->num_terrain - 1);
    if (count >= 0) {
        long remaining = (long)count + 1;
        do {
            short terrain_id = 0;
            short low_color_unused = 0;
            short lt_cliff_color = 0;
            short rt_cliff_color = 0;
            short hi_color = 0;
            short med_color = 0;
            short is_animated = 0;
            short animation_frames = 0;
            float interval = 0.0f;
            float pause_between_loops = 0.0f;
            short terrain_to_draw = 0;
            short rows = 0;
            short cols = 0;
            short impassable_terrain = 0;
            short passable_terrain = 0;
            short row = 0;
            short col = 0;
            short border_num = 0;
            long resource_id = 0;
            char name[13];
            char pict_name[13];
            memset(name, 0, sizeof(name));
            memset(pict_name, 0, sizeof(pict_name));

            int scan_ok = fscanf(
                infile,
                "%hd %12s %12s %ld %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd %hd %hd %hd %hd %hd",
                &terrain_id,
                name,
                pict_name,
                &resource_id,
                &low_color_unused,
                &lt_cliff_color,
                &rt_cliff_color,
                &hi_color,
                &med_color,
                &is_animated,
                &animation_frames,
                &interval,
                &pause_between_loops,
                &terrain_to_draw,
                &rows,
                &cols,
                &impassable_terrain,
                &passable_terrain,
                &row,
                &col,
                &border_num);

            if (scan_ok != EOF && terrain_id >= 0 && terrain_id < 32) {
                RGE_Tile_Set* ts = &this->terrain_types[terrain_id];
                short shape_index = 0;
                for (int i = 0; i < 19; ++i) {
                    fscanf(infile, "%hd %hd", &ts->tiles[i].count, &ts->tiles[i].animations);
                    ts->tiles[i].shape_index = shape_index;
                    shape_index = (short)(shape_index + ts->tiles[i].count * ts->tiles[i].animations);
                }

                short loaded_borders = 0;
                while (loaded_borders < border_num) {
                    short border = 0;
                    short border_type = 0;
                    fscanf(infile, "%hd %hd", &border, &border_type);
                    if (border >= 0 && border < 32) {
                        ts->borders[border] = border_type;
                    }
                    loaded_borders = (short)(loaded_borders + 1);
                }

                ts->sound = (med_color < 0 || sounds == nullptr) ? nullptr : sounds[med_color];
                ts->map_low_color = (uchar)hi_color;
                ts->map_med_color = (uchar)lt_cliff_color;
                ts->map_hi_color = (uchar)rt_cliff_color;
                ts->map_lt_cliff_color = (uchar)impassable_terrain;
                ts->map_rt_cliff_color = (uchar)passable_terrain;
                ts->impassable_terrain = (uchar)row;
                ts->passable_terrain = (uchar)col;
                rge_convert_us(name);
                rge_copy_fixed_text(ts->name, sizeof(ts->name), name);
                rge_copy_fixed_text(ts->pict_name, sizeof(ts->pict_name), pict_name);
                ts->animate_last = 0.0f;
                ts->resource_id = resource_id;
                ts->loaded = 1;
                ts->rows = rows;
                ts->cols = cols;
                ts->is_animated = (uchar)is_animated;
                ts->animation_frames = animation_frames;
                ts->pause_frames = (interval == 0.0f) ? 0 : (short)(pause_between_loops / interval);
                ts->interval = interval;
                ts->frame = 0;
                ts->pause_between_loops = pause_between_loops;
                ts->draw_frame = 0;
                ts->frame_changed = 0;
                ts->drawn = 0;
                ts->terrain_to_draw = terrain_to_draw;
            }
            remaining = remaining - 1;
        } while (remaining != 0);
    }
    fclose(infile);
}

void RGE_Map::load_border_types(char* filename, RGE_Sound** sounds) {
    for (int i = 0; i < 16; ++i) {
        this->border_types[i].loaded = 0;
    }

    FILE* infile = fopen(filename, "r");
    if (infile == nullptr) {
        return;
    }

    fscanf(infile, "%hd", &this->num_borders);
    short count = (short)(this->num_borders - 1);
    if (count >= 0) {
        long remaining = (long)count + 1;
        do {
            short border_id = 0;
            short low_color_unused = 0;
            short map_med_color = 0;
            short map_hi_color = 0;
            short map_low_color = 0;
            short sound_id = 0;
            short tile_flag = 0;
            short animation_frames = 0;
            float interval = 0.0f;
            float pause_between_loops = 0.0f;
            short draw_tile = 0;
            short underlay_terrain = 0;
            short border_style = 0;
            long resource_id = 0;
            char name[13];
            char pict_name[13];
            memset(name, 0, sizeof(name));
            memset(pict_name, 0, sizeof(pict_name));

            int scan_ok = fscanf(
                infile,
                "%hd %12s %12s %ld %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd",
                &border_id,
                name,
                pict_name,
                &resource_id,
                &low_color_unused,
                &map_med_color,
                &map_hi_color,
                &map_low_color,
                &sound_id,
                &tile_flag,
                &animation_frames,
                &interval,
                &pause_between_loops,
                &draw_tile,
                &underlay_terrain,
                &border_style);

            if (scan_ok != EOF && border_id >= 0 && border_id < 16) {
                RGE_Border_Set* bs = &this->border_types[border_id];
                short shape_index = 0;
                for (int i = 0; i < 19; ++i) {
                    for (int j = 0; j < 12; ++j) {
                        fscanf(infile, "%hd %hd", &bs->borders[i][j].count, &bs->borders[i][j].animations);
                        bs->borders[i][j].shape_index = shape_index;
                        shape_index = (short)(shape_index + bs->borders[i][j].count * bs->borders[i][j].animations);
                    }
                }

                bs->sound = (sound_id < 0 || sounds == nullptr) ? nullptr : sounds[sound_id];
                bs->map_low_color = (uchar)map_low_color;
                bs->map_med_color = (uchar)map_med_color;
                bs->map_hi_color = (uchar)map_hi_color;
                rge_convert_us(name);
                rge_copy_fixed_text(bs->name, sizeof(bs->name), name);
                rge_copy_fixed_text(bs->pict_name, sizeof(bs->pict_name), pict_name);
                bs->loaded = 1;
                bs->resource_id = resource_id;
                bs->is_animated = (uchar)tile_flag;
                bs->animation_frames = animation_frames;
                bs->pause_frames = (interval == 0.0f) ? 0 : (short)(pause_between_loops / interval);
                bs->interval = interval;
                bs->pause_between_loops = pause_between_loops;
                bs->frame = 0;
                bs->draw_frame = 0;
                bs->animate_last = 0.0f;
                bs->frame_changed = 0;
                bs->drawn = 0;
                bs->draw_tile = (uchar)draw_tile;
                bs->underlay_terrain = underlay_terrain;
                bs->border_style = border_style;
            }
            remaining = remaining - 1;
        } while (remaining != 0);
    }
    fclose(infile);
}
void RGE_Map::coordinate_map() {
    this->set_map_screen_pos(0, 0, this->map_width - 1, this->map_height - 1);
}
void RGE_Map::set_map_visible(uchar flag) {
    this->map_visible_flag = flag;
}
void RGE_Map::set_map_fog(uchar flag) {
    this->fog_flag = flag;
}
void RGE_Map::get_point(short* param_1, short* param_2, float param_3, float param_4, float param_5, short param_6, short param_7) {
    // Fully verified. Source of truth: map.cpp.decomp @ 0x0045A6D0
    int half_width = (int)this->tile_half_width;
    int half_height = (int)this->tile_half_height;

    int x = (int)((param_4 + param_3) * (float)half_width) + (int)param_6;
    int y = (int)((param_4 - 1.0f - param_3 - param_5) * (float)half_height) - 0x10 + (int)param_7;

    *param_1 = (short)x;
    *param_2 = (short)y;
}
void RGE_Map::request_redraw(int col0, int row0, int col1, int row1, uchar attr) {
    int x0 = col0;
    int y0 = row0;
    int x1 = col1;
    int y1 = row1;

    if (col1 < col0) {
        x0 = col1;
        x1 = col0;
    }
    if (row1 < row0) {
        y0 = row1;
        y1 = row0;
    }

    if (x1 < 0 || y1 < 0 || x0 >= this->map_width || y0 >= this->map_height) {
        return;
    }

    if (x0 < 0) {
        x0 = 0;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (x1 >= this->map_width) {
        x1 = this->map_width - 1;
    }
    if (y1 >= this->map_height) {
        y1 = this->map_height - 1;
    }

    for (int row = y0; row <= y1; ++row) {
        if (x0 <= x1) {
            RGE_Tile* tile = &this->map_row_offset[row][x0];
            int count = (x1 - x0) + 1;
            do {
                tile->draw_as = 0xCC;
                tile->draw_attribute = attr;
                ++tile;
                count = count - 1;
            } while (count != 0);
        }
    }
}
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
