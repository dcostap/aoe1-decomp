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
#include "RGE_SPick_Info.h"
#include "Ov_Sprite_Draw_Rec.h"
#include "DisplaySelectedObjRec.h"
#include "RGE_Object_List.h"
#include "RGE_Object_Node.h"
#include "RGE_Sprite.h"
#include "RGE_Active_Sprite_List.h"
#include "RGE_Color_Table.h"
#include "TShape.h"
#include "DClipInfo_List.h"
#include "DClipInfo_Node.h"
#include "TMousePointer.h"
#include "TMessagePanel.h"
#include "RGE_Tile_Set.h"
#include "RGE_Border_Set.h"
#include "Tile_FogEdge_Table.h"
#include "Tile_BlackEdge_Table.h"
#include "../include/custom_debug.h"
#include "globals.h"
#include "debug_helpers.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include <fcntl.h>
#include <io.h>

extern "C" void _ASMSet_Shadowing(int p1, int p2, int p3, int p4);
extern "C" void _ASMSet_Color_Xform(int v);
extern "C" void _ASMSet_Xlate_Table(void* p);

// Global variables (from decomp)
int view_debug_redraw_all = 0;
int view_debug_ObstructionMap = 0;
int view_debug_palette = 0;
int tiles_drawn = 0;
int frame_count = 0;
int View_Grid_Mode = 0;
RGE_Pick_Obj_Info Picked_Objects[0x40] = {}; // Stride 0xC, max 0x40. Source of truth: view.cpp.asm.
extern TMousePointer* MouseSystem;
extern RGE_Base_Game* rge_base_game;
static int s_view_debug_draw_logs = 0;
static int s_view_debug_terrain_logs = 0;
static int s_view_debug_masked_draws = 0;
static int s_view_debug_fog_masked_draws = 0;
static int s_view_debug_fallback_draws = 0;

static const float kView_Scroll_Factor = 0.0625f; // Source of truth: view.cpp.asm uses DAT_005776c4.
static const float kView_Pick_Offset = 0.5f;      // Source of truth: view.cpp.asm uses DAT_005776c0 (=-0.5), i.e. +0.5 bias.
static const float kView_Cliff_Brush_Snap_Scale = 0.33333334f; // Source of truth: view.cpp.asm uses DAT_005776b8.

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
    // Fully verified. Source of truth: view.cpp.asm @ 0x00533510
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
    this->save_area1 = nullptr;
    this->set_selection_area(-1, -1, -1, -1);

    this->Terrain_Clip_Mask = nullptr;
    this->Terrain_Fog_Clip_Mask = nullptr;
    this->Master_Clip_Mask = nullptr;

    this->LastRenderBits = nullptr;
    this->RenderOffsets = nullptr;
    this->LastRenderSize = 0;
    this->Tile_Edge_Tables = nullptr;
    this->Black_Edge_Tables = nullptr;

    this->Float_Scroll_Offsets = nullptr;
    this->Float_Scroll_Offsets_Sz = 0;
    this->Float_X_Delta = 0;
    this->Float_Y_Delta = 0;
    this->Queued_Blits = 0;
    this->Blit_Queue = nullptr;
    this->Blit_Queue_Size = 0;
    this->Current_Blit = 0;
    this->Blit_Offset_X = 0;
    this->Blit_Offset_Y = 0;
    this->prior_objs = nullptr;
    this->futur_objs = nullptr;

    for (int i = 0; i < 5; ++i) {
        this->pick_lists[i] = nullptr;
        this->pick_list_size[i] = 0;
    }

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
    // Fully verified. Source of truth: view.cpp.asm @ 0x00533760
    if (this->border_line_shape != nullptr) {
        delete this->border_line_shape;
        this->border_line_shape = nullptr;
    }

    this->delete_surfaces();

    if (this->red_pen != nullptr) {
        DeleteObject(this->red_pen);
        this->red_pen = nullptr;
    }

    if (this->RenderOffsets != nullptr) {
        std::free(this->RenderOffsets);
        this->RenderOffsets = nullptr;
    }

    if (this->Terrain_Clip_Mask != nullptr) {
        delete this->Terrain_Clip_Mask;
        this->Terrain_Clip_Mask = nullptr;
    }
    if (this->Terrain_Fog_Clip_Mask != nullptr) {
        delete this->Terrain_Fog_Clip_Mask;
        this->Terrain_Fog_Clip_Mask = nullptr;
    }
    if (this->Master_Clip_Mask != nullptr) {
        delete this->Master_Clip_Mask;
        this->Master_Clip_Mask = nullptr;
    }

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
    if (this->prior_objs) {
        delete this->prior_objs;
        this->prior_objs = nullptr;
    }
    if (this->futur_objs) {
        delete this->futur_objs;
        this->futur_objs = nullptr;
    }
    for (int i = 0; i < 5; ++i) {
        if (this->pick_lists[i] != nullptr) {
            std::free(this->pick_lists[i]);
            this->pick_lists[i] = nullptr;
        }
    }

    if (MouseSystem != nullptr) {
        MouseSystem->set_game_mode(0);
        MouseSystem->set_game_enable(0);
    }

    if (this->DispSel_List) {
        std::free(this->DispSel_List);
        this->DispSel_List = nullptr;
    }

    this->reset_overlay_sprites();
}

void RGE_View::display_object_selection(int id, int duration, int select_type, int reset_type) {
    // Source of truth: view.cpp.decomp @ 0x00533EC0
    bool found_empty = false;
    DisplaySelectedObjRec* slot = nullptr;

    for (int i = 0; i < this->DispSel_List_Max; ++i) {
        DisplaySelectedObjRec* rec = &this->DispSel_List[i];
        if (rec->active == 0) {
            found_empty = true;
            slot = rec;
        } else if (reset_type != 0 && rec->select_type == reset_type) {
            rec->start_time -= rec->duration;
        }
    }

    if (found_empty && slot != nullptr) {
        slot->active = 1;
        slot->id = id;
        slot->start_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\view.cpp", 0x31D);
        slot->duration = (unsigned long)duration;
        slot->select_type = select_type;
        this->DispSel_List_Size += 1;
    }
}

void RGE_View::update_display_selected_objects() {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00533E10
    const ulong now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\view.cpp", 0x2CB);

    for (int i = 0; i < this->DispSel_List_Max; ++i) {
        DisplaySelectedObjRec* rec = &this->DispSel_List[i];
        if (rec->active == 0) {
            continue;
        }

        RGE_Static_Object* obj = this->world->objectsValue[rec->id];

        if (obj == nullptr) {
            rec->active = 0;
            this->DispSel_List_Size -= 1;
            continue;
        }

        const ulong elapsed = now - rec->start_time;
        if ((ulong)rec->duration < elapsed) {
            rec->active = 0;
            this->DispSel_List_Size -= 1;
            continue;
        }

        const uchar mask = (uchar)rec->select_type;
        if ((elapsed & 0x100) == 0) {
            obj->selected = (uchar)(obj->selected | mask);
        } else {
            obj->selected = (uchar)(obj->selected & ~mask);
        }
    }
}

void RGE_View::reset_overlay_sprites() {
    // Source of truth: view.cpp.decomp @ 0x0053AC40
    Ov_Sprite_Draw_Rec* cur = this->extra_sprites;
    while (cur != nullptr) {
        Ov_Sprite_Draw_Rec* next = cur->next;
        delete cur;
        cur = next;
    }
    this->extra_sprites = nullptr;
}

void RGE_View::add_overlay_sprite(
    TShape* shape,
    int facet,
    int world_x,
    int world_y,
    int flags,
    int draw_level,
    unsigned char* color_table,
    int display_function,
    unsigned long draw_interval) {
    // Source of truth: view.cpp.decomp @ 0x0053ACD0
    Ov_Sprite_Draw_Rec* rec = new (std::nothrow) Ov_Sprite_Draw_Rec();
    if (rec != nullptr) {
        Ov_Sprite_Draw_Rec* old = this->extra_sprites;
        rec->prev = nullptr;
        rec->next = old;
        if (old != nullptr) {
            old->prev = rec;
        }
        this->extra_sprites = rec;

        rec->theShape = shape;
        rec->thefacet = facet;
        rec->world_x = world_x;
        rec->world_y = world_y;
        rec->flags = flags;
        rec->drawLevel = draw_level;
        rec->colortable = color_table;
        rec->displayfunction = display_function;
        rec->DrawTimeInterval = draw_interval;
        rec->LastDrawTime = 0;
    }
}

long RGE_View::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    // Source of truth: callsites in this codebase use the collapsed 7-arg signature.
    if (param_7 == (uchar)0xA1) {
        return this->setup(param_1, param_2, param_3, param_4, param_5, param_6, 0, 0xA1, (char*)"bordline");
    }
    return this->setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7, 1, (char*)"bordline");
}

