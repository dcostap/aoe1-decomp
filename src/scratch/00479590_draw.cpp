// Attempt log:
// baseline: restored the full image-copy and GDI draw paths; frame 0x40, diff 866.
// layout: added inherited panel width and height ownership; diff 858.
// control-flow: computed panel bounds before text extent; exact size, frame 0x44, diff 833.
// context: restored canonical TPanel fields and virtual draw ownership; no code change.
// remaining drift: VC5 keeps the vtable carrier in EBX, not original EDI, and misses 4 frame bytes.
// left in scratch: typed period-plausible draw source with 32 aligned calls; no exact lead remains.
struct tagRECT { long left; long top; long right; long bottom; };
struct tagSIZE { long cx; long cy; };
struct tagPALETTEENTRY { unsigned char peRed, peGreen, peBlue, peFlags; };

extern int (__stdcall *SelectClipRgn)(void*, void*);
extern void* (__stdcall *SelectObject)(void*, void*);
extern unsigned int (__stdcall *GetPaletteEntries)(void*, unsigned int, unsigned int, tagPALETTEENTRY*);
extern unsigned int (__stdcall *SetBkColor)(void*, unsigned int);
extern int (__stdcall *SetBkMode)(void*, int);
extern int (__stdcall *GetTextExtentPoint32A)(void*, const char*, int, tagSIZE*);
extern unsigned int (__stdcall *SetTextColor)(void*, unsigned int);
extern int (__stdcall *SetRect)(tagRECT*, int, int, int, int);
extern int (__stdcall *DrawTextA)(void*, const char*, int, tagRECT*, unsigned int);

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
        this->need_restore = 0;
        return;
    }

    tagPALETTEENTRY p;
    tagSIZE ts;
    tagRECT rect;
    void* old_font;
    unsigned long font_rgb;
    unsigned long back_rgb;
    int len;
    long top;
    long left;
    long right;
    long bottom;
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
            if (this->index_color == 0) {
                font_rgb = this->font_color1;
                back_rgb = this->font_color2;
            } else {
                GetPaletteEntries(rge_base_game->draw_system->Pal, this->font_color, 1, &p);
                font_rgb = ((unsigned long)p.peBlue << 16) | ((unsigned long)p.peGreen << 8) | p.peRed;
                GetPaletteEntries(rge_base_game->draw_system->Pal, this->back_color, 1, &p);
                back_rgb = ((unsigned long)p.peBlue << 16) | ((unsigned long)p.peGreen << 8) | p.peRed;
            }

            if (this->message_type == 2) {
                SetBkColor(this->render_area->hdc, 0);
                SetBkMode(this->render_area->hdc, 2);
            } else {
                SetBkMode(this->render_area->hdc, 1);
            }

            left = this->draw_left;
            top = this->draw_top;
            right = this->pnl_wid + left - 1;
            bottom = this->pnl_hgt + top - 1;

            len = 0;
            while (msg[len] != 0) ++len;
            GetTextExtentPoint32A(this->render_area->hdc, msg, len, &ts);

            unsigned int flags;
            if (this->message_type == 1) {
                flags = 0x21;
            } else if (this->message_type == 5) {
                flags = 0x22;
            } else {
                len = 0;
                while (msg[len] != 0) ++len;
                GetTextExtentPoint32A(this->render_area->hdc, msg, len, &ts);
                flags = (this->word_wrap == 0 || ts.cx <= this->pnl_wid - 2) ? 0x20 : 0x10;
                if (this->horz_just == 4) flags |= 1;
                else if (this->horz_just == 3) flags |= 2;
                if (this->vert_just == 4) flags |= 4;
                else if (this->vert_just == 1) flags |= 8;
            }

            SetTextColor(this->render_area->hdc, back_rgb);
            SetRect(&rect, left, top, right - 2, bottom - 2);
            DrawTextA(this->render_area->hdc, msg, -1, &rect, flags);
            SetRect(&rect, left, top + 2, right - 2, bottom);
            DrawTextA(this->render_area->hdc, msg, -1, &rect, flags);
            SetRect(&rect, left + 2, top, right, bottom - 2);
            DrawTextA(this->render_area->hdc, msg, -1, &rect, flags);
            SetRect(&rect, left + 2, top + 2, right, bottom);
            DrawTextA(this->render_area->hdc, msg, -1, &rect, flags);
            SetTextColor(this->render_area->hdc, font_rgb);
            SetRect(&rect, left + 1, top + 1, right - 1, bottom - 1);
            DrawTextA(this->render_area->hdc, msg, -1, &rect, flags);

            SelectObject(this->render_area->hdc, old_font);
            SelectClipRgn(this->render_area->hdc, 0);
            this->render_area->ReleaseDc("pnl_msg::draw");
        }
    }

    this->draw_finish();
}
