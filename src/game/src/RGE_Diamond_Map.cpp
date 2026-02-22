#include "RGE_Diamond_Map.h"

#include "RGE_Base_Game.h"
#include "RGE_Color_Table.h"
#include "RGE_Game_World.h"
#include "RGE_Map.h"
#include "RGE_Map_Image_Line.h"
#include "RGE_Map_Tile_Row.h"
#include "RGE_Master_Static_Object.h"
#include "RGE_Object_List.h"
#include "RGE_Object_Node.h"
#include "RGE_Player.h"
#include "RGE_Tile_List_Node.h"
#include "RGE_Tile.h"
#include "RGE_Static_Object.h"
#include "RGE_View.h"
#include "TPicture.h"
#include "TDrawArea.h"
#include "globals.h"

#include <cstddef>
#include <cstdlib>
#include <cstring>

extern RGE_Base_Game* rge_base_game;

static short diam_map_ceil_pos_to_short(float v) {
    // Mirrors the decomp's common pattern:
    //   i = __ftol(v);
    //   if ((float)i != v) ++i;
    short i = (short)(long)v;
    if ((float)i != v) {
        i = (short)(i + 1);
    }
    return i;
}

static short diam_map_trunc_to_short(float v) {
    return (short)(long)v;
}

static long diam_map_trunc_to_long(float v) {
    return (long)v;
}

RGE_Diamond_Map::RGE_Diamond_Map()
    : TPanel((char*)"RGE_Diamond_Map") {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x00436830
    this->world = nullptr;
    this->player = nullptr;
    this->map = nullptr;
    this->all_visible = 0;
    this->render_all = 1;
    this->mouse_last_x = 0;
    this->mouse_last_y = 0;
    this->repos_mouse = 0;
    this->view_rect.left = 0;
    this->view_rect.top = 0;
    this->view_rect.right = 0;
    this->view_rect.bottom = 0;
    this->last_player = nullptr;
    this->map_image_lines = nullptr;
    this->map_tile_rows = nullptr;
    this->map_wid = 0;
    this->map_hgt = 0;
    this->map_image_start_y = 0;
    this->map_image_wid = 0;
    this->map_image_hgt = 0;
    this->map_tile_row_cnt = 0;
    this->map_row_step = 0.0f;
    this->map_col_ratio = 0.0f;
    this->map_row_ratio = 0.0f;
    this->map_tile_draw_hgt = 0;
    this->map_tile_draw_wid = 0;
    this->view_col = -1;
    this->view_row = -1;
    this->main_view = nullptr;
    this->scrolling = 0;
    this->fog_color = 0xFF;
    this->draw_objects_mode = 0;
    this->cur_player_bit = 0;
    this->own_save_area = 0;
    this->save_area = nullptr;
}

RGE_Diamond_Map::~RGE_Diamond_Map() {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x00436930
    this->delete_surfaces();

    if (this->map_tile_rows != nullptr) {
        std::free(this->map_tile_rows);
        this->map_tile_rows = nullptr;
    }
    if (this->map_image_lines != nullptr) {
        std::free(this->map_image_lines);
        this->map_image_lines = nullptr;
    }
}

// -----------------------------------------------------------------------------
// Virtual forwarding layer (header redeclares TPanel virtuals)
// -----------------------------------------------------------------------------

long RGE_Diamond_Map::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
void RGE_Diamond_Map::set_rect(tagRECT param_1) { TPanel::set_rect(param_1); }
void RGE_Diamond_Map::set_rect(long param_1, long param_2, long param_3, long param_4) { TPanel::set_rect(param_1, param_2, param_3, param_4); }
void RGE_Diamond_Map::set_color(uchar param_1) { TPanel::set_color(param_1); }
void RGE_Diamond_Map::set_active(int param_1) { TPanel::set_active(param_1); }
void RGE_Diamond_Map::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void RGE_Diamond_Map::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void RGE_Diamond_Map::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void RGE_Diamond_Map::draw_setup(int param_1) { TPanel::draw_setup(param_1); }
void RGE_Diamond_Map::draw_finish() { TPanel::draw_finish(); }
void RGE_Diamond_Map::draw_rect(tagRECT* param_1) { TPanel::draw_rect(param_1); }
void RGE_Diamond_Map::draw_offset(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset(param_1, param_2, param_3); }
void RGE_Diamond_Map::draw_rect2(tagRECT* param_1) { TPanel::draw_rect2(param_1); }
void RGE_Diamond_Map::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset2(param_1, param_2, param_3); }
void RGE_Diamond_Map::paint() { TPanel::paint(); }
long RGE_Diamond_Map::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map::handle_idle() { return TPanel::handle_idle(); }
long RGE_Diamond_Map::handle_paint() { return TPanel::handle_paint(); }
long RGE_Diamond_Map::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long RGE_Diamond_Map::handle_char(long param_1, short param_2) { return TPanel::handle_char(param_1, param_2); }
long RGE_Diamond_Map::handle_command(uint param_1, long param_2) { return TPanel::handle_command(param_1, param_2); }
long RGE_Diamond_Map::handle_user_command(uint param_1, long param_2) { return TPanel::handle_user_command(param_1, param_2); }
long RGE_Diamond_Map::handle_timer_command(uint param_1, long param_2) { return TPanel::handle_timer_command(param_1, param_2); }
long RGE_Diamond_Map::handle_scroll(long param_1, long param_2) { return TPanel::handle_scroll(param_1, param_2); }
long RGE_Diamond_Map::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long RGE_Diamond_Map::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long RGE_Diamond_Map::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long RGE_Diamond_Map::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long RGE_Diamond_Map::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long RGE_Diamond_Map::char_action(long param_1, short param_2) { return TPanel::char_action(param_1, param_2); }
long RGE_Diamond_Map::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return TPanel::action(param_1, param_2, param_3, param_4); }
void RGE_Diamond_Map::get_true_render_rect(tagRECT* param_1) { TPanel::get_true_render_rect(param_1); }
void RGE_Diamond_Map::set_focus(int param_1) { TPanel::set_focus(param_1); }
void RGE_Diamond_Map::set_tab_order(TPanel* param_1, TPanel* param_2) { TPanel::set_tab_order(param_1, param_2); }
void RGE_Diamond_Map::set_tab_order(TPanel** param_1, short param_2) { TPanel::set_tab_order(param_1, param_2); }
uchar RGE_Diamond_Map::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TPanel::get_help_info(param_1, param_2, param_3, param_4); }
void RGE_Diamond_Map::stop_sound_system() { TPanel::stop_sound_system(); }
int RGE_Diamond_Map::restart_sound_system() { return TPanel::restart_sound_system(); }
void RGE_Diamond_Map::take_snapshot() { TPanel::take_snapshot(); }
void RGE_Diamond_Map::handle_reactivate() { TPanel::handle_reactivate(); }

