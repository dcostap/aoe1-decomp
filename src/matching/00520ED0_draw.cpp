// 00520ED0 TRIBE_Panel_Text_Line::draw
// Source: tpnl_txl.cpp lines 53-79
//
// Attempt log:
// Probe 1: standard structure — VC5 saves all registers in prologue using `sub esp,8`,
//   original uses `push ecx`+`push esi` and saves edi/ebp/ebx later in draw path
// Probe 2: goto-based single return — still `sub esp,8` prologue, 89.7% diff
// Probe 3: deep codegen basin mismatch on register saving pattern and stack frame
// Probe 4: void return + extern function pointers (failed VC5 syntax)
// Probe 5: eliminated dc local; GetDc used only as condition guard
// Probe 6-8: various virtual call approaches
// Probe 7: used render_area->DrawDc inline instead of cached HDC local
// Probe 8: eliminated vtable named local — lost mov ecx,esi for thiscall
// Probe 9: restored vtable local + dc elimination → push ecx prologue match!
// Probe 10: got parent_panel into ecx via typed virtual method
// Probe 11: added the period TPanel virtual surface for draw_setup,
//   draw_finish, and draw_rect → 0.0000% MATCH

#include "..\..\include\game_globals.h"
#include <windows.h>
#include <string.h>

extern "C" {
__declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
__declspec(dllimport) int __stdcall SetBkMode(HDC, int);
__declspec(dllimport) COLORREF __stdcall SetTextColor(HDC, COLORREF);
__declspec(dllimport) BOOL __stdcall TextOutA(HDC, int, int, LPCSTR, int);
}

extern char s_tpnl_txl_draw[];

#ifdef TPNL_TXL_SHARED_CONTEXT
#include "..\..\include\tpnl_txl_context.h"
#else
class TDrawArea {
public:
    char gap_00[0x38];
    HDC DrawDc;
    void* GetDc(char* name);
    void ReleaseDc(char* name);
};

class TPanel {
public:
    char gap_04[8];
    long pnl_x;
    long pnl_y;
    char gap_14[0x0C];
    TDrawArea* render_area;
    RECT clip_rect;
    char gap_34[0x0C];
    TPanel* parent_panel;
    char gap_44[0x28];
    int active;
    int visible;
    char gap_74[0x80];

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
    void* font;
    unsigned char text_type;
    char text[200];
    char pad[3];
    long id;

    virtual ~TRIBE_Panel_Text_Line();
    virtual void draw();
    void set_info(unsigned char type, char* str, long new_id);
};
#endif

void TRIBE_Panel_Text_Line::draw()
{
    if (this->render_area == 0 || this->visible == 0 || this->active == 0)
        return;

    if (this->parent_panel != 0)
        this->parent_panel->draw_rect(&this->clip_rect);

    this->draw_setup(0);

    if (this->render_area->GetDc(s_tpnl_txl_draw)) {
        HGDIOBJ old_font = SelectObject(this->render_area->DrawDc, (HGDIOBJ)this->font);
        SetBkMode(this->render_area->DrawDc, 1);
        SetTextColor(this->render_area->DrawDc, 0);

        if (this->text[0] != 0) {
            TextOutA(this->render_area->DrawDc, this->pnl_x, this->pnl_y,
                     this->text, strlen(this->text));
        }

        SelectObject(this->render_area->DrawDc, old_font);
        this->render_area->ReleaseDc(s_tpnl_txl_draw);
    }

    this->draw_finish();
}
