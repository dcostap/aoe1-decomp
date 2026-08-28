#ifndef AOE1_RPNL_TIM_H
#define AOE1_RPNL_TIM_H

// PDB source module: C:\\msdev\\work\\age1_x1\\rpnl_tim.cpp.
// This header owns only RGE_Panel_Time.

#include "panel.h"

class RGE_Panel_Time : public TPanel {
public:
    void* font;
    long game_time;
    long last_game_time;
    long old_time;
    long real_time;

    RGE_Panel_Time(TDrawArea*, TPanel*, void*);
    virtual ~RGE_Panel_Time();
    virtual void draw();
    virtual long handle_idle();
};

typedef char rpnl_tim_panel_size_check[
    (sizeof(RGE_Panel_Time) == 0x108) ? 1 : -1];

#endif
