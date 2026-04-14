class RGE_Communications_Speed {
public:
    char gap_00[0x12C];
    unsigned int CurrentBufferGranularity;
    char gap_130[0x10C];
    int LastFrameHadTime;

    unsigned int GetBufferGranularityAdjusted();
};

unsigned int RGE_Communications_Speed::GetBufferGranularityAdjusted() {
    LastFrameHadTime = 1;
    return CurrentBufferGranularity;
}
