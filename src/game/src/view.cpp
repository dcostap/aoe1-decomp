#include "RGE_View.h"
#include "RGE_Player.h"
#include "RGE_Map.h"
#include "RGE_Game_World.h"
#include "TSpan_List_Manager.h"
#include "TDrawArea.h"
#include "RGE_Base_Game.h"
#include "RGE_Visible_Map.h"
#include "RGE_Static_Object.h"
#include "RGE_Master_Static_Object.h"
#include "RGE_Sprite.h"
#include "TShape.h"
#include "TMousePointer.h"
#include "TMessagePanel.h"
#include "RGE_Tile_Set.h"
#include "RGE_Border_Set.h"
#include "globals.h"
#include <cstdio>
#include <cstdlib>

extern "C" void _ASMSet_Shadowing(int p1, int p2, int p3, int p4);

// Global variables (from decomp)
int view_debug_redraw_all = 0;
int view_debug_ObstructionMap = 0;
int view_debug_palette = 0;
int tiles_drawn = 0;
int frame_count = 0;
int View_Grid_Mode = 0;
extern TMousePointer* MouseSystem;
extern RGE_Base_Game* rge_base_game;

static int rge_view_get_border_edge_pictures(
    RGE_View* self,
    uchar border_type,
    uchar tile_type,
    uchar border_shape_bits,
    short col,
    short row,
    int* left_index,
    int* bottom_index,
    int* right_index,
    int* center_index) {
    if (left_index) *left_index = -1;
    if (bottom_index) *bottom_index = -1;
    if (right_index) *right_index = -1;
    if (center_index) *center_index = -1;

    if (self == nullptr || self->map == nullptr || border_type >= 16) {
        return 0;
    }
    if (self->map->border_types[border_type].shape == nullptr) {
        return 0;
    }
    if (border_shape_bits == 0) {
        return 0;
    }

    // Source of truth: view.cpp.decomp @ 0x00539C80.
    if ((border_shape_bits & 0x01) != 0) {
        short s = self->get_border_picture(border_type, tile_type, 0x01, col, row);
        if (left_index) *left_index = (int)s;
    }
    if ((border_shape_bits & 0x02) != 0) {
        short s = self->get_border_picture(border_type, tile_type, 0x04, col, row);
        if (center_index) *center_index = (int)s;
    }
    if ((border_shape_bits & 0x04) != 0) {
        short s = self->get_border_picture(border_type, tile_type, 0x03, col, row);
        if (right_index) *right_index = (int)s;
    }
    if ((border_shape_bits & 0x08) != 0) {
        short s = self->get_border_picture(border_type, tile_type, 0x02, col, row);
        if (bottom_index) *bottom_index = (int)s;
    }
    return 1;
}

static void rge_view_try_load_sprite_shape(RGE_Sprite* spr) {
    if (spr == nullptr || spr->shape != nullptr) {
        return;
    }
    if (spr->pict_name[0] == '\0') {
        return;
    }

    char shp_name[64];
    std::snprintf(shp_name, sizeof(shp_name), "%s.shp", spr->pict_name);
    shp_name[sizeof(shp_name) - 1] = '\0';

    TShape* loaded_shape = new TShape(shp_name, spr->resource_id);
    if (loaded_shape != nullptr && loaded_shape->is_loaded() != 0) {
        spr->shape = loaded_shape;
        spr->loaded = 1;
    } else if (loaded_shape != nullptr) {
        delete loaded_shape;
    }
}

void RGE_View::draw()
{
    tiles_drawn = 0;
    if (view_debug_redraw_all != 0) {
        this->render_terrain_mode = 0;
        view_debug_redraw_all = 0;
    }
    if (view_debug_ObstructionMap != 0 || view_debug_palette != 0) {
        this->render_terrain_mode = 0;
    }

    if (this->world == nullptr) {
        this->draw_setup(0);
        if (this->cur_render_area) {
           this->cur_render_area->Clear(&this->cur_render_area->ClipRect, 0);
        }
        this->draw_finish();
        return;
    }

    if (this->Terrain_Clip_Mask) this->Terrain_Clip_Mask->ResetAll();
    if (this->Terrain_Fog_Clip_Mask) this->Terrain_Fog_Clip_Mask->ResetAll();
    if (this->Master_Clip_Mask) this->Master_Clip_Mask->ResetAll();

    this->Use_Rect2 = 0;
    this->Limited_Render_Rect = 0;

    this->update();

    this->draw_setup(0);

    if (this->render_terrain_mode == 0) {
        this->Float_X_Delta = 0;
        this->Float_Y_Delta = 0;
        if (this->save_area1) {
            this->save_area1->SetFloatOffsets(0, 0);
            this->save_area1->Clear(&this->save_area1->ClipRect, 0);
        }
    }

    this->draw_view(10, this->save_area1); // 10 is terrain mode

    this->render_terrain_mode = 1;
    this->draw_finish();

    frame_count++;
}

