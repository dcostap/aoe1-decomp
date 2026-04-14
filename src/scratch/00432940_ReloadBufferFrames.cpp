class TurnTimer_rbf {
public:
    void Reset(void);
};

class RGE_Communications_Speed_rbf {
public:
    void ReloadBufferFrames(void);
    void AdjustLocalSpeed(void);
    char gap_00[0x100];
    TurnTimer_rbf* turn_timer;
    char gap_104[0x18];
    int buffer_frames;
    char gap_120[0x04];
    int current_buffer;
    char gap_128[0x10C];
    int dropped_frames;
};

void RGE_Communications_Speed_rbf::ReloadBufferFrames(void) {
    this->turn_timer->Reset();
    this->dropped_frames = 0;
    this->AdjustLocalSpeed();
    this->current_buffer = this->buffer_frames;
}
