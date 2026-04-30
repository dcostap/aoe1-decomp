// TListPanel::mouse_left_move_action

class TListPanel {
public:
    char gap_00[0x10];
    long pnl_y;                          // 0x10
    char gap_14[4];                      // 0x14
    long pnl_height;                     // 0x18
    char gap_1C[0x170];
    int mouse_scroll_last_time;          // 0x18C
    int mouse_scroll_interval;           // 0x190
    int mouse_scroll_up;                 // 0x194
    int mouse_scroll_down;               // 0x198
    char gap_19C[0x64];

    void goto_item(long param_1, long param_2);
    long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4);
};

extern "C" unsigned long __cdecl debug_timeGetTime(char* param_1, int param_2);

long TListPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) {
    if (param_2 < this->pnl_y) {
        this->mouse_scroll_down = 0;
        if (this->mouse_scroll_up != 0)
            return 1;
        this->mouse_scroll_up = 1;
        this->mouse_scroll_last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp", 0xB1) - this->mouse_scroll_interval;
        return 1;
    }

    if (param_2 >= this->pnl_y + this->pnl_height) {
        if (param_2 > this->pnl_y + this->pnl_height - 1) {
            this->mouse_scroll_up = 0;
            if (this->mouse_scroll_down != 0)
                return 1;
            this->mouse_scroll_down = 1;
            this->mouse_scroll_last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp", 0xBA) - this->mouse_scroll_interval;
            return 1;
        }
        this->mouse_scroll_up = 0;
        this->mouse_scroll_down = 0;
        return 1;
    }

    this->mouse_scroll_up = 0;
    this->mouse_scroll_down = 0;
    this->goto_item(param_1, param_2);
    return 1;
}
