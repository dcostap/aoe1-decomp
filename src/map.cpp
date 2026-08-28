#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../include/map.h"
#include "../include/world.h"
#include "../include/basegame.h"
#include "../include/player.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/sound.h"
#include "../include/Shape.h"
#include "../include/visible.h"
#include "../include/zone_map.h"
#include "../include/rmm_base.h"
#include "../include/vis_unit.h"
#include "../include/rmm_dbct.h"
#include "../include/debuglog.h"
#include "../include/rge_base_game_global.h"

extern "C" void __cdecl rge_read(int file, void* data, int size);
extern "C" void __cdecl rge_write(int file, void* data, int size);
extern "C" void __cdecl addstring(char** dst, char* base, char* ext);
extern "C" void __cdecl convert_us(char* text);
extern "C" int __cdecl debug_rand(char* file, int line);
extern "C" void __cdecl debug_srand(char* file, int line, unsigned int seed);
extern float save_game_version;
extern float old_map_cutoff;
extern float DAT_005706a8;
extern float DAT_005706ac;
extern double DAT_005706c0;
extern double DAT_005706d0;
extern double DAT_005706d8;
extern float DAT_005706e8;
extern unsigned int DAT_0062e65c;
extern TDebuggingLog* L;

RGE_Map::RGE_Map(int fd, RGE_Sound** sounds, unsigned char load_random)
{
    this->map_zones = 0;
    rge_read(fd, this, 0x8DD0);
    RGE_Game_World* world = rge_base_game->world;
    this->map = 0;
    this->game_world = world;
    this->search_map = 0;
    this->map_row_offset = 0;
    this->search_map_rows = 0;
    this->load_terrain_types(sounds);
    this->load_border_types(sounds);
    this->init_tile_sizes();
    if (load_random != 0) {
        this->data_load_random_map(fd);
    }
}

RGE_Map::RGE_Map(char* border_file, char* terrain_file, char* unused_file,
                 short tile_width_arg, short tile_height_arg,
                 short elev_height_arg, RGE_Sound** sounds)
{
    int i;
    int j;

    this->map_zones = 0;
    this->random_map = 0;
    this->game_world = rge_base_game->world;

    this->tile_width = tile_width_arg;
    this->tile_half_width = tile_width_arg / 2;
    this->tile_height = tile_height_arg;
    this->tile_half_height = tile_height_arg / 2;
    this->elev_height = elev_height_arg;
    this->map_width = 0;
    this->map_height = 0;
    this->world_width = 0;
    this->world_height = 0;

    this->set_tile_size(0, tile_width_arg, tile_height_arg, 0);
    this->set_tile_size(1, this->tile_width, this->elev_height, -100);
    this->set_tile_size(2, this->tile_width,
                        this->elev_height + this->tile_height, 100);
    this->set_tile_size(3, this->tile_width, this->tile_height, -100);
    this->set_tile_size(4, this->tile_width, this->tile_height, -100);
    this->set_tile_size(5, this->tile_width, this->elev_height, -100);
    this->set_tile_size(6, this->tile_width,
                        this->elev_height + this->tile_height, 100);
    this->set_tile_size(7, this->tile_width, this->elev_height, -100);
    this->set_tile_size(8, this->tile_width,
                        this->elev_height + this->tile_height, 100);
    this->set_tile_size(9, this->tile_width, this->elev_height, -100);
    this->set_tile_size(10, this->tile_width,
                        this->elev_height + this->tile_height, 100);
    this->set_tile_size(11, this->tile_width, this->tile_height, -100);
    this->set_tile_size(12, this->tile_width, this->tile_height, -100);
    this->set_tile_size(13, this->tile_width, this->elev_height, -100);
    this->set_tile_size(14, this->tile_width,
                        this->elev_height + this->tile_height, 100);
    this->set_tile_size(15, this->tile_width, this->tile_height, 100);
    this->set_tile_size(16, this->tile_width, this->tile_height, 100);
    this->set_tile_size(17, this->tile_half_width, this->tile_height, 0);
    this->set_tile_size(18, this->tile_half_width, this->tile_height, 0);

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

    for (i = 0; i < 32; ++i) {
        this->terrain_types[i].num_obj_type = 0;
        this->terrain_types[i].rows = 0;
        this->terrain_types[i].cols = 0;
        for (j = 0; j < 30; ++j) {
            this->terrain_types[i].obj_types[j] = 0;
            this->terrain_types[i].obj_density[j] = 0;
        }
        for (j = 0; j < 32; ++j) {
            this->terrain_types[i].borders[j] = 0;
        }
        this->terrain_types[i].shape = 0;
        this->terrain_types[i].sound = 0;
    }

    for (i = 15; i >= 0; --i) {
        this->border_types[i].shape = 0;
        this->border_types[i].sound = 0;
    }

    this->load_terrain_types(terrain_file, sounds);
    this->load_border_types(border_file, sounds);
    this->map = 0;
    this->search_map = 0;
    this->map_row_offset = 0;
    this->search_map_rows = 0;
    this->unified_vis_map = 0;
    this->unit_manager = 0;
}

RGE_Map::~RGE_Map()
{
    int i;

    if (this->map_zones != 0) {
        delete this->map_zones;
        this->map_zones = 0;
    }
    if (this->random_map != 0) {
        delete this->random_map;
        this->random_map = 0;
    }
    if (this->map != 0) {
        free(this->map);
    }
    if (this->search_map != 0) {
        free(this->search_map);
    }
    if (this->map_row_offset != 0) {
        free(this->map_row_offset);
    }
    if (this->search_map_rows != 0) {
        free(this->search_map_rows);
    }

    for (i = 31; i >= 0; --i) {
        if (this->terrain_types[i].shape != 0) {
            delete this->terrain_types[i].shape;
            this->terrain_types[i].shape = 0;
        }
    }
    for (i = 15; i >= 0; --i) {
        if (this->border_types[i].shape != 0) {
            delete this->border_types[i].shape;
            this->border_types[i].shape = 0;
        }
    }

    if (this->unified_vis_map != 0) {
        delete this->unified_vis_map;
    }
    if (this->unit_manager != 0) {
        delete this->unit_manager;
    }
}

void RGE_Map::init_tile_sizes()
{
    this->tile_width = 0x40;
    this->tile_height = 0x20;
    this->tile_half_width = 0x20;
    this->tile_half_height = 0x10;
    this->elev_height = 0x10;

    this->set_tile_size(0, 0x40, 0x20, 0);
    this->set_tile_size(1, this->tile_width, this->elev_height, -8);
    this->set_tile_size(2, this->tile_width,
                        this->elev_height + this->tile_height, 8);
    this->set_tile_size(3, this->tile_width, this->tile_height, -8);
    this->set_tile_size(4, this->tile_width, this->tile_height, -8);
    this->set_tile_size(5, this->tile_width, this->elev_height, -8);
    this->set_tile_size(6, this->tile_width,
                        this->elev_height + this->tile_height, 8);
    this->set_tile_size(7, this->tile_width, this->elev_height, -8);
    this->set_tile_size(8, this->tile_width,
                        this->elev_height + this->tile_height, 8);
    this->set_tile_size(9, this->tile_width, this->elev_height, -8);
    this->set_tile_size(10, this->tile_width,
                        this->elev_height + this->tile_height, 8);
    this->set_tile_size(11, this->tile_width, this->tile_height, -8);
    this->set_tile_size(12, this->tile_width, this->tile_height, -8);
    this->set_tile_size(13, this->tile_width, this->elev_height, -8);
    this->set_tile_size(14, this->tile_width,
                        this->elev_height + this->tile_height, 8);
    this->set_tile_size(15, this->tile_width, this->tile_height, 8);
    this->set_tile_size(16, this->tile_width, this->tile_height, 8);
    this->set_tile_size(17, this->tile_half_width, this->tile_height, 0);
    this->set_tile_size(18, this->tile_half_width, this->tile_height, 0);
}

void RGE_Map::data_load_random_map(int file)
{
    this->random_map = new RGE_RMM_Database_Controller(file);
}

void RGE_Map::load_random_map(char* param_1, char* param_2, char* param_3,
                              char* param_4)
{
    RGE_RMM_Database_Controller* ctrl =
        new RGE_RMM_Database_Controller(param_2, param_3, param_4, param_1);
    this->random_map = ctrl;
}

void RGE_Map::set_map_visible(unsigned char v)
{
    this->map_visible_flag = v;
}

void RGE_Map::set_map_fog(unsigned char v)
{
    this->fog_flag = v;
}

void RGE_Map::clear_map(RGE_Player* param_1, RGE_Game_World* param_2,
                        unsigned char param_3, long param_4, long param_5)
{
    new_map(param_4, param_5);
    if (param_2 != 0) {
        param_2->reset_object_count();
    }
    set_terrain(param_1, param_2, 0, 0, param_4 - 1, param_5 - 1,
                param_3, 1, 0);
    if (param_2 != 0) {
        param_2->reset_player_visible_maps();
    }
}

void RGE_Map::new_map(long width, long height)
{
    int i;

    if (width <= 0 || height <= 0) {
        return;
    }

    if (this->map != 0) {
        if (this->game_world != 0) {
            int player_count = this->game_world->player_num;
            for (i = 0; i < player_count; ++i) {
                if (this->game_world->players != 0 &&
                    this->game_world->players[i] != 0) {
                    this->game_world->players[i]->objects->removeAllObjects();
                    this->game_world->players[i]->sleeping_objects->removeAllObjects();
                    this->game_world->players[i]->doppleganger_objects->removeAllObjects();
                }
            }
        }
        free(this->map);
    }

    if (this->search_map != 0) {
        free(this->search_map);
    }
    if (this->map_row_offset != 0) {
        free(this->map_row_offset);
    }
    if (this->search_map_rows != 0) {
        free(this->search_map_rows);
    }

    this->map_width = width;
    this->map_height = height;
    this->world_width = this->tile_width * width;
    this->world_height = this->tile_height * height;
    this->map = (RGE_Tile*)calloc(height * width, sizeof(RGE_Tile));
    this->search_map = (unsigned char*)calloc(
        this->map_height * this->map_width, sizeof(unsigned char));
    this->map_row_offset = (RGE_Tile**)calloc(
        this->map_height + 1, sizeof(RGE_Tile*));
    this->search_map_rows = (unsigned char**)calloc(
        this->map_height + 1, sizeof(unsigned char*));

    for (i = 0; i < this->map_height; ++i) {
        this->map_row_offset[i] = this->map + i * this->map_width;
        this->search_map_rows[i] = this->search_map + i * this->map_width;
    }

    this->map_row_offset[this->map_height] = this->map;
    this->search_map_rows[this->map_height] = this->search_map;

    for (i = 0; i < this->map_height; ++i) {
        for (int j = 0; j < this->map_width; ++j) {
            this->map_row_offset[i][j].height = 1;
        }
    }

    this->set_map_screen_pos(0, 0, this->map_width - 1,
                             this->map_height - 1);

    if (this->map_zones != 0) {
        delete this->map_zones;
    }
    this->map_zones = new RGE_Zone_Map_List(this);

    if (this->unified_vis_map != 0) {
        delete this->unified_vis_map;
    }
    this->unified_vis_map = new RGE_Unified_Visible_Map(width, height);

    if (this->unit_manager != 0) {
        delete this->unit_manager;
    }
    this->unit_manager = new Visible_Unit_Manager(
        this->game_world->player_num, 0x40);
}

