// Attempt log:
// baseline: restored the full image-copy and GDI draw paths; frame 0x40, diff 866.
// layout: added inherited panel width and height ownership; diff 858.
// control-flow: computed panel bounds before text extent; exact size, frame 0x44, diff 833.
// context: restored canonical TPanel fields and virtual draw ownership; no code change.
// remaining drift: VC5 keeps the vtable carrier in EBX, not original EDI, and misses 4 frame bytes.
// left in scratch: typed period-plausible draw source with 32 aligned calls; no exact lead remains.
// shared-local lifetime probe: reordered x/y/wid/hgt with the original coordinate ownership; codegen unchanged, so keep the natural form.
// branch-layout: put the palette path first; this matches the original conditional edge and improves diff 833 -> 827.
// source-shape: use inline strlen for both text extents; CFG parity improves and diff reaches 811.
// layout: retain inner width/height locals, then add the origin before rectangle draws; diff reaches 775.
// context: imported GDI declarations and the period Windows header restore the repeated palette-call shape; diff reaches 633.
// behavior: corrected the four early guard exits to clear TPanel::need_redraw (+0x38), matching the original write; diff stayed 633 and shape improved 72.49% -> 72.75%.
// control-flow: tested SetTextColor before the rectangle bound updates, matching original line/call order; rolled back because strict diff worsened 633 -> 635.
// layout: modeled the proven +0x8C/+0x90 panel rectangle as tagRECT; diff worsened 633 -> 656 and was rolled back.
// liveness: hoisted the Ghidra function-scope flags local; emitted code duplicated the clean source.
// abi: changed the background COLORREF local to the Ghidra signed-int surface; emitted code duplicated the clean source.
// control-flow: assembly-donor evidence showed +1 origin loads before text extent; pre-added origin locals reached frame 0x48 and 85.17% shape, but added 27 bytes and changed the vtable carrier to EBX, so restored clean source.
// control-flow: split the same proven +1 operations into separate increments; output remained the 1174-byte variant, so restored clean source.
// layout: tested the live wid local in the word-wrap comparison; original 00479825 reads a stack width home, but VC5 kept wid in EBX and diff worsened 633 -> 639, so restored clean source.
// control-flow: reversed the dimension assignment order against the original x/y/wid/hgt load order; emitted bytes were unchanged, so restored clean source.
// liveness: initialized configured colors before the palette override to test the original EBX background carrier; CFG changed and diff worsened 633 -> 732, so restored clean source.
// layout: retested the binary-proven inner width in word-wrap; it repeated the 639-byte basin and was restored.
// abi: COLORREF/HGDIOBJ/HDC and unsigned text length matched the clean 633-byte output; kept the clean source instead.
// liveness: moving the background color declaration after palette/size/rect locals and reordering coordinates were codegen duplicates.
// variant: 16- and 64-case natural source labs found no size+frame+call-set eligible variant; no lab winner replaced typed source.
// control-flow: combined pre-incremented origins with SetTextColor-before-bound-updates reached frame 0x48 and 85.64% shape, but size grew 23 bytes and the vtable/message carriers swapped; restored clean source.
// stack/PDB: original Ghidra locals place y at the lowest frame slot, then x, wid, and hgt; the explicit iStack_28 is the saved virtual carrier. This confirms a real y-home lead, not padding.
// layout: scoping all draw locals inside the text block was codegen-neutral; restored clean source.
// layout: declaring x/y/wid/hgt at the PDB line-328 origin block was also codegen-neutral; no new ownership lead remains in this claim.
// left in scratch: exact call order and size match, but frame is 0x44 vs 0x48 and register/local scheduling still differs.
#include <string.h>
#include <windows.h>

struct DrawSystem { char gap_00[8]; void* Pal; };
struct GameBaseInner { char gap_00[0x48]; DrawSystem* draw_system; };
extern GameBaseInner* rge_base_game;

class TDrawArea {
public:
    char gap_00[0x38];
    void* hdc;

    void SetTrans(int a, int b);
    void Copy(TDrawArea* dest, long x, long y, tagRECT* rect, int mode);
    void* GetDc(char* tag);
    int HasDc(char* tag);
    void ReleaseDc(char* tag);
};

class TPanel {
public:
    virtual void pv0();
    virtual void pv1();
    virtual void pv2();
    virtual void pv3();
    virtual void pv4();
    virtual void pv5(int);
    virtual void pv6();
    virtual void pv7();
    virtual void pv8();
    virtual void pv9();
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();

    char gap_004[8];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char gap_01C[4];
    TDrawArea* render_area;
    char gap_024[0x14];
    int need_redraw;
    char gap_03C[0x30];
    int field_6C;
    int field_70;
    char gap_074[0x14];
    void* clip_rgn;
    long draw_left;
    long draw_top;
    char gap_094[0x5F];
    unsigned char need_restore;
};