long RGE_View::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7, int param_8, char* param_9) {
    // Fully verified. Source of truth: view.cpp.asm @ 0x00533940
    TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
    this->cur_render_area = nullptr;
    this->calc_draw_count = param_8;
    this->start_scr_col = 0;
    this->start_scr_row = 0;
    this->start_map_col = 0;
    this->start_map_row = 0;
    this->last_view_x = -9999.0f;
    this->last_view_y = -9999.0f;
    this->function_mode = 0;

    this->white_pen = GetStockObject(6);
    this->red_pen = CreatePen(0, 1, 0xFF);
    this->hollow_brush = GetStockObject(5);

    char shape_name[260];
    std::sprintf(shape_name, "%s.shp", param_9);
    this->border_line_shape = new (std::nothrow) TShape(shape_name, -1);

    this->Init_Tile_Edge_Tables();

    for (int i = 0; i < 5; ++i) {
        this->pick_lists[i] = (RGE_SPick_Info*)std::calloc(0x40, sizeof(RGE_SPick_Info));
        this->pick_list_size[i] = 0;
    }

    return 1;
}

void RGE_View::Init_Tile_Edge_Tables() {
    // Fully verified. Source of truth: view.cpp.asm @ 0x00533AF0
    constexpr int kTileTypeCount = 0x44 / 4;
    constexpr int kMaskEntryCount = 0x2F;

    int fd = _open("data2\\tileedge.dat", _O_BINARY | _O_RDONLY);
    if (fd != -1) {
        _lseek(fd, 0, SEEK_END);
        const long bytes = _tell(fd);
        this->Tile_Edge_Tables = (Tile_FogEdge_Table**)std::calloc(1, (size_t)bytes);
        _lseek(fd, 0, SEEK_SET);
        _read(fd, this->Tile_Edge_Tables, (unsigned int)bytes);
        _close(fd);

        Tile_FogEdge_Table** tables = this->Tile_Edge_Tables;
        for (int i = 0; i < kTileTypeCount; ++i) {
            Tile_FogEdge_Table** entry = (Tile_FogEdge_Table**)((char*)this->Tile_Edge_Tables + i * 4);
            *entry = (Tile_FogEdge_Table*)((char*)tables + (intptr_t)(*entry));
        }
        for (int i = 0; i < kTileTypeCount; ++i) {
            Tile_FogEdge_Table* rows = *(Tile_FogEdge_Table**)((char*)this->Tile_Edge_Tables + i * 4);
            for (int j = 0; j < kMaskEntryCount; ++j) {
                if (rows[j].normal_draw != nullptr) {
                    rows[j].normal_draw = (VSpanMiniList*)((char*)tables + (intptr_t)rows[j].normal_draw);
                }
                if (rows[j].fog_draw != nullptr) {
                    rows[j].fog_draw = (VSpanMiniList*)((char*)tables + (intptr_t)rows[j].fog_draw);
                }
            }
        }
    }

    fd = _open("data2\\blkedge.dat", _O_BINARY | _O_RDONLY);
    if (fd != -1) {
        _lseek(fd, 0, SEEK_END);
        const long bytes = _tell(fd);
        this->Black_Edge_Tables = (Tile_BlackEdge_Table**)std::calloc(1, (size_t)bytes);
        _lseek(fd, 0, SEEK_SET);
        _read(fd, this->Black_Edge_Tables, (unsigned int)bytes);
        _close(fd);

        Tile_BlackEdge_Table** tables = this->Black_Edge_Tables;
        for (int i = 0; i < kTileTypeCount; ++i) {
            Tile_BlackEdge_Table** entry = (Tile_BlackEdge_Table**)((char*)this->Black_Edge_Tables + i * 4);
            *entry = (Tile_BlackEdge_Table*)((char*)tables + (intptr_t)(*entry));
        }
        for (int i = 0; i < kTileTypeCount; ++i) {
            Tile_BlackEdge_Table* rows = *(Tile_BlackEdge_Table**)((char*)this->Black_Edge_Tables + i * 4);
            for (int j = 0; j < kMaskEntryCount; ++j) {
                if (rows[j].black_UNdraw != nullptr) {
                    rows[j].black_UNdraw = (VSpanMiniList*)((char*)tables + (intptr_t)rows[j].black_UNdraw);
                }
            }
        }
    }

    std::memset(this->EdgeNumber, 0xFF, sizeof(this->EdgeNumber));

    int next_edge = 0;
    for (int i = 0; i < 0x100; ++i) {
        const unsigned char bits = (unsigned char)i;
        bool valid = true;
        const bool c1 = (bits & 0x01) != 0;
        const bool c2 = (bits & 0x02) != 0;
        const bool c4 = (bits & 0x04) != 0;
        const bool c8 = (bits & 0x08) != 0;

        if ((bits & 0x80) != 0 && (c1 || c8)) valid = false;
        if ((bits & 0x40) != 0 && (c4 || c8)) valid = false;
        if ((bits & 0x20) != 0 && (c2 || c4)) valid = false;
        if ((bits & 0x10) != 0 && (c1 || c2)) valid = false;

        if (valid) {
            this->EdgeNumber[i] = (unsigned char)next_edge;
            next_edge++;
        }
    }

    for (unsigned int i = 0; i < 0x100; ++i) {
        if (this->EdgeNumber[i] == 0xFF) {
            unsigned int b1 = i & 0x01;
            unsigned int b2 = i & 0x02;
            unsigned int b4 = i & 0x04;
            unsigned int b8 = i & 0x08;

            if ((i & 0x80) != 0) {
                b8 = 0;
                b1 = 0;
            }
            if ((i & 0x40) != 0) {
                b8 = 0;
                b4 = 0;
            }
            if ((i & 0x20) != 0) {
                b4 = 0;
                b2 = 0;
            }
            if ((i & 0x10) != 0) {
                b2 = 0;
                b1 = 0;
            }

            const unsigned int canonical = (i & 0xF0) | b8 | b4 | b2 | b1;
            this->EdgeNumber[i] = this->EdgeNumber[canonical];
        }
    }
}

void RGE_View::set_rect(tagRECT param_1) {
    // Source of truth: view.cpp.decomp calls through TPanel::set_rect(tagRECT).
    TPanel::set_rect(param_1);
}

void RGE_View::set_rect(long param_1, long param_2, long param_3, long param_4) {
    // Fully verified. Source of truth: view.cpp.asm @ 0x00533F70
    TPanel::set_rect(param_1, param_2, param_3, param_4);
    this->calc_draw_vars();
    this->create_surfaces();

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

    this->Terrain_Clip_Mask = new (std::nothrow) TSpan_List_Manager((int)param_3, (int)param_4);
    this->Terrain_Fog_Clip_Mask = new (std::nothrow) TSpan_List_Manager((int)param_3, (int)param_4);
    this->Master_Clip_Mask = new (std::nothrow) TSpan_List_Manager((int)param_3, (int)param_4);

    if (MouseSystem != nullptr && param_3 > 0 && param_4 > 0) {
        MouseSystem->set_game_window((int)param_1, (int)param_2, (int)(param_3 + param_1), (int)(param_4 + param_2));
        MouseSystem->set_game_mode(1);
    }

    this->set_redraw(TPanel::RedrawMode::RedrawFull);
}

void RGE_View::delete_surfaces() {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00534100
    if (this->save_area1 != nullptr) {
        delete this->save_area1;
        this->save_area1 = nullptr;
    }
}

int RGE_View::create_surfaces() {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00534130
    if (this->pnl_wid == 0 && this->pnl_hgt == 0) {
        return 1;
    }

    if (this->save_area1 == nullptr) {
        this->save_area1 = new (std::nothrow) TDrawArea((char*)"Terrain Buffer");
        if (this->save_area1 != nullptr && this->render_area != nullptr) {
            this->save_area1->Init(this->render_area->DrawSystem, nullptr, (int)this->pnl_wid, (int)this->pnl_hgt, 1, 0, 0);
        }
    }

    if (this->save_area1 != nullptr && 0 < this->pnl_hgt) {
        this->save_area1->SetSize(this->pnl_wid, this->pnl_hgt, 1);
        this->Float_X_Delta = 0;
        this->Float_Y_Delta = 0;
        this->save_area1->SetFloatOffsets(0, 0);

        if (this->prior_objs != nullptr) {
            delete this->prior_objs;
            this->prior_objs = nullptr;
        }
        if (this->futur_objs != nullptr) {
            delete this->futur_objs;
            this->futur_objs = nullptr;
        }

        const int yline = (int)this->pnl_hgt + 0x1C2;
        this->prior_objs = new (std::nothrow) DClipInfo_List(yline * 2, yline, 0x40, -200, (int)this->pnl_hgt + 0xF9, 0x28);
        this->futur_objs = new (std::nothrow) DClipInfo_List(yline * 2, yline, 0x40, -200, (int)this->pnl_hgt + 0xF9, 0x28);

        if (this->prior_objs != nullptr) {
            this->prior_objs->SetDrawRegion(0, 0, (int)this->pnl_wid - 1, (int)this->pnl_hgt - 1);
        }
        if (this->futur_objs != nullptr) {
            this->futur_objs->SetDrawRegion(0, 0, (int)this->pnl_wid - 1, (int)this->pnl_hgt - 1);
        }
    }

    return (this->save_area1 != nullptr) ? 1 : 0;
}

