// Attempt log:
// baseline: natural render path with local typed Win32 and draw-area stubs; frame 0x44, diff 1552.
// layout: restored TPanel ownership for width, height, and draw origin; frame 0x48, diff 1526.
// control-flow: used panel dimensions and original justification enum values; frame 0x40, diff 1506.
// liveness: retained ImageRect and text pointers and corrected RGB local order; best diff 1361.
// current claim: tested pointer declaration/order and direct member forms; no gain.
// current claim: replaced the hand-written text scan with CRT strlen; target uses repne scasb.
// strlen source is more period-plausible, but its current layout basin is diff 1452.
// remaining drift: early pointer register allocation, block placement, and several local homes.
// left in scratch: typed source with the binary-supported strlen path; structural work remains.
#include <string.h>

struct tagRECT { long left; long top; long right; long bottom; };
struct tagSIZE { long cx; long cy; };
struct tagPALETTEENTRY { unsigned char peRed, peGreen, peBlue, peFlags; };

extern int (__stdcall *SelectClipRgn)(void*, void*);
extern void* (__stdcall *SelectObject)(void*, void*);
extern unsigned int (__stdcall *GetPaletteEntries)(void*, unsigned int, unsigned int, tagPALETTEENTRY*);
extern unsigned int (__stdcall *SetBkColor)(void*, unsigned int);
extern int (__stdcall *SetBkMode)(void*, int);
extern int (__stdcall *GetTextExtentPoint32A)(void*, const char*, int, tagSIZE*);
extern int (__stdcall *SetRect)(tagRECT*, int, int, int, int);
extern unsigned int (__stdcall *SetTextColor)(void*, unsigned int);
extern int (__stdcall *DrawTextA)(void*, const char*, int, tagRECT*, unsigned int);

struct DrawSystem { char gap_00[8]; void* Pal; };
struct GameBaseInner { char gap_00[0x48]; DrawSystem* draw_system; };
extern GameBaseInner* rge_base_game;

struct Shape_Info {
    char gap_00[0x10];
    long Width;
    char gap_14[4];
    long Hotspot_X;
    long Hotspot_Y;
};

class TShape;

class TDrawArea {
public:
    char gap_00[0x38];
    void* hdc;

    void PtrClear(tagRECT* rect, int mode);
    void SetClipRect(tagRECT* rect);
    void* GetDc(char* tag);
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
    virtual void pv8(int);

    char gap_04[0x10];
    long pnl_wid;
    long pnl_hgt;
    char gap_1C[4];
    TDrawArea* render_area;
    char gap_24[0x68];
    long draw_left;
    long draw_top;
    char gap_94[0x5F];
    unsigned char need_restore;
};

class TShape {
public:
    Shape_Info* shape_info;
    void shape_draw(TDrawArea* draw_area, long x, long y, long frame, unsigned char transparent, unsigned char* remap);
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
    TShape* Icon1;
    TShape* Icon2;
    int IconFrame1;
    int IconFrame2;

    int render_to_image_buffer();
};

