#include <new>

// Matches in the tpnl_tim.cpp EH/object-lifetime basin under /GX.
// Keeping one shared image_buffer local and the final `if (image_buffer != 0)` copy path first
// preserves the original saved-register and branch-layout family.

#ifndef TPNL_TIM_SHARED_CONTEXT
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct TDrawSystem {
    char gap_00[0x18];
    long width;
};
struct HRGN__;
typedef HRGN__* HRGN;

extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* obj);
extern "C" __declspec(dllimport) HRGN __stdcall CreateRectRgn(int left, int top, int right, int bottom);

class TDrawArea {
public:
    TDrawSystem* system;
    char gap_04[0x14];
    long width;
    long height;
    char gap_20[0xE0];

    TDrawArea(char* name, int flags);
    ~TDrawArea();
    int Init(TDrawSystem* system, long width, long height, int a5, int a6);
};

void* operator new(unsigned int size);
void operator delete(void* ptr);

char s_time_message_panel[] = "time message panel";

class TPanel {
public:
    char gap_00[0x10];
    long pnl_wid;
    long pnl_hgt;
    char gap_1C[0x4];
    TDrawArea* render_area;
    char gap_24[0xCF];
    unsigned char field_F3;

    virtual void setup();
    virtual void set_color();
    virtual void set_active();
    virtual void set_positioning();
    virtual void set_fixed_position();
    virtual void draw_setup();
    virtual void draw_finish();
    virtual void draw();
    virtual long set_redraw(int);
    virtual long handle_idle();
    virtual void set_rect(long x, long y, long width, long height);
};

class TRIBE_Panel_Time : public TPanel {
public:
    char gap_F4[0x3C];
    HRGN image_clip_region;
    TDrawArea* image_buffer;
    tagRECT image_rect;
    tagRECT used_image_rect;
    tagRECT used_screen_rect;
    int image_text_active;
    long last_ib_width;
    long last_ib_height;

    void set_rect(long x, long y, long width, long height);
};
#else
#include "../../include/tpnl_tim_context.h"
char s_time_message_panel[] = "time message panel";
#endif

void TRIBE_Panel_Time::set_rect(long x, long y, long width, long height) {
    TDrawArea* image_buffer;

    this->TPanel::set_rect(x, y, width, height);

    if (this->pnl_wid <= this->last_ib_width) {
        if (this->pnl_hgt <= this->last_ib_height) {
            if (x + this->last_ib_width < this->render_area->width) {
                goto skip_recreate;
            }
        }
    }

    if (this->image_clip_region != 0) {
        DeleteObject(this->image_clip_region);
        this->image_clip_region = 0;
    }

    image_buffer = this->image_buffer;
    if (image_buffer != 0) {
        image_buffer->~TDrawArea();
        operator delete(image_buffer);
        this->image_buffer = 0;
    }

    image_buffer = new TDrawArea(s_time_message_panel, 0);
    this->image_buffer = image_buffer;
    image_buffer->Init(*(TDrawSystem**)this->render_area, this->pnl_wid, this->pnl_hgt, 0, 0);

    this->last_ib_width = this->pnl_wid;
    this->last_ib_height = this->pnl_hgt;
    this->image_rect.left = 0;
    this->image_rect.top = 0;
    this->image_rect.right = this->pnl_wid - 1;
    this->image_rect.bottom = this->pnl_hgt - 1;
    this->image_clip_region = CreateRectRgn(0, 0, this->pnl_wid - 1, this->pnl_hgt - 1);

skip_recreate:

    if (this->image_buffer != 0) {
        this->used_image_rect = this->image_rect;
    } else {
        this->last_ib_width = -1;
        this->last_ib_height = -1;
    }

    this->field_F3 = 1;
    this->set_redraw(1);
}
