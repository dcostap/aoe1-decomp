// TListPanel::draw - draw items in the visible range
//
// The inherited panel fields and the TTextPanel line/color fields are kept
// named here so the proven offsets remain part of the source model.
//
// Attempt log: canonical inherited offsets, the imported GDI surface, the
// external draw string, the short draw_line ABI, the focus/capture predicate,
// and the counted visible-line loop produce the exact 303-byte owner.
// The complete Pnl_lst wrapper confirms all 13 ordered calls and the original
// panel inheritance. Keep the typed drawing ownership and loop bounds.

#ifndef AOE1_PNL_LST_CONTEXT_H
extern "C" {
__declspec(dllimport) int __stdcall SelectClipRgn(void* hdc, void* hrgn);
__declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* object);
__declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode);
}

extern char s_pnl_lst__draw[];

class TDrawArea {
public:
    void* GetDc(char* name);
    void ReleaseDc(char* name);
};

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)

class TPanel {
public:
    VPAD8(v0)
    VPAD2(v8)
    virtual void draw_setup(int clear);
    virtual void draw_finish();
    virtual void draw();

    char gap_04[0x08];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char gap_1C[0x04];
    TDrawArea* render_area;       // +0x20
    char gap_24[0x14];
    int need_redraw;              // +0x38
    char gap_3C[0x2C];
    int mouse_captured;           // +0x68
    int active;                   // +0x6C
    int visible;                  // +0x70
    int tab_stop;                 // +0x74
    int have_focus;               // +0x78
    char gap_7C[0x08];
    int just_drawn;               // +0x84
    void* clip_rgn;               // +0x88
    char gap_8C[0x68];
};

class TTextPanel : public TPanel {
public:
    void* list;                   // +0xF4
    short num_lines;              // +0xF8
    short draw_lines;             // +0xFA
    short top_line;               // +0xFC
    short bot_line;               // +0xFE
    short cur_line;               // +0x100
    short cur_col;                // +0x102
    void* font;                   // +0x104
    long font_wid;                // +0x108
    long font_hgt;                // +0x10C
    int vert_align;               // +0x110
    int horz_align;               // +0x114
    int word_wrap;                // +0x118
    int text_style;               // +0x11C
    unsigned long text_color1;    // +0x120
    unsigned long text_color2;    // +0x124
    unsigned long highlightTextColor1; // +0x128
    unsigned long highlightTextColor2; // +0x12C
    void* scbar_panel;            // +0x130
    int auto_scbar;               // +0x134
    short fixed_len;              // +0x138
    short gap_13A;
    long text_wid;                // +0x13C
    long text_hgt;                // +0x140
    void* back_pic;               // +0x144
    short back_pic_wid;           // +0x148
    short back_pic_hgt;           // +0x14A
    int fill_back;                // +0x14C
    unsigned char back_color;      // +0x150
    char gap_151[3];
    int outline;                  // +0x154
    unsigned char outline_color;  // +0x158
    char gap_159[3];
    int sorted;                   // +0x15C
    long second_column_pos;       // +0x160
    long full_width;              // +0x164
    long scbar_width;             // +0x168
    int scbar_active;             // +0x16C
    int bevel_type;               // +0x170
    unsigned char bevel_color1;   // +0x174
    unsigned char bevel_color2;   // +0x175
    unsigned char bevel_color3;   // +0x176
    unsigned char bevel_color4;   // +0x177
    unsigned char bevel_color5;   // +0x178
    unsigned char bevel_color6;   // +0x179
    char gap_17A[2];
    void* clip_rgn2;              // +0x17C
    int border_size;              // +0x180
    int spacer_size;              // +0x184

    void draw_background();
    void draw_line(void* dc, short line_index, short line,
                   unsigned long value1, unsigned long value2);
    void draw_border();
};

class TListPanel : public TTextPanel {
public:
    int auto_track;               // +0x188
    unsigned long mouse_scroll_last_time; // +0x18C
    unsigned long mouse_scroll_interval;  // +0x190
    int mouse_scroll_up;           // +0x194
    int mouse_scroll_down;         // +0x198
    int drawHighlightBar;          // +0x19C

    virtual void draw();
    void draw_highlight_bar();
};
#endif

void TListPanel::draw()
{
    this->need_redraw = 0;
    if (this->render_area == 0 || this->visible == 0 || this->active == 0) {
        return;
    }

    this->draw_background();
    this->draw_setup(0);

    void* dc = this->render_area->GetDc(s_pnl_lst__draw);
    if (dc != 0) {
        SelectClipRgn(dc, this->clip_rgn);
        void* old_font = SelectObject(dc, this->font);
        SetBkMode(dc, 1);

        for (short line = this->top_line, line_index = 0;
             line <= this->bot_line; ++line, ++line_index) {
            if (this->drawHighlightBar != 0 &&
                (this->have_focus != 0 || this->mouse_captured != 0) &&
                line_index + this->top_line == this->cur_line) {
                this->draw_line(dc, line_index, line,
                                this->highlightTextColor1,
                                this->highlightTextColor2);
            } else {
                this->draw_line(dc, line_index, line,
                                this->text_color1, this->text_color2);
            }
        }

        SelectObject(dc, old_font);
        SelectClipRgn(dc, 0);
        this->render_area->ReleaseDc(s_pnl_lst__draw);
    }

    this->draw_border();
    this->draw_highlight_bar();
    this->draw_finish();
}
