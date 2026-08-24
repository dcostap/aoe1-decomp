// Authentic durable Pnl_inp.cpp translation-unit wrapper.
// Source module: C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp.
//
// The disabled include list is the proposal's canonical PDB-order owner map.
// The source bodies below use one real TPanel -> TTextPanel -> TInputPanel
// surface. No helper vtable, manual vptr store, assembly, or volatile probe is
// used. The include lines remain disabled because the historical per-function
// files carry narrow declarations for isolated checks.
#if 0
#include "matching/00476C10_TInputPanel.cpp"
#include "matching/00476CF0_TInputPanel.cpp"
#include "scratch/00476D80_setup.cpp"
#include "matching/00476EE0_set_focus.cpp"
#include "matching/00476F20_set_format.cpp"
#include "matching/00476F30_handle_idle.cpp"
#include "matching/00476FA0_char_action.cpp"
#include "scratch/00477220_key_down_action.cpp"
#include "matching/004777C0_draw.cpp"
#include "matching/00477910_set_text.cpp"
#include "matching/00477990_set_text.cpp"
#include "matching/004779A0_get_input_buffer.cpp"
#include "matching/004779B0_append_character.cpp"
#include "matching/004779D0_insert_character.cpp"
#include "matching/00477AF0_delete_character.cpp"
#include "matching/00477C90_backspace_character.cpp"
#include "matching/00477CB0_paste.cpp"
#include "matching/00477E90_reformat.cpp"
#include "matching/00477EF0_calc_input_pos.cpp"
#include "matching/00478010_calc_cur_line_col.cpp"
#include "matching/00478150_is_blank.cpp"
#include "matching/004781A0_get_trimmed_str.cpp"
#endif

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned long ulong;

typedef void* HWND;
typedef void* HANDLE;
typedef void* HDC;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

typedef int PositionMode;
typedef int RedrawMode;

struct PanelNode;
struct TextNode {
    char* text;
    char* text2;
    long id;
    TextNode* next_node;
};

struct TDrawArea {
    void* inst;
    void* Wnd;
    char gap_08[0x100 - 0x08];

    void* GetDc(const char* name);
    void ReleaseDc(const char* name);
    uchar* Lock(const char* name, int flag);
    void Unlock(const char* name);
    void DrawVertLine(int x, int y, int h, uchar color);
};

class TDigital {
public:
    int play();
};

class TPanel {
public:
    virtual ~TPanel();
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

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    tagRECT clip_rect;
    PositionMode position_mode;
    RedrawMode need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    int mouse_captured;
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    int overlapping_children;
    int handle_mouse_input;
    int just_drawn;
    void* clip_rgn;
    tagRECT render_rect;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    ulong mouse_down_time;
    int error_code;
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    uchar mouse_action;
    uchar mouse_down_button;
    uchar panel_type;
    uchar color;
    uchar fill_in_background;
    uchar clip_to_parent;
    uchar draw_rect2_flag;
    uchar need_restore;
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_text(char*);

    TextNode* list;
    short num_lines;
    short draw_lines;
    short top_line;
    short bot_line;
    short cur_line;
    short cur_col;
    void* font;
    long font_wid;
    long font_hgt;
    int vert_align;
    int horz_align;
    int word_wrap;
    int text_style;
    ulong text_color1;
    ulong text_color2;
    ulong highlightTextColor1;
    ulong highlightTextColor2;
    void* scbar_panel;
    int auto_scbar;
    short fixed_len;
    uchar pad_13A[2];
    long text_wid;
    long text_hgt;
    void* back_pic;
    short back_pic_wid;
    short back_pic_hgt;
    int fill_back;
    uchar back_color;
    uchar pad_151[3];
    int outline;
    uchar outline_color;
    uchar pad_159[3];
    int sorted;
    long second_column_pos;
    long full_width;
    long scbar_width;
    int scbar_active;
    int bevel_type;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    uchar pad_17A[2];
    void* clip_rgn2;
    int border_size;
    int spacer_size;

    TTextPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, long, uchar, long, uchar, short, char*);
    void set_alignment(int, int);
    void set_word_wrap(int);
    void draw();
    void calc_line_pos(void*, short, short, tagRECT*, int*);
    char* get_text();
    char* get_text(int);
    void scroll(uchar, uchar, int);
    char* currentLine();
};

