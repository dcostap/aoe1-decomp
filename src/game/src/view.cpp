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
#include "RGE_Pick_Info.h"
#include "RGE_Object_List.h"
#include "RGE_Object_Node.h"
#include "RGE_Sprite.h"
#include "RGE_Active_Sprite_List.h"
#include "RGE_Color_Table.h"
#include "TShape.h"
#include "TMousePointer.h"
#include "TMessagePanel.h"
#include "RGE_Tile_Set.h"
#include "RGE_Border_Set.h"
#include "globals.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

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

static const float kView_Scroll_Factor = 0.0625f; // Source of truth: view.cpp.asm uses DAT_005776c4.
static const float kView_Pick_Offset = 0.5f;      // Source of truth: view.cpp.asm uses DAT_005776c0 (=-0.5), i.e. +0.5 bias.

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

RGE_View::RGE_View()
    : TPanel((char*)"RGE_View") {
    // Partially verified. Source of truth: view.cpp.decomp @ 0x00533510 (RGE_View::RGE_View).
    this->cur_render_area = nullptr;
    this->calc_draw_count = 0;
    this->world = nullptr;
    this->player = nullptr;
    this->map = nullptr;

    this->tile_wid = 0;
    this->tile_hgt = 0;
    this->tile_half_wid = 0;
    this->tile_half_hgt = 0;
    this->elev_hgt = 0;
    this->render_rect_wid = 0;
    this->render_rect_hgt = 0;
    this->max_col_num = 0;
    this->max_row_num = 0;
    this->center_scr_col = 0;
    this->center_scr_row = 0;
    this->center_scr_col_offset = 0;
    this->center_scr_row_offset = 0;
    this->center_map_col = 0;
    this->center_map_row = 0;
    this->start_scr_col = 0;
    this->start_scr_row = 0;
    this->start_map_col = 0;
    this->start_map_row = 0;
    this->map_scr_x_offset = 0;
    this->map_scr_y_offset = 0;
    this->last_view_x = -9999.0f;
    this->last_view_y = -9999.0f;
    this->function_mode = 0;
    this->function_parm = 0;
    this->render_terrain_mode = 0;

    this->sel_col1 = -1;
    this->sel_row1 = -1;
    this->sel_col2 = -1;
    this->sel_row2 = -1;
    this->save_paint_terrain = -1;

    this->white_pen = nullptr;
    this->red_pen = nullptr;
    this->hollow_brush = nullptr;
    this->border_line_shape = nullptr;

    this->scroll_action = 0;
    this->mouse_last_x = -1;
    this->mouse_last_y = -1;
    this->movable_object = nullptr;

    this->Terrain_Clip_Mask = nullptr;
    this->Terrain_Fog_Clip_Mask = nullptr;
    this->Master_Clip_Mask = nullptr;

    this->Tile_Edge_Tables = nullptr;
    this->Black_Edge_Tables = nullptr;

    std::memset(&this->OverlaidPanel, 0, sizeof(this->OverlaidPanel));
    this->OverlaidPanelActive = 0;
    std::memset(this->EdgeNumber, 0xFF, sizeof(this->EdgeNumber));
    this->Limited_Render_Rect = 0;
    this->Use_Rect2 = 0;
    std::memset(&this->Render_Rect1, 0, sizeof(this->Render_Rect1));
    std::memset(&this->Render_Rect2, 0, sizeof(this->Render_Rect2));

    this->Float_Scroll_Offsets = nullptr;
    this->Float_Scroll_Offsets_Sz = 0;
    this->Float_X_Delta = 0;
    this->Float_Y_Delta = 0;
    this->Queued_Blits = 0;
    this->Blit_Queue = nullptr;
    this->Blit_Queue_Size = 0;
    this->Blt_Queue_Allocated = 0;
    this->Current_Blit = 0;
    this->Blit_Offset_X = 0;
    this->Blit_Offset_Y = 0;

    this->real_old_map_col = 0;
    this->real_old_map_row = 0;
    for (int i = 0; i < 5; ++i) {
        this->pick_lists[i] = nullptr;
        this->pick_list_size[i] = 0;
    }

    this->save_area1 = nullptr;
    this->LastRenderBits = nullptr;
    this->RenderOffsets = nullptr;
    this->LastRenderSize = 0;
    this->prior_objs = nullptr;
    this->futur_objs = nullptr;

    this->UC_ObjectTouched = 0;
    this->UC_TouchedObj = (int)0x80000000u;
    this->UC_StartTime = 0;
    this->UC_ElapsedTime = 0;

    this->message_panel = nullptr;
    this->extra_sprites = nullptr;

    this->DispSel_List = (DisplaySelectedObjRec*)std::calloc(8, 0x14);
    this->DispSel_List_Size = 0;
    this->DispSel_List_Max = 8;
}

