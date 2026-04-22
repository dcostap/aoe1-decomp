class InfluenceMap {
public:
    int setValue(int x, int y, int value);
};

class TribeInformationAIModule {
public:
    void setTileExplored(int x, int y);
    char gap_00[0x104];
    int mapXSizeValue;
    int mapYSizeValue;
    char gap_10C[0x4C];
    InfluenceMap pathMap;
};

void TribeInformationAIModule::setTileExplored(int x, int y) {
    if (x >= 0 && y >= 0 && x < this->mapXSizeValue && y < this->mapYSizeValue)
        this->pathMap.setValue(x, y, 0);
}