class TInputPanel : public TTextPanel {
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

    TInputPanel();
    virtual ~TInputPanel();

    uchar caret_color;
    uchar pad_189[3];
    ulong caret_interval;
    ulong caret_last_time;
    int draw_caret;
    TDigital* overLengthSound;
    FormatType format_type;
    char* input_buffer;
    char* input_buffer1;
    char* input_buffer2;
    short input_len;
    short max_len;
    int insert_mode;
    short input_pos;
    uchar pad_1B6[2];

    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, long, uchar, long, uchar, uchar, short, TDigital*, char*,
               FormatType);
    virtual void set_focus(int);
    void set_format(FormatType);
    virtual long handle_idle();
    virtual long char_action(long, short);
    virtual long key_down_action(long, short, int, int, int);
    virtual void draw();
    virtual void set_text(char*);
    virtual void set_text(char**, short);
    char* get_input_buffer();

protected:
    int append_character(long);
    int insert_character(long);
    int delete_character();
    int backspace_character();
    int paste();
    void reformat();
    void calc_input_pos();
    void calc_cur_line_col();

public:
    int is_blank();
    char* get_trimmed_str(char*, int);
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetCaretBlinkTime();
extern "C" unsigned long __cdecl debug_timeGetTime(char*, int);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" short __cdecl __mbslen(const char*);
extern "C" int __cdecl _mbslen(const char*);
extern "C" int __cdecl __mbscmp(const char*, const char*);
extern "C" char* __cdecl __mbschr(const char*, unsigned int);
extern "C" char* __cdecl __mbscpy(char*, const char*);
extern "C" void* __cdecl _mbsncpy(void*, void*, int);
extern "C" void* __cdecl _mbsninc(void*, int);
extern "C" void* __cdecl _mbsinc(void*);
extern "C" void* __cdecl _mbsdec(void*, void*);
extern "C" int __cdecl __ismbcspace(unsigned int);
extern "C" int __cdecl memset(void*, int, unsigned int);
extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" void (__stdcall* const MessageBeep)(unsigned int);
extern void operator delete(void*);
typedef void* (__stdcall *SelectObjectFn)(void*, void*);
extern SelectObjectFn g_SelectObject;
extern char pnl_inp_draw[];
extern "C" int __stdcall IsClipboardFormatAvailable(unsigned int);
extern "C" int __stdcall OpenClipboard(HWND);
extern "C" HANDLE __stdcall GetClipboardData(unsigned int);
extern "C" void* __stdcall GlobalLock(HANDLE);
extern "C" int __stdcall GlobalUnlock(HANDLE);
extern "C" int __stdcall CloseClipboard(void);

TInputPanel::TInputPanel() : TTextPanel()
{
    this->caret_color = 0;
    this->caret_interval = GetCaretBlinkTime();
    this->caret_last_time = 0;
    this->draw_caret = 1;
    this->insert_mode = 1;
    this->handle_mouse_input = 1;
    this->bevel_type = 1;
    this->overLengthSound = 0;
    this->input_buffer = 0;
    this->input_buffer1 = 0;
    this->input_buffer2 = 0;
    this->input_len = 0;
    this->max_len = 0;
    this->input_pos = 0;
    this->panel_type = 7;
    this->horz_align = 5;
}

TInputPanel::~TInputPanel()
{
    if (this->input_buffer1 != 0) {
        delete this->input_buffer1;
        this->input_buffer1 = 0;
    }
    if (this->input_buffer2 != 0) {
        delete this->input_buffer2;
        this->input_buffer2 = 0;
    }
    this->input_buffer = 0;
    this->handle_mouse_input = 1;
}

