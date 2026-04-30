// TListPanel::draw - draw items in visible range

typedef void* HDC;

class TDrawArea {
public:
    HDC GetDc(char* name);
    void ReleaseDc(char* name);
    unsigned char* Lock(char* name, int param_2);
    void Unlock(char* name);
};

class TPanel {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20(long a);
    virtual void v24();
    virtual void v28(int a);
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    // extra vtable slots up to 0xB4...
};

class TTextPanel : public TPanel {
public:
    void draw_background();
    void draw_border();
    void draw_line(HDC dc, short line, int idx, int bmp1, int bmp2);
    void calc_draw_info(int param_1);
};

struct TListPanel : public TTextPanel {
    char gap_00[0x20];
    TDrawArea* draw_area;             // 0x20
    char gap_24[0x14];
    int clip_enabled;                 // 0x38
    char gap_3C[0x2C];
    int bmp_font;                     // 0x68
    int bmp_font2;                    // 0x6C
    int bmp_font3;                    // 0x70
    char gap_74[0x14];
    int clip_region;                  // 0x88
    char gap_8C[0x6C];
    short num_lines;                  // 0xF8
    short draw_lines;                 // 0xFA
    short top_line;                   // 0xFC
    short bot_line;                   // 0xFE
    short cur_line;                   // 0x100
    char gap_102[0x02];
    int line_font;                    // 0x104
    char gap_108[0x18];
    int line_spacing;                 // 0x120
    int line_height;                  // 0x124
    int highlight_bmp1;               // 0x128
    int highlight_bmp2;               // 0x12C
    char gap_130[0x2C];
    short num_lines2;                 // 0x15C (padding)
    char pad[0x20];
    int scroll_bar_width;             // 0x180
    int bevel_style;                  // 0x184
    char gap_188[0x10];
    int some_field;                   // 0x198
    int draw_highlight_bar_enabled;   // 0x19C

    void draw_highlight_bar();
    void draw();
};

extern "C" int __stdcall SelectClipRgn(HDC dc, int region);
extern "C" int __stdcall SelectObject(HDC dc, int obj);
extern "C" int __stdcall SetBkMode(HDC dc, int mode);

void TListPanel::draw() {
    this->clip_enabled = 0;
    if (this->draw_area == 0 || this->bmp_font3 == 0 || this->bmp_font2 == 0)
        return;

    this->draw_background();
    this->v28(0);
    HDC dc = this->draw_area->GetDc("pnl_lst::draw");

    if (dc != 0) {
        SelectClipRgn(dc, this->clip_region);
        int old_font = SelectObject(dc, this->line_font);
        SetBkMode(dc, 1);

        for (short line = this->top_line; line <= this->bot_line; line++) {
            int idx = line - this->top_line;
            int bmp1, bmp2;
            if (this->draw_highlight_bar_enabled != 0 && (this->bmp_font != 0 || this->bmp_font2 != 0) && idx + this->top_line == this->cur_line) {
                bmp1 = this->highlight_bmp1;
                bmp2 = this->highlight_bmp2;
            } else {
                bmp1 = this->line_spacing;
                bmp2 = this->line_height;
            }
            this->draw_line(dc, line, idx, bmp1, bmp2);
        }

        SelectObject(dc, old_font);
        SelectClipRgn(dc, 0);
        this->draw_area->ReleaseDc("pnl_lst::draw");
    }

    this->draw_border();
    this->draw_highlight_bar();
    this->v2C();
}
