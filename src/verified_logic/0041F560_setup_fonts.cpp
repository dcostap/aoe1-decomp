// VA: 0041F560 RGE_Base_Game::setup_fonts (410 B)
// PDB source: basegame.cpp:2682-2732
//
// Attempt log:
// - Replaced the packet scaffold with the period typed RGE_Base_Game,
//   RGE_Font, TDrawArea, TEXTMETRICA, and member-call surfaces.  The loop
//   keeps the original short index and switch on tmHeight; the binary also
//   proves the API receives the address of the ascent field.
// - Corrected draw_area/font_num/fonts to the proven +0x4C/+0x1E0/+0x1E4
//   ownership; this removed the broad displacement drift.
// - A natural RGE_Font element-pointer local shortened the body but did not
//   reproduce the oracle's reused scaled offset; rolled back.
// - A named int font_index assigned from tm.tmHeight restored the oracle's
//   one-time index scaling and exact 410-byte body shape (best diff 50).
// - Restored the base-game virtual slot surface, reordered locals, added the
//   donor stdlib context, and tested an int old SelectObject handle; all were
//   codegen duplicates.  An 8-variant declaration/scope lab likewise found
//   only the same two codegen groups.
// - Left in scratch: calls/CFG and instruction count align, but VC5 keeps a
//   0x3C frame and rotates this/dc/font through ESI/EDI/EBX versus the oracle's
//   0x40 frame and EDI/EBX/ESI register coloring.
// - Direct member ownership for the calloc result, generic TEXTMETRIC/GetTextMetrics
//   spellings, and typed HDC/HFONT handles each duplicated the 50-byte drift;
//   restored the pinned named-array and explicit-A API source.
// - Main-agent stack accounting rejected a blind-review field correction. Two
//   pending SelectObject arguments shift ESP by eight bytes at the metric reads.

#include <windows.h>
#include <stdlib.h>

extern char s_basegame_setup_fonts[];

#ifndef BASEGAME_GROUPED_TU
struct RGE_Font {
    void* font;
    long font_wid;
    long font_hgt;
};

class TDrawArea {
public:
    void* GetDc(char* name);
    void ReleaseDc(char* name);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

#define BASE_PAD(n) virtual void base_pad##n();
    BASE_PAD(1) BASE_PAD(2) BASE_PAD(3) BASE_PAD(4) BASE_PAD(5)
    BASE_PAD(6) BASE_PAD(7) BASE_PAD(8) BASE_PAD(9) BASE_PAD(10)
    BASE_PAD(11) BASE_PAD(12) BASE_PAD(13) BASE_PAD(14) BASE_PAD(15)
    BASE_PAD(16) BASE_PAD(17) BASE_PAD(18) BASE_PAD(19) BASE_PAD(20)
    BASE_PAD(21) BASE_PAD(22) BASE_PAD(23) BASE_PAD(24) BASE_PAD(25)
    BASE_PAD(26) BASE_PAD(27) BASE_PAD(28) BASE_PAD(29) BASE_PAD(30)
    BASE_PAD(31) BASE_PAD(32) BASE_PAD(33) BASE_PAD(34) BASE_PAD(35)
    virtual int setup_fonts();
#undef BASE_PAD

    char gap_04[0x4C - 0x04];
    TDrawArea* draw_area;
    char gap_50[0x1E0 - 0x50];
    short font_num;
    char gap_1E2[2];
    RGE_Font* fonts;

    void* make_font(void* dc, long id, int italic);
};
#endif

int RGE_Base_Game::setup_fonts()
{
    RGE_Font* font_array;
    void* dc;
    HGDIOBJ old_font;
    short i;
    void* font;
    int font_index;
    TEXTMETRICA tm;

    this->font_num = 12;
    font_array = (RGE_Font*)calloc(12, 12);
    this->fonts = font_array;
    if (font_array == 0)
        return 0;

    dc = this->draw_area->GetDc(s_basegame_setup_fonts);
    if (dc == 0)
        return 0;

    i = 0;
    if (this->font_num > 0) {
        do {
            tm.tmHeight = (long)i;
            switch (tm.tmHeight) {
            case 0:
                font = this->make_font(dc, 0x6E, 0);
                break;
            case 1:
                font = this->make_font(dc, 0x71, 0);
                break;
            case 4:
                font = this->make_font(dc, 0x74, 0);
                break;
            case 6:
                font = this->make_font(dc, 0x83, 0);
                break;
            case 7:
                font = this->make_font(dc, 0x77, 0);
                break;
            case 8:
                font = this->make_font(dc, 0x80, 1);
                break;
            case 9:
                font = this->make_font(dc, 0x7A, 0);
                break;
            case 10:
                font = this->make_font(dc, 0x7D, 0);
                break;
            case 11:
                font = this->make_font(dc, 0x80, 0);
                break;
            default:
                font = 0;
                break;
            }

            if (font != 0) {
                old_font = SelectObject((HDC)dc, (HGDIOBJ)font);
                GetTextMetricsA((HDC)dc,
                                (LPTEXTMETRICA)&tm.tmAscent);
                font_index = tm.tmHeight;
                this->fonts[font_index].font = font;
                this->fonts[font_index].font_wid = tm.tmMaxCharWidth;
                this->fonts[font_index].font_hgt =
                    tm.tmAscent + tm.tmAveCharWidth;
                SelectObject((HDC)dc, old_font);
            }

            i = i + 1;
        } while (i < this->font_num);
    }

    this->draw_area->ReleaseDc(s_basegame_setup_fonts);
    return 1;
}