long TInputPanel::setup(TDrawArea* da, TPanel* parent, long p3, long p4,
                        long p5, long p6, void* p7, long p8, long p9,
                        char* p10, long p11, uchar p12, long p13, uchar p14,
                        uchar p15, short maxChars, TDigital* digital,
                        char* text, FormatType format)
{
    short setupMax = (format == FormatMultiLine) ? 0 : maxChars;
    if (TTextPanel::setup(da, parent, p3, p4, p5, p6, p7, p8, p9, p10,
                          p11, p12, p13, p14, setupMax, 0) == 0) {
        return 0;
    }
    this->caret_color = p15;
    this->format_type = format;
    if (this->have_focus != 0) {
        this->draw_caret = 1;
        this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 89);
    }
    if (maxChars != 0)
        this->overLengthSound = digital;
    else
        this->overLengthSound = 0;
    if (this->format_type == FormatMultiLine) {
        this->set_alignment(3, 1);
        this->set_word_wrap(1);
    } else {
        this->set_alignment(0, 5);
    }
    this->input_buffer1 = (char*)calloc((unsigned int)((int)maxChars + (int)maxChars + 1), 1);
    if (this->input_buffer1 == 0) return 0;
    this->input_buffer2 = (char*)calloc((unsigned int)((int)maxChars + (int)maxChars + 1), 1);
    if (this->input_buffer2 == 0) return 0;
    this->input_buffer = this->input_buffer1;
    this->set_text(text);
    this->max_len = maxChars;
    this->reformat();
    return 1;
}

void TInputPanel::set_focus(int focus)
{
    TPanel::set_focus(focus);
    if (this->have_focus != 0) {
        this->draw_caret = 1;
        this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 137);
    }
}

void TInputPanel::set_format(FormatType format)
{
    this->format_type = format;
}

long TInputPanel::handle_idle()
{
    if (this->have_focus != 0) {
        unsigned long now = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 158);
        if ((now - this->caret_last_time) >= this->caret_interval) {
            this->draw_caret = (this->draw_caret == 0) ? 1 : 0;
            this->set_redraw(1);
            now = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 163);
            this->caret_last_time = now;
        }
    }
    return TPanel::handle_idle();
}

long TInputPanel::char_action(long ch, short count)
{
    short i;
    if (ch == 8 || ch == 9 || ch == 10 || ch == 13 || ch == 27 || ch < 0x1B)
        return 1;
    if (count == 0) count = 1;
    i = 0;
    if (count <= 0) return 1;
    while (i < count) {
        switch (this->format_type) {
        case FormatPercent:
            if (__mbslen(this->get_text()) < 2 && ch >= '0' && ch <= '9') break;
            if (__mbslen(this->get_text()) != 2 || ch != '0' ||
                __mbscmp("10", this->get_text()) != 0) {
                if (this->overLengthSound != 0) this->overLengthSound->play();
                else MessageBeep(0xFFFFFFFF);
                return 1;
            }
            break;
        case FormatNumber:
        case FormatInteger:
        case FormatUnsignedInt:
            if (ch >= '0' && ch <= '9') break;
            if (ch == '-' && this->input_buffer[0] == 0 && this->format_type != FormatUnsignedInt) break;
            if (ch == '.' && __mbschr(this->input_buffer, ch) != 0 && this->format_type == FormatNumber) break;
            if (this->overLengthSound != 0) this->overLengthSound->play();
            else MessageBeep(0xFFFFFFFF);
            return 1;
        case FormatFile:
        case FormatFileNoExt:
            if (ch == '.') {
                if (this->format_type == FormatFile && __mbschr(this->input_buffer, ch) == 0) break;
            }
            if (ch == '.' || ch == '\\' || ch == ':' || ch == '/' || ch == '"' || ch == '*' || ch == '?' || ch == '>' || ch == '<' || ch == '|') {
                if (this->overLengthSound != 0) this->overLengthSound->play();
                else MessageBeep(0xFFFFFFFF);
                return 1;
            }
            break;
        case FormatPath:
            if ((ch == ':' && this->input_len != 1) || ch == '/' || ch == '"' || ch == '*' || ch == '?' || ch == '>' || ch == '<' || ch == '|') {
                if (this->overLengthSound != 0) this->overLengthSound->play();
                else MessageBeep(0xFFFFFFFF);
                return 1;
            }
            break;
        case FormatSingleLine:
        case FormatMultiLine:
        default:
            break;
        }
        if (this->insert_character(ch) == 0) return 1;
        ++i;
    }
    return 1;
}

