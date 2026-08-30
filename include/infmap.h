#ifndef AOE1_INFMAP_H
#define AOE1_INFMAP_H

#include "xy_point.h"

// InfluenceMap. The vptr is compiler-owned.

class InfluenceMap {
public:
    virtual ~InfluenceMap();

    InfluenceMap(int xSize, int ySize, unsigned char fillValue);
    InfluenceMap(int fd);

    int initialize(unsigned char value);
    void save(int fd);
    void load(int fd);
    void printToFile(char* filename);
    void setReferencePoint(int x, int y);
    int lookupValue(int x, int y);

    int setValue(int x, int y, unsigned char value);
    int setValue(int x1, int y1, int x2, int y2, unsigned char value);
    int incrementValue(int x, int y, unsigned char amount);
    int incrementValue(int x1, int y1, int x2, int y2, unsigned char amount);
    int decrementValue(int x, int y, unsigned char amount);
    int decrementValue(int x1, int y1, int x2, int y2, unsigned char amount);

    int setCoverageCount(const XYPoint& from, const XYPoint& to, int threshold);
    int setConnectionCount(const XYPoint& from, const XYPoint& to,
                           int minimum, int edgeHorizontal, int edgeVertical,
                           int allDirections);
    int coverageIncluding(const XYPoint& from, const XYPoint& to,
                          unsigned char minimum, unsigned char amount);
    int connectionsIncluding(const XYPoint& from, const XYPoint& to,
                             unsigned char minimum, unsigned char amount,
                             int mode1, int mode2, int allDirections);

    void setUnchangeableLimit(unsigned char value);
    int maxValue();

    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    unsigned char* valueValue;
    unsigned char** rowValue;
    int coverageCountValue;
    int connectionCountValue;
    unsigned char unchangeableLimitValue;
};

#endif
