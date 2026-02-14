#include "RGE_View.h"
#include "RGE_Player.h"
#include "RGE_Map.h"
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
#include <cstdio>
#include <cstdlib>

// Global variables (from decomp)
int view_debug_redraw_all = 0;
int view_debug_ObstructionMap = 0;
int view_debug_palette = 0;
int tiles_drawn = 0;
int frame_count = 0;
int View_Grid_Mode = 0;
extern TMousePointer* MouseSystem;
extern RGE_Base_Game* rge_base_game;

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
    short cur_col = this->start_map_col;
    short cur_row = this->start_map_row;
    short cur_scr_x = this->start_scr_col;
    short cur_scr_y = this->start_scr_row;

    for (int r = 0; r < this->max_row_num; ++r) {
        short row_map_col = cur_col;
        short row_map_row = cur_row;
        short row_scr_x = cur_scr_x;
        short row_scr_y = cur_scr_y;

        for (int c = 0; c < this->max_col_num; ++c) {
            if (row_map_col >= 0 && row_map_col < this->map->map_width &&
                row_map_row >= 0 && row_map_row < this->map->map_height) {
                
                RGE_Tile* tile = this->map->get_tile(row_map_col, row_map_row);
                if (tile) {
                    uchar vis = 0xF;
                    if (this->player->visible) {
                        vis = this->player->visible->get_visible(row_map_col, row_map_row);
                    }

                    if (vis != 0) {
                        this->draw_tile(tile, vis, row_scr_x, row_scr_y, row_map_col, row_map_row, 0, 0, 0);
                    }
                }
            }
            row_map_col++;
            row_map_row--;
            row_scr_x += this->tile_wid;
        }

        cur_col++;
        cur_row++;
        cur_scr_y += this->tile_hgt;
    }

    return 0;
}

int RGE_View::draw_tile(RGE_Tile* tile, uchar vis, short x, short y, short col, short row, uchar fog, int param_9, int param_10)
{
    uchar draw_border = tile->border_type;
    int draw_terrain = 0;

    if (View_Grid_Mode > 0 && (draw_border == 0)) {
        if (((col / View_Grid_Mode) + (row / View_Grid_Mode)) % 2 == 1) {
            draw_border |= 0x20;
        }
    }

    if (view_debug_ObstructionMap != 0) {
        draw_terrain = 0;
    } else {
        draw_terrain = 1;
    }

    short pic = this->get_tile_picture(tile->terrain_type, vis, col, row);
    if (pic != (short)0xFFFF) {
        RGE_Tile_Set* block = &this->map->terrain_types[tile->terrain_type];
        if (block->shape) {
            this->draw_terrain_shape(x, y, block->shape, pic, vis, fog, param_9, param_10);
        }
    }

    tiles_drawn++;
    return 1;
}

void RGE_View::draw_terrain_shape(int x, int y, TShape* shape, int frame, uchar vis, uchar fog, int param_7, int param_8)
{
    if (this->cur_render_area == nullptr) return;
    shape->shape_draw(this->cur_render_area, x, y, frame, 0, 0, nullptr);
}

short RGE_View::get_tile_picture(uchar terrain_type, uchar vis, short col, short row)
{
    if (terrain_type >= this->map->num_terrain) return (short)0xFFFF;

    RGE_Tile_Set* block = &this->map->terrain_types[terrain_type];
    if (block->shape == nullptr) return (short)0xFFFF;

    int index = (col % 4) * 4 + (row % 4); 
    return (short)index;
}

short RGE_View::get_border_picture(uchar terrain_type, uchar border_type, uchar param_3, short col, short row)
{
    return (short)0xFFFF;
}
