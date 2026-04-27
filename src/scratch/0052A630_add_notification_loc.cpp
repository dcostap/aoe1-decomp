// attempt log:
// first pass: direct guard/update form for the 5-slot notification list
// second pass: add /GX because this sibling family is EH-framed and the default basin was too small
// third pass: keep the slot/index locals explicit so VC5 has the same early arg-load / push-order basin as the asm
// fourth pass: collapsed the compare into one OR-chain so the early rejection matches the original basin without the extra register pressure
// fifth pass: added a slot local, but the body still sits in the wrong 96-byte basin or in a larger mismatched basin
// paused here: layout is right, but VC5 is still picking the wrong early arg-load / push order basin

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
    long slot;

    current = this->current_notification_loc;
    slot = current;
    if (current < 0 || this->notification_loc_x[current] != x || this->notification_loc_y[current] != y) {
        slot = current + 1;
        this->current_notification_loc = slot;
        if (slot >= 5) {
            this->current_notification_loc = 0;
        }
        slot = this->current_notification_loc;
        this->notification_loc_x[slot] = x;
        this->notification_loc_y[slot] = y;
    }
    this->current_notification_recalled = this->current_notification_loc;
}
