// VA: 00469910 TEasy_Panel::create_scrollbar(TPanel*, TScrollBarPanel**, TTextPanel*, long, long, long, long, long)
// PDB source: Panel_ez.cpp lines 1616-1640
// attempt 1: natural new/setup path with visible helper methods; first build had fields shifted by +4 from implicit vptr.
// attempt 2: account for TEasy_Panel virtual vptr in padding so field offsets match binary.
// attempt 3: use goto labels for a common result tail; VC5 still cloned success SEH epilogue.
// attempt 4: explicit result local initialized to zero did not alter tail layout.
// attempt 5: positive combined success path with final return 0 did not change VC5's cloned epilogue.
// attempt 6: model vptr explicitly; no change.
// attempt 7: decompiler-style result variable still optimized to cloned returns.
// attempt 8: early parameter result write perturbed setup argument generation; rolled back.
// attempt 9: late parameter result assignment optimized to same cloned epilogues.
// attempt 10: volatile local result forced stack stores and worsened early diff; rolled back to best tail-drift form.
// left in scratch: behavior/call sequence and first 137 bytes match; remaining drift is VC5 SEH return-tail layout.
// rebuilt clones success/failure epilogues and leaves failure branch targets 0x13 bytes later than original common tail.
// FLAGS: config/flags/00469910_create_scrollbar.rsp keeps /GX because default no-/GX build lacks the original EH/new frame and is too small.
// worker 2026-08-10: confirmed the existing canonical typed reconstruction and /GX response-file context;
// no new source-shape lead was found beyond the documented shared-SEH-tail blocker.
// probe 2026-08-11: model the PDB's protected virtual method ABI with a compiler-owned vptr
// instead of an explicit data member; this preserves the proven +0x14/+0x448 layout while
// testing whether polymorphic TEasy_Panel context selects the original EH tail.
// probe 2026-08-11: model TScrollBarPanel's likely polymorphic base surface with a declared
// virtual destructor and reduce its explicit gap by the compiler-owned vptr; field_D8 and
// sizeof remain binary-proven while testing constructor/EH type context.
// probes 1-2 result: both ABI surfaces emitted byte-identical code (47-byte diff, +19 bytes);
// paired create_vert_slider/create_horz_slider exact donors show the same persistent /GX
// shared-failure-tail drift, so the remaining gap is compiler/EH block placement rather than
// unresolved ownership, calls, or layout.
// probe 2026-08-12: model the proven TPanel base for TEasy_Panel and TScrollBarPanel;
// inherited field_D8 and draw_area ownership retain all offsets but emit identical bytes.
// probe 2026-08-12: model TTextPanel as a TPanel-derived type and use implicit base conversion
// for setup; the typed ABI is natural and byte-identical.
// probe 2026-08-12: split the three proven success guards into nested positive if statements;
// VC5 keeps the same 47-byte shared-failure-tail drift.
// probe 2026-08-12: use declaration-only new TScrollBarPanel syntax; codegen is unchanged.
// probe 2026-08-12: align set_bevel_info colors with the exact signed-int Pnl_scbr ABI;
// codegen remains unchanged and the remaining issue is still the /GX cleanup tail.
// group-panelez-469910: retest the complete TPanel -> TEasy_Panel, TPanel -> TScrollBarPanel,
// and TPanel -> TTextPanel ABI from the exact Panel_ez sibling and scrollbar donors.
// - A registered result with a common source return was a codegen duplicate;
//   no stack home or CFG change appeared.  Restored the full typed ABI source.
// shardE-469910: split failure guards into early returns; code grew by 30 bytes and was restored.
// shardE-469910: explicit result arms, all-failure gotos, and registered-result forms were
// duplicates or farther from the oracle.  Negative-OR and else-arm guard forms were duplicates.
// Remaining evidence-backed blocker is the /GX shared EH cleanup tail: VC5 clones the failure
// epilogue and omits the oracle's two-byte jump into one common cleanup block.
// Exact translation-unit finish: the grouped pnl_ez.cpp owner set supplies a
// real earlier body and one shared scrollbar surface. The natural factory then
// matches all 368 bytes and six calls. Target-only compilation emits the prior
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
class TVerticalSliderPanel;
class THorizontalSliderPanel;
class TShape;

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
    long field_14;
    long field_18;
    char gap_1C[0x20 - 0x1C];
    TDrawArea* draw_area;
    char data_24[0xD8 - 0x24];
    int field_D8;
    char data_DC[0xF4 - 0xDC];
};

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
    TScrollBarPanel();
    long setup(void* draw_area, TPanel* parent, long x, long y, long w, long h,
               char* a, char* b, char* c, char* d, long e, long f,
               TPanel* text_panel, long param_4, int vertical);
    void set_buttons(TShape* pics, int a, int b, int c, int d);
    void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6);
};

class TTextPanel : public TPanel {
public:
    char data_F4[0x188 - 0xF4];
    virtual ~TTextPanel();
    void set_scrollbar(TScrollBarPanel* sb, int value);
};

class TEasy_Panel : public TPanel {
public:
    long ideal_width;      // +0xF4
    long ideal_height;     // +0xF8
    char gap_FC[0x220];
    int use_bevels;        // +0x31C
    unsigned char bevel_color1; // +0x320
    unsigned char bevel_color2; // +0x321
    unsigned char bevel_color3; // +0x322
    unsigned char bevel_color4; // +0x323
    unsigned char bevel_color5; // +0x324
    unsigned char bevel_color6; // +0x325
    char gap_326[0x122];
    TShape* button_pics;   // +0x448

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

int TEasy_Panel::create_scrollbar(TPanel* parent, TScrollBarPanel** out, TTextPanel* text, long param_4, long param_5, long param_6, long param_7, long param_8) {
    long x = (this->field_14 * param_5) / this->ideal_width;
    long y = (param_6 * this->field_18) / this->ideal_height;
    long h = (param_8 * this->field_18) / this->ideal_height;
    TScrollBarPanel* sb = new TScrollBarPanel;
    *out = sb;

    if (sb != 0) {
        if (sb->field_D8 == 0) {
            if (sb->setup(this->draw_area, parent, x, y, param_7, h, 0, 0, 0, 0, param_7, param_7, (TPanel*)text, param_4, 0) != 0) {
                if (text != 0) {
                    text->set_scrollbar(*out, 0);
                }

                if (this->button_pics != 0) {
                    (*out)->set_buttons(this->button_pics, -1, 8, 10, 12);
                }

                if (this->use_bevels != 0) {
                    (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
                }

                return 1;
            }
        }
    }

    return 0;
}
