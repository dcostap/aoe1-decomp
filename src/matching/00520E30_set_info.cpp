// 00520E30 TRIBE_Panel_Text_Line::set_info
// Source: tpnl_txl.cpp lines 40-47
//
// Attempt log:
// Probe 1: strcmp/strcpy with __stdcall function ptr — 30.8% diff, register allocation off
// Probe 2: swapped operand order (type == text_type, strcmp(str, text)) — 20.1% diff, strcmp matches!
//   Remaining: vtable load timing and no ecx=this in set_redraw call
// Probe 3: declare set_redraw in TPanel and call as member function for thiscall codegen

#include "..\..\include\game_globals.h"
#include <string.h>

#ifdef TPNL_TXL_SHARED_CONTEXT
#include "..\..\include\tpnl_txl_context.h"
#else
class TDrawArea;

class TPanel {
public:
    char gap_00[0x7C];
    int field_80;
    char gap_84[0x54];
    int field_D8;
    char gap_DC[0x18];

    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(RECT);
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
    virtual void draw_rect(RECT*);
    virtual void draw_offset(long, long, RECT*);
    virtual void draw_rect2(RECT*);
    virtual void draw_offset2(long, long, RECT*);
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
    virtual void get_true_render_rect(RECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
};

class TRIBE_Panel_Text_Line : public TPanel {
public:
    void* font;                    // +0xF4 (4)
    unsigned char text_type;       // +0xF8 (1)
    char text[200];                // +0xF9 (200)
    char _pad[3];                  // +0x1C1 (3)
    long id;                       // +0x1C4 (4)

    virtual ~TRIBE_Panel_Text_Line();
    virtual void draw();
    void set_info(unsigned char type, char* str, long new_id);
};
#endif

void TRIBE_Panel_Text_Line::set_info(unsigned char type, char* str, long new_id)
{
    if (type == this->text_type && strcmp(str, this->text) == 0 && new_id == this->id)
        return;

    this->text_type = type;
    strcpy(this->text, str);
    this->id = new_id;

    this->set_redraw(1);
}
