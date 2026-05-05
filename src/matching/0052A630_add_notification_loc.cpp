// 0052A630 TRIBE_Game::add_notification_loc(long x, long y)
// Source: tribegam.cpp lines 5653-5667
// Attempt 2: use direct field access instead of slot temp to force double reload

class TRIBE_Game {
public:
    char gap_00[0xC28];
    long notification_loc_x[5];
    long notification_loc_y[5];
    long current_notification_loc;
    long current_notification_recalled;

    void add_notification_loc(long x, long y);
};

void TRIBE_Game::add_notification_loc(long x, long y) {
    long current;
    current = this->current_notification_loc;
    if (current < 0 || this->notification_loc_x[current] != x || this->notification_loc_y[current] != y) {
        this->current_notification_loc = current + 1;
        if (this->current_notification_loc >= 5) {
            this->current_notification_loc = 0;
        }
        this->notification_loc_x[this->current_notification_loc] = x;
        this->notification_loc_y[this->current_notification_loc] = y;
    }
    this->current_notification_recalled = this->current_notification_loc;
}