long TInputPanel::key_down_action(long key, short, int, int param4, int param5)
{
    short len;
    short col;
    short line;

    switch (key) {
    case 0x25:
        if (this->num_lines < 1) return 1;
        col = this->cur_col;
        if (col > 0) {
            col--;
            this->cur_col = col;
            this->calc_input_pos();
            this->set_redraw(1);
            return 1;
        } else {
            col = this->cur_line;
            if (col <= 0) return 1;
            col--;
            this->cur_line = col;
            col = __mbslen(this->get_text(this->cur_line));
        }
        this->cur_col = col;
        this->calc_input_pos();
        this->set_redraw(1);
        return 1;

    case 0x27:
        if (this->num_lines < 1) return 1;
        col = this->cur_col;
        len = __mbslen(this->get_text(this->cur_line));
        if (col < len) {
            this->cur_col = col + 1;
            this->calc_input_pos();
            this->set_redraw(1);
        } else {
            if (this->cur_line >= this->num_lines - 1) return 1;
            this->cur_line++;
            this->cur_col = 0;
            this->calc_input_pos();
            this->set_redraw(1);
        }
        return 1;

    case 0x26:
        if (this->num_lines < 1) return 1;
        if (this->cur_line > 0) {
            this->cur_line--;
            if (this->cur_col > __mbslen(this->get_text(this->cur_line)))
                this->cur_col = __mbslen(this->get_text(this->cur_line));
            this->calc_input_pos();
            this->set_redraw(1);
            return 1;
        }
        break;

    case 0x28:
        if (this->num_lines < 1) return 1;
        if (this->cur_line >= this->num_lines - 1) return 1;
        this->cur_line++;
        line = this->cur_line;
        goto page_update;

    case 0x24:
        if (this->num_lines < 1) return 1;
        if (param4 != 0) {
            if (this->cur_col == 0 && this->cur_line == 0) break;
            this->cur_col = 0;
            this->cur_line = 0;
            this->calc_input_pos();
            this->set_redraw(1);
            return 1;
        }
        if (this->cur_col == 0) break;
        this->cur_col = 0;
        this->set_redraw(1);
        this->calc_input_pos();
        return 1;

    case 0x23:
        if (this->num_lines < 1) return 1;
        if (param4 != 0) {
            if (this->cur_line == this->num_lines - 1) {
                len = __mbslen(this->get_text(this->cur_line));
                if (this->cur_col == len) break;
            }
            this->cur_line = this->num_lines - 1;
            this->cur_col = __mbslen(this->get_text(this->cur_line));
        } else {
            len = __mbslen(this->get_text(this->cur_line));
            if (this->cur_col == len) break;
            this->cur_col = __mbslen(this->get_text(this->cur_line));
        }
        this->set_redraw(1);
        this->calc_input_pos();
        return 1;

    case 0x21:
        if (this->num_lines < 1) return 1;
        if (this->cur_line <= 0) return 1;
        line = this->cur_line;
        if (line < this->top_line || line > this->bot_line) line = this->top_line;
        if (line == this->top_line) {
            this->scroll(5, 0, 1);
            line = this->top_line;
        }
        goto page_update;

    case 0x22:
        if (this->num_lines < 1) return 1;
        if (this->cur_line >= this->num_lines - 1) return 1;
        line = this->cur_line;
        if (line < this->top_line || line > this->bot_line) line = this->bot_line;
        if (line == this->bot_line) {
            this->scroll(4, 0, 1);
            line = this->bot_line;
        }
page_update:
        this->cur_line = line;
        len = __mbslen(this->get_text(this->cur_line));
        if (this->cur_col > len)
            this->cur_col = __mbslen(this->get_text(this->cur_line));
        this->calc_input_pos();
        this->set_redraw(1);
        return 1;

    case 0x2E:
        this->delete_character();
        return 1;

    case 0x2D:
        if (param5 != 0) goto paste_action;
        if (param4 != 0) return 1;
        this->insert_mode = (this->insert_mode == 0);
        return 1;

    case 8:
        this->backspace_character();
        return 1;

    case 0x0D:
        if (this->format_type == FormatMultiLine) {
            this->insert_character(10);
            return 1;
        }
        if (this->parent_panel != 0)
            this->parent_panel->action(this, 0, 0, 0);
        return 1;

    case 0x1B:
        if (this->parent_panel != 0)
            this->parent_panel->action(this, 1, 0, 0);
        return 1;

    case 0x56:
        if (param4 == 0) return 0;
paste_action:
        this->paste();
        return 1;

    default:
        return 0;
    }
    return 1;
}

