#include "../../include/scr_stms_context.h"

// Attempt log:
// - The shared overloaded TTextPanel view emitted vslot +0xE0; the oracle
//   uses +0xE8.
// - The donor-backed declaration-only view reached +0xE4 with overloaded
//   names, then +0xEC with 57 placeholders and unique names.
// - The reduced 56-slot view with unique names emits the exact +0xE8 call.
// - Walkbacks proved both the unique names and the 56-slot count are needed.
// - Candidate scr_stms.cpp validation matches all five owners and its one
//   compiler-generated destructor.
// BINARY NOTE: scr_stms.cpp uses the Pnl_txt text surface.  Its long and
// char* overloads occupy +0xE4 and +0xE8.  The shared status context keeps a
// narrower declaration for the other constructor calls, so this local view
// preserves the proven call slot without changing shared ownership.
// This declaration-only view does not construct or own a text-panel object.
class Status_Text_Panel {
public:
    // TPanel owns these 56 slots in this beta.  Keep their reviewed names
    // while the local view supplies only the slots needed by this caller.
    virtual ~Status_Text_Panel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(long, long, long, long);
    virtual void set_rect(tagRECT);
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
    virtual void set_tab_order(TPanel**, short);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    // Pnl_txt.cpp declares this overload group as char*, long, char**;
    // VC5 places the group in reverse vtable order.
    virtual void set_text(char* text);
    virtual void set_text(long text_id);
    virtual void set_text(char** text, short id);
};

void TRIBE_Screen_Status_Message::set_text(char* param) {
    ((Status_Text_Panel*)this->member_478)->set_text(param);
}
