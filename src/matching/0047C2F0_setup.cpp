// VA: 0047C2F0 TTextPanel::setup
// PDB source: Pnl_txt.cpp

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
    long setup(TDrawArea* draw, TPanel* parent, long p3, long p4, long p5, long p6, int zero);
};

class TTextPanel : public TPanel {
public:
    char gap_04[0x134];
    short fixed_len;      // +138
    char gap_13a[0x12];
    int fill_back;         // +14c
    unsigned char back_color; // +150
    char gap_151[3];
    int outline;          // +154
    unsigned char outline_color; // +158
    char gap_159[0x17];
    int bevel_type;       // +170

    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4,
               long param_5, long param_6, void* param_7, long param_8,
               long param_9, char* param_10, int param_11, unsigned char param_12,
               int param_13, unsigned char param_14, short param_15,
               char** param_16, short param_17);
    void set_font(void* param_7, long param_8, long param_9);
    enum Alignment {
        AlignCenter = 0,
        AlignLeft = 1,
        AlignRight = 2,
        AlignTop = 3,
        AlignBottom = 4,
        AlignHorizontalScroll = 5,
        AlignWordwrap = 6
    };
    void set_alignment(Alignment a, Alignment b);
    void set_back_pic(char* p);
};
#endif

long TTextPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4,
                       long param_5, long param_6, void* param_7, long param_8,
                       long param_9, char* param_10, int param_11, unsigned char param_12,
                       int param_13, unsigned char param_14, short param_15,
                       char** param_16, short param_17)
{
    TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, 0);
    this->fill_back = param_11;
    this->back_color = param_12;
    this->outline = param_13;
    this->outline_color = param_14;
    this->fixed_len = param_15;
    if (param_13 != 0) {
        this->bevel_type = 1;
    }
    this->set_text(param_16, param_17);
    this->set_font(param_7, param_8, param_9);
    this->set_alignment(AlignTop, AlignLeft);
    this->set_back_pic(param_10);
    return 1;
}
