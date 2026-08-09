// 00438060 RGE_Diamond_Map::draw_object (diam_map.cpp:1118-1186)
// Attempt log (sa-d55a5d35-draw_object, bounded 10-probe pass):
// - Reconstructed full typed TPanel/RGE_Diamond_Map, RGE_Map_Tile_Row and FillRect surfaces;
//   baseline reached exact size/call set with 14 differing bytes.
// - Corrected the max-coordinate predicate from the oracle cmp/jge and reversed the FPU arm
//   spelling so VC5 emits the binary je threshold layout; best output is 10 differing bytes.
// - Tried typed row-index/final-pointer orderings, pointer post-decrement, and a one-record-
//   before-base expression. VC5 stayed in the same 10-byte row-index basin; no opaque form kept.
// - Paused with ordinary `map_tile_rows + row_index - 1`; all calls/relocations, marker branches,
//   FPU math, and FillRect sites align. Remaining drift is the first row LEA's -24 displacement.

extern float DAT_0056f604;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    void* DrawSystem;
    void* Wnd;
    unsigned char* Bits;
    void* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    int Width;
    int Height;
    int Pitch;
    int Orien;
    tagRECT ClipRect;
    void* DrawDc;
    void* DrawSurface;
    char SurfaceDesc[0x6C];
    void* Node;
    char* Name;
    unsigned char* LastBits;
    int LastPitch;
    void** DisplayOffsets;
    void** CurDisplayOffsets;
    void** FloatOffsets;
    void* shadow_color_table;
    void* SpanList;
    void* CurSpanList;
    int Float_X_Delta;
    int Float_Y_Delta;
    int DisplayOffsetsSz;
    int FloatOffsetsSz;
    int SystemMemOnly;
    int UsingVidMem;
    int UseTrans;
    int IsPrimarySurface;
    int Restored;
    int ExtendedLines;
    unsigned char TransColor;
    unsigned char gap_FD[3];

    void FillRect(long x1, long y1, long x2, long y2, unsigned char color);
};

class TPanel {
public:
    virtual ~TPanel();

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    tagRECT clip_rect;
    char gap_34[0xB8];
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;
};

struct RGE_Map_Image_Line {
    short tile_row;
    short start_x;
    short line_len;
};

struct RGE_Map_Tile_Row {
    short image_line;
    unsigned char draw;
    unsigned char pad_03;
    short row_len;
    unsigned char pad_06[2];
    float col_step;
    float col_extra;
    short map_col;
    short map_row;
    short draw_wid;
    unsigned char pad_16[2];
    float draw_step;
    short num_tiles;
    unsigned char pad_1E[2];
    float ratio;
};

class RGE_Diamond_Map : public TPanel {
public:
    void draw_object(short param_1, short param_2, unsigned char param_3,
                     short param_4, void* param_5);

    void* world;
    void* player;
    void* map;
    int all_visible;
    int render_all;
    long mouse_last_x;
    long mouse_last_y;
    int repos_mouse;
    tagRECT view_rect;
    void* last_player;
    RGE_Map_Image_Line* map_image_lines;
    RGE_Map_Tile_Row* map_tile_rows;
    short map_wid;
    short map_hgt;
    short map_image_start_y;
    short map_image_wid;
    short map_image_hgt;
    short map_tile_row_cnt;
    float map_row_step;
    float map_col_ratio;
    float map_row_ratio;
    short map_tile_draw_hgt;
    short map_tile_draw_wid;
    short view_col;
    short view_row;
    void* main_view;
    int scrolling;
    unsigned char fog_color;
    unsigned char pad_159[3];
    int draw_objects_mode;
    unsigned long cur_player_bit;
    int own_save_area;
    TDrawArea* save_area;
};

void RGE_Diamond_Map::draw_object(short param_1, short param_2,
                                  unsigned char param_3, short param_4,
                                  void* param_5)
{
    short max_coord = param_2;
    int row_index = (int)this->map_wid + (int)param_2 - (int)param_1;
    RGE_Map_Tile_Row* row = this->map_tile_rows + row_index - 1;

    if (param_1 < param_2)
        max_coord = param_1;

    short x_offset;
    if (row->ratio < DAT_0056f604) {
        x_offset = (short)((float)max_coord * row->ratio);
    } else {
        x_offset = (short)((float)max_coord * row->draw_step);
    }

    short image_line = row->image_line;
    short x = this->map_image_lines[image_line].start_x;
    x = x + (short)this->pnl_x + x_offset;

    short y = (short)this->pnl_y + this->map_image_start_y + image_line;

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
    }
}