void RGE_View::update()
{
    if (this->player == nullptr) return;

    if (this->player->view_x != this->last_view_x || this->player->view_y != this->last_view_y) {
        this->center_map_col = (short)this->player->view_x;
        this->center_map_row = (short)this->player->view_y;
        this->last_view_x = this->player->view_x;
        this->last_view_y = this->player->view_y;

        this->center_scr_col = (this->render_rect_wid / 2) - this->tile_half_wid;
        this->center_scr_row = (this->render_rect_hgt / 2) - this->tile_half_hgt;

        RGE_Tile* center_tile = this->map->get_tile(this->center_map_col, this->center_map_row);
        if (center_tile) {
            this->map_scr_x_offset = center_tile->screen_xpos - this->center_scr_col;
            this->map_scr_y_offset = (this->elev_hgt * center_tile->height + center_tile->screen_ypos) - this->center_scr_row;
        }

        this->center_scr_col_offset = (short)((this->center_map_col + this->center_map_row) * this->tile_half_wid - this->player->view_x);
        this->center_scr_row_offset = (short)((this->center_map_row - this->center_map_col) * this->tile_half_hgt - this->player->view_y);

        short r_cols = (this->max_col_num / 2) + 2;
        this->start_map_col = this->center_map_col - r_cols;
        this->start_map_row = this->center_map_row - r_cols;
        this->start_scr_col = this->center_scr_col + (r_cols * this->tile_half_wid * -2);
        
        short r_rows = (this->max_row_num / 2) + 1;
        this->start_map_col += r_rows;
        this->start_map_row -= r_rows;
        this->start_scr_row = this->center_scr_row + (r_rows * this->tile_half_hgt * -2);
    }
}

void RGE_View::draw_view(uchar mode, TDrawArea* area)
{
    if (area == nullptr) area = this->cur_render_area;
    if (area == nullptr) return;

    if (area->Lock("draw_view", 1)) {
        if (mode == 10) { // Terrain
            tagRECT rect;
            rect.left = 0;
            rect.top = 0;
            rect.right = area->Width - 1;
            rect.bottom = area->Height - 1;
            this->view_function_terrain(mode, rect);
        }
        area->Unlock("draw_view");
    }
}

