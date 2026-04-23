class RGE_Game_World {
public:
    int world_time;
    int old_world_time;
    int world_time_delta;
    int world_time_delta_seconds;
    int timer;
    int old_time;
    char gap_18[0x04];
    unsigned char temp_pause;
    char gap_1D[0x4B];
    int next_object_id;
    char gap_6C[0x44];
    int player_turn;
    unsigned long player_time_delta[9];

    void reset_object_count(void);
};

void RGE_Game_World::reset_object_count(void) {
    unsigned long* delta;
    int count;

    this->world_time = 0;
    this->old_world_time = 0;
    this->world_time_delta = 0;
    this->world_time_delta_seconds = 0;
    this->timer = 0;
    this->old_time = 0;
    this->temp_pause = 0;
    this->next_object_id = 0;
    this->player_turn = 0;
    delta = this->player_time_delta;
    count = 9;
    do {
        *delta = 0;
        delta = delta + 1;
        count = count - 1;
    } while (count != 0);
}
