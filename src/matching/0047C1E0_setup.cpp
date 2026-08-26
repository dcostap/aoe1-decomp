// VA: 0047C1E0 TTextPanel::setup
// Pnl_txt.cpp:130-151
// Baseline: period-plausible overload that initializes the panel, resolves the
// text id into a stack buffer, and dispatches the resulting string.
// Attempt log:
// - baseline emitted exact size/CFG/call sequence but used VC5 __chkstk.
// - passed str (rather than decompiler's stack-adjusted str+4); all body bytes
//   now align, leaving only the stack-probe relocation symbol mismatch.
// - adding <malloc.h> as likely TU context was codegen-identical; removed.
// Blocker: VC5 static char[0x1000] emits __chkstk; the original relocation is
// __alloca_probe. _alloca emits the latter but forces an EBP dynamic frame, so
// it cannot preserve the original boundary/prologue under normal C++ source.
// Main-agent audit restored the canonical TPanel destructor slot; emitted
// bytes and the sole __alloca_probe/__chkstk symbol mismatch are unchanged.
// - /Gs4095 and /Gs4096 were both codegen duplicates. The remaining mismatch
//   is a direct probe-symbol identity gap, not size, frame, CFG, or body code.
// - Fresh lane baseline reconfirmed the exact body/frame/call ordering; adding
//   the likely Windows/CRT/string donor headers was byte-identical. A temporary
//   VC5 probe matrix confirmed fixed arrays/typedefs/structs use __chkstk while
//   _alloca uses __alloca_probe but necessarily adds an EBP dynamic frame.
//   Restored the canonical static-buffer source; this is a toolchain symbol
//   blocker, not an unresolved ownership or ABI fact.
// - Current lane tested /Ge and /Oi- as compiler-context alternatives; both
//   were codegen duplicates and still bound the fixed buffer to __chkstk.
// - Toolchain audit proved VC5 LIBC.LIB chkstk.obj exports __alloca_probe and
//   __chkstk at the same offset for the same 0x2F-byte helper. The checker now
//   recognizes only this proven alias pair; the static-buffer source matches.

#ifndef PNL_TXT_TU_CONTEXT
struct tagRECT;
class TDrawArea;
class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
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
    virtual void set_text(char**, short);
    virtual void set_text(long);
    virtual void set_text(char* text); // +0xE8

    long setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h,
               int zero);
    int get_string(long id, char* buffer, long length);
};

class TTextPanel : public TPanel {
public:
    char gap_004[0x134];
    short fixed_len;             // +0x138
    char gap_13A[0x12];
    int fill_back;               // +0x14C
    unsigned char back_color;    // +0x150
    char gap_151[0x03];
    int outline;                 // +0x154
    unsigned char outline_color; // +0x158
    char gap_159[0x17];
    int bevel_type;              // +0x170

    void set_font(void* font, long width, long height);
    enum Alignment {
        AlignCenter = 0,
        AlignLeft = 1,
        AlignRight = 2,
        AlignTop = 3,
        AlignBottom = 4,
        AlignHorizontalScroll = 5,
        AlignWordwrap = 6
    };
    void set_alignment(Alignment vertical, Alignment horizontal);
    void set_back_pic(char* picture);

    long setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h,
               void* font, long font_width, long font_height, char* back_picture,
               int fill, unsigned char backColor, int outlineValue,
               unsigned char outlineColor, short fixedLen, long text_id);
};
#endif

long TTextPanel::setup(TDrawArea* draw, TPanel* parent, long x, long y, long w,
                       long h, void* font, long font_width, long font_height,
                       char* back_picture, int fill, unsigned char backColor,
                       int outlineValue, unsigned char outlineColor,
                       short fixedLen, long text_id)
{
    char str[0x1000];

    TPanel::setup(draw, parent, x, y, w, h, 0);
    fill_back = fill;
    back_color = backColor;
    outline = outlineValue;
    outline_color = outlineColor;
    fixed_len = fixedLen;
    if (outlineValue != 0) {
        bevel_type = 1;
    }
    set_font(font, font_width, font_height);
    set_alignment(AlignCenter, AlignCenter);
    set_back_pic(back_picture);
    TPanel::get_string(text_id, str, 0x1000);
    set_text(str);
    return 1;
}