RGE_View::~RGE_View() {
    // Partially verified. Source of truth: view.cpp.decomp @ 0x00533760 (RGE_View::~RGE_View).
    if (this->Tile_Edge_Tables) {
        std::free(this->Tile_Edge_Tables);
        this->Tile_Edge_Tables = nullptr;
    }
    if (this->Black_Edge_Tables) {
        std::free(this->Black_Edge_Tables);
        this->Black_Edge_Tables = nullptr;
    }
    if (this->Float_Scroll_Offsets) {
        std::free(this->Float_Scroll_Offsets);
        this->Float_Scroll_Offsets = nullptr;
    }
    if (this->Blit_Queue) {
        std::free(this->Blit_Queue);
        this->Blit_Queue = nullptr;
    }
    for (int i = 0; i < 5; ++i) {
        if (this->pick_lists[i] != nullptr) {
            std::free(this->pick_lists[i]);
            this->pick_lists[i] = nullptr;
        }
    }
    if (this->LastRenderBits) {
        std::free(this->LastRenderBits);
        this->LastRenderBits = nullptr;
    }
    if (this->RenderOffsets) {
        std::free(this->RenderOffsets);
        this->RenderOffsets = nullptr;
    }
    if (this->save_area1) {
        delete this->save_area1;
        this->save_area1 = nullptr;
    }
    if (this->Terrain_Clip_Mask) {
        delete this->Terrain_Clip_Mask;
        this->Terrain_Clip_Mask = nullptr;
    }
    if (this->Terrain_Fog_Clip_Mask) {
        delete this->Terrain_Fog_Clip_Mask;
        this->Terrain_Fog_Clip_Mask = nullptr;
    }
    if (this->Master_Clip_Mask) {
        delete this->Master_Clip_Mask;
        this->Master_Clip_Mask = nullptr;
    }
    if (this->DispSel_List) {
        std::free(this->DispSel_List);
        this->DispSel_List = nullptr;
    }
}

long RGE_View::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    // Partially verified. Source of truth: view.cpp.decomp @ 0x00533940 (RGE_View::setup).
    long ok = TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
    this->cur_render_area = nullptr;
    this->last_view_x = -9999.0f;
    this->last_view_y = -9999.0f;
    this->function_mode = 0;
    return ok;
}

void RGE_View::set_rect(tagRECT param_1) {
    // Source of truth: view.cpp.decomp calls through TPanel::set_rect(tagRECT).
    TPanel::set_rect(param_1);
}

