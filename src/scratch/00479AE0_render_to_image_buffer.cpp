// first reconstruction from the Ghidra packet; expected broad layout/codegen drift
// current draft compiles and is size-aligned, but broad control/layout drift remains (~85%); stack is 0x44 vs original 0x40
// testing int instead of bool for the wrap/tight flag to see if VC5 keeps it in register and recovers the 0x40 stack
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
    char gap_00[8];
    long Width;
    long Height;
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

class TShape {
public:
    Shape_Info* shape_info;
    void shape_draw(TDrawArea* draw_area, long x, long y, long frame, unsigned char transparent, unsigned char* remap);
};

class TMessagePanel {
public:
    char gap_000[0x8C];
    long draw_left;
    long draw_top;
    char gap_094[0x60];
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

    this->ImageBuffer->PtrClear(&this->ImageRect, 1);

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

    this->ImageBuffer->SetClipRect(&this->ImageRect);
    SelectClipRgn(this->ImageBuffer->hdc, this->image_clip_region);
    void* old_font = SelectObject(this->ImageBuffer->hdc, this->font);

    tagPALETTEENTRY p;
    unsigned long font_rgb;
    unsigned long back_rgb;
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
        SetBkColor(this->ImageBuffer->hdc, 0);
        SetBkMode(this->ImageBuffer->hdc, 2);
    } else {
        SetBkMode(this->ImageBuffer->hdc, 1);
    }

    long x = this->ImageRect.left;
    long y = this->ImageRect.top;
    long text_x = x + 1;
    long text_y = y + 1;
    long avail_w = this->font_wid - 2;
    long avail_h = this->font_hgt;

    tagSIZE ts;
    int len = 0;
    while (this->text[len] != 0) ++len;
    int ok = GetTextExtentPoint32A(this->ImageBuffer->hdc, this->text, len, &ts);

    tagRECT rect;
    if (ok == 0) {
        SetRect(&rect, x, y, text_x + avail_w - 4, text_y + avail_h - 4);
        SetRect(&this->UsedImageRect, 0, 0, 1, 1);
        this->ImageTextActive = 0;
    } else {
        unsigned int flags;
        long used_x = 0;
        long used_y = 0;
        long used_w = ts.cx + 2;
        long used_h = rect.left + 2;
        int tight = 1;

        if (this->message_type == 1) {
            flags = 0x21;
            used_x = ((this->font_wid - used_w) >> 1) - 1;
        } else if (this->message_type == 5) {
            flags = 0x22;
            used_x = (this->font_wid - used_w) - 1;
            used_y = 0;
        } else {
            if (this->word_wrap == 0 || ts.cx <= avail_w) {
                used_w = ts.cx + 1;
                used_h = rect.left + 1;
                flags = 0x20;
                tight = 1;
            } else {
                used_w = this->font_wid;
                used_h = this->font_hgt;
                flags = 0x10;
                tight = 0;
            }
            used_x = 0;
            used_y = 0;
            if (this->horz_just == 1) {
                flags |= 1;
                if (tight) used_x = ((this->font_wid - used_w) >> 1) - 1;
            } else if (this->horz_just == 2) {
                flags |= 2;
                if (tight) used_x = (this->font_wid - used_w) - 1;
            } else if (tight) {
                used_x = 0;
            }
            if (this->vert_just == 1) {
                flags |= 4;
                if (tight) used_y = ((this->font_hgt - used_h) >> 1) - 1;
            } else if (this->vert_just == 2) {
                flags |= 8;
                if (tight) used_y = (this->font_hgt - used_h) - 1;
            } else if (tight) {
                used_y = 0;
            }
        }

        if (used_y < 0) used_y = 0;
        if (used_x < 0) used_x = 0;

        this->UsedImageRect.left = used_x;
        this->UsedImageRect.top = used_y;
        this->UsedImageRect.right = used_x + used_w;
        this->UsedImageRect.bottom = used_y + used_h;
        if (this->ImageRect.right < this->UsedImageRect.right) this->UsedImageRect.right = this->ImageRect.right;
        if (this->ImageRect.bottom < this->UsedImageRect.bottom) this->UsedImageRect.bottom = this->ImageRect.bottom;

        SetTextColor(this->ImageBuffer->hdc, back_rgb);
        long right = text_x + avail_w;
        long bottom = text_y + this->font_hgt - 2;
        SetRect(&rect, x, y, right - 2, bottom - 2);
        DrawTextA(this->ImageBuffer->hdc, this->text, -1, &rect, flags);
        SetRect(&rect, x, y + 2, right - 2, bottom);
        DrawTextA(this->ImageBuffer->hdc, this->text, -1, &rect, flags);
        SetRect(&rect, x + 2, y, right, bottom - 2);
        DrawTextA(this->ImageBuffer->hdc, this->text, -1, &rect, flags);
        SetRect(&rect, x + 2, y + 2, right, bottom);
        DrawTextA(this->ImageBuffer->hdc, this->text, -1, &rect, flags);
        SetTextColor(this->ImageBuffer->hdc, font_rgb);
        SetRect(&rect, text_x, text_y, right - 1, bottom - 1);
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
