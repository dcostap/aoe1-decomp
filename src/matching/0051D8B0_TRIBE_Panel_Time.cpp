#ifndef TPNL_TIM_SHARED_CONTEXT
class TDrawArea;
struct HRGN__;
typedef HRGN__* HRGN;

extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* obj);
void operator delete(void* ptr);

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();

    char gap_00[0x10];
    long pnl_wid;
    long pnl_hgt;
    char gap_1C[0x4];
    void* render_area;
    char gap_24[0xCF];
    unsigned char field_F3;
};

class TRIBE_Panel_Time : public TPanel {
public:
    char gap_F4[0x3C];
    HRGN image_clip_region;
    TDrawArea* image_buffer;

    virtual ~TRIBE_Panel_Time();
};

class TDrawArea {
public:
    ~TDrawArea();
};
#else
#include "../../include/tpnl_tim_context.h"
#endif

TRIBE_Panel_Time::~TRIBE_Panel_Time() {
    TDrawArea* image_buffer;

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
}