int TMessagePanel::render_to_image_buffer() {
    if (this->ImageBuffer == 0) {
        return 0;
    }

    tagRECT* image_rect = &this->ImageRect;
    this->ImageBuffer->PtrClear(image_rect, 1);

    if (this->text[0] == 0) {
        SetRect(&this->UsedImageRect, 0, 0, 1, 1);
        SetRect(&this->UsedScreenRect, this->draw_left, this->draw_top, this->draw_left + 1, this->draw_top + 1);
        this->ImageTextActive = 1;
        return 1;
    }

    void* dc = this->ImageBuffer->GetDc("pnl_msg::render_to_image_buffer");
    if (dc == 0) {
        return 0;
    }

    this->ImageBuffer->SetClipRect(image_rect);
    SelectClipRgn(this->ImageBuffer->hdc, this->image_clip_region);
    void* old_font = SelectObject(this->ImageBuffer->hdc, this->font);

    tagPALETTEENTRY p;
    unsigned long back_rgb;
    unsigned long font_rgb;
    if (this->index_color == 0) {
        back_rgb = this->font_color2;
        font_rgb = this->font_color1;
    } else {
        GetPaletteEntries(rge_base_game->draw_system->Pal, this->font_color, 1, &p);
        font_rgb = ((unsigned long)p.peBlue << 16) | ((unsigned long)p.peGreen << 8) | p.peRed;
        GetPaletteEntries(rge_base_game->draw_system->Pal, this->back_color, 1, &p);
        back_rgb = ((unsigned long)p.peBlue << 16) | ((unsigned long)p.peGreen << 8) | p.peRed;
    }

    if (this->message_type == 2) {
        SetBkColor(this->ImageBuffer->hdc, 0);
        SetBkMode(this->ImageBuffer->hdc, 2);
    } else {
        SetBkMode(this->ImageBuffer->hdc, 1);
    }

    long x = image_rect->left;
    long display_hgt;
    long y = image_rect->top;
    long wid = this->pnl_wid - 2;
    long hgt = this->pnl_hgt - 2;

    tagSIZE ts;
    int len = strlen(this->text);
    int ok = GetTextExtentPoint32A(this->ImageBuffer->hdc, text, len, &ts);

    tagRECT rect;
    if (ok == 0) {
        SetRect(&rect, x, y, x + wid - 2, y + hgt - 2);
        SetRect(&this->UsedImageRect, 0, 0, 1, 1);
        this->ImageTextActive = 0;
    } else {
        unsigned int flags;
        long used_x = 0;
        long used_y = 0;
        long used_w = ts.cx + 2;
        display_hgt = ts.cy + 2;
        int tight = 1;

        if (this->message_type == 1) {
            flags = 0x21;
            used_x = ((this->pnl_wid - used_w) >> 1) - 1;
        } else if (this->message_type == 5) {
            flags = 0x22;
            used_x = (this->pnl_wid - used_w) - 1;
            used_y = 0;
        } else {
            if (this->word_wrap == 0 || ts.cx <= wid) {
                used_w = ts.cx + 1;
                display_hgt = ts.cy + 1;
                flags = 0x20;
                tight = 1;
            } else {
                used_w = this->pnl_wid;
                display_hgt = this->pnl_hgt;
                flags = 0x10;
                tight = 0;
            }
            used_x = 0;
            used_y = 0;
            if (this->horz_just == 4) {
                flags |= 1;
                if (tight) used_x = ((this->pnl_wid - used_w) >> 1) - 1;
            } else if (this->horz_just == 3) {
                flags |= 2;
                if (tight) used_x = (this->pnl_wid - used_w) - 1;
            } else if (tight) {
                used_x = 0;
            }
            if (this->vert_just == 4) {
                flags |= 4;
                if (tight) used_y = ((this->pnl_hgt - display_hgt) >> 1) - 1;
            } else if (this->vert_just == 1) {
                flags |= 8;
                if (tight) used_y = (this->pnl_hgt - display_hgt) - 1;
            } else if (tight) {
                used_y = 0;
            }
        }

        if (used_y < 0) used_y = 0;
        if (used_x < 0) used_x = 0;

        this->UsedImageRect.left = used_x;
        this->UsedImageRect.top = used_y;
        this->UsedImageRect.right = used_x + used_w;
        this->UsedImageRect.bottom = used_y + display_hgt;
        if (this->ImageRect.right < this->UsedImageRect.right) this->UsedImageRect.right = this->ImageRect.right;
        if (this->ImageRect.bottom < this->UsedImageRect.bottom) this->UsedImageRect.bottom = this->ImageRect.bottom;

        SetTextColor(this->ImageBuffer->hdc, back_rgb);
        SetRect(&rect, x, y, x + wid - 1, y + hgt - 1);
        DrawTextA(this->ImageBuffer->hdc, this->text, -1, &rect, flags);
        SetRect(&rect, x, y + 2, x + wid - 1, y + hgt + 1);
        DrawTextA(this->ImageBuffer->hdc, this->text, -1, &rect, flags);
        SetRect(&rect, x + 2, y, x + wid + 1, y + hgt - 1);
        DrawTextA(this->ImageBuffer->hdc, this->text, -1, &rect, flags);
        SetRect(&rect, x + 2, y + 2, x + wid + 1, y + hgt + 1);
        DrawTextA(this->ImageBuffer->hdc, this->text, -1, &rect, flags);
        SetTextColor(this->ImageBuffer->hdc, font_rgb);
        SetRect(&rect, x + 1, y + 1, x + wid, y + hgt);
        DrawTextA(this->ImageBuffer->hdc, this->text, -1, &rect, flags);

        if (this->Icon1 != 0) {
            Shape_Info* info = this->Icon1->shape_info;
            long frame = this->IconFrame1;
            long width = info[frame].Width;
            this->Icon1->shape_draw(this->ImageBuffer, info[frame].Hotspot_X - width - 4 + this->UsedImageRect.left,
                                    info[frame].Hotspot_Y + 6 + this->UsedImageRect.top, frame, 0, 0);
            this->UsedImageRect.left += -4 - width;
        }
        if (this->Icon2 != 0) {
            Shape_Info* info = this->Icon2->shape_info;
            long frame = this->IconFrame2;
            long width = info[frame].Width;
            this->Icon2->shape_draw(this->ImageBuffer, info[frame].Hotspot_X - width - 4 + this->UsedImageRect.left,
                                    info[frame].Hotspot_Y + 6 + this->UsedImageRect.top, frame, 0, 0);
            this->UsedImageRect.left += -4 - width;
        }
        this->ImageTextActive = 1;
    }

    SelectObject(this->ImageBuffer->hdc, old_font);
    SelectClipRgn(this->ImageBuffer->hdc, 0);
    this->ImageBuffer->ReleaseDc("pnl_msg::render_to_image_buffer");

    this->UsedScreenRect.left = this->UsedImageRect.left + this->draw_left;
    this->UsedScreenRect.top = this->UsedImageRect.top + this->draw_top;
    this->UsedScreenRect.right = this->UsedImageRect.right + this->draw_left;
    this->UsedScreenRect.bottom = this->UsedImageRect.bottom + this->draw_top;
    return this->ImageTextActive;
}