void TInputPanel::draw()
{
    TTextPanel::draw();
    if (this->render_area == 0) return;
    if (this->visible == 0) return;
    if (this->active == 0) return;
    if (this->have_focus == 0) return;
    if (this->draw_caret == 0) return;
    if (this->cur_line < this->top_line) return;
    if (this->cur_line > this->bot_line) return;

    this->draw_setup(0);
    void* dc = this->render_area->GetDc(pnl_inp_draw);
    if (dc != 0) {
        SelectObjectFn select_object = g_SelectObject;
        void* old_font = select_object(dc, this->font);
        tagRECT line_rect;
        int cursor_x_offset;
        short cur = this->cur_line;
        short diff = cur - this->top_line;
        this->calc_line_pos(dc, diff, cur, &line_rect, &cursor_x_offset);
        select_object(dc, old_font);
        this->render_area->ReleaseDc(pnl_inp_draw);
        uchar* locked = this->render_area->Lock(pnl_inp_draw, 1);
        if (locked != 0) {
            int x = cursor_x_offset + line_rect.left;
            int y = line_rect.top;
            int h = (line_rect.bottom - line_rect.top) + 1;
            if (x < this->render_rect.right) {
                this->render_area->DrawVertLine(x, y, h, this->caret_color);
                this->render_area->DrawVertLine(x + 1, y, h, this->caret_color);
            }
            this->render_area->Unlock(pnl_inp_draw);
        }
    }
    this->draw_finish();
}

void TInputPanel::set_text(char* param_1)
{
    char* buf = this->input_buffer;
    if (buf != 0) {
        if (param_1 == 0) *buf = 0;
        else __mbscpy(buf, param_1);
        short len = __mbslen(this->input_buffer);
        this->input_len = len;
        this->input_pos = 0;
        this->cur_line = 0;
        this->cur_col = 0;
        if (this->format_type != FormatMultiLine && len > 0) {
            this->input_pos = len;
            this->cur_col = len;
        }
        this->reformat();
    }
}

void TInputPanel::set_text(char**, short)
{
}

char* TInputPanel::get_input_buffer()
{
    return this->input_buffer;
}

int TInputPanel::append_character(long value)
{
    this->input_pos = this->input_len;
    return this->insert_character(value);
}

int TInputPanel::insert_character(long ch)
{
    if (this->input_len >= this->max_len) {
        if (this->overLengthSound != 0) this->overLengthSound->play();
        else MessageBeep(0xFFFFFFFF);
        return 0;
    }

    char* src_buffer;
    char* dst_buffer;
    if (this->input_buffer == this->input_buffer1) {
        src_buffer = this->input_buffer1;
        dst_buffer = this->input_buffer2;
    } else {
        src_buffer = this->input_buffer2;
        dst_buffer = this->input_buffer1;
    }
    this->input_buffer = dst_buffer;
    *dst_buffer = 0;
    if (this->input_pos > 0) {
        _mbsncpy(dst_buffer, src_buffer, this->input_pos);
        src_buffer = (char*)_mbsninc(src_buffer, this->input_pos);
        dst_buffer = (char*)_mbsninc(dst_buffer, this->input_pos);
    }
    _mbsncpy(dst_buffer, &ch, 1);
    dst_buffer = (char*)_mbsinc(dst_buffer);
    _mbsncpy(dst_buffer, src_buffer, this->input_len - this->input_pos + 1);
    this->input_len++;
    this->input_pos++;
    this->reformat();
    this->calc_cur_line_col();
    this->draw_caret = 1;
    this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 655);
    return 1;
}

