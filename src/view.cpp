#include <windows.h>
#include "../include/program_mode.h"
#include <ddraw.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>

#include "../include/asp_list.h"
#include "../include/basegame.h"
#include "../include/drawarea.h"
#include "../include/Shape.h"
#include "../include/game_globals.h"
#include "../include/map.h"
#include "../include/m_s_obj.h"
#include "../include/Mouseptr.h"
#include "../include/obj_list.h"
#include "../include/panel.h"
#include "../include/pathsys.h"
#include "../include/player.h"
#include "../include/pnl_msg.h"
#include "../include/rge_base_game_global.h"
#include "../include/stat_obj.h"
#include "../include/sprite.h"
#include "../include/visible.h"
#include "../include/view.h"
#include "../include/asm_draw.h"
#include "../include/world.h"

static const char s_C__msdev_work_age1_x1_view_cpp[] = "C:\\msdev\\work\\age1_x1\\view.cpp";

class Tile_FogEdge_Table {
  public:
    VSpanMiniList* normal_draw;
    VSpanMiniList* fog_draw;
};

class Tile_BlackEdge_Table {
  public:
    VSpanMiniList* black_UNdraw;
};

class Blit_Queue_Entry {
  public:
    tagRECT src;
    tagRECT dest;
};

class DisplaySelectedObjRec {
  public:
    int active;
    int id;
    unsigned long start_time;
    unsigned long duration;
    int select_type;
};

class Ov_Sprite_Draw_Rec {
  public:
    Ov_Sprite_Draw_Rec* next;
    Ov_Sprite_Draw_Rec* prev;
    TShape* theShape;
    int thefacet;
    int world_x;
    int world_y;
    int flags;
    int drawLevel;
    int displayfunction;
    unsigned long LastDrawTime;
    unsigned long DrawTimeInterval;
    unsigned char* colortable;
};

class RGE_SPick_Info {
  public:
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
    RGE_SPick_Info* next;
    RGE_SPick_Info* prev;
};

RGE_View::RGE_View() {
    this->cur_render_area = 0;
    this->calc_draw_count = 0;
    this->world = 0;
    this->player = 0;
    this->map = 0;
    this->tile_wid = 0;
    this->tile_hgt = 0;
    this->tile_half_hgt = 0;
    this->tile_half_wid = 0;
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
    this->save_area1 = 0;
    this->save_paint_terrain = -1;
    this->white_pen = 0;
    this->red_pen = 0;
    this->hollow_brush = 0;
    this->border_line_shape = 0;
    this->scroll_action = 0;
    this->mouse_last_x = -1;
    this->mouse_last_y = -1;
    this->movable_object = 0;
    this->set_selection_area(-1, -1, -1, -1);
    this->Terrain_Clip_Mask = 0;
    this->Terrain_Fog_Clip_Mask = 0;
    this->Master_Clip_Mask = 0;
    this->LastRenderBits = 0;
    this->RenderOffsets = 0;
    this->LastRenderSize = 0;
    this->Tile_Edge_Tables = 0;
    this->Black_Edge_Tables = 0;
    this->Float_X_Delta = 0;
    this->Float_Y_Delta = 0;
    this->Float_Scroll_Offsets = 0;
    this->Float_Scroll_Offsets_Sz = 0;
    this->Queued_Blits = 0;
    this->Blit_Queue = 0;
    this->Blit_Queue_Size = 0;
    this->Current_Blit = 0;
    this->Blit_Offset_X = 0;
    this->Blit_Offset_Y = 0;
    this->prior_objs = 0;
    this->futur_objs = 0;
    for (int i = 0; i < 5; i++) {
        this->pick_lists[i] = 0;
        this->pick_list_size[i] = 0;
    }
    this->UC_ObjectTouched = 0;
    this->UC_TouchedObj = 0x80000000;
    this->UC_StartTime = 0;
    this->UC_ElapsedTime = 0;
    this->message_panel = 0;
    this->extra_sprites = 0;
    this->DispSel_List_Size = 0;
    this->DispSel_List_Max = 8;
    this->DispSel_List = (DisplaySelectedObjRec*) calloc(8, sizeof(DisplaySelectedObjRec));
}

RGE_View::~RGE_View() {
    TShape* shape = this->border_line_shape;
    if (shape != 0) {
        delete shape;
        this->border_line_shape = 0;
    }

    this->delete_surfaces();

    if (this->red_pen != 0) {
        DeleteObject(this->red_pen);
        this->red_pen = 0;
    }

    if (this->RenderOffsets != 0) {
        free(this->RenderOffsets);
    }

    TSpan_List_Manager* span = this->Terrain_Clip_Mask;
    if (span != 0) {
        delete span;
    }
    span = this->Terrain_Fog_Clip_Mask;
    if (span != 0) {
        delete span;
    }
    span = this->Master_Clip_Mask;
    if (span != 0) {
        delete span;
    }

    if (this->Tile_Edge_Tables != 0)
        free(this->Tile_Edge_Tables);
    if (this->Black_Edge_Tables != 0)
        free(this->Black_Edge_Tables);
    if (this->Float_Scroll_Offsets != 0)
        free(this->Float_Scroll_Offsets);
    if (this->Blit_Queue != 0)
        free(this->Blit_Queue);

    DClipInfo_List* clip = this->prior_objs;
    if (clip != 0) {
        delete clip;
    }
    clip = this->futur_objs;
    if (clip != 0) {
        delete clip;
    }

    for (int i = 0; i < 5; ++i) {
        if (this->pick_lists[i] != 0) {
            free(this->pick_lists[i]);
        }
    }

    if (MouseSystem != 0) {
        MouseSystem->set_game_mode(0);
        MouseSystem->set_game_enable(0);
    }

    if (this->DispSel_List != 0)
        free(this->DispSel_List);

    this->reset_overlay_sprites();
    this->TPanel::~TPanel();
}

long RGE_View::setup(
    TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in, long wid_in, long hgt_in,
    unsigned char color_in, int calc_draw_count_in, char* border_line_file
) {
    char str[260];

    TPanel::setup(render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, color_in);

    this->cur_render_area = 0;
    this->calc_draw_count = calc_draw_count_in;
    this->start_scr_col = 0;
    this->start_scr_row = 0;
    this->start_map_col = 0;
    this->start_map_row = 0;
    this->last_view_x = -9999.0f;
    this->last_view_y = -9999.0f;
    this->function_mode = 0;

    this->white_pen = GetStockObject(WHITE_PEN);
    this->red_pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
    this->hollow_brush = GetStockObject(HOLLOW_BRUSH);

    sprintf(str, "%s.shp", border_line_file);
    this->border_line_shape = new TShape(str, -1);

    this->Init_Tile_Edge_Tables();

    int i = 5;
    do {
        int index = 5 - i;
        this->pick_lists[index] = (RGE_SPick_Info*) calloc(64, sizeof(RGE_SPick_Info));
        this->pick_list_size[index] = 0;
        i--;
    } while (i != 0);

    return 1;
}

void RGE_View::set_focus(int have_focus_in) {
    this->TPanel::set_focus(have_focus_in);
    if (MouseSystem != 0) {
        MouseSystem->set_game_enable(this->have_focus);
    }
}

static const char s_tile_file[] = "DATA2\\TILEEDGE.DAT";
static const char s_black_tile_file[] = "DATA2\\BLKEDGE.DAT";

void RGE_View::Init_Tile_Edge_Tables() {
    int fd, len;
    int i, j;
    Tile_FogEdge_Table* fog_table;
    Tile_BlackEdge_Table* black_table;
    int base;
    int count;
    int ok;

    fd = _open(s_tile_file, _O_BINARY);
    if (fd != -1) {
        _lseek(fd, 0, SEEK_END);
        len = _tell(fd);
        this->Tile_Edge_Tables = (Tile_FogEdge_Table**) calloc(1, len);
        _lseek(fd, 0, SEEK_SET);
        _read(fd, this->Tile_Edge_Tables, len);
        _close(fd);
        base = (int) this->Tile_Edge_Tables;
        for (i = 0; i < 0x11; i++)
            this->Tile_Edge_Tables[i] = (Tile_FogEdge_Table*) ((unsigned char*) this->Tile_Edge_Tables[i] + base);
        for (i = 0; i < 0x11; i++) {
            fog_table = this->Tile_Edge_Tables[i];
            for (j = 0; j < 0x2f; j++) {
                if (fog_table[j].normal_draw)
                    fog_table[j].normal_draw = (VSpanMiniList*) ((unsigned char*) fog_table[j].normal_draw + base);
                if (fog_table[j].fog_draw)
                    fog_table[j].fog_draw = (VSpanMiniList*) ((unsigned char*) fog_table[j].fog_draw + base);
            }
        }
    }
    fd = _open(s_black_tile_file, _O_BINARY);
    if (fd != -1) {
        _lseek(fd, 0, SEEK_END);
        len = _tell(fd);
        this->Black_Edge_Tables = (Tile_BlackEdge_Table**) calloc(1, len);
        _lseek(fd, 0, SEEK_SET);
        _read(fd, this->Black_Edge_Tables, len);
        _close(fd);
        base = (int) this->Black_Edge_Tables;
        for (i = 0; i < 0x11; i++)
            this->Black_Edge_Tables[i] = (Tile_BlackEdge_Table*) ((unsigned char*) this->Black_Edge_Tables[i] + base);
        for (i = 0; i < 0x11; i++) {
            black_table = this->Black_Edge_Tables[i];
            for (j = 0; j < 0x2f; j++) {
                if (black_table[j].black_UNdraw)
                    black_table[j].black_UNdraw =
                        (VSpanMiniList*) ((unsigned char*) black_table[j].black_UNdraw + base);
            }
        }
    }
    uchar* edge = this->EdgeNumber;
    for (i = 0; i < 0x100; i++)
        edge[i] = 0xff;
    count = 0;
    i = 0;
    do {
        int b0, b1, b2, b3, b4, b5, b6, b7;
        ok = 1;
        b0 = (i & 1) == 1;
        b1 = (i & 2) == 2;
        b2 = (i & 4) == 4;
        b3 = (i & 8) == 8;
        b4 = (i & 0x10) == 0x10;
        b5 = (i & 0x20) == 0x20;
        b6 = (i & 0x40) == 0x40;
        b7 = (i & 0x80) == 0x80;
        if (b7 && (b0 || b3))
            ok = 0;
        if (b6 && (b2 || b3))
            ok = 0;
        if (b5 && (b1 || b2))
            ok = 0;
        if (b4 && (b0 || b1))
            ok = 0;
        if (ok)
            edge[i] = (uchar) count++;
        i++;
    } while (i < 0x100);
    i = 0;
    do {
        if (edge[i] == 0xff) {
            int b0, b1, b2, b3, b4, b5, b6, b7;
            b0 = i & 1;
            b1 = i & 2;
            b2 = i & 4;
            b3 = i & 8;
            b4 = i & 0x10;
            b5 = i & 0x20;
            b6 = i & 0x40;
            b7 = i & 0x80;
            if (b7) {
                b3 = 0;
                b0 = 0;
            }
            if (b6) {
                b3 = 0;
                b2 = 0;
            }
            if (b5) {
                b2 = 0;
                b1 = 0;
            }
            if (b4) {
                b1 = 0;
                b0 = 0;
            }
            edge[i] = edge[b7 | b6 | b5 | b4 | b3 | b2 | b1 | b0];
        }
        i++;
    } while (i < 0x100);
}

extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

void RGE_View::update_display_selected_objects(void) {
    unsigned long curTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\view.cpp", 715);
    int i = 0;

    if (this->DispSel_List_Max <= 0)
        return;

    {
        do {
            DisplaySelectedObjRec* entry = &this->DispSel_List[i];
            if (entry->active) {
                RGE_Static_Object* obj;
                obj = this->world->objectsValue[entry->id];
                if (obj == 0) {
                    entry->active = 0;
                    this->DispSel_List_Size = this->DispSel_List_Size - 1;
                } else {
                    unsigned long elapsed = curTime - entry->start_time;
                    if (elapsed > entry->duration) {
                        entry->active = 0;
                        this->DispSel_List_Size = this->DispSel_List_Size - 1;
                    } else if (!(elapsed & 0x100)) {
                        obj->selected = obj->selected | (unsigned char) entry->select_type;
                        goto next_entry;
                    }
                    obj->selected = obj->selected & ~(unsigned char) entry->select_type;
                }
            }
        next_entry:
            ++i;
        } while (i < this->DispSel_List_Max);
    }
}

void RGE_View::display_object_selection(int id, int duration, int select_type, int reset_type) {
    int found = 0;
    int i = 0;
    DisplaySelectedObjRec* n;

    if (this->DispSel_List_Max > 0) {
        int key = reset_type;

        do {
            DisplaySelectedObjRec* entry = &this->DispSel_List[i];
            if (entry->active == 0) {
                found = 1;
                n = entry;
            } else if (key != 0 && entry->select_type == key) {
                entry->start_time -= entry->duration;
            }
            i++;
        } while (i < this->DispSel_List_Max);
    }

    if (found) {
        n->active = 1;
        n->id = id;
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\view.cpp", 797);
        n->start_time = now;
        n->duration = duration;
        n->select_type = select_type;
        this->DispSel_List_Size++;
    }
}

void RGE_View::set_rect(long x_in, long y_in, long wid_in, long hgt_in) {
    this->TPanel::set_rect(x_in, y_in, wid_in, hgt_in);
    this->calc_draw_vars();
    this->create_surfaces();

    this->last_view_x = -9999.0f;
    this->last_view_y = -9999.0f;

    delete this->Terrain_Clip_Mask;
    delete this->Terrain_Fog_Clip_Mask;
    delete this->Master_Clip_Mask;

    this->Terrain_Clip_Mask = new TSpan_List_Manager(wid_in, hgt_in);
    this->Terrain_Fog_Clip_Mask = new TSpan_List_Manager(wid_in, hgt_in);
    this->Master_Clip_Mask = new TSpan_List_Manager(wid_in, hgt_in);

    if (MouseSystem != 0 && wid_in > 0 && hgt_in > 0) {
        MouseSystem->set_game_window(x_in, y_in, x_in + wid_in, y_in + hgt_in);
        MouseSystem->set_game_mode(1);
    }

    this->set_redraw(TPanel::RedrawImmediate);
}

void RGE_View::delete_surfaces(void) {
    TDrawArea* area;

    area = save_area1;
    if (area != 0) {
        delete area;
        save_area1 = 0;
    }
}

int RGE_View::create_surfaces() {
    if (this->pnl_wid == 0 && this->pnl_hgt == 0) {
        return 1;
    }

    if (this->save_area1 == 0) {
        TDrawArea* area = new TDrawArea("Terrain Buffer", 0);
        this->save_area1 = area;
        if (area != 0) {
            area->Init(this->render_area->DrawSystem, this->pnl_wid, this->pnl_hgt, 1, 0);
        }
    }

    if (this->save_area1 != 0 && this->pnl_hgt > 0) {
        this->save_area1->SetSize(this->pnl_wid, this->pnl_hgt, 1);
        this->Float_X_Delta = 0;
        this->Float_Y_Delta = 0;
        this->save_area1->SetFloatOffsets(0, 0);

        DClipInfo_List* p = this->prior_objs;
        if (p != 0) {
            delete p;
        }
        p = this->futur_objs;
        if (p != 0) {
            delete p;
        }

        int v = this->pnl_hgt + 0x1c2;
        this->prior_objs = new DClipInfo_List(v + v, v, 0x40, -200, this->pnl_hgt + 0xf9, 0x28);
        this->futur_objs = new DClipInfo_List(v + v, v, 0x40, -200, this->pnl_hgt + 0xf9, 0x28);

        this->prior_objs->SetDrawRegion(0, 0, this->pnl_wid - 1, this->pnl_hgt - 1);
        this->futur_objs->SetDrawRegion(0, 0, this->pnl_wid - 1, this->pnl_hgt - 1);
    }

    return this->save_area1 != 0;
}

void RGE_View::calc_draw_vars() {
    if (this->visible != 0 && this->tile_wid != 0 && this->tile_hgt != 0) {
        this->center_scr_col_offset = 0;
        this->max_col_num = (short) (this->pnl_wid / (int) this->tile_wid);
        this->center_scr_row_offset = 0;
        this->max_row_num = (short) (this->pnl_hgt / (int) this->tile_hgt);
        this->center_scr_col = (short) this->render_rect.left - this->tile_half_wid + (short) (this->pnl_wid / 2);
        this->center_scr_row = (short) this->render_rect.top - this->tile_half_hgt + (short) (this->pnl_hgt / 2);
    } else {
        this->max_row_num = 0;
        this->max_col_num = 0;
        this->center_scr_col = 0;
        this->center_scr_row = 0;
        this->center_map_col = 0;
        this->center_map_row = 0;
        this->center_scr_col_offset = 0;
        this->center_scr_row_offset = 0;
    }
}

void RGE_View::set_redraw(TPanel::RedrawMode redraw_mode) {
    this->TPanel::set_redraw(redraw_mode);
    if (redraw_mode == 2) {
        render_terrain_mode = 0;
    }
}

void RGE_View::set_world(RGE_Game_World* world_in) {
    this->world = world_in;
    if (world_in != 0) {
        map = world_in->map;
        map->coordinate_map();
        tile_wid = map->tile_width;
        tile_hgt = map->tile_height;
        tile_half_wid = map->tile_half_width;
        tile_half_hgt = map->tile_half_height;
        elev_hgt = map->elev_height;
    } else {
        map = 0;
        tile_wid = 0;
        tile_hgt = 0;
        tile_half_wid = 0;
        tile_half_hgt = 0;
        elev_hgt = 0;
    }
    calc_draw_vars();
}

void RGE_View::set_player(RGE_Player* player_in) {
    this->player = player_in;
    last_view_x = -9999.0f;
    last_view_y = -9999.0f;
    set_redraw(TPanel::RedrawImmediate);
}

void RGE_View::set_selection_area(long sel_col1_in, long sel_row1_in, long sel_col2_in, long sel_row2_in) {
    if (this->map && rge_base_game->game_mode != 0x15) {
        this->map->request_redraw(this->sel_col1, this->sel_row1, this->sel_col2, this->sel_row2, 0);
    }
    this->sel_col1 = sel_col1_in;
    this->sel_row1 = sel_row1_in;
    this->sel_col2 = sel_col2_in;
    this->sel_row2 = sel_row2_in;
    if (this->map && rge_base_game->game_mode != 0x15) {
        this->map->request_redraw(sel_col1_in, sel_row1_in, sel_col2_in, sel_row2_in, 0x10);
    }
    this->set_redraw(TPanel::RedrawNormal);
}

int RGE_View::get_selection_area(
    long& sel_col1_in, long& sel_row1_in, long& sel_col2_in, long& sel_row2_in, int fix_coords
) {
    sel_col1_in = this->sel_col1;
    sel_row1_in = this->sel_row1;
    sel_col2_in = this->sel_col2;
    sel_row2_in = this->sel_row2;

    if (sel_col1_in == -1 && sel_row1_in == -1 && sel_col2_in == -1 && sel_row2_in == -1) {
        return 0;
    }

    if (sel_col1_in < 0) {
        sel_col1_in = 0;
    } else if (sel_col1_in >= this->map->map_width) {
        sel_col1_in = this->map->map_width - 1;
    }

    if (sel_row1_in < 0) {
        sel_row1_in = 0;
    } else if (sel_row1_in >= this->map->map_height) {
        sel_row1_in = this->map->map_height - 1;
    }

    if (sel_col2_in < 0) {
        sel_col2_in = 0;
    } else if (sel_col2_in >= this->map->map_width) {
        sel_col2_in = this->map->map_width - 1;
    }

    if (sel_row2_in < 0) {
        sel_row2_in = 0;
    } else if (sel_row2_in >= this->map->map_height) {
        sel_row2_in = this->map->map_height - 1;
    }

    if (fix_coords) {
        long c1 = sel_col1_in;
        long c2 = sel_col2_in;
        long r1 = sel_row1_in;
        long r2 = sel_row2_in;

        sel_col1_in = (c1 < c2) ? c1 : c2;
        sel_row1_in = (r1 < r2) ? r1 : r2;
        sel_col2_in = (c1 > c2) ? c1 : c2;
        sel_row2_in = (r1 > r2) ? r1 : r2;
    }

    return 1;
}

