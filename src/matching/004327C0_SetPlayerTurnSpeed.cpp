class RGE_Communications_Speed {
public:
    char gap_00[0x1BC];
    unsigned long PlayerAvgFramesMsec[10];
    unsigned long PlayerHighLatencyMsec[10];

    void SetPlayerTurnSpeed(unsigned int player, unsigned char avg_frames_msec, unsigned char high_latency);
};

void RGE_Communications_Speed::SetPlayerTurnSpeed(unsigned int player, unsigned char avg_frames_msec, unsigned char high_latency) {
    if (player < 1 || player > 9) {
        return;
    }
    this->PlayerAvgFramesMsec[player] = avg_frames_msec;
    this->PlayerHighLatencyMsec[player] = high_latency * 10;
}