int TInputPanel::delete_character()
{
    int bVar1;
    uchar* pcVar2;
    uchar* pcVar3;
    uchar* pcVar4;
    int move_back_one;
    if (this->input_pos >= this->input_len) return 0;
    pcVar3 = (uchar*)this->input_buffer1;
    bVar1 = 0;
    if (this->input_buffer == (char*)pcVar3) {
        pcVar4 = pcVar3;
        pcVar3 = (uchar*)this->input_buffer2;
    } else {
        pcVar4 = (uchar*)this->input_buffer2;
    }
    this->input_buffer = (char*)pcVar3;
    *pcVar3 = 0;
    pcVar2 = pcVar4;
    move_back_one = (int)pcVar3;
    if (this->input_pos > 0) {
        _mbsncpy(pcVar3, pcVar4, (int)this->input_pos);
        pcVar2 = (uchar*)_mbsninc(pcVar4, (int)this->input_pos);
        move_back_one = (int)_mbsninc(pcVar3, (int)this->input_pos);
    }
    if (*pcVar2 == '\r') {
        pcVar3 = (uchar*)_mbsinc(pcVar2);
        pcVar4 = (uchar*)1;
        if (*pcVar3 == '\n') {
            pcVar3 = (uchar*)_mbsinc(pcVar3);
            pcVar4 = (uchar*)2;
        }
    } else {
        if ((*pcVar2 == '\n') && (pcVar2 > pcVar4)) {
            pcVar4 = (uchar*)_mbsdec(pcVar4, pcVar2);
            if (*pcVar4 == '\r') {
                move_back_one = (int)_mbsdec(pcVar3, (uchar*)move_back_one);
                pcVar3 = (uchar*)_mbsninc(pcVar4, 2);
                pcVar4 = (uchar*)2;
                bVar1 = 1;
                goto do_copy;
            }
            pcVar3 = (uchar*)_mbsninc(pcVar4, 2);
        } else {
            pcVar3 = (uchar*)_mbsinc(pcVar2);
        }
        pcVar4 = (uchar*)1;
    }
do_copy:
    _mbsncpy((uchar*)move_back_one, pcVar3,
             ((int)this->input_len - (int)this->input_pos) + 1);
    if (bVar1) --this->input_pos;
    this->input_len -= (short)(int)pcVar4;
    this->reformat();
    this->calc_cur_line_col();
    this->draw_caret = 1;
    this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 758);
    return 1;
}

int TInputPanel::backspace_character()
{
    if (this->input_pos > 0) {
        this->input_pos = this->input_pos - 1;
        return this->delete_character();
    }
    return 0;
}

int TInputPanel::paste()
{
    int len;
    HANDLE data_handle;
    char* locked;
    char* old_str;
    char* new_cur;
    char* old_tail;
    char* dst_tail;
    char new_str[0x1000];
    len = 0;
    new_str[0] = 0;
    if (!IsClipboardFormatAvailable(1)) return 0;
    if (!OpenClipboard(this->render_area->Wnd)) return 0;
    data_handle = GetClipboardData(1);
    if (data_handle != 0) {
        locked = (char*)GlobalLock(data_handle);
        if (locked != 0) {
            len = _mbslen(locked);
            if (len > 0xfff) len = 0xfff;
            for (int i = 0; i < 0x1000; ++i) new_str[i] = 0;
            _mbsncpy(new_str, locked, len);
            GlobalUnlock(data_handle);
        }
    }
    CloseClipboard();
    {
        int total_len;
        int max_len;
        total_len = len;
        total_len += this->input_len;
        max_len = this->max_len;
        if (total_len >= max_len) {
            if (this->overLengthSound != 0) {
                this->overLengthSound->play();
                return 0;
            }
            MessageBeep(0xffffffff);
            return 0;
        }
    }
    new_cur = this->input_buffer1;
    if (this->input_buffer == new_cur) {
        old_str = new_cur;
        new_cur = this->input_buffer2;
    } else {
        old_str = this->input_buffer2;
    }
    this->input_buffer = new_cur;
    *new_cur = 0;
    _mbsncpy(new_cur, old_str, (int)this->input_pos);
    old_tail = (char*)_mbsninc(old_str, (int)this->input_pos);
    dst_tail = new_cur;
    dst_tail = (char*)_mbsninc(dst_tail, (int)this->input_pos);
    _mbsncpy(dst_tail, new_str, len);
    dst_tail = (char*)_mbsninc(dst_tail, len);
    _mbsncpy(dst_tail, old_tail, ((int)this->input_len - (int)this->input_pos) + 1);
    this->input_len += (short)len;
    this->input_pos += (short)len;
    this->reformat();
    this->calc_cur_line_col();
    this->draw_caret = 1;
    this->caret_last_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 866);
    return 1;
}