void RGE_View::CreateBlitQueue(tagRECT& src_rect, tagRECT& dest_rect, int xDelta, int yDelta) {
    int one_blit = 0;
    int nBlits;
    int One_Blit;
    int blt_deltaX = 0;
    int blt_deltaY = 0;
    tagRECT blt_src;

    if (xDelta == 0 && yDelta == 0)
        return;

    if (src_rect.top > dest_rect.bottom || src_rect.left > dest_rect.right || src_rect.bottom < dest_rect.top
        || src_rect.right < dest_rect.left) {
        one_blit = 1;
        nBlits = 1;
    } else {
        int width = src_rect.right - src_rect.left + 1;
        int height = src_rect.bottom - src_rect.top + 1;
        int yd = yDelta;
        int xd = xDelta;

        if (yd < 0)
            yd = -yd;
        if (xd < 0)
            xd = -xd;

        One_Blit = 9999;
        nBlits = 9999;
        if (yDelta != 0)
            One_Blit = (yd + height - 1) / yd;
        if (xDelta != 0)
            nBlits = (xd + width - 1) / xd;

        blt_src = src_rect;
        if (One_Blit < nBlits) {
            nBlits = One_Blit;
            blt_deltaY = yDelta;
            if (yDelta < 0)
                blt_src.top = yDelta + src_rect.bottom + 1;
            else
                blt_src.bottom = yDelta + src_rect.top - 1;
        } else {
            blt_deltaX = xDelta;
            if (xDelta < 0)
                blt_src.left = xDelta + src_rect.right + 1;
            else
                blt_src.right = xDelta + src_rect.left - 1;
        }
    }

    if (this->Blt_Queue_Allocated < nBlits) {
        if (this->Blit_Queue != 0)
            free(this->Blit_Queue);
        this->Blit_Queue = 0;
    }

    if (this->Blit_Queue == 0) {
        this->Blit_Queue = (Blit_Queue_Entry*) calloc(nBlits, 32);
        this->Blt_Queue_Allocated = nBlits;
    }

    if (one_blit) {
        Blit_Queue_Entry* entry = this->Blit_Queue;
        entry->src.left = src_rect.left;
        entry->src.top = src_rect.top;
        entry->src.right = src_rect.right;
        entry->src.bottom = src_rect.bottom;
        entry->dest.left = dest_rect.left;
        entry->dest.top = dest_rect.top;
        entry->dest.right = dest_rect.right;
        entry->dest.bottom = dest_rect.bottom;
    } else if (nBlits > 0) {
        int offset = 0;
        int count = nBlits;

        do {
            Blit_Queue_Entry* entry = (Blit_Queue_Entry*) ((unsigned char*) this->Blit_Queue + offset);

            entry->src.left = blt_src.left;
            entry->src.top = blt_src.top;
            entry->src.right = blt_src.right;
            entry->src.bottom = blt_src.bottom;
            entry->dest.top = blt_src.top - yDelta;
            entry->dest.left = blt_src.left - xDelta;
            entry->dest.bottom = blt_src.bottom - yDelta;
            entry->dest.right = blt_src.right - xDelta;

            blt_src.top += blt_deltaY;
            blt_src.bottom += blt_deltaY;
            blt_src.left += blt_deltaX;
            blt_src.right += blt_deltaX;

            if (blt_src.top < src_rect.top)
                blt_src.top = src_rect.top;
            if (blt_src.left < src_rect.left)
                blt_src.left = src_rect.left;
            if (blt_src.right > src_rect.right)
                blt_src.right = src_rect.right;
            if (blt_src.bottom > src_rect.bottom)
                blt_src.bottom = src_rect.bottom;

            offset += 0x20;
            --count;
        } while (count != 0);
    }

    this->Queued_Blits = 1;
    this->Blit_Queue_Size = nBlits;
    this->Current_Blit = -1;
    this->Blit_Offset_X = this->render_rect.left;
    this->Blit_Offset_Y = this->render_rect.top;
}

void RGE_View::ProcessQueuedBlit(int WaitIfBusy) {
    tagRECT src;

    if (this->Queued_Blits != 0) {
        if (WaitIfBusy == 0 && this->render_area->DrawSurface->GetBltStatus(1) != 0) {
            return;
        }

        this->Current_Blit++;
        if (this->Blit_Queue != 0 && this->Current_Blit >= 0 && this->Current_Blit < this->Blit_Queue_Size) {
            Blit_Queue_Entry* entry = &this->Blit_Queue[this->Current_Blit];

            src.left = entry->src.left + this->Blit_Offset_X;
            src.top = entry->src.top + this->Blit_Offset_Y;
            src.right = entry->src.right + this->Blit_Offset_X + 1;
            src.bottom = entry->src.bottom + this->Blit_Offset_Y + 1;

            this->render_area->DrawSurface->BltFast(
                entry->dest.left + this->Blit_Offset_X, entry->dest.top + this->Blit_Offset_Y,
                this->render_area->DrawSurface, &src, 0x10
            );

            if (this->Current_Blit + 1 < this->Blit_Queue_Size) {
                return;
            }
        }

        this->Queued_Blits = 0;
    }
}

void RGE_View::draw() {
    short old_start_map_col;
    short old_start_map_row;
    short old_start_scr_col;
    short old_start_scr_row;
    int old_map_scr_x_offset;
    int old_map_scr_y_offset;
    short x_diff;
    short y_diff;
    tagRECT old_rect;
    tagRECT new_rect;
    tagRECT clip_rect1;
    tagRECT clip_rect2;

    tiles_drawn = 0;

    if (view_debug_redraw_all != 0) {
        this->render_terrain_mode = 0;
        view_debug_redraw_all = 0;
    }
    if (view_debug_ObstructionMap != 0 || view_debug_palette != 0) {
        this->render_terrain_mode = 0;
    }

    if (this->world == 0) {
        this->draw_setup(0);
        this->render_area->Clear(&this->clip_rect, this->color);
        this->draw_finish();
        return;
    }

    old_start_scr_row = this->start_scr_row;
    old_start_map_row = this->start_map_row;
    old_start_scr_col = this->start_scr_col;
    old_start_map_col = this->start_map_col;

    this->Terrain_Clip_Mask->ResetAll();
    this->Terrain_Fog_Clip_Mask->ResetAll();
    this->Master_Clip_Mask->ResetAll();

    old_map_scr_y_offset = this->map_scr_y_offset;
    old_map_scr_x_offset = this->map_scr_x_offset;
    this->Use_Rect2 = 0;
    this->Limited_Render_Rect = 0;

    this->update();
    this->draw_setup(0);

    if (this->render_terrain_mode == 1
        && (this->start_map_col != old_start_map_col || this->start_map_row != old_start_map_row
            || this->start_scr_col != old_start_scr_col || this->start_scr_row != old_start_scr_row)) {
        x_diff = (short) ((short) this->map_scr_x_offset - (short) old_map_scr_x_offset);
        y_diff = (short) ((short) this->map_scr_y_offset - (short) old_map_scr_y_offset);

        if (x_diff != 0 || y_diff != 0) {
            int adjust;

            old_rect.left = 0;
            old_rect.top = 0;
            old_rect.right = this->pnl_wid - 1;
            old_rect.bottom = this->pnl_hgt - 1;

            new_rect.left = x_diff;
            new_rect.top = y_diff;
            new_rect.right = old_rect.right + x_diff;
            new_rect.bottom = old_rect.bottom + y_diff;

            if (new_rect.bottom < 0 || new_rect.right < 0 || old_rect.bottom < new_rect.top
                || old_rect.right < new_rect.left) {
                this->render_terrain_mode = 0;
            } else {
                if ((x_diff & 7) != 0) {
                    adjust = new_rect.left;
                    if (x_diff <= 0) {
                        adjust += 7;
                    }
                    adjust = (adjust & ~7) - new_rect.left;
                    x_diff = (short) (x_diff + adjust);
                    this->map_scr_x_offset += adjust;
                }

                if ((y_diff & 7) != 0) {
                    adjust = new_rect.top;
                    if (y_diff <= 0) {
                        adjust += 7;
                    }
                    adjust = (adjust & ~7) - new_rect.top;
                    y_diff = (short) (y_diff + adjust);
                    this->map_scr_y_offset += adjust;
                }

                if (x_diff < 0) {
                    old_rect.left = 0;
                    old_rect.right = this->pnl_wid + x_diff - 1;
                    new_rect.left = -x_diff;
                    new_rect.right = this->pnl_wid - 1;
                } else {
                    old_rect.left = x_diff;
                    old_rect.right = this->pnl_wid - 1;
                    new_rect.left = 0;
                    new_rect.right = this->pnl_wid - x_diff - 1;
                }

                if (y_diff < 0) {
                    old_rect.top = 0;
                    old_rect.bottom = this->pnl_hgt + y_diff - 1;
                    new_rect.top = -y_diff;
                    new_rect.bottom = this->pnl_hgt - 1;
                } else {
                    old_rect.top = y_diff;
                    old_rect.bottom = this->pnl_hgt - 1;
                    new_rect.top = 0;
                    new_rect.bottom = this->pnl_hgt - y_diff - 1;
                }

                if (this->render_area->DrawSystem->DrawType == 1 || this->render_area->UsingVidMem == 0) {
                    this->render_area->OverlayMemCopy(
                        old_rect, new_rect, x_diff, y_diff, this->render_rect.left, this->render_rect.top
                    );
                    this->Queued_Blits = 0;
                } else {
                    this->CreateBlitQueue(old_rect, new_rect, x_diff, y_diff);
                    if (MouseSystem != 0) {
                        MouseSystem->Poll();
                    }
                    if (this->Queued_Blits != 0) {
                        this->ProcessQueuedBlit(0);
                    }
                }

                this->prior_objs->Scroll(x_diff, y_diff);

                this->Float_X_Delta += x_diff;
                if (this->Float_X_Delta >= this->save_area1->Width) {
                    if (this->save_area1->Lock("view::draw", 1) != 0) {
                        memcpy(
                            this->save_area1->DisplayOffsets[0],
                            (unsigned char*) this->save_area1->DisplayOffsets[this->save_area1->Height - 1]
                                + this->save_area1->Width,
                            this->Float_X_Delta - x_diff
                        );
                        this->Float_X_Delta -= this->save_area1->Width;
                        this->Float_Y_Delta++;
                        if (this->Float_Y_Delta >= this->save_area1->Height) {
                            this->Float_Y_Delta = 0;
                        }
                        this->save_area1->Unlock("view::draw");
                    }
                } else if (this->Float_X_Delta < 0) {
                    if (this->save_area1->Lock("view::draw2", 1) != 0) {
                        this->Float_X_Delta += this->save_area1->Width;
                        this->Float_Y_Delta--;
                        if (this->Float_Y_Delta < 0) {
                            this->Float_Y_Delta = this->save_area1->Height - 1;
                        }
                        memcpy(
                            (unsigned char*) this->save_area1->DisplayOffsets[this->save_area1->Height - 1]
                                + this->save_area1->Width,
                            this->save_area1->DisplayOffsets[0], this->Float_X_Delta
                        );
                        this->save_area1->Unlock("view::draw3");
                    }
                }

                this->Float_Y_Delta += y_diff;
                if (this->Float_Y_Delta < 0) {
                    this->Float_Y_Delta += this->save_area1->Height;
                }
                if (this->Float_Y_Delta >= this->save_area1->Height) {
                    this->Float_Y_Delta -= this->save_area1->Height;
                }
                this->save_area1->SetFloatOffsets(this->Float_X_Delta, this->Float_Y_Delta);

                if (new_rect.left == 0 && new_rect.right == this->pnl_wid - 1) {
                    clip_rect1.left = -1;
                    if (new_rect.top == 0 && new_rect.bottom == this->pnl_hgt - 1) {
                        clip_rect2.left = -1;
                    } else {
                        clip_rect2.left = 0;
                        clip_rect2.right = this->pnl_wid - 1;
                        if (new_rect.top == 0) {
                            clip_rect2.top = new_rect.bottom + 1;
                            clip_rect2.bottom = this->pnl_hgt - 1;
                        } else {
                            clip_rect2.top = 0;
                            clip_rect2.bottom = new_rect.top - 1;
                        }
                    }
                } else if (new_rect.left == 0) {
                    clip_rect1.left = new_rect.right + 1;
                    clip_rect1.top = 0;
                    clip_rect1.right = this->pnl_wid - 1;
                    clip_rect1.bottom = this->pnl_hgt - 1;
                    if (new_rect.top == 0 && new_rect.bottom == this->pnl_hgt - 1) {
                        clip_rect2.left = -1;
                    } else {
                        clip_rect2.left = 0;
                        if (new_rect.top == 0) {
                            clip_rect2.top = new_rect.bottom + 1;
                            clip_rect2.right = new_rect.right;
                            clip_rect2.bottom = this->pnl_hgt - 1;
                        } else {
                            clip_rect2.top = 0;
                            clip_rect2.right = new_rect.right;
                            clip_rect2.bottom = new_rect.top - 1;
                        }
                    }
                } else {
                    clip_rect1.left = 0;
                    clip_rect1.top = 0;
                    clip_rect1.right = new_rect.left - 1;
                    clip_rect1.bottom = this->pnl_hgt - 1;
                    if (new_rect.top == 0 && new_rect.bottom == this->pnl_hgt - 1) {
                        clip_rect2.left = -1;
                    } else {
                        clip_rect2.left = new_rect.left;
                        if (new_rect.top == 0) {
                            clip_rect2.top = new_rect.bottom + 1;
                            clip_rect2.right = this->pnl_wid - 1;
                            clip_rect2.bottom = this->pnl_hgt - 1;
                        } else {
                            clip_rect2.top = 0;
                            clip_rect2.right = this->pnl_wid - 1;
                            clip_rect2.bottom = new_rect.top - 1;
                        }
                    }
                }

                if (clip_rect1.left != -1) {
                    this->save_area1->PtrClear(&clip_rect1, 0);
                    this->Limited_Render_Rect = 1;
                    this->Render_Rect1 = clip_rect1;
                }
                if (clip_rect2.left != -1) {
                    this->save_area1->PtrClear(&clip_rect2, 0);
                    if (clip_rect1.left == -1) {
                        this->Limited_Render_Rect = 1;
                        this->Render_Rect1 = clip_rect2;
                    } else {
                        this->Use_Rect2 = 1;
                        this->Render_Rect2 = clip_rect2;
                    }
                }
            }
        }
    }

    if (MouseSystem != 0) {
        MouseSystem->Poll();
    }
    if (this->Queued_Blits != 0) {
        this->ProcessQueuedBlit(0);
    }

    int game_mode = rge_base_game->game_mode;
    if ((game_mode >= 9 && game_mode <= 10) || game_mode == 0x13) {
        this->draw_paint_brush();
    }

    if (this->render_terrain_mode == 0) {
        this->Float_X_Delta = 0;
        this->Float_Y_Delta = 0;
        this->save_area1->SetFloatOffsets(0, 0);
        this->save_area1->PtrClear(&this->save_area1->ClipRect, 0);
    }

    this->draw_view(10, this->save_area1);
    this->render_terrain_mode = 1;
    this->draw_finish();
    frame_count++;
}

void RGE_View::update() {
    RGE_Player* view_player = this->player;

    if (view_player == 0 || (view_player->view_x == this->last_view_x && view_player->view_y == this->last_view_y)) {
        return;
    }

    this->center_map_col = (short) view_player->view_x;
    this->center_map_row = (short) view_player->view_y;
    this->last_view_x = view_player->view_x;
    this->last_view_y = view_player->view_y;

    float view_x_fraction = view_player->view_x - (float) this->center_map_col;
    float view_y_fraction = view_player->view_y - (float) this->center_map_row;

    this->center_scr_col = (short) (this->render_rect.left + this->pnl_wid / 2 - this->tile_half_wid);
    this->center_scr_row = (short) (this->render_rect.top + this->pnl_hgt / 2 - this->tile_half_hgt);

    int screen_col_adjust = (int) ((view_x_fraction * g_view_tile_fraction_scale) * this->tile_wid
                                   + (view_y_fraction * g_view_tile_fraction_scale) * this->tile_wid);
    screen_col_adjust = -screen_col_adjust;

    int screen_row_adjust = (int) ((view_y_fraction * g_view_tile_fraction_scale) * this->tile_hgt
                                   - (view_x_fraction * g_view_tile_fraction_scale) * this->tile_hgt);
    screen_row_adjust = -screen_row_adjust - this->tile_half_hgt;

    this->center_scr_col = (short) (this->center_scr_col + screen_col_adjust);
    this->center_scr_row = (short) (this->center_scr_row + screen_row_adjust);

    RGE_Tile* center_tile = this->map->map_row_offset[this->center_map_row] + this->center_map_col;
    this->map_scr_x_offset = (int) center_tile->screen_xpos - (int) this->center_scr_col;
    this->map_scr_y_offset =
        (int) center_tile->screen_ypos + (int) center_tile->height * this->elev_hgt - (int) this->center_scr_row;

    this->center_scr_col_offset =
        (this->center_map_col + this->center_map_row) * this->tile_half_wid + screen_col_adjust;
    this->center_scr_row_offset =
        (this->center_map_row - this->center_map_col) * this->tile_half_hgt + screen_row_adjust;

    int col_adjust = this->max_col_num / 2 + 2;
    this->start_map_row = (short) (this->center_map_row - col_adjust);
    this->start_map_col = (short) (this->center_map_col - col_adjust);
    this->start_scr_col = (short) (this->center_scr_col - col_adjust * this->tile_half_wid * 2);

    int row_adjust = this->max_row_num / 2 + 1;
    this->start_map_col = (short) (this->start_map_col + row_adjust);
    this->start_map_row = (short) (this->start_map_row - row_adjust);
    this->start_scr_row = (short) (this->center_scr_row - row_adjust * this->tile_half_hgt * 2);
}

void RGE_View::draw_view(unsigned char function_mode_in, TDrawArea* draw_area_in) {
    if (draw_area_in == 0)
        this->cur_render_area = this->render_area;
    else
        this->cur_render_area = draw_area_in;

    {
        tagRECT save_render_rect;
        if (this->cur_render_area == this->save_area1) {
            save_render_rect.left = this->render_rect.left;
            save_render_rect.right = this->render_rect.right;
            save_render_rect.top = this->render_rect.top;
            save_render_rect.bottom = this->render_rect.bottom;

            this->render_rect.left -= save_render_rect.left;
            this->start_scr_col -= (short) save_render_rect.left;
            this->start_scr_row -= (short) save_render_rect.top;
            this->render_rect.top -= save_render_rect.top;
            this->render_rect.right -= save_render_rect.left;
            this->render_rect.bottom -= save_render_rect.top;
            this->map_scr_x_offset += save_render_rect.left;
            this->map_scr_y_offset += save_render_rect.top;
        }
        if (this->cur_render_area->Lock("view::draw_view", 1)) {
            if (function_mode_in == 10) {
                this->view_function_terrain(10, save_render_rect);
            } else {
                this->view_function(function_mode_in, 0, 0, 0, 0, 0, 0, 0, 0);
            }
            this->cur_render_area->Unlock("view::draw_view");
        }
        if (this->cur_render_area == this->save_area1) {
            this->start_scr_col += (short) save_render_rect.left;
            this->start_scr_row += (short) save_render_rect.top;
            this->render_rect.right += save_render_rect.left;
            this->render_rect.bottom += save_render_rect.top;
            this->render_rect.left += save_render_rect.left;
            this->render_rect.top += save_render_rect.top;
            this->map_scr_x_offset -= save_render_rect.left;
            this->map_scr_y_offset -= save_render_rect.top;
        }
    }
    this->cur_render_area = 0;
}