void RGE_Map::clear_map(unsigned char param_1, unsigned char param_2)
{
    for (long y = 0; y < this->map_height; ++y) {
        RGE_Tile* row = this->map_row_offset[y];
        for (long x = 0; x < this->map_width; ++x, ++row) {
            row->tile_type = 0;
            row->terrain_type = param_1;
            row->height = param_2;
            row->border_type = 0;
            row->border_shape = 0;
            row->screen_xpos = 0;
            row->screen_ypos = 0;
            row->last_drawn_as = 0;
            row->last_drawn_shape = 0xFF;
            row->draw_as = 0;
            row->draw_attribute = 0;
            row->last_drawn_shape2 = 0xFF;
        }
    }

    this->set_map_screen_pos(0, 0, this->map_width - 1,
                             this->map_height - 1);
}

void RGE_Map::request_redraw(int x0, int y0, int x1, int y1,
                             unsigned char val)
{
    RGE_Map* self = this;

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

    if (x1 >= 0 && y1 >= 0 && x0 < self->map_width &&
        y0 < self->map_height) {
        if (x0 < 0) x0 = 0;
        if (y0 < 0) y0 = 0;
        if (x1 >= self->map_width) x1 = self->map_width - 1;
        if (y1 >= self->map_height) y1 = self->map_height - 1;

        int row = y0;
        while (row <= y1) {
            RGE_Tile* tile = &self->map_row_offset[row][x0];
            if (x0 <= x1) {
                int count = x1 - x0 + 1;
                do {
                    tile->last_drawn_as = 0xCC;
                    tile->draw_attribute = val;
                    ++tile;
                    --count;
                } while (count != 0);
            }
            ++row;
        }
    }
}

void RGE_Map::clear_map_view_info()
{
    int iVar2;
    int iVar3 = 0;
    RGE_Tile* tile_row;

    if (0 < this->map_height) {
        do {
            iVar2 = 0;
            tile_row = this->map_row_offset[iVar3];
            if (0 < this->map_width) {
                unsigned char* puVar1 = &tile_row->last_drawn_shape;
                do {
                    puVar1[-1] = 0;
                    *puVar1 = 0xff;
                    puVar1[1] = 0;
                    puVar1[2] = 0;
                    puVar1[3] = 0xff;
                    puVar1 += 0x18;
                    iVar2 = iVar2 + 1;
                } while (iVar2 < this->map_width);
            }
            iVar3 = iVar3 + 1;
        } while (iVar3 < this->map_height);
    }
}

void RGE_Map::coordinate_map()
{
    this->set_map_screen_pos(0, 0, this->map_width - 1,
                             this->map_height - 1);
}

void RGE_Map::set_map_screen_pos(int col0, int row0, int col1, int row1)
{
    if (col0 < 0) {
        col0 = 0;
    } else if (col0 > this->map_width - 1) {
        col0 = this->map_width - 1;
    }

    if (row0 < 0) {
        row0 = 0;
    } else if (row0 > this->map_height - 1) {
        row0 = this->map_height - 1;
    }

    if (col1 < 0) {
        col1 = 0;
    } else if (col1 > this->map_width - 1) {
        col1 = this->map_width - 1;
    }

    if (row1 < 0) {
        row1 = 0;
    } else if (row1 > this->map_height - 1) {
        row1 = this->map_height - 1;
    }

    for (; row0 <= row1; ++row0) {
        RGE_Tile* tile = this->map_row_offset[row0] + col0;
        for (int col = col0; col <= col1; ++tile, ++col) {
            tile->screen_xpos = (short)(row0 + col) * this->tile_half_width;
            tile->screen_ypos = (short)(row0 - col) * this->tile_half_height
                - (short)(tile->height) * this->elev_height;

            switch (tile->tile_type) {
            case 2:
            case 6:
            case 8:
            case 10:
            case 14:
            case 15:
            case 16:
                tile->screen_ypos -= this->elev_height;
                break;
            }
        }
    }
}

void RGE_Map::scenario_save(int file)
{
    RGE_Map* map = this;
    rge_write(file, &map->map_width, 4);

    long* height = &map->map_height;
    rge_write(file, height, 4);

    long height_count = *height;
    short y = 0;
    unsigned char overlay_info;
    unsigned char height_info;
    unsigned char local_bytes[2];

    if (height_count > 0) {
        do {
            short x = 0;
            if (height_count > 0) {
                do {
                    overlay_info = map->map_row_offset[y][x].terrain_type & 0x1f;
                    height_info = map->map_row_offset[y][x].height;
                    local_bytes[0] = height_info;
                    local_bytes[1] = 0;
                    rge_write(file, &overlay_info, 1);
                    rge_write(file, local_bytes, 1);
                    rge_write(file, local_bytes + 1, 1);
                    ++x;
                } while (x < *height);
            }
            height_count = *height;
            ++y;
        } while (y < height_count);
    }
}

void RGE_Map::scenario_load(int file, unsigned char* param2)
{
    int iVar3 = file;
    long local_4;
    long width;

    rge_read(file, &local_4, 4);
    rge_read(file, &width, 4);
    this->new_map(local_4, width);

    long height_count = this->map_height;
    long h = 0;
    if (height_count > 0) {
        do {
            int i = 0;
            long y = 0;
            if (height_count > 0) {
                short x = (short)h;
                do {
                    unsigned char overlay_info;
                    unsigned char height_info;
                    unsigned char unused_info;

                    rge_read(iVar3, &overlay_info, 1);
                    rge_read(iVar3, &height_info, 1);
                    rge_read(iVar3, &unused_info, 1);

                    this->map_row_offset[x][i].terrain_type = overlay_info;
                    this->map_row_offset[x][i].height = height_info;

                    y = y + 1;
                    i = (int)(short)y;
                } while (i < this->map_height);
            }
            height_count = this->map_height;
            ++h;
        } while ((short)h < height_count);
    }

    this->set_elev(0, 0, (short)this->map_width - 1,
                   (short)this->map_height - 1, 0, 0, 0);
    this->set_terrain(0, 0, 0, 0, (short)this->map_width - 1,
                      (short)this->map_height - 1, 0, 0, 0);
}

RGE_Tile** RGE_Map::give_up_map_offsets()
{
    return this->map_row_offset;
}

long RGE_Map::get_map_width()
{
    return this->map_width;
}

long RGE_Map::get_map_height()
{
    return this->map_height;
}

unsigned char RGE_Map::postclean_elevation(long x0, long y0, long x1,
                                            long y1, unsigned char elevation)
{
    int last_row;
    int last_col;
    short width;
    bool bad;
    bool neighbor_bad;
    int x;
    unsigned char tile_byte;
    unsigned short next_elevation;
    RGE_Tile* tile;
    long changed;
    short offset3;
    short offset2;
    short offset1;

    width = (short)this->map_width;
    offset3 = (short)(-1 - width);
    offset2 = (short)(1 - width);
    offset1 = (short)(-width);
    changed = 0;

    if (x0 > 0) --x0;
    if (y0 > 0) --y0;
    if (x1 < this->map_width - 1) ++x1;
    if (y1 < this->map_height - 1) ++y1;

    do {
        if (y1 < y0)
            return (unsigned char)changed;

        tile = this->map_row_offset[y0] + x0;
        for (x = (int)x0; x <= x1; ++x) {
            neighbor_bad = false;
            bad = false;
            tile_byte = tile->height;
            next_elevation = (unsigned short)tile_byte;

            if (next_elevation < elevation) {
                ++next_elevation;
                if (y0 > 0 && next_elevation <
                    (unsigned short)(tile[offset1].height))
                    neighbor_bad = true;
                last_row = this->map_height - 1;
                if (y0 < last_row && next_elevation <
                    (unsigned short)(tile[width].height))
                    neighbor_bad = true;
                if (x > 0 && next_elevation <
                    (unsigned short)(tile[-1].height))
                    neighbor_bad = true;
                last_col = this->map_width - 1;
                if (x < last_col && next_elevation <
                    (unsigned short)(tile[1].height))
                    neighbor_bad = true;
                bad = neighbor_bad;
                if (y0 > 0) {
                    if (x > 0 && next_elevation <
                        (unsigned short)(tile[offset3].height))
                        neighbor_bad = true;
                    bad = neighbor_bad;
                    if (x < last_col && next_elevation <
                        (unsigned short)(tile[offset2].height))
                        bad = true;
                }
                if (y0 < last_row) {
                    if (x > 0 && next_elevation <
                        (unsigned short)(tile[width - 1].height))
                        bad = true;
                    if (x < last_col && next_elevation <
                        (unsigned short)(tile[width + 1].height))
                        bad = true;
                }
            } else if (elevation < next_elevation) {
                next_elevation = (unsigned short)(next_elevation - 1);
                if (y0 > 0 && (short)(unsigned short)
                    (tile[offset1].height) < (short)next_elevation)
                    bad = true;
                last_row = this->map_height - 1;
                if (y0 < last_row && (short)(unsigned short)
                    (tile[width].height) < (short)next_elevation)
                    bad = true;
                if (x > 0 && (short)(unsigned short)
                    (tile[-1].height) < (short)next_elevation)
                    bad = true;
                last_col = this->map_width - 1;
                if (x < last_col && (short)(unsigned short)
                    (tile[1].height) < (short)next_elevation)
                    bad = true;
                if (y0 > 0) {
                    if (x > 0 && (short)(unsigned short)
                        (tile[offset3].height) < (short)next_elevation)
                        bad = true;
                    if (x < last_col && (short)(unsigned short)
                        (tile[offset2].height) < (short)next_elevation)
                        bad = true;
                }
                if (y0 < last_row) {
                    if (x > 0 && (short)(unsigned short)
                        (tile[width - 1].height) < (short)next_elevation)
                        bad = true;
                    if (x < last_col && (short)(unsigned short)
                        (tile[width + 1].height) < (short)next_elevation)
                        bad = true;
                }
            }

            if (bad) {
                changed = 1;
                tile->height = (unsigned char)next_elevation;
            }
            ++tile;
        }
        ++y0;
    } while (true);
}

