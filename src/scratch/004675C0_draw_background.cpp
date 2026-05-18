// VA 004675C0 TEasy_Panel::draw_background
// Panel_ez.cpp:402-530
// Attempt log:
// 1: Natural source from packet/decompiler, local TDrawArea/TShape surfaces.
// 2: First natural build compiled but was size-short: configured 979 exceeds .text 976.
// 3: Fixed TEasy_Panel layout by adding post-RECT gap so background_pos is +0x38, background_pic +0x204, background_pic2 +0x208, picture_style +0x318, use_bevels +0x31c, colors +0x320/+0x454/+0x455, shadow_area +0x46c.
// 4: Implemented pre_draw/post_draw, shadow-area path with clear/copy/center/tile modes, fallback pic selection, background clear colors, shape Lock/minmax/draw, shadow-table/DrawShadowBox, and bevel Lock/DrawBevel3/Unlock.
// 5: Probed /GX and /Ob0: still size-short 976 bytes. Probed /Og- and /Od: exact 979 bytes but broad mismatch (~91.6% positional, first mismatch offset 0); flags removed.
// 6: Added temporary volatile pad to recover exact size under /O2 for diagnostics; got exact 979 bytes but first mismatch offset 4 and broad 87.0% positional due artificial early stores; removed before final because it is not a valid match path.
// 7: Remaining blocker is broad VC5 frame/local topology: natural C has the right field offsets and broad call surface but compiles 3 bytes short; exact-size diagnostic forms are broad from prologue.
// GIVEUP: left in scratch; no accepted_drift because natural build is size-short and diagnostic exact-size variants are broad/prologue-different.

typedef unsigned char uchar;
struct RECT { long left, top, right, bottom; };

class TDrawArea_004675C0 {
public:
    char gap_00[0x18];
    long Width;
    long Height;
    void Clear(RECT*, int);
    uchar* Lock(char*, int);
    void Unlock(char*);
    void Copy(TDrawArea_004675C0*, long, long, RECT*, int);
    void SetShadowTable(void*);
    void DrawShadowBox(long,long,long,long);
    void DrawBevel3(long,long,long,long,uchar,uchar,uchar,uchar,uchar,uchar);
};

class TShape_004675C0 {
public:
    uchar shape_minmax(long*, long*, long*, long*, int);
    uchar shape_draw(TDrawArea_004675C0*, long, long, int, uchar, uchar*);
};

class TEasy_Panel_004675C0 {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24();
    virtual void pre_draw(int);
    virtual void post_draw();

    char gap_04[8];
    long x;
    long y;
    long width;
    long height;
    char gap_1C[4];
    TDrawArea_004675C0* draw_area;
    RECT rect;
    char gap_34[4];
    long background_pos; // +38
    char gap_3C[0x1C8];
    TShape_004675C0* background_pic; // +204
    TShape_004675C0* background_pic2; // +208
    char gap_20C[0x10C];
    int picture_style; // +318
    int use_bevels; // +31C
    uchar bevel_color1; uchar bevel_color2; uchar bevel_color3; uchar bevel_color4; uchar bevel_color5; uchar bevel_color6;
    char gap_326[0x126];
    void* shadow_color_table; // +44C
    char gap_450[4];
    uchar background_color1; // +454
    uchar background_color2; // +455
    char gap_456[0x16];
    TDrawArea_004675C0* shadow_area; // +46C

    void draw_background(int use_alt);
};

void TEasy_Panel_004675C0::draw_background(int use_alt)
{
    long y_max;
    long x_min;
    long y_min;
    long x_max;
    long pic_hgt;
    TShape_004675C0* pic;

    this->pre_draw(0);

    if (use_alt && this->shadow_area) {
        if (this->background_pos == 2)
            this->draw_area->Clear(&this->rect, this->background_color2);

        TDrawArea_004675C0* sarea = this->shadow_area;
        int tile_h = sarea->Height;
        int tile_w = sarea->Width;
        switch (this->picture_style) {
        case 0:
            sarea->Copy(this->draw_area, this->x, this->y, 0, 0);
            break;
        case 1: {
            short xx = (short)this->x + (short)(this->width / 2) - (short)(tile_w / 2);
            short yy = (short)this->y + (short)(this->height / 2) - (short)(tile_h / 2);
            sarea->Copy(this->draw_area, (long)xx, (long)yy, 0, 0);
            break;
        }
        case 2: {
            long yy = 0;
            if (this->height >= 0) {
                do {
                    long xx = 0;
                    if (this->width >= 0) {
                        do {
                            sarea->Copy(this->draw_area, xx + this->x, yy + this->y, 0, 0);
                            xx += tile_w;
                        } while (xx <= this->width);
                    }
                    yy += tile_h;
                } while (yy <= this->height);
            }
            break;
        }
        }
        goto bevels;
    }

    if (use_alt && this->background_pic2)
        pic = this->background_pic2;
    else
        pic = this->background_pic;

    if (this->background_pos == 2 || pic == 0) {
        this->draw_area->Clear(&this->rect, use_alt ? this->background_color2 : this->background_color1);
        if (pic == 0)
            goto bevels;
    }

    if (this->draw_area->Lock("panel_ez::draw_background", 1)) {
        pic->shape_minmax(&x_min, &y_min, &x_max, &y_max, 0);
        long pic_w = x_max - x_min + 1;
        pic_hgt = y_max - y_min + 1;
        switch (this->picture_style) {
        case 1: {
            short xx = (short)this->x + (short)(this->width / 2) - (short)(pic_w / 2);
            short yy = (short)this->y + (short)(this->height / 2) - (short)(pic_hgt / 2);
            pic->shape_draw(this->draw_area, (long)xx, (long)yy, 0, 0, 0);
            if (use_alt && this->shadow_color_table) {
                this->draw_area->SetShadowTable(this->shadow_color_table);
                this->draw_area->DrawShadowBox((long)xx, (long)yy, xx + pic_w - 1, yy + pic_hgt - 1);
            }
            break;
        }
        case 2: {
            long yy = 0;
            if (this->height >= 0) {
                do {
                    long xx = 0;
                    if (this->width >= 0) {
                        do {
                            pic->shape_draw(this->draw_area, xx + this->x, yy + this->y, 0, 0, 0);
                            xx += pic_w;
                        } while (xx <= this->width);
                    }
                    yy += pic_hgt;
                } while (yy <= this->height);
            }
            if (use_alt && this->shadow_color_table) {
                this->draw_area->SetShadowTable(this->shadow_color_table);
                this->draw_area->DrawShadowBox(this->x, this->y, this->x + this->width - 1, this->y + this->height - 1);
            }
            break;
        }
        default:
            pic->shape_draw(this->draw_area, this->x, this->y, 0, 0, 0);
            if (use_alt && this->shadow_color_table) {
                this->draw_area->SetShadowTable(this->shadow_color_table);
                this->draw_area->DrawShadowBox(this->x, this->y, this->x + pic_w - 1, this->y + pic_hgt - 1);
            }
            break;
        }
        this->draw_area->Unlock("panel_ez::draw_background");
    }

bevels:
    if (this->use_bevels) {
        if (this->draw_area->Lock("panel_ez::draw_background2", 1)) {
            this->draw_area->DrawBevel3(this->x, this->y, this->x + this->width - 1, this->y + this->height - 1,
                                        this->bevel_color1, this->bevel_color2, this->bevel_color3,
                                        this->bevel_color4, this->bevel_color5, this->bevel_color6);
            this->draw_area->Unlock("panel_ez::draw_background2");
        }
    }
    this->post_draw();
}
