class RGE_Communications_Speed_sfsc {
public:
    void SetFutureSpeedChange(int buffer_frames, int granularity, int turn_change);
    char gap_00[0x120];
    int future_buffer;
    char gap_124[0x0C];
    int future_granularity;
    char gap_134[0x0C];
    int future_turn_change;
};

void RGE_Communications_Speed_sfsc::SetFutureSpeedChange(int buffer_frames, int granularity, int turn_change) {
    if (this->future_turn_change)
        return;
    this->future_buffer = buffer_frames;
    this->future_granularity = granularity;
    this->future_turn_change = turn_change;
}