// -----------------------------------------------------------------------------
// Non-virtual helpers
// -----------------------------------------------------------------------------

long RGE_Diamond_Map::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7, int param_8, TDrawArea* param_9) {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x004369C0
    this->save_area = param_9;
    this->own_save_area = 0;
    (void)param_8;
    return TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

int RGE_Diamond_Map::set_bitmap(char* param_1, long param_2) {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x00436A10
    if (this->map_tile_rows != nullptr) {
        std::free(this->map_tile_rows);
        this->map_tile_rows = nullptr;
    }
    if (this->map_image_lines != nullptr) {
        std::free(this->map_image_lines);
        this->map_image_lines = nullptr;
    }
    this->map_image_start_y = 0;
    this->map_image_wid = 0;
    this->map_image_hgt = 0;

    TPicture* pic = new TPicture(param_1, param_2, 0, nullptr, 0);
    if (pic == nullptr) {
        return 0;
    }
    if (pic->Dib == nullptr) {
        delete pic;
        return 0;
    }

    const short pic_hgt = (short)pic->Height;
    const short pic_wid = (short)pic->Width;
    if (pic_hgt <= 0 || pic_wid <= 0 || pic->Bits == nullptr) {
        delete pic;
        return 0;
    }

    this->map_image_lines = (RGE_Map_Image_Line*)std::calloc((size_t)pic_hgt, sizeof(RGE_Map_Image_Line));
    if (this->map_image_lines == nullptr) {
        delete pic;
        return 0;
    }

    long pitch = pic->AlignedWidth();
    uchar* row = pic->Bits;
    if (pic->Orien != 1) {
        row = pic->Bits + ((pic->Height - 1) * pitch);
        pitch = -pitch;
    }

    this->map_image_start_y = -1;
    for (short y = 0; y < pic_hgt; ++y) {
        short start_x = -1;
        short len = 0;

        for (short x = 0; x < pic_wid; ++x) {
            if (row[x] == 0xFF) {
                start_x = x;
                break;
            }
        }
        if (start_x == -1) {
            row = row + pitch;
            continue;
        }

        short x = start_x;
        while (x < pic_wid && row[x] == 0xFF) {
            ++len;
            ++x;
        }

        const int out = (int)this->map_image_hgt;
        this->map_image_lines[out].start_x = start_x;
        this->map_image_lines[out].line_len = len;
        ++this->map_image_hgt;

        if (this->map_image_wid < len) {
            this->map_image_wid = len;
        }

        if (this->map_image_start_y == -1) {
            this->map_image_start_y = y;
        }

        row = row + pitch;
    }

    delete pic;

    if (this->world != nullptr) {
        this->set_world(this->world);
    }
    return 1;
}

void RGE_Diamond_Map::set_world(RGE_Game_World* param_1) {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x00436C30
    this->world = param_1;
    if (param_1 == nullptr || this->map_image_lines == nullptr) {
        this->map = nullptr;
        return;
    }

    this->map = param_1->map;
    if (this->map == nullptr) {
        return;
    }

    this->map_wid = (short)this->map->map_width;
    this->map_hgt = (short)this->map->map_height;
    this->map_tile_row_cnt = (short)((this->map_wid + this->map_hgt) - 1);

    if (this->map_tile_rows != nullptr) {
        std::free(this->map_tile_rows);
        this->map_tile_rows = nullptr;
    }

    this->map_tile_rows = (RGE_Map_Tile_Row*)std::calloc((size_t)this->map_tile_row_cnt, sizeof(RGE_Map_Tile_Row));
    if (this->map_tile_rows == nullptr) {
        return;
    }

    const short img_hgt = this->map_image_hgt;
    if (img_hgt == 0) {
        return;
    }

    this->map_row_step = (float)(int)this->map_tile_row_cnt / (float)(int)img_hgt;
    float tile_row_f = 0.0f;
    if (this->map_tile_row_cnt > img_hgt) {
        tile_row_f = this->map_row_step * 0.5f;
    }

    int tot_draw_wid = 0;
    for (short image_line = 0; image_line < img_hgt; ++image_line) {
        short tile_row = (short)diam_map_trunc_to_long(tile_row_f);
        if (tile_row >= this->map_tile_row_cnt) {
            tile_row = (short)(this->map_tile_row_cnt - 1);
        }

        const short line_len = this->map_image_lines[image_line].line_len;
        this->map_image_lines[image_line].tile_row = tile_row;

        // Compute row length (# tiles on this diagonal).
        short row_len = 0;
        if (tile_row < this->map_wid) {
            if (tile_row < this->map_hgt) {
                row_len = (short)(tile_row + 1);
            } else {
                row_len = this->map_hgt;
            }
        } else {
            row_len = (short)((this->map_hgt - tile_row) + this->map_wid - 1);
        }

        if (line_len <= 0 || row_len <= 0) {
            tile_row_f = tile_row_f + this->map_row_step;
            continue;
        }

        float col_step = (float)(int)row_len / (float)(int)line_len;
        float pixels_per_tile = (float)(int)line_len / (float)(int)row_len;
        short draw_wid = diam_map_ceil_pos_to_short(pixels_per_tile);

        RGE_Map_Tile_Row* tr = &this->map_tile_rows[tile_row];
        tr->image_line = image_line;
        tr->draw = 1;
        tr->row_len = row_len;
        tr->col_step = col_step;
        tr->draw_wid = draw_wid;
        tr->draw_step = pixels_per_tile;

        // `ratio` is used by draw_tile/draw_object/draw_view_rect for row->pixel mapping.
        tr->ratio = pixels_per_tile;
        tr->col_extra = (tr->ratio < 1.0f) ? (col_step * 0.5f) : 0.0f;

        // Map base col/row for the diagonal.
        if (tile_row < this->map_wid) {
            tr->map_row = 0;
            tr->map_col = (short)((this->map_wid - tile_row) - 1);
        } else {
            tr->map_row = (short)((tile_row - this->map_wid) + 1);
            tr->map_col = 0;
        }

        tr->num_tiles = row_len;
        tot_draw_wid += (int)draw_wid;

        tile_row_f = tile_row_f + this->map_row_step;
    }

    // Derived tile draw metrics.
    this->map_tile_draw_hgt = diam_map_ceil_pos_to_short(1.0f / this->map_row_step);
    this->map_tile_draw_wid = (short)(tot_draw_wid / (int)img_hgt);
    if (this->map_tile_draw_wid == 0) {
        this->map_tile_draw_wid = 1;
    }

    // Pixel-per-tile scaling used by view-rect.
    this->map_col_ratio = (float)(int)this->map_tile_row_cnt / (float)(int)img_hgt;
    this->map_row_ratio = (float)(int)img_hgt / (float)(int)this->map_tile_row_cnt;

    // Fill non-draw rows by copying the last draw row.
    short last_draw = 0;
    for (short i = 0; i < this->map_tile_row_cnt; ++i) {
        if (this->map_tile_rows[i].draw != 0) {
            last_draw = i;
            continue;
        }
        this->map_tile_rows[i] = this->map_tile_rows[last_draw];
    }

    this->view_col = -1;
    this->view_row = -1;
    this->set_redraw(TPanel::RedrawMode::RedrawFull);
}

void RGE_Diamond_Map::set_player(RGE_Player* param_1) {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x00437070
    this->player = param_1;
    this->set_redraw(TPanel::RedrawMode::RedrawFull);
}

void RGE_Diamond_Map::set_main_view(RGE_View* param_1) {
    this->main_view = param_1;
}

void RGE_Diamond_Map::set_redraw(RedrawMode param_1) {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x004370A0
    TPanel::set_redraw(param_1);
    if (param_1 == TPanel::RedrawMode::RedrawFull) {
        this->render_all = 1;
    }
}

void RGE_Diamond_Map::delete_surfaces() {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x004370C0
    if (this->save_area != nullptr && this->own_save_area != 0) {
        delete this->save_area;
    }
    this->save_area = nullptr;
    this->own_save_area = 0;
}

int RGE_Diamond_Map::create_surfaces() {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x00437120
    if (this->save_area == nullptr) {
        this->save_area = new TDrawArea((char*)"Diamond map (restored)");
        if (this->save_area == nullptr) {
            return 0;
        }

        if (this->render_area == nullptr || this->render_area->DrawSystem == nullptr) {
            delete this->save_area;
            this->save_area = nullptr;
            return 0;
        }

        if (this->save_area->Init(this->render_area->DrawSystem, 0, (int)this->pnl_wid, (int)this->pnl_hgt, 0, 0, 0) == 0) {
            delete this->save_area;
            this->save_area = nullptr;
            return 0;
        }

        this->own_save_area = 1;
        return 1;
    }

    if (this->own_save_area != 0) {
        this->save_area->SetSize(this->pnl_wid, this->pnl_hgt, 0);
    }
    return 1;
}

// -----------------------------------------------------------------------------
// Draw pipeline
// -----------------------------------------------------------------------------

void RGE_Diamond_Map::draw() {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x004372C0
    if (this->render_area == nullptr || this->save_area == nullptr || this->visible == 0 || this->active == 0) {
        this->need_redraw = TPanel::NoRedraw;
        return;
    }

    this->draw_setup(0);

    if (this->map != nullptr && this->player != nullptr && this->map_image_lines != nullptr && this->map_tile_rows != nullptr) {
        this->cur_player_bit = 1UL << (((unsigned long)this->world->curr_player) & 0x1FU);

        if (this->render_all == 0) {
            this->draw_explored_tiles();
        } else {
            if (this->parent_panel != nullptr) {
                this->parent_panel->draw_rect(&this->clip_rect);
                this->render_area->Copy(this->save_area, 0, 0, &this->render_rect, 0);
                this->clear_image();
            } else {
                this->save_area->Clear(nullptr, (int)this->color);
            }

            this->draw_all_tiles();
            this->render_all = 0;
        }

        this->copy_image();

        if (rge_base_game == nullptr || rge_base_game->game_mode != 0x15) {
            this->draw_selected_area();
        }
        this->draw_objects();

        if (this->render_area->Lock((char*)"diam_map::draw_view_rect", 1) != nullptr) {
            this->draw_view_rect();
            this->render_area->Unlock((char*)"diam_map::draw_view_rect");
        }

        this->draw_finish();
        this->player->diam_tile_list.del_list();
        return;
    }

    if (this->map_image_lines != nullptr) {
        this->clear_image();
        this->copy_image();
        this->draw_finish();
        return;
    }

    if (this->parent_panel != nullptr) {
        this->parent_panel->draw_rect(&this->clip_rect);
        this->draw_finish();
        return;
    }

    this->render_area->Clear(&this->clip_rect, (int)this->color);
    this->draw_finish();
}

void RGE_Diamond_Map::clear_image() {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x004374C0
    if (this->save_area == nullptr) {
        return;
    }

    uchar* bits = this->save_area->Lock((char*)"diam_map::clear_image", 1);
    if (bits == nullptr) {
        return;
    }

    short pitch = (short)this->save_area->Pitch;
    uchar* line_bits = this->save_area->Bits;
    if (this->save_area->Orien == 1) {
        line_bits = this->save_area->Bits + (int)this->map_image_start_y * this->save_area->Pitch;
    } else {
        line_bits = this->save_area->Bits + ((this->save_area->Height - (int)this->map_image_start_y) - 1) * this->save_area->Pitch;
        pitch = (short)-pitch;
    }

    int global_y = (int)this->pnl_y + (int)this->map_image_start_y;
    const int end_global_y = global_y + (int)this->map_image_hgt;
    if (global_y < end_global_y) {
        int count = end_global_y - global_y;
        RGE_Map_Image_Line* ml = this->map_image_lines;
        while (count-- != 0) {
            if (this->clip_rect.top <= global_y && global_y <= this->clip_rect.bottom) {
                short start_x = ml->start_x;
                short global_x0 = (short)((short)this->pnl_x + start_x);
                short global_x1 = (short)(global_x0 + ml->line_len - 1);
                short clipped_x0 = global_x0;
                if ((int)global_x0 < this->clip_rect.left) {
                    clipped_x0 = (short)this->clip_rect.left;
                    start_x = (short)(start_x + (clipped_x0 - global_x0));
                }
                if (this->clip_rect.right < (int)global_x1) {
                    global_x1 = (short)this->clip_rect.right;
                }

                if (this->clip_rect.left <= (int)clipped_x0 && (int)global_x1 <= this->clip_rect.right) {
                    std::memset(line_bits + start_x, this->color, ((int)global_x1 - (int)clipped_x0) + 1);
                }
            }

            ml = (RGE_Map_Image_Line*)((uchar*)ml + sizeof(RGE_Map_Image_Line));
            line_bits = line_bits + pitch;
            ++global_y;
        }
    }

    this->save_area->Unlock((char*)"diam_map::clear_image");
}

void RGE_Diamond_Map::copy_image() {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x00437620
    if (this->save_area == nullptr || this->render_area == nullptr) {
        return;
    }

    tagRECT r;
    r.left = 0;
    r.top = 0;
    r.right = this->pnl_wid - 1;
    r.bottom = this->pnl_hgt - 1;

    this->save_area->Copy(this->render_area, this->pnl_x, this->pnl_y, &r, 0);
}

void RGE_Diamond_Map::draw_all_tiles() {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x00437660
    if (this->save_area == nullptr) {
        return;
    }

    if (this->save_area->Lock((char*)"diam_map::draw_all_tiles", 1) != nullptr) {
        for (short row = 0; row < this->map_hgt; ++row) {
            for (short col = 0; col < this->map_wid; ++col) {
                this->draw_tile(col, row, 0, 0);
            }
        }
        this->save_area->Unlock((char*)"diam_map::draw_all_tiles");
    }
}

void RGE_Diamond_Map::draw_explored_tiles() {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x004376D0
    if (this->player == nullptr || this->save_area == nullptr) {
        return;
    }

    RGE_Tile_List_Node* list = nullptr;
    int count = 0;
    this->player->diam_tile_list.get_list_info(&list, &count);

    if (count <= 0) {
        return;
    }

    if (this->save_area->Lock((char*)"diam_map::draw_explored_tiles", 1) != nullptr) {
        for (int i = 0; i < count; ++i) {
            this->draw_tile((short)list[i].col, (short)list[i].row, 0, 0);
        }
        this->save_area->Unlock((char*)"diam_map::draw_explored_tiles");
    }
}

void RGE_Diamond_Map::draw_tile(short param_1, short param_2, int param_3, uchar param_4) {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x00437760
    const int col = (int)param_1;
    const int row = (int)param_2;

    RGE_Map_Tile_Row* tile_row = this->map_tile_rows + (((row + (int)this->map_wid) - col) - 1);
    if (tile_row->draw == 0) {
        return;
    }

    if (this->map == nullptr || this->map->map_row_offset == nullptr || this->player == nullptr) {
        return;
    }

    RGE_Tile* tile = &this->map->map_row_offset[row][col];
    if (this->map->map_visible_flag == 0 &&
        (this->player->mutualExploredMask & unified_map_offsets[row][col]) == 0) {
        return;
    }

    // Compute pixel offset for this tile along its scanline.
    short t = (short)row;
    if (param_1 < param_2) {
        t = param_1;
    }

    bool do_draw = false;
    short offs = 0;
    if (tile_row->ratio < 1.0f) {
        float f = (float)(int)t * tile_row->ratio;
        offs = diam_map_trunc_to_short(f);
        if ((f - (float)(int)offs) < tile_row->ratio) {
            do_draw = true;
        }
    } else {
        offs = diam_map_trunc_to_short((float)(int)t * tile_row->draw_step);
        do_draw = true;
    }

    if (!do_draw) {
        return;
    }

    long x = (long)this->map_image_lines[tile_row->image_line].start_x + (long)offs;
    long y = (long)this->map_image_start_y + (long)tile_row->image_line;

    if (param_3 != 0) {
        // Fog/overlay draw path: render_area is expected to already be locked by caller.
        x += this->pnl_x;
        y += this->pnl_y;

        const short wid = tile_row->draw_wid;
        if (this->map_tile_draw_hgt != 1) {
            if (this->map_tile_draw_hgt < 1) {
                return;
            }
            for (short dy = 0; dy < this->map_tile_draw_hgt; ++dy) {
                for (short dx = 0; dx < wid; ++dx) {
                    this->render_area->SetPixel(x + dx, y + dy, this->fog_color);
                }
            }
            return;
        }

        if (wid == 1) {
            this->render_area->SetPixel(x, y, this->fog_color);
            return;
        }
        if (wid == 2) {
            this->render_area->SetPixel(x, y, this->fog_color);
            this->render_area->SetPixel(x + 1, y, this->fog_color);
            return;
        }
        if (wid < 1) {
            return;
        }
        for (short dx = 0; dx < wid; ++dx) {
            this->render_area->SetPixel(x + dx, y, this->fog_color);
        }
        return;
    }

    // Determine base terrain color.
    uchar terrain = tile->terrain_type & 0x1F;
    long color = 0;
    if (param_4 == 0) {
        switch ((unsigned char)tile->tile_type) {
        case 0:
            color = (long)this->map->terrain_types[terrain].map_med_color;
            break;
        case 1:
        case 4:
        case 5:
        case 7:
        case 8:
        case 9:
        case 12:
        case 13:
        case 15:
            color = (long)this->map->terrain_types[terrain].map_low_color;
            break;
        case 2:
        case 3:
        case 6:
        case 10:
        case 11:
        case 14:
        case 16:
            param_4 = this->map->terrain_types[terrain].map_hi_color;
            color = (long)param_4;
            break;
        default:
            break;
        }
    } else {
        color = (long)param_4;
    }

    // Scan neighborhood for "level 4" objects that override the color.
    for (short scan_row = (short)(param_2 - 1);; ++scan_row) {
        if (row + 2 <= (int)scan_row) {
            break;
        }

        if (-1 < scan_row && scan_row < this->map_hgt) {
            for (short scan_col = (short)(param_1 - 1); (int)scan_col < col + 2; ++scan_col) {
                if (scan_col < 0 || this->map_wid <= scan_col) {
                    continue;
                }

                RGE_Object_Node* node = this->map->map_row_offset[(int)scan_row][(int)scan_col].objects.list;
                while (node != nullptr) {
                    if (node->node != nullptr && node->node->master_obj != nullptr &&
                        node->node->master_obj->map_draw_level == 4) {
                        color = (long)node->node->master_obj->map_color;
                        break;
                    }
                    node = node->next;
                }
            }
        }
    }

    const uchar c = (uchar)color;
    const short wid = tile_row->draw_wid;

    if (this->map_tile_draw_hgt == 1) {
        if (wid == 1) {
            this->save_area->SetPixel(x, y, c);
            return;
        }
        if (wid == 2) {
            this->save_area->SetPixel(x, y, c);
            this->save_area->SetPixel(x + 1, y, c);
            return;
        }
        if (wid > 0) {
            for (short dx = 0; dx < wid; ++dx) {
                this->save_area->SetPixel(x + dx, y, c);
            }
            return;
        }
        return;
    }

    if (this->map_tile_draw_hgt > 0) {
        for (short dy = 0; dy < this->map_tile_draw_hgt; ++dy) {
            for (short dx = 0; dx < wid; ++dx) {
                this->save_area->SetPixel(x + dx, y + dy, c);
            }
        }
    }
}

// -----------------------------------------------------------------------------
// Selection + objects + view rect
// -----------------------------------------------------------------------------

void RGE_Diamond_Map::draw_selected_area() {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x00437C20
    if (this->main_view == nullptr) {
        return;
    }

    long sel_col0 = 0;
    long sel_row0 = 0;
    long sel_col1 = 0;
    long sel_row1 = 0;
    if (this->main_view->get_selection_area(&sel_col0, &sel_row0, &sel_col1, &sel_row1, 1) == 0) {
        return;
    }

    if (this->render_area->Lock((char*)"diam_map::draw_selected_area", 1) == nullptr) {
        return;
    }

    if (sel_row0 <= sel_row1) {
        for (long r = sel_row0; r <= sel_row1; ++r) {
            if (sel_col0 <= sel_col1) {
                for (long c = sel_col0; c <= sel_col1; ++c) {
                    this->draw_tile((short)c, (short)r, 1, 0);
                }
            }
        }
    }

    this->render_area->Unlock((char*)"diam_map::draw_selected_area");
}

void RGE_Diamond_Map::draw_objects() {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x00437CC0
    if (this->world == nullptr || this->player == nullptr || this->render_area == nullptr) {
        return;
    }

    if (this->render_area->Lock((char*)"diam_map::draw_objects", 1) == nullptr) {
        return;
    }

    this->draw_objects_mode = 1;
    if (this->world->players != nullptr && this->world->players[0] != nullptr &&
        this->world->players[0]->objects != nullptr) {
        for (RGE_Object_Node* n = this->world->players[0]->objects->list; n != nullptr; n = n->next) {
            if (n->node != nullptr) {
                this->draw_visible_object(n->node, 0xFF, 0xFF);
            }
        }
    }

    this->draw_objects_mode = 2;
    for (short i = 1; i < this->world->player_num; ++i) {
        RGE_Player* p = (this->world->players != nullptr) ? this->world->players[i] : nullptr;
        if (p == nullptr || p->color_table == nullptr) {
            continue;
        }
        const uchar color = p->color_table->map_color;

        if (p->doppleganger_objects != nullptr) {
            for (RGE_Object_Node* n = p->doppleganger_objects->list; n != nullptr; n = n->next) {
                if (n->node != nullptr) {
                    this->draw_visible_object(n->node, color, color);
                }
            }
        }

        if (p->objects != nullptr) {
            for (RGE_Object_Node* n = p->objects->list; n != nullptr; n = n->next) {
                RGE_Static_Object* obj = n->node;
                if (obj != nullptr && (obj->selected & 1) == 0) {
                    if (obj->owner != this->player || obj->underAttack() == 0) {
                        this->draw_visible_object(obj, color, color);
                    }
                }
            }
        }
    }

    if (0 < this->player->sel_count) {
        this->draw_objects_mode = 3;
        short drawn = 0;
        for (short idx = 0; idx < 0x19; ++idx) {
            if (this->player->sel_count <= drawn) {
                break;
            }
            RGE_Static_Object* obj = this->player->sel_list[idx];
            if (obj != nullptr) {
                this->draw_visible_object(obj, 0xFF, 0xFF);
                ++drawn;
            }
        }
    }

    this->draw_objects_mode = 4;
    uchar player_color = (this->player->color_table != nullptr) ? this->player->color_table->map_color : (uchar)0xFF;
    if (this->player->objects != nullptr) {
        for (RGE_Object_Node* n = this->player->objects->list; n != nullptr; n = n->next) {
            RGE_Static_Object* obj = n->node;
            if (obj != nullptr && obj->underAttack() != 0) {
                this->draw_visible_object(obj, player_color, player_color);
            }
        }
    }

    this->render_area->Unlock((char*)"diam_map::draw_objects");
}

void RGE_Diamond_Map::draw_visible_object(RGE_Static_Object* param_1, uchar param_2, uchar param_3) {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x00437EC0
    if (param_1 == nullptr || param_1->tile == nullptr || this->player == nullptr || this->map == nullptr) {
        return;
    }

    short col = (short)diam_map_trunc_to_long(param_1->world_x);
    short row = (short)diam_map_trunc_to_long(param_1->world_y);

    char vis = 0;
    if (this->player->visible == nullptr) {
        vis = 0x0F;
    } else {
        if (this->map->map_visible_flag != 0 && this->map->fog_flag == 0) {
            vis = 0x0F;
        } else {
            if (this->player->mutualExploredMask & unified_map_offsets[(int)row][(int)col]) {
                vis = (char)0x80;
            }
            if (this->player->mutualVisibleMask & unified_map_offsets[(int)row][(int)col]) {
                vis = 0x0F;
            }
            if (this->map->map_visible_flag != 0 && vis == 0) {
                vis = (char)0x80;
            }
            if (this->map->fog_flag == 0 && vis == (char)0x80) {
                vis = 0x0F;
            }
        }
    }

    if (!(vis == 0x0F || (vis == (char)0x80 && param_1->master_obj != nullptr && param_1->master_obj->fog_flag != 0))) {
        return;
    }

    uchar draw_level = 0;
    if (param_1->type == 0x19) {
        if (vis == 0x0F) {
            return;
        }

        if (param_1->owner != nullptr &&
            this->player->mutualAlly[param_1->owner->id] == 1) {
            // Doppleganger extra data lives in the "next" object-sized block.
            const uchar* base = (const uchar*)param_1;
            const unsigned long* mask_ptr = (const unsigned long*)(base + sizeof(RGE_Static_Object) + offsetof(RGE_Static_Object, tile));
            if ((this->cur_player_bit & *mask_ptr) == 0) {
                const uchar* info = base + sizeof(RGE_Static_Object) + offsetof(RGE_Static_Object, inside_obj);
                draw_level = info[0];
                param_2 = info[1];
                param_3 = param_2;
            } else {
                param_2 = 0xFF;
                param_3 = 0xFF;
                draw_level = 0;
            }
        } else {
            param_2 = 0xFF;
            param_3 = 0xFF;
            draw_level = 0;
        }
    } else if (param_1->master_obj != nullptr) {
        draw_level = param_1->master_obj->map_draw_level;
        if (draw_level == 3) {
            param_2 = param_1->master_obj->map_color;
        }
    }

    switch (draw_level) {
    case 1:
        this->draw_object(col, row, param_3, 1, param_1);
        return;
    case 2:
        this->draw_object(col, row, param_2, 2, param_1);
        return;
    case 3:
        param_3 = param_2;
        this->draw_object(col, row, param_3, 2, param_1);
        return;
    default:
        return;
    }
}

void RGE_Diamond_Map::draw_object(short param_1, short param_2, uchar param_3, short param_4, RGE_Static_Object* param_5) {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x00438060
    (void)param_5;

    const int col = (int)param_1;
    const int row = (int)param_2;

    RGE_Map_Tile_Row* tile_row = this->map_tile_rows + (((row + (int)this->map_wid) - col) - 1);

    short t = param_2;
    if (param_1 < param_2) {
        t = param_1;
    }

    short offs = 0;
    if (tile_row->ratio < 1.0f) {
        offs = diam_map_trunc_to_short((float)(int)t * tile_row->ratio);
    } else {
        offs = diam_map_trunc_to_short((float)(int)t * tile_row->draw_step);
    }

    short image_line = tile_row->image_line;
    long x = (long)this->map_image_lines[image_line].start_x + (long)this->pnl_x + (long)offs;
    long y = (long)this->pnl_y + (long)this->map_image_start_y + (long)image_line;

    if (param_4 == 1) {
        this->render_area->FillRect(x - 1, y - 1, x + 1, y + 1, param_3);
        return;
    }

    if (param_4 == 2) {
        this->render_area->FillRect(x, y - 1, x, y + 1, param_3);
        this->render_area->FillRect(x - 1, y, x + 1, y, param_3);
        return;
    }

    if (param_4 == 3) {
        this->render_area->FillRect(x - 3, y, x + 3, y + 1, param_3);
        this->render_area->FillRect(x - 2, y - 1, x + 2, y + 2, param_3);
        return;
    }

    if (param_4 == 4) {
        this->render_area->FillRect(x - 2, y - 2, x + 2, y + 2, param_3);
        return;
    }
}

void RGE_Diamond_Map::draw_clipped_horz_line(short param_1, short param_2, short param_3, uchar param_4, RGE_Map_Image_Line* param_5) {
    // Fully verified. Source of truth: diam_map.cpp.decomp @ 0x004381D0
    short start_x = param_5->start_x;
    int minx = (int)this->pnl_x + (int)start_x;
    if (param_1 < minx) {
        param_1 = (short)this->pnl_x + start_x;
    }

    if (param_5->line_len + minx <= (int)param_1 + (int)param_3 - 1) {
        param_3 = (short)(this->pnl_x - param_1) + param_5->line_len + start_x;
    }

    this->render_area->DrawHorzLine((int)param_1, (int)param_2, (int)param_3, param_4);
}

void RGE_Diamond_Map::draw_view_rect() {
    // Fully verified. Source of truth: diam_map.cpp.asm @ 0x00438250
    if (this->player == nullptr || this->map == nullptr || this->map_tile_rows == nullptr || this->map_image_lines == nullptr) {
        return;
    }

    short view_col = (short)diam_map_trunc_to_long(this->player->view_x);
    short view_row = (short)diam_map_trunc_to_long(this->player->view_y);

    if (view_col != this->view_col || view_row != this->view_row) {
        if (view_col < 0 || (int)this->map->map_width <= (int)view_col) return;
        if (view_row < 0 || (int)this->map->map_height <= (int)view_row) return;

        RGE_Map_Tile_Row* tile_row = this->map_tile_rows + ((((int)this->map_wid + (int)view_row) - (int)view_col) - 1);
        short t = view_row;
        if (view_col < view_row) {
            t = view_col;
        }

        short offs = 0;
        if (tile_row->ratio < 1.0f) {
            offs = diam_map_trunc_to_short((float)(int)t * tile_row->ratio);
        } else {
            offs = diam_map_trunc_to_short((float)(int)t * tile_row->draw_step);
        }

        short image_line = tile_row->image_line;
        long center_x = (long)this->map_image_lines[image_line].start_x + (long)this->pnl_x + (long)offs;
        long center_y = (long)this->pnl_y + (long)this->map_image_start_y + (long)image_line;

        short max_col = 0;
        short max_row = 0;
        if (this->main_view != nullptr) {
            this->main_view->get_max_size(&max_col, &max_row);
        }

        int half = (int)max_col / 2;
        this->view_rect.left = diam_map_trunc_to_long((float)center_x - (float)half * this->map_col_ratio);
        this->view_rect.top = diam_map_trunc_to_long((float)center_y - (float)(int)max_row * this->map_row_ratio);
        this->view_rect.right = diam_map_trunc_to_long((float)center_x + (float)(half + 2) * this->map_col_ratio);
        this->view_rect.bottom = diam_map_trunc_to_long((float)center_y + (float)(int)(max_row + 4) * this->map_row_ratio);

        this->view_col = view_col;
        this->view_row = view_row;
    }

    long y = this->view_rect.top;
    if (y > this->view_rect.bottom) {
        return;
    }

    while (y <= this->view_rect.bottom) {
        long global_y0 = (long)this->pnl_y + (long)this->map_image_start_y;
        if (y < global_y0) {
            ++y;
            continue;
        }

        long global_y1 = global_y0 + (long)this->map_image_hgt - 1;
        if (y > global_y1) {
            ++y;
            continue;
        }

        long line_index = (y - (long)this->map_image_start_y) - (long)this->pnl_y;
        RGE_Map_Image_Line* line = this->map_image_lines + line_index;

        if (y == this->view_rect.top || y == this->view_rect.bottom) {
            long x0 = this->view_rect.left;
            long x1 = this->view_rect.right;

            long minx = (long)this->pnl_x + (long)line->start_x;
            long maxx = minx + (long)line->line_len;

            if (x0 < minx) x0 = minx;
            if (x1 >= maxx) x1 = maxx - 1;

            if (x0 <= x1) {
                this->render_area->DrawHorzLine(x0, y, (x1 - x0) + 1, 0xFF);
            }
        } else {
            long minx = (long)this->pnl_x + (long)line->start_x;
            long maxx = minx + (long)line->line_len;

            if (minx <= this->view_rect.left && this->view_rect.left < maxx) {
                this->render_area->SetPixel(this->view_rect.left, y, 0xFF);
            }
            if (minx <= this->view_rect.right && this->view_rect.right < maxx) {
                this->render_area->SetPixel(this->view_rect.right, y, 0xFF);
            }
        }

        ++y;
    }
}

// -----------------------------------------------------------------------------
// Mouse helpers
// -----------------------------------------------------------------------------

int RGE_Diamond_Map::pick_tile(long param_1, long param_2, short* param_3, short* param_4, RGE_Tile** param_5) {
    // Fully verified. Source of truth: diam_map.cpp.asm @ 0x00438530
    if (this->map == nullptr || this->map_image_lines == nullptr) {
        return 0;
    }

    long x = param_1 - this->pnl_x;
    long y = param_2 - this->pnl_y;

    const long start_y = (long)this->map_image_start_y;
    if (y < start_y) return 0;
    const long end_y = start_y + (long)this->map_image_hgt - 1;
    if (y > end_y) return 0;

    y = y - start_y;
    RGE_Map_Image_Line* line = &this->map_image_lines[y];
    if (x < (long)line->start_x) return 0;
    const long end_x = (long)line->start_x + (long)line->line_len - 1;
    if (x > end_x) return 0;

    short tile_row = line->tile_row;
    RGE_Map_Tile_Row* tr = &this->map_tile_rows[tile_row];

    x = x - (long)line->start_x;
    short offs = (short)diam_map_trunc_to_long((float)x * tr->col_step + tr->col_extra);

    short col = (short)(tr->map_col + offs);
    short row = (short)(tr->map_row + offs);

    if (param_3 != nullptr) {
        *param_3 = col;
    }
    if (param_4 != nullptr) {
        *param_4 = row;
    }
    if (param_5 != nullptr) {
        if (this->map->map_row_offset != nullptr) {
            *param_5 = &this->map->map_row_offset[row][col];
        } else {
            *param_5 = nullptr;
        }
    }

    return 1;
}

long RGE_Diamond_Map::handle_size(long param_1, long param_2) {
    // Fully verified. Source of truth: diam_map.cpp.asm @ 0x00438630
    TPanel::handle_size(param_1, param_2);
    this->view_col = -1;
    this->view_row = -1;
    this->create_surfaces();
    return 0;
}

void RGE_Diamond_Map::start_scroll_view(long param_1, long param_2) {
    // Fully verified. Source of truth: diam_map.cpp.asm @ 0x00438670
    short col = 0;
    short row = 0;
    RGE_Tile* tile = nullptr;
    if (this->pick_tile(param_1, param_2, &col, &row, &tile) == 0) {
        return;
    }

    this->capture_mouse();
    this->scrolling = 1;
    if (this->player != nullptr) {
        this->player->set_view_loc((float)(int)col + 0.5f, (float)(int)row + 0.5f);
    }
    this->set_redraw(TPanel::RedrawMode::Redraw);
    if (this->main_view != nullptr) {
        this->main_view->set_redraw(TPanel::RedrawMode::Redraw);
    }
    this->mouse_last_x = param_1;
    this->mouse_last_y = param_2;
}

void RGE_Diamond_Map::handle_scroll_view(long param_1, long param_2) {
    // Fully verified. Source of truth: diam_map.cpp.asm @ 0x00438720
    short col = 0;
    short row = 0;
    RGE_Tile* tile = nullptr;
    if (this->pick_tile(param_1, param_2, &col, &row, &tile) == 0) {
        return;
    }

    if (this->player != nullptr) {
        this->player->set_view_loc((float)(int)col + 0.5f, (float)(int)row + 0.5f);
    }
    this->set_redraw(TPanel::RedrawMode::Redraw);
    if (this->main_view != nullptr) {
        this->main_view->set_redraw(TPanel::RedrawMode::Redraw);
    }
    this->mouse_last_x = param_1;
    this->mouse_last_y = param_2;
}

void RGE_Diamond_Map::end_scroll_view() {
    // Fully verified. Source of truth: diam_map.cpp.asm @ 0x004387C0
    this->scrolling = 0;
    this->release_mouse();
}

int RGE_Diamond_Map::is_inside(long param_1, long param_2) {
    // Fully verified. Source of truth: diam_map.cpp.asm @ 0x004387D0
    if (TPanel::is_inside(param_1, param_2) == 0) {
        return 0;
    }
    RGE_Tile* tile = nullptr;
    short col = 0;
    short row = 0;
    return this->pick_tile(param_1, param_2, &col, &row, &tile);
}