void RGE_View::calc_draw_vars() {
    // Fully verified. Source of truth: view.cpp.asm @ 0x00534340
    if (this->pnl_wid != 0 && this->pnl_hgt != 0 && this->tile_wid != 0 && this->tile_hgt != 0) {
        this->center_scr_col_offset = 0;
        this->center_scr_row_offset = 0;
        this->max_col_num = (short)(this->pnl_wid / (long)this->tile_wid);
        this->max_row_num = (short)(this->pnl_hgt / (long)this->tile_hgt);
        this->center_scr_col = (short)((short)this->pnl_wid - this->tile_half_wid + (short)(this->pnl_wid / 2));
        this->center_scr_row = (short)((short)this->pnl_hgt - this->tile_half_hgt + (short)(this->pnl_hgt / 2));
        return;
    }

    this->max_row_num = 0;
    this->max_col_num = 0;
    this->center_scr_col = 0;
    this->center_scr_row = 0;
    this->center_map_col = 0;
    this->center_map_row = 0;
    this->center_scr_col_offset = 0;
    this->center_scr_row_offset = 0;
}

void RGE_View::set_focus(int param_1) {
    // Fully verified. Source of truth: view.cpp.asm @ 0x00533AC0
    TPanel::set_focus(param_1);
    if (MouseSystem != nullptr) {
        MouseSystem->set_game_enable(this->have_focus);
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
    // Fully verified. Source of truth: view.cpp.decomp @ 0x005359E0.
    if (param_5 == nullptr) {
        return '\0';
    }

    tagPOINT mouse_pos;
    mouse_pos.x = param_3;
    mouse_pos.y = param_4;

    tagPOINT start_mouse_pos;
    start_mouse_pos.x = param_3;
    start_mouse_pos.y = param_4;

    param_5->x = 0.0f;
    param_5->y = 0.0f;
    param_5->scr_x = 0;
    param_5->scr_y = 0;
    param_5->object = nullptr;
    param_5->tile = nullptr;

    void* picked = (param_1 != '(') ? (void*)param_6 : nullptr;
    const long res = this->view_function(param_1, param_2, &mouse_pos, &start_mouse_pos, &picked, &param_5->x, &param_5->y, &param_5->scr_x, &param_5->scr_y);

    const uchar c = (uchar)res;
    if (c == '4') {
        param_5->object = (RGE_Static_Object*)picked;
        return '4';
    }
    if (c == '3') {
        param_5->tile = (RGE_Tile*)picked;
    }
    return c;
}

uchar RGE_View::pick_multi(uchar param_1, long param_2, long param_3, long param_4, long param_5) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00535A80.
    bool picked_any = false;

    if (this->player == nullptr || this->world == nullptr || this->map == nullptr) {
        return '\0';
    }

    int num = this->pick_multi_objects(
        (int)param_2, (int)param_3, (int)param_4, (int)param_5,
        10, 0x14, (int)this->player->id, param_1, 1);

    for (int i = 0; i < num; ++i) {
        int obj_id = Picked_Objects[i].object_id;
        if (obj_id != -1) {
            RGE_Static_Object* obj = this->world->objectsValue[obj_id];
            if ((obj != nullptr) && (obj->object_state < 7)) {
                int ok = this->player->select_one_object(obj, 0);
                if (ok == 0) {
                    break;
                }
                picked_any = true;
            }
        }
    }

    if (picked_any) {
        return '\x01';
    }

    int dx = (int)(param_4 - param_2);
    int dy = (int)(param_5 - param_3);
    int tol = dx;
    if (dy <= dx) {
        tol = dy;
    }
    if (tol < 0x32) {
        tol = dy;
        if (dx < dy) {
            tol = dx;
        }
    } else {
        tol = 0x32;
    }

    int num2 = this->pick_objects((dx / 2) + (int)param_2, (dy / 2) + (int)param_3, 10, 0x14, tol, 4, 1);
    if (num2 != 0) {
        int best_weight = 0;
        RGE_Static_Object* best_obj = nullptr;

        for (int i = 0; i < num2; ++i) {
            int obj_id = Picked_Objects[i].object_id;
            if (obj_id < 0) {
                continue;
            }

            RGE_Static_Object* obj = this->world->objectsValue[obj_id];
            if (obj == nullptr) {
                continue;
            }
            if (obj->object_state >= 7) {
                continue;
            }
            if (obj->master_obj->select_level <= 1) {
                continue;
            }

            if ((this->map->map_visible_flag == '\0') && (this->pick_through_fog(obj) == 0)) {
                int row = (int)obj->world_y;
                int col = (int)obj->world_x;
                uchar vis = this->player->visible->get_visible(col, row);
                if (vis != '\x0f') {
                    continue;
                }
            }

            int w = this->pick_weight(obj, (int)Picked_Objects[i].confidence);
            if (obj->owner == this->player) {
                w += 5;
            }
            if (best_weight < w) {
                best_weight = w;
                best_obj = obj;
            }
        }

        if (best_obj != nullptr) {
            int ok = this->player->select_one_object(best_obj, 0);
            if (ok != 0) {
                return '\x01';
            }
        }
    }

    return '\0';
}

int RGE_View::pick_objects(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x005390D0.
    if (this->prior_objs == nullptr) {
        return 0;
    }

    if ((param_5 < 0) || (param_4 < param_3)) {
        return 0;
    }

    if ((param_1 < this->clip_rect.left) || (this->clip_rect.right < param_1) ||
        (param_2 < this->clip_rect.top) || (this->clip_rect.bottom < param_2) ||
        (0x28 < param_3) || (param_4 < 0)) {
        return 0;
    }

    if (param_3 < 0) {
        param_3 = 0;
    }
    if (0x28 < param_4) {
        param_4 = 0x28;
    }

    int local_x = param_1 - this->clip_rect.left;
    int local_y = param_2 - this->clip_rect.top;

    int num = 0;
    for (int level = param_4; param_3 <= level; --level) {
        for (DClipInfo_Node* node = this->prior_objs->Draw_Level_Head[level]; node != nullptr; node = node->NextOnLevel) {
            int confidence = 0;

            if ((node->Node_Type == 0) && ((param_7 == 0) || (-1 < node->Object_ID))) {
                int node_y1 = (int)node->y1;
                int node_x2 = (int)node->x2;

                if ((local_x < (int)node->x1 - param_5) ||
                    (local_y < node_y1 - param_5) ||
                    (param_5 + node_x2 < local_x) ||
                    ((int)node->y2 + param_5 < local_y)) {
                    confidence = 0;
                } else {
                    confidence = 4;
                    if (((int)node->x1 <= local_x) && (node_y1 <= local_y) &&
                        (local_x <= node_x2) && (local_y <= (int)node->y2)) {
                        confidence = 3;

                        int rel_x;
                        if ((node->Draw_Flag & 2) == 2) {
                            rel_x = node_x2 - local_x;
                        } else {
                            rel_x = local_x - (int)node->x1;
                        }

                        int sc = this->sprite_check(node->Shape_Base, node->Shape, rel_x, local_y - node_y1);
                        if (sc == 1) {
                            confidence = 2;
                        } else if (sc == 2) {
                            confidence = 1;
                        }
                    }
                }
            }

            if ((confidence != 0) && (confidence <= param_6)) {
                int obj_id = node->Object_ID;
                short draw_level = node->y3;

                int found = -1;
                for (int i = 0; i < num; ++i) {
                    if (Picked_Objects[i].object_id == obj_id) {
                        found = i;
                        break;
                    }
                }

                if (found != -1) {
                    short old_conf = Picked_Objects[found].confidence;
                    short old_draw = Picked_Objects[found].draw_level;
                    if ((old_conf < (short)confidence) || ((old_conf == (short)confidence) && (draw_level < old_draw))) {
                        continue;
                    }
                } else {
                    if (num == 0x40) {
                        return 0x40;
                    }
                    found = num++;
                }

                Picked_Objects[found].object_id = obj_id;
                Picked_Objects[found].confidence = (short)confidence;
                Picked_Objects[found].draw_level = draw_level;
                Picked_Objects[found].draw_x = (short)node->Draw_X;
                Picked_Objects[found].draw_y = (short)node->Draw_Y;
            }
        }
    }

    // Sort by (confidence asc, draw_level desc) to match the ordered lists in the original.
    for (int i = 0; i < num - 1; ++i) {
        for (int j = i + 1; j < num; ++j) {
            const RGE_Pick_Obj_Info& a = Picked_Objects[i];
            const RGE_Pick_Obj_Info& b = Picked_Objects[j];
            if ((b.confidence < a.confidence) || ((b.confidence == a.confidence) && (a.draw_level < b.draw_level))) {
                RGE_Pick_Obj_Info tmp = Picked_Objects[i];
                Picked_Objects[i] = Picked_Objects[j];
                Picked_Objects[j] = tmp;
            }
        }
    }

    return num;
}

