// attempt log:
// first pass: direct integer math for the border limits using the PointMaker surface from the type dump
// second pass: keep the exact field offsets but collapse back to the simplest direct expressions the original likely used
// target shape: left/top = (dim * percent) / 100, right/bottom = dim - limit

class PointMaker {
public:
    char gap_00[0xFD4];
    int Width;
    int Height;
    char gap_FDC[0x64];
    int BorderDepthPercentage;
    int LeftLimit;
    int RightLimit;
    int TopLimit;
    int BottomLimit;

    void PrepareLimits(void);
};

void PointMaker::PrepareLimits(void) {
    int width = this->Width;
    int border = this->BorderDepthPercentage;
    int left = (border * width) / 100;
    this->LeftLimit = left;
    this->RightLimit = width - left;
    int height = this->Height;
    int top = (border * height) / 100;
    this->TopLimit = top;
    this->BottomLimit = height - top;
}
