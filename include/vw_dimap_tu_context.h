#ifndef AOE1_VW_DIMAP_TU_CONTEXT_H
#define AOE1_VW_DIMAP_TU_CONTEXT_H

// Module context for the initial vw_dimap.cpp recovery pass.
// The shipped class hierarchy and the narrow per-function donor views do not
// yet provide one proven complete view layout. Keep this context conservative;
// affected owners remain observed until the shared ABI is reviewed.

typedef unsigned char uchar;

class RGE_Tile;
class RGE_Player {
public:
    void set_view_loc(float x, float y, float z);
    void unselect_object();
    unsigned char command_make_do(int mode, float x, float y);
    unsigned char command_make_move(int mode, float x, float y);
    unsigned char command_make_work(int mode, float x, float y);
};

class RGE_Prog_Info {
public:
    char gap_00[0x8DC];
    short interface_style;
};

class RGE_Base_Game {
public:
    char gap_00[0x0C];
    RGE_Prog_Info* prog_info;
    char gap_10[0x1A0];
    int prog_mode;
    int game_mode;

    int get_paused();
    void add_to_timing(int index, unsigned long value);
    void set_game_mode(int mode, int sub_mode);
};

class TPanel {
public:
    virtual ~TPanel();

    char gap_04[0xBC];
    int field_C0;
    char gap_C4[0x28];
    unsigned char field_EC;
    char gap_ED[7];

    long handle_mouse_down(unsigned char button, long x, long y, int ctrl,
                           int shift);
    void release_mouse();
};

class RGE_Diamond_Map : public TPanel {
public:
    virtual ~RGE_Diamond_Map();

    char gap_F4[4];
    RGE_Player* player;
    char gap_FC[0x58];
    int scrolling;

    int pick_tile(long x, long y, void* tile_x, void* tile_y, void* tile);
    void start_scroll_view(long x, long y);
    void handle_scroll_view(long x, long y);
    void end_scroll_view();
    void draw();
};

class RGE_Diamond_Map_View : public RGE_Diamond_Map {
public:
    RGE_Diamond_Map_View();

    long handle_mouse_down(unsigned char button, long x, long y, int ctrl,
                           int shift);
    long mouse_left_down_action(long x, long y, int key, int flags);
    long mouse_left_move_action(long x, long y, int key, int flags);
    long mouse_left_up_action(long x, long y, int key, int flags);
    long mouse_right_down_action(long x, long y, int key, int flags);
    long mouse_right_move_action(long x, long y, int key, int flags);
    long mouse_right_up_action(long x, long y, int key, int flags);
    void draw();

    virtual int command_make_do(long x, long y);
    virtual int command_make_move(long x, long y);
    virtual int command_make_work(long x, long y);

    int capture_mouse();
    int right_click2(long x, long y);
};

extern RGE_Base_Game* rge_base_game;
extern int allow_user_commands;
extern float FLOAT_005777e8;
extern unsigned long debug_timeGetTime(const char* file, int line);

#endif
