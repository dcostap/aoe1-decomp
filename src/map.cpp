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

void __cdecl rge_read(int file, void *data, int size);
void __cdecl rge_write(int file, void *data, int size);
extern void __cdecl addstring(char **dst, char *base, char *ext);
extern void __cdecl convert_us(char *text);
int __cdecl debug_rand(char *file, int line);
void __cdecl debug_srand(char *file, int line, unsigned int seed);
extern float save_game_version;
extern float DAT_005706a8;
extern float DAT_005706ac;
extern double DAT_005706c0;
extern double DAT_005706d0;
extern double DAT_005706d8;
extern float DAT_005706e8;
extern TDebuggingLog *L;

RGE_Map::RGE_Map(int infile, RGE_Sound **sounds, unsigned char setup) {
    this->map_zones = 0;
    rge_read(infile, this, 0x8DD0);
    RGE_Game_World *world = rge_base_game->world;
    this->game_world = world;
    this->map = 0;
    this->search_map = 0;
    this->map_row_offset = 0;
    this->search_map_rows = 0;
    this->load_terrain_types(sounds);
    this->load_border_types(sounds);
    this->init_tile_sizes();
    if (setup != 0) {
        this->data_load_random_map(infile);
    }
}

RGE_Map::RGE_Map(char *border_tbl, char *terrain_tbl, char *map_tbl, short TileWid, short TileHgt, short ElevHgt,
                 RGE_Sound **sounds) {
    int i;
    int j;

    this->map_zones = 0;
    this->random_map = 0;
    this->game_world = rge_base_game->world;

    this->tile_width = TileWid;
    this->tile_half_width = TileWid / 2;
    this->tile_height = TileHgt;
    this->tile_half_height = TileHgt / 2;
    this->elev_height = ElevHgt;
    this->map_width = 0;
    this->map_height = 0;
    this->world_width = 0;
    this->world_height = 0;

    this->set_tile_size(0, TileWid, TileHgt, 0);
    this->set_tile_size(1, this->tile_width, this->elev_height, -100);
    this->set_tile_size(2, this->tile_width, this->elev_height + this->tile_height, 100);
    this->set_tile_size(3, this->tile_width, this->tile_height, -100);
    this->set_tile_size(4, this->tile_width, this->tile_height, -100);
    this->set_tile_size(5, this->tile_width, this->elev_height, -100);
    this->set_tile_size(6, this->tile_width, this->elev_height + this->tile_height, 100);
    this->set_tile_size(7, this->tile_width, this->elev_height, -100);
    this->set_tile_size(8, this->tile_width, this->elev_height + this->tile_height, 100);
    this->set_tile_size(9, this->tile_width, this->elev_height, -100);
    this->set_tile_size(10, this->tile_width, this->elev_height + this->tile_height, 100);
    this->set_tile_size(11, this->tile_width, this->tile_height, -100);
    this->set_tile_size(12, this->tile_width, this->tile_height, -100);
    this->set_tile_size(13, this->tile_width, this->elev_height, -100);
    this->set_tile_size(14, this->tile_width, this->elev_height + this->tile_height, 100);
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

    this->load_terrain_types(terrain_tbl, sounds);
    this->load_border_types(border_tbl, sounds);
    this->map = 0;
    this->search_map = 0;
    this->map_row_offset = 0;
    this->search_map_rows = 0;
    this->unified_vis_map = 0;
    this->unit_manager = 0;
}

