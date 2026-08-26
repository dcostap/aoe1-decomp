typedef unsigned char uchar;
typedef unsigned long ulong;
typedef int PositionMode;
typedef int RedrawMode;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long,
                                  long, long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
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
    virtual long handle_mouse_down(uchar, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual long handle_mouse_dbl_click(uchar, long, long, int, int);
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
    virtual long action(TPanel*, long, ulong, ulong);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int focus);
};

extern unsigned long debug_timeGetTime(char* file, int line);

class TInputPanel : public TPanel {
public:
    char gap_04[0x74];
    int have_focus;
    char gap_7C[0x114];
    unsigned long caret_last_time;
    int draw_caret;

    void set_focus(int focus);
};

void TInputPanel::set_focus(int focus) {
    TPanel::set_focus(focus);
    if (have_focus != 0) {
        draw_caret = 1;
        caret_last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 0x89);
    }
}