class TMessagePanel : public TPanel {
public:
    int message_type;
    char text[0x200];
    int showing_message;
    int start_time;
    int show_message_interval;
    void* font;
    long font_wid;
    long font_hgt;
    unsigned char font_color;
    unsigned char back_color;
    char gap_312[2];
    int index_color;
    unsigned long font_color1;
    unsigned long font_color2;
    int horz_just;
    int vert_just;
    int word_wrap;
    void* image_clip_region;
    TDrawArea* ImageBuffer;
    tagRECT ImageRect;
    tagRECT UsedImageRect;
    tagRECT UsedScreenRect;
    int LastIBWidth;
    int LastIBHeight;
    int ImageTextActive;

    int render_to_image_buffer();
    virtual void draw();
};

void TMessagePanel::draw() {
    if (this->render_area == 0 || this->field_70 == 0 || this->field_6C == 0 || this->showing_message == 0) {
        this->need_redraw = 0;
        return;
    }

    long y;
    long x;
    long wid;
    long hgt;
    unsigned long font_rgb;
    void* old_font;
    unsigned long back_rgb;
    tagPALETTEENTRY p;
    tagSIZE ts;
    tagRECT rect;
    int len;
    this->draw_setup(0);

    if (this->ImageTextActive != 0 && this->ImageBuffer != 0) {
        if (this->need_restore != 0) {
            this->render_to_image_buffer();
            this->need_restore = 0;
            this->draw_finish();
            return;
        }
        this->ImageBuffer->SetTrans(1, 1);
        this->ImageBuffer->Copy(this->render_area, this->UsedScreenRect.left, this->UsedScreenRect.top, &this->UsedImageRect, 1);
        this->ImageBuffer->SetTrans(0, 1);
        this->draw_finish();
        return;
    }

    char* msg = this->text;
    if (msg[0] != 0) {
        void* dc = this->render_area->GetDc("pnl_msg::draw");
        if (dc != 0) {
            SelectClipRgn(this->render_area->hdc, this->clip_rgn);
            old_font = SelectObject(this->render_area->hdc, this->font);
            if (this->index_color != 0) {
                GetPaletteEntries(rge_base_game->draw_system->Pal, this->font_color, 1, &p);
                font_rgb = ((unsigned long)p.peBlue << 16) | ((unsigned long)p.peGreen << 8) | p.peRed;
                GetPaletteEntries(rge_base_game->draw_system->Pal, this->back_color, 1, &p);
                back_rgb = ((unsigned long)p.peBlue << 16) | ((unsigned long)p.peGreen << 8) | p.peRed;
            } else {
                font_rgb = this->font_color1;
                back_rgb = this->font_color2;
            }

            if (this->message_type == 2) {
                SetBkColor(this->render_area->hdc, 0);
                SetBkMode(this->render_area->hdc, 2);
            } else {
                SetBkMode(this->render_area->hdc, 1);
            }

            x = this->draw_left;
            y = this->draw_top;
            wid = this->pnl_wid - 2;
            hgt = this->pnl_hgt - 2;

            len = strlen(msg);
            GetTextExtentPoint32A(this->render_area->hdc, msg, len, &ts);

            unsigned int flags;
            if (this->message_type == 1) {
                flags = 0x21;
            } else if (this->message_type == 5) {
                flags = 0x22;
            } else {
                len = strlen(msg);
                GetTextExtentPoint32A(this->render_area->hdc, msg, len, &ts);
                flags = (this->word_wrap == 0 || ts.cx <= this->pnl_wid - 2) ? 0x20 : 0x10;
                if (this->horz_just == 4) flags |= 1;
                else if (this->horz_just == 3) flags |= 2;
                if (this->vert_just == 4) flags |= 4;
                else if (this->vert_just == 1) flags |= 8;
            }

            wid = wid + x + 1;
            hgt = hgt + y + 1;
            SetTextColor(this->render_area->hdc, back_rgb);
            SetRect(&rect, x, y, wid - 2, hgt - 2);
            DrawTextA(this->render_area->hdc, msg, -1, &rect, flags);
            SetRect(&rect, x, y + 2, wid - 2, hgt);
            DrawTextA(this->render_area->hdc, msg, -1, &rect, flags);
            SetRect(&rect, x + 2, y, wid, hgt - 2);
            DrawTextA(this->render_area->hdc, msg, -1, &rect, flags);
            SetRect(&rect, x + 2, y + 2, wid, hgt);
            DrawTextA(this->render_area->hdc, msg, -1, &rect, flags);
            SetTextColor(this->render_area->hdc, font_rgb);
            SetRect(&rect, x + 1, y + 1, wid - 1, hgt - 1);
            DrawTextA(this->render_area->hdc, msg, -1, &rect, flags);

            SelectObject(this->render_area->hdc, old_font);
            SelectClipRgn(this->render_area->hdc, 0);
            this->render_area->ReleaseDc("pnl_msg::draw");
        }
    }

    this->draw_finish();
}
