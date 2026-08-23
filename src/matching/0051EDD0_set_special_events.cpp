// VA: 0051EDD0 Time_Line_Panel::set_special_events (258 B, EXACT MATCH)
// PDB source: tpnl_tml.cpp lines 321-341
// Key insight: function-scope locals force the 16-byte sub area to be fully
// occupied, leaving the param_1 slot available for operator_new result reuse.
// Must use /GX flag for EH prologue (delete + new with throwing constructor).
// BINARY NOTE: this owner uses the shared tpnl_tml.cpp timeline and TShape surfaces.

#include "../../include/tpnl_tml_context.h"

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

int Time_Line_Panel::set_special_events(char* param_1) {
    long x_min;
    long y_max;
    long y_min;
    long loc;
    if (this->special_events_pic) {
        delete this->special_events_pic;
        this->special_events_pic = 0;
        this->special_events_pic_wid = 0;
        this->special_events_pic_hgt = 0;
    }
    if (param_1 && *param_1) {
        this->special_events_pic = new TShape(param_1, -1);
        this->special_events_pic->shape_minmax(&y_max, &loc, &x_min, &y_min, 0);
        this->special_events_pic_wid = (short)(x_min - y_max + 1);
        this->special_events_pic_hgt = (short)(y_min - loc + 1);
        return 1;
    }
    return 0;
}
