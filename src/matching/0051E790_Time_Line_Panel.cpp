// 0051E790 ~Time_Line_Panel (tpnl_tml.cpp:116-141)
// PDB source: tpnl_tml.cpp (Time_Line_Panel::~Time_Line_Panel)
//
// Attempt log:
// attempt 1: manual dtor+op delete; 192/206b, no EH frame.
// attempt 2: delete operator + virtual dtors for EH frame. EXACT MATCH.
// Key: virtual destructors in TPanel/TEasy_Panel/Time_Line_Panel force VC5
//   to emit EH frame (push -1; push handler; mov [fs:0],esp). Automatic base
//   dtor call (not explicit), proper linked-list walk using p->next before free.
//   Offsets: TPanel vtable at +0x00 (compiler-managed). 12 relocations masked.
// BINARY NOTE: this owner shares the complete tpnl_tml.cpp class declarations
// with the earlier constructor and the later create_timeline owner.
// context probe: the authentic ordered group remains an exact 206-byte owner.

#include "../../include/tpnl_tml_context.h"
#include <stdlib.h>     // free
#include <new.h>        // operator delete

Time_Line_Panel::~Time_Line_Panel() {
    Special_Events* p;

    while (this->time_slice_events != NULL) {
        p = this->time_slice_events;
        this->time_slice_events = p->next;
        free(p);
    }

    if (this->background_pic != NULL) {
        delete this->background_pic;
        this->background_pic = NULL;
    }

    if (this->special_events_pic != NULL) {
        delete this->special_events_pic;
        this->special_events_pic = NULL;
    }

    for (int i = 0; i < 3; i++) {
        this->delete_panel((TPanel**)&this->legend_entry_text[i]);
    }

}