void RGE_Map::preclean_elevation(long x1, long y1, long x2, long y2,
                                  unsigned char max_elevation)
{
    short width = (short)this->map_width;
    short offset_northwest = -1 - width;
    short offset_north = -width;
    short offset_northeast = 1 - width;
    short offset_southeast = width + 1;
    short offset_southwest = width - 1;
    short offset_south = width;
    long index2;
    long index1;
    unsigned char change_flag;

    do {
        change_flag = 0;
        if (x1 > 0) --x1;
        if (y1 > 0) --y1;
        if (x2 < this->map_width - 1) ++x2;
        if (y2 < this->map_height - 1) ++y2;

        for (index2 = y1; index2 <= y2; ++index2) {
            RGE_Tile* tile = this->map_row_offset[index2] + x1;
            for (index1 = x1; index1 <= x2; ++tile, ++index1) {
                unsigned char tile_byte = tile->height;
                short northwest = 0;
                short northeast = 0;
                short east = 0;
                short southeast = 0;
                short south = 0;
                short southwest = 0;
                short west = 0;
                short north = 0;
                short elevation = (short)tile_byte;

                if (index2 > 0 && (tile + offset_north)->height > elevation)
                    north = 1;
                if (index2 < this->map_height - 1 &&
                    (tile + offset_south)->height > elevation)
                    south = 1;
                if (index1 > 0 && tile[-1].height > elevation)
                    west = 1;
                if (index1 < this->map_width - 1 &&
                    tile[1].height > elevation)
                    east = 1;
                if (index2 > 0) {
                    if (index1 > 0 &&
                        (tile + offset_northwest)->height > elevation)
                        northwest = 1;
                    if (index1 < this->map_width - 1 &&
                        (tile + offset_northeast)->height > elevation)
                        northeast = 1;
                }
                if (index2 < this->map_height - 1) {
                    if (index1 > 0 &&
                        (tile + offset_southwest)->height > elevation)
                        southwest = 1;
                    if (index1 < this->map_width - 1 &&
                        (tile + offset_southeast)->height > elevation)
                        southeast = 1;
                }

                unsigned char conflict = 0;
                if (north && south) conflict = 1;
                if (east && west) conflict = 1;
                if (conflict) {
                    if (elevation >= max_elevation) {
                        if (northwest)
                            (tile + offset_northwest)->height =
                                (unsigned char)elevation;
                        if (north)
                            (tile + offset_north)->height =
                                (unsigned char)elevation;
                        if (northeast)
                            (tile + offset_northeast)->height =
                                (unsigned char)elevation;
                        if (east)
                            tile[1].height = (unsigned char)elevation;
                        if (southeast)
                            (tile + offset_southeast)->height =
                                (unsigned char)elevation;
                        if (south)
                            (tile + offset_south)->height =
                                (unsigned char)elevation;
                        if (southwest)
                            (tile + offset_southwest)->height =
                                (unsigned char)elevation;
                        if (west)
                            tile[-1].height = (unsigned char)elevation;
                    } else {
                        tile->height = (unsigned char)(elevation + 1);
                    }
                    change_flag = 1;
                }
            }
        }
    } while (change_flag);
}

void RGE_Map::clean_elevation(long x1, long y1, long x2, long y2,
                              unsigned char elevation)
{
    unsigned char change_flag;
    short width = (short)this->map_width;
    short offset_nw = (short)(-1 - width);
    short offset_n = (short)-width;
    short offset_ne = (short)(1 - width);
    short offset_se = (short)(width + 1);
    short offset_sw = (short)(width - 1);

    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
    if (x2 >= this->map_width) x2 = this->map_width - 1;
    if (y2 >= this->map_height) y2 = this->map_height - 1;

    do {
        change_flag = 0;
        x1 -= 2;
        y1 -= 2;
        x2 += 2;
        y2 += 2;

        if (x1 < 0) x1 = 0;
        if (y1 < 0) y1 = 0;
        if (x2 >= this->map_width) x2 = this->map_width - 1;
        if (y2 >= this->map_height) y2 = this->map_height - 1;

        this->preclean_elevation(x1, y1, x2, y2, elevation);

        for (long row = y1; row <= y2; ++row) {
            RGE_Tile* tile = this->map_row_offset[row] + x1;
            for (long col = x1; col <= x2; ++tile, ++col) {
                short north_west = 0;
                short north = 0;
                short north_east = 0;
                short east = 0;
                short south_east = 0;
                short south = 0;
                short south_west = 0;
                short west = 0;
                short current = (short)(tile->height);

                if (row > 0 && (tile[offset_n].height) > current)
                    north = 1;
                if (row < this->map_height - 1 &&
                    (tile[width].height) > current)
                    south = 1;
                if (col > 0 && (tile[-1].height) > current)
                    west = 1;
                if (col < this->map_width - 1 &&
                    (tile[1].height) > current)
                    east = 1;
                if (row > 0) {
                    if (col > 0 &&
                        (tile[offset_nw].height) > current)
                        north_west = 1;
                    if (col < this->map_width - 1 &&
                        (tile[offset_ne].height) > current)
                        north_east = 1;
                }
                if (row < this->map_height - 1) {
                    if (col > 0 &&
                        (tile[offset_sw].height) > current)
                        south_west = 1;
                    if (col < this->map_width - 1 &&
                        (tile[offset_se].height) > current)
                        south_east = 1;
                }

                bool fix = false;
                if (north_west) {
                    if ((north_east && !north) || (east && !north_east) ||
                        (south_west && !west) || (south && !south_west) ||
                        ((south_east && !south) && !east)) fix = 1;
                }
                if (north_east && !fix) {
                    if ((south_east && !east) || (south && !south_east) ||
                        (north_west && !north) || (west && !north_west) ||
                        (south_west && !west && !south)) fix = 1;
                }
                if (south_east && !fix) {
                    if ((south_west && !south) || (west && !south_west) ||
                        (north_east && !east) || (north && !north_east) ||
                        (north_west && !north && !west)) fix = 1;
                }
                if (south_west && !fix) {
                    if (north_west && !west) fix = 1;
                    else if (north && !north_west) fix = 1;
                    else if (south_east && !south) fix = 1;
                    else if (east && !south_east) fix = 1;
                    else if (north_east && !east && !north) fix = 1;
                }

                if (fix) {
                    if (current >= elevation) {
                        if (north_west)
                            (tile + offset_nw)->height =
                                (unsigned char)current;
                        if (north)
                            (tile + offset_n)->height =
                                (unsigned char)current;
                        if (north_east)
                            (tile + offset_ne)->height =
                                (unsigned char)current;
                        if (east)
                            tile[1].height = (unsigned char)current;
                        if (south_east)
                            (tile + offset_se)->height =
                                (unsigned char)current;
                        if (south)
                            (tile + width)->height =
                                (unsigned char)current;
                        if (south_west)
                            (tile + offset_sw)->height =
                                (unsigned char)current;
                        if (west)
                            tile[-1].height = (unsigned char)current;
                    } else {
                        tile->height = (unsigned char)(current + 1);
                    }
                    change_flag = 1;
                }
            }
        }

        if (this->postclean_elevation(x1, y1, x2, y2, elevation) != 0)
            change_flag = 1;
        if (!change_flag) {
            this->set_elev((short)x1, (short)y1, (short)x2, (short)y2,
                           0, 0, 0);
            return;
        }
    } while (true);
}

void RGE_Map::clean_terrain(long x1, long y1, long x2, long y2,
                            unsigned char terrain)
{
    short map_width = (short)this->map_width;
    short offset_nw = (short)(-1 - map_width);
    short offset_n = (short)-map_width;
    short offset_ne = (short)(1 - map_width);
    short offset_se = (short)(map_width + 1);
    short offset_sw = (short)(map_width - 1);

    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
    if (x2 >= this->map_width) x2 = this->map_width - 1;
    if (y2 >= this->map_height) y2 = this->map_height - 1;

    bool changed;
    do {
        changed = 0;
        if (x1 > 0) --x1;
        if (y1 > 0) --y1;
        if (x2 < this->map_width - 1) ++x2;
        if (y2 < this->map_height - 1) ++y2;

        int pass = 0;
        do {
            for (int row = y1; row <= y2; ++row) {
                RGE_Tile* tile = this->map_row_offset[row] + x1;
                for (int col = x1; col <= x2; ++tile, ++col) {
                    if ((tile->terrain_type & 0x1f) != terrain) {
                        short north_west = 0;
                        short north = 0;
                        short north_east = 0;
                        short east = 0;
                        short south_east = 0;
                        short south = 0;
                        short south_west = 0;
                        short west = 0;
                        unsigned char fix;

                        if (row > 0 &&
                            (tile[offset_n].terrain_type & 0x1f) == terrain)
                            north = 1;
                        if (row < this->map_height - 1 &&
                            (tile[map_width].terrain_type & 0x1f) == terrain)
                            south = 1;
                        if (col > 0 &&
                            (tile[-1].terrain_type & 0x1f) == terrain)
                            west = 1;
                        if (col < this->map_width - 1 &&
                            (tile[1].terrain_type & 0x1f) == terrain)
                            east = 1;

                        if (pass == 1) {
                            if (row > 0) {
                                if (col > 0 &&
                                    (tile[offset_nw].terrain_type & 0x1f) == terrain)
                                    north_west = 1;
                                if (col < this->map_width - 1 &&
                                    (tile[offset_ne].terrain_type & 0x1f) == terrain)
                                    north_east = 1;
                            }
                            if (row < this->map_height - 1) {
                                if (col > 0 &&
                                    (tile[offset_sw].terrain_type & 0x1f) == terrain)
                                    south_west = 1;
                                if (col < this->map_width - 1 &&
                                    (tile[offset_se].terrain_type & 0x1f) == terrain)
                                    south_east = 1;
                            }
                        }

                        fix = 0;
                        if (pass == 0) {
                            if ((north && south) || (east && west)) fix = 1;
                        } else {
                            if (north_west) {
                                if ((north_east && !north) ||
                                    (east && !north_east) ||
                                    (south_west && !west) ||
                                    (south && !south_west) ||
                                    ((south_east && !south) && !east)) fix = 1;
                            }
                            if (north_east && !fix) {
                                if ((north_west && !north) ||
                                    (west && !north_west) ||
                                    (south_east && !east) ||
                                    (south && !south_east) ||
                                    (south_west && !west && !south)) fix = 1;
                            }
                            if (south_east && !fix) {
                                if ((north_east && !east) ||
                                    (north && !north_east) ||
                                    (south_west && !south) ||
                                    (west && !south_west) ||
                                    (north_west && !west && !north)) fix = 1;
                            }
                            if (south_west && !fix) {
                                if ((north_west && !west) ||
                                    (north && !north_west) ||
                                    (south_east && !south) ||
                                    (east && !south_east) ||
                                    (north_east && !east && !north)) fix = 1;
                            }
                        }

                        if (fix) {
                            this->set_terrain(this->game_world, col, row,
                                              terrain, 0, 0);
                            changed = 1;
                        }
                    }
                }
            }
            ++pass;
        } while (pass < 2);

        if (!changed) return;
    } while (true);
}

