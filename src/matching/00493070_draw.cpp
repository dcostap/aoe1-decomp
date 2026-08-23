// TScrollTextPanel::draw — real pass
// VA: 00493070
//
// Canonical ownership (binary-proven offsets):
//   +0x20 render_area (TDrawArea*), +0x38 need_redraw, +0x6C active,
//   +0x70 field_70, +0x88 clip_rgn, +0xF8 line_count (short),
//   +0x104 font, +0x120/+0x124 text_color1/text_color2.
// Virtual slots: 0x28 draw_setup(int), 0x2C draw_finish(), 0x30 draw().
// Direct base calls: TTextPanel::draw_background (0047D3D0),
// TTextPanel::draw_border (0047D570), TScrollTextPanel::draw_scrolled_line
// (00493160). IAT: SelectClipRgn (88A5DC), SelectObject (88A59C),
// SetBkMode (88A5EC). PDB lines 500-540, scr_cred.cpp.
//
// Attempt log:
// - baseline: natural guarded reconstruction; draw_scrolled_line declared
//   with the exact ?draw_scrolled_line@TScrollTextPanel@@QAEXPAXFFKK@Z
//   surface, GetDc/ReleaseDc with char* (PAD) like the matched donors.

#include "../../include/scr_cred_context.h"

#if 0
extern "C" {
__declspec(dllimport) int __stdcall SelectClipRgn(void* hdc, void* hrgn);
__declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* object);
__declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode);
}

extern const char s_scr_cred_draw_005862e0[];

class TDrawArea {
public:
    char gap_00[0x38];
    void* DrawDc;
    void* GetDc(char* unused);
    void ReleaseDc(char* unused);
};

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)

class TPanel {
public:
    VPAD8(v0) VPAD2(v8)
    virtual void draw_setup(int clear);   // slot 0x28
    virtual void draw_finish();           // slot 0x2C
    virtual void draw();                  // slot 0x30

    char gap_04[0x1C];                    // +0x04
    TDrawArea* render_area;               // +0x20
    char gap_24[0x14];                    // +0x24..+0x37
    int need_redraw;                      // +0x38
    char gap_3C[0x30];                    // +0x3C..+0x6B
    int active;                           // +0x6C
    int field_70;                         // +0x70
    char gap_74[0x14];                    // +0x74..+0x87
    void* clip_rgn;                       // +0x88
    char gap_8C[0x6C];                    // +0x8C..+0xF7
    short line_count;                     // +0xF8
    char gap_FA[0x0A];                    // +0xFA..+0x103
    void* font;                           // +0x104
    char gap_108[0x18];                   // +0x108..+0x11F
    unsigned long text_color1;            // +0x120
    unsigned long text_color2;            // +0x124
    char gap_128[0x60];                   // +0x128..+0x187
    int scroll;                           // +0x188
    unsigned long last_time;              // +0x18C
    int speed;                            // +0x190
    int done;                             // +0x194
};

class TTextPanel : public TPanel {
public:
    void draw_background();
    void draw_border();
};

class TScrollTextPanel : public TTextPanel {
public:
    virtual void draw();
    void draw_scrolled_line(void* hdc, short x, short y,
                            unsigned long color1, unsigned long color2);
};
#endif

void TScrollTextPanel::draw()
{
    this->need_redraw = 0;
    if (this->render_area != 0 && this->field_70 != 0 && this->active != 0)
    {
        this->draw_background();
        this->draw_setup(0);
        void* dc = this->render_area->GetDc((char*)s_scr_cred_draw_005862e0);
        if (dc != 0)
        {
            SelectClipRgn(dc, this->clip_rgn);
            void* old_font = SelectObject(dc, this->font);
            SetBkMode(dc, 1);
            for (short i = 0; i < this->line_count; i++)
            {
                this->draw_scrolled_line(dc, i, i,
                                         this->text_color1, this->text_color2);
            }
            SelectObject(dc, old_font);
            SelectClipRgn(dc, 0);
            this->render_area->ReleaseDc((char*)s_scr_cred_draw_005862e0);
        }
        this->draw_border();
        this->draw_finish();
    }
}
