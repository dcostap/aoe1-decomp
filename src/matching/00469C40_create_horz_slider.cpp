// attempt 1: natural horizontal slider factory with proportional coordinates, optional button art and bevels
// size matches; early-return version keeps math/setup block exact, remaining drift is epilogue layout plus bevel color zero-extension/order
// tried result-local single-exit form and int color formal parameters; result local regressed early register allocation, so keep cleaner early-return basin
// worker 2026-08-10: one explicit done label with an initialized result local moved the first mismatch
// into allocation math and was restored. Final holdout is the original shared EH cleanup tail; the
// natural source matches all five calls and the complete factory body before that tail.
// probe 2026-08-11: corrected the two helper declarations to the period ABI proven by their exact
// same-TU definitions (all set_buttons/set_bevel_info value parameters are int, not long).
// probe 2026-08-11: corrected setup's third post-pointer parameter to long, matching the exact
// THorizontalSliderPanel::setup donor and its decorated ABI.
// probe 2026-08-11: restored the proven polymorphic slider base surface and vptr while preserving
// field_D8 at 0xD8 and the complete 0x1CC derived allocation size.
// probe 2026-08-11: restored TEasy_Panel's virtual method surface with the exact donor-style
// 0x10 post-vptr gap so all observed panel fields retain their proven offsets.
// probe 2026-08-11: the labeled success-to-done form was codegen-identical to the clean basin.
// Delayed result initialization reached exact size but displaced the out-pointer/register topology
// (215-byte diff); explicit failure gotos and ordinary early returns likewise worsened the body
// (210-byte and 251-byte diffs). All were rolled back. The remaining 46-byte drift is only the
// /GX cleanup-tail shape: the oracle joins three failure edges at one xor/common epilogue, while
// VC5 clones the failure cleanup after the success epilogue in this natural source basin.
// group-panelez-469C40: retest the complete TPanel -> TEasy_Panel and TPanel -> TScrollBarPanel
// ABI from the exact Panel_ez sibling and pnl_sld donors before final validation.
// - A registered result was a codegen duplicate; no stack home or CFG change
//   appeared.  Restored the full typed ABI source.
// probe 2026-08-13: explicit failure-edge result assignments plus a done label worsened the
// body (251-byte diff); restored the combined guard.
// probe 2026-08-13: a failure-only goto, a post-allocation result declaration, a long result,
// a do-while join, and direct per-arm returns were all codegen duplicates (46-byte diff).
// The remaining drift is a compiler-owned duplicated /GX cleanup tail; no source-shape lead
// remains without changing the exact body prefix.
// worker 2026-08-16 (sa-374696e2-r1): natural direct success/failure returns matched the
// paired vertical-slider donor but remained a 46-byte duplicate. Separate early returns for
// null, field_D8, and setup failure worsened the body to 251 bytes. Initializing the existing
// result local to zero was also a 46-byte duplicate. Restored the clean natural result source.
// worker 2026-08-17 (sa-2509371b-r1): a named done label, success-only goto, and explicit
// allocation parentheses were 46-byte duplicates. A named typed slider pointer worsened the
// body to 247 bytes. Restored the direct typed output ownership and natural creation flow.
// worker 2026-08-17 (sa-17d3e1fb-r1): defining the proven empty
// THorizontalSliderPanel destructor in this TU changed the compiler-owned EH tail and gave
// an authoritative 0-byte MATCH. This is not retained: VA 0047BE30 already has the compiler-
// facing owner src/matching/0047BE30_THorizontalSliderPanel.cpp. Keeping that definition here
// would violate the one-owner rule. The declaration-only natural source remains at 46 bytes.
// ACCEPTED DRIFT: The complete factory body and all five calls match. The
// declaration-only build clones the success and failure EH epilogues. The
// oracle shares them. Both paths restore the same SEH link, registers, stack,
// and return value. Only MOV, XOR, and POP instructions move around the SEH
// restore. No call or external memory effect moves. The proven empty destructor
// definition makes this source exact in the authentic same-TU context.
// Exact translation-unit finish: the grouped pnl_ez.cpp owner set supplies a
// real earlier body and one shared slider surface. The natural factory then
// matches all 363 bytes and five calls. Target-only compilation emits the
// reviewed cloned-tail drift.

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
class TVerticalSliderPanel;
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

class THorizontalSliderPanel : public TScrollBarPanel {
public:
    char data[0x1CC - 0x1C4];
    virtual ~THorizontalSliderPanel();
    THorizontalSliderPanel();
    long setup(void* draw_area, TPanel* parent, long x, long y, long w, long h,
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
    virtual int create_horz_slider(TPanel* parent, THorizontalSliderPanel** out, long p3, long p4, long p5, long p6, long p7, long p8, long p9);
    virtual void position_panel(TPanel*, long, long, long, long);
};
#endif

int TEasy_Panel::create_horz_slider(TPanel* parent, THorizontalSliderPanel** out, long p3, long p4, long p5, long p6, long p7, long p8, long p9) {
    long ideal_x = (p6 * this->base_width) / this->ideal_width;
    long ideal_y = (p7 * this->base_height) / this->ideal_height;
    long ideal_w = (p8 * this->base_width) / this->ideal_width;
    long ideal_h = (p9 * this->base_height) / this->ideal_height;

    int result;
    *out = new THorizontalSliderPanel;
    if (*out != 0 && (*out)->field_D8 == 0 &&
        (*out)->setup(this->draw_area, parent, ideal_x, ideal_y, ideal_w, ideal_h, 0, 0, 0, p3, p4, p5, 1, 0) != 0) {
        if (this->button_pics != 0) {
            (*out)->set_buttons(this->button_pics, -1, 8, 10, 12);
        }

        if (this->use_bevels != 0) {
            (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
        }
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