void RGE_Map::clean_borders(long p0, long p1, long p2, long p3)
{
}

long RGE_Map::clean_border_tile(long p0, long p1, long (* const p2)[32])
{
    return -1;
}

unsigned char RGE_Map::do_terrain_brush(long x, long y, long radius,
                                        unsigned char terrain)
{
    long rad = radius;
    long x1 = x - rad;
    long x2 = x + rad;
    long y1 = y - rad;
    long y2 = y + rad;

    if (x1 < 0) x1 = 0;
    if (x2 >= this->map_width) x2 = this->map_width - 1;
    if (y1 < 0) y1 = 0;
    if (y2 >= this->map_height) y2 = this->map_height - 1;

    long row = y1;
    while (row <= y2) {
        long col = x1;
        while (col <= x2) {
            this->set_terrain(this->game_world, col, row, terrain, 0, 0);
            ++col;
        }
        ++row;
    }
    return 1;
}

unsigned char RGE_Map::do_terrain_brush_stroke(long x0, long y0, long x1,
                                                long y1, long radius,
                                                unsigned char terrain)
{
    radius >>= 1;
    if (x0 < 0) x0 = 0;
    if (x1 >= this->map_width) x1 = this->map_width - 1;
    if (y0 < 0) y0 = 0;
    if (y1 >= this->map_height) y1 = this->map_height - 1;

    long x_distance = x1 - x0;
    long y_distance = y1 - y0;
    long index;
    double step_x;
    double step_y;
    double x;
    double y;
    index = (long)sqrt((double)x_distance * x_distance +
                       (double)y_distance * y_distance);
    step_x = (double)x_distance / (double)index;
    step_y = (double)y_distance / (double)index;
    x = (double)x0;
    y = (double)y0;

    this->do_terrain_brush(x0, y0, radius, terrain);
    if (index > 0) {
        long count = index;
        do {
            x = step_x + x;
            y = step_y + y;
            this->do_terrain_brush((long)x, (long)y, radius, terrain);
            --count;
        } while (count != 0);
    }
    if ((double)x1 != x || (double)y1 != y)
        this->do_terrain_brush(x1, y1, radius, terrain);
    return 1;
}

unsigned char RGE_Map::do_elevation_brush(long x, long y, long radius,
                                           unsigned char elevation)
{
    long minx = x - radius;
    long maxx = x + radius;
    long miny = y - radius;
    long maxy = y + radius;
    if (minx < 0) minx = 0;
    if (maxx >= this->map_width) maxx = this->map_width - 1;
    if (miny < 0) miny = 0;
    if (maxy >= this->map_height) maxy = this->map_height - 1;
    for (long row = miny; row <= maxy; ++row) {
        if (minx <= maxx) {
            for (long col = minx; col <= maxx; ++col)
                this->map_row_offset[row][col].height = elevation;
        }
    }
    return 1;
}

unsigned char RGE_Map::do_elevation_brush_stroke(long x0, long y0, long x1,
                                                  long y1, long radius,
                                                  unsigned char elevation)
{
    radius >>= 1;
    if (x0 < 0) x0 = 0;
    if (x1 >= this->map_width) x1 = this->map_width - 1;
    if (y0 < 0) y0 = 0;
    if (y1 >= this->map_height) y1 = this->map_height - 1;

    long x_distance = x1 - x0;
    long y_distance = y1 - y0;
    long index;
    double step_x;
    double step_y;
    double x;
    double y;
    index = (long)sqrt((double)x_distance * x_distance +
                       (double)y_distance * y_distance);
    step_x = (double)x_distance / (double)index;
    step_y = (double)y_distance / (double)index;
    x = (double)x0;
    y = (double)y0;

    this->do_elevation_brush(x0, y0, radius, elevation);
    if (index > 0) {
        long count = index;
        do {
            x = step_x + x;
            y = step_y + y;
            this->do_elevation_brush((long)x, (long)y, radius, elevation);
            --count;
        } while (count != 0);
    }
    if ((double)x1 != x || (double)y1 != y)
        this->do_elevation_brush(x1, y1, radius, elevation);

    if (x0 < x1) {
        x0 -= radius;
        x1 += radius;
    } else {
        long temp_x = x0;
        x0 = x1 - radius;
        x1 = temp_x + radius;
    }
    if (y0 < y1) {
        y0 -= radius;
        y1 += radius;
    } else {
        long temp_y = y0;
        y0 = y1 - radius;
        y1 = temp_y + radius;
    }
    this->clean_elevation(x0, y0, x1, y1, elevation);
    return 1;
}

unsigned char RGE_Map::do_cliff_brush(long p0, long p1, unsigned char p2,
                                      unsigned char p3)
{
    return 0;
}

unsigned char RGE_Map::do_cliff_brush_stroke(long x0, long y0, long x1,
                                              long y1, unsigned char a,
                                              unsigned char b)
{
    if (x0 < 0) x0 = 0;
    if (x1 >= this->map_width) x1 = this->map_width - 1;
    if (y0 < 0) y0 = 0;
    if (y1 >= this->map_height) y1 = this->map_height - 1;

    long x_distance = x1 - x0;
    long y_distance = y1 - y0;
    long index;
    double step_x;
    double step_y;
    double x;
    double y;
    index = (long)sqrt((double)x_distance * x_distance +
                       (double)y_distance * y_distance);
    step_x = (double)x_distance / (double)index;
    step_y = (double)y_distance / (double)index;
    x = (double)x0;
    y = (double)y0;

    this->do_cliff_brush(x0, y0, a, b);
    if (index > 0) {
        long count = index;
        do {
            x = step_x + x;
            y = step_y + y;
            this->do_cliff_brush((long)x, (long)y, a, b);
            --count;
        } while (count != 0);
    }
    if ((double)x1 != x || (double)y1 != y)
        this->do_cliff_brush(x1, y1, a, b);
    return 1;
}

void RGE_Map::map_generate(RGE_Player* p0, RGE_Game_World* p1,
                           RGE_Player_Info* p2, unsigned char* p3)
{
}

void RGE_Map::map_generate2(RGE_Game_World* param_1, long param_2,
                            long param_3, unsigned char param_4, long param_5)
{
    unsigned char old_state = this->game_world->game_state;
    this->game_world->game_state = 3;

    int seed = rge_base_game->random_map_seed;
    if (seed == -1)
        seed = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x5CE);

    rge_base_game->save_random_map_seed = seed;
    L->Log("Random Map Seed = %d", seed);

    debug_srand((char*)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x5DA, seed);
    this->clear_map(0, param_1, 0, param_2, param_3);

    debug_srand((char*)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x5DD, seed);
    this->random_map->init(this, param_1, param_4, param_5, 1);

    debug_srand((char*)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x5E0, seed);
    this->random_map->generate();
    this->random_map->de_init();

    int after_seed = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x5E5);
    L->Log("After Random Map Generation random number is %d", after_seed);

    this->game_world->game_state = old_state;
}

void RGE_Map::load_map(int file)
{
    long local_10;
    long width;
    unsigned char value;

    rge_read(file, &local_10, 4);
    rge_read(file, &width, 4);
    this->new_map(local_10, width);

    RGE_Zone_Map_List* old_zones = this->map_zones;
    if (old_zones != 0)
        delete old_zones;

    RGE_Zone_Map_List* zones = new RGE_Zone_Map_List(file, this);
    this->map_zones = zones;

    rge_read(file, &this->map_visible_flag, 1);
    rge_read(file, &this->fog_flag, 1);

    if (!(save_game_version < old_map_cutoff)) {
        long h = 0;
        if (this->map_height > 0) {
            do {
                RGE_Tile* tile = this->map_row_offset[h];
                int y = 0;
                if (this->map_width > 0) {
                    do {
                        rge_read(file, tile, 2);
                        rge_read(file, &tile->screen_ypos, 2);
                        rge_read(file, &tile->tile_type, 1);

                        rge_read(file, &value, 1);
                        tile->terrain_type = value;
                        rge_read(file, &value, 1);
                        tile->height = value;

                        rge_read(file, &value, 1);
                        tile->border_type = value;
                        rge_read(file, &value, 1);
                        tile->border_shape = value;
                        tile->last_drawn_as = 0;
                        tile->last_drawn_shape = 0xff;
                        tile->draw_as = 0;
                        tile->draw_attribute = 0;
                        tile->objects.list = 0;
                        tile->objects.number_of_objects = 0;
                        tile->last_drawn_shape2 = 0xff;

                        ++tile;
                        ++y;
                    } while (y < this->map_width);
                }
                ++h;
            } while (h < this->map_height);
        }
    } else {
        rge_read(file, this->map,
                 this->map_width * this->map_height * 0x18);
        long h = 0;
        if (this->map_height > 0) {
            do {
                int y = 0;
                if (this->map_width > 0) {
                    do {
                        this->map_row_offset[h][y].objects.list = 0;
                        ++y;
                    } while (y < this->map_width);
                }
                ++h;
            } while (h < this->map_height);
        }
    }

    this->unified_vis_map->load(file);
}

void RGE_Map::save_map(int file)
{
    int handle = file;
    RGE_Map* map = this;
    long* width = &map->map_width;
    rge_write(handle, width, 4);

    long* height = &map->map_height;
    rge_write(handle, height, 4);
    map->map_zones->save(handle);
    rge_write(handle, &map->map_visible_flag, 1);
    rge_write(handle, &map->fog_flag, 1);

    if (!(save_game_version < DAT_005706a8)) {
        int y = 0;
        if (*height > 0) {
            do {
                int x = 0;
                RGE_Tile* tile = map->map_row_offset[y];
                if (map->map_width > 0) {
                    do {
                        rge_write(handle, tile, 2);
                        rge_write(handle, &tile->screen_ypos, 2);
                        rge_write(handle, &tile->tile_type, 1);

                        unsigned char value = tile->terrain_type & 0x1f;
                        rge_write(handle, &value, 1);
                        value = tile->height;
                        rge_write(handle, &value, 1);
                        value = tile->border_type & 0x0f;
                        rge_write(handle, &value, 1);
                        value = tile->border_shape;
                        rge_write(handle, &value, 1);

                        ++tile;
                        ++x;
                    } while (x < map->map_width);
                }
                y++;
            } while (y < *height);
        }
    } else {
        int tile_count = *height;
        tile_count *= this->map_width;
        rge_write(handle, this->map, tile_count * 0x18);
    }

    map->unified_vis_map->save(handle);
}

