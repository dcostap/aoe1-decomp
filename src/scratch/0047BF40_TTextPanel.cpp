// VA: 0047BF40 TTextPanel::TTextPanel
// Pnl_txt.cpp:73-78
// Baseline reconstruction: use the real TPanel base constructor and the
// named text-panel fields proved by the constructor's stores.
// Attempt log:
// - Replaced the raw helper call and fake flat object with a natural derived
//   constructor; the first check below records the resulting ABI/codegen.
// - Expanded the same-TU TPanel virtual surface and TTextPanel draw override;
//   this was a codegen duplicate. Natural VC5 places the derived vtable store
//   at entry, while the oracle sinks it after the field stores; forcing that
//   placement would require the prohibited manual-vtable source shape.
// - Main-agent audit retained natural base/derived construction and the full
//   named text-panel field layout; no explicit vptr store is permitted.
// - Removing the derived destructor declaration was a codegen duplicate;
//   restored the ABI-proven virtual destructor surface.
// - An explicit natural `: TPanel()` initializer was also a duplicate;
//   restored the implicit base-construction spelling.
// - Restored the executable's full TPanel/TTextPanel slot surface (draw,
//   set_rect/set_active, mouse/key/action overrides, and four text slots);
//   the constructor bytes were unchanged.
// - A nonpolymorphic TPanel gap with a polymorphic TTextPanel preserved the
//   first mismatch and disturbed field scheduling; restored real inheritance.
// - A diagnostic C-style `vftable` field plus explicit 0x571BF8 assignment
//   matched exactly, confirming that the remaining gap is only deferred vptr
//   placement.  Restored the natural polymorphic surface: the explicit store
//   is compiler-steering scaffolding, not a canonical source claim.
// - A fresh mapped-assembly donor search found only generic constructor field
//   initialization, with no natural delayed-vptr source lead.  Kept the
//   canonical polymorphic source and the deferred-vptr issue as the blocker.
// - A natural declaration-order member-initializer list reduced the strict
//   diff from 250 to 12 bytes and aligned every field store, but VC5 still
//   emitted the derived vptr before highlight_text_color1; restored the
//   canonical body form.  The remaining gap is compiler-only vptr scheduling.
// - Mirrored donor 00436830 with inline empty TPanel/TTextPanel destructors
//   and an out-of-line TPanel constructor after the derived body; codegen was
//   unchanged, so the full virtual surface remains the evidence-backed lead.

struct tagRECT;

class TPanel {
public:
    virtual ~TPanel();
    TPanel();

    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
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

    char gap_04[0x7C];
    int panel_state_80;
    char gap_84[0x6A];
    unsigned char panel_flag_EE;
    char gap_EF[0x05];
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_rect(long, long, long, long);
    virtual void set_active(int);
    virtual void draw();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void set_text(char**, short);
    virtual void set_text(long);
    virtual void set_text(char*);
    virtual void set_bevel_info(int, int, int, int, int, int, int);

    void* list;                         // +0xF4
    short num_lines;                    // +0xF8
    short draw_lines;                   // +0xFA
    short top_line;                     // +0xFC
    short bot_line;                     // +0xFE
    short cur_line;                     // +0x100
    short cur_col;                      // +0x102
    void* font;                         // +0x104
    long font_wid;                      // +0x108
    long font_hgt;                      // +0x10C
    long vert_align;                    // +0x110
    long horz_align;                    // +0x114
    int word_wrap;                      // +0x118
    long text_style;                    // +0x11C
    unsigned long text_color1;          // +0x120
    unsigned long text_color2;          // +0x124
    unsigned long highlight_text_color1;// +0x128
    unsigned long highlight_text_color2;// +0x12C
    void* scbar_panel;                  // +0x130
    int auto_scbar;                     // +0x134
    short fixed_len;                    // +0x138
    char gap_13A[0x02];
    long text_wid;                      // +0x13C
    long text_hgt;                      // +0x140
    void* back_pic;                     // +0x144
    short back_pic_wid;                 // +0x148
    short back_pic_hgt;                 // +0x14A
    int fill_back;                      // +0x14C
    unsigned char back_color;            // +0x150
    char gap_151[0x03];
    int outline;                        // +0x154
    unsigned char outline_color;         // +0x158
    char gap_159[0x03];
    int sorted;                         // +0x15C
    long second_column_pos;             // +0x160
    long full_width;                    // +0x164
    long scbar_width;                   // +0x168
    int scbar_active;                   // +0x16C
    int bevel_type;                     // +0x170
    unsigned char bevel_color1;          // +0x174
    unsigned char bevel_color2;          // +0x175
    unsigned char bevel_color3;          // +0x176
    unsigned char bevel_color4;          // +0x177
    unsigned char bevel_color5;          // +0x178
    unsigned char bevel_color6;          // +0x179
    char gap_17A[0x02];
    void* clip_rgn2;                    // +0x17C
    int border_size;                    // +0x180
    int spacer_size;                    // +0x184

    TTextPanel();
};

TTextPanel::TTextPanel()
{
    this->back_color = 0xFF;
    this->list = 0;
    this->num_lines = 0;
    this->draw_lines = 0;
    this->top_line = 0;
    this->bot_line = 0;
    this->cur_line = 0;
    this->cur_col = 0;
    this->font = 0;
    this->font_wid = 0;
    this->font_hgt = 0;
    this->vert_align = 0;
    this->horz_align = 0;
    this->word_wrap = 0;
    this->text_style = 2;
    this->text_color1 = 0xFFFFFF;
    this->text_color2 = 0;
    this->highlight_text_color2 = 0;
    this->scbar_panel = 0;
    this->auto_scbar = 0;
    this->fixed_len = 0;
    this->text_wid = 0;
    this->text_hgt = 0;
    this->back_pic = 0;
    this->back_pic_wid = 0;
    this->back_pic_hgt = 0;
    this->fill_back = 0;
    this->outline = 0;
    this->outline_color = 0;
    this->sorted = 0;
    this->second_column_pos = 0;
    this->full_width = 0;
    this->scbar_width = 0;
    this->scbar_active = 0;
    this->bevel_type = 0;
    this->bevel_color1 = 0;
    this->bevel_color2 = 0;
    this->bevel_color3 = 0;
    this->bevel_color4 = 0;
    this->bevel_color5 = 0;
    this->bevel_color6 = 0;
    this->clip_rgn2 = 0;
    this->border_size = 0;
    this->spacer_size = 0;

    this->panel_state_80 = 0;
    this->highlight_text_color1 = 0xFFFF;
    this->panel_flag_EE = 1;
}
