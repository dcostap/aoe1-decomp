// 00533510 RGE_View::RGE_View
// Attempt log:
// initial constructor source from packet/decompiler; using /GX because original has EH registration.

extern "C" void* __cdecl calloc(unsigned int, unsigned int);

#ifndef RGE_VIEW_SHARED_CONTEXT
class TPanel { public: TPanel(); virtual ~TPanel(); };

class RGE_View : public TPanel {
public:
    char pad_004[0x0F4 - 4];
    void* cur_render_area;      // f4
    int calc_draw_count;        // f8
    void* world;                // fc
    void* player;               // 100
    void* map;                  // 104
    short tile_wid;             //108
    short tile_hgt;             //10a
    short tile_half_wid;        //10c
    short tile_half_hgt;        //10e
    short elev_hgt;             //110
    char pad_112[4];
    short max_col_num;          //116
    short max_row_num;          //118
    short center_scr_col;       //11a
    short center_scr_row;       //11c
    short center_scr_col_offset;//11e
    short center_scr_row_offset;//120
    short center_map_col;       //122
    short center_map_row;       //124
    short start_scr_col;        //126
    short start_scr_row;        //128
    short start_map_col;        //12a
    short start_map_row;        //12c
    char pad_12e[2];
    int map_scr_x_offset;       //130
    int map_scr_y_offset;       //134
    int last_view_x;            //138
    int last_view_y;            //13c
    unsigned char function_mode;//140
    unsigned char function_parm;//141
    unsigned char render_terrain_mode;//142
    char pad_143[0x154-0x143];
    short save_paint_terrain;   //154
    char pad_156[2];
    void* white_pen;            //158
    void* red_pen;              //15c
    void* hollow_brush;         //160
    void* border_line_shape;    //164
    unsigned char scroll_action;//168
    char pad_169[3];
    int mouse_last_x;           //16c
    int mouse_last_y;           //170
    void* movable_object;       //174
    void* Terrain_Clip_Mask;    //178
    void* Terrain_Fog_Clip_Mask;//17c
    void* Master_Clip_Mask;     //180
    void* Tile_Edge_Tables;     //184
    void* Black_Edge_Tables;    //188
    char pad_18c[0x2C8-0x18c];
    void* Float_Scroll_Offsets; //2c8
    int Float_Scroll_Offsets_Sz;//2cc
    int Float_X_Delta;          //2d0
    int Float_Y_Delta;          //2d4
    int Queued_Blits;           //2d8
    void* Blit_Queue;           //2dc
    int Blit_Queue_Size;        //2e0
    char pad_2e4[4];
    int Current_Blit;           //2e8
    int Blit_Offset_X;          //2ec
    int Blit_Offset_Y;          //2f0
    char pad_2f4[8];
    int pick_list_count[5];     //2fc
    int pick_list_size[5];      //310
    int save_area1;             //324
    void* LastRenderBits;       //328
    void* RenderOffsets;        //32c
    int LastRenderSize;         //330
    void* prior_objs;           //334
    void* futur_objs;           //338
    int UC_ObjectTouched;       //33c
    int UC_TouchedObj;          //340
    int UC_StartTime;           //344
    int UC_ElapsedTime;         //348
    void* message_panel;        //34c
    void* extra_sprites;        //350
    void* DispSel_List;         //354
    int DispSel_List_Size;      //358
    int DispSel_List_Max;       //35c

    RGE_View();
    void set_selection_area(int,int,int,int);
};
#endif

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
    this->last_view_x = 0xC61C3C00;
    this->last_view_y = 0xC61C3C00;
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
        this->pick_list_count[i] = 0;
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
#ifdef RGE_VIEW_SHARED_CONTEXT
    this->DispSel_List_void = calloc(8, 0x14);
#else
    this->DispSel_List = calloc(8, 0x14);
#endif
}
