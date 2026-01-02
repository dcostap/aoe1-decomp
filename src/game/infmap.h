#pragma once
#include "../common.h"

class InfluenceMap {
public:
    int xSizeValue;                          // 0x4
    int ySizeValue;                          // 0x8
    int xReferencePointValue;                // 0xC
    int yReferencePointValue;                // 0x10
    uchar* valueValue;                       // 0x14
    uchar** rowValue;                        // 0x18
    int coverageCountValue;                  // 0x1C
    int connectionCountValue;                // 0x20
    uchar unchangeableLimitValue;            // 0x24

    InfluenceMap(int param_1, int param_2, uchar param_3);
    InfluenceMap(int param_1);
    virtual ~InfluenceMap();
    virtual int initialize(uchar param_1);
    virtual void save(int param_1);
    virtual void load(int param_1);
    virtual void printToFile(char* param_1);
    virtual void setReferencePoint(int param_1, int param_2);
    virtual int lookupValue(int param_1, int param_2);
    virtual int setValue(int param_1, int param_2, uchar param_3);
    virtual int setValue(int param_1, int param_2, int param_3, int param_4, uchar param_5);
    virtual int incrementValue(int param_1, int param_2, uchar param_3);
    virtual int incrementValue(int param_1, int param_2, int param_3, int param_4, uchar param_5);
    virtual int decrementValue(int param_1, int param_2, uchar param_3);
    virtual int decrementValue(int param_1, int param_2, int param_3, int param_4, uchar param_5);
    virtual int setCoverageCount(XYPoint* param_1, XYPoint* param_2, int param_3);
    virtual int setConnectionCount(XYPoint* param_1, XYPoint* param_2, int param_3, int param_4, int param_5, int param_6);
    virtual int coverageIncluding(XYPoint* param_1, XYPoint* param_2, uchar param_3, uchar param_4);
    virtual int connectionsIncluding(XYPoint* param_1, XYPoint* param_2, uchar param_3, uchar param_4, int param_5, int param_6, int param_7);
    virtual void setUnchangeableLimit(uchar param_1);
    virtual int maxValue();
};

static_assert(sizeof(InfluenceMap) == 0x28, "InfluenceMap Size Mismatch");
static_assert(offsetof(InfluenceMap, unchangeableLimitValue) == 0x24, "InfluenceMap Offset Mismatch");

