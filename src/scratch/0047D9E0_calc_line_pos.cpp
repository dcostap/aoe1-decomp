// VA: 0047D9E0 TTextPanel::calc_line_pos (555 bytes)
// Pnl_txt.cpp:1235-1346
//
// Canonical reconstruction from the original call/field evidence:
//   get_text(current) supplies the line; col_offset is the cursor-prefix
//   width, while text_size.cx is subsequently reused for the whole-line width.
//   The four alignment values are the period TTextPanel enum values:
//   center=0, left=1, right=2, top=3, bottom=4, horizontal-scroll=5,
//   wordwrap=6.
//
// Attempt log:
// - Baseline had the correct frame, six calls, and formulas but an inverted
//   guard/enum CFG.  Inverting the live-text guard, preserving the original
//   signed compare, and using switches for horizontal/vertical alignment
//   recovered the original shared tails.
// - A shared short byte-length local and, importantly, measuring the original
//   text with the copied-prefix byte count recovered exact size, all calls,
//   and the original control flow.  Initializing the null-text width recovered
//   all 192 instructions and left one operand-order byte in the final RECT
//   right-edge LEA.  Bottom-alignment term and right-edge expression variants
//   were duplicate; source is left typed and period-plausible.

struct SIZE;

extern "C" short __cdecl __mbslen(const char* str);
extern "C" unsigned char* __cdecl __mbsncpy(unsigned char* dst,
                                               const unsigned char* src,
                                               int count);
extern "C" int __cdecl strlen(const char* str);
extern "C" void* __cdecl memset(void* dst, int value, unsigned int count);
extern "C" __declspec(dllimport) int __stdcall GetTextExtentPoint32A(
    void* dc, const char* text, int count, SIZE* size);

struct RECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct SIZE {
    long cx;
    long cy;
};

class TPanel {
public:
    char gap_00[0x0C];
    long pnl_x;                         // +0x0C
    long pnl_y;                         // +0x10
    long pnl_wid;                       // +0x14
    long pnl_hgt;                       // +0x18
    char gap_1C[0xD8];                  // to +0xF4
};

class TTextPanel : public TPanel {
public:
    char* list;                         // +0xF4
    short num_lines;                    // +0xF8
    short draw_lines;                   // +0xFA
    short top_line;                     // +0xFC
    short bot_line;                     // +0xFE
    short cur_line;                     // +0x100
    short cur_col;                      // +0x102
    void* font;                         // +0x104
    char gap_108[0x08];                 // to +0x110
    long vert_align;                    // +0x110
    long horz_align;                    // +0x114
    long word_wrap;                     // +0x118
    char gap_11C[0x24];                 // to +0x140
    long text_hgt;                      // +0x140
    char gap_144[0x3C];                 // to +0x180
    long border_size;                   // +0x180
    long spacer_size;                   // +0x184

    char* get_text(long index);
    void calc_line_pos(void* dc, short line, short current,
                       RECT* rect, long* out);
};

void TTextPanel::calc_line_pos(void* dc, short line, short current,
                               RECT* rect, long* out)
{
    char* text = this->get_text((long)current);
    long col_offset;
    SIZE text_size;
    char temp_text2[256];
    short byte_len;

    if (text != 0) {
        if (this->cur_col == 0) {
            col_offset = 0;
        } else {
            short text_len = __mbslen(text);
            if (this->cur_col > text_len) {
                byte_len = (short)strlen(text);
                GetTextExtentPoint32A(dc, text, byte_len, &text_size);
            } else {
                memset(temp_text2, 0, 0x100);
                __mbsncpy((unsigned char*)temp_text2,
                          (const unsigned char*)text,
                          (unsigned int)this->cur_col);
                byte_len = (short)strlen(temp_text2);
                GetTextExtentPoint32A(dc, text, byte_len, &text_size);
            }
            col_offset = text_size.cx;
        }

        // This call is present in the original line-measurement path even
        // though the following byte-length expression supplies the count.
        __mbslen(text);
        byte_len = (short)strlen(text);
        GetTextExtentPoint32A(dc, text, byte_len, &text_size);
    } else {
        col_offset = 0;
        text_size.cx = 0;
    }

    long horizontal = this->horz_align;
    if (horizontal != 0 && horizontal != 6) {
        col_offset += 5;
    }

    long x;
    switch (horizontal) {
    case 1:
        x = this->pnl_x + this->border_size;
        break;
    case 2:
        x = this->pnl_x + this->pnl_wid - this->border_size
            - text_size.cx - 7;
        break;
    case 5:
        x = this->pnl_x + this->border_size;
        if (col_offset + 1 >= this->pnl_wid) {
            x += this->pnl_wid - col_offset - 2;
        }
        break;
    default:
        x = this->pnl_x + this->pnl_wid / 2 - text_size.cx / 2;
        break;
    }

    long row_size = this->spacer_size;
    if (row_size == 0) {
        row_size = this->text_hgt;
    } else {
        row_size = this->text_hgt + row_size * 2 - 1;
    }

    long y;
    switch (this->vert_align) {
    case 3:
        y = line * row_size + this->pnl_y + this->border_size
            + this->spacer_size;
        break;
    case 4:
        y = this->pnl_y - (this->num_lines - line) * row_size;
        y += this->pnl_hgt - this->border_size - this->spacer_size - 1;
        break;
    default:
        y = line * row_size - (this->num_lines * row_size) / 2
            + this->pnl_y + this->pnl_hgt / 2;
        break;
    }

    rect->left = x;
    rect->top = y;
    rect->right = x - 1 + text_size.cx;
    rect->bottom = y + this->text_hgt;
    if (out != 0) {
        *out = col_offset;
    }
}
