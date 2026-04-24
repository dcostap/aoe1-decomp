// From basegame.cpp
// matched via variant lab: raw int* pointer with indices [-1],[0],[1],[4],[5],[6]
// do-while(--i) with stride 8, not for-loop or struct access

struct RGE_Timing_Info {
    int last_time;
    int accum_time;
    int field_04;
    char gap_08[8];
    int field_10;
    int field_14;
    int field_18;
};

class RGE_Base_Game {
public:
    char gap_00[0x504];
    int frame_count;
    int world_update_count;
    int view_update_count;
    int last_frame_count;
    int last_world_update_count;
    int last_view_update_count;
    int fps;
    int world_update_fps;
    int view_update_fps;
    char gap_528[4];
    RGE_Timing_Info timings[0x1E];

    void reset_timings();
};

void RGE_Base_Game::reset_timings() {
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
    this->last_frame_count = 0;
    this->last_world_update_count = 0;
    this->last_view_update_count = 0;
    this->fps = 0;
    this->world_update_fps = 0;
    this->view_update_fps = 0;

    int i = 0x1E;
    int* t = (int*)this->timings;
    do {
        t[-1] = 0;
        t[0] = 0;
        t[1] = 0;
        t[4] = 0;
        t[5] = 0;
        t[6] = 0;
        t += 8;
    } while (--i != 0);
}
