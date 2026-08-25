// 004D8C80 TribeInformationAIModule::blotExploredMap
// PDB: taiinfmd.cpp:870-890, 152 bytes
// void __thiscall blotExploredMap(int param_1, int param_2, int param_3, int param_4)
// ret 10h (4 params)
// FLAGS: default

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class InfluenceMap {
public:
    int lookupValue(int y, int x);
    void setValue(int y, int x, int value);
};

struct XYPoint {
    int y;
    int x;
};

class TribeInformationAIModule {
public:
    char _gap_000[0x158];
    InfluenceMap pathMap;               // +0x158

    int mapBound(XYPoint* pt);
    void blotExploredMap(int p1, int p2, int p3, int p4);
};
#endif

#endif
void TribeInformationAIModule::blotExploredMap(int p1, int p2, int p3, int p4)
{
    XYPoint min;
    XYPoint max;

    max.y = p1;
    max.x = p2;
    this->mapBound((XYPoint*)&max);

    min.y = p3;
    min.x = p4;
    this->mapBound((XYPoint*)&min);

    for (int y = max.y; y <= min.y; y++) {
        for (int x = max.x; x <= min.x; x++) {
            if (this->pathMap.lookupValue(y, x) != 1)
                this->pathMap.setValue(y, x, 2);
        }
    }
}