int RGE_View::pick_multi_objects(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, uchar param_8, int param_9) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x005396F0.
    (void)param_9;

    if (this->prior_objs == nullptr || this->world == nullptr) {
        return 0;
    }

    if ((param_3 < this->clip_rect.left) || (this->clip_rect.right < param_1) ||
        (param_4 < this->clip_rect.top) || (this->clip_rect.bottom < param_2) ||
        (0x28 < param_5) || (param_6 < 0)) {
        return 0;
    }

    if (param_5 < 0) {
        param_5 = 0;
    }
    int level = param_6;
    if (0x28 < param_6) {
        level = 0x28;
    }

    int x1 = param_1 - this->clip_rect.left;
    int x2 = param_3 - this->clip_rect.left;
    int y1 = param_2 - this->clip_rect.top;
    int y2 = param_4 - this->clip_rect.top;

    int num = 0;
    for (; param_5 <= level; --level) {
        DClipInfo_Node* node = this->prior_objs->Draw_Level_Head[level];
        for (; node != nullptr; node = node->NextOnLevel) {
            short conf = 0;
            int obj_id = node->Object_ID;

            if ((node->Node_Type == 0) && (-1 < obj_id)) {
                if ((x1 <= (int)node->x2) && ((int)node->x1 <= x2) && (y1 <= (int)node->y2) && ((int)node->y1 <= y2)) {
                    RGE_Static_Object* obj = this->world->objectsValue[obj_id];
                    if ((obj != nullptr) && ((param_7 == -1) || (obj->owner->id == param_7)) &&
                        (obj->object_state == '\x02') && ((uchar)param_8 <= (uchar)obj->master_obj->select_level)) {
                        conf = 1;
                    }
                }
            }

            if (conf != 0) {
                int found = -1;
                for (int i = 0; i < num; ++i) {
                    if (Picked_Objects[i].object_id == obj_id) {
                        found = i;
                        break;
                    }
                }

                if (found != -1) {
                    if (conf < Picked_Objects[found].confidence) {
                        Picked_Objects[found].confidence = conf;
                    }
                } else {
                    if (num == 0x40) {
                        return 0x40;
                    }
                    Picked_Objects[num].object_id = obj_id;
                    Picked_Objects[num].confidence = conf;
                    Picked_Objects[num].draw_level = conf;
                    Picked_Objects[num].draw_x = (short)node->Draw_X;
                    Picked_Objects[num].draw_y = (short)node->Draw_Y;
                    ++num;
                }
            }
        }
    }

    return num;
}

int RGE_View::sprite_check(uchar* param_1, Shape_Info* param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00539510.
    (void)this;

    if (((param_2 != nullptr) && (-1 < param_3)) &&
        ((param_3 < (int)param_2->Width) && ((-1 < param_4) && (param_4 < (int)param_2->Height)))) {
        int width = (int)param_2->Width;
        int pos = (int)*(short*)(param_1 + param_4 * 4 + param_2->Shape_Outline_Offset);
        if ((-1 < pos) && (pos <= param_3) &&
            (param_3 <= width - *(short*)(param_1 + param_4 * 4 + param_2->Shape_Outline_Offset + 2))) {
            uchar* pb = param_1 + *(int*)(param_1 + param_4 * 4 + param_2->Shape_Data_Offsets);
            if (pos < width) {
                while (pos <= param_3) {
                    uchar b = *pb;
                    uchar* next = pb + 1;

                    switch (b & 0xF) {
                    case 0:
                    case 4:
                    case 8:
                    case 0xC: {
                        pos += (uint)(b >> 2);
                        if (param_3 < pos) {
                            return 2;
                        }
                        next += (b >> 2);
                        break;
                    }
                    case 1:
                    case 5:
                    case 9:
                    case 0xD:
                        pos += (uint)(b >> 2);
                        break;

                    case 2: {
                        uint u = ((uint)b << 4) | (uint)*next;
                        pos += (int)u;
                        if (param_3 < pos) {
                            return 2;
                        }
                        next = pb + u + 2;
                        break;
                    }
                    case 3: {
                        uchar b2 = *next;
                        next = pb + 2;
                        pos += (int)(((uint)b << 4) | (uint)b2);
                        break;
                    }

                    case 6: {
                        uint u = (uint)(b >> 4);
                        if (u == 0) {
                            u = (uint)*next;
                            next = pb + 2;
                        }
                        pos += (int)u;
                        if (param_3 < pos) {
                            return 2;
                        }
                        next += u;
                        break;
                    }
                    case 7:
                    case 0xA: {
                        uint u = (uint)(b >> 4);
                        if (u == 0) {
                            u = (uint)*next;
                            next = pb + 2;
                        }
                        pos += (int)u;
                        if (param_3 < pos) {
                            return 2;
                        }
                        next += 1;
                        break;
                    }
                    case 0xB: {
                        uint u = (uint)(b >> 4);
                        if (u == 0) {
                            u = (uint)*next;
                            next = pb + 2;
                        }
                        pos += (int)u;
                        if (param_3 < pos) {
                            return 2;
                        }
                        break;
                    }

                    case 0xE:
                    case 0xF:
                        return 0;

                    default:
                        return 1;
                    }

                    pb = next;
                    if (width <= pos) {
                        return 1;
                    }
                }
            }
            return 1;
        }
    }

    return 0;
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

int RGE_View::get_tile_screen_coords(short col, short row, short* out_x, short* out_y, int adjust_elev) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00535DA0
    if (out_x != nullptr) {
        *out_x = 0;
    }
    if (out_y != nullptr) {
        *out_y = 0;
    }

    if (this->map == nullptr) {
        return 0;
    }

    if (col < 0 || row < 0 || col >= (short)this->map->map_width || row >= (short)this->map->map_height) {
        return 0;
    }

    RGE_Tile* tile = nullptr;
    if (this->map->map_row_offset != nullptr) {
        tile = this->map->map_row_offset[row] + col;
    }
    if (tile == nullptr) {
        return 0;
    }

    const uchar tile_type = tile->tile_type;
    short scr_y = (short)(this->map->tilesizes[tile_type].y_delta + tile->screen_ypos - (short)this->map_scr_y_offset);

    if (adjust_elev != 0) {
        if (tile_type != 0) {
            scr_y = (short)(scr_y + (short)(this->elev_hgt / 2));
        }
        if (tile_type == 6 || tile_type == 5 || tile_type == 3 || tile_type == 0x0B) {
            scr_y = (short)(scr_y - this->elev_hgt);
        }
    }

    if (out_x != nullptr) {
        *out_x = (short)(tile->screen_xpos - (short)this->map_scr_x_offset);
    }
    if (out_y != nullptr) {
        *out_y = scr_y;
    }
    return 1;
}

void RGE_View::get_center_screen_pos(short* out_y, short* out_x) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00535EB0
    if (out_y != nullptr) {
        *out_y = this->center_scr_row;
    }
    if (out_x != nullptr) {
        *out_x = this->center_scr_col;
    }
}

void RGE_View::get_start_coords(short* out_map_col, short* out_map_row, short* out_scr_x, short* out_scr_y) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00535ED0
    if (out_map_col != nullptr) {
        *out_map_col = this->start_map_col;
    }
    if (out_map_row != nullptr) {
        *out_map_row = this->start_map_row;
    }
    if (out_scr_x != nullptr) {
        *out_scr_x = this->start_scr_col;
    }
    if (out_scr_y != nullptr) {
        *out_scr_y = this->start_scr_row;
    }
}