RGE_Map::~RGE_Map() {
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

void RGE_Map::init_tile_sizes() {
    this->tile_width = 0x40;
    this->tile_height = 0x20;
    this->tile_half_width = 0x20;
    this->tile_half_height = 0x10;
    this->elev_height = 0x10;

    this->set_tile_size(0, 0x40, 0x20, 0);
    this->set_tile_size(1, this->tile_width, this->elev_height, -8);
    this->set_tile_size(2, this->tile_width, this->elev_height + this->tile_height, 8);
    this->set_tile_size(3, this->tile_width, this->tile_height, -8);
    this->set_tile_size(4, this->tile_width, this->tile_height, -8);
    this->set_tile_size(5, this->tile_width, this->elev_height, -8);
    this->set_tile_size(6, this->tile_width, this->elev_height + this->tile_height, 8);
    this->set_tile_size(7, this->tile_width, this->elev_height, -8);
    this->set_tile_size(8, this->tile_width, this->elev_height + this->tile_height, 8);
    this->set_tile_size(9, this->tile_width, this->elev_height, -8);
    this->set_tile_size(10, this->tile_width, this->elev_height + this->tile_height, 8);
    this->set_tile_size(11, this->tile_width, this->tile_height, -8);
    this->set_tile_size(12, this->tile_width, this->tile_height, -8);
    this->set_tile_size(13, this->tile_width, this->elev_height, -8);
    this->set_tile_size(14, this->tile_width, this->elev_height + this->tile_height, 8);
    this->set_tile_size(15, this->tile_width, this->tile_height, 8);
    this->set_tile_size(16, this->tile_width, this->tile_height, 8);
    this->set_tile_size(17, this->tile_half_width, this->tile_height, 0);
    this->set_tile_size(18, this->tile_half_width, this->tile_height, 0);
}

void RGE_Map::data_load_random_map(int infile) {
    this->random_map = new RGE_RMM_Database_Controller(infile);
}

void RGE_Map::load_random_map(char *rmm_map_file, char *rmm_land_file, char *rmm_terr_file, char *rmm_obj_file) {
    RGE_RMM_Database_Controller *ctrl =
        new RGE_RMM_Database_Controller(rmm_land_file, rmm_terr_file, rmm_obj_file, rmm_map_file);
    this->random_map = ctrl;
}

void RGE_Map::set_map_visible(unsigned char flag) {
    this->map_visible_flag = flag;
}

void RGE_Map::set_map_fog(unsigned char flag) {
    this->fog_flag = flag;
}

void RGE_Map::clear_map(RGE_Player *player, RGE_Game_World *world, unsigned char new_terrain, long width, long height) {
    new_map(width, height);
    if (world != 0) {
        world->reset_object_count();
    }
    set_terrain(player, world, 0, 0, width - 1, height - 1, new_terrain, 1, 0);
    if (world != 0) {
        world->reset_player_visible_maps();
    }
}

void RGE_Map::new_map(long width, long height) {
    int i;

    if (width <= 0 || height <= 0) {
        return;
    }

    if (this->map != 0) {
        if (this->game_world != 0) {
            int player_count = this->game_world->player_num;
            for (i = 0; i < player_count; ++i) {
                if (this->game_world->players != 0 && this->game_world->players[i] != 0) {
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
    this->map = (RGE_Tile *)calloc(height * width, sizeof(RGE_Tile));
    this->search_map = (unsigned char *)calloc(this->map_height * this->map_width, sizeof(unsigned char));
    this->map_row_offset = (RGE_Tile **)calloc(this->map_height + 1, sizeof(RGE_Tile *));
    this->search_map_rows = (unsigned char **)calloc(this->map_height + 1, sizeof(unsigned char *));

    for (i = 0; i < this->map_height; ++i) {
        this->map_row_offset[i] = this->map + i * this->map_width;
        this->search_map_rows[i] = this->search_map + i * this->map_width;
    }

    this->map_row_offset[this->map_height] = this->map;
    this->search_map_rows[this->map_height] = this->search_map;

    for (i = 0; i < this->map_height; ++i) {
        for (int j = 0; j < this->map_width; ++j) {
            RGE_Tile *tile = &this->map_row_offset[i][j];
            tile->height = 1;
        }
    }

    this->set_map_screen_pos(0, 0, this->map_width - 1, this->map_height - 1);

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
    this->unit_manager = new Visible_Unit_Manager(this->game_world->player_num, 0x40);
}

void RGE_Map::clear_map(unsigned char terrain, unsigned char elev) {
    for (long y = 0; y < this->map_height; ++y) {
        RGE_Tile *row = this->map_row_offset[y];
        for (long x = 0; x < this->map_width; ++row, ++x) {
            row->tile_type = 0;
            row->terrain_type = terrain;
            row->height = elev;
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

    this->set_map_screen_pos(0, 0, this->map_width - 1, this->map_height - 1);
}

void RGE_Map::request_redraw(int x1, int y1, int x2, int y2, unsigned char attribute) {
    RGE_Map *self = this;

    if (x1 > x2) {
        int t = x1;
        x1 = x2;
        x2 = t;
    }
    if (y1 > y2) {
        int t = y1;
        y1 = y2;
        y2 = t;
    }

    if (x2 >= 0 && y2 >= 0 && x1 < self->map_width && y1 < self->map_height) {
        if (x1 < 0)
            x1 = 0;
        if (y1 < 0)
            y1 = 0;
        if (x2 >= self->map_width)
            x2 = self->map_width - 1;
        if (y2 >= self->map_height)
            y2 = self->map_height - 1;

        int row = y1;
        while (row <= y2) {
            RGE_Tile *tile = &self->map_row_offset[row][x1];
            if (x1 <= x2) {
                int count = x2 - x1 + 1;
                do {
                    tile->last_drawn_as = 0xCC;
                    tile->draw_attribute = attribute;
                    ++tile;
                    --count;
                } while (count != 0);
            }
            ++row;
        }
    }
}

void RGE_Map::clear_map_view_info() {
    int col;
    int row = 0;
    RGE_Tile *tile_row;

    if (0 < this->map_height) {
        do {
            col = 0;
            tile_row = this->map_row_offset[row];
            if (0 < this->map_width) {
                unsigned char *view_data = &tile_row->last_drawn_shape;
                do {
                    view_data[-1] = 0;
                    *view_data = 0xff;
                    view_data[1] = 0;
                    view_data[2] = 0;
                    view_data[3] = 0xff;
                    view_data += 0x18;
                    col = col + 1;
                } while (col < this->map_width);
            }
            row = row + 1;
        } while (row < this->map_height);
    }
}

void RGE_Map::coordinate_map() {
    this->set_map_screen_pos(0, 0, this->map_width - 1, this->map_height - 1);
}

void RGE_Map::set_map_screen_pos(int x1, int y1, int x2, int y2) {
    if (x1 < 0) {
        x1 = 0;
    } else if (x1 > this->map_width - 1) {
        x1 = this->map_width - 1;
    }

    if (y1 < 0) {
        y1 = 0;
    } else if (y1 > this->map_height - 1) {
        y1 = this->map_height - 1;
    }

    if (x2 < 0) {
        x2 = 0;
    } else if (x2 > this->map_width - 1) {
        x2 = this->map_width - 1;
    }

    if (y2 < 0) {
        y2 = 0;
    } else if (y2 > this->map_height - 1) {
        y2 = this->map_height - 1;
    }

    for (; y1 <= y2; ++y1) {
        RGE_Tile *tile = this->map_row_offset[y1] + x1;
        for (int col = x1; col <= x2; ++tile, ++col) {
            tile->screen_xpos = (short)(y1 + col) * this->tile_half_width;
            tile->screen_ypos = (short)(y1 - col) * this->tile_half_height - (short)(tile->height) * this->elev_height;

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

void RGE_Map::scenario_save(int outfile) {
    RGE_Map *map = this;
    rge_write(outfile, &map->map_width, 4);

    long *height = &map->map_height;
    rge_write(outfile, height, 4);

    long height_count = *height;
    short y = 0;
    unsigned char terrain_info;
    unsigned char height_info;
    unsigned char local_bytes[2];

    if (height_count > 0) {
        do {
            short x = 0;
            if (height_count > 0) {
                do {
                    terrain_info = map->map_row_offset[y][x].terrain_type & 0x1f;
                    height_info = map->map_row_offset[y][x].height;
                    local_bytes[0] = height_info;
                    local_bytes[1] = 0;
                    rge_write(outfile, &terrain_info, 1);
                    rge_write(outfile, local_bytes, 1);
                    rge_write(outfile, local_bytes + 1, 1);
                    ++x;
                } while (x < *height);
            }
            height_count = *height;
            ++y;
        } while (y < height_count);
    }
}

void RGE_Map::scenario_load(int infile, unsigned char *zone_terrain) {
    long map_height;
    long w;

    rge_read(infile, &map_height, 4);
    rge_read(infile, &w, 4);
    this->new_map(map_height, w);

    long height_count = this->map_height;
    long h = 0;
    if (height_count > 0) {
        do {
            int i = 0;
            long y = 0;
            if (height_count > 0) {
                short x = (short)h;
                do {
                    unsigned char terrain_info;
                    unsigned char height_info;
                    unsigned char overlay_info;

                    rge_read(infile, &terrain_info, 1);
                    rge_read(infile, &height_info, 1);
                    rge_read(infile, &overlay_info, 1);

                    this->map_row_offset[x][i].terrain_type = terrain_info;
                    this->map_row_offset[x][i].height = height_info;

                    y = y + 1;
                    i = (int)(short)y;
                } while (i < this->map_height);
            }
            height_count = this->map_height;
            ++h;
        } while ((short)h < height_count);
    }

    this->set_elev(0, 0, (short)this->map_width - 1, (short)this->map_height - 1, 0, 0, 0);
    this->set_terrain(0, 0, 0, 0, (short)this->map_width - 1, (short)this->map_height - 1, 0, 0, 0);
}

RGE_Tile **RGE_Map::give_up_map_offsets() {
    return this->map_row_offset;
}

long RGE_Map::get_map_width() {
    return this->map_width;
}

long RGE_Map::get_map_height() {
    return this->map_height;
}

unsigned char RGE_Map::postclean_elevation(long x1, long y1, long x2, long y2, unsigned char elevation_height) {
    short width = (short)this->map_width;
    short offset_northwest = (short)(-1 - width);
    short offset_northeast = (short)(1 - width);
    short offset_north = (short)-width;
    short offset_southwest = (short)(width - 1);
    short offset_southeast = (short)(width + 1);
    short offset_south = width;
    unsigned char was_bad = 0;
    long index1;

    if (x1 > 0)
        --x1;
    if (y1 > 0)
        --y1;
    if (x2 < this->map_width - 1)
        ++x2;
    if (y2 < this->map_height - 1)
        ++y2;

    do {
        if (y2 < y1)
            return was_bad;

        RGE_Tile *tile = this->map_row_offset[y1] + x1;
        for (index1 = x1; index1 <= x2; ++index1) {
            bool bad = false;
            unsigned char current_height = tile->height;
            unsigned short new_height = current_height;

            if (current_height < elevation_height) {
                ++new_height;

                if (y1 > 0 && (tile + offset_north)->height > new_height)
                    bad = true;
                if (y1 < this->map_height - 1 && (tile + offset_south)->height > new_height)
                    bad = true;
                if (index1 > 0 && tile[-1].height > new_height)
                    bad = true;
                if (index1 < this->map_width - 1 && tile[1].height > new_height)
                    bad = true;
                if (y1 > 0) {
                    if (index1 > 0 && (tile + offset_northwest)->height > new_height)
                        bad = true;
                    if (index1 < this->map_width - 1 && (tile + offset_northeast)->height > new_height)
                        bad = true;
                }
                if (y1 < this->map_height - 1) {
                    if (index1 > 0 && (tile + offset_southwest)->height > new_height)
                        bad = true;
                    if (index1 < this->map_width - 1 && (tile + offset_southeast)->height > new_height)
                        bad = true;
                }
            } else if (elevation_height < current_height) {
                --new_height;

                if (y1 > 0 && (tile + offset_north)->height < new_height)
                    bad = true;
                if (y1 < this->map_height - 1 && (tile + offset_south)->height < new_height)
                    bad = true;
                if (index1 > 0 && tile[-1].height < new_height)
                    bad = true;
                if (index1 < this->map_width - 1 && tile[1].height < new_height)
                    bad = true;
                if (y1 > 0) {
                    if (index1 > 0 && (tile + offset_northwest)->height < new_height)
                        bad = true;
                    if (index1 < this->map_width - 1 && (tile + offset_northeast)->height < new_height)
                        bad = true;
                }
                if (y1 < this->map_height - 1) {
                    if (index1 > 0 && (tile + offset_southwest)->height < new_height)
                        bad = true;
                    if (index1 < this->map_width - 1 && (tile + offset_southeast)->height < new_height)
                        bad = true;
                }
            }

            if (bad) {
                was_bad = 1;
                tile->height = new_height;
            }
            ++tile;
        }
        ++y1;
    } while (true);
}

void RGE_Map::preclean_elevation(long x1, long y1, long x2, long y2, unsigned char elevation_height) {
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
        if (x1 > 0)
            --x1;
        if (y1 > 0)
            --y1;
        if (x2 < this->map_width - 1)
            ++x2;
        if (y2 < this->map_height - 1)
            ++y2;

        for (index2 = y1; index2 <= y2; ++index2) {
            RGE_Tile *tile = this->map_row_offset[index2] + x1;
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
                if (index2 < this->map_height - 1 && (tile + offset_south)->height > elevation)
                    south = 1;
                if (index1 > 0 && tile[-1].height > elevation)
                    west = 1;
                if (index1 < this->map_width - 1 && tile[1].height > elevation)
                    east = 1;
                if (index2 > 0) {
                    if (index1 > 0 && (tile + offset_northwest)->height > elevation)
                        northwest = 1;
                    if (index1 < this->map_width - 1 && (tile + offset_northeast)->height > elevation)
                        northeast = 1;
                }
                if (index2 < this->map_height - 1) {
                    if (index1 > 0 && (tile + offset_southwest)->height > elevation)
                        southwest = 1;
                    if (index1 < this->map_width - 1 && (tile + offset_southeast)->height > elevation)
                        southeast = 1;
                }

                unsigned char conflict = 0;
                if (north && south)
                    conflict = 1;
                if (east && west)
                    conflict = 1;
                if (conflict) {
                    if (elevation >= elevation_height) {
                        if (northwest)
                            (tile + offset_northwest)->height = (unsigned char)elevation;
                        if (north)
                            (tile + offset_north)->height = (unsigned char)elevation;
                        if (northeast)
                            (tile + offset_northeast)->height = (unsigned char)elevation;
                        if (east)
                            tile[1].height = (unsigned char)elevation;
                        if (southeast)
                            (tile + offset_southeast)->height = (unsigned char)elevation;
                        if (south)
                            (tile + offset_south)->height = (unsigned char)elevation;
                        if (southwest)
                            (tile + offset_southwest)->height = (unsigned char)elevation;
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

void RGE_Map::clean_elevation(long x1, long y1, long x2, long y2, unsigned char elevation_height) {
    unsigned char change_flag;
    short width = (short)this->map_width;
    short offset_nw = (short)(-1 - width);
    short offset_n = (short)-width;
    short offset_ne = (short)(1 - width);
    short offset_se = (short)(width + 1);
    short offset_sw = (short)(width - 1);

    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (x2 >= this->map_width)
        x2 = this->map_width - 1;
    if (y2 >= this->map_height)
        y2 = this->map_height - 1;

    do {
        change_flag = 0;
        x1 -= 2;
        y1 -= 2;
        x2 += 2;
        y2 += 2;

        if (x1 < 0)
            x1 = 0;
        if (y1 < 0)
            y1 = 0;
        if (x2 >= this->map_width)
            x2 = this->map_width - 1;
        if (y2 >= this->map_height)
            y2 = this->map_height - 1;

        this->preclean_elevation(x1, y1, x2, y2, elevation_height);

        for (long row = y1; row <= y2; ++row) {
            RGE_Tile *tile = this->map_row_offset[row] + x1;
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
                if (row < this->map_height - 1 && (tile[width].height) > current)
                    south = 1;
                if (col > 0 && (tile[-1].height) > current)
                    west = 1;
                if (col < this->map_width - 1 && (tile[1].height) > current)
                    east = 1;
                if (row > 0) {
                    if (col > 0 && (tile[offset_nw].height) > current)
                        north_west = 1;
                    if (col < this->map_width - 1 && (tile[offset_ne].height) > current)
                        north_east = 1;
                }
                if (row < this->map_height - 1) {
                    if (col > 0 && (tile[offset_sw].height) > current)
                        south_west = 1;
                    if (col < this->map_width - 1 && (tile[offset_se].height) > current)
                        south_east = 1;
                }

                bool fix = false;
                if (north_west) {
                    if ((north_east && !north) || (east && !north_east) || (south_west && !west) ||
                        (south && !south_west) || ((south_east && !south) && !east))
                        fix = 1;
                }
                if (north_east && !fix) {
                    if ((south_east && !east) || (south && !south_east) || (north_west && !north) ||
                        (west && !north_west) || (south_west && !west && !south))
                        fix = 1;
                }
                if (south_east && !fix) {
                    if ((south_west && !south) || (west && !south_west) || (north_east && !east) ||
                        (north && !north_east) || (north_west && !north && !west))
                        fix = 1;
                }
                if (south_west && !fix) {
                    if (north_west && !west)
                        fix = 1;
                    else if (north && !north_west)
                        fix = 1;
                    else if (south_east && !south)
                        fix = 1;
                    else if (east && !south_east)
                        fix = 1;
                    else if (north_east && !east && !north)
                        fix = 1;
                }

                if (fix) {
                    if (current >= elevation_height) {
                        if (north_west)
                            (tile + offset_nw)->height = (unsigned char)current;
                        if (north)
                            (tile + offset_n)->height = (unsigned char)current;
                        if (north_east)
                            (tile + offset_ne)->height = (unsigned char)current;
                        if (east)
                            tile[1].height = (unsigned char)current;
                        if (south_east)
                            (tile + offset_se)->height = (unsigned char)current;
                        if (south)
                            (tile + width)->height = (unsigned char)current;
                        if (south_west)
                            (tile + offset_sw)->height = (unsigned char)current;
                        if (west)
                            tile[-1].height = (unsigned char)current;
                    } else {
                        tile->height = (unsigned char)(current + 1);
                    }
                    change_flag = 1;
                }
            }
        }

        if (this->postclean_elevation(x1, y1, x2, y2, elevation_height) != 0)
            change_flag = 1;
        if (!change_flag) {
            this->set_elev((short)x1, (short)y1, (short)x2, (short)y2, 0, 0, 0);
            return;
        }
    } while (true);
}

void RGE_Map::clean_terrain(long x1, long y1, long x2, long y2, unsigned char replacement_terrain) {
    short map_width = (short)this->map_width;
    short offset_nw = (short)(-1 - map_width);
    short offset_n = (short)-map_width;
    short offset_ne = (short)(1 - map_width);
    short offset_se = (short)(map_width + 1);
    short offset_sw = (short)(map_width - 1);

    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (x2 >= this->map_width)
        x2 = this->map_width - 1;
    if (y2 >= this->map_height)
        y2 = this->map_height - 1;

    bool change_flag;
    do {
        change_flag = 0;
        if (x1 > 0)
            --x1;
        if (y1 > 0)
            --y1;
        if (x2 < this->map_width - 1)
            ++x2;
        if (y2 < this->map_height - 1)
            ++y2;

        int pass_index = 0;
        do {
            for (int row = y1; row <= y2; ++row) {
                RGE_Tile *tile = this->map_row_offset[row] + x1;
                for (int col = x1; col <= x2; ++tile, ++col) {
                    if ((tile->terrain_type & 0x1f) != replacement_terrain) {
                        short north_west = 0;
                        short north = 0;
                        short north_east = 0;
                        short east = 0;
                        short south_east = 0;
                        short south = 0;
                        short south_west = 0;
                        short west = 0;
                        unsigned char fix;

                        if (row > 0 && (tile[offset_n].terrain_type & 0x1f) == replacement_terrain)
                            north = 1;
                        if (row < this->map_height - 1 && (tile[map_width].terrain_type & 0x1f) == replacement_terrain)
                            south = 1;
                        if (col > 0 && (tile[-1].terrain_type & 0x1f) == replacement_terrain)
                            west = 1;
                        if (col < this->map_width - 1 && (tile[1].terrain_type & 0x1f) == replacement_terrain)
                            east = 1;

                        if (pass_index == 1) {
                            if (row > 0) {
                                if (col > 0 && (tile[offset_nw].terrain_type & 0x1f) == replacement_terrain)
                                    north_west = 1;
                                if (col < this->map_width - 1 &&
                                    (tile[offset_ne].terrain_type & 0x1f) == replacement_terrain)
                                    north_east = 1;
                            }
                            if (row < this->map_height - 1) {
                                if (col > 0 && (tile[offset_sw].terrain_type & 0x1f) == replacement_terrain)
                                    south_west = 1;
                                if (col < this->map_width - 1 &&
                                    (tile[offset_se].terrain_type & 0x1f) == replacement_terrain)
                                    south_east = 1;
                            }
                        }

                        fix = 0;
                        if (pass_index == 0) {
                            if ((north && south) || (east && west))
                                fix = 1;
                        } else {
                            if (north_west) {
                                if ((north_east && !north) || (east && !north_east) || (south_west && !west) ||
                                    (south && !south_west) || ((south_east && !south) && !east))
                                    fix = 1;
                            }
                            if (north_east && !fix) {
                                if ((north_west && !north) || (west && !north_west) || (south_east && !east) ||
                                    (south && !south_east) || (south_west && !west && !south))
                                    fix = 1;
                            }
                            if (south_east && !fix) {
                                if ((north_east && !east) || (north && !north_east) || (south_west && !south) ||
                                    (west && !south_west) || (north_west && !west && !north))
                                    fix = 1;
                            }
                            if (south_west && !fix) {
                                if ((north_west && !west) || (north && !north_west) || (south_east && !south) ||
                                    (east && !south_east) || (north_east && !east && !north))
                                    fix = 1;
                            }
                        }

                        if (fix) {
                            this->set_terrain(this->game_world, col, row, replacement_terrain, 0, 0);
                            change_flag = 1;
                        }
                    }
                }
            }
            ++pass_index;
        } while (pass_index < 2);

        if (!change_flag)
            return;
    } while (true);
}

void RGE_Map::clean_borders(long x1, long y1, long x2, long y2) {
}

long RGE_Map::clean_border_tile(long this_terrain, long other_terrain, long (*const matrix)[32]) {
    return -1;
}

unsigned char RGE_Map::do_terrain_brush(long x, long y, long brush_size, unsigned char terrain_id) {
    long rad = brush_size;
    long x1 = x - rad;
    long x2 = x + rad;
    long y1 = y - rad;
    long y2 = y + rad;

    if (x1 < 0)
        x1 = 0;
    if (x2 >= this->map_width)
        x2 = this->map_width - 1;
    if (y1 < 0)
        y1 = 0;
    if (y2 >= this->map_height)
        y2 = this->map_height - 1;

    long row = y1;
    while (row <= y2) {
        long col = x1;
        while (col <= x2) {
            this->set_terrain(this->game_world, col, row, terrain_id, 0, 0);
            ++col;
        }
        ++row;
    }
    return 1;
}

unsigned char RGE_Map::do_terrain_brush_stroke(long x1, long y1, long x2, long y2, long brush_size,
                                               unsigned char terrain_id) {
    brush_size >>= 1;
    if (x1 < 0)
        x1 = 0;
    if (x2 >= this->map_width)
        x2 = this->map_width - 1;
    if (y1 < 0)
        y1 = 0;
    if (y2 >= this->map_height)
        y2 = this->map_height - 1;

    long x_distance = x2 - x1;
    long y_distance = y2 - y1;
    long index;
    double step_x;
    double step_y;
    double x;
    double y;
    index = (long)sqrt((double)x_distance * x_distance + (double)y_distance * y_distance);
    step_x = (double)x_distance / (double)index;
    step_y = (double)y_distance / (double)index;
    x = (double)x1;
    y = (double)y1;

    this->do_terrain_brush(x1, y1, brush_size, terrain_id);
    if (index > 0) {
        long count = index;
        do {
            x = step_x + x;
            y = step_y + y;
            this->do_terrain_brush((long)x, (long)y, brush_size, terrain_id);
            --count;
        } while (count != 0);
    }
    if ((double)x2 != x || (double)y2 != y)
        this->do_terrain_brush(x2, y2, brush_size, terrain_id);
    return 1;
}

unsigned char RGE_Map::do_elevation_brush(long x, long y, long brush_size, unsigned char elevation_height) {
    long minx = x - brush_size;
    long maxx = x + brush_size;
    long miny = y - brush_size;
    long maxy = y + brush_size;
    if (minx < 0)
        minx = 0;
    if (maxx >= this->map_width)
        maxx = this->map_width - 1;
    if (miny < 0)
        miny = 0;
    if (maxy >= this->map_height)
        maxy = this->map_height - 1;
    for (long row = miny; row <= maxy; ++row) {
        if (minx <= maxx) {
            RGE_Tile *tile;
            for (long col = minx; col <= maxx; ++col) {
                tile = &this->map_row_offset[row][col];
                tile->height = elevation_height;
            }
        }
    }
    return 1;
}

unsigned char RGE_Map::do_elevation_brush_stroke(long x1, long y1, long x2, long y2, long brush_size,
                                                 unsigned char elevation_height) {
    brush_size >>= 1;
    if (x1 < 0)
        x1 = 0;
    if (x2 >= this->map_width)
        x2 = this->map_width - 1;
    if (y1 < 0)
        y1 = 0;
    if (y2 >= this->map_height)
        y2 = this->map_height - 1;

    long x_distance = x2 - x1;
    long y_distance = y2 - y1;
    long index;
    double step_x;
    double step_y;
    double x;
    double y;
    index = (long)sqrt((double)x_distance * x_distance + (double)y_distance * y_distance);
    step_x = (double)x_distance / (double)index;
    step_y = (double)y_distance / (double)index;
    x = (double)x1;
    y = (double)y1;

    this->do_elevation_brush(x1, y1, brush_size, elevation_height);
    if (index > 0) {
        long count = index;
        do {
            x = step_x + x;
            y = step_y + y;
            this->do_elevation_brush((long)x, (long)y, brush_size, elevation_height);
            --count;
        } while (count != 0);
    }
    if ((double)x2 != x || (double)y2 != y)
        this->do_elevation_brush(x2, y2, brush_size, elevation_height);

    if (x1 < x2) {
        x1 -= brush_size;
        x2 += brush_size;
    } else {
        long temp_x = x1;
        x1 = x2 - brush_size;
        x2 = temp_x + brush_size;
    }
    if (y1 < y2) {
        y1 -= brush_size;
        y2 += brush_size;
    } else {
        long temp_y = y1;
        y1 = y2 - brush_size;
        y2 = temp_y + brush_size;
    }
    this->clean_elevation(x1, y1, x2, y2, elevation_height);
    return 1;
}

unsigned char RGE_Map::do_cliff_brush(long x, long y, unsigned char cliff_id, unsigned char delete_cliff) {
    return 0;
}

unsigned char RGE_Map::do_cliff_brush_stroke(long x1, long y1, long x2, long y2, unsigned char cliff_id,
                                             unsigned char delete_cliff) {
    if (x1 < 0)
        x1 = 0;
    if (x2 >= this->map_width)
        x2 = this->map_width - 1;
    if (y1 < 0)
        y1 = 0;
    if (y2 >= this->map_height)
        y2 = this->map_height - 1;

    long x_distance = x2 - x1;
    long y_distance = y2 - y1;
    long index;
    double step_x;
    double step_y;
    double x;
    double y;
    index = (long)sqrt((double)x_distance * x_distance + (double)y_distance * y_distance);
    step_x = (double)x_distance / (double)index;
    step_y = (double)y_distance / (double)index;
    x = (double)x1;
    y = (double)y1;

    this->do_cliff_brush(x1, y1, cliff_id, delete_cliff);
    if (index > 0) {
        long count = index;
        do {
            x = step_x + x;
            y = step_y + y;
            this->do_cliff_brush((long)x, (long)y, cliff_id, delete_cliff);
            --count;
        } while (count != 0);
    }
    if ((double)x2 != x || (double)y2 != y)
        this->do_cliff_brush(x2, y2, cliff_id, delete_cliff);
    return 1;
}

void RGE_Map::map_generate(RGE_Player *owner, RGE_Game_World *gworld, RGE_Player_Info *player_info,
                           unsigned char *zone_terrain) {
}

void RGE_Map::map_generate2(RGE_Game_World *gworld, long new_width, long new_height, unsigned char type,
                            long player_num) {
    unsigned char old_state = this->game_world->game_state;
    this->game_world->game_state = 3;

    int seed = rge_base_game->random_map_seed;
    if (seed == -1)
        seed = debug_rand((char *)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x5CE);

    rge_base_game->save_random_map_seed = seed;
    L->Log("Random Map Seed = %d", seed);

    debug_srand((char *)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x5DA, seed);
    this->clear_map(0, gworld, 0, new_width, new_height);

    debug_srand((char *)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x5DD, seed);
    this->random_map->init(this, gworld, type, player_num, 1);

    debug_srand((char *)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x5E0, seed);
    this->random_map->generate();
    this->random_map->de_init();

    int after_seed = debug_rand((char *)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x5E5);
    L->Log("After Random Map Generation random number is %d", after_seed);

    this->game_world->game_state = old_state;
}

void RGE_Map::load_map(int infile) {
    long map_height;
    long w;
    unsigned char c;

    rge_read(infile, &map_height, 4);
    rge_read(infile, &w, 4);
    this->new_map(map_height, w);

    RGE_Zone_Map_List *old_zones = this->map_zones;
    if (old_zones != 0)
        delete old_zones;

    RGE_Zone_Map_List *zones = new RGE_Zone_Map_List(infile, this);
    this->map_zones = zones;

    rge_read(infile, &this->map_visible_flag, 1);
    rge_read(infile, &this->fog_flag, 1);

    if (!(save_game_version < DAT_005706a8)) {
        long h = 0;
        if (this->map_height > 0) {
            do {
                RGE_Tile *tile = this->map_row_offset[h];
                int y = 0;
                if (this->map_width > 0) {
                    do {
                        rge_read(infile, tile, 2);
                        rge_read(infile, &tile->screen_ypos, 2);
                        rge_read(infile, &tile->tile_type, 1);

                        rge_read(infile, &c, 1);
                        tile->terrain_type = c;
                        rge_read(infile, &c, 1);
                        tile->height = c;

                        rge_read(infile, &c, 1);
                        tile->border_type = c;
                        rge_read(infile, &c, 1);
                        tile->border_shape = c;
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
        rge_read(infile, this->map, this->map_width * this->map_height * 0x18);
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

    this->unified_vis_map->load(infile);
}

void RGE_Map::save_map(int outfile) {
    int handle = outfile;
    RGE_Map *map = this;
    long *width = &map->map_width;
    rge_write(handle, width, 4);

    long *height = &map->map_height;
    rge_write(handle, height, 4);
    map->map_zones->save(handle);
    rge_write(handle, &map->map_visible_flag, 1);
    rge_write(handle, &map->fog_flag, 1);

    if (!(save_game_version < DAT_005706a8)) {
        int y = 0;
        if (*height > 0) {
            do {
                int x = 0;
                RGE_Tile *tile = map->map_row_offset[y];
                if (map->map_width > 0) {
                    do {
                        rge_write(handle, tile, 2);
                        rge_write(handle, &tile->screen_ypos, 2);
                        rge_write(handle, &tile->tile_type, 1);

                        unsigned char c = tile->terrain_type & 0x1f;
                        rge_write(handle, &c, 1);
                        c = tile->height;
                        rge_write(handle, &c, 1);
                        c = tile->border_type & 0x0f;
                        rge_write(handle, &c, 1);
                        c = tile->border_shape;
                        rge_write(handle, &c, 1);

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

void RGE_Map::save(int outfile) {
    RGE_Map *copy = (RGE_Map *)calloc(1, sizeof(RGE_Map));
    memcpy(copy, this, sizeof(RGE_Map));
    int i;

    for (i = 0; i < 32; ++i) {
        if (this->terrain_types[i].loaded != 0) {
            if (this->terrain_types[i].sound != 0) {
                copy->terrain_types[i].sound = (RGE_Sound *)this->terrain_types[i].sound->id;
            } else {
                copy->terrain_types[i].sound = (RGE_Sound *)-1;
            }
        }
    }

    for (i = 0; i < 16; ++i) {
        if (this->border_types[i].sound == 0 || this->border_types[i].loaded == 0) {
            copy->border_types[i].sound = (RGE_Sound *)-1;
        } else {
            copy->border_types[i].sound = (RGE_Sound *)this->border_types[i].sound->id;
        }
    }

    rge_write(outfile, copy, 0x8dd0);
    this->random_map->save(outfile);
    free(copy);
}

void RGE_Map::load_terrain_types(RGE_Sound **sounds) {
    char *filename2 = 0;
    long *resource_id = &this->terrain_types[31].resource_id;
    int count = 0x20;

    do {
        RGE_Tile_Set *tile_set = (RGE_Tile_Set *)(resource_id - 7);
        if (tile_set->loaded != 0) {
            addstring(&filename2, tile_set->pict_name, (char *)".shp");
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

void RGE_Map::load_terrain_types(char *terrain_table, RGE_Sound **sounds) {
    short border_num;
    short border;
    short sound_id;
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
    float pause_between_loops;
    FILE *infile;
    long resource_id;
    char name[13];
    char pict_name[13];

    int i;
    for (i = 31; i >= 0; --i)
        this->terrain_types[i].loaded = 0;

    infile = fopen(terrain_table, "r");
    if (infile != 0) {
        fscanf(infile, "%hd", &this->num_terrain);
        short remaining = this->num_terrain - 1;
        if (remaining >= 0) {
            int terrain_count = (int)remaining + 1;
            do {
                short id;
                short shape_index = 0;
                if (fscanf(infile, "%hd %s %s %d %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd %hd %hd %hd %hd %hd",
                           &id, name, pict_name, &resource_id, &random, &med_color, &hi_color, &low_color, &sound_id,
                           &is_animated, &animation_frames, &interval, &pause_between_loops, &terrain_to_draw, &row,
                           &col, &lt_cliff_color, &rt_cliff_color, &impassable_terrain, &passable_terrain,
                           &border_num) != -1 &&
                    id < 32 && id >= 0) {
                    RGE_Tile_Set *terrain = &this->terrain_types[id];
                    RGE_TOB_Picts *pict = terrain->tiles;
                    for (int tile = 0; tile < 19; ++tile) {
                        fscanf(infile, "%hd %hd", &pict->count, &pict->animations);
                        pict->shape_index = shape_index;
                        shape_index += pict->count * pict->animations;
                        ++pict;
                    }

                    short border_index = 0;
                    if (border_num > 0) {
                        do {
                            fscanf(infile, "%hd %hd", &id, &border);
                            terrain->borders[id] = border;
                            ++border_index;
                        } while (border_index < border_num);
                    }

                    if (sound_id >= 0)
                        terrain->sound = sounds[sound_id];
                    else
                        terrain->sound = 0;
                    terrain->map_low_color = (unsigned char)low_color;
                    terrain->map_med_color = (unsigned char)med_color;
                    terrain->map_hi_color = (unsigned char)hi_color;
                    terrain->map_lt_cliff_color = (unsigned char)lt_cliff_color;
                    terrain->map_rt_cliff_color = (unsigned char)rt_cliff_color;
                    terrain->impassable_terrain = (unsigned char)impassable_terrain;
                    terrain->passable_terrain = (unsigned char)passable_terrain;
                    convert_us(name);
                    strcpy(terrain->name, name);
                    strcpy(terrain->pict_name, pict_name);
                    terrain->resource_id = resource_id;
                    terrain->animate_last = 0.0f;
                    terrain->loaded = 1;
                    terrain->rows = row;
                    terrain->cols = col;
                    terrain->is_animated = (unsigned char)is_animated;
                    terrain->animation_frames = animation_frames;
                    if (interval == DAT_005706ac)
                        terrain->pause_frames = 0;
                    else
                        terrain->pause_frames = (short)(long)(pause_between_loops / interval);
                    terrain->interval = interval;
                    terrain->frame = 0;
                    terrain->pause_between_loops = pause_between_loops;
                    terrain->draw_frame = 0;
                    terrain->frame_changed = 0;
                    terrain->drawn = 0;
                    terrain->terrain_to_draw = terrain_to_draw;
                }
            } while (--terrain_count != 0);
        }
    }
    fclose(infile);
}

void RGE_Map::load_border_types(RGE_Sound **sounds) {
    char *filename2 = 0;
    long *resource_id = &this->border_types[15].resource_id;
    int count = 16;

    do {
        RGE_Border_Set *border = (RGE_Border_Set *)(resource_id - 7);
        if (border->loaded != 0) {
            addstring(&filename2, border->pict_name, (char *)".shp");
            TShape *shape = new TShape(filename2, *resource_id);
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

void RGE_Map::load_border_types(char *border_table, RGE_Sound **sounds) {
    int i;
    for (i = 15; i >= 0; --i)
        this->border_types[i].loaded = 0;

    FILE *file = fopen(border_table, "r");
    if (file != 0) {
        fscanf(file, "%hd", &this->num_borders);
        short border_count = this->num_borders - 1;
        if (border_count >= 0) {
            long count = (int)border_count + 1;
            do {
                short border_id;
                short border_num;
                short map_med_color;
                short map_hi_color;
                short map_low_color;
                short sound_id;
                short is_animated;
                short animation_frames;
                float interval;
                float pause_between_loops;
                short tile_flag;
                short underlay_terrain;
                short border_style;
                long resource_id;
                char name[13];
                char pict_name[13];

                if (fscanf(file, "%hd %s %s %d %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd", &border_id, name,
                           pict_name, &resource_id, &border_num, &map_med_color, &map_hi_color, &map_low_color,
                           &sound_id, &is_animated, &animation_frames, &interval, &pause_between_loops, &tile_flag,
                           &underlay_terrain, &border_style) != EOF) {
                    if (border_id < 16 && border_id >= 0) {
                        RGE_Border_Set *border = &this->border_types[border_id];
                        short shape_index = 0;

                        for (i = 0; i < 19; ++i) {
                            RGE_TOB_Picts *tile = border->borders[i];
                            int j = 0;
                            do {
                                fscanf(file, "%hd %hd", &tile->count, &tile->animations);
                                tile->shape_index = shape_index;
                                shape_index += tile->count * tile->animations;
                                ++tile;
                                ++j;
                            } while (j < 12);
                        }

                        if (sound_id < 0)
                            border->sound = 0;
                        else
                            border->sound = sounds[sound_id];
                        border->map_low_color = (unsigned char)map_low_color;
                        border->map_med_color = (unsigned char)map_med_color;
                        border->map_hi_color = (unsigned char)map_hi_color;
                        convert_us(name);
                        strcpy(border->name, name);
                        strcpy(border->pict_name, pict_name);
                        border->resource_id = resource_id;
                        border->loaded = 1;
                        border->is_animated = (unsigned char)is_animated;
                        border->animation_frames = animation_frames;
                        if (interval == 0.0f)
                            border->pause_frames = 0;
                        else
                            border->pause_frames = (short)(pause_between_loops / interval);
                        border->interval = interval;
                        border->pause_between_loops = pause_between_loops;
                        border->frame = 0;
                        border->draw_frame = 0;
                        border->animate_last = 0.0f;
                        border->frame_changed = 0;
                        border->drawn = 0;
                        border->draw_tile = (unsigned char)tile_flag;
                        border->underlay_terrain = underlay_terrain;
                        border->border_style = border_style;
                    }
                }
                --count;
            } while (count != 0);
        }
    }
    fclose(file);
}

void RGE_Map::load_terrain_obj_types(char *terr_obj_tbl) {
    FILE *file = fopen(terr_obj_tbl, "r");
    if (file != 0) {
        short num;
        short density;
        short flag;
        short obj_id;
        short id;

        fscanf(file, "%hd", &num);
        while (fscanf(file, "%hd %hd %hd %hd", &id, &obj_id, &density, &flag) != EOF) {
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

void RGE_Map::delete_objects_on_tile(RGE_Player *obj_owner, RGE_Game_World *gworld, int x, int y, int no_delete_start,
                                     int no_delete_end) {
    if (x < 0 || x >= this->map_width || y < 0 || y >= this->map_height)
        return;

    RGE_Object_Node *p = this->map_row_offset[y][x].objects.list;
    if (p == 0)
        return;

    while (p != 0) {
        RGE_Static_Object *obj = p->node;
        RGE_Object_Node *next = p->next;
        int obj_id = obj->master_obj->id;
        if (obj->owner == obj_owner) {
            if (obj_id < no_delete_start || obj_id > no_delete_end) {
                if (obj != 0)
                    delete obj;
            }
        }
        p = next;
    }
}

void RGE_Map::delete_all_objects_on_tile(int x, int y) {
    if (x < 0 || x >= this->map_width)
        return;
    if (y < 0 || y >= this->map_height)
        return;

    RGE_Object_Node *node = this->map_row_offset[y][x].objects.list;
    while (node != 0) {
        RGE_Object_Node *next = node->next;
        RGE_Static_Object *object = node->node;
        if (object != 0)
            delete object;
        node = next;
    }
}

void RGE_Map::create_terrain_object(RGE_Player *obj_owner, RGE_Game_World *gworld, short row, short col,
                                    short old_terrain, int delete_obj, int no_delete_start, int no_delete_end) {
    float x = 0.0f;
    float y = 0.0f;
    short terrain = this->get_terrain(col, row);
    short end_i = this->terrain_types[terrain].num_obj_type;

    if (end_i > 0) {
        RGE_Object_Node *list = this->map_row_offset[row][col].objects.list;

        while (list != 0) {
            RGE_Static_Object *object = list->node;
            RGE_Object_Node *next_list = list->next;
            short object_type = object->master_obj->id;

            if (object->owner == obj_owner && (object_type < no_delete_start || object_type > no_delete_end)) {
                if (old_terrain < 0) {
                    if (delete_obj != 0) {
                        if (object != 0)
                            delete object;
                    } else {
                        object->destroy_obj();
                    }
                } else {
                    short index;
                    for (index = this->terrain_types[old_terrain].num_obj_type; index >= 0; --index) {
                        if (this->terrain_types[old_terrain].obj_types[index] == object_type)
                            break;
                    }

                    if (index >= 0) {
                        if (delete_obj != 0) {
                            if (object != 0)
                                delete object;
                        } else {
                            object->destroy_obj();
                        }
                    }
                }
            }
            list = next_list;
        }

        for (int i = 0; i < end_i; ++i) {
            int object_type = (short)this->terrain_types[terrain].obj_types[i];
            if (object_type != -1) {
                RGE_Master_Static_Object *master_obj = obj_owner->master_objects[object_type];
                short obj_density = this->terrain_types[terrain].obj_density[i];
                unsigned char obj_flag = this->terrain_types[terrain].obj_placement_flag[i];

                if (master_obj != 0 && obj_density > 0) {
                    int density_left = obj_density;
                    do {
                        if (obj_flag == 0) {
                            x = (float)(int)col -
                                (float)debug_rand((char *)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x813) * -3.051851e-05f;
                            y = (float)(int)row -
                                (float)debug_rand((char *)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x814) * -3.051851e-05f;
                        } else if (obj_flag == 1) {
                            x = (float)(int)col - -0.5f;
                            y = (float)(int)row - -0.5f;
                        }

                        int place_it;
                        if (obj_density >= 1000) {
                            place_it = 1;
                        } else {
                            int random_value = debug_rand((char *)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x820);
                            place_it = ((random_value * 1000) / 0x7fff) < density_left;
                        }

                        if (place_it) {
                            if (!master_obj->check_placement(obj_owner, x, y, 0, 0, 1, 0, 1, 0, 1))
                                master_obj->make_new_obj(obj_owner, x, y, 0);
                        }
                        obj_density -= 1000;
                        density_left -= 1000;
                    } while (obj_density > 0);
                }
            }
        }
    }
}

int RGE_Map::clear_terrain_object(RGE_Game_World *gworld, short row, short col, short old_terrain, int delete_obj,
                                  int no_delete_start, int no_delete_end) {
    short object_type = -1;
    RGE_Object_Node *list;
    RGE_Object_Node *next_list;

    this->get_terrain(col, row);
    list = this->map_row_offset[row][col].objects.list;

    while (list != 0) {
        RGE_Static_Object *object = list->node;
        next_list = list->next;

        if (object->master_obj->id < no_delete_start || object->master_obj->id > no_delete_end) {
            if (old_terrain < 0) {
                if (delete_obj != 0) {
                    if (object != 0)
                        delete object;
                } else {
                    object->destroy_obj();
                }
            } else {
                object_type = object->master_obj->id;
                short index;
                for (index = this->terrain_types[old_terrain].num_obj_type; index >= 0; --index) {
                    if (this->terrain_types[old_terrain].obj_types[index] == object_type)
                        break;
                }

                if (index >= 0) {
                    if (delete_obj != 0) {
                        if (object != 0)
                            delete object;
                    } else {
                        object->destroy_obj();
                    }
                } else if (object->master_obj->check_placement(object->owner, object->world_x, object->world_y, 0, 0, 1,
                                                               1, 1, 0, 0)) {
                    object = list->node;
                    if (delete_obj != 0) {
                        if (object != 0)
                            delete object;
                    } else {
                        object->destroy_obj();
                    }
                }
            }
        }
        list = next_list;
    }

    return object_type;
}

void RGE_Map::place_terrain_object(RGE_Player *player, RGE_Game_World *gworld, short row, short col, int obj_type_id,
                                   int FillFlag) {
    RGE_Master_Static_Object *master_obj;
    int end_i;
    int terrain;
    terrain = this->get_terrain(col, row);
    end_i = this->terrain_types[terrain].num_obj_type;
    int i = 0;
    float x;
    float y;

    for (i = 0; i < end_i; ++i) {
        int object_type = (short)this->terrain_types[terrain].obj_types[i];
        if (object_type != -1) {
            master_obj = player->master_objects[object_type];
            short obj_density = this->terrain_types[terrain].obj_density[i];
            unsigned char obj_flag = this->terrain_types[terrain].obj_placement_flag[i];

            if (master_obj != 0) {
                if (FillFlag == 0) {
                    if (obj_density > 0) {
                        int density_left = obj_density;
                        do {
                            if (obj_flag != 0) {
                                x = (float)(int)col - -0.5f;
                                y = (float)(int)row - -0.5f;
                            } else {
                                x = (float)(int)col -
                                    (float)debug_rand((char *)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x894) *
                                        -3.051851e-05f;
                                y = (float)(int)row -
                                    (float)debug_rand((char *)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x895) *
                                        -3.051851e-05f;
                            }

                            int place_it;
                            if (obj_density >= 1000) {
                                place_it = 1;
                            } else {
                                int random_value = debug_rand((char *)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x8A2);
                                place_it = ((random_value * 1000) / 0x7fff) < density_left;
                            }

                            if (place_it) {
                                if (!master_obj->check_placement(player, x, y, 0, 0, 1, 0, 1, 0, 1))
                                    master_obj->make_new_obj(player, x, y, 0);
                            }
                            obj_density -= 1000;
                            density_left -= 1000;
                        } while (obj_density > 0);
                    }
                } else if (FillFlag == 1) {
                    if (obj_flag != 0) {
                        x = (float)(int)col - -0.5f;
                        y = (float)(int)row - -0.5f;
                    } else {
                        x = (float)(int)col -
                            (float)debug_rand((char *)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x8AF) * -3.051851e-05f;
                        y = (float)(int)row -
                            (float)debug_rand((char *)"C:\\msdev\\work\\age1_x1\\map.cpp", 0x8B0) * -3.051851e-05f;
                    }

                    if (!master_obj->check_placement(player, x, y, 0, 0, 1, 0, 1, 0, 1)) {
                        master_obj->make_new_obj(player, x, y, 0);
                        return;
                    }
                }
            }
        }
    }
}

void RGE_Map::create_terrain_objects(RGE_Player *obj_owner, RGE_Game_World *gworld) {
    short y = 0;
    short x = 0;

    if (this->map_height > 0) {
        do {
            x = 0;
            if (this->map_width > 0) {
                do {
                    this->create_terrain_object(obj_owner, gworld, y, x, -1, 0, -1, -1);
                    x++;
                } while (x < this->map_width);
            }
            y++;
        } while (y < this->map_height);
    }
}

void RGE_Map::set_tile_size(unsigned char tile_type, short width, short height, short y_delta) {
    this->tilesizes[tile_type].width = width;
    this->tilesizes[tile_type].height = height;
    this->tilesizes[tile_type].y_delta = y_delta;
}

void RGE_Map::tile_map_coords(short x, short y, RGE_Tile *tile, float *offset_x, float *offset_y) {
    double offset;
    double x_ratio;
    double y_value;
    double y_ratio;
    double z;

    x_ratio = (float)(int)x / (float)(int)this->tile_width;
    offset = 0.0f;
    y_value = (float)(int)y;
    y_ratio = y_value / (float)(int)this->tile_height;
    switch (tile->tile_type) {
    case 0:
    case 9:
        goto case_zero;
    case 1:
        if (x_ratio <= DAT_005706c0) {
            offset = (y_ratio + y_ratio) - ((DAT_005706c0 - x_ratio) + (DAT_005706c0 - x_ratio));
        } else {
            offset = (y_ratio + y_ratio) - ((x_ratio - DAT_005706c0) + (x_ratio - DAT_005706c0));
        }
        break;
    case 2:
        if (DAT_005706c0 < x_ratio) {
            offset = x_ratio * DAT_005706d0 - (y_ratio - DAT_005706c0);
            break;
        }
        goto case_eight;
    case 3:
        offset = DAT_005706d8 - x_ratio;
        if (x_ratio * DAT_005706c0 < y_value) {
            offset = offset * DAT_005706c0 - (y_ratio - DAT_005706c0);
            break;
        }
        y_value = y_ratio + y_ratio;
        offset = (offset + offset) - DAT_005706d8;
        goto add_vertical;
    case 4:
        if ((DAT_005706d8 - x_ratio) * DAT_005706c0 < y_value) {
            offset = x_ratio * DAT_005706c0 - (y_ratio - DAT_005706c0);
            break;
        }
    case 7:
    case_seven:
        y_value = y_ratio + y_ratio;
        offset = (x_ratio + x_ratio) - DAT_005706d8;
    add_vertical:
        offset = offset + y_value;
        break;
    case 5:
        goto case_five;
    case 6:
        goto case_six;
    case 8:
        goto case_eight;
    case 14:
        if (x_ratio <= DAT_005706c0)
            goto case_six;
        goto case_eight;
    case_eight:
        offset = (DAT_005706d8 - x_ratio) * DAT_005706d0 - (y_ratio - DAT_005706c0);
        break;
    case_six:
        offset = x_ratio * DAT_005706d0 - (y_ratio - DAT_005706c0);
        break;
    case 10:
        if (DAT_005706d8 <= y_ratio) {
            offset = -DAT_005706d8;
        } else {
            offset = -y_ratio;
        }
        break;
    case 11:
        if (x_ratio <= DAT_005706c0) {
            offset = (DAT_005706c0 - x_ratio) + (DAT_005706c0 - x_ratio);
            break;
        }
        goto case_zero;
    case 12:
        if (DAT_005706c0 < x_ratio) {
            offset = (x_ratio - DAT_005706c0) + (x_ratio - DAT_005706c0);
            break;
        }
    case_zero:
        offset = 0.0f;
        break;
    case 13:
        if (x_ratio <= DAT_005706c0) {
            offset = (DAT_005706c0 - x_ratio) + y_ratio;
            offset = offset + offset;
        } else {
            offset = (x_ratio - DAT_005706c0) + y_ratio;
            offset = offset + offset;
        }
        break;
    case 15:
        if (y_value <= DAT_005706d8 - x_ratio * DAT_005706c0)
            goto case_seven;
        goto case_eight;
    case 16:
        if (DAT_005706d8 - (DAT_005706d8 - x_ratio) * DAT_005706c0 < y_value)
            goto case_six;
    case_five:
        offset = y_ratio + y_ratio;
        y_value = DAT_005706d8 - (x_ratio + x_ratio);
        goto add_vertical;
    }

    offset = (((x_ratio + x_ratio) - (DAT_005706d8 - (y_ratio + y_ratio))) + offset) * DAT_005706c0;
    *offset_y = offset;
    *offset_x = (x_ratio + x_ratio) - offset;
}

unsigned char RGE_Map::check_map_coords(short mapcol, short maprow) {
    if ((mapcol >= 0) && ((int)mapcol < this->map_width) && (maprow >= 0) && ((int)maprow < this->map_height))
        return 1;
    return 0;
}

unsigned char RGE_Map::get_elev(short mapcol, short maprow) {
    unsigned char elev = (unsigned char)(this->map_row_offset[maprow][mapcol].height);
    if (elev > 8)
        elev = 0;
    return elev;
}

unsigned char RGE_Map::get_terrain(short mapcol, short maprow) {
    unsigned char id = this->map_row_offset[maprow][mapcol].terrain_type & 0x1F;
    if (id <= 0x20) {
        unsigned int idx = id;
        if (this->terrain_types[idx].loaded != 0 || this->terrain_types[idx].terrain_to_draw >= 0)
            return id;
    }
    return 0;
}

unsigned char RGE_Map::get_border(short mapcol, short maprow) {
    unsigned char border_type = this->map_row_offset[maprow][mapcol].border_type & 0x0F;
    if (border_type > 0x10 || this->border_types[border_type].loaded == 0)
        border_type = 0;
    return border_type;
}

void RGE_Map::set_terrain_passablity(short mapcol1, short maprow1, short mapcol2, short maprow2,
                                     unsigned char passabilty) {
    short temp;

    if (maprow1 > maprow2) {
        temp = maprow2;
        maprow2 = maprow1;
        maprow1 = temp;
    }
    if (mapcol1 > mapcol2) {
        temp = mapcol2;
        mapcol2 = mapcol1;
        mapcol1 = temp;
    }

    if (maprow1 < 0)
        maprow1 = 0;
    if (maprow2 >= this->map_height)
        maprow2 = (short)this->map_height - 1;
    if (mapcol1 < 0)
        mapcol1 = 0;
    if (mapcol2 >= this->map_width)
        mapcol2 = (short)this->map_width - 1;

    for (short row = maprow1; row <= maprow2; ++row) {
        for (short col = mapcol1; col <= mapcol2; ++col) {
            RGE_Tile *tile = &this->map_row_offset[row][col];
            short terrain = tile->terrain_type;
            if (passabilty != 0)
                tile->terrain_type = this->terrain_types[terrain].passable_terrain;
            else
                tile->terrain_type = this->terrain_types[terrain].impassable_terrain;
        }
    }
}

void RGE_Map::set_elev(short mapcol1, short maprow1, short mapcol2, short maprow2, unsigned char elev, short delta,
                       unsigned char set_flag) {
    short row_i;
    short col_i;
    RGE_Tile *tile;
    RGE_Player *cur_player = this->game_world->players[this->game_world->curr_player];

    if (maprow1 > maprow2) {
        short temp = maprow2;
        maprow2 = maprow1;
        maprow1 = temp;
    }
    if (mapcol1 > mapcol2) {
        short temp = mapcol2;
        mapcol2 = mapcol1;
        mapcol1 = temp;
    }

    if (maprow1 < 0)
        maprow1 = 0;
    if (maprow2 >= this->map_height)
        maprow2 = (short)this->map_height - 1;
    if (mapcol1 < 0)
        mapcol1 = 0;
    if (mapcol2 >= this->map_width)
        mapcol2 = (short)this->map_width - 1;

    if (set_flag != 0) {
        if (delta != 0) {
            for (row_i = maprow1; row_i <= maprow2; ++row_i) {
                for (col_i = mapcol1; col_i <= mapcol2; ++col_i) {
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
            if (elev > 8)
                elev = 8;
            for (row_i = maprow1; row_i <= maprow2; ++row_i) {
                for (col_i = mapcol1; col_i <= mapcol2; ++col_i) {
                    tile = &this->map_row_offset[row_i][col_i];
                    tile->height = elev;
                }
            }
        }
    }

    if (maprow1 > 0)
        --maprow1;
    if (maprow2 < this->map_height - 1)
        ++maprow2;
    if (mapcol1 > 0)
        --mapcol1;
    if (mapcol2 < this->map_width - 1)
        ++mapcol2;

    for (row_i = maprow1; row_i <= maprow2; ++row_i) {
        for (col_i = mapcol1; col_i <= mapcol2; ++col_i) {
            tile = &this->map_row_offset[row_i][col_i];
            tile->tile_type = this->get_tile_type(col_i, row_i);
            RGE_Object_Node *object_node = tile->objects.list;
            while (object_node != 0) {
                object_node->node->teleport(object_node->node->world_x, object_node->node->world_y, 0.0f);
                object_node = object_node->next;
            }
            if (this->game_world->game_state != 3)
                cur_player->diam_tile_list.add_node(col_i, row_i);
        }
    }

    this->set_map_screen_pos((int)mapcol1, (int)maprow1, (int)mapcol2, (int)maprow2);
    this->request_redraw((int)mapcol1, (int)maprow1, (int)mapcol2, (int)maprow2, 0);
}

void RGE_Map::set_terrain(RGE_Game_World *gworld, short mapcol, short maprow, unsigned char terrain,
                          int no_delete_start, int no_delete_end) {
    RGE_Player *obj_owner;
    RGE_Player *cur_player;
    RGE_Tile *tile;
    int row_i;
    int col_i;
    short old_terrain;

    obj_owner = *gworld->players;
    cur_player = this->game_world->players[this->game_world->curr_player];
    row_i = (int)maprow;
    col_i = (int)mapcol;
    tile = &this->map_row_offset[row_i][col_i];
    old_terrain = (short)(tile->terrain_type & 0x1F);

    if (old_terrain != terrain) {
        tile->terrain_type = (terrain ^ tile->terrain_type) & 0x1F ^ tile->terrain_type;
        if (obj_owner != 0) {
            request_redraw(col_i, row_i, col_i, row_i, 0);
            if (gworld->game_state != 3)
                cur_player->diam_tile_list.add_node(col_i, row_i);
            int value = clear_terrain_object(gworld, maprow, mapcol, old_terrain, 1, no_delete_start, no_delete_end);
            place_terrain_object(obj_owner, gworld, maprow, mapcol, value, 0);
        }
    }
    get_border_type(mapcol, maprow);
}

void RGE_Map::set_terrain_absolute(RGE_Game_World *gworld, short mapcol, short maprow, unsigned char terrain,
                                   int no_delete_start, int no_delete_end) {
    RGE_Player *obj_owner;
    RGE_Tile *tile;

    obj_owner = (RGE_Player *)*gworld->players;
    tile = &this->map_row_offset[maprow][mapcol];
    tile->terrain_type = terrain;

    if (obj_owner != 0) {
        int result = clear_terrain_object(gworld, maprow, mapcol, -1, 1, no_delete_start, no_delete_end);
        place_terrain_object(obj_owner, gworld, maprow, mapcol, result, 1);
    }
    get_border_type(mapcol, maprow);
}

void RGE_Map::set_terrain(RGE_Player *obj_owner, RGE_Game_World *gworld, short mapcol1, short maprow1, short mapcol2,
                          short maprow2, unsigned char terrain, unsigned char set_flag, int delete_obj) {
    short terrain_id = (short)(unsigned short)terrain;

    if (terrain_id >= this->num_terrain)
        return;

    if (this->terrain_types[terrain_id].loaded == 0) {
        short terrain_to_draw = this->terrain_types[terrain_id].terrain_to_draw;
        if (terrain_to_draw < 0 || this->terrain_types[terrain_to_draw].loaded != 1)
            return;
    }

    if (maprow1 > maprow2) {
        short temp = maprow2;
        maprow2 = maprow1;
        maprow1 = temp;
    }
    if (mapcol1 > mapcol2) {
        short temp = mapcol2;
        mapcol2 = mapcol1;
        mapcol1 = temp;
    }

    if (maprow1 < 0)
        maprow1 = 0;
    if (maprow2 >= this->map_height)
        maprow2 = (short)this->map_height - 1;
    if (mapcol1 < 0)
        mapcol1 = 0;
    if (mapcol2 >= this->map_width)
        mapcol2 = (short)this->map_width - 1;

    if (set_flag != 0 || obj_owner != 0) {
        short maprow = maprow1;
        if (maprow <= maprow2) {
            do {
                short col = mapcol1;
                if (col <= mapcol2) {
                    unsigned char *tile_data =
                        reinterpret_cast<unsigned char *>(this->map_row_offset[maprow] + col) + 5;
                    do {
                        if (0 < this->terrain_types[terrain_id].tiles[tile_data[-1]].count) {
                            unsigned char old_terrain = *tile_data;
                            short old_terrain_id = (short)(old_terrain & 0x1f);

                            if (old_terrain_id != terrain_id && set_flag != 0) {
                                *tile_data = (unsigned char)(((terrain ^ old_terrain) & 0x1f) ^ old_terrain);
                            }

                            if (obj_owner != 0) {
                                this->create_terrain_object(obj_owner, gworld, maprow, col, old_terrain_id, delete_obj,
                                                            -1, -1);
                            }
                        }
                        ++col;
                        tile_data += sizeof(RGE_Tile);
                    } while (col <= mapcol2);
                }
                ++maprow;
            } while (maprow <= maprow2);
        }
    }

    if (maprow1 > 0)
        --maprow1;
    if (maprow2 < this->map_height - 1)
        ++maprow2;
    if (mapcol1 > 0)
        --mapcol1;
    if (mapcol2 < this->map_width - 1)
        ++mapcol2;

    for (short row = maprow1; row <= maprow2; ++row) {
        for (short col = mapcol1; col <= mapcol2; ++col)
            this->get_border_type(col, row);
    }

    this->request_redraw((int)mapcol1, (int)maprow1, (int)mapcol2, (int)maprow2, 0);
}

unsigned char RGE_Map::get_tile_type(short map_col, short map_row) {
    long width;
    long height;
    RGE_Tile **rows;
    RGE_Tile *row;
    RGE_Tile *tile;
    unsigned short c, cp1, cm1;
    unsigned short nw, n, ne, w, e, sw, s, se;

    if (map_col < 0)
        return 0;
    if ((long)map_col >= this->map_width)
        return 0;
    width = this->map_width;
    if (map_row < 0)
        return 0;
    height = this->map_height;
    if ((long)map_row >= height)
        return 0;

    rows = this->map_row_offset;
    row = rows[map_row];
    tile = row + map_col;
    c = (unsigned short)(rows[map_row][map_col].height);
    cp1 = c + 1;
    cm1 = c - 1;

    if (map_row > 0 && (long)map_col < width - 1)
        nw = (unsigned short)(rows[map_row - 1][map_col + 1].height);
    else
        nw = c;
    if (map_row > 0)
        n = (unsigned short)(rows[map_row - 1][map_col].height);
    else
        n = c;
    if ((long)map_col < width - 1)
        e = (unsigned short)(tile[1].height);
    else
        e = c;
    if (map_col > 0 && (long)map_row < height - 1)
        sw = (unsigned short)(rows[map_row + 1][map_col - 1].height);
    else
        sw = c;
    if (map_col > 0)
        w = (unsigned short)(tile[-1].height);
    else
        w = c;
    if ((long)map_row < height - 1)
        s = (unsigned short)(rows[map_row + 1][map_col].height);
    else
        s = c;
    if (map_row > 0 && map_col > 0)
        ne = (unsigned short)(rows[map_row - 1][map_col - 1].height);
    else
        ne = c;
    if ((long)map_row < height - 1 && (long)map_col < width - 1)
        se = (unsigned short)(rows[map_row + 1][map_col + 1].height);
    else
        se = c;

    if (n == cp1 && e == cp1)
        return 0x0e;
    if (w == cp1 && s == cp1)
        return 0x0d;
    if (n == cp1 && w == cp1)
        return 0x10;
    if (e == cp1 && s == cp1)
        return 0x0f;
    if (n == cp1)
        return 6;
    if (e == cp1)
        return 8;
    if (w == cp1)
        return 5;
    if (s == cp1)
        return 7;
    if (nw == cp1) {
        if (w == cm1 && s == cm1)
            return 2;
        return 0x0a;
    }
    if (sw == cp1) {
        if (n == cm1 && e == cm1)
            return 1;
        return 9;
    }
    if (ne == cp1) {
        if (e == cm1 && s == cm1)
            return 3;
        return 0x0b;
    }
    if (se == cp1) {
        if (n == cm1 && w == cm1)
            return 4;
        return 0x0c;
    }
    return 0;
}

void RGE_Map::get_border_type(short map_col, short map_row) {
    unsigned char ter_top_lft;
    unsigned char ter_lft;
    unsigned char ter_rgt;
    unsigned char ter_bot;
    unsigned char ter_bot_lft;
    unsigned char ter_bot_rgt;
    unsigned char ter_top_rgt;
    int yMax;
    int xMax;
    int xi;
    unsigned char ter_top;
    unsigned char ter_cur;

    if (map_col < 0 || map_col >= this->map_width || map_row < 0 || map_row >= this->map_height)
        return;

    RGE_Tile **rows = this->map_row_offset;
    xi = map_col;
    RGE_Tile *tile = rows[map_row] + xi;
    ter_top_lft = tile->terrain_type & 0x1f;
    if (map_row > 0)
        ter_lft = rows[map_row - 1][xi].terrain_type & 0x1f;
    else
        ter_lft = ter_top_lft;
    yMax = this->map_height - 1;
    if (map_row < yMax)
        ter_bot = rows[map_row + 1][xi].terrain_type & 0x1f;
    else
        ter_bot = ter_top_lft;
    if (map_col > 0)
        ter_rgt = rows[map_row][xi - 1].terrain_type & 0x1f;
    else
        ter_rgt = ter_top_lft;
    xMax = this->map_width - 1;
    if (xi < xMax)
        ter_top_rgt = rows[map_row][xi + 1].terrain_type & 0x1f;
    else
        ter_top_rgt = ter_top_lft;
    if (map_row > 0 && map_col > 0)
        ter_bot_lft = rows[map_row - 1][xi - 1].terrain_type & 0x1f;
    else
        ter_bot_lft = ter_top_lft;
    if (map_row > 0 && xi < xMax)
        ter_top = rows[map_row - 1][xi + 1].terrain_type & 0x1f;
    else
        ter_top = ter_top_lft;
    if (map_row < yMax && map_col > 0)
        ter_bot_rgt = rows[map_row + 1][xi - 1].terrain_type & 0x1f;
    else
        ter_bot_rgt = ter_top_lft;
    if (map_row < yMax && xi < xMax)
        ter_cur = rows[map_row + 1][xi + 1].terrain_type & 0x1f;
    else
        ter_cur = ter_top_lft;

    check_for_border(ter_top_lft, ter_lft);
    check_for_border(ter_top_lft, ter_bot);
    check_for_border(ter_top_lft, ter_rgt);
    check_for_border(ter_top_lft, ter_top_rgt);
    check_for_border(ter_top_lft, ter_bot_lft);
    check_for_border(ter_top_lft, ter_top);
    check_for_border(ter_top_lft, ter_bot_rgt);
    check_for_border(ter_top_lft, ter_cur);

    unsigned char bor_ter;
    if (ter_lft != ter_top_lft)
        bor_ter = ter_lft;
    else if (ter_bot != ter_top_lft)
        bor_ter = ter_bot;
    else if (ter_rgt != ter_top_lft)
        bor_ter = ter_rgt;
    else if (ter_top_rgt != ter_top_lft)
        bor_ter = ter_top_rgt;
    else if (ter_bot_lft != ter_top_lft)
        bor_ter = ter_bot_lft;
    else if (ter_top != ter_top_lft)
        bor_ter = ter_top;
    else if (ter_bot_rgt != ter_top_lft)
        bor_ter = ter_bot_rgt;
    else if (ter_cur != ter_top_lft)
        bor_ter = ter_cur;
    else {
        tile->border_type = 0;
        tile->border_shape = 0;
        return;
    }

    short *border_table = this->terrain_types[ter_top_lft].borders;
    short border = border_table[bor_ter];
    if (border == -1 || border < 0 || border >= 16 || this->border_types[border].loaded == 0) {
        tile->border_type = 0;
        tile->border_shape = 0;
        return;
    }

    unsigned char edge;
    if (this->border_types[border].border_style == 1) {
        edge = 0;
        if (border_table[(unsigned char)ter_lft] == border)
            edge |= 1;
        if (border_table[(unsigned char)ter_bot] == border)
            edge += 2;
        if (border_table[(unsigned char)ter_rgt] == border)
            edge += 4;
        if (border_table[(unsigned char)ter_top_rgt] == border)
            edge += 8;
        tile->border_type = (unsigned char)border;
        tile->border_shape = edge;
        return;
    }

    if (border_table[(unsigned char)ter_lft] == border && border_table[(unsigned char)ter_rgt] == border)
        edge = 1;
    else if (border_table[(unsigned char)ter_lft] == border && border_table[(unsigned char)ter_top_rgt] == border)
        edge = 2;
    else if (border_table[(unsigned char)ter_bot] == border && border_table[(unsigned char)ter_rgt] == border)
        edge = 3;
    else if (border_table[(unsigned char)ter_bot] == border && border_table[(unsigned char)ter_top_rgt] == border)
        edge = 4;
    else if (border_table[(unsigned char)ter_lft] == border)
        edge = 9;
    else if (border_table[(unsigned char)ter_bot] == border)
        edge = 10;
    else if (border_table[(unsigned char)ter_rgt] == border)
        edge = 11;
    else if (border_table[(unsigned char)ter_top_rgt] == border)
        edge = 12;
    else if (border_table[(unsigned char)ter_bot_lft] == border)
        edge = 5;
    else if (border_table[(unsigned char)ter_top] == border)
        edge = 6;
    else if (border_table[(unsigned char)ter_bot_rgt] == border)
        edge = 7;
    else if (border_table[ter_cur] == border)
        edge = 8;
    else {
        tile->border_type = 0;
        tile->border_shape = 0;
        return;
    }

    tile->border_type = (unsigned char)border;
    tile->border_shape = edge;
}

void RGE_Map::check_for_border(unsigned char cur_ter, unsigned char &bor_ter) {
    if (bor_ter == cur_ter)
        return;
    short border = this->terrain_types[cur_ter].borders[bor_ter];
    if (border == -1 || border < 0 || border >= 0x10 || this->border_types[border].loaded == 0)
        bor_ter = cur_ter;
}

void RGE_Map::update(unsigned long world_time) {
    static unsigned long last_world_time;

    if (world_time - last_world_time < 100)
        return;

    float cur_time = (float)world_time * DAT_005706e8;
    short i;

    for (i = 0; i < this->num_terrain; ++i) {
        RGE_Tile_Set *terrain = &this->terrain_types[i];
        if (terrain->is_animated) {
            float elapsed = cur_time - terrain->animate_last;
            if (terrain->interval <= elapsed) {
                short frame_count = (short)(elapsed / terrain->interval);
                short animation_frames = terrain->animation_frames;
                short frame = frame_count + terrain->frame;
                short total_frames = terrain->pause_frames + animation_frames;

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
                terrain->animate_last = cur_time - (elapsed - (float)frame_count * terrain->interval);
            }
        }
    }

    for (i = 0; i < this->num_borders; ++i) {
        RGE_Border_Set *border = &this->border_types[i];
        if (border->is_animated) {
            float elapsed = cur_time - border->animate_last;
            if (border->interval <= elapsed) {
                short frame_count = (short)(elapsed / border->interval);
                short animation_frames = border->animation_frames;
                short frame = frame_count + border->frame;
                short total_frames = border->pause_frames + animation_frames;

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
                border->animate_last = cur_time - (elapsed - (float)frame_count * border->interval);
            }
        }
    }

    last_world_time = world_time;
}

void RGE_Map::get_point(short &screen_x, short &screen_y, float x, float y, float z, short x_offset, short y_offset) {
    screen_x = (short)((int)((y + x) * this->tile_half_width) + x_offset);
    screen_y = (short)((int)((y + 1.0f - x - z) * this->tile_half_height) + y_offset - 0x10);
}
