// VA: 00446230 TDrawArea::DrawShadowBox (271 B)
// PDB source: Drawarea.cpp, lines 4356-4409
//
// Baseline reconstruction: clip the requested rectangle to the draw area's
// clip rectangle and surface, then apply the configured shadow color table to
// each pixel in the resulting rectangle.
//
// Attempt log:
// - Replaced the prior FillRect/DrawBevel scaffold with the binary-supported
//   TDrawArea/RGE_Color_Table ownership and the AlignedWidth row scan.
// - Parameter-left clipping comparisons plus a negative invalid-rectangle
//   guard recovered the original prologue, CFG, call set, and most bytes.
// - Pointer/table declaration, address-term, and running-cursor variants were
//   duplicate or worse; best retained output is 273 bytes, 47 differing
//   positional bytes, with the residual confined to row-pointer scheduling.
// - Main-agent audit replaced the raw color-table vptr field with its canonical
//   virtual destructor surface; the validated gap is 48 bytes with unchanged
//   size, calls, frame, and instruction shape.

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct RGE_Color_Table {
    virtual ~RGE_Color_Table();
    char color_table_name[30];
    short resource_id;
    unsigned char type;
    unsigned char map_color;
    short id;
    unsigned char table[256];
};

class TDrawArea {
public:
    void* DrawSystem;
    void* Wnd;
    unsigned char* Bits;
    void* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    long Width;
    long Height;
    long Pitch;
    long Orien;
    tagRECT ClipRect;
    char gap_38[0x90];
    RGE_Color_Table* shadow_color_table;

    long AlignedWidth();
    void DrawShadowBox(long x1, long y1, long x2, long y2);
};

void TDrawArea::DrawShadowBox(long x1, long y1, long x2, long y2)
{
    if (this->shadow_color_table != 0 && this->Bits != 0) {
        if (x1 < this->ClipRect.left) {
            x1 = this->ClipRect.left;
        }
        if (y1 < this->ClipRect.top) {
            y1 = this->ClipRect.top;
        }
        if (x2 > this->ClipRect.right) {
            x2 = this->ClipRect.right;
        }
        if (y2 > this->ClipRect.bottom) {
            y2 = this->ClipRect.bottom;
        }
        if (x1 < 0) {
            x1 = 0;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (x2 >= this->Width) {
            x2 = this->Width - 1;
        }
        if (y2 >= this->Height) {
            y2 = this->Height - 1;
        }

        if (x2 < x1 || y2 < y1) {
            return;
        }

        {
            long orientation = this->Orien;
            long row_pitch = this->AlignedWidth() * orientation;
            unsigned char* row_start;
            unsigned char* row_end;
            unsigned char* table;
            long row_offset;

            if (orientation < 1) {
                row_offset = (y1 - this->Height + 1) * row_pitch;
            }
            else {
                row_offset = row_pitch * y1;
            }

            row_start = this->Bits + row_offset + x1;
            row_end = row_start + (x2 - x1);
            table = this->shadow_color_table->table;

            if (y1 <= y2) {
                int row_count = (y2 - y1) + 1;
                unsigned char* pixel = row_start;
                do {
                    for (; pixel <= row_end; pixel++) {
                        *pixel = table[*pixel];
                    }
                    row_start += row_pitch;
                    row_end += row_pitch;
                    row_count--;
                    pixel = row_start;
                } while (row_count != 0);
            }
        }
    }
}
