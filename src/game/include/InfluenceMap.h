#pragma once
#include "common.h"

class InfluenceMap {
public:
    InfluenceMap();
    InfluenceMap(int param_1, int param_2, uchar param_3);
    InfluenceMap(int param_1);

    // Virtuals (best-effort)
    virtual ~InfluenceMap(); // vt[0] (0x0)

    int initialize(uchar param_1);
    void save(int param_1);
    void load(int param_1);
    void printToFile(char* param_1);
    void setReferencePoint(int param_1, int param_2);
    int lookupValue(int param_1, int param_2);
    int setValue(int param_1, int param_2, uchar param_3);
    int setValue(int param_1, int param_2, int param_3, int param_4, uchar param_5);
    int incrementValue(int param_1, int param_2, uchar param_3);
    int incrementValue(int param_1, int param_2, int param_3, int param_4, uchar param_5);
    int decrementValue(int param_1, int param_2, uchar param_3);
    int decrementValue(int param_1, int param_2, int param_3, int param_4, uchar param_5);
    int setCoverageCount(XYPoint* param_1, XYPoint* param_2, int param_3);
    int setConnectionCount(XYPoint* param_1, XYPoint* param_2, int param_3, int param_4, int param_5, int param_6);
    int coverageIncluding(XYPoint* param_1, XYPoint* param_2, uchar param_3, uchar param_4);
    int connectionsIncluding(XYPoint* param_1, XYPoint* param_2, uchar param_3, uchar param_4, int param_5, int param_6, int param_7);
    void setUnchangeableLimit(uchar param_1);
    int maxValue();

    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    uchar* valueValue;
    uchar** rowValue;
    int coverageCountValue;
    int connectionCountValue;
    uchar unchangeableLimitValue;
};
static_assert(sizeof(InfluenceMap) == 0x28, "Size mismatch");
