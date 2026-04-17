class RGE_Communications_Speed_sal {
public:
    void SetActualLatency(unsigned int player, unsigned long latency);
    char gap_00[0x148];
    int actual_latency[1];
};

void RGE_Communications_Speed_sal::SetActualLatency(unsigned int player, unsigned long latency) {
    if ((player != 0) && (player < 10)) {
        if (latency < 30) {
            latency = 30;
        }
        if (6000 < latency) {
            latency = 6000;
        }
        this->actual_latency[player] = (int)latency;
    }
}