void RGE_Map::save(int file)
{
    RGE_Map* copy = (RGE_Map*)calloc(1, sizeof(RGE_Map));
    *copy = *this;
    int i;

    for (i = 0; i < 32; ++i) {
        if (this->terrain_types[i].loaded != 0 &&
            this->terrain_types[i].sound != 0) {
            copy->terrain_types[i].sound =
                (RGE_Sound*)this->terrain_types[i].sound->id;
        } else {
            copy->terrain_types[i].sound = (RGE_Sound*)-1;
        }
    }

    for (i = 0; i < 16; ++i) {
        if (this->border_types[i].loaded != 0 &&
            this->border_types[i].sound != 0) {
            copy->border_types[i].sound =
                (RGE_Sound*)this->border_types[i].sound->id;
        } else {
            copy->border_types[i].sound = (RGE_Sound*)-1;
        }
    }

    rge_write(file, copy, 0x8dd0);
    this->random_map->save(file);
    free(copy);
}

void RGE_Map::load_terrain_types(RGE_Sound** sounds)
{
    char* filename2 = 0;
    long* resource_id = &this->terrain_types[31].resource_id;
    int count = 0x20;

    do {
        RGE_Tile_Set* tile_set = (RGE_Tile_Set*)(resource_id - 7);
        if (tile_set->loaded != 0) {
            addstring(&filename2, tile_set->pict_name, (char*)".shp");
            tile_set->shape = new TShape(filename2, *resource_id);
            if (tile_set->shape->is_loaded() == 0)
                tile_set->loaded = 0;
            if ((long)tile_set->sound >= 0)
                tile_set->sound = sounds[(long)tile_set->sound];
            else
                tile_set->sound = 0;
        }
        resource_id -= 0x66;
        --count;
    } while (count != 0);

    if (filename2 != 0)
        free(filename2);
}

void RGE_Map::load_terrain_types(char* filename, RGE_Sound** sounds)
{
    int i;
    for (i = 31; i >= 0; --i)
        this->terrain_types[i].loaded = 0;

    FILE* local_38 = fopen(filename, "r");
    if (local_38 != 0) {
        fscanf(local_38, (char*)"%hd", &this->num_terrain);
        short terrain_count = this->num_terrain - 1;
        if (terrain_count >= 0) {
            int resource_id = (int)terrain_count + 1;
            do {
                short border_num;
                short sound_id;
                short border;
                short low_color;
                short med_color;
                short hi_color;
                short lt_cliff_color;
                short rt_cliff_color;
                short impassable_terrain;
                short passable_terrain;
                short row;
                short col;
                short is_animated;
                short animation_frames;
                short terrain_to_draw;
                short random;
                float interval;
                float infile;
                float local_30;
                long local_28;
                short terrain_id;
                char name[13];
                char pict_name[13];
                int i2;
                RGE_TOB_Picts* tile;

                if (fscanf(local_38,
                    (char*)"%hd %s %s %d %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd %hd %hd %hd %hd %hd",
                    &terrain_id, name, pict_name, &local_28,
                    &border_num, &lt_cliff_color, &rt_cliff_color, &hi_color,
                    &med_color, &terrain_to_draw, &random, &infile,
                    &local_30, &interval, &is_animated, &animation_frames,
                    &impassable_terrain, &passable_terrain, &row, &col,
                    &sound_id) != -1) {
                    if (terrain_id < 32 && terrain_id >= 0) {
                        RGE_Tile_Set* terrain = &this->terrain_types[terrain_id];
                        short shape_index = 0;
                        int tile_count = 19;
                        tile = terrain->tiles;
                        do {
                            fscanf(local_38, "%hd %hd", &tile->count,
                                   &tile->animations);
                            tile->shape_index = shape_index;
                            shape_index += tile->count * tile->animations;
                            ++tile;
                            --tile_count;
                        } while (tile_count != 0);

                        i2 = 0;
                        if (sound_id > 0) {
                            do {
                                fscanf(local_38, "%hd %hd", &border,
                                       &low_color);
                                terrain->borders[border] = low_color;
                                ++i2;
                            } while (i2 < sound_id);
                        }

                        if (med_color < 0)
                            terrain->sound = 0;
                        else
                            terrain->sound = sounds[med_color];
                        terrain->map_low_color = (unsigned char)hi_color;
                        terrain->map_med_color = (unsigned char)lt_cliff_color;
                        terrain->map_hi_color = (unsigned char)rt_cliff_color;
                        terrain->map_lt_cliff_color =
                            (unsigned char)impassable_terrain;
                        terrain->map_rt_cliff_color =
                            (unsigned char)passable_terrain;
                        terrain->impassable_terrain = (unsigned char)row;
                        terrain->passable_terrain = (unsigned char)col;
                        convert_us(name);
                        strcpy(terrain->name, name);
                        strcpy(terrain->pict_name, pict_name);
                        terrain->animate_last = 0.0f;
                        terrain->resource_id = local_28;
                        terrain->loaded = 1;
                        terrain->rows = is_animated;
                        terrain->cols = animation_frames;
                        terrain->is_animated = (unsigned char)terrain_to_draw;
                        terrain->animation_frames = random;
                        if (infile == 0.0f)
                            terrain->pause_frames = 0;
                        else
                            terrain->pause_frames = (short)(local_30 / infile);
                        terrain->interval = infile;
                        terrain->frame = 0;
                        terrain->pause_between_loops = local_30;
                        terrain->draw_frame = 0;
                        terrain->frame_changed = 0;
                        terrain->drawn = 0;
                        terrain->terrain_to_draw = sound_id;
                    }
                }
                --resource_id;
            } while (resource_id != 0);
        }
    }
    fclose(local_38);
}

void RGE_Map::load_border_types(RGE_Sound** sounds)
{
    char* filename2 = 0;
    long* resource_id = &this->border_types[15].resource_id;
    int count = 16;

    do {
        RGE_Border_Set* border = (RGE_Border_Set*)(resource_id - 7);
        if (border->loaded != 0) {
            addstring(&filename2, border->pict_name, (char*)".shp");
            TShape* shape = new TShape(filename2, *resource_id);
            border->shape = shape;
            if (shape->is_loaded() == 0)
                border->loaded = 0;
            if ((long)border->sound >= 0)
                border->sound = sounds[(long)border->sound];
            else
                border->sound = 0;
        }
        resource_id -= 0x168;
        --count;
    } while (count != 0);

    if (filename2 != 0)
        free(filename2);
}

void RGE_Map::load_border_types(char* filename, RGE_Sound** sounds)
{
    short sound_id;
    short low_color;
    short med_color;
    short hi_color;
    short is_animated;
    short animation_frames;
    short tile_flag;
    short underlay_terrain;
    short border_style;
    short random;
    short local_48;
    short local_46;
    RGE_TOB_Picts* p;
    RGE_TOB_Picts* row_start;
    float frame_rate;
    float pause_between_loops;
    FILE* infile;
    long resource_id;
    long local_28;
    char name[13];
    char pict_name[13];

    int i;
    for (i = 15; i >= 0; --i)
        this->border_types[i].loaded = 0;

    infile = fopen(filename, "r");
    if (infile != 0) {
        fscanf(infile, "%hd", &this->num_borders);
        short remaining = this->num_borders - 1;
        if (remaining >= 0) {
            resource_id = (int)remaining + 1;
            do {
                short border_num;
                short shape_index = 0;
                if (fscanf(infile,
                    "%hd %s %s %d %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd",
                    &border_num, name + 4, pict_name + 4, &local_28,
                    &local_46, &is_animated, &animation_frames, &hi_color,
                    &med_color, &tile_flag, &underlay_terrain, &frame_rate,
                    &pause_between_loops, &border_style, &random, &local_48) != -1 &&
                    border_num < 16 && border_num >= 0) {
                    RGE_Border_Set* border = &this->border_types[border_num];
                    p = border->borders[0];
                    for (int row = 0; row < 19; ++row) {
                        row_start = p;
                        for (int col = 0; col < 12; ++col) {
                            fscanf(infile, "%hd %hd", &p->count,
                                   &p->animations);
                            p->shape_index = shape_index;
                            shape_index += p->count * p->animations;
                            ++p;
                        }
                        p = row_start + 12;
                    }

                    if (med_color >= 0)
                        border->sound = sounds[med_color];
                    else
                        border->sound = 0;
                    border->map_low_color = (unsigned char)hi_color;
                    border->map_med_color = (unsigned char)is_animated;
                    border->map_hi_color = (unsigned char)animation_frames;
                    convert_us(name);
                    strcpy(border->name, name);
                    strcpy(border->pict_name, pict_name);
                    border->loaded = 1;
                    border->resource_id = local_28;
                    border->is_animated = (unsigned char)tile_flag;
                    border->animation_frames = underlay_terrain;
                    if (frame_rate == DAT_005706ac)
                        border->pause_frames = 0;
                    else
                        border->pause_frames =
                            (short)(long)(pause_between_loops / frame_rate);
                    border->interval = frame_rate;
                    border->pause_between_loops = pause_between_loops;
                    border->frame = 0;
                    border->draw_frame = 0;
                    border->animate_last = 0.0f;
                    border->frame_changed = 0;
                    border->drawn = 0;
                    border->draw_tile = (unsigned char)border_style;
                    border->underlay_terrain = random;
                    border->border_style = local_48;
                }
            } while (--resource_id != 0);
        }
    }
    fclose(infile);
}

void RGE_Map::load_terrain_obj_types(char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file != 0) {
        short num;
        short density;
        short flag;
        short obj_id;
        short id;

        fscanf(file, "%hd", &num);
        while (fscanf(file, "%hd %hd %hd %hd",
                      &id, &obj_id, &density, &flag) != EOF) {
            if (this->terrain_types[id].loaded != 0) {
                if (this->terrain_types[id].num_obj_type < 30) {
                    num = this->terrain_types[id].num_obj_type;
                    this->terrain_types[id].obj_types[num] = obj_id;
                    this->terrain_types[id].obj_density[num] = density;
                    this->terrain_types[id].obj_placement_flag[num] = flag;
                    ++this->terrain_types[id].num_obj_type;
                }
            }
        }
    }
    fclose(file);
}

void RGE_Map::delete_objects_on_tile(RGE_Player* player,
                                     RGE_Game_World* /*world*/, int x, int y,
                                     int min_id, int max_id)
{
    if (x < 0 || x >= this->map_width || y < 0 || y >= this->map_height)
        return;

    RGE_Object_Node* p = this->map_row_offset[y][x].objects.list;
    if (p == 0)
        return;

    while (p != 0) {
        RGE_Static_Object* obj = p->node;
        RGE_Object_Node* next = p->next;
        int obj_id = obj->master_obj->id;
        if (obj->owner == player) {
            if (obj_id < min_id || obj_id > max_id) {
                if (obj != 0)
                    delete obj;
            }
        }
        p = next;
    }
}

