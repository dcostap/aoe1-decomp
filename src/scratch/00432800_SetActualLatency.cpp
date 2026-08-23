class RGE_Communications_Speed_sal {
public:
    void SetActualLatency(unsigned int player, unsigned long latency);
    char gap_00[0x144];
    unsigned long actual_latency[1];
};

void RGE_Communications_Speed_sal::SetActualLatency(unsigned int player, unsigned long latency) {
    if (player >= 1 && player <= 9) {
        if (latency < 30)
            latency = 30;
        if (latency > 6000)
            latency = 6000;
        this->actual_latency[player] = latency;
    }
}
