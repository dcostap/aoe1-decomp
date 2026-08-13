// VA 00476680 TEditPanel::draw
// pnl_edit.cpp:859-973
// Attempt log:
// 1: Natural implementation from packet/decompiler with local TDrawArea/vtable and Win32 imports.
// 2: First compiling pass had exact 940-byte size but field offsets after rect were 4 bytes early; fixed TEditPanel gap so dirty is +0x38, visible +0x70, brush +0x108, bevel_type +0x150, colors +0x154..+0x159.
// 3: Fixed TDrawArea virtual surface: background border call is vtable +0x34 and high-bevel background call is +0x3c; inserted unused +0x38 slot.
// 4: Changed palette access from virtual call to raw vtable slot load `(*(void***)draw_area)[2]`, matching original GetNearestPaletteIndex argument load.
// 5: Implemented top pre_draw/post_draw flow, dirty clear, Clear/fill background path, background image/border path, bevel switch cases 1..7, Lock/Unlock calls, and edit HWND show/hide/DrawTextEx path.
// 6: Bevel switch now uses original offsets/order for bevel_type and six colors; switch body is close enough that edit diff dropped to 18.8298% while size stayed exact.
// 7: Restructured early visible test from early return to `if (visible != 0) { body }`; no codegen change, rolled form kept harmless.
// 8: Probed /Ob0: no change. Probed /Og-: much worse (91.2766% positional, first mismatch 0), flag removed.
// 9: Remaining first mismatch is at offset 3: rebuilt saves EBX and EDI in the prologue, while original shrink-wraps them until after the visible/null check (`push edi; push ebx` at 00476697/98).
// 10: Current default validation: exact 940 bytes, positional 696 / 74.0426%, edit 177 / 18.8298%, first mismatch offset 3. Drift is broad positional due early callee-save scheduling and shifted branch distances, not accepted-drift quality.
// GIVEUP: left in scratch for future source-shape/context work to recover VC5 shrink-wrapped EBX/EDI saves and exact branch distances.
// Current bounded pass:
// 11: <windows.h> import declarations fixed all 13 indirect API relocations;
//     current checker result is 940B exact size, 27/27 calls, 38 differing bytes.
// 12-16: branch/lifetime, virtual draw declaration, and done-label variants
//     left the emitted code unchanged; canonical TPanel inheritance restored.
// 17: typed DrawArea->DrawSystem->Pal ownership replaced the diagnostic raw
//     vtable read with identical bytes. Final gap is prologue shrink-wrapping:
//     original delays push edi/ebx until the visible path, while VC5 saves them
//     at entry in this TU; the body is otherwise a 98.19% resynchronized match.
// New claim: baseline revalidated the 940-byte/38-byte-diff clean source.
// Probes 1-6 scoped RECT/old_font, tried positive visible nesting, removed the
// redundant panel receiver, reordered stack-local declarations, and completed
// the same-TU virtual surface; all were codegen duplicates.  Restore clean
// source for the documented shrink-wrap blocker.
// New claim probes: a focused guard/receiver variant lab (4 cases), a TPanel
// reference receiver, a shared hidden-exit goto label, and a braced invisible
// guard all preserved the 940-byte/38-byte-diff result.  Restored the clean
// pointer receiver and early-return source.  The only lead remains VC5's
// entry-save choice versus the original delayed EBX/EDI saves.

#include <windows.h>

typedef unsigned char uchar;

struct TDrawSystem {
    char gap_00[8];
    void* Pal;
};

struct TDrawArea {
    TDrawSystem* DrawSystem;
    char gap_04[0x80];
    int field_84;
    void Clear(RECT* r, int color);
    uchar* Lock(char* name, int wait);
    void Unlock(char* name);
    HDC GetDc(char* name);
    void ReleaseDc(char* name);
    void DrawRect(long x1,long y1,long x2,long y2,uchar c1);
    void DrawBevel(long x1,long y1,long x2,long y2,uchar c1,uchar c2);
    void DrawBevel2(long x1,long y1,long x2,long y2,uchar c1,uchar c2,uchar c3,uchar c4);
    void DrawBevel3(long x1,long y1,long x2,long y2,uchar c1,uchar c2,uchar c3,uchar c4,uchar c5,uchar c6);
};