void RGE_View::get_center_coords(short* out_map_col, short* out_map_row, short* out_scr_x, short* out_scr_y) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00535F20
    if (out_map_col != nullptr) {
        *out_map_col = this->center_map_col;
    }
    if (out_map_row != nullptr) {
        *out_map_row = this->center_map_row;
    }
    if (out_scr_x != nullptr) {
        *out_scr_x = this->center_scr_col;
    }
    if (out_scr_y != nullptr) {
        *out_scr_y = this->center_scr_row;
    }
}

void RGE_View::get_tile_sizes(short* out_tile_wid, short* out_tile_hgt, short* out_half_wid, short* out_half_hgt) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00535F70
    if (out_tile_wid != nullptr) {
        *out_tile_wid = this->tile_wid;
    }
    if (out_tile_hgt != nullptr) {
        *out_tile_hgt = this->tile_hgt;
    }
    if (out_half_wid != nullptr) {
        *out_half_wid = this->tile_half_wid;
    }
    if (out_half_hgt != nullptr) {
        *out_half_hgt = this->tile_half_hgt;
    }
}

long RGE_View::view_function(uchar mode, uchar parm, tagPOINT* mouse_pos, tagPOINT* start_mouse_pos, void** picked, float* out_x, float* out_y, short* out_scr_x, short* out_scr_y) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x00535FE0
    (void)start_mouse_pos;

    this->function_mode = mode;
    this->function_parm = parm;

    if ((mode == '\n') && (this->calc_draw_count != 0) && (this->map != nullptr)) {
        short i = 0;
        while (i < this->map->num_terrain) {
            this->map->terrain_types[i].drawn = '\0';
            i = (short)(i + 1);
        }
    }

    short find_col = 0;
    short find_row = 0;
    if (mode == '<') {
        if (out_x != nullptr) {
            find_col = (short)((long)(*out_x));
        }
        if (out_y != nullptr) {
            find_row = (short)((long)(*out_y));
        }
    }

    RGE_Static_Object* last_picked_obj = nullptr;
    if (picked != nullptr) {
        if ((mode == ')') || (mode == '*') || (mode == '+') || (mode == ',')) {
            last_picked_obj = (RGE_Static_Object*)(*picked);
        }
        *picked = nullptr;
    }

    if (out_x != nullptr) *out_x = 0.0f;
    if (out_y != nullptr) *out_y = 0.0f;
    if (out_scr_x != nullptr) *out_scr_x = 0;
    if (out_scr_y != nullptr) *out_scr_y = 0;

    if (mode == '\x0e') {
        long sel_col1 = 0;
        long sel_row1 = 0;
        long sel_col2 = 0;
        long sel_row2 = 0;
        if (this->get_selection_area(&sel_col1, &sel_row1, &sel_col2, &sel_row2, 1) == 0) {
            return 0;
        }
    }

    if (this->map == nullptr) {
        if ((mode == '(') || (mode == '<') || (mode == ')') || (mode == '*') || (mode == '+') || (mode == ',')) {
            return '2';
        }
        return 0;
    }

    if (mode == '<') {
        if ((0 <= find_col) && (0 <= find_row) &&
            ((int)find_col < this->map->map_width) && ((int)find_row < this->map->map_height) &&
            (this->map->map_row_offset != nullptr)) {
            RGE_Tile* tile = this->map->map_row_offset[find_row] + find_col;
            if (tile != nullptr) {
                short scr_x = 0;
                short scr_y = 0;
                if (this->get_tile_screen_coords(find_col, find_row, &scr_x, &scr_y, 0) != 0) {
                    if (out_x != nullptr) *out_x = (float)((int)find_col);
                    if (out_y != nullptr) *out_y = (float)((int)find_row);
                    if (out_scr_x != nullptr) *out_scr_x = scr_x;
                    if (out_scr_y != nullptr) *out_scr_y = scr_y;
                    if (picked != nullptr) *picked = tile;
                    return '3';
                }
            }
        }
        return '2';
    }

    long picked_type = '2';
    RGE_Static_Object* picked_obj = nullptr;
    short picked_scr_x = 0;
    short picked_scr_y = 0;

    if ((mode == ')') || (mode == '*') || (mode == '+') || (mode == ',')) {
        if ((this->player != nullptr) && (this->world != nullptr) && (mouse_pos != nullptr)) {
            int max_level = 0x28;
            int min_level = 0;
            if (parm != '\0') {
                min_level = 10;
                max_level = 0x14;
            }

            const int num = this->pick_objects((int)mouse_pos->x, (int)mouse_pos->y, min_level, max_level, 0x0f, 4, 1);
            for (int i = 0; i < num; ++i) {
                const int obj_id = Picked_Objects[i].object_id;
                if (obj_id < 0) {
                    continue;
                }

                RGE_Static_Object* obj = this->world->objectsValue[obj_id];
                if ((obj == nullptr) || (obj->object_state >= 7) || (obj->master_obj == nullptr)) {
                    continue;
                }
                if ((uchar)parm > (uchar)obj->master_obj->select_level) {
                    continue;
                }
                if ((this->map->map_visible_flag == '\0') && (this->pick_through_fog(obj) == 0) &&
                    (this->player->visible != nullptr)) {
                    const int row = (int)obj->world_y;
                    const int col = (int)obj->world_x;
                    const uchar vis = this->player->visible->get_visible(col, row);
                    if ((vis != '\x0f') && ((vis != 0x80) || (this->map->fog_flag != '\0'))) {
                        continue;
                    }
                }
                if (this->pick_weight(obj, (int)Picked_Objects[i].confidence) <= 0) {
                    continue;
                }

                if (mode == ',') {
                    picked_type = '4';
                    continue;
                }

                if ((last_picked_obj != nullptr) && (obj == last_picked_obj) && (picked_type == '4')) {
                    if (picked != nullptr) {
                        *picked = picked_obj;
                    }
                    return '4';
                }

                if ((picked_obj == nullptr) || (picked_obj->master_obj == nullptr) ||
                    ((uchar)picked_obj->master_obj->select_level <= (uchar)obj->master_obj->select_level) ||
                    ((picked_obj == last_picked_obj) && (obj != last_picked_obj))) {
                    picked_obj = obj;
                    picked_scr_x = (short)(this->pnl_x + Picked_Objects[i].draw_x);
                    picked_scr_y = (short)(this->pnl_y + Picked_Objects[i].draw_y);
                    if (out_x != nullptr) *out_x = obj->world_x;
                    if (out_y != nullptr) *out_y = obj->world_y;
                    if (out_scr_x != nullptr) *out_scr_x = picked_scr_x;
                    if (out_scr_y != nullptr) *out_scr_y = picked_scr_y;
                    picked_type = '4';
                }
            }
        }

        if (((mode == ')') || (mode == '*') || (mode == '+')) && (picked_type == '4') && (picked != nullptr)) {
            *picked = picked_obj;
        }

        if ((mode != '*') || (picked_type == '4')) {
            return picked_type;
        }
    }

    if ((mode != '(') && (mode != '*')) {
        if ((mode == ')') || (mode == '+') || (mode == ',')) {
            return picked_type;
        }
        return 0;
    }
    if (mouse_pos == nullptr) {
        return '2';
    }
    if ((this->tile_half_wid == 0) || (this->tile_half_hgt == 0)) {
        return '2';
    }

    const float sx = (float)(mouse_pos->x + this->map_scr_x_offset);
    const float sy = (float)(mouse_pos->y + this->map_scr_y_offset);
    const float a = sx / (float)this->tile_half_wid;
    const float b = sy / (float)this->tile_half_hgt;
    const float map_col = (a - b) * 0.5f;
    const float map_row = (a + b) * 0.5f;

    const int col = (int)map_col;
    const int row = (int)map_row;
    if ((col < 0) || (row < 0) || (this->map->map_width <= col) || (this->map->map_height <= row)) {
        return '2';
    }

    RGE_Tile* tile = this->map->get_tile(col, row);
    if (tile == nullptr) {
        return '2';
    }

    if (out_x != nullptr) *out_x = map_col;
    if (out_y != nullptr) *out_y = map_row;
    if (out_scr_x != nullptr) *out_scr_x = (short)(tile->screen_xpos - (short)this->map_scr_x_offset);
    if (out_scr_y != nullptr) *out_scr_y = (short)(tile->screen_ypos - (short)this->map_scr_y_offset);
    if (picked != nullptr) *picked = tile;
    return '3';
}

static void rge_get_mouse_pos(tagPOINT* pt) {
    if (pt == nullptr) return;
    GetCursorPos((POINT*)pt);
    if (rge_base_game != nullptr && rge_base_game->prog_info != nullptr && rge_base_game->prog_info->full_screen == 0) {
        ScreenToClient((HWND)rge_base_game->prog_window, (POINT*)pt);
        if (60000 < (uint)pt->x) pt->x = pt->x - 0x10000;
        if (60000 < (uint)pt->y) pt->y = pt->y - 0x10000;
    }
}

