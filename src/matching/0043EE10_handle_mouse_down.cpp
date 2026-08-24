// first pass: dialog hit-test on slot +0xBC, then help-button action on slot +0xB4, otherwise fall through to the base helper
// using the real THelpDialog slot order is the key; the remaining risk is only the forwarding call shape
#ifdef DLG_HELP_SHARED_CONTEXT
#include "../../include/dlg_help_context.h"
#else
class TPanel {};
class TButtonPanel : public TPanel {};
class TDrawArea;
class THelpDialog;

typedef unsigned char uchar;

class THelpDialog {
public:
    virtual ~THelpDialog();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7);
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    virtual void set_rect(struct tagRECT param_1);
    virtual void set_color(uchar param_1);
    virtual void set_active(int param_1);
    virtual void set_positioning(int param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13);
    virtual void set_fixed_position(long param_1, long param_2, long param_3, long param_4);
    virtual void set_redraw(int param_1);
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, int param_3);
    virtual void draw_setup(int param_1);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(struct tagRECT* param_1);
    virtual void draw_offset(long param_1, long param_2, struct tagRECT* param_3);
    virtual void draw_rect2(struct tagRECT* param_1);
    virtual void draw_offset2(long param_1, long param_2, struct tagRECT* param_3);
    virtual void paint();
    virtual long wnd_proc(void* param_1, unsigned int param_2, unsigned int param_3, long param_4);
    virtual long handle_idle();
    virtual long handle_size(long param_1, long param_2);
    virtual long handle_paint();
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long handle_char(long param_1, short param_2);
    virtual long handle_command(unsigned int param_1, long param_2);
    virtual long handle_user_command(unsigned int param_1, long param_2);
    virtual long handle_timer_command(unsigned int param_1, long param_2);
    virtual long handle_scroll(long param_1, long param_2);
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4);
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long mouse_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4);
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long char_action(long param_1, short param_2);
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    virtual void get_true_render_rect(struct tagRECT* param_1);
    virtual int is_inside(long param_1, long param_2);

    char pad_000[0x598];
    TButtonPanel* ok_button;
    TButtonPanel* encyclopedia_button;
};

class TEasy_Panel {
public:
    long handle_mouse_down(uchar button, long x, long y, int flags, int area);
};
#endif

long THelpDialog::handle_mouse_down(uchar button, long x, long y, int flags, int area) {
    if (this->is_inside(x, y) == 0) {
        this->action(this->ok_button, 1, 0, 0);
        return 1;
    }

    return ((TEasy_Panel*)this)->TEasy_Panel::handle_mouse_down(button, x, y, flags, area);
}