void RGE_Map::delete_all_objects_on_tile(int x, int y)
{
    if (x < 0 || x >= this->map_width)
        return;
    if (y < 0 || y >= this->map_height)
        return;

    RGE_Object_Node* node = this->map_row_offset[y][x].objects.list;
    while (node != 0) {
        RGE_Object_Node* next = node->next;
        RGE_Static_Object* object = node->node;
        if (object != 0)
            delete object;
        node = next;
    }
}

void RGE_Map::create_terrain_object(RGE_Player* player,
                                    RGE_Game_World* /*world*/, short row,
                                    short col, short new_terrain,
                                    int remove_now, int min_id, int max_id)
{
    float local_c = 0.0f;
    float x = 0.0f;
    short terrain = (short)this->get_terrain(col, row);
    short num_obj_type = this->terrain_types[terrain].num_obj_type;
    RGE_Object_Node* node;
    RGE_Static_Object* object;
    short object_id;

    if (num_obj_type > 0) {
        node = this->map_row_offset[row][col].objects.list;
        if (node != 0) {
            do {
                object = node->node;
                node = node->next;
                object_id = object->master_obj->id;
                if (object->owner == player &&
                    (object_id < min_id || object_id > max_id)) {
                    if (new_terrain < 0) {
                        if (remove_now != 0) {
                            if (object != 0)
                                delete object;
                        } else {
                            object->destroy_obj();
                        }
                    } else {
                        short replacement_count =
                            this->terrain_types[new_terrain].num_obj_type;
                        if (replacement_count >= 0) {
                            short* replacement_types =
                                this->terrain_types[new_terrain].obj_types;
                            do {
                                if (replacement_types[replacement_count] == object_id)
                                    break;
                                --replacement_count;
                            } while (replacement_count >= 0);
                            if (replacement_count >= 0) {
                                if (remove_now != 0) {
                                    if (object != 0)
                                        delete object;
                                } else {
                                    object->destroy_obj();
                                }
                            }
                        }
                    }
                }
            } while (node != 0);
        }

        if (num_obj_type > 0) {
            unsigned char* placement =
                this->terrain_types[terrain].obj_placement_flag;
            short* density = this->terrain_types[terrain].obj_density;
            int remaining = (int)num_obj_type;
            do {
                short object_type = density[-30];
                if (object_type != -1) {
                    short chance = *density;
                    RGE_Master_Static_Object* master =
                        player->master_objects[object_type];
                    unsigned char mode = *placement;
                    if (master != 0 && chance > 0) {
                        int chance_left = (int)chance;
                        do {
                            switch (mode) {
                            case 0:
                                local_c = (float)(int)col -
                                    (float)debug_rand(
                                        (char*)"C:\\msdev\\work\\age1_x1\\map.cpp",
                                        0x813) * -3.051851e-05f;
                                x = (float)(int)row -
                                    (float)debug_rand(
                                        (char*)"C:\\msdev\\work\\age1_x1\\map.cpp",
                                        0x814) * -3.051851e-05f;
                                break;
                            case 1:
                                local_c = (float)(int)col - -0.5f;
                                x = (float)(int)row - -0.5f;
                                break;
                            }

                            int place_it;
                            if (chance < 1000) {
                                int random_value = debug_rand(
                                    (char*)"C:\\msdev\\work\\age1_x1\\map.cpp",
                                    0x820);
                                place_it = (random_value * 1000) /
                                    0x7fff < chance_left;
                            } else {
                                place_it = 1;
                            }
                            if (place_it) {
                                if (!master->check_placement(player, local_c, x,
                                                       0, 0, 1, 0, 1, 0, 1))
                                    master->make_new_obj(player, local_c, x, 0);
                            }
                            chance -= 1000;
                            chance_left -= 1000;
                        } while (chance > 0);
                    }
                }
                ++density;
                ++placement;
                --remaining;
            } while (remaining != 0);
        }
    }
}

int RGE_Map::clear_terrain_object(RGE_Game_World* world, short col,
                                  short row, short old_terrain,
                                  int remove_now, int min_id, int max_id)
{
    short object_id;
    RGE_Object_Node* node;
    RGE_Object_Node* current_node;
    short object_type;
    RGE_Static_Object* object;

    this->get_terrain(row, col);
    node = this->map_row_offset[col][row].objects.list;
    short result = -1;

    while (node != 0) {
        current_node = node;
        object = current_node->node;
        node = current_node->next;
        object_id = object->master_obj->id;

        if (object_id >= min_id && object_id <= max_id)
            continue;

        if (old_terrain < 0) {
            if (remove_now != 0) {
                if (object != 0)
                    delete object;
            } else {
                object->destroy_obj();
            }
            continue;
        }

        result = object_id;
        object_type = this->terrain_types[old_terrain].num_obj_type;
        if (object_type >= 0) {
            do {
                if (this->terrain_types[old_terrain].obj_types[object_type] ==
                    object_id)
                    break;
                --object_type;
            } while (object_type >= 0);
        }

        if (object_type >= 0) {
            if (remove_now != 0) {
                if (object != 0)
                    delete object;
            } else {
                object->destroy_obj();
            }
            continue;
        }

        if (object->master_obj->check_placement(
                object->owner, object->world_x, object->world_y, 0,
                0, 1, 1, 1, 0, 0)) {
            if (remove_now != 0) {
                if (object != 0)
                    delete object;
            } else {
                object->destroy_obj();
            }
        }
    }

    return result;
}

void RGE_Map::place_terrain_object(RGE_Player* player,
                                   RGE_Game_World* world, short row, short col,
                                   int object_id, int single_placement)
{
    RGE_Master_Static_Object* master_obj;
    int num_obj_type;
    int terrain;
    terrain = this->get_terrain(col, row);
    num_obj_type = this->terrain_types[terrain].num_obj_type;
    int terrain_i = 0;
    float x;
    float y;

    for (terrain_i = 0; terrain_i < num_obj_type; ++terrain_i) {
        int object_type = (short)this->terrain_types[terrain].obj_types[terrain_i];
        if (object_type != -1) {
            master_obj = player->master_objects[object_type];
            short obj_density = this->terrain_types[terrain].obj_density[terrain_i];
            unsigned char obj_flag =
                this->terrain_types[terrain].obj_placement_flag[terrain_i];

            if (master_obj != 0) {
                if (single_placement == 0) {
                    if (obj_density > 0) {
                        int density_left = obj_density;
                        do {
                            if (obj_flag != 0) {
                                x = (float)(int)col - -0.5f;
                                y = (float)(int)row - -0.5f;
                            } else {
                                x = (float)(int)col -
                                    (float)debug_rand(
                                        (char*)"C:\\msdev\\work\\age1_x1\\map.cpp",
                                        0x894) * -3.051851e-05f;
                                y = (float)(int)row -
                                    (float)debug_rand(
                                        (char*)"C:\\msdev\\work\\age1_x1\\map.cpp",
                                        0x895) * -3.051851e-05f;
                            }

                            int place_it;
                            if (obj_density >= 1000) {
                                place_it = 1;
                            } else {
                                int random_value = debug_rand(
                                    (char*)"C:\\msdev\\work\\age1_x1\\map.cpp",
                                    0x8A2);
                                place_it = ((random_value * 1000) / 0x7fff) <
                                           density_left;
                            }

                            if (place_it) {
                                if (!master_obj->check_placement(
                                        player, x, y, 0, 0, 1, 0, 1, 0, 1))
                                    master_obj->make_new_obj(player, x, y, 0);
                            }
                            obj_density -= 1000;
                            density_left -= 1000;
                        } while (obj_density > 0);
                    }
                } else if (single_placement == 1) {
                    if (obj_flag != 0) {
                        x = (float)(int)col - -0.5f;
                        y = (float)(int)row - -0.5f;
                    } else {
                        x = (float)(int)col -
                            (float)debug_rand(
                                (char*)"C:\\msdev\\work\\age1_x1\\map.cpp",
                                0x8AF) * -3.051851e-05f;
                        y = (float)(int)row -
                            (float)debug_rand(
                                (char*)"C:\\msdev\\work\\age1_x1\\map.cpp",
                                0x8B0) * -3.051851e-05f;
                    }

                    if (!master_obj->check_placement(
                            player, x, y, 0, 0, 1, 0, 1, 0, 1)) {
                        master_obj->make_new_obj(player, x, y, 0);
                        return;
                    }
                }
            }
        }
    }
}

void RGE_Map::create_terrain_objects(RGE_Player* player,
                                     RGE_Game_World* world)
{
    short y = 0;
    short x = 0;

    if (this->map_height > 0) {
        do {
            x = 0;
            if (this->map_width > 0) {
                do {
                    this->create_terrain_object(player, world, y, x, -1, 0,
                                                -1, -1);
                    x++;
                } while (x < this->map_width);
            }
            y++;
        } while (y < this->map_height);
    }
}

void RGE_Map::set_tile_size(unsigned char index, short width, short height,
                            short y_delta)
{
    this->tilesizes[index].width = width;
    this->tilesizes[index].height = height;
    this->tilesizes[index].y_delta = y_delta;
}

