// VA: 0047ACC0 TScrollBarPanel::handle_idle
// PDB: Pnl_scbr.cpp lines 292-340
// BINARY NOTE: The two rectangle tests call the inherited TPanel
// is_inside_rect helper. A canonical TPanel base recovers both direct symbols
// without changing the idle state machine or its fault order.
#ifndef PNL_SCBR_CANONICAL_TU
#include "../../include/pnl_scbr_context.h"
#endif

long TScrollBarPanel::handle_idle() {
    switch (this->state) {
    case 2: {
        if (this->active == 0) return 0;
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp", 306);
        if (now - this->last_time < this->repeat_time) return 0;
        this->last_time = now;
        switch (this->action_type) {
        case 1:
            this->scroll(0,0); return 0;
        case 2:
            this->scroll(1,0); return 0;
        case 3:
            if (!this->is_inside_rect(this->mouse_x, this->mouse_y, &this->rect1)) {
                this->active = 0; this->state = 0;
                this->redraw(1);
                return 0;
            }
            this->scroll(2,0); return 0;
        case 4:
            this->scroll(2,0); return 0;
        case 5:
            if (!this->is_inside_rect(this->mouse_x, this->mouse_y, &this->rect2)) {
                this->active = 0; this->state = 0;
                this->redraw(1);
                return 0;
            }
            this->scroll(3,0); return 0;
        }
        break;
    }
    case 1: {
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp", 296);
        if (now - this->last_time >= this->initial_time) {
            this->state = 2;
            this->last_time = now - this->repeat_time;
        }
        break;
    }
    }
    return 0;
}
