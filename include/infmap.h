#ifndef AOE1_INFMAP_H
#define AOE1_INFMAP_H

#include "xy_point.h"

// InfluenceMap. The vptr is compiler-owned.

class InfluenceMap {
  public:
    virtual ~InfluenceMap();

    InfluenceMap(int x, int y, unsigned char initialValue);
    InfluenceMap(int infile);

    int initialize(unsigned char initialValue);
    void save(int outfile);
    void load(int infile);
    void printToFile(char* filename);
    void setReferencePoint(int x, int y);
    int lookupValue(int x, int y);

    int setValue(int x, int y, unsigned char v);
    int setValue(int minX, int minY, int maxX, int maxY, unsigned char v);
    int incrementValue(int x, int y, unsigned char v);
    int incrementValue(int minX, int minY, int maxX, int maxY, unsigned char v);
    int decrementValue(int x, int y, unsigned char v);
    int decrementValue(int minX, int minY, int maxX, int maxY, unsigned char v);

    int setCoverageCount(const XYPoint& min, const XYPoint& max, int valueLevel);
    int setConnectionCount(
        const XYPoint& min, const XYPoint& max, int valueLevel, int countOrthogonalEdgesAsConnections,
        int countDiagonalEdgesAsConnections, int countDiagonalConnections
    );
    int coverageIncluding(
        const XYPoint& min, const XYPoint& max, unsigned char valueLevel, unsigned char newValueLevel
    );
    int connectionsIncluding(
        const XYPoint& min, const XYPoint& max, unsigned char valueLevel, unsigned char newValueLevel,
        int countOrthogonalEdgesAsConnections, int countDiagonalEdgesAsConnections, int countDiagonalConnections
    );

    void setUnchangeableLimit(unsigned char uL);
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
