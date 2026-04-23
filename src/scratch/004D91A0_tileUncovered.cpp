// blocked by the 64-byte .text ceiling when using a local pathMap stub; needs a smaller/shared-type formulation
struct InfluenceMap;
extern int __fastcall lookupValue(InfluenceMap* self, int, int x, int y);

class TribeInformationAIModule {
public:
    int mapXSizeValue;
    int mapYSizeValue;
    char gap_08[0x150];
    char pathMap[0x28];

    int tileUncovered(int x, int y);
};

int TribeInformationAIModule::tileUncovered(int x, int y) {
    if (x < 0 || y < 0 || x >= this->mapXSizeValue || y >= this->mapYSizeValue) return 0;
    return lookupValue((InfluenceMap*)&this->pathMap, 0, x, y) != 0xFF;
}
