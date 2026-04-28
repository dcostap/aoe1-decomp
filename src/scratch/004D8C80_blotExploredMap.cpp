// TribeInformationAIModule::blotExploredMap
// VA: 004D8C80
// taiinfmd.cpp:870-890
// 152 bytes, not matched (parked)
// Takes rect coords, clamps via mapBound, then loops to set
// influence map values to 2 where not already 1.
//
// Attempt log (5+ variants):
// v0: XYPoint locals + influence pathMap → sub esp 0x14, reg alloc diff
// v1: flat layout, simpler structs → 40B diff, sub esp 0x10 matches
// v2: reordered assignments → still ~40B diff
// v3: temps for params + y-then-x store order → still registers diverge
//
// Remaining diff: register allocation (ECX/EDX/EAX for param loads)
// and store ordering. TU-context boundary issue.

#include "../../include/game_globals.h"

class XYPoint {
public:
    int x, y;
};

class InfluenceMap {
public:
    char gap_00[4];
    int lookupValue(int x, int y);
    int setValue(int x, int y, int val);
};

class TribeInformationAIModule {
public:
    void mapBound(XYPoint* p);
    char gap_00[0x158];
    InfluenceMap pathMap;       // +0x158

    void blotExploredMap(int param_1, int param_2, int param_3, int param_4);
};

void TribeInformationAIModule::blotExploredMap(int param_1, int param_2, int param_3, int param_4) {
    XYPoint minPt, maxPt;
    int p1 = param_1;
    int p2 = param_2;
    minPt.y = p2;
    minPt.x = p1;
    int p3 = param_3;
    int p4 = param_4;
    maxPt.y = p4;
    maxPt.x = p3;

    mapBound(&minPt);
    mapBound(&maxPt);

    int x, y;
    for (x = minPt.x; x <= maxPt.x; x++) {
        for (y = minPt.y; y <= maxPt.y; y++) {
            if (pathMap.lookupValue(x, y) != 1) {
                pathMap.setValue(x, y, 2);
            }
        }
    }
}
