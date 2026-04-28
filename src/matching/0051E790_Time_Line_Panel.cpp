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

#include <stdlib.h>     // free
#include <new.h>        // operator delete

struct Special_Events {
    char _gap_00[0xAC];
    Special_Events* next;            // +0xAC
};

struct TShape {
    char _gap_00;
    ~TShape();
};

struct TPanel {
    // compiler-managed vtable ptr at +0x00
    void delete_panel(TPanel** panel);
    virtual ~TPanel();
};

struct TEasy_Panel : public TPanel {
    char _gap_04[0x474];            // +0x04-0x477
    virtual ~TEasy_Panel();
};

struct Time_Line_Panel : public TEasy_Panel {
    char _gap_478[0x34];             // +0x478-0x4AB
    TShape* background_pic;          // +0x4AC
    char _gap_4B0[0x24];            // +0x4B0-0x4D3
    TShape* special_events_pic;      // +0x4D4
    char _gap_4D8[0x40];            // +0x4D8-0x517
    Special_Events* time_slice_events; // +0x518
    char _gap_51C[0x04];            // +0x51C-0x51F
    TPanel* legend_entry_text[3];    // +0x520

    virtual ~Time_Line_Panel();
};

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
        this->delete_panel(&this->legend_entry_text[i]);
    }

}
