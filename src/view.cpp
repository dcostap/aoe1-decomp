#include <windows.h>
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
#include "../include/world.h"

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

RGE_View::RGE_View()
{
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
    this->set_selection_area(-1,-1,-1,-1);
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
    this->DispSel_List =
        (DisplaySelectedObjRec*)calloc(8, sizeof(DisplaySelectedObjRec));
}

RGE_View::~RGE_View()
{
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

    if (this->Tile_Edge_Tables != 0) free(this->Tile_Edge_Tables);
    if (this->Black_Edge_Tables != 0) free(this->Black_Edge_Tables);
    if (this->Float_Scroll_Offsets != 0) free(this->Float_Scroll_Offsets);
    if (this->Blit_Queue != 0) free(this->Blit_Queue);

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

    if (this->DispSel_List != 0) free(this->DispSel_List);

    this->reset_overlay_sprites();
    this->TPanel::~TPanel();
}

long RGE_View::setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h, unsigned char flag, int calc_count, char* shape_name)
{
    char str[260];

    TPanel::setup(draw, parent, x, y, w, h, flag);

    this->cur_render_area = 0;
    this->calc_draw_count = calc_count;
    this->start_scr_col = 0;
    this->start_scr_row = 0;
    this->start_map_col = 0;
    this->start_map_row = 0;
    this->last_view_x = -9999.0f;
    this->last_view_y = -9999.0f;
    this->function_mode = 0;

    this->white_pen = GetStockObject(6);
    this->red_pen = CreatePen(0, 1, 0xff);
    this->hollow_brush = GetStockObject(5);

    sprintf(str, "%s.shp", shape_name);
    this->border_line_shape = new TShape(str, -1);

    this->Init_Tile_Edge_Tables();

    int i = 5;
    do {
        int index = 5 - i;
        this->pick_lists[index] =
            (RGE_SPick_Info*)calloc(0x40, sizeof(RGE_SPick_Info));
        this->pick_list_size[index] = 0;
        i--;
    } while (i != 0);

    return 1;
}


void RGE_View::set_focus(int focus) {
    this->TPanel::set_focus(focus);
    if (MouseSystem != 0) {
        MouseSystem->set_game_enable(this->have_focus);
    }
}

static const char s_tile_file[] = "DATA2\\TILEEDGE.DAT";
static const char s_black_tile_file[] = "DATA2\\BLKEDGE.DAT";

void RGE_View::Init_Tile_Edge_Tables()
{
    int fd, len;
    int i, j;
    Tile_FogEdge_Table* fog_table;
    Tile_BlackEdge_Table* black_table;
    int base;
    int count;
    int ok;
    Tile_BlackEdge_Table** black_roots;

    fd = _open(s_tile_file, _O_BINARY);
    if (fd != -1) {
        _lseek(fd,0,SEEK_END); len = _tell(fd); this->Tile_Edge_Tables = (Tile_FogEdge_Table**)calloc(1,len); _lseek(fd,0,SEEK_SET); _read(fd,this->Tile_Edge_Tables,len); _close(fd);
        base = (int)this->Tile_Edge_Tables;
        unsigned char* tile_edge_data = (unsigned char*)this->Tile_Edge_Tables;
        for (i=0;i<0x44;i+=4)
            *(int*)(tile_edge_data + i) += base;
        for (i=0;i<0x44;i+=4) {
            fog_table = *(Tile_FogEdge_Table**)(tile_edge_data + i);
            for (j=0;j<0x2f;j++) {
                if (fog_table[j].normal_draw)
                    fog_table[j].normal_draw = (VSpanMiniList*)((unsigned char*)fog_table[j].normal_draw + base);
                if (fog_table[j].fog_draw)
                    fog_table[j].fog_draw = (VSpanMiniList*)((unsigned char*)fog_table[j].fog_draw + base);
            }
        }
    }
    fd = _open(s_black_tile_file, _O_BINARY);
    if (fd != -1) {
        _lseek(fd,0,SEEK_END); len = _tell(fd); this->Black_Edge_Tables = (Tile_BlackEdge_Table**)calloc(1,len); _lseek(fd,0,SEEK_SET); _read(fd,this->Black_Edge_Tables,len); _close(fd);
        base = (int)this->Black_Edge_Tables;
        unsigned char* black_edge_data = (unsigned char*)this->Black_Edge_Tables;
        black_roots = this->Black_Edge_Tables;
        for (i=0;i<0x11;i++,black_roots++)
            *black_roots = (Tile_BlackEdge_Table*)((unsigned char*)*black_roots + base);
        for (i=0;i<0x44;i+=4) {
            black_table = *(Tile_BlackEdge_Table**)(black_edge_data + i);
            for (j=0;j<0x2f;j++) {
                if (black_table[j].black_UNdraw)
                    black_table[j].black_UNdraw = (VSpanMiniList*)((unsigned char*)black_table[j].black_UNdraw + base);
            }
        }
    }
    uchar* edge = this->EdgeNumber;
    for (i=0;i<0x100;i++) edge[i] = 0xff;
    count = 0;
    i = 0;
    do {
        int b0,b1,b2,b3,b4,b5,b6,b7;
        ok = 1;
        b0 = (i & 1) == 1;
        b1 = (i & 2) == 2;
        b2 = (i & 4) == 4;
        b3 = (i & 8) == 8;
        b4 = (i & 0x10) == 0x10;
        b5 = (i & 0x20) == 0x20;
        b6 = (i & 0x40) == 0x40;
        b7 = (i & 0x80) == 0x80;
        if (b7 && (b0 || b3)) ok = 0;
        if (b6 && (b2 || b3)) ok = 0;
        if (b5 && (b1 || b2)) ok = 0;
        if (b4 && (b0 || b1)) ok = 0;
        if (ok) edge[i] = (uchar)count++;
        i++;
    } while (i < 0x100);
    i = 0;
    do {
        if (edge[i] == 0xff) {
            int b0,b1,b2,b3,b4,b5,b6,b7;
            b0 = i & 1; b1 = i & 2; b2 = i & 4; b3 = i & 8; b4 = i & 0x10; b5 = i & 0x20; b6 = i & 0x40; b7 = i & 0x80;
            if (b7) { b3 = 0; b0 = 0; }
            if (b6) { b3 = 0; b2 = 0; }
            if (b5) { b2 = 0; b1 = 0; }
            if (b4) { b1 = 0; b0 = 0; }
            edge[i] = edge[b7 | b6 | b5 | b4 | b3 | b2 | b1 | b0];
        }
        i++;
    } while (i < 0x100);
}


extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);


void RGE_View::update_display_selected_objects(void) {
    unsigned long curTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\view.cpp", 0x2CB);
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
                        obj->selected = obj->selected |
                                        (unsigned char)entry->select_type;
                        goto next_entry;
                    }
                    obj->selected = obj->selected &
                                    ~(unsigned char)entry->select_type;
                }
            }
next_entry:
            ++i;
        } while (i < this->DispSel_List_Max);
    }
}


extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);


void RGE_View::display_object_selection(int param_1, int param_2, int param_3, int param_4)
{
    int found = 0;
    int i = 0;
    DisplaySelectedObjRec* slot = 0;

    if (this->DispSel_List_Max > 0) {
        int key = param_4;

        do {
            DisplaySelectedObjRec* entry = &this->DispSel_List[i];
            if (entry->active == 0) {
                found = 1;
                slot = entry;
            } else if (key != 0 && entry->select_type == key) {
                entry->start_time -= entry->duration;
            }
            i++;
        } while (i < this->DispSel_List_Max);
    }

    if (found && slot != 0) {
        slot->active = 1;
        slot->id = param_1;
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\view.cpp", 0x31d);
        slot->start_time = now;
        slot->duration = param_2;
        slot->select_type = param_3;
        this->DispSel_List_Size++;
    }
}


