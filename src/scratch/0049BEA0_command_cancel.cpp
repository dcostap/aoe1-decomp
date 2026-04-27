// target: VA 0049BEA0 TRIBE_Screen_Game::command_cancel()
// first pass: preserve the early-return ladder and direct global/member call order
// probe 1: direct member-call spelling is still pulling the wrong layout basin for main_view/popup-help offsets
// blocker: the remaining drift is in local class surface/layout, not the branch structure

class TDrawArea;

class TPanel {
public:
    void* vtable_ptr;
    char gap_04[0x88];
    char render_rect[0x10];
};

class RGE_View : public TPanel {
public:
    TDrawArea* cur_render_area;
    int calc_draw_count;
    void* world;
    void* player;
    void* map;
    short tile_wid;
    short tile_hgt;
    short tile_half_wid;
    short tile_half_hgt;
    short elev_hgt;
    short render_rect_wid;
    short render_rect_hgt;
    short max_col_num;
    short max_row_num;
    short center_scr_col;
    short center_scr_row;
    short center_scr_col_offset;
    short center_scr_row_offset;
    short center_map_col;
    short center_map_row;
    short start_scr_col;
    short start_scr_row;
    short start_map_col;
    short start_map_row;
    char pad_12E[0x2];
    int map_scr_x_offset;
    int map_scr_y_offset;
    float last_view_x;
    float last_view_y;
    unsigned char function_mode;
    unsigned char function_parm;
    unsigned char render_terrain_mode;
    unsigned char pad_143;
    long sel_col1;
    long sel_row1;
    long sel_col2;
    long sel_row2;

    void set_selection_area(long left, long top, long right, long bottom);
};

class TRIBE_Main_View : public RGE_View {
public:
    void* vtable2;
};

class RGE_Base_Game {
public:
    int get_paused();
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04(int, int);
};

extern RGE_Base_Game* rge_base_game;

class TEasy_Panel : public TPanel {
public:
    char gap_08C[0xD0];
    unsigned char popup_help_flag; // +0x45C

    void clear_popup_help();
};

class TRIBE_Screen_Game : public TEasy_Panel {
public:
    char gap_45D[0x5B];
    TRIBE_Main_View* main_view; // +0x4B8

    void command_view_selected();
    void command_cancel();
};

void TRIBE_Screen_Game::command_cancel() {
    if (this->popup_help_flag) {
        this->clear_popup_help();
        return;
    }

    if (rge_base_game->get_paused()) {
        return;
    }

    if (((int*)rge_base_game)[0x1B4 / 4] == 0) {
        this->command_view_selected();
        return;
    }

    if (((int*)rge_base_game)[0x1B4 / 4] == 0x15) {
        ((void (*)(TRIBE_Main_View*))(*(void***)this->main_view)[60])(this->main_view);
        this->main_view->set_selection_area(-1, -1, -1, -1);
    }

    rge_base_game->vf04(0, 0);
}