void RGE_View::draw_object_outline() {
    // Fully verified. Source of truth: view.cpp.asm @ 0x00535610
    if (rge_base_game == nullptr) {
        return;
    }

    const short master_id = rge_base_game->master_obj_id;
    if (master_id == (short)-1) {
        return;
    }

    RGE_Player* cur_player = rge_base_game->get_player();
    if ((cur_player == nullptr) || (cur_player->master_objects == nullptr)) {
        return;
    }
    RGE_Master_Static_Object* master = cur_player->master_objects[master_id];
    if (master == nullptr) {
        return;
    }

    tagPOINT point;
    rge_get_mouse_pos(&point);

    if ((point.x < this->render_rect.left) || (this->render_rect.right < point.x) ||
        (point.y < this->render_rect.top) || (this->render_rect.bottom < point.y)) {
        return;
    }

    RGE_Pick_Info pick_info;
    const long local_x = point.x - this->render_rect.left;
    const long local_y = point.y - this->render_rect.top;
    if (this->pick('(', '\0', local_x, local_y, &pick_info, nullptr) != '3') {
        return;
    }

    float world_x = pick_info.x;
    float world_y = pick_info.y;
    master->alignment(&world_x, &world_y, this->world, 0);

    short scr_x = 0;
    short scr_y = 0;
    if (this->get_tile_screen_coords((short)world_x, (short)world_y, &scr_x, &scr_y, 1) == 0) {
        return;
    }

    short ab_x4 = 0;
    short ab_local_12 = 0;
    short ab_scr_y = 0;
    short ab_y3 = 0;
    short ab_y4 = 0;
    short ab_y1 = 0;
    short ab_x2 = 0;
    short ab_local_4[2] = { 0, 0 };
    master->alignment_box(this->world, world_x, world_y,
                          &ab_x4, &ab_local_12, &ab_scr_y,
                          &ab_y3, &ab_y4, &ab_y1, &ab_x2, ab_local_4);

    const uchar place_ok = master->check_placement(cur_player, world_x, world_y, nullptr, 1, master->elevation_flag, 0, 1, 1, 1);
    fog_next_shape = 1;
    if (place_ok == '\0') {
        fog_next_shape = 5;
    } else {
        const uint phase = (this->world->world_time >> 7) & 7;
        const int base = (phase < 4) ? (int)(phase + 0x24) : (int)(0x2C - phase);
        fog_next_shape = (base << 4) | 9;
    }

    int center_x_delta = (int)(short)ab_x4 - (int)(short)ab_y4;
    center_x_delta = (center_x_delta - (center_x_delta >> 31)) >> 1;
    const int center_x = (int)(short)ab_y4 + center_x_delta + (int)scr_x;

    int center_y_delta = (int)(short)ab_y3 - (int)(short)ab_local_4[0];
    center_y_delta = (center_y_delta - (center_y_delta >> 31)) >> 1;
    const int center_y = (int)(short)ab_local_4[0] + center_y_delta + (int)scr_y;

    if (master->sprite != nullptr) {
        SDI_Draw_Line = center_y;
        const int draw_flag = (int)(master->draw_flag & 1);
        const uchar draw_color = (place_ok == '\0') ? master->draw_color : (uchar)0x97;

        long draw_facet = 0;
        RGE_Color_Table* draw_color_table = nullptr;
        if ((rge_base_game->game_mode == 8) && (rge_base_game->sub_game_mode == 1) &&
            (this->movable_object != nullptr) && (this->movable_object->owner != nullptr)) {
            draw_facet = (long)(uint)this->movable_object->facet;
            draw_color_table = this->movable_object->owner->color_table;
        } else {
            RGE_Player* draw_player = rge_base_game->get_player();
            if (draw_player != nullptr) {
                draw_color_table = draw_player->color_table;
            }
        }

        master->draw(this->render_area, (short)center_x, (short)center_y, draw_color_table, draw_facet, 0L, draw_flag, draw_color);
    }

    fog_next_shape = 0;
}

void RGE_View::draw_paint_brush() {
    // Fully verified. Source of truth: view.cpp.asm @ 0x005358B0
    this->set_selection_area(-1, -1, -1, -1);

    if (rge_base_game == nullptr) {
        return;
    }

    tagPOINT point;
    rge_get_mouse_pos(&point);
    if ((point.x < this->render_rect.left) || (this->render_rect.right < point.x) ||
        (point.y < this->render_rect.top) || (this->render_rect.bottom < point.y)) {
        return;
    }

    RGE_Pick_Info pick_info;
    if (this->pick('(', '\0', point.x, point.y, &pick_info, nullptr) != '3') {
        return;
    }

    short brush_size = 0;
    if (rge_base_game->game_mode == 0x13) {
        const int snap_col = (int)(pick_info.x * kView_Cliff_Brush_Snap_Scale);
        const int snap_row = (int)(pick_info.y * kView_Cliff_Brush_Snap_Scale);
        pick_info.x = 1.0f + (float)(snap_col * 3);
        pick_info.y = 1.0f + (float)(snap_row * 3);
        brush_size = 3;
    } else {
        brush_size = (short)rge_base_game->brush_size;
    }

    const int col = (int)pick_info.x;
    const int row = (int)pick_info.y;
    const int half = ((int)brush_size >> 1);
    this->set_selection_area(col - half, row - half, col + half, row + half);
}

void RGE_View::draw()
{
    tiles_drawn = 0;
    s_view_debug_masked_draws = 0;
    s_view_debug_fog_masked_draws = 0;
    s_view_debug_fallback_draws = 0;
    if (view_debug_redraw_all != 0) {
        this->render_terrain_mode = 0;
        view_debug_redraw_all = 0;
    }
    if (view_debug_ObstructionMap != 0 || view_debug_palette != 0) {
        this->render_terrain_mode = 0;
    }

    if (this->world == nullptr) {
        CUSTOM_DEBUG_BEGIN
        if (s_view_debug_draw_logs < 12) {
            CUSTOM_DEBUG_LOG("RGE_View::draw: world is null, clearing render area");
            s_view_debug_draw_logs++;
        }
        CUSTOM_DEBUG_END
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

    // Source of truth: view.cpp.decomp uses save_area1 as the terrain draw target.
    // save_area1 is panel-local; it is copied into render_area at panel coordinates after draw.
    TDrawArea* terrain_target = (this->save_area1 != nullptr) ? this->save_area1 : this->render_area;

    if (this->render_terrain_mode == 0) {
        this->Float_X_Delta = 0;
        this->Float_Y_Delta = 0;
        if (this->save_area1) {
            this->save_area1->SetFloatOffsets(0, 0);
            this->save_area1->Clear(&this->save_area1->ClipRect, 0);
        }
    }

    if (terrain_target != nullptr) {
        terrain_target->Clear(&terrain_target->ClipRect, 0);
    }

    this->draw_view(10, terrain_target); // 10 is terrain mode

    if (terrain_target == this->save_area1 && this->render_area != nullptr) {
        tagRECT src;
        src.left = 0;
        src.top = 0;
        src.right = this->pnl_wid - 1;
        src.bottom = this->pnl_hgt - 1;
        this->save_area1->Copy(this->render_area, this->pnl_x, this->pnl_y, &src, 0);
    }

    CUSTOM_DEBUG_BEGIN
    if (s_view_debug_draw_logs < 12 || (frame_count % 120) == 0) {
        CUSTOM_DEBUG_LOG_FMT(
            "RGE_View::draw: frame=%d tiles_drawn=%d mask_draws=%d fog_mask_draws=%d fallback_draws=%d world=%p map=%p player=%p start=(%d,%d) map_offset=(%d,%d)",
            frame_count,
            tiles_drawn,
            s_view_debug_masked_draws,
            s_view_debug_fog_masked_draws,
            s_view_debug_fallback_draws,
            this->world,
            this->map,
            this->player,
            (int)this->start_map_col,
            (int)this->start_map_row,
            (int)this->map_scr_x_offset,
            (int)this->map_scr_y_offset);
        if (s_view_debug_draw_logs < 12) {
            s_view_debug_draw_logs++;
        }
    }
    CUSTOM_DEBUG_END

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
    } else {
        CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("RGE_View::draw_view: Lock failed mode=%u area=%p", (unsigned)mode, area);
        CUSTOM_DEBUG_END
    }
    this->cur_render_area = nullptr;
}

