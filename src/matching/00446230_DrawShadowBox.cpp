// VA: 00446230 TDrawArea::DrawShadowBox (271 B)
// PDB source: Drawarea.cpp, lines 4356-4409
//
// Baseline reconstruction: clip the requested rectangle to the draw area's
// clip rectangle and surface, then apply the configured shadow color table to
// each pixel in the resulting rectangle.
//
// Exact recovery notes:
// - The executable clips all four inputs in place before it tests the final rectangle.
// - Each orientation branch forms the first row pointer directly.
// - The row loop resets one pixel cursor, translates each byte, and advances both row bounds.
// - The first exact transition added the period-supported stdlib header to this source shape.
// - Removing stdlib produced 72 differing bytes. The header is required.
// - Splitting row formation, grouping the row-end delta, and removing one scope stayed exact.
// - Replacing local layout gaps with PDB-backed DirectDraw fields stayed exact.
// - No custom flags, aliases, fake volatility, or synthetic predecessor functions are present.

#include <stdlib.h>

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct _DDCOLORKEY {
    unsigned long dwColorSpaceLowValue;
    unsigned long dwColorSpaceHighValue;
};

struct _DDPIXELFORMAT {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwFourCC;
    unsigned long dwRGBBitCount;
    unsigned long dwRBitMask;
    unsigned long dwGBitMask;
    unsigned long dwBBitMask;
    unsigned long dwRGBAlphaBitMask;
};

struct _DDSCAPS {
    unsigned long dwCaps;
};

struct _DDSURFACEDESC {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwHeight;
    unsigned long dwWidth;
    long lPitch;
    unsigned long dwBackBufferCount;
    unsigned long dwMipMapCount;
    unsigned long dwAlphaBitDepth;
    unsigned long dwReserved;
    void* lpSurface;
    _DDCOLORKEY ddckCKDestOverlay;
    _DDCOLORKEY ddckCKDestBlt;
    _DDCOLORKEY ddckCKSrcOverlay;
    _DDCOLORKEY ddckCKSrcBlt;
    _DDPIXELFORMAT ddpfPixelFormat;
    _DDSCAPS ddsCaps;
};

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char color_table_name[30];
    short resource_id;
    unsigned char type;
    unsigned char map_color;
    short id;
    unsigned char table[256];
};

class TDrawSystem;
class BITMAPINFO256;
class IDirectDrawSurface;
class DrawAreaNode;
class TSpan_List_Manager;

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void* Wnd;
    unsigned char* Bits;
    BITMAPINFO256* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    int Width;
    int Height;
    int Pitch;
    int Orien;
    tagRECT ClipRect;
    void* DrawDc;
    IDirectDrawSurface* DrawSurface;
    _DDSURFACEDESC SurfaceDesc;
    DrawAreaNode* Node;
    char* Name;
    unsigned char* LastBits;
    int LastPitch;
    void** DisplayOffsets;
    void** CurDisplayOffsets;
    void** FloatOffsets;
    RGE_Color_Table* shadow_color_table;
    TSpan_List_Manager* SpanList;
    TSpan_List_Manager* CurSpanList;
    int Float_X_Delta;
    int Float_Y_Delta;
    int DisplayOffsetsSz;
    int FloatOffsetsSz;
    int SystemMemOnly;
    int UsingVidMem;
    int UseTrans;
    int IsPrimarySurface;
    int Restored;
    int ExtendedLines;
    unsigned char TransColor;
    unsigned char _pad_end[3];

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

        long orientation = this->Orien;
        long row_pitch = this->AlignedWidth() * orientation;

        unsigned char* row_start;
        unsigned char* row_end;
        unsigned char* pixel;
        unsigned char* table;

        if (orientation < 1) {
            row_start = this->Bits + x1;
            row_start += (y1 - this->Height + 1) * row_pitch;
        }
        else {
            row_start = this->Bits + x1;
            row_start += row_pitch * y1;
        }

        row_end = row_start + (x2 - x1);
        table = this->shadow_color_table->table;

        if (y1 <= y2) {
            int row_count = (y2 - y1) + 1;
            do {
                pixel = row_start;
                for (; pixel <= row_end; pixel++) {
                    *pixel = table[*pixel];
                }
                row_start += row_pitch;
                row_end += row_pitch;
                row_count--;
            } while (row_count != 0);
        }
    }
}
