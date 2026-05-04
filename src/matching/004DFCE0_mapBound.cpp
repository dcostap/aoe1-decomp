struct XYPoint {
    int x;
    int y;
};

class TribeInformationAIModule {
public:
    char gap_00[0x104];
    int mapXSizeValue;
    int mapYSizeValue;

    int mapBound(XYPoint* pt);
};

int TribeInformationAIModule::mapBound(XYPoint* pt) {
    int ret = 0;

    if (pt->x < 0) {
        pt->x = 0;
        ret = 1;
    } else if (pt->x >= this->mapXSizeValue) {
        pt->x = this->mapXSizeValue - 1;
        ret = 1;
    }
    if (pt->y < 0) {
        pt->y = 0;
        ret = 1;
    } else if (pt->y >= this->mapYSizeValue) {
        pt->y = this->mapYSizeValue - 1;
        ret = 1;
    }
    return ret;
}
