#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    char gap_00[0x1040];
    int BorderDepthPercentage;

    void PrepareLimits(void);
    void SetBorderDepthPercentage(int value);
};
#endif

void PointMaker::SetBorderDepthPercentage(int value) {
    this->BorderDepthPercentage = value;
    if (value > 0x1E) {
        this->BorderDepthPercentage = 0x1E;
    }
    if (this->BorderDepthPercentage < 5) {
        this->BorderDepthPercentage = 5;
    }
    this->PrepareLimits();
}
