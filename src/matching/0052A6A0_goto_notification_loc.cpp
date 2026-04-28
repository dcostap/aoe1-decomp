// 0052A6A0 TRIBE_Game::goto_notification_loc
// Source: tribegam.cpp lines 5671-5691. 129 bytes. __thiscall.
//
// MATCHED. Exact 129-byte match confirmed via local check_function.py.
// Probe 3: nested chained call get_player()->set_view_loc(fx, fy)
// forces right-to-left arg eval: float conversions before get_player.
//
// Attempt log:
// - probe 1: inheritance from RGE_Base_Game → offsets wrong (28.7% diff)
// - probe 2: flat class + separate get_player/set_view_loc → 13.2% diff (scheduling)
// - probe 3: nested chained call → 0% diff

class RGE_Player;

class RGE_Base_Game {
public:
    RGE_Player* get_player();
};

class RGE_Player {
public:
    void set_view_loc(float x, float y);
};

class TRIBE_Game {
public:
    char gap_00[0xC28];
    long notification_loc_x[5];  // +0xC28
    long notification_loc_y[5];  // +0xC3C
    long current_notification_loc;     // +0xC50
    long current_notification_recalled; // +0xC54

    void goto_notification_loc();
};

void TRIBE_Game::goto_notification_loc() {
    if (this->current_notification_recalled == -1)
        return;

    long x = this->notification_loc_x[this->current_notification_recalled];
    long y = this->notification_loc_y[this->current_notification_recalled];

    this->current_notification_recalled--;

    if (this->current_notification_recalled < 0)
        this->current_notification_recalled = 4;

    if (this->notification_loc_x[this->current_notification_recalled] == -1 ||
        this->notification_loc_y[this->current_notification_recalled] == -1) {
        this->current_notification_recalled = this->current_notification_loc;
    }

    ((RGE_Base_Game*)this)->get_player()->set_view_loc((float)x, (float)y);
}
