// VA: 00493160 TScrollTextPanel::draw_scrolled_line (692 bytes)
// PDB source: scr_cred.cpp lines 547-644
//
// Attempt log:
// initial reconstruction used DrawTextA/SetBkMode and a flat approximate panel;
// the binary actually calls TextOutA and uses the two clip-region fields.
// Rebuilt the source around the proven TPanel/TTextPanel/TScrollTextPanel
// ownership and the old source's switch-shaped three-mode rendering.
// independent text-null checks restored the original redundant branch and
// reached the best checked source shape (692-byte rebuild, diff 656).
// direct saved-self reload, declaration order, Windows ABI spellings, and
// header-context variants were either unchanged or worsened frame/register
// topology. Main-agent audit restored direct this ownership and an ordinary
// RECT output instead of retaining the diagnostic overlapping stack window.
// The normalized source validates at 685 bytes with 614 differing bytes,
// improving on the diagnostic overlap's 656-byte diff despite losing exact
// size. Remaining drift is primarily VC5 register/stack-slot coloring.
// - using the short line_index parameter directly, without a long line-number
//   local, kept the natural ABI and improved the resync diff to 614 bytes;
//   prologue and size stayed unchanged, so this form is retained.
// - an explicit typed self alias was codegen-neutral and was removed.
// - using RECT.left as the computed x local worsened the frame and shape;
//   the separate text_x local is restored. Primary-text declaration reorder
//   was also codegen-neutral.
// - a natural short or long line-number local was codegen-neutral; direct
//   short parameter use remains the clean source form.
// - adding the separate binary-looking secondary length local changed only
//   edit alignment and was rolled back as duplicate emitted code.
// - the RECT.left self-overlap form reached the original 692-byte size but
//   worsened the positional diff to 656; it is a decompiler artifact here.
// - the original still differs at structural stack coloring: it preserves a
//   zero store and reuses incoming short-parameter homes for coordinates.
// Current worker probes (2026-08-17):
// - Rechecked natural declaration orders for primary/secondary text locals,
//   RECT placement, and coordinate locals. These were emitted-code duplicates.
// - Removing the y local expanded the frame mismatch and deleted one call.
//   Restored the named y local.
// - A typed RECT-member output window did not compile without an unsupported
//   pointer cast. The prior overlapping RECT experiment remains rejected.
// - SDK-only GDI declarations, a primary text-length initializer, combined
//   null guard, line-count promotion, and a long line-number local did not
//   improve the natural result. The SDK and guard forms were duplicates.
// - Replacing either style switch with an if/else chain reduced structural
//   quality or call alignment. The binary switch lowering remains canonical.
// - Twelve meaningful checks found no policy-valid exact source. Clean source
//   remains 685 bytes versus 692, with 23 ordered calls and diff 614.
// - A same-TU draw_line donor proves a receiver-plus-RECT local as a natural
//   source shape. Applying that aggregate here reproduced the binary receiver
//   store and late receiver lifetime, but the donor-like form worsened the
//   strict diff to 645 and lost exact blocks. A clean-order aggregate reached
//   683 bytes and diff 611, but its CFG shape was worse; it was reverted.
// - A short or long copied line index, a branch-local receiver alias, direct
//   receiver access, and extra length initialization did not improve the
//   reduced natural source. The clean RECT form remains pinned for audit.
// - Full scr_cred context is not valid for this owner yet. With the exact PDB
//   prefix and /GX, VC5 merges one final TextOutA tail. The grouped result is
//   666 bytes with 22 calls. The standalone clean source stays at 685 bytes,
//   preserves all 23 ordered calls, and remains the authoritative attempt.

#include <string.h>
#include "../../include/scr_cred_context.h"

#if 0
typedef unsigned char uchar;
typedef unsigned long ulong;

extern "C" __declspec(dllimport) int __stdcall SelectClipRgn(HDC hdc, HRGN region);
extern "C" __declspec(dllimport) COLORREF __stdcall SetTextColor(HDC hdc, COLORREF color);
extern "C" __declspec(dllimport) BOOL __stdcall TextOutA(HDC hdc, int x, int y,
                                                           LPCSTR text, int count);

class TPanel {
public:
    virtual ~TPanel();