void RGE_Map::tile_map_coords(short x, short y, RGE_Tile* tile,
                              float* out1, float* out2)
{
    double fx = (double)(int)x / (double)(int)this->tile_width;
    register float result;
    double raw_y = (double)(int)y;
    double fy = raw_y / (double)(int)this->tile_height;
    double z = 0.0;

    switch (tile->tile_type) {
    case 1:
        if (fx > DAT_005706c0)
            result = (fy + fy) - ((fx - DAT_005706c0) +
                                  (fx - DAT_005706c0));
        else
            result = (fy + fy) - ((DAT_005706c0 - fx) +
                                  (DAT_005706c0 - fx));
        goto z_result;
    case 2:
        if (fx > DAT_005706c0) {
            result = fx * DAT_005706d0 - (fy - DAT_005706c0);
            goto z_result;
        }
        goto tile_case8;
    case 3:
        if (fx * DAT_005706c0 < raw_y) {
            result = (DAT_005706d8 - fx) * DAT_005706c0 -
                     (fy - DAT_005706c0);
            goto z_result;
        }
        result = DAT_005706d8 - fx;
        fy = fy + fy;
        result = (result + result) - DAT_005706d8;
        goto add_fy;
    case 4:
        if ((DAT_005706d8 - fx) * DAT_005706c0 < raw_y) {
            result = fx * DAT_005706c0 - (fy - DAT_005706c0);
            goto z_result;
        }
        goto tile_case7;
    case 10:
        if (DAT_005706d8 <= fy)
            z = -1.0;
        else {
            result = -fy;
            goto z_result;
        }
        goto default_result;
    case 11:
        if (fx <= DAT_005706c0) {
            result = (DAT_005706c0 - fx) + (DAT_005706c0 - fx);
            goto z_result;
        }
        goto tile_case0;
    case 12:
        if (fx > DAT_005706c0) {
            result = (fx - DAT_005706c0) + (fx - DAT_005706c0);
            goto z_result;
        }
    case 0:
    case 9:
tile_case0:
        z = 0.0;
        goto default_result;
    case 13:
        if (fx > DAT_005706c0)
            result = ((fx - DAT_005706c0) + fy) +
                     ((fx - DAT_005706c0) + fy);
        else
            result = ((DAT_005706c0 - fx) + fy) +
                     ((DAT_005706c0 - fx) + fy);
        goto z_result;
    case 14:
        if (fx <= DAT_005706c0) goto tile_case6;
        goto tile_case8;
    case 15:
        if (raw_y <= DAT_005706d8 - fx * DAT_005706c0)
            goto tile_case7;
        goto tile_case8;
    case 8:
tile_case8:
        result = (DAT_005706d8 - fx) * DAT_005706d0 -
                 (fy - DAT_005706c0);
        goto z_result;
    case 7:
tile_case7:
        fy = fy + fy;
        result = (fx + fx) - DAT_005706d8;
add_fy:
        result = result + fy;
        goto z_result;
    case 16:
        if (DAT_005706d8 - (DAT_005706d8 - fx) * DAT_005706c0 < raw_y)
            goto tile_case6;
        goto tile_case5;
    case 6:
tile_case6:
        result = fx * DAT_005706d0 - (fy - DAT_005706c0);
        goto z_result;
    case 5:
tile_case5:
        result = fy + fy;
        fy = DAT_005706d8 - (fx + fx);
        goto add_fy;
z_result:
        z = result;
default_result:
default:
        {
            float normalized = (float)((((fx + fx) -
                (DAT_005706d8 - (fy + fy))) + z) * DAT_005706c0);
            *out2 = normalized;
            *out1 = (float)((fx + fx) - normalized);
        }
        break;
    }
}

unsigned char RGE_Map::check_map_coords(short x, short y)
{
    if ((x >= 0) && ((int)x < this->map_width) &&
        (y >= 0) && ((int)y < this->map_height))
        return 1;
    return 0;
}

unsigned char RGE_Map::get_elev(short x, short y)
{
    unsigned char elev =
        (unsigned char)(this->map_row_offset[y][x].height);
    if (elev > 8)
        elev = 0;
    return elev;
}

unsigned char RGE_Map::get_terrain(short x, short y)
{
    unsigned char id = this->map_row_offset[y][x].terrain_type & 0x1F;
    if (id <= 0x20) {
        unsigned int idx = id;
        RGE_Tile_Set* terrain = &this->terrain_types[idx];
        if (terrain->loaded != 0 || terrain->terrain_to_draw >= 0)
            return id;
    }
    return 0;
}

unsigned char RGE_Map::get_border(short x, short y)
{
    unsigned char border = this->map_row_offset[y][x].border_type & 0x0F;
    if (border > 0x10 || this->border_types[border].loaded == 0)
        border = 0;
    return border;
}

void RGE_Map::set_terrain_passablity(short x1, short y1, short x2, short y2,
                                     unsigned char passable)
{
    if (y1 > y2) {
        short temp = y2;
        y2 = y1;
        y1 = temp;
    }
    if (x1 > x2) {
        int temp = x2;
        x2 = x1;
        x1 = (short)temp;
    }

    if (y1 < 0) y1 = 0;
    if ((int)y2 >= this->map_height)
        y2 = (short)this->map_height - 1;
    if (x1 < 0) x1 = 0;
    if ((int)x2 >= this->map_width)
        x2 = (short)this->map_width - 1;

    if (y1 <= y2) {
        for (int y = y1; y <= y2; ++y) {
            if (x1 <= x2) {
                for (int x = x1; x <= x2; ++x) {
                    RGE_Tile* tile = &this->map_row_offset[y][x];
                    unsigned char old_terrain = tile->terrain_type;
                    short terrain_type = (short)(old_terrain & 0x1F);
                    unsigned char replacement;

                    if (passable != 0)
                        replacement = this->terrain_types[terrain_type].passable_terrain;
                    else
                        replacement = this->terrain_types[terrain_type].impassable_terrain;
                    tile->terrain_type =
                        (unsigned char)((replacement ^ old_terrain) & 0x1F) ^
                        old_terrain;
                }
            }
        }
    }
}

void RGE_Map::set_elev(short col0, short row0, short col1, short row1,
                       unsigned char elevation, short delta,
                       unsigned char relative)
{
    short row_i;
    short col_i;
    RGE_Tile* tile;
    RGE_Player* cur_player =
        this->game_world->players[this->game_world->curr_player];

    if (row0 > row1) {
        short temp = row1;
        row1 = row0;
        row0 = temp;
    }
    if (col0 > col1) {
        short temp = col1;
        col1 = col0;
        col0 = temp;
    }

    if (row0 < 0) row0 = 0;
    if (row1 >= this->map_height)
        row1 = (short)this->map_height - 1;
    if (col0 < 0) col0 = 0;
    if (col1 >= this->map_width)
        col1 = (short)this->map_width - 1;

    if (relative != 0) {
        if (delta != 0) {
            for (row_i = row0; row_i <= row1; ++row_i) {
                for (col_i = col0; col_i <= col1; ++col_i) {
                    tile = &this->map_row_offset[row_i][col_i];
                    short new_elevation = tile->height + delta;
                    if (new_elevation < 0)
                        new_elevation = 0;
                    else if (new_elevation > 0xFF)
                        new_elevation = 0xFF;
                    tile->height = (unsigned char)new_elevation;
                    if (tile->height > 8)
                        tile->height = 0;
                }
            }
        } else {
            if (elevation > 8) elevation = 8;
            for (row_i = row0; row_i <= row1; ++row_i) {
                for (col_i = col0; col_i <= col1; ++col_i) {
                    tile = &this->map_row_offset[row_i][col_i];
                    tile->height = elevation;
                }
            }
        }
    }

    if (row0 > 0) --row0;
    if (row1 < this->map_height - 1) ++row1;
    if (col0 > 0) --col0;
    if (col1 < this->map_width - 1) ++col1;

    for (row_i = row0; row_i <= row1; ++row_i) {
        for (col_i = col0; col_i <= col1; ++col_i) {
            tile = &this->map_row_offset[row_i][col_i];
            tile->tile_type = this->get_tile_type(col_i, row_i);
            RGE_Object_Node* object_node = tile->objects.list;
            while (object_node != 0) {
                object_node->node->teleport(object_node->node->world_x,
                                             object_node->node->world_y, 0.0f);
                object_node = object_node->next;
            }
            if (this->game_world->game_state != 3)
                cur_player->diam_tile_list.add_node(col_i, row_i);
        }
    }

    this->set_map_screen_pos((int)col0, (int)row0,
                             (int)col1, (int)row1);
    this->request_redraw((int)col0, (int)row0,
                         (int)col1, (int)row1, 0);
}

void RGE_Map::set_terrain(RGE_Game_World* gw, short col, short row,
                          unsigned char terrain, int param5, int param6)
{
    RGE_Player* obj_owner;
    RGE_Player* cur_player;
    RGE_Tile* tile;
    int row_i;
    int col_i;
    short old_terrain;

    obj_owner = *gw->players;
    cur_player = this->game_world->players[this->game_world->curr_player];
    row_i = (int)row;
    col_i = (int)col;
    tile = &this->map_row_offset[row_i][col_i];
    old_terrain = (short)(tile->terrain_type & 0x1F);

    if (old_terrain != terrain) {
        tile->terrain_type =
            (terrain ^ tile->terrain_type) & 0x1F ^ tile->terrain_type;
        if (obj_owner != 0) {
            request_redraw(col_i, row_i, col_i, row_i, 0);
            if (gw->game_state != 3)
                cur_player->diam_tile_list.add_node(col_i, row_i);
            int value = clear_terrain_object(gw, row, col, old_terrain,
                                             1, param5, param6);
            place_terrain_object(obj_owner, gw, row, col, value, 0);
        }
    }
    get_border_type(col, row);
}

void RGE_Map::set_terrain_absolute(RGE_Game_World* gw, short row, short col,
                                   unsigned char terrain, int param5,
                                   int param6)
{
    RGE_Player* p0;
    RGE_Tile* tile;

    p0 = (RGE_Player*)*gw->players;
    tile = &this->map_row_offset[col][row];
    tile->terrain_type = terrain;

    if (p0 != 0) {
        int result = clear_terrain_object(gw, col, row, -1, 1,
                                          param5, param6);
        place_terrain_object(p0, gw, col, row, result, 1);
    }
    get_border_type(row, col);
}

void RGE_Map::set_terrain(RGE_Player* player, RGE_Game_World* world,
                          short x1, short y1, short x2, short y2,
                          unsigned char terrain, unsigned char blend,
                          int arg9)
{
    short terrain_id;
    unsigned int terrain_index;

    if ((short)(unsigned char)terrain < this->num_terrain) {
        terrain_id = (short)(unsigned char)terrain;
        terrain_index = (unsigned char)terrain;
        if (this->terrain_types[terrain_index].loaded != 0 ||
            (this->terrain_types[terrain_index].terrain_to_draw > -1 &&
             this->terrain_types[
                 this->terrain_types[terrain_index].terrain_to_draw].loaded == 1)) {
            if (y1 > y2) {
                short temp = y1;
                y1 = y2;
                y2 = temp;
            }
            if (x1 > x2) {
                short temp = x1;
                x1 = x2;
                x2 = temp;
            }

            if (y1 < 0) y1 = 0;
            if ((int)y2 >= this->map_height)
                y2 = (short)(this->map_height - 1);
            if (x1 < 0) x1 = 0;
            if ((int)x2 >= this->map_width)
                x2 = (short)(this->map_width - 1);

            if ((blend != 0 || player != 0) && y1 <= y2) {
                for (short row = y1; row <= y2; ++row) {
                    if (x1 <= x2) {
                        RGE_Tile* tile =
                            &this->map_row_offset[(int)row][x1];
                        for (short col = x1; col <= x2; ++col) {
                            if (this->terrain_types[terrain_index].tiles[
                                    tile->tile_type].count > 0) {
                                short old_terrain = (short)tile->terrain_type;
                                if (old_terrain != terrain_id && blend != 0) {
                                    tile->terrain_type = terrain;
                                }
                                if (player != 0) {
                                    this->create_terrain_object(
                                        player, world, row, col, old_terrain,
                                        arg9, -1, -1);
                                }
                            }
                            ++tile;
                        }
                    }
                }
            }

            if (y1 > 0) --y1;
            if ((int)y2 < this->map_height - 1) ++y2;
            if (x1 > 0) --x1;
            if ((int)x2 < this->map_width - 1) ++x2;

            for (short row = y1; row <= y2; ++row) {
                for (short col = x1; col <= x2; ++col)
                    this->get_border_type(col, row);
            }
            this->request_redraw(x1, y1, x2, y2, 0);
        }
    }
}

