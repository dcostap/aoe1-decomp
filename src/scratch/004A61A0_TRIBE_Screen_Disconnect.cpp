// 004A61A0 TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect
//
// Attempt log:
// - Earlier raw-wrapper scaffold had the right broad effects but no constructor
//   EH/vptr surface and an extra draw-area helper call.
// - Baseline candidate: natural TScreenPanel-derived constructor, named fields,
//   real panel member-call surfaces, and the proven rge_base_game draw_area.
// - Direct setup predicate removed the named result and recovered the exact
//   prologue/setup call sequence through the conditional (best codegen: 91
//   positional bytes, 219-byte rebuilt body, exact four-call set).
// - Shared-goto, arm-order, destructor-surface, qualified-call, virtuality, and
//   switch probes did not improve the remaining branch tail.
// - Final unresolved drift is structural: VC5 duplicates the normal EH cleanup
//   epilogue on the setup-failure path instead of the original short jump to the
//   shared epilogue. No call or field-ownership discrepancy remains.
// - Fresh pass inspected the /GX exact same-TU constructor/dtor family first.
//   Canonicalized the local TPanel/TEasy_Panel inheritance, proven 0xF4 base
//   size, inherited virtual surface, and nonvirtual TScreenPanel setup helper;
//   this preserved the exact four-call set and 31-instruction prefix.
// - Same-TU donor control-flow forms tried: explicit setup-failure return with
//   and without else, inverted guard, do-while(0) break, both-arm returns, and
//   unary ! guard. All landed in the same 219-byte VC5 basin; no further blind
//   branch-tail variants remain productive under this pass.
// - Final source keeps the period-plausible unary ! guard and explicit failure
//   return; remaining drift is the duplicated normal EH cleanup epilogue.

struct tagRECT;
class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void* draw_area, TPanel* parent, long p3, long p4,
                       long p5, long p6, unsigned char p7);
    virtual void set_rect(tagRECT rect);
    virtual void set_rect(long left, long top, long right, long bottom);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(int mode, int a2, int a3, int a4, int a5,
                                 int a6, int a7, int a8, int a9,
                                 TPanel* a10, TPanel* a11, TPanel* a12,
                                 TPanel* a13);
    virtual void set_fixed_position(long left, long top, long right, long bottom);
    virtual void set_redraw(int mode);
    virtual void set_overlapped_redraw(TPanel* p1, TPanel* p2, int mode);
    virtual void draw_setup(int mode);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT* rect);
    virtual void draw_offset(long x, long y, tagRECT* rect);
    virtual void draw_rect2(tagRECT* rect);
    virtual void draw_offset2(long x, long y, tagRECT* rect);
    virtual void paint();
    virtual long wnd_proc(void* hwnd, unsigned int msg, unsigned int wparam,
                          long lparam);
    virtual long handle_idle();
    virtual long handle_size(long width, long height);
    virtual long handle_paint();
    virtual long handle_key_down(long key, short repeat, int a3, int a4, int a5);
    virtual long handle_char(long key, short repeat);
    virtual long handle_command(unsigned int command, long param);
    virtual long handle_user_command(unsigned int command, long param);
    virtual long handle_timer_command(unsigned int command, long param);
    virtual long handle_scroll(long a1, long a2);
    virtual long handle_mouse_down(unsigned char button, long x, long y,
                                   int a4, int a5);
    virtual long handle_mouse_move(long x, long y, int a3, int a4);
    virtual long handle_mouse_up(unsigned char button, long x, long y,
                                 int a4, int a5);
    virtual long handle_mouse_dbl_click(unsigned char button, long x, long y,
                                        int a4, int a5);
    virtual long mouse_move_action(long x, long y, int a3, int a4);
    virtual long mouse_left_down_action(long x, long y, int a3, int a4);
    virtual long mouse_left_hold_action(long x, long y, int a3, int a4);
    virtual long mouse_left_move_action(long x, long y, int a3, int a4);
    virtual long mouse_left_up_action(long x, long y, int a3, int a4);
    virtual long mouse_left_dbl_click_action(long x, long y, int a3, int a4);
    virtual long mouse_right_down_action(long x, long y, int a3, int a4);
    virtual long mouse_right_hold_action(long x, long y, int a3, int a4);
    virtual long mouse_right_move_action(long x, long y, int a3, int a4);
    virtual long mouse_right_up_action(long x, long y, int a3, int a4);
    virtual long mouse_right_dbl_click_action(long x, long y, int a3, int a4);
    virtual long key_down_action(long key, short repeat, int a3, int a4, int a5);
    virtual long char_action(long key, short repeat);
    virtual long action(TPanel* panel, long command, unsigned long p3,
                        unsigned long p4);
    virtual void get_true_render_rect(tagRECT* rect);
    virtual int is_inside(long x, long y);
    virtual void set_focus(int focus);
    virtual void set_tab_order(TPanel* previous, TPanel* next);
    virtual void set_tab_order(TPanel** panels, short count);
    virtual unsigned char get_help_info(char** text, long* id, long a3, long a4);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char gap_04[0xD4];
    int field_D8;
    char gap_DC[0x18];
};