void TInputPanel::reformat()
{
    short top = this->top_line;
    short cur = this->cur_line;
    TTextPanel::set_text(this->input_buffer);
    short n = this->num_lines;
    if (cur >= n) cur = n - 1;
    this->cur_line = cur;
    if (top >= n) this->top_line = n - 1;
    this->scroll(1, (uchar)top, 1);
    this->set_redraw(1);
}

void TInputPanel::calc_input_pos()
{
    TextNode* node;
    short i;
    short len;
    node = this->list;
    this->input_pos = 0;
    for (i = 0; node != 0 && i < this->cur_line; i++) {
        len = __mbslen(node->text);
        this->input_pos = this->input_pos + len;
        node = node->next_node;
    }
    short col = this->cur_col;
    this->input_pos = this->input_pos + col;
    short pos = this->input_pos;
    if (col > 0 && pos > 0) {
        if (this->input_buffer[pos - 1] == '\n') {
            this->input_pos = pos - 1;
            this->cur_col = col - 1;
        }
    }
    short col2 = this->cur_col;
    if (col2 > 0) {
        short pos2 = this->input_pos;
        if (pos2 > 0 && this->input_buffer[pos2 - 1] == '\r') {
            this->input_pos = pos2 - 1;
            this->cur_col = col2 - 1;
        }
    }
    if (this->cur_line < this->top_line) {
        do { this->scroll(3, 1, 1); } while (this->cur_line < this->top_line);
    }
    if (this->cur_line > this->bot_line) {
        do { this->scroll(2, 1, 1); } while (this->cur_line > this->bot_line);
    }
}

void TInputPanel::calc_cur_line_col()
{
    TextNode* node;
    short offset;
    short len;
    node = this->list;
    this->cur_line = 0;
    this->cur_col = 0;
    offset = 0;
    while (node != 0 && this->cur_line != this->num_lines - 1) {
        len = __mbslen(node->text);
        if (offset + len > this->input_pos) break;
        offset += len;
        this->cur_line++;
        node = node->next_node;
    }
    this->cur_col = this->input_pos - offset;
    if (this->cur_col > 0 && this->input_pos > 0 && this->input_buffer[this->input_pos - 1] == '\n') {
        this->input_pos--;
        this->cur_col--;
    }
    if (this->cur_col > 0 && this->input_pos > 0 && this->input_buffer[this->input_pos - 1] == '\r') {
        this->input_pos--;
        this->cur_col--;
    }
    if (this->cur_line < this->top_line) {
        do { this->scroll(3, 1, 1); } while (this->cur_line < this->top_line);
    }
    if (this->cur_line > this->bot_line) {
        do { this->scroll(2, 1, 1); } while (this->cur_line > this->bot_line);
    }
}

int TInputPanel::is_blank()
{
    char* p = this->currentLine();
    if (p == 0) goto blank;
    if (*p == 0) goto blank;
    while (1) {
        if (*p == '\0') goto blank;
        if (__ismbcspace((unsigned char)*p) == 0) return 0;
        p = (char*)_mbsinc(p);
    }
blank:
    return 1;
}

char* TInputPanel::get_trimmed_str(char* dst, int maxlen)
{
    char temp_str[256];
    uchar* base;
    uchar* p;
    uchar* cur;
    memset(temp_str, 0, sizeof(temp_str));
    strcpy(temp_str, this->currentLine());
    memset(dst, 0, maxlen);
    base = (uchar*)dst;
    p = base;
    cur = (uchar*)temp_str;
    while (__ismbcspace(*cur & 0xFF)) cur = (uchar*)_mbsinc(cur);
    while (*cur) {
        _mbsncpy(p, cur, 1);
        p = (uchar*)_mbsinc(p);
        cur = (uchar*)_mbsinc(cur);
    }
    while (1) {
        *p = 0;
        if (p == base) break;
        p = (uchar*)_mbsdec(base, p);
        if (__ismbcspace(*p)) continue;
        break;
    }
    return (char*)base;
}