class TPanel {
public:
    virtual ~TPanel(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24();
    virtual void pre_draw(int);
    virtual void post_draw();
    virtual void vf30();
    virtual void border(RECT*);
    virtual void vf38();
    virtual void vf3C(RECT*);

    char gap_04[8];
    long x;
    long y;
    long width;
    long height;
    char gap_1C[4];
    TDrawArea* draw_area;
    RECT rect;
    char gap_34[4];
    long dirty;
    char gap_3C[4];
    TPanel* background;
    char gap_44[0x28];
    int active;
    int visible;
    char gap_74[4];
    int have_focus;
    char gap_7C[0x08];
    int field_84;
    HRGN clip_rgn;
    char gap_8C[0x63];
    uchar back_index;
    char gap_F0[4];
};

class TEditPanel : public TPanel {
public:
    HWND edit_wnd;
    char gap_F8[4];
    char* text;
    char gap_100[4];
    int hidden;
    int brush;
    char gap_10C[8];
    COLORREF text_color1;
    COLORREF text_color2;
    char gap_11C[8];
    unsigned int back_color;
    HGDIOBJ font;
    char gap_130[4];
    RECT draw_rect;
    unsigned int draw_format;
    char gap_148[12];
    int bevel_type;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;

    virtual void draw();
};

void TEditPanel::draw()
{
    this->dirty = 0;
    if (this->visible == 0) return;
    RECT r;
    HGDIOBJ old_font;
    TPanel* panel = this;

    panel->pre_draw(0);

    if (this->brush && this->active && this->have_focus) {
        uchar c = (uchar)GetNearestPaletteIndex(this->draw_area->DrawSystem->Pal, this->back_color);
        this->draw_area->Clear(&this->rect, c);
    } else {
        TPanel* bg = this->background;
        if (bg) {
            if (this->bevel_type >= 2 && this->bevel_type <= 7) {
                bg->vf3C(&this->rect);
            } else if (bg->field_84 == 0) {
                bg->border(&this->rect);
            }
        } else {
            this->draw_area->Clear(&this->rect, this->back_index);
        }
    }

    if (this->bevel_type != 0) {
        if (this->draw_area->Lock("pnl_edit::draw", 1)) {
            switch (this->bevel_type) {
            case 1:
                this->draw_area->DrawRect(this->x, this->y, this->x + this->width - 1, this->y + this->height - 1, this->bevel_color1);
                break;
            case 2:
                this->draw_area->DrawBevel(this->x, this->y, this->x + this->width - 1, this->y + this->height - 1, this->bevel_color6, this->bevel_color1);
                break;
            case 3:
                this->draw_area->DrawBevel2(this->x, this->y, this->x + this->width - 1, this->y + this->height - 1, this->bevel_color6, this->bevel_color5, this->bevel_color2, this->bevel_color1);
                break;
            case 4:
                this->draw_area->DrawBevel3(this->x, this->y, this->x + this->width - 1, this->y + this->height - 1, this->bevel_color6, this->bevel_color5, this->bevel_color4, this->bevel_color3, this->bevel_color2, this->bevel_color1);
                break;
            case 5:
                this->draw_area->DrawBevel(this->x, this->y, this->x + this->width - 1, this->y + this->height - 1, this->bevel_color1, this->bevel_color6);
                break;
            case 6:
                this->draw_area->DrawBevel2(this->x, this->y, this->x + this->width - 1, this->y + this->height - 1, this->bevel_color1, this->bevel_color2, this->bevel_color5, this->bevel_color6);
                break;
            case 7:
                this->draw_area->DrawBevel3(this->x, this->y, this->x + this->width - 1, this->y + this->height - 1, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
                break;
            }
        }
        this->draw_area->Unlock("pnl_edit::draw");
    }

    if (this->edit_wnd && this->active) {
        if (this->have_focus) {
            if (this->hidden) {
                ShowWindow(this->edit_wnd, 5);
                InvalidateRect(this->edit_wnd, 0, 1);
                this->hidden = 0;
                panel->post_draw();
                return;
            }
        } else {
            if (!this->hidden) {
                ShowWindow(this->edit_wnd, 0);
                this->hidden = 1;
            }
            HDC dc = this->draw_area->GetDc("pnl_edit::draw");
            if (dc) {
                SelectClipRgn(dc, this->clip_rgn);
                old_font = SelectObject(dc, this->font);
                SetBkMode(dc, 1);
                SetTextColor(dc, this->text_color2);
                r.left = this->draw_rect.left - 1;
                r.top = this->draw_rect.top + 1;
                r.right = this->draw_rect.right - 1;
                r.bottom = this->draw_rect.bottom + 1;
                DrawTextExA(dc, this->text, -1, &r, this->draw_format, 0);
                SetTextColor(dc, this->text_color1);
                DrawTextExA(dc, this->text, -1, &this->draw_rect, this->draw_format, 0);
                SelectObject(dc, old_font);
                SelectClipRgn(dc, 0);
                this->draw_area->ReleaseDc("pnl_edit::draw");
            }
        }
    }

    panel->post_draw();
}
