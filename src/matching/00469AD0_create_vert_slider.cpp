// attempt 1: natural vertical slider factory with proportional coordinates, optional button art and bevels
// size matches; early-return version keeps math/setup block exact, remaining drift is epilogue layout plus bevel color zero-extension/order
// tried result-local single-exit form and int color formal parameters; result local regressed early register allocation, so keep cleaner early-return basin
// worker 2026-08-10: a failure-label rewrite was codegen-identical; a result local moved the first
// mismatch into the allocation math and was restored. Final holdout is the original shared EH cleanup
// tail (oracle branches to one failure epilogue; this natural source emits separate cleanup tails).
// worker 2026-08-11 (sa02c04fb1_00469AD0): uninitialized result plus an explicit done label was
// codegen-identical. Positive and negative compound success/failure guards were also identical;
// all three probes preserved the exact 0x0000-0x014D prefix, five ordered calls, and 46-byte diff.
// Dossier confirms the only structural gap is the /GX return tail: the oracle joins three failure
// edges at 00469C24 (xor eax,eax) before one common cleanup, while VC5 clones a failure cleanup
// after the success epilogue. The paired create_scrollbar target documents the same persistent
// EH-tail behavior even after result/goto/vptr probes. Keep this natural typed source in
// scratch; remaining lead is a compiler/EH-tail blocker, not an unresolved call or field layout.
// worker 2026-08-12 (normal-469AD0-r1): exact Panel_ez/pnl_sld donors confirm the int helper
// values and long setup parameter; changing declarations did not change emitted code.
// Compiler-owned vptr surfaces with proven offsets were also a duplicate and were not retained.
// A natural combined success guard with one trailing failure return remained the same 46-byte
// mismatch. The common /GX cleanup tail remains the only structural gap.
// refill-469AD0-r1: test the complete TPanel -> TEasy_Panel and TPanel -> TScrollBarPanel ABI
// from the exact Panel_ez horizontal/scrollbar donors, including the full virtual surfaces.
// The first full-ABI pass made setup a virtual call and regressed to 199 bytes; the exact
// pnl_sld donor keeps this overload nonvirtual, which restored the 46-byte basin.
// The full ABI, scoped result assignment, and new.h context were then checked; only the
// initialized result changed code (215 bytes, despite exact size), and all other changes were
// duplicates. Keep the typed full-ABI source and direct natural returns.
// refill-469AD0-r2: explicit success-else-failure arms with a trailing success return were
// codegen-identical (46-byte drift); VC5 still emits a cloned failure cleanup after success.
// shardE-469AD0: nested status/setup blocks with an explicit result join were also a duplicate;
// restored the direct natural guard. The only gap remains the shared /GX failure cleanup tail.
// abi-fix-469AD0: corrected TVerticalSliderPanel::setup's first parameter from void* to
// TDrawArea*, matching the executable's setup ABI. VC5 emitted identical bytes and kept all
// five direct call targets aligned; retain the natural typed declaration.
// Exact translation-unit finish: the grouped pnl_ez.cpp owner set supplies a
// real earlier body and one shared slider surface. The natural factory then
// matches all 363 bytes and five calls. Target-only compilation emits the prior
// cloned-tail drift.

#ifndef PANEL_BUTTON_TEXT_CONTEXT_H
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class TButtonPanel;
class TTextPanel;
class TInputPanel;
class TEditPanel;
class TDropDownPanel;
class TListPanel;
class THorizontalSliderPanel;
class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
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

    char gap_04[0x0C - 0x04];
    long field_0C;
    long field_10;
    long base_width;
    long base_height;
    char gap_1C[0x20 - 0x1C];
    TDrawArea* draw_area;
    char data_24[0xD8 - 0x24];
    int field_D8;
    char data_DC[0xF4 - 0xDC];
};

class TShape {};

class TScrollBarPanel : public TPanel {
public:
    char data_F4[0x108 - 0xF4];
    TShape* button_pics;
    int back_frame;
    int up_frame;
    int down_frame;
    int tab_frame;
    char data_11C[0x1B8 - 0x11C];
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char data_1C2[0x1C4 - 0x1C2];

    virtual ~TScrollBarPanel();
    void set_buttons(TShape*, int, int, int, int);
    void set_bevel_info(int, int, int, int, int, int, int);
};

class TVerticalSliderPanel : public TScrollBarPanel {
public:
    char data[0x1CC - 0x1C4];
    virtual ~TVerticalSliderPanel();
    TVerticalSliderPanel();
    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y, long w, long h,
               char* a, char* b, long c, long p3, long p4, long p5, int one, int zero);
};

class TEasy_Panel : public TPanel {
public:
    long ideal_width;
    long ideal_height;
    char gap_0FC[0x31C - 0xFC];
    long use_bevels;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char gap_326[0x448 - 0x326];
    TShape* button_pics;

    virtual void draw_background(int);
    virtual void set_ideal_size(long, long);
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long, long, long, long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long, long, long, long, long, long, long);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long, long, long, long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long, long, long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long, long, long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long, long, long, long, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long, long, long, int, int, int);
    virtual int create_input(TPanel*, TInputPanel**, char*, short, int, long, long, long, long, long);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, int, long, long, long, long, long, int, int);
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long, long, long, long, long);
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long, long);
    virtual int create_scrollbar(TPanel*, TScrollBarPanel**, TTextPanel*, long, long, long, long, long);
    virtual int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long, long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long, long, long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);
};
#endif

int TEasy_Panel::create_vert_slider(TPanel* parent, TVerticalSliderPanel** out, long p3, long p4, long p5, long p6, long p7, long p8, long p9) {
    long ideal_x = (p6 * this->base_width) / this->ideal_width;
    long ideal_y = (p7 * this->base_height) / this->ideal_height;
    long ideal_w = (p8 * this->base_width) / this->ideal_width;
    long ideal_h = (p9 * this->base_height) / this->ideal_height;

    *out = new TVerticalSliderPanel;
    if (*out != 0 && (*out)->field_D8 == 0 &&
        (*out)->setup(this->draw_area, parent, ideal_x, ideal_y, ideal_w, ideal_h, 0, 0, 0, p3, p4, p5, 1, 0) != 0) {
        if (this->button_pics != 0) {
            (*out)->set_buttons(this->button_pics, -1, 8, 10, 12);
        }

        if (this->use_bevels != 0) {
            (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
        }

        return 1;
    }

    return 0;
}
