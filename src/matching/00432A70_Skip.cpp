class RGE_TimeSinceLastCall {
public:
    void Skip(void);
};

class RGE_Communications_Speed {
public:
    char gap_00[0x104];
    RGE_TimeSinceLastCall* FrameTSLC;
    char gap_108[0x134];
    int LastFrameHadTime;

    void Skip(void);
};

void RGE_Communications_Speed::Skip(void) {
    FrameTSLC->Skip();
    LastFrameHadTime = 0;
}