void RGE_View::set_rect(long param_1, long param_2, long param_3, long param_4) {
    // Partially verified. Source of truth: view.cpp.decomp @ 0x00533F70 (RGE_View::set_rect).
    TPanel::set_rect(param_1, param_2, param_3, param_4);

    this->render_rect_wid = (short)param_3;
    this->render_rect_hgt = (short)param_4;

    if (this->tile_half_wid <= 0) this->tile_half_wid = (this->map != nullptr) ? this->map->tile_half_width : 32;
    if (this->tile_half_hgt <= 0) this->tile_half_hgt = (this->map != nullptr) ? this->map->tile_half_height : 16;
    if (this->tile_wid <= 0) this->tile_wid = (short)(this->tile_half_wid * 2);
    if (this->tile_hgt <= 0) this->tile_hgt = (short)(this->tile_half_hgt * 2);

    if (this->tile_half_wid > 0) {
        this->max_col_num = (short)(param_3 / this->tile_half_wid);
    }
    if (this->tile_half_hgt > 0) {
        this->max_row_num = (short)(param_4 / this->tile_half_hgt);
    }
    if (this->max_col_num < 1) this->max_col_num = 1;
    if (this->max_row_num < 1) this->max_row_num = 1;

    this->last_view_x = -9999.0f;
    this->last_view_y = -9999.0f;

    if (this->Terrain_Clip_Mask) {
        delete this->Terrain_Clip_Mask;
        this->Terrain_Clip_Mask = nullptr;
    }
    if (this->Terrain_Fog_Clip_Mask) {
        delete this->Terrain_Fog_Clip_Mask;
        this->Terrain_Fog_Clip_Mask = nullptr;
    }
    if (this->Master_Clip_Mask) {
        delete this->Master_Clip_Mask;
        this->Master_Clip_Mask = nullptr;
    }

    if (param_3 > 0 && param_4 > 0) {
        this->Terrain_Clip_Mask = new TSpan_List_Manager((int)param_3, (int)param_4);
        this->Terrain_Fog_Clip_Mask = new TSpan_List_Manager((int)param_3, (int)param_4);
        this->Master_Clip_Mask = new TSpan_List_Manager((int)param_3, (int)param_4);
    }
}

void RGE_View::set_focus(int param_1) {
    // Partially verified. Source of truth: view.cpp.decomp @ 0x00533AC0.
    TPanel::set_focus(param_1);
    if (MouseSystem != nullptr) {
        MouseSystem->set_game_enable(param_1);
    }
}

void RGE_View::set_selection_area(long param_1, long param_2, long param_3, long param_4) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00534530.
    if ((this->map != nullptr) && (rge_base_game->game_mode != 0x15)) {
        this->map->request_redraw((int)this->sel_col1, (int)this->sel_row1, (int)this->sel_col2, (int)this->sel_row2, '\0');
    }

    this->sel_col1 = param_1;
    this->sel_row1 = param_2;
    this->sel_col2 = param_3;
    this->sel_row2 = param_4;

    if ((this->map != nullptr) && (rge_base_game->game_mode != 0x15)) {
        this->map->request_redraw((int)param_1, (int)param_2, (int)param_3, (int)param_4, '\x10');
    }

    this->set_redraw(TPanel::RedrawMode::Redraw);
}

uchar RGE_View::pick(uchar param_1, uchar param_2, long param_3, long param_4, RGE_Pick_Info* param_5, RGE_Static_Object* param_6) {
    // Partially verified. Source of truth: view.cpp.decomp @ 0x005359E0.
    // NOTE: The original calls view_function(); this repo does not yet have that pipeline transliterated.
    // This is the minimal tile-pick behavior needed by scroll/paint interactions.
    (void)param_2;
    (void)param_6;

    if (param_5 != nullptr) {
        param_5->x = 0.0f;
        param_5->y = 0.0f;
        param_5->scr_x = 0;
        param_5->scr_y = 0;
        param_5->object = nullptr;
        param_5->tile = nullptr;
    }

    if (this->map == nullptr || param_5 == nullptr) {
        return '\0';
    }
    if (param_1 != '(') {
        return '\0';
    }
    if (this->tile_half_wid == 0 || this->tile_half_hgt == 0) {
        return '\0';
    }

    // Approximate inverse of the isometric projection used by RGE_Map::coordinate_map()/tile screen coords.
    float sx = (float)(param_3 + this->map_scr_x_offset);
    float sy = (float)(param_4 + this->map_scr_y_offset);
    float a = sx / (float)this->tile_half_wid;
    float b = sy / (float)this->tile_half_hgt;

    float col = (a - b) * 0.5f;
    float row = (a + b) * 0.5f;

    param_5->x = col;
    param_5->y = row;
    param_5->scr_x = (short)param_3;
    param_5->scr_y = (short)param_4;

    int icol = (int)col;
    int irow = (int)row;
    if (icol < 0 || irow < 0 || icol >= (int)this->map->map_width || irow >= (int)this->map->map_height) {
        return '\0';
    }

    param_5->tile = this->map->get_tile(icol, irow);
    return (param_5->tile != nullptr) ? '3' : '\0';
}

