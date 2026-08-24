// 0047D3D0 TTextPanel::draw_background
// Pnl_txt.cpp:1006-1089
//
// Canonical ownership follows the same panel/draw-area/background shape used
// by the period TTextPanel siblings and by Time_Line_Panel::draw_background:
// the panel owns the picture, fill flag/color, bevel selector, and its
// position/size; the draw area owns Lock/FillRect/Unlock; and the bevel object
// owns the two virtual fallback operations.
//
// Attempt log:
// - Replaced the former field-only scaffold with the natural typed tiled
//   picture, fill, and bevel paths supported by the original CFG and Pnl_txt
//   line bands.  The analogous Time_Line_Panel donor supplies the loop and
//   lock/unlock source shape; target-specific fields are at +0x144..+0x150.
// - Named picture/panel dimensions recovered the donor's ECX/EDI field-load
//   roles and reduced the byte diff from 345 to 259; the natural
//   `int row = 0; int row_count = pic_rows;` declaration order then recovered
//   the original EBX pic-row/EBP row topology and reduced it to 236 bytes.
// - Reversed short declaration order, split/combined initialization, top-level
//   versus scoped row declarations, coordinate term order, and named y/x
//   temporaries were either neutral or less useful.  Final unresolved drift
//   is localized to the tiled shape_draw arithmetic/scheduling; size/frame,
//   ordered calls, and CFG counts match.  No raw text cursors or compiler
//   steering remain in the living source.
// - The exact Pnl_scbr tiled-draw donor uses the full TShape data surface and
//   Windows SDK context.  Added that period ABI context as a focused probe;
//   the target still keeps named panel fields and direct shape ownership.
// - With that donor context active, swapped the short count declaration order
//   and used the period zero-initializer form for pic_rows to test register
//   ownership without changing the tiled-draw behavior.
// - Replaced the intermediate dimension locals with direct named panel-member
//   expressions, matching the compact period source shape for count setup.
// - The full donor ABI context plus direct named dimensions produced an exact
//   match.  Kept the ordinary typed source; no raw cursor or fake qualifier is
//   needed.

#include <windows.h>

#ifndef PNL_TXT_TU_CONTEXT
class TDrawArea {
public:
    unsigned char* Lock(char* tag, int flag);
    void Unlock(char* tag);
    void FillRect(long left, long top, long right, long bottom,
                  unsigned char color);
};

class TShape {
public:
    unsigned char* shape_data;
    int load_type;
    int load_size;
    void* shape_header;
    void* head;
    void* offsets;
    void* fshape;
    void* shape_info;

    unsigned char shape_draw(TDrawArea* area, long x, long y,
                             long draw_flags, unsigned char palette,
                             unsigned char* table);
};

struct TextPanelRect {
    long left;
    long top;
    long right;
    long bottom;
};

class TBevel {
public:
    virtual void vf_00();
    virtual void vf_04();
    virtual void vf_08();
    virtual void vf_0C();
    virtual void vf_10();
    virtual void vf_14();
    virtual void vf_18();
    virtual void vf_1C();
    virtual void vf_20();
    virtual void vf_24();
    virtual void vf_28();
    virtual void vf_2C();
    virtual void vf_30();
    virtual void draw_low(TextPanelRect* rect);   // +0x34
    virtual void vf_38();
    virtual void draw_high(TextPanelRect* rect);  // +0x3C
    char gap_04[0x80];
    int flag_84;
};

class TTextPanel {
public:
    char gap_00[0x0C];
    long x;                              // +0x0C
    long y;                              // +0x10
    long width;                          // +0x14
    long height;                         // +0x18
    char gap_1C[0x04];
    TDrawArea* render_area;              // +0x20
    TextPanelRect rect;                  // +0x24
    char gap_34[0x0C];
    TBevel* bevel;                       // +0x40
    char gap_44[0x100];
    TShape* back_pic;                    // +0x144
    short back_pic_wid;                  // +0x148
    short back_pic_hgt;                  // +0x14A
    int fill_back;                       // +0x14C
    unsigned char back_color;             // +0x150
    char gap_151[0x1F];
    int bevel_type;                      // +0x170

    void draw_background();
};
#endif

void TTextPanel::draw_background()
{
    short pic_cols;
    short pic_rows = 0;

    if (this->back_pic != 0) {
        if (this->render_area->Lock("pnl_txt::draw_background", 1) == 0) {
            return;
        }

        if (this->back_pic_wid >= this->width) {
            pic_cols = 1;
        } else {
            pic_cols = (short)(this->width / this->back_pic_wid);
            if ((short)pic_cols * this->back_pic_wid < this->width) {
                pic_cols++;
            }
        }

        if (this->back_pic_hgt >= this->height) {
            pic_rows = (short)(this->height / this->back_pic_hgt);
            if ((short)pic_rows * this->back_pic_hgt < this->height) {
                pic_rows++;
            }
        }

        if (pic_rows > 0) {
            int row = 0;
            int row_count = pic_rows;
            do {
                if (pic_cols > 0) {
                    int col = 0;
                    int col_count = (short)pic_cols;
                    do {
                        int draw_y = row * this->back_pic_hgt + this->y;
                        int draw_x = col * this->back_pic_wid + this->x;
                        this->back_pic->shape_draw(
                            this->render_area,
                            draw_x, draw_y,
                            0, 0, 0);
                        col++;
                        col_count--;
                    } while (col_count != 0);
                }
                row++;
                row_count--;
            } while (row_count != 0);
        }

        this->render_area->Unlock("pnl_txt::draw_background");
        return;
    }

    if (this->fill_back != 0) {
        if (this->render_area->Lock("pnl_txt::draw_background2", 1) == 0) {
            return;
        }
        this->render_area->FillRect(
            this->x, this->y,
            this->x + this->width - 1,
            this->y + this->height - 1,
            this->back_color);
        this->render_area->Unlock("pnl_txt::draw_background2");
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
