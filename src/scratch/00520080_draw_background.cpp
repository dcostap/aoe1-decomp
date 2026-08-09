// 00520080 Time_Line_Panel::draw_background
// Source: tpnl_tml.cpp lines 1062-1120
// Attempt log:
// 1: natural decompiler-shaped tiling/fill/bevel paths; behavior/call set close, edit diff ~86B.
// 2: fixed the height tile-count source to match the original's odd uninitialized-local fallthrough when pic_h < panel_h; edit diff improved to 76B.
// 3: tried y-coordinate named local before shape_draw; VC5 optimized to the same scheduling.
// 4: tried reversed x/y expression term order; no codegen change.
// 5: tried void return for TShape::shape_draw; no codegen change.
// 6: tried narrow unsigned-char zero args for shape_draw tail parameters; no codegen change.
// 7: tried explicit draw_x/draw_y locals; no codegen change.
// 8: tried compound assignment draw_y/draw_x spelling to force original register sequence; no codegen change.
// 9: tried swapping local declaration order; no codegen change.
// 10: tried short locals and for-loop spelling; worsened diff, reverted.
// 11: corrected TShape::shape_draw to the executable unsigned-char/long/uchar ABI;
//     emitted code was unchanged, but the living declaration now has the exact symbol surface.
// 12: mirrored the same-TU donor's y-then-x named temporaries; VC5 emitted the
//     same tiled loop, so the direct canonical expressions were restored.
// 13: made both tile-count locals short without casts; this worsened the height
//     branch and was restored to the int locals that preserve the observed stack stores.
// Left in scratch: remaining drift is localized mostly to the tiled shape_draw loop scheduling/argument setup, causing 4-byte shift in the first branch and branch-target displacement drift; fill/bevel tails look behaviorally aligned.

class TDrawArea {
public:
    unsigned char* Lock(char* tag, int flag);
    void Unlock(char* tag);
    void FillRect(long left, long top, long right, long bottom, unsigned char color);
};

class TShape {
public:
    unsigned char shape_draw(TDrawArea* area, long x, long y, long a,
                             unsigned char b, unsigned char* c);
};

struct Rect4 { long left; long top; long right; long bottom; };

class TBevelLike {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30();
    virtual void draw_low(Rect4* r);   // +34
    virtual void v38();
    virtual void draw_high(Rect4* r);  // +3C
    char gap_04[0x80];
    int flag_84;
};

class Time_Line_Panel {
public:
    void* vtbl;                 // +0
    char gap_04[8];
    long x;                     // +0x0C
    long y;                     // +0x10
    long width;                 // +0x14
    long height;                // +0x18
    char gap_1C[4];
    TDrawArea* render_area;      // +0x20
    Rect4 rect;                  // +0x24
    char gap_34[0x0C];
    TBevelLike* bevel;           // +0x40
    char gap_44[0x468];
    TShape* background_pic;      // +0x4AC
    short background_pic_wid;    // +0x4B0
    short background_pic_hgt;    // +0x4B2
    int fill_back;               // +0x4B4
    unsigned char back_color;    // +0x4B8
    char gap_4B9[0x0F];
    int bevel_type;              // +0x4C8

    void draw_background();
};

void Time_Line_Panel::draw_background()
{
    int pic_rows;
    int tile_rows;

    if (this->background_pic != 0) {
        if (this->render_area->Lock("tpnl_tml::draw_background", 1) == 0) {
            return;
        }

        int pic_w = this->background_pic_wid;
        int panel_w = this->width;
        if (pic_w >= panel_w) {
            pic_rows = 1;
        } else {
            pic_rows = panel_w / pic_w;
            if ((short)pic_rows * pic_w < panel_w) {
                pic_rows++;
            }
        }

        int pic_h = this->background_pic_hgt;
        int panel_h = this->height;
        if (pic_h >= panel_h) {
            tile_rows = panel_h / pic_h;
            if ((short)tile_rows * pic_h < panel_h) {
                tile_rows++;
            }
        }

        if ((short)tile_rows > 0) {
            int row = 0;
            tile_rows = (short)tile_rows;
            do {
                if ((short)pic_rows > 0) {
                    int col = 0;
                    int count = (short)pic_rows;
                    do {
                        this->background_pic->shape_draw(this->render_area,
                            this->x + col * this->background_pic_wid,
                            this->y + row * this->background_pic_hgt,
                            0, 0, 0);
                        col++;
                        count--;
                    } while (count != 0);
                }
                row++;
                tile_rows--;
            } while (tile_rows != 0);
        }

        this->render_area->Unlock("tpnl_tml::draw_background");
        return;
    }

    if (this->fill_back != 0) {
        if (this->render_area->Lock("tpnl_tml::draw_background2", 1) == 0) {
            return;
        }
        this->render_area->FillRect(this->x, this->y,
            this->x + this->width - 1,
            this->y + this->height - 1,
            this->back_color);
        this->render_area->Unlock("tpnl_tml::draw_background2");
        return;
    }

    if (this->bevel != 0) {
        if (this->bevel_type >= 2 && this->bevel_type <= 7) {
            this->bevel->draw_high(&this->rect);
            return;
        }
        if (this->bevel->flag_84 == 0) {
            this->bevel->draw_low(&this->rect);
        }
    }
}