uchar RGE_View::pick_multi(uchar param_1, long param_2, long param_3, long param_4, long param_5) {
    // TODO: STUB - the original uses prior_objs/futur_objs capture lists (DClipInfo_List) to select objects.
    // Keep this function for control-flow parity in end_scroll_view while the capture pipeline is not present.
    (void)param_1;
    if (this->player != nullptr) {
        this->player->select_area(param_2, param_3, param_4, param_5);
    }
    return '\0';
}

int RGE_View::pick_through_fog(RGE_Static_Object* param_1) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00535CB0.
    (void)param_1;
    return 0;
}

int RGE_View::pick_weight(RGE_Static_Object* param_1, int param_2) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00535CC0.
    bool bVar1;
    RGE_Static_Object* pRVar2;

    pRVar2 = param_1;
    uchar select_level = (uchar)param_1->master_obj->select_level;

    if ((this->UC_ObjectTouched == 0) || (this->UC_TouchedObj != pRVar2->id)) {
        bVar1 = false;
    } else {
        bVar1 = true;
    }

    if (select_level == 2) {
        if (bVar1) {
            return 5;
        }
        if ((param_2 != 1) && (param_2 != 2)) {
            if (param_2 != 3) {
                return 0;
            }
            return 2;
        }
    } else {
        if (select_level != 3) {
            if (select_level != 4) {
                return 1;
            }
            if (!bVar1) {
                if ((param_2 != 1) && (param_2 != 2)) {
                    return (param_2 == 3) + 2;
                }
                return 4;
            }
            return 5;
        }
        if (bVar1) {
            return 5;
        }
        if (param_2 != 1) {
            if (param_2 != 2) {
                return 0;
            }
            return 3;
        }
    }
    return 3;
}

int RGE_View::start_scroll_view(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053A0D0.
    RGE_Pick_Info pick_info;

    if (param_1 == '\x03') {
        uchar uVar2 = this->pick('(', '\0', param_2, param_3, &pick_info, nullptr);
        if (uVar2 != '3') {
            return 0;
        }

        long col = (long)pick_info.x;
        long row = (long)pick_info.y;
        this->set_selection_area(col, row, col, row);
    } else if (param_1 == '\t') {
        this->pick('(', '\0', param_2, param_3, &pick_info, nullptr);
        this->real_old_map_col = (long)pick_info.x;
        this->real_old_map_row = (long)pick_info.y;

        if (this->do_paint(param_2, param_3, param_2, param_3, 1) == 0) {
            return 0;
        }

        this->set_redraw(TPanel::RedrawMode::Redraw);
    }

    this->scroll_action = param_1;
    this->mouse_last_x = param_2;
    this->mouse_last_y = param_3;

    this->capture_mouse();

    uchar action = this->scroll_action;
    if (action == '\x01' || action == '\x02' || action == '\x06' || action == '\a' || action == '\b') {
        rge_base_game->mouse_off();
    }

    if (this->scroll_action == '\x02') {
        if ((param_5 == 0) && (param_4 == 0)) {
            this->player->unselect_object();
        }
        this->set_redraw(TPanel::RedrawMode::Redraw);
    }

    if ((this->scroll_action == '\x06') || (this->scroll_action == '\b')) {
        uchar uVar2 = this->pick('(', '\0', param_2, param_3, &pick_info, nullptr);
        if (uVar2 == '3') {
            this->player->set_view_loc(pick_info.x + kView_Pick_Offset, pick_info.y + kView_Pick_Offset);
            this->set_redraw(TPanel::RedrawMode::Redraw);
            return 1;
        }
    }

    return 0;
}

