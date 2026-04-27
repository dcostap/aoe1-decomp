// attempt 1: mirror the close 0043EE10 dialog shape with the quick-message member at +0x490
// target shape: hit-test via slot +0xBC, button action via slot +0xB4, otherwise forward to TEasy_Panel::handle_mouse_down

typedef unsigned char uchar;

class TPanel {};
class TButtonPanel : public TPanel {};
class TTextPanel;
class TEditPanel;

class TEasy_Panel {
public:
    virtual long handle_mouse_down(uchar button, long x, long y, int flags, int area);
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();
    virtual long setup(void* a, TPanel* b, long c, long d, long e, long f, uchar g);
    virtual void set_rect(long a, long b, long c, long d);
    virtual void set_rect(struct tagRECT a);
    virtual void set_color(uchar a);
    virtual void set_active(int a);
    virtual void set_positioning(int a, long b, long c, long d, long e, long f, long g, long h, long i, TPanel* j, TPanel* k, TPanel* l, TPanel* m);
    virtual void set_fixed_position(long a, long b, long c, long d);
    virtual void set_redraw(int a);
    virtual void set_overlapped_redraw(TPanel* a, TPanel* b, int c);
    virtual void draw_setup(int a);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(struct tagRECT* a);
    virtual void draw_offset(long a, long b, struct tagRECT* c);
    virtual void draw_rect2(struct tagRECT* a);
    virtual void draw_offset2(long a, long b, struct tagRECT* c);
    virtual void paint();
    virtual long wnd_proc(void* a, unsigned int b, unsigned int c, long d);
    virtual long handle_idle();
    virtual long handle_size(long a, long b);
    virtual long handle_paint();
    virtual long handle_key_down(long a, short b, int c, int d, int e);
    virtual long handle_char(long a, short b);
    virtual long handle_command(unsigned int a, long b);
    virtual long handle_user_command(unsigned int a, long b);
    virtual long handle_timer_command(unsigned int a, long b);
    virtual long handle_scroll(long a, long b);
    virtual long handle_mouse_down(uchar a, long b, long c, int d, int e);
    virtual long handle_mouse_move(long a, long b, int c, int d);
    virtual long handle_mouse_up(uchar a, long b, long c, int d, int e);
    virtual long handle_mouse_dbl_click(uchar a, long b, long c, int d, int e);
    virtual long mouse_move_action(long a, long b, int c, int d);
    virtual long mouse_left_down_action(long a, long b, int c, int d);
    virtual long mouse_left_hold_action(long a, long b, int c, int d);
    virtual long mouse_left_move_action(long a, long b, int c, int d);
    virtual long mouse_left_up_action(long a, long b, int c, int d);
    virtual long mouse_left_dbl_click_action(long a, long b, int c, int d);
    virtual long mouse_right_down_action(long a, long b, int c, int d);
    virtual long mouse_right_hold_action(long a, long b, int c, int d);
    virtual long mouse_right_move_action(long a, long b, int c, int d);
    virtual long mouse_right_up_action(long a, long b, int c, int d);
    virtual long mouse_right_dbl_click_action(long a, long b, int c, int d);
    virtual long key_down_action(long a, short b, int c, int d, int e);
    virtual long char_action(long a, short b);
    virtual long action(TPanel* a, long b, unsigned long c, unsigned long d);
    virtual void get_true_render_rect(struct tagRECT* a);
    virtual int is_inside(long a, long b);
};

class TribeSendQuickMessageDialog : public TDialogPanel {
public:
    char pad_000[0x48C];
    TEditPanel* chatInput;
    TTextPanel* chatTitle;
    long modeValue;

    long handle_mouse_down(uchar button, long x, long y, int flags, int area);
};

long TribeSendQuickMessageDialog::handle_mouse_down(uchar button, long x, long y, int flags, int area) {
    if (this->is_inside(x, y) == 0) {
        this->action((TPanel*)this->chatInput, 1, 0, 0);
        return 1;
    }

    return TEasy_Panel::handle_mouse_down(button, x, y, flags, area);
}