void RGE_View::draw_object_outline() {
    short placement;
    short x1;
    short y1;
    short x2;
    short y2;
    short x3;
    short y3;
    short x4;
    short y4;
    short scr_x;
    short scr_y;
    unsigned char frame_color;
    tagPOINT point;
    RGE_Pick_Info pick_info;

    short master_obj_id = rge_base_game->master_obj_id;
    if (master_obj_id == -1)
        return;

    RGE_Player* player = rge_base_game->get_player();
    RGE_Master_Static_Object* master = player->master_objects[(int) master_obj_id];
    if (master == 0)
        return;

    rge_base_game->get_mouse_pos(point);
    if (point.x < this->render_rect.left || point.x > this->render_rect.right || point.y < this->render_rect.top
        || point.y > this->render_rect.bottom)
        return;

    unsigned short pick_result = (unsigned char) this->pick(
        0x28, 0, point.x - this->render_rect.left, point.y - this->render_rect.top, &pick_info, 0
    );
    if (pick_result != 0x33)
        return;

    master->alignment(pick_info.x, pick_info.y, this->world, 0);
    if (this->get_tile_screen_coords((short) pick_info.x, (short) pick_info.y, &scr_x, &scr_y, 1) == 0)
        return;

    master->alignment_box(this->world, pick_info.x, pick_info.y, x1, y1, x2, y2, x3, y3, x4, y4);

    placement = (unsigned char) master->check_placement(
        rge_base_game->get_player(), pick_info.x, pick_info.y, 0, 1, master->elevation_flag, 0, 1, 1, 1
    );
    fog_next_shape = 1;
    if (placement == 0) {
        fog_next_shape = 5;
    } else {
        unsigned int shape = (this->world->world_time >> 7) & 7;
        if (shape < 4)
            shape += 0x24;
        else
            shape = 0x2C - shape;
        fog_next_shape = (shape << 4) | 9;
    }

    scr_x += ((int) x1 - (int) x3) / 2 + x3;
    scr_y += ((int) y2 - (int) y4) / 2 + y4;

    if (master->sprite != 0) {
        SDI_Draw_Line = (int) scr_y;
        int draw_flag = master->draw_flag & 1;

        if (placement == 0)
            frame_color = master->draw_color;
        else
            frame_color = 0x97;

        if (rge_base_game->game_mode == 8 && rge_base_game->sub_game_mode == 1 && this->movable_object != 0) {
            RGE_Static_Object* movable = this->movable_object;
            master->draw(
                this->render_area, scr_x, scr_y, movable->owner->color_table, movable->facet, 0, draw_flag, frame_color
            );
        } else {
            master->draw(
                this->render_area, scr_x, scr_y, rge_base_game->get_player()->color_table, 0, 0, draw_flag, frame_color
            );
        }
    }

    fog_next_shape = 0;
}

void RGE_View::draw_paint_brush() {
    tagPOINT point;
    RGE_Pick_Info pick_info;

    set_selection_area(-1, -1, -1, -1);

    rge_base_game->get_mouse_pos(point);

    if (point.x < this->render_rect.left || point.x > this->render_rect.right || point.y < this->render_rect.top
        || point.y > this->render_rect.bottom)
        return;

    unsigned short pickResult = (unsigned char) pick(0x28, 0, point.x, point.y, &pick_info, 0);

    if (pickResult != '3')
        return;

    short brushSize;
    if (rge_base_game->game_mode == 0x13) {
        int t1 = (int) (pick_info.x * (1.0f / 3.0f));
        int v1 = -t1 * 3;
        pick_info.x = 1.0f - (float) v1;

        int t2 = (int) (pick_info.y * (1.0f / 3.0f));
        int v2 = -t2 * 3;
        pick_info.y = 1.0f - (float) v2;

        brushSize = 3;
    } else {
        brushSize = rge_base_game->brush_size;
    }

    long cx = (long) pick_info.x;
    long cy = (long) pick_info.y;
    set_selection_area(cx - (brushSize >> 1), cy - (brushSize >> 1), cx + (brushSize >> 1), cy + (brushSize >> 1));
}

unsigned char RGE_View::pick(
    unsigned char pick_mode_in, unsigned char select_level, long x, long y, RGE_Pick_Info* pick_info,
    RGE_Static_Object* last_picked_object
) {
    void* picked_output = ((unsigned char) pick_mode_in != '(') ? last_picked_object : 0;
    tagPOINT start_mouse_pos;
    tagPOINT mouse_pos;

    mouse_pos.x = x;
    mouse_pos.y = y;
    start_mouse_pos.x = x;
    start_mouse_pos.y = y;

    memset(pick_info, 0, sizeof(*pick_info));

    long ret = this->view_function(
        pick_mode_in, select_level, &mouse_pos, &start_mouse_pos, &picked_output, &pick_info->x, &pick_info->y,
        &pick_info->scr_x, &pick_info->scr_y
    );
    unsigned char code = (unsigned char) ret;
    if (code == 0x34) {
        pick_info->object = (RGE_Static_Object*) picked_output;
    } else if (code == 0x33) {
        pick_info->tile = (RGE_Tile*) picked_output;
    }
    return code;
}

unsigned char RGE_View::pick_multi(unsigned char select_level, long x1, long y1, long x2, long y2) {
    RGE_Pick_Obj_Info* pp;
    int i = 0;
    int picked_any = 0;
    int count;
    RGE_Static_Object* picked_obj;
    count = this->pick_multi_objects(x1, y1, x2, y2, 10, 20, this->player->id, select_level, 1);
    if (count > 0) {
        pp = Picked_Objects;
        do {
            int idx = pp->object_id;
            if (idx != -1) {
                RGE_Static_Object* obj = this->world->objectsValue[idx];
                if (obj != 0 && obj->object_state < RGE_OBJECT_STATE_PENDING_REMOVAL) {
                    if (!this->player->select_one_object(obj, 0))
                        break;
                    picked_any = 1;
                }
            }
            i++;
            ++pp;
        } while (i < count);
    }
    if (picked_any)
        return 1;

    long dx = x2 - x1;
    long dy = y2 - y1;
    long r = dx;
    if (dx >= dy)
        r = dy;
    if (r < 50) {
        r = dy;
        if (dx < dy)
            r = dx;
    } else
        r = 50;

    count = this->pick_objects(x1 + dx / 2, y1 + dy / 2, 10, 20, r, 4, 1);
    if (count) {
        picked_obj = 0;
        int bestScore = 0;
        int remaining;
        if (count > 0) {
            pp = Picked_Objects;
            remaining = count;
            do {
                int idx = pp->object_id;
                if (idx >= 0) {
                    RGE_Static_Object* obj = this->world->objectsValue[idx];
                    if (obj && obj->object_state < RGE_OBJECT_STATE_PENDING_REMOVAL
                        && obj->master_obj->select_level >= 2) {
                        if (!this->map->map_visible_flag && !this->pick_through_fog(obj)) {
                            int vy = (int) obj->world_y;
                            int vx = (int) obj->world_x;
                            if (this->player->visible->get_visible(vx, vy) != 0x0f)
                                goto next;
                        }
                        int score = this->pick_weight(obj, pp->confidence);
                        if (obj->owner == this->player)
                            score += 5;
                        if (score > bestScore) {
                            picked_obj = obj;
                            bestScore = score;
                        }
                    }
                }
            next:
                ++pp;
                remaining--;
            } while (remaining != 0);
        }
        if (picked_obj && this->player->select_one_object(picked_obj, 0))
            return 1;
    }
    return 0;
}

unsigned char RGE_View::pick(
    unsigned char function_mode_in, unsigned char select_level, tagPOINT* mouse_pos, tagPOINT* start_mouse_pos,
    void** picked_item, float* item_x, float* item_y, short* item_scr_x, short* item_scr_y
) {
    return (unsigned char) view_function(
        function_mode_in, select_level, mouse_pos, start_mouse_pos, picked_item, item_x, item_y, item_scr_x, item_scr_y
    );
}

int RGE_View::pick_through_fog(RGE_Static_Object* obj) {
    return 0;
}

int RGE_View::pick_weight(RGE_Static_Object* obj, int confidence) {
    unsigned char select_level = obj->master_obj->select_level;
    int touched;

    if (this->UC_ObjectTouched && this->UC_TouchedObj == obj->id)
        touched = 1;
    else
        touched = 0;

    int result = 0;

    switch ((int) (unsigned) select_level) {
        case 4:
            if (touched)
                return 5;
            if (confidence == 1 || confidence == 2)
                return 4;
            if (confidence == 3)
                return 3;
            return 2;
        case 3:
            if (touched)
                return 5;
            if (confidence == 1 || confidence == 2)
                result = 3;
            break;
        case 2:
            if (touched)
                return 5;
            if (confidence == 1 || confidence == 2)
                result = 3;
            else if (confidence == 3)
                result = 2;
            break;
        default:
            return 1;
    }

    return result;
}