int RGE_View::handle_scroll_view(long param_1, long param_2) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053A290.
    tagPOINT point;
    RGE_Pick_Info pick_info;
    long save_mouse_last_x;

    point.x = this->mouse_last_x;
    if ((param_1 == point.x) && (param_2 == this->mouse_last_y)) {
        return 0;
    }

    if (this->player == nullptr) {
        return 0;
    }

    float start_view_x = this->player->view_x;
    float start_view_y = this->player->view_y;

    uchar action = this->scroll_action;
    switch (action) {
    case '\x02':
        this->mouse_last_x = param_1;
        this->mouse_last_y = param_2;
        this->bound_point(&this->mouse_last_x, &this->mouse_last_y);
        this->set_redraw(TPanel::RedrawMode::Redraw);
        return 0;

    case '\x06': {
        if (this->is_inside(param_1, param_2) != 0) {
            uchar uVar8 = this->pick('(', '\0', param_1, param_2, &pick_info, nullptr);
            if (uVar8 == '3') {
                this->player->set_view_loc(pick_info.x + kView_Pick_Offset, pick_info.y + kView_Pick_Offset);
            }
        }

        this->mouse_last_x = param_1;
        this->mouse_last_y = param_2;

        if ((start_view_x == this->player->view_x) && (start_view_y == this->player->view_y)) {
            return 0;
        }
        this->set_redraw(TPanel::RedrawMode::Redraw);
        return 1;
    }

    case '\a': {
        int iVar10 = (int)(param_2 - this->mouse_last_y);
        if (((param_2 != this->mouse_last_y) && (iVar10 < 100)) && (-100 < iVar10)) {
            short sVar9 = (short)((long)((float)iVar10 * kView_Scroll_Factor));
            this->player->map_y = (short)(this->player->map_y + sVar9);
            this->player->map_x = (short)(this->player->map_x - sVar9);
        }

        iVar10 = (int)(param_1 - this->mouse_last_x);
        if (((param_1 != this->mouse_last_x) && (iVar10 < 100)) && (-100 < iVar10)) {
            short sVar9 = (short)((long)((float)iVar10 * kView_Scroll_Factor));
            this->player->map_y = (short)(this->player->map_y + sVar9);
            this->player->map_x = (short)(this->player->map_x + sVar9);
        }

        if ((std::abs((int)(param_2 - this->mouse_down_y)) < 9) && (std::abs((int)(param_1 - this->mouse_down_x)) < 9)) {
            this->mouse_last_x = param_1;
            this->mouse_last_y = param_2;
            this->set_redraw(TPanel::RedrawMode::Redraw);
            return 1;
        }

        point.x = this->mouse_down_x;
        point.y = this->mouse_down_y;
        if (this->render_area && this->render_area->Wnd) {
            ClientToScreen((HWND)this->render_area->Wnd, (POINT*)&point);
            SetCursorPos(point.x, point.y);
        }

        this->mouse_last_x = this->mouse_down_x;
        this->mouse_last_y = this->mouse_down_y;
        this->set_redraw(TPanel::RedrawMode::Redraw);
        return 1;
    }

    case '\b': {
        int iVar10 = (int)(param_2 - this->mouse_last_y);
        if (((param_2 != this->mouse_last_y) && (iVar10 < 100)) && (-100 < iVar10)) {
            int step = (int)((long)((float)iVar10 * kView_Scroll_Factor));
            this->player->set_view_loc(this->player->view_x - (float)step, this->player->view_y + (float)step);
        }

        iVar10 = (int)(param_1 - this->mouse_last_x);
        if (((param_1 != this->mouse_last_x) && (iVar10 < 100)) && (-100 < iVar10)) {
            int step = (int)((long)((float)iVar10 * kView_Scroll_Factor));
            this->player->set_view_loc(this->player->view_x + (float)step, this->player->view_y + (float)step);
        }

        if ((std::abs((int)(param_2 - this->mouse_down_y)) < 9) && (std::abs((int)(param_1 - this->mouse_down_x)) < 9)) {
            this->mouse_last_x = param_1;
            this->mouse_last_y = param_2;
        } else {
            point.x = this->mouse_down_x;
            point.y = this->mouse_down_y;
            if (this->render_area && this->render_area->Wnd) {
                ClientToScreen((HWND)this->render_area->Wnd, (POINT*)&point);
                SetCursorPos(point.x, point.y);
            }
            this->mouse_last_x = this->mouse_down_x;
            this->mouse_last_y = this->mouse_down_y;
        }

        if ((start_view_x == this->player->view_x) && (start_view_y == this->player->view_y)) {
            return 0;
        }
        this->set_redraw(TPanel::RedrawMode::Redraw);
        return 1;
    }
    }

    // Default: edge-scrolling while dragging (also handles selection and paint interactions).
    int bVar7;
    if ((action == '\x03') || (action == '\x04') || (action == '\t')) {
        if (((param_1 < this->clip_rect.left + 0x40) && (param_1 < point.x)) ||
            ((this->clip_rect.right - 0x40 < param_1) && (point.x < param_1)) ||
            ((param_2 < this->clip_rect.top + 0x20) && (param_2 < this->mouse_last_y)) ||
            ((this->clip_rect.bottom - 0x20 < param_2) && (this->mouse_last_y < param_2))) {
            bVar7 = 1;
        } else {
            bVar7 = 0;
        }
    } else {
        bVar7 = 1;
    }

    int iVar10 = (int)(param_2 - this->mouse_last_y);
    if (((iVar10 != 0) && (iVar10 < 200)) && ((-200 < iVar10 && (bVar7 != 0)))) {
        this->player->set_view_loc(
            this->player->view_x - (float)iVar10 * kView_Scroll_Factor,
            this->player->view_y + (float)iVar10 * kView_Scroll_Factor);
    }

    iVar10 = (int)(param_1 - this->mouse_last_x);
    if (((iVar10 != 0) && (iVar10 < 200)) && ((-200 < iVar10 && (bVar7 != 0)))) {
        this->player->set_view_loc(
            this->player->view_x + (float)iVar10 * kView_Scroll_Factor,
            this->player->view_y + (float)iVar10 * kView_Scroll_Factor);
    }

    point.x = this->mouse_last_x;
    long old_mouse_last_y = this->mouse_last_y;
    this->mouse_last_x = param_1;
    this->mouse_last_y = param_2;

    if (bVar7 != 0) {
        if ((8 < std::abs((int)(param_2 - this->mouse_down_y))) || (8 < std::abs((int)(param_1 - this->mouse_down_x)))) {
            point.x = this->mouse_down_x;
            point.y = this->mouse_down_y;
            if (this->render_area && this->render_area->Wnd) {
                ClientToScreen((HWND)this->render_area->Wnd, (POINT*)&point);
                SetCursorPos(point.x, point.y);
            }
            this->mouse_last_x = this->mouse_down_x;
            this->mouse_last_y = this->mouse_down_y;
        }
    } else {
        this->mouse_down_x = param_1;
        this->mouse_down_y = param_2;
    }

    action = this->scroll_action;
    if (action == '\x03') {
        uchar uVar8 = this->pick('(', '\0', param_1, param_2, &pick_info, nullptr);
        if ((uVar8 == '3') && (this->player != nullptr)) {
            long col2 = (long)pick_info.x;
            long row2 = (long)pick_info.y;
            this->set_selection_area(this->sel_col1, this->sel_row1, col2, row2);
        }
    } else if (action == '\x04') {
        if ((this->player->selected_obj != nullptr) &&
            (this->pick('(', '\0', param_1, param_2, &pick_info, nullptr) == '3')) {
            this->player->selected_obj->teleport(pick_info.x, pick_info.y, 0.0f);

            RGE_Static_Object* pRVar6 = this->player->selected_obj;
            uchar uVar8;
            if (pRVar6->sprite_list == nullptr) {
                if (pRVar6->sprite == nullptr) {
                    uVar8 = '\x14';
                } else {
                    uVar8 = pRVar6->sprite->get_lowest_draw_level();
                }
            } else {
                uVar8 = pRVar6->sprite_list->get_lowest_draw_level();
            }

            if (uVar8 == '\0') {
                this->set_redraw(TPanel::RedrawMode::RedrawFull);
            } else {
                this->set_redraw(TPanel::RedrawMode::Redraw);
            }
        }
    } else if (action == '\t') {
        this->do_paint(point.x, old_mouse_last_y, param_1, param_2, 2);
        this->set_redraw(TPanel::RedrawMode::Redraw);
    }

    if ((start_view_x == this->player->view_x) && (start_view_y == this->player->view_y)) {
        return 0;
    }
    this->set_redraw(TPanel::RedrawMode::Redraw);
    return 1;
}

