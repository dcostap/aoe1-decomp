// VA: 0051F4E0 Time_Line_Panel::add_pop_total_special_event()
// Source: tpnl_tml.cpp lines 544-575
// Size: 124 bytes, __thiscall, ret 10h (4 params)
//
// Attempt log:
// Probe 1: Natural struct with field-order assignments — 6 bytes diff
//   Pure register allocation: original uses edx=pop_total, ecx=icon_flag
//   Rebuilt reverses: ecx=pop_total, edx=icon_flag
// Probe 2: Moved pop_total assignment up (before zero-fill) — worse (21 bytes)
// Probe 3: Swapped icon_flag before pop_total in source — fixed reg alloc, reversed store order
// Probe 4: Exact struct types from type dump — still 6 bytes (edx/ecx swap)
// Probe 5: const locals for pop_total/icon_flag — still 6 bytes
// Probe 6: Renamed params (pt/iflg) + icon_flag first in source — fixed regs, wrong store order
//
// Remaining 6 bytes: pure VC5 register allocation symmetry
//   Original: edx=pop_total, ecx=icon_flag, edx=time_slice_events
//   Rebuilt:  edx=icon_flag, ecx=pop_total, ecx=time_slice_events
//   All behaviorally identical (params are symmetric for the allocator)
//   Store order matches, zero-fill matches, calloc matches
//   Cannot break the register symmetry from C++ source alone.
// Parked in scratch per Boss direction.

struct Special_Events {
    long time_slice;                    // +0x00
    long X_line_pos;                    // +0x04
    long Y_line_pos;                    // +0x08
    long intermediate_y_line_segment;   // +0x0C
    unsigned char player_id;             // +0x10
    unsigned char player_color;          // +0x11
    unsigned char event;                 // +0x12
    unsigned char _gap_13[1];            // +0x13 padding
    long pop_total;                     // +0x14
    long interger_value_1;              // +0x18
    long interger_value_2;              // +0x1C
    long start_x;                       // +0x20
    long start_y;                       // +0x24
    long start_txt_x1;                  // +0x28
    long start_txt_y1;                  // +0x2C
    long start_txt_x2;                  // +0x30
    long start_txt_y2;                  // +0x34
    int text_length1;                   // +0x38
    char text1[50];                     // +0x3C
    unsigned char _pad_1[2];            // +0x6E gap
    int text_length2;                   // +0x70
    char text2[50];                     // +0x74
    unsigned char _pad_2[2];            // +0xA6 gap
    int icon_flag;                      // +0xA8
    Special_Events* next;               // +0xAC
};

// Total: 0xB0 bytes

class Time_Line_Panel {
public:
    char _gap_00[0x518];
    Special_Events* time_slice_events;  // +0x518

    void add_pop_total_special_event(long time_slice, long pop_total, long X_line_pos, int icon_flag);
};

extern "C" void* calloc(unsigned int count, unsigned int size);

void Time_Line_Panel::add_pop_total_special_event(long time_slice, long pop_total, long X_line_pos, int icon_flag) {
    Special_Events* se = (Special_Events*)calloc(1, 0xB0);

    se->time_slice = time_slice;
    se->X_line_pos = X_line_pos;
    se->Y_line_pos = 0;
    se->intermediate_y_line_segment = 0;
    se->player_id = 0;
    se->player_color = 0;
    se->interger_value_1 = 0;
    se->interger_value_2 = 0;
    se->start_x = 0;
    se->start_y = 0;
    se->start_txt_x1 = 0;
    se->start_txt_y1 = 0;
    se->start_txt_x2 = 0;
    se->start_txt_y2 = 0;
    se->text_length1 = 0;
    se->text1[0] = 0;
    se->text_length2 = 0;
    se->text2[0] = 0;
    se->event = 3;
    se->pop_total = pop_total;
    se->icon_flag = icon_flag;
    se->next = this->time_slice_events;
    this->time_slice_events = se;
}
