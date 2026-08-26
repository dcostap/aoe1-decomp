// 0048A680 RGE_Panel_Time::RGE_Panel_Time
// Source: rpnl_tim.cpp lines 30-41
//
// Attempt log:
// (inherited from original scratch) — tried plain body + /GX, VC5 stayed in non-EH basin
// Root cause: TPanel base class needs virtual destructor declared to trigger FS:[0] EH prolog
// Probe 6: Added virtual ~TPanel(), /GX flag, correct RGE_Panel_Time vtable with draw/handle_idle

#include "..\..\include\game_globals.h"
#include "..\..\include\rpnl_tim_context.h"

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