void RGE_View::end_scroll_view() {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053A9C0.
    tagPOINT point;

    switch (this->scroll_action) {
    case '\x01':
    case '\x06':
    case '\a':
    case '\b':
        point.x = (LONG)this->mouse_down_x;
        point.y = (LONG)this->mouse_down_y;
        if (this->render_area && this->render_area->Wnd) {
            ClientToScreen((HWND)this->render_area->Wnd, (POINT*)&point);
            SetCursorPos(point.x, point.y);
        }
        break;

    case '\x02': {
        long x0 = this->mouse_down_x;
        long x1 = this->mouse_last_x;
        long min_x = x0;
        long max_x = x1;
        if (x1 < x0) {
            min_x = x1;
            max_x = x0;
        }

        long y0 = this->mouse_down_y;
        long y1 = this->mouse_last_y;
        long min_y = y0;
        long max_y = y1;
        if (y1 < y0) {
            min_y = y1;
            max_y = y0;
        }

        this->pick_multi('\x04', min_x, min_y, max_x, max_y);
        this->set_redraw(TPanel::RedrawMode::Redraw);
        break;
    }

    case '\t':
        this->do_paint(this->mouse_down_x, this->mouse_down_y, this->mouse_last_x, this->mouse_last_y, 0);
        this->set_redraw(TPanel::RedrawMode::Redraw);
        break;
    }

    uchar uVar1 = this->scroll_action;
    if (uVar1 == '\x01' || uVar1 == '\x02' || uVar1 == '\x06' || uVar1 == '\a' || uVar1 == '\b') {
        rge_base_game->mouse_on();
    }

    this->release_mouse();
    this->scroll_action = '\0';
}

