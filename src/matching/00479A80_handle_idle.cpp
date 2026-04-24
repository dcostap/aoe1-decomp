long debug_timeGetTime(const char* file, int line);

class TMessagePanel {
public:
    char gap_00[0x6C];
    int _padding_;
    char gap_70[0x84];
    int message_type;
    char gap_F8[0x200];
    int showing_message;
    int start_time;
    int show_message_interval;

    void remove_message();
    long handle_idle();
};

long TMessagePanel::handle_idle() {
    if (_padding_ && showing_message) {
        if (message_type == 1 || message_type == 3 || message_type == 4) {
            long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp", 0x1BA);
            if (now - start_time >= show_message_interval) {
                remove_message();
            }
        }
    }
    return 0;
}
