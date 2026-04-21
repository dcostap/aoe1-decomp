class RGE_Communications_Speed_sal {
public:
    void SetActualLatency(int player, int latency);
    char gap_00[0x148];
    int actual_latency[1];
};

void RGE_Communications_Speed_sal::SetActualLatency(int player, int latency) {
    if (player < 1 || player > 9)
        return;
    if (latency < 30)
        latency = 30;
    if (latency > 6000)
        latency = 6000;
    this->actual_latency[player] = latency;
}
