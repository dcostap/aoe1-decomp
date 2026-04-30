// 004D8C80 TribeInformationAIModule::blotExploredMap
// PDB: taiinfmd.cpp:870-890, 152 bytes
// void __thiscall blotExploredMap(int param_1, int param_2, int param_3, int param_4)
// ret 10h (4 params)
// FLAGS: default

class InfluenceMap {
public:
    int lookupValue(int y, int x);
    void setValue(int y, int x, int value);
};

struct BlotLocals {
    int y2;
    int x2;
    int y1;
    int x1;
};

class TribeInformationAIModule {
public:
    char _gap_000[0x158];
    InfluenceMap pathMap;               // +0x158
    char _gap_15C[0x38C - 0x15C];

    int mapBound(int* coord);
    void blotExploredMap(int p1, int p2, int p3, int p4);
};

void TribeInformationAIModule::blotExploredMap(int p1, int p2, int p3, int p4)
{
    BlotLocals L;

    L.x1 = p2;
    L.y1 = p1;
    L.x2 = p4;
    L.y2 = p3;

    this->mapBound(&L.y1);
    this->mapBound(&L.y2);

    if (L.y1 > L.y2)
        return;

    int y = L.y1;
    do {
        if (L.x1 <= L.x2) {
            int cx = L.x1;
            do {
                if (this->pathMap.lookupValue(y, cx) != 1)
                    this->pathMap.setValue(y, cx, 2);
                cx++;
            } while (cx <= L.x2);
        }
        y++;
    } while (y <= L.y2);
}
