// 0051CE40 TRIBE_Panel_Pop::set_rect(long, long, long, long)
// PDB: tpnl_pop.cpp:85-129, 389 bytes
// __thiscall, void
// FLAGS: default + /GX

#ifndef TPNL_POP_SHARED_CONTEXT
#include <stdlib.h>
#include <new.h>

extern "C" void __cdecl operator_delete(void* ptr);

__declspec(dllimport) int __stdcall DeleteObject(void* obj);
__declspec(dllimport) void* __stdcall CreateRectRgn(int left, int top, int right, int bottom);

struct TDrawArea {
    void* draw_sys;       // +0x00
    char gap_04[0x14];    // +0x04 to +0x17
    int width;            // +0x18
    char pad[0xE4];       // +0x1C to +0xFF

    TDrawArea(const char* name, int param);
    ~TDrawArea();
    int Init(void* draw_sys, int w, int h, int x, int y);
};

struct tagRECT {
    int left;
    int top;
    int right;
    int bottom;
};

class TPanel {
public:
    TPanel();
    virtual ~TPanel();
    virtual long setup(TDrawArea* area, TPanel* parent, long a, long b,
                       long c, long d, unsigned char e);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long param_1, long param_2, long param_3,
                          long param_4);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*,
                                 TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    char gap_04[0x10];
    int pnl_wid;           // +0x14
    int pnl_hgt;           // +0x18
    char gap_1C[0x04];
    TDrawArea* render_area; // +0x20
    char gap_24[0xFC];
    void* image_clip_region; // +0x120
    TDrawArea* ImageBuffer;  // +0x124
    tagRECT ImageRect;         // +0x128
    tagRECT UsedImageRect;     // +0x138
    tagRECT gap_RECT;          // +0x148 (third RECT, unused)
    int ImageTextActive;    // +0x158
    int LastIBWidth;        // +0x15C
    int LastIBHeight;       // +0x160
};

class TRIBE_Panel_Pop : public TPanel {
public:
    virtual ~TRIBE_Panel_Pop();
    virtual void set_rect(long param_1, long param_2, long param_3,
                          long param_4);
};
#endif

void TRIBE_Panel_Pop::set_rect(long param_1, long param_2, long param_3, long param_4) {
    TPanel::set_rect(param_1, param_2, param_3, param_4);

    if (this->pnl_wid > this->LastIBWidth) goto need_realloc;
    if (this->pnl_hgt > this->LastIBHeight) goto need_realloc;
    if (param_1 + this->LastIBWidth >= this->render_area->width) goto need_realloc;
    goto skip_realloc;

need_realloc:
    {
        if (this->image_clip_region != 0) {
            DeleteObject(this->image_clip_region);
            this->image_clip_region = 0;
        }

        TDrawArea* buf = this->ImageBuffer;
        if (buf != 0) {
            buf->~TDrawArea();
            operator_delete(buf);
            this->ImageBuffer = 0;
        }

        buf = new TDrawArea("time message panel", 0);

        this->ImageBuffer = buf;

        // Original calls Init even with null buf (same code path)
        buf->Init(this->render_area->draw_sys, this->pnl_wid, this->pnl_hgt, 0, 0);

        this->LastIBWidth = this->pnl_wid;
        this->LastIBHeight = this->pnl_hgt;

        this->ImageRect.left = 0;
        this->ImageRect.top = 0;
        this->ImageRect.right = this->pnl_wid - 1;
        this->ImageRect.bottom = this->pnl_hgt - 1;

        this->image_clip_region = CreateRectRgn(0, 0, this->pnl_wid - 1, this->pnl_hgt - 1);
    }

skip_realloc:
    if (this->ImageBuffer != 0) {
        this->UsedImageRect = this->ImageRect;
    } else {
        this->LastIBWidth = -1;
        this->LastIBHeight = -1;
    }

    *(unsigned char*)((char*)this + 0xF3) = 1;

    this->set_redraw(1);
}
