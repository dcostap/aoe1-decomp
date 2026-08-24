// PDB-qualified owner: TRIBE_Panel_Time::get_clock_type in tpnl_tim.cpp,
// lines 205-207. The preceding jump table at 0051DC40 is data owned by
// set_clock_type; this function owns 0051DC60-0051DC66 and ends at 0051DC67.
#ifndef TPNL_TIM_SHARED_CONTEXT
class TRIBE_Panel_Time {
public:
    virtual ~TRIBE_Panel_Time();
    char gap_0[0xFC];
    int clock_type;
    int get_clock_type();
};
#else
#include "../../include/tpnl_tim_context.h"
#endif

int TRIBE_Panel_Time::get_clock_type() { return this->clock_type; }