int RGE_View::get_tile_screen_coords(short find_col, short find_row, short* scr_x, short* scr_y, int drop) {
    if (scr_x != 0)
        *scr_x = 0;
    if (scr_y != 0)
        *scr_y = 0;

    if (find_col >= 0) {
        RGE_Map* pMap = this->map;
        if (find_col < pMap->map_width) {
            if (find_row >= 0) {
                if (find_row < pMap->map_height) {
                    RGE_Tile* pTile = pMap->map_row_offset[find_row] + find_col;
                    if (pTile != 0) {
                        int screen_x = pTile->screen_xpos - this->map_scr_x_offset;
                        int screen_y = pTile->screen_ypos;
                        screen_y += pMap->tilesizes[pTile->tile_type].y_delta;
                        screen_y -= this->map_scr_y_offset;

                        if (drop != 0) {
                            if (pTile->tile_type != 0)
                                screen_y += this->elev_hgt / 2;
                            if (pTile->tile_type == 6)
                                screen_y -= this->elev_hgt;
                            if (pTile->tile_type == 5)
                                screen_y -= this->elev_hgt;
                            if (pTile->tile_type == 3)
                                screen_y -= this->elev_hgt;
                            if (pTile->tile_type == 0x0B)
                                screen_y -= this->elev_hgt;
                        }

                        *scr_x = (short) screen_x;
                        *scr_y = (short) screen_y;
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

void RGE_View::get_center_screen_pos(short* scr_x, short* scr_y) {
    *scr_x = center_scr_row;
    *scr_y = center_scr_col;
}

void RGE_View::get_start_coords(short* map_col, short* map_row, short* scr_col, short* scr_row) {
    if (map_col != 0) {
        *map_col = start_map_col;
    }
    if (map_row != 0) {
        *map_row = start_map_row;
    }
    if (scr_col != 0) {
        *scr_col = start_scr_col;
    }
    if (scr_row != 0) {
        *scr_row = start_scr_row;
    }
}

void RGE_View::get_center_coords(short* map_col, short* map_row, short* scr_col, short* scr_row) {
    if (map_col != 0) {
        *map_col = center_map_col;
    }
    if (map_row != 0) {
        *map_row = center_map_row;
    }
    if (scr_col != 0) {
        *scr_col = center_scr_col;
    }
    if (scr_row != 0) {
        *scr_row = center_scr_row;
    }
}

void RGE_View::get_tile_sizes(short* wid, short* hgt, short* half_wid, short* half_hgt) {
    if (wid != 0) {
        *wid = tile_wid;
    }
    if (hgt != 0) {
        *hgt = tile_hgt;
    }
    if (half_wid != 0) {
        *half_wid = tile_half_wid;
    }
    if (half_hgt != 0) {
        *half_hgt = tile_half_hgt;
    }
}

void RGE_View::get_max_size(short* col_num, short* row_num) {
    *col_num = max_col_num;
    *row_num = max_row_num;
}

long RGE_View::view_function(
    unsigned char function_mode_in, unsigned char function_parm_in, tagPOINT* mouse_pos, tagPOINT* start_mouse_pos,
    void** picked_item, float* item_x, float* item_y, short* item_scr_x, short* item_scr_y
) {
    RGE_Tile_List_Node* changed_tiles;
    int changed_tile_count;
    RGE_Static_Object* orig_picked_obj;
    RGE_Static_Object* last_picked_obj;
    short find_col;
    short find_row;
    long calc_sel_col1;
    long calc_sel_row1;
    long calc_sel_col2;
    long calc_sel_row2;
    unsigned char result;

    this->function_mode = function_mode_in;
    this->function_parm = function_parm_in;

    if (this->function_mode == 10 && this->calc_draw_count != 0) {
        short terrain = 0;
        if (this->map->num_terrain > 0) {
            do {
                this->map->terrain_types[terrain].drawn = 0;
                ++terrain;
            } while (terrain < this->map->num_terrain);
        }
    }

    this->player->tile_list.get_list_info(changed_tiles, changed_tile_count);

    result = 0x32;
    if (this->function_mode == 0x28 || this->function_mode == 0x3c || this->function_mode == 0x29
        || this->function_mode == 0x2a || this->function_mode == 0x2b || this->function_mode == 0x2c) {
        if (this->function_mode == 0x3c) {
            find_col = (short) (long) *item_x;
            find_row = (short) (long) *item_y;
        }

        *item_x = 0.0f;
        *item_y = 0.0f;
        *item_scr_x = 0;
        *item_scr_y = 0;

        if (this->function_mode == 0x29 || this->function_mode == 0x2a || this->function_mode == 0x2b
            || this->function_mode == 0x2c) {
            orig_picked_obj = (RGE_Static_Object*) *picked_item;
        }
        *picked_item = 0;
        last_picked_obj = 0;
    }

    if (this->function_mode == 0x0e) {
        if (this->get_selection_area(calc_sel_col1, calc_sel_row1, calc_sel_col2, calc_sel_row2, 1) == 0) {
            return 0;
        }
    }

    short start_screen_x = this->start_scr_col;
    short start_screen_y = this->start_scr_row;
    short start_map_col = this->start_map_col;
    short start_map_row = this->start_map_row;
    short rows_to_scan = (short) ((this->max_row_num + 6) * 2);
    short cols_to_scan = (short) (this->max_col_num + 4);
    short original_cols_to_scan = cols_to_scan;
    unsigned char direction = 4;
    short row_number = 0;

    if (rows_to_scan > 0) {
        do {
            short screen_x = start_screen_x;
            short map_col = start_map_col;
            short map_row = start_map_row;
            short col_number = 0;

            if (cols_to_scan > 0) {
                do {
                    int in_map = 0;
                    if (map_col >= 0 && map_col < this->map->map_width && map_row >= 0
                        && map_row < this->map->map_height) {
                        in_map = 1;
                    }

                    if (in_map || this->function_mode == 0x28 || this->function_mode == 0x2a) {
                        unsigned char visibility;

                        if (in_map) {
                            RGE_Visible_Map* visible = this->player->visible;
                            if (visible == 0 || this->map->map_visible_flag != 0) {
                                visibility = visible->get_visible(map_col, map_row);
                                if (visibility == 0) {
                                    visibility = 0x80;
                                }
                            } else {
                                visibility = visible->get_visible(map_col, map_row);
                                if (this->function_mode == 0x1e || this->function_mode == 0x1f) {
                                    visibility = 0x0f;
                                }
                            }
                        } else {
                            visibility = 0;
                        }

                        if (in_map && this->function_mode == 0x0b) {
                            RGE_Tile* drawn_tile = this->map->map_row_offset[map_row] + map_col;
                            if (drawn_tile->draw_as == drawn_tile->last_drawn_as) {
                                visibility = 0;
                            }
                        }

                        if (visibility != 0x0f && visibility != 0x80) {
                            visibility = 0;
                        }

                        if (visibility != 0 || this->function_mode == 0x0e || this->function_mode == 0x28
                            || this->function_mode == 0x3c || this->function_mode == 0x2a) {
                            RGE_Tile* tile;
                            unsigned char tile_type;
                            unsigned char tile_height;

                            if (in_map) {
                                tile = this->map->map_row_offset[map_row] + map_col;
                                tile_type = tile->tile_type;
                                tile_height = tile->height;
                            } else {
                                tile = 0;
                                tile_type = 0;
                                tile_height = 0;
                            }

                            short tile_screen_row = (short) (start_screen_y - tile_height * this->elev_hgt);
                            switch (tile_type) {
                                case 2:
                                case 6:
                                case 8:
                                case 10:
                                case 14:
                                case 15:
                                case 16:
                                    tile_screen_row = (short) (tile_screen_row - this->elev_hgt);
                                    break;
                            }

                            int outside;
                            if (screen_x > this->render_rect.right || tile_screen_row > this->render_rect.bottom
                                || screen_x + this->map->tilesizes[tile_type].width <= this->render_rect.left
                                || tile_screen_row + this->map->tilesizes[tile_type].height <= this->render_rect.top
                                || (this->function_mode == 0x0e
                                    && (map_col < calc_sel_col1 || map_col > calc_sel_col2 || map_row < calc_sel_row1
                                        || map_row > calc_sel_row2))) {
                                outside = 1;
                            } else {
                                outside = 0;
                            }

                            if (this->function_mode == 10 || this->function_mode == 0x1e || this->function_mode == 0x1f
                                || this->function_mode == 0x20 || this->function_mode == 0x15
                                || this->function_mode == 0x0b || this->function_mode == 0x0e) {
                                if (!outside
                                    && (this->function_mode == 10 || this->function_mode == 0x0b
                                        || this->function_mode == 0x0e)) {
                                    unsigned char terrain_type = tile->terrain_type;
                                    short terrain_to_draw = this->map->terrain_types[terrain_type].terrain_to_draw;
                                    if (terrain_to_draw != -1) {
                                        terrain_type = (unsigned char) terrain_to_draw;
                                    }

                                    if (this->function_mode == 10 && this->calc_draw_count != 0
                                        && (short) terrain_type < this->map->num_terrain) {
                                        ++this->map->terrain_types[terrain_type].drawn;
                                    }

                                    if (this->function_mode == 0x0b) {
                                        tile->last_drawn_as = tile->draw_as;
                                    }
                                }

                                if ((visibility == 0x0f || visibility == 0x80)
                                    && (this->function_mode == 0x1e || this->function_mode == 0x1f
                                        || this->function_mode == 0x20 || this->function_mode == 0x15)) {
                                    unsigned char fog_flag =
                                        (visibility == 0x0f || (visibility == 0x80 && this->map->fog_flag == 0)) ? 0
                                                                                                                 : 1;

                                    if (this->function_mode == 0x1e) {
                                        this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
                                        fog_next_shape = 1;
                                        tile->objects.shadow_draw(
                                            this->cur_render_area, screen_x, start_screen_y, 1, fog_flag
                                        );
                                        this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
                                        fog_next_shape = 0;
                                        tile->objects.shadow_draw(
                                            this->cur_render_area, screen_x, start_screen_y, 1, fog_flag
                                        );
                                        this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
                                    }

                                    if (this->function_mode == 0x1f) {
                                        this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
                                        fog_next_shape = 1;
                                        tile->objects.shadow_draw(
                                            this->cur_render_area, screen_x, start_screen_y, 10, fog_flag
                                        );
                                        this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
                                        fog_next_shape = 0;
                                        tile->objects.shadow_draw(
                                            this->cur_render_area, screen_x, start_screen_y, 10, fog_flag
                                        );
                                        this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
                                    }

                                    if (this->function_mode == 0x20) {
                                        if (this->map->fog_flag != 0 && visibility == 0x80) {
                                            fog_next_shape = 1;
                                        }
                                        tile->objects.shadow_draw(
                                            this->cur_render_area, screen_x, start_screen_y, 0, fog_flag
                                        );
                                        fog_next_shape = 0;
                                    } else if (this->function_mode == 0x15) {
                                        if (this->map->fog_flag != 0 && visibility == 0x80) {
                                            fog_next_shape = 1;
                                        }
                                        tile->objects.normal_draw(
                                            this->cur_render_area, screen_x, start_screen_y, fog_flag
                                        );
                                        fog_next_shape = 0;
                                    }
                                }
                            } else {
                                if ((visibility == 0x0f || visibility == 0x80)
                                    && (this->function_mode == 0x29 || this->function_mode == 0x2a
                                        || this->function_mode == 0x2b || this->function_mode == 0x2c)) {
                                    unsigned char fog_flag =
                                        (visibility == 0x0f || (visibility == 0x80 && this->map->fog_flag == 0)) ? 0
                                                                                                                 : 1;
                                    RGE_Static_Object* object = this->hit_object(
                                        tile, screen_x, start_screen_y, map_col, map_row, mouse_pos, start_mouse_pos,
                                        item_scr_x, item_scr_y, orig_picked_obj, fog_flag
                                    );

                                    if (object != 0) {
                                        if (this->function_mode == 0x2c) {
                                            result = 0x34;
                                        } else {
                                            if (orig_picked_obj != 0 && object == orig_picked_obj && result == 0x34) {
                                                *picked_item = last_picked_obj;
                                                return 0x34;
                                            }

                                            if (last_picked_obj == 0
                                                || object->master_obj->select_level
                                                       >= last_picked_obj->master_obj->select_level
                                                || (last_picked_obj == orig_picked_obj && object != orig_picked_obj)) {
                                                *item_x = object->world_x;
                                                *item_y = object->world_y;
                                                last_picked_obj = object;
                                                result = 0x34;
                                            }
                                        }
                                    }
                                }

                                if (this->function_mode == 0x28 || (this->function_mode == 0x2a && result == 0x32)) {
                                    if (this->hit_tile(tile, screen_x, tile_screen_row, map_col, map_row, mouse_pos)) {
                                        if (tile != 0) {
                                            this->map->tile_map_coords(
                                                (short) (mouse_pos->x - screen_x),
                                                (short) (mouse_pos->y - tile_screen_row), tile, item_x, item_y
                                            );
                                            *item_x += (float) map_col;
                                            *item_y += (float) map_row;
                                        } else {
                                            *item_x = (float) map_col;
                                            *item_y = (float) map_row;
                                        }
                                        *item_scr_x = screen_x;
                                        *item_scr_y = tile_screen_row;
                                        result = 0x33;
                                        *picked_item = tile;
                                    }
                                } else if (this->function_mode == 0x3c && map_col == find_col && map_row == find_row) {
                                    *item_x = (float) map_col;
                                    *item_y = (float) map_row;
                                    *item_scr_x = screen_x;
                                    *item_scr_y = tile_screen_row;
                                    *picked_item = tile;
                                    return 0x33;
                                }
                            }
                        }
                    }

                    screen_x = (short) (screen_x + this->tile_wid);
                    ++map_col;
                    ++map_row;
                    ++col_number;
                } while (col_number < cols_to_scan);
            }

            if (direction == 1 && cols_to_scan == original_cols_to_scan) {
                direction = 2;
            }

            switch (direction) {
                case 1:
                    ++cols_to_scan;
                    start_screen_x = (short) (start_screen_x - this->tile_half_wid);
                    --start_map_col;
                    break;
                case 2:
                    --cols_to_scan;
                    start_screen_x = (short) (start_screen_x + this->tile_half_wid);
                    ++start_map_row;
                    break;
                case 3:
                    start_screen_x = (short) (start_screen_x - this->tile_half_wid);
                    --start_map_col;
                    direction = 4;
                    break;
                case 4:
                    start_screen_x = (short) (start_screen_x + this->tile_half_wid);
                    ++start_map_row;
                    direction = 3;
                    break;
            }

            start_screen_y = (short) (start_screen_y + this->tile_half_hgt);
            ++row_number;
        } while (row_number < rows_to_scan);
    }

    if (this->function_mode == 10) {
        short terrain = 0;
        if (this->map->num_terrain > 0) {
            do {
                this->map->terrain_types[terrain].frame_changed = 0;
                ++terrain;
            } while (terrain < this->map->num_terrain);
        }
    }

    if ((this->function_mode == 0x29 || this->function_mode == 0x2a || this->function_mode == 0x2b) && result == 0x34) {
        *picked_item = last_picked_obj;
    }

    return result;
}

long RGE_View::view_function_terrain(unsigned char function_mode_in, tagRECT save_render_rect) {
    int start_map_x;
    int start_row;
    int cols_2_scan;
    int rows_2_scan;
    int Map_Width;
    int Map_Height;
    unsigned long TileFoggedMask;
    unsigned long TileVisibleMask;
    int Full_Visibility;
    int current_region;
    int row_num;

    if (this->DispSel_List_Size > 0) {
        this->update_display_selected_objects();
    }

    start_map_x = this->start_map_col;
    start_row = this->start_map_row;
    cols_2_scan = this->max_col_num + 5;
    rows_2_scan = this->max_row_num * 2 + 12;
    Map_Width = this->map->map_width;
    Map_Height = this->map->map_height;
    this->function_mode = function_mode_in;

    if (this->map->num_terrain > 0) {
        int terrain_num = 0;
        do {
            this->map->terrain_types[terrain_num].drawn = 0;
            terrain_num++;
        } while (terrain_num < this->map->num_terrain);
    }

    TileFoggedMask = this->player->mutualExploredMask;
    TileVisibleMask = this->player->mutualVisibleMask;
    SDI_List = this->futur_objs;
    this->futur_objs->ReclaimAllNodes();

    current_region = -1;
    if (this->player->visible == 0 || this->map->map_visible_flag != 0) {
        Full_Visibility = 1;
    } else {
        Full_Visibility = 0;
    }

    row_num = 0;
    if (rows_2_scan > 0) {
        do {
            int map_col = start_map_x;
            int map_row = start_row;
            int col_num = 0;
            int odd_row;

            if ((row_num & 3) == 3 && MouseSystem != 0) {
                MouseSystem->Poll();
            }

            odd_row = row_num & 1;
            if (odd_row == 1 && this->Queued_Blits != 0) {
                this->ProcessQueuedBlit(0);
            }

            if (cols_2_scan > 0) {
                do {
                    if (map_row >= 0 && map_col >= 0) {
                        if (map_row >= Map_Height || map_col >= Map_Width) {
                            col_num = cols_2_scan;
                        } else {
                            RGE_Map* current_map = this->map;
                            RGE_Tile* tile = current_map->map_row_offset[map_row] + map_col;
                            int tile_x = tile->screen_xpos - this->map_scr_x_offset;
                            int tile_y = tile->screen_ypos - this->map_scr_y_offset;
                            int tile_right = tile_x + this->tile_wid;
                            int tile_bottom = tile_y + current_map->tilesizes[tile->tile_type].height;
                            short draw_x = (short) tile_x;
                            short draw_y = (short) tile_y;
                            unsigned char MapVis;

                            if ((unified_map_offsets[map_row][map_col] & TileVisibleMask) != 0) {
                                MapVis = 0x0f;
                            } else if ((unified_map_offsets[map_row][map_col] & TileFoggedMask) != 0
                                       || Full_Visibility != 0) {
                                MapVis = this->map->fog_flag != 0 ? 0x80 : 0x0f;
                            } else {
                                MapVis = 0;
                                tile->last_drawn_as = 0;
                            }

                            if (MapVis != 0 && tile_x <= this->render_rect.right && tile_y <= this->render_rect.bottom
                                && tile_right > this->render_rect.left && tile_bottom > this->render_rect.top) {
                                unsigned char terrain_num = tile->terrain_type;
                                int black_tile_mask_num = -1;
                                int tile_mask_num = -1;
                                int region = 0;
                                int clip_to = 0;

                                if (this->calc_draw_count != 0 && (short) terrain_num < this->map->num_terrain) {
                                    this->map->terrain_types[terrain_num].drawn++;
                                }

                                if (this->render_terrain_mode != 0 && tile->last_drawn_as == MapVis) {
                                    if (MapVis == 0x0f) {
                                        if (this->map->fog_flag == 0) {
                                            black_tile_mask_num = 0;
                                        } else {
                                            black_tile_mask_num = this->get_tile_mask_num(
                                                map_col, map_row, Map_Width, Map_Height, TileVisibleMask
                                            );
                                        }
                                        if ((int) tile->last_drawn_shape != black_tile_mask_num) {
                                            goto draw_this_tile;
                                        }
                                    }

                                    if (MapVis == 0x0f || MapVis == 0x80) {
                                        if (Full_Visibility == 0) {
                                            tile_mask_num = this->get_tile_mask_num(
                                                map_col, map_row, Map_Width, Map_Height, TileFoggedMask
                                            );
                                        } else {
                                            tile_mask_num = 0;
                                        }
                                        if ((int) tile->last_drawn_shape2 != tile_mask_num) {
                                            goto draw_this_tile;
                                        }
                                    }

                                    if (this->Limited_Render_Rect == 0) {
                                        goto tile_off_screen;
                                    }

                                    if (this->Use_Rect2 != 0 && this->Render_Rect2.right >= tile_x
                                        && tile_right >= this->Render_Rect2.left && this->Render_Rect2.bottom >= tile_y
                                        && tile_bottom >= this->Render_Rect2.top) {
                                        clip_to = 1;
                                    }

                                    if (this->Render_Rect1.right >= tile_x && tile_right >= this->Render_Rect1.left
                                        && this->Render_Rect1.bottom >= tile_y
                                        && tile_bottom >= this->Render_Rect1.top) {
                                        region = 1;
                                    } else {
                                        if (clip_to == 0) {
                                            goto tile_off_screen;
                                        }
                                        clip_to = 0;
                                        region = 2;
                                    }
                                }

                            draw_this_tile: {
                                Tile_FogEdge_Table* edge_table = this->Tile_Edge_Tables[tile->tile_type];
                                Tile_BlackEdge_Table* black_table = this->Black_Edge_Tables[tile->tile_type];
                                VSpanMiniList* normal_draw_data;
                                VSpanMiniList* fog_draw_data;
                                VSpanMiniList* black_draw_data;
                                int draw_normal;
                                int fog_draw;
                                int draw_black;

                                if (this->map->fog_flag == 0) {
                                    black_tile_mask_num = 0;
                                }
                                if (Full_Visibility != 0) {
                                    tile_mask_num = 0;
                                }
                                if (black_tile_mask_num == -1) {
                                    if (MapVis == 0x0f) {
                                        black_tile_mask_num = this->get_tile_mask_num(
                                            map_col, map_row, Map_Width, Map_Height, TileVisibleMask
                                        );
                                    } else {
                                        black_tile_mask_num = 0;
                                    }
                                }
                                if (tile_mask_num == -1) {
                                    if (MapVis != 0) {
                                        tile_mask_num = this->get_tile_mask_num(
                                            map_col, map_row, Map_Width, Map_Height, TileFoggedMask
                                        );
                                    } else {
                                        tile_mask_num = 0;
                                    }
                                }

                                normal_draw_data = edge_table[black_tile_mask_num].normal_draw;
                                fog_draw_data = edge_table[black_tile_mask_num].fog_draw;
                                black_draw_data = black_table[tile_mask_num].black_UNdraw;

                                if (MapVis == 0x80) {
                                    fog_draw_data = edge_table[0].normal_draw;
                                    fog_draw = 1;
                                    draw_normal = 0;
                                } else {
                                    draw_normal = normal_draw_data != 0;
                                    fog_draw = fog_draw_data != 0;
                                }

                                draw_black = tile_mask_num > 0 && black_draw_data != 0;

                                if (region != current_region) {
                                    if (region == 0) {
                                        this->Terrain_Clip_Mask->SetSpanRegions(
                                            this->render_rect.left, this->render_rect.top, this->render_rect.right,
                                            this->render_rect.bottom
                                        );
                                        this->Terrain_Fog_Clip_Mask->SetSpanRegions(
                                            this->render_rect.left, this->render_rect.top, this->render_rect.right,
                                            this->render_rect.bottom
                                        );
                                    }
                                    if (region == 1) {
                                        this->Terrain_Clip_Mask->SetSpanRegions(
                                            this->Render_Rect1.left, this->Render_Rect1.top, this->Render_Rect1.right,
                                            this->Render_Rect1.bottom
                                        );
                                        this->Terrain_Fog_Clip_Mask->SetSpanRegions(
                                            this->Render_Rect1.left, this->Render_Rect1.top, this->Render_Rect1.right,
                                            this->Render_Rect1.bottom
                                        );
                                    }
                                    current_region = region;
                                    if (region == 2) {
                                        this->Terrain_Clip_Mask->SetSpanRegions(
                                            this->Render_Rect2.left, this->Render_Rect2.top, this->Render_Rect2.right,
                                            this->Render_Rect2.bottom
                                        );
                                        this->Terrain_Fog_Clip_Mask->SetSpanRegions(
                                            this->Render_Rect2.left, this->Render_Rect2.top, this->Render_Rect2.right,
                                            this->Render_Rect2.bottom
                                        );
                                        current_region = region;
                                    }
                                }

                                if (draw_normal != 0) {
                                    this->Terrain_Clip_Mask->AddMiniList(normal_draw_data, tile_x, tile_y);
                                }
                                if (fog_draw != 0) {
                                    this->Terrain_Fog_Clip_Mask->AddMiniList(fog_draw_data, tile_x, tile_y);
                                }
                                if (draw_black != 0) {
                                    if (draw_normal != 0) {
                                        this->Terrain_Clip_Mask->SubtractMiniList(black_draw_data, tile_x, tile_y);
                                    }
                                    if (fog_draw != 0) {
                                        this->Terrain_Fog_Clip_Mask->SubtractMiniList(black_draw_data, tile_x, tile_y);
                                    }
                                }

                                if (clip_to != 0) {
                                    this->Terrain_Clip_Mask->SetSpanRegions(
                                        this->Render_Rect2.left, this->Render_Rect2.top, this->Render_Rect2.right,
                                        this->Render_Rect2.bottom
                                    );
                                    this->Terrain_Fog_Clip_Mask->SetSpanRegions(
                                        this->Render_Rect2.left, this->Render_Rect2.top, this->Render_Rect2.right,
                                        this->Render_Rect2.bottom
                                    );
                                    current_region = 2;

                                    if (draw_normal != 0) {
                                        this->Terrain_Clip_Mask->AddMiniList(normal_draw_data, tile_x, tile_y);
                                    }
                                    if (fog_draw != 0) {
                                        this->Terrain_Fog_Clip_Mask->AddMiniList(fog_draw_data, tile_x, tile_y);
                                    }
                                    if (draw_black != 0) {
                                        if (draw_normal != 0) {
                                            this->Terrain_Clip_Mask->SubtractMiniList(black_draw_data, tile_x, tile_y);
                                        }
                                        if (fog_draw != 0) {
                                            this->Terrain_Fog_Clip_Mask->SubtractMiniList(
                                                black_draw_data, tile_x, tile_y
                                            );
                                        }
                                    }
                                }

                                terrain_num = tile->terrain_type;
                                {
                                    short terrain_to_draw = this->map->terrain_types[terrain_num].terrain_to_draw;
                                    if (terrain_to_draw != -1) {
                                        terrain_num = (unsigned char) terrain_to_draw;
                                    }
                                }

                                tile->last_drawn_shape2 = (unsigned char) tile_mask_num;
                                tile->last_drawn_shape = (unsigned char) black_tile_mask_num;
                                tile->last_drawn_as = MapVis;
                                tile->draw_as = MapVis;
                                tile->draw_attribute &= 0xbf;
                                this->draw_tile(
                                    tile, terrain_num, draw_x, draw_y, (short) map_col, (short) map_row, MapVis,
                                    draw_normal, fog_draw
                                );
                                tiles_drawn++;
                            }
                            }

                        tile_off_screen:
                            if (tile != 0 && (tile->draw_attribute & 0x40) == 0x40) {
                                unsigned char terrain_num = tile->terrain_type;
                                short terrain_to_draw = this->map->terrain_types[terrain_num].terrain_to_draw;
                                if (terrain_to_draw != -1) {
                                    terrain_num = (unsigned char) terrain_to_draw;
                                }
                                this->draw_tile(
                                    tile, terrain_num, draw_x, draw_y, (short) map_col, (short) map_row, MapVis, 1, 1
                                );
                                tile->draw_attribute &= 0xbf;
                            }

                            if (view_debug_Objects == 0 && tile != 0) {
                                SDI_Capture_Info = 1;
                                if (MapVis == 0) {
                                    this->futur_objs->SetCaptureLevel(0, 5);
                                }
                                if (MapVis != 0x0f) {
                                    fog_next_shape = 1;
                                }
                                tile->objects.draw(
                                    this->save_area1, draw_x, (short) (draw_y + tile->height * this->tile_half_hgt),
                                    MapVis == 0x80
                                );
                                this->futur_objs->SetCaptureLevel(0, 0x28);
                                fog_next_shape = 0;
                                SDI_Capture_Info = 0;
                            }
                        }
                    }

                    map_col++;
                    map_row++;
                    col_num++;
                } while (col_num < cols_2_scan);
            }

            if (odd_row == 1) {
                start_row++;
            } else {
                start_map_x--;
            }
            row_num++;
        } while (row_num < rows_2_scan);
    }

    while (this->Queued_Blits != 0) {
        this->ProcessQueuedBlit(1);
    }
    if (MouseSystem != 0) {
        MouseSystem->Poll();
    }

    this->render_rect.left += save_render_rect.left;
    this->render_rect.top += save_render_rect.top;
    this->render_rect.right += save_render_rect.left;
    this->render_rect.bottom += save_render_rect.top;

    SDI_Capture_Info = 1;
    if (this->scroll_action == 2) {
        this->futur_objs->AddGDINode(
            4, 0x14, this->mouse_down_x - save_render_rect.left, this->mouse_down_y - save_render_rect.top,
            this->mouse_last_x - save_render_rect.left, this->mouse_last_y - save_render_rect.top, 0, 0, 0, 0, 0x28,
            0xff, 0
        );
    }

    {
        int game_mode = rge_base_game->game_mode;
        if (game_mode == 1 || (game_mode > 6 && game_mode < 9)) {
            this->draw_object_outline();
        }
    }
    if (rge_base_game->game_mode == 0x15) {
        this->draw_multi_object_outline();
    }

    {
        int ResetALLCyclic = 0;
        Ov_Sprite_Draw_Rec* sprite = this->extra_sprites;
        if (sprite != 0) {
            unsigned long current_time = debug_timeGetTime((char*) s_C__msdev_work_age1_x1_view_cpp, 3646);
            while (sprite != 0) {
                int remove_sprite = 0;

                if (sprite->theShape != 0) {
                    if (sprite->LastDrawTime == 0) {
                        sprite->LastDrawTime = current_time;
                    } else if ((sprite->displayfunction == 1 || sprite->displayfunction == 2)
                               && current_time - sprite->LastDrawTime >= sprite->DrawTimeInterval) {
                        unsigned long elapsed = current_time - sprite->LastDrawTime;
                        do {
                            sprite->thefacet++;
                            if (sprite->thefacet >= sprite->theShape->shape_count()) {
                                sprite->thefacet = 0;
                                if (sprite->displayfunction == 2) {
                                    remove_sprite = 1;
                                    ResetALLCyclic = 1;
                                }
                            }
                            elapsed -= sprite->DrawTimeInterval;
                            sprite->LastDrawTime += sprite->DrawTimeInterval;
                        } while (elapsed >= sprite->DrawTimeInterval);
                    }

                    if (remove_sprite == 0) {
                        SDI_Draw_Level = sprite->drawLevel;
                        SDI_Object_ID = -1;
                        sprite->theShape->shape_draw(
                            this->render_area, sprite->world_x - this->map_scr_x_offset,
                            sprite->world_y - this->map_scr_y_offset, sprite->thefacet, (unsigned char) sprite->flags,
                            sprite->colortable
                        );
                    }
                }

                if (sprite->theShape == 0 || remove_sprite == 0) {
                    sprite = sprite->next;
                } else {
                    Ov_Sprite_Draw_Rec* next = sprite->next;
                    if (sprite->prev != 0) {
                        sprite->prev->next = sprite->next;
                    }
                    if (sprite->next != 0) {
                        sprite->next->prev = sprite->prev;
                    }
                    if (sprite->prev == 0) {
                        this->extra_sprites = sprite->next;
                    }
                    delete sprite;
                    sprite = next;
                }
            }
        }

        if (ResetALLCyclic != 0) {
            this->reset_cyclic_overlay_sprites();
        }
    }

    SDI_Capture_Info = 0;
    this->render_rect.left -= save_render_rect.left;
    this->render_rect.top -= save_render_rect.top;
    this->render_rect.right -= save_render_rect.left;
    this->render_rect.bottom -= save_render_rect.top;

    {
        int line = 0;
        if (this->futur_objs->YLine_Size > 0) {
            do {
                DClipInfo_Node* node = this->futur_objs->Draw_Clip_Nodes[line];
                while (node != 0) {
                    int level = node->Draw_Level;
                    DClipInfo_Node* tail = this->futur_objs->Draw_Level_Tail[level];
                    if (tail == 0) {
                        this->futur_objs->Draw_Level_Head[level] = node;
                    } else {
                        tail->NextOnLevel = node;
                    }
                    this->futur_objs->Draw_Level_Tail[level] = node;
                    node = node->Next;
                }
                line++;
            } while (line < this->futur_objs->YLine_Size);
        }
    }

    Clip_draw = 0;
    Clip_remove = 0;
    if (current_region != 0) {
        this->Terrain_Clip_Mask->SetSpanRegions(
            this->render_rect.left, this->render_rect.top, this->render_rect.right, this->render_rect.bottom
        );
        this->Terrain_Fog_Clip_Mask->SetSpanRegions(
            this->render_rect.left, this->render_rect.top, this->render_rect.right, this->render_rect.bottom
        );
    }

    {
        int level = 0;
        do {
            DClipInfo_Node* node = this->futur_objs->Draw_Level_Head[level];
            while (node != 0) {
                if (node->Node_Type == 0) {
                    Shape_Info* shape = node->Shape;

                    ASMSet_Surface_Info(
                        this->save_area1->CurDisplayOffsets, this->Terrain_Clip_Mask->Line_Head_Ptrs,
                        this->Terrain_Clip_Mask->Line_Tail_Ptrs, this->Terrain_Clip_Mask->Min_Span_Px,
                        this->Terrain_Clip_Mask->Min_Line, this->Terrain_Clip_Mask->Max_Span_Px,
                        this->Terrain_Clip_Mask->Max_Line
                    );
                    ASMSet_Color_Xform(node->Xform_Mask);
                    ASMSet_Xlate_Table(node->Color_Table);
                    ASMDraw_Sprite(
                        node->Shape_Base, node->Draw_X, node->Draw_Y, shape->Width, shape->Height,
                        shape->Shape_Data_Offsets, shape->Shape_Outline_Offset, node->Draw_Flag & 0xfe
                    );

                    ASMSet_Surface_Info(
                        this->save_area1->CurDisplayOffsets, this->Terrain_Fog_Clip_Mask->Line_Head_Ptrs,
                        this->Terrain_Fog_Clip_Mask->Line_Tail_Ptrs, this->Terrain_Fog_Clip_Mask->Min_Span_Px,
                        this->Terrain_Fog_Clip_Mask->Min_Line, this->Terrain_Fog_Clip_Mask->Max_Span_Px,
                        this->Terrain_Fog_Clip_Mask->Max_Line
                    );
                    ASMDraw_Sprite(
                        node->Shape_Base, node->Draw_X, node->Draw_Y, shape->Width, shape->Height,
                        shape->Shape_Data_Offsets, shape->Shape_Outline_Offset, node->Draw_Flag | 1
                    );
                }
                node = node->NextOnLevel;
            }
            level++;
        } while (level <= 5);
    }

    if (MouseSystem != 0) {
        MouseSystem->Poll();
    }

    if (rge_base_game->prog_mode == ProgModeGame && this->have_focus != 0 && MouseSystem->get_game_enable() != 0) {
        unsigned long current_time = debug_timeGetTime((char*) s_C__msdev_work_age1_x1_view_cpp, 3857);
        tagPOINT CPoint;

        if (this->Get_Cursor_Position(CPoint, -save_render_rect.left, -save_render_rect.top) != 0) {
            int object_id;
            int picked = this->pick_touched_object(this->futur_objs, CPoint.x, CPoint.y, 10, 0x28, object_id);
            if (picked == 1) {
                int old_object_id = this->UC_TouchedObj;
                if (this->UC_ObjectTouched != 0 && old_object_id == object_id) {
                    goto no_mouse_process;
                }

                this->UC_ObjectTouched = 1;
                if (old_object_id == object_id) {
                    goto no_mouse_process;
                }

                this->UC_StartTime = current_time;
                this->UC_TouchedObj = object_id;
                {
                    int cursor_facet = 0;
                    int text_id = 0;
                    if (this->player->get_mouse_pointer_action_vars(object_id, cursor_facet, text_id) == 1) {
                        MouseSystem->set_game_facet(cursor_facet);
                        if (this->message_panel != 0 && rge_base_game->rollover != 0) {
                            char pText[128];
                            this->get_string(text_id, pText, 127);
                            this->message_panel->show_message(
                                TMessagePanel::InfoMessage, pText, TMessagePanel::RolloverColor, 0, 0, 0, 0
                            );
                        }
                        goto no_mouse_process;
                    }
                }

                MouseSystem->set_game_facet(0);
                if (this->message_panel != 0 && rge_base_game->rollover != 0) {
                    this->message_panel->remove_message();
                }
            } else if (this->UC_ObjectTouched != 0) {
                this->UC_ObjectTouched = 0;
                this->UC_TouchedObj = 0x80000000;
                MouseSystem->set_game_facet(0);
                if (this->message_panel != 0 && rge_base_game->rollover != 0) {
                    this->message_panel->remove_message();
                }
            }
        }
    }

no_mouse_process: {
    PanelNode* child_node = this->first_child_node;
    while (child_node != 0) {
        TPanel* child = child_node->panel;
        if (child->active != 0 && child->need_redraw != 0) {
            tagRECT child_rect;
            DClipInfo_Node* new_node;
            int left;
            int top;
            int right;
            int bottom;

            child->get_true_render_rect(child_rect);
            left = child_rect.left - save_render_rect.left;
            top = child_rect.top - save_render_rect.top;
            right = child_rect.right - save_render_rect.left;
            bottom = child_rect.bottom - save_render_rect.top;
            if (left < 0)
                left = 0;
            if (top < 0)
                top = 0;

            new_node = this->futur_objs->AddGDINode(
                3, bottom, left, top, right, bottom, 0, 0, 0, 0, 0x1e, child->display_changed_count, 0
            );
            if (new_node != 0) {
                DClipInfo_Node* tail = this->futur_objs->Draw_Level_Tail[0x1e];
                if (tail == 0) {
                    this->futur_objs->Draw_Level_Head[0x1e] = new_node;
                } else {
                    tail->NextOnLevel = new_node;
                }
                this->futur_objs->Draw_Level_Tail[0x1e] = new_node;
            }
        }
        child_node = child_node->next_node;
    }
}

    if (this->render_terrain_mode == 0) {
        int line = 0;
        if (this->save_area1->Height > 0) {
            do {
                this->Master_Clip_Mask->AddSpan(0, this->save_area1->Width - 1, line);
                line++;
            } while (line < this->save_area1->Height);
        }
        this->prior_objs->ReclaimAllNodes();
    } else {
        this->Master_Clip_Mask->Merge_n_Align(this->Terrain_Clip_Mask, this->Terrain_Fog_Clip_Mask);

        if (this->Limited_Render_Rect != 0) {
            if (this->Render_Rect1.left >= 0) {
                int line = this->Render_Rect1.top;
                if (line <= this->Render_Rect1.bottom) {
                    do {
                        this->Master_Clip_Mask->AddSpan(this->Render_Rect1.left, this->Render_Rect1.right, line);
                        line++;
                    } while (line <= this->Render_Rect1.bottom);
                }
            }
            if (this->Use_Rect2 != 0 && this->Render_Rect2.left >= 0) {
                int line = this->Render_Rect2.top;
                if (line <= this->Render_Rect2.bottom) {
                    do {
                        this->Master_Clip_Mask->AddSpan(this->Render_Rect2.left, this->Render_Rect2.right, line);
                        line++;
                    } while (line <= this->Render_Rect2.bottom);
                }
            }
        }

        {
            int line = 0;
            if (this->futur_objs->YLine_Size > 0) {
                do {
                    DClipInfo_Node* new_node = this->futur_objs->Draw_Clip_Nodes[line];
                    while (new_node != 0) {
                        if (new_node->Draw_Level > 5) {
                            DClipInfo_Node* old_node = this->prior_objs->Draw_Clip_Nodes[line];
                            int add_node = 1;
                            while (old_node != 0) {
                                int compare_size = new_node->Node_Type != 0 ? 0x34 : 0x24;
                                if (memcmp(&new_node->Shape, &old_node->Shape, compare_size) == 0) {
                                    add_node = 0;
                                    Clip_remove++;
                                    old_node->Node_Type = -1;
                                    break;
                                }
                                old_node = old_node->Next;
                            }

                            if (add_node != 0) {
                                if (new_node->Node_Type == 0) {
                                    this->Master_Clip_Mask->AddShape_Align(
                                        new_node->Shape_Base, new_node->Shape, new_node->Draw_X, new_node->Draw_Y,
                                        (new_node->Draw_Flag & 2) == 2
                                    );
                                    Clip_draw++;
                                } else {
                                    this->Add_GDI_Clip_Mask(new_node, this->Master_Clip_Mask);
                                }
                            }
                        }
                        new_node = new_node->Next;
                    }

                    {
                        DClipInfo_Node* old_node = this->prior_objs->Draw_Clip_Nodes[line];
                        while (old_node != 0) {
                            if (old_node->Draw_Level > 5 && old_node->Node_Type != -1) {
                                DClipInfo_Node* new_node2 = this->futur_objs->Draw_Clip_Nodes[line];
                                int add_node = 1;
                                while (new_node2 != 0) {
                                    int compare_size = old_node->Node_Type != 0 ? 0x34 : 0x24;
                                    if (memcmp(&new_node2->Shape, &old_node->Shape, compare_size) == 0) {
                                        add_node = 0;
                                        break;
                                    }
                                    new_node2 = new_node2->Next;
                                }

                                if (add_node != 0) {
                                    if (old_node->Node_Type == 0) {
                                        this->Master_Clip_Mask->AddShape_Align(
                                            old_node->Shape_Base, old_node->Shape, old_node->Draw_X, old_node->Draw_Y,
                                            (old_node->Draw_Flag & 2) == 2
                                        );
                                        Clip_draw++;
                                    } else {
                                        this->Add_GDI_Clip_Mask(old_node, this->Master_Clip_Mask);
                                    }
                                }
                            }
                            old_node = old_node->Next;
                        }
                    }
                    line++;
                } while (line < this->futur_objs->YLine_Size);
            }
        }
    }

    this->render_rect.left += save_render_rect.left;
    this->render_rect.top += save_render_rect.top;
    this->render_rect.right += save_render_rect.left;
    this->render_rect.bottom += save_render_rect.top;
    this->save_area1->PtrSpanCopy(
        this->render_area, this->render_rect.left, this->render_rect.top, &this->save_area1->ClipRect,
        (unsigned char**) this->Master_Clip_Mask->Line_Head_Ptrs
    );
    this->Update_Render_Pointers();
    this->render_rect.left -= save_render_rect.left;
    this->render_rect.top -= save_render_rect.top;
    this->render_rect.right -= save_render_rect.left;
    this->render_rect.bottom -= save_render_rect.top;

    ASMSet_Surface_Info(
        this->RenderOffsets, this->Master_Clip_Mask->Line_Head_Ptrs, this->Master_Clip_Mask->Line_Tail_Ptrs,
        this->Master_Clip_Mask->Min_Span_Px, this->Master_Clip_Mask->Min_Line, this->Master_Clip_Mask->Max_Span_Px,
        this->Master_Clip_Mask->Max_Line
    );
    this->render_area->CurSpanList = this->Master_Clip_Mask;

    {
        int level = 6;
        do {
            DClipInfo_Node* node = this->futur_objs->Draw_Level_Head[level];
            while (node != 0) {
                if (node->Node_Type == 0) {
                    int reset_shadowing = 0;
                    unsigned int shadow_flags = node->Draw_Flag & 0xffc;
                    if (shadow_flags != 0) {
                        if ((shadow_flags & 4) == 4) {
                            ASMSet_Shadowing(0x00ffffff, 0, 0xffff00ff, 0);
                        }
                        if ((shadow_flags & 8) == 8) {
                            unsigned int shade = ((int) shadow_flags >> 4) & 0xff;
                            unsigned int value = (shade << 16) | shade;
                            ASMSet_Shadowing(0xff00ff00, value, 0x00ff00ff, value << 8);
                        }
                        reset_shadowing = 1;
                    }

                    ASMSet_Color_Xform(node->Xform_Mask);
                    ASMSet_Xlate_Table(node->Color_Table);
                    ASMDraw_Sprite(
                        node->Shape_Base, node->Draw_X, node->Draw_Y, node->Shape->Width, node->Shape->Height,
                        node->Shape->Shape_Data_Offsets, node->Shape->Shape_Outline_Offset, node->Draw_Flag & 3
                    );

                    if (reset_shadowing != 0) {
                        ASMSet_Shadowing(0x00ff00ff, 0, 0xff00ff00, 0);
                    }
                } else {
                    this->Draw_GDI_Object(node, this->render_area);
                }
                node = node->NextOnLevel;
            }
            level++;
        } while (level <= 0x28);
    }

    if (view_debug_spans != 0 && this->render_terrain_mode != 0) {
        int color = frame_count % 0xdc + 0x10;
        int line = 0;
        if (this->render_area->Height > 0) {
            do {
                this->render_area->DrawLine(0, line, this->render_area->Width - 1, line, (unsigned char) color);
                line++;
            } while (line < this->render_area->Height);
        }
    }

    if (view_debug_palette != 0) {
        int row = 0;
        int y = 0x20;
        do {
            unsigned char col = 0;
            int x = 0;
            do {
                this->render_area->FillRect(
                    x, y, x + 0x1f, y + 0x0f, (unsigned char) (col + (unsigned char) row * 0x10)
                );
                x += 0x20;
                col++;
            } while (x < 0x200);
            y += 0x10;
            row++;
        } while (y < 0x120);
    }

    this->render_area->Unlock("view::view_function_terrain");
    this->render_area->CurSpanList = this->render_area->SpanList;

    {
        DClipInfo_List* temp = this->futur_objs;
        this->futur_objs = this->prior_objs;
        this->prior_objs = temp;
    }
    return 0;
}

void RGE_View::Update_Render_Pointers() {
    unsigned char* bits = render_area->Bits;

    if (LastRenderBits == bits) {
        int count = render_rect.bottom - render_rect.top + 1;
        if (LastRenderSize == count)
            return;
    }

    int count = render_rect.bottom - render_rect.top + 1;
    if (count <= 0 || bits == 0)
        return;

    if (count != LastRenderSize || RenderOffsets == 0) {
        if (RenderOffsets != 0)
            free(RenderOffsets);
        RenderOffsets = (void**) malloc(count * sizeof(void*));
        LastRenderSize = count;
    }

    for (int i = 0; i < count; i++) {
        RenderOffsets[i] =
            static_cast<unsigned char*>(render_area->DisplayOffsets[i + render_rect.top]) + render_rect.left;
    }
}

void RGE_View::Add_GDI_Clip_Mask(DClipInfo_Node* SDI, TSpan_List_Manager* Clip_Mask) {
    if (SDI->Node_Type == 1) {
        Clip_Mask->AddLine_Align(SDI->x1, SDI->y1, SDI->x2, SDI->y2);
        Clip_Mask->AddLine_Align(SDI->x2, SDI->y2, SDI->x3, SDI->y3);
        Clip_Mask->AddLine_Align(SDI->x3, SDI->y3, SDI->x4, SDI->y4);
        Clip_Mask->AddLine_Align(SDI->x4, SDI->y4, SDI->x1, SDI->y1);
        return;
    }
    int edge;
    if (SDI->Node_Type == 2 || SDI->Node_Type == 3) {
        int y1v;
        int y2v;
        int tmp;
        int y;

        int xl = SDI->x1 & ~3;
        edge = SDI->x2 | 3;
        y1v = SDI->y1;
        y2v = SDI->y2;
        if (y1v > y2v) {
            tmp = y1v;
            y1v = y2v;
            y2v = tmp;
        }
        if (y1v <= y2v) {
            y = y1v;
            do {
                Clip_Mask->AddSpan(xl, edge, y);
                y++;
            } while (y <= y2v);
        }
    }
    if (SDI->Node_Type == 4) {
        int y1v;
        int y2v;
        int x1v;
        int x2v;
        int tmp;
        int y;

        x1v = SDI->x1;
        x2v = SDI->x2;
        if (x1v > x2v) {
            tmp = x1v;
            x1v = x2v;
            x2v = tmp;
        }
        int xl = x1v & ~3;
        edge = x1v | 3;
        int right_edge = x2v & ~3;
        int xr = x2v | 3;
        y1v = SDI->y1;
        y2v = SDI->y2;
        if (y1v > y2v) {
            tmp = y1v;
            y1v = y2v;
            y2v = tmp;
        }
        Clip_Mask->AddSpan(xl, xr, y1v);
        Clip_Mask->AddSpan(xl, xr, y2v);
        y = y1v + 1;
        for (; y < y2v; y++) {
            Clip_Mask->AddSpan(xl, edge, y);
            Clip_Mask->AddSpan(right_edge, xr, y);
        }
    }
}

void RGE_View::draw_multi_object_outline() {
}

void RGE_View::Draw_GDI_Object(DClipInfo_Node* SDI, TDrawArea* render_area) {
    int i;

    if (SDI->Node_Type == 1) {
        render_area->DrawLine(SDI->x1, SDI->y1, SDI->x2, SDI->y2, SDI->Draw_Flag);
        render_area->DrawLine(SDI->x2, SDI->y2, SDI->x3, SDI->y3, SDI->Draw_Flag);
        render_area->DrawLine(SDI->x3, SDI->y3, SDI->x4, SDI->y4, SDI->Draw_Flag);
        render_area->DrawLine(SDI->x4, SDI->y4, SDI->x1, SDI->y1, SDI->Draw_Flag);
        return;
    }

    if (SDI->Node_Type == 2) {
        i = SDI->y1;
        if (i <= SDI->y2) {
            do {
                if (SDI->y3 != 0) {
                    render_area->DrawLine(SDI->x1, i, SDI->x3, i, 0x4A);
                }
                if (SDI->y4 != 0) {
                    render_area->DrawLine(SDI->x4, i, SDI->x2, i, 0x97);
                }
                i++;
            } while (i <= SDI->y2);
        }
    }

    if (SDI->Node_Type == 4) {
        render_area->DrawLine(SDI->x1, SDI->y1, SDI->x2, SDI->y1, 0xFF);
        render_area->DrawLine(SDI->x1, SDI->y2, SDI->x2, SDI->y2, 0xFF);
        render_area->DrawLine(SDI->x1, SDI->y1, SDI->x1, SDI->y2, 0xFF);
        render_area->DrawLine(SDI->x2, SDI->y1, SDI->x2, SDI->y2, 0xFF);
    }
}

int RGE_View::get_tile_mask_num(int map_col, int map_row, int map_width, int map_height, unsigned long VisibleMask) {
    unsigned int mask_number = 0;

    if (0 < map_col && 0 < map_row && map_col < map_width - 1 && map_row < map_height - 1) {
        if ((unified_map_offsets[map_row - 1][map_col] & VisibleMask) == 0)
            mask_number = 0x80;
        if ((unified_map_offsets[map_row][map_col + 1] & VisibleMask) == 0)
            mask_number |= 0x40;
        if ((unified_map_offsets[map_row + 1][map_col] & VisibleMask) == 0)
            mask_number |= 0x20;
        if ((unified_map_offsets[map_row][map_col - 1] & VisibleMask) == 0)
            mask_number |= 0x10;
        if ((unified_map_offsets[map_row - 1][map_col + 1] & VisibleMask) == 0)
            mask_number |= 0x08;
        if ((unified_map_offsets[map_row + 1][map_col + 1] & VisibleMask) == 0)
            mask_number |= 0x04;
        if ((unified_map_offsets[map_row + 1][map_col - 1] & VisibleMask) == 0)
            mask_number |= 0x02;
        if ((unified_map_offsets[map_row - 1][map_col - 1] & VisibleMask) == 0)
            mask_number |= 0x01;
    } else {
        if (0 < map_col && (unified_map_offsets[map_row][map_col - 1] & VisibleMask) == 0)
            mask_number = 0x10;
        int max_col = map_width - 1;
        if (map_col < max_col && (unified_map_offsets[map_row][map_col + 1] & VisibleMask) == 0)
            mask_number |= 0x40;
        if (0 < map_row && (unified_map_offsets[map_row - 1][map_col] & VisibleMask) == 0)
            mask_number |= 0x80;
        int max_row = map_height - 1;
        if (map_row < max_row && (unified_map_offsets[map_row + 1][map_col] & VisibleMask) == 0)
            mask_number |= 0x20;
        if (0 < map_col && 0 < map_row && (unified_map_offsets[map_row - 1][map_col - 1] & VisibleMask) == 0)
            mask_number |= 0x01;
        if (0 < map_col && map_row < max_row && (unified_map_offsets[map_row + 1][map_col - 1] & VisibleMask) == 0)
            mask_number |= 0x02;
        if (map_col < max_col && 0 < map_row && (unified_map_offsets[map_row - 1][map_col + 1] & VisibleMask) == 0)
            mask_number |= 0x08;
        if (map_col < max_col && map_row < max_row
            && (unified_map_offsets[map_row + 1][map_col + 1] & VisibleMask) == 0)
            mask_number |= 0x04;
    }

    return this->EdgeNumber[mask_number];
}

int RGE_View::draw_tile(
    RGE_Tile* tile, unsigned char terrain_type, short x, short y, short map_col, short map_row, unsigned char visible,
    int norm_draw, int fog_draw
) {
    unsigned char draw_attribute = tile->draw_attribute;

    if ((short) terrain_type >= this->map->num_terrain || this->map->terrain_types[terrain_type].loaded == 0) {
        return 0;
    }

    int draw_terrain = 1;
    int retval = 0;
    int draw_border = 0;
    unsigned char border_type = tile->border_type;
    int left_index;
    int right_index;
    int bottom_index;
    int top_index;

    if (border_type != 0 && this->map->border_types[border_type].loaded != 0
        && this->map->border_types[border_type].shape != 0) {
        if (this->map->border_types[border_type].border_style == 0) {
            short frame = this->get_border_picture(border_type, tile->tile_type, tile->border_shape, map_col, map_row);
            if (frame != -1) {
                draw_border = 1;
                draw_terrain = this->map->border_types[border_type].draw_tile;
            }
        } else if (this->get_border_edge_pictures(
                       border_type, tile->tile_type, tile->border_shape, map_col, map_row, left_index, bottom_index,
                       right_index, top_index
                   )
                   != 0) {
            draw_border = 1;
            draw_terrain = 1;
        }
    }

    if (View_Grid_Mode > 0 && (draw_attribute & 0xdf) == 0
        && (((map_col / View_Grid_Mode) + (map_row / View_Grid_Mode)) & 1) == 1) {
        draw_attribute |= 0x20;
    }

    if (view_debug_ObstructionMap != 0) {
        draw_border = 0;
    }

    if (draw_terrain != 0) {
        TShape* terrain_shape = this->map->terrain_types[terrain_type].shape;
        short frame = this->get_tile_picture(terrain_type, tile->tile_type, map_col, map_row);

        if (terrain_shape != 0 && frame != -1) {
            if (view_debug_ObstructionMap != 0) {
                this->draw_terrain_obstruction_map(x, y, terrain_shape, frame, map_col, map_row);
                return 1;
            }

            this->draw_terrain_shape(x, y, terrain_shape, frame, visible, draw_attribute, norm_draw, fog_draw);
            retval = 1;
        }

        if (draw_border == 0) {
            if (map_col > 0) {
                RGE_Tile* neighbor = this->map->map_row_offset[map_row] + map_col - 1;
                neighbor->draw_attribute |= 0x40;
            }
            if (map_row < this->map->map_height - 1) {
                RGE_Tile* neighbor = this->map->map_row_offset[map_row + 1] + map_col;
                neighbor->draw_attribute |= 0x40;
            }
        }
    }

    if (draw_border != 0) {
        TShape* border_shape = this->map->border_types[border_type].shape;
        if (border_shape != 0) {
            if (this->map->border_types[border_type].border_style == 0) {
                short frame =
                    this->get_border_picture(border_type, tile->tile_type, tile->border_shape, map_col, map_row);
                if (frame != -1) {
                    this->draw_terrain_shape(x, y, border_shape, frame, visible, draw_attribute, norm_draw, fog_draw);
                }
            } else if (this->get_border_edge_pictures(
                           border_type, tile->tile_type, tile->border_shape, map_col, map_row, left_index, bottom_index,
                           right_index, top_index
                       )
                       != 0) {
                if (left_index != -1) {
                    this->draw_terrain_shape(
                        x, y, border_shape, left_index, visible, draw_attribute, norm_draw, fog_draw
                    );
                }
                if (right_index != -1) {
                    this->draw_terrain_shape(
                        x, y, border_shape, right_index, visible, draw_attribute, norm_draw, fog_draw
                    );
                }
                if (bottom_index != -1) {
                    this->draw_terrain_shape(
                        x, y, border_shape, bottom_index, visible, draw_attribute, norm_draw, fog_draw
                    );
                }
                if (top_index != -1) {
                    this->draw_terrain_shape(
                        x, y, border_shape, top_index, visible, draw_attribute, norm_draw, fog_draw
                    );
                }
            }
        }

        if (map_col > 0) {
            RGE_Tile* neighbor = this->map->map_row_offset[map_row] + map_col - 1;
            neighbor->draw_attribute |= 0x40;
        }
        if (map_row < this->map->map_height - 1) {
            RGE_Tile* neighbor = this->map->map_row_offset[map_row + 1] + map_col;
            neighbor->draw_attribute |= 0x40;
        }
    }

    return retval;
}

void RGE_View::draw_terrain_shape(
    int x, int y, TShape* shape, int index, unsigned char visible, unsigned char draw_attribute, int draw_normal,
    int draw_fog
) {
    int draw_x = x - shape->shape_info[index].Hotspot_X;
    int draw_y = y - shape->shape_info[index].Hotspot_Y;

    if ((draw_attribute & 0x10) == 0x10) {
        fog_next_shape = 1;
        ASMSet_Shadowing(0x00ff00ff, 0x28002800, 0xff00ff00, 0x00280028);
        shape->shape_draw(this->cur_render_area, draw_x, draw_y, index, 0, 0);
        ASMSet_Shadowing(0x00ff00ff, 0, 0xff00ff00, 0);
        fog_next_shape = 0;
        return;
    }

    if ((draw_attribute & 0x20) == 0x20) {
        ASMSet_Shadowing(0x00ff00ff, 0x56005600, 0xff00ff00, 0x00560056);
    }

    if ((draw_attribute & 0x80) == 0x80) {
        int c = draw_attribute & 0x0f;
        int value = (((c << 16) + c) << 12) + 0x04000400;
        ASMSet_Shadowing(0x00ff00ff, value, 0xff00ff00, value);
    }

    int one = 1;
    int zero = 0;
    if (this->map->fog_flag != 0 && visible == 0x80) {
        fog_next_shape = one;
    }

    if (draw_fog != 0) {
        this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
        fog_next_shape = one;
        shape->shape_draw(this->cur_render_area, x, y, index, 0, 0);
        fog_next_shape = zero;
    }

    if ((draw_attribute & 0xa0) != 0) {
        fog_next_shape = one;
    }

    if (draw_normal != 0) {
        this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
        shape->shape_draw(this->cur_render_area, x, y, index, 0, 0);
    }

    this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
    ASMSet_Shadowing(0x00ff00ff, 0, 0xff00ff00, 0);
    fog_next_shape = zero;
}

void RGE_View::draw_terrain_obstruction_map(int x, int y, TShape* shape, int index, int TileX, int TileY) {
    int TileX4 = TileX * 4;
    TileY *= 4;

    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
    shape->shape_draw(this->cur_render_area, x, y, index, 0, 0);

    shape = rge_base_game->get_shape(0);

    TileX = 0;
    do {
        int TileY4 = 0;
        int draw_x_offset = TileX * 8;
        int draw_y_offset = TileX * 4;
        do {
            int obstruction = pathSystem.obstruction(TileY4 + TileX4, TileX + TileY);
            if (obstruction > 0) {
                shape->shape_draw(
                    this->cur_render_area, x + 2 + draw_x_offset, y + 0x0d + draw_y_offset, obstruction - 1, 0, 0
                );
            }
            ++TileY4;
            draw_x_offset += 8;
            draw_y_offset -= 4;
        } while (TileY4 < 4);
        ++TileX;
    } while (TileX < 4);
}

int RGE_View::Get_Cursor_Position(tagPOINT& Point, int adjustX, int adjustY) {
    GetCursorPos(&Point);
    TDrawSystem* draw_system = this->render_area->DrawSystem;
    if (draw_system->ScreenMode == 1) {
        ScreenToClient(this->render_area->Wnd, &Point);
        if (Point.x > 0x7FFF)
            Point.x -= 0x10000;
        if (Point.y > 0x7FFF)
            Point.y -= 0x10000;
    }
    Point.x += adjustX;
    Point.y += adjustY;

    if (Point.x < this->render_rect.left || Point.x > this->render_rect.right || Point.y < this->render_rect.top
        || Point.y > this->render_rect.bottom)
        return 0;
    return 1;
}

int RGE_View::Pick_Tile(long x, long y, int* Tile_X, int* Tile_Y) {
    int MapW;
    int MapH;
    int TileX;
    int TileY;
    int screenTileX;
    int bx1;
    int by1;
    int bx2;
    int by2;
    int Search;

    MapW = this->map->map_width;
    MapH = this->map->map_height;
    x += this->map_scr_x_offset - this->render_rect.left;
    y += this->map_scr_y_offset - this->render_rect.top;

    if (x < 0) {
        *Tile_X = -1;
        *Tile_Y = -1;
    } else if (x >= MapW * this->tile_wid) {
        *Tile_X = MapW + 1;
        *Tile_Y = MapH + 1;
    } else {
        screenTileX = x / this->tile_wid;
        TileY = y / this->tile_hgt;
        TileX = screenTileX + TileY;
        TileY = screenTileX - TileY;

        while (TileY < 0 || TileX >= MapW) {
            --TileX;
            ++TileY;
        }
        while (TileY >= MapH || TileX < 0) {
            ++TileX;
            --TileY;
        }

        Search = 1;
        while (Search) {
            this->get_tile_bounding_coords(TileX, TileY, bx1, by1, bx2, by2);
            if (y < by1) {
                ++TileX;
                --TileY;
            } else if (y > by2) {
                --TileX;
                ++TileY;
            } else {
                Search = 0;
            }
        }

        this->tile_half_hgt = 0;
        this->tile_half_wid = 0;
    }

    return 0;
}

void RGE_View::get_tile_bounding_coords(int Tile_X, int Tile_Y, int& bx1, int& by1, int& bx2, int& by2) {
    RGE_Tile* tile = &this->map->map_row_offset[Tile_Y][Tile_X];
    int screen_x = tile->screen_xpos;
    int tile_type = tile->tile_type;
    bx1 = screen_x;
    bx2 = this->map->tilesizes[tile_type].width + screen_x - 1;
    by1 = tile->screen_ypos - this->tile_half_hgt;
    this->tile_half_hgt = 0;
    this->tile_half_wid = 0;
    this->elev_hgt = 0;
    by2 = this->map->tilesizes[tile_type].height + by1 - 1;
}

int RGE_View::pick_objects(
    int Xpos, int Ypos, int min_level, int max_level, int range, int max_confidence, int ignoreNeg
) {
    if (range < 0 || max_level < min_level || Xpos < this->render_rect.left || Xpos > this->render_rect.right
        || Ypos < this->render_rect.top || Ypos > this->render_rect.bottom || min_level > 40 || max_level < 0) {
        return 0;
    }

    if (min_level < 0) {
        min_level = 0;
    }
    if (max_level > 40) {
        max_level = 40;
    }

    Xpos -= this->render_rect.left;
    Ypos -= this->render_rect.top;

    RGE_SPick_Info* head[5];
    RGE_SPick_Info* tail[5];
    RGE_SPick_Info* freep[5];
    int i;
    for (i = 1; i < 5; ++i) {
        head[i] = 0;
        tail[i] = 0;
        freep[i] = 0;
        this->pick_list_size[i] = 0;
    }

    for (int level = max_level; level >= min_level; --level) {
        DClipInfo_Node* clip = this->prior_objs->Draw_Level_Head[level];
        while (clip != 0) {
            int confidence = 0;

            //! @bug This drops every negative-ID node, so recyclable temporary units can never be picked.
            //! Class 11 and missiles get negative IDs by design, and editor picks all pass ignoreNeg = 1.
            //! Editor Delete mode relies on this pick alone, so arrows cannot be selected or removed.
            if (clip->Node_Type == 0 && (ignoreNeg == 0 || clip->Object_ID >= 0)) {
                int left = clip->x1;
                int top = clip->y1;
                int right = clip->x2;
                int bottom = clip->y2;

                if (Xpos >= left - range && Ypos >= top - range && Xpos <= right + range && Ypos <= bottom + range) {
                    confidence = 4;
                    if (Xpos >= left && Ypos >= top && Xpos <= right && Ypos <= bottom) {
                        confidence = 3;
                        int check_x;
                        if ((clip->Draw_Flag & 2) == 2) {
                            check_x = right - Xpos;
                        } else {
                            check_x = Xpos - left;
                        }

                        int check = this->sprite_check(clip->Shape_Base, clip->Shape, check_x, Ypos - top);
                        if (check == 1) {
                            confidence = 2;
                        } else if (check == 2) {
                            confidence = 1;
                        }
                    }
                }
            }

            if (confidence != 0 && confidence <= max_confidence) {
                short draw_level = clip->y3;
                int obj_id = clip->Object_ID;
                int add = 1;
                int old_confidence = 1;
                RGE_SPick_Info* old = 0;

                while (old == 0 && old_confidence < 5) {
                    old = head[old_confidence];
                    while (old != 0 && old->object_id != obj_id) {
                        old = old->next;
                    }
                    if (old == 0) {
                        ++old_confidence;
                    }
                }

                if (old != 0) {
                    if (old_confidence < confidence || (old_confidence == confidence && draw_level < old->draw_level)) {
                        add = 0;
                    }

                    if (add != 0) {
                        if (head[old_confidence] == old) {
                            head[old_confidence] = old->next;
                        }
                        if (tail[old_confidence] == old) {
                            tail[old_confidence] = old->prev;
                        }
                        if (old->next != 0) {
                            old->next->prev = old->prev;
                        }
                        if (old->prev != 0) {
                            old->prev->next = old->next;
                        }

                        old->next = freep[old_confidence];
                        old->prev = 0;
                        freep[old_confidence] = old;
                    }
                }

                if (add != 0) {
                    RGE_SPick_Info* pick = freep[confidence];
                    if (pick != 0) {
                        freep[confidence] = pick->next;
                    } else {
                        int size = this->pick_list_size[confidence];
                        if (size == 64) {
                            add = 0;
                        } else {
                            pick = this->pick_lists[confidence] + size;
                            this->pick_list_size[confidence] = size + 1;
                        }
                    }

                    if (add != 0) {
                        pick->object_id = obj_id;
                        pick->confidence = (short) confidence;
                        pick->draw_level = draw_level;
                        pick->draw_x = (short) clip->Draw_X;
                        pick->draw_y = (short) clip->Draw_Y;
                        pick->next = 0;
                        pick->prev = 0;

                        RGE_SPick_Info* at = head[confidence];
                        if (at == 0) {
                            head[confidence] = pick;
                            tail[confidence] = pick;
                        } else {
                            while (draw_level < at->draw_level && at->next != 0) {
                                at = at->next;
                            }

                            if (draw_level < at->draw_level) {
                                at->next = pick;
                                pick->prev = at;
                                tail[confidence] = pick;
                            } else {
                                pick->next = at;
                                pick->prev = at->prev;
                                if (at->prev == 0) {
                                    head[confidence] = pick;
                                } else {
                                    at->prev->next = pick;
                                }
                                at->prev = pick;
                            }
                        }
                    }
                }
            }

            clip = clip->NextOnLevel;
        }
    }

    int num_picked = 0;
    for (i = 1; i < 5; ++i) {
        RGE_SPick_Info* pick = head[i];
        while (pick != 0) {
            RGE_Pick_Obj_Info* output = &Picked_Objects[num_picked];
            int obj_id = pick->object_id;
            ++num_picked;
            output->object_id = obj_id;
            output->confidence = pick->confidence;
            output->draw_level = pick->draw_level;
            output->draw_x = pick->draw_x;
            output->draw_y = pick->draw_y;
            if (num_picked >= 64) {
                return 64;
            }
            pick = pick->next;
        }
    }

    return num_picked;
}

int RGE_View::sprite_check(uchar* Shape_Base, Shape_Info* Shape, int check_x, int check_y) {
    int width;
    if (Shape != 0) {
        if (check_x >= 0) {
            width = Shape->Width;
            if (check_x < width) {
                if (check_y >= 0) {
                    if (check_y < Shape->Height) {
                        uchar* outline = Shape_Base + Shape->Shape_Outline_Offset;
                        int r = *(short*) (outline + check_y * 4);
                        int right_pad = *(short*) (outline + check_y * 4 + 2);
                        if (r >= 0 && check_x >= r && check_x <= width - right_pad) {
                            int* data_offsets = (int*) (Shape_Base + Shape->Shape_Data_Offsets);
                            uchar* p = Shape_Base + data_offsets[check_y];
                            if (r < width) {
                                while (r < width) {
                                    if (check_x < r) {
                                        return 1;
                                    }
                                    unsigned int n;
                                    uchar command = *p;
                                    p++;
                                    unsigned char selector = command & 0x0F;
                                    switch (selector) {
                                        case 0:
                                        case 4:
                                        case 8:
                                        case 12:
                                            n = ((unsigned int) command) >> 2;
                                            r += n;
                                            if (check_x < r)
                                                goto ret2;
                                            p += n;
                                            break;
                                        case 2:
                                            n = (((unsigned int) command) << 4) | (unsigned int) (*p++);
                                            r += n;
                                            if (check_x < r)
                                                goto ret2;
                                            p += n;
                                            break;
                                        case 1:
                                        case 5:
                                        case 9:
                                        case 13:
                                            n = ((unsigned int) command) >> 2;
                                            r += n;
                                            break;
                                        case 3:
                                            n = (((unsigned int) command) << 4) | (unsigned int) (*p++);
                                            r += n;
                                            break;
                                        case 6:
                                            n = ((unsigned int) command) >> 4;
                                            if (n == 0)
                                                n = *p++;
                                            r += n;
                                            if (check_x < r)
                                                goto ret2;
                                            p += n;
                                            break;
                                        case 7:
                                        case 10:
                                            n = ((unsigned int) command) >> 4;
                                            if (n == 0)
                                                n = *p++;
                                            r += n;
                                            if (check_x < r)
                                                goto ret2;
                                            p++;
                                            break;
                                        case 11:
                                            n = ((unsigned int) command) >> 4;
                                            if (n == 0)
                                                n = *p++;
                                            r += n;
                                            if (check_x < r)
                                                goto ret2;
                                            break;
                                        case 14:
                                        case 15:
                                            goto ret0;
                                        default:
                                            return 1;
                                    }
                                }
                            }
                            return 1;
                        }
                    }
                }
            }
        }
    }
ret0:
    return 0;
ret2:
    return 2;
}

int RGE_View::pick_multi_objects(
    int Xpos1, int Ypos1, int Xpos2, int Ypos2, int min_level, int max_level, int player, unsigned char select_level,
    int ignoreNeg
) {
    int num_picked = 0;

    if (Xpos2 < this->render_rect.left || Xpos1 > this->render_rect.right || Ypos2 < this->render_rect.top
        || Ypos1 > this->render_rect.bottom || min_level > 0x28 || max_level < 0) {
        return 0;
    }

    if (min_level < 0) {
        min_level = 0;
    }
    if (max_level > 0x28) {
        max_level = 0x28;
    }

    Xpos1 -= this->render_rect.left;
    Xpos2 -= this->render_rect.left;
    Ypos1 -= this->render_rect.top;
    Ypos2 -= this->render_rect.top;

    RGE_Pick_Obj_Info* output = Picked_Objects;
    for (int level = max_level; level >= min_level; --level) {
        DClipInfo_Node* node = this->prior_objs->Draw_Level_Head[level];
        if (node == 0) {
            continue;
        }

        do {
            int found = 0;
            int object_id;
            if (node->Node_Type == 0) {
                object_id = node->Object_ID;
                if (object_id >= 0 && Xpos1 <= node->x2 && node->x1 <= Xpos2 && Ypos1 <= node->y2
                    && node->y1 <= Ypos2) {
                    RGE_Static_Object* object = this->world->objectsValue[object_id];
                    if ((player == -1 || object->owner->id == player) && object->object_state == RGE_OBJECT_STATE_ACTIVE
                        && object->master_obj->select_level >= select_level) {
                        found = 1;
                    }
                }
            }

            if (found != 0) {
                int add_it = 1;
                if (num_picked > 0) {
                    for (int i = 0; i < num_picked; ++i) {
                        if (Picked_Objects[i].object_id == object_id) {
                            add_it = 0;
                            if (Picked_Objects[i].confidence > found) {
                                Picked_Objects[i].confidence = (short) found;
                            }
                            break;
                        }
                    }
                }

                if (add_it != 0) {
                    output->object_id = object_id;
                    output->confidence = (short) found;
                    output->draw_level = (short) found;
                    output->draw_x = (short) node->Draw_X;
                    output->draw_y = (short) node->Draw_Y;
                    ++num_picked;
                    ++output;
                }

                if (output >= &Picked_Objects[64]) {
                    return 0x40;
                }
            }

            node = node->NextOnLevel;
        } while (node != 0);
    }

    return num_picked;
}

int RGE_View::pick_touched_object(
    DClipInfo_List* obj_list, int Xpos, int Ypos, int min_level, int max_level, int& touched_object_id
) {
    touched_object_id = 0;
    if (max_level >= min_level && Xpos >= this->render_rect.left && Xpos <= this->render_rect.right
        && Ypos >= this->render_rect.top && Ypos <= this->render_rect.bottom && min_level <= 0x28 && max_level >= 0) {
        if (min_level < 0) {
            min_level = 0;
        }
        if (max_level > 0x28) {
            max_level = 0x28;
        }
        int select = 0;
        int l = max_level;
        if (l >= min_level) {
            do {
                DClipInfo_Node* node = obj_list->Draw_Level_Head[l];
                if (node != 0) {
                    do {
                        if (node->Node_Type == 0) {
                            int flags = node->Draw_Flag;
                            int x1 = node->x1;
                            int y1 = node->y1;
                            int x2 = node->x2;
                            if ((flags & 2) == 2) {
                                if (this->sprite_check(node->Shape_Base, node->Shape, x2 - Xpos, Ypos - y1) == 2) {
                                    select = 1;
                                    touched_object_id = node->Object_ID;
                                }
                            } else {
                                if (this->sprite_check(node->Shape_Base, node->Shape, Xpos - x1, Ypos - y1) == 2) {
                                    select = 1;
                                    touched_object_id = node->Object_ID;
                                }
                            }
                        }
                        node = node->NextOnLevel;
                    } while (node != 0);
                }
                if (select == 1) {
                    return 1;
                }
                l--;
            } while (l >= min_level);
        }
    }
    return 0;
}

short RGE_View::get_tile_picture(unsigned char terrain_type, unsigned char tile_type, short map_col, short map_row) {
    unsigned char rows;
    unsigned char cols;
    RGE_Map* map = this->map;
    RGE_Tile_Set* ts = &map->terrain_types[terrain_type];
    if (ts->shape == 0)
        return -1;

    RGE_TOB_Picts* tile = &ts->tiles[tile_type];
    if (tile->count == 0)
        return -1;

    short result = 0;
    if (tile->count > 1) {
        rows = (unsigned char) ts->rows;
        cols = (unsigned char) ts->cols;
        if (rows > 1 || cols > 1) {
            terrain_type = rows > 0 ? (unsigned char) (map_row % rows) : 0;
            tile_type = cols > 0 ? (unsigned char) (map_col % cols) : 0;
            result = (unsigned short) terrain_type * (unsigned short) cols + (unsigned short) tile_type;
        }
    }

    if (result > tile->count - 1)
        result = 0;
    return (short) (tile->animations * result + tile->shape_index);
}

short RGE_View::get_border_picture(
    unsigned char border_type, unsigned char tile_type, unsigned char border_shape, short map_col, short map_row
) {
    RGE_Border_Set* bt = &this->map->border_types[border_type];
    if (bt->shape == 0)
        return -1;

    RGE_TOB_Picts* tile = &bt->borders[tile_type - 1][border_shape + 0xB];
    if (tile->count == 0)
        return -1;

    short result = 0;
    if (tile->count > 1) {
        short style = bt->border_style;
        if ((style == 0 && (border_shape == 0xB || border_shape == 0xC))
            || (style == 1 && (border_shape == 0x3 || border_shape == 0x2))) {
            result = map_row % tile->count;
        } else if ((style == 0 && (border_shape == 0x9 || border_shape == 0xA))
                   || (style == 1 && (border_shape == 0x1 || border_shape == 0x4))) {
            result = map_col % tile->count;
        } else {
            result = 0;
        }
    }

    if (result > tile->count - 1)
        result = 0;
    return (short) (tile->animations * result + tile->shape_index);
}

int RGE_View::get_border_edge_pictures(
    unsigned char border_type, unsigned char tile_type, unsigned char border_shape, short map_col, short map_row,
    int& top_index, int& right_index, int& left_index, int& bottom_index
) {
    top_index = -1;
    left_index = -1;
    right_index = -1;
    bottom_index = -1;

    if (this->map->border_types[border_type].shape && border_shape) {
        if (border_shape & 1) {
            short s = this->get_border_picture(border_type, tile_type, 1, map_col, map_row);
            top_index = (int) s;
        }
        if (border_shape & 2) {
            short s = this->get_border_picture(border_type, tile_type, 4, map_col, map_row);
            bottom_index = (int) s;
        }
        if (border_shape & 4) {
            short s = this->get_border_picture(border_type, tile_type, 3, map_col, map_row);
            left_index = (int) s;
        }
        if (border_shape & 8) {
            short s = this->get_border_picture(border_type, tile_type, 2, map_col, map_row);
            right_index = (int) s;
        }
        return 1;
    }
    return 0;
}

int RGE_View::hit_tile(RGE_Tile* tile, short x, short y, short map_col, short map_row, tagPOINT* mouse_pos) {
    short terrain_type = 0;
    short tile_type;

    if (tile) {
        tile_type = tile->tile_type;
        terrain_type = tile->terrain_type & 0x1F;
    } else {
        tile_type = 0;
    }

    if (mouse_pos->x >= x) {
        if (mouse_pos->x < x + this->map->tilesizes[(int) tile_type].width && mouse_pos->y >= y
            && mouse_pos->y < y + this->map->tilesizes[(int) tile_type].height) {
            RGE_Map* map = this->map;
            if (terrain_type < map->num_terrain && map->terrain_types[terrain_type].loaded) {
                TShape* sh = map->terrain_types[terrain_type].shape;
                short pic = this->get_tile_picture(terrain_type, (unsigned char) tile_type, map_col, map_row);

                if (sh == 0 || pic == -1)
                    goto outer_success;

                if (mouse_pos->y >= y + this->map->tilesizes[(int) tile_type].height)
                    goto failure;
                if (!sh->shape_check(mouse_pos->x - x, mouse_pos->y - y, pic))
                    goto failure;
                goto shape_success;

            shape_success:
                return 1;
            outer_success:
                return 1;
            failure:
                return 0;
            }
            return 1;
        }
    }

    return 0;
}

RGE_Static_Object* RGE_View::hit_object(
    RGE_Tile* tile, short x, short y, short map_col, short map_row, tagPOINT* mouse_pos, tagPOINT* start_mouse_pos,
    short* item_scr_x, short* item_scr_y, RGE_Static_Object* orig_picked_obj, unsigned char fog_flag
) {
    short frame_x;
    short frame_y;
    short frame_x2;
    short frame_y2;
    RGE_Object_Node* first;
    RGE_Static_Object* picked = 0;
    if (&tile->objects != 0) {
        first = tile->objects.sort();
        RGE_Object_Node* cur = first;
        short sx = x;
        short sy = y;
        RGE_Static_Object* obj;
        for (; cur != 0 && (obj = cur->node) != 0; cur = cur->next) {
            if (obj->object_state < RGE_OBJECT_STATE_PENDING_REMOVAL) {
                if ((!fog_flag || obj->master_obj->fog_flag) && obj->master_obj->select_level >= this->function_parm) {
                    if (this->function_mode == '+' || this->function_mode == ',') {
                        if (obj->owner == this->player) {
                            if (this->function_mode == ',') {
                                if (obj->box_hit_test(
                                        sx, sy, (short) start_mouse_pos->x, (short) start_mouse_pos->y,
                                        (short) mouse_pos->x, (short) mouse_pos->y
                                    )) {
                                    if (!this->player->select_one_object(obj, 0))
                                        break;
                                    picked = obj;
                                }
                            } else {
                                goto ordinary_hit;
                            }
                        }
                    } else {
                    ordinary_hit:
                        if (obj->hit_test(sx, sy, (short) mouse_pos->x, (short) mouse_pos->y, 5)) {
                            if (orig_picked_obj != 0 && obj == orig_picked_obj && picked != 0) {
                                return picked;
                            }
                            if (picked != 0 && obj->owner != this->player && picked->owner == this->player)
                                goto next;
                            if (picked != 0 && obj->master_obj->select_level < picked->master_obj->select_level)
                                goto next;
                            {
                                picked = obj;
                                if (!obj->get_frame(frame_x, frame_y, frame_x2, frame_y2)) {
                                    frame_x = 0;
                                    frame_y = 0;
                                }
                                *item_scr_x = (short) (obj->screen_x_offset + frame_x + sx);
                                *item_scr_y = (short) (obj->screen_y_offset + frame_y + sy);
                            }
                        }
                    }
                }
            }
        next:;
        }
        while (first != 0) {
            RGE_Object_Node* next_node = first->next;
            free(first);
            first = next_node;
        }
    }
    return picked;
}

int RGE_View::start_scroll_view(unsigned char scroll_action_in, long x, long y, int ctrl_key, int shift_key) {
    RGE_Pick_Info pick_info;
    int result;

    if (scroll_action_in == 3) {
        if (this->pick(0x28, 0, x, y, &pick_info, 0) != 0x33) {
            return 0;
        }
        long col = (long) pick_info.y;
        long row = (long) pick_info.x;
        this->set_selection_area(row, col, row, col);
    } else if (scroll_action_in == 9) {
        this->pick(0x28, 0, x, y, &pick_info, 0);
        this->real_old_map_col = (long) pick_info.x;
        this->real_old_map_row = (long) pick_info.y;
        if (!this->do_paint(x, y, x, y, 1)) {
            return 0;
        }
        this->set_redraw((TPanel::RedrawMode) 1);
    }

    result = 0;
    this->scroll_action = scroll_action_in;
    this->mouse_last_x = x;
    this->mouse_down_x = x;
    this->mouse_last_y = y;
    this->mouse_down_y = y;
    this->capture_mouse();

    if (this->scroll_action == 1 || this->scroll_action == 2 || this->scroll_action == 6 || this->scroll_action == 7
        || this->scroll_action == 8) {
        rge_base_game->mouse_off();
    }

    if (this->scroll_action == 2) {
        if (shift_key == 0 && ctrl_key == 0) {
            this->player->unselect_object();
        }
        this->set_redraw((TPanel::RedrawMode) 1);
    }

    if (this->scroll_action == 6 || this->scroll_action == 8) {
        if (this->pick(0x28, 0, x, y, &pick_info, 0) == 0x33) {
            this->player->set_view_loc(
                pick_info.x - g_view_pick_coordinate_offset, pick_info.y - g_view_pick_coordinate_offset
            );
            this->set_redraw((TPanel::RedrawMode) 1);
            result = 1;
        }
    }

    return result;
}

int RGE_View::handle_scroll_view(long x, long y) {
    RGE_Pick_Info pick_info;
    tagPOINT point;
    float save_view_x;
    float save_view_y;
    long save_mouse_last_x;
    long old_mouse_y;
    int move_view;
    long delta;

    if (x == this->mouse_last_x && y == this->mouse_last_y) {
        return 0;
    }

    save_view_x = this->player->view_x;
    save_view_y = this->player->view_y;

    switch (this->scroll_action) {
        case 2:
            this->mouse_last_x = x;
            this->mouse_last_y = y;
            this->bound_point(this->mouse_last_x, this->mouse_last_y);
            this->set_redraw((TPanel::RedrawMode) 1);
            return 0;

        case 6:
            if (this->is_inside(x, y) && this->pick(0x28, 0, x, y, &pick_info, 0) == 0x33) {
                this->player->set_view_loc(
                    pick_info.x - g_view_pick_coordinate_offset, pick_info.y - g_view_pick_coordinate_offset
                );
            }
            this->mouse_last_x = x;
            this->mouse_last_y = y;
            if (save_view_x == this->player->view_x && save_view_y == this->player->view_y) {
                return 0;
            }
            this->set_redraw((TPanel::RedrawMode) 1);
            return 1;

        case 7:
            delta = y - this->mouse_last_y;
            if (delta != 0 && delta < 100 && delta > -100) {
                short amount = (short) ((float) delta * g_view_tile_fraction_scale);
                this->player->map_y += amount;
                this->player->map_x -= amount;
            }

            delta = x - this->mouse_last_x;
            if (delta != 0 && delta < 100 && delta > -100) {
                short amount = (short) ((float) delta * g_view_tile_fraction_scale);
                this->player->map_y += amount;
                this->player->map_x += amount;
            }

            if (abs(y - this->mouse_down_y) <= 8 && abs(x - this->mouse_down_x) <= 8) {
                this->mouse_last_x = x;
                this->mouse_last_y = y;
            } else {
                point.x = this->mouse_down_x;
                point.y = this->mouse_down_y;
                ClientToScreen(this->render_area->Wnd, &point);
                SetCursorPos(point.x, point.y);
                this->mouse_last_x = this->mouse_down_x;
                this->mouse_last_y = this->mouse_down_y;
            }
            this->set_redraw((TPanel::RedrawMode) 1);
            return 1;

        case 8:
            delta = y - this->mouse_last_y;
            if (delta != 0 && delta < 100 && delta > -100) {
                long amount = (long) ((float) delta * g_view_tile_fraction_scale);
                this->player->set_view_loc(this->player->view_x - amount, this->player->view_y + amount);
            }

            delta = x - this->mouse_last_x;
            if (delta != 0 && delta < 100 && delta > -100) {
                long amount = (long) ((float) delta * g_view_tile_fraction_scale);
                this->player->set_view_loc(this->player->view_x + amount, this->player->view_y + amount);
            }

            if (abs(y - this->mouse_down_y) <= 8 && abs(x - this->mouse_down_x) <= 8) {
                this->mouse_last_x = x;
                this->mouse_last_y = y;
            } else {
                point.x = this->mouse_down_x;
                point.y = this->mouse_down_y;
                ClientToScreen(this->render_area->Wnd, &point);
                SetCursorPos(point.x, point.y);
                this->mouse_last_x = this->mouse_down_x;
                this->mouse_last_y = this->mouse_down_y;
            }

            if (save_view_x == this->player->view_x && save_view_y == this->player->view_y) {
                return 0;
            }
            this->set_redraw((TPanel::RedrawMode) 1);
            return 1;
    }

    if (this->scroll_action == 3 || this->scroll_action == 4 || this->scroll_action == 9) {
        move_view = (x < this->clip_rect.left + 64 && x < this->mouse_last_x)
                    || (x > this->clip_rect.right - 64 && x > this->mouse_last_x)
                    || (y < this->clip_rect.top + 32 && y < this->mouse_last_y)
                    || (y > this->clip_rect.bottom - 32 && y > this->mouse_last_y);
    } else {
        move_view = 1;
    }

    delta = y - this->mouse_last_y;
    if (delta != 0 && delta < 200 && delta > -200 && move_view) {
        this->player->set_view_loc(
            this->player->view_x - (float) delta * g_view_scroll_fraction_scale,
            this->player->view_y + (float) delta * g_view_scroll_fraction_scale
        );
    }

    delta = x - this->mouse_last_x;
    if (delta != 0 && delta < 200 && delta > -200 && move_view) {
        this->player->set_view_loc(
            this->player->view_x + (float) delta * g_view_scroll_fraction_scale,
            this->player->view_y + (float) delta * g_view_scroll_fraction_scale
        );
    }

    save_mouse_last_x = this->mouse_last_x;
    old_mouse_y = this->mouse_last_y;
    this->mouse_last_x = x;
    this->mouse_last_y = y;

    if (move_view) {
        if (abs(y - this->mouse_down_y) > 8 || abs(x - this->mouse_down_x) > 8) {
            point.x = this->mouse_down_x;
            point.y = this->mouse_down_y;
            ClientToScreen(this->render_area->Wnd, &point);
            SetCursorPos(point.x, point.y);
            this->mouse_last_x = this->mouse_down_x;
            this->mouse_last_y = this->mouse_down_y;
        }
    } else {
        this->mouse_down_x = x;
        this->mouse_down_y = y;
    }

    if (this->scroll_action == 3) {
        if (this->pick(0x28, 0, x, y, &pick_info, 0) == 0x33 && this->player != 0) {
            this->set_selection_area(this->sel_col1, this->sel_row1, (long) pick_info.x, (long) pick_info.y);
        }
    } else if (this->scroll_action == 4) {
        if (this->player->selected_obj != 0 && this->pick(0x28, 0, x, y, &pick_info, 0) == 0x33) {
            this->player->selected_obj->teleport(pick_info.x, pick_info.y, 0);
            unsigned char draw_level;
            if (this->player->selected_obj->sprite_list != 0) {
                draw_level = this->player->selected_obj->sprite_list->get_lowest_draw_level();
            } else if (this->player->selected_obj->sprite != 0) {
                draw_level = this->player->selected_obj->sprite->get_lowest_draw_level();
            } else {
                draw_level = 20;
            }
            if (draw_level == 0) {
                this->set_redraw((TPanel::RedrawMode) 2);
            } else {
                this->set_redraw((TPanel::RedrawMode) 1);
            }
        }
    } else if (this->scroll_action == 9) {
        this->do_paint(save_mouse_last_x, old_mouse_y, x, y, 2);
        this->set_redraw((TPanel::RedrawMode) 1);
    }

    if (save_view_x == this->player->view_x && save_view_y == this->player->view_y) {
        return 0;
    }
    this->set_redraw((TPanel::RedrawMode) 1);
    return 1;
}

void RGE_View::end_scroll_view() {
    long min_x, max_x, min_y, max_y;

    switch (this->scroll_action) {
        case 2:
            if (this->mouse_down_x > this->mouse_last_x) {
                min_x = this->mouse_last_x;
                max_x = this->mouse_down_x;
            } else {
                min_x = this->mouse_down_x;
                max_x = this->mouse_last_x;
            }
            if (this->mouse_down_y > this->mouse_last_y) {
                min_y = this->mouse_last_y;
                max_y = this->mouse_down_y;
            } else {
                min_y = this->mouse_down_y;
                max_y = this->mouse_last_y;
            }
            this->pick_multi(4, min_x, min_y, max_x, max_y);
            this->set_redraw((TPanel::RedrawMode) 1);
            break;

        case 1:
        case 6:
        case 7:
        case 8: {
            tagPOINT point;
            point.x = this->mouse_down_x;
            point.y = this->mouse_down_y;
            ClientToScreen(this->render_area->Wnd, &point);
            SetCursorPos(point.x, point.y);
            break;
        }

        case 9:
            this->do_paint(this->mouse_down_x, this->mouse_down_y, this->mouse_down_x, this->mouse_down_y, 0);
            this->set_redraw((TPanel::RedrawMode) 1);
            break;

        case 3:
        case 4:
        case 5:
            break;
    }

    if (this->scroll_action == 1 || this->scroll_action == 2 || this->scroll_action == 6 || this->scroll_action == 7
        || this->scroll_action == 8) {
        rge_base_game->mouse_on();
    }

    this->release_mouse();
    this->scroll_action = 0;
}

int RGE_View::do_paint(long old_x, long old_y, long new_x, long new_y, int up_down) {
    RGE_Pick_Info pick_info;
    long new_col;
    long new_row;
    int mode;
    short brush;

    if (this->pick(0x28, 0, new_x, new_y, &pick_info, 0) != 0x33) {
        return 0;
    }

    new_col = (long) pick_info.x;
    new_row = (long) pick_info.y;
    this->pick(0x28, 0, old_x, old_y, &pick_info, 0);

    mode = rge_base_game->game_mode;
    brush = rge_base_game->brush_size;
    //! The terrain brush requests no immediate redraw here; the cliff brush does (case 0x13).
    //! The cached terrain buffer then keeps stale pixels for tiles the redraw marks miss.
    //! Hidden (unloaded) terrain ids hit early returns and show only after a forced rebuild.
    switch (mode) {
        case 9:
            if (up_down != 0) {
                short terrain_id = rge_base_game->terrain_id;
                if (terrain_id != -1) {
                    this->map->do_terrain_brush_stroke(
                        this->real_old_map_col, this->real_old_map_row, new_col, new_row, brush, terrain_id
                    );
                }
            }
            break;
        case 10:
            if (up_down != 0) {
                short elevation_height = rge_base_game->elevation_height;
                if (elevation_height != -1) {
                    this->map->do_elevation_brush_stroke(
                        this->real_old_map_col, this->real_old_map_row, new_col, new_row, brush, elevation_height
                    );
                }
            }
            break;
        case 0x13:
            if (rge_base_game->sub_game_mode == 1) {
                this->map->do_cliff_brush_stroke(
                    this->real_old_map_col, this->real_old_map_row, new_col, new_row, 0, 1
                );
            } else {
                this->map->do_cliff_brush_stroke(
                    this->real_old_map_col, this->real_old_map_row, new_col, new_row, 0, 0
                );
            }
            this->set_redraw(TPanel::RedrawImmediate);
            break;
    }

    this->real_old_map_row = new_row;
    this->real_old_map_col = new_col;
    return 1;
}

void RGE_View::reset_overlay_sprites(void) {
    Ov_Sprite_Draw_Rec* sprite;
    Ov_Sprite_Draw_Rec* next;

    sprite = extra_sprites;
    while (sprite != 0) {
        next = sprite->next;
        delete sprite;
        sprite = next;
    }
    extra_sprites = 0;
}

void RGE_View::reset_cyclic_overlay_sprites(void) {
    Ov_Sprite_Draw_Rec* sprite;
    Ov_Sprite_Draw_Rec* next;

    sprite = extra_sprites;
    while (sprite != 0) {
        if (sprite->displayfunction == 1) {
            if (sprite->prev != 0) {
                sprite->prev->next = sprite->next;
            }
            if (sprite->next != 0) {
                sprite->next->prev = sprite->prev;
            }
            if (sprite->prev == 0) {
                extra_sprites = sprite->next;
            }
            next = sprite->next;
            delete sprite;
            sprite = next;
        } else {
            sprite = sprite->next;
        }
    }
}

void RGE_View::add_overlay_sprite(
    TShape* theShape, int facet, int x, int y, int flags, int drawlevel, unsigned char* colorTable, int dispFunc,
    unsigned long DrawInterval
) {
    Ov_Sprite_Draw_Rec* sprite;
    Ov_Sprite_Draw_Rec* head;

    sprite = new Ov_Sprite_Draw_Rec;
    if (sprite != 0) {
        head = extra_sprites;
        sprite->prev = 0;
        sprite->next = head;
        if (head != 0) {
            head->prev = sprite;
        }
        extra_sprites = sprite;
        sprite->theShape = theShape;
        sprite->thefacet = facet;
        sprite->world_x = x;
        sprite->world_y = y;
        sprite->flags = flags;
        sprite->drawLevel = drawlevel;
        sprite->colortable = colorTable;
        sprite->displayfunction = dispFunc;
        sprite->DrawTimeInterval = DrawInterval;
        sprite->LastDrawTime = 0;
    }
}

bool RGE_View::Object_Was_Displayed(int ObjectID, bool InFogOK) {
    DClipInfo_Node* node;

    node = prior_objs->LocateIDbyDrawLevel(ObjectID, 6, 0x28, 0);
    if (node == 0) {
        return false;
    }
    if (!InFogOK && (node->Draw_Flag & 1) != 0) {
        return false;
    }
    return true;
}

DClipInfo_List::DClipInfo_List(
    int InitialSize, int GrowSize, int szitem, int top_Yline, int bottom_Yline, int mxLevel
) {
    int yline_offset;
    int yline_size;

    Free_Pool_Zone = -1;
    Free_Pool_Index = -1;
    Default_Grow_Size = GrowSize;
    Element_Size = szitem;
    yline_offset = -top_Yline;
    yline_size = (bottom_Yline - top_Yline) + 1;
    Zone_Ptrs = 0;
    Zone_Size_Ptrs = 0;
    Max_Zones = 8;
    Used_Zones = 0;
    Free_Head = 0;
    Total_Blocks = 0;
    Free_Blocks = 0;
    YLine_Offset = yline_offset;
    YLine_Size = yline_size;
    Max_Draw_Levels = mxLevel;
    SetCaptureLevel(0, mxLevel);
    Draw_Clip_Nodes = (DClipInfo_Node**) calloc(YLine_Size, sizeof(DClipInfo_Node*));
    Draw_Level_Head = (DClipInfo_Node**) calloc(Max_Draw_Levels + 1, sizeof(DClipInfo_Node*));
    Draw_Level_Tail = (DClipInfo_Node**) calloc(Max_Draw_Levels + 1, sizeof(DClipInfo_Node*));
    ResetStats();
    SetNumZones(8);
    InitNewZone(InitialSize);
    Select_Box = 0;
}
DClipInfo_List::~DClipInfo_List(void) {
    int i;

    i = 0;
    if (Used_Zones > 0) {
        do {
            if (Zone_Ptrs[i] != 0) {
                free(Zone_Ptrs[i]);
            }
            i = i + 1;
        } while (i < Used_Zones);
    }
    if (Zone_Ptrs != 0) {
        free(Zone_Ptrs);
    }
    if (Zone_Size_Ptrs != 0) {
        free(Zone_Size_Ptrs);
    }
    if (Draw_Clip_Nodes != 0) {
        free(Draw_Clip_Nodes);
    }
    if (Draw_Level_Head != 0) {
        free(Draw_Level_Head);
    }
    if (Draw_Level_Tail != 0) {
        free(Draw_Level_Tail);
    }
}

void DClipInfo_List::SetCaptureLevel(int minLevel, int maxLevel) {
    int temp;

    if (minLevel > maxLevel) {
        temp = minLevel;
        minLevel = maxLevel;
        maxLevel = temp;
    }
    if (minLevel < 0) {
        minLevel = 0;
    }
    if (maxLevel > Max_Draw_Levels) {
        maxLevel = Max_Draw_Levels;
    }
    Accept_Min_Level = minLevel;
    Accept_Max_Level = maxLevel;
}
void DClipInfo_List::SetNumZones(int New_Size) {
    DClipInfo_Node** Ptrs;
    int* new_zone_sizes;
    int i;

    if (New_Size >= Max_Zones) {
        Ptrs = (DClipInfo_Node**) calloc(New_Size, 4);
        new_zone_sizes = (int*) calloc(New_Size, sizeof(int));
        if (Zone_Ptrs != 0) {
            i = 0;
            if (Used_Zones > 0) {
                do {
                    Ptrs[i] = Zone_Ptrs[i];
                    new_zone_sizes[i] = Zone_Size_Ptrs[i];
                    i = i + 1;
                } while (i < Used_Zones);
            }
            free(Zone_Ptrs);
            free(Zone_Size_Ptrs);
        }
        Zone_Ptrs = Ptrs;
        Zone_Size_Ptrs = new_zone_sizes;
        Max_Zones = New_Size;
    }
}
void DClipInfo_List::InitNewZone(int Zone_Size) {
    int zone_index;
    unsigned int alloc_size;

    if (Used_Zones == Max_Zones) {
        SetNumZones(Used_Zones + 4);
    }
    zone_index = Used_Zones;
    Used_Zones = zone_index + 1;
    alloc_size = Element_Size * Zone_Size;
    Zone_Size_Ptrs[zone_index] = Zone_Size;
    Zone_Ptrs[zone_index] = (DClipInfo_Node*) malloc(alloc_size);
    NewZone_Count = NewZone_Count + 1;
    Total_Blocks = Total_Blocks + Zone_Size;
    Free_Blocks = Free_Blocks + Zone_Size;
    if (Free_Pool_Zone == -1) {
        Free_Pool_Zone = zone_index;
        Free_Pool_Index = 0;
    }
}

DClipInfo_Node* DClipInfo_List::GetNode(void) {
    DClipInfo_Node* node;

    if (Free_Blocks == 0) {
        InitNewZone(Default_Grow_Size);
    }
    node = Free_Head;
    if (node != 0) {
        Free_Head = node->Next;
        Free_Blocks = Free_Blocks - 1;
        return node;
    }
    node = Zone_Ptrs[Free_Pool_Zone] + Free_Pool_Index;
    Free_Blocks = Free_Blocks - 1;
    Free_Pool_Index = Free_Pool_Index + 1;
    if (Free_Pool_Index == Zone_Size_Ptrs[Free_Pool_Zone]) {
        Free_Pool_Zone = Free_Pool_Zone + 1;
        Free_Pool_Index = 0;
        if (Free_Pool_Zone == Used_Zones) {
            Free_Pool_Zone = -1;
        }
    }
    return node;
}

void DClipInfo_List::SetDrawRegion(int Left, int Top, int Right, int Bottom) {
    if (Left <= Right) {
        if (Top <= Bottom) {
            SD_XMin = Left;
            SD_XMax = Right;
            SD_YMin = Top;
            SD_YMax = Bottom;
        }
    }
}

void DClipInfo_List::AddDrawNode(
    void* ShapeBase, Shape_Info* theShape, int SortLine, int Xpos, int Ypos, int DrawFlags, unsigned char* ColorTable,
    int XformMask, int DrawLevel, int Object_ID
) {
    int line = this->YLine_Offset + SortLine;

    if (DrawLevel > this->Accept_Max_Level)
        return;
    if (DrawLevel < this->Accept_Min_Level)
        return;

    Shape_Info* shp = theShape;
    int right;
    int bottom;
    int HotX;
    int HotY;
    right = Xpos + shp->Width - 1;
    bottom = Ypos + shp->Height - 1;
    HotX = Xpos + shp->Hotspot_X;
    HotY = Ypos + shp->Hotspot_Y;

    if (!(Xpos <= this->SD_XMax && right >= this->SD_XMin && Ypos <= this->SD_YMax && bottom >= this->SD_YMin
          && line >= 0 && line < this->YLine_Size))
        return;

    DClipInfo_Node* node = this->GetNode();
    DClipInfo_Node** list = this->Draw_Clip_Nodes + line;
    DClipInfo_Node* cur = *list;
    if (cur == 0) {
        *list = node;
    } else {
        while (cur->Next != 0)
            cur = cur->Next;
        cur->Next = node;
    }

    node->Next = 0;
    node->NextOnLevel = 0;
    node->Object_ID = Object_ID;
    node->Draw_Flag = DrawFlags;
    node->Shape_Base = (unsigned char*) ShapeBase;
    node->Color_Table = ColorTable;
    node->Xform_Mask = XformMask;
    node->Shape = shp;
    node->Draw_X = Xpos;
    node->Draw_Y = Ypos;
    node->Draw_Level = DrawLevel;
    node->Node_Type = 0;

    if (this->Select_Box != 0) {
        node->x1 = (short) (HotX + this->Select_Box[0]);
        node->y1 = (short) (this->Select_Box[1] + HotY);
        node->x2 = (short) (this->Select_Box[2] + HotX);
        node->y2 = (short) (this->Select_Box[3] + HotY);
        this->Select_Box = 0;
    } else {
        node->x1 = (short) Xpos;
        node->y1 = (short) Ypos;
        node->x2 = (short) (Xpos + shp->Width - 1);
        node->y2 = (short) (Ypos + shp->Height - 1);
    }

    node->x3 = (short) HotX;
    node->y3 = (short) HotY;
    node->x4 = 0;
    node->y4 = 0;
}

DClipInfo_Node* DClipInfo_List::AddGDINode(
    int GDI_Type, int SortLine, int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4, int DrawLevel,
    int DrawColor, int Object_ID
) {
    int line_index = YLine_Offset + SortLine;

    if (DrawLevel > Accept_Max_Level || DrawLevel < Accept_Min_Level || line_index < 0 || line_index >= YLine_Size)
        return 0;

    DClipInfo_Node* node = GetNode();
    node->Next = Draw_Clip_Nodes[line_index];
    Draw_Clip_Nodes[line_index] = node;

    node->Object_ID = Object_ID;
    node->Draw_Flag = DrawColor;
    node->Node_Type = GDI_Type;
    node->x1 = X1;
    node->y1 = Y1;
    node->x2 = X2;
    node->y2 = Y2;
    node->x3 = X3;
    node->y3 = Y3;
    node->NextOnLevel = 0;
    node->Shape = 0;
    node->Draw_X = 0;
    node->Draw_Y = 0;
    node->Shape_Base = 0;
    node->Color_Table = 0;
    node->Xform_Mask = 0;
    node->Draw_Level = DrawLevel;
    node->x4 = X4;
    node->y4 = Y4;

    return node;
}

DClipInfo_Node* DClipInfo_List::LocateIDbyDrawLevel(int SearchID, int StartLevel, int EndLevel, int NodeType) {
    if (StartLevel > EndLevel) {
        int temp = StartLevel;
        StartLevel = EndLevel;
        EndLevel = temp;
    }

    if (StartLevel < 0) {
        StartLevel = 0;
    }

    int max_levels = this->Max_Draw_Levels;
    if (EndLevel > max_levels) {
        EndLevel = max_levels;
    }

    if (StartLevel <= max_levels && EndLevel >= 0) {
        int level = StartLevel;
        if (StartLevel <= EndLevel) {
            DClipInfo_Node** head_ptr = this->Draw_Level_Head + StartLevel;
            do {
                DClipInfo_Node* node = *head_ptr;
                while (node) {
                    if (node->Object_ID == SearchID && node->Node_Type == NodeType) {
                        return node;
                    }
                    node = node->NextOnLevel;
                }
                level++;
                head_ptr++;
            } while (level <= EndLevel);
        }
    }

    return 0;
}

void DClipInfo_List::Scroll(int xDelta, int yDelta) {
    if (yDelta > 0) {
        int i = 0;
        if (this->YLine_Size - yDelta > 0) {
            do {
                int next = i + 1;
                this->Draw_Clip_Nodes[i] = this->Draw_Clip_Nodes[i + yDelta];
                i = next;
            } while (i < this->YLine_Size - yDelta);
        }

        i = this->YLine_Size - yDelta;
        if (i < this->YLine_Size) {
            do {
                int next = i + 1;
                this->Draw_Clip_Nodes[i] = 0;
                i = next;
            } while (i < this->YLine_Size);
        }
    }

    if (yDelta < 0) {
        int neg = -yDelta;
        int i = this->YLine_Size - 1;
        int source = this->YLine_Size - 1 + yDelta;

        if (i >= neg) {
            do {
                this->Draw_Clip_Nodes[i] = this->Draw_Clip_Nodes[source];
                i = i - 1;
                source = source - 1;
            } while (i >= neg);
        }

        i = 0;
        if (neg > 0) {
            do {
                int next = i + 1;
                this->Draw_Clip_Nodes[i] = 0;
                i = next;
            } while (i < neg);
        }
    }

    int i = 0;
    if (this->YLine_Size > 0) {
        do {
            DClipInfo_Node* node = this->Draw_Clip_Nodes[i];

            while (node != 0) {
                switch (node->Node_Type) {
                    case 0:
                        node->Draw_X -= xDelta;
                        node->Draw_Y -= yDelta;
                        break;

                    case 1:
                        node->y3 -= (short) yDelta;
                        node->y4 -= (short) yDelta;

                    case 2:
                        node->x3 -= (short) xDelta;
                        node->x4 -= (short) xDelta;

                    case 3:
                    case 4:
                        node->x1 -= (short) xDelta;
                        node->y1 -= (short) yDelta;
                        node->x2 -= (short) xDelta;
                        node->y2 -= (short) yDelta;
                        break;
                }

                node = node->Next;
            }

            i = i + 1;
        } while (i < this->YLine_Size);
    }
}

void DClipInfo_List::FreeNode(DClipInfo_Node* theNode) {
    theNode->Next = Free_Head;
    Free_Head = theNode;
    Free_Blocks = Free_Blocks + 1;
}

int DClipInfo_List::FreeThread(DClipInfo_Node* HeadNode, DClipInfo_Node* TailNode) {
    int count = 0;
    DClipInfo_Node* cur = HeadNode;
    if (HeadNode == 0)
        return 0;
    if (TailNode == 0) {
        do {
            TailNode = cur;
            ++this->Free_Blocks;
            ++count;
            cur = cur->Next;
        } while (cur != 0);
    } else {
        do {
            ++this->Free_Blocks;
            ++count;
            if (cur != TailNode)
                cur = cur->Next;
            else
                cur = 0;
        } while (cur != 0);
    }
    TailNode->Next = this->Free_Head;
    this->Free_Head = HeadNode;
    return count;
}
void DClipInfo_List::ReclaimAllNodes(void) {
    memset(Draw_Clip_Nodes, 0, YLine_Size * 4);
    memset(Draw_Level_Head, 0, (Max_Draw_Levels * 4) + 4);
    memset(Draw_Level_Tail, 0, (Max_Draw_Levels * 4) + 4);
    Free_Head = 0;
    Free_Pool_Zone = 0;
    Free_Pool_Index = 0;
    Free_Blocks = Total_Blocks;
    Reset_Count = Reset_Count + 1;
}

void DClipInfo_List::ResetStats() {
    this->Alloc_Count = 0;
    this->Dealloc_Count = 0;
    this->NewZone_Count = 0;
    this->Reset_Count = 0;
}