    void* previous_panel;          // +0x04
    void* previous_modal;          // +0x08
    long pnl_x;                    // +0x0c
    long pnl_y;                    // +0x10
    long pnl_wid;                  // +0x14
    long pnl_hgt;                  // +0x18
    char* panel_name;              // +0x1c
    void* render_area;             // +0x20
    char gap_24[0x64];
    void* clip_rgn;                // +0x88
    char gap_8c[0x68];
};

class TTextPanel : public TPanel {
public:
    char gap_f4[4];
    short line_count;              // +0xf8
    char gap_fa[0x12];
    long line_height;              // +0x10c
    char gap_110[4];
    long align;                    // +0x114
    char gap_118[4];
    long draw_mode;                // +0x11c
    char gap_120[0x40];
    long line_offset;              // +0x160
    char gap_164[0x18];
    void* clip_region;             // +0x17c
    char gap_180[8];

    char* get_text(long index);
    char* get_text2(long index);
    void calc_line_pos(void* hdc, short draw_index, short line_index,
                       RECT* line_rect, long* offset);
};

class TScrollTextPanel : public TTextPanel {
public:
    long scroll;                   // +0x188
    long last_time;                // +0x18c
    long scroll_speed;             // +0x190
    long done;                     // +0x194

    void draw_scrolled_line(void* hdc, short draw_index, short line_index,
                            ulong color1, ulong color2);
};
#endif

void TScrollTextPanel::draw_scrolled_line(void* hdc, short draw_index,
                                          short line_index, ulong color1,
                                          ulong color2) {
    char* text;
    short text_len;
    char* temp_text2;
    short text2_length;
    RECT line_rect;
    long text_x;
    long text_y;
    temp_text2 = 0;
    text2_length = 0;
    text = this->get_text((long)line_index);
    temp_text2 = this->get_text2((long)line_index);
    if (text == 0) {
        if (temp_text2 == 0) return;
    }
    if (text != 0) {
        text_len = (short)strlen(text);
    }
    if (temp_text2 != 0) {
        text2_length = (short)strlen(temp_text2);
    }

    this->calc_line_pos(hdc, draw_index, line_index, &line_rect, 0);

    text_x = line_rect.left;
    if ((this->align != 0) && (this->align != 6)) {
        text_x += 5;
    }
    text_x = this->line_offset + text_x;
    text_y = this->pnl_hgt - this->scroll + line_rect.top;
    if ((line_index == (short)this->line_count - 1) &&
        (this->line_height + text_y < this->pnl_y)) {
        this->done = 1;
    }

    if (this->clip_region != 0) {
        SelectClipRgn(hdc, this->clip_region);
    }

    switch (this->draw_mode) {
    case 0:
        SetTextColor(hdc, color1);
        if (text != 0) {
            TextOutA(hdc, text_x, text_y, text, (int)text_len);
        }
        break;
    case 1:
        SetTextColor(hdc, color1);
        if (text != 0) {
            TextOutA(hdc, text_x - 1, text_y + 1, text, (int)text_len);
        }
        SetTextColor(hdc, color2);
        if (text != 0) {
            TextOutA(hdc, text_x, text_y, text, (int)text_len);
        }
        break;
    case 2:
        SetTextColor(hdc, color2);
        if (text != 0) {
            TextOutA(hdc, text_x - 1, text_y + 1, text, (int)text_len);
        }
        SetTextColor(hdc, color1);
        if (text != 0) {
            TextOutA(hdc, text_x, text_y, text, (int)text_len);
        }
        break;
    default:
        break;
    }

    if (temp_text2 == 0) return;

    if (this->clip_region != 0) {
        SelectClipRgn(hdc, this->clip_rgn);
    }

    switch (this->draw_mode) {
    case 0:
        SetTextColor(hdc, color1);
        TextOutA(hdc, text_x, text_y, temp_text2, (int)text2_length);
        return;
    case 1:
        SetTextColor(hdc, color1);
        TextOutA(hdc, text_x - 1, text_y + 1, temp_text2, (int)text2_length);
        SetTextColor(hdc, color2);
        TextOutA(hdc, text_x, text_y, temp_text2, (int)text2_length);
        return;
    case 2:
        SetTextColor(hdc, color2);
        TextOutA(hdc, text_x - 1, text_y + 1, temp_text2, (int)text2_length);
        SetTextColor(hdc, color1);
        TextOutA(hdc, text_x, text_y, temp_text2, (int)text2_length);
        return;
    default:
        return;
    }
}
