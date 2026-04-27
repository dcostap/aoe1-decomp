// 0048A680 RGE_Panel_Time::RGE_Panel_Time
// Source: rpnl_tim.cpp lines 30-41
//
// Attempt log:
// (inherited from original scratch) — tried plain body + /GX, VC5 stayed in non-EH basin
// Root cause: TPanel base class needs virtual destructor declared to trigger FS:[0] EH prolog
// Probe 6: Added virtual ~TPanel(), /GX flag, correct RGE_Panel_Time vtable with draw/handle_idle

#include "..\..\include\game_globals.h"

class TDrawArea;
class TPanel;

class TPanel {
public:
    char gap_00[0x7C];
    int field_80;
    char gap_84[0x54];
    int field_D8;
    char gap_DC[0x18];

    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual long vf0C();
    virtual long handle_idle();

    TPanel();
    long setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height, unsigned char modal);
};

class RGE_Panel_Time : public TPanel {
public:
    void* font;
    unsigned long game_time;
    unsigned long last_game_time;
    int old_time;
    unsigned long real_time;

    virtual ~RGE_Panel_Time();
    virtual void* scalar_deleting_destructor(unsigned int);
    virtual long draw();
    virtual long handle_idle();

    RGE_Panel_Time(TDrawArea* draw_area, TPanel* parent, void* font_arg);
};

RGE_Panel_Time::RGE_Panel_Time(TDrawArea* draw_area, TPanel* parent, void* font_arg) : TPanel() {
    this->font = font_arg;
    this->field_80 = 0;
    this->game_time = 0;
    this->last_game_time = 0;
    this->old_time = -1;
    if (!this->setup(draw_area, parent, 0, 0, 0, 0, 0)) {
        this->field_D8 = 1;
    }
}
