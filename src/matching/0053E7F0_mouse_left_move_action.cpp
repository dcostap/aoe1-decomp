// 0053E7F0 RGE_Main_View::mouse_left_move_action
// vw_main.cpp:636-675, 249 bytes, __thiscall, ret 10h
//
// Attempt log:
//   baseline: restored the period class/member surface and typed global from
//     the exact same-TU mouse-right handler; raw global indirection in the
//     prior scratch candidate was not the original source shape.
//   probe 2: C-linkage spelling of rge_base_game did not change codegen.
//   probe 3/4: narrow helper/vtable and parameter-width variants isolated the
//     register-pressure issue but were diagnostic-only and rolled back.
//   probe 5: the post-start handler reloads the original x/y parameter homes;
//     the decompiler's param_3/param_4 attribution ignored callee cleanup.
//   final: the complete inherited TPanel/RGE_View surface with that corrected
//     source call is exact under the default VC5 flags.

#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);

    char gap_04[0x1AC];
    int prog_mode;                         // +0x1B0
    int game_mode;                         // +0x1B4

    int get_paused();
};

extern RGE_Base_Game* rge_base_game;

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
    virtual void set_redraw(int);
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
    long mouse_down_x;                     // +0xC4
    long mouse_down_y;                     // +0xC8
    int mouse_down_ctrl;                   // +0xCC
    int mouse_down_shift;                  // +0xD0
    unsigned long mouse_down_time;         // +0xD4
    int error_code;                        // +0xD8
    int z_order;                           // +0xDC
    int display_changed_count;             // +0xE0
    long help_string_id;                   // +0xE4
    long help_page_id;                     // +0xE8
    unsigned char mouse_action;            // +0xEC
    unsigned char mouse_down_button;       // +0xED
    unsigned char panel_type;              // +0xEE
    unsigned char color;                   // +0xEF
    unsigned char fill_in_background;      // +0xF0
    unsigned char clip_to_parent;          // +0xF1
    unsigned char draw_rect2_flag;         // +0xF2
    unsigned char need_restore;            // +0xF3

    void release_mouse();
};

class RGE_View : public TPanel {
public:
    virtual int pick_through_fog(void*);
    virtual int pick_weight(void*, int);
    virtual int start_scroll_view(unsigned char, long, long, int, int);
    virtual int handle_scroll_view(long, long);
    virtual void end_scroll_view();
    virtual int do_paint(long, long, long, long, int);
    virtual void draw_multi_object_outline();

    char gap_F4[0x74];
    unsigned char scroll_action;            // +0x168
};

class RGE_Main_View : public RGE_View {
public:
    long mouse_left_move_action(long, long, int, int);
};
#endif

long RGE_Main_View::mouse_left_move_action(long param_1, long param_2,
                                           int param_3, int param_4) {
    int mode = rge_base_game->prog_mode;
    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        if (rge_base_game->get_paused()) {
            if (this->scroll_action) {
                this->end_scroll_view();
            } else {
                this->release_mouse();
            }
            return 0;
        }

        if (this->scroll_action) {
            this->handle_scroll_view(param_1, param_2);
            return 1;
        }

        switch (rge_base_game->game_mode) {
        case 0:
            this->release_mouse();
            this->start_scroll_view(2, this->mouse_down_x, this->mouse_down_y,
                                    param_3, param_4);
            // The five-argument start_scroll_view call cleans its own stack;
            // the following source call therefore uses the original x/y pair.
            this->handle_scroll_view(param_1, param_2);
            return 1;
        case 1:
        case 7:
        case 8:
            this->set_redraw(1);
            break;
        }
        return 1;
    }
    return 0;
}
