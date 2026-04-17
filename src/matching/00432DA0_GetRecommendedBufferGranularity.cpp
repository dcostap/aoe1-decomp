class RGE_TimeSinceLastCall {
public:
    unsigned long GetAvg(int param_1);
};

class RGE_Communications_Speed {
public:
    char gap_00[0x104];
    RGE_TimeSinceLastCall* FrameTSLC;
    char gap_108[0x110];
    unsigned int OptimalBufferGranularity;

    unsigned int GetRecommendedBufferGranularity(void);
};

unsigned int RGE_Communications_Speed::GetRecommendedBufferGranularity(void) {
    unsigned int granularity;

    granularity = this->FrameTSLC->GetAvg(0x32);
    this->OptimalBufferGranularity = granularity;
    if (granularity > 0x96) {
        granularity = 0x96;
    }
    this->OptimalBufferGranularity = granularity;
    if (granularity < 10) {
        granularity = 10;
    }
    this->OptimalBufferGranularity = granularity;
    return granularity;
}