int RGE_View::do_paint(long param_1, long param_2, long param_3, long param_4, int param_5) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053AAF0.
    RGE_Pick_Info pick_info;

    uchar uVar2 = this->pick('(', '\0', param_3, param_4, &pick_info, nullptr);
    if (uVar2 != '3') {
        return 0;
    }

    long lVar3 = (long)pick_info.x; // col
    long lVar4 = (long)pick_info.y; // row

    this->pick('(', '\0', param_1, param_2, &pick_info, nullptr);

    int iVar1 = rge_base_game->game_mode;
    if (iVar1 == 9) {
        if ((param_5 != 0) && (rge_base_game->terrain_id != -1)) {
            this->map->do_terrain_brush_stroke(
                this->real_old_map_col, this->real_old_map_row, lVar3, lVar4,
                (long)rge_base_game->brush_size, (uchar)rge_base_game->terrain_id);
        }
    } else if (iVar1 == 10) {
        if ((param_5 != 0) && (rge_base_game->elevation_height != -1)) {
            this->map->do_elevation_brush_stroke(
                this->real_old_map_col, this->real_old_map_row, lVar3, lVar4,
                (long)rge_base_game->brush_size, (uchar)rge_base_game->elevation_height);
        }
    } else if (iVar1 == 0x13) {
        this->map->do_cliff_brush_stroke(
            this->real_old_map_col, this->real_old_map_row, lVar3, lVar4,
            0, (uchar)(rge_base_game->sub_game_mode == 1));
        this->set_redraw(TPanel::RedrawMode::RedrawFull);
    }

    this->real_old_map_row = lVar4;
    this->real_old_map_col = lVar3;
    return 1;
}

