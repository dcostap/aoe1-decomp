class InfluenceMap {
public:
    int lookupValue(int x, int y);
};

class TribeInformationAIModule {
public:
    char gap_00[0x104];
    int mapXSizeValue;
    int mapYSizeValue;
    char gap_10C[0x158 - 0x10C];
    InfluenceMap pathMap;

    int tileUncovered(int x, int y);
};

int TribeInformationAIModule::tileUncovered(int x, int y) {
    int rv;

    if (x < 0 || y < 0 || x >= this->mapXSizeValue || y >= this->mapYSizeValue) {
        goto not_found;
    }
    if (this->pathMap.lookupValue(x, y) != 0xFF) {
        rv = 1;
        return rv;
    }
not_found:
    return 0;
}
