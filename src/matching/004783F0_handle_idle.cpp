// TListPanel::handle_idle — exact Pnl_lst.cpp owner.
// The canonical panel surface restores the original compare operand order.

#ifndef AOE1_PNL_LST_CONTEXT_H
extern "C" unsigned long __cdecl debug_timeGetTime(char* param_1, int param_2);
#endif

#ifndef AOE1_PNL_LST_CONTEXT_H
class TPanel {
public:
    long handle_idle();
};

class TListPanel : public TPanel {
public:
    char gap_04[0xF8];
    short num_lines;                  // 0xF8
    short draw_lines;                 // 0xFA
    short top_line;                   // 0xFC
    short bot_line;                   // 0xFE
    short cur_line;                   // 0x100
    char pad_102[0x8A];
    int mouse_scroll_last_time;      // 0x18C
    int mouse_scroll_interval;       // 0x190
    int mouse_scroll_up;             // 0x194
    int mouse_scroll_down;           // 0x198
    char gap_19C[0x64];

    void scroll_cur_line(unsigned char action, short line, int flag);

    long handle_idle();
};
#endif

long TListPanel::handle_idle() {
    TPanel::handle_idle();
    if (this->mouse_scroll_up == 0 && this->mouse_scroll_down == 0)
        return 0;

    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp", 0x6C);
    if (now - this->mouse_scroll_last_time < (unsigned long)this->mouse_scroll_interval)
        return 0;

    this->mouse_scroll_last_time = now;

    if (this->mouse_scroll_up != 0) {
        if (this->cur_line != this->top_line)
            this->scroll_cur_line(1, this->top_line, 1);
        this->scroll_cur_line(3, 0, 1);
        return 0;
    }

    if (this->cur_line != this->bot_line)
        this->scroll_cur_line(1, this->bot_line, 1);
    this->scroll_cur_line(2, 0, 1);
    return 0;
}
