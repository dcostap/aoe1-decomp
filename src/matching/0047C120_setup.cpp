// VA: 0047C120 TTextPanel::setup
// Pnl_txt.cpp:102-120
// Retry 2026-05-24: replace stale stub with packet-derived TTextPanel setup.

#ifndef PNL_TXT_TU_CONTEXT
struct tagRECT;
class TDrawArea;
class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
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
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    virtual void set_text(char**, short);
    virtual void set_text(long);
    virtual void set_text(char* text); // +0xE8
    long setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h, int zero);
};

class TTextPanel : public TPanel {
public:
    char gap_004[0x134];
    short fixed_len;           // +0x138
    char gap_13A[0x12];
    int fill_back;             // +0x14C
    unsigned char back_color;  // +0x150
    char gap_151[0x03];
    int outline;               // +0x154
    unsigned char outline_color; // +0x158
    char gap_159[0x17];
    int bevel_type;            // +0x170

    void set_font(void* font, long p2, long p3);
    enum Alignment {
        AlignCenter = 0,
        AlignLeft = 1,
        AlignRight = 2,
        AlignTop = 3,
        AlignBottom = 4,
        AlignHorizontalScroll = 5,
        AlignWordwrap = 6
    };
    void set_alignment(Alignment h, Alignment v);
    void set_back_pic(char* pic);

    long setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h,
               void* font, long font_arg2, long font_arg3, char* back_pic,
               int fill, unsigned char backColor, int outline, unsigned char outlineColor,
               short fixedLen, char* text);
};
#endif

long TTextPanel::setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h,
                       void* font, long font_arg2, long font_arg3, char* back_pic,
                       int fill, unsigned char backColor, int outlineValue, unsigned char outlineColor,
                       short fixedLenValue, char* text)
{
    TPanel::setup(draw, parent, x, y, w, h, 0);
    fill_back = fill;
    back_color = (unsigned char)backColor;
    outline = outlineValue;
    outline_color = outlineColor;
    fixed_len = fixedLenValue;
    if (outlineValue != 0) {
        bevel_type = 1;
    }
    set_text(text);
    set_font(font, font_arg2, font_arg3);
    set_alignment(AlignCenter, AlignCenter);
    set_back_pic(back_pic);
    return 1;
}
