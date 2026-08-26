// attempt 1: natural TInputPanel setup wrapper around TTextPanel::setup
// Structural TU repair: PDB uses int for parameters 11 and 13, and class
// TDrawArea. The grouped owner requires the corresponding H/E/H decoration.
// Resume validation: this repair emits the expected symbol at the original
// 352-byte boundary. The remaining one-byte difference is in the call/data
// relocation surface; the source model and boundary are otherwise aligned.
// ABI probes: restoring the FormatType parameter and the reformat member
// reduced the isolated drift from three bytes to one. Declaration-only slot
// probes matched the narrow checker but had no authentic class evidence and
// were removed.

unsigned long debug_timeGetTime(char* file, int line);
void* calloc(unsigned int, unsigned int);

typedef unsigned char uchar;
typedef unsigned long ulong;
typedef int PositionMode;
typedef int RedrawMode;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {};
class TPanel;
class TDigital {};
class TTextPanel {
public:
    virtual ~TTextPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long,
                                  long, long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
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
    virtual long handle_mouse_down(uchar, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual long handle_mouse_dbl_click(uchar, long, long, int, int);
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
    virtual long action(TPanel*, long, ulong, ulong);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual uchar get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    virtual void set_text(char**, short);
    virtual void set_text(long);
    virtual void set_text(char*);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
    long setup(TDrawArea*, TPanel*, long,long,long,long, void*, long,long,char*, int, unsigned char, int, unsigned char, short, char*);
    void set_alignment(int,int);
    void set_word_wrap(int);
};
class TInputPanel: public TTextPanel {
public:
    enum FormatType {
        FormatSingleLine = 0,
        FormatNumber = 1,
        FormatInteger = 2,
        FormatUnsignedInt = 3,
        FormatFile = 4,
        FormatFileNoExt = 5,
        FormatPath = 6,
        FormatMultiLine = 7,
        FormatPercent = 8
    };

    char gap[0x188 - 4];
    unsigned char field_188;
    char pad_189[7];
    unsigned long field_190;
    long field_194;
    TDigital* field_198;
    long field_19C;
    char* field_1A0;
    char* field_1A4;
    char* field_1A8;
    short field_1AC;
    short field_1AE;
    long setup(TDrawArea*, TPanel*, long,long,long,long, void*, long,long,char*, int, unsigned char, int, unsigned char, unsigned char, short, TDigital*, char*, FormatType);
    virtual void set_focus(int);
    void set_format(FormatType);
    virtual long handle_idle();
    virtual long char_action(long, short);
    virtual long key_down_action(long, short, int, int, int);
    virtual void draw();
    virtual void set_text(char*);
    virtual void set_text(char**, short);
    void reformat();
};

long TInputPanel::setup(TDrawArea* da, TPanel* parent, long p3,long p4,long p5,long p6, void* p7, long p8,long p9,char* p10,int p11,unsigned char p12,int p13,unsigned char p14,unsigned char p15, short maxChars, TDigital* digital, char* text, FormatType format) {
    long setupMax = (format == 7) ? 0 : maxChars;
    if (TTextPanel::setup(da,parent,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,setupMax,0) == 0) {
        return 0;
    }
    this->field_188 = p15;
    this->field_19C = format;
    if (*(long*)((char*)this + 0x78)) {
        this->field_194 = 1;
        this->field_190 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 89);
    }
    if (maxChars) this->field_198 = digital; else this->field_198 = 0;
    if (this->field_19C == 7) {
        this->set_alignment(3,1);
        this->set_word_wrap(1);
    } else {
        this->set_alignment(0,5);
    }
    this->field_1A4 = (char*)calloc((int)maxChars + (int)maxChars + 1,1);
    if (!this->field_1A4) return 0;
    this->field_1A8 = (char*)calloc((int)maxChars + (int)maxChars + 1,1);
    if (!this->field_1A8) return 0;
    this->field_1A0 = this->field_1A4;
    this->set_text(text);
    this->field_1AE = maxChars;
    this->reformat();
    return 1;
}
