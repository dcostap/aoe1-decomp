// TListPanel::draw_highlight_bar — draw the current-line highlight frame
// VA: 00478CD0, Pnl_lst.cpp:515-572
//
// Canonical ownership follows the exact Pnl_txt.cpp/Drawarea.cpp donors:
// TPanel owns the panel rectangle and render area, TTextPanel owns line,
// bevel, and spacing fields, and TDrawArea owns the lock/draw/unlock surface.
// The common Unlock call intentionally remains outside the DC/Lock guards.
//
// Attempt log:
// - replaced the raw-address/__fastcall scaffold with the typed same-TU
//   TDrawArea calls, calc_line_pos ABI, common Unlock tail, and period switch;
//   direct member rereads for cur_line removed the extra callee-save.
// - kept separate switch arms in the PDB handler order 0/1,5,6,7,2,3,4;
//   right-to-left push evidence requires reverse colors for 5-7 and ascending
//   colors for 2-4. This restored 491 bytes, all 11 calls, and the CFG.
// - named x/width/border locals in field-load order reduced the remaining drift
//   to one SIB byte at +00B6: oracle LEA [ebx+edx], rebuilt [edx+ebx].
// - reversed/split bottom-term and top/bottom declaration probes were either
//   codegen duplicates or broad tail-merge regressions; restored this natural
//   best source. Left in scratch: one localized address-term encoding byte.
// - initialized bottom from spacer_size and compound-added rect.bottom; this
//   was a codegen duplicate, so restored the direct typed addition.
// - swapped bottom's natural operand order to spacer_size + rect.bottom;
//   emitted code was unchanged, so restored the clean source.

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

extern char s_pnl_lst__draw_highlight_bar[];

class TDrawArea {
public:
    void* GetDc(char* name);
    void ReleaseDc(char* name);
    unsigned char* Lock(char* name, int mode);
    void Unlock(char* name);

    void DrawRect(long x1, long y1, long x2, long y2,
                  unsigned char color);
    void DrawBevel(long x1, long y1, long x2, long y2,
                   unsigned char c1, unsigned char c2);
    void DrawBevel2(long x1, long y1, long x2, long y2,
                    unsigned char c1, unsigned char c2,
                    unsigned char c3, unsigned char c4);
    void DrawBevel3(long x1, long y1, long x2, long y2,
                    unsigned char c1, unsigned char c2,
                    unsigned char c3, unsigned char c4,
                    unsigned char c5, unsigned char c6);
};

class TPanel {
public:
    virtual ~TPanel();

    char gap_04[0x08];
    long pnl_x;                    // +0x0C
    long pnl_y;                    // +0x10
    long pnl_wid;                  // +0x14
    long pnl_hgt;                  // +0x18
    char gap_1C[0x04];
    TDrawArea* render_area;        // +0x20
    char gap_24[0xD0];              // through +0xF3
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x08];
    short top_line;                 // +0xFC
    short bot_line;                 // +0xFE
    short cur_line;                 // +0x100
    char gap_102[0x6E];             // through +0x16F
    int bevel_type;                 // +0x170
    unsigned char bevel_color1;     // +0x174
    unsigned char bevel_color2;     // +0x175
    unsigned char bevel_color3;     // +0x176
    unsigned char bevel_color4;     // +0x177
    unsigned char bevel_color5;     // +0x178
    unsigned char bevel_color6;     // +0x179
    char gap_17A[0x06];              // through +0x17F
    long border_size;                // +0x180
    long spacer_size;                // +0x184

    void calc_line_pos(void* dc, short line, short current,
                       tagRECT* rect, long* out);
};

class TListPanel : public TTextPanel {
public:
    char gap_188[0x14];              // through +0x19B
    int drawHighlightBar;            // +0x19C

    void draw_highlight_bar();
};

void TListPanel::draw_highlight_bar()
{
    if (this->drawHighlightBar == 0)
        return;

    if (this->cur_line < this->top_line)
        return;
    if (this->cur_line > this->bot_line)
        return;

    void* dc = this->render_area->GetDc(s_pnl_lst__draw_highlight_bar);
    if (dc != 0) {
        tagRECT rect;
        this->calc_line_pos(dc, this->cur_line - this->top_line, this->cur_line,
                            &rect, 0);
        this->render_area->ReleaseDc(s_pnl_lst__draw_highlight_bar);

        if (this->render_area->Lock(s_pnl_lst__draw_highlight_bar, 1) != 0) {
            long x = this->pnl_x;
            long width = this->pnl_wid;
            long border = this->border_size;
            long left = x + border;
            long right = x + width - border - 1;
            long top = rect.top - this->spacer_size;
            long bottom = rect.bottom + this->spacer_size;

            switch (this->bevel_type) {
            case 0:
            case 1:
                this->render_area->DrawRect(left, top, right, bottom, 0xFF);
                break;
            case 5:
                this->render_area->DrawBevel(
                    left, top, right, bottom,
                    this->bevel_color6, this->bevel_color1);
                break;
            case 6:
                this->render_area->DrawBevel2(
                    left, top, right, bottom,
                    this->bevel_color6, this->bevel_color5,
                    this->bevel_color2, this->bevel_color1);
                break;
            case 7:
                this->render_area->DrawBevel3(
                    left, top, right, bottom,
                    this->bevel_color6, this->bevel_color5,
                    this->bevel_color4, this->bevel_color3,
                    this->bevel_color2, this->bevel_color1);
                break;
            case 2:
                this->render_area->DrawBevel(
                    left, top, right, bottom,
                    this->bevel_color1, this->bevel_color6);
                break;
            case 3:
                this->render_area->DrawBevel2(
                    left, top, right, bottom,
                    this->bevel_color1, this->bevel_color2,
                    this->bevel_color5, this->bevel_color6);
                break;
            case 4:
                this->render_area->DrawBevel3(
                    left, top, right, bottom,
                    this->bevel_color1, this->bevel_color2,
                    this->bevel_color3, this->bevel_color4,
                    this->bevel_color5, this->bevel_color6);
                break;
            }
        }
    }

    this->render_area->Unlock(s_pnl_lst__draw_highlight_bar);
}
