#ifndef AOE1_POINT_CONTEXT_H
#define AOE1_POINT_CONTEXT_H

// Authentic point.cpp context. game_globals.h is the period-context donor
// required by the exact XYZ arithmetic and rotation owners.
#include "game_globals.h"

class XYZ {
public:
    int xValue;
    int yValue;
    int zValue;

    XYZ();
    XYZ(int x, int y, int z);

    void rotateXYByFacet(const XYZ& facet, XYZ& output,
                         unsigned char facetIndex);

    XYZ& operator=(const XYZ& other);
    XYZ operator+(const XYZ& other) const;
    XYZ operator-(const XYZ& other) const;
};

typedef char point_xyz_size_check[(sizeof(XYZ) == 0x0C) ? 1 : -1];

int __cdecl operator==(const XYZ& a, const XYZ& b);
int __cdecl operator!=(const XYZ& a, const XYZ& b);

#endif
