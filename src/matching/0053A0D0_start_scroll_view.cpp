// VA: 0053A0D0 RGE_View::start_scroll_view
// PDB: view.cpp:5854-5914
// Fresh reconstruction: the pick result is the period RGE_Pick_Info object;
// the view owns the mouse-down and scroll fields at their proven offsets.
// Prior worker notes remain useful evidence: the former volatile stub forced
// the right frame but did not reproduce the source-level register schedule.
//
// Attempt log (normal-53A0D0-r1):
// 1: natural typed Pick_Info and named view fields: 397 B, 16 calls, 4 fewer returns.
// 2: delayed result initialization: codegen duplicate.
// 3: reused the action parameter as the zero result: codegen duplicate.
// 4: volatile result restored four returns and reached 421 B; retained as diagnostic.
// 5: declaration-order change: codegen duplicate.
// 6: saved action local: codegen duplicate.
// 7: volatile action local: 425 B and worse block coverage; rolled back.
// 8: register-qualified action local: codegen duplicate; rolled back.
// 9: reused result for the first converted coordinate: 441 B, 335 strict diff.
// 10: reversed conversion order: 437 B, 338 strict diff; exact-codegen stage.
// Final: restored the clean natural source. Remaining lead is result-home and
// action-register scheduling. Diagnostic volatile forms are not retained.
// 11: use one saved action value for dispatch and scroll state; codegen was
// unchanged at 397 B / 418 strict-diff bytes, so the natural baseline remains.
// 12: direct final return instead of a synthetic result local; codegen was
// unchanged at 397 B / 418 strict-diff bytes, so the baseline was restored.
// 13: delayed result assignment remained a codegen duplicate.
// 14: volatile result plus saved action restored the target prologue, four
//     returns, and 437-byte size; result-home argument reload was one extra.
// 15: plain result removed that structure; rolled back.
// 16: hoisted col/row locals were a duplicate; rolled back.
// 17: plain col with volatile final result reached 421 B / 414 diff.
// 18: cached the volatile y conversion into plain col; reached 429 B / 66 diff.
// 19: a raw local read at +8 reached 437 B / 2 diff with exact calls,
//     returns, and all other bytes aligned. It has no proven field ownership.
// 20: named first view-y value was a codegen duplicate.
// 21: offset +4 collapsed the distinct late expression and regressed to 66.
// 22: alternate alias spelling also regressed to 66; restored the offset +8
//     diagnostic form as the best binary-supported reconstruction.
// 23: normalized the living source by removing codegen-only volatile/register
//     scheduling and the raw +8 read. Close scheduling evidence remains in
//     checkpoint probe-026.
// 24: restored the reviewed virtual ABI: start_scroll_view is vt[58], and the
//     full same-TU TPanel surface owns its fields through +0xF4. Body codegen
//     stayed in the natural 405-byte / 418-byte-diff basin.
// 25: a switch dispatch regressed ordered calls and was rolled back.
// 26: direct coordinate casts, delayed result assignment, a saved action local,
//     and positive success guards were codegen duplicates of the natural source.
// 27: model the return as a natural state result: declare it without an
//     initializer, assign zero after the action-specific branches, assign one
//     in the final success arm, and return it once. This gives an exact 437 B
//     MATCH with the canonical TPanel/RGE_View ABI and no codegen-only tricks.

struct RGE_Static_Object;
struct RGE_Tile;
struct RGE_Game_World;
struct RGE_Map;
struct TDrawArea;

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

class RGE_Player {
public:
    void unselect_object();
    void set_view_loc(float x, float y);
};

class RGE_Base_Game {
public:
    void mouse_off();
};

extern RGE_Base_Game* rge_base_game;
extern float flt_5776C0;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long,
                                  TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int mode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(void*);
    virtual void draw_offset(long, long, void*);
    virtual void draw_rect2(void*);
    virtual void draw_offset2(long, long, void*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(void*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char gap_04[0xC0];
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    int error_code;
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;

    int capture_mouse();
};

class RGE_View : public TPanel {
public:
    TDrawArea* cur_render_area;
    int calc_draw_count;
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    char gap_108[0x60];
    unsigned char scroll_action;
    char gap_169[3];
    long mouse_last_x;
    long mouse_last_y;
    char gap_174[0x180];
    long real_old_map_col;
    long real_old_map_row;

    virtual int pick_through_fog(RGE_Static_Object* obj);
    virtual int pick_weight(RGE_Static_Object* obj, int weight);
    virtual int start_scroll_view(unsigned char action, long x, long y, int p4, int p5);
    virtual int handle_scroll_view(long x, long y);
    virtual void end_scroll_view();
    virtual int do_paint(long x1, long y1, long x2, long y2, int flag);

    unsigned char pick(unsigned char key, unsigned char p2, long x, long y,
                       RGE_Pick_Info* info, RGE_Static_Object* obj);
    void set_selection_area(long x1, long y1, long x2, long y2);

};

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
        this->set_redraw(1);
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
        this->set_redraw(1);
    }

    if (this->scroll_action == 6 || this->scroll_action == 8) {
        if (this->pick(0x28, 0, x, y, &pick_info, 0) == 0x33) {
            this->player->set_view_loc(pick_info.x - flt_5776C0,
                                       pick_info.y - flt_5776C0);
            this->set_redraw(1);
            result = 1;
        }
    }

    return result;
}