void RGE_View::draw_multi_object_outline() {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00538410.
    return;
}

int RGE_View::get_selection_area(long* col1, long* row1, long* col2, long* row2, int normalize) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x005345D0
    *col1 = this->sel_col1;
    *row1 = this->sel_row1;
    *col2 = this->sel_col2;
    int r2 = (int)this->sel_row2;
    *row2 = r2;

    int c1 = (int)*col1;
    if (c1 == -1 && *row1 == -1 && *col2 == -1 && r2 == -1) {
        return 0;
    }

    if (c1 < 0) {
        *col1 = 0;
    } else {
        int mw = this->map->map_width;
        if (mw <= c1) {
            *col1 = mw - 1;
        }
    }

    if (*row1 < 0) {
        *row1 = 0;
    } else {
        int mh = this->map->map_height;
        if (mh <= *row1) {
            *row1 = mh - 1;
        }
    }

    if (*col2 < 0) {
        *col2 = 0;
    } else {
        int mw = this->map->map_width;
        if (mw <= *col2) {
            *col2 = mw - 1;
        }
    }

    if (*row2 < 0) {
        *row2 = 0;
    } else {
        int mh = this->map->map_height;
        if (mh <= *row2) {
            *row2 = mh - 1;
        }
    }

    if (normalize != 0) {
        int a = (int)*col1;
        int b = (int)*col2;
        int d = (int)*row2;
        int c = (int)*row1;

        int min_c = a;
        if (b <= a) {
            min_c = b;
        }
        *col1 = min_c;

        int min_r = c;
        if (d <= c) {
            min_r = d;
        }
        *row1 = min_r;

        if (a <= b) {
            a = b;
        }
        *col2 = a;

        if (c <= d) {
            c = d;
        }
        *row2 = c;
    }

    return 1;
}

void RGE_View::get_max_size(short* max_col, short* max_row) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00535FC0
    *max_col = this->max_col_num;
    *max_row = this->max_row_num;
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
        if (this->render_area) {
           this->render_area->Clear(&this->render_area->ClipRect, 0);
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
    if (this->map == nullptr) return;

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
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00535480 (RGE_View::draw_view).
    if (area == nullptr) area = this->render_area;
    if (area == nullptr) return;

    this->cur_render_area = area;
    if (area->Lock("draw_view", 1)) {
        if (mode == 10) { // Terrain
            tagRECT rect = area->ClipRect;
            this->view_function_terrain(mode, rect);
        }
        area->Unlock("draw_view");
    }
    this->cur_render_area = nullptr;
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

                                // Source of truth: view.cpp.decomp @ 0x00536B40 (RGE_View::view_function_terrain)
                                // calls RGE_Object_List::draw(&tile->objects, ...).
                                if (tile->objects.list != nullptr) {
                                    if (vis != 0x0F) {
                                        fog_next_shape = 1;
                                    }
                                    short obj_y = (short)(sy + (int)tile->height * (int)this->tile_half_hgt);
                                    tile->objects.draw(
                                        this->cur_render_area,
                                        (short)sx,
                                        obj_y,
                                        (uchar)(vis == 0x80));
                                    fog_next_shape = 0;
                                }
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