long RGE_View::view_function_terrain(uchar mode, tagRECT rect)
{
    (void)mode;
    if (this->map == nullptr || this->cur_render_area == nullptr || this->map->map_row_offset == nullptr) {
        return 0;
    }

    int col_num = (int)this->start_map_col;
    int row_num = (int)this->start_map_row;
    const int cols_to_scan = (int)this->max_col_num + 5;
    const int rows_to_scan = (int)this->max_row_num * 2 + 0x0C;
    const int map_w = this->map->map_width;
    const int map_h = this->map->map_height;

    for (int scan_row = 0; scan_row < rows_to_scan; ++scan_row) {
        int map_col = col_num;
        int map_row = row_num;

        for (int scan_col = 0; scan_col < cols_to_scan; ++scan_col) {
            if (map_col >= 0 && map_row >= 0 && map_col < map_w && map_row < map_h) {
                RGE_Tile* tile = &this->map->map_row_offset[map_row][map_col];
                int sx = (int)tile->screen_xpos - this->map_scr_x_offset;
                int sy = (int)tile->screen_ypos - this->map_scr_y_offset;

                unsigned int tt = (unsigned int)tile->tile_type;
                if (tt < 19u) {
                    int ex = sx + (int)this->map->tilesizes[tt].width;
                    int ey = sy + (int)this->map->tilesizes[tt].height;
                    if (!(ex < rect.left || sx > rect.right || ey < rect.top || sy > rect.bottom)) {
                        uchar vis = 0x0F;
                        if (this->player != nullptr && this->player->visible != nullptr) {
                            vis = this->player->visible->get_visible((short)map_col, (short)map_row);
                        }
                        if (vis == 0 && this->map->map_visible_flag != 0) {
                            vis = 0x0F;
                        }

                        if (vis != 0) {
                            uchar terrain_to_draw = (uchar)(tile->terrain_type & 0x1F);
                            if ((int)terrain_to_draw < this->map->num_terrain) {
                                short override_terrain = this->map->terrain_types[terrain_to_draw].terrain_to_draw;
                                if (override_terrain != -1 && override_terrain >= 0 && override_terrain < this->map->num_terrain) {
                                    terrain_to_draw = (uchar)override_terrain;
                                }

                                tile->draw_attribute = (uchar)(tile->draw_attribute & 0xBF);
                                this->draw_tile(
                                    tile,
                                    terrain_to_draw,
                                    (short)sx,
                                    (short)sy,
                                    (short)map_col,
                                    (short)map_row,
                                    vis,
                                    0,
                                    0);
                                tiles_drawn = tiles_drawn + 1;
                            }
                        }
                    }
                }
            }

            map_col = map_col + 1;
            map_row = map_row + 1;
        }

        if ((scan_row & 1) != 0) {
            row_num = row_num + 1;
        } else {
            col_num = col_num - 1;
        }
    }

    // Draw world objects (static resources/decorations/etc) as a compatibility
    // path while tile object-list linkage is still incomplete.
    if (this->world != nullptr && this->world->objectsValue != nullptr && this->world->maxNumberObjectsValue > 0) {
        int max_objects = this->world->maxNumberObjectsValue;
        for (int i = 0; i < max_objects; ++i) {
            RGE_Static_Object* obj = this->world->objectsValue[i];
            if (obj == nullptr || obj->master_obj == nullptr) {
                continue;
            }

            int ox = (int)obj->world_x;
            int oy = (int)obj->world_y;
            if (ox < 0 || oy < 0 || ox >= this->map->map_width || oy >= this->map->map_height) {
                continue;
            }

            uchar vis = 0x0F;
            if (this->player != nullptr && this->player->visible != nullptr) {
                vis = this->player->visible->get_visible((short)ox, (short)oy);
            }
            if (vis == 0 && this->map->map_visible_flag != 0) {
                vis = 0x0F;
            }
            if (vis == 0) {
                continue;
            }

            RGE_Tile* tile = this->map->get_tile(ox, oy);
            if (tile == nullptr) {
                continue;
            }

            int sx = (int)tile->screen_xpos - this->map_scr_x_offset + (int)obj->screen_x_offset;
            int sy = (int)tile->screen_ypos + (int)tile->height * this->tile_half_hgt - this->map_scr_y_offset + (int)obj->screen_y_offset;

            if (sx < rect.left - this->tile_wid || sx > rect.right + this->tile_wid ||
                sy < rect.top - this->tile_hgt * 2 || sy > rect.bottom + this->tile_hgt * 4) {
                continue;
            }

            RGE_Sprite* spr = obj->sprite;
            if (spr == nullptr) {
                spr = obj->master_obj->sprite;
            }
            rge_view_try_load_sprite_shape(spr);

            int drawn = 0;
            int facet = (int)obj->facet;
            if (facet < 0) {
                facet = 0;
            }
            if (spr != nullptr && spr->facet_num > 0 && facet >= spr->facet_num) {
                facet = 0;
            }

            // Source of truth: sprite.cpp.decomp @ 0x004C04F0 (RGE_Sprite::draw).
            // Route through sprite draw so draw-list remapping, color xform, and xlate-table behavior match runtime.
            if (spr != nullptr) {
                spr->draw((long)facet, 0, sx, sy, sx, sy, nullptr, this->cur_render_area, 0);
                drawn = 1;
            }

            if (drawn == 0) {
                this->cur_render_area->DrawLine(sx - 3, sy - 3, sx + 3, sy + 3, 250);
                this->cur_render_area->DrawLine(sx - 3, sy + 3, sx + 3, sy - 3, 250);
            }
        }
    }

    return 0;
}