class TTextPanel;
class TButtonPanel;

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    virtual void draw_background(int mode);
    virtual void set_ideal_size(long width, long height);
    virtual int create_button(TPanel* parent, TButtonPanel** out, long id,
                              long a4, long a5, long a6, long a7, long a8,
                              long a9, long a10, long a11);
    virtual int create_button(TPanel* parent, TButtonPanel** out, char* name,
                              char* text, long a5, long a6, long a7, long a8,
                              long a9, long a10, long a11);
    virtual int create_check_box(TPanel* parent, TButtonPanel** out, long id,
                                 long a4, long a5, long a6, long a7, long a8);
    virtual int create_radio_button(TPanel* parent, TButtonPanel** out,
                                    long id, long a4, long a5, long a6,
                                    long a7, long a8);
    virtual int create_text(TPanel* parent, TTextPanel** out, int string_id,
                            long x, long y, long width, long height, long font,
                            int align, int center, int wrap);
    virtual int create_text(TPanel* parent, TTextPanel** out, char** text,
                            long x, long y, long width, long height, long font,
                            long align, int center, int wrap);
    virtual int create_text(TPanel* parent, TTextPanel** out, char* text,
                            long x, long y, long width, long height, long font,
                            int align, int center, int wrap);
    virtual int create_input(TPanel* parent, void* out, char* text, short len,
                             int format, long x, long y, long width, long height,
                             long a10);
    virtual int create_edit(TPanel* parent, void* out, char* text, short len,
                            int format, long x, long y, long width, long height,
                            long a10, int a11, int a12);
    virtual int create_drop_down(TPanel* parent, void* out, long id, long a4,
                                 long a5, long a6, long a7, long a8, long a9);
    virtual int create_list(TPanel* parent, void* out, long id, long a4,
                            long a5, long a6, long a7);
    virtual int create_scrollbar(TPanel* parent, void* out, TTextPanel* text,
                                 long a4, long a5, long a6, long a7, long a8);
    virtual int create_auto_scrollbar(void* out, TTextPanel* text, long a3);
    virtual int create_vert_slider(TPanel* parent, void* out, long id, long a4,
                                   long a5, long a6, long a7, long a8, long a9);
    virtual int create_horz_slider(TPanel* parent, void* out, long id, long a4,
                                   long a5, long a6, long a7, long a8, long a9);
    virtual void position_panel(TPanel* parent, long a2, long a3, long a4,
                                long a5);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
    TScreenPanel(char* name);
    long setup(void* draw_area, char* info, long id, int value);
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    void* draw_area;
};

extern RGE_Base_Game* rge_base_game;
extern char s_Multiplayer_Disconnect_Screen[];
extern char s_scr3[];

class TRIBE_Screen_Disconnect : public TScreenPanel {
public:
    int mode;
    TTextPanel* message;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;

    virtual ~TRIBE_Screen_Disconnect();
    TRIBE_Screen_Disconnect(int mode);
};

TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect(int mode)
    : TScreenPanel(s_Multiplayer_Disconnect_Screen)
{
    this->mode = mode;
    this->message = 0;
    this->cancel_button = 0;
    this->close_button = 0;

    if (!this->setup(rge_base_game->draw_area, s_scr3, 0xC385, 0)) {
        this->field_D8 = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1E0);
    this->create_text((TPanel*)this, &this->message, 0x4C0,
                      0x28, 0x28, 0x230, 0x190, 4, 1, 1, 1);
}