unsigned char RGE_Map::get_tile_type(short x, short y)
{
    long width;
    long height;
    RGE_Tile** rows;
    RGE_Tile* row;
    RGE_Tile* tile;
    unsigned short c, cp1, cm1;
    unsigned short nw, n, ne, w, e, sw, s, se;

    if (x < 0) return 0;
    if ((long)x >= this->map_width) return 0;
    width = this->map_width;
    if (y < 0) return 0;
    height = this->map_height;
    if ((long)y >= height) return 0;

    rows = this->map_row_offset;
    row = rows[y];
    tile = row + x;
    c = (unsigned short)(rows[y][x].height);
    cp1 = c + 1;
    cm1 = c - 1;

    if (y > 0 && (long)x < width - 1)
        nw = (unsigned short)(rows[y - 1][x + 1].height);
    else nw = c;
    if (y > 0)
        n = (unsigned short)(rows[y - 1][x].height);
    else n = c;
    if ((long)x < width - 1)
        e = (unsigned short)(tile[1].height);
    else e = c;
    if (x > 0 && (long)y < height - 1)
        sw = (unsigned short)(rows[y + 1][x - 1].height);
    else sw = c;
    if (x > 0)
        w = (unsigned short)(tile[-1].height);
    else w = c;
    if ((long)y < height - 1)
        s = (unsigned short)(rows[y + 1][x].height);
    else s = c;
    if (y > 0 && x > 0)
        ne = (unsigned short)(rows[y - 1][x - 1].height);
    else ne = c;
    if ((long)y < height - 1 && (long)x < width - 1)
        se = (unsigned short)(rows[y + 1][x + 1].height);
    else se = c;

    if (n == cp1 && e == cp1) return 0x0e;
    if (w == cp1 && s == cp1) return 0x0d;
    if (n == cp1 && w == cp1) return 0x10;
    if (e == cp1 && s == cp1) return 0x0f;
    if (n == cp1) return 6;
    if (e == cp1) return 8;
    if (w == cp1) return 5;
    if (s == cp1) return 7;
    if (nw == cp1) {
        if (w == cm1 && s == cm1) return 2;
        return 0x0a;
    }
    if (sw == cp1) {
        if (n == cm1 && e == cm1) return 1;
        return 9;
    }
    if (ne == cp1) {
        if (e == cm1 && s == cm1) return 3;
        return 0x0b;
    }
    if (se == cp1) {
        if (n == cm1 && w == cm1) return 4;
        return 0x0c;
    }
    return 0;
}

void RGE_Map::get_border_type(short x, short y)
{
    unsigned char ter_top_lft;
    unsigned char ter_lft;
    unsigned char ter_rgt;
    unsigned char ter_bot;
    unsigned char tile;
    unsigned char ter_bot_lft;
    unsigned char ter_bot_rgt;
    int yMax;
    int xMax;
    int xi;
    unsigned char ter_top;
    unsigned char ter_final;

    if (x < 0 || x >= this->map_width || y < 0 || y >= this->map_height)
        return;

    RGE_Tile** rows = this->map_row_offset;
    xi = x;
    RGE_Tile* cur = rows[y] + xi;
    ter_top_lft = cur->terrain_type & 0x1f;
    if (y > 0) ter_lft = rows[y - 1][xi].terrain_type & 0x1f;
    else ter_lft = ter_top_lft;
    yMax = this->map_height - 1;
    if (y < yMax) tile = rows[y + 1][xi].terrain_type & 0x1f;
    else tile = ter_top_lft;
    if (x > 0) ter_rgt = rows[y][xi - 1].terrain_type & 0x1f;
    else ter_rgt = ter_top_lft;
    xMax = this->map_width - 1;
    if (xi < xMax) ter_bot = rows[y][xi + 1].terrain_type & 0x1f;
    else ter_bot = ter_top_lft;
    if (y > 0 && x > 0)
        ter_bot_lft = rows[y - 1][xi - 1].terrain_type & 0x1f;
    else ter_bot_lft = ter_top_lft;
    if (y > 0 && xi < xMax)
        ter_top = rows[y - 1][xi + 1].terrain_type & 0x1f;
    else ter_top = ter_top_lft;
    if (y < yMax && x > 0)
        ter_bot_rgt = rows[y + 1][xi - 1].terrain_type & 0x1f;
    else ter_bot_rgt = ter_top_lft;
    if (y < yMax && xi < xMax)
        ter_final = rows[y + 1][xi + 1].terrain_type & 0x1f;
    else ter_final = ter_top_lft;

    check_for_border(ter_top_lft, ter_lft);
    check_for_border(ter_top_lft, tile);
    check_for_border(ter_top_lft, ter_rgt);
    check_for_border(ter_top_lft, ter_bot);
    check_for_border(ter_top_lft, ter_bot_lft);
    check_for_border(ter_top_lft, ter_top);
    check_for_border(ter_top_lft, ter_bot_rgt);
    check_for_border(ter_top_lft, ter_final);

    unsigned char border_neighbor =
        ter_lft != ter_top_lft ? ter_lft :
        tile != ter_top_lft ? tile :
        ter_rgt != ter_top_lft ? ter_rgt :
        ter_bot != ter_top_lft ? ter_bot :
        ter_bot_lft != ter_top_lft ? ter_bot_lft :
        ter_top != ter_top_lft ? ter_top :
        ter_bot_rgt != ter_top_lft ? ter_bot_rgt : ter_final;
    if (border_neighbor == ter_top_lft) {
        cur->border_type = 0;
        cur->border_shape = 0;
        return;
    }

    short* border_table = this->terrain_types[ter_top_lft].borders;
    short border = border_table[border_neighbor];
    if (border == -1 || border < 0 || border >= 16 ||
        this->border_types[border].loaded == 0) {
        cur->border_type = 0;
        cur->border_shape = 0;
        return;
    }

    unsigned char edge;
    if (this->border_types[border].border_style == 1) {
        edge = 0;
        if (border_table[(unsigned char)ter_lft] == border) edge |= 1;
        if (border_table[(unsigned char)tile] == border) edge |= 2;
        if (border_table[(unsigned char)ter_rgt] == border) edge |= 4;
        if (border_table[(unsigned char)ter_bot] == border) edge |= 8;
        cur->border_type = (unsigned char)border;
        cur->border_shape = edge;
        return;
    }

    if (border_table[(unsigned char)ter_lft] == border &&
        border_table[(unsigned char)ter_rgt] == border)
        edge = 1;
    else if (border_table[(unsigned char)ter_lft] == border &&
             border_table[(unsigned char)ter_bot] == border)
        edge = 2;
    else if (border_table[(unsigned char)tile] == border &&
             border_table[(unsigned char)ter_rgt] == border)
        edge = 3;
    else if (border_table[(unsigned char)tile] == border &&
             border_table[(unsigned char)ter_bot] == border)
        edge = 4;
    else if (border_table[(unsigned char)ter_lft] == border)
        edge = 9;
    else if (border_table[(unsigned char)tile] == border)
        edge = 10;
    else if (border_table[(unsigned char)ter_rgt] == border)
        edge = 11;
    else if (border_table[(unsigned char)ter_bot] == border)
        edge = 12;
    else if (border_table[(unsigned char)ter_bot_lft] == border)
        edge = 5;
    else if (border_table[(unsigned char)ter_top] == border)
        edge = 6;
    else if (border_table[(unsigned char)ter_bot_rgt] == border)
        edge = 7;
    else if (border_table[ter_final] == border)
        edge = 8;
    else {
        cur->border_type = 0;
        cur->border_shape = 0;
        return;
    }

    cur->border_type = (unsigned char)border;
    cur->border_shape = edge;
}

void RGE_Map::check_for_border(unsigned char param_1,
                               unsigned char& param_2)
{
    if (param_2 == param_1)
        return;
    short border = this->terrain_types[param_1].borders[param_2];
    if (border == -1 || border < 0 || border >= 0x10 ||
        this->border_types[border].loaded == 0)
        param_2 = param_1;
}

void RGE_Map::update(unsigned long time)
{
    if (time - DAT_0062e65c < 100)
        return;

    float cur_time = (float)time * DAT_005706e8;
    short i;

    for (i = 0; i < this->num_terrain; ++i) {
        RGE_Tile_Set* terrain = &this->terrain_types[i];
        if (terrain->is_animated) {
            float elapsed = cur_time - terrain->animate_last;
            if (terrain->interval <= elapsed) {
                short frame_count = (short)(elapsed / terrain->interval);
                short animation_frames = terrain->animation_frames;
                short total_frames = terrain->pause_frames + animation_frames;
                short frame = frame_count + terrain->frame;

                if (frame >= total_frames)
                    frame %= total_frames;
                terrain->frame = frame;
                if (frame >= animation_frames)
                    frame = animation_frames - 1;
                if (terrain->draw_frame != frame) {
                    terrain->draw_frame = frame;
                    terrain->frame_changed = 1;
                    this->any_frame_change = 1;
                }
                terrain->animate_last = cur_time -
                    (elapsed - (float)frame_count * terrain->interval);
            }
        }
    }

    for (i = 0; i < this->num_borders; ++i) {
        RGE_Border_Set* border = &this->border_types[i];
        if (border->is_animated) {
            float elapsed = cur_time - border->animate_last;
            if (border->interval <= elapsed) {
                short frame_count = (short)(elapsed / border->interval);
                short animation_frames = border->animation_frames;
                short total_frames = border->pause_frames + animation_frames;
                short frame = frame_count + border->frame;

                if (frame >= total_frames)
                    frame %= total_frames;
                border->frame = frame;
                if (frame >= animation_frames)
                    frame = animation_frames - 1;
                if (border->draw_frame != frame) {
                    border->draw_frame = frame;
                    border->frame_changed = 1;
                    this->any_frame_change = 1;
                }
                border->animate_last = cur_time -
                    (elapsed - (float)frame_count * border->interval);
            }
        }
    }

    DAT_0062e65c = time;
}

void RGE_Map::get_point(short& out_x, short& out_y,
                        float param_3, float param_4, float param_5,
                        short param_6, short param_7)
{
    out_x = (short)((int)((param_4 + param_3) * this->tile_half_width) +
                    param_6);
    out_y = (short)((int)((param_4 - 0.5f - param_3 - param_5) *
                          this->tile_half_height) + param_7 - 0x10);
}
