// taiinfmd.cpp:8565-8574, 105 bytes
// attempt 1: 95.2%, vptr shifted all offsets
// attempt 2: 77.1%, offsets correct, register/order diff
// attempt 3: 77.1%, denom order change no help
// attempt 4: 96 bytes, (mapX+3)>>2 too compact
// attempt 5: 77.1%, same as attempt 2
// BEST: 77.1%. BLOCKER: VC5 uses edi for mapX (not esi), computes full denom
//   before qy (not interleaved), extra push for locals. Register allocation at
//   entry cascades through entire function. Math is correct, field offsets match.
class TribeInformationAIModule {
public:
    virtual void vf00();
    char gap_04[0x104 - 0x04];
    int mapX;
    int mapY;

    int percentTilesExploredInPositionQuadrant(int param1, int param2);
};

int TribeInformationAIModule::percentTilesExploredInPositionQuadrant(int param1, int param2) {
    if (mapX == -1) {
        return 0;
    }
    int qx = (param1 * 4) / mapX;
    int denom = ((mapX + (mapX >> 31 & 3)) >> 2) * mapY;
    int qy = (param2 * 4) / mapY;
    denom = (denom + (denom >> 31 & 3)) >> 2;
    int idx = (qy + qx * 4 + 0x56) * 3;
    int* table = (int*)this;
    int value = table[idx];
    return (value * 100) / denom;
}
