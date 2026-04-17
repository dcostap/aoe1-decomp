class TCommunications_Handler {
public:
    int IsPlayerHuman(unsigned int player);
};

class RGE_Communications_Speed {
public:
    char gap_00[0x108];
    TCommunications_Handler* Comm;
    char gap_10C[0x38];
    unsigned int ActualLatency[10];
    char gap_16C[0xA0];
    unsigned long HighestLatencyMsec;

    unsigned char GetHighLatencyCenti(void);
};

unsigned char RGE_Communications_Speed::GetHighLatencyCenti(void) {
    unsigned int high_latency;
    unsigned int player;
    unsigned int* latency;

    high_latency = 0;
    player = 1;
    latency = &this->ActualLatency[1];
    do {
        if (this->Comm->IsPlayerHuman(player) != 0) {
            if (high_latency <= *latency) {
                high_latency = *latency;
            }
        }
        player++;
        latency++;
    } while (player <= 9);

    this->HighestLatencyMsec = high_latency;
    high_latency = (high_latency + 5) / 10;
    if (high_latency <= 1) {
        high_latency = 1;
    }
    if (high_latency >= 0xFF) {
        high_latency = 0xFF;
    }
    return (unsigned char)high_latency;
}