int RGE_View::draw_tile(RGE_Tile* tile, uchar vis, short x, short y, short col, short row, uchar fog, int param_9, int param_10)
{
    if (tile == nullptr || this->map == nullptr) {
        return 0;
    }
    if ((ushort)vis >= (ushort)this->map->num_terrain || this->map->terrain_types[vis].loaded == 0) {
        return 0;
    }

    uchar draw_attribute = tile->draw_attribute;
    int draw_terrain = 1;
    int terrain_drawn = 0;
    int draw_border = 0;
    int left_index = -1;
    int right_index = -1;
    int bottom_index = -1;
    int center_index = -1;

    uchar border_type = tile->border_type & 0x0F;
    uchar border_shape = tile->border_shape & 0x0F;

    if (border_type != 0 &&
        border_type < 16 &&
        this->map->border_types[border_type].loaded != 0 &&
        this->map->border_types[border_type].shape != nullptr) {
        if (this->map->border_types[border_type].border_style == 0) {
            short s = this->get_border_picture(border_type, tile->tile_type, border_shape, col, row);
            if (s != -1) {
                draw_border = 1;
                center_index = (int)s;
                draw_terrain = this->map->border_types[border_type].draw_tile;
            }
        } else {
            if (rge_view_get_border_edge_pictures(
                    this,
                    border_type,
                    tile->tile_type,
                    border_shape,
                    col,
                    row,
                    &left_index,
                    &bottom_index,
                    &right_index,
                    &center_index)) {
                draw_border = 1;
                draw_terrain = 1;
            }
        }
    }

    if (View_Grid_Mode > 0 && ((draw_attribute & 0xDF) == 0)) {
        if (((col / View_Grid_Mode) + (row / View_Grid_Mode)) % 2 == 1) {
            draw_attribute = (uchar)(draw_attribute | 0x20);
        }
    }

    if (view_debug_ObstructionMap != 0) {
        draw_border = 0;
    }

    if (draw_terrain != 0) {
        RGE_Tile_Set* block = &this->map->terrain_types[vis];
        short pic = this->get_tile_picture(vis, tile->tile_type, col, row);
        if (block->shape != nullptr && pic != (short)0xFFFF) {
            this->draw_terrain_shape(x, y, block->shape, pic, fog, draw_attribute, param_9, param_10);
            terrain_drawn = 1;
        }

        if (!draw_border) {
            if (col > 0 && row >= 0 && row < this->map->map_height) {
                this->map->map_row_offset[row][col - 1].draw_attribute |= 0x40;
            }
            if (row >= 0 && row < this->map->map_height - 1 && col >= 0 && col < this->map->map_width) {
                this->map->map_row_offset[row + 1][col].draw_attribute |= 0x40;
            }
        }
    }

    if (!draw_border) {
        return terrain_drawn;
    }

    TShape* border_shape_ptr = this->map->border_types[border_type].shape;
    if (border_shape_ptr == nullptr) {
        return terrain_drawn;
    }

    if (this->map->border_types[border_type].border_style == 0) {
        short s = this->get_border_picture(border_type, tile->tile_type, tile->border_shape, col, row);
        if (s != -1) {
            center_index = (int)s;
        } else {
            center_index = -1;
        }
    } else {
        if (!rge_view_get_border_edge_pictures(
                this,
                border_type,
                tile->tile_type,
                tile->border_shape,
                col,
                row,
                &left_index,
                &bottom_index,
                &right_index,
                &center_index)) {
            center_index = -1;
        }

        if (left_index != -1) {
            this->draw_terrain_shape(x, y, border_shape_ptr, left_index, fog, draw_attribute, param_9, param_10);
        }
        if (right_index != -1) {
            this->draw_terrain_shape(x, y, border_shape_ptr, right_index, fog, draw_attribute, param_9, param_10);
        }
        if (bottom_index != -1) {
            this->draw_terrain_shape(x, y, border_shape_ptr, bottom_index, fog, draw_attribute, param_9, param_10);
        }
    }

    if (center_index != -1) {
        this->draw_terrain_shape(x, y, border_shape_ptr, center_index, fog, draw_attribute, param_9, param_10);
    }

    if (col > 0 && row >= 0 && row < this->map->map_height) {
        this->map->map_row_offset[row][col - 1].draw_attribute |= 0x40;
    }
    if (row >= 0 && row < this->map->map_height - 1 && col >= 0 && col < this->map->map_width) {
        this->map->map_row_offset[row + 1][col].draw_attribute |= 0x40;
    }

    return terrain_drawn;
}