long RGE_View::view_function_terrain(uchar mode, tagRECT rect)
{
    (void)mode;

    if (0 < this->DispSel_List_Size) {
        this->update_display_selected_objects();
    }

    if (this->map == nullptr || this->cur_render_area == nullptr || this->map->map_row_offset == nullptr) {
        CUSTOM_DEBUG_BEGIN
        if (s_view_debug_terrain_logs < 12) {
            CUSTOM_DEBUG_LOG_FMT(
                "RGE_View::view_function_terrain: early return map=%p cur_render=%p rows=%p",
                this->map,
                this->cur_render_area,
                (this->map != nullptr) ? this->map->map_row_offset : nullptr);
            s_view_debug_terrain_logs++;
        }
        CUSTOM_DEBUG_END
        return 0;
    }

    int col_num = (int)this->start_map_col;
    int row_num = (int)this->start_map_row;
    const int cols_to_scan = (int)this->max_col_num + 5;
    const int rows_to_scan = (int)this->max_row_num * 2 + 0x0C;
    const int map_w = this->map->map_width;
    const int map_h = this->map->map_height;
    const int tile_visible_mask =
        (this->player == nullptr || this->player->visible == nullptr || this->map->map_visible_flag != 0) ? 1 : 0;
    const ulong explored_mask = (this->player != nullptr) ? this->player->mutualExploredMask : 0;
    const ulong visible_mask = (this->player != nullptr) ? this->player->mutualVisibleMask : 0;
    constexpr int kEdgeTileTypeCount = 17;
    int in_bounds_tiles = 0;
    int clip_visible_tiles = 0;
    int vis_nonzero_tiles = 0;
    int terrain_candidates = 0;
    int tile_type_hist[19];
    int terrain_id_hist[32];
    std::memset(tile_type_hist, 0, sizeof(tile_type_hist));
    std::memset(terrain_id_hist, 0, sizeof(terrain_id_hist));
    int draw_min_x = 0x7FFFFFFF;
    int draw_min_y = 0x7FFFFFFF;
    int draw_max_x = -0x7FFFFFFF;
    int draw_max_y = -0x7FFFFFFF;

    if (this->Terrain_Clip_Mask != nullptr) {
        this->Terrain_Clip_Mask->SetSpanRegions(rect.left, rect.top, rect.right, rect.bottom);
    }
    if (this->Terrain_Fog_Clip_Mask != nullptr) {
        this->Terrain_Fog_Clip_Mask->SetSpanRegions(rect.left, rect.top, rect.right, rect.bottom);
    }

    for (int scan_row = 0; scan_row < rows_to_scan; ++scan_row) {
        int map_col = col_num;
        int map_row = row_num;

        for (int scan_col = 0; scan_col < cols_to_scan; ++scan_col) {
            if (map_col >= 0 && map_row >= 0 && map_col < map_w && map_row < map_h) {
                in_bounds_tiles++;
                RGE_Tile* tile = &this->map->map_row_offset[map_row][map_col];
                int sx = (int)tile->screen_xpos - this->map_scr_x_offset;
                int sy = (int)tile->screen_ypos - this->map_scr_y_offset;

                unsigned int tt = (unsigned int)tile->tile_type;
                if (tt < 19u) {
                    int ex = sx + (int)this->map->tilesizes[tt].width;
                    int ey = sy + (int)this->map->tilesizes[tt].height;
                    if (!(ex < rect.left || sx > rect.right || ey < rect.top || sy > rect.bottom)) {
                        clip_visible_tiles++;
                        uchar map_vis = 0;
                        ulong tile_offset = 0;
                        if (map_row >= 0 && map_row < 256 && unified_map_offsets[map_row] != nullptr && map_col >= 0) {
                            tile_offset = unified_map_offsets[map_row][map_col];
                        }

                        if ((tile_offset & visible_mask) == 0) {
                            if ((explored_mask & tile_offset) != 0 || tile_visible_mask != 0) {
                                map_vis = (this->map->fog_flag != 0) ? (uchar)0x80 : (uchar)0x0F;
                            } else {
                                map_vis = 0;
                                tile->last_drawn_as = 0;
                            }
                        } else {
                            map_vis = 0x0F;
                        }

                        if (map_vis == 0 &&
                            this->player != nullptr &&
                            this->player->visible != nullptr &&
                            this->player->visible->numberTilesExploredValue == 0) {
                            map_vis = 0x0F;
                        }

                        if (map_vis != 0) {
                            vis_nonzero_tiles++;
                            uchar terrain_to_draw = (uchar)(tile->terrain_type & 0x1F);
                            if ((int)terrain_to_draw < this->map->num_terrain) {
                                terrain_candidates++;
                                if ((int)tt >= 0 && (int)tt < 19) {
                                    tile_type_hist[(int)tt]++;
                                }
                                if ((int)terrain_to_draw >= 0 && (int)terrain_to_draw < 32) {
                                    terrain_id_hist[(int)terrain_to_draw]++;
                                }
                                short override_terrain = this->map->terrain_types[terrain_to_draw].terrain_to_draw;
                                if (override_terrain != -1 && override_terrain >= 0 && override_terrain < this->map->num_terrain) {
                                    terrain_to_draw = (uchar)override_terrain;
                                }

                                int tile_mask_num = 0;
                                int clip_to = 0;
                                if (this->Tile_Edge_Tables != nullptr && this->Black_Edge_Tables != nullptr &&
                                    (int)tile->tile_type >= 0 && (int)tile->tile_type < kEdgeTileTypeCount) {
                                    int black_tile_mask_num = 0;
                                    if (map_vis == 0x0F && this->map->fog_flag != 0) {
                                        black_tile_mask_num = this->get_tile_mask_num(map_col, map_row, map_w, map_h, visible_mask);
                                    }

                                    int explored_tile_mask_num = 0;
                                    if (tile_visible_mask == 0 && map_vis != 0) {
                                        explored_tile_mask_num = this->get_tile_mask_num(map_col, map_row, map_w, map_h, explored_mask);
                                    }

                                    Tile_FogEdge_Table* edge_table = this->Tile_Edge_Tables[tile->tile_type];
                                    Tile_BlackEdge_Table* black_edge_table = this->Black_Edge_Tables[tile->tile_type];
                                    if (edge_table != nullptr) {
                                        VSpanMiniList* normal_draw_data = edge_table[black_tile_mask_num].normal_draw;
                                        VSpanMiniList* fog_draw_data = edge_table[black_tile_mask_num].fog_draw;
                                        VSpanMiniList* black_undraw_data = nullptr;
                                        if (black_edge_table != nullptr && explored_tile_mask_num >= 0) {
                                            black_undraw_data = black_edge_table[explored_tile_mask_num].black_UNdraw;
                                        }

                                        if (map_vis == 0x80) {
                                            fog_draw_data = edge_table[0].normal_draw;
                                            clip_to = (fog_draw_data != nullptr) ? 1 : 0;
                                            tile_mask_num = 0;
                                        } else {
                                            tile_mask_num = (normal_draw_data != nullptr) ? 1 : 0;
                                            clip_to = (fog_draw_data != nullptr) ? 1 : 0;
                                        }

                                        const int has_black_clip =
                                            (explored_tile_mask_num >= 1 && black_undraw_data != nullptr) ? 1 : 0;

                                        if (tile_mask_num != 0 && this->Terrain_Clip_Mask != nullptr) {
                                            this->Terrain_Clip_Mask->AddMiniList(normal_draw_data, sx, sy);
                                        }
                                        if (clip_to != 0 && this->Terrain_Fog_Clip_Mask != nullptr) {
                                            this->Terrain_Fog_Clip_Mask->AddMiniList(fog_draw_data, sx, sy);
                                        }
                                        if (has_black_clip != 0) {
                                            if (tile_mask_num != 0 && this->Terrain_Clip_Mask != nullptr) {
                                                this->Terrain_Clip_Mask->SubtractMiniList(black_undraw_data, sx, sy);
                                            }
                                            if (clip_to != 0 && this->Terrain_Fog_Clip_Mask != nullptr) {
                                                this->Terrain_Fog_Clip_Mask->SubtractMiniList(black_undraw_data, sx, sy);
                                            }
                                        }
                                    }
                                }

                                tile->last_drawn_as = map_vis;
                                tile->draw_as = map_vis;
                                tile->draw_attribute = (uchar)(tile->draw_attribute & 0xBF);
                                this->draw_tile(
                                    tile,
                                    terrain_to_draw,
                                    (short)sx,
                                    (short)sy,
                                    (short)map_col,
                                    (short)map_row,
                                    map_vis,
                                    tile_mask_num,
                                    clip_to);
                                tiles_drawn = tiles_drawn + 1;

                                int ex_draw = sx + (int)this->map->tilesizes[tt].width;
                                int ey_draw = sy + (int)this->map->tilesizes[tt].height;
                                if (sx < draw_min_x) draw_min_x = sx;
                                if (sy < draw_min_y) draw_min_y = sy;
                                if (ex_draw > draw_max_x) draw_max_x = ex_draw;
                                if (ey_draw > draw_max_y) draw_max_y = ey_draw;

                                // Source of truth: view.cpp.decomp @ 0x00536B40 (RGE_View::view_function_terrain)
                                // calls RGE_Object_List::draw(&tile->objects, ...).
                                if (tile->objects.list != nullptr) {
                                    if (map_vis != 0x0F) {
                                        fog_next_shape = 1;
                                    }
                                    short obj_y = (short)(sy + (int)tile->height * (int)this->tile_half_hgt);
                                    tile->objects.draw(
                                        this->cur_render_area,
                                        (short)sx,
                                        obj_y,
                                        (uchar)(map_vis == 0x80));
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

    if (rge_base_game != nullptr) {
        const int gm = rge_base_game->game_mode;
        if (gm == 1 || ((6 < gm) && (gm < 9))) {
            this->draw_object_outline();
        }
        if (gm == 0x15) {
            this->draw_paint_brush();
        }
    }

    CUSTOM_DEBUG_BEGIN
    if (s_view_debug_terrain_logs < 12 || tiles_drawn == 0 || (frame_count % 120) == 0) {
        CUSTOM_DEBUG_LOG_FMT(
            "RGE_View::view_function_terrain: map=%ldx%ld scan=%dx%d in_bounds=%d clip=%d vis=%d terrain_ok=%d tiles_drawn=%d bbox=(%d,%d)-(%d,%d) player=%p",
            (long)map_w,
            (long)map_h,
            cols_to_scan,
            rows_to_scan,
            in_bounds_tiles,
            clip_visible_tiles,
            vis_nonzero_tiles,
            terrain_candidates,
            tiles_drawn,
            (draw_min_x == 0x7FFFFFFF) ? -1 : draw_min_x,
            (draw_min_y == 0x7FFFFFFF) ? -1 : draw_min_y,
            draw_max_x,
            draw_max_y,
            this->player);
        if (s_view_debug_terrain_logs < 4) {
            CUSTOM_DEBUG_LOG_FMT(
                "RGE_View::terrain_hist tt0=%d tt1=%d tt2=%d tt3=%d tt4=%d tt5=%d terr0=%d terr1=%d terr2=%d terr3=%d terr4=%d terr5=%d",
                tile_type_hist[0],
                tile_type_hist[1],
                tile_type_hist[2],
                tile_type_hist[3],
                tile_type_hist[4],
                tile_type_hist[5],
                terrain_id_hist[0],
                terrain_id_hist[1],
                terrain_id_hist[2],
                terrain_id_hist[3],
                terrain_id_hist[4],
                terrain_id_hist[5]);
        }
        if (s_view_debug_terrain_logs < 12) {
            s_view_debug_terrain_logs++;
        }
    }
    CUSTOM_DEBUG_END

    return 0;
}

int RGE_View::get_tile_mask_num(int param_1, int param_2, int param_3, int param_4, ulong param_5)
{
    // Fully verified. Source of truth: view.cpp.asm @ 0x00538590
    uint mask_bits = 0;

    if ((((param_1 < 1) || (param_2 < 1)) || (param_3 - 1 <= param_1)) || (param_4 - 1 <= param_2)) {
        if ((0 < param_1) && ((unified_map_offsets[param_2][param_1 - 1] & param_5) == 0)) {
            mask_bits = 0x10;
        }

        int max_col = param_3 - 1;
        if ((param_1 < max_col) && ((unified_map_offsets[param_2][param_1 + 1] & param_5) == 0)) {
            mask_bits |= 0x40;
        }

        if ((0 < param_2) && ((unified_map_offsets[param_2 - 1][param_1] & param_5) == 0)) {
            mask_bits |= 0x80;
        }

        int max_row = param_4 - 1;
        if ((param_2 < max_row) && ((unified_map_offsets[param_2 + 1][param_1] & param_5) == 0)) {
            mask_bits |= 0x20;
        }

        if (0 < param_1) {
            if ((0 < param_2) && ((unified_map_offsets[param_2 - 1][param_1 - 1] & param_5) == 0)) {
                mask_bits |= 0x01;
            }
            if ((param_2 < max_row) && ((unified_map_offsets[param_2 + 1][param_1 - 1] & param_5) == 0)) {
                mask_bits |= 0x02;
            }
        }

        if (param_1 < max_col) {
            if ((0 < param_2) && ((unified_map_offsets[param_2 - 1][param_1 + 1] & param_5) == 0)) {
                mask_bits |= 0x08;
            }
            if ((param_2 < max_row) && ((unified_map_offsets[param_2 + 1][param_1 + 1] & param_5) == 0)) {
                mask_bits |= 0x04;
            }
        }
    } else {
        unsigned long* row_above = unified_map_offsets[param_2 - 1];
        if ((row_above[param_1] & param_5) == 0) {
            mask_bits = 0x80;
        }

        unsigned long* row = unified_map_offsets[param_2];
        if ((row[param_1 + 1] & param_5) == 0) {
            mask_bits |= 0x40;
        }

        unsigned long* row_below = unified_map_offsets[param_2 + 1];
        if ((row_below[param_1] & param_5) == 0) {
            mask_bits |= 0x20;
        }
        if ((row[param_1 - 1] & param_5) == 0) {
            mask_bits |= 0x10;
        }
        if ((row_above[param_1 + 1] & param_5) == 0) {
            mask_bits |= 0x08;
        }
        if ((row_below[param_1 + 1] & param_5) == 0) {
            mask_bits |= 0x04;
        }
        if ((row_below[param_1 - 1] & param_5) == 0) {
            mask_bits |= 0x02;
        }
        if ((row_above[param_1 - 1] & param_5) == 0) {
            mask_bits |= 0x01;
        }
    }

    return (uint)this->EdgeNumber[mask_bits];
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
        CUSTOM_DEBUG_BEGIN
        static int s_draw_tile_dbg = 0;
        static unsigned char s_draw_tile_seen_terr[32] = {0};
        if (s_draw_tile_dbg < 24) {
            CUSTOM_DEBUG_LOG_FMT(
                "draw_tile dbg terr=%u tile_type=%u pic=%d terr_shape=%p border_type=%u border_shape_ptr=%p draw_border=%d draw_terrain=%d map_vis=%u",
                (unsigned)vis,
                (unsigned)tile->tile_type,
                (int)pic,
                block->shape,
                (unsigned)border_type,
                (border_type < 16) ? this->map->border_types[border_type].shape : nullptr,
                draw_border,
                draw_terrain,
                (unsigned)fog);
            s_draw_tile_dbg++;
        }
        if ((unsigned)vis < 32u && s_draw_tile_seen_terr[(unsigned)vis] == 0) {
            s_draw_tile_seen_terr[(unsigned)vis] = 1;
            int shp_count = -1;
            if (block->shape != nullptr) {
                shp_count = (int)block->shape->shape_count();
            }
            CUSTOM_DEBUG_LOG_FMT(
                "draw_tile terr_meta terr=%u name='%s' pict='%s' resid=%ld rows=%d cols=%d t0(count=%d anim=%d idx=%d) shape_count=%d",
                (unsigned)vis,
                block->name,
                block->pict_name,
                block->resource_id,
                (int)block->rows,
                (int)block->cols,
                (int)block->tiles[0].count,
                (int)block->tiles[0].animations,
                (int)block->tiles[0].shape_index,
                shp_count);
        }
        CUSTOM_DEBUG_END
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
        (void)shape->shape_draw(this->cur_render_area, x - hotspot_x, y - hotspot_y, frame, 0, nullptr);
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
        (void)shape->shape_draw(this->cur_render_area, x, y, frame, 0, nullptr);
        s_view_debug_fog_masked_draws++;
        fog_next_shape = 0;
    }

    if ((fog & 0xA0) != 0) {
        fog_next_shape = 1;
    }

    if (param_7 != 0) {
        this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
        (void)shape->shape_draw(this->cur_render_area, x, y, frame, 0, nullptr);
        s_view_debug_masked_draws++;
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

bool RGE_View::Object_Was_Displayed(long object_id, bool include_flagged)
{
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053AD50
    DClipInfo_Node* node = this->prior_objs->LocateIDbyDrawLevel((int)object_id, 6, 0x28, 0);
    if (node == nullptr) {
        return false;
    }
    if ((!include_flagged) && ((node->Draw_Flag & 1) != 0)) {
        return false;
    }
    return true;
}
