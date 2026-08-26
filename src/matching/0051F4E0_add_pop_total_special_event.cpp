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
// Probe 7: Moved event=3 and pop_total=pop_total before the remaining zero-fill.
//   This produced the original register colors, late event/pop/icon stores, and
//   the exact 124-byte target. Walkback of only this source-order change restored
//   the 6-byte permutation.
// Exact: 124/124 bytes, 0 strict diff, exact frame/call/CFG/relocation identity.
// BINARY NOTE: the target allocates a zeroed 0xB0-byte Special_Events record,
// writes the four parameters and event value 3, then prepends the record at
// Time_Line_Panel::time_slice_events (+0x518).
// BINARY NOTE: event and pop_total are assigned before the remaining zero
// stores in source; VC5 schedules their final stores in the original late group.

#include "../../include/tpnl_tml_context.h"

extern "C" void* calloc(unsigned int count, unsigned int size);

void Time_Line_Panel::add_pop_total_special_event(long time_slice, long pop_total, long X_line_pos, int icon_flag) {
    Special_Events* se = (Special_Events*)calloc(1, 0xB0);

    se->time_slice = time_slice;
    se->X_line_pos = X_line_pos;
    se->Y_line_pos = 0;
    se->intermediate_y_line_segment = 0;
    se->player_id = 0;
    se->player_color = 0;
    se->event = 3;
    se->pop_total = pop_total;
    se->integer_value_1 = 0;
    se->integer_value_2 = 0;
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
    se->icon_flag = icon_flag;
    se->next = this->time_slice_events;
    this->time_slice_events = se;
}
