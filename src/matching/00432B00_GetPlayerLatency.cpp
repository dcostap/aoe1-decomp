class RGE_Communications_Speed {
public:
    char gap_00[0x144];
    unsigned long ActualLatency[10];

    unsigned long GetPlayerLatency(unsigned int player);
};

unsigned long RGE_Communications_Speed::GetPlayerLatency(unsigned int player) {
    if (player < 1 || player > 9) {
        return 0;
    }
    return this->ActualLatency[player];
}
