// 00436830 RGE_Diamond_Map::RGE_Diamond_Map (diam_map.cpp:40-76)
// Attempt 3: give TPanel a non-inline constructor so VC5 emits the base ctor call

typedef struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
} RECT;

class TPanel {
public:
    virtual ~TPanel() {}
    TPanel();                     // non-inline definition follows
    char _pad[0xF0];
};

class RGE_Diamond_Map : public TPanel {
public:
    virtual ~RGE_Diamond_Map() {}
    RGE_Diamond_Map();

    void* world;                // +0xF4
    void* player;               // +0xF8
    void* map;                  // +0xFC
    int all_visible;            // +0x100
    int render_all;             // +0x104
    long mouse_last_x;          // +0x108
    long mouse_last_y;          // +0x10C
    int repos_mouse;            // +0x110
    RECT view_rect;             // +0x114
    void* last_player;          // +0x124
    void* map_image_lines;      // +0x128
    void* map_tile_rows;        // +0x12C
    short map_wid;              // +0x130
    short map_hgt;              // +0x132
    short map_image_start_y;    // +0x134
    short map_image_wid;        // +0x136
    short map_image_hgt;        // +0x138
    short map_tile_row_cnt;     // +0x13A
    float map_row_step;         // +0x13C
    float map_col_ratio;        // +0x140
    float map_row_ratio;        // +0x144
    short map_tile_draw_hgt;    // +0x148
    short map_tile_draw_wid;    // +0x14A
    short view_col;             // +0x14C
    short view_row;             // +0x14E
    void* main_view;            // +0x150
    int scrolling;              // +0x154
    unsigned char fog_color;    // +0x158
    char pad_159[3];            // +0x159
    int draw_objects_mode;      // +0x15C
    unsigned long cur_player_bit; // +0x160
    int own_save_area;          // +0x164
    void* save_area;            // +0x168
};

RGE_Diamond_Map::RGE_Diamond_Map()
{
    world = (void*)0;
    player = (void*)0;
    map = (void*)0;
    repos_mouse = 0;
    last_player = (void*)0;
    map_image_start_y = 0;
    map_image_lines = (void*)0;
    map_tile_rows = (void*)0;
    map_image_wid = 0;
    map_image_hgt = 0;
    map_tile_row_cnt = 0;
    map_row_step = 0.0f;
    map_tile_draw_hgt = 0;
    map_tile_draw_wid = 0;
    map_col_ratio = 0.0f;
    map_row_ratio = 0.0f;
    save_area = (void*)0;
    own_save_area = 0;

    view_col = -1;
    view_row = -1;
    render_all = 1;
    fog_color = 0xFF;

    view_rect.left = 0;
    view_rect.top = 0;
    view_rect.right = 0;
    view_rect.bottom = 0;
    main_view = (void*)0;
    scrolling = 0;
    draw_objects_mode = 0;
    cur_player_bit = 0;
}

TPanel::TPanel()
{
}