void RGE_View::set_rect(long a, long b, long c, long d)
{
    this->TPanel::set_rect(a, b, c, d);
    this->calc_draw_vars();
    this->create_surfaces();

    this->last_view_x = -9999.0f;
    this->last_view_y = -9999.0f;

    delete this->Terrain_Clip_Mask;
    delete this->Terrain_Fog_Clip_Mask;
    delete this->Master_Clip_Mask;

    this->Terrain_Clip_Mask = new TSpan_List_Manager(c, d);
    this->Terrain_Fog_Clip_Mask = new TSpan_List_Manager(c, d);
    this->Master_Clip_Mask = new TSpan_List_Manager(c, d);

    if (MouseSystem != 0 && c > 0 && d > 0) {
        MouseSystem->set_game_window(a, b, a + c, b + d);
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



int RGE_View::create_surfaces()
{
    if (this->pnl_wid == 0 && this->pnl_hgt == 0) {
        return 1;
    }

    if (this->save_area1 == 0) {
        TDrawArea* area = new TDrawArea("Terrain Buffer", 0);
        this->save_area1 = area;
        if (area != 0) {
            area->Init(this->render_area->DrawSystem, this->pnl_wid,
                       this->pnl_hgt, 1, 0);
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
    int pw;

    if (this->visible != 0 && this->tile_wid != 0 && this->tile_hgt != 0) {
        pw = this->pnl_wid;

        this->center_scr_col_offset = 0;
        this->max_col_num = (short)(pw / (int)this->tile_wid);
        this->center_scr_row_offset = 0;
        this->max_row_num = (short)(this->pnl_hgt / (int)this->tile_hgt);
        this->center_scr_col = (this->render_rect.left - this->tile_half_wid) + (short)(pw / 2);
        this->center_scr_row = (this->render_rect.top - this->tile_half_hgt) + (short)(this->pnl_hgt / 2);
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


void RGE_View::set_redraw(TPanel::RedrawMode mode) {
    this->TPanel::set_redraw(mode);
    if (mode == 2) {
        render_terrain_mode = 0;
    }
}


void RGE_View::set_world(RGE_Game_World* world) {
    this->world = world;
    if (world != 0) {
        map = world->map;
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


void RGE_View::set_player(RGE_Player* player) {
    this->player = player;
    last_view_x = -9999.0f;
    last_view_y = -9999.0f;
    set_redraw(TPanel::RedrawImmediate);
}


void RGE_View::set_selection_area(long col1, long row1, long col2, long row2)
{
    if (this->map && rge_base_game->game_mode != 0x15) {
        this->map->request_redraw(this->sel_col1, this->sel_row1, this->sel_col2, this->sel_row2, 0);
    }
    this->sel_col1 = col1;
    this->sel_row1 = row1;
    this->sel_col2 = col2;
    this->sel_row2 = row2;
    if (this->map && rge_base_game->game_mode != 0x15) {
        this->map->request_redraw(col1, row1, col2, row2, 0x10);
    }
    this->set_redraw(TPanel::RedrawNormal);
}



int RGE_View::get_selection_area(long& col1, long& row1, long& col2, long& row2, int normalize)
{
    col1 = this->sel_col1;
    row1 = this->sel_row1;
    col2 = this->sel_col2;
    row2 = this->sel_row2;

    if (col1 == -1 && row1 == -1 && col2 == -1 && row2 == -1) {
        return 0;
    }

    if (col1 < 0) {
        col1 = 0;
    } else if (col1 >= this->map->map_width) {
        col1 = this->map->map_width - 1;
    }

    if (row1 < 0) {
        row1 = 0;
    } else if (row1 >= this->map->map_height) {
        row1 = this->map->map_height - 1;
    }

    if (col2 < 0) {
        col2 = 0;
    } else if (col2 >= this->map->map_width) {
        col2 = this->map->map_width - 1;
    }

    if (row2 < 0) {
        row2 = 0;
    } else if (row2 >= this->map->map_height) {
        row2 = this->map->map_height - 1;
    }

    if (normalize) {
        long c1 = col1;
        long c2 = col2;
        long r1 = row1;
        long r2 = row2;

        col1 = (c1 < c2) ? c1 : c2;
        row1 = (r1 < r2) ? r1 : r2;
        col2 = (c1 > c2) ? c1 : c2;
        row2 = (r1 > r2) ? r1 : r2;
    }

    return 1;
}


void RGE_View::CreateBlitQueue(tagRECT& param_1, tagRECT& param_2, int param_3, int param_4)
{
    int nBlits;
    int yd;
    tagRECT blt_src;
    int local_4;
    int One_Blit = 0;
    int vBlits;
    int blt_deltaX;
    int blt_deltaY;
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar6;
    int xd;
    int blit_index;
    int count;
    yd = param_4;
    if ((param_3 != 0) || (yd != 0)) {
        if (((iVar6 = param_1.top) > param_2.bottom) ||
            (((iVar1 = param_1.left, iVar1 > param_2.right ||
              (iVar2 = param_1.bottom, iVar2 < param_2.top)) ||
             (iVar3 = param_1.right, iVar3 < param_2.left)))) {
            One_Blit = 1;
            nBlits = 1;
            blt_src.left = iVar1;
            blt_src.top = iVar6;
            blt_src.right = iVar3;
            local_4 = iVar2;
        } else {
            nBlits = param_4;
            if (nBlits < 0) nBlits = -nBlits;
            xd = param_3;
            if (xd < 0) xd = -xd;
            vBlits = 9999;
            if (param_4 != 0) vBlits = (nBlits + (iVar2 - iVar6)) / nBlits;
            nBlits = 9999;
            if (param_3 != 0) nBlits = (xd + (iVar3 - iVar1)) / xd;
            blt_src.left = param_1.left;
            blt_src.top = param_1.top;
            blt_src.right = param_1.right;
            local_4 = param_1.bottom;
            blt_deltaX = 0;
            blt_deltaY = 0;
            if (vBlits < nBlits) {
                nBlits = vBlits;
                blt_deltaY = param_4;
                if (param_4 < 0) blt_src.top = param_4 + iVar2 + 1;
                else local_4 = param_4 + iVar6 - 1;
            } else {
                blt_deltaX = param_3;
                if (param_3 < 0) blt_src.left = param_3 + iVar3 + 1;
                else blt_src.right = param_3 + iVar1 - 1;
            }
        }

        if (nBlits > this->Blt_Queue_Allocated) {
            if (this->Blit_Queue != 0) free(this->Blit_Queue);
            this->Blit_Queue = 0;
        }
        if (this->Blit_Queue == 0) {
            this->Blit_Queue = (Blit_Queue_Entry*)calloc(
                nBlits, sizeof(Blit_Queue_Entry));
            this->Blt_Queue_Allocated = nBlits;
        }
        if (One_Blit) {
            this->Blit_Queue[0].src = param_1;
            this->Blit_Queue[0].dest = param_2;
        } else if (nBlits > 0) {
            count = nBlits;
            blit_index = 0;
            do {
                Blit_Queue_Entry* entry = &this->Blit_Queue[blit_index];
                entry->src.left = blt_src.left;
                entry->src.top = blt_src.top;
                entry->src.right = blt_src.right;
                entry->src.bottom = local_4;
                entry->dest.left = blt_src.left - param_3;
                entry->dest.top = blt_src.top - param_4;
                entry->dest.right = blt_src.right - param_3;
                entry->dest.bottom = local_4 - param_4;
                blt_src.top += blt_deltaY;
                local_4 += blt_deltaY;
                blt_src.left += blt_deltaX;
                blt_src.right += blt_deltaX;
                if (blt_src.top < param_1.top) blt_src.top = param_1.top;
                if (blt_src.left < param_1.left) blt_src.left = param_1.left;
                if (blt_src.right > param_1.right) blt_src.right = param_1.right;
                if (local_4 > param_1.bottom) local_4 = param_1.bottom;
                blit_index++;
                count--;
            } while (count != 0);
        }
        this->Queued_Blits = 1;
        this->Blit_Queue_Size = nBlits;
        this->Current_Blit = -1;
        this->Blit_Offset_X = this->render_rect.left;
        this->Blit_Offset_Y = this->render_rect.top;
    }
}








void RGE_View::ProcessQueuedBlit(int force)
{
    if (!this->Queued_Blits)
        return;

    if (force == 0) {
        if (this->render_area->DrawSurface->GetBltStatus(1))
            return;
    }

    this->Current_Blit++;
    if (this->Blit_Queue && this->Current_Blit >= 0 && this->Current_Blit < this->Blit_Queue_Size) {
        Blit_Queue_Entry* entry = &this->Blit_Queue[this->Current_Blit];
        tagRECT src;
        src.top = entry->src.top + this->Blit_Offset_Y;
        src.left = entry->src.left + this->Blit_Offset_X;
        src.bottom = entry->src.bottom + this->Blit_Offset_Y + 1;
        src.right = entry->src.right + this->Blit_Offset_X + 1;
        this->render_area->DrawSurface->BltFast(
            entry->dest.left + this->Blit_Offset_X,
            entry->dest.top + this->Blit_Offset_Y,
            this->render_area->DrawSurface, &src, 16);
        if (this->Current_Blit + 1 < this->Blit_Queue_Size)
            return;
    }
    this->Queued_Blits = 0;
}



void RGE_View::draw()
{
    tagRECT clip_rect2;
    tagRECT new_rect;
    tagRECT old_rect;
    tagRECT clip_rect1;
    int redraw_all = view_debug_redraw_all;

    tiles_drawn = 0;
    if (redraw_all != 0) {
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

    short old_start_map_col = this->start_map_col;
    short old_start_map_row = this->start_map_row;
    short old_start_scr_col = this->start_scr_col;
    short old_start_scr_row = this->start_scr_row;
    this->Terrain_Clip_Mask->ResetAll();
    this->Terrain_Fog_Clip_Mask->ResetAll();
    this->Master_Clip_Mask->ResetAll();
    int old_map_scr_x_offset = this->map_scr_x_offset;
    int old_map_scr_y_offset = this->map_scr_y_offset;
    this->Use_Rect2 = 0;
    this->Limited_Render_Rect = 0;
    this->update();
    this->draw_setup(0);

    if (this->render_terrain_mode == 1) {
        if ((this->start_map_col == old_start_map_col && this->start_map_row == old_start_map_row) &&
            (this->start_scr_col == old_start_scr_col && this->start_scr_row == old_start_scr_row)) {
            goto label_done;
        }

        long dx = (short)this->map_scr_x_offset - old_map_scr_x_offset;
        long dy = (short)this->map_scr_y_offset - old_map_scr_y_offset;
        if (dx == 0 && dy == 0) goto label_done;

        int screen_width = this->pnl_wid;
        int screen_height = this->pnl_hgt;

        new_rect.left = (int)dx;
        new_rect.top = (int)dy;
        old_rect.left = 0;
        old_rect.top = 0;
        old_rect.right = screen_width - 1;
        old_rect.bottom = screen_height - 1;
        new_rect.right = old_rect.right + new_rect.left;
        new_rect.bottom = old_rect.bottom + new_rect.top;

        if (new_rect.bottom < 0 || new_rect.right < 0 || old_rect.bottom < new_rect.top || old_rect.right < new_rect.left) {
            this->render_terrain_mode = 0;
            goto label_done;
        }

        if ((dx & 7) != 0) {
            long t = dx;
            if (dx <= 0) t = dx + 7;
            long a = (t & ~7) - dx;
            dx += a;
            this->map_scr_x_offset += a;
        }
        if ((dy & 7) != 0) {
            long t = dy;
            if (dy <= 0) t = dy + 7;
            long a = (t & ~7) - dy;
            dy += a;
            this->map_scr_y_offset += a;
        }

        if (dx < 0) {
            old_rect.left = 0;
            old_rect.right = (int)dx + screen_width - 1;
            new_rect.left = -(int)dx;
        } else {
            old_rect.left = (int)dx;
            old_rect.right = screen_width - 1;
            new_rect.left = 0;
            screen_width = screen_width - old_rect.left;
        }
        new_rect.right = screen_width - 1;

        if (dy < 0) {
            old_rect.top = 0;
            old_rect.bottom = (int)dy + screen_height - 1;
            new_rect.top = -(int)dy;
        } else {
            old_rect.top = (int)dy;
            old_rect.bottom = screen_height - 1;
            new_rect.top = 0;
            screen_height = screen_height - old_rect.top;
        }
        new_rect.bottom = screen_height - 1;

        int xd = (int)dx;
        int yd = (int)dy;

        if (this->render_area->DrawSystem->DrawType == 1 || this->render_area->UsingVidMem == 0) {
            this->render_area->OverlayMemCopy(old_rect, new_rect, xd, yd,
                                               this->render_rect.left,
                                               this->render_rect.top);
            this->Queued_Blits = 0;
        } else {
            this->CreateBlitQueue(old_rect, new_rect, xd, yd);
            if (MouseSystem != 0) MouseSystem->Poll();
            if (this->Queued_Blits != 0) this->ProcessQueuedBlit(0);
        }

        this->prior_objs->Scroll(xd, yd);

        int fxd = this->Float_X_Delta + xd;
        this->Float_X_Delta = fxd;
        if (fxd >= this->save_area1->Width) {
            if (this->save_area1->Lock("view::draw", 1) != 0) {
                memcpy(this->save_area1->Bits,
                       this->save_area1->Bits +
                           (this->save_area1->Height - 1) * this->save_area1->Pitch +
                           this->save_area1->Width,
                       this->Float_X_Delta - xd);
                this->Float_X_Delta -= this->save_area1->Width;
                this->Float_Y_Delta += 1;
                if (this->Float_Y_Delta >= this->save_area1->Height) this->Float_Y_Delta = 0;
                this->save_area1->Unlock("view::draw");
            }
        } else {
            if (fxd < 0 && this->save_area1->Lock("view::draw2", 1) != 0) {
                this->Float_X_Delta += this->save_area1->Width;
                this->Float_Y_Delta -= 1;
                if (this->Float_Y_Delta < 0) this->Float_Y_Delta = this->save_area1->Height - 1;
                memcpy(this->save_area1->Bits,
                       this->save_area1->Bits +
                           (this->save_area1->Height - 1) * this->save_area1->Pitch +
                           this->save_area1->Width,
                       this->Float_X_Delta);
                this->save_area1->Unlock("view::draw3");
            }
        }

        this->Float_Y_Delta += yd;
        if (this->Float_Y_Delta < 0) this->Float_Y_Delta += this->save_area1->Height;
        if (this->Float_Y_Delta >= this->save_area1->Height) this->Float_Y_Delta -= this->save_area1->Height;

        this->save_area1->SetFloatOffsets(this->Float_X_Delta, this->Float_Y_Delta);

        if ((new_rect.left == 0) && (new_rect.right == this->pnl_wid - 1)) {
            clip_rect1.left = -1;
            if ((new_rect.top == 0) && (new_rect.bottom == this->pnl_hgt - 1)) {
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
            clip_rect1.right = this->pnl_wid - 1;
            clip_rect1.left = new_rect.right + 1;
            clip_rect1.bottom = this->pnl_hgt - 1;
            clip_rect1.top = 0;
            if ((new_rect.top == 0) && (new_rect.bottom == clip_rect1.bottom)) {
                clip_rect2.left = -1;
            } else {
                clip_rect2.left = 0;
                if (new_rect.top == 0) {
                    clip_rect2.top = new_rect.bottom + 1;
                    clip_rect2.right = new_rect.right;
                    clip_rect2.bottom = clip_rect1.bottom;
                } else {
                    clip_rect2.top = 0;
                    clip_rect2.right = new_rect.right;
                    clip_rect2.bottom = new_rect.top - 1;
                }
            }
        } else {
            clip_rect1.right = new_rect.left - 1;
            clip_rect1.bottom = this->pnl_hgt - 1;
            clip_rect1.left = 0;
            clip_rect1.top = 0;
            if ((new_rect.top == 0) && (new_rect.bottom == clip_rect1.bottom)) {
                clip_rect2.left = -1;
            } else {
                clip_rect2.left = new_rect.left;
                if (new_rect.top == 0) {
                    clip_rect2.top = new_rect.bottom + 1;
                    clip_rect2.right = this->pnl_wid - 1;
                    clip_rect2.bottom = clip_rect1.bottom;
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
            if (clip_rect1.left != -1) {
                this->Use_Rect2 = 1;
                this->Render_Rect2 = clip_rect2;
            } else {
                this->Limited_Render_Rect = 1;
                this->Render_Rect1 = clip_rect2;
            }
        }
    }

label_done:
    if (MouseSystem != 0) MouseSystem->Poll();
    if (this->Queued_Blits != 0) this->ProcessQueuedBlit(0);

    int gm = rge_base_game->game_mode;
    if ((gm >= 9 && gm <= 10) || gm == 0x13) {
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

void RGE_View::update()
{
    RGE_Player* p;
    short sVar6;
    short sVar7;
    short sVar8;
    short sVar9;
    short sVar10;
    RGE_Tile* tile;
    p = this->player;
    if (p && (p->view_x != this->last_view_x || p->view_y != this->last_view_y)) {
        sVar6 = (short)(int)p->view_x;
        this->center_map_col = sVar6;
        sVar7 = (short)(int)p->view_y;
        sVar6 = this->center_map_col;
        this->center_map_row = sVar7;
        sVar9 = (short)(this->render_rect.left + this->pnl_wid / 2) - this->tile_half_wid;
        sVar10 = (short)(this->render_rect.top + this->pnl_hgt / 2) - this->tile_half_hgt;
        this->last_view_x = p->view_x;
        this->last_view_y = p->view_y;
        this->center_scr_col = sVar9;
        this->center_scr_row = sVar10;
        sVar7 = (short)(int)(((p->view_y - (float)this->center_map_row) * DAT_005776b4 *
                              (float)this->tile_wid) +
                             ((p->view_x - (float)sVar6) *
                              (float)this->tile_wid));
        sVar8 = (short)(int)(((p->view_y - (float)this->center_map_row) * DAT_005776b4 *
                              (float)this->tile_hgt) -
                             ((p->view_x - (float)sVar6) *
                              (float)this->tile_hgt));
        sVar9 -= sVar7;
        sVar10 -= sVar8 + this->tile_half_hgt;
        this->center_scr_col = sVar9;
        this->center_scr_row = sVar10;
        tile = this->map->map_row_offset[this->center_map_row] + sVar6;
        this->map_scr_x_offset = (int)tile->screen_xpos - (int)sVar9;
        this->map_scr_y_offset = ((int)this->elev_hgt * tile->height +
                                  (int)tile->screen_ypos) - (int)sVar10;
        this->center_scr_col_offset = (short)((sVar6 + this->center_map_row) * this->tile_half_wid - sVar7);
        this->center_scr_row_offset = (short)((this->center_map_row - sVar6) * this->tile_half_hgt - sVar8 - this->tile_half_hgt);
        sVar7 = this->max_col_num / 2 + 2;
        this->start_map_row = this->center_map_row;
        this->start_map_row -= sVar7;
        this->start_map_col = sVar6 - sVar7;
        this->start_scr_col = (short)(sVar9 - sVar7 * this->tile_half_wid * 2);
        sVar6 = this->max_row_num / 2 + 1;
        this->start_map_col += sVar6;
        this->start_map_row -= sVar6;
        this->start_scr_row = (short)(sVar10 - sVar6 * this->tile_half_hgt * 2);
    }
}





void RGE_View::draw_view(unsigned char p1, TDrawArea* p2)
{
    if (p2 == 0)
        this->cur_render_area = this->render_area;
    else
        this->cur_render_area = p2;

    {
        tagRECT save_render_rect;
        if (this->cur_render_area == this->save_area1) {
        save_render_rect.left = this->render_rect.left;
        save_render_rect.right = this->render_rect.right;
        save_render_rect.top = this->render_rect.top;
        save_render_rect.bottom = this->render_rect.bottom;

        this->render_rect.left -= save_render_rect.left;
        this->start_scr_col -= (short)save_render_rect.left;
        this->start_scr_row -= (short)save_render_rect.top;
        this->render_rect.top -= save_render_rect.top;
        this->render_rect.right -= save_render_rect.left;
        this->render_rect.bottom -= save_render_rect.top;
        this->map_scr_x_offset += save_render_rect.left;
        this->map_scr_y_offset += save_render_rect.top;
    }
    if (this->cur_render_area->Lock("view::draw_view", 1)) {
        if (p1 == 10) {
            this->view_function_terrain(10, save_render_rect);
        } else {
            this->view_function(p1, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        this->cur_render_area->Unlock("view::draw_view");
    }
    if (this->cur_render_area == this->save_area1) {
        this->start_scr_col += (short)save_render_rect.left;
        this->start_scr_row += (short)save_render_rect.top;
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
    RGE_Master_Static_Object* master = player->master_objects[(int)master_obj_id];
    if (master == 0)
        return;

    rge_base_game->get_mouse_pos(point);
    if (point.x < this->render_rect.left ||
        point.x > this->render_rect.right ||
        point.y < this->render_rect.top ||
        point.y > this->render_rect.bottom)
        return;

    unsigned short pick_result = (unsigned char)this->pick(
        0x28, 0, point.x - this->render_rect.left,
        point.y - this->render_rect.top,
        &pick_info, 0);
    if (pick_result != 0x33)
        return;

    master->alignment(pick_info.x, pick_info.y, this->world, 0);
    if (this->get_tile_screen_coords(
            (short)pick_info.x, (short)pick_info.y, &scr_x, &scr_y, 1) == 0)
        return;

    master->alignment_box(this->world, pick_info.x, pick_info.y,
                          x1, y1, x2, y2, x3, y3, x4, y4);

    placement = (unsigned char)master->check_placement(
        rge_base_game->get_player(), pick_info.x, pick_info.y,
        0, 1, master->elevation_flag, 0, 1, 1, 1);
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

    scr_x += ((int)x1 - (int)x3) / 2 + x3;
    scr_y += ((int)y2 - (int)y4) / 2 + y4;

    if (master->sprite != 0) {
        SDI_Draw_Line = (int)scr_y;
        int draw_flag = master->draw_flag & 1;

        if (placement == 0)
            frame_color = master->draw_color;
        else
            frame_color = 0x97;

        if (rge_base_game->game_mode == 8 &&
            rge_base_game->sub_game_mode == 1 &&
            this->movable_object != 0) {
            RGE_Static_Object* movable = this->movable_object;
            RGE_Color_Table* colors = movable->owner->color_table;
            master->draw(this->render_area, scr_x, scr_y, colors,
                         movable->facet, 0, draw_flag, frame_color);
        } else {
            RGE_Color_Table* colors = rge_base_game->get_player()->color_table;
            master->draw(this->render_area, scr_x, scr_y, colors,
                         0, 0, draw_flag, frame_color);
        }
    }

    fog_next_shape = 0;
}



void RGE_View::draw_paint_brush() {
    tagPOINT point;
    RGE_Pick_Info pick_info;

    set_selection_area(-1, -1, -1, -1);

    rge_base_game->get_mouse_pos(point);

    if (point.x < this->render_rect.left ||
        point.x > this->render_rect.right ||
        point.y < this->render_rect.top ||
        point.y > this->render_rect.bottom)
        return;

    unsigned short pickResult = (unsigned char)pick(
        0x28, 0, point.x, point.y, &pick_info, 0);

    if (pickResult != '3')
        return;

    short brushSize;
    if (rge_base_game->game_mode == 0x13) {
        int t1 = (int)(pick_info.x * (1.0f / 3.0f));
        int v1 = -t1 * 3;
        pick_info.x = 1.0f - (float)v1;

        int t2 = (int)(pick_info.y * (1.0f / 3.0f));
        int v2 = -t2 * 3;
        pick_info.y = 1.0f - (float)v2;

        brushSize = 3;
    } else {
        brushSize = rge_base_game->brush_size;
    }

    long cx = (long)pick_info.x;
    long cy = (long)pick_info.y;
    set_selection_area(cx - (brushSize >> 1),
                       cy - (brushSize >> 1),
                       cx + (brushSize >> 1),
                       cy + (brushSize >> 1));
}





unsigned char RGE_View::pick(unsigned char param_1, unsigned char param_2,
                              long x, long y,
                              RGE_Pick_Info* param_5,
                              RGE_Static_Object* param_6) {
    void* picked_output = ((unsigned char)param_1 != '(') ? param_6 : 0;
    tagPOINT start_mouse_pos;
    tagPOINT mouse_pos;

    mouse_pos.x = x;
    mouse_pos.y = y;
    start_mouse_pos.x = x;
    start_mouse_pos.y = y;

    memset(param_5, 0, sizeof(*param_5));

    long ret = this->view_function(
        param_1, param_2, &mouse_pos,
        &start_mouse_pos, &picked_output,
        &param_5->x, &param_5->y,
        &param_5->scr_x, &param_5->scr_y);
    unsigned char code = (unsigned char)ret;
    if (code == 0x34) {
        param_5->object = (RGE_Static_Object*)picked_output;
    } else if (code == 0x33) {
        param_5->tile = (RGE_Tile*)picked_output;
    }
    return code;
}



unsigned char RGE_View::pick_multi(unsigned char p1, long x1, long y1, long x2, long y2)
{
    RGE_Pick_Obj_Info* pp;
    int i = 0;
    int picked_any = 0;
    int count;
    RGE_Static_Object* picked_obj;
    count = this->pick_multi_objects(x1, y1, x2, y2, 10, 20, this->player->id, p1, 1);
    if (count > 0) {
        pp = Picked_Objects;
        do {
            int idx = pp->object_id;
            if (idx != -1) {
                RGE_Static_Object* obj = this->world->objectsValue[idx];
                if (obj != 0 && obj->object_state < 7) {
                    if (!this->player->select_one_object(obj,0)) break;
                    picked_any = 1;
                }
            }
            i++;
            ++pp;
        } while (i < count);
    }
    if (picked_any) return 1;

    long dx = x2 - x1;
    long dy = y2 - y1;
    long r = dx;
    if (dx >= dy) r = dy;
    if (r < 50) {
        r = dy;
        if (dx < dy) r = dx;
    } else r = 50;

    count = this->pick_objects(x1 + dx/2, y1 + dy/2, 10, 20, r, 4, 1);
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
                    if (obj && obj->object_state < 7 && obj->master_obj->select_level >= 2) {
                        if (!this->map->map_visible_flag && !this->pick_through_fog(obj)) {
                            int vy = (int)obj->world_y;
                            int vx = (int)obj->world_x;
                            if (this->player->visible->get_visible(vx, vy) != 0x0f) goto next;
                        }
                        int score = this->pick_weight(obj, pp->confidence);
                        if (obj->owner == this->player) score += 5;
                        if (score > bestScore) { picked_obj = obj; bestScore = score; }
                    }
                }
next:
                ++pp;
                remaining--;
            } while (remaining != 0);
        }
        if (picked_obj && this->player->select_one_object(picked_obj,0)) return 1;
    }
    return 0;
}


unsigned char RGE_View::pick(unsigned char a1, unsigned char a2, tagPOINT* p1, tagPOINT* p2, void** out_obj, float* out_x, float* out_y, short* out_col, short* out_row) {
    return (unsigned char)view_function(a1, a2, p1, p2, out_obj, out_x, out_y, out_col, out_row);
}


int RGE_View::pick_through_fog(RGE_Static_Object* object) { return 0; }



int RGE_View::pick_weight(RGE_Static_Object* param_1, int param_2) {
    unsigned char select_level = param_1->master_obj->select_level;
    int touched;

    if (this->UC_ObjectTouched && this->UC_TouchedObj == param_1->id)
        touched = 1;
    else
        touched = 0;

    int result = 0;

    switch ((int)(unsigned)select_level) {
        case 4:
            if (touched) return 5;
            if (param_2 == 1 || param_2 == 2) return 4;
            if (param_2 == 3) return 3;
            return 2;
        case 3:
            if (touched) return 5;
            if (param_2 == 1 || param_2 == 2)
                result = 3;
            break;
        case 2:
            if (touched) return 5;
            if (param_2 == 1 || param_2 == 2)
                result = 3;
            else if (param_2 == 3)
                result = 2;
            break;
        default:
            return 1;
    }

    return result;
}



int RGE_View::get_tile_screen_coords(short col, short row, short* out_x, short* out_y, int adjust) {
    if (out_x != 0) *out_x = 0;
    if (out_y != 0) *out_y = 0;

    if (col >= 0) {
        RGE_Map* pMap = this->map;
        if (col < pMap->map_width) {
            if (row >= 0) {
                if (row < pMap->map_height) {
                    RGE_Tile* pTile = pMap->map_row_offset[row] + col;
                    if (pTile != 0) {
                        int screen_x = pTile->screen_xpos - this->map_scr_x_offset;
                        int screen_y = pTile->screen_ypos;
                        screen_y += pMap->tilesizes[pTile->tile_type].y_delta;
                        screen_y -= this->map_scr_y_offset;

                        if (adjust != 0) {
                            if (pTile->tile_type != 0) screen_y += this->elev_hgt / 2;
                            if (pTile->tile_type == 6) screen_y -= this->elev_hgt;
                            if (pTile->tile_type == 5) screen_y -= this->elev_hgt;
                            if (pTile->tile_type == 3) screen_y -= this->elev_hgt;
                            if (pTile->tile_type == 0x0B) screen_y -= this->elev_hgt;
                        }

                        *out_x = (short)screen_x;
                        *out_y = (short)screen_y;
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}


void RGE_View::get_center_screen_pos(short* row, short* col) {
    *row = center_scr_row;
    *col = center_scr_col;
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


void RGE_View::get_tile_sizes(short* width, short* height, short* half_width, short* half_height) {
    if (width != 0) {
        *width = tile_wid;
    }
    if (height != 0) {
        *height = tile_hgt;
    }
    if (half_width != 0) {
        *half_width = tile_half_wid;
    }
    if (half_height != 0) {
        *half_height = tile_half_hgt;
    }
}


void RGE_View::get_max_size(short* cols, short* rows) {
    *cols = max_col_num;
    *rows = max_row_num;
}





long RGE_View::view_function(unsigned char a1, unsigned char a2, tagPOINT* p1, tagPOINT* p2,
                             void** out_obj, float* out_x, float* out_y, short* out_col, short* out_row)
{
    unsigned char visible;
    short map_row;
    short map_col;
    short start_scr_col2;
    short start_scr_row2;
    short cur_col_num;
    short picked_type;
    unsigned char fog_flag;
    unsigned char tile;
    RGE_Tile* tile_ptr;
    short start_map_row2;
    short direction;
    unsigned char tile_screen_row;
    short last_picked_obj;
    RGE_Static_Object* terrain_type;
    unsigned char tile_type;
    unsigned char col_num;
    short row_num;
    long calc_sel_col1;
    long calc_sel_col2;
    long calc_sel_row1;
    long calc_sel_row2;
    long calc_sel_row3;
    RGE_Static_Object* find_col;
    short find_row;
    short max_col_num2;
    short max_row_num2;
    short list_size;

    this->function_mode = a1;
    this->function_parm = a2;

    if (a1 == 0x0A && this->calc_draw_count != 0) {
        for (short i = 0; i < this->map->num_terrain; i++) {
            this->map->terrain_types[i].drawn = 0;
        }
    }

    RGE_Tile_List_Node* list_node;
    int num_active;
    this->player->tile_list.get_list_info(list_node, num_active);

    fog_flag = 0x32;
    if (this->function_mode == 0x28 || this->function_mode == 0x3C || this->function_mode == 0x29 ||
        this->function_mode == 0x2A || this->function_mode == 0x2B || this->function_mode == 0x2C) {
        if (this->function_mode == 0x3C) {
            find_row = (short)(long)(*out_x);
            max_col_num2 = (short)(long)(*out_y);
        }
        *out_x = 0.0f;
        *out_y = 0.0f;
        *out_col = 0;
        *out_row = 0;
        if (this->function_mode == 0x29 || this->function_mode == 0x2A || this->function_mode == 0x2B ||
            this->function_mode == 0x2C) {
            find_col = (RGE_Static_Object*)*out_obj;
        }
        *out_obj = 0;
        terrain_type = 0;
    }

    if (this->function_mode == 0x0E) {
        if (this->get_selection_area(calc_sel_col2, calc_sel_row2,
                                     calc_sel_row1, calc_sel_row3, 1) == 0) {
            return 0;
        }
    }

    start_scr_row2 = this->start_scr_col;
    start_map_row2 = this->start_map_col;
    cur_col_num = this->start_scr_row;
    direction = this->start_map_row;
    list_size = this->max_row_num + 6;
    list_size <<= 1;
    picked_type = this->max_col_num + 4;
    max_row_num2 = picked_type;
    tile_screen_row = 4;
    calc_sel_col1 = 0;

    if ((short)list_size > 0) {
        do {
            map_row = start_scr_row2;
            start_scr_col2 = start_map_row2;
            map_col = direction;
            row_num = 0;
            if (picked_type > 0) {
                do {
                    int in_bounds;
                    int draw_flag;
                    if (start_scr_col2 >= 0 && start_scr_col2 < this->map->map_width &&
                        map_col >= 0 && map_col < this->map->map_height) {
                        in_bounds = 1;
                    } else {
                        in_bounds = 0;
                        if (this->function_mode != 0x28 && this->function_mode != 0x2A) {
                            goto col_continue;
                        }
                    }
                    if (in_bounds) {
                        RGE_Visible_Map* vis = this->player->visible;
                        if (vis != 0 && this->map->map_visible_flag == 0) {
                            visible = vis->get_visible(start_scr_col2, map_col);
                            if (this->function_mode == 0x1E || this->function_mode == 0x1F) {
                                visible = 0x0F;
                            }
                        } else {
                            visible = vis->get_visible(start_scr_col2, map_col);
                            if (visible == 0) {
                                visible = 0x80;
                            }
                        }
                    } else {
                        visible = 0;
                    }
                    if (this->function_mode == 0x0B) {
                        RGE_Tile* t = this->map->map_row_offset[map_col] + start_scr_col2;
                        if (t->draw_as == t->last_drawn_as) {
                            visible = 0;
                        }
                    }
                    if (visible != 0x0F && visible != 0x80) {
                        visible = 0;
                    }
                    if (visible == 0 && this->function_mode != 0x0E && this->function_mode != 0x28 &&
                        this->function_mode != 0x3C && this->function_mode != 0x2A) {
                        goto col_continue;
                    }
                    unsigned char tile_height;
                    if (in_bounds) {
                        tile_ptr = this->map->map_row_offset[map_col] + start_scr_col2;
                        col_num = tile_ptr->tile_type;
                        tile_height = tile_ptr->height;
                    } else {
                        tile_ptr = 0;
                        col_num = 0;
                        tile_height = 0;
                    }
                    last_picked_obj = (short)(cur_col_num -
                        tile_height * this->elev_hgt);
                    switch (col_num) {
                    case 2:
                    case 6:
                    case 8:
                    case 10:
                    case 14:
                    case 15:
                    case 16:
                        last_picked_obj -= this->elev_hgt;
                        break;
                    }
                    draw_flag = map_row > this->render_rect.right || last_picked_obj > this->render_rect.bottom ||
                        map_row + this->map->tilesizes[col_num].width <= this->render_rect.left ||
                        last_picked_obj + this->map->tilesizes[col_num].height <= this->render_rect.top ||
                        (this->function_mode == 0x0E &&
                          (start_scr_col2 < calc_sel_col2 || start_scr_col2 > calc_sel_row1 ||
                          map_col < calc_sel_row2 || map_col > calc_sel_row3));
                    if (this->function_mode == 0x0A || this->function_mode == 0x1E || this->function_mode == 0x1F ||
                        this->function_mode == 0x20 || this->function_mode == 0x15 || this->function_mode == 0x0B ||
                        this->function_mode == 0x0E) {
                        if (draw_flag == 0 &&
                            (this->function_mode == 0x0A || this->function_mode == 0x0B || this->function_mode == 0x0E)) {
                            tile_type = tile_ptr->terrain_type;
                            if (this->map->terrain_types[tile_type].terrain_to_draw != -1) {
                                tile_type = (unsigned char)this->map->terrain_types[tile_type].terrain_to_draw;
                            }
                            if (this->function_mode == 0x0A && this->calc_draw_count != 0 &&
                                (short)tile_type < this->map->num_terrain) {
                                this->map->terrain_types[tile_type].drawn++;
                            }
                            if (this->function_mode == 0x0B) {
                                tile_ptr->last_drawn_as = tile_ptr->draw_as;
                            }
                        }
                        if (visible == 0x0F || visible == 0x80) {
                            if (this->function_mode == 0x1E || this->function_mode == 0x1F ||
                                this->function_mode == 0x20 || this->function_mode == 0x15) {
                                if (visible == 0x0F || (visible == 0x80 && this->map->fog_flag == 0)) {
                                    tile = 0;
                                } else {
                                    tile = 1;
                                }
                                if (this->function_mode == 0x1E) {
                                    this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
                                    fog_next_shape = 1;
                                    tile_ptr->objects.shadow_draw(this->cur_render_area, map_row, cur_col_num, 1, tile);
                                    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
                                    fog_next_shape = 0;
                                    tile_ptr->objects.shadow_draw(this->cur_render_area, map_row, cur_col_num, 1, tile);
                                    this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
                                }
                                if (this->function_mode == 0x1F) {
                                    this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
                                    fog_next_shape = 1;
                                    tile_ptr->objects.shadow_draw(this->cur_render_area, map_row, cur_col_num, 0x0A, tile);
                                    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
                                    fog_next_shape = 0;
                                    tile_ptr->objects.shadow_draw(this->cur_render_area, map_row, cur_col_num, 0x0A, tile);
                                    this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
                                }
                                if (this->function_mode == 0x20) {
                                    if (this->map->fog_flag != 0 && visible == 0x80) {
                                        fog_next_shape = 1;
                                    }
                                    tile_ptr->objects.shadow_draw(this->cur_render_area, map_row, cur_col_num, 0, tile);
                                } else {
                                    if (this->function_mode != 0x15) {
                                        goto col_continue;
                                    }
                                    if (this->map->fog_flag != 0 && visible == 0x80) {
                                        fog_next_shape = 1;
                                    }
                                    tile_ptr->objects.normal_draw(this->cur_render_area, map_row, cur_col_num, tile);
                                }
                                fog_next_shape = 0;
                            }
                        }
                    } else {
                        if (visible == 0x0F || visible == 0x80) {
                            if (this->function_mode == 0x29 || this->function_mode == 0x2A ||
                                this->function_mode == 0x2B || this->function_mode == 0x2C) {
                                if (visible == 0x0F || (visible == 0x80 && this->map->fog_flag == 0)) {
                                    tile = 0;
                                } else {
                                    tile = 1;
                                }
                                RGE_Static_Object* obj = this->hit_object(tile_ptr, map_row, cur_col_num,
                                                                           start_scr_col2, map_col,
                                                                           p1, p2,
                                                                           out_col, out_row, find_col, tile);
                                if (obj != 0) {
                                    if (this->function_mode == 0x2C) {
                                        fog_flag = 0x34;
                                    } else {
                                        if (find_col != 0 && obj == find_col && fog_flag == 0x34) {
                                            *out_obj = terrain_type;
                                            return 0x34;
                                        }
                                        if (terrain_type == 0 ||
                                            terrain_type->master_obj->select_level <= obj->master_obj->select_level ||
                                            (terrain_type == find_col && obj != find_col)) {
                                            *out_x = obj->world_x;
                                            *out_y = obj->world_y;
                                            fog_flag = 0x34;
                                            terrain_type = obj;
                                        }
                                    }
                                }
                            }
                        }
                        if (this->function_mode == 0x28 || (this->function_mode == 0x2A && fog_flag == 0x32)) {
                            if (this->hit_tile(tile_ptr, map_row, last_picked_obj, start_scr_col2, map_col, p1) != 0) {
                                if (tile_ptr == 0) {
                                    *out_x = (float)start_scr_col2;
                                    *out_y = (float)map_col;
                                } else {
                                    this->map->tile_map_coords((short)p1->x - map_row,
                                                               (short)p1->y - last_picked_obj,
                                                               tile_ptr, out_x, out_y);
                                    *out_x = (float)start_scr_col2 + *out_x;
                                    *out_y = (float)map_col + *out_y;
                                }
                                *out_col = map_row;
                                fog_flag = 0x33;
                                *out_row = last_picked_obj;
                                *out_obj = tile_ptr;
                            }
                        } else if (this->function_mode == 0x3C) {
                            if (start_scr_col2 == find_row && map_col == max_col_num2) {
                                *out_x = (float)start_scr_col2;
                                *out_y = (float)map_col;
                                *out_col = map_row;
                                *out_row = last_picked_obj;
                                *out_obj = tile_ptr;
                                return 0x33;
                            }
                        }
                    }
                col_continue:
                    map_row += this->tile_wid;
                    start_scr_col2++;
                    map_col++;
                    row_num++;
                } while (row_num < picked_type);
            }
            if (tile_screen_row == 1 && picked_type == max_row_num2) {
                tile_screen_row = 2;
            }
            switch (tile_screen_row) {
            case 1:
                picked_type++;
                start_scr_row2 -= this->tile_half_wid;
                start_map_row2--;
                break;
            case 2:
                picked_type--;
                start_scr_row2 += this->tile_half_wid;
                direction++;
                break;
            case 3:
                tile_screen_row = 4;
                start_scr_row2 -= this->tile_half_wid;
                start_map_row2--;
                break;
            case 4:
                start_scr_row2 += this->tile_half_wid;
                direction++;
                tile_screen_row = 3;
                break;
            }
            cur_col_num += this->tile_half_hgt;
            calc_sel_col1++;
        } while ((short)calc_sel_col1 < (short)list_size);
    }

    if (this->function_mode == 0x0A) {
        for (short i = 0; i < this->map->num_terrain; i++) {
            this->map->terrain_types[i].frame_changed = 0;
        }
    }
    if (this->function_mode == 0x29 || this->function_mode == 0x2A || this->function_mode == 0x2B) {
        if (fog_flag == 0x34) {
            *out_obj = terrain_type;
        }
    }
    return fog_flag;
}


extern const char s_C__msdev_work_age1_x1_view_cpp[];
extern char s_view__view_function_terrain[];
extern "C" void __cdecl _ASMSet_Surface_Info(void* offsets, void* heads, void* tails,
                                              long min_span, long min_line,
                                              long max_span, long max_line);
extern "C" void __cdecl _ASMSet_Color_Xform(void* mask);
extern "C" void __cdecl _ASMSet_Xlate_Table(void* table);
extern "C" void __cdecl _ASMDraw_Sprite(long base, long x, long y, long width, long height,
                                         long data_offsets, long outline_offset, long flags);
extern "C" void __cdecl _ASMSet_Shadowing(long a, long b, long c, long d);

long RGE_View::view_function_terrain(unsigned char mode, tagRECT rect) {
    RGE_Tile* tile;
    short terrain_override;
    Tile_FogEdge_Table* edge_table;
    long screen_x;
    unsigned long mask;
    unsigned char reset_all_cyclic;
    unsigned char terrain;
    unsigned long MapVis;
    unsigned char draw_as;
    long screen_y;
    long row;
    int facet;
    long scan;
    long start_row;
    long black_mask_num;
    long screen_bottom;
    long normal_draw;
    long fog_mask_num;
    VSpanMiniList* black_list;
    long screen_right;
    long fog_draw;
    int clip_to;
    long map_width;
    long col;
    long map_height;
    Tile_BlackEdge_Table* black_edges;
    int full_visibility;
    unsigned long TileVisibleMask;
    unsigned long TileExploredMask;
    VSpanMiniList* fog_list;
    long col_num;
    long inner;
    VSpanMiniList* normal_list;
    long cols_2_scan;
    unsigned long TileFoggedMask;
    unsigned long row_index;
    long rows_2_scan;
    long terrain_index;
    Ov_Sprite_Draw_Rec* sprite;
    Ov_Sprite_Draw_Rec* next_sprite;
    unsigned char remove_sprite;
    DClipInfo_List* list;
    DClipInfo_List* future;
    DClipInfo_List* prior;
    DClipInfo_List* tmp;
    DClipInfo_Node* node;
    DClipInfo_Node* tail;
    DClipInfo_Node* added;
    DClipInfo_Node* future_node;
    DClipInfo_Node* prior_node;
    TSpan_List_Manager* clip;
    Shape_Info* shape;
    PanelNode* panel_node;
    TPanel* panel;
    long level;
    int shadowing;
    unsigned long shadow_flags;
    unsigned long shadow_value;
    long color;
    long row_base;
    unsigned char row_color;
    long palette_color;
    long x;
    POINT pt;
    RECT pr;
    char text[128];
    int text_id;

    if (this->DispSel_List_Size > 0) {
        this->update_display_selected_objects();
    }

    col_num = this->start_map_col;
    start_row = this->start_map_row;
    cols_2_scan = this->max_col_num + 5;
    rows_2_scan = this->max_row_num * 2 + 12;
    map_width = this->map->map_width;
    map_height = this->map->map_height;
    this->function_mode = mode;

    for (terrain_index = 0; terrain_index < this->map->num_terrain; ++terrain_index) {
        this->map->terrain_types[terrain_index].drawn = 0;
    }

    TileExploredMask = this->player->mutualExploredMask;
    TileFoggedMask = this->player->mutualVisibleMask;
    SDI_List = this->futur_objs;
    this->futur_objs->ReclaimAllNodes();

    MapVis = (unsigned long)-1;
    if (this->player->visible == 0 ||
        (TileVisibleMask = 0, this->map->map_visible_flag != 0)) {
        TileVisibleMask = 1;
    }

    for (scan = 0; scan < rows_2_scan; ++scan) {
        col = col_num;
        row = start_row;
        if (((scan & 3) == 3) && MouseSystem != 0) {
            MouseSystem->Poll();
        }
        row_index = scan & 1;
        if (row_index == 1 && this->Queued_Blits != 0) {
            this->ProcessQueuedBlit(0);
        }

        for (inner = 0; inner < cols_2_scan; ++inner) {
            if (row >= 0 && col >= 0) {
                if (row >= map_height || col >= map_width) {
                    inner = cols_2_scan;
                } else {
                    tile = &this->map->map_row_offset[row][col];
                    screen_x = tile->screen_xpos - this->map_scr_x_offset;
                    screen_y = tile->screen_ypos - this->map_scr_y_offset;
                    screen_right = screen_x + this->tile_wid;
                    screen_bottom =
                        screen_y + this->map->tilesizes[tile->tile_type].height;
                    mask = unified_map_offsets[row][col];

                    if ((mask & TileFoggedMask) != 0) {
                        draw_as = 0x0f;
                    } else if ((mask & TileExploredMask) != 0 ||
                               TileVisibleMask != 0) {
                        draw_as = this->map->fog_flag ? 0x80 : 0x0f;
                    } else {
                        draw_as = 0;
                        tile->last_drawn_as = 0;
                        goto TileOffScreen;
                    }

                    if (screen_x <= this->render_rect.right &&
                        screen_y <= this->render_rect.bottom &&
                        screen_right > this->render_rect.left &&
                        screen_bottom > this->render_rect.top) {
                        terrain = tile->terrain_type;
                        if (this->calc_draw_count != 0 &&
                            terrain < this->map->num_terrain) {
                            this->map->terrain_types[terrain].drawn++;
                        }

                        fog_mask_num = -1;
                        black_mask_num = -1;
                        clip_to = 0;
                        full_visibility = 0;
                        if (this->render_terrain_mode != 0 &&
                            tile->last_drawn_as == draw_as) {
                            if (draw_as == 0x0f) {
                                if (this->map->fog_flag == 0) {
                                    fog_mask_num = 0;
                                } else {
                                    fog_mask_num = this->get_tile_mask_num(
                                        col, row, map_width, map_height,
                                        TileFoggedMask);
                                }
                                if (tile->last_drawn_shape != fog_mask_num) {
                                    goto TileOffScreen;
                                }
                            }
                            if (draw_as == 0x0f || draw_as == 0x80) {
                                if (TileVisibleMask == 0) {
                                    black_mask_num = this->get_tile_mask_num(
                                        col, row, map_width, map_height,
                                        TileExploredMask);
                                } else {
                                    black_mask_num = 0;
                                }
                                if (tile->last_drawn_shape2 != black_mask_num) {
                                    goto TileOffScreen;
                                }
                            }
                            if (this->Limited_Render_Rect == 0) {
                                goto TileOffScreen;
                            }
                            if (this->Use_Rect2 != 0 &&
                                (this->Render_Rect2.right < screen_x ||
                                 screen_right < this->Render_Rect2.left ||
                                 this->Render_Rect2.bottom < screen_y ||
                                 (full_visibility = 1,
                                  screen_bottom < this->Render_Rect2.top))) {
                                full_visibility = 0;
                            }
                            if (this->Render_Rect1.right < screen_x ||
                                screen_right < this->Render_Rect1.left ||
                                this->Render_Rect1.bottom < screen_y ||
                                screen_bottom < this->Render_Rect1.top) {
                                if (full_visibility == 0) {
                                    goto TileOffScreen;
                                }
                                full_visibility = 0;
                                clip_to = 2;
                            } else {
                                clip_to = 1;
                            }
                        }

                        edge_table = this->Tile_Edge_Tables[tile->tile_type];
                        black_edges = this->Black_Edge_Tables[tile->tile_type];
                        if (this->map->fog_flag == 0) {
                            fog_mask_num = 0;
                        }
                        if (TileVisibleMask != 0) {
                            black_mask_num = 0;
                        }
                        if (fog_mask_num == -1) {
                            if (draw_as == 0x0f) {
                                fog_mask_num = this->get_tile_mask_num(
                                    col, row, map_width, map_height,
                                    TileFoggedMask);
                            } else {
                                fog_mask_num = 0;
                            }
                        }
                        if (black_mask_num == -1) {
                            if (draw_as != 0) {
                                black_mask_num = this->get_tile_mask_num(
                                    col, row, map_width, map_height,
                                    TileExploredMask);
                            } else {
                                black_mask_num = 0;
                            }
                        }
                        normal_list = edge_table[fog_mask_num].normal_draw;
                        fog_list = edge_table[fog_mask_num].fog_draw;
                        black_list = black_edges[black_mask_num].black_UNdraw;
                        if (draw_as == 0x80) {
                            fog_list = edge_table[0].normal_draw;
                            normal_draw = 0;
                            fog_draw = 1;
                        } else {
                            normal_draw = (normal_list != 0);
                            fog_draw = (fog_list != 0);
                        }
                        if (black_mask_num < 1 || black_list == 0) {
                            black_list = 0;
                        }
                        if (clip_to != (int)MapVis) {
                            if (clip_to == 0) {
                                this->Terrain_Clip_Mask->SetSpanRegions(
                                    this->render_rect.left,
                                    this->render_rect.top,
                                    this->render_rect.right,
                                    this->render_rect.bottom);
                                this->Terrain_Fog_Clip_Mask->SetSpanRegions(
                                    this->render_rect.left,
                                    this->render_rect.top,
                                    this->render_rect.right,
                                    this->render_rect.bottom);
                            }
                            if (clip_to == 1) {
                                this->Terrain_Clip_Mask->SetSpanRegions(
                                    this->Render_Rect1.left,
                                    this->Render_Rect1.top,
                                    this->Render_Rect1.right,
                                    this->Render_Rect1.bottom);
                                this->Terrain_Fog_Clip_Mask->SetSpanRegions(
                                    this->Render_Rect1.left,
                                    this->Render_Rect1.top,
                                    this->Render_Rect1.right,
                                    this->Render_Rect1.bottom);
                            }
                            MapVis = clip_to;
                            if (clip_to == 2) {
                                this->Terrain_Clip_Mask->SetSpanRegions(
                                    this->Render_Rect2.left,
                                    this->Render_Rect2.top,
                                    this->Render_Rect2.right,
                                    this->Render_Rect2.bottom);
                                this->Terrain_Fog_Clip_Mask->SetSpanRegions(
                                    this->Render_Rect2.left,
                                    this->Render_Rect2.top,
                                    this->Render_Rect2.right,
                                    this->Render_Rect2.bottom);
                                MapVis = clip_to;
                            }
                        }
                        if (normal_draw) {
                            this->Terrain_Clip_Mask->AddMiniList(
                                normal_list, screen_x, screen_y);
                        }
                        if (fog_draw) {
                            this->Terrain_Fog_Clip_Mask->AddMiniList(
                                fog_list, screen_x, screen_y);
                        }
                        if (black_list != 0) {
                            if (normal_draw) {
                                this->Terrain_Clip_Mask->SubtractMiniList(
                                    black_list, screen_x, screen_y);
                            }
                            if (fog_draw) {
                                this->Terrain_Fog_Clip_Mask->SubtractMiniList(
                                    black_list, screen_x, screen_y);
                            }
                        }
                        if (full_visibility != 0) {
                            this->Terrain_Clip_Mask->SetSpanRegions(
                                this->Render_Rect2.left, this->Render_Rect2.top,
                                this->Render_Rect2.right,
                                this->Render_Rect2.bottom);
                            this->Terrain_Fog_Clip_Mask->SetSpanRegions(
                                this->Render_Rect2.left, this->Render_Rect2.top,
                                this->Render_Rect2.right,
                                this->Render_Rect2.bottom);
                            MapVis = 2;
                            if (normal_draw) {
                                this->Terrain_Clip_Mask->AddMiniList(
                                    normal_list, screen_x, screen_y);
                            }
                            if (fog_draw) {
                                this->Terrain_Fog_Clip_Mask->AddMiniList(
                                    fog_list, screen_x, screen_y);
                            }
                            if (black_list != 0) {
                                if (normal_draw) {
                                    this->Terrain_Clip_Mask->SubtractMiniList(
                                        black_list, screen_x, screen_y);
                                }
                                if (fog_draw) {
                                    this->Terrain_Fog_Clip_Mask
                                        ->SubtractMiniList(black_list, screen_x,
                                                           screen_y);
                                }
                            }
                        }
                        {
                            terrain_override = this->map->terrain_types[terrain]
                                                   .terrain_to_draw;
                            if (terrain_override != -1) {
                                terrain = (unsigned char)terrain_override;
                            }
                        }
                        tile->last_drawn_shape2 = (unsigned char)black_mask_num;
                        tile->last_drawn_shape = (unsigned char)fog_mask_num;
                        tile->last_drawn_as = draw_as;
                        tile->draw_as = draw_as;
                        tile->draw_attribute &= 0xbf;
                        this->draw_tile(tile, terrain, (short)screen_x,
                                        (short)screen_y, (short)col, (short)row,
                                        draw_as, normal_draw, fog_draw);
                        ++tiles_drawn;
                    }

                TileOffScreen:
                    if (tile != 0 && (tile->draw_attribute & 0x40) == 0x40) {
                        terrain = tile->terrain_type;
                        terrain_override =
                            this->map->terrain_types[terrain].terrain_to_draw;
                        if (terrain_override != -1) {
                            terrain = (unsigned char)terrain_override;
                        }
                        this->draw_tile(tile, terrain, (short)screen_x,
                                        (short)screen_y, (short)col, (short)row,
                                        draw_as, 1, 1);
                        tile->draw_attribute &= 0xbf;
                    }

                    if (view_debug_Objects == 0 && tile != 0) {
                        SDI_Capture_Info = 1;
                        if (draw_as == 0) {
                            this->futur_objs->SetCaptureLevel(0, 5);
                        }
                        if (draw_as != 0x0f) {
                            fog_next_shape = 1;
                        }
                        tile->objects.draw(
                            this->save_area1, (short)screen_x,
                            (short)(tile->height * this->tile_half_hgt +
                                    screen_y),
                            draw_as == 0x80);
                        this->futur_objs->SetCaptureLevel(0, 0x28);
                        fog_next_shape = 0;
                        SDI_Capture_Info = 0;
                    }

                    (void)MapVis;
                }
            }
            ++col;
            ++row;
        }

        if (row_index == 1) {
            ++start_row;
        } else {
            --col_num;
        }
    }

    while (this->Queued_Blits != 0) {
        this->ProcessQueuedBlit(1);
    }
    if (MouseSystem != 0) {
        MouseSystem->Poll();
    }

    this->render_rect.left += rect.left;
    this->render_rect.top += rect.top;
    this->render_rect.right += rect.left;
    this->render_rect.bottom += rect.top;

    SDI_Capture_Info = 1;
    if (this->scroll_action == 2) {
        this->futur_objs->AddGDINode(
            4, 0x14,
            this->mouse_down_x - rect.left,
            this->mouse_down_y - rect.top,
            this->mouse_last_x - rect.left,
            this->mouse_last_y - rect.top,
            0, 0, 0, 0, 0x28, 0xFF, 0);
    }

    if (rge_base_game->game_mode == 1 ||
        (rge_base_game->game_mode > 6 && rge_base_game->game_mode <= 8)) {
        this->draw_object_outline();
    }
    if (rge_base_game->game_mode == 0x15) {
        this->draw_multi_object_outline();
    }

    {
        reset_all_cyclic = 0;
        if (this->extra_sprites != 0) {
            unsigned long now = debug_timeGetTime(
                s_C__msdev_work_age1_x1_view_cpp, 0xE3E);
            sprite = this->extra_sprites;
            while (sprite != 0) {
                remove_sprite = 0;
                if (sprite->theShape != 0) {
                    if (sprite->LastDrawTime == 0) {
                        sprite->LastDrawTime = now;
                    } else if ((sprite->displayfunction == 1 ||
                                sprite->displayfunction == 2) &&
                               now - sprite->LastDrawTime >=
                                   sprite->DrawTimeInterval) {
                        unsigned long elapsed = now - sprite->LastDrawTime;
                        do {
                            ++sprite->thefacet;
                            if (sprite->thefacet >=
                                sprite->theShape->shape_count()) {
                                sprite->thefacet = 0;
                                if (sprite->displayfunction == 2) {
                                    remove_sprite = 1;
                                    reset_all_cyclic = 1;
                                }
                            }
                            elapsed -= sprite->DrawTimeInterval;
                            sprite->LastDrawTime += sprite->DrawTimeInterval;
                        } while (elapsed >= sprite->DrawTimeInterval);
                    }
                    if (!remove_sprite) {
                        SDI_Draw_Level = sprite->drawLevel;
                        SDI_Object_ID = -1;
                        sprite->theShape->shape_draw(this->render_area,
                            sprite->world_x - this->map_scr_x_offset,
                            sprite->world_y - this->map_scr_y_offset,
                            sprite->thefacet,
                            sprite->flags,
                            sprite->colortable);
                    }
                }
                if (remove_sprite) {
                    if (sprite->prev != 0) {
                        sprite->prev->next = sprite->next;
                    }
                    if (sprite->next != 0) {
                        sprite->next->prev = sprite->prev;
                    }
                    if (sprite->prev == 0) {
                        this->extra_sprites = sprite->next;
                    }
                    next_sprite = sprite->next;
                    delete sprite;
                    sprite = next_sprite;
                } else {
                    sprite = sprite->next;
                }
            }
        }
        if (reset_all_cyclic) {
            this->reset_cyclic_overlay_sprites();
        }
    }

    SDI_Capture_Info = 0;
    this->render_rect.left -= rect.left;
    this->render_rect.top -= rect.top;
    this->render_rect.right -= rect.left;
    this->render_rect.bottom -= rect.top;

    {
        list = this->futur_objs;
        for (long y = 0; y < list->YLine_Size; ++y) {
            for (node = list->Draw_Clip_Nodes[y]; node != 0; node = node->Next) {
                level = node->Draw_Level;
                tail = list->Draw_Level_Tail[level];
                if (tail == 0) {
                    list->Draw_Level_Head[level] = node;
                } else {
                    tail->NextOnLevel = node;
                }
                list->Draw_Level_Tail[level] = node;
            }
        }
    }

    Clip_draw = 0;
    Clip_remove = 0;
    if (MapVis != 0) {
        this->Terrain_Clip_Mask->SetSpanRegions(this->render_rect.left, this->render_rect.top,
            this->render_rect.right, this->render_rect.bottom);
        this->Terrain_Fog_Clip_Mask->SetSpanRegions(this->render_rect.left, this->render_rect.top,
            this->render_rect.right, this->render_rect.bottom);
    }

    {
        list = this->futur_objs;
        for (level = 0; level < 6; ++level) {
            for (node = list->Draw_Level_Head[level]; node != 0; node = node->NextOnLevel) {
                if (node->Node_Type == 0) {
                    clip = this->Terrain_Clip_Mask;
                    _ASMSet_Surface_Info(this->save_area1->DisplayOffsets, clip->Line_Head_Ptrs,
                        clip->Line_Tail_Ptrs, clip->Min_Span_Px, clip->Min_Line,
                        clip->Max_Span_Px, clip->Max_Line);
                    _ASMSet_Color_Xform((void*)node->Xform_Mask);
                    _ASMSet_Xlate_Table(node->Color_Table);
                    shape = node->Shape;
                    _ASMDraw_Sprite((long)node->Shape_Base, node->Draw_X, node->Draw_Y,
                        shape->Width, shape->Height, shape->Shape_Data_Offsets,
                        shape->Shape_Outline_Offset, node->Draw_Flag & 0xFE);
                    clip = this->Terrain_Fog_Clip_Mask;
                    _ASMSet_Surface_Info(this->save_area1->DisplayOffsets, clip->Line_Head_Ptrs,
                        clip->Line_Tail_Ptrs, clip->Min_Span_Px, clip->Min_Line,
                        clip->Max_Span_Px, clip->Max_Line);
                    _ASMDraw_Sprite((long)node->Shape_Base, node->Draw_X, node->Draw_Y,
                        shape->Width, shape->Height, shape->Shape_Data_Offsets,
                        shape->Shape_Outline_Offset, node->Draw_Flag | 1);
                }
            }
        }
    }

    if (MouseSystem != 0) {
        MouseSystem->Poll();
    }
    if (rge_base_game->prog_mode == 4 && this->have_focus != 0 &&
        MouseSystem->get_game_enable() != 0) {
        unsigned long now = debug_timeGetTime(
            s_C__msdev_work_age1_x1_view_cpp, 0xF11);
        if (this->Get_Cursor_Position(&pt, -rect.left, -rect.top) != 0) {
            long touched;
            if (this->pick_touched_object(this->futur_objs, pt.x, pt.y, 10, 0x28, &touched) == 1) {
                if (this->UC_ObjectTouched == 0 || this->UC_TouchedObj != touched) {
                    this->UC_ObjectTouched = 1;
                    if (this->UC_TouchedObj != touched) {
                        this->UC_StartTime = now;
                        this->UC_TouchedObj = touched;
                        facet = 0;
                        text_id = 0;
                        if (this->player->get_mouse_pointer_action_vars(
                                touched, facet, text_id) == 1) {
                            MouseSystem->set_game_facet(facet);
                            if (this->message_panel != 0 && rge_base_game->rollover != 0) {
                                this->get_string(text_id, text, 0x7F);
                                this->message_panel->show_message(
                                    TMessagePanel::InfoMessage, text, 'p', 0,
                                    0, 0, 0);
                            }
                        } else {
                            MouseSystem->set_game_facet(0);
                            if (this->message_panel != 0 && rge_base_game->rollover != 0) {
                                this->message_panel->remove_message();
                            }
                        }
                    }
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

    for (panel_node = this->first_child_node; panel_node != 0;
         panel_node = panel_node->next_node) {
        panel = panel_node->panel;
        if (panel->active != 0 && panel->need_redraw != TPanel::RedrawNone) {
            panel->get_true_render_rect(pr);
            long x1 = pr.left - rect.left;
            long y1 = pr.top - rect.top;
            long x2 = pr.right - rect.left;
            long y2 = pr.bottom - rect.top;
            if (x1 < 0) x1 = 0;
            if (y1 < 0) y1 = 0;
            added = this->futur_objs->AddGDINode(
                3, y1, x1, y1, x2, y2, 0, 0, 0, 0, 0x1E,
                panel->display_changed_count, 0);
            if (added != 0) {
                list = this->futur_objs;
                tail = list->Draw_Level_Tail[0x1E];
                if (tail == 0) {
                    list->Draw_Level_Head[0x1E] = added;
                } else {
                    tail->NextOnLevel = added;
                }
                list->Draw_Level_Tail[0x1E] = added;
            }
        }
    }

    if (this->render_terrain_mode == 0) {
        long y = 0;
        if (this->save_area1->Height > 0) {
            do {
                this->Master_Clip_Mask->AddSpan(0, this->save_area1->Width - 1, y);
                ++y;
            } while (y < this->save_area1->Height);
        }
        this->prior_objs->ReclaimAllNodes();
    } else {
        long y;
        this->Master_Clip_Mask->Merge_n_Align(this->Terrain_Clip_Mask, this->Terrain_Fog_Clip_Mask);
        if (this->Limited_Render_Rect != 0) {
            if (this->Render_Rect1.left >= 0) {
                y = this->Render_Rect1.top;
                if (y <= this->Render_Rect1.bottom) {
                    do {
                        this->Master_Clip_Mask->AddSpan(
                            this->Render_Rect1.left, this->Render_Rect1.right, y);
                        ++y;
                    } while (y <= this->Render_Rect1.bottom);
                }
            }
            if (this->Use_Rect2 != 0) {
                if (this->Render_Rect2.left >= 0) {
                    y = this->Render_Rect2.top;
                    if (y <= this->Render_Rect2.bottom) {
                        do {
                            this->Master_Clip_Mask->AddSpan(
                                this->Render_Rect2.left, this->Render_Rect2.right, y);
                            ++y;
                        } while (y <= this->Render_Rect2.bottom);
                    }
                }
            }
        }

        future = this->futur_objs;
        prior = this->prior_objs;
        for (y = 0; y < future->YLine_Size; ++y) {
            for (future_node = future->Draw_Clip_Nodes[y]; future_node != 0;
                 future_node = future_node->Next) {
                if (future_node->Draw_Level > 5) {
                    bool different = true;
                    prior_node = prior->Draw_Clip_Nodes[y];
                    while (prior_node != 0) {
                        long bytes = (future_node->Node_Type != 0) ? 0x14 : 0x24;
                        if (memcmp(&future_node->Shape, &prior_node->Shape, bytes) == 0) {
                            different = false;
                            ++Clip_remove;
                            prior_node->Node_Type = -1;
                            break;
                        }
                        prior_node = prior_node->Next;
                    }
                    if (different) {
                        if (future_node->Node_Type == 0) {
                            this->Master_Clip_Mask->AddShape_Align(
                                future_node->Shape_Base, future_node->Shape,
                                future_node->Draw_X, future_node->Draw_Y,
                                ((future_node->Draw_Flag & 2) == 2));
                            ++Clip_draw;
                        } else {
                            this->Add_GDI_Clip_Mask(future_node, this->Master_Clip_Mask);
                        }
                    }
                }
            }
            for (prior_node = prior->Draw_Clip_Nodes[y]; prior_node != 0;
                 prior_node = prior_node->Next) {
                if (prior_node->Draw_Level > 5 && prior_node->Node_Type != -1) {
                    bool different = true;
                    future_node = future->Draw_Clip_Nodes[y];
                    while (future_node != 0) {
                        long bytes = (prior_node->Node_Type != 0) ? 0x14 : 0x24;
                        if (memcmp(&future_node->Shape, &prior_node->Shape, bytes) == 0) {
                            different = false;
                            break;
                        }
                        future_node = future_node->Next;
                    }
                    if (different) {
                        if (prior_node->Node_Type == 0) {
                            this->Master_Clip_Mask->AddShape_Align(
                                prior_node->Shape_Base, prior_node->Shape,
                                prior_node->Draw_X, prior_node->Draw_Y,
                                ((prior_node->Draw_Flag & 2) == 2));
                            ++Clip_draw;
                        } else {
                            this->Add_GDI_Clip_Mask(prior_node, this->Master_Clip_Mask);
                        }
                    }
                }
            }
        }
    }

    this->render_rect.left += rect.left;
    this->render_rect.top += rect.top;
    this->render_rect.right += rect.left;
    this->render_rect.bottom += rect.top;
    this->save_area1->PtrSpanCopy(this->render_area, this->render_rect.left, this->render_rect.top,
                                  &this->save_area1->ClipRect,
                                  (unsigned char**)this->Master_Clip_Mask->Line_Head_Ptrs);
    this->Update_Render_Pointers();
    this->render_rect.left -= rect.left;
    this->render_rect.top -= rect.top;
    this->render_rect.right -= rect.left;
    this->render_rect.bottom -= rect.top;
    _ASMSet_Surface_Info(this->RenderOffsets, this->Master_Clip_Mask->Line_Head_Ptrs,
        this->Master_Clip_Mask->Line_Tail_Ptrs, this->Master_Clip_Mask->Min_Span_Px,
        this->Master_Clip_Mask->Min_Line, this->Master_Clip_Mask->Max_Span_Px,
        this->Master_Clip_Mask->Max_Line);
    this->render_area->CurSpanList = this->Master_Clip_Mask;

    {
        list = this->futur_objs;
        for (level = 6; level < 41; ++level) {
            for (node = list->Draw_Level_Head[level]; node != 0; node = node->NextOnLevel) {
                if (node->Node_Type == 0) {
                    shadowing = 0;
                    shadow_flags = node->Draw_Flag & 0xFFC;
                    if (shadow_flags != 0) {
                        if ((shadow_flags & 4) == 4) {
                            _ASMSet_Shadowing(0xFFFFFF, 0, 0xFFFF00FF, 0);
                        }
                        if ((shadow_flags & 8) == 8) {
                            shadow_value = shadow_flags >> 4;
                            _ASMSet_Shadowing(0xFF00FF00,
                                (shadow_value << 16) | shadow_value,
                                0x00FF00FF, shadow_value << 8);
                        }
                        shadowing = 1;
                    }
                    _ASMSet_Color_Xform((void*)node->Xform_Mask);
                    _ASMSet_Xlate_Table(node->Color_Table);
                    shape = node->Shape;
                    _ASMDraw_Sprite((long)node->Shape_Base, node->Draw_X, node->Draw_Y,
                                    shape->Width, shape->Height,
                                    shape->Shape_Data_Offsets,
                                    shape->Shape_Outline_Offset,
                                    node->Draw_Flag & 3);
                    if (shadowing) {
                        _ASMSet_Shadowing(0xFF00FF, 0, 0xFF00FF00, 0);
                    }
                } else {
                    this->Draw_GDI_Object(node, this->render_area);
                }
            }
        }
    }

    if (view_debug_spans != 0 && this->render_terrain_mode != 0) {
        color = frame_count % 0xDC + 0x10;
        long y = 0;
        if (this->render_area->Height > 0) {
            do {
                this->render_area->DrawLine(0, y, this->render_area->Width - 1, y, color);
                ++y;
            } while (y < this->render_area->Height);
        }
    }

    if (view_debug_palette != 0) {
        row_base = 0;
        long y = 0x20;
        do {
            row_color = (unsigned char)(row_base * 0x10);
            palette_color = 0;
            x = 0;
            do {
                this->render_area->FillRect(x, y, x + 0x1F, y + 0x0F,
                                           (unsigned char)(palette_color + row_color));
                x += 0x20;
                ++palette_color;
            } while (x < 0x200);
            y += 0x10;
            ++row_base;
        } while (y < 0x120);
    }

    this->render_area->Unlock(s_view__view_function_terrain);
    this->render_area->CurSpanList = this->render_area->SpanList;
    {
        tmp = this->prior_objs;
        this->prior_objs = this->futur_objs;
        this->futur_objs = tmp;
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
        RenderOffsets = (void**)malloc(count * sizeof(void*));
        LastRenderSize = count;
    }

    for (int i = 0; i < count; i++) {
        RenderOffsets[i] = static_cast<unsigned char*>(
            render_area->DisplayOffsets[i + render_rect.top]) + render_rect.left;
    }
}




void RGE_View::Add_GDI_Clip_Mask(DClipInfo_Node* node, TSpan_List_Manager* span_mgr)
{
    if (node->Node_Type == 1) {
        span_mgr->AddLine_Align(node->x1, node->y1, node->x2, node->y2);
        span_mgr->AddLine_Align(node->x2, node->y2, node->x3, node->y3);
        span_mgr->AddLine_Align(node->x3, node->y3, node->x4, node->y4);
        span_mgr->AddLine_Align(node->x4, node->y4, node->x1, node->y1);
        return;
    }
    int edge;
    if (node->Node_Type == 2 || node->Node_Type == 3) {
        int y1v;
        int y2v;
        int tmp;
        int y;

        int xl = node->x1 & ~3;
        edge = node->x2 | 3;
        y1v = node->y1;
        y2v = node->y2;
        if (y1v > y2v) {
            tmp = y1v; y1v = y2v; y2v = tmp;
        }
        if (y1v <= y2v) {
            y = y1v;
            do {
                span_mgr->AddSpan(xl, edge, y);
                y++;
            } while (y <= y2v);
        }
    }
    if (node->Node_Type == 4) {
        int y1v;
        int y2v;
        int x1v;
        int x2v;
        int tmp;
        int y;

        x1v = node->x1;
        x2v = node->x2;
        if (x1v > x2v) {
            tmp = x1v; x1v = x2v; x2v = tmp;
        }
        int xl = x1v & ~3;
        edge = x1v | 3;
        int right_edge = x2v & ~3;
        int xr = x2v | 3;
        y1v = node->y1;
        y2v = node->y2;
        if (y1v > y2v) {
            tmp = y1v; y1v = y2v; y2v = tmp;
        }
        span_mgr->AddSpan(xl, xr, y1v);
        span_mgr->AddSpan(xl, xr, y2v);
        y = y1v + 1;
        for (; y < y2v; y++) {
            span_mgr->AddSpan(xl, edge, y);
            span_mgr->AddSpan(right_edge, xr, y);
        }
    }
}


void RGE_View::draw_multi_object_outline() {}



void RGE_View::Draw_GDI_Object(DClipInfo_Node* node, TDrawArea* draw) {
    int i;

    if (node->Node_Type == 1) {
        draw->DrawLine(node->x1, node->y1, node->x2, node->y2, node->Draw_Flag);
        draw->DrawLine(node->x2, node->y2, node->x3, node->y3, node->Draw_Flag);
        draw->DrawLine(node->x3, node->y3, node->x4, node->y4, node->Draw_Flag);
        draw->DrawLine(node->x4, node->y4, node->x1, node->y1, node->Draw_Flag);
        return;
    }

    if (node->Node_Type == 2) {
        i = node->y1;
        if (i <= node->y2) {
            do {
                if (node->y3 != 0) {
                    draw->DrawLine(node->x1, i, node->x3, i, 0x4A);
                }
                if (node->y4 != 0) {
                    draw->DrawLine(node->x4, i, node->x2, i, 0x97);
                }
                i++;
            } while (i <= node->y2);
        }
    }

    if (node->Node_Type == 4) {
        draw->DrawLine(node->x1, node->y1, node->x2, node->y1, 0xFF);
        draw->DrawLine(node->x1, node->y2, node->x2, node->y2, 0xFF);
        draw->DrawLine(node->x1, node->y1, node->x1, node->y2, 0xFF);
        draw->DrawLine(node->x2, node->y1, node->x2, node->y2, 0xFF);
    }
}



int RGE_View::get_tile_mask_num(int col, int row, int map_width,
                                int map_height, unsigned long mask)
{
    unsigned int mask_number = 0;

    if (0 < col && 0 < row && col < map_width - 1 && row < map_height - 1) {
        if ((unified_map_offsets[row - 1][col] & mask) == 0)
            mask_number = 0x80;
        if ((unified_map_offsets[row][col + 1] & mask) == 0)
            mask_number |= 0x40;
        if ((unified_map_offsets[row + 1][col] & mask) == 0)
            mask_number |= 0x20;
        if ((unified_map_offsets[row][col - 1] & mask) == 0)
            mask_number |= 0x10;
        if ((unified_map_offsets[row - 1][col + 1] & mask) == 0)
            mask_number |= 0x08;
        if ((unified_map_offsets[row + 1][col + 1] & mask) == 0)
            mask_number |= 0x04;
        if ((unified_map_offsets[row + 1][col - 1] & mask) == 0)
            mask_number |= 0x02;
        if ((unified_map_offsets[row - 1][col - 1] & mask) == 0)
            mask_number |= 0x01;
    } else {
        if (0 < col && (unified_map_offsets[row][col - 1] & mask) == 0)
            mask_number = 0x10;
        int max_col = map_width - 1;
        if (col < max_col && (unified_map_offsets[row][col + 1] & mask) == 0)
            mask_number |= 0x40;
        if (0 < row && (unified_map_offsets[row - 1][col] & mask) == 0)
            mask_number |= 0x80;
        int max_row = map_height - 1;
        if (row < max_row && (unified_map_offsets[row + 1][col] & mask) == 0)
            mask_number |= 0x20;
        if (0 < col && 0 < row &&
            (unified_map_offsets[row - 1][col - 1] & mask) == 0)
            mask_number |= 0x01;
        if (0 < col && row < max_row &&
            (unified_map_offsets[row + 1][col - 1] & mask) == 0)
            mask_number |= 0x02;
        if (col < max_col && 0 < row &&
            (unified_map_offsets[row - 1][col + 1] & mask) == 0)
            mask_number |= 0x08;
        if (col < max_col && row < max_row &&
            (unified_map_offsets[row + 1][col + 1] & mask) == 0)
            mask_number |= 0x04;
    }

    return this->EdgeNumber[mask_number];
}



int RGE_View::draw_tile(RGE_Tile* tile, unsigned char terrain_type,
                        short x, short y, short map_x, short map_y,
                        unsigned char draw_attribute, int draw1, int draw2)
{
    unsigned char draw_border = tile->draw_attribute;
    int terrain_offset;
    int overlay_available;
    int terrain_draw;
    unsigned char border_info;
    int border_type;
    int left_index;
    int right_index;
    int bottom_index;
    int retval;
    int result = 0;

    if ((short)terrain_type >= this->map->num_terrain ||
        ((terrain_offset = (int)terrain_type * (int)sizeof(RGE_Tile_Set)),
         this->map->terrain_types[terrain_type].loaded == 0)) {
        return 0;
    }

    terrain_draw = 1;
    result = 0;
    overlay_available = 0;
    border_info = tile->border_type;
    border_type = border_info & 0x0F;

    if (border_type != 0) {
        RGE_Border_Set* border = &this->map->border_types[border_type];
        if (border->loaded != 0 && border->shape != 0) {
            if (border->border_style == 0) {
                short picture = this->get_border_picture(
                    border_type, tile->tile_type,
                    (unsigned char)(border_info >> 4), map_x, map_y);
                if (picture != -1) {
                    overlay_available = 1;
                    terrain_draw = border->draw_tile;
                }
            } else {
                if (this->get_border_edge_pictures(
                        border_type, tile->tile_type,
                        (unsigned char)(border_info >> 4), map_x, map_y,
                        left_index, bottom_index,
                        right_index, retval) != 0) {
                    overlay_available = 1;
                    terrain_draw = 1;
                }
            }
        }
    }

    if (View_Grid_Mode > 0 && (draw_border & 0xDF) == 0 &&
        ((((int)map_x / View_Grid_Mode) +
          ((int)map_y / View_Grid_Mode)) & 1) == 1) {
        draw_border |= 0x20;
    }

    if (view_debug_ObstructionMap != 0) {
        overlay_available = 0;
    }

    if (terrain_draw != 0) {
        TShape* shape = this->map->terrain_types[terrain_type].shape;
        short picture = this->get_tile_picture(
            terrain_type, tile->tile_type, map_x, map_y);
        if (shape != 0 && picture != -1) {
            if (view_debug_ObstructionMap != 0) {
                this->draw_terrain_obstruction_map(
                    x, y, shape, picture, map_x, map_y);
                return 1;
            }
            this->draw_terrain_shape(
                x, y, shape, picture, draw_attribute,
                draw_border, draw1, draw2);
            result = 1;
        }

        if (overlay_available == 0) {
            if (map_x > 0) {
                RGE_Tile* left = this->map->map_row_offset[map_y] + map_x - 1;
                left->draw_attribute |= 0x40;
            }
            if (map_y < this->map->map_height - 1) {
                RGE_Tile* below = this->map->map_row_offset[map_y + 1] + map_x;
                below->draw_attribute |= 0x40;
            }
        }
    }

    if (overlay_available == 0) {
        goto done;
    }

    {
        TShape* shape = this->map->border_types[border_type].shape;
        if (shape != 0) {
            if (this->map->border_types[border_type].border_style == 0) {
                short picture = this->get_border_picture(
                    border_type, tile->tile_type,
                    (unsigned char)(border_info >> 4), map_x, map_y);
                if (picture != -1) {
                    retval = picture;
                } else {
                    goto mark_neighbors;
                }
            } else {
                if (this->get_border_edge_pictures(
                        border_type, tile->tile_type,
                        (unsigned char)(border_info >> 4), map_x, map_y,
                        left_index, bottom_index,
                        right_index, retval) == 0) {
                    goto mark_neighbors;
                }
                if (left_index != -1) {
                    this->draw_terrain_shape(
                        x, y, shape, left_index, draw_attribute,
                        draw_border, draw1, draw2);
                }
                if (right_index != -1) {
                    this->draw_terrain_shape(
                        x, y, shape, right_index, draw_attribute,
                        draw_border, draw1, draw2);
                }
                if (bottom_index != -1) {
                    this->draw_terrain_shape(
                        x, y, shape, bottom_index, draw_attribute,
                        draw_border, draw1, draw2);
                }
                if (retval == -1) {
                    goto mark_neighbors;
                }
            }
            this->draw_terrain_shape(
                x, y, shape, retval, draw_attribute,
                draw_border, draw1, draw2);
        }
    }

mark_neighbors:
    if (map_x > 0) {
        RGE_Tile* left = this->map->map_row_offset[map_y] + map_x - 1;
        left->draw_attribute |= 0x40;
    }
    if (map_y < this->map->map_height - 1) {
        RGE_Tile* below = this->map->map_row_offset[map_y + 1] + map_x;
        below->draw_attribute |= 0x40;
    }

done:
    return result;
}




void RGE_View::draw_terrain_shape(int x, int y, TShape* shape, int frame, unsigned char vis, unsigned char fog_flag, int draw1, int draw2)
{
    int draw_x = x - shape->shape_info[frame].Hotspot_X;
    int draw_y = y - shape->shape_info[frame].Hotspot_Y;

    if ((fog_flag & 0x10) == 0x10) {
        fog_next_shape = 1;
        _ASMSet_Shadowing(0x00ff00ff, 0x28002800, 0xff00ff00, 0x00280028);
        shape->shape_draw(this->cur_render_area, draw_x, draw_y, frame, 0, 0);
        _ASMSet_Shadowing(0x00ff00ff, 0, 0xff00ff00, 0);
        fog_next_shape = 0;
        return;
    }

    if ((fog_flag & 0x20) == 0x20) {
        _ASMSet_Shadowing(0x00ff00ff, 0x56005600, 0xff00ff00, 0x00560056);
    }

    if ((fog_flag & 0x80) == 0x80) {
        int c = fog_flag & 0x0f;
        int value = (((c << 16) + c) << 12) + 0x04000400;
        _ASMSet_Shadowing(0x00ff00ff, value, 0xff00ff00, value);
    }

    int one = 1;
    int zero = 0;
    if (this->map->fog_flag != 0 && vis == 0x80) {
        fog_next_shape = one;
    }

    if (draw2 != 0) {
        this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
        fog_next_shape = one;
        shape->shape_draw(this->cur_render_area, x, y, frame, 0, 0);
        fog_next_shape = zero;
    }

    if ((fog_flag & 0xa0) != 0) {
        fog_next_shape = one;
    }

    if (draw1 != 0) {
        this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
        shape->shape_draw(this->cur_render_area, x, y, frame, 0, 0);
    }

    this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
    _ASMSet_Shadowing(0x00ff00ff, 0, 0xff00ff00, 0);
    fog_next_shape = zero;
}



void RGE_View::draw_terrain_obstruction_map(
    int x, int y, TShape* shape, int frame, int tile_x, int tile_y)
{
    int outer;
    int tile_x4 = tile_x * 4;
    tile_y *= 4;

    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
    shape->shape_draw(this->cur_render_area, x, y, frame, 0, 0);

    TShape* obstruction_shape = rge_base_game->get_shape(0);
    for (outer = 0; outer < 4; ++outer) {
        int i = 0;
        frame = tile_y + outer;
        int x_offset = outer * 8;
        int y_offset = outer * 4;

        do {
            int obstruction = pathSystem.obstruction(i + tile_x4, frame);
            if (obstruction > 0) {
                obstruction_shape->shape_draw(this->cur_render_area,
                    x + 2 + x_offset,
                    y + 0x0D + y_offset,
                    obstruction - 1, 0, 0);
            }
            ++i;
            x_offset += 8;
            y_offset -= 4;
        } while (i < 4);

    }
}



int RGE_View::Get_Cursor_Position(tagPOINT& point, int offset_x, int offset_y) {
    GetCursorPos(&point);
    TDrawSystem* draw_system = this->render_area->DrawSystem;
    if (draw_system->ScreenMode == 1) {
        ScreenToClient(draw_system->Wnd, &point);
        if (point.x > 0x7FFF)
            point.x -= 0x10000;
        if (point.y > 0x7FFF)
            point.y -= 0x10000;
    }
    point.x += offset_x;
    int new_x = point.x;
    point.y += offset_y;
    int new_y = point.y;

    if (new_x < this->render_rect.left || new_x > this->render_rect.right ||
        new_y < this->render_rect.top || new_y > this->render_rect.bottom)
        return 0;
    return 1;
}



int RGE_View::Pick_Tile(long px, long py, int* col_out, int* row_out) {
    int map_h;
    int map_w;
    int by1;
    int bx1;
    map_h = map->map_height;
    map_w = map->map_width;
    bx1 = (map_scr_x_offset - this->render_rect.left) + px;
    by1 = (map_scr_y_offset - this->render_rect.top) + py;

    if (bx1 < 0) {
        *col_out = -1;
        *row_out = -1;
        return 0;
    }

    if (bx1 >= map_w * tile_wid) {
        *col_out = map_w + 1;
        *row_out = map_h + 1;
        return 0;
    }

    int tcol = bx1 / tile_wid;
    int trow = by1 / tile_hgt;
    int diff = tcol - trow;
    tcol = tcol + trow;

    while (diff < 0 || tcol >= map_w) {
        tcol--;
        diff++;
    }

    while (diff >= map_h || tcol < 0) {
        tcol++;
        diff--;
    }

    int found = 1;
    do {
        int bound_row;
        int bound_top;
        int bound_left;
        get_tile_bounding_coords(tcol, diff, map_w,
                                 bound_row, bound_top, bound_left);
        if (by1 < bound_row) {
            tcol++;
            diff--;
        } else if (by1 > bound_left) {
            tcol--;
            diff++;
        } else {
            found = 0;
        }
    } while (found);

    tile_half_hgt = 0;
    tile_half_wid = 0;
    return 0;
}




void RGE_View::get_tile_bounding_coords(int param_1, int param_2, int& param_3, int& param_4, int& param_5, int& param_6) {
    RGE_Tile* pRVar3 = this->map->map_row_offset[param_2];
    short sVar2 = pRVar3[param_1].screen_xpos;
    byte bVar1 = pRVar3[param_1].tile_type;
    param_3 = sVar2;
    param_5 = this->map->tilesizes[bVar1].width + sVar2 - 1;
    param_4 = pRVar3[param_1].screen_ypos - this->tile_half_hgt;
    this->tile_half_hgt = 0;
    this->tile_half_wid = 0;
    this->elev_hgt = 0;
    param_6 = this->map->tilesizes[bVar1].height + param_4 - 1;
}



int RGE_View::pick_objects(int x, int y, int min_level, int max_level,
                           int radius, int priority, int skip_negative)
{
    RGE_SPick_Info* head[5];
    RGE_SPick_Info* tail[5];
    RGE_SPick_Info* freep[5];
    RGE_SPick_Info* found;
    RGE_SPick_Info* previous;
    RGE_SPick_Info* current;
    RGE_SPick_Info** head_ptr;
    DClipInfo_Node* node;
    int level;
    int confidence;
    int object_id;
    int selected_level;
    short draw_level;
    int i;
    int keep;
    int total_picked = 0;
    int* pick_sizes;

    if (radius < 0) {
        return 0;
    }
    if (max_level < min_level) {
        return 0;
    }
    if (x < this->render_rect.left || x > this->render_rect.right ||
        y < this->render_rect.top || y > this->render_rect.bottom) {
        return 0;
    }
    if (0x28 < min_level || max_level < 0) {
        return 0;
    }

    if (min_level < 0) {
        min_level = 0;
    }
    if (max_level > 0x28) {
        max_level = 0x28;
    }

    y -= this->render_rect.top;
    x -= this->render_rect.left;

    pick_sizes = this->pick_list_size + 1;
    pick_sizes[0] = 0;
    pick_sizes[1] = 0;
    pick_sizes[2] = 0;
    pick_sizes[3] = 0;

    freep[1] = 0;
    freep[2] = 0;
    freep[3] = 0;
    freep[4] = 0;
    tail[1] = 0;
    tail[2] = 0;
    tail[3] = 0;
    tail[4] = 0;
    head[1] = 0;
    head[2] = 0;
    head[3] = 0;
    head[4] = 0;

    level = max_level;
    do {
        if (level < min_level) {
            int output_level = 1;
            head_ptr = head + 1;
            for (; output_level < 5; ++output_level, ++head_ptr) {
                current = *head_ptr;
                if (current != 0) {
                    RGE_Pick_Obj_Info* output = &Picked_Objects[total_picked];
                    do {
                        output->object_id = current->object_id;
                        output->confidence = current->confidence;
                        output->draw_level = current->draw_level;
                        output->draw_x = current->draw_x;
                        output->draw_y = current->draw_y;
                        ++total_picked;
                        ++output;
                        current = current->next;
                    } while (current != 0);
                }
            }
            return total_picked;
        }

        node = this->prior_objs->Draw_Level_Head[level];
        for (; node != 0; node = node->NextOnLevel) {
            confidence = 0;
            if (node->Node_Type == 0 &&
                (skip_negative == 0 || node->Object_ID >= 0)) {
                int node_y1 = node->y1;
                int node_x2 = node->x2;
                if (x < node->x1 - radius ||
                    y < node_y1 - radius ||
                    radius + node_x2 < x ||
                    node->y2 + radius < y) {
                    confidence = 0;
                } else {
                    confidence = 4;
                    if (node->x1 <= x && node_y1 <= y &&
                        x <= node_x2 && y <= node->y2) {
                        confidence = 3;
                        if ((node->Draw_Flag & 2) == 2) {
                            node_x2 -= x;
                        } else {
                            node_x2 = x - node->x1;
                        }
                        int mask = this->sprite_check(
                            node->Shape_Base, node->Shape,
                            node_x2, y - node_y1);
                        if (mask == 1) {
                            confidence = 2;
                        } else if (mask == 2) {
                            confidence = 1;
                        }
                    }
                }
            }

            if (confidence != 0 && confidence <= priority) {
                draw_level = node->y3;
                object_id = node->Object_ID;
                keep = 1;
                found = 0;
                int picked_level = 1;
                head_ptr = head + 1;
                do {
                    if (found == 0) {
                        current = *head_ptr;
                        if (current != 0) {
                            do {
                                if (current->object_id == object_id) {
                                    found = current;
                                    selected_level = picked_level;
                                    break;
                                }
                                current = current->next;
                            } while (current != 0);
                        }
                    }
                    ++picked_level;
                    ++head_ptr;
                } while (picked_level < 5);

                if (found != 0) {
                    if (selected_level < confidence ||
                        (selected_level == confidence &&
                         draw_level < found->draw_level)) {
                        keep = 0;
                    }

                    if (keep) {
                        if (head[selected_level] == found) {
                            head[selected_level] = found->next;
                        }
                        if (tail[selected_level] == found) {
                            tail[selected_level] = found->prev;
                        }
                        if (found->next != 0) {
                            found->next->prev = found->prev;
                        }
                        if (found->prev != 0) {
                            found->prev->next = found->next;
                        }
                        found->next = freep[selected_level];
                        found->prev = 0;
                        freep[selected_level] = found;
                    }
                }

                if (keep) {
                    current = freep[confidence];
                    if (current == 0) {
                        i = this->pick_list_size[confidence];
                        if (i == 0x40) {
                            keep = 0;
                        } else {
                            current = this->pick_lists[confidence] + i;
                            this->pick_list_size[confidence] = i + 1;
                        }
                    } else {
                        freep[confidence] = current->next;
                    }

                    if (keep) {
                        current->object_id = object_id;
                        current->confidence = (short)confidence;
                        current->draw_level = draw_level;
                        current->draw_x = (short)node->Draw_X;
                        current->draw_y = (short)node->Draw_Y;
                        head_ptr = head + confidence;
                        current->next = 0;
                        current->prev = 0;
                        found = *head_ptr;
                        if (found == 0) {
                            *head_ptr = current;
                            tail[confidence] = current;
                        } else {
                            do {
                                if (found->draw_level <= draw_level) {
                                    current->next = found;
                                    previous = found->prev;
                                    current->prev = previous;
                                    if (previous == 0) {
                                        *head_ptr = current;
                                        found->prev = current;
                                    } else {
                                        current->prev->next = current;
                                        found->prev = current;
                                    }
                                    break;
                                }
                                previous = found->next;
                                if (previous == 0) {
                                    found->next = current;
                                    current->prev = found;
                                    tail[confidence] = current;
                                    break;
                                }
                                found = previous;
                            } while (found != 0);
                        }
                    }
                }
            }

        }
        --level;
    } while (true);
}




int RGE_View::sprite_check(uchar* shape, Shape_Info* info, int x, int y)
{
    int width;
    int start;
    int right_pad;
    uchar* p;
    uchar code;
    unsigned int n;
    Shape_Info* shape_info = info;

    if (shape_info != 0) {
        if (x >= 0) {
                    width = shape_info->Width;
            if (x < width) {
                if (y >= 0) {
                    if (y < shape_info->Height) {
                        uchar* outline = shape + shape_info->Shape_Outline_Offset;
                        start = *(short*)(outline + y * 4);
                        right_pad = *(short*)(outline + y * 4 + 2);
                        if (start >= 0) {
                            if (x >= start) {
                                if (x <= width - right_pad) {
                                    int* data_offsets = (int*)(shape + shape_info->Shape_Data_Offsets);
                                    p = shape + data_offsets[y];
                                    if (start < width) {
                                        while (start < width) {
                                            if (x < start) {
                                                return 1;
                                            }
                                        code = *p++;
                                        switch (code & 0x0F) {
                                            case 0:
                                            case 4:
                                            case 8:
                                            case 12:
                                                n = ((unsigned int)code) >> 2;
                                                start += n;
                                                if (x < start) goto ret2;
                                                p += n;
                                                break;
                                            case 2:
                                                n = (((unsigned int)code) << 4) | (unsigned int)(*p++);
                                                start += n;
                                                if (x < start) goto ret2;
                                                p += n;
                                                break;
                                            case 1:
                                            case 5:
                                            case 9:
                                            case 13:
                                                n = ((unsigned int)code) >> 2;
                                                start += n;
                                                break;
                                            case 3:
                                                n = (((unsigned int)code) << 4) | (unsigned int)(*p++);
                                                start += n;
                                                break;
                                            case 6:
                                                n = ((unsigned int)code) >> 4;
                                                if (n == 0) n = *p++;
                                                start += n;
                                                if (x < start) goto ret2;
                                                p += n;
                                                break;
                                            case 7:
                                            case 10:
                                                n = ((unsigned int)code) >> 4;
                                                if (n == 0) n = *p++;
                                                start += n;
                                                if (x < start) goto ret2;
                                                p++;
                                                break;
                                            case 11:
                                                n = ((unsigned int)code) >> 4;
                                                if (n == 0) n = *p++;
                                                start += n;
                                                if (x < start) goto ret2;
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
        }
    }
ret0:
    return 0;
ret2:
    return 2;
}



int RGE_View::pick_multi_objects(int x1, int y1, int x2, int y2, int min_level, int max_level, int player_id, unsigned char select_level, int flag)
{
    int num_picked = 0;
    int z;
    if (x2 < this->render_rect.left || x1 > this->render_rect.right ||
        y2 < this->render_rect.top || y1 > this->render_rect.bottom)
        return 0;
    if (min_level > 40 || max_level < 0)
        return 0;
    if (min_level < 0) min_level = 0;
    if (max_level > 40) max_level = 40;

    x1 -= this->render_rect.left;
    x2 -= this->render_rect.left;
    y1 -= this->render_rect.top;
    y2 -= this->render_rect.top;

    z = max_level;
    if (z >= min_level) {
        do {
            DClipInfo_Node* node = this->prior_objs->Draw_Level_Head[z];
            if (node != 0) {
                RGE_Pick_Obj_Info* out = &Picked_Objects[num_picked];
                do {
                    int ok = 0;
                    if (node->Node_Type == 0) {
                        int object_id = node->Object_ID;
                        if (object_id >= 0) {
                            if (x1 <= (int)node->x2 && x2 >= (int)node->x1 &&
                                y1 <= (int)node->y2 && y2 >= (int)node->y1) {
                                RGE_Static_Object* obj = this->world->objectsValue[object_id];
                                if (player_id == -1 || obj->owner->id == player_id) {
                                    if (obj->object_state == 2 && obj->master_obj->select_level >= select_level) {
                                        ok = 1;
                                    }
                                }
                            }
                        }
                    }
                    if (ok != 0) {
                        int add = 1;
                        if (out > &Picked_Objects[0]) {
                            int i = 0;
                            RGE_Pick_Obj_Info* p = Picked_Objects;
                            do {
                                if (p->object_id == node->Object_ID) {
                                    add = 0;
                                    if ((short)ok < Picked_Objects[i].confidence) {
                                        Picked_Objects[i].confidence = (short)ok;
                                    }
                                    break;
                                }
                                i++;
                                ++p;
                            } while (i < num_picked);
                        }
                        if (add) {
                            out->object_id = node->Object_ID;
                            out->confidence = (short)ok;
                            out->draw_level = (short)ok;
                            out->draw_x = node->Draw_X;
                            out->draw_y = node->Draw_Y;
                            num_picked++;
                            ++out;
                        }
                        if (out >= &Picked_Objects[64]) return 0x40;
                    }
                    node = node->NextOnLevel;
                } while (node != 0);
            }
            z--;
        } while (z >= min_level);
    }
    return num_picked;
}



int RGE_View::pick_touched_object(DClipInfo_List* list, int x, int y, int min_level, int max_level, int& out_object_id)
{
    out_object_id = 0;
    if (max_level >= min_level &&
        x >= this->render_rect.left && x <= this->render_rect.right &&
        y >= this->render_rect.top && y <= this->render_rect.bottom &&
        min_level <= 0x28 && max_level >= 0) {
        if (min_level < 0) {
            min_level = 0;
        }
        if (max_level > 0x28) {
            max_level = 0x28;
        }
        int found = 0;
        int level = max_level;
        if (level >= min_level) {
            do {
                DClipInfo_Node* node = list->Draw_Level_Head[level];
                if (node != 0) {
                    do {
                        if (node->Node_Type == 0) {
                            int flags = node->Draw_Flag;
                            int x1 = node->x1;
                            int y1 = node->y1;
                            int x2 = node->x2;
                            if ((flags & 2) == 2) {
                                if (this->sprite_check(node->Shape_Base, node->Shape, x2 - x, y - y1) == 2) {
                                    found = 1;
                                    out_object_id = node->Object_ID;
                                }
                            } else {
                                if (this->sprite_check(node->Shape_Base, node->Shape, x - x1, y - y1) == 2) {
                                    found = 1;
                                    out_object_id = node->Object_ID;
                                }
                            }
                        }
                        node = node->NextOnLevel;
                    } while (node != 0);
                }
                if (found == 1) {
                    return 1;
                }
                level--;
            } while (level >= min_level);
        }
    }
    return 0;
}



short RGE_View::get_tile_picture(unsigned char param_1, unsigned char param_2, short param_3, short param_4) {
    RGE_Tile_Set* ts = &this->map->terrain_types[param_1];
    if (ts->shape == 0) return -1;

    RGE_TOB_Picts* tile = &ts->tiles[param_2];
    if (tile->count == 0) return -1;

    short result = 0;
    if (tile->count > 1) {
        unsigned char rows = (unsigned char)ts->rows;
        unsigned char cols = (unsigned char)ts->cols;
        param_1 = rows;
        param_2 = cols;
        if (rows > 1 || cols > 1) {
            if (rows > 0) param_1 = (unsigned char)(param_4 % rows); else param_1 = 0;
            if (cols > 0) param_2 = (unsigned char)(param_3 % cols); else param_2 = 0;
            result = (unsigned short)param_1 * (unsigned short)cols + (unsigned short)param_2;
        }
    }

    if (result > tile->count - 1) result = 0;
    return (short)(tile->animations * result + tile->shape_index);
}



short RGE_View::get_border_picture(unsigned char param_1, unsigned char param_2, unsigned char param_3, short param_4, short param_5) {
    RGE_Border_Set* bt = &this->map->border_types[param_1];
    if (bt->shape == 0) return -1;

    RGE_TOB_Picts* tile = &bt->borders[param_2 - 1][param_3 + 0xB];
    if (tile->count == 0) return -1;

    short result = 0;
    if (tile->count > 1) {
        short style = bt->border_style;
        if ((style == 0 && (param_3 == 0xB || param_3 == 0xC)) ||
            (style == 1 && (param_3 == 0x3 || param_3 == 0x2))) {
            result = param_5 % tile->count;
        } else if ((style == 0 && (param_3 == 0x9 || param_3 == 0xA)) ||
                   (style == 1 && (param_3 == 0x1 || param_3 == 0x4))) {
            result = param_4 % tile->count;
        } else {
            result = 0;
        }
    }

    if (result > tile->count - 1) result = 0;
    return (short)(tile->animations * result + tile->shape_index);
}



int RGE_View::get_border_edge_pictures(unsigned char param_1, unsigned char param_2, unsigned char param_3, short param_4, short param_5, int& param_6, int& param_7, int& param_8, int& param_9) {
    param_6 = -1;
    param_8 = -1;
    param_7 = -1;
    param_9 = -1;

    if (this->map->border_types[param_1].shape && param_3) {
        if (param_3 & 1) {
            short s = this->get_border_picture(param_1, param_2, 1, param_4, param_5);
            param_6 = (int)s;
        }
        if (param_3 & 2) {
            short s = this->get_border_picture(param_1, param_2, 4, param_4, param_5);
            param_9 = (int)s;
        }
        if (param_3 & 4) {
            short s = this->get_border_picture(param_1, param_2, 3, param_4, param_5);
            param_8 = (int)s;
        }
        if (param_3 & 8) {
            short s = this->get_border_picture(param_1, param_2, 2, param_4, param_5);
            param_7 = (int)s;
        }
        return 1;
    }
    return 0;
}



int RGE_View::hit_tile(RGE_Tile* tile, short sx, short sy,
                        short a, short b, tagPOINT* pt)
{
    short terrain_type = 0;
    short tile_type;

    if (tile) {
        tile_type = tile->tile_type;
        terrain_type = tile->terrain_type & 0x1F;
    } else {
        tile_type = 0;
    }

    if (pt->x >= sx) {
        if (pt->x < sx + this->map->tilesizes[(int)tile_type].width &&
            pt->y >= sy &&
            pt->y < sy + this->map->tilesizes[(int)tile_type].height) {
            RGE_Map* map = this->map;
            if (terrain_type < map->num_terrain &&
                map->terrain_types[terrain_type].loaded) {
                TShape* sh = map->terrain_types[terrain_type].shape;
                short pic = this->get_tile_picture(terrain_type, (unsigned char)tile_type, a, b);

                if (sh == 0 || pic == -1)
                    goto outer_success;

                if (pt->y >= sy + this->map->tilesizes[(int)tile_type].height)
                    goto failure;
                if (!sh->shape_check(pt->x - sx, pt->y - sy, pic))
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


RGE_Static_Object* RGE_View::hit_object(RGE_Tile* tile, short x, short y, short a, short b,
                                        tagPOINT* p1, tagPOINT* p2, short* out_x, short* out_y,
                                        RGE_Static_Object* skip, unsigned char through_fog)
{
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
                if (obj->object_state < 7) {
                    if ((!through_fog || obj->master_obj->fog_flag) &&
                        obj->master_obj->select_level >= this->function_parm) {
                        if (this->function_mode == '+' || this->function_mode == ',') {
                            if (obj->owner == this->player) {
                            if (this->function_mode == ',') {
                                if (obj->box_hit_test(sx, sy, (short)p2->x, (short)p2->y,
                                                      (short)p1->x, (short)p1->y)) {
                                    if (!this->player->select_one_object(obj, 0)) break;
                                    picked = obj;
                                }
                            } else {
                                goto ordinary_hit;
                            }
                            }
                        } else {
ordinary_hit:
                            if (obj->hit_test(sx, sy, (short)p1->x, (short)p1->y, 5)) {
                            if (skip != 0 && obj == skip && picked != 0) {
                                return picked;
                            }
                            if (picked != 0 && obj->owner != this->player && picked->owner == this->player) goto next;
                            if (picked != 0 && obj->master_obj->select_level < picked->master_obj->select_level) goto next;
                            {
                                picked = obj;
                                if (!obj->get_frame(frame_x, frame_y,
                                                    frame_x2, frame_y2)) {
                                    frame_x = 0;
                                    frame_y = 0;
                                }
                                *out_x = (short)(obj->screen_x_offset + frame_x + sx);
                                *out_y = (short)(obj->screen_y_offset + frame_y + sy);
                            }
                            }
                        }
                    }
                }
next:
                ;
        }
        while (first != 0) {
            RGE_Object_Node* next_node = first->next;
            free(first);
            first = next_node;
        }
    }
    return picked;
}



int RGE_View::start_scroll_view(unsigned char action, long x, long y,
                                int p4, int p5)
{
    RGE_Pick_Info pick_info;
    int result;

    if (action == 3) {
        if (this->pick(0x28, 0, x, y, &pick_info, 0) != 0x33) {
            return 0;
        }
        long col = (long)pick_info.y;
        long row = (long)pick_info.x;
        this->set_selection_area(row, col, row, col);
    } else if (action == 9) {
        this->pick(0x28, 0, x, y, &pick_info, 0);
        this->real_old_map_col = (long)pick_info.x;
        this->real_old_map_row = (long)pick_info.y;
        if (!this->do_paint(x, y, x, y, 1)) {
            return 0;
        }
        this->set_redraw((TPanel::RedrawMode)1);
    }

    result = 0;
    this->scroll_action = action;
    this->mouse_last_x = x;
    this->mouse_down_x = x;
    this->mouse_last_y = y;
    this->mouse_down_y = y;
    this->capture_mouse();

    if (this->scroll_action == 1 || this->scroll_action == 2 ||
        this->scroll_action == 6 || this->scroll_action == 7 ||
        this->scroll_action == 8) {
        rge_base_game->mouse_off();
    }

    if (this->scroll_action == 2) {
        if (p5 == 0 && p4 == 0) {
            this->player->unselect_object();
        }
        this->set_redraw((TPanel::RedrawMode)1);
    }

    if (this->scroll_action == 6 || this->scroll_action == 8) {
        if (this->pick(0x28, 0, x, y, &pick_info, 0) == 0x33) {
            this->player->set_view_loc(pick_info.x - DAT_005776c0,
                                       pick_info.y - DAT_005776c0);
            this->set_redraw((TPanel::RedrawMode)1);
            result = 1;
        }
    }

    return result;
}

int RGE_View::handle_scroll_view(long param_1, long param_2)
{
    long point_x;                 // saved mouse_last_x
    float save_view_x;            // saved player view_x
    float save_view_y;            // saved player view_y
    long lVar12;                  // saved mouse_last_y (late)
    int iVar10;                   // deltas / ftol results
    tagPOINT point;
    RGE_Pick_Info pick_info;
    int bVar7;

    point_x = this->mouse_last_x;
    if (param_1 == this->mouse_last_x && param_2 == this->mouse_last_y) {
        return 0;
    }

    save_view_x = this->player->view_x;
    save_view_y = this->player->view_y;

    switch (this->scroll_action) {
    case 2:
        this->mouse_last_x = param_1;
        this->mouse_last_y = param_2;
        this->bound_point(this->mouse_last_x, this->mouse_last_y);
            this->set_redraw((TPanel::RedrawMode)1);
        return 0;

    case 6:
        if (this->is_inside(param_1, param_2) != 0 &&
            this->pick(0x28, 0, param_1, param_2, &pick_info, 0) == 0x33) {
            this->player->set_view_loc(pick_info.x - DAT_005776c0, pick_info.y - DAT_005776c0);
        }
        this->mouse_last_x = param_1;
        this->mouse_last_y = param_2;
        if (save_view_x == this->player->view_x && save_view_y == this->player->view_y) {
            return 0;
        }
            this->set_redraw((TPanel::RedrawMode)1);
        return 1;

    case 7:
        iVar10 = param_2 - this->mouse_last_y;
        if (iVar10 != 0 && iVar10 < 100 && iVar10 > -100) {
            short sVar9 = (short)((float)iVar10 * DAT_005776b4);
            this->player->map_y += sVar9;
            this->player->map_x -= sVar9;
        }
        iVar10 = param_1 - this->mouse_last_x;
        if (iVar10 != 0 && iVar10 < 100 && iVar10 > -100) {
            short sVar9 = (short)((float)iVar10 * DAT_005776b4);
            this->player->map_y += sVar9;
            this->player->map_x += sVar9;
        }
        if (abs(param_2 - this->mouse_down_y) > 8 || abs(param_1 - this->mouse_down_x) > 8) {
            point.x = this->mouse_down_x;
            point.y = this->mouse_down_y;
            ClientToScreen(this->render_area->Wnd, &point);
            SetCursorPos(point.x, point.y);
            this->mouse_last_y = this->mouse_down_y;
            this->mouse_last_x = this->mouse_down_x;
            this->set_redraw((TPanel::RedrawMode)1);
            return 1;
        }
        this->mouse_last_x = param_1;
        this->mouse_last_y = param_2;
        this->set_redraw((TPanel::RedrawMode)1);
        return 1;

    case 8:
        iVar10 = param_2 - this->mouse_last_y;
        if (iVar10 != 0 && iVar10 < 100 && iVar10 > -100) {
            iVar10 = (int)((float)iVar10 * DAT_005776b4);
            this->player->set_view_loc(this->player->view_x - (float)iVar10,
                                       this->player->view_y + (float)iVar10);
        }
        iVar10 = param_1 - this->mouse_last_x;
        if (iVar10 != 0 && iVar10 < 100 && iVar10 > -100) {
            iVar10 = (int)((float)iVar10 * DAT_005776b4);
            this->player->set_view_loc(this->player->view_x + (float)iVar10,
                                       this->player->view_y + (float)iVar10);
        }
        if (abs(param_2 - this->mouse_down_y) <= 8 && abs(param_1 - this->mouse_down_x) <= 8) {
            this->mouse_last_x = param_1;
            this->mouse_last_y = param_2;
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
        this->set_redraw((TPanel::RedrawMode)1);
        return 1;
    }

    if (this->scroll_action == 3 || this->scroll_action == 4 || this->scroll_action == 9) {
        if ((param_1 < this->clip_rect.left + 0x40 && param_1 < point_x) ||
            (param_1 > this->clip_rect.right - 0x40 && param_1 > point_x) ||
            (param_2 < this->clip_rect.top + 0x20 && param_2 < this->mouse_last_y) ||
            (param_2 > this->clip_rect.bottom - 0x20 && param_2 > this->mouse_last_y)) {
            bVar7 = 1;
        } else {
            bVar7 = 0;
        }
    } else {
        bVar7 = 1;
    }

    iVar10 = param_2 - this->mouse_last_y;
    if (iVar10 != 0 && iVar10 < 200 && iVar10 > -200 && bVar7) {
        this->player->set_view_loc(this->player->view_x - (float)iVar10 * DAT_005776c4,
                                   this->player->view_y + (float)iVar10 * DAT_005776c4);
    }
    iVar10 = param_1 - this->mouse_last_x;
    if (iVar10 != 0 && iVar10 < 200 && iVar10 > -200 && bVar7) {
        this->player->set_view_loc(this->player->view_x + (float)iVar10 * DAT_005776c4,
                                   this->player->view_y + (float)iVar10 * DAT_005776c4);
    }

    point_x = this->mouse_last_x;
    lVar12 = this->mouse_last_y;
    this->mouse_last_x = param_1;
    this->mouse_last_y = param_2;
    if (bVar7) {
        if (abs(param_2 - this->mouse_down_y) > 8 || abs(param_1 - this->mouse_down_x) > 8) {
            point.x = this->mouse_down_x;
            point.y = this->mouse_down_y;
            ClientToScreen(this->render_area->Wnd, &point);
            SetCursorPos(point.x, point.y);
            this->mouse_last_x = this->mouse_down_x;
            this->mouse_last_y = this->mouse_down_y;
        }
    } else {
        this->mouse_down_x = param_1;
        this->mouse_down_y = param_2;
    }

    if (this->scroll_action == 3) {
        if (this->pick(0x28, 0, param_1, param_2, &pick_info, 0) == 0x33 && this->player != 0) {
            this->set_selection_area(this->sel_col1, this->sel_row1,
                                     (long)pick_info.x, (long)pick_info.y);
        }
    } else if (this->scroll_action == 4) {
        if (this->player->selected_obj != 0 &&
            this->pick(0x28, 0, param_1, param_2, &pick_info, 0) == 0x33) {
            this->player->selected_obj->teleport(pick_info.x, pick_info.y, 0);
            RGE_Static_Object* pRVar6 = this->player->selected_obj;
            unsigned char level;
            if (pRVar6->sprite_list != 0) {
                level = pRVar6->sprite_list->get_lowest_draw_level();
            } else if (pRVar6->sprite != 0) {
                level = pRVar6->sprite->get_lowest_draw_level();
            } else {
                level = 0x14;
            }
            if (level == 0) {
                this->set_redraw((TPanel::RedrawMode)2);
            } else {
        this->set_redraw((TPanel::RedrawMode)1);
            }
        }
    } else if (this->scroll_action == 9) {
        this->do_paint(point_x, lVar12, param_1, param_2, 2);
        this->set_redraw((TPanel::RedrawMode)1);
    }

    if (save_view_x != this->player->view_x || save_view_y != this->player->view_y) {
        this->set_redraw((TPanel::RedrawMode)1);
        return 1;
    }
    return 0;
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
        this->set_redraw((TPanel::RedrawMode)1);
        break;

    case 1:
    case 6:
    case 7:
    case 8: {
        tagPOINT pt;
        pt.x = this->mouse_down_x;
        pt.y = this->mouse_down_y;
        ClientToScreen(this->render_area->Wnd, &pt);
        SetCursorPos(pt.x, pt.y);
        break;
    }

    case 9:
        this->do_paint(this->mouse_down_x, this->mouse_down_y, this->mouse_down_x, this->mouse_down_y, 0);
        this->set_redraw((TPanel::RedrawMode)1);
        break;

    case 3:
    case 4:
    case 5:
        break;
    }

    if (this->scroll_action == 1 || this->scroll_action == 2
        || this->scroll_action == 6 || this->scroll_action == 7
        || this->scroll_action == 8)
    {
        rge_base_game->mouse_on();
    }

    this->release_mouse();
    this->scroll_action = 0;
}



int RGE_View::do_paint(long param_1, long param_2, long param_3, long param_4, int param_5)
{
    RGE_Pick_Info pick_info;
    long new_col;
    long new_row;
    int mode;
    short brush;

    if (this->pick(0x28, 0, param_3, param_4, &pick_info, 0) != 0x33) {
        return 0;
    }

    new_col = (long)pick_info.x;
    new_row = (long)pick_info.y;
    this->pick(0x28, 0, param_1, param_2, &pick_info, 0);

    mode = rge_base_game->game_mode;
    brush = rge_base_game->brush_size;
    switch (mode) {
    case 9:
        if (param_5 != 0 && rge_base_game->terrain_id != -1) {
            this->map->do_terrain_brush_stroke(
                this->real_old_map_col, this->real_old_map_row,
                new_col, new_row, brush,
                (unsigned char)rge_base_game->terrain_id);
        }
        break;
    case 10:
        if (param_5 != 0 && rge_base_game->elevation_height != -1) {
            this->map->do_elevation_brush_stroke(
                this->real_old_map_col, this->real_old_map_row,
                new_col, new_row, brush,
                (unsigned char)rge_base_game->elevation_height);
        }
        break;
    case 0x13:
        if (rge_base_game->sub_game_mode == 1) {
            this->map->do_cliff_brush_stroke(
                this->real_old_map_col, this->real_old_map_row,
                new_col, new_row, 0, 1);
        } else {
            this->map->do_cliff_brush_stroke(
                this->real_old_map_col, this->real_old_map_row,
                new_col, new_row, 0, 0);
        }
        this->redraw(2);
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


void RGE_View::add_overlay_sprite(TShape* shape, int facet, int world_x, int world_y, int flags, int draw_level, unsigned char* color_table, int displayfunction, unsigned long draw_time_interval) {
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
        sprite->theShape = shape;
        sprite->thefacet = facet;
        sprite->world_x = world_x;
        sprite->world_y = world_y;
        sprite->flags = flags;
        sprite->drawLevel = draw_level;
        sprite->colortable = color_table;
        sprite->displayfunction = displayfunction;
        sprite->DrawTimeInterval = draw_time_interval;
        sprite->LastDrawTime = 0;
    }
}


bool RGE_View::Object_Was_Displayed(int id, bool allow_flagged) {
    DClipInfo_Node* node;

    node = prior_objs->LocateIDbyDrawLevel(id, 6, 0x28, 0);
    if (node == 0) {
        return false;
    }
    if (!allow_flagged && (node->Draw_Flag & 1) != 0) {
        return false;
    }
    return true;
}

DClipInfo_List::DClipInfo_List(int init_zone_size, int default_grow_size,
                               int element_size, int ymin, int ymax,
                               int max_draw_levels) {
    int yline_offset;
    int yline_size;

    Free_Pool_Zone = -1;
    Free_Pool_Index = -1;
    Default_Grow_Size = default_grow_size;
    Element_Size = element_size;
    yline_offset = -ymin;
    yline_size = (ymax - ymin) + 1;
    Zone_Ptrs = 0;
    Zone_Size_Ptrs = 0;
    Max_Zones = 8;
    Used_Zones = 0;
    Free_Head = 0;
    Total_Blocks = 0;
    Free_Blocks = 0;
    YLine_Offset = yline_offset;
    YLine_Size = yline_size;
    Max_Draw_Levels = max_draw_levels;
    SetCaptureLevel(0, max_draw_levels);
    Draw_Clip_Nodes = (DClipInfo_Node**)calloc(YLine_Size,
                                                sizeof(DClipInfo_Node*));
    Draw_Level_Head = (DClipInfo_Node**)calloc(Max_Draw_Levels + 1,
                                                sizeof(DClipInfo_Node*));
    Draw_Level_Tail = (DClipInfo_Node**)calloc(Max_Draw_Levels + 1,
                                                sizeof(DClipInfo_Node*));
    ResetStats();
    SetNumZones(8);
    InitNewZone(init_zone_size);
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


void DClipInfo_List::SetCaptureLevel(int min_level, int max_level) {
    int temp;

    if (min_level > max_level) {
        temp = min_level;
        min_level = max_level;
        max_level = temp;
    }
    if (min_level < 0) {
        min_level = 0;
    }
    if (max_level > Max_Draw_Levels) {
        max_level = Max_Draw_Levels;
    }
    Accept_Min_Level = min_level;
    Accept_Max_Level = max_level;
}
void DClipInfo_List::SetNumZones(int num_zones) {
    DClipInfo_Node** new_zone_ptrs;
    int* new_zone_sizes;
    int i;

    if (num_zones >= Max_Zones) {
        new_zone_ptrs = (DClipInfo_Node**)calloc(num_zones, 4);
        new_zone_sizes = (int*)calloc(num_zones, sizeof(int));
        if (Zone_Ptrs != 0) {
            i = 0;
            if (Used_Zones > 0) {
                do {
                    new_zone_ptrs[i] = Zone_Ptrs[i];
                    new_zone_sizes[i] = Zone_Size_Ptrs[i];
                    i = i + 1;
                } while (i < Used_Zones);
            }
            free(Zone_Ptrs);
            free(Zone_Size_Ptrs);
        }
        Zone_Ptrs = new_zone_ptrs;
        Zone_Size_Ptrs = new_zone_sizes;
        Max_Zones = num_zones;
    }
}
void DClipInfo_List::InitNewZone(int zone_size) {
    int zone_index;
    unsigned int alloc_size;

    if (Used_Zones == Max_Zones) {
        SetNumZones(Used_Zones + 4);
    }
    zone_index = Used_Zones;
    Used_Zones = zone_index + 1;
    alloc_size = Element_Size * zone_size;
    Zone_Size_Ptrs[zone_index] = zone_size;
    Zone_Ptrs[zone_index] = (DClipInfo_Node*)malloc(alloc_size);
    NewZone_Count = NewZone_Count + 1;
    Total_Blocks = Total_Blocks + zone_size;
    Free_Blocks = Free_Blocks + zone_size;
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


void DClipInfo_List::SetDrawRegion(int xmin, int ymin, int xmax, int ymax) {
    if (xmin <= xmax) {
        if (ymin <= ymax) {
            SD_XMin = xmin;
            SD_XMax = xmax;
            SD_YMin = ymin;
            SD_YMax = ymax;
        }
    }
}



void DClipInfo_List::AddDrawNode(void* shape_base, Shape_Info* shape, int yline, int draw_x, int draw_y,
                                 int draw_flag, unsigned char* color_table, int xform_mask,
                                 int draw_level, int object_id)
{
    int yline_tmp = this->YLine_Offset + yline;

    if (draw_level > this->Accept_Max_Level)
        return;
    if (draw_level < this->Accept_Min_Level)
        return;

    Shape_Info* shp = shape;
    int right;
    int bottom;
    int hot_x;
    int hot_y;
    right = draw_x + shp->Width - 1;
    bottom = draw_y + shp->Height - 1;
    hot_x = draw_x + shp->Hotspot_X;
    hot_y = draw_y + shp->Hotspot_Y;

    if (!(draw_x <= this->SD_XMax && right >= this->SD_XMin &&
          draw_y <= this->SD_YMax && bottom >= this->SD_YMin &&
          yline_tmp >= 0 && yline_tmp < this->YLine_Size))
        return;

    DClipInfo_Node* node = this->GetNode();
    DClipInfo_Node** list = this->Draw_Clip_Nodes + yline_tmp;
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
    node->Object_ID = object_id;
    node->Draw_Flag = draw_flag;
    node->Shape_Base = (unsigned char*)shape_base;
    node->Color_Table = color_table;
    node->Xform_Mask = xform_mask;
    node->Shape = shp;
    node->Draw_X = draw_x;
    node->Draw_Y = draw_y;
    node->Draw_Level = draw_level;
    node->Node_Type = 0;

    if (this->Select_Box != 0) {
        node->x1 = (short)(hot_x + this->Select_Box[0]);
        node->y1 = (short)(this->Select_Box[1] + hot_y);
        node->x2 = (short)(this->Select_Box[2] + hot_x);
        node->y2 = (short)(this->Select_Box[3] + hot_y);
        this->Select_Box = 0;
    } else {
        node->x1 = (short)draw_x;
        node->y1 = (short)draw_y;
        node->x2 = (short)(draw_x + shp->Width - 1);
        node->y2 = (short)(draw_y + shp->Height - 1);
    }

    node->x3 = (short)hot_x;
    node->y3 = (short)hot_y;
    node->x4 = 0;
    node->y4 = 0;
}



DClipInfo_Node* DClipInfo_List::AddGDINode(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10, int param_11, int param_12, int param_13)
{
    int iVar2 = YLine_Offset + param_2;

    if (param_11 > Accept_Max_Level || param_11 < Accept_Min_Level || iVar2 < 0 || iVar2 >= YLine_Size)
        return 0;

    DClipInfo_Node* node = GetNode();
    node->Next = Draw_Clip_Nodes[iVar2];
    Draw_Clip_Nodes[iVar2] = node;

    node->Object_ID = param_13;
    node->Draw_Flag = param_12;
    node->Node_Type = param_1;
    node->x1 = param_3;
    node->y1 = param_4;
    node->x2 = param_5;
    node->y2 = param_6;
    node->x3 = param_7;
    node->y3 = param_8;
    node->NextOnLevel = 0;
    node->Shape = 0;
    node->Draw_X = 0;
    node->Draw_Y = 0;
    node->Shape_Base = 0;
    node->Color_Table = 0;
    node->Xform_Mask = 0;
    node->Draw_Level = param_11;
    node->x4 = param_9;
    node->y4 = param_10;

    return node;
}



DClipInfo_Node* DClipInfo_List::LocateIDbyDrawLevel(int object_id, int level_a, int level_b, int node_type)
{
    if (level_a > level_b) {
        int temp = level_a;
        level_a = level_b;
        level_b = temp;
    }

    if (level_a < 0) {
        level_a = 0;
    }

    int max_levels = this->Max_Draw_Levels;
    if (level_b > max_levels) {
        level_b = max_levels;
    }

    if (level_a <= max_levels && level_b >= 0 && level_a <= level_b) {
        DClipInfo_Node** head_ptr = this->Draw_Level_Head + level_a;
        int level = level_a;
        do {
            DClipInfo_Node* node = *head_ptr;
            while (node) {
                if (node->Object_ID == object_id && node->Node_Type == node_type) {
                    return node;
                }
                node = node->NextOnLevel;
            }
            level++;
            head_ptr++;
        } while (level <= level_b);
    }

    return 0;
}




void DClipInfo_List::Scroll(int scroll_x, int scroll_y)
{
    if (scroll_y > 0) {
        int i = 0;
        if (this->YLine_Size - scroll_y > 0) {
            do {
                int next = i + 1;
                this->Draw_Clip_Nodes[i] = this->Draw_Clip_Nodes[i + scroll_y];
                i = next;
            } while (i < this->YLine_Size - scroll_y);
        }

        i = this->YLine_Size - scroll_y;
        if (i < this->YLine_Size) {
            do {
                int next = i + 1;
                this->Draw_Clip_Nodes[i] = 0;
                i = next;
            } while (i < this->YLine_Size);
        }
    }

    if (scroll_y < 0) {
        int neg = -scroll_y;
        int i = this->YLine_Size - 1;
        int source = this->YLine_Size - 1 + scroll_y;

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
                    node->Draw_X -= scroll_x;
                    node->Draw_Y -= scroll_y;
                    break;

                case 1:
                    node->y3 -= (short)scroll_y;
                    node->y4 -= (short)scroll_y;

                case 2:
                    node->x3 -= (short)scroll_x;
                    node->x4 -= (short)scroll_x;

                case 3:
                case 4:
                    node->x1 -= (short)scroll_x;
                    node->y1 -= (short)scroll_y;
                    node->x2 -= (short)scroll_x;
                    node->y2 -= (short)scroll_y;
                    break;
                }

                node = node->Next;
            }

            i = i + 1;
        } while (i < this->YLine_Size);
    }
}


void DClipInfo_List::FreeNode(DClipInfo_Node* node) {
    node->Next = Free_Head;
    Free_Head = node;
    Free_Blocks = Free_Blocks + 1;
}

int DClipInfo_List::FreeThread(DClipInfo_Node* head, DClipInfo_Node* tail) {
    int count = 0;
    DClipInfo_Node* cur = head;
    if (head == 0) return 0;
    if (tail == 0) {
        do {
            tail = cur;
            ++this->Free_Blocks;
            ++count;
            cur = cur->Next;
        } while (cur != 0);
    } else {
        do {
            ++this->Free_Blocks;
            ++count;
            if (cur != tail) cur = cur->Next;
            else cur = 0;
        } while (cur != 0);
    }
    tail->Next = this->Free_Head;
    this->Free_Head = head;
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