void RGE_View::draw_terrain_shape(int x, int y, TShape* shape, int frame, uchar vis, uchar fog, int param_7, int param_8)
{
    // Source of truth: view.cpp.decomp @ 0x00538B80
    if (this->cur_render_area == nullptr || shape == nullptr) {
        return;
    }

    int hotspot_x = 0;
    int hotspot_y = 0;
    if (shape->shape_info != nullptr && frame >= 0 && frame < shape->shape_count()) {
        hotspot_x = shape->shape_info[frame].Hotspot_X;
        hotspot_y = shape->shape_info[frame].Hotspot_Y;
    }

    if ((fog & 0x10) == 0x10) {
        fog_next_shape = 1;
        _ASMSet_Shadowing(0x00FF00FF, 0x28002800, (int)0xFF00FF00u, 0x00280028);
        shape->shape_draw(this->cur_render_area, x - hotspot_x, y - hotspot_y, frame, 0, 0, nullptr);
        _ASMSet_Shadowing(0x00FF00FF, 0, (int)0xFF00FF00u, 0);
        fog_next_shape = 0;
        return;
    }

    if ((fog & 0x20) == 0x20) {
        _ASMSet_Shadowing(0x00FF00FF, 0x56005600, (int)0xFF00FF00u, 0x00560056);
    }

    if ((fog & 0x80) == 0x80) {
        int shade = ((int)(fog & 0x0F) * 0x10001000) + 0x04000400;
        _ASMSet_Shadowing(0x00FF00FF, shade, (int)0xFF00FF00u, shade);
    }

    if (this->map != nullptr && this->map->fog_flag != 0 && vis == 0x80) {
        fog_next_shape = 1;
    }

    if (param_8 != 0) {
        this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
        fog_next_shape = 1;
        shape->shape_draw(this->cur_render_area, x, y, frame, 0, 0, nullptr);
        fog_next_shape = 0;
    }

    if ((fog & 0xA0) != 0) {
        fog_next_shape = 1;
    }

    if (param_7 != 0) {
        this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
        shape->shape_draw(this->cur_render_area, x, y, frame, 0, 0, nullptr);
    }

    this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
    _ASMSet_Shadowing(0x00FF00FF, 0, (int)0xFF00FF00u, 0);
    fog_next_shape = 0;
}

short RGE_View::get_tile_picture(uchar terrain_type, uchar vis, short col, short row)
{
    if (this->map == nullptr) {
        return (short)0xFFFF;
    }
    if (terrain_type >= this->map->num_terrain) {
        return (short)0xFFFF;
    }

    RGE_Tile_Set* block = &this->map->terrain_types[terrain_type];
    if (block->shape == nullptr) {
        return (short)0xFFFF;
    }

    unsigned int tt = (unsigned int)vis;
    if (tt >= 19u) {
        tt = 0;
    }

    short count = block->tiles[tt].count;
    if (count == 0) {
        return (short)0xFFFF;
    }

    short sub_tile = 0;
    if (count > 1) {
        uchar rows = (uchar)block->rows;
        uchar cols = (uchar)block->cols;
        if (rows > 1 || cols > 1) {
            uchar row_mod = (rows == 0) ? 0 : (uchar)((int)row % (int)rows);
            uchar col_mod = (cols == 0) ? 0 : (uchar)((int)col % (int)cols);
            sub_tile = (short)((ushort)row_mod * (ushort)cols + (ushort)col_mod);
        }
    }

    if (sub_tile > count - 1) {
        sub_tile = 0;
    }

    return (short)(block->tiles[tt].animations * sub_tile + block->tiles[tt].shape_index);
}

short RGE_View::get_border_picture(uchar terrain_type, uchar border_type, uchar param_3, short col, short row)
{
    if (this->map == nullptr) {
        return (short)0xFFFF;
    }
    if (terrain_type >= 16) {
        return (short)0xFFFF;
    }

    RGE_Border_Set* block = &this->map->border_types[terrain_type];
    if (block->shape == nullptr) {
        return (short)0xFFFF;
    }

    // Source of truth: view.cpp.decomp @ 0x00539B90.
    // borders[tile_type - 1][border_shape + 0x0B] => flattened:
    // (tile_type * 12) + border_shape - 1
    const int kMaxBorderPicts = 19 * 12;
    int flat_index = (int)border_type * 12 + (int)param_3 - 1;
    if (flat_index < 0 || flat_index >= kMaxBorderPicts) {
        return (short)0xFFFF;
    }

    RGE_TOB_Picts* pict = &block->borders[0][0] + flat_index;
    short count = pict->count;
    if (count == 0) {
        return (short)0xFFFF;
    }

    short sub_index = 0;
    if (count > 1) {
        short style = block->border_style;
        if (((style == 0) && (param_3 == 0x0B || param_3 == 0x0C)) ||
            ((style == 1) && (param_3 == 0x03 || param_3 == 0x02))) {
            sub_index = (short)((int)row % (int)count);
        } else if (((style == 0) && (param_3 == 0x09 || param_3 == 0x0A)) ||
                   ((style == 1) && (param_3 == 0x01 || param_3 == 0x04))) {
            sub_index = (short)((int)col % (int)count);
        } else {
            sub_index = 0;
        }
    }

    if (sub_index > count - 1) {
        sub_index = 0;
    }

    return (short)(pict->animations * sub_index + pict->shape_index);
}
