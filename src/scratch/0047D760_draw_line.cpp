// VA: 0047D760 TTextPanel::draw_line
// Pnl_txt.cpp:1139-1229
//
// Canonical ownership: TTextPanel supplies the text, alignment, style, and
// second-column state.  The line rectangle uses its left field as the panel
// receiver and passes its top field to calc_line_pos, as shown by the binary.
// The original style switch keeps the three TextOutA tails shared.
//
// Attempt log:
// - Replaced the field-only scaffold with a typed Pnl_txt reconstruction.
//   The source now models get_text/get_text2, calc_line_pos, the counted text
//   lengths, the two clip regions, and the three text styles.
// - An ordered if/else style probe improved call alignment but worsened the
//   strict diff.  The switch is the better source shape for the dec/jump CFG.
// - Local declaration and short line-number variants changed register and
//   frame shape without improving positional bytes.  Restored the clean form.
// - The Windows SDK RECT/GDI surface was an emitted-code duplicate of the
//   local import surface, but remains the period-plausible living context.
// - A named text_y local improved the strict diff to 481 bytes and preserved
//   the natural coordinate model.  Pointer initialization was a duplicate.
// - Left in scratch: original frame 0x20 versus rebuilt 0x1C, three missing
//   indirect call sites from VC5 tail merging, and early register coloring.

#include <windows.h>

class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();

    char gap_04[0x1C];
    TDrawArea* render_area;              // +0x20
    char gap_24[0x64];
    void* clip_rgn;                      // +0x88
    char gap_8C[0x68];                   // through +0xF3
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x20];                   // through +0x113
    int horz_align;                      // +0x114
    char gap_118[0x04];
    int text_style;                      // +0x11C
    char gap_120[0x40];
    long second_column_pos;              // +0x160
    char gap_164[0x18];
    void* clip_rgn2;                     // +0x17C

    char* get_text(long line);
    char* get_text2(long line);
    void calc_line_pos(void* dc, short line_index, short line,
                       RECT* rect, long* out);
    void draw_line(void* dc, short line_index, short line,
                   unsigned long color1, unsigned long color2);
};

void TTextPanel::draw_line(void* dc, short line_index, short line,
                           unsigned long color1, unsigned long color2)
{
    char* text;
    char* text2 = 0;
    short text_len = 0;
    short text2_len = 0;
    RECT line_rect;

    line_rect.left = (long)this;
    text = this->get_text((long)line);
    text2 = this->get_text2((long)line);

    if (text == 0) {
        if (text2 == 0) {
            return;
        }
    } else {
        text_len = (short)strlen(text);
    }

    if (text2 != 0) {
        text2_len = (short)strlen(text2);
    }

    this->calc_line_pos(dc, line_index, line,
                        (RECT*)&line_rect.top, 0);

    long text_x = line_rect.top;
    if (this->horz_align != 0 && this->horz_align != 6) {
        text_x += 5;
    }
    long second_text_x = this->second_column_pos + text_x;
    long text_y = line_rect.right;

    if (this->clip_rgn2 != 0) {
        SelectClipRgn(dc, this->clip_rgn2);
    }

    switch (this->text_style) {
    case 0:
        SetTextColor(dc, color1);
        break;
    case 1:
        SetTextColor(dc, color1);
        if (text != 0) {
            TextOutA(dc, text_x + 1, text_y - 1,
                     text, (int)text_len);
        }
        SetTextColor(dc, color2);
        break;
    case 2:
        SetTextColor(dc, color2);
        if (text != 0) {
            TextOutA(dc, text_x + 1, text_y - 1,
                     text, (int)text_len);
        }
        SetTextColor(dc, color1);
        break;
    default:
        break;
    }

    if (text != 0) {
        TextOutA(dc, text_x, text_y, text, (int)text_len);
    }

    if (text2 == 0) {
        return;
    }

    TTextPanel* panel = (TTextPanel*)line_rect.left;
    if (panel->clip_rgn2 != 0) {
        SelectClipRgn(dc, panel->clip_rgn);
    }

    switch (panel->text_style) {
    case 0:
        SetTextColor(dc, color1);
        TextOutA(dc, second_text_x, text_y,
                 text2, (int)text2_len);
        return;
    case 1:
        SetTextColor(dc, color1);
        TextOutA(dc, second_text_x + 1, text_y - 1,
                 text2, (int)text2_len);
        SetTextColor(dc, color2);
        TextOutA(dc, second_text_x, text_y,
                 text2, (int)text2_len);
        return;
    case 2:
        SetTextColor(dc, color2);
        TextOutA(dc, second_text_x + 1, text_y - 1,
                 text2, (int)text2_len);
        SetTextColor(dc, color1);
        TextOutA(dc, second_text_x, text_y,
                 text2, (int)text2_len);
        return;
    default:
        return;
    }
}
